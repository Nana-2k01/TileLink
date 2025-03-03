// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtlul_interconnect_tb.h for the primary calling header

#include "Vtlul_interconnect_tb__pch.h"
#include "Vtlul_interconnect_tb__Syms.h"
#include "Vtlul_interconnect_tb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtlul_interconnect_tb___024root___dump_triggers__act(Vtlul_interconnect_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtlul_interconnect_tb___024root___eval_triggers__act(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_triggers__act\n"); );
    // Body
    CData/*0:0*/ __Vtrigcurrexpr_h9dba0e51__0;
    __Vtrigcurrexpr_h9dba0e51__0 = 0;
    CData/*0:0*/ __Vtrigcurrexpr_he4263f00__0;
    __Vtrigcurrexpr_he4263f00__0 = 0;
    __Vtrigcurrexpr_h9dba0e51__0 = ((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__master_id)) 
                                    && (1U & (((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
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
                                              >> (3U 
                                                  & vlSelf->tlul_interconnect_tb__DOT__master_id))));
    __Vtrigcurrexpr_he4263f00__0 = ((2U >= (3U & vlSelf->tlul_interconnect_tb__DOT__m)) 
                                    && (1U & (((((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full)) 
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
                                              >> (3U 
                                                  & vlSelf->tlul_interconnect_tb__DOT__m))));
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tlul_interconnect_tb__DOT__clk_100) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_100__0))) 
                                     | ((IData)(vlSelf->tlul_interconnect_tb__DOT__reset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__reset__0)))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->tlul_interconnect_tb__DOT__clk_24) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_24__0))) 
                                     | ((IData)(vlSelf->tlul_interconnect_tb__DOT__reset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__reset__0)))));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->tlul_interconnect_tb__DOT__clk_100) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_100__0))));
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->tlul_interconnect_tb__DOT__clk_24) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_24__0))));
    vlSelf->__VactTriggered.set(4U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(5U, ((IData)(__Vtrigcurrexpr_h9dba0e51__0) 
                                     != (IData)(vlSelf->__Vtrigprevexpr_h9dba0e51__0)));
    vlSelf->__VactTriggered.set(6U, ((IData)(__Vtrigcurrexpr_he4263f00__0) 
                                     != (IData)(vlSelf->__Vtrigprevexpr_he4263f00__0)));
    vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_100__0 
        = vlSelf->tlul_interconnect_tb__DOT__clk_100;
    vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__reset__0 
        = vlSelf->tlul_interconnect_tb__DOT__reset;
    vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_24__0 
        = vlSelf->tlul_interconnect_tb__DOT__clk_24;
    vlSelf->__Vtrigprevexpr_h9dba0e51__0 = __Vtrigcurrexpr_h9dba0e51__0;
    vlSelf->__Vtrigprevexpr_he4263f00__0 = __Vtrigcurrexpr_he4263f00__0;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(5U, 1U);
        vlSelf->__VactTriggered.set(6U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtlul_interconnect_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
