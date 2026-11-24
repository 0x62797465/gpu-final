// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmem_serial_tb.h for the primary calling header

#ifndef VERILATED_VMEM_SERIAL_TB___024ROOT_H_
#define VERILATED_VMEM_SERIAL_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
#include "Vmem_serial_tb___024root.h"


class Vmem_serial_tb__Syms;
struct Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod1__struct__0 {
    ::CData/*3:0*/ __PVT__packets_left;
    ::CData/*0:0*/ __PVT__write;
    ::IData/*17:0*/ __PVT__addr;
    ::VlWide<8>/*255:0*/ __PVT__wdata;
    ::CData/*4:0*/ __PVT__burstcount;
    ::IData/*31:0*/ __PVT__byteenable;

    bool operator==(const Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod1__struct__0& rhs) const {
        return __PVT__packets_left == rhs.__PVT__packets_left
            && __PVT__write == rhs.__PVT__write
            && __PVT__addr == rhs.__PVT__addr
            && __PVT__wdata == rhs.__PVT__wdata
            && __PVT__burstcount == rhs.__PVT__burstcount
            && __PVT__byteenable == rhs.__PVT__byteenable;
    }
    bool operator!=(const Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod1__struct__0& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod1__struct__0& rhs) const {
        if (__PVT__packets_left < rhs.__PVT__packets_left) return true;
        if (rhs.__PVT__packets_left < __PVT__packets_left) return false;
        if (__PVT__write < rhs.__PVT__write) return true;
        if (rhs.__PVT__write < __PVT__write) return false;
        if (__PVT__addr < rhs.__PVT__addr) return true;
        if (rhs.__PVT__addr < __PVT__addr) return false;
        if (__PVT__wdata < rhs.__PVT__wdata) return true;
        if (rhs.__PVT__wdata < __PVT__wdata) return false;
        if (__PVT__burstcount < rhs.__PVT__burstcount) return true;
        if (rhs.__PVT__burstcount < __PVT__burstcount) return false;
        if (__PVT__byteenable < rhs.__PVT__byteenable) return true;
        if (rhs.__PVT__byteenable < __PVT__byteenable) return false;
        return false;
    }
};
template <>
struct VlIsCustomStruct<Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod1__struct__0> : public std::true_type {};
struct Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod2__struct__0 {
    ::VlWide<4>/*127:0*/ __PVT__addresses;
    ::VlWide<32>/*1023:0*/ __PVT__expected;
    ::CData/*1:0*/ __PVT__head;
    ::CData/*1:0*/ __PVT__tail;
    ::CData/*0:0*/ __PVT__full;
    ::CData/*0:0*/ __PVT__full_next;

    bool operator==(const Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod2__struct__0& rhs) const {
        return __PVT__addresses == rhs.__PVT__addresses
            && __PVT__expected == rhs.__PVT__expected
            && __PVT__head == rhs.__PVT__head
            && __PVT__tail == rhs.__PVT__tail
            && __PVT__full == rhs.__PVT__full
            && __PVT__full_next == rhs.__PVT__full_next;
    }
    bool operator!=(const Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod2__struct__0& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod2__struct__0& rhs) const {
        if (__PVT__addresses < rhs.__PVT__addresses) return true;
        if (rhs.__PVT__addresses < __PVT__addresses) return false;
        if (__PVT__expected < rhs.__PVT__expected) return true;
        if (rhs.__PVT__expected < __PVT__expected) return false;
        if (__PVT__head < rhs.__PVT__head) return true;
        if (rhs.__PVT__head < __PVT__head) return false;
        if (__PVT__tail < rhs.__PVT__tail) return true;
        if (rhs.__PVT__tail < __PVT__tail) return false;
        if (__PVT__full < rhs.__PVT__full) return true;
        if (rhs.__PVT__full < __PVT__full) return false;
        if (__PVT__full_next < rhs.__PVT__full_next) return true;
        if (rhs.__PVT__full_next < __PVT__full_next) return false;
        return false;
    }
};
template <>
struct VlIsCustomStruct<Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod2__struct__0> : public std::true_type {};
struct Vmem_serial_tb_mem_serial_tb__DOT__dut__DOT____typeimpmod1__struct__0 {
    ::CData/*0:0*/ __PVT__ready;
    ::CData/*0:0*/ __PVT__burstbegin;
    ::IData/*26:0*/ __PVT__addr;
    ::CData/*0:0*/ __PVT__rdata_valid;
    ::IData/*31:0*/ __PVT__rdata;
    ::IData/*31:0*/ __PVT__wdata;
    ::CData/*0:0*/ __PVT__read_req;
    ::CData/*3:0*/ __PVT__be;
    ::CData/*0:0*/ __PVT__write_req;
    ::CData/*4:0*/ __PVT__burstcount;

    bool operator==(const Vmem_serial_tb_mem_serial_tb__DOT__dut__DOT____typeimpmod1__struct__0& rhs) const {
        return __PVT__ready == rhs.__PVT__ready
            && __PVT__burstbegin == rhs.__PVT__burstbegin
            && __PVT__addr == rhs.__PVT__addr
            && __PVT__rdata_valid == rhs.__PVT__rdata_valid
            && __PVT__rdata == rhs.__PVT__rdata
            && __PVT__wdata == rhs.__PVT__wdata
            && __PVT__read_req == rhs.__PVT__read_req
            && __PVT__be == rhs.__PVT__be
            && __PVT__write_req == rhs.__PVT__write_req
            && __PVT__burstcount == rhs.__PVT__burstcount;
    }
    bool operator!=(const Vmem_serial_tb_mem_serial_tb__DOT__dut__DOT____typeimpmod1__struct__0& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Vmem_serial_tb_mem_serial_tb__DOT__dut__DOT____typeimpmod1__struct__0& rhs) const {
        if (__PVT__ready < rhs.__PVT__ready) return true;
        if (rhs.__PVT__ready < __PVT__ready) return false;
        if (__PVT__burstbegin < rhs.__PVT__burstbegin) return true;
        if (rhs.__PVT__burstbegin < __PVT__burstbegin) return false;
        if (__PVT__addr < rhs.__PVT__addr) return true;
        if (rhs.__PVT__addr < __PVT__addr) return false;
        if (__PVT__rdata_valid < rhs.__PVT__rdata_valid) return true;
        if (rhs.__PVT__rdata_valid < __PVT__rdata_valid) return false;
        if (__PVT__rdata < rhs.__PVT__rdata) return true;
        if (rhs.__PVT__rdata < __PVT__rdata) return false;
        if (__PVT__wdata < rhs.__PVT__wdata) return true;
        if (rhs.__PVT__wdata < __PVT__wdata) return false;
        if (__PVT__read_req < rhs.__PVT__read_req) return true;
        if (rhs.__PVT__read_req < __PVT__read_req) return false;
        if (__PVT__be < rhs.__PVT__be) return true;
        if (rhs.__PVT__be < __PVT__be) return false;
        if (__PVT__write_req < rhs.__PVT__write_req) return true;
        if (rhs.__PVT__write_req < __PVT__write_req) return false;
        if (__PVT__burstcount < rhs.__PVT__burstcount) return true;
        if (rhs.__PVT__burstcount < __PVT__burstcount) return false;
        return false;
    }
};
template <>
struct VlIsCustomStruct<Vmem_serial_tb_mem_serial_tb__DOT__dut__DOT____typeimpmod1__struct__0> : public std::true_type {};

class alignas(VL_CACHE_LINE_BYTES) Vmem_serial_tb___024root final {
  public:

    // TRIVIALLY CONSTRUCTIBLE STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        ::CData/*3:0*/ mem_serial_tb__DOT__CMD_IN_VALID;
        ::CData/*0:0*/ mem_serial_tb__DOT__clk;
        ::CData/*0:0*/ mem_serial_tb__DOT__reset;
        ::CData/*4:0*/ mem_serial_tb__DOT__dat__DOT____PVT__burstcount;
        ::CData/*0:0*/ mem_serial_tb__DOT__dat__DOT____PVT__write;
        ::CData/*3:0*/ mem_serial_tb__DOT__dat__DOT____PVT__packets_left;
        Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod1__struct__0 mem_serial_tb__DOT__dat;
        ::CData/*0:0*/ mem_serial_tb__DOT__r_queue__DOT____PVT__full_next;
        ::CData/*0:0*/ mem_serial_tb__DOT__r_queue__DOT____PVT__full;
        ::CData/*1:0*/ mem_serial_tb__DOT__r_queue__DOT____PVT__tail;
        ::CData/*1:0*/ mem_serial_tb__DOT__r_queue__DOT____PVT__head;
        Vmem_serial_tb_mem_serial_tb__DOT____typeimpmod2__struct__0 mem_serial_tb__DOT__r_queue;
        ::CData/*3:0*/ mem_serial_tb__DOT__cmd_consumed_valid_local;
        ::CData/*0:0*/ mem_serial_tb__DOT__cmd_in_valid_prev;
        ::CData/*1:0*/ mem_serial_tb__DOT__cmd_ptr;
        ::CData/*1:0*/ mem_serial_tb__DOT__cmd_ptr_prev;
        ::CData/*0:0*/ mem_serial_tb__DOT__n_escape;
        ::CData/*1:0*/ mem_serial_tb__DOT__dut__DOT__DDR2LP_CKE;
        ::CData/*1:0*/ mem_serial_tb__DOT__dut__DOT__DDR2LP_CS_n;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__DDR2LP_OCT_RZQ;
        ::CData/*3:0*/ mem_serial_tb__DOT__dut__DOT__CMD_CONSUMED;
        ::CData/*4:0*/ mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstcount;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin;
        Vmem_serial_tb_mem_serial_tb__DOT__dut__DOT____typeimpmod1__struct__0 mem_serial_tb__DOT__dut__DOT__avl;
        ::CData/*2:0*/ mem_serial_tb__DOT__dut__DOT__state;
        ::CData/*2:0*/ mem_serial_tb__DOT__dut__DOT__wleft;
        ::CData/*3:0*/ mem_serial_tb__DOT__dut__DOT__cmd_in_valid_local;
        ::CData/*1:0*/ mem_serial_tb__DOT__dut__DOT__in_ptr;
        ::CData/*4:0*/ mem_serial_tb__DOT__dut__DOT__rbuff_ptr;
        ::CData/*4:0*/ mem_serial_tb__DOT__dut__DOT__rbuff_ptr_prev;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__rbuff_valid_prev;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_init_done;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_success;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__local_cal_fail;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_ready_0;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_valid_0;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__afi_clk;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__afi_reset_n;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__afi_reset_export_n;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ck;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ck_n;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_cke;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_cs_n;
        ::CData/*3:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_dm;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue_full;
        ::CData/*7:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__head;
        ::CData/*7:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__tail;
        ::CData/*4:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__write_left;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__escape_stall;
        ::CData/*0:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__inc_queue;
        ::CData/*3:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bmask;
        ::CData/*3:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__state;
        ::CData/*4:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__bursts;
        ::CData/*0:0*/ __Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__burstbegin_0;
        ::CData/*0:0*/ __Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__write_req_1;
        ::CData/*0:0*/ __Vsampled_mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__read_req_2;
        ::CData/*0:0*/ __Vsampled_mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__consuming_write_3;
        ::CData/*0:0*/ __Vtrigprevexpr___TOP__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__control_clk__0;
        ::CData/*0:0*/ __Vtrigprevexpr___TOP__mem_serial_tb__DOT__reset__0;
        ::CData/*0:0*/ __Vtrigprevexpr___TOP__mem_serial_tb__DOT__clk__0;
    };
    struct {
        ::SData/*15:0*/ mem_serial_tb__DOT__dut__DOT__DEBUG_OUT;
        ::SData/*9:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_ca;
        ::VlWide<4>/*127:0*/ mem_serial_tb__DOT__CMD_IN;
        ::VlWide<262144>/*8388607:0*/ mem_serial_tb__DOT__mem_goal;
        ::IData/*31:0*/ mem_serial_tb__DOT__dat__DOT____PVT__byteenable;
        ::VlWide<8>/*255:0*/ mem_serial_tb__DOT__dat__DOT____PVT__wdata;
        ::IData/*17:0*/ mem_serial_tb__DOT__dat__DOT____PVT__addr;
        ::VlWide<32>/*1023:0*/ mem_serial_tb__DOT__r_queue__DOT____PVT__expected;
        ::VlWide<4>/*127:0*/ mem_serial_tb__DOT__r_queue__DOT____PVT__addresses;
        ::IData/*31:0*/ mem_serial_tb__DOT__read_out_valid_local;
        ::IData/*31:0*/ mem_serial_tb__DOT__read_consumed;
        ::IData/*31:0*/ mem_serial_tb__DOT__unnamedblk7__DOT__unnamedblk8__DOT__a;
        ::VlWide<32>/*1023:0*/ mem_serial_tb__DOT__dut__DOT__READ_OUT;
        ::IData/*31:0*/ mem_serial_tb__DOT__dut__DOT__READ_OUT_VALID;
        ::IData/*31:0*/ mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__wdata;
        ::IData/*26:0*/ mem_serial_tb__DOT__dut__DOT__avl__DOT____PVT__addr;
        ::IData/*31:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_3;
        ::IData/*31:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_2;
        ::IData/*31:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_1;
        ::IData/*31:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT____VlemExpr_0;
        ::IData/*31:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__avl_rdata_0;
        ::VlWide<262144>/*8388607:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem;
        ::VlWide<256>/*8191:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__queue;
        ::IData/*26:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__cur_addr;
        ::IData/*31:0*/ mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__unnamedblk1__DOT__i;
        ::VlWide<262144>/*8388607:0*/ __Vdly__mem_serial_tb__DOT__dut__DOT__mem_controller__DOT__mem_24;
        ::IData/*31:0*/ __Vi;
        ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
        ::VlUnpacked<::QData/*63:0*/, 1> __VicoTriggered;
        ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggered;
        ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggeredAcc;
        ::VlUnpacked<::QData/*63:0*/, 1> __VnbaTriggered;
        ::VlUnpacked<::CData/*0:0*/, 6> __VtraceActivity;
    };

    // NOT TRIVIALLY CONSTRUCTIBLE STATE
    union {
        struct {
            ::VlDelayScheduler __VdlySched;
            ::VlTriggerScheduler __VtrigSched_h78d7008b__0;
            ::VlTriggerScheduler __VtrigSched_h78d70056__0;
        } __Vnontrivs;
    };

    // INTERNAL VARIABLES
    Vmem_serial_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vmem_serial_tb___024root(Vmem_serial_tb__Syms* symsp, const char* namep);
    ~Vmem_serial_tb___024root();
    VL_UNCOPYABLE(Vmem_serial_tb___024root);
    VL_UNMOVABLE(Vmem_serial_tb___024root);

    // INTERNAL METHODS
};


#endif  // guard
