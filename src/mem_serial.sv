`include "types.svh"
module mem_serial (
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

    input  [MEMCMD_IN_W-1:0] [31:0] CMD_IN,
    input  [MEMCMD_IN_W-1:0]        CMD_IN_VALID,
    output logic [MEMCMD_IN_W-1:0]  CMD_CONSUMED,
    output logic [WORDS_FIFO-1:0] [31:0]   READ_OUT,
    output logic [WORDS_FIFO-1:0]          READ_OUT_VALID, // alternates to indicate new data

    input                       CPU_RESET_n,
    input                       CLK,

    output    [15:0]            DEBUG_OUT

);

logic local_init_done;
logic local_cal_success;
logic local_cal_fail;

logic afi_half_clk;

struct {
    logic          ready;       
    logic          burstbegin;  
    logic [26:0]   addr;        
    logic          rdata_valid; 
    logic [31:0]   rdata;       
    logic [31:0]   wdata;       
    logic          read_req;    
    logic [3:0]    be;          
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
    .avl_size_0(8),//avl.burstcount),

    .afi_clk(),
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

localparam int initializing = 0;
localparam int idle = 1;
localparam int write_start = 2;
localparam int read_start = 3;
localparam int write_issue = 4;
localparam int writing = 5;

logic [$clog2(5)-1:0] state;

logic [4:0] wleft; // writes left

logic [MEMCMD_IN_W-1:0] cmd_in_valid_local;

logic [$clog2(MEMCMD_IN_W-1)-1:0] in_ptr;    // zero indexed
logic [$clog2(WORDS_FIFO-1)-1:0]  rbuff_ptr; 
logic [$clog2(WORDS_FIFO-1)-1:0]  rbuff_ptr_prev; 
logic rbuff_valid_prev;

always @(posedge afi_half_clk or negedge CPU_RESET_n) begin
    if (!CPU_RESET_n) begin
        state <= initializing;
        avl.addr <= '0; // 26:0
        avl.wdata <= '0;
        avl.write_req <= '0;
        avl.burstbegin <= '0;
        avl.read_req <= '0;
        avl.burstcount <= 8; 

        rbuff_ptr <= 0;
        rbuff_ptr_prev <= 0;
        in_ptr <= 0;
        rbuff_valid_prev <= 0;

        cmd_in_valid_local <= '0;

        READ_OUT_VALID <= '0;
        CMD_CONSUMED <= '0;
    end else begin
        // prevent metastability & mid write sampling
        cmd_in_valid_local <= CMD_IN_VALID; 
        if (rbuff_valid_prev && local_init_done && local_cal_success)
            READ_OUT_VALID[rbuff_ptr_prev] <= !READ_OUT_VALID[rbuff_ptr_prev];
        rbuff_ptr_prev <= rbuff_ptr;
        rbuff_valid_prev <= 0;

        if (avl.rdata_valid && local_init_done && local_cal_success) begin
            rbuff_valid_prev <= 1;
            READ_OUT[rbuff_ptr] <= avl.rdata;
            rbuff_ptr <= rbuff_ptr + 1;
            if (rbuff_ptr == WORDS_FIFO-1) // support non-powers of 2
                rbuff_ptr <= 0;
        end
        case (state)
            initializing : begin
                if (local_init_done && local_cal_success)
                    state <= idle;
            end
            idle : begin
                if (cmd_in_valid_local[in_ptr]^CMD_CONSUMED[in_ptr]) begin
                    CMD_CONSUMED[in_ptr] <= !CMD_CONSUMED[in_ptr];
                    if (!CMD_IN[in_ptr][0]) begin
                        state <= read_start;
                    end else begin
                        state <= write_start;
                    end
                    in_ptr <= in_ptr + 1;
                end
                if (avl.ready) begin
                    avl.burstbegin <= 0;
                    avl.read_req <= 0;
                    avl.write_req <= 0;
                end
            end
            write_start : begin
                if (cmd_in_valid_local[in_ptr]^CMD_CONSUMED[in_ptr]) begin
                    CMD_CONSUMED[in_ptr] <= !CMD_CONSUMED[in_ptr];
                    avl.addr <= CMD_IN[in_ptr];
                    state <= write_issue;
                    in_ptr <= in_ptr + 1;
                end
                if (avl.ready) begin
                    avl.burstbegin <= 0;
                    avl.read_req <= 0;
                    avl.write_req <= 0;
                end
            end
            read_start : begin
                if (avl.ready) begin
                    avl.write_req <= 0;
                    if (cmd_in_valid_local[in_ptr]^CMD_CONSUMED[in_ptr]) begin
                        CMD_CONSUMED[in_ptr] <= !CMD_CONSUMED[in_ptr];
                        avl.addr <= CMD_IN[in_ptr];
                        avl.burstbegin <= 1;
                        avl.read_req <= 1;

                        state <= idle;
                        in_ptr <= in_ptr + 1;
                    end else begin
                        avl.burstbegin <= 0;
                        avl.read_req <= 0;
                        avl.write_req <= 0;
                    end
                end
            end
            write_issue : begin
                if (avl.ready) begin
                    avl.read_req <= 0;
                    if (cmd_in_valid_local[in_ptr]^CMD_CONSUMED[in_ptr]) begin
                        CMD_CONSUMED[in_ptr] <= !CMD_CONSUMED[in_ptr];
                        avl.wdata <= CMD_IN[in_ptr];
                        avl.burstbegin <= 1;
                        avl.write_req <= 1;
                        wleft <= 7; // leaves early

                        state <= writing;
                        in_ptr <= in_ptr + 1;
                    end else begin
                        avl.burstbegin <= 0;
                        avl.read_req <= 0;
                        avl.write_req <= 0;
                    end
                end 
            end
            writing : begin
                if (avl.ready) begin
                    avl.burstbegin <= 0;
                    if (cmd_in_valid_local[in_ptr]^CMD_CONSUMED[in_ptr]) begin
                        CMD_CONSUMED[in_ptr] <= !CMD_CONSUMED[in_ptr];
                        avl.wdata <= CMD_IN[in_ptr];
                        avl.write_req <= 1;
                        in_ptr <= in_ptr + 1;

                        wleft <= wleft - 1;
                        if (wleft-1 == 0)
                            state <= idle;
                        
                        avl.write_req <= 1;
                    end else begin
                        avl.write_req <= 0;
                    end
                end
            end
            // default : state <= initializing; to make bugs more obvious
        endcase
    end
end

endmodule
