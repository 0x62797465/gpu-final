// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmem_serial_tb.h for the primary calling header

#include "Vmem_serial_tb__pch.h"

void Vmem_serial_tb___024root___ctor_var_reset(Vmem_serial_tb___024root* vlSelf);

void Vmem_serial_tb___024root__ctor(Vmem_serial_tb___024root* vlSelf, Vmem_serial_tb__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__VdlySched, *vlSelf->vlSymsp->_vm_contextp__);
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__VtrigSched_h78d7008b__0);
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__VtrigSched_h78d70056__0);
    // Reset structure values
    Vmem_serial_tb___024root___ctor_var_reset(vlSelf);
}

Vmem_serial_tb___024root::Vmem_serial_tb___024root(Vmem_serial_tb__Syms* symsp, const char* namep) {
    Vmem_serial_tb___024root__ctor(this, symsp, namep);
}

void Vmem_serial_tb___024root__dtor(Vmem_serial_tb___024root* vlSelf) {
    // Destroy members
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__VtrigSched_h78d70056__0);
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__VtrigSched_h78d7008b__0);
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__VdlySched);
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

Vmem_serial_tb___024root::~Vmem_serial_tb___024root() {
    Vmem_serial_tb___024root__dtor(this);
}
