#ifndef __G_SAIL_PWR_CTRL_H__
#define __G_SAIL_PWR_CTRL_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_PWR_CTRL.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER


    Generation parameters: 
    { 'filename': 'g_SAIL_PWR_CTRL.h',
      'integer-qualifiers': True,
      'modules': ['SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/common_inc/8650/g_SAIL_PWR_CTRL.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER
 *--------------------------------------------------------------------------*/

#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_BASE      + 0x00000000u)
#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_SIZE                                                 0x10000ul
#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_USED                                                 0x53fcu
#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS                                                 0x00000000u

#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_ADDR                                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x0u)
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_OFFS                                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x0u)
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_RMSK                                                                        0x7u
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_IN)
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK                                         0x4u
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_SHFT                                           2u
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_ISD_MOVE_TO_ISLAND_STATE_BMSK                                               0x2u
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_ISD_MOVE_TO_ISLAND_STATE_SHFT                                                 1u
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_ISD_MOVE_TO_NORMAL_STATE_BMSK                                               0x1u
#define HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_ISD_MOVE_TO_NORMAL_STATE_SHFT                                                 0u

#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_ADDR                                                                (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4u)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_OFFS                                                                (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4u)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_RMSK                                                                      0xffu
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_IN)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_DEBUG_BMSK                                        0x80u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_DEBUG_SHFT                                           7u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_DFT_BMSK                                          0x40u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_DFT_SHFT                                             6u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_CLK_BMSK                                          0x20u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_CLK_SHFT                                             5u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_BMSK                                              0x10u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_SHFT                                                 4u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_DEBUG_BMSK                                          0x8u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_DEBUG_SHFT                                            3u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_DFT_BMSK                                            0x4u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_DFT_SHFT                                              2u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_CLK_BMSK                                            0x2u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_CLK_SHFT                                              1u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_BMSK                                                0x1u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_SHFT                                                  0u

#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ADDR                                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x8u)
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_OFFS                                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x8u)
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_RMSK                                                                  0x3ffffffful
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_AGGR_FATAL_ERR_PS_HOLD_BMSK                                           0x20000000ul
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_AGGR_FATAL_ERR_PS_HOLD_SHFT                                                   29u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_AGGR_FATAL_ERR_ISO_EN_BMSK                                            0x10000000ul
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_AGGR_FATAL_ERR_ISO_EN_SHFT                                                    28u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_MUX_SEL_BMSK                                                  0xc000000ul
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_MUX_SEL_SHFT                                                         26u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_COUNTER_RESET_BMSK                                            0x2000000ul
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_COUNTER_RESET_SHFT                                                   25u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_COUNTER_HALT_BMSK                                             0x1000000ul
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_COUNTER_HALT_SHFT                                                    24u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_COUNT_ZEROS_BMSK                                               0xffc000ul
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_COUNT_ZEROS_SHFT                                                     14u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_COUNT_ONES_BMSK                                                  0x3ff0u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_DEGLITCH_COUNT_ONES_SHFT                                                       4u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK                                                        0x8u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_SHFT                                                          3u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_FSM_STATE_BMSK                                                           0x6u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_FSM_STATE_SHFT                                                             1u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_SAIL_FROM_MD_CX_ISO_EN_SEQ_BMSK                                              0x1u
#define HWIO_SAILSS_PWR_CTRL_ISD_STATUS_SAIL_FROM_MD_CX_ISO_EN_SEQ_SHFT                                                0u

#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_ADDR                                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0xcu)
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_OFFS                                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0xcu)
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_RMSK                                                                            0x3u
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PS_HOLD_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PS_HOLD_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PS_HOLD_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PS_HOLD_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PS_HOLD_IN)
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_TO_MD_PS_HOLD_BMSK                                                         0x2u
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_TO_MD_PS_HOLD_SHFT                                                           1u
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_PS_HOLD_BMSK                                                               0x1u
#define HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_PS_HOLD_SHFT                                                                 0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x10u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_OFFS                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x10u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_RMSK                                                  0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_SAIL_FATAL_ERR_ISO_EN_MASK_BMSK                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_SAIL_FATAL_ERR_ISO_EN_MASK_SHFT                                0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x14u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OFFS                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x14u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_RMSK                                              0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_BMSK               0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_SHFT                        0u

#define HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x18u)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_OFFS                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x18u)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_RMSK                                                       0x3ffu
#define HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_IN)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_ISD_DEGLITCH_MAX_COUNT_VAL_BMSK                            0x3ffu
#define HWIO_SAILSS_PWR_CTRL_ISD_DEGLITCH_MAX_COUNT_VAL_ISD_DEGLITCH_MAX_COUNT_VAL_SHFT                                0u

#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ADDR                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1cu)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_OFFS                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_RMSK                                                                0xfu
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_IN)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_4_BMSK                                          0x8u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_4_SHFT                                            3u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_3_BMSK                                          0x4u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_3_SHFT                                            2u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_2_BMSK                                          0x2u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_2_SHFT                                            1u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_1_BMSK                                          0x1u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_1_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ADDR                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x20u)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_OFFS                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x20u)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_RMSK                                                               0x3fu
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_IN)
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_6_BMSK                                         0x20u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_6_SHFT                                            5u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_5_BMSK                                         0x10u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_5_SHFT                                            4u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_4_BMSK                                          0x8u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_4_SHFT                                            3u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_3_BMSK                                          0x4u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_3_SHFT                                            2u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_2_BMSK                                          0x2u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_2_SHFT                                            1u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_1_BMSK                                          0x1u
#define HWIO_SAILSS_PWR_CTRL_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_1_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ADDR                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x24u)
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_OFFS                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x24u)
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_RMSK                                                                0x7u
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_IN)
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_3_BMSK                                          0x4u
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_3_SHFT                                            2u
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_2_BMSK                                          0x2u
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_2_SHFT                                            1u
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_1_BMSK                                          0x1u
#define HWIO_SAILSS_PWR_CTRL_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_1_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_ADDR                                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x28u)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_OFFS                                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x28u)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_RMSK                                                                    0xffu
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_DEBUG_BMSK                                      0x80u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_DEBUG_SHFT                                         7u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_DFT_BMSK                                        0x40u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_DFT_SHFT                                           6u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_CLK_BMSK                                        0x20u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_CLK_SHFT                                           5u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_BMSK                                            0x10u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_SHFT                                               4u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_DEBUG_BMSK                                        0x8u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_DEBUG_SHFT                                          3u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_DFT_BMSK                                          0x4u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_DFT_SHFT                                            2u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_CLK_BMSK                                          0x2u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_CLK_SHFT                                            1u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_BMSK                                              0x1u
#define HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_SHFT                                                0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x2cu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x2cu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_ADDR                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x30u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_OFFS                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x30u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_RMSK                                            0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_BMSK           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_SHFT                    0u

#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_ADDR                                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x34u)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_OFFS                                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x34u)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_RMSK                                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_IN)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_ISD_SPARE_REG_0_BMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_0_ISD_SPARE_REG_0_SHFT                                                      0u

#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_ADDR                                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x38u)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_OFFS                                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x38u)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_RMSK                                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_IN)
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_ISD_SPARE_REG_1_BMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_ISD_SPARE_REG_1_ISD_SPARE_REG_1_SHFT                                                      0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_ADDR                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x400u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_OFFS                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x400u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_RMSK                                                                  0xfu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_WDOG_TIMER_CLK_ON_BMSK                                                0x8u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_WDOG_TIMER_CLK_ON_SHFT                                                  3u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_WDOG_BARK_RESET_BMSK                                                  0x4u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_WDOG_BARK_RESET_SHFT                                                    2u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_WDOG_BITE_RESET_BMSK                                                  0x2u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_WDOG_BITE_RESET_SHFT                                                    1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_FREEZE_THE_WDOG_BMSK                                                  0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_FREEZE_THE_WDOG_SHFT                                                    0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x404u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_OFFS                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x404u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_RMSK                                                          0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_ENABLE_THE_WDOG_BMSK                                          0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL_EN_WDOG_ENABLE_THE_WDOG_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_ADDR                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x408u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_OFFS                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x408u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_RMSK                                                                0xfu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_WDOG_CNT_RES_STS_BMSK                                               0x8u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_WDOG_CNT_RES_STS_SHFT                                                 3u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_WDOG_RES_SOURCE_BMSK                                                0x4u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_WDOG_RES_SOURCE_SHFT                                                  2u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_WDOG_BITE_IRQ_BMSK                                                  0x2u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_WDOG_BITE_IRQ_SHFT                                                    1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_WDOG_BARK_IRQ_BMSK                                                  0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS_WDOG_BARK_IRQ_SHFT                                                    0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x40cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x40cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_RMSK                                                         0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_PWR_SEQ_WDOG_BARK_TIME_BMSK                                  0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BARK_TIME_PWR_SEQ_WDOG_BARK_TIME_SHFT                                        0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x410u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x410u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_RMSK                                                         0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_PWR_SEQ_WDOG_BITE_TIME_BMSK                                  0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_BITE_TIME_PWR_SEQ_WDOG_BITE_TIME_SHFT                                        0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_ADDR                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x414u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_OFFS                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x414u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_RMSK                                                        0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_PWR_SEQ_WDOG_TEST_VALUE_BMSK                                0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_TEST_VALUE_PWR_SEQ_WDOG_TEST_VALUE_SHFT                                      0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_COUNT_ADDR                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x418u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_COUNT_OFFS                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x418u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_COUNT_RMSK                                                             0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_COUNT_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_COUNT_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_COUNT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_COUNT_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_COUNT_PWR_SEQ_WDOG_COUNT_BMSK                                          0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WDOG_COUNT_PWR_SEQ_WDOG_COUNT_SHFT                                                0u

#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_ADDR                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x420u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_OFFS                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x420u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_RMSK                                                                  0x3fu
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_PWR_CTRL_RSVD_BMSK                                                    0x3eu
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_PWR_CTRL_RSVD_SHFT                                                       1u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_SAIL_LOW_PWR_ENTRY_BMSK                                                0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_CONTROL_SAIL_LOW_PWR_ENTRY_SHFT                                                  0u

#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_ADDR                                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x424u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_OFFS                                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x424u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_RMSK                                                                    0x7u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_SLEEP_EXIT_BMSK                                                         0x4u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_SLEEP_EXIT_SHFT                                                           2u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_SLEEP_ENTRY_BMSK                                                        0x2u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_SLEEP_ENTRY_SHFT                                                          1u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_SAIL_IS_IN_SLEEP_BMSK                                                   0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_STATUS_SAIL_IS_IN_SLEEP_SHFT                                                     0u

#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x428u)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x428u)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_RMSK                                                             0xfu
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_QACTIVE_BMSK                                                     0x8u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_QACTIVE_SHFT                                                       3u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_QDENY_BMSK                                                       0x4u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_QDENY_SHFT                                                         2u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_QACCEPTN_BMSK                                                    0x2u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_QACCEPTN_SHFT                                                      1u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_QREQN_BMSK                                                       0x1u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL_QREQN_SHFT                                                         0u

#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_ADDR                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x42cu)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_OFFS                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x42cu)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_RMSK                                                              0x1fffu
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_IN)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_QCH_DENY_TO_REQ_CNT_BMSK                                          0x1fe0u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_QCH_DENY_TO_REQ_CNT_SHFT                                               5u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_QCH_HYST_CNT_BMSK                                                   0x1fu
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_CTRL_QCH_HYST_CNT_SHFT                                                      0u

#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_ADDR                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x430u)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_OFFS                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x430u)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_RMSK                                                              0x7fu
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_LOW_PWR_RDY_BMSK                                                  0x40u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_LOW_PWR_RDY_SHFT                                                     6u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_QCH_FSM_CUR_STATE_BMSK                                            0x3cu
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_QCH_FSM_CUR_STATE_SHFT                                               2u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_QCH_HYST_CNT_EXPIRY_BMSK                                           0x2u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_QCH_HYST_CNT_EXPIRY_SHFT                                             1u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_QCH_DENY_TO_REQ_CNT_EXPIRY_BMSK                                    0x1u
#define HWIO_SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS_QCH_DENY_TO_REQ_CNT_EXPIRY_SHFT                                      0u

#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x434u)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x434u)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_RMSK                                                             0xfu
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_QACTIVE_BMSK                                                     0x8u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_QACTIVE_SHFT                                                       3u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_QDENY_BMSK                                                       0x4u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_QDENY_SHFT                                                         2u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_QACCEPTN_BMSK                                                    0x2u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_QACCEPTN_SHFT                                                      1u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_QREQN_BMSK                                                       0x1u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL_QREQN_SHFT                                                         0u

#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_ADDR                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x438u)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_OFFS                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x438u)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_RMSK                                                              0x1fffu
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_IN)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_QCH_DENY_TO_REQ_CNT_BMSK                                          0x1fe0u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_QCH_DENY_TO_REQ_CNT_SHFT                                               5u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_QCH_HYST_CNT_BMSK                                                   0x1fu
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_CTRL_QCH_HYST_CNT_SHFT                                                      0u

#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_ADDR                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x43cu)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_OFFS                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x43cu)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_RMSK                                                              0x7fu
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_LOW_PWR_RDY_BMSK                                                  0x40u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_LOW_PWR_RDY_SHFT                                                     6u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_QCH_FSM_CUR_STATE_BMSK                                            0x3cu
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_QCH_FSM_CUR_STATE_SHFT                                               2u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_QCH_HYST_CNT_EXPIRY_BMSK                                           0x2u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_QCH_HYST_CNT_EXPIRY_SHFT                                             1u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_QCH_DENY_TO_REQ_CNT_EXPIRY_BMSK                                    0x1u
#define HWIO_SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS_QCH_DENY_TO_REQ_CNT_EXPIRY_SHFT                                      0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_ADDR                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x440u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_OFFS                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x440u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_RMSK                                                       0x3fu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PACTIVE_BMSK                                               0x30u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PACTIVE_SHFT                                                  4u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PDENY_BMSK                                                  0x8u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PDENY_SHFT                                                    3u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PACCEPT_BMSK                                                0x4u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PACCEPT_SHFT                                                  2u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PREQ_BMSK                                                   0x2u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PREQ_SHFT                                                     1u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PSTATE_BMSK                                                 0x1u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL_PSTATE_SHFT                                                   0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_ADDR                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x444u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_OFFS                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x444u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_RMSK                                                         0xffffu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_IN)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_BMSK                                0xff00u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_SHFT                                     8u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_PSTABLE_TIMER_CFG_BMSK                                         0xffu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_CTRL_PSTABLE_TIMER_CFG_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS_ADDR                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x448u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS_OFFS                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x448u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS_RMSK                                                          0x7u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS_FSM_CUR_STATE_BMSK                                            0x7u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS_FSM_CUR_STATE_SHFT                                              0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_ADDR                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x44cu)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_OFFS                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x44cu)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_RMSK                                                       0x3fu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PACTIVE_BMSK                                               0x30u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PACTIVE_SHFT                                                  4u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PDENY_BMSK                                                  0x8u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PDENY_SHFT                                                    3u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PACCEPT_BMSK                                                0x4u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PACCEPT_SHFT                                                  2u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PREQ_BMSK                                                   0x2u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PREQ_SHFT                                                     1u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PSTATE_BMSK                                                 0x1u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL_PSTATE_SHFT                                                   0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_ADDR                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x450u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_OFFS                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x450u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_RMSK                                                         0xffffu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_IN)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_BMSK                                0xff00u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_SHFT                                     8u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_PSTABLE_TIMER_CFG_BMSK                                         0xffu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_CTRL_PSTABLE_TIMER_CFG_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS_ADDR                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x454u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS_OFFS                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x454u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS_RMSK                                                          0x7u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS_FSM_CUR_STATE_BMSK                                            0x7u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS_FSM_CUR_STATE_SHFT                                              0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_ADDR                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x458u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_OFFS                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x458u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_RMSK                                                       0x3fu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PACTIVE_BMSK                                               0x30u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PACTIVE_SHFT                                                  4u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PDENY_BMSK                                                  0x8u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PDENY_SHFT                                                    3u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PACCEPT_BMSK                                                0x4u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PACCEPT_SHFT                                                  2u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PREQ_BMSK                                                   0x2u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PREQ_SHFT                                                     1u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PSTATE_BMSK                                                 0x1u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL_PSTATE_SHFT                                                   0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_ADDR                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x45cu)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_OFFS                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x45cu)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_RMSK                                                         0xffffu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_IN)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_BMSK                                0xff00u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_SHFT                                     8u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_PSTABLE_TIMER_CFG_BMSK                                         0xffu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_CTRL_PSTABLE_TIMER_CFG_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS_ADDR                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x460u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS_OFFS                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x460u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS_RMSK                                                          0x7u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS_FSM_CUR_STATE_BMSK                                            0x7u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS_FSM_CUR_STATE_SHFT                                              0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_ADDR                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x464u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_OFFS                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x464u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_RMSK                                                       0x3fu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PACTIVE_BMSK                                               0x30u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PACTIVE_SHFT                                                  4u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PDENY_BMSK                                                  0x8u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PDENY_SHFT                                                    3u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PACCEPT_BMSK                                                0x4u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PACCEPT_SHFT                                                  2u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PREQ_BMSK                                                   0x2u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PREQ_SHFT                                                     1u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PSTATE_BMSK                                                 0x1u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL_PSTATE_SHFT                                                   0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_ADDR                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x468u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_OFFS                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x468u)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_RMSK                                                         0xffffu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_IN)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_BMSK                                0xff00u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_SHFT                                     8u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_PSTABLE_TIMER_CFG_BMSK                                         0xffu
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_CTRL_PSTABLE_TIMER_CFG_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS_ADDR                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x46cu)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS_OFFS                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x46cu)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS_RMSK                                                          0x7u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS_FSM_CUR_STATE_BMSK                                            0x7u
#define HWIO_SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS_FSM_CUR_STATE_SHFT                                              0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_ADDR                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x470u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_OFFS                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x470u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_RMSK                                                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_IN)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_WAKE_IRQ_CFG_ENABLE_BMSK                                   0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0_WAKE_IRQ_CFG_ENABLE_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x474u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x474u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_RMSK                                                      0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_IN)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_WAKE_IRQ_CFG_NEGEDGE_BMSK                                 0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0_WAKE_IRQ_CFG_NEGEDGE_SHFT                                          0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x478u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x478u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_RMSK                                                      0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_IN)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_WAKE_IRQ_CFG_POSEDGE_BMSK                                 0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0_WAKE_IRQ_CFG_POSEDGE_SHFT                                          0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_ADDR                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x47cu)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_OFFS                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x47cu)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_RMSK                                                     0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_IN)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_WAKE_IRQ_CFG_POLARITY_BMSK                               0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0_WAKE_IRQ_CFG_POLARITY_SHFT                                        0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_0_ADDR                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x480u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_0_OFFS                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x480u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_0_RMSK                                                           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_0_WAKE_IRQ_STATUS_BMSK                                           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_0_WAKE_IRQ_STATUS_SHFT                                                    0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_ADDR                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x484u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_OFFS                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x484u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_RMSK                                                                   0x7u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_IN)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_WAKE_HANDLER_CLK_ENABLE_BMSK                                           0x4u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_WAKE_HANDLER_CLK_ENABLE_SHFT                                             2u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_STOP_MONITORING_BMSK                                                   0x2u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_STOP_MONITORING_SHFT                                                     1u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_START_MONITORING_BMSK                                                  0x1u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_CFG_START_MONITORING_SHFT                                                    0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_ADDR                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x488u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_OFFS                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x488u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_RMSK                                                               0x1fu
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_REPLAY_CURR_STATE_BMSK                                             0x18u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_REPLAY_CURR_STATE_SHFT                                                3u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_MAIN_CURR_STATE_BMSK                                                0x6u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_MAIN_CURR_STATE_SHFT                                                  1u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_MONITORING_STARTED_BMSK                                             0x1u
#define HWIO_SAILSS_PWR_CTRL_WAKE_HANDLER_STATUS_MONITORING_STARTED_SHFT                                               0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_ADDR                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x48cu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_OFFS                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x48cu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_RMSK                                                        0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_SAIL_CX_APM_FUNC_OUT_BMSK                                   0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT_SAIL_CX_APM_FUNC_OUT_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_IN_ADDR                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x490u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_IN_OFFS                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x490u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_IN_RMSK                                                         0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_IN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_IN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_IN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_IN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_IN_SAIL_CX_APM_FUNC_IN_BMSK                                     0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_IN_SAIL_CX_APM_FUNC_IN_SHFT                                              0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x494u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x494u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_SAIL_CX_APM_CONTROLLER_CONFIG_0_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0_SAIL_CX_APM_CONTROLLER_CONFIG_0_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x498u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x498u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_SAIL_CX_APM_CONTROLLER_CONFIG_1_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1_SAIL_CX_APM_CONTROLLER_CONFIG_1_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x49cu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x49cu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_SAIL_CX_APM_CONTROLLER_CONFIG_2_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2_SAIL_CX_APM_CONTROLLER_CONFIG_2_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4a0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4a0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_SAIL_CX_APM_CONTROLLER_CONFIG_3_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_3_SAIL_CX_APM_CONTROLLER_CONFIG_3_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4a4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4a4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_SAIL_CX_APM_CONTROLLER_CONFIG_4_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_4_SAIL_CX_APM_CONTROLLER_CONFIG_4_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4a8u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4a8u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_BMSK            0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_SHFT                     0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4acu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4acu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_BMSK            0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_SHFT                     0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4b0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4b0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_SAIL_CX_APM_CONTROLLER_CONFIG_7_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_7_SAIL_CX_APM_CONTROLLER_CONFIG_7_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4b4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4b4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_BMSK            0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_SHFT                     0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4b8u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4b8u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_BMSK            0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_SHFT                     0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4bcu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4bcu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_RSVD_OUT_BMSK                                    0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_OUT_RSVD_OUT_SHFT                                             0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_0_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4c0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_0_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4c0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_0_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_0_SAIL_CX_APM_CONTROLLER_STATUS_0_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_0_SAIL_CX_APM_CONTROLLER_STATUS_0_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_1_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4c4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_1_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4c4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_1_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_1_SAIL_CX_APM_CONTROLLER_STATUS_1_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_1_SAIL_CX_APM_CONTROLLER_STATUS_1_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_2_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4c8u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_2_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4c8u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_2_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_2_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_2_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_2_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_2_SAIL_CX_APM_CONTROLLER_STATUS_2_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_2_SAIL_CX_APM_CONTROLLER_STATUS_2_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_3_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4ccu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_3_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4ccu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_3_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_3_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_3_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_3_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_3_SAIL_CX_APM_CONTROLLER_STATUS_3_BMSK             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_STATUS_3_SAIL_CX_APM_CONTROLLER_STATUS_3_SHFT                      0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_IN_ADDR                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4d0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_IN_OFFS                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4d0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_IN_RMSK                                              0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_IN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_IN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_IN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_IN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_IN_RSVD_IN_BMSK                                      0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_RSVD_IN_RSVD_IN_SHFT                                               0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4d4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_OFFS                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4d4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_RMSK                                           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_BMSK          0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_SHFT                   0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4d8u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_OFFS                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4d8u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_RMSK                                           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_BMSK          0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_SHFT                   0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4dcu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_OFFS                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4dcu)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_RMSK                                           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_BMSK          0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_SHFT                   0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4e0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_OFFS                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4e0u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_RMSK                                           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_BMSK          0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_SHFT                   0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x4e4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_OFFS                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x4e4u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_RMSK                                                     0x1u
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_CSR_SAIL_CX_APM_CTRL_SEL_BMSK                            0x1u
#define HWIO_SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONTROL_CSR_SAIL_CX_APM_CTRL_SEL_SHFT                              0u

#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR                                                (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x500u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_OFFS                                                (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x500u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_RMSK                                                0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_BMSK                   0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_SHFT                            0u

#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR                                                (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x504u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_OFFS                                                (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x504u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_RMSK                                                0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_EN_BMSK                      0x80000000ul
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_EN_SHFT                              31u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_RSVD_BMSK              0x7f000000ul
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_RSVD_SHFT                      24u
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_BMSK                     0xfffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_SHFT                            0u

#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_ADDR                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x508u)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_OFFS                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x508u)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_RMSK                                                               0x1ffu
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_IN)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_PC_DEBUG_BUS_CX_EN_BMSK                                            0x1ffu
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_CX_EN_PC_DEBUG_BUS_CX_EN_SHFT                                                0u

#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_ADDR                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x50cu)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_OFFS                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x50cu)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_RMSK                                                          0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_IN)
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_PC_DEBUG_BUS_MX_EN_BMSK                                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PC_DEBUG_BUS_MX_EN_PC_DEBUG_BUS_MX_EN_SHFT                                                0u

#define HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_ADDR                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x510u)
#define HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_OFFS                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x510u)
#define HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_RMSK                                                             0x3fffful
#define HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_IN)
#define HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_PC_HW_EVENTS_MX_EN_BMSK                                          0x3fffful
#define HWIO_SAILSS_PWR_CTRL_PC_HW_EVENTS_MX_EN_PC_HW_EVENTS_MX_EN_SHFT                                                0u

#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x514u)
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x514u)
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_RMSK                                                             0x3u
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_IN)
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_PC_DEBUG_BUS_MX_MASTER_EN_BMSK                                   0x2u
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_PC_DEBUG_BUS_MX_MASTER_EN_SHFT                                     1u
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_ISD_DEBUG_BUS_MX_MASTER_EN_BMSK                                  0x1u
#define HWIO_SAILSS_PWR_CTRL_DEBUG_BUS_MX_MASTER_EN_ISD_DEBUG_BUS_MX_MASTER_EN_SHFT                                    0u

#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_ADDR                                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x518u)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_OFFS                                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x518u)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_RMSK                                                                         0x1u
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_IN)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_HVM_CXO_PAD_EN_BMSK                                                          0x1u
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_HVM_CXO_PAD_EN_SHFT                                                            0u

#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS_ADDR                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x51cu)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS_OFFS                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x51cu)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS_RMSK                                                                  0x1u
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS_HVM_CXO_PAD_EN_BMSK                                                   0x1u
#define HWIO_SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS_HVM_CXO_PAD_EN_SHFT                                                     0u

#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x520u)
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x520u)
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_RMSK                                                            0x7fu
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_IN)
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_PULL_BMSK                                            0x60u
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_PULL_SHFT                                               5u
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_HDRIVE_BMSK                                          0x1cu
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_HDRIVE_SHFT                                             2u
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_OE_BMSK                                               0x2u
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_OE_SHFT                                                 1u
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_IE_BMSK                                               0x1u
#define HWIO_SAILSS_PWR_CTRL_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_IE_SHFT                                                 0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_ADDR                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x524u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_OFFS                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x524u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_RMSK                                                          0x7fu
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_PULL_BMSK                                        0x60u
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_PULL_SHFT                                           5u
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_HDRIVE_BMSK                                      0x1cu
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_HDRIVE_SHFT                                         2u
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_OE_BMSK                                           0x2u
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_OE_SHFT                                             1u
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_IE_BMSK                                           0x1u
#define HWIO_SAILSS_PWR_CTRL_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_IE_SHFT                                             0u

#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_ADDR                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x528u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_OFFS                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x528u)
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_RMSK                                                         0x7fu
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_IN)
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_PULL_BMSK                                      0x60u
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_PULL_SHFT                                         5u
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_HDRIVE_BMSK                                    0x1cu
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_HDRIVE_SHFT                                       2u
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_OE_BMSK                                         0x2u
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_OE_SHFT                                           1u
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_IE_BMSK                                         0x1u
#define HWIO_SAILSS_PWR_CTRL_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_IE_SHFT                                           0u

#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_ADDR                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x600u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_OFFS                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x600u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_RMSK                                                        0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_PWR_CTRL_SPARE_REG_BMSK                                     0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0_PWR_CTRL_SPARE_REG_SHFT                                              0u

#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_ADDR                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x604u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_OFFS                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x604u)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_RMSK                                                        0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_PWR_CTRL_SPARE_REG_BMSK                                     0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_1_PWR_CTRL_SPARE_REG_SHFT                                              0u

#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_ADDR                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0xf50u)
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_OFFS                                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0xf50u)
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_RMSK                                                            0x1fffu
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_HPCNT_BMSK                                                      0x1f80u
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_HPCNT_SHFT                                                           7u
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_VPCNT_BMSK                                                        0x7eu
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_VPCNT_SHFT                                                           1u
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_FLT_BMSK                                                           0x1u
#define HWIO_SAILSS_PWR_CTRL_FUSA_STATUS_REGISTER_FLT_SHFT                                                             0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_ADDR                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1000u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_OFFS                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1000u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_RMSK                                                                   0x3u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_DISABLE_DEBUG_CSR_UPDATE_BMSK                                          0x2u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_DISABLE_DEBUG_CSR_UPDATE_SHFT                                            1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_FORCE_CLK_EN_BMSK                                                      0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_0_FORCE_CLK_EN_SHFT                                                        0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PARAM_SEQ_CONFIG_ADDR                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1004u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PARAM_SEQ_CONFIG_OFFS                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1004u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PARAM_SEQ_CONFIG_RMSK                                                         0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PARAM_SEQ_CONFIG_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PARAM_SEQ_CONFIG_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PARAM_SEQ_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PARAM_SEQ_CONFIG_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PARAM_SEQ_CONFIG_NUM_SEQ_CMD_WORDS_BMSK                                       0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PARAM_SEQ_CONFIG_NUM_SEQ_CMD_WORDS_SHFT                                           0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BUSY_ADDR                                                                (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1008u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BUSY_OFFS                                                                (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1008u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BUSY_RMSK                                                                       0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BUSY_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BUSY_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BUSY_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BUSY_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BUSY_BUSY_STAT_BMSK                                                             0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BUSY_BUSY_STAT_SHFT                                                               0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER_ADDR                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x100cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER_OFFS                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x100cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER_RMSK                                                      0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_BMSK                                   0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_SHFT                                       0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STAT_ADDR                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1010u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STAT_OFFS                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1010u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STAT_RMSK                                                                   0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STAT_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STAT_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STAT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STAT_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STAT_DBG_STEPPING_STATUS_BMSK                                               0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STAT_DBG_STEPPING_STATUS_SHFT                                                 0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_ADDR                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1014u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_OFFS                                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1014u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_RMSK                                                               0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_SEQ_START_ADDR_BMSK                                                0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_START_ADDR_SEQ_START_ADDR_SHFT                                                    0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_ADDR                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1018u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_OFFS                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1018u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_RMSK                                                 0x800003fful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_BMSK                              0x80000000ul
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_SHFT                                      31u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_BMSK                              0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_SHFT                                  0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_ADDR                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x101cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_OFFS                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x101cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_RMSK                                                           0x3u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_OVERRIDE_TRIGGER_BMSK                                0x2u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_OVERRIDE_TRIGGER_SHFT                                  1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_SW_OVERRIDE_NO_TRIGGER_FVAL        0x0u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_SW_OVERRIDE_TRIGGER_FVAL        0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_BMSK                                      0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_SHFT                                        0u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_SEQ_SW_OVERRIDE_NO_TRIGGER_FVAL           0x0u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_SEQ_SW_OVERRIDE_TRIGGER_FVAL              0x1u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1020u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_OFFS                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1020u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_RMSK                                            0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_PWR_CTRL_OVERRIDE_MASK_BMSK                     0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_PWR_CTRL_OVERRIDE_MASK_SHFT                              0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1024u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1024u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_PWR_CTRL_OVERRIDE_VAL_BMSK                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_PWR_CTRL_OVERRIDE_VAL_SHFT                                0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1028u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_OFFS                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1028u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_RMSK                                            0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_PWR_CTRL_OVERRIDE_MASK_BMSK                     0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_PWR_CTRL_OVERRIDE_MASK_SHFT                              0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x102cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x102cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_PWR_CTRL_OVERRIDE_VAL_BMSK                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_PWR_CTRL_OVERRIDE_VAL_SHFT                                0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1030u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_OFFS                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1030u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_RMSK                                            0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_BMSK                   0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_SHFT                            0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1034u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_OFFS                                             (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1034u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_RMSK                                             0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_BMSK                     0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_SHFT                              0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_ADDR                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1038u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_OFFS                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1038u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_RMSK                                                           0xfu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_MD_WAKE_UP_BMSK                                                0x8u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_MD_WAKE_UP_SHFT                                                  3u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_SAIL_WAKE_UP_BMSK                                              0x4u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_SAIL_WAKE_UP_SHFT                                                2u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_SAIL_PMIC_WAKEUP_BMSK                                          0x2u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_SAIL_PMIC_WAKEUP_SHFT                                            1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_LOW_POWER_MODE_BMSK                                            0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_CONTROL_LOW_POWER_MODE_SHFT                                              0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x103cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_OFFS                                              (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x103cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_RMSK                                              0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_BMSK                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_SHFT                                0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR                                               (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1040u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_OFFS                                               (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1040u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_RMSK                                               0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_BMSK                         0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_SHFT                                  0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(b)                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0X1050 + (0x4*(b)))
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_OFFS(b)                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0X1050 + (0x4*(b)))
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_RMSK                                                         0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_MAXb                                                            31u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_INI(b)                \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(b), HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_RMSK)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_INMI(b,mask)        \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(b), mask)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_OUTI(b,val)        \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(b),val)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_OUTMI(b,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(b),mask,val,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_INI(b))
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_CFG_BR_ADDR_BMSK                                             0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_BR_ADDR_b_CFG_BR_ADDR_SHFT                                                 0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(v)                                               (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0X1150 + (0x4*(v)))
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_OFFS(v)                                               (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0X1150 + (0x4*(v)))
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_RMSK                                                     0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_MAXv                                                          15u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_INI(v)                \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(v), HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_RMSK)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_INMI(v,mask)        \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(v), mask)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_OUTI(v,val)        \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(v),val)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_OUTMI(v,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(v),mask,val,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_INI(v))
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_CFG_DELAY_VAL_BMSK                                       0xffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_CONFIG_DELAY_VAL_v_CFG_DELAY_VAL_SHFT                                             0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1200u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_OFFS                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1200u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_RMSK                                                 0x800003fful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_BMSK                            0x80000000ul
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_SHFT                                    31u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_BMSK                                  0x3ffu
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_SHFT                                      0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_ADDR                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1204u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_OFFS                                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1204u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_RMSK                                                               0x10001ul
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_IN)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_SEQ_DBG_STEP_TRIGGER_BMSK                                          0x10000ul
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_SEQ_DBG_STEP_TRIGGER_SHFT                                               16u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_SEQ_DBG_STEP_CONTINUE_BMSK                                             0x1u
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_DBG_STEP_SEQ_DBG_STEP_CONTINUE_SHFT                                               0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0_ADDR                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1208u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0_OFFS                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1208u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0_RMSK                                                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0_PWR_SEQ_PWR_CONTROL_0_BMSK                                 0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0_PWR_SEQ_PWR_CONTROL_0_SHFT                                          0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1_ADDR                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x120cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1_OFFS                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x120cu)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1_RMSK                                                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1_PWR_SEQ_PWR_CONTROL_1_BMSK                                 0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1_PWR_SEQ_PWR_CONTROL_1_SHFT                                          0u

#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS_ADDR                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1210u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS_OFFS                                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1210u)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS_RMSK                                                         0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS_PWR_SEQ_WAIT_EVENTS_BMSK                                     0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS_PWR_SEQ_WAIT_EVENTS_SHFT                                              0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_ADDR                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1300u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_OFFS                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1300u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_RMSK                                                              0x3u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_DISABLE_DEBUG_CSR_UPDATE_BMSK                                     0x2u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_DISABLE_DEBUG_CSR_UPDATE_SHFT                                       1u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_FORCE_CLK_EN_BMSK                                                 0x1u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_0_FORCE_CLK_EN_SHFT                                                   0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PARAM_SEQ_CONFIG_ADDR                                               (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1304u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PARAM_SEQ_CONFIG_OFFS                                               (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1304u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PARAM_SEQ_CONFIG_RMSK                                                    0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PARAM_SEQ_CONFIG_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PARAM_SEQ_CONFIG_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PARAM_SEQ_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PARAM_SEQ_CONFIG_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PARAM_SEQ_CONFIG_NUM_SEQ_CMD_WORDS_BMSK                                  0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PARAM_SEQ_CONFIG_NUM_SEQ_CMD_WORDS_SHFT                                      0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BUSY_ADDR                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1308u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BUSY_OFFS                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1308u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BUSY_RMSK                                                                  0x1u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BUSY_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BUSY_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BUSY_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BUSY_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BUSY_BUSY_STAT_BMSK                                                        0x1u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BUSY_BUSY_STAT_SHFT                                                          0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_ADDR                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x130cu)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_OFFS                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x130cu)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_RMSK                                                 0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_BMSK                              0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_SHFT                                  0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STAT_ADDR                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1310u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STAT_OFFS                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1310u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STAT_RMSK                                                              0x1u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STAT_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STAT_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STAT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STAT_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STAT_DBG_STEPPING_STATUS_BMSK                                          0x1u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STAT_DBG_STEPPING_STATUS_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_ADDR                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1314u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_OFFS                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1314u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_RMSK                                                          0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_SEQ_START_ADDR_BMSK                                           0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_START_ADDR_SEQ_START_ADDR_SHFT                                               0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1318u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_OFFS                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1318u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_RMSK                                            0x800003fful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_BMSK                         0x80000000ul
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_SHFT                                 31u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_BMSK                         0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_SHFT                             0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x131cu)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_OFFS                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x131cu)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_RMSK                                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_PWR_CTRL_OVERRIDE_MASK_0_BMSK              0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_PWR_CTRL_OVERRIDE_MASK_0_SHFT                       0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1320u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_OFFS                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1320u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_RMSK                                        0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_PWR_CTRL_OVERRIDE_VAL_0_BMSK                0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_PWR_CTRL_OVERRIDE_VAL_0_SHFT                         0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1324u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_OFFS                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1324u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_RMSK                                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_PWR_CTRL_OVERRIDE_MASK_1_BMSK              0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_PWR_CTRL_OVERRIDE_MASK_1_SHFT                       0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1328u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_OFFS                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1328u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_RMSK                                        0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_PWR_CTRL_OVERRIDE_VAL_1_BMSK                0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_PWR_CTRL_OVERRIDE_VAL_1_SHFT                         0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x132cu)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_OFFS                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x132cu)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_RMSK                                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_BMSK              0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_SHFT                       0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1330u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_OFFS                                        (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1330u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_RMSK                                        0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_BMSK                0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_SHFT                         0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1334u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_OFFS                                         (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1334u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_RMSK                                         0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_BMSK                  0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_SHFT                           0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1338u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_OFFS                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1338u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_RMSK                                          0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_BMSK                    0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_SHFT                             0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(b)                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0X133C + (0x4*(b)))
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_OFFS(b)                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0X133C + (0x4*(b)))
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_RMSK                                                    0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_MAXb                                                       31u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_INI(b)                \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(b), HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_RMSK)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_INMI(b,mask)        \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(b), mask)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_OUTI(b,val)        \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(b),val)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_OUTMI(b,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(b),mask,val,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_INI(b))
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_CFG_BR_ADDR_BMSK                                        0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_BR_ADDR_b_CFG_BR_ADDR_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(v)                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0X1400 + (0x4*(v)))
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_OFFS(v)                                          (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0X1400 + (0x4*(v)))
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_RMSK                                                0xffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_MAXv                                                     15u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_INI(v)                \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(v), HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_RMSK)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_INMI(v,mask)        \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(v), mask)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_OUTI(v,val)        \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(v),val)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_OUTMI(v,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(v),mask,val,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_INI(v))
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_CFG_DELAY_VAL_BMSK                                  0xffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_CFG_DELAY_VAL_SHFT                                        0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1500u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_OFFS                                            (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1500u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_RMSK                                            0x800003fful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_BMSK                       0x80000000ul
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_SHFT                               31u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_BMSK                             0x3ffu
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_SHFT                                 0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_ADDR                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1504u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_OFFS                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1504u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_RMSK                                                          0x10001ul
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_IN)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_SEQ_DBG_STEP_TRIGGER_BMSK                                     0x10000ul
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_SEQ_DBG_STEP_TRIGGER_SHFT                                          16u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_SEQ_DBG_STEP_CONTINUE_BMSK                                        0x1u
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_STEP_SEQ_DBG_STEP_CONTINUE_SHFT                                          0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0_ADDR                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1508u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0_OFFS                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1508u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0_RMSK                                                  0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0_CRASH_WAKEUP_PWR_CONTROL_0_BMSK                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0_CRASH_WAKEUP_PWR_CONTROL_0_SHFT                                0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1_ADDR                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x150cu)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1_OFFS                                                  (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x150cu)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1_RMSK                                                  0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1_CRASH_WAKEUP_PWR_CONTROL_1_BMSK                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1_CRASH_WAKEUP_PWR_CONTROL_1_SHFT                                0u

#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS_ADDR                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1510u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS_OFFS                                                    (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1510u)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS_RMSK                                                    0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS_ADDR)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS_CRASH_WAKEUP_WAIT_EVENTS_BMSK                           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS_CRASH_WAKEUP_WAIT_EVENTS_SHFT                                    0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_ADDR                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1600u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_OFFS                                                       (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1600u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_RMSK                                                       0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_IN)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_WAKE_IRQ_CFG_ENABLE_BMSK                                   0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1_WAKE_IRQ_CFG_ENABLE_SHFT                                            0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1604u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1604u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_RMSK                                                      0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_IN)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_WAKE_IRQ_CFG_NEGEDGE_BMSK                                 0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1_WAKE_IRQ_CFG_NEGEDGE_SHFT                                          0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_ADDR                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1608u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_OFFS                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1608u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_RMSK                                                      0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_IN)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_WAKE_IRQ_CFG_POSEDGE_BMSK                                 0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1_WAKE_IRQ_CFG_POSEDGE_SHFT                                          0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_ADDR                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x160cu)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_OFFS                                                     (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x160cu)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_RMSK                                                     0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_OUT(v)            \
                out_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_ADDR,v)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_ADDR,m,v,HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_IN)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_WAKE_IRQ_CFG_POLARITY_BMSK                               0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1_WAKE_IRQ_CFG_POLARITY_SHFT                                        0u

#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_1_ADDR                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0x1610u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_1_OFFS                                                           (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0x1610u)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_1_RMSK                                                           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_1_IN                    \
                in_dword(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_1_ADDR)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_1_ADDR, m)
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_1_WAKE_IRQ_STATUS_BMSK                                           0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_WAKE_IRQ_STATUS_1_WAKE_IRQ_STATUS_SHFT                                                    0u

#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_ADDR(m)                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0X4000 + (0x4*(m)))
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_OFFS(m)                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0X4000 + (0x4*(m)))
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_RMSK                                                         0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_MAXm                                                                255u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_INI(m)                \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_ADDR(m), HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_RMSK)
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_INMI(m,mask)        \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_ADDR(m), mask)
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_OUTI(m,val)        \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_ADDR(m),val)
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_ADDR(m),mask,val,HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_INI(m))
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_BMSK                                       0xff000000ul
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_SHFT                                               24u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_DELAY_FVAL                                        0x0u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_RETURN_FVAL                                       0x1u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_BRANCH_EQUAL_NO_RETURN_FVAL                       0x2u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_BRANCH_EQUAL_WITH_RETURN_FVAL                     0x3u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_SET_OUTPUT_LEVEL_0_FVAL                           0x4u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_SET_OUTPUT_LEVEL_1_FVAL                           0x5u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_0_FVAL                       0x6u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_1_FVAL                       0x7u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_DATA_FIELD_BMSK                                          0xff0000ul
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_1_DATA_FIELD_SHFT                                                16u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_BMSK                                           0xff00u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_SHFT                                                8u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_DELAY_FVAL                                        0x0u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_RETURN_FVAL                                       0x1u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_BRANCH_EQUAL_NO_RETURN_FVAL                       0x2u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_BRANCH_EQUAL_WITH_RETURN_FVAL                     0x3u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_SET_OUTPUT_LEVEL_0_FVAL                           0x4u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_SET_OUTPUT_LEVEL_1_FVAL                           0x5u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_0_FVAL                       0x6u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_1_FVAL                       0x7u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_DATA_FIELD_BMSK                                              0xffu
#define HWIO_SAILSS_PWR_CTRL_SAILSS_PC_SEQ_MEM_m_CMD_0_DATA_FIELD_SHFT                                                 0u

#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_ADDR(m)                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE      + 0X5000 + (0x4*(m)))
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_OFFS(m)                                                   (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS + 0X5000 + (0x4*(m)))
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_RMSK                                                      0xfffffffful
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_MAXm                                                             255u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_INI(m)                \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_ADDR(m), HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_RMSK)
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_INMI(m,mask)        \
                in_dword_masked(HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_ADDR(m), mask)
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_OUTI(m,val)        \
                out_dword(HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_ADDR(m),val)
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_OUTMI(m,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_ADDR(m),mask,val,HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_INI(m))
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_BMSK                          0xff000000ul
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_SHFT                                  24u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_DELAY_FVAL                           0x0u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_RETURN_FVAL                          0x1u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_BRANCH_EQUAL_NO_RETURN_FVAL          0x2u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_BRANCH_EQUAL_WITH_RETURN_FVAL        0x3u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_SET_OUTPUT_LEVEL_0_FVAL              0x4u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_SET_OUTPUT_LEVEL_1_FVAL              0x5u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_0_FVAL          0x6u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_1_FVAL          0x7u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_DATA_FIELD_BMSK                             0xff0000ul
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_DATA_FIELD_SHFT                                   16u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_BMSK                              0xff00u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_SHFT                                   8u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_DELAY_FVAL                           0x0u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_RETURN_FVAL                          0x1u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_BRANCH_EQUAL_NO_RETURN_FVAL          0x2u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_BRANCH_EQUAL_WITH_RETURN_FVAL        0x3u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_SET_OUTPUT_LEVEL_0_FVAL              0x4u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_SET_OUTPUT_LEVEL_1_FVAL              0x5u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_0_FVAL          0x6u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_1_FVAL          0x7u
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_DATA_FIELD_BMSK                                 0xffu
#define HWIO_SAILSS_PWR_CTRL_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_DATA_FIELD_SHFT                                    0u


#endif /* __G_SAIL_PWR_CTRL_H__ */
