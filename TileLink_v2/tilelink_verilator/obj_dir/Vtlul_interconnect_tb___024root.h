// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtlul_interconnect_tb.h for the primary calling header

#ifndef VERILATED_VTLUL_INTERCONNECT_TB___024ROOT_H_
#define VERILATED_VTLUL_INTERCONNECT_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtlul_interconnect_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtlul_interconnect_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tlul_interconnect_tb__DOT__clk_100;
        CData/*0:0*/ tlul_interconnect_tb__DOT__clk_24;
        CData/*0:0*/ tlul_interconnect_tb__DOT__reset;
        CData/*2:0*/ tlul_interconnect_tb__DOT__master_a_valid;
        CData/*2:0*/ tlul_interconnect_tb__DOT__master_d_ready;
        CData/*0:0*/ tlul_interconnect_tb__DOT__slave_a_ready;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__slave_d_valid;
        CData/*2:0*/ tlul_interconnect_tb__DOT__u_top__DOT__slave_d_opcode;
        CData/*2:0*/ tlul_interconnect_tb__DOT__u_top__DOT__slave_d_param;
        CData/*2:0*/ tlul_interconnect_tb__DOT__u_top__DOT__slave_d_size;
        CData/*1:0*/ tlul_interconnect_tb__DOT__u_top__DOT__slave_d_source;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__slave_d_sink;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__slave_d_error;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__xbar_d_ready;
        CData/*1:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant;
        CData/*1:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__candidate;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_en;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_en;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_empty;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_wr_en;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_en;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_full;
        CData/*0:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_empty;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray_rd_reg;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray_wr_reg;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray_rd_reg;
        CData/*3:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray_wr_reg;
        CData/*3:0*/ __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr;
        CData/*3:0*/ __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr;
        CData/*3:0*/ __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr;
        CData/*2:0*/ __Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0;
        CData/*0:0*/ __Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0;
        CData/*2:0*/ __Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0;
        CData/*0:0*/ __Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_100__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_24__0;
        CData/*0:0*/ __Vtrigprevexpr_h9dba0e51__0;
        CData/*0:0*/ __Vtrigprevexpr_he4263f00__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*8:0*/ tlul_interconnect_tb__DOT__master_a_opcode;
        SData/*8:0*/ tlul_interconnect_tb__DOT__master_a_param;
        SData/*8:0*/ tlul_interconnect_tb__DOT__master_a_size;
        SData/*11:0*/ tlul_interconnect_tb__DOT__master_a_mask;
        VlWide<3>/*95:0*/ tlul_interconnect_tb__DOT__master_a_address;
        VlWide<3>/*95:0*/ tlul_interconnect_tb__DOT__master_a_data;
        IData/*31:0*/ tlul_interconnect_tb__DOT__master_id;
        IData/*31:0*/ tlul_interconnect_tb__DOT__m;
        IData/*31:0*/ tlul_interconnect_tb__DOT__u_top__DOT__slave_d_data;
        IData/*31:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__i;
        VlWide<3>/*79:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data;
        VlWide<3>/*79:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data;
    };
    struct {
        VlWide<3>/*79:0*/ __Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0;
        IData/*31:0*/ __VactIterCount;
        QData/*45:0*/ tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_data;
        QData/*45:0*/ __Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0;
        VlUnpacked<VlWide<3>/*79:0*/, 8> tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem;
        VlUnpacked<QData/*45:0*/, 8> tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h098e486f__0;
    VlTriggerScheduler __VtrigSched_h84fefcb9__0;
    VlTriggerScheduler __VtrigSched_h44127792__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<7> __VactTriggered;
    VlTriggerVec<7> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtlul_interconnect_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtlul_interconnect_tb___024root(Vtlul_interconnect_tb__Syms* symsp, const char* v__name);
    ~Vtlul_interconnect_tb___024root();
    VL_UNCOPYABLE(Vtlul_interconnect_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
