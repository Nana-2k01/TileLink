// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtlul_interconnect_tb.h for the primary calling header

#include "Vtlul_interconnect_tb__pch.h"
#include "Vtlul_interconnect_tb__Syms.h"
#include "Vtlul_interconnect_tb___024root.h"

void Vtlul_interconnect_tb___024root___ctor_var_reset(Vtlul_interconnect_tb___024root* vlSelf);

Vtlul_interconnect_tb___024root::Vtlul_interconnect_tb___024root(Vtlul_interconnect_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtlul_interconnect_tb___024root___ctor_var_reset(this);
}

void Vtlul_interconnect_tb___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtlul_interconnect_tb___024root::~Vtlul_interconnect_tb___024root() {
}
