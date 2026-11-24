// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vmem_serial_tb__Syms.h"


VL_ATTR_COLD void Vmem_serial_tb___024root__trace_init_sub__TOP____024unit__0(Vmem_serial_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_init_sub__TOP__0(Vmem_serial_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_init_sub__TOP__0\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$unit", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vmem_serial_tb___024root__trace_init_sub__TOP____024unit__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "mem_serial_tb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+143,0,"ITERATIONS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+2,0,"CMD_IN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"CMD_IN_VALID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"CMD_CONSUMED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_WIDE(tracep,c+78,0,"READ_OUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+110,0,"READ_OUT_VALID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+140,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "dat", VerilatedTracePrefixType::STRUCT_UNPACKED, 6, 0);
    VL_TRACE_DECL_BUS(tracep,c+24,0,"packets_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+26,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_WIDE(tracep,c+27,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 255,0);
    VL_TRACE_DECL_BUS(tracep,c+35,0,"burstcount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"byteenable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "r_queue", VerilatedTracePrefixType::STRUCT_UNPACKED, 6, 0);
    VL_TRACE_DECL_WIDE(tracep,c+37,0,"addresses",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_WIDE(tracep,c+41,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+73,0,"head",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+74,0,"tail",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+76,0,"full_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+7,0,"cmd_consumed_valid_local",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"read_out_valid_local",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"read_consumed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+10,0,"cmd_in_valid_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+11,0,"cmd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+12,0,"cmd_ptr_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+13,0,"n_escape",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+144,0,"DDR2LP_CA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"DDR2LP_CKE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+145,0,"DDR2LP_CK_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+146,0,"DDR2LP_CK_p",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"DDR2LP_CS_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+147,0,"DDR2LP_DM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+148,0,"DDR2LP_DQ",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+149,0,"DDR2LP_DQS_n",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+149,0,"DDR2LP_DQS_p",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+150,0,"DDR2LP_OCT_RZQ",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+2,0,"CMD_IN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"CMD_IN_VALID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"CMD_CONSUMED",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_WIDE(tracep,c+78,0,"READ_OUT",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+110,0,"READ_OUT_VALID",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"CPU_RESET_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+140,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+151,0,"DEBUG_OUT",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+111,0,"local_init_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+112,0,"local_cal_success",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+113,0,"local_cal_fail",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"afi_half_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "avl", VerilatedTracePrefixType::STRUCT_UNPACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+14,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+15,0,"burstbegin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 26,0);
    VL_TRACE_DECL_BIT(tracep,c+17,0,"rdata_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+18,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+19,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+20,0,"read_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+22,0,"write_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"burstcount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+113,0,"debug_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+152,0,"initializing",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+153,0,"idle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+154,0,"write_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+155,0,"read_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+156,0,"write_issue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+157,0,"writing",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+114,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"wleft",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+116,0,"cmd_in_valid_local",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+117,0,"in_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+118,0,"rbuff_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+119,0,"rbuff_ptr_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+120,0,"rbuff_valid_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "mem_controller", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"global_reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+121,0,"avl_burstbegin_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+122,0,"avl_addr_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 26,0);
    VL_TRACE_DECL_BUS(tracep,c+123,0,"avl_wdata_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+158,0,"avl_be_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+124,0,"avl_read_req_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+125,0,"avl_write_req_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+159,0,"avl_size_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+111,0,"local_init_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+112,0,"local_cal_success",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+113,0,"local_cal_fail",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"afi_half_clk",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+126,0,"avl_ready_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+127,0,"avl_rdata_valid_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+128,0,"avl_rdata_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+140,0,"pll_ref_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"soft_reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+160,0,"afi_clk",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+161,0,"afi_reset_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+162,0,"afi_reset_export_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+144,0,"mem_ca",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"mem_ck",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"mem_ck_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+165,0,"mem_cke",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+166,0,"mem_cs_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+147,0,"mem_dm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+148,0,"mem_dq",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+149,0,"mem_dqs",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+149,0,"mem_dqs_n",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"mp_cmd_clk_0_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"mp_cmd_reset_n_0_reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"mp_rfifo_clk_0_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"mp_rfifo_reset_n_0_reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"mp_wfifo_clk_0_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"mp_wfifo_reset_n_0_reset_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+150,0,"oct_rzqin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+167,0,"QUEUE_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+168,0,"QUEUE_WRAPPER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"control_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+129,0,"queue_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+130,0,"head",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+131,0,"tail",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+132,0,"write_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+133,0,"consuming_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+134,0,"escape_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+135,0,"inc_queue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+136,0,"cur_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 26,0);
    VL_TRACE_DECL_BUS(tracep,c+137,0,"bmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+138,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+139,0,"bursts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_init_sub__TOP____024unit__0(Vmem_serial_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_init_sub__TOP____024unit__0\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+154,0,"STREAMING_MULTIPROCESSORS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+154,0,"STREAMING_MULTIPROCESSORS_SUB_PARTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+156,0,"TOTAL_SMSP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+169,0,"MEMORY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+170,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+156,0,"MEMCMD_IN_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+156,0,"LINES_FIFO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+171,0,"WORDS_FIFO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+152,0,"FAST_EMULATION",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+172,0,"TOTAL_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_init_top(Vmem_serial_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_init_top\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmem_serial_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vmem_serial_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmem_serial_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmem_serial_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_register(Vmem_serial_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_register\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vmem_serial_tb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vmem_serial_tb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vmem_serial_tb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vmem_serial_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_const_0_sub_0(Vmem_serial_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_const_0\n"); );
    // Body
    Vmem_serial_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmem_serial_tb___024root*>(voidSelf);
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vmem_serial_tb___024root__trace_const_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_const_0_sub_0(Vmem_serial_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_const_0_sub_0\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+143,(0x0000000aU),32);
    bufp->fullSData(oldp+144,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ca),10);
    bufp->fullBit(oldp+145,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ck_n));
    bufp->fullBit(oldp+146,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ck));
    bufp->fullCData(oldp+147,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_dm),4);
    bufp->fullIData(oldp+148,(0U),32);
    bufp->fullCData(oldp+149,(0U),4);
    bufp->fullBit(oldp+150,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__DDR2LP_OCT_RZQ));
    bufp->fullSData(oldp+151,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__DEBUG_OUT),16);
    bufp->fullIData(oldp+152,(0U),32);
    bufp->fullIData(oldp+153,(1U),32);
    bufp->fullIData(oldp+154,(2U),32);
    bufp->fullIData(oldp+155,(3U),32);
    bufp->fullIData(oldp+156,(4U),32);
    bufp->fullIData(oldp+157,(5U),32);
    bufp->fullCData(oldp+158,(0x0fU),4);
    bufp->fullCData(oldp+159,(8U),5);
    bufp->fullBit(oldp+160,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__afi_clk));
    bufp->fullBit(oldp+161,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__afi_reset_n));
    bufp->fullBit(oldp+162,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__afi_reset_export_n));
    bufp->fullBit(oldp+163,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ck));
    bufp->fullBit(oldp+164,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ck_n));
    bufp->fullBit(oldp+165,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_cke));
    bufp->fullBit(oldp+166,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_cs_n));
    bufp->fullIData(oldp+167,(0x00000100U),32);
    bufp->fullIData(oldp+168,(8U),32);
    bufp->fullIData(oldp+169,(0x00100000U),32);
    bufp->fullIData(oldp+170,(0x00000011U),32);
    bufp->fullIData(oldp+171,(0x00000020U),32);
    bufp->fullIData(oldp+172,(0x00040000U),32);
}

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_full_0_sub_0(Vmem_serial_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_full_0\n"); );
    // Body
    Vmem_serial_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmem_serial_tb___024root*>(voidSelf);
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vmem_serial_tb___024root__trace_full_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_full_0_sub_0(Vmem_serial_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_full_0_sub_0\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+0,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__DDR2LP_CKE),2);
    bufp->fullCData(oldp+1,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__DDR2LP_CS_n),2);
    bufp->fullWData(oldp+2,(vlSelfRef.mem_serial_tb__DOT__CMD_IN),128);
    bufp->fullCData(oldp+6,(vlSelfRef.mem_serial_tb__DOT__CMD_IN_VALID),4);
    bufp->fullCData(oldp+7,(vlSelfRef.mem_serial_tb__DOT__cmd_consumed_valid_local),4);
    bufp->fullIData(oldp+8,(vlSelfRef.mem_serial_tb__DOT__read_out_valid_local),32);
    bufp->fullIData(oldp+9,(vlSelfRef.mem_serial_tb__DOT__read_consumed),32);
    bufp->fullBit(oldp+10,(vlSelfRef.mem_serial_tb__DOT__cmd_in_valid_prev));
    bufp->fullCData(oldp+11,(vlSelfRef.mem_serial_tb__DOT__cmd_ptr),2);
    bufp->fullCData(oldp+12,(vlSelfRef.mem_serial_tb__DOT__cmd_ptr_prev),2);
    bufp->fullBit(oldp+13,(vlSelfRef.mem_serial_tb__DOT__n_escape));
    bufp->fullBit(oldp+14,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                           .__PVT__ready));
    bufp->fullBit(oldp+15,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                           .__PVT__burstbegin));
    bufp->fullIData(oldp+16,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                             .__PVT__addr),27);
    bufp->fullBit(oldp+17,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                           .__PVT__rdata_valid));
    bufp->fullIData(oldp+18,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                             .__PVT__rdata),32);
    bufp->fullIData(oldp+19,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                             .__PVT__wdata),32);
    bufp->fullBit(oldp+20,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                           .__PVT__read_req));
    bufp->fullCData(oldp+21,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                             .__PVT__be),4);
    bufp->fullBit(oldp+22,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                           .__PVT__write_req));
    bufp->fullCData(oldp+23,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                             .__PVT__burstcount),5);
    bufp->fullCData(oldp+24,(vlSelfRef.mem_serial_tb__DOT__dat
                             .__PVT__packets_left),4);
    bufp->fullBit(oldp+25,(vlSelfRef.mem_serial_tb__DOT__dat
                           .__PVT__write));
    bufp->fullIData(oldp+26,(vlSelfRef.mem_serial_tb__DOT__dat
                             .__PVT__addr),18);
    bufp->fullWData(oldp+27,(vlSelfRef.mem_serial_tb__DOT__dat
                             .__PVT__wdata),256);
    bufp->fullCData(oldp+35,(vlSelfRef.mem_serial_tb__DOT__dat
                             .__PVT__burstcount),5);
    bufp->fullIData(oldp+36,(vlSelfRef.mem_serial_tb__DOT__dat
                             .__PVT__byteenable),32);
    bufp->fullWData(oldp+37,(vlSelfRef.mem_serial_tb__DOT__r_queue
                             .__PVT__addresses),128);
    bufp->fullWData(oldp+41,(vlSelfRef.mem_serial_tb__DOT__r_queue
                             .__PVT__expected),1024);
    bufp->fullCData(oldp+73,(vlSelfRef.mem_serial_tb__DOT__r_queue
                             .__PVT__head),2);
    bufp->fullCData(oldp+74,(vlSelfRef.mem_serial_tb__DOT__r_queue
                             .__PVT__tail),2);
    bufp->fullBit(oldp+75,(vlSelfRef.mem_serial_tb__DOT__r_queue
                           .__PVT__full));
    bufp->fullBit(oldp+76,(vlSelfRef.mem_serial_tb__DOT__r_queue
                           .__PVT__full_next));
    bufp->fullCData(oldp+77,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED),4);
    bufp->fullWData(oldp+78,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT),1024);
    bufp->fullIData(oldp+110,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT_VALID),32);
    bufp->fullBit(oldp+111,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done));
    bufp->fullBit(oldp+112,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_success));
    bufp->fullBit(oldp+113,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_fail));
    bufp->fullCData(oldp+114,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state),3);
    bufp->fullCData(oldp+115,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__wleft),3);
    bufp->fullCData(oldp+116,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local),4);
    bufp->fullCData(oldp+117,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr),2);
    bufp->fullCData(oldp+118,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr),5);
    bufp->fullCData(oldp+119,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr_prev),5);
    bufp->fullBit(oldp+120,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_valid_prev));
    bufp->fullBit(oldp+121,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin));
    bufp->fullIData(oldp+122,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr),27);
    bufp->fullIData(oldp+123,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata),32);
    bufp->fullBit(oldp+124,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req));
    bufp->fullBit(oldp+125,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req));
    bufp->fullBit(oldp+126,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0));
    bufp->fullBit(oldp+127,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0));
    bufp->fullIData(oldp+128,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_0),32);
    bufp->fullBit(oldp+129,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue_full));
    bufp->fullCData(oldp+130,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head),8);
    bufp->fullCData(oldp+131,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail),8);
    bufp->fullCData(oldp+132,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left),5);
    bufp->fullBit(oldp+133,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write));
    bufp->fullBit(oldp+134,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall));
    bufp->fullBit(oldp+135,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue));
    bufp->fullIData(oldp+136,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr),27);
    bufp->fullCData(oldp+137,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask),4);
    bufp->fullCData(oldp+138,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state),4);
    bufp->fullCData(oldp+139,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts),5);
    bufp->fullBit(oldp+140,(vlSelfRef.mem_serial_tb__DOT__clk));
    bufp->fullBit(oldp+141,(vlSelfRef.mem_serial_tb__DOT__reset));
    bufp->fullBit(oldp+142,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk));
}
