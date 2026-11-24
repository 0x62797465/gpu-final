all: mem_serial_tb

mem_serial_tb: src/mem_serial.sv src/types.svh src/params.svh tb/mem_controller_emulator.sv tb/mem_serial_tb.sv
	verilator -Wno-fatal --trace --binary --sv -Isrc src/mem_serial.sv src/types.svh src/params.svh tb/mem_controller_emulator.sv tb/mem_serial_tb.sv --top-module mem_serial_tb --Mdir build
	build/Vmem_serial_tb

clean:
	rm -rf build