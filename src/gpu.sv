`include "params.svh"
module gpu (
    input CLK,
    input CPU_RESET_n,
    input UART_RX,
    output UART_TX
);

genvar i;
generate
    for (i = 0; i++; i < STREAMING_MANAGERS) begin
        sm sm (CLK, CPU_RESET_n, STREAM)
    end
endgenerate

endmodule