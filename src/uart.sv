// taken from my CPU
module char_out (
	input [7:0]        chr,
	input              chr_ready,
	input              clk,
    input              CPU_RESET_n,
	output     reg     tm_ready = 1'b1,
    output     reg     UART_TX
);

reg [9:0] baud = 10'b0;
reg [2:0] bit_ptr = 3'b0;
reg [1:0] state = 2'b0;

always @(posedge clk or negedge CPU_RESET_n) begin // putchar equivalent
	if (!CPU_RESET_n) begin
		tm_ready <= 1; // Mark as ready
		baud <= 0; // reset counter
		state <= 0;
	end
	else begin
		if (baud == 434) begin // 50,000,000/434 is about 115,200
			baud <= 0;
			case (state)
				2'b00 : begin // lower signal to signal a start of a byte
					UART_TX <= 0;
					state <= state + 1;
				end
				2'b01 : begin
					if (bit_ptr == 3'b111) // end of byte
						state <= state + 1;	
					UART_TX <= chr[bit_ptr]; // put bit in
					bit_ptr <= bit_ptr + 1; 
				end
				2'b10 : begin
					UART_TX <= 1; // mark byte as done
					state <= 0;
					tm_ready <= 1;
				end
			endcase
		end else if (tm_ready && chr_ready) begin
			baud <= 0;
			tm_ready <= 0; // mark as in use
		end else if (!tm_ready) begin
			baud <= baud + 1;
		end
	end
end
endmodule

module char_in (
    input              clk,
    input              CPU_RESET_n,
    input              UART_RX,
	output        reg  rc_done = '1,
	output        reg [7:0] chr = '0
);

reg [9:0] baud = 10'b0;
reg [2:0] bit_ptr = 3'b0;
reg delay = 0; // delays a cycle
reg wait_rise = 0; // wait for clock rise
reg RX = 0;
reg [1:0] temp;
always @(posedge clk) begin
	temp <= {temp[0], UART_RX}; // prevent metastability
	RX <= temp[1];
end
always @(posedge clk or negedge CPU_RESET_n) begin // getchar equivalent
	if (!CPU_RESET_n) begin
		baud <= 0;
		chr <= '0;
		rc_done <= '1;
		bit_ptr <= '0;
	end
	else if (!rc_done) begin // recieve state
		if (baud == 434) begin
			baud <= 0;
			if (delay) begin // delays initial pulse to make sure it goes in the middle
				delay <= 0;
				baud <= 0;
			end
			else begin
				chr[bit_ptr] <= RX; // read in bit-by-bit
				if (bit_ptr == 3'b111) begin
					rc_done <= 1'b1; 
					wait_rise <= 1'b1;
				end
				bit_ptr <= bit_ptr + 1;
			end	
		end
		else
			baud <= baud + 1;
	end else if (!RX && !wait_rise) begin // begin state
		baud <= 217; // delay by half a cycle
		rc_done <= 0;
		delay <= 1;
	end else if (wait_rise) begin // waiting for end bit state
		baud <= baud + 1; 
		if (baud == 434) begin
			if (RX) begin
				wait_rise <= 0;
				baud <= 433;
			end else
				baud <= 0;
		end
	end
end
endmodule