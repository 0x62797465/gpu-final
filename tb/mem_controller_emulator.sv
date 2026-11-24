`include "../src/types.svh"
// dummy but does emulate memory access and has assertions
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
logic [TOTAL_WORDS-1:0] [31:0] mem;

// lazy implementation since this is only ever emulated
logic queue_full;
logic [QUEUE_WRAPPER-1:0] head;
logic [QUEUE_WRAPPER-1:0] tail;
logic [QUEUE_SIZE-1:0] [31:0] queue;

logic [4:0] write_left;
logic consuming_write;

logic escape_stall;
logic inc_queue;

assign queue_full = ((head-tail)%QUEUE_SIZE <= 10) && head!=tail;

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
    $display("Writes left: %h", write_left);
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

always @(posedge afi_half_clk or negedge global_reset_n) begin
    if (!global_reset_n) begin
        local_init_done <= 0;
        local_cal_success <= 0;
        local_cal_fail <= 0;
        escape_stall <= $urandom_range(1, 0) || FAST_EMULATION;
        inc_queue <= $urandom_range(1, 0) || FAST_EMULATION;
    end else begin
        escape_stall <= $urandom_range(1, 0) || FAST_EMULATION;
        inc_queue <= $urandom_range(1, 0) || FAST_EMULATION;
        if (!local_init_done) begin 
            if (escape_stall) begin
                local_init_done <= 1;
                local_cal_success <= 1;
                avl_ready_0 <= 0;
                for (int i = 0; i < TOTAL_WORDS; i++)
                    mem[i] <= '0;
                avl_rdata_valid_0 <= 0;
                avl_rdata_0 <= 0;
                consuming_write <= 0;
                write_left <= 0;
                state <= 0;
                head <= 0;
                tail <= 0;
            end
        end else begin
            // empty the queue // technically the real thing drains faster
            avl_rdata_valid_0 <= 0;
            if (inc_queue && (head != tail || state == 7)) begin
                case (state)
                    0 : begin
                        tail <= tail + 1;
                        if (queue[tail])
                            state <= 1; // write
                        else
                            state <= 5; // read
                    end
                    1 : begin
                        tail <= tail + 1;
                        bursts <= queue[tail][4:0];
                        state <= 2;
                    end
                    2 : begin
                        tail <= tail + 1;
                        cur_addr <= queue[tail][26:0];
                        state <= 3;
                    end
                    3 : begin
                        tail <= tail + 1;
                        bmask <= queue[tail][3:0];
                        state <= 4;
                    end
                    4 : begin
                        tail <= tail + 1;
                        mem[cur_addr] <= {bmask[3] ? queue[tail][31:24] : mem[cur_addr][31:24],
                                          bmask[2] ? queue[tail][23:16] : mem[cur_addr][23:16],
                                          bmask[1] ? queue[tail][15 :8] : mem[cur_addr][15:8],
                                          bmask[0] ? queue[tail][7  :0] : mem[cur_addr][7 :0]};
                        bursts <= bursts - 1;
                        cur_addr <= cur_addr + 1;
                        if (bursts-1 == 0)
                            state <= 0;
                        else
                            state <= 3;
                    end
                    5 : begin
                        tail <= tail + 1;
                        bursts <= queue[tail];
                        state <= 6;
                    end
                    6 : begin
                        tail <= tail + 1;
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
            end
            // consume incoming requests (delay at random)
            if (!avl_ready_0 && !queue_full) begin
                if (escape_stall) begin
                    avl_ready_0 <= 1;
                end
            end else if (avl_ready_0 && (avl_burstbegin_0 || (consuming_write && avl_write_req_0))) begin
                if (avl_write_req_0 && consuming_write) begin
                    queue[head][3:0] <= avl_be_0;
                    queue[(QUEUE_SIZE-1) & (head+1)] <= avl_wdata_0;
                    write_left <= write_left - 1;
                    head <= head + 2;
                    if (write_left-1 == 0) 
                        consuming_write <= 0;
                end else if (avl_write_req_0 && avl_burstbegin_0) begin
                    queue[head] <= '1; // write type
                    queue[(QUEUE_SIZE-1) & (head+1)][4:0] <= avl_size_0;
                    queue[(QUEUE_SIZE-1) & (head+2)][26:0] <= avl_addr_0;
                    queue[(QUEUE_SIZE-1) & (head+3)][3:0] <= avl_be_0;
                    queue[(QUEUE_SIZE-1) & (head+4)] <= avl_wdata_0;
                    head <= head + 5;
                    write_left <= avl_size_0-1;
                    if (avl_size_0 > 1)
                        consuming_write <= 1;
                end else if (avl_read_req_0 && avl_burstbegin_0) begin
                    queue[head] <= '0; // read type
                    queue[(QUEUE_SIZE-1) & (head+1)][4:0] <= avl_size_0;
                    queue[(QUEUE_SIZE-1) & (head+2)][26:0] <= avl_addr_0;
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