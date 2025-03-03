// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtlul_interconnect_tb.h for the primary calling header

#include "Vtlul_interconnect_tb__pch.h"
#include "Vtlul_interconnect_tb___024root.h"

VlCoroutine Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0(Vtlul_interconnect_tb___024root* vlSelf);

void Vtlul_interconnect_tb___024root___eval_initial(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_initial\n"); );
    // Body
    Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_100__0 
        = vlSelf->tlul_interconnect_tb__DOT__clk_100;
    vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__reset__0 
        = vlSelf->tlul_interconnect_tb__DOT__reset;
    vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_24__0 
        = vlSelf->tlul_interconnect_tb__DOT__clk_24;
    vlSelf->__Vtrigprevexpr_h9dba0e51__0 = ((2U >= 
                                             (3U & vlSelf->tlul_interconnect_tb__DOT__master_id)) 
                                            && (1U 
                                                & (((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                                      & (2U 
                                                         == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                                     << 2U) 
                                                    | ((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                                         & (1U 
                                                            == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                                        << 1U) 
                                                       | ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                                          & (0U 
                                                             == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))) 
                                                   >> 
                                                   (3U 
                                                    & vlSelf->tlul_interconnect_tb__DOT__master_id))));
    vlSelf->__Vtrigprevexpr_he4263f00__0 = ((2U >= 
                                             (3U & vlSelf->tlul_interconnect_tb__DOT__m)) 
                                            && (1U 
                                                & (((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                                      & (2U 
                                                         == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                                     << 2U) 
                                                    | ((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                                         & (1U 
                                                            == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                                        << 1U) 
                                                       | ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                                          & (0U 
                                                             == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))) 
                                                   >> 
                                                   (3U 
                                                    & vlSelf->tlul_interconnect_tb__DOT__m))));
}

VlCoroutine Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0(Vtlul_interconnect_tb___024root* vlSelf);
VlCoroutine Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1(Vtlul_interconnect_tb___024root* vlSelf);

VL_INLINE_OPT VlCoroutine Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    CData/*0:0*/ tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__0;
    tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__0 = 0;
    CData/*2:0*/ tlul_interconnect_tb__DOT____Vlvbound_h314d5456__0;
    tlul_interconnect_tb__DOT____Vlvbound_h314d5456__0 = 0;
    IData/*31:0*/ tlul_interconnect_tb__DOT____Vlvbound_h3cdd1469__0;
    tlul_interconnect_tb__DOT____Vlvbound_h3cdd1469__0 = 0;
    CData/*2:0*/ tlul_interconnect_tb__DOT____Vlvbound_hc782269f__0;
    tlul_interconnect_tb__DOT____Vlvbound_hc782269f__0 = 0;
    IData/*31:0*/ tlul_interconnect_tb__DOT____Vlvbound_h9cd1ca35__0;
    tlul_interconnect_tb__DOT____Vlvbound_h9cd1ca35__0 = 0;
    CData/*0:0*/ tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__1;
    tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__1 = 0;
    CData/*0:0*/ tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__2;
    tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__2 = 0;
    CData/*2:0*/ tlul_interconnect_tb__DOT____Vlvbound_h314d5456__1;
    tlul_interconnect_tb__DOT____Vlvbound_h314d5456__1 = 0;
    IData/*31:0*/ tlul_interconnect_tb__DOT____Vlvbound_h3cdd1469__1;
    tlul_interconnect_tb__DOT____Vlvbound_h3cdd1469__1 = 0;
    CData/*2:0*/ tlul_interconnect_tb__DOT____Vlvbound_hc782269f__1;
    tlul_interconnect_tb__DOT____Vlvbound_hc782269f__1 = 0;
    IData/*31:0*/ tlul_interconnect_tb__DOT____Vlvbound_h9cd1ca35__1;
    tlul_interconnect_tb__DOT____Vlvbound_h9cd1ca35__1 = 0;
    CData/*0:0*/ tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__3;
    tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__3 = 0;
    CData/*0:0*/ tlul_interconnect_tb__DOT____Vlvbound_ha36aeaac__0;
    tlul_interconnect_tb__DOT____Vlvbound_ha36aeaac__0 = 0;
    CData/*2:0*/ tlul_interconnect_tb__DOT____Vlvbound_h6d27da7f__0;
    tlul_interconnect_tb__DOT____Vlvbound_h6d27da7f__0 = 0;
    IData/*31:0*/ tlul_interconnect_tb__DOT____Vlvbound_h4652c455__0;
    tlul_interconnect_tb__DOT____Vlvbound_h4652c455__0 = 0;
    CData/*2:0*/ tlul_interconnect_tb__DOT____Vlvbound_hbfdbc908__0;
    tlul_interconnect_tb__DOT____Vlvbound_hbfdbc908__0 = 0;
    IData/*31:0*/ tlul_interconnect_tb__DOT____Vlvbound_h4fcd35e1__0;
    tlul_interconnect_tb__DOT____Vlvbound_h4fcd35e1__0 = 0;
    CData/*0:0*/ tlul_interconnect_tb__DOT____Vlvbound_ha36aeaac__1;
    tlul_interconnect_tb__DOT____Vlvbound_ha36aeaac__1 = 0;
    // Body
    vlSelf->tlul_interconnect_tb__DOT__clk_100 = 0U;
    vlSelf->tlul_interconnect_tb__DOT__clk_24 = 0U;
    vlSelf->tlul_interconnect_tb__DOT__reset = 1U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_valid = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_opcode = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_param = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_size = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_address[0U] = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_address[1U] = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_address[2U] = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_mask = 0xfU;
    vlSelf->tlul_interconnect_tb__DOT__master_a_data[0U] = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_data[1U] = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_a_data[2U] = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_d_ready = 7U;
    vlSelf->tlul_interconnect_tb__DOT__master_id = 0U;
    vlSelf->tlul_interconnect_tb__DOT__m = 1U;
    Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0(vlSelf);
    Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1(vlSelf);
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "tlul_interconnect_tb.sv", 
                                       92);
    vlSelf->tlul_interconnect_tb__DOT__reset = 0U;
    vlSelf->tlul_interconnect_tb__DOT__master_id = 0U;
    tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__0 = 1U;
    tlul_interconnect_tb__DOT____Vlvbound_h314d5456__0 = 4U;
    tlul_interconnect_tb__DOT____Vlvbound_h3cdd1469__0 = 0x1000U;
    tlul_interconnect_tb__DOT____Vlvbound_hc782269f__0 = 2U;
    tlul_interconnect_tb__DOT____Vlvbound_h9cd1ca35__0 = 0xdeadbeefU;
    if ((8U >= (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))) {
        vlSelf->tlul_interconnect_tb__DOT__master_a_opcode 
            = (((~ ((IData)(7U) << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_opcode)) 
               | (0x1ffU & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_h314d5456__0) 
                            << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))));
        vlSelf->tlul_interconnect_tb__DOT__master_a_size 
            = (((~ ((IData)(7U) << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_size)) 
               | (0x1ffU & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_hc782269f__0) 
                            << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))));
    }
    if ((0x5fU >= (0x7fU & VL_MULS_III(32, (IData)(0x20U), vlSelf->tlul_interconnect_tb__DOT__master_id)))) {
        VL_ASSIGNSEL_WI(96,32,(0x7fU & VL_MULS_III(32, (IData)(0x20U), vlSelf->tlul_interconnect_tb__DOT__master_id)), vlSelf->tlul_interconnect_tb__DOT__master_a_address, tlul_interconnect_tb__DOT____Vlvbound_h3cdd1469__0);
        VL_ASSIGNSEL_WI(96,32,(0x7fU & VL_MULS_III(32, (IData)(0x20U), vlSelf->tlul_interconnect_tb__DOT__master_id)), vlSelf->tlul_interconnect_tb__DOT__master_a_data, tlul_interconnect_tb__DOT____Vlvbound_h9cd1ca35__0);
    }
    if (VL_LIKELY((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__master_id)))) {
        vlSelf->tlul_interconnect_tb__DOT__master_a_valid 
            = (((~ ((IData)(1U) << (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid)) 
               | (7U & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__0) 
                        << (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))));
    }
    while ((1U & (~ ((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__master_id)) 
                     && (1U & (((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                  & (2U == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                 << 2U) | ((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                             & (1U 
                                                == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                            << 1U) 
                                           | ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                              & (0U 
                                                 == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))) 
                               >> (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))))))) {
        co_await vlSelf->__VtrigSched_h098e486f__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] ((2'h2 >= tlul_interconnect_tb.master_id[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.master_id[1:0]+:32'h1]]))", 
                                                           "tlul_interconnect_tb.sv", 
                                                           102);
    }
    co_await vlSelf->__VtrigSched_h84fefcb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tlul_interconnect_tb.clk_100)", 
                                                       "tlul_interconnect_tb.sv", 
                                                       103);
    tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__1 = 0U;
    if (VL_LIKELY((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__master_id)))) {
        vlSelf->tlul_interconnect_tb__DOT__master_a_valid 
            = (((~ ((IData)(1U) << (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid)) 
               | (7U & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__1) 
                        << (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))));
    }
    vlSelf->tlul_interconnect_tb__DOT__master_id = 1U;
    tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__2 = 1U;
    tlul_interconnect_tb__DOT____Vlvbound_h314d5456__1 = 0U;
    tlul_interconnect_tb__DOT____Vlvbound_h3cdd1469__1 = 0x2000U;
    tlul_interconnect_tb__DOT____Vlvbound_hc782269f__1 = 2U;
    if ((8U >= (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))) {
        vlSelf->tlul_interconnect_tb__DOT__master_a_opcode 
            = (((~ ((IData)(7U) << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_opcode)) 
               | (0x1ffU & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_h314d5456__1) 
                            << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))));
        vlSelf->tlul_interconnect_tb__DOT__master_a_size 
            = (((~ ((IData)(7U) << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_size)) 
               | (0x1ffU & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_hc782269f__1) 
                            << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__master_id)))));
    }
    tlul_interconnect_tb__DOT____Vlvbound_h9cd1ca35__1 = 0xcafebabeU;
    if ((0x5fU >= (0x7fU & VL_MULS_III(32, (IData)(0x20U), vlSelf->tlul_interconnect_tb__DOT__master_id)))) {
        VL_ASSIGNSEL_WI(96,32,(0x7fU & VL_MULS_III(32, (IData)(0x20U), vlSelf->tlul_interconnect_tb__DOT__master_id)), vlSelf->tlul_interconnect_tb__DOT__master_a_address, tlul_interconnect_tb__DOT____Vlvbound_h3cdd1469__1);
        VL_ASSIGNSEL_WI(96,32,(0x7fU & VL_MULS_III(32, (IData)(0x20U), vlSelf->tlul_interconnect_tb__DOT__master_id)), vlSelf->tlul_interconnect_tb__DOT__master_a_data, tlul_interconnect_tb__DOT____Vlvbound_h9cd1ca35__1);
    }
    if (VL_LIKELY((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__master_id)))) {
        vlSelf->tlul_interconnect_tb__DOT__master_a_valid 
            = (((~ ((IData)(1U) << (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid)) 
               | (7U & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__2) 
                        << (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))));
    }
    while ((1U & (~ ((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__master_id)) 
                     && (1U & (((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                  & (2U == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                 << 2U) | ((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                             & (1U 
                                                == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                            << 1U) 
                                           | ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                              & (0U 
                                                 == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))) 
                               >> (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))))))) {
        co_await vlSelf->__VtrigSched_h098e486f__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] ((2'h2 >= tlul_interconnect_tb.master_id[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.master_id[1:0]+:32'h1]]))", 
                                                           "tlul_interconnect_tb.sv", 
                                                           113);
    }
    co_await vlSelf->__VtrigSched_h84fefcb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tlul_interconnect_tb.clk_100)", 
                                                       "tlul_interconnect_tb.sv", 
                                                       114);
    tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__3 = 0U;
    if (VL_LIKELY((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__master_id)))) {
        vlSelf->tlul_interconnect_tb__DOT__master_a_valid 
            = (((~ ((IData)(1U) << (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid)) 
               | (7U & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_h2e60e3bd__3) 
                        << (3U & vlSelf->tlul_interconnect_tb__DOT__master_id))));
    }
    vlSelf->tlul_interconnect_tb__DOT__m = 2U;
    tlul_interconnect_tb__DOT____Vlvbound_ha36aeaac__0 = 1U;
    tlul_interconnect_tb__DOT____Vlvbound_h6d27da7f__0 = 1U;
    tlul_interconnect_tb__DOT____Vlvbound_h4652c455__0 = 0x3000U;
    tlul_interconnect_tb__DOT____Vlvbound_hbfdbc908__0 = 2U;
    if ((8U >= (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__m)))) {
        vlSelf->tlul_interconnect_tb__DOT__master_a_opcode 
            = (((~ ((IData)(7U) << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__m)))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_opcode)) 
               | (0x1ffU & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_h6d27da7f__0) 
                            << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__m)))));
        vlSelf->tlul_interconnect_tb__DOT__master_a_size 
            = (((~ ((IData)(7U) << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__m)))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_size)) 
               | (0x1ffU & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_hbfdbc908__0) 
                            << (0xfU & VL_MULS_III(32, (IData)(3U), vlSelf->tlul_interconnect_tb__DOT__m)))));
    }
    tlul_interconnect_tb__DOT____Vlvbound_h4fcd35e1__0 = 0x12345678U;
    if ((0x5fU >= (0x7fU & VL_MULS_III(32, (IData)(0x20U), vlSelf->tlul_interconnect_tb__DOT__m)))) {
        VL_ASSIGNSEL_WI(96,32,(0x7fU & VL_MULS_III(32, (IData)(0x20U), vlSelf->tlul_interconnect_tb__DOT__m)), vlSelf->tlul_interconnect_tb__DOT__master_a_address, tlul_interconnect_tb__DOT____Vlvbound_h4652c455__0);
        VL_ASSIGNSEL_WI(96,32,(0x7fU & VL_MULS_III(32, (IData)(0x20U), vlSelf->tlul_interconnect_tb__DOT__m)), vlSelf->tlul_interconnect_tb__DOT__master_a_data, tlul_interconnect_tb__DOT____Vlvbound_h4fcd35e1__0);
    }
    if (VL_LIKELY((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__m)))) {
        vlSelf->tlul_interconnect_tb__DOT__master_a_valid 
            = (((~ ((IData)(1U) << (3U & vlSelf->tlul_interconnect_tb__DOT__m))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid)) 
               | (7U & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_ha36aeaac__0) 
                        << (3U & vlSelf->tlul_interconnect_tb__DOT__m))));
    }
    while ((1U & (~ ((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__m)) 
                     && (1U & (((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                  & (2U == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                 << 2U) | ((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                             & (1U 
                                                == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))) 
                                            << 1U) 
                                           | ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
                                              & (0U 
                                                 == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))) 
                               >> (3U & vlSelf->tlul_interconnect_tb__DOT__m))))))) {
        co_await vlSelf->__VtrigSched_h44127792__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] ((2'h2 >= tlul_interconnect_tb.m[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.m[1:0]+:32'h1]]))", 
                                                           "tlul_interconnect_tb.sv", 
                                                           124);
    }
    co_await vlSelf->__VtrigSched_h84fefcb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tlul_interconnect_tb.clk_100)", 
                                                       "tlul_interconnect_tb.sv", 
                                                       125);
    tlul_interconnect_tb__DOT____Vlvbound_ha36aeaac__1 = 0U;
    if (VL_LIKELY((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__m)))) {
        vlSelf->tlul_interconnect_tb__DOT__master_a_valid 
            = (((~ ((IData)(1U) << (3U & vlSelf->tlul_interconnect_tb__DOT__m))) 
                & (IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid)) 
               | (7U & ((IData)(tlul_interconnect_tb__DOT____Vlvbound_ha36aeaac__1) 
                        << (3U & vlSelf->tlul_interconnect_tb__DOT__m))));
    }
    co_await vlSelf->__VdlySched.delay(0x5f5e100ULL, 
                                       nullptr, "tlul_interconnect_tb.sv", 
                                       132);
    VL_FINISH_MT("tlul_interconnect_tb.sv", 132, "");
}

VL_INLINE_OPT VlCoroutine Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x5208ULL, 
                                           nullptr, 
                                           "tlul_interconnect_tb.sv", 
                                           88);
        vlSelf->tlul_interconnect_tb__DOT__clk_24 = 
            (1U & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__clk_24)));
    }
}

VL_INLINE_OPT VlCoroutine Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tlul_interconnect_tb.sv", 
                                           87);
        vlSelf->tlul_interconnect_tb__DOT__clk_100 
            = (1U & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__clk_100)));
    }
}

extern const VlUnpacked<CData/*0:0*/, 32> Vtlul_interconnect_tb__ConstPool__TABLE_h9751e8f9_0;

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___act_comb__TOP__0(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___act_comb__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_3;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->tlul_interconnect_tb__DOT__master_d_ready) 
                     << 2U) | (3U & (IData)((vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_data 
                                             >> 0x23U))));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_d_ready 
        = Vtlul_interconnect_tb__ConstPool__TABLE_h9751e8f9_0
        [__Vtableidx1];
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid 
        = ((2U >= (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)) 
           && (1U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid) 
                     >> (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_en 
        = ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_empty)) 
           & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_d_ready));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_en 
        = ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
           & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid));
    __Vtemp_1[0U] = (IData)((((QData)((IData)(((0xbU 
                                                >= 
                                                (0xfU 
                                                 & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 2U)))
                                                ? (0xfU 
                                                   & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_mask) 
                                                      >> 
                                                      (0xfU 
                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 2U))))
                                                : 0U))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((0x5fU 
                                                            >= 
                                                            (0x7fU 
                                                             & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                            ? 
                                                           (((0U 
                                                              == 
                                                              (0x1fU 
                                                               & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                              ? 0U
                                                              : 
                                                             (vlSelf->tlul_interconnect_tb__DOT__master_a_data[
                                                              (((IData)(0x1fU) 
                                                                + 
                                                                (0x7fU 
                                                                 & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                                               >> 5U)] 
                                                              << 
                                                              ((IData)(0x20U) 
                                                               - 
                                                               (0x1fU 
                                                                & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                                                            | (vlSelf->tlul_interconnect_tb__DOT__master_a_data[
                                                               (3U 
                                                                & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                                                   >> 5U))] 
                                                               >> 
                                                               (0x1fU 
                                                                & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                                                            : 0U)))));
    __Vtemp_1[1U] = ((((0x5fU >= (0x7fU & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                        ? (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                             ? 0U : (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                     (((IData)(0x1fU) 
                                       + (0x7fU & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                      >> 5U)] << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                           | (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                              (3U & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                        : 0U) << 4U) | (IData)(((((QData)((IData)(
                                                                  ((0xbU 
                                                                    >= 
                                                                    (0xfU 
                                                                     & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 2U)))
                                                                    ? 
                                                                   (0xfU 
                                                                    & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_mask) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 2U))))
                                                                    : 0U))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   ((0x5fU 
                                                                     >= 
                                                                     (0x7fU 
                                                                      & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                                     ? 
                                                                    (((0U 
                                                                       == 
                                                                       (0x1fU 
                                                                        & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                                       ? 0U
                                                                       : 
                                                                      (vlSelf->tlul_interconnect_tb__DOT__master_a_data[
                                                                       (((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7fU 
                                                                          & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                                                        >> 5U)] 
                                                                       << 
                                                                       ((IData)(0x20U) 
                                                                        - 
                                                                        (0x1fU 
                                                                         & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                                                                     | (vlSelf->tlul_interconnect_tb__DOT__master_a_data[
                                                                        (3U 
                                                                         & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                                                            >> 5U))] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                                                                     : 0U)))) 
                                                >> 0x20U)));
    __Vtemp_3[2U] = ((((8U >= (0xfU & ((IData)(3U) 
                                       * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))
                        ? (7U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_size) 
                                 >> (0xfU & ((IData)(3U) 
                                             * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)))))
                        : 0U) << 6U) | (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant) 
                                         << 4U) | (
                                                   ((0x5fU 
                                                     >= 
                                                     (0x7fU 
                                                      & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                     ? 
                                                    (((0U 
                                                       == 
                                                       (0x1fU 
                                                        & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                       ? 0U
                                                       : 
                                                      (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                                       (((IData)(0x1fU) 
                                                         + 
                                                         (0x7fU 
                                                          & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                                        >> 5U)] 
                                                       << 
                                                       ((IData)(0x20U) 
                                                        - 
                                                        (0x1fU 
                                                         & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                                                     | (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                                        (3U 
                                                         & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                                            >> 5U))] 
                                                        >> 
                                                        (0x1fU 
                                                         & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                                                     : 0U) 
                                                   >> 0x1cU)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data[0U] 
        = __Vtemp_1[0U];
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data[1U] 
        = __Vtemp_1[1U];
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data[2U] 
        = (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid) 
            << 0xfU) | ((((8U >= (0xfU & ((IData)(3U) 
                                          * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))
                           ? (7U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_opcode) 
                                    >> (0xfU & ((IData)(3U) 
                                                * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)))))
                           : 0U) << 0xcU) | ((((8U 
                                                >= 
                                                (0xfU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))
                                                ? (7U 
                                                   & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_param) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)))))
                                                : 0U) 
                                              << 9U) 
                                             | __Vtemp_3[2U])));
}

void Vtlul_interconnect_tb___024root___eval_act(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_act\n"); );
    // Body
    if ((0x74ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_sequent__TOP__0(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_sequent__TOP__0\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__reset)))) {
        if (VL_UNLIKELY(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_wr_en)) {
            VL_WRITEF("[%t] CDC: Captured D response (opcode=%0#, source=%0#, data=0x%0x) in async FIFO\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      3,(IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_opcode),
                      2,vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_source,
                      32,vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_data);
        }
    }
    vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr 
        = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr;
    vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr 
        = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr;
    if ((1U & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__reset)))) {
        if (VL_UNLIKELY(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_en)) {
            VL_WRITEF("[%t] CDC: Sent A request (opcode=%0#, addr=0x%0x, source=%0#) to 24MHz domain\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      3,(7U & (vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[2U] 
                               >> 0xdU)),32,((vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[2U] 
                                              << 0x1bU) 
                                             | (vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[1U] 
                                                >> 5U)),
                      2,(3U & (vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[2U] 
                               >> 5U)));
        }
    }
    if ((1U & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__reset)))) {
        if (VL_UNLIKELY(((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_empty)) 
                         & (IData)(vlSelf->tlul_interconnect_tb__DOT__slave_a_ready)))) {
            VL_WRITEF("[%t] Slave accepted request (opcode=%0#, addr=0x%0x, source=%0#)\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      3,(7U & (vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[2U] 
                               >> 0xdU)),32,((vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[2U] 
                                              << 0x1bU) 
                                             | (vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[1U] 
                                                >> 5U)),
                      2,(3U & (vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[2U] 
                               >> 5U)));
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_valid) 
                         & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_full))))) {
            VL_WRITEF("[%t] Slave response (opcode=%0#) forwarded to CDC (source=%0#, data=0x%0x)\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      3,(IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_opcode),
                      2,vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_source,
                      32,vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_data);
        }
    }
    if (vlSelf->tlul_interconnect_tb__DOT__reset) {
        vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr = 0U;
        vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr = 0U;
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray_wr_reg = 0U;
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray_rd_reg = 0U;
    } else {
        if (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_wr_en) 
             & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_full)))) {
            vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr)));
        }
        if (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_en) 
             & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_empty)))) {
            vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr)));
        }
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray_wr_reg 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray;
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray_rd_reg 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray;
    }
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_sequent__TOP__1(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->__Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0 = 0U;
    if (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_en) 
         & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)))) {
        vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0[0U] 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data[0U];
        vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0[1U] 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data[1U];
        vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0[2U] 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data[2U];
        vlSelf->__Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0 = 1U;
        vlSelf->__Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0 
            = (7U & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr));
    }
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_sequent__TOP__2(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*1:0*/ __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant;
    __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant = 0;
    CData/*3:0*/ __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr;
    __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr = 0;
    // Body
    if ((1U & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__reset)))) {
        if (VL_UNLIKELY(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_en)) {
            VL_WRITEF("[%t] CDC: Captured A request (opcode=%0#, addr=0x%0x, source=%0#) in async FIFO\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      3,((8U >= (0xfU & ((IData)(3U) 
                                         * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))
                          ? (7U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_opcode) 
                                   >> (0xfU & ((IData)(3U) 
                                               * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)))))
                          : 0U),32,((0x5fU >= (0x7fU 
                                               & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                     ? (((0U == (0x1fU 
                                                 & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                          ? 0U : (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                                  (((IData)(0x1fU) 
                                                    + 
                                                    (0x7fU 
                                                     & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                                        | (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                           (3U & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                                  >> 5U))] 
                                           >> (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                                     : 0U),2,(IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant));
        }
    }
    vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr 
        = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr;
    __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr 
        = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__reset))))) {
        VL_WRITEF("[%t] Arbiter grant = Master %0#\n",
                  64,VL_TIME_UNITED_Q(1000),-9,2,(IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant));
        if (VL_UNLIKELY(((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid) 
                         & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full))))) {
            VL_WRITEF("[%t] Forwarded request from Master %0# (opcode=%0#, addr=0x%0x) to CDC\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      2,(IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant),
                      3,((8U >= (0xfU & ((IData)(3U) 
                                         * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))
                          ? (7U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_opcode) 
                                   >> (0xfU & ((IData)(3U) 
                                               * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)))))
                          : 0U),32,((0x5fU >= (0x7fU 
                                               & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                     ? (((0U == (0x1fU 
                                                 & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                          ? 0U : (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                                  (((IData)(0x1fU) 
                                                    + 
                                                    (0x7fU 
                                                     & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                                        | (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                           (3U & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                                  >> 5U))] 
                                           >> (0x1fU 
                                               & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                                     : 0U));
        }
    }
    if ((1U & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__reset)))) {
        if (VL_UNLIKELY(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_en)) {
            VL_WRITEF("[%t] CDC: Sent D response (opcode=%0#, source=%0#, data=0x%0x) to 100MHz domain\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      3,(7U & (IData)((vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_data 
                                       >> 0x2bU))),
                      2,(3U & (IData)((vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_data 
                                       >> 0x23U))),
                      32,(IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_data));
        }
    }
    __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant 
        = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant;
    if (vlSelf->tlul_interconnect_tb__DOT__reset) {
        vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr = 0U;
        __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr = 0U;
        __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant = 0U;
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray_rd_reg = 0U;
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray_wr_reg = 0U;
    } else {
        if (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_en) 
             & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_empty)))) {
            vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr)));
        }
        if (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_en) 
             & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)))) {
            __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr)));
        }
        if ((1U & (~ ((2U >= (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)) 
                      && (1U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid) 
                                >> (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))))) {
            vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__candidate 
                = (3U & VL_MODDIV_III(32, ((IData)(1U) 
                                           + (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)), (IData)(3U)));
            vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__i = 0U;
            {
                while (VL_GTS_III(32, 3U, vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__i)) {
                    if (((2U >= (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__candidate)) 
                         && (1U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid) 
                                   >> (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__candidate))))) {
                        __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant 
                            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__candidate;
                        goto __Vlabel1;
                    }
                    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__candidate 
                        = (3U & VL_MODDIV_III(32, ((IData)(1U) 
                                                   + (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__candidate)), (IData)(3U)));
                    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__i 
                        = ((IData)(1U) + vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__i);
                }
                __Vlabel1: ;
            }
        }
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray_rd_reg 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray;
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray_wr_reg 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray;
    }
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr 
        = __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr;
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant 
        = __Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant;
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray 
        = (0xfU & ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr), 1U)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full 
        = ((8U ^ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray)) 
           == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray_wr_reg));
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_sequent__TOP__3(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->__Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0 = 0U;
    if (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_wr_en) 
         & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_full)))) {
        vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0 
            = (((QData)((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_valid)) 
                << 0x2dU) | (((QData)((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_opcode)) 
                              << 0x2aU) | (((QData)((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_param)) 
                                            << 0x27U) 
                                           | (((QData)((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_size)) 
                                               << 0x24U) 
                                              | (((QData)((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_source)) 
                                                  << 0x22U) 
                                                 | (((QData)((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_sink)) 
                                                     << 0x21U) 
                                                    | (((QData)((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_data)) 
                                                        << 1U) 
                                                       | (QData)((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_error)))))))));
        vlSelf->__Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0 = 1U;
        vlSelf->__Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0 
            = (7U & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr));
    }
    if (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_en) 
         & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_empty)))) {
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[0U] 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem
            [(7U & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr))][0U];
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[1U] 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem
            [(7U & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr))][1U];
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data[2U] 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem
            [(7U & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr))][2U];
    }
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_sequent__TOP__4(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_sequent__TOP__4\n"); );
    // Body
    if (vlSelf->__Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0) {
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem[vlSelf->__Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0][0U] 
            = vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0[0U];
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem[vlSelf->__Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0][1U] 
            = vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0[1U];
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem[vlSelf->__Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0][2U] 
            = vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0[2U];
    }
    if (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_en) 
         & (~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_empty)))) {
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_data 
            = vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem
            [(7U & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr))];
    }
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_comb__TOP__0(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_comb__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_3;
    // Body
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid 
        = ((2U >= (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)) 
           && (1U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid) 
                     >> (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))));
    __Vtemp_1[0U] = (IData)((((QData)((IData)(((0xbU 
                                                >= 
                                                (0xfU 
                                                 & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 2U)))
                                                ? (0xfU 
                                                   & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_mask) 
                                                      >> 
                                                      (0xfU 
                                                       & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 2U))))
                                                : 0U))) 
                              << 0x20U) | (QData)((IData)(
                                                          ((0x5fU 
                                                            >= 
                                                            (0x7fU 
                                                             & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                            ? 
                                                           (((0U 
                                                              == 
                                                              (0x1fU 
                                                               & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                              ? 0U
                                                              : 
                                                             (vlSelf->tlul_interconnect_tb__DOT__master_a_data[
                                                              (((IData)(0x1fU) 
                                                                + 
                                                                (0x7fU 
                                                                 & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                                               >> 5U)] 
                                                              << 
                                                              ((IData)(0x20U) 
                                                               - 
                                                               (0x1fU 
                                                                & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                                                            | (vlSelf->tlul_interconnect_tb__DOT__master_a_data[
                                                               (3U 
                                                                & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                                                   >> 5U))] 
                                                               >> 
                                                               (0x1fU 
                                                                & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                                                            : 0U)))));
    __Vtemp_1[1U] = ((((0x5fU >= (0x7fU & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                        ? (((0U == (0x1fU & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                             ? 0U : (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                     (((IData)(0x1fU) 
                                       + (0x7fU & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                      >> 5U)] << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                           | (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                              (3U & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                     >> 5U))] >> (0x1fU 
                                                  & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                        : 0U) << 4U) | (IData)(((((QData)((IData)(
                                                                  ((0xbU 
                                                                    >= 
                                                                    (0xfU 
                                                                     & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 2U)))
                                                                    ? 
                                                                   (0xfU 
                                                                    & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_mask) 
                                                                       >> 
                                                                       (0xfU 
                                                                        & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 2U))))
                                                                    : 0U))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   ((0x5fU 
                                                                     >= 
                                                                     (0x7fU 
                                                                      & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                                     ? 
                                                                    (((0U 
                                                                       == 
                                                                       (0x1fU 
                                                                        & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                                       ? 0U
                                                                       : 
                                                                      (vlSelf->tlul_interconnect_tb__DOT__master_a_data[
                                                                       (((IData)(0x1fU) 
                                                                         + 
                                                                         (0x7fU 
                                                                          & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                                                        >> 5U)] 
                                                                       << 
                                                                       ((IData)(0x20U) 
                                                                        - 
                                                                        (0x1fU 
                                                                         & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                                                                     | (vlSelf->tlul_interconnect_tb__DOT__master_a_data[
                                                                        (3U 
                                                                         & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                                                            >> 5U))] 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                                                                     : 0U)))) 
                                                >> 0x20U)));
    __Vtemp_3[2U] = ((((8U >= (0xfU & ((IData)(3U) 
                                       * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))
                        ? (7U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_size) 
                                 >> (0xfU & ((IData)(3U) 
                                             * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)))))
                        : 0U) << 6U) | (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant) 
                                         << 4U) | (
                                                   ((0x5fU 
                                                     >= 
                                                     (0x7fU 
                                                      & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                     ? 
                                                    (((0U 
                                                       == 
                                                       (0x1fU 
                                                        & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U)))
                                                       ? 0U
                                                       : 
                                                      (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                                       (((IData)(0x1fU) 
                                                         + 
                                                         (0x7fU 
                                                          & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))) 
                                                        >> 5U)] 
                                                       << 
                                                       ((IData)(0x20U) 
                                                        - 
                                                        (0x1fU 
                                                         & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))) 
                                                     | (vlSelf->tlul_interconnect_tb__DOT__master_a_address[
                                                        (3U 
                                                         & (VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U) 
                                                            >> 5U))] 
                                                        >> 
                                                        (0x1fU 
                                                         & VL_SHIFTL_III(7,7,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant), 5U))))
                                                     : 0U) 
                                                   >> 0x1cU)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data[0U] 
        = __Vtemp_1[0U];
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data[1U] 
        = __Vtemp_1[1U];
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data[2U] 
        = (((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid) 
            << 0xfU) | ((((8U >= (0xfU & ((IData)(3U) 
                                          * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))
                           ? (7U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_opcode) 
                                    >> (0xfU & ((IData)(3U) 
                                                * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)))))
                           : 0U) << 0xcU) | ((((8U 
                                                >= 
                                                (0xfU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))))
                                                ? (7U 
                                                   & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_param) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)))))
                                                : 0U) 
                                              << 9U) 
                                             | __Vtemp_3[2U])));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_en 
        = ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
           & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid));
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_sequent__TOP__5(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_sequent__TOP__5\n"); );
    // Body
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr 
        = vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr;
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr 
        = vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr;
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray 
        = (0xfU & ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr), 1U)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray 
        = (0xfU & ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr), 1U)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_full 
        = ((8U ^ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray)) 
           == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray_wr_reg));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_empty 
        = ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray_rd_reg) 
           == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_wr_en 
        = ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_full)) 
           & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_valid));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_en 
        = ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_empty)) 
           & (IData)(vlSelf->tlul_interconnect_tb__DOT__slave_a_ready));
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_sequent__TOP__6(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_sequent__TOP__6\n"); );
    // Body
    if (vlSelf->__Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0) {
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem[vlSelf->__Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0] 
            = vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0;
    }
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_sequent__TOP__7(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_sequent__TOP__7\n"); );
    // Body
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr 
        = vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr;
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray 
        = (0xfU & ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr), 1U)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_empty 
        = ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray_rd_reg) 
           == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray));
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_comb__TOP__1(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_comb__TOP__1\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->tlul_interconnect_tb__DOT__master_d_ready) 
                     << 2U) | (3U & (IData)((vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_data 
                                             >> 0x23U))));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_d_ready 
        = Vtlul_interconnect_tb__ConstPool__TABLE_h9751e8f9_0
        [__Vtableidx1];
}

VL_INLINE_OPT void Vtlul_interconnect_tb___024root___nba_comb__TOP__2(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___nba_comb__TOP__2\n"); );
    // Body
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_en 
        = ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_empty)) 
           & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_d_ready));
}

void Vtlul_interconnect_tb___024root___eval_nba(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x75ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x74ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x75ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___nba_comb__TOP__2(vlSelf);
    }
}

void Vtlul_interconnect_tb___024root___timing_resume(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___timing_resume\n"); );
    // Body
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h098e486f__0.resume("@([changed] ((2'h2 >= tlul_interconnect_tb.master_id[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.master_id[1:0]+:32'h1]]))");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h84fefcb9__0.resume("@(posedge tlul_interconnect_tb.clk_100)");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h44127792__0.resume("@([changed] ((2'h2 >= tlul_interconnect_tb.m[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.m[1:0]+:32'h1]]))");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtlul_interconnect_tb___024root___timing_commit(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___timing_commit\n"); );
    // Body
    if ((! (0x20ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h098e486f__0.commit("@([changed] ((2'h2 >= tlul_interconnect_tb.master_id[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.master_id[1:0]+:32'h1]]))");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h84fefcb9__0.commit("@(posedge tlul_interconnect_tb.clk_100)");
    }
    if ((! (0x40ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h44127792__0.commit("@([changed] ((2'h2 >= tlul_interconnect_tb.m[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.m[1:0]+:32'h1]]))");
    }
}

void Vtlul_interconnect_tb___024root___eval_triggers__act(Vtlul_interconnect_tb___024root* vlSelf);

bool Vtlul_interconnect_tb___024root___eval_phase__act(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<7> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtlul_interconnect_tb___024root___eval_triggers__act(vlSelf);
    Vtlul_interconnect_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtlul_interconnect_tb___024root___timing_resume(vlSelf);
        Vtlul_interconnect_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtlul_interconnect_tb___024root___eval_phase__nba(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtlul_interconnect_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtlul_interconnect_tb___024root___dump_triggers__nba(Vtlul_interconnect_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtlul_interconnect_tb___024root___dump_triggers__act(Vtlul_interconnect_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtlul_interconnect_tb___024root___eval(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtlul_interconnect_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tlul_interconnect_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtlul_interconnect_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tlul_interconnect_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtlul_interconnect_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtlul_interconnect_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtlul_interconnect_tb___024root___eval_debug_assertions(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
