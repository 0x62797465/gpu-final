`ifndef PARAMS_GAURD
`define PARAMS_GAURD
localparam int STREAMING_MULTIPROCESSORS = 2;
localparam int STREAMING_MULTIPROCESSORS_SUB_PARTS = 2;
localparam int TOTAL_SMSP = STREAMING_MULTIPROCESSORS * STREAMING_MULTIPROCESSORS_SUB_PARTS;
localparam int unsigned MEMORY = 2**20;
localparam int ADDR_BITS = $clog2(MEMORY)-1-2; // must be less than 32 bits (-2 due to word alignment)

localparam int MEMCMD_IN_W = 4; // can put in x/2 commands per cycle (breaks if not a power of two, or is 2 or less)
localparam int LINES_FIFO = 4; // how many reads can be in flight
localparam int WORDS_FIFO = LINES_FIFO*8;

localparam int FAST_EMULATION = 0; // removes random delays; can lead to bugs being missed
localparam int unsigned TOTAL_WORDS = MEMORY/4; // how many 32 bit words; 2**27 = 512 MB
`endif