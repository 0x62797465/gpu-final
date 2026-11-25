`include "../src/params.svh"

// This is a randomized testbench meant to see if the ddr helper
// reads and writes how we expect under randomized timing. This is meant
// to stress the clock domain crossing that will occur in addition
// to testing normal corectness.

module ddr_frontend_tb;
    localparam int ITERATIONS = 100; // iterations per modulos

    // DUT wires
    logic [MEMCMD_IN_W-1:0] [31:0] CMD_IN;
    logic [MEMCMD_IN_W-1:0]        CMD_IN_VALID;
    logic [MEMCMD_IN_W-1:0]        CMD_CONSUMED;
    logic [WORDS_FIFO-1:0] [31:0]  READ_OUT;
    logic [WORDS_FIFO-1:0]         READ_OUT_VALID;

    logic [TOTAL_WORDS-1:0] [31:0] mem_goal; // expected state; checked with reads

    logic clk = 0;
    logic reset = 0;
    always #10 clk = ~clk; // different from memory controller

    ddr_frontend dut (
        .CMD_IN(CMD_IN),
        .CMD_IN_VALID(CMD_IN_VALID),
        .CMD_CONSUMED(CMD_CONSUMED),
        .READ_OUT(READ_OUT),
        .READ_OUT_VALID(READ_OUT_VALID), // alternates to indicate new data

        .CPU_RESET_n(reset),
        .CLK(clk)
    );
    
    struct {
        logic [$clog2(11)-1:0]            packets_left;
        logic                             write;
        logic [$clog2(TOTAL_WORDS-1)-1:0] addr;
        logic [7:0] [31:0]                wdata;
        // for future use, currently excluded because 
        // we do read modify cache evict write and 
        // cache lines have a constant size (32 bytes for us)
        logic [4:0]            burstcount;
        logic [31:0]           byteenable;
    } dat;

    task gpu_reset();
        @(posedge clk);
        reset = 0;
        for (int a = 0; a < ITERATIONS; a++) begin // extra long so both clock domains reset
            @(posedge clk);
        end
        reset = 1;
        for (int a = 0; a < ITERATIONS; a++) begin
            @(posedge clk);
        end    
    endtask
    
    // fills the struct with random (valid) data
    task gen_cmd(int unsigned addr_modulo);
        dat.write = |$urandom_range(1,0);
        dat.addr  = $urandom_range(addr_modulo-1, 0);
        for (int i = 0; i < 8; i++) begin
            dat.wdata[i] = $urandom();
        end
        dat.packets_left = 2 + 8*dat.write;
        // currently unused
        dat.burstcount = 8; // $urandom_range(8,1);
        dat.byteenable[31:0] = $urandom(); 
    endtask
        
    struct {
        logic [LINES_FIFO-1:0] [31:0] addresses;
        logic [WORDS_FIFO-1:0] [31:0] expected;

        logic [$clog2(LINES_FIFO-1)-1:0] head;
        logic [$clog2(LINES_FIFO-1)-1:0] tail;
        logic [2:0]                      tail_word_offset;
        logic full;
        logic full_next;
    } r_queue;

    task commit_cmd(); // commit to local state
        if (dat.write) begin
            for (int i = 0; i < dat.burstcount; i++) begin
                mem_goal[dat.addr+i] = dat.wdata[i];
            end
        end else begin
            r_queue.addresses[r_queue.head] = dat.addr;
            for (int i = 0; i < dat.burstcount; i++) begin
                r_queue.expected[r_queue.head*8+i] = mem_goal[dat.addr+i];
            end
            r_queue.head = r_queue.head + 1; 
            if (r_queue.head == r_queue.tail)
                r_queue.full_next = 1;
        end
    endtask

    logic [MEMCMD_IN_W-1:0] cmd_consumed_valid_local;
    logic [WORDS_FIFO-1:0]  read_out_valid_local;
    logic [WORDS_FIFO-1:0]  read_consumed;
    logic cmd_in_valid_prev;
    logic [$clog2(MEMCMD_IN_W-1)-1:0] cmd_ptr;
    logic [$clog2(MEMCMD_IN_W-1)-1:0] cmd_ptr_prev;
    logic n_escape;

    task transfer_cmd();
        while (((r_queue.full && !dat.write) && (r_queue.head == r_queue.tail)) || (|dat.packets_left) || n_escape) begin
            @(negedge clk);
            n_escape = $urandom_range(1,0);
            // fill the cmd queue
            if (cmd_in_valid_prev)
                CMD_IN_VALID[cmd_ptr_prev] = !CMD_IN_VALID[cmd_ptr_prev];
            cmd_in_valid_prev = 0;
            cmd_ptr_prev = cmd_ptr;
            if (|$urandom_range(1,0) && !(cmd_consumed_valid_local[cmd_ptr] ^
                    CMD_IN_VALID[cmd_ptr]) && |dat.packets_left) begin

                cmd_in_valid_prev = 1;
                if (dat.packets_left <= dat.burstcount && |dat.write)
                    CMD_IN[cmd_ptr] = dat.wdata[dat.burstcount-dat.packets_left];
                else if (dat.packets_left == dat.burstcount+1 && |dat.write)
                    CMD_IN[cmd_ptr] = dat.addr;
                else if (dat.packets_left == dat.burstcount+2 && |dat.write)
                    CMD_IN[cmd_ptr] = '1;
                else if (dat.packets_left == 2)
                    CMD_IN[cmd_ptr] = '0;
                else if (dat.packets_left == 1)
                    CMD_IN[cmd_ptr] = dat.addr;
                else
                    $fatal(2, "Invalid command state reached.\n");
                if (cmd_ptr == MEMCMD_IN_W-1)
                    cmd_ptr = 0;
                else
                    cmd_ptr = cmd_ptr + 1;
                dat.packets_left = dat.packets_left - 1;
            end
            cmd_consumed_valid_local = CMD_CONSUMED;
            // empty & check the read data
            if (|$urandom_range(1,0) && (read_out_valid_local[(r_queue.tail*8+r_queue.tail_word_offset)]^
             read_consumed[(r_queue.tail*8+r_queue.tail_word_offset)])) begin
                while (r_queue.tail_word_offset < 8) begin
                    if ((read_out_valid_local[(r_queue.tail*8+r_queue.tail_word_offset)]^
                            read_consumed[(r_queue.tail*8+r_queue.tail_word_offset)])) begin
                        if (READ_OUT[r_queue.tail*8+r_queue.tail_word_offset] != r_queue.expected[r_queue.tail*8+r_queue.tail_word_offset]) begin
                            $warning("Surrounding data: %h %h", r_queue.expected[r_queue.tail*8+r_queue.tail_word_offset+1], 
                             r_queue.expected[r_queue.tail*8+r_queue.tail_word_offset-1]);
                            $fatal(2, "Read data does not match expected address: %h data: %h expected: %h\n",
                             r_queue.addresses[r_queue.tail]+r_queue.tail_word_offset, READ_OUT[r_queue.tail*8+r_queue.tail_word_offset], 
                             r_queue.expected[r_queue.tail*8+r_queue.tail_word_offset]);
                        end
                        read_consumed[r_queue.tail*8+r_queue.tail_word_offset] = !read_consumed[r_queue.tail*8+r_queue.tail_word_offset];
                        if (r_queue.tail_word_offset == 7) begin
                            r_queue.tail_word_offset = 0;
                            r_queue.tail = 1 + r_queue.tail;
                            r_queue.full = 0;
                            r_queue.full_next = 0;
                        end else
                            r_queue.tail_word_offset = r_queue.tail_word_offset + 1;
                        if (r_queue.tail == LINES_FIFO)
                            r_queue.tail = 0;
                    end else
                        break;
                end
            end
             
            read_out_valid_local = READ_OUT_VALID;
        end
    endtask

    initial begin
        automatic int unsigned addr_modulo = 2;
        automatic int unsigned non_zero_words = 0;

        n_escape = 1;
        CMD_IN_VALID = '0;
        
        r_queue.head = 0;
        r_queue.tail = 0;
        r_queue.full = 0;
        r_queue.full_next = 0;
        r_queue.tail_word_offset = 0;

        cmd_consumed_valid_local = 0;
        cmd_ptr = 0;
        cmd_in_valid_prev = 0;
        
        read_consumed = 0;
        
        gpu_reset();
        // this essentially restricts our address space to find overwrite related bugs,
        // then it widens it to find bugs that may only occur in higher bounds
        while (2**addr_modulo <= TOTAL_WORDS) begin
            for (int a = 0; a < ITERATIONS; a++) begin
                gen_cmd(2**addr_modulo);
                if (dat.write || !r_queue.full) begin
                    commit_cmd();
                end else
                    dat.packets_left = 0;
                transfer_cmd();
                r_queue.full = r_queue.full_next;
            end
            addr_modulo = addr_modulo + 1;
        end
        
        while (r_queue.head != r_queue.tail || dut.mem_controller.head != dut.mem_controller.tail) begin
            n_escape = 1;
            transfer_cmd();
        end
        
        // checks if the memory state is what we expect
        for (int i = 0; i < TOTAL_WORDS; i++) begin
            if (mem_goal[i] != 0)
                non_zero_words = non_zero_words + 1;
            
            assert(mem_goal[i] == dut.mem_controller.mem[i])
            else $fatal(2, "Memory missmatch, address: %h expected: %h got: %h",
                    i, mem_goal[i], dut.mem_controller.mem[i]);
        end

        assert (non_zero_words != 0)
        else $fatal(2, "Something is extremely wrong, no writes have been commited to local or real memory");
        
        
        $exit();
    end

endmodule