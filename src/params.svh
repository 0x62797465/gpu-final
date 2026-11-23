`ifndef PARAMS_GAURD
`define PARAMS_GAURD
localparam int STREAMING_MULTIPROCESSORS = 2;
localparam int STREAMING_MULTIPROCESSORS_SUB_PARTS = 2;
localparam int TOTAL_SMSP = STREAMING_MULTIPROCESSORS * STREAMING_MULTIPROCESSORS_SUB_PARTS;
localparam int MEMORY = 536870912;
localparam int ADDR_BITS = $clog2(MEMORY)-1-2; // must be less than 32 bits (-2 due to word alignment)

localparam int MEMCMD_IN_W = 4; // can put in x/2 commands per cycle (breaks if not a power of two, or is 2 or less)

localparam int FAST_EMULATION = 0; // removes random delays; can lead to bugs being missed
`endif