// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtlul_interconnect_tb.h for the primary calling header

#include "Vtlul_interconnect_tb__pch.h"
#include "Vtlul_interconnect_tb___024root.h"

VL_ATTR_COLD void Vtlul_interconnect_tb___024root___eval_static(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtlul_interconnect_tb___024root___eval_final(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtlul_interconnect_tb___024root___dump_triggers__stl(Vtlul_interconnect_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtlul_interconnect_tb___024root___eval_phase__stl(Vtlul_interconnect_tb___024root* vlSelf);

VL_ATTR_COLD void Vtlul_interconnect_tb___024root___eval_settle(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtlul_interconnect_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tlul_interconnect_tb.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtlul_interconnect_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtlul_interconnect_tb___024root___dump_triggers__stl(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 32> Vtlul_interconnect_tb__ConstPool__TABLE_h9751e8f9_0;

VL_ATTR_COLD void Vtlul_interconnect_tb___024root___stl_sequent__TOP__0(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___stl_sequent__TOP__0\n"); );
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
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray 
        = (0xfU & ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr), 1U)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray 
        = (0xfU & ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr), 1U)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray 
        = (0xfU & ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr), 1U)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray 
        = (0xfU & ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr), 1U)));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid 
        = ((2U >= (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant)) 
           && (1U & ((IData)(vlSelf->tlul_interconnect_tb__DOT__master_a_valid) 
                     >> (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant))));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full 
        = ((8U ^ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray)) 
           == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray_wr_reg));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_empty 
        = ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray_rd_reg) 
           == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_empty 
        = ((IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray_rd_reg) 
           == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_full 
        = ((8U ^ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray)) 
           == (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray_wr_reg));
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
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_en 
        = ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_empty)) 
           & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_d_ready));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_en 
        = ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_empty)) 
           & (IData)(vlSelf->tlul_interconnect_tb__DOT__slave_a_ready));
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_wr_en 
        = ((~ (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_full)) 
           & (IData)(vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_valid));
}

VL_ATTR_COLD void Vtlul_interconnect_tb___024root___eval_stl(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtlul_interconnect_tb___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtlul_interconnect_tb___024root___eval_triggers__stl(Vtlul_interconnect_tb___024root* vlSelf);

VL_ATTR_COLD bool Vtlul_interconnect_tb___024root___eval_phase__stl(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtlul_interconnect_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtlul_interconnect_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtlul_interconnect_tb___024root___dump_triggers__act(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tlul_interconnect_tb.clk_100 or posedge tlul_interconnect_tb.reset)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tlul_interconnect_tb.clk_24 or posedge tlul_interconnect_tb.reset)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge tlul_interconnect_tb.clk_100)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge tlul_interconnect_tb.clk_24)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([changed] ((2'h2 >= tlul_interconnect_tb.master_id[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.master_id[1:0]+:32'h1]]))\n");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @([changed] ((2'h2 >= tlul_interconnect_tb.m[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.m[1:0]+:32'h1]]))\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtlul_interconnect_tb___024root___dump_triggers__nba(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tlul_interconnect_tb.clk_100 or posedge tlul_interconnect_tb.reset)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tlul_interconnect_tb.clk_24 or posedge tlul_interconnect_tb.reset)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge tlul_interconnect_tb.clk_100)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge tlul_interconnect_tb.clk_24)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([changed] ((2'h2 >= tlul_interconnect_tb.master_id[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.master_id[1:0]+:32'h1]]))\n");
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @([changed] ((2'h2 >= tlul_interconnect_tb.m[1:0]) && {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h2 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), {((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h1 == tlul_interconnect_tb.u_top.u_xbar_main.grant)), ((~ tlul_interconnect_tb.u_top.u_cdc_adapter.fifo_a_full) & (2'h0 == tlul_interconnect_tb.u_top.u_xbar_main.grant))}}[tlul_interconnect_tb.m[1:0]+:32'h1]]))\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtlul_interconnect_tb___024root___ctor_var_reset(Vtlul_interconnect_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtlul_interconnect_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtlul_interconnect_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tlul_interconnect_tb__DOT__clk_100 = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__clk_24 = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__master_a_valid = VL_RAND_RESET_I(3);
    vlSelf->tlul_interconnect_tb__DOT__master_a_opcode = VL_RAND_RESET_I(9);
    vlSelf->tlul_interconnect_tb__DOT__master_a_param = VL_RAND_RESET_I(9);
    vlSelf->tlul_interconnect_tb__DOT__master_a_size = VL_RAND_RESET_I(9);
    VL_RAND_RESET_W(96, vlSelf->tlul_interconnect_tb__DOT__master_a_address);
    vlSelf->tlul_interconnect_tb__DOT__master_a_mask = VL_RAND_RESET_I(12);
    VL_RAND_RESET_W(96, vlSelf->tlul_interconnect_tb__DOT__master_a_data);
    vlSelf->tlul_interconnect_tb__DOT__master_d_ready = VL_RAND_RESET_I(3);
    vlSelf->tlul_interconnect_tb__DOT__slave_a_ready = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__master_id = VL_RAND_RESET_I(32);
    vlSelf->tlul_interconnect_tb__DOT__m = VL_RAND_RESET_I(32);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_valid = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_opcode = VL_RAND_RESET_I(3);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_param = VL_RAND_RESET_I(3);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_size = VL_RAND_RESET_I(3);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_source = VL_RAND_RESET_I(2);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_sink = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_data = VL_RAND_RESET_I(32);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__slave_d_error = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_a_valid = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__xbar_d_ready = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__grant = VL_RAND_RESET_I(2);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_xbar_main__DOT__candidate = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(80, vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_data);
    VL_RAND_RESET_W(80, vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_data);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_rd_en = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_full = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a_empty = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_data = VL_RAND_RESET_Q(46);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_rd_en = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_full = VL_RAND_RESET_I(1);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d_empty = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_RAND_RESET_W(80, vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem[__Vi0]);
    }
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__wr_ptr_gray_rd_reg = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr_gray_wr_reg = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem[__Vi0] = VL_RAND_RESET_Q(46);
    }
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr_gray_rd_reg = VL_RAND_RESET_I(4);
    vlSelf->tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr_gray_wr_reg = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__rd_ptr = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__rd_ptr = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__wr_ptr = VL_RAND_RESET_I(4);
    vlSelf->__Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0 = 0;
    VL_RAND_RESET_W(80, vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0);
    vlSelf->__Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_a__DOT__mem__v0 = 0;
    vlSelf->__Vdlyvdim0__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0 = 0;
    vlSelf->__Vdlyvval__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0 = VL_RAND_RESET_Q(46);
    vlSelf->__Vdlyvset__tlul_interconnect_tb__DOT__u_top__DOT__u_cdc_adapter__DOT__fifo_d__DOT__mem__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_100__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__reset__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_interconnect_tb__DOT__clk_24__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_h9dba0e51__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_he4263f00__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
