#ifndef __G_SAIL_TO_MD_LLC_HWIO_H__
#define __G_SAIL_TO_MD_LLC_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_LLC_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_LLC_BROADCAST_PMGR


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_LLC_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_LLC_BROADCAST_PMGR'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/bist/inc/common_inc/g_SAIL_TO_MD_LLC_HWIO.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_LLC_BROADCAST_PMGR
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE                                                                     (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x09a4c000ul)
#define SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_SIZE                                                                0x4000u
#define SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_USED                                                                0x2004u
#define SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS                                                                0x09a4c000ul

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_IDLE_ADDR                                                          (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x0u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_IDLE_OFFS                                                          (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x0u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_IDLE_RMSK                                                                 0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_IDLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_IDLE_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_IDLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_IDLE_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_IDLE_LLCC_IDLE_BMSK                                                       0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_IDLE_LLCC_IDLE_SHFT                                                         0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_RMSK                                                           0x3u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_DEBUG_SELECT_BMSK                                              0x3u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DEBUG_CTRL_DEBUG_SELECT_SHFT                                                0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_ADDR                                                   (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x10u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_OFFS                                                   (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x10u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_RMSK                                                   0xfffffffful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_TPD4_BMSK                                              0xff000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_TPD4_SHFT                                                      24u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_TPD3_BMSK                                                0xff0000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_TPD3_SHFT                                                      16u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_TPD2_BMSK                                                  0xff00u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_TPD2_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_TPD1_BMSK                                                    0xffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING0_TPD1_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_ADDR                                                   (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x14u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_OFFS                                                   (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x14u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_RMSK                                                    0x1fffffful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_OVERLAP_TH1_TPD4_BMSK                                   0x1000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_OVERLAP_TH1_TPD4_SHFT                                          24u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_TH3_DUMMY_BMSK                                           0xff0000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_TH3_DUMMY_SHFT                                                 16u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_TPD1_PRE_BMSK                                              0xff00u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_TPD1_PRE_SHFT                                                   8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_TH1_BMSK                                                     0xffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING1_TH1_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_ADDR                                                   (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x18u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_OFFS                                                   (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x18u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_RMSK                                                         0xffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_TPD2_NRET_TO_ACTIVE_BMSK                                     0xffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_TIMING2_TPD2_NRET_TO_ACTIVE_SHFT                                        0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_ADDR                                                  (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x1cu)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_OFFS                                                  (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_RMSK                                                       0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_SEL_BMSK                                                   0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL0_SEL_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_ADDR                                                  (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x20u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_OFFS                                                  (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x20u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_RMSK                                                       0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_NRET_SEL_BMSK                                              0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_SEL1_NRET_SEL_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_ADDR                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x24u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_OFFS                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x24u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_RMSK                                                     0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_SEL_BMSK                                                 0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKEUP_SEL_SEL_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_ADDR                                                       (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x28u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_OFFS                                                       (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x28u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_RMSK                                                              0x3u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_WAKEUP_COMMAND_BMSK                                               0x2u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_WAKEUP_COMMAND_SHFT                                                 1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_SLEEP_COMMAND_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_CMD_SLEEP_COMMAND_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x30u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x30u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_15_14_BMSK                                 0xf0000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_15_14_SHFT                                         28u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_13_12_BMSK                                  0xf000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_13_12_SHFT                                         24u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_11_10_BMSK                                   0xf00000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_11_10_SHFT                                         20u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_9_8_BMSK                                      0xf0000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_9_8_SHFT                                           16u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_7_6_BMSK                                       0xf000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_7_6_SHFT                                           12u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_5_4_BMSK                                        0xf00u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_5_4_SHFT                                            8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_3_2_BMSK                                         0xf0u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_3_2_SHFT                                            4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_1_0_BMSK                                          0xfu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS0_TAG_RAM_1_0_SHFT                                            0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x34u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x34u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_RMSK                                                   0xffffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_LCP_SRAM_BMSK                                          0xf000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_LCP_SRAM_SHFT                                              12u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_BERC_LFILL_RAM_BMSK                                     0xf00u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_BERC_LFILL_RAM_SHFT                                         8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_TRP_WRSC_FIFO_RAM_BMSK                                   0xf0u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_TRP_WRSC_FIFO_RAM_SHFT                                      4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_MRU_RAM_BMSK                                              0xfu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_STATUS1_MRU_RAM_SHFT                                                0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_PWR_STATUS_ADDR                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x38u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_PWR_STATUS_OFFS                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x38u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_PWR_STATUS_RMSK                                                  0xfffffful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_PWR_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_PWR_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_PWR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_PWR_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_PWR_STATUS_RAM_PWR_STATUS_BMSK                                   0xfffffful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_PWR_STATUS_RAM_PWR_STATUS_SHFT                                          0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_CMD_STATUS_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x40u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_CMD_STATUS_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x40u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_CMD_STATUS_RMSK                                                 0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_CMD_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_CMD_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_CMD_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_CMD_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_CMD_STATUS_SLEEP_STATUS_BMSK                                    0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_SLP_CMD_STATUS_SLEEP_STATUS_SHFT                                        0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKE_CMD_STATUS_ADDR                                           (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x44u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKE_CMD_STATUS_OFFS                                           (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x44u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKE_CMD_STATUS_RMSK                                                0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKE_CMD_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKE_CMD_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKE_CMD_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKE_CMD_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKE_CMD_STATUS_WAKEUP_STATUS_BMSK                                  0xfffu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RAM_WAKE_CMD_STATUS_WAKEUP_STATUS_SHFT                                      0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_ADDR                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x48u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_OFFS                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x48u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_RMSK                                                   0x1f1fful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_WAKEUP_IN_PROGRESS_BMSK                                0x10000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_WAKEUP_IN_PROGRESS_SHFT                                     16u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_WAKEUP_RAM_INDEX_BMSK                                   0xf000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_WAKEUP_RAM_INDEX_SHFT                                       12u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_SLP_IN_PROGRESS_BMSK                                     0x100u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_SLP_IN_PROGRESS_SHFT                                         8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_SLP_RAM_INDEX_BMSK                                        0xf0u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_SLP_RAM_INDEX_SHFT                                           4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_RAMSLP_FSM_CURR_STATE_BMSK                                 0xfu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SLP_FSM_STATUS_RAMSLP_FSM_CURR_STATE_SHFT                                   0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x50u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x50u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RMSK                                                      0x8fff3333ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_ENABLE_RCG_FSM_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_ENABLE_RCG_FSM_SHFT                                               31u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_DECISION_TIMER_VALUE_BMSK                              0xf000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_DECISION_TIMER_VALUE_SHFT                                     24u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_QACTIVE_HYSTERESIS_BMSK                                 0xff0000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_QACTIVE_HYSTERESIS_SHFT                                       16u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_OVERRIDE_QACTIVE_BMSK                                     0x2000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_OVERRIDE_QACTIVE_SHFT                                         13u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_QACTIVE_VALUE_BMSK                                        0x1000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_QACTIVE_VALUE_SHFT                                            12u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_OVERRIDE_QACCEPT_BMSK                                      0x200u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_OVERRIDE_QACCEPT_SHFT                                          9u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_QACCEPT_N_VALUE_BMSK                                       0x100u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_QACCEPT_N_VALUE_SHFT                                           8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_OVERRIDE_QDENY_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_OVERRIDE_QDENY_SHFT                                            5u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_QDENY_VALUE_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_QDENY_VALUE_SHFT                                               4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_OVERRIDE_FENCE_EN_BMSK                                       0x2u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_OVERRIDE_FENCE_EN_SHFT                                         1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_FENCE_EN_VALUE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_CTRL_RCG_FENCE_EN_VALUE_SHFT                                            0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_ADDR                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x54u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_OFFS                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x54u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_RMSK                                                  0xffff11ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_LLCC_BLOCKS_QACTIVE_BMSK                              0xffff00ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_LLCC_BLOCKS_QACTIVE_SHFT                                     8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_DPC_FSM_QACTIVE_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_DPC_FSM_QACTIVE_SHFT                                         4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_CFG_QACTIVE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_QACTIVE_STATUS_CFG_QACTIVE_SHFT                                             0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x58u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x58u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_RMSK                                                           0x7u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_RCG_FSM_QSTATE_BMSK                                            0x6u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_RCG_FSM_QSTATE_SHFT                                              1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_QREQ_N_SYNC_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_RCG_STATUS_QREQ_N_SYNC_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x60u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x60u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_RMSK                                                           0x7u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_RCG_HYSTERESIS_CLK_EN_BMSK                                     0x4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_RCG_HYSTERESIS_CLK_EN_SHFT                                       2u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_PROF_CLK_EN_BMSK                                               0x2u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_PROF_CLK_EN_SHFT                                                 1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_SLP_CTRL_CLK_EN_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CLOCK_CTRL_SLP_CTRL_CLK_EN_SHFT                                             0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_ADDR                                             (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x64u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_OFFS                                             (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x64u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_RMSK                                                0x1f11ful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_LCP_ROOT_CLK_EN_BMSK                                0x10000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_LCP_ROOT_CLK_EN_SHFT                                     16u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_LCP_INTERNAL_RCG_HYSTERESIS_BMSK                     0xf000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_LCP_INTERNAL_RCG_HYSTERESIS_SHFT                         12u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_CLK_EN_DURING_LF_PEND_BMSK                            0x100u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_CLK_EN_DURING_LF_PEND_SHFT                                8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_ROOT_CLK_EN_BMSK                                       0x10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_ROOT_CLK_EN_SHFT                                          4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_INTERNAL_RCG_HYSTERESIS_BMSK                            0xfu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_INTERNAL_RCG_CTRL_INTERNAL_RCG_HYSTERESIS_SHFT                              0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_ADDR                                          (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x68u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_OFFS                                          (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x68u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_RMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_CORE_CLK_FORCE_OFF_BMSK                              0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_CORE_CLOCK_FORCE_OFF_CORE_CLK_FORCE_OFF_SHFT                                0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_ADDR                                                 (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x70u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_OFFS                                                 (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x70u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_RMSK                                                        0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_DISCARD_PRE_ARES_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CTRL_DISCARD_PRE_ARES_SHFT                                         0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CLEAR_ADDR                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x74u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CLEAR_OFFS                                                (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x74u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CLEAR_RMSK                                                       0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CLEAR_PRE_ARES_CLEAR_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_CLEAR_PRE_ARES_CLEAR_SHFT                                          0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x78u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x78u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_RMSK                                                      0x3u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_PRE_ARES_SEEN_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_PRE_ARES_SEEN_SHFT                                          1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_PRE_ARES_DONE_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PRE_ARES_STATUS_PRE_ARES_DONE_SHFT                                          0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_ADDR                                                         (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x80u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_OFFS                                                         (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x80u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_RMSK                                                         0xfffffffful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_SPARE_FIELD_BMSK                                             0xfffffffful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_SPARE_SPARE_FIELD_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x100u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x100u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_RMSK                                                      0x80000ff1ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_ENABLE_DPC_FSM_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_ENABLE_DPC_FSM_SHFT                                               31u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_OVERRIDE_PWR_DWN_ACK_BMSK                                      0x800u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_OVERRIDE_PWR_DWN_ACK_SHFT                                         11u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_PWR_DWN_ACK_VALUE_BMSK                                         0x400u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_PWR_DWN_ACK_VALUE_SHFT                                            10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_OVERRIDE_QACTIVE_BMSK                                      0x200u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_OVERRIDE_QACTIVE_SHFT                                          9u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_QACTIVE_VALUE_BMSK                                         0x100u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_QACTIVE_VALUE_SHFT                                             8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_OVERRIDE_QACCEPT_BMSK                                       0x80u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_OVERRIDE_QACCEPT_SHFT                                          7u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_QACCEPT_N_VALUE_BMSK                                        0x40u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_QACCEPT_N_VALUE_SHFT                                           6u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_OVERRIDE_QDENY_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_OVERRIDE_QDENY_SHFT                                            5u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_QDENY_VALUE_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DPC_QDENY_VALUE_SHFT                                               4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DUAL_SLP_CNTLR_LAUNCH_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_CTRL_DUAL_SLP_CNTLR_LAUNCH_SHFT                                         0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x104u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x104u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_RMSK                                                   0x1333u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_MICRO_SLEEP_MODE_EN_BMSK                               0x1000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_MICRO_SLEEP_MODE_EN_SHFT                                   12u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_CLAMP_MEM_WAKEUP_EN_BMSK                                0x200u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_CLAMP_MEM_WAKEUP_EN_SHFT                                    9u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_CLAMP_MEM_SLEEP_EN_BMSK                                 0x100u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_CLAMP_MEM_SLEEP_EN_SHFT                                     8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_MICRO_WAKEUP_BATCH_BMSK                                  0x30u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_MICRO_WAKEUP_BATCH_SHFT                                     4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_MICRO_SLEEP_BATCH_BMSK                                    0x3u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_RAMSLP_MODE_MICRO_SLEEP_BATCH_SHFT                                      0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x108u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x108u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_RMSK                                                        0x7317u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_QREQ_N_SYNC_BMSK                                        0x4000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_QREQ_N_SYNC_SHFT                                            14u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_QACCEPT_N_BMSK                                          0x2000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_QACCEPT_N_SHFT                                              13u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_QDENY_BMSK                                              0x1000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_QDENY_SHFT                                                  12u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_PWR_DWN_REQ_SYNC_BMSK                                        0x200u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_PWR_DWN_REQ_SYNC_SHFT                                            9u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_PWR_DWN_ACK_BMSK                                             0x100u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_PWR_DWN_ACK_SHFT                                                 8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_QACTIVE_BMSK                                              0x10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_QACTIVE_SHFT                                                 4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_FSM_QSTATE_BMSK                                            0x7u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_DPC_STATUS_DPC_FSM_QSTATE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_ADDR                                                 (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x10cu)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_OFFS                                                 (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x10cu)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_RMSK                                                     0x3f11u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_MC_FENCE_HYSTERESIS_BMSK                                 0x3f00u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_MC_FENCE_HYSTERESIS_SHFT                                      8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_MC_FENCE_OVERRIDE_VALUE_BMSK                               0x10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_MC_FENCE_OVERRIDE_VALUE_SHFT                                  4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_MC_FENCE_OVERRIDE_EN_BMSK                                   0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_CTRL_MC_FENCE_OVERRIDE_EN_SHFT                                     0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_ADDR(n)                                          (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0X110 + (0x4*(n)))
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_OFFS(n)                                          (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0X110 + (0x4*(n)))
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_RMSK                                                   0x31u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_MAXn                                                      0u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_INI(n)                \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_ADDR(n), HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_RMSK)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_INMI(n,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_ADDR(n), mask)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_MC_FENCE_FSM_STATE_BMSK                                0x30u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_MC_FENCE_FSM_STATE_SHFT                                   4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_MC_FENCE_REQ_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_MC_FENCE_n_STATUS_MC_FENCE_REQ_SHFT                                         0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_ADDR(n)                                           (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0X1000 + (0x4*(n)))
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_OFFS(n)                                           (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0X1000 + (0x4*(n)))
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_RMSK                                                    0x1fu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_MAXn                                                      15u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_INI(n)                \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_ADDR(n), HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_RMSK)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_INMI(n,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_ADDR(n), mask)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_OUTI(n,val)        \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_ADDR(n),val)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_ADDR(n),mask,val,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_INI(n))
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_EVENT_SEL_BMSK                                          0x1fu
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PROF_EVENT_n_CFG_EVENT_SEL_SHFT                                             0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_ADDR                                       (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x2000u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_OFFS                                       (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x2000u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT31_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT31_SHFT                                         31u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT30_BMSK                                 0x40000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT30_SHFT                                         30u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT29_BMSK                                 0x20000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT29_SHFT                                         29u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT28_BMSK                                 0x10000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT28_SHFT                                         28u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT27_BMSK                                  0x8000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT27_SHFT                                         27u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT26_BMSK                                  0x4000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT26_SHFT                                         26u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT25_BMSK                                  0x2000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT25_SHFT                                         25u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT24_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT24_SHFT                                         24u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT23_BMSK                                   0x800000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT23_SHFT                                         23u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT22_BMSK                                   0x400000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT22_SHFT                                         22u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT21_BMSK                                   0x200000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT21_SHFT                                         21u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT20_BMSK                                   0x100000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT20_SHFT                                         20u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT19_BMSK                                    0x80000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT19_SHFT                                         19u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT18_BMSK                                    0x40000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT18_SHFT                                         18u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT17_BMSK                                    0x20000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT17_SHFT                                         17u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT16_BMSK                                    0x10000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT16_SHFT                                         16u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT15_BMSK                                     0x8000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT15_SHFT                                         15u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT14_BMSK                                     0x4000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT14_SHFT                                         14u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT13_BMSK                                     0x2000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT13_SHFT                                         13u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT12_BMSK                                     0x1000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT12_SHFT                                         12u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT11_BMSK                                      0x800u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT11_SHFT                                         11u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT10_BMSK                                      0x400u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT10_SHFT                                         10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT9_BMSK                                       0x200u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT9_SHFT                                           9u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT8_BMSK                                       0x100u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT8_SHFT                                           8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT7_BMSK                                        0x80u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT7_SHFT                                           7u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT6_BMSK                                        0x40u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT6_SHFT                                           6u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT5_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT5_SHFT                                           5u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT4_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT4_SHFT                                           4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT3_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT3_SHFT                                           3u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT2_BMSK                                         0x4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT2_SHFT                                           2u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT1_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT1_SHFT                                           1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT0_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_VER_STATUS_BIT0_SHFT                                           0u

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_ADDR                                      (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE      + 0x2004u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_OFFS                                      (SAIL_TO_MD_LLC_BROADCAST_PMGR_REG_BASE_OFFS + 0x2004u)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_15_CFG_BMSK          0x80000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_15_CFG_SHFT                  31u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_14_CFG_BMSK          0x40000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_14_CFG_SHFT                  30u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_13_CFG_BMSK          0x20000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_13_CFG_SHFT                  29u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_12_CFG_BMSK          0x10000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_12_CFG_SHFT                  28u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_11_CFG_BMSK           0x8000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_11_CFG_SHFT                  27u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_10_CFG_BMSK           0x4000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_10_CFG_SHFT                  26u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_9_CFG_BMSK            0x2000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_9_CFG_SHFT                   25u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_8_CFG_BMSK            0x1000000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_8_CFG_SHFT                   24u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_7_CFG_BMSK             0x800000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_7_CFG_SHFT                   23u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_6_CFG_BMSK             0x400000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_6_CFG_SHFT                   22u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_5_CFG_BMSK             0x200000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_5_CFG_SHFT                   21u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_4_CFG_BMSK             0x100000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_4_CFG_SHFT                   20u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_3_CFG_BMSK              0x80000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_3_CFG_SHFT                   19u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_2_CFG_BMSK              0x40000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_2_CFG_SHFT                   18u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_1_CFG_BMSK              0x20000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_1_CFG_SHFT                   17u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_0_CFG_BMSK              0x10000ul
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PROF_EVENT_0_CFG_SHFT                   16u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_MC_FENCE_CTRL_BMSK                  0x8000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_MC_FENCE_CTRL_SHFT                      15u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_DPC_RAMSLP_MODE_BMSK                0x4000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_DPC_RAMSLP_MODE_SHFT                    14u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_DPC_CTRL_BMSK                       0x2000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_DPC_CTRL_SHFT                           13u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_SPARE_BMSK                          0x1000u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_SPARE_SHFT                              12u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PRE_ARES_CTRL_BMSK                   0x800u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_PRE_ARES_CTRL_SHFT                      11u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_INTERNAL_RCG_CTRL_BMSK               0x400u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_INTERNAL_RCG_CTRL_SHFT                  10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_CLOCK_CTRL_BMSK                      0x200u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_CLOCK_CTRL_SHFT                          9u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RCG_CTRL_BMSK                        0x100u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RCG_CTRL_SHFT                            8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_CMD_BMSK                          0x80u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_CMD_SHFT                             7u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_WAKEUP_SEL_BMSK                   0x40u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_WAKEUP_SEL_SHFT                      6u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_SLP_SEL1_BMSK                     0x20u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_SLP_SEL1_SHFT                        5u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_SLP_SEL0_BMSK                     0x10u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_SLP_SEL0_SHFT                        4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_TIMING2_BMSK                       0x8u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_TIMING2_SHFT                         3u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_TIMING1_BMSK                       0x4u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_TIMING1_SHFT                         2u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_TIMING0_BMSK                       0x2u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_RAM_TIMING0_SHFT                         1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_DEBUG_CTRL_BMSK                        0x1u
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_PMGR_PARITY_ERROR_HOR0_STATUS_LLCC_PMGR_DEBUG_CTRL_SHFT                          0u


#endif /* __G_SAIL_TO_MD_LLC_HWIO_H__ */
