`include "params.svh"

// we rely on the fact that this is equal or under 32 bits
typedef struct packed {
    logic [1:0]                                  TYPE; // 2 if fake write, 1 if write, 0 if read
    logic [$clog2(TOTAL_SMSP-1)-1:0]             ID;
} mem_metadata;