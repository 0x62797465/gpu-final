localparam int STREAMING_MULTIPROCESSORS = 2;
localparam int STREAMING_MULTIPROCESSORS_SUB_PARTS = 2;
localparam int TOTAL_SMSP = STREAMING_MULTIPROCESSORS * STREAMING_MULTIPROCESSORS_SUB_PARTS;
localparam int MEMORY = 536870912;
localparam int ADDR_BITS = $clog2(MEMORY)-1-2; // must be less than 32 bits (-2 due to word alignment)

localparam int FIFO_MEMCMD_BUFF_SIZE = 10; // 10 entries of 32 bits