// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmem_serial_tb.h for the primary calling header

#include "Vmem_serial_tb__pch.h"

VlCoroutine Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__0(Vmem_serial_tb___024root* vlSelf);
VlCoroutine Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__1(Vmem_serial_tb___024root* vlSelf);
VlCoroutine Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__2(Vmem_serial_tb___024root* vlSelf);

void Vmem_serial_tb___024root___eval_initial(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_initial\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__be = 0x0fU;
    }
    vlSelfRef.__VtraceActivity[1U] = 1U;
    Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

void Vmem_serial_tb___024root___eval_sample(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_sample\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin_0 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin;
    vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req_1 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req;
    vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req_2 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req;
    vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write_3 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmem_serial_tb___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

bool Vmem_serial_tb___024root___eval_ico(Vmem_serial_tb___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_ico\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmem_serial_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vmem_serial_tb___024root___timing_ready(Vmem_serial_tb___024root* vlSelf);
void Vmem_serial_tb___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmem_serial_tb___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool Vmem_serial_tb___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
void Vmem_serial_tb___024root___timing_resume(Vmem_serial_tb___024root* vlSelf);

bool Vmem_serial_tb___024root___eval_act(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_act\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (::QData)((::IData)(
                                                            ((vlSelfRef.__Vnontrivs.__VdlySched.awaitingCurrentTime() 
                                                              << 4U) 
                                                             | (((((~ (::IData)(vlSelfRef.mem_serial_tb__DOT__clk)) 
                                                                   & (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0)) 
                                                                  << 3U) 
                                                                 | (((::IData)(vlSelfRef.mem_serial_tb__DOT__clk) 
                                                                     & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0))) 
                                                                    << 2U)) 
                                                                | ((((~ (::IData)(vlSelfRef.mem_serial_tb__DOT__reset)) 
                                                                     & (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__reset__0)) 
                                                                    << 1U) 
                                                                   | ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk) 
                                                                      & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk__0))))))));
        vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk__0 
            = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk;
        vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__reset__0 
            = vlSelfRef.mem_serial_tb__DOT__reset;
        vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0 
            = vlSelfRef.mem_serial_tb__DOT__clk;
    }
    Vmem_serial_tb___024root___timing_ready(vlSelf);
    Vmem_serial_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmem_serial_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vmem_serial_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vmem_serial_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vmem_serial_tb___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_body__act
            if ((((0x000000000000000cULL & vlSelfRef.__VactTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _act_comb__TOP__0
                    vlSelfRef.mem_serial_tb__DOT__r_queue.__PVT__full_next 
                        = vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full_next;
                    vlSelfRef.mem_serial_tb__DOT__r_queue.__PVT__full 
                        = vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full;
                    vlSelfRef.mem_serial_tb__DOT__r_queue.__PVT__tail 
                        = vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail;
                    vlSelfRef.mem_serial_tb__DOT__r_queue.__PVT__head 
                        = vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head;
                    VL_ASSIGN_W(1024, vlSelfRef.mem_serial_tb__DOT__r_queue
                                .__PVT__expected, vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected);
                    VL_ASSIGN_W(128, vlSelfRef.mem_serial_tb__DOT__r_queue
                                .__PVT__addresses, vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses);
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__byteenable 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__byteenable;
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__burstcount 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__burstcount;
                    VL_ASSIGN_W(256, vlSelfRef.mem_serial_tb__DOT__dat
                                .__PVT__wdata, vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__wdata);
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__addr 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__addr;
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__write 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write;
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__packets_left 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left;
                }
                vlSelfRef.__VtraceActivity[3U] = 1U;
            }
        }
    }
    return (__VactExecute);
}

bool Vmem_serial_tb___024root___eval_inact(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_inact\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__Vnontrivs.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/mem_serial_tb.sv", 8, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vmem_serial_tb___024root___nba_sequent__TOP__0(Vmem_serial_tb___024root* vlSelf);
void Vmem_serial_tb___024root___nba_sequent__TOP__1(Vmem_serial_tb___024root* vlSelf);
void Vmem_serial_tb___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out);

bool Vmem_serial_tb___024root___eval_nba(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_nba\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vmem_serial_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((1ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                Vmem_serial_tb___024root___nba_sequent__TOP__0(vlSelf);
            }
            if ((((3ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                Vmem_serial_tb___024root___nba_sequent__TOP__1(vlSelf);
                vlSelfRef.__VtraceActivity[4U] = 1U;
            }
            if ((((0x000000000000000cULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _act_comb__TOP__0
                    vlSelfRef.mem_serial_tb__DOT__r_queue.__PVT__full_next 
                        = vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full_next;
                    vlSelfRef.mem_serial_tb__DOT__r_queue.__PVT__full 
                        = vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full;
                    vlSelfRef.mem_serial_tb__DOT__r_queue.__PVT__tail 
                        = vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail;
                    vlSelfRef.mem_serial_tb__DOT__r_queue.__PVT__head 
                        = vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head;
                    VL_ASSIGN_W(1024, vlSelfRef.mem_serial_tb__DOT__r_queue
                                .__PVT__expected, vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected);
                    VL_ASSIGN_W(128, vlSelfRef.mem_serial_tb__DOT__r_queue
                                .__PVT__addresses, vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses);
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__byteenable 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__byteenable;
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__burstcount 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__burstcount;
                    VL_ASSIGN_W(256, vlSelfRef.mem_serial_tb__DOT__dat
                                .__PVT__wdata, vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__wdata);
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__addr 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__addr;
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__write 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write;
                    vlSelfRef.mem_serial_tb__DOT__dat.__PVT__packets_left 
                        = vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left;
                }
                vlSelfRef.__VtraceActivity[5U] = 1U;
            }
        }
        Vmem_serial_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vmem_serial_tb___024root___eval_obs(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_obs\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vmem_serial_tb___024root___eval_react(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_react\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vmem_serial_tb___024root___eval_postponed(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_postponed\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vmem_serial_tb___024root____VbeforeTrig_h78d7008b__0(Vmem_serial_tb___024root* vlSelf, const char* __VeventDescription);
void Vmem_serial_tb___024root____VbeforeTrig_h78d70056__0(Vmem_serial_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__0(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::IData/*31:0*/ mem_serial_tb__DOT__unnamedblk7__DOT__addr_modulo;
    mem_serial_tb__DOT__unnamedblk7__DOT__addr_modulo = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk1__DOT__a_0;
    __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk1__DOT__a_0 = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk2__DOT__a_1;
    __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk2__DOT__a_1 = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__gen_cmd__addr_modulo_2;
    __Vtask_mem_serial_tb__DOT__gen_cmd__addr_modulo_2 = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__gen_cmd____VlefExpr_1_3;
    __Vtask_mem_serial_tb__DOT__gen_cmd____VlefExpr_1_3 = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__gen_cmd____VlefExpr_0_4;
    __Vtask_mem_serial_tb__DOT__gen_cmd____VlefExpr_0_4 = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk4__DOT__i_6;
    __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk4__DOT__i_6 = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk5__DOT__i_7;
    __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk5__DOT__i_7 = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_2_8;
    __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_2_8 = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_1_9;
    __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_1_9 = 0;
    ::IData/*31:0*/ __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_0_10;
    __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_0_10 = 0;
    // Body
    mem_serial_tb__DOT__unnamedblk7__DOT__addr_modulo = 2U;
    vlSelfRef.mem_serial_tb__DOT__n_escape = 1U;
    vlSelfRef.mem_serial_tb__DOT__CMD_IN_VALID = 0U;
    vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head = 0U;
    vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail = 0U;
    vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full = 0U;
    vlSelfRef.mem_serial_tb__DOT__cmd_consumed_valid_local = 0U;
    vlSelfRef.mem_serial_tb__DOT__cmd_ptr = 0U;
    vlSelfRef.mem_serial_tb__DOT__cmd_in_valid_prev = 0U;
    vlSelfRef.mem_serial_tb__DOT__read_consumed = 0U;
    vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full_next = 0U;
    Vmem_serial_tb___024root____VbeforeTrig_h78d7008b__0(vlSelf, 
                                                         "@(posedge mem_serial_tb.clk)");
    co_await vlSelfRef.__Vnontrivs.__VtrigSched_h78d7008b__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge mem_serial_tb.clk)", 
                                                                     "tb/mem_serial_tb.sv", 
                                                                     48);
    vlSelfRef.__VtraceActivity[2U] = 1U;
    vlSelfRef.mem_serial_tb__DOT__reset = 0U;
    __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk1__DOT__a_0 = 0U;
    __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk1__DOT__a_0 = 0U;
    while (VL_GTS_III(32, 0x0000000aU, __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk1__DOT__a_0)) {
        Vmem_serial_tb___024root____VbeforeTrig_h78d7008b__0(vlSelf, 
                                                             "@(posedge mem_serial_tb.clk)");
        co_await vlSelfRef.__Vnontrivs.__VtrigSched_h78d7008b__0.trigger(0U, 
                                                                         nullptr, 
                                                                         "@(posedge mem_serial_tb.clk)", 
                                                                         "tb/mem_serial_tb.sv", 
                                                                         51);
        vlSelfRef.__VtraceActivity[2U] = 1U;
        __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk1__DOT__a_0 
            = ((::IData)(1U) + __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk1__DOT__a_0);
    }
    vlSelfRef.mem_serial_tb__DOT__reset = 1U;
    __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk2__DOT__a_1 = 0U;
    __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk2__DOT__a_1 = 0U;
    while (VL_GTS_III(32, 0x0000000aU, __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk2__DOT__a_1)) {
        Vmem_serial_tb___024root____VbeforeTrig_h78d7008b__0(vlSelf, 
                                                             "@(posedge mem_serial_tb.clk)");
        co_await vlSelfRef.__Vnontrivs.__VtrigSched_h78d7008b__0.trigger(0U, 
                                                                         nullptr, 
                                                                         "@(posedge mem_serial_tb.clk)", 
                                                                         "tb/mem_serial_tb.sv", 
                                                                         55);
        vlSelfRef.__VtraceActivity[2U] = 1U;
        __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk2__DOT__a_1 
            = ((::IData)(1U) + __Vtask_mem_serial_tb__DOT__gpu_reset__unnamedblk2__DOT__a_1);
    }
    while ((0x00040000U >= VL_SHIFTL_III(32,32,32, (::IData)(1U), mem_serial_tb__DOT__unnamedblk7__DOT__addr_modulo))) {
        vlSelfRef.mem_serial_tb__DOT__unnamedblk7__DOT__unnamedblk8__DOT__a = 0U;
        while (VL_GTS_III(32, 0x0000000aU, vlSelfRef.mem_serial_tb__DOT__unnamedblk7__DOT__unnamedblk8__DOT__a)) {
            VL_WRITEF_NX("%h %h %h\n",3, '#',1,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full_next
                         , '#',2,(::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head)
                         , '#',2,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail);
            __Vtask_mem_serial_tb__DOT__gen_cmd__addr_modulo_2 
                = VL_SHIFTL_III(32,32,32, (::IData)(1U), mem_serial_tb__DOT__unnamedblk7__DOT__addr_modulo);
            __Vtask_mem_serial_tb__DOT__gen_cmd____VlefExpr_0_4 
                = VL_URANDOM_RANGE_I(1U, 0U);
            vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write 
                = (0U != __Vtask_mem_serial_tb__DOT__gen_cmd____VlefExpr_0_4);
            __Vtask_mem_serial_tb__DOT__gen_cmd____VlefExpr_1_3 
                = VL_URANDOM_RANGE_I((__Vtask_mem_serial_tb__DOT__gen_cmd__addr_modulo_2 
                                      - (::IData)(1U)), 0U);
            vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__addr 
                = (0x0003ffffU & __Vtask_mem_serial_tb__DOT__gen_cmd____VlefExpr_1_3);
            VL_RANDOM_W(256, vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__wdata);
            vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left 
                = (0x0000000fU & ((::IData)(2U) + ((::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write) 
                                                   << 3U)));
            vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__burstcount = 8U;
            vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__byteenable 
                = VL_RANDOM_I();
            if ((1U & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write) 
                       | (~ (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full))))) {
                if (vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write) {
                    __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk4__DOT__i_6 = 0U;
                    __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk4__DOT__i_6 = 0U;
                    while ((__Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk4__DOT__i_6 
                            < (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__burstcount))) {
                        VL_ASSIGNSEL_WI(8388608, 32, 
                                        (0x007fffffU 
                                         & ((vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__addr 
                                             + __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk4__DOT__i_6) 
                                            << 5U)), vlSelfRef.mem_serial_tb__DOT__mem_goal, vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__wdata
                                        [(7U & __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk4__DOT__i_6)]);
                        __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk4__DOT__i_6 
                            = ((::IData)(1U) + __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk4__DOT__i_6);
                    }
                } else {
                    VL_ASSIGNSEL_WI(128, 32, (0x0000007fU 
                                              & ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head) 
                                                 << 5U)), vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses, vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__addr);
                    __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk5__DOT__i_7 = 0U;
                    __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk5__DOT__i_7 = 0U;
                    while ((__Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk5__DOT__i_7 
                            < (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__burstcount))) {
                        VL_ASSIGNSEL_WI(1024, 32, (0x000003ffU 
                                                   & ((((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head) 
                                                        << 3U) 
                                                       + __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk5__DOT__i_7) 
                                                      << 5U)), vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected, vlSelfRef.mem_serial_tb__DOT__mem_goal
                                        [(0x0003ffffU 
                                          & (vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__addr 
                                             + __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk5__DOT__i_7))]);
                        __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk5__DOT__i_7 
                            = ((::IData)(1U) + __Vtask_mem_serial_tb__DOT__commit_cmd__unnamedblk5__DOT__i_7);
                    }
                    vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head 
                        = (3U & ((::IData)(1U) + (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head)));
                    if (((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head) 
                         == (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))) {
                        vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full_next = 1U;
                    }
                }
            } else {
                vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left = 0U;
            }
            VL_WRITEF_NX("%h %h %h %h %h\n",5, '#',1,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full
                         , '#',1,(1U & (~ (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write)))
                         , '#',2,(::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head)
                         , '#',2,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail
                         , '#',4,(::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left));
            while ((((((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full) 
                       & (~ (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write))) 
                      & ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head) 
                         == (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))) 
                     | (0U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left))) 
                    | (::IData)(vlSelfRef.mem_serial_tb__DOT__n_escape))) {
                Vmem_serial_tb___024root____VbeforeTrig_h78d70056__0(vlSelf, 
                                                                     "@(negedge mem_serial_tb.clk)");
                co_await vlSelfRef.__Vnontrivs.__VtrigSched_h78d70056__0.trigger(0U, 
                                                                                nullptr, 
                                                                                "@(negedge mem_serial_tb.clk)", 
                                                                                "tb/mem_serial_tb.sv", 
                                                                                108);
                vlSelfRef.__VtraceActivity[2U] = 1U;
                VL_WRITEF_NX("%h %h %h %h %h\n",5, '#',1,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full
                             , '#',1,(1U & (~ (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write)))
                             , '#',2,(::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__head)
                             , '#',2,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail
                             , '#',4,(::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left));
                __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_0_10 
                    = VL_URANDOM_RANGE_I(1U, 0U);
                vlSelfRef.mem_serial_tb__DOT__n_escape 
                    = (1U & __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_0_10);
                if (vlSelfRef.mem_serial_tb__DOT__cmd_in_valid_prev) {
                    vlSelfRef.mem_serial_tb__DOT__CMD_IN_VALID 
                        = (((~ ((::IData)(1U) << (::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr_prev))) 
                            & (::IData)(vlSelfRef.mem_serial_tb__DOT__CMD_IN_VALID)) 
                           | (0x0fU & ((1U & (~ ((::IData)(vlSelfRef.mem_serial_tb__DOT__CMD_IN_VALID) 
                                                 >> (::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr_prev)))) 
                                       << (::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr_prev))));
                }
                vlSelfRef.mem_serial_tb__DOT__cmd_in_valid_prev = 0U;
                vlSelfRef.mem_serial_tb__DOT__cmd_ptr_prev 
                    = vlSelfRef.mem_serial_tb__DOT__cmd_ptr;
                __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_1_9 
                    = VL_URANDOM_RANGE_I(1U, 0U);
                if ((((0U != __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_1_9) 
                      && (1U & (~ (((::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_consumed_valid_local) 
                                    ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__CMD_IN_VALID)) 
                                   >> (::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr))))) 
                     && (0U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left)))) {
                    vlSelfRef.mem_serial_tb__DOT__cmd_in_valid_prev = 1U;
                    if ((((::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left) 
                          <= (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__burstcount)) 
                         & (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write))) {
                        VL_ASSIGNSEL_WI(128, 32, (0x0000007fU 
                                                  & ((::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr) 
                                                     << 5U)), vlSelfRef.mem_serial_tb__DOT__CMD_IN, vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__wdata
                                        [(7U & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__burstcount) 
                                                - (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left)))]);
                    } else if ((((::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left) 
                                 == ((::IData)(1U) 
                                     + (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__burstcount))) 
                                & (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write))) {
                        VL_ASSIGNSEL_WI(128, 32, (0x0000007fU 
                                                  & ((::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr) 
                                                     << 5U)), vlSelfRef.mem_serial_tb__DOT__CMD_IN, vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__addr);
                    } else if ((((::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left) 
                                 == ((::IData)(2U) 
                                     + (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__burstcount))) 
                                & (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__write))) {
                        VL_ASSIGNSEL_WI(128, 32, (0x0000007fU 
                                                  & ((::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr) 
                                                     << 5U)), vlSelfRef.mem_serial_tb__DOT__CMD_IN, 0xffffffffU);
                    } else if ((2U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left))) {
                        VL_ASSIGNSEL_WI(128, 32, (0x0000007fU 
                                                  & ((::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr) 
                                                     << 5U)), vlSelfRef.mem_serial_tb__DOT__CMD_IN, 0U);
                    } else if (VL_LIKELY(((1U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left))))) {
                        VL_ASSIGNSEL_WI(128, 32, (0x0000007fU 
                                                  & ((::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr) 
                                                     << 5U)), vlSelfRef.mem_serial_tb__DOT__CMD_IN, vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__addr);
                    } else {
                        VL_WRITEF_NX("[%0t] %%Fatal: mem_serial_tb.sv:134: Assertion failed in %m: Invalid command state reached.\n\n",3, 'M',vlSymsp->__Vm_topNames[1].c_str(),"transfer_cmd", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1));
                        VL_STOP_MT("tb/mem_serial_tb.sv", 134, "", false);
                    }
                    vlSelfRef.mem_serial_tb__DOT__cmd_ptr 
                        = ((3U == (::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr))
                            ? 0U : (3U & ((::IData)(1U) 
                                          + (::IData)(vlSelfRef.mem_serial_tb__DOT__cmd_ptr))));
                    vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left 
                        = (0x0000000fU & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dat__DOT____PVT__packets_left) 
                                          - (::IData)(1U)));
                }
                vlSelfRef.mem_serial_tb__DOT__cmd_consumed_valid_local 
                    = vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED;
                __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_2_8 
                    = VL_URANDOM_RANGE_I(1U, 0U);
                if (VL_UNLIKELY((((0U != __Vtask_mem_serial_tb__DOT__transfer_cmd____VlefExpr_2_8) 
                                  && (1U & ((vlSelfRef.mem_serial_tb__DOT__read_out_valid_local 
                                             ^ vlSelfRef.mem_serial_tb__DOT__read_consumed) 
                                            >> (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))))))) {
                    VL_WRITEF_NX("meow\n",0);
                    if (VL_UNLIKELY(((vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                      [(0x00000018U 
                                        & ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                           << 3U))] 
                                      != vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                      [(0x00000018U 
                                        & ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                           << 3U))])))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: mem_serial_tb.sv:147: Assertion failed in %m: Read data does not match expected address: %h data: %h expected: %h\n\n",6, 'M',vlSymsp->__Vm_topNames[1].c_str(),"transfer_cmd.unnamedblk6", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses
                                     [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                     [(0x00000018U 
                                       & ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                          << 3U))], '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                     [(0x00000018U 
                                       & ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                          << 3U))]);
                        VL_STOP_MT("tb/mem_serial_tb.sv", 147, "", false);
                    }
                    if (VL_UNLIKELY(((vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                      [(0x0000001fU 
                                        & ((::IData)(1U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))] 
                                      != vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                      [(0x0000001fU 
                                        & ((::IData)(1U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))])))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: mem_serial_tb.sv:147: Assertion failed in %m: Read data does not match expected address: %h data: %h expected: %h\n\n",6, 'M',vlSymsp->__Vm_topNames[1].c_str(),"transfer_cmd.unnamedblk6", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses
                                     [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                     [(0x0000001fU 
                                       & ((::IData)(1U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                     [(0x0000001fU 
                                       & ((::IData)(1U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]);
                        VL_STOP_MT("tb/mem_serial_tb.sv", 147, "", false);
                    }
                    if (VL_UNLIKELY(((vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                      [(0x0000001fU 
                                        & ((::IData)(2U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))] 
                                      != vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                      [(0x0000001fU 
                                        & ((::IData)(2U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))])))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: mem_serial_tb.sv:147: Assertion failed in %m: Read data does not match expected address: %h data: %h expected: %h\n\n",6, 'M',vlSymsp->__Vm_topNames[1].c_str(),"transfer_cmd.unnamedblk6", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses
                                     [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                     [(0x0000001fU 
                                       & ((::IData)(2U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                     [(0x0000001fU 
                                       & ((::IData)(2U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]);
                        VL_STOP_MT("tb/mem_serial_tb.sv", 147, "", false);
                    }
                    if (VL_UNLIKELY(((vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                      [(0x0000001fU 
                                        & ((::IData)(3U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))] 
                                      != vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                      [(0x0000001fU 
                                        & ((::IData)(3U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))])))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: mem_serial_tb.sv:147: Assertion failed in %m: Read data does not match expected address: %h data: %h expected: %h\n\n",6, 'M',vlSymsp->__Vm_topNames[1].c_str(),"transfer_cmd.unnamedblk6", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses
                                     [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                     [(0x0000001fU 
                                       & ((::IData)(3U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                     [(0x0000001fU 
                                       & ((::IData)(3U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]);
                        VL_STOP_MT("tb/mem_serial_tb.sv", 147, "", false);
                    }
                    if (VL_UNLIKELY(((vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                      [(0x0000001fU 
                                        & ((::IData)(4U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))] 
                                      != vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                      [(0x0000001fU 
                                        & ((::IData)(4U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))])))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: mem_serial_tb.sv:147: Assertion failed in %m: Read data does not match expected address: %h data: %h expected: %h\n\n",6, 'M',vlSymsp->__Vm_topNames[1].c_str(),"transfer_cmd.unnamedblk6", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses
                                     [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                     [(0x0000001fU 
                                       & ((::IData)(4U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                     [(0x0000001fU 
                                       & ((::IData)(4U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]);
                        VL_STOP_MT("tb/mem_serial_tb.sv", 147, "", false);
                    }
                    if (VL_UNLIKELY(((vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                      [(0x0000001fU 
                                        & ((::IData)(5U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))] 
                                      != vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                      [(0x0000001fU 
                                        & ((::IData)(5U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))])))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: mem_serial_tb.sv:147: Assertion failed in %m: Read data does not match expected address: %h data: %h expected: %h\n\n",6, 'M',vlSymsp->__Vm_topNames[1].c_str(),"transfer_cmd.unnamedblk6", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses
                                     [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                     [(0x0000001fU 
                                       & ((::IData)(5U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                     [(0x0000001fU 
                                       & ((::IData)(5U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]);
                        VL_STOP_MT("tb/mem_serial_tb.sv", 147, "", false);
                    }
                    if (VL_UNLIKELY(((vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                      [(0x0000001fU 
                                        & ((::IData)(6U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))] 
                                      != vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                      [(0x0000001fU 
                                        & ((::IData)(6U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))])))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: mem_serial_tb.sv:147: Assertion failed in %m: Read data does not match expected address: %h data: %h expected: %h\n\n",6, 'M',vlSymsp->__Vm_topNames[1].c_str(),"transfer_cmd.unnamedblk6", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses
                                     [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                     [(0x0000001fU 
                                       & ((::IData)(6U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                     [(0x0000001fU 
                                       & ((::IData)(6U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]);
                        VL_STOP_MT("tb/mem_serial_tb.sv", 147, "", false);
                    }
                    if (VL_UNLIKELY(((vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                      [(0x0000001fU 
                                        & ((::IData)(7U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))] 
                                      != vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                      [(0x0000001fU 
                                        & ((::IData)(7U) 
                                           + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                              << 3U)))])))) {
                        VL_WRITEF_NX("[%0t] %%Fatal: mem_serial_tb.sv:147: Assertion failed in %m: Read data does not match expected address: %h data: %h expected: %h\n\n",6, 'M',vlSymsp->__Vm_topNames[1].c_str(),"transfer_cmd.unnamedblk6", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__addresses
                                     [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT
                                     [(0x0000001fU 
                                       & ((::IData)(7U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__expected
                                     [(0x0000001fU 
                                       & ((::IData)(7U) 
                                          + ((::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail) 
                                             << 3U)))]);
                        VL_STOP_MT("tb/mem_serial_tb.sv", 147, "", false);
                    }
                    vlSelfRef.mem_serial_tb__DOT__read_consumed 
                        = (((~ ((::IData)(1U) << (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))) 
                            & vlSelfRef.mem_serial_tb__DOT__read_consumed) 
                           | (0x00000000ffffffffULL 
                              & ((1U & (~ (vlSelfRef.mem_serial_tb__DOT__read_consumed 
                                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail)))) 
                                 << (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail))));
                    vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail 
                        = (3U & ((::IData)(1U) + (::IData)(vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__tail)));
                    vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full = 0U;
                    vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full_next = 0U;
                }
                vlSelfRef.mem_serial_tb__DOT__read_out_valid_local 
                    = vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT_VALID;
            }
            vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full 
                = vlSelfRef.mem_serial_tb__DOT__r_queue__DOT____PVT__full_next;
            vlSelfRef.mem_serial_tb__DOT__unnamedblk7__DOT__unnamedblk8__DOT__a 
                = ((::IData)(1U) + vlSelfRef.mem_serial_tb__DOT__unnamedblk7__DOT__unnamedblk8__DOT__a);
        }
        mem_serial_tb__DOT__unnamedblk7__DOT__addr_modulo 
            = ((::IData)(1U) + mem_serial_tb__DOT__unnamedblk7__DOT__addr_modulo);
    }
    VL_FINISH_MT("tb/mem_serial_tb.sv", 196, "");
    vlSelfRef.__VtraceActivity[2U] = 1U;
    co_return;
}

VlCoroutine Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__1(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__Vnontrivs.__VdlySched.delay(3ULL, 
                                                         nullptr, 
                                                         "tb/mem_controller_emulator.sv", 
                                                         47);
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk 
            = (1U & (~ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk)));
    }
    co_return;
}

VlCoroutine Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__2(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__Vnontrivs.__VdlySched.delay(0x000000000000000aULL, 
                                                         nullptr, 
                                                         "tb/mem_serial_tb.sv", 
                                                         22);
        vlSelfRef.mem_serial_tb__DOT__clk = (1U & (~ (::IData)(vlSelfRef.mem_serial_tb__DOT__clk)));
    }
    co_return;
}

bool Vmem_serial_tb___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___trigger_anySet__ico\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

bool Vmem_serial_tb___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___trigger_anySet__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vmem_serial_tb___024root___nba_sequent__TOP__0(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___nba_sequent__TOP__0\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->_vm_contextp__->assertCtlGet<1, 1>(VerilatedAssertCtlQuery::ASSERT_CTL_ON)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet<1, 1>(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON)) {
            if ((1U & (~ ((~ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done)) 
                          | (~ (::IData)(vlSelfRef.mem_serial_tb__DOT__reset)))))) {
                if (VL_UNLIKELY(((1U & (~ ((~ (::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req_2)) 
                                           | (::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin_0))))))) {
                    VL_WRITEF_NX("[%0t] %%Fatal: mem_controller_emulator.sv:80: Assertion failed in %m: A read was requested without a burst, this should not happen but is harmless.\n\n",3, 'M',vlSymsp->__Vm_topNames[1].c_str(),"dut.mem_controller", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1));
                    VL_STOP_MT("tb/mem_controller_emulator.sv", 80, "", false);
                }
                if (VL_UNLIKELY(((1U & (~ ((~ (::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin_0)) 
                                           | (~ (::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write_3)))))))) {
                    VL_WRITEF_NX("[%0t] %%Fatal: mem_controller_emulator.sv:88: Assertion failed in %m: A new burst was started without finishing the write.\n\n",3, 'M',vlSymsp->__Vm_topNames[1].c_str(),"dut.mem_controller", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1));
                    VL_STOP_MT("tb/mem_controller_emulator.sv", 88, "", false);
                }
                if (VL_UNLIKELY(((1U & (~ ((~ (::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin_0)) 
                                           | ((::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req_1) 
                                              | (::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req_2)))))))) {
                    VL_WRITEF_NX("[%0t] %%Fatal: mem_controller_emulator.sv:72: Assertion failed in %m: A burst was requested without a read or write, this can cause undefined behavior.\n\n",3, 'M',vlSymsp->__Vm_topNames[1].c_str(),"dut.mem_controller", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1));
                    VL_STOP_MT("tb/mem_controller_emulator.sv", 72, "", false);
                }
                if (VL_UNLIKELY(((1U & (~ ((~ (::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req_1)) 
                                           | ((::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin_0) 
                                              | (::IData)(vlSelfRef.__Vsampled_mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write_3)))))))) {
                    VL_WRITEF_NX("[%0t] %%Fatal: mem_controller_emulator.sv:96: Assertion failed in %m: A write was asserted without reason.\n\n",3, 'M',vlSymsp->__Vm_topNames[1].c_str(),"dut.mem_controller", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1));
                    VL_STOP_MT("tb/mem_controller_emulator.sv", 96, "", false);
                }
            }
        }
    }
}

void Vmem_serial_tb___024root___nba_sequent__TOP__1(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___nba_sequent__TOP__1\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*4:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__rbuff_ptr_5;
    __Vdly__mem_serial_tb__DOT__dut__DOT__rbuff_ptr_5 = 0;
    ::CData/*2:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__state_6;
    __Vdly__mem_serial_tb__DOT__dut__DOT__state_6 = 0;
    ::CData/*3:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7;
    __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7 = 0;
    ::CData/*1:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8;
    __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8 = 0;
    ::CData/*2:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__wleft_14;
    __Vdly__mem_serial_tb__DOT__dut__DOT__wleft_14 = 0;
    ::CData/*0:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall_16;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall_16 = 0;
    ::CData/*0:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue_17;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue_17 = 0;
    ::CData/*7:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 = 0;
    ::CData/*3:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 = 0;
    ::CData/*4:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts_21;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts_21 = 0;
    ::IData/*26:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr_22;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr_22 = 0;
    ::CData/*3:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask_23;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask_23 = 0;
    ::CData/*0:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0_26;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0_26 = 0;
    ::CData/*4:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left_27;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left_27 = 0;
    ::CData/*7:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head_30;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head_30 = 0;
    ::SData/*31:0*/ __VExpandSel_Lsb_1;
    ::IData/*31:0*/ __VExpandSel_Lsb_2;
    ::SData/*31:0*/ __VExpandSel_Lsb_3;
    ::IData/*31:0*/ __VExpandSel_Lsb_4;
    ::SData/*31:0*/ __VExpandSel_Lsb_5;
    ::IData/*31:0*/ __VExpandSel_Lsb_6;
    // Body
    __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED;
    __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr;
    __Vdly__mem_serial_tb__DOT__dut__DOT__wleft_14 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__wleft;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall_16 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue_17 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts_21 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr_22 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask_23 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask;
    VL_ASSIGN_W(8388608, vlSelfRef.__Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_24, vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem);
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left_27 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head_30 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head;
    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0_26 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0;
    __Vdly__mem_serial_tb__DOT__dut__DOT__state_6 = vlSelfRef.mem_serial_tb__DOT__dut__DOT__state;
    __Vdly__mem_serial_tb__DOT__dut__DOT__rbuff_ptr_5 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr;
    if ((1U & (~ (::IData)(vlSelfRef.mem_serial_tb__DOT__reset)))) {
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstcount = 8U;
    }
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__burstcount 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstcount;
    if (vlSelfRef.mem_serial_tb__DOT__reset) {
        if ((0U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
            if ((1U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                            ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                    __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7 
                        = (((~ ((::IData)(1U) << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))) 
                            & (::IData)(__Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7)) 
                           | (0x0fU & ((1U & (~ ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED) 
                                                 >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) 
                                       << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))));
                    __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8 
                        = (3U & ((::IData)(1U) + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)));
                }
            } else if ((2U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                            ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                    __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7 
                        = (((~ ((::IData)(1U) << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))) 
                            & (::IData)(__Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7)) 
                           | (0x0fU & ((1U & (~ ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED) 
                                                 >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) 
                                       << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))));
                    __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8 
                        = (3U & ((::IData)(1U) + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)));
                }
            } else if ((3U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                    if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                               >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7 
                            = (((~ ((::IData)(1U) << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))) 
                                & (::IData)(__Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7)) 
                               | (0x0fU & ((1U & (~ 
                                                  ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED) 
                                                   >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) 
                                           << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8 
                            = (3U & ((::IData)(1U) 
                                     + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)));
                    }
                }
            } else if ((4U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                    if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                               >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7 
                            = (((~ ((::IData)(1U) << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))) 
                                & (::IData)(__Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7)) 
                               | (0x0fU & ((1U & (~ 
                                                  ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED) 
                                                   >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) 
                                           << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8 
                            = (3U & ((::IData)(1U) 
                                     + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)));
                    }
                }
            } else if ((5U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                    if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                               >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7 
                            = (((~ ((::IData)(1U) << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))) 
                                & (::IData)(__Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7)) 
                               | (0x0fU & ((1U & (~ 
                                                  ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED) 
                                                   >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) 
                                           << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8 
                            = (3U & ((::IData)(1U) 
                                     + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)));
                    }
                }
            }
            if ((1U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if ((2U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                    if ((3U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                        if ((4U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                            if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                                if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                            ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                                    __Vdly__mem_serial_tb__DOT__dut__DOT__wleft_14 = 6U;
                                }
                            }
                        } else if ((5U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                            if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                                if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                            ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                                    __Vdly__mem_serial_tb__DOT__dut__DOT__wleft_14 
                                        = (7U & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__wleft) 
                                                 - (::IData)(1U)));
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((0U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
            if (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done) 
                 & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_success))) {
                __Vdly__mem_serial_tb__DOT__dut__DOT__state_6 = 1U;
            }
        } else if ((1U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
            if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                        ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                       >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                __Vdly__mem_serial_tb__DOT__dut__DOT__state_6 
                    = ((1U & vlSelfRef.mem_serial_tb__DOT__CMD_IN
                        [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))])
                        ? 2U : 3U);
            }
        } else if ((2U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
            if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                        ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                       >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                __Vdly__mem_serial_tb__DOT__dut__DOT__state_6 = 4U;
            }
        } else if ((3U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
            if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                            ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                    __Vdly__mem_serial_tb__DOT__dut__DOT__state_6 = 1U;
                }
            }
        } else if ((4U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
            if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                            ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                    __Vdly__mem_serial_tb__DOT__dut__DOT__state_6 = 5U;
                }
            }
        } else if ((5U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
            if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                            ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                    if ((1U & (~ (0U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__wleft))))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__state_6 = 1U;
                    }
                }
            }
        }
        if ((((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_valid_prev) 
              & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done)) 
             & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_success))) {
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT_VALID 
                = (((~ ((::IData)(1U) << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr_prev))) 
                    & vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT_VALID) 
                   | (0x00000000ffffffffULL & ((1U 
                                                & (~ 
                                                   (vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT_VALID 
                                                    >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr_prev)))) 
                                               << (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr_prev))));
        }
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr_prev 
            = vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr;
        if ((((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0) 
              & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done)) 
             & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_success))) {
            __Vdly__mem_serial_tb__DOT__dut__DOT__rbuff_ptr_5 
                = (0x0000001fU & ((::IData)(1U) + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr)));
            if ((0x1eU == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr))) {
                __Vdly__mem_serial_tb__DOT__dut__DOT__rbuff_ptr_5 = 0U;
            }
            VL_ASSIGNSEL_WI(1024, 32, (0x000003ffU 
                                       & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr) 
                                          << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT, vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_0);
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr 
                = __Vdly__mem_serial_tb__DOT__dut__DOT__rbuff_ptr_5;
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_valid_prev = 0U;
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_valid_prev = 1U;
        } else {
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr 
                = __Vdly__mem_serial_tb__DOT__dut__DOT__rbuff_ptr_5;
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_valid_prev = 0U;
        }
    } else {
        __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7 = 0U;
        __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8 = 0U;
        __Vdly__mem_serial_tb__DOT__dut__DOT__state_6 = 0U;
        __Vdly__mem_serial_tb__DOT__dut__DOT__rbuff_ptr_5 = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__READ_OUT_VALID = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr_prev = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_ptr 
            = __Vdly__mem_serial_tb__DOT__dut__DOT__rbuff_ptr_5;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__rbuff_valid_prev = 0U;
    }
    if (vlSelfRef.mem_serial_tb__DOT__reset) {
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_0 
            = VL_URANDOM_RANGE_I(1U, 0U);
        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall_16 
            = (0U != vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_0);
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_1 
            = VL_URANDOM_RANGE_I(1U, 0U);
        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue_17 
            = (0U != vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_1);
        if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done) {
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0 = 0U;
            if (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue) 
                 & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue_full) 
                    | ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head) 
                       != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))))) {
                if (((((((((0U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state)) 
                           | (1U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) 
                          | (2U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) 
                         | (3U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) 
                        | (4U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) 
                       | (5U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) 
                      | (6U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) 
                     | (7U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state)))) {
                    if ((0U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 
                            = (0x000000ffU & ((::IData)(1U) 
                                              + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 
                            = ((0U != vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                [(0x000000ffU & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))])
                                ? 1U : 5U);
                    } else if ((1U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 
                            = (0x000000ffU & ((::IData)(1U) 
                                              + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts_21 
                            = (0x0000001fU & vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                               [(0x000000ffU & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))]);
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 = 2U;
                    } else if ((2U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 
                            = (0x000000ffU & ((::IData)(1U) 
                                              + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr_22 
                            = (0x07ffffffU & vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                               [(0x000000ffU & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))]);
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 = 3U;
                    } else if ((3U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 
                            = (0x000000ffU & ((::IData)(1U) 
                                              + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask_23 
                            = (0x0000000fU & vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                               [(0x000000ffU & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))]);
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 = 4U;
                    } else if (VL_UNLIKELY(((4U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts_21 
                            = (0x0000001fU & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts) 
                                              - (::IData)(1U)));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 
                            = (0x000000ffU & ((::IData)(1U) 
                                              + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 
                            = ((0U == ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts) 
                                       - (::IData)(2U)))
                                ? 0U : 3U);
                        VL_WRITEF_NX("%h %h %h %h\n",4
                                     , '#',4,vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask
                                     , '#',27,vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr
                                     , '#',32,((((0x0000ff00U 
                                                  & (((8U 
                                                       & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask))
                                                       ? 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & ((::IData)(0x0018U) 
                                                             + 
                                                             ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                              << 5U))))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                         [
                                                         (((::IData)(7U) 
                                                           + 
                                                           (0x00001fffU 
                                                            & ((::IData)(0x0018U) 
                                                               + 
                                                               ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                << 5U)))) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & ((::IData)(0x0018U) 
                                                              + 
                                                              ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                               << 5U)))))) 
                                                       | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                          [
                                                          (0x000000ffU 
                                                           & (((::IData)(0x0018U) 
                                                               + 
                                                               ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                << 5U)) 
                                                              >> 5U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & ((::IData)(0x0018U) 
                                                              + 
                                                              ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                               << 5U)))))
                                                       : 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & ((::IData)(0x00000018U) 
                                                             + 
                                                             (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                              << 5U))))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                         [
                                                         (((::IData)(7U) 
                                                           + 
                                                           (0x007fffffU 
                                                            & ((::IData)(0x00000018U) 
                                                               + 
                                                               (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                << 5U)))) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & ((::IData)(0x00000018U) 
                                                              + 
                                                              (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                               << 5U)))))) 
                                                       | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                          [
                                                          (0x0003ffffU 
                                                           & (((::IData)(0x00000018U) 
                                                               + 
                                                               (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                << 5U)) 
                                                              >> 5U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & ((::IData)(0x00000018U) 
                                                              + 
                                                              (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                               << 5U)))))) 
                                                     << 8U)) 
                                                 | (0x000000ffU 
                                                    & ((4U 
                                                        & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask))
                                                        ? 
                                                       (((0U 
                                                          == 
                                                          (0x0000001fU 
                                                           & ((::IData)(0x0010U) 
                                                              + 
                                                              ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                               << 5U))))
                                                          ? 0U
                                                          : 
                                                         (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                          [
                                                          (((::IData)(7U) 
                                                            + 
                                                            (0x00001fffU 
                                                             & ((::IData)(0x0010U) 
                                                                + 
                                                                ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                 << 5U)))) 
                                                           >> 5U)] 
                                                          << 
                                                          ((::IData)(0x00000020U) 
                                                           - 
                                                           (0x0000001fU 
                                                            & ((::IData)(0x0010U) 
                                                               + 
                                                               ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                << 5U)))))) 
                                                        | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                           [
                                                           (0x000000ffU 
                                                            & (((::IData)(0x0010U) 
                                                                + 
                                                                ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                 << 5U)) 
                                                               >> 5U))] 
                                                           >> 
                                                           (0x0000001fU 
                                                            & ((::IData)(0x0010U) 
                                                               + 
                                                               ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                << 5U)))))
                                                        : 
                                                       (((0U 
                                                          == 
                                                          (0x0000001fU 
                                                           & ((::IData)(0x00000010U) 
                                                              + 
                                                              (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                               << 5U))))
                                                          ? 0U
                                                          : 
                                                         (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                          [
                                                          (((::IData)(7U) 
                                                            + 
                                                            (0x007fffffU 
                                                             & ((::IData)(0x00000010U) 
                                                                + 
                                                                (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                 << 5U)))) 
                                                           >> 5U)] 
                                                          << 
                                                          ((::IData)(0x00000020U) 
                                                           - 
                                                           (0x0000001fU 
                                                            & ((::IData)(0x00000010U) 
                                                               + 
                                                               (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                << 5U)))))) 
                                                        | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                           [
                                                           (0x0003ffffU 
                                                            & (((::IData)(0x00000010U) 
                                                                + 
                                                                (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                 << 5U)) 
                                                               >> 5U))] 
                                                           >> 
                                                           (0x0000001fU 
                                                            & ((::IData)(0x00000010U) 
                                                               + 
                                                               (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                << 5U)))))))) 
                                                << 0x00000010U) 
                                               | ((0x0000ff00U 
                                                   & (((2U 
                                                        & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask))
                                                        ? 
                                                       (((0U 
                                                          == 
                                                          (0x0000001fU 
                                                           & ((::IData)(8U) 
                                                              + 
                                                              ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                               << 5U))))
                                                          ? 0U
                                                          : 
                                                         (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                          [
                                                          (((::IData)(7U) 
                                                            + 
                                                            (0x00001fffU 
                                                             & ((::IData)(8U) 
                                                                + 
                                                                ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                 << 5U)))) 
                                                           >> 5U)] 
                                                          << 
                                                          ((::IData)(0x00000020U) 
                                                           - 
                                                           (0x0000001fU 
                                                            & ((::IData)(8U) 
                                                               + 
                                                               ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                << 5U)))))) 
                                                        | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                           [
                                                           (0x000000ffU 
                                                            & (((::IData)(8U) 
                                                                + 
                                                                ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                 << 5U)) 
                                                               >> 5U))] 
                                                           >> 
                                                           (0x0000001fU 
                                                            & ((::IData)(8U) 
                                                               + 
                                                               ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                                << 5U)))))
                                                        : 
                                                       (((0U 
                                                          == 
                                                          (0x0000001fU 
                                                           & ((::IData)(8U) 
                                                              + 
                                                              (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                               << 5U))))
                                                          ? 0U
                                                          : 
                                                         (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                          [
                                                          (((::IData)(7U) 
                                                            + 
                                                            (0x007fffffU 
                                                             & ((::IData)(8U) 
                                                                + 
                                                                (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                 << 5U)))) 
                                                           >> 5U)] 
                                                          << 
                                                          ((::IData)(0x00000020U) 
                                                           - 
                                                           (0x0000001fU 
                                                            & ((::IData)(8U) 
                                                               + 
                                                               (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                << 5U)))))) 
                                                        | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                           [
                                                           (0x0003ffffU 
                                                            & (((::IData)(8U) 
                                                                + 
                                                                (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                 << 5U)) 
                                                               >> 5U))] 
                                                           >> 
                                                           (0x0000001fU 
                                                            & ((::IData)(8U) 
                                                               + 
                                                               (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                                << 5U)))))) 
                                                      << 8U)) 
                                                  | (0x000000ffU 
                                                     & ((1U 
                                                         & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask))
                                                         ? vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                        [
                                                        (0x000000ffU 
                                                         & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))]
                                                         : vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                        [
                                                        (0x0003ffffU 
                                                         & vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr)]))))
                                     , '#',32,vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                     [(0x000000ffU 
                                       & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))]);
                        __VExpandSel_Lsb_1 = (0x00001fffU 
                                              & ((::IData)(0x0018U) 
                                                 + 
                                                 ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                  << 5U)));
                        __VExpandSel_Lsb_2 = (0x007fffffU 
                                              & ((::IData)(0x00000018U) 
                                                 + 
                                                 (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                  << 5U)));
                        __VExpandSel_Lsb_3 = (0x00001fffU 
                                              & ((::IData)(0x0010U) 
                                                 + 
                                                 ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                  << 5U)));
                        __VExpandSel_Lsb_4 = (0x007fffffU 
                                              & ((::IData)(0x00000010U) 
                                                 + 
                                                 (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                  << 5U)));
                        __VExpandSel_Lsb_5 = (0x00001fffU 
                                              & ((::IData)(8U) 
                                                 + 
                                                 ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                  << 5U)));
                        __VExpandSel_Lsb_6 = (0x007fffffU 
                                              & ((::IData)(8U) 
                                                 + 
                                                 (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                  << 5U)));
                        VL_ASSIGNSEL_WI(8388608, 32, 
                                        (0x007fffffU 
                                         & (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                            << 5U)), vlSelfRef.__Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_24, 
                                        ((((0x0000ff00U 
                                            & (((8U 
                                                 & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((::IData)(0x0018U) 
                                                       + 
                                                       ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                        << 5U))))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                   [
                                                   (((::IData)(7U) 
                                                     + __VExpandSel_Lsb_1) 
                                                    >> 5U)] 
                                                   << 
                                                   ((::IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((::IData)(0x0018U) 
                                                        + 
                                                        ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                         << 5U)))))) 
                                                 | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                    [
                                                    (__VExpandSel_Lsb_1 
                                                     >> 5U)] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((::IData)(0x0018U) 
                                                        + 
                                                        ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                         << 5U)))))
                                                 : 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((::IData)(0x00000018U) 
                                                       + 
                                                       (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                        << 5U))))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                   [
                                                   (((::IData)(7U) 
                                                     + __VExpandSel_Lsb_2) 
                                                    >> 5U)] 
                                                   << 
                                                   ((::IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((::IData)(0x00000018U) 
                                                        + 
                                                        (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                         << 5U)))))) 
                                                 | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                    [
                                                    (__VExpandSel_Lsb_2 
                                                     >> 5U)] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((::IData)(0x00000018U) 
                                                        + 
                                                        (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                         << 5U)))))) 
                                               << 8U)) 
                                           | (0x000000ffU 
                                              & ((4U 
                                                  & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask))
                                                  ? 
                                                 (((0U 
                                                    == 
                                                    (0x0000001fU 
                                                     & ((::IData)(0x0010U) 
                                                        + 
                                                        ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                         << 5U))))
                                                    ? 0U
                                                    : 
                                                   (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                    [
                                                    (((::IData)(7U) 
                                                      + __VExpandSel_Lsb_3) 
                                                     >> 5U)] 
                                                    << 
                                                    ((::IData)(0x00000020U) 
                                                     - 
                                                     (0x0000001fU 
                                                      & ((::IData)(0x0010U) 
                                                         + 
                                                         ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                          << 5U)))))) 
                                                  | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                     [
                                                     (__VExpandSel_Lsb_3 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x0000001fU 
                                                      & ((::IData)(0x0010U) 
                                                         + 
                                                         ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                          << 5U)))))
                                                  : 
                                                 (((0U 
                                                    == 
                                                    (0x0000001fU 
                                                     & ((::IData)(0x00000010U) 
                                                        + 
                                                        (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                         << 5U))))
                                                    ? 0U
                                                    : 
                                                   (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                    [
                                                    (((::IData)(7U) 
                                                      + __VExpandSel_Lsb_4) 
                                                     >> 5U)] 
                                                    << 
                                                    ((::IData)(0x00000020U) 
                                                     - 
                                                     (0x0000001fU 
                                                      & ((::IData)(0x00000010U) 
                                                         + 
                                                         (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                          << 5U)))))) 
                                                  | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                     [
                                                     (__VExpandSel_Lsb_4 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x0000001fU 
                                                      & ((::IData)(0x00000010U) 
                                                         + 
                                                         (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                          << 5U)))))))) 
                                          << 0x00000010U) 
                                         | ((0x0000ff00U 
                                             & (((2U 
                                                  & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask))
                                                  ? 
                                                 (((0U 
                                                    == 
                                                    (0x0000001fU 
                                                     & ((::IData)(8U) 
                                                        + 
                                                        ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                         << 5U))))
                                                    ? 0U
                                                    : 
                                                   (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                    [
                                                    (((::IData)(7U) 
                                                      + __VExpandSel_Lsb_5) 
                                                     >> 5U)] 
                                                    << 
                                                    ((::IData)(0x00000020U) 
                                                     - 
                                                     (0x0000001fU 
                                                      & ((::IData)(8U) 
                                                         + 
                                                         ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                          << 5U)))))) 
                                                  | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                     [
                                                     (__VExpandSel_Lsb_5 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x0000001fU 
                                                      & ((::IData)(8U) 
                                                         + 
                                                         ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail) 
                                                          << 5U)))))
                                                  : 
                                                 (((0U 
                                                    == 
                                                    (0x0000001fU 
                                                     & ((::IData)(8U) 
                                                        + 
                                                        (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                         << 5U))))
                                                    ? 0U
                                                    : 
                                                   (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                    [
                                                    (((::IData)(7U) 
                                                      + __VExpandSel_Lsb_6) 
                                                     >> 5U)] 
                                                    << 
                                                    ((::IData)(0x00000020U) 
                                                     - 
                                                     (0x0000001fU 
                                                      & ((::IData)(8U) 
                                                         + 
                                                         (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                          << 5U)))))) 
                                                  | (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                     [
                                                     (__VExpandSel_Lsb_6 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x0000001fU 
                                                      & ((::IData)(8U) 
                                                         + 
                                                         (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
                                                          << 5U)))))) 
                                                << 8U)) 
                                            | (0x000000ffU 
                                               & ((1U 
                                                   & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask))
                                                   ? vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                                                  [
                                                  (0x000000ffU 
                                                   & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))]
                                                   : vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                                                  [
                                                  (0x0003ffffU 
                                                   & vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr)])))));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr_22 
                            = (0x07ffffffU & ((::IData)(1U) 
                                              + vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr));
                    } else if ((5U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 
                            = (0x000000ffU & ((::IData)(1U) 
                                              + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts_21 
                            = (0x0000001fU & vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                               [(0x000000ffU & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))]);
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 = 6U;
                    } else if ((6U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state))) {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 
                            = (0x000000ffU & ((::IData)(1U) 
                                              + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)));
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr_22 
                            = (0x07ffffffU & vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue
                               [(0x000000ffU & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail))]);
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 = 7U;
                    } else {
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts_21 
                            = (0x0000001fU & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts) 
                                              - (::IData)(1U)));
                        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0 = 1U;
                        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_0 
                            = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem
                            [(0x0003ffffU & vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr)];
                        if ((0U == ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts) 
                                    - (::IData)(2U)))) {
                            __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 = 0U;
                        }
                        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr_22 
                            = (0x07ffffffU & ((::IData)(1U) 
                                              + vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr));
                    }
                }
            }
            if ((1U & ((~ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0)) 
                       & (~ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue_full))))) {
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall) {
                    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0_26 = 1U;
                }
            } else if (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) 
                        & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin) 
                           | ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write) 
                              & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req))))) {
                if (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req) 
                     & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write))) {
                    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left_27 
                        = (0x0000001fU & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left) 
                                          - (::IData)(1U)));
                    VL_ASSIGNSEL_WI(8192, 32, (0x00001fffU 
                                               & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, 0x0000000fU);
                    if ((0U == ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left) 
                                - (::IData)(2U)))) {
                        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write = 0U;
                    }
                    VL_ASSIGNSEL_WI(8192, 32, (0x0100U 
                                               & (((::IData)(1U) 
                                                   + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata);
                    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head_30 
                        = (0x000000ffU & ((::IData)(2U) 
                                          + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)));
                } else if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req) {
                    VL_ASSIGNSEL_WI(8192, 32, (0x00001fffU 
                                               & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, 0xffffffffU);
                    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left_27 = 8U;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write = 1U;
                    VL_ASSIGNSEL_WI(8192, 32, (0x0100U 
                                               & (((::IData)(1U) 
                                                   + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, 8U);
                    VL_ASSIGNSEL_WI(8192, 32, (0x0100U 
                                               & (((::IData)(2U) 
                                                   + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr);
                    VL_ASSIGNSEL_WI(8192, 32, (0x0100U 
                                               & (((::IData)(3U) 
                                                   + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, 0x0000000fU);
                    VL_ASSIGNSEL_WI(8192, 32, (0x0100U 
                                               & (((::IData)(4U) 
                                                   + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata);
                    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head_30 
                        = (0x000000ffU & ((::IData)(5U) 
                                          + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)));
                } else if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req) {
                    VL_ASSIGNSEL_WI(8192, 32, (0x00001fffU 
                                               & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, 0U);
                    VL_ASSIGNSEL_WI(8192, 32, (0x0100U 
                                               & (((::IData)(1U) 
                                                   + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, 8U);
                    VL_ASSIGNSEL_WI(8192, 32, (0x0100U 
                                               & (((::IData)(2U) 
                                                   + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)) 
                                                  << 5U)), vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr);
                    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head_30 
                        = (0x000000ffU & ((::IData)(3U) 
                                          + (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head)));
                }
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue_full) {
                    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0_26 = 0U;
                } else if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall) {
                    __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0_26 = 1U;
                }
            }
        } else if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall) {
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__unnamedblk1__DOT__i = 0U;
            __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head_30 = 0U;
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done = 1U;
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_success = 1U;
            __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0_26 = 1U;
            while ((0x00040000U > vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__unnamedblk1__DOT__i)) {
                VL_ASSIGNSEL_WI(8388608, 32, (0x007fffffU 
                                              & (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__unnamedblk1__DOT__i 
                                                 << 5U)), vlSelfRef.__Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_24, 0U);
                vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__unnamedblk1__DOT__i 
                    = ((::IData)(1U) + vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__unnamedblk1__DOT__i);
            }
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0 = 0U;
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_0 = 0U;
            vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write = 0U;
            __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left_27 = 0U;
            __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20 = 0U;
            __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19 = 0U;
        }
    } else {
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_2 
            = VL_URANDOM_RANGE_I(1U, 0U);
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_success = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_fail = 0U;
        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall_16 
            = (0U != vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_2);
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_3 
            = VL_URANDOM_RANGE_I(1U, 0U);
        __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue_17 
            = (0U != vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_3);
    }
    if (vlSelfRef.mem_serial_tb__DOT__reset) {
        if ((0U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
            if ((1U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin = 0U;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req = 0U;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req = 0U;
                }
            } else if ((2U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin = 0U;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req = 0U;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req = 0U;
                }
            } else if ((3U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin 
                        = (1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                  ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                 >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)));
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req 
                        = (1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                  ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                 >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)));
                    if ((1U & (~ (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                   ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                  >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))))) {
                        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req = 0U;
                    }
                }
            } else if ((4U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin 
                        = (1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                  ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                 >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)));
                    if ((1U & (~ (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                   ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                  >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))))) {
                        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req = 0U;
                    }
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req 
                        = (1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                  ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                 >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)));
                }
            } else if ((5U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin = 0U;
                    if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                               >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req = 1U;
                        if ((0U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__wleft))) {
                            vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req = 1U;
                        }
                    } else {
                        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req = 0U;
                    }
                }
            }
            if ((1U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                if ((2U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                    if ((3U != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                        if ((4U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                            if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                                if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                            ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata 
                                        = vlSelfRef.mem_serial_tb__DOT__CMD_IN
                                        [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))];
                                }
                            }
                        } else if ((5U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                            if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                                if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                            ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                           >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata 
                                        = vlSelfRef.mem_serial_tb__DOT__CMD_IN
                                        [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))];
                                }
                            }
                        }
                    }
                }
                if ((2U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                    if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                               >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr 
                            = (0x07ffffffU & vlSelfRef.mem_serial_tb__DOT__CMD_IN
                               [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))]);
                    }
                } else if ((3U == (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__state))) {
                    if (vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0) {
                        if ((1U & (((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local) 
                                    ^ (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED)) 
                                   >> (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr)))) {
                            vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr 
                                = (0x07ffffffU & vlSelfRef.mem_serial_tb__DOT__CMD_IN
                                   [(3U & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr))]);
                        }
                    }
                }
            }
        }
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local 
            = vlSelfRef.mem_serial_tb__DOT__CMD_IN_VALID;
    } else {
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local = 0U;
    }
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall_16;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue_17;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state_20;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts_21;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr_22;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask_23;
    VL_ASSIGN_W(8388608, vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem, vlSelfRef.__Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_24);
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left_27;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail_19;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head_30;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue_full 
        = ((0x0000000aU >= (0x000000ffU & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head) 
                                           - (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)))) 
           & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head) 
              != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)));
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__rdata_valid 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__rdata 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_0;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__wleft = __Vdly__mem_serial_tb__DOT__dut__DOT__wleft_14;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__state = __Vdly__mem_serial_tb__DOT__dut__DOT__state_6;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__in_ptr 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__in_ptr_8;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED_7;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0 
        = __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0_26;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__burstbegin 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__read_req 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__wdata 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__addr 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__write_req 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req;
    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__ready 
        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0;
}

void Vmem_serial_tb___024root___timing_ready(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___timing_ready\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((((4ULL & vlSelfRef.__VactTriggered[0U])) != 0ULL)) {
        vlSelfRef.__Vnontrivs.__VtrigSched_h78d7008b__0.ready(
                                                              "@(posedge mem_serial_tb.clk)");
    }
    if ((((8ULL & vlSelfRef.__VactTriggered[0U])) != 0ULL)) {
        vlSelfRef.__Vnontrivs.__VtrigSched_h78d70056__0.ready(
                                                              "@(negedge mem_serial_tb.clk)");
    }
}

void Vmem_serial_tb___024root___timing_resume(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___timing_resume\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vnontrivs.__VtrigSched_h78d7008b__0.moveToResumeQueue(
                                                                      "@(posedge mem_serial_tb.clk)");
    vlSelfRef.__Vnontrivs.__VtrigSched_h78d70056__0.moveToResumeQueue(
                                                                      "@(negedge mem_serial_tb.clk)");
    vlSelfRef.__Vnontrivs.__VtrigSched_h78d7008b__0.resume(
                                                           "@(posedge mem_serial_tb.clk)");
    vlSelfRef.__Vnontrivs.__VtrigSched_h78d70056__0.resume(
                                                           "@(negedge mem_serial_tb.clk)");
    if ((((0x0000000000000010ULL & vlSelfRef.__VactTriggered[0U])) != 0ULL)) {
        vlSelfRef.__Vnontrivs.__VdlySched.resume();
    }
}

void Vmem_serial_tb___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((0U >= n));
}

void Vmem_serial_tb___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___trigger_clear__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((::IData)(1U) + n);
    } while ((1U > n));
}

void Vmem_serial_tb___024root____VbeforeTrig_h78d7008b__0(Vmem_serial_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root____VbeforeTrig_h78d7008b__0\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::VlUnpacked<::QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (::QData)((::IData)(((((~ (::IData)(vlSelfRef.mem_serial_tb__DOT__clk)) 
                                        & (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0)) 
                                       << 3U) | (((::IData)(vlSelfRef.mem_serial_tb__DOT__clk) 
                                                  & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0))) 
                                                 << 2U))));
    vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0 
        = vlSelfRef.mem_serial_tb__DOT__clk;
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__Vnontrivs.__VtrigSched_h78d7008b__0.ready(__VeventDescription);
    }
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__Vnontrivs.__VtrigSched_h78d70056__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vmem_serial_tb___024root____VbeforeTrig_h78d70056__0(Vmem_serial_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root____VbeforeTrig_h78d70056__0\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::VlUnpacked<::QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (::QData)((::IData)(((((~ (::IData)(vlSelfRef.mem_serial_tb__DOT__clk)) 
                                        & (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0)) 
                                       << 3U) | (((::IData)(vlSelfRef.mem_serial_tb__DOT__clk) 
                                                  & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0))) 
                                                 << 2U))));
    vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0 
        = vlSelfRef.mem_serial_tb__DOT__clk;
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__Vnontrivs.__VtrigSched_h78d7008b__0.ready(__VeventDescription);
    }
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__Vnontrivs.__VtrigSched_h78d70056__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vmem_serial_tb___024root___eval_debug_assertions(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_debug_assertions\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
