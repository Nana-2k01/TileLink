// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTLUL_INTERCONNECT_TB__SYMS_H_
#define VERILATED_VTLUL_INTERCONNECT_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtlul_interconnect_tb.h"

// INCLUDE MODULE CLASSES
#include "Vtlul_interconnect_tb___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtlul_interconnect_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtlul_interconnect_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtlul_interconnect_tb___024root TOP;

    // CONSTRUCTORS
    Vtlul_interconnect_tb__Syms(VerilatedContext* contextp, const char* namep, Vtlul_interconnect_tb* modelp);
    ~Vtlul_interconnect_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
