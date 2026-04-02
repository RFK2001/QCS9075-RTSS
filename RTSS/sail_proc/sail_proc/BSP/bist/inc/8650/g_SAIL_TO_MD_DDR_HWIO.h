#ifndef __G_SAIL_TO_MD_DDR_HWIO_H__
#define __G_SAIL_TO_MD_DDR_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_DDR_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_DDR_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/bist/inc/8650/g_SAIL_TO_MD_DDR_HWIO.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE                                                  (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x09080000ul)
#define SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_SIZE                                             0x400u
#define SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_USED                                             0x1f8u
#define SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS                                             0x09080000ul

#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x0u)
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x0u)
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_RMSK                                                          0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MAJOR_BMSK                                                    0xff000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MAJOR_SHFT                                                            24u
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MAJOR1_BMSK                                                     0xff0000ul
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MAJOR1_SHFT                                                           16u
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MINOR_BMSK                                                        0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MINOR_SHFT                                                             8u
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_STEP_BMSK                                                           0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_STEP_SHFT                                                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RMSK                                                              0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_SPARE_REG0_BMSK                                                   0xfffeu
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_SPARE_REG0_SHFT                                                        1u
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RESET_MASK_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RESET_MASK_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RESET_MASK_UNMASK_RESET_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RESET_MASK_MASK_RESET_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR                                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x8u)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_OFFS                                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x8u)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RMSK                                                               0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_SPARE_REG1_BMSK                                                    0xfffeu
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_SPARE_REG1_SHFT                                                         1u
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RESET_N_BMSK                                                          0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RESET_N_SHFT                                                            0u
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RESET_N_RESET_ENABLED_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RESET_N_RESET_DISABLED_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR                                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xcu)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_OFFS                                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xcu)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_RMSK                                                            0x1ff33fful
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_DDRSS_DEBUG_BUS_SEL_BMSK                                        0x1f80000ul
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_DDRSS_DEBUG_BUS_SEL_SHFT                                               19u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_DDRSS_BIST_CH_SEL_BMSK                                            0x60000ul
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_DDRSS_BIST_CH_SEL_SHFT                                                 17u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_RSV_SEL_BMSK                                                      0x10000ul
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_RSV_SEL_SHFT                                                           16u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_DEBUG_BUS_SEL_BMSK                                             0x3000u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_DEBUG_BUS_SEL_SHFT                                                 12u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH45_SEL_BMSK                                            0x300u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH45_SEL_SHFT                                                8u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH23_SEL_BMSK                                             0xc0u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH23_SEL_SHFT                                                6u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH01_SEL_BMSK                                             0x30u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH01_SEL_SHFT                                                4u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_BIST_SEL_BMSK                                                     0xfu
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_BIST_SEL_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x10u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x10u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_RMSK                                                      0xc001003ful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_OR_RDATA_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_OR_RDATA_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_AND_RDATA_BMSK                                       0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_AND_RDATA_SHFT                                               30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_TCM_CONFIG_BMSK                                         0x10000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_TCM_CONFIG_SHFT                                              16u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_BROADCAST_EN_BMSK                                          0x3fu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_BROADCAST_EN_SHFT                                             0u

#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR                                                        (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x14u)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_OFFS                                                        (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x14u)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_RMSK                                                        0xc000003ful
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_OR_RDATA_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_OR_RDATA_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_AND_RDATA_BMSK                                           0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_AND_RDATA_SHFT                                                   30u
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_BROADCAST_EN_BMSK                                              0x3fu
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_BROADCAST_EN_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x18u)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x18u)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_RMSK                                                      0xc000003ful
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_OR_RDATA_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_OR_RDATA_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_AND_RDATA_BMSK                                       0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_AND_RDATA_SHFT                                               30u
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_BROADCAST_EN_BMSK                                          0x3fu
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_BROADCAST_EN_SHFT                                             0u

#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1cu)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_OFFS                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_RMSK                                                   0x4000003ful
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_AHB2PHY_AND_RDATA_BMSK                                 0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_AHB2PHY_AND_RDATA_SHFT                                         30u
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_AHB2PHY_BROADCAST_EN_BMSK                                    0x3fu
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_AHB2PHY_BROADCAST_EN_SHFT                                       0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x20u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x20u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_APPS_INTERRUPT0_MASK_0_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_APPS_INTERRUPT0_MASK_0_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x24u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x24u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_APPS_INTERRUPT0_STATUS_0_BMSK                   0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_APPS_INTERRUPT0_STATUS_0_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x28u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x28u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_APPS_INTERRUPT1_MASK_0_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_APPS_INTERRUPT1_MASK_0_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x2cu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x2cu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_APPS_INTERRUPT1_STATUS_0_BMSK                   0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_APPS_INTERRUPT1_STATUS_0_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x30u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x30u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_APPS_INTERRUPT2_MASK_0_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_APPS_INTERRUPT2_MASK_0_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x34u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x34u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_APPS_INTERRUPT2_STATUS_0_BMSK                   0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_APPS_INTERRUPT2_STATUS_0_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x38u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x38u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_APPS_INTERRUPT3_MASK_0_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_APPS_INTERRUPT3_MASK_0_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x3cu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x3cu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_APPS_INTERRUPT3_STATUS_0_BMSK                   0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_APPS_INTERRUPT3_STATUS_0_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x40u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x40u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_APPS_INTERRUPT4_MASK_0_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_APPS_INTERRUPT4_MASK_0_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x44u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x44u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_APPS_INTERRUPT4_STATUS_0_BMSK                   0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_APPS_INTERRUPT4_STATUS_0_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x48u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x48u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_APPS_INTERRUPT5_MASK_0_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_APPS_INTERRUPT5_MASK_0_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x4cu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x4cu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_APPS_INTERRUPT5_STATUS_0_BMSK                   0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_APPS_INTERRUPT5_STATUS_0_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x50u)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_OFFS                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x50u)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_AOP_INTERRUPT_MASK_0_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_AOP_INTERRUPT_MASK_0_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x54u)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x54u)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_AOP_INTERRUPT_STATUS_0_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_AOP_INTERRUPT_STATUS_0_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR                                               (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x58u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_OFFS                                               (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x58u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_SHRM_INTERRUPT_MASK_0_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_SHRM_INTERRUPT_MASK_0_SHFT                                  0u

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_ADDR                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x5cu)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_OFFS                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x5cu)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_RMSK                                             0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_SHRM_INTERRUPT_STATUS_0_BMSK                     0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_SHRM_INTERRUPT_STATUS_0_SHFT                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR                                                 (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x60u)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_OFFS                                                 (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x60u)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_RMSK                                                     0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_PERIOD_EN_CTRL_BMSK                                      0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_PERIOD_EN_CTRL_SHFT                                           0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x64u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x64u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_RMSK                                                         0xf73u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_ACK_BCAST_BMSK                                        0xf00u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_ACK_BCAST_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_PRIORITY_BMSK                                          0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_PRIORITY_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_URGENCY_DISABLE_SHFT                                      1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_DISABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_DISABLE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x68u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x68u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_RMSK                                                         0xf73u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_ACK_BCAST_BMSK                                        0xf00u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_ACK_BCAST_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_PRIORITY_BMSK                                          0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_PRIORITY_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_URGENCY_DISABLE_SHFT                                      1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_DISABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_DISABLE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x6cu)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x6cu)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_RMSK                                                         0xf73u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_ACK_BCAST_BMSK                                        0xf00u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_ACK_BCAST_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_PRIORITY_BMSK                                          0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_PRIORITY_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_URGENCY_DISABLE_SHFT                                      1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_DISABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_DISABLE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x70u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x70u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_RMSK                                                         0xf73u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_ACK_BCAST_BMSK                                        0xf00u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_ACK_BCAST_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_PRIORITY_BMSK                                          0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_PRIORITY_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_URGENCY_DISABLE_SHFT                                      1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_DISABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_DISABLE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x74u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x74u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_RMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_CLK_EN_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_CLK_EN_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x78u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x78u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_RMSK                                                            0xf1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_DEBUG_SPARE_BMSK                                                0xf0u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_DEBUG_SPARE_SHFT                                                   4u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_DEBUG_MODE_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_DEBUG_MODE_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x7cu)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x7cu)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_RMSK                                                             0x3u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_ABORT_BMSK                                                       0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_ABORT_SHFT                                                         1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_SINGLE_STEP_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_SINGLE_STEP_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x80u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x80u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_RMSK                                                     0xffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DOWNTIME_URGENCY_IN_BMSK                                 0xffff000ul
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DOWNTIME_URGENCY_IN_SHFT                                        12u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_REQ_OUT_BMSK                                            0x800u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_REQ_OUT_SHFT                                               11u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_URGENCY_OUT_BMSK                                        0x700u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_URGENCY_OUT_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_ACK_IN_BMSK                                              0x80u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_ACK_IN_SHFT                                                 7u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_STATE_MC_INPUTS_BMSK                                          0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_STATE_MC_INPUTS_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_PRESENT_STATE_BMSK                                             0xfu
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_PRESENT_STATE_SHFT                                               0u

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR                                         (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x84u)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_OFFS                                         (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x84u)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_RMSK                                                0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_STOP_ENA_BMSK                                       0x4u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_STOP_ENA_SHFT                                         2u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_SET_ENA_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_SET_ENA_SHFT                                          1u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_FREEZE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_FREEZE_SHFT                                           0u

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR                                     (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x88u)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_OFFS                                     (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x88u)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_SET_VAL_BMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_SET_VAL_SHFT                                      0u

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x8cu)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_OFFS                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x8cu)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_RMSK                                    0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_STOP_VAL_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_STOP_VAL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x90u)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x90u)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_COUNTER_VAL_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_COUNTER_VAL_SHFT                                         0u

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR                                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x94u)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_OFFS                                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x94u)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_RMSK                                                              0x3u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_GPU1_CTG_SEL_BMSK                                                 0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_GPU1_CTG_SEL_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_GPU0_CTG_SEL_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_GPU0_CTG_SEL_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x9cu)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_OFFS                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x9cu)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_RMSK                                                  0x3ffu
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT7_AGG_OPT_BMSK                                0x200u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT7_AGG_OPT_SHFT                                    9u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT6_AGG_OPT_BMSK                                0x100u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT6_AGG_OPT_SHFT                                    8u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_SHRM_INT_AGG_OPT_BMSK                                  0x80u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_SHRM_INT_AGG_OPT_SHFT                                     7u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_AOP_INT_AGG_OPT_BMSK                                   0x40u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_AOP_INT_AGG_OPT_SHFT                                      6u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT5_AGG_OPT_BMSK                                 0x20u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT5_AGG_OPT_SHFT                                    5u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT4_AGG_OPT_BMSK                                 0x10u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT4_AGG_OPT_SHFT                                    4u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT3_AGG_OPT_BMSK                                  0x8u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT3_AGG_OPT_SHFT                                    3u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT2_AGG_OPT_BMSK                                  0x4u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT2_AGG_OPT_SHFT                                    2u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT1_AGG_OPT_BMSK                                  0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT1_AGG_OPT_SHFT                                    1u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT0_AGG_OPT_BMSK                                  0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT0_AGG_OPT_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xa0u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xa0u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_RMSK                                                             0x3ff01ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_EN_TWO_CH_MODE_BMSK                                              0x20000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_EN_TWO_CH_MODE_SHFT                                                   17u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_EN_FOUR_CH_MODE_BMSK                                             0x10000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_EN_FOUR_CH_MODE_SHFT                                                  16u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_LLC_NUM_CTRLRS_BMSK                                               0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_LLC_NUM_CTRLRS_SHFT                                                    8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_LLC_PRESENT_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_LLC_PRESENT_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xa4u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xa4u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_RMSK                                                            0xfff1fful
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_NUM_WAYS_BMSK                                               0xff0000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_NUM_WAYS_SHFT                                                     16u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_NUM_GRANULES_PER_CL_BMSK                                      0xf000u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_NUM_GRANULES_PER_CL_SHFT                                          12u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_GRANULE_SUPPORT_BMSK                                           0x100u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_GRANULE_SUPPORT_SHFT                                               8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_CL_SIZE_BMSK                                                    0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_CL_SIZE_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xa8u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xa8u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_RMSK                                                              0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_LLC_CACHE_SIZE_BMSK                                               0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_LLC_CACHE_SIZE_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xacu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xacu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_RMSK                                                                0x1fu
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_LLC_NUM_PCBS_BMSK                                                   0x1fu
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_LLC_NUM_PCBS_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xb8u)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xb8u)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_RMSK                                                                0x1fu
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_QMIP_POLICY_SEL_BMSK                                                0x1cu
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_QMIP_POLICY_SEL_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_SHRM_POLICY_SEL_BMSK                                                 0x3u
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_SHRM_POLICY_SEL_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xbcu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_OFFS                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xbcu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_RMSK                                          0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_LLCC_POLICY_HYSTERISIS_CTR_LOAD_BMSK          0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_LLCC_POLICY_HYSTERISIS_CTR_LOAD_SHFT                  31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_LLCC_POLICY_HYSTERISIS_CTR_BMSK                   0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_LLCC_POLICY_HYSTERISIS_CTR_SHFT                        0u

#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xc0u)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_OFFS                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xc0u)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_RMSK                                          0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                               0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                       31u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                             0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                  8u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                          0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                             0u

#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xc4u)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_OFFS                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xc4u)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_RMSK                                          0xc0000077ul
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                        31u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                        0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                30u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                    0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                       4u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                 0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_ADDR                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xc8u)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_OFFS                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xc8u)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_RMSK                                          0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                         0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                 31u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                   0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                           30u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                             0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                    24u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                          0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                20u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                          0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                               16u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                           0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                8u
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                        0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                           0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xccu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xccu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_RMSK                                           0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xd0u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xd0u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xd4u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xd4u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_RMSK                                           0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xd8u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xd8u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_RMSK                                           0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xdcu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xdcu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xe0u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xe0u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_RMSK                                           0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xe4u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xe4u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_RMSK                                           0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xe8u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xe8u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xecu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xecu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_RMSK                                           0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xf0u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xf0u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_RMSK                                           0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xf4u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xf4u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xf8u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xf8u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_RMSK                                           0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xfcu)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xfcu)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_RMSK                                            0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                               0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                    8u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                            0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                               0u

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x100u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x100u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_RMSK                                            0xc0000077ul
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                  0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                          31u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                          0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                  30u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                      0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                         4u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                   0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                     0u

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x104u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x104u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_RMSK                                            0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                           0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                   31u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                     0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                             30u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                               0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                            0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                  20u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                            0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                 16u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                             0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                  8u
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                          0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                             0u

#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x108u)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x108u)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_RMSK                                            0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                           0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                   31u
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                     0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                             30u
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                               0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                            0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                  20u
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                            0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                 16u
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                             0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                  8u
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                          0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                             0u

#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x10cu)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_OFFS                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x10cu)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_RMSK                                       0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                            0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                    31u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                          0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                               8u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                       0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                          0u

#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x110u)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_OFFS                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x110u)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_RMSK                                       0xc0000077ul
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                             0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                     31u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                     0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                             30u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                 0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                    4u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                              0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_ADDR                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x114u)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_OFFS                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x114u)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_RMSK                                       0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                      0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                              31u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                        30u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                          0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                 24u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                       0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                             20u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                       0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                            16u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                        0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                             8u
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                     0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                        0u

#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x134u)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_OFFS                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x134u)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_RMSK                                                        0x3ffu
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_SOFTWARE_ARES_BMSK                                   0x200u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_SOFTWARE_ARES_SHFT                                       9u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DDRSS_PHY_CLK_CTRL_BMSK                              0x100u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DDRSS_PHY_CLK_CTRL_SHFT                                  8u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_WR_PATH_MODE_BMSK                                     0x80u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_WR_PATH_MODE_SHFT                                        7u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DATA_IN_BMSK                                          0x40u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DATA_IN_SHFT                                             6u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_EN_BMSK                                               0x20u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_EN_SHFT                                                  5u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_WNDW_EN_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_WNDW_EN_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RO_CNT_RESET_BMSK                                      0x8u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RO_CNT_RESET_SHFT                                        3u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RD_PATH_MODE_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RD_PATH_MODE_SHFT                                        2u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RO_ENABLE_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RO_ENABLE_SHFT                                           1u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DATA_SEL_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DATA_SEL_SHFT                                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x138u)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_OFFS                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x138u)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_RMSK                                                       0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_SB_TST_WNDW_MAX_CNT_BMSK                                   0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_SB_TST_WNDW_MAX_CNT_SHFT                                        0u

#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_ADDR                                                 (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x13cu)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_OFFS                                                 (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x13cu)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_RMSK                                                  0x7fffffful
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_RX_DATA_OUT_BMSK                               0x6000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_RX_DATA_OUT_SHFT                                      25u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_TX_DATA_OUT_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_TX_DATA_OUT_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_EN_CNT_STA_BMSK                                 0xf00000ul
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_EN_CNT_STA_SHFT                                       20u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_REQ_CNT_STA_BMSK                                 0xf0000ul
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_REQ_CNT_STA_SHFT                                      16u
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_RO_CNT_STA_BMSK                                   0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_RO_CNT_STA_SHFT                                        0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x140u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x140u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_APPS_INTERRUPT6_MASK_0_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_APPS_INTERRUPT6_MASK_0_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x144u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x144u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_APPS_INTERRUPT6_STATUS_0_BMSK                   0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_APPS_INTERRUPT6_STATUS_0_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x148u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x148u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_APPS_INTERRUPT7_MASK_0_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_APPS_INTERRUPT7_MASK_0_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x14cu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x14cu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_APPS_INTERRUPT7_STATUS_0_BMSK                   0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_APPS_INTERRUPT7_STATUS_0_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR                                                         (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x150u)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_OFFS                                                         (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x150u)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_RMSK                                                               0x11u
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_DPM_STOP_ACK_BMSK                                                  0x10u
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_DPM_STOP_ACK_SHFT                                                     4u
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_DPM_STOP_BMSK                                                       0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_DPM_STOP_SHFT                                                         0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x160u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x160u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_RMSK                                           0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x164u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x164u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x168u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x168u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_RMSK                                           0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC4_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x16cu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x16cu)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_RMSK                                           0x8000fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x170u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x170u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x174u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x174u)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_RMSK                                           0xc777fffful
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000ul
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8u
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffu
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC5_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x190u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x190u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_RMSK                                                         0xf73u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_DT_REQ_ACK_BCAST_BMSK                                        0xf00u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_DT_REQ_ACK_BCAST_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_DT_REQ_PRIORITY_BMSK                                          0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_DT_REQ_PRIORITY_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_DT_REQ_URGENCY_DISABLE_SHFT                                      1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_DT_REQ_DISABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_4_DT_REQ_DISABLE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x194u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x194u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_RMSK                                                         0xf73u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_DT_REQ_ACK_BCAST_BMSK                                        0xf00u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_DT_REQ_ACK_BCAST_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_DT_REQ_PRIORITY_BMSK                                          0x70u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_DT_REQ_PRIORITY_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_DT_REQ_URGENCY_DISABLE_SHFT                                      1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_DT_REQ_DISABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_5_DT_REQ_DISABLE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1a0u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1a0u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_RMSK                                                    0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_DOWNTIME_REQ_IN_BMSK                                    0xffff0000ul
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_DOWNTIME_REQ_IN_SHFT                                            16u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_DOWNTIME_ACK_OUT_BMSK                                       0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_DOWNTIME_ACK_OUT_SHFT                                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1a4u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1a4u)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_RMSK                                                    0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_DOWNTIME_REQ_GRANT_BMSK                                 0xffff0000ul
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_DOWNTIME_REQ_GRANT_SHFT                                         16u
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_DOWNTIME_REQ_MAX_PRI_BMSK                                   0xffffu
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_DOWNTIME_REQ_MAX_PRI_SHFT                                        0u

#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1a8u)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_OFFS                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1a8u)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_RMSK                                                  0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_AOP_INTERRUPT_MASK_1_BMSK                             0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_AOP_INTERRUPT_MASK_1_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1acu)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1acu)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_AOP_INTERRUPT_STATUS_1_BMSK                         0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_AOP_INTERRUPT_STATUS_1_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1b0u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1b0u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_APPS_INTERRUPT0_MASK_1_BMSK                         0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_APPS_INTERRUPT0_MASK_1_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1b4u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1b4u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_RMSK                                              0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_APPS_INTERRUPT0_STATUS_1_BMSK                     0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_APPS_INTERRUPT0_STATUS_1_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1b8u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1b8u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_APPS_INTERRUPT1_MASK_1_BMSK                         0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_APPS_INTERRUPT1_MASK_1_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1bcu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1bcu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_RMSK                                              0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_APPS_INTERRUPT1_STATUS_1_BMSK                     0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_APPS_INTERRUPT1_STATUS_1_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1c0u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1c0u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_APPS_INTERRUPT2_MASK_1_BMSK                         0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_APPS_INTERRUPT2_MASK_1_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1c4u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1c4u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_RMSK                                              0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_APPS_INTERRUPT2_STATUS_1_BMSK                     0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_APPS_INTERRUPT2_STATUS_1_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1c8u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1c8u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_APPS_INTERRUPT3_MASK_1_BMSK                         0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_APPS_INTERRUPT3_MASK_1_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1ccu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1ccu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_RMSK                                              0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_APPS_INTERRUPT3_STATUS_1_BMSK                     0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_APPS_INTERRUPT3_STATUS_1_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1d0u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1d0u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_APPS_INTERRUPT4_MASK_1_BMSK                         0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_APPS_INTERRUPT4_MASK_1_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1d4u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1d4u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_RMSK                                              0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_APPS_INTERRUPT4_STATUS_1_BMSK                     0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_APPS_INTERRUPT4_STATUS_1_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1d8u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1d8u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_APPS_INTERRUPT5_MASK_1_BMSK                         0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_APPS_INTERRUPT5_MASK_1_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1dcu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1dcu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_RMSK                                              0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_APPS_INTERRUPT5_STATUS_1_BMSK                     0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_APPS_INTERRUPT5_STATUS_1_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1e0u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1e0u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_APPS_INTERRUPT6_MASK_1_BMSK                         0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_APPS_INTERRUPT6_MASK_1_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1e4u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1e4u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_RMSK                                              0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_APPS_INTERRUPT6_STATUS_1_BMSK                     0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_APPS_INTERRUPT6_STATUS_1_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1e8u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1e8u)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_APPS_INTERRUPT7_MASK_1_BMSK                         0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_APPS_INTERRUPT7_MASK_1_SHFT                                0u

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1ecu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1ecu)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_RMSK                                              0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_APPS_INTERRUPT7_STATUS_1_BMSK                     0xfffffful
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_APPS_INTERRUPT7_STATUS_1_SHFT                            0u

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR                                               (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1f0u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_OFFS                                               (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1f0u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_SHRM_INTERRUPT_MASK_1_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_SHRM_INTERRUPT_MASK_1_SHFT                                  0u

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_ADDR                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1f4u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_OFFS                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1f4u)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_RMSK                                             0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_SHRM_INTERRUPT_STATUS_1_BMSK                     0xfffffffful
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_SHRM_INTERRUPT_STATUS_1_SHFT                              0u

#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_ADDR                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1f8u)
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_OFFS                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1f8u)
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_RMSK                                                    0x1fffu
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_HPCNT_BMSK                                              0x1f80u
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_HPCNT_SHFT                                                   7u
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_VPCNT_BMSK                                                0x7eu
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_VPCNT_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_FLT_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_FLT_SHFT                                                     0u


#endif /* __G_SAIL_TO_MD_DDR_HWIO_H__ */
