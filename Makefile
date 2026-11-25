all: ddr_frontend_tb

ddr_frontend_tb: src/ddr_frontend.sv src/types.svh src/params.svh tb/mem_controller_emulator.sv tb/ddr_frontend_tb.sv
	verilator -Wno-fatal --trace --binary --sv -Isrc src/ddr_frontend.sv src/types.svh src/params.svh tb/mem_controller_emulator.sv tb/ddr_frontend_tb.sv --top-module ddr_frontend_tb --Mdir build
	build/Vddr_frontend_tb

clean:
	rm -rf build