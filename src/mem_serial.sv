`include "types.svh"
// The clocks are synchronous (DDR controller is 2x faster, but is derived from CLK)
// so we are able to do some things that a traditional setup would not permit.
// Regardless, this needs to be tested.
// Just a FIFO queue; different warps are not likely to try and access the same
// addresses due to synchronization issues and same-warp accesses are optimized
// at the SMSP level. 
// External has 2 m10k blocks allowing for full bandwidth utilization,
// and will keep track of reads/false writes. This unit outputs what
// commands were executed (besides true writes) and the read data 
// along with a stall signal. 
// The external module must always be able to drain reads at least as
// fast as we output them. 
module mem_sched (
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

    input [1:0] [31:0]          QUEUE_IN,
    input [1:0]                 QUEUE_IN_VALID,
    output                      QUEUE_STALL,
    output logic [31:0]         QUEUE_OUT,
    output logic                QUEUE_OUT_VALID,
    output logic [1:0] [31:0]   READ_OUT,
    output logic [1:0]          READ_OUT_VALID, // alternates to indicate new data

    input                       CPU_RESET_n,
    input                       CLK,

    output    [15:0]            DEBUG_OUT

);

logic local_init_done;
logic local_cal_success;
logic local_cal_fail;

logic afi_clk;
logic afi_half_clk;

struct {
    logic          ready;       
    logic          burstbegin;  
    logic [26:0]   addr;        
    logic          rdata_valid; 
    logic [31:0]   rdata;       
    logic [31:0]   wdata;       
    logic          read_req;    
    logic [31:0]   be;          
    logic          write_req;   
    logic [4:0]    burstcount;
} avl;

assign avl.be = '1;

assign debug_out = {CLK, local_init_done,
    local_cal_success, local_cal_fail};

mem_controller mem_controller (
    .pll_ref_clk(CLK),
    .global_reset_n(CPU_RESET_n),
    .soft_reset_n(CPU_RESET_n),

    .mem_ca(DDR2LP_CA),
    .mem_ck(DDR2LP_CK_p),
    .mem_ck_n(DDR2LP_CK_n),
    .mem_cke(DDR2LP_CKE[0]),
    .mem_cs_n(DDR2LP_CS_n[0]),
    .mem_dm(DDR2LP_DM),
    .mem_dq(DDR2LP_DQ),
    .mem_dqs(DDR2LP_DQS_p),
    .mem_dqs_n(DDR2LP_DQS_n),

    .avl_ready_0(avl.ready),
    .avl_burstbegin_0(avl.burstbegin),
    .avl_addr_0(avl.addr),
    .avl_rdata_valid_0(avl.rdata_valid),
    .avl_rdata_0(avl.rdata),
    .avl_wdata_0(avl.wdata),
    .avl_be_0(avl.be),
    .avl_read_req_0(avl.read_req),
    .avl_write_req_0(avl.write_req),
    .avl_size_0(avl.burstcount),

    .afi_clk(afi_clk),
    .afi_half_clk(afi_half_clk),
    .afi_reset_n(),
    .afi_reset_export_n(),

    .oct_rzqin(DDR2LP_OCT_RZQ),

    .local_init_done(local_init_done),
    .local_cal_success(local_cal_success),
    .local_cal_fail(local_cal_fail),

    .mp_cmd_clk_0_clk(afi_half_clk),
    .mp_cmd_reset_n_0_reset_n(CPU_RESET_n),
    .mp_rfifo_clk_0_clk(afi_half_clk),
    .mp_rfifo_reset_n_0_reset_n(CPU_RESET_n),
    .mp_wfifo_clk_0_clk(afi_half_clk),
    .mp_wfifo_reset_n_0_reset_n(CPU_RESET_n)
);

struct {
    logic                                     empty;
    logic                                     full;
    logic [$clog2(FIFO_MEMCMD_BUFF_SIZE)-1:0] left;
    logic [$clog2(FIFO_MEMCMD_BUFF_SIZE)-1:0] head;
    logic [$clog2(FIFO_MEMCMD_BUFF_SIZE)-1:0] tail;
    logic [$clog2(FIFO_MEMCMD_BUFF_SIZE)-1:0] pseudo_tail;
    logic [$clog2(FIFO_MEMCMD_BUFF_SIZE)-1:0] tail_diff;
    logic [31:0] dat_at_tail;
    logic [31:0] data [FIFO_MEMCMD_BUFF_SIZE:0];
} memq;

assign memq.tail_diff = memq.pseudo_tail-memq.tail;

assign memq.dat_at_tail = memq.data[memq.tail];

assign memq.empty = !memq.full && (memq.head == memq.tail);
assign memq.left = memq.pseudo_tail-memq.head;

assign QUEUE_STALL = ((memq.left < 4) || (memq.full)) && !memq.empty;

logic [1:0] total_in = QUEUE_IN_VALID[0] + QUEUE_IN_VALID[1];

logic in_op;
logic in_fw;
logic in_hd; // header
// read is depth two, so doesn't hit this
// false write is depth 11 due to bytemask
// real write is depth 10 due to lack of
// subtraction of two due to header consumption
// on assignment
logic [$clog2(9)-1:0] entries_left; 

always @(posedge CLK or negedge CPU_RESET_n) begin
    if (!CPU_RESET_n) begin
        memq.full <= 0;
        memq.head <= 0;
        memq.tail <= 0;

        in_fw <= 0;
        in_op <= 0;
        in_hd <= 0;

        QUEUE_OUT_VALID <= 0;
    end else begin
        QUEUE_OUT_VALID <= 0;
        // fill queue, drive full signal
        if (memq.left >= 2 || memq.empty) begin
            memq.full <= (memq.head + total_in) == memq.tail;
            memq.head <= memq.head + total_in;
            if (QUEUE_IN_VALID[0]) begin
                memq.data[memq.head] <= QUEUE_IN[0]; 
            end 
            if (QUEUE_IN_VALID[1]) begin
                memq.data[memq.head+total_in-1] <= QUEUE_IN[1];
            end
        end
        // empty finished commands
        // only forward read/fake-write 
        // metadata to output
        if (in_hd) begin
            QUEUE_OUT_VALID <= 1;
            QUEUE_OUT <= memq.dat_at_tail;
            memq.tail <= memq.tail + 1;
            in_hd <= 0;
        end else if (memq.pseudo_tail != memq.tail) begin
            if (in_op) begin
                if (memq.tail_diff >= entries_left) begin
                    memq.tail <= memq.tail+entries_left;
                    entries_left <= 0;
                    if (in_fw) begin // last cycle is bytemask
                        QUEUE_OUT[0] <= memq.data[memq.tail+entries_left];
                        QUEUE_OUT_VALID <= 1;
                    end
                    in_op <= 0;
                    in_fw <= 0;         
                end else begin
                    entries_left <= entries_left - memq.tail_diff;
                    memq.tail <= memq.pseudo_tail;
                end 
            end else begin
                // the pseudo tail MUST consume at least two entries
                // when starting a new command, so this works
                if (memq.dat_at_tail[1:0] == 2'b10) begin // fake write
                    in_fw <= 1;
                    in_op <= 1;
                    in_hd <= 1;
                    entries_left <= 9;
                    QUEUE_OUT_VALID <= 1;
                    QUEUE_OUT <= memq.dat_at_tail;
                end
                if (memq.dat_at_tail[1:0] == 2'b01) begin // write
                    in_op <= 1;
                    entries_left <= 8;
                end
                if (memq.dat_at_tail[1:0] == 2'b00) begin // read
                    in_hd <= 1;
                    QUEUE_OUT_VALID <= 1;
                    QUEUE_OUT <= memq.dat_at_tail;
                end
                memq.tail <= memq.tail + 1;
            end
        end
        // QUEUE_STALL_OUT <= QUEUE_STALL; // dual driven; needs to settle // delay might not be afoardable+consequences need to be measured
    end
end

localparam int initializing = 0;
localparam int idle = 1;
localparam int write_start = 2;

logic [$clog2(9)-1:0] state;

logic rbuff_ptr;

logic [$clog2(7)-1:0] wleft; // writes left

always @(posedge afi_half_clk) begin
    if (!CPU_RESET_n) begin
        state <= initializing;
        avl.addr <= '0; // 26:0
        avl.wdata <= '0;
        avl.write_req <= '0;
        avl.burstbegin <= '0;
        avl.read_req <= '0;
        avl.burstcount <= 8; 

        memq.pseudo_tail <= 0;

        rbuff_ptr <= 0;

        READ_OUT_VALID <= '0;
    end else begin
        if (avl.rdata_valid && local_init_done && local_cal_success) begin
            READ_OUT[rbuff_ptr] <= avl.rdata;
            READ_OUT_VALID[rbuff_ptr] <= !READ_OUT_VALID[rbuff_ptr];
            rbuff_ptr <= !rbuff_ptr;
        end
        case (state)
            initializing : begin
                if (local_init_done && local_cal_success)
                    state <= idle;
            end
            idle : begin
                if (avl.ready) begin
                    if (!memq.data[memq.pseudo_tail][0] && 
                            (memq.left < FIFO_MEMCMD_BUFF_SIZE-1 || memq.full)) begin
                        avl.burstbegin <= 1;
                        avl.read_req <= 1;
                        avl.addr <= memq.data[memq.pseudo_tail+1]; 
                        memq.pseudo_tail <= memq.pseudo_tail + 2;
                    end else if (memq.left < FIFO_MEMCMD_BUFF_SIZE-2 || memq.full) begin
                        avl.addr <= memq.data[memq.pseudo_tail+1];
                        avl.wdata <= memq.data[memq.pseudo_tail+2];
                        avl.burstbegin <= 1;
                        avl.write_req <= 1;
                        memq.pseudo_tail <= memq.pseudo_tail + 3;
                        wleft <= 7;
                        state <= write_start;
                    end else begin
                        avl.burstbegin <= 0;
                        avl.read_req <= 0;
                        avl.write_req <= 0;
                    end
                end
            end
            write_start : begin
                if (avl.ready) begin
                    avl.burstbegin <= 0;
                    if (memq.pseudo_tail != memq.head) begin
                        wleft <= wleft - 1;
                        memq.pseudo_tail <= memq.pseudo_tail + 1;
                        avl.wdata <= memq.data[memq.pseudo_tail];
                        if (wleft)
                            avl.write_req <= 1;
                        else begin // extra consumption of bytemask
                            avl.write_req <= 0;
                            state <= idle;
                        end
                    end else begin
                        avl.write_req <= 0;
                    end
                end
            end
            default : state <= initializing;
        endcase
    end
end

endmodule
