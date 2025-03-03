// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtlul_interconnect_tb__pch.h"
#include "Vtlul_interconnect_tb.h"
#include "Vtlul_interconnect_tb___024root.h"

// FUNCTIONS
Vtlul_interconnect_tb__Syms::~Vtlul_interconnect_tb__Syms()
{
}

Vtlul_interconnect_tb__Syms::Vtlul_interconnect_tb__Syms(VerilatedContext* contextp, const char* namep, Vtlul_interconnect_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
