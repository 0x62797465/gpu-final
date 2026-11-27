`ifndef PARAMS_GAURD
`define PARAMS_GAURD
localparam int STREAMING_MULTIPROCESSORS = 2;
localparam int STREAMING_MULTIPROCESSORS_SUB_PARTS = 2;
localparam int TOTAL_SMSP = STREAMING_MULTIPROCESSORS * STREAMING_MULTIPROCESSORS_SUB_PARTS;
localparam int unsigned MEMORY = 2**20;
localparam int unsigned TOTAL_WORDS = MEMORY/4; // how many 32 bit words; 2**27 = 512 MB
localparam int ADDR_BITS = $clog2(MEMORY-1); // must be less than 32 bits
localparam int ADDR_BITS_WALIGNED = ADDR_BITS-$clog2(4);

localparam int MEMCMD_IN_W = 4; // can put in x/2 commands per cycle (breaks if not a power of two, or is 2 or less)
localparam int LINES_FIFO = 4; // how many reads can be in flight
localparam int WORDS_FIFO = LINES_FIFO*8;

localparam int FAST_EMULATION = 0; // removes random delays; can lead to bugs being missed
`define EMULATION  // Quartus fails to infer some things, so they are defined explicity (see l2_ctrl.sv)  
// Note that the cyclone v gx starter kit has 446 m10k
// blocks
localparam int L2_M10K_BLOCKS = 128; // must be power of two
localparam int L2_MEMSIZE = L2_M10K_BLOCKS*256; // in 32 bit words
// stores dirty bit and address
localparam int L2_METADATA_SIZE = L2_MEMSIZE/32;
localparam int L2_QUEUE_SIZE    = 256*4; // in words; m10k will round up
localparam int L2_CONSUME_PORTS = 2;
// this denotes reads and writes, so if set to two
// then two reads and two writes can occur in a single cycle.
// Due to complexity of the alternative, this physically
// splits memory   
localparam int L2_PORTS = 2; // should be under SMSP amount + 1
// how many 32 bit words per write/read
// higher = better bandwidth and more wiring and more r/w conflicts 
localparam int L2_WIDTH = 2; 
localparam int L2_MISS_QUEUE_SIZE = 2*256;
localparam int L2_LINES = L2_MEMSIZE/8; // 8 words, 32 bytes 

`endif