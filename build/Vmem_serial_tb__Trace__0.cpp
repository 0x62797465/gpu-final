// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vmem_serial_tb__Syms.h"


void Vmem_serial_tb___024root__trace_chg_0_sub_0(Vmem_serial_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vmem_serial_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_chg_0\n"); );
    // Body
    Vmem_serial_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmem_serial_tb___024root*>(voidSelf);
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vmem_serial_tb___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

void Vmem_serial_tb___024root__trace_chg_0_sub_0(Vmem_serial_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_chg_0_sub_0\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__VtraceActivity[0U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__DDR2LP_CKE),2);
        bufp->chgCData(oldp+1,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__DDR2LP_CS_n),2);
    }
    if (VL_UNLIKELY(((vlSelfRef.__VtraceActivity[1U] 
                      | vlSelfRef.__VtraceActivity[2U])))) {
        bufp->chgWData(oldp+2,(vlSelfRef.mem_serial_tb__DOT__CMD_IN),128);
        bufp->chgCData(oldp+6,(vlSelfRef.mem_serial_tb__DOT__CMD_IN_VALID),4);
        bufp->chgCData(oldp+7,(vlSelfRef.mem_serial_tb__DOT__cmd_consumed_valid_local),4);
        bufp->chgIData(oldp+8,(vlSelfRef.mem_serial_tb__DOT__read_out_valid_local),32);
        bufp->chgIData(oldp+9,(vlSelfRef.mem_serial_tb__DOT__read_consumed),32);
        bufp->chgBit(oldp+10,(vlSelfRef.mem_serial_tb__DOT__cmd_in_valid_prev));
        bufp->chgCData(oldp+11,(vlSelfRef.mem_serial_tb__DOT__cmd_ptr),2);
        bufp->chgCData(oldp+12,(vlSelfRef.mem_serial_tb__DOT__cmd_ptr_prev),2);
        bufp->chgBit(oldp+13,(vlSelfRef.mem_serial_tb__DOT__n_escape));
    }
    if (VL_UNLIKELY(((vlSelfRef.__VtraceActivity[1U] 
                      | vlSelfRef.__VtraceActivity[4U])))) {
        bufp->chgBit(oldp+14,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                              .__PVT__ready));
        bufp->chgBit(oldp+15,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                              .__PVT__burstbegin));
        bufp->chgIData(oldp+16,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                                .__PVT__addr),27);
        bufp->chgBit(oldp+17,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                              .__PVT__rdata_valid));
        bufp->chgIData(oldp+18,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                                .__PVT__rdata),32);
        bufp->chgIData(oldp+19,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                                .__PVT__wdata),32);
        bufp->chgBit(oldp+20,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                              .__PVT__read_req));
        bufp->chgCData(oldp+21,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                                .__PVT__be),4);
        bufp->chgBit(oldp+22,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                              .__PVT__write_req));
        bufp->chgCData(oldp+23,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl
                                .__PVT__burstcount),5);
    }
    if (VL_UNLIKELY(((vlSelfRef.__VtraceActivity[3U] 
                      | vlSelfRef.__VtraceActivity[5U])))) {
        bufp->chgCData(oldp+24,(vlSelfRef.mem_serial_tb__DOT__dat
                                .__PVT__packets_left),4);
        bufp->chgBit(oldp+25,(vlSelfRef.mem_serial_tb__DOT__dat
                              .__PVT__write));
        bufp->chgIData(oldp+26,(vlSelfRef.mem_serial_tb__DOT__dat
                                .__PVT__addr),18);
        bufp->chgWData(oldp+27,(vlSelfRef.mem_serial_tb__DOT__dat
                                .__PVT__wdata),256);
        bufp->chgCData(oldp+35,(vlSelfRef.mem_serial_tb__DOT__dat
                                .__PVT__burstcount),5);
        bufp->chgIData(oldp+36,(vlSelfRef.mem_serial_tb__DOT__dat
                                .__PVT__byteenable),32);
        bufp->chgWData(oldp+37,(vlSelfRef.mem_serial_tb__DOT__r_queue
                                .__PVT__addresses),128);
        bufp->chgWData(oldp+41,(vlSelfRef.mem_serial_tb__DOT__r_queue
                                .__PVT__expected),1024);
        bufp->chgCData(oldp+73,(vlSelfRef.mem_serial_tb__DOT__r_queue
                                .__PVT__head),2);
        bufp->chgCData(oldp+74,(vlSelfRef.mem_serial_tb__DOT__r_queue
                                .__PVT__tail),2);
        bufp->chgBit(oldp+75,(vlSelfRef.mem_serial_tb__DOT__r_queue
                              .__PVT__full));
        bufp->chgBit(oldp+76,(vlSelfRef.mem_serial_tb__DOT__r_queue
                              .__PVT__full_next));
    }
    if (VL_UNLIKELY((vlSelfRef.__VtraceActivity[4U]))) {
        bufp->chgCData(oldp+77,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED),4);
        bufp->chgWData(oldp+78,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT),1024);
        bufp->chgIData(oldp+110,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT_VALID),32);
        bufp->chgBit(oldp+111,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done));
        bufp->chgBit(oldp+112,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_success));
        bufp->chgBit(oldp+113,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_fail));
        bufp->chgCData(oldp+114,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state),3);
        bufp->chgCData(oldp+115,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__wleft),3);
        bufp->chgCData(oldp+116,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local),4);
        bufp->chgCData(oldp+117,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr),2);
        bufp->chgCData(oldp+118,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr),5);
        bufp->chgCData(oldp+119,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr_prev),5);
        bufp->chgBit(oldp+120,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_valid_prev));
        bufp->chgBit(oldp+121,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin));
        bufp->chgIData(oldp+122,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr),27);
        bufp->chgIData(oldp+123,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata),32);
        bufp->chgBit(oldp+124,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req));
        bufp->chgBit(oldp+125,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req));
        bufp->chgBit(oldp+126,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0));
        bufp->chgBit(oldp+127,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0));
        bufp->chgIData(oldp+128,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_0),32);
        bufp->chgBit(oldp+129,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue_full));
        bufp->chgCData(oldp+130,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head),8);
        bufp->chgCData(oldp+131,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail),8);
        bufp->chgCData(oldp+132,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left),5);
        bufp->chgBit(oldp+133,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write));
        bufp->chgBit(oldp+134,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall));
        bufp->chgBit(oldp+135,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue));
        bufp->chgIData(oldp+136,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr),27);
        bufp->chgCData(oldp+137,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask),4);
        bufp->chgCData(oldp+138,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state),4);
        bufp->chgCData(oldp+139,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts),5);
    }
    bufp->chgBit(oldp+140,(vlSelfRef.mem_serial_tb__DOT__clk));
    bufp->chgBit(oldp+141,(vlSelfRef.mem_serial_tb__DOT__reset));
    bufp->chgBit(oldp+142,(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk));
}

void Vmem_serial_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root__trace_cleanup\n"); );
    // Body
    Vmem_serial_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmem_serial_tb___024root*>(voidSelf);
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->vlInst.TOP.__VtraceActivity[0U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[1U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[2U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[3U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[4U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[5U] = 0U;
}
