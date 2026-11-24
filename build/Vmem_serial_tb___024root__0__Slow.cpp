// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmem_serial_tb.h for the primary calling header

#include "Vmem_serial_tb__pch.h"

void Vmem_serial_tb___024root___timing_ready(Vmem_serial_tb___024root* vlSelf);

VL_ATTR_COLD void Vmem_serial_tb___024root___eval_static(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_static\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.mem_serial_tb__DOT__clk = 0U;
        vlSelfRef.mem_serial_tb__DOT__reset = 0U;
        vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk = 0U;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__reset__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0 = 0U;
    Vmem_serial_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((::IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmem_serial_tb___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmem_serial_tb___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool Vmem_serial_tb___024root___eval_stl(Vmem_serial_tb___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_stl\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmem_serial_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vmem_serial_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _stl_comb__TOP__0
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__DDR2LP_CS_n 
                        = ((2U & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__DDR2LP_CS_n)) 
                           | (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_cs_n));
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__DDR2LP_CKE 
                        = ((2U & (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__DDR2LP_CKE)) 
                           | (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_cke));
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue_full 
                        = ((0x0000000aU >= (0x000000ffU 
                                            & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head) 
                                               - (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)))) 
                           & ((::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head) 
                              != (::IData)(vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail)));
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
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__burstcount 
                        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstcount;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__write_req 
                        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__read_req 
                        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__wdata 
                        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__rdata 
                        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_0;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__rdata_valid 
                        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__addr 
                        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__burstbegin 
                        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin;
                    vlSelfRef.mem_serial_tb__DOT__dut__DOT__avl.__PVT__ready 
                        = vlSelfRef.mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0;
                }
                {
                    // Inlined CFunc: __VtraceActivitySetAll
                    vlSelfRef.__VtraceActivity[0U] = 1U;
                    vlSelfRef.__VtraceActivity[1U] = 1U;
                    vlSelfRef.__VtraceActivity[2U] = 1U;
                    vlSelfRef.__VtraceActivity[3U] = 1U;
                    vlSelfRef.__VtraceActivity[4U] = 1U;
                    vlSelfRef.__VtraceActivity[5U] = 1U;
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__stl(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_dump_triggers__stl\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vmem_serial_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmem_serial_tb___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__ico(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_dump_triggers__ico\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vmem_serial_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmem_serial_tb___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__act(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_dump_triggers__act\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vmem_serial_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__nba(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_dump_triggers__nba\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vmem_serial_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__obs(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_dump_triggers__obs\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__react(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_dump_triggers__react\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmem_serial_tb___024root___eval_final(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___eval_final\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmem_serial_tb___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(Vmem_serial_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vmem_serial_tb___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___trigger_anySet__stl\n"); );
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

bool Vmem_serial_tb___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmem_serial_tb___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(Vmem_serial_tb___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vmem_serial_tb___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmem_serial_tb___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (::IData)(Vmem_serial_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge mem_serial_tb.dut.mem_controller.control_clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge mem_serial_tb.reset)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge mem_serial_tb.clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge mem_serial_tb.clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmem_serial_tb___024root___ctor_var_reset(Vmem_serial_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmem_serial_tb___024root___ctor_var_reset\n"); );
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->mem_serial_tb__DOT__CMD_IN, __VscopeHash, 2559443612006716382ull);
    vlSelf->mem_serial_tb__DOT__CMD_IN_VALID = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3995377643766885175ull);
    VL_SCOPED_RAND_RESET_W(8388608, vlSelf->mem_serial_tb__DOT__mem_goal, __VscopeHash, 10214978579464339021ull);
    vlSelf->mem_serial_tb__DOT__dat__DOT____PVT__byteenable = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11617331330105468563ull);
    vlSelf->mem_serial_tb__DOT__dat__DOT____PVT__burstcount = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16762354846110960575ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->mem_serial_tb__DOT__dat__DOT____PVT__wdata, __VscopeHash, 13850158059386453594ull);
    vlSelf->mem_serial_tb__DOT__dat__DOT____PVT__addr = VL_SCOPED_RAND_RESET_I(18, __VscopeHash, 12544824204525859949ull);
    vlSelf->mem_serial_tb__DOT__dat__DOT____PVT__write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8072336105468150748ull);
    vlSelf->mem_serial_tb__DOT__dat__DOT____PVT__packets_left = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2492331604215453299ull);
    vlSelf->mem_serial_tb__DOT__dat.__PVT__packets_left = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8807403895629022272ull);
    vlSelf->mem_serial_tb__DOT__dat.__PVT__write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8807403895629022272ull);
    vlSelf->mem_serial_tb__DOT__dat.__PVT__addr = VL_SCOPED_RAND_RESET_I(18, __VscopeHash, 8807403895629022272ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->mem_serial_tb__DOT__dat.__PVT__wdata, __VscopeHash, 8807403895629022272ull);
    vlSelf->mem_serial_tb__DOT__dat.__PVT__burstcount = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8807403895629022272ull);
    vlSelf->mem_serial_tb__DOT__dat.__PVT__byteenable = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8807403895629022272ull);
    vlSelf->mem_serial_tb__DOT__r_queue__DOT____PVT__full_next = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6187927390075949232ull);
    vlSelf->mem_serial_tb__DOT__r_queue__DOT____PVT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6500060603828359540ull);
    vlSelf->mem_serial_tb__DOT__r_queue__DOT____PVT__tail = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12193822237948698511ull);
    vlSelf->mem_serial_tb__DOT__r_queue__DOT____PVT__head = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14961726021387819358ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->mem_serial_tb__DOT__r_queue__DOT____PVT__expected, __VscopeHash, 7900238892510962962ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->mem_serial_tb__DOT__r_queue__DOT____PVT__addresses, __VscopeHash, 15947438063690541746ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->mem_serial_tb__DOT__r_queue.__PVT__addresses, __VscopeHash, 8978376641960705220ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->mem_serial_tb__DOT__r_queue.__PVT__expected, __VscopeHash, 8978376641960705220ull);
    vlSelf->mem_serial_tb__DOT__r_queue.__PVT__head = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8978376641960705220ull);
    vlSelf->mem_serial_tb__DOT__r_queue.__PVT__tail = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8978376641960705220ull);
    vlSelf->mem_serial_tb__DOT__r_queue.__PVT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8978376641960705220ull);
    vlSelf->mem_serial_tb__DOT__r_queue.__PVT__full_next = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8978376641960705220ull);
    vlSelf->mem_serial_tb__DOT__cmd_consumed_valid_local = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14097725125424656262ull);
    vlSelf->mem_serial_tb__DOT__read_out_valid_local = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10502474293872765667ull);
    vlSelf->mem_serial_tb__DOT__read_consumed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5913625212106148151ull);
    vlSelf->mem_serial_tb__DOT__cmd_in_valid_prev = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5394836320224997370ull);
    vlSelf->mem_serial_tb__DOT__cmd_ptr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2630920399791235836ull);
    vlSelf->mem_serial_tb__DOT__cmd_ptr_prev = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10707319515049853523ull);
    vlSelf->mem_serial_tb__DOT__n_escape = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10183594825686711820ull);
    vlSelf->mem_serial_tb__DOT__unnamedblk7__DOT__unnamedblk8__DOT__a = 0;
    vlSelf->mem_serial_tb__DOT__dut__DOT__DDR2LP_CKE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15314193023497124874ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__DDR2LP_CS_n = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17410442779691295686ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__DDR2LP_OCT_RZQ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10858652332857817344ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6248045164963422458ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->mem_serial_tb__DOT__dut__DOT__READ_OUT, __VscopeHash, 16339591452285393999ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__READ_OUT_VALID = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11443877305409436750ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__DEBUG_OUT = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15724440610684806735ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstcount = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2979102695803124088ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11498456431814064235ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7320520658071086382ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11011326882957733376ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr = VL_SCOPED_RAND_RESET_I(27, __VscopeHash, 4124997499661251560ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10036055926137727077ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__burstbegin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__addr = VL_SCOPED_RAND_RESET_I(27, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__rdata_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__read_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__write_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__avl.__PVT__burstcount = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2692409963552754211ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4366576571241832977ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__wleft = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13357971225666827752ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12732591868950659358ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__in_ptr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3913327542843830563ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__rbuff_ptr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16218675168984216974ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__rbuff_ptr_prev = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1478824502631319581ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__rbuff_valid_prev = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9832248357119639640ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9099176531270508833ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_success = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6451171215142860643ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_fail = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9594606024238031290ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13942056438934547052ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17552856392003165930ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14858726513412682205ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__afi_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4212530607643465705ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__afi_reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10602338819401308739ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__afi_reset_export_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14073097148263315849ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ca = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 12830244044012907056ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ck = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7275867683449149410ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ck_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3820510301477809780ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_cke = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16287280366690279490ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_cs_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17209097326485590376ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_dm = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13124129251537006201ull);
    VL_SCOPED_RAND_RESET_W(8388608, vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem, __VscopeHash, 5351024801093591898ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17882137389737625575ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7378371676424559687ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16531184437682158351ull);
    VL_SCOPED_RAND_RESET_W(8192, vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue, __VscopeHash, 845580691824069690ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16433952346228267895ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7306289827898428144ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 986405276187036415ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5363818783153233134ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr = VL_SCOPED_RAND_RESET_I(27, __VscopeHash, 12428834246844407681ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1264183001691078876ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11471956466767848757ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1780739680404317249ull);
    vlSelf->mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__unnamedblk1__DOT__i = 0;
    VL_ZERO_W(8388608, vlSelf->__Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_24);
    vlSelf->__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin_0 = 0;
    vlSelf->__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req_1 = 0;
    vlSelf->__Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req_2 = 0;
    vlSelf->__Vsampled_mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write_3 = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 1);
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 1);
    vlSelf->__VactTriggeredAcc[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggeredAcc.data(), sizeof(vlSelf->__VactTriggeredAcc[0]), 1);
    vlSelf->__Vtrigprevexpr___TOP__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__mem_serial_tb__DOT__reset__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 1);
    vlSelf->__Vi = 0;
    vlSelf->__VtraceActivity[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VtraceActivity.data(), sizeof(vlSelf->__VtraceActivity[0]), 6);
}
