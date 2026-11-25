// This module uses a round robin approach to consume requests
// from all streaming multiprocessors. If a read/write misses
// than we communicate with the ddr controller helper.
module l2_ctrl (
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

endmodule 