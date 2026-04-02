#ifndef __G_SAIL_TO_MD_GCC_GPLL7_HWIO_H__
#define __G_SAIL_TO_MD_GCC_GPLL7_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_GCC_GPLL7_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_GCC_GPLL7_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO'],
      'output-fvals': True,
      'output-offsets': True}
*/
/*
    ===========================================================================

    Copyright (c) 2022 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.

    ===========================================================================

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE                             (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x00107000ul)
#define SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_SIZE                        0x1000u
#define SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_USED                        0x80u
#define SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS                        0x00107000ul

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_ADDR                                              (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x0u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OFFS                                              (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x0u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LOCK_DET_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LOCK_DET_SHFT                                         31u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LOCK_DET_NOT_LOCKED_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LOCK_DET_LOCKED_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LOCK_DET_FINE_BMSK                            0x40000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LOCK_DET_FINE_SHFT                                    30u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LOCK_DET_FINE_NOT_LOCKED_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LOCK_DET_FINE_LOCKED_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_ENABLE_STATUS_BMSK                            0x20000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_ENABLE_STATUS_SHFT                                    29u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_ENABLE_STATUS_OUTPUTS_NOT_ENABLED_FVAL               0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_ENABLE_STATUS_OUTPUTS_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BITS28_24_BMSK                            0x1f000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BITS28_24_SHFT                                    24u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BITS23_15_BMSK                              0xff8000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BITS23_15_SHFT                                    15u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LATCH_INPUT_BMSK                                  0x4000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LATCH_INPUT_SHFT                                      14u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LATCH_INPUT_NO_LATCH_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_LATCH_INPUT_LATCH_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_ACK_LATCH_BMSK                                    0x2000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_ACK_LATCH_SHFT                                        13u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BITS12_9_BMSK                                 0x1e00u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BITS12_9_SHFT                                      9u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PCAL_NOT_DONE_BMSK                                     0x100u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PCAL_NOT_DONE_SHFT                                         8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PCAL_NOT_DONE_PROCESS_CALIBRATION_DONE_FVAL              0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PCAL_NOT_DONE_PROCESS_CALIBRATION_NOT_DONE_FVAL          0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BIT7_BMSK                                       0x80u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BIT7_SHFT                                          7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BIT6_BMSK                                       0x40u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BIT6_SHFT                                          6u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_ODD_HW_CTL_BMSK                                     0x20u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_ODD_HW_CTL_SHFT                                        5u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_ODD_HW_CTL_SW_CONTROL_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_ODD_HW_CTL_HW_CONTROL_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_EVEN_HW_CTL_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_EVEN_HW_CTL_SHFT                                       4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_EVEN_HW_CTL_SW_CONTROL_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_EVEN_HW_CTL_HW_CONTROL_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_MAIN_HW_CTL_BMSK                                     0x8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_MAIN_HW_CTL_SHFT                                       3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_MAIN_HW_CTL_SW_CONTROL_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_OUT_MAIN_HW_CTL_HW_CONTROL_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_RESET_N_BMSK                                         0x4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_RESET_N_SHFT                                           2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_RESET_N_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_RESET_N_NO_RESET_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BIT1_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_RESERVE_BIT1_SHFT                                          1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_OUTCTRL_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_OUTCTRL_SHFT                                           0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_OUTCTRL_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_MODE_PLL_OUTCTRL_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_ADDR                                            (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_OFFS                                            (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_RMSK                                                   0x7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_PLL_OPMODE_BMSK                                        0x7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_PLL_OPMODE_SHFT                                          0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_PLL_OPMODE_STANDBY_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_PLL_OPMODE_RUN_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_PLL_OPMODE_NA_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_OPMODE_PLL_OPMODE_FREEZE_FVAL                                 0x3u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_ADDR                                             (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x8u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_OFFS                                             (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x8u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_RMSK                                                 0xffffu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_PLL_STATE_INTERNAL_BMSK                              0xff00u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_PLL_STATE_INTERNAL_SHFT                                   8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_RESERVE_BITS7_3_BMSK                                   0xf8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_RESERVE_BITS7_3_SHFT                                      3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_PLL_STATE_BMSK                                          0x7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_PLL_STATE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_PLL_STATE_STANDBY_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_PLL_STATE_RUN_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_PLL_STATE_NA_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_PLL_STATE_FREEZE_FVAL                                   0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATE_PLL_STATE_OFF_FVAL                                      0x4u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATUS_ADDR                                            (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0xcu)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATUS_OFFS                                            (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0xcu)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATUS_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATUS_STATUS_31_0_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_STATUS_STATUS_31_0_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_ADDR                                             (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x10u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_OFFS                                             (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x10u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_RMSK                                             0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_PLL_CAL_L_VAL_BMSK                               0xffff0000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_PLL_CAL_L_VAL_SHFT                                       16u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_PLL_L_VAL_BMSK                                       0xffffu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_L_VAL_PLL_L_VAL_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_ADDR                                         (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x14u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_OFFS                                         (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x14u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_RMSK                                             0xffffu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_PLL_ALPHA_VAL_BMSK                               0xffffu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_ALPHA_VAL_PLL_ALPHA_VAL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_ADDR                                          (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x18u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_OFFS                                          (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x18u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT31_BMSK                            0x80000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT31_SHFT                                    31u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT30_BMSK                            0x40000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT30_SHFT                                    30u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT29_BMSK                            0x20000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT29_SHFT                                    29u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_FRAC_FORMAT_SEL_BMSK                          0x10000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_FRAC_FORMAT_SEL_SHFT                                  28u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_FRAC_FORMAT_SEL_POWER_OF_TWO_BASED_FRACTIONAL_MULTIPLIER_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_FRAC_FORMAT_SEL_M_OVER_N_BASED_FRACTIONAL_MULTIPLIER_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_LATCH_INTERFACE_BYPASS_BMSK                    0x8000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_LATCH_INTERFACE_BYPASS_SHFT                           27u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_LATCH_INTERFACE_BYPASS_DO_NOT_BYPASS_FVAL            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_LATCH_INTERFACE_BYPASS_BYPASS_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_OFF_WHEN_NO_VOTE_BMSK                          0x4000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_OFF_WHEN_NO_VOTE_SHFT                                 26u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_OFF_WHEN_NO_VOTE_STANDBY_STATE_WHEN_VOTE_RUN_IS_0_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_OFF_WHEN_NO_VOTE_RESET_STATE_WHEN_VOTE_RUN_IS_0_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_ENABLE_VOTE_RUN_BMSK                           0x2000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_ENABLE_VOTE_RUN_SHFT                                  25u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_ENABLE_VOTE_RUN_USE_PLL_OPMODE_AND_OUTCTRL_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_ENABLE_VOTE_RUN_USE_VOTE_RUN_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PRE_DIV_RATIO_BMSK                             0x1c00000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PRE_DIV_RATIO_SHFT                                    22u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PRE_DIV_RATIO_DIVIDE_BY_1_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PRE_DIV_RATIO_DIVIDE_BY_2_FVAL                       0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PRE_DIV_RATIO_DIVIDE_BY_4_FVAL                       0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BITS21_18_BMSK                          0x3c0000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BITS21_18_SHFT                                18u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_ODD_BMSK                          0x3c000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_ODD_SHFT                               14u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_ODD_DIVIDE_BY_1_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_ODD_DIVIDE_BY_3_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_ODD_DIVIDE_BY_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_ODD_DIVIDE_BY_7_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_EVEN_BMSK                          0x3c00u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_EVEN_SHFT                              10u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_EVEN_DIVIDE_BY_1_FVAL                 0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_EVEN_DIVIDE_BY_2_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_EVEN_DIVIDE_BY_4_FVAL                 0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_POST_DIV_RATIO_EVEN_DIVIDE_BY_8_FVAL                 0x7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BITS9_6_BMSK                               0x3c0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BITS9_6_SHFT                                   6u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT5_BMSK                                   0x20u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT5_SHFT                                      5u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_TEST_EN_BMSK                                 0x10u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_TEST_EN_SHFT                                    4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_TEST_EN_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_TEST_EN_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT3_BMSK                                    0x8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_RESERVE_BIT3_SHFT                                      3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_ODD_EN_BMSK                                   0x4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_ODD_EN_SHFT                                     2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_ODD_EN_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_ODD_EN_ENABLE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_EVEN_EN_BMSK                                  0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_EVEN_EN_SHFT                                    1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_EVEN_EN_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_EVEN_EN_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_MAIN_EN_BMSK                                  0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_MAIN_EN_SHFT                                    0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_MAIN_EN_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_PLLOUT_MAIN_EN_ENABLE_FVAL                           0x1u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_ADDR                                        (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x1cu)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_OFFS                                        (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT63_BMSK                          0x80000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT63_SHFT                                  31u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT62_BMSK                          0x40000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT62_SHFT                                  30u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT61_BMSK                          0x20000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT61_SHFT                                  29u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT60_BMSK                          0x10000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT60_SHFT                                  28u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT59_BMSK                           0x8000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT59_SHFT                                  27u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT58_BMSK                           0x4000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT58_SHFT                                  26u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT57_BMSK                           0x2000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT57_SHFT                                  25u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT56_BMSK                           0x1000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT56_SHFT                                  24u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT55_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT55_SHFT                                  23u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_LOCK_DET_REPLICA_EN_BMSK                      0x400000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_LOCK_DET_REPLICA_EN_SHFT                            22u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_LOCK_DET_REPLICA_EN_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_LOCK_DET_REPLICA_EN_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT53_BMSK                            0x200000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT53_SHFT                                  21u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT52_BMSK                            0x100000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT52_SHFT                                  20u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT51_BMSK                             0x80000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT51_SHFT                                  19u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_LOCK_DETECTOR_SELECTION_BMSK                   0x40000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_LOCK_DETECTOR_SELECTION_SHFT                        18u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_LOCK_DETECTOR_SELECTION_LOCK_DETECT_FROM_FLL_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_LOCK_DETECTOR_SELECTION_LOCK_DETECT_FROM_PLL_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_TYPE_2_MODE_SELECTION_BMSK                     0x20000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_TYPE_2_MODE_SELECTION_SHFT                          17u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_BANG_BANG_MODE_SELECTION_BMSK                  0x10000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_BANG_BANG_MODE_SELECTION_SHFT                       16u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT47_BMSK                              0x8000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT47_SHFT                                  15u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT46_BMSK                              0x4000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT46_SHFT                                  14u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_REF_CLK_AT_OUT_BMSK                             0x2000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_REF_CLK_AT_OUT_SHFT                                 13u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_REF_CLK_AT_OUT_OUTPUT_IS_THE_REFERENCE_CLOCK_WHEN_NOT_LOCKED_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_REF_CLK_AT_OUT_OUTPUT_IS_ALWAYS_THE_CLOCK_GENERATED_BY_PLL_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_BMSK                      0x1800u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_SHFT                          11u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_NO_SCALING_FVAL              0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_SCALE_FREQUENCY_DOWNWARD_BY_6_PERCENT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_SCALE_FREQUENCY_DOWNWARD_BY_12_PERCENT_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_SCALE_FREQUENCY_DOWNWARD_BY_25_PERCENT_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT42_BMSK                               0x400u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT42_SHFT                                  10u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BITS41_37_BMSK                           0x3e0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BITS41_37_SHFT                               5u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT36_BMSK                                0x10u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_RESERVE_BIT36_SHFT                                   4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_CALIB_CTRL_BMSK                                    0xeu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_CALIB_CTRL_SHFT                                      1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_CALIB_CTRL_ALWAYS_PERFORM_CALIBRATION_FVAL         0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_CALIB_CTRL_NEVER_PERFORM_CALIBRATION_FVAL          0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_CALIB_CTRL_AUTOMATIC_FVAL                          0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_BMSK                        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_SHFT                          0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_USE_BOTH_FINE_AND_COARSE_LOCK_DETECTORS_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_USE_ONLY_THE_FINE_LOCK_DETECTOR_FVAL        0x1u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_ADDR                                        (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x20u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_OFFS                                        (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x20u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_RMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FINE_LDC_THRESHOLD_BMSK                     0xfc000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FINE_LDC_THRESHOLD_SHFT                             26u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_COARSE_LDC_THRESHOLD_BMSK                    0x3c00000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_COARSE_LDC_THRESHOLD_SHFT                           22u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_COARSE_LOCK_DET_NEG_THRESHOLD_BMSK            0x3c0000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_COARSE_LOCK_DET_NEG_THRESHOLD_SHFT                  18u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_COARSE_LOCK_DET_POS_THRESHOLD_BMSK             0x3c000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_COARSE_LOCK_DET_POS_THRESHOLD_SHFT                  14u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FINE_LOCK_DET_THRESHOLD_BMSK                    0x3800u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FINE_LOCK_DET_THRESHOLD_SHFT                        11u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FINE_LOCK_DET_SAMPLE_SIZE_BMSK                   0x700u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FINE_LOCK_DET_SAMPLE_SIZE_SHFT                       8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FWD_GAIN_SLEWING_KFN_BMSK                         0xf0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FWD_GAIN_SLEWING_KFN_SHFT                            4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FWD_GAIN_KFN_BMSK                                  0xfu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_FWD_GAIN_KFN_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_ADDR                                      (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x24u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_OFFS                                      (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x24u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_RESERVE_BITS63_53_BMSK                    0xffe00000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_RESERVE_BITS63_53_SHFT                            21u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_VCO_RDIV_CONTROL_BMSK                       0x180000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_VCO_RDIV_CONTROL_SHFT                             19u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_DIS_STARTUP_IN_DCO_BIAS_BMSK                 0x40000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_DIS_STARTUP_IN_DCO_BIAS_SHFT                      18u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_HYSTERESIS_FOR_STARTUP_COMP_BMSK             0x20000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_HYSTERESIS_FOR_STARTUP_COMP_SHFT                  17u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_IREF_FOR_STARTUP_COMP_BMSK                   0x10000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_IREF_FOR_STARTUP_COMP_SHFT                        16u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_CASCODE_FREEZE_LOCK_DET_BMSK                  0xc000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_CASCODE_FREEZE_LOCK_DET_SHFT                      14u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_CASCODE_FREEZE_LOCK_DET_COARSE_LOCK_DETECT_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_CASCODE_FREEZE_LOCK_DET_FINE_LOCK_DETECT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_CASCODE_FREEZE_LOCK_DET_PLL_LOCK_DETECT_INT_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_CASCODE_FREEZE_LOCK_DET_RESERVED_FVAL            0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_OSC_SETTLING_TIME_BMSK                        0x3000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_OSC_SETTLING_TIME_SHFT                            12u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_OSC_SETTLING_TIME_COUNT_0_IE_DO_NOT_WAIT_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_OSC_SETTLING_TIME_COUNT_30_REFERENCE_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_OSC_SETTLING_TIME_COUNT_75_REFERENCE_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_OSC_SETTLING_TIME_COUNT_150_REFERENCE_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_NUM_STEPS_FAST_LOCK_BMSK                       0xc00u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_NUM_STEPS_FAST_LOCK_SHFT                          10u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_NUM_STEPS_FAST_LOCK_USE_12_STEPS_FVAL            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_NUM_STEPS_FAST_LOCK_USE_10_STEPS_FVAL            0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_NUM_STEPS_FAST_LOCK_USE_8_STEPS_FVAL             0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_NUM_STEPS_FAST_LOCK_USE_6_STEPS_FVAL             0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_CASC_CURRENT_CTL_B_BMSK                        0x380u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_CASC_CURRENT_CTL_B_SHFT                            7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_INC_MIN_GLITCH_THRESHOLD_4X_BMSK                0x40u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_INC_MIN_GLITCH_THRESHOLD_4X_SHFT                   6u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_INC_MIN_GLITCH_THRESHOLD_4X_MINIMUM_GLITCH_THRESHOLD_IS_NOT_INCREASED_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_INC_MIN_GLITCH_THRESHOLD_4X_MINIMUM_GLITCH_THRESHOLD_IS_INCREASED_BY_4X_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_MIN_GLITCH_THRESHOLD_BMSK                       0x30u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_MIN_GLITCH_THRESHOLD_SHFT                          4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_MIN_GLITCH_THRESHOLD_MINIMUM_OF_4_FVAL           0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_MIN_GLITCH_THRESHOLD_MINIMUM_OF_16_FVAL          0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_MIN_GLITCH_THRESHOLD_MINIMUM_OF_128_FVAL         0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_MIN_GLITCH_THRESHOLD_MINIMUM_OF_256_FVAL         0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_LDET_THRESH_SCALE_BMSK                           0x8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_LDET_THRESH_SCALE_SHFT                             3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_DCO_STARTUP_CONFIG_BMSK                          0x6u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_DCO_STARTUP_CONFIG_SHFT                            1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_DIV_LOCK_DET_THRESHOLDS_BMSK                     0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_DIV_LOCK_DET_THRESHOLDS_SHFT                       0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_DIV_LOCK_DET_THRESHOLDS_DISABLE_FVAL             0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U_DIV_LOCK_DET_THRESHOLDS_ENABLE_FVAL              0x1u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_ADDR                                     (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x28u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_OFFS                                     (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x28u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_THRESHOLD_BMSK                    0xc0000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_THRESHOLD_SHFT                            30u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_PCODE_OFFSET_BMSK                        0x38000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_PCODE_OFFSET_SHFT                                27u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_COUNTER_BLANK_BMSK                        0x4000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_COUNTER_BLANK_SHFT                               26u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_RESYNC_EDGE_BMSK                       0x2000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_RESYNC_EDGE_SHFT                              25u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_RESYNC_SEL_BMSK                        0x1000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_RESYNC_SEL_SHFT                               24u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_LOCK_NUM_SAMPLES_BMSK                   0xc00000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_LOCK_NUM_SAMPLES_SHFT                         22u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_LOCK_THRESH_BMSK                        0x380000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_LOCK_THRESH_SHFT                              19u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_RESERVE_BIT82_BMSK                          0x40000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_RESERVE_BIT82_SHFT                               18u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_NUM_SAMPLES_BMSK                     0x30000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_NUM_SAMPLES_SHFT                          16u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_CORR_INDEX_BMSK                       0xc000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_CORR_INDEX_SHFT                           14u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_EN_BMSK                               0x2000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_EN_SHFT                                   13u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_EN_CALIBRATION_DISABLE_FVAL              0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BB_CAL_EN_CALIBRATION_ENABLE_FVAL               0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_DELAY_AFTER_FLL_LOCKDET_BMSK                 0x1800u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_DELAY_AFTER_FLL_LOCKDET_SHFT                     11u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BBMODE_INT_GAIN_BMSK                          0x780u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BBMODE_INT_GAIN_SHFT                              7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BBMODE_PROP_GAIN_BMSK                          0x78u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_BBMODE_PROP_GAIN_SHFT                             3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_TDC_SELECTION_BMSK                              0x4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_TDC_SELECTION_SHFT                                2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_DITHER_MODE_BMSK                                0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_DITHER_MODE_SHFT                                  1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_FORCE_DSM_ON_BMSK                               0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_FORCE_DSM_ON_SHFT                                 0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_FORCE_DSM_ON_NOT_FORCED_ENABLED_FVAL            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_CONFIG_CTL_U1_FORCE_DSM_ON_FORCED_ENABLED_FVAL                0x1u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ADDR                                          (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x2cu)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_OFFS                                          (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x2cu)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_BIST_CFG_BMSK                                 0xfff80000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_BIST_CFG_SHFT                                         19u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_BMSK                             0x70000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_SHFT                                  16u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_PLLOUT_MAIN_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_PLLOUT_EVEN_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_PLLOUT_ODD_FVAL                      0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_NA_3_FVAL                            0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_NMO_OUTPUT_FVAL                      0x4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_DIVIDER_OUTPUT_FVAL                  0x5u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_NA_6_FVAL                            0x6u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_PLLOUT_TEST_SEL_REFERENCE_CLOCK_FVAL                 0x7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_RESERVE_BIT15_BMSK                                0x8000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_RESERVE_BIT15_SHFT                                    15u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_STATUS_SEL_BMSK                                   0x7c00u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_STATUS_SEL_SHFT                                       10u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_TRAINING_SEQ_EN_BMSK                               0x200u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_TRAINING_SEQ_EN_SHFT                                   9u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_TRAINING_SEQ_EN_NO_TRAINING_SEQUENCE_FVAL            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_TRAINING_SEQ_EN_ENABLE_TRAINING_SEQUENCE_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_STATUS_EN_BMSK                                     0x100u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_STATUS_EN_SHFT                                         8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_STATUS_EN_DISABLE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_STATUS_EN_ENABLE_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VDD_TEST_BMSK                                    0x80u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VDD_TEST_SHFT                                       7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VDD_TEST_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VDD_TEST_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VREG_TEST_BMSK                                   0x40u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VREG_TEST_SHFT                                      6u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VREG_TEST_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VREG_TEST_ENABLE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VREF_TEST_BMSK                                   0x20u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VREF_TEST_SHFT                                      5u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VREF_TEST_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VREF_TEST_ENABLE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VDCO_TEST_BMSK                                   0x10u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VDCO_TEST_SHFT                                      4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VDCO_TEST_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VDCO_TEST_ENABLE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VSS_TEST_BMSK                                     0x8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VSS_TEST_SHFT                                       3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VSS_TEST_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_VSS_TEST_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_IVCO_TEST_BMSK                                    0x4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_IVCO_TEST_SHFT                                      2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_IVCO_TEST_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_EN_IVCO_TEST_ENABLE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ATEST1_EN_BMSK                                       0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ATEST1_EN_SHFT                                         1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ATEST1_EN_DISABLE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ATEST1_EN_ENABLE_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ATEST0_EN_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ATEST0_EN_SHFT                                         0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ATEST0_EN_DISABLE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_ATEST0_EN_ENABLE_FVAL                                0x1u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_ADDR                                        (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x30u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OFFS                                        (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x30u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_RMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_CASC_DAC_FCW_LSBS_BMSK                      0xe0000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_CASC_DAC_FCW_LSBS_SHFT                              29u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_CASC_DAC_BMSK                      0x10000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_CASC_DAC_SHFT                              28u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_CASC_DAC_DO_NOT_OVERRIDE_FVAL             0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_CASC_DAC_OVERRIDE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_COMP_COARSE_FCW_BMSK                         0xe000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_COMP_COARSE_FCW_SHFT                                25u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_COMP_COARSE_FCW_BMSK                0x1800000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_COMP_COARSE_FCW_SHFT                       23u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_COMP_COARSE_FCW_DO_NOT_OVERRIDE_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_COMP_COARSE_FCW_OVERRIDE_THE_INPUT_TO_THE_DAC_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_COMP_COARSE_FCW_OVERRIDE_THE_INTERNAL_COMPENSATION_CODE_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_FINE_FCW_BMSK                                 0x7e0000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_FINE_FCW_SHFT                                       17u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_FINE_FCW_BMSK                         0x10000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_FINE_FCW_SHFT                              16u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_FINE_FCW_DO_NOT_OVERRIDE_FVAL             0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_FINE_FCW_OVERRIDE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_REG_COARSE_FCW_BMSK                             0xfe00u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_REG_COARSE_FCW_SHFT                                  9u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_REG_COARSE_FCW_BMSK                     0x100u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_REG_COARSE_FCW_SHFT                         8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_REG_COARSE_FCW_DO_NOT_OVERRIDE_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_REG_COARSE_FCW_OVERRIDE_FVAL              0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_PROCESS_CALIB_WORD_BMSK                           0xe0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_PROCESS_CALIB_WORD_SHFT                              5u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_CALIB_WORD_BMSK                          0x10u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_CALIB_WORD_SHFT                             4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_CALIB_WORD_DO_NOT_OVERRIDE_FVAL           0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_OVERRIDE_CALIB_WORD_OVERRIDE_FVAL                  0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_DISABLE_CASC_DAC_LATCH_BMSK                        0x8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_DISABLE_CASC_DAC_LATCH_SHFT                          3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_DISABLE_CASC_DAC_LATCH_ENABLE_FVAL                 0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_DISABLE_CASC_DAC_LATCH_DISABLE_FVAL                0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_DISABLE_LFSR_BMSK                                  0x4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_DISABLE_LFSR_SHFT                                    2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_DISABLE_LFSR_ENABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_DISABLE_LFSR_DISABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_SKIP_FINE_TUNE_BMSK                                0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_SKIP_FINE_TUNE_SHFT                                  1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_SKIP_FINE_TUNE_PERFORM_FINE_TUNING_FVAL            0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_SKIP_FINE_TUNE_SKIP_FINE_TUNING_FVAL               0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_SKIP_FAST_LOCK_BMSK                                0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_SKIP_FAST_LOCK_SHFT                                  0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_SKIP_FAST_LOCK_USE_FAST_LOCKING_FVAL               0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U_SKIP_FAST_LOCK_USE_LINEAR_LOCKING_FVAL             0x1u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADDR                                       (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x34u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_OFFS                                       (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x34u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_OUT_CLK_POLARITY_BMSK                      0x80000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_OUT_CLK_POLARITY_SHFT                              31u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_OUT_CLK_POLARITY_DO_NOT_INVERT_OUTPUT_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_OUT_CLK_POLARITY_INVERT_OUTPUT_FVAL               0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_REF_GATING_DISABLE_BMSK                    0x40000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_REF_GATING_DISABLE_SHFT                            30u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_REF_GATING_DISABLE_ENABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_REF_GATING_DISABLE_DISABLE_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_FLL_COUNT_DISABLE_BMSK                     0x20000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_FLL_COUNT_DISABLE_SHFT                             29u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_FLL_COUNT_DISABLE_ENABLE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_FLL_COUNT_DISABLE_DISABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_FLL_COUNT_IN_DIV2_BMSK                     0x10000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_FLL_COUNT_IN_DIV2_SHFT                             28u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_FLL_COUNT_IN_DIV2_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_FLL_COUNT_IN_DIV2_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NMO_START_BMSK                              0x8000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NMO_START_SHFT                                     27u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DIV2_NMO_EN_BMSK                            0x4000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DIV2_NMO_EN_SHFT                                   26u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DIV2_NMO_EN_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DIV2_NMO_EN_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NMO_OSC_SEL_BMSK                            0x3000000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NMO_OSC_SEL_SHFT                                   24u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NMO_OSC_SEL_OFF_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NMO_OSC_SEL_FREQ_OF_1200MHZ_FVAL                  0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NMO_OSC_SEL_FREQ_OF_900MHZ_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NMO_OSC_SEL_FREQ_OF_600MHZ_FVAL                   0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_MAG_BMSK                               0xe00000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_MAG_SHFT                                     21u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_MAG_OFF_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_MAG_NOISE_OF_34MVRMS_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_MAG_NOISE_OF_61MVRMS_FVAL                   0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_MAG_NOISE_OF_72MVRMS_FVAL                   0x7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_GEN_EN_BMSK                            0x100000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_GEN_EN_SHFT                                  20u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_GEN_EN_DISABLE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_NOISE_GEN_EN_ENABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_SILENCE_REF_OUTBUF_BMSK                       0x80000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_SILENCE_REF_OUTBUF_SHFT                            19u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_SILENCE_REF_OUTBUF_DONT_TIE_LOW_FVAL              0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_SILENCE_REF_OUTBUF_TIE_LOW_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_OSCBUF_DYN_SW_BMSK                    0x40000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_OSCBUF_DYN_SW_SHFT                         18u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_OSCBUF_DYN_SW_ENABLE_FVAL                 0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_OSCBUF_DYN_SW_DISABLE_FVAL                0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_REF_CLK_SEL_BMSK                              0x20000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_REF_CLK_SEL_SHFT                                   17u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_REF_CLK_SEL_SELECT_CLK_REF_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_REF_CLK_SEL_SELECT_CLK_AUX_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_RESERVE_BIT80_BMSK                            0x10000ul
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_RESERVE_BIT80_SHFT                                 16u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_RESERVE_BIT79_BMSK                             0x8000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_RESERVE_BIT79_SHFT                                 15u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_CLAMP_BMSK                             0x4000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_CLAMP_SHFT                                 14u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_CLAMP_ENABLE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_CLAMP_DISABLE_FVAL                        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_DAC_AMP_CASCODE_BMSK                   0x2000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_DAC_AMP_CASCODE_SHFT                       13u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_DAC_AMP_CASCODE_ENABLE_FVAL               0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_DISABLE_DAC_AMP_CASCODE_DISABLE_FVAL              0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADD_REF_CYC_CALIB_STEPS_BMSK                   0x1800u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADD_REF_CYC_CALIB_STEPS_SHFT                       11u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADD_REF_CYC_CALIB_STEPS_ADD_0_CYCLES_FVAL         0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADD_REF_CYC_CALIB_STEPS_ADD_1_CYCLES_FVAL         0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADD_REF_CYC_CALIB_STEPS_ADD_2_CYCLES_FVAL         0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ADD_REF_CYC_CALIB_STEPS_ADD_4_CYCLES_FVAL         0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_DETECTOR_COUNT_LIMIT_BMSK                0x600u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_DETECTOR_COUNT_LIMIT_SHFT                    9u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_DETECTOR_COUNT_LIMIT_LIMIT_OF_4_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_DETECTOR_COUNT_LIMIT_LIMIT_OF_16_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_DETECTOR_COUNT_LIMIT_LIMIT_OF_32_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_DETECTOR_COUNT_LIMIT_LIMIT_OF_128_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_PREVENTION_DIS_BMSK                      0x100u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_PREVENTION_DIS_SHFT                          8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_PREVENTION_DIS_GLITCH_DETECTOR_IS_ON_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_GLITCH_PREVENTION_DIS_GLITCH_DETECTOR_IS_OFF_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_COARSE_BIN_OVERRIDE_LOC_BMSK                     0x80u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_COARSE_BIN_OVERRIDE_LOC_SHFT                        7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_COARSE_BIN_OVERRIDE_LOC_AFTER_SPLIT_INTO_REGULAR_AND_COMPENSATION_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_COARSE_BIN_OVERRIDE_LOC_BEFORE_THE_SPLIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_BYPASS_FIRST_ORDER_DSM_BMSK                      0x40u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_BYPASS_FIRST_ORDER_DSM_SHFT                         6u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_BYPASS_FIRST_ORDER_DSM_DO_NOT_BYPASS_FVAL         0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_BYPASS_FIRST_ORDER_DSM_BYPASS_FVAL                0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ATEST_ISCALE_BMSK                                0x30u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_ATEST_ISCALE_SHFT                                   4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_EN_ATEST_LB_BMSK                                  0x8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_EN_ATEST_LB_SHFT                                    3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_EN_ATEST_LB_LOOPBACK_DISABLED_FVAL                0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_EN_ATEST_LB_LOOPBACK_ENABLED_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_BYPASS_ATEST_BUFFER_BMSK                          0x4u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_BYPASS_ATEST_BUFFER_SHFT                            2u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_BYPASS_ATEST_BUFFER_ATEST_BUFFER_ENABLED_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_BYPASS_ATEST_BUFFER_ATEST_BUFFER_DISABLED_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_CASC_DAC_FCW_MSBS_BMSK                            0x3u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_TEST_CTL_U1_CASC_DAC_FCW_MSBS_SHFT                              0u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_ADDR                                               (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x38u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_OFFS                                               (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x38u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_RMSK                                                   0xffffu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_ADDR,v)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_ADDR,m,v,HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_IN)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_SSC_NUM_STEPS_BMSK                                     0xf000u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_SSC_NUM_STEPS_SHFT                                         12u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_SSC_UPDATE_RATE_BMSK                                    0xf00u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_SSC_UPDATE_RATE_SHFT                                        8u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_SSC_DELTA_ALPHA_BMSK                                     0xffu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_PLL_SSC_SSC_DELTA_ALPHA_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_ADDR                                  (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE      + 0x80u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_OFFS                                  (SAIL_TO_MD_GCC_GPLL7_GCC_GPLL7_CM_PLL_LUCID_EVO_REG_BASE_OFFS + 0x80u)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_RMSK                                      0x1fffu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_HPCNT_BMSK                                0x1f80u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_HPCNT_SHFT                                     7u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_VPCNT_BMSK                                  0x7eu
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_VPCNT_SHFT                                     1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_FLT_BMSK                                     0x1u
#define HWIO_SAIL_TO_MD_GCC_GPLL7_FUSA_STATUS_REGISTER_FLT_SHFT                                       0u


#endif /* __G_SAIL_TO_MD_GCC_GPLL7_HWIO_H__ */
