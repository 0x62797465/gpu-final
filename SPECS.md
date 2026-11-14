Streaming manager is top level. It contains an iCache and dCache. It deals with the memory controller and requests from the units. 

The streaming manager subparts (there will be two) contain 8 int32 lanes, 8 fp32 lanes, 1 SFU, and 8 LD/ST lanes. The ISA will be designed such that groups of threads will have to remain together. 

Execution units will allow resident data to remain at a minimal logic cost. 

The schedular will be allowed to issue 1 instruction per cycle; reg read -> execution -> reg wb & next instruction read into logic
Scorebording will be used to make idle time minimal. For variable length instructions, idle time will vary so a signal will be sent back. 

Each SM will have 8 M10K blocks configured for 32*256 dual port.
8 lanes will be able to read/write in a single cycle, multi-source instructions will need multiple cycles to gather all needed regs.
This makes our register file able to hold 2048 32 bit registers. This limits us to 32 threads/4 warps with 64 regs per thread.