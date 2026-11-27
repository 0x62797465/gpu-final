`include "types.svh"

// This module uses a round robin approach to consume requests
// from all streaming multiprocessors. If a read/write misses
// than we communicate with the ddr controller helper.
module l2_ctrl (
    // [addr]:[wbit][burts][SMSP_ID]:[bmask]:[write data]*x
    // [addr]:[wbit][burts][SMSP_ID]
    input  [STREAMING_MULTIPROCESSORS-1:0] [31:0] REQUESTS,
    input  [STREAMING_MULTIPROCESSORS-1:0] REQUESTS_VALID,
    output logic [STREAMING_MULTIPROCESSORS-1:0] READY_NEXT,
    output logic [STREAMING_MULTIPROCESSORS-1:0] [31:0] RDATA,
    
    // forwaded to the serializer
    output    [9:0]             DDR2LP_CA,
    output    [1:0]             DDR2LP_CKE,
    output                      DDR2LP_CK_n,
    output                      DDR2LP_CK_p,
    output    [1:0]             DDR2LP_CS_n,
    output    [3:0]             DDR2LP_DM,
    inout     [31:0]            DDR2LP_DQ,
    inout     [3:0]             DDR2LP_DQS_n,
    inout     [3:0]             DDR2LP_DQS_p,
    input                       DDR2LP_OCT_RZQ,

    input                       CPU_RESET_n,
    input                       CLK
);

// queue before processing, allowing many in-flight reads/rights
logic [L2_CONSUME_PORTS*2-1:0] [(L2_QUEUE_SIZE/(L2_CONSUME_PORTS*2))-1:0] [31:0] cmd_q;
logic [L2_CONSUME_PORTS*2-1:0] [$clog2(L2_QUEUE_SIZE/(L2_CONSUME_PORTS*2))-1:0] q_waddr;
logic [L2_CONSUME_PORTS*2-1:0] [$clog2(L2_QUEUE_SIZE/(L2_CONSUME_PORTS*2))-1:0] q_raddr;
logic [L2_CONSUME_PORTS*2-1:0] [31:0] q_wdata;
logic [L2_CONSUME_PORTS*2-1:0] [31:0] q_rdata;
logic [L2_CONSUME_PORTS*2-1:0] qwe;
always @(posedge CLK) begin
    for (int a = 0; a < L2_CONSUME_PORTS*2; a++) begin
        if (qwe[a]) begin
            cmd_q[a][q_waddr[a]] <= q_wdata;
        end
        q_rdata[a] <= cmd_q[a][q_raddr[a]];
    end
end


// Hard partitions+round robin would lead to many waiting ports and
// requires the amount of streaming managers to be divisible by the
// amount of l2 consuming ports,
// true round robin with a different searcher for each port would
// cost about n^2 in comparisons to prevent conflict.
// Therefore, we use a base pointer that each port has an offset
// from and if their data is valid the thread splits off and 
// stays there until it's done. This prevents race conditions,
// prevents ports from being idle when they don't have to be,
// and avoids massive circut complexity.

logic [STREAMING_MULTIPROCESSORS-1:0] allocated;
logic [L2_CONSUME_PORTS-1:0] recieving;
logic [L2_CONSUME_PORTS-1:0] need_warmup;
logic [$clog2(STREAMING_MULTIPROCESSORS)-1:0] base_ptr;
logic [L2_CONSUME_PORTS-1:0] [$clog2(STREAMING_MULTIPROCESSORS)-1:0] port_ptr;
logic [L2_CONSUME_PORTS-1:0] [$clog2(L2_QUEUE_SIZE/(L2_CONSUME_PORTS))-1:0] qhead;
logic [L2_CONSUME_PORTS-1:0] [$clog2(L2_QUEUE_SIZE/(L2_CONSUME_PORTS))-1:0] qtail;
logic [L2_CONSUME_PORTS-1:0] qfull;
logic [L2_CONSUME_PORTS-1:0] header_left; // addr + metadata
logic [L2_CONSUME_PORTS-1:0] [$clog2(9)-1:0] body_left; // bmask + 8 bursts

always @(posedge CLK or negedge CPU_RESET_n) begin
    if (!CPU_RESET_n) begin
        port_ptr <= 0;
        base_ptr <= 0;
        recieving <= 0;
        READY_NEXT <= 0;
        qhead <= 0;
        qtail <= 0;
        qfull <= 0;
        q_waddr <= 0;
        allocated <= 0;
        header_left <= 0;
        need_warmup <= 0;
        body_left <= 0;
    end else begin
        qwe <= '0;
        for (int a = 0; a < L2_CONSUME_PORTS; a++) begin            
            if (recieving[a]) begin
                // need_warmup gives the request for new data cycle to propagate
                if (!need_warmup[a] && REQUESTS_VALID[port_ptr[a]]) begin
                    if (!qfull[a] || qhead[a] != qtail[a]) begin
                        if (READY_NEXT[port_ptr[a]] == 0)
                            need_warmup[a] <= 1;
                        READY_NEXT[port_ptr[a]] <= 1;
                        
                        // calculate how much left to read
                        if (header_left[a]) begin
                            header_left[a] <= 0;
                            if (REQUESTS[port_ptr[a]][31]) begin
                                body_left[a] <= REQUESTS[port_ptr[a]][30:30-$clog2(8)] + 1;
                            end else begin
                                recieving[a] <= 0;
                                READY_NEXT[port_ptr[a]] <= 0;
                            end
                        end else if (body_left[a] == 1) begin
                            READY_NEXT[port_ptr[a]] <= 0;
                        end

                        // actually write to queue
                        q_wdata[a+(qhead[a][0]*L2_CONSUME_PORTS)] <= REQUESTS[port_ptr[a]];
                        q_waddr[a+(qhead[a][0]*L2_CONSUME_PORTS)] <= qhead[a][$high(qhead):1];
                        qwe[a+(qhead[a][0]*L2_CONSUME_PORTS)] <= 1;

                        // increment head & fullness calculation
                        if (qhead[a]+1'b1 == qtail[a])
                            qfull[a] <= 1;
                        else
                            qfull[a] <= 0;
                        qhead[a] <= qhead[a] + 1;
                    end 
                    if (qfull[a] && (qhead[a] == qtail[a]))
                        READY_NEXT[(base_ptr+a)&$high(READY_NEXT)] <= 0;
                end else begin
                    need_warmup[a] <= 0;
                end
            end else if (REQUESTS_VALID[(base_ptr+a)&($high(REQUESTS_VALID))]
                 && (!qfull[a] || (qtail[a] != qhead[a]))) begin
                // allocate & record information
                port_ptr[a] <= base_ptr+a;
                recieving[a] <= 1;
                allocated[(base_ptr+a)&$high(READY_NEXT)] <= 1;
                READY_NEXT[(base_ptr+a)&$high(READY_NEXT)] <= 1;

                // write addr
                q_wdata[a+(qhead[a][0]*L2_CONSUME_PORTS)] <= REQUESTS[(base_ptr+a)&($high(REQUESTS_VALID))];
                q_waddr[a+(qhead[a][0]*L2_CONSUME_PORTS)] <= qhead[a][$high(qhead):1];
                qwe[a+(qhead[a][0]*L2_CONSUME_PORTS)] <= 1;

                // setup initial control flow
                need_warmup[a] <= 1;
                header_left[a] <= 1;
                body_left[a] <= 0;

                // increment head & fullness calculation
                if (qhead[a]+1'b1 == qtail[a])
                    qfull[a] <= 1;
                else
                    qfull[a] <= 0;
                qhead[a] <= 1 + qhead[a];
            end
        end
    end
end

// [valid bit][dirty bit][address]
logic [L2_PORTS-1:0] [(L2_LINES/L2_PORTS)-1:0] [31:0] cmetadata;
logic [L2_PORTS-1:0] [$clog2(L2_LINES/L2_PORTS)-1:0] meta_waddr;
logic [L2_PORTS-1:0] [$clog2(L2_LINES/L2_PORTS)-1:0] meta_raddr;
logic [L2_PORTS-1:0] [63:0] meta_wdata;
logic [L2_PORTS-1:0] [63:0] meta_rdata;
logic [L2_PORTS-1:0] mwe;
always @(posedge CLK) begin
    for (int a = 0; a < L2_PORTS; a++) begin
        if (mwe[a]) begin
            cmetadata[a][meta_waddr[a]] <= meta_wdata;
        end
        meta_rdata[a] <= cmetadata[a][meta_raddr[a]];
    end
end

struct {
    logic [L2_PORTS*2-1:0] raddr;
    logic [L2_PORTS*2-1:0] waddr;
    logic [L2_PORTS-1:0] [$clog2(L2_WIDTH*4-1)-1:0] bmask;
} c;

logic [31:0] l2w_addr [L2_PORTS-1:0];
logic [31:0] l2r_addr [L2_PORTS-1:0];
logic [L2_PORTS-1:0] we;
logic [(32*L2_WIDTH)-1:0] wdata [L2_PORTS-1:0]; 
logic [(32*L2_WIDTH)-1:0] rdata [L2_PORTS-1:0]; 
 
`define EMULATION
`ifdef EMULATION
logic [L2_PORTS-1:0] [(L2_MEMSIZE/L2_PORTS)-1:0] [(32*L2_WIDTH)-1:0] cache;
always @(posedge CLK) begin
    for (int a = 0; a < L2_PORTS; a++) begin
        if (we[a]) begin
            for (int b = 0; b < L2_WIDTH; b++) begin
                if (c.bmask[a][0+(b*4)]) 
                    cache[a][l2w_addr[a][$clog2(L2_MEMSIZE/L2_PORTS)-1:0]+0+(b*4)][(b*32)+7+:8] 
                        <= wdata[b][(b*32)+7+:8];
                if (c.bmask[a][1+(b*4)])
                    cache[a][l2w_addr[a][$clog2(L2_MEMSIZE/L2_PORTS)-1:0]+1+(b*4)][(b*32)+15+:8]
                        <= wdata[b][(b*32)+15+:8];
                if (c.bmask[a][2+(b*4)])
                    cache[a][l2w_addr[a][$clog2(L2_MEMSIZE/L2_PORTS)-1:0]+2+(b*4)][(b*32)+23+:8]
                        <= wdata[b][(b*32)+23+:8];
                if (c.bmask[a][3+(b*4)])
                    cache[a][l2w_addr[a][$clog2(L2_MEMSIZE/L2_PORTS)-1:0]+3+(b*4)][(b*32)+31+:8]
                        <= wdata[b][(b*32)+31+:8];
            end
        end
        rdata[a] <= cache[a][l2r_addr[a][$clog2(L2_MEMSIZE/L2_PORTS)-1:0]];
    end
end

`else
// todo
altsyncram mem (
    .clock0(clk),
    .address_a(queue_addr),
    .data_a(queue_data),
    .wren_a(write_enable),
    .byteena_a(queue_mask),

    .address_b(addr[14:2]),
    .q_b(raw_mem_data)
);
defparam
    mem.operation_mode = "DUAL_PORT",
    mem.width_a = 32,
    mem.width_b = 32,
    mem.numwords_a = 8192,
    mem.numwords_b = 8192,
    mem.widthad_a = 13,
    mem.widthad_b = 13,
    mem.width_byteena_a = 4,
    mem.address_reg_b = "CLOCK0",
    mem.outdata_reg_b = "UNREGISTERED",
    mem.ram_block_type = "M10K";
`endif

// reduces conflicts (from something 
// like strident access) by hashing L2
// destinations from address
logic [L2_PORTS-1:0] [31:0] haddr; // for partitioning
logic [L2_PORTS-1:0] [STREAMING_MULTIPROCESSORS-1:0] cmd_in_ptr;

always_comb begin
    for (int i = 0; i < L2_PORTS; i++) begin
        l2r_addr[i]  = c.raddr[i];
        l2r_addr[i] ^= l2r_addr[i] << 13;
        l2r_addr[i] ^= l2r_addr[i] >> 17;
        l2r_addr[i] ^= l2r_addr[i] << 5;
    end
    for (int i = 0; i < L2_PORTS; i++) begin
        l2w_addr[i]  = c.waddr[i];
        l2w_addr[i] ^= l2w_addr[i] << 13;
        l2w_addr[i] ^= l2w_addr[i] >> 17;
        l2w_addr[i] ^= l2w_addr[i] << 5;
    end
    for (int i = 0; i < L2_PORTS; i++) begin
        haddr[i]  = REQUESTS[cmd_in_ptr[i]][31:$clog2(32)]; // line aligned
        haddr[i] ^= haddr[i] << 13;
        haddr[i] ^= haddr[i] >> 17;
        haddr[i] ^= haddr[i] << 5;
    end
    
end

struct {
    // data read out
    logic [WORDS_FIFO-1:0] [31:0]   rdata;
    logic [WORDS_FIFO-1:0]          rdata_valid;
    logic [WORDS_FIFO-1:0]          rdata_valid_local;
    logic [LINES_FIFO-1:0] [31:0]   pending_raddr;
    logic [$clog2(LINES_FIFO)-1:0]  rfifo_head;
    logic [$clog2(LINES_FIFO)-1:0]  rfifo_tail;
    logic [$clog2(8)-1:0]           rfifo_tail_offset;

    // commands into frontend
    logic [MEMCMD_IN_W-1:0] [31:0]  cmds;
    logic [MEMCMD_IN_W-1:0]         cmd_valid;
    logic                           cmd_valid_prev;
    logic [MEMCMD_IN_W-1:0]         cmd_consumed;
    logic [MEMCMD_IN_W-1:0]         cmd_consumed_local;
    logic [$clog2(MEMCMD_IN_W)-1:0] cmd_head;

    // race condition prevention for ports
    logic [L2_PORTS-1:0]            waiting_lock;
    logic [$clog2(L2_PORTS)-1:0]    id_allocated;
    logic                           id_valid;
} ddr;

ddr_frontend ddr_frontend(
    .DDR2LP_CA(DDR2LP_CA),
    .DDR2LP_CKE(DDR2LP_CKE),
    .DDR2LP_CK_n(DDR2LP_CK_n),
    .DDR2LP_CK_p(DDR2LP_CK_p),
    .DDR2LP_CS_n(DDR2LP_CS_n),
    .DDR2LP_DM(DDR2LP_DM),
    .DDR2LP_DQ(DDR2LP_DQ),
    .DDR2LP_DQS_n(DDR2LP_DQS_n),
    .DDR2LP_DQS_p(DDR2LP_DQS_p),
    .DDR2LP_OCT_RZQ(DDR2LP_OCT_RZQ),

    .CMD_IN(ddr.cmds),
    .CMD_IN_VALID(ddr.cmd_valid),
    .CMD_CONSUMED(ddr.cmd_consumed),
    .READ_OUT(ddr.rdata),
    .READ_OUT_VALID(ddr.rdata_valid),

    .CPU_RESET_n(CPU_RESET_n),
    .CLK(CLK)
);

logic [L2_PORTS-1:0] [$clog2(15)-1:0] state;
logic [L2_PORTS-1:0] [$clog2(8)-1:0] addr;
logic [STREAMING_MULTIPROCESSORS-1:0] processing;

localparam int scanning = 0;
localparam int awaiting_metadata = 1;
localparam int process_metadata = 2;
localparam int w_cachehit = 3;
localparam int r_cachehit = 4;
localparam int ddr_read = 5;
localparam int ddr_write = 6;
localparam int evict = 7;
localparam int cache_commit = 8;
logic [L2_PORTS-1:0] pending_write;


always @(posedge CLK or negedge CPU_RESET_n) begin
    if (!CPU_RESET_n) begin
        state <= 0;
        processing <= 0;
        for (int i = 0; i < L2_PORTS; i++) begin
            cmd_in_ptr[i] = i;
        end
    end else begin
        for (int i = 0; i < L2_PORTS; i++) begin
            case (state[i]) 
                scanning : begin
                    // Asking if it's in the partition,
                    // if it's an address (which means the data
                    // is valid and nothing else is processing it)
                    // conflicts don't occur because there is one 
                    // port per partition.
                    if (!processing[i] && REQUESTS_VALID[cmd_in_ptr[i]]
                     && (haddr[i] >= (i*(L2_MEMSIZE/L2_PORTS)))
                     && (haddr[i] < ((i+1)*(L2_MEMSIZE/L2_PORTS)))) begin
                        processing[i] <= 1;
                        state[i] <= awaiting_metadata;
                        meta_raddr[i] <= haddr[i];
                        addr[i] <= REQUESTS[cmd_in_ptr[i]];
                    end else
                        cmd_in_ptr[i] <= cmd_in_ptr[i] + 1;
                end
                awaiting_metadata : state[i] <= process_metadata;
                process_metadata : begin
                    if (|REQUESTS[cmd_in_ptr[i]])
                        pending_write[i] <= 1;
                    else 
                        pending_write[i] <= 0;
                    if (meta_rdata[i][31]) begin // valid bit
                        if (meta_rdata[i][29:0] == addr[i]) begin
                            if (|REQUESTS[cmd_in_ptr[i]]) begin
                                state[i] <= w_cachehit;
                                mwe[i] <= 1;
                                meta_wdata[i] <= meta_rdata[i];
                                meta_wdata[i][30] <= 1;
                            end else begin
                                state[i] <= r_cachehit;
                            end
                        end else begin
                            ddr.waiting_lock[i] <= 1;
                            state[i] <= evict;
                        end
                    end
                    if (|REQUESTS[cmd_in_ptr[i]]) begin
                        state[i] <= ddr_write;
                    end else begin
                        state[i] <= ddr_read;
                    end
                end
                evict : begin
                    
                end
            endcase
        end
    end
end

// Handle ddr communication fairly locks the queue
// by doing a round robin scan to see which ports 
// need a lock
always @(posedge CLK or negedge CPU_RESET_n) begin
    if (!CPU_RESET_n) begin
        ddr.id_allocated <= 0;
        ddr.id_valid <= 0;
    end else begin
        if (!ddr.id_valid) begin
            
        end
    end
end

endmodule