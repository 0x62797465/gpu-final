// Just a FIFO queue; different warps are not likely to try and access the same
// addresses due to synchronization issues and same-warp accesses are optimized
// locally. 
module mem_sched (
    output    [9:0]  DDR2LP_CA,
    output    [1:0]  DDR2LP_CKE,
    output           DDR2LP_CK_n,
    output           DDR2LP_CK_p,
    output    [1:0]  DDR2LP_CS_n,
    output    [3:0]  DDR2LP_DM,
    inout     [31:0] DDR2LP_DQ,
    inout     [3:0]  DDR2LP_DQS_n,
    inout     [3:0]  DDR2LP_DQS_p,
    input            DDR2LP_OCT_RZQ,

    input            CPU_RESET_n,
    input            CLK,

    output    [15:0] debug_out

);

wire pll_ref_clk;
wire local_init_done;
wire local_cal_success;
wire local_cal_fail;
wire drv_status_pass;
wire drv_status_fail;
wire drv_status_test_complete;

wire afi_clk;
wire afi_half_clk;
wire clk_lpddr2;

assign debug_out = {CLK, local_init_done,
    local_cal_success, local_cal_fail, drv_status_pass,
    drv_status_fail, drv_status_test_complete};

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

    .afi_clk(afi_clk),
    .afi_half_clk(afi_half_clk),
    .afi_reset_n(),
    .afi_reset_export_n(),

    .oct_rzqin(DDR2LP_OCT_RZQ),

    .local_init_done(local_init_done),
    .local_cal_success(local_cal_success),
    .local_cal_fail(local_cal_fail),

    .drv_status_pass(drv_status_pass),
    .drv_status_fail(drv_status_fail),
    .drv_status_test_complete(drv_status_test_complete)
);

fpga_lpddr2_example_if0 fpga_lpddr2_inst(
		/*input  wire     */   .pll_ref_clk(CLOCK_50_B5B),
		/*input  wire     */   .global_reset_n(test_global_reset_n),
		/*input  wire     */   .soft_reset_n(test_software_reset_n),
		/*output wire     */   .afi_clk(afi_clk),
		/*output wire     */   .afi_half_clk(afi_half_clk),
		/*output wire     */   .afi_reset_n(),
		/*output wire     */   .afi_reset_export_n(),
		
		/*output wire [9:0] */   .mem_ca(DDR2LP_CA),
		/*output wire [0:0] */   .mem_ck(DDR2LP_CK_p),
		/*output wire [0:0] */   .mem_ck_n(DDR2LP_CK_n),
		/*output wire [0:0] */   .mem_cke(DDR2LP_CKE[0]),
		/*output wire [0:0] */   .mem_cs_n(DDR2LP_CS_n[0]),
		/*output wire [3:0] */   .mem_dm(DDR2LP_DM),
		/*inout  wire [31:0]*/   .mem_dq(DDR2LP_DQ),
		/*inout  wire [3:0] */   .mem_dqs(DDR2LP_DQS_p),
		/*inout  wire [3:0] */   .mem_dqs_n(DDR2LP_DQS_n),

		/*inout  wire [3:0] */   .avl_ready_0(fpga_lpddr2_avl_ready),            //          avl_0.waitrequest_n
		/*input  wire     */   .avl_burstbegin_0(fpga_lpddr2_avl_burstbegin),    //             .beginbursttransfer
		/*input  wire [26:0]*/   .avl_addr_0(fpga_lpddr2_avl_addr),            //             .address
		/*output wire     */   .avl_rdata_valid_0(fpga_lpddr2_avl_rdata_valid),    //             .readdatavalid
		/*output wire [31:0]*/   .avl_rdata_0(fpga_lpddr2_avl_rdata),            //             .readdata
		/*input  wire [31:0]*/   .avl_wdata_0(fpga_lpddr2_avl_wdata),            //             .writedata
		/*input  wire [3:0] */   .avl_be_0(4'hF),                        //             .byteenable
		/*input  wire     */   .avl_read_req_0(fpga_lpddr2_avl_read_req),        //             .read
		/*input  wire     */   .avl_write_req_0(fpga_lpddr2_avl_write_req),      //             .write
		/*input  wire [2:0] */   .avl_size_0(fpga_lpddr2_avl_size),            //             .burstcount
		
		/*input  wire     */   .mp_cmd_clk_0_clk(afi_half_clk),              //     mp_cmd_clk_0.clk
		/*input  wire     */   .mp_cmd_reset_n_0_reset_n(test_software_reset_n),   //   mp_cmd_reset_n_0.reset_n
		/*input  wire     */   .mp_rfifo_clk_0_clk(afi_half_clk),            //     mp_rfifo_clk_0.clk
		/*input  wire     */   .mp_rfifo_reset_n_0_reset_n(test_software_reset_n), // mp_rfifo_reset_n_0.reset_n
		/*input  wire     */   .mp_wfifo_clk_0_clk(afi_half_clk),            //     mp_wfifo_clk_0.clk
		/*input  wire     */   .mp_wfifo_reset_n_0_reset_n(test_software_reset_n), // mp_wfifo_reset_n_0.reset_n
		
		/*output wire     */   .local_init_done(fpga_lpddr2_local_init_done),    //         status.local_init_done
		/*output wire     */   .local_cal_success(fpga_lpddr2_local_cal_success),  //             .local_cal_success
		/*output wire     */   .local_cal_fail(fpga_lpddr2_local_cal_fail),      //             .local_cal_fail
		
		/*input  wire     */   .oct_rzqin(DDR2LP_OCT_RZQ)                  //            oct.rzqin
		
	);

endmodule
