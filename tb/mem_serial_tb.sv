`include "../src/params.svh"
// dummy but does emulate memory access and has important assertions
module mem_controller (
        input  logic        global_reset_n,
		input  logic        avl_burstbegin_0,
		input  logic [26:0] avl_addr_0,
		input  logic [31:0] avl_wdata_0,
		input  logic [3:0]  avl_be_0,
		input  logic        avl_read_req_0,
		input  logic        avl_write_req_0,
		input  logic [4:0]  avl_size_0,
        output logic        local_init_done,                         
		output logic        local_cal_success,
		output logic        local_cal_fail,
        output logic        afi_half_clk,
		output logic        avl_ready_0,                              
		output logic        avl_rdata_valid_0,
		output logic [31:0] avl_rdata_0,
        // everything following is dead; simply here to prevent warnings
        input  wire         pll_ref_clk,       
		input  wire         soft_reset_n,                 
		output wire         afi_clk,           
		output wire         afi_reset_n,               
		output wire         afi_reset_export_n,
		output wire [9:0]   mem_ca,                                 
		output wire [0:0]   mem_ck,
		output wire [0:0]   mem_ck_n,
		output wire [0:0]   mem_cke,
		output wire [0:0]   mem_cs_n,
		output wire [3:0]   mem_dm,
		inout  wire [31:0]  mem_dq,
		inout  wire [3:0]   mem_dqs,
		inout  wire [3:0]   mem_dqs_n,
		input  wire         mp_cmd_clk_0_clk,                  
		input  wire         mp_cmd_reset_n_0_reset_n,      
		input  wire         mp_rfifo_clk_0_clk,              
		input  wire         mp_rfifo_reset_n_0_reset_n,  
		input  wire         mp_wfifo_clk_0_clk,              
		input  wire         mp_wfifo_reset_n_0_reset_n,  
		input  wire         oct_rzqin
);

localparam int QUEUE_SIZE = 256; 
localparam int QUEUE_WRAPPER = $clog2(QUEUE_SIZE-1);

logic control_clk = 0;
always #3 control_clk = ~control_clk;
assign afi_half_clk = control_clk;

// memory block; 4Gb (512MB); word aligned
logic [134217728:0] [31:0] mem;

// lazy implementation since this is only ever emulated
logic queue_full;
logic [QUEUE_WRAPPER-1:0] head;
logic [QUEUE_WRAPPER-1:0] tail;
logic [QUEUE_SIZE-1:0] [31:0] queue;

logic [4:0] write_left;
logic consuming_write;

logic escape_stall = ($urandom_range(2, 1) == 1) || FAST_EMULATION;
logic inc_queue = ($urandom_range(2, 1) == 1) || FAST_EMULATION;

assign queue_full = (head-tail <= 10) && head!=tail;

assert property (
    @(posedge afi_half_clk)
    disable iff (!local_init_done || !global_reset_n)
    avl_burstbegin_0 |-> (avl_write_req_0 || avl_read_req_0)
) else begin
    $fatal(2, "A burst was requested without a read or write, this can cause undefined behavior.\n");
end

assert property (
    @(posedge afi_half_clk)
    disable iff (!local_init_done || !global_reset_n)
    avl_read_req_0 |-> (avl_burstbegin_0)
) else begin
    $fatal(2, "A read was requested without a burst, this should not happen but is harmless.\n");
end

assert property (
    @(posedge afi_half_clk)
    disable iff (!local_init_done || !global_reset_n)
    avl_burstbegin_0 |-> (!consuming_write)
) else begin
    $fatal(2, "A new burst was started without finishing the write.\n");
end

assert property (
    @(posedge afi_half_clk)
    disable iff (!local_init_done || !global_reset_n)
    avl_write_req_0 |-> (avl_burstbegin_0 || consuming_write)
) else begin
    $fatal(2, "A write was asserted without reason.\n");
end

logic [26:0] cur_addr;
logic [3:0]  bmask; 
logic [3:0]  state;
logic [4:0]  bursts;

always @(posedge control_clk) begin
    if (!global_reset_n) begin
        local_init_done <= 0;
        local_cal_success <= 0;
        local_cal_fail <= 0;
    end else begin
        if (!local_init_done) begin 
            if (escape_stall) begin
                local_init_done <= 1;
                local_cal_success <= 1;
                avl_ready_0 <= 1;
                mem <= '0;
                avl_rdata_valid_0 <= 0;
                avl_rdata_0 <= 0;
                consuming_write <= 0;
                write_left <= 0;
                state <= 0;
            end
        end else begin
            // empty the queue // technically the real thing drains faster
            avl_rdata_valid_0 <= 0;
            if (inc_queue && (head != tail)) begin
                case (state)
                    0 : begin
                        if (queue[tail])
                            state <= 1; // write
                        else
                            state <= 5; // read
                    end
                    1 : begin
                        bursts <= queue[tail];
                        state <= 2;
                    end
                    2 : begin
                        cur_addr <= queue[tail];
                        state <= 3;
                    end
                    3 : begin
                        bmask <= queue[tail];
                        state <= 4;
                    end
                    4 : begin
                        mem[cur_addr] <= {mem[cur_addr][31:24] & {4{bmask[3]}},
                                          mem[cur_addr][23:16] & {4{bmask[2]}},
                                          mem[cur_addr][15:8]  & {4{bmask[1]}},
                                          mem[cur_addr][7:0]   & {4{bmask[0]}}};
                        bursts <= bursts - 1;
                        cur_addr <= cur_addr + 1;
                        if (bursts-1 == 0)
                            state <= 0;
                        else
                            state <= 3;
                    end
                    5 : begin
                        bursts <= queue[tail];
                        state <= 6;
                    end
                    6 : begin
                        cur_addr <= queue[tail];
                        state <= 7;
                    end
                    7 : begin
                        avl_rdata_valid_0 <= 1;
                        avl_rdata_0 <= mem[cur_addr];
                        bursts <= bursts - 1;
                        cur_addr <= cur_addr + 1;
                        if (bursts-1 == 0)
                            state <= 0;
                    end
                endcase
                tail <= tail + 1;
            end
            // consume incoming requests (delay at random)
            if (!avl_ready_0 && !queue_full) begin
                if (escape_stall) begin
                    avl_ready_0 <= 1;
                end
            end else if (avl_ready_0 && (avl_burstbegin_0 || (consuming_write && avl_write_req_0))) begin
                if (avl_write_req_0 && consuming_write) begin
                    queue[head] <= avl_wdata_0;
                    write_left <= write_left - 1;
                    head <= head + 1;
                    if (write_left-1 == 0) 
                        consuming_write <= 0;
                end else if (avl_write_req_0) begin
                    queue[head] <= '1; // write type
                    queue[QUEUE_WRAPPER & (head+1)] <= avl_size_0;
                    queue[QUEUE_WRAPPER & (head+2)] <= avl_addr_0;
                    queue[QUEUE_WRAPPER & (head+3)] <= avl_be_0;
                    queue[QUEUE_WRAPPER & (head+4)] <= avl_wdata_0;
                    head <= head + 5;
                    write_left <= avl_size_0-1;
                    if (avl_size_0 > 1)
                        consuming_write <= 1;
                end else if (avl_read_req_0) begin
                    queue[head] <= '0; // read type
                    queue[QUEUE_WRAPPER & (head+1)] <= avl_size_0;
                    queue[QUEUE_WRAPPER & (head+2)] <= avl_addr_0;
                    head <= head + 3;
                end
                if (queue_full)
                    avl_ready_0 <= 0;
                else if (escape_stall)
                    avl_ready_0 <= 1;
            end
        end
    end
end

endmodule

module mem_serial_tb;
    logic clk = 0;
    logic control_clk = 0;
    logic reset = 0;
    always #10 clk = ~clk;
    
    logic [MEMCMD_IN_W-1:0] [31:0] CMD_IN;
    logic [MEMCMD_IN_W-1:0]        CMD_IN_VALID;
    logic [MEMCMD_IN_W-1:0]        CMD_CONSUMED;
    logic [7:0] [31:0]             READ_OUT;
    logic [7:0]                    READ_OUT_VALID; 

    logic [134217727:0] [31:0] mem_goal;

    mem_serial dut (
        .CMD_IN(CMD_IN),
        .CMD_IN_VALID(CMD_IN_VALID),
        .CMD_CONSUMED(CMD_CONSUMED),
        .READ_OUT(READ_OUT),
        .READ_OUT_VALID(READ_OUT_VALID), // alternates to indicate new data

        .CPU_RESET_n(reset),
        .CLK(clk)
    );

    localparam int ITERATIONS = 1000;
    
    struct {
        logic                write;
        logic [26:0]         addr;
        logic [7:0] [31:0]   wdata;
        logic [31:0]         be;
        logic [4:0]          burstcount;
    } dat;

    initial begin
        automatic int addr_modulo = 2;
        while (addr_modulo <= 134217727) begin
            for (int i = 0; i < ITERATIONS; i++) begin
                dat.write = $urandom_range(1,0);
                dat.addr  = $urandom_range(addr_modulo-1, 0);
                for (int a = 0; a < 8; a++) begin
                    dat.wdata[a] = $urandom();
                end
                dat.be    = $urandom();
                dat.burstcount = $urandom_range(8, 1);
                if (dat.write)
            end
            addr_modulo = addr_modulo ** 2;
        end
    end

endmodule