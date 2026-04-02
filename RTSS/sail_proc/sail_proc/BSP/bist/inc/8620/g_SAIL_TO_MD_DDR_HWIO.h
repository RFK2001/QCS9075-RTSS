#ifndef G_SAIL_TO_MD_DDR_HWIO_H
#define G_SAIL_TO_MD_DDR_HWIO_H
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_DDR_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        MonacoAU [monacoau_v1.0_p3q3r53_MTO_rpm]
 
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

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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
 * MODULE: SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE                                                  (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x09080000UL)
#define SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_SIZE                                             0x400U
#define SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_USED                                             0x1f8U
#define SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS                                             0x09080000UL

#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x0U)
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x0U)
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_RMSK                                                          0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MAJOR_BMSK                                                    0xff000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MAJOR_SHFT                                                            24U
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MAJOR1_BMSK                                                     0xff0000UL
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MAJOR1_SHFT                                                           16U
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MINOR_BMSK                                                        0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_MINOR_SHFT                                                             8U
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_STEP_BMSK                                                           0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_HW_VERSION_STEP_SHFT                                                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x4U)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x4U)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RMSK                                                              0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_SPARE_REG0_BMSK                                                   0xfffeU
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_SPARE_REG0_SHFT                                                        1U
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RESET_MASK_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RESET_MASK_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RESET_MASK_UNMASK_RESET_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CTRL_RESET_MASK_MASK_RESET_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR                                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x8U)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_OFFS                                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x8U)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RMSK                                                               0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_SPARE_REG1_BMSK                                                    0xfffeU
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_SPARE_REG1_SHFT                                                         1U
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RESET_N_BMSK                                                          0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RESET_N_SHFT                                                            0U
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RESET_N_RESET_ENABLED_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_DDR_REG_RESET_CMD_RESET_N_RESET_DISABLED_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR                                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xcU)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_OFFS                                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xcU)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_RMSK                                                            0x1ff30ffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_DDRSS_DEBUG_BUS_SEL_BMSK                                        0x1f80000UL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_DDRSS_DEBUG_BUS_SEL_SHFT                                               19U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_DDRSS_BIST_CH_SEL_BMSK                                            0x60000UL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_DDRSS_BIST_CH_SEL_SHFT                                                 17U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_RSV_SEL_BMSK                                                      0x10000UL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_RSV_SEL_SHFT                                                           16U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_DEBUG_BUS_SEL_BMSK                                             0x3000U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_DEBUG_BUS_SEL_SHFT                                                 12U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH23_SEL_BMSK                                             0xc0U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH23_SEL_SHFT                                                6U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH01_SEL_BMSK                                             0x30U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_TESTSE_CH01_SEL_SHFT                                                4U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_BIST_SEL_BMSK                                                     0xfU
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_SEL_PHY_BIST_SEL_SHFT                                                       0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x10U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x10U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_RMSK                                                      0xc001003fUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_OR_RDATA_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_OR_RDATA_SHFT                                                31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_AND_RDATA_BMSK                                       0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_AND_RDATA_SHFT                                               30U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_TCM_CONFIG_BMSK                                         0x10000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_TCM_CONFIG_SHFT                                              16U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_BROADCAST_EN_BMSK                                          0x3fU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_BROADCAST_LLCC_BROADCAST_EN_SHFT                                             0U

#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR                                                        (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x14U)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_OFFS                                                        (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x14U)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_RMSK                                                        0xc000003fUL
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_OR_RDATA_BMSK                                            0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_OR_RDATA_SHFT                                                    31U
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_AND_RDATA_BMSK                                           0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_AND_RDATA_SHFT                                                   30U
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_BROADCAST_EN_BMSK                                              0x3fU
#define HWIO_SAIL_TO_MD_DDR_REG_MC_BROADCAST_MC_BROADCAST_EN_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x18U)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x18U)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_RMSK                                                      0xc000003fUL
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_OR_RDATA_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_OR_RDATA_SHFT                                                31U
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_AND_RDATA_BMSK                                       0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_AND_RDATA_SHFT                                               30U
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_BROADCAST_EN_BMSK                                          0x3fU
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_BROADCAST_MCCC_BROADCAST_EN_SHFT                                             0U

#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1cU)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_OFFS                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1cU)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_RMSK                                                   0x4000003fUL
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_AHB2PHY_AND_RDATA_BMSK                                 0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_AHB2PHY_AND_RDATA_SHFT                                         30U
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_AHB2PHY_BROADCAST_EN_BMSK                                    0x3fU
#define HWIO_SAIL_TO_MD_DDR_REG_AHB2PHY_BROADCAST_AHB2PHY_BROADCAST_EN_SHFT                                       0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x20U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x20U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_APPS_INTERRUPT0_MASK_0_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_0_APPS_INTERRUPT0_MASK_0_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x24U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x24U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_APPS_INTERRUPT0_STATUS_0_BMSK                   0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_0_APPS_INTERRUPT0_STATUS_0_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x28U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x28U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_APPS_INTERRUPT1_MASK_0_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_0_APPS_INTERRUPT1_MASK_0_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x2cU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x2cU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_APPS_INTERRUPT1_STATUS_0_BMSK                   0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_0_APPS_INTERRUPT1_STATUS_0_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x30U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x30U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_APPS_INTERRUPT2_MASK_0_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_0_APPS_INTERRUPT2_MASK_0_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x34U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x34U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_APPS_INTERRUPT2_STATUS_0_BMSK                   0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_0_APPS_INTERRUPT2_STATUS_0_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x38U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x38U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_APPS_INTERRUPT3_MASK_0_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_0_APPS_INTERRUPT3_MASK_0_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x3cU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_APPS_INTERRUPT3_STATUS_0_BMSK                   0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_0_APPS_INTERRUPT3_STATUS_0_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x40U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x40U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_APPS_INTERRUPT4_MASK_0_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_0_APPS_INTERRUPT4_MASK_0_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x44U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x44U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_APPS_INTERRUPT4_STATUS_0_BMSK                   0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_0_APPS_INTERRUPT4_STATUS_0_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x48U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x48U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_APPS_INTERRUPT5_MASK_0_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_0_APPS_INTERRUPT5_MASK_0_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x4cU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_APPS_INTERRUPT5_STATUS_0_BMSK                   0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_0_APPS_INTERRUPT5_STATUS_0_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x50U)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_OFFS                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x50U)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_RMSK                                                0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_AOP_INTERRUPT_MASK_0_BMSK                           0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_0_AOP_INTERRUPT_MASK_0_SHFT                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x54U)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x54U)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_AOP_INTERRUPT_STATUS_0_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_0_AOP_INTERRUPT_STATUS_0_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR                                               (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x58U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_OFFS                                               (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x58U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_RMSK                                               0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_SHRM_INTERRUPT_MASK_0_BMSK                         0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_0_SHRM_INTERRUPT_MASK_0_SHFT                                  0U

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_ADDR                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x5cU)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_OFFS                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x5cU)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_RMSK                                             0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_SHRM_INTERRUPT_STATUS_0_BMSK                     0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_0_SHRM_INTERRUPT_STATUS_0_SHFT                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR                                                 (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x60U)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_OFFS                                                 (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x60U)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_RMSK                                                     0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_PERIOD_EN_CTRL_BMSK                                      0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_RSI_PERIOD_BUS_CTRL_PERIOD_EN_CTRL_SHFT                                           0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x64U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x64U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_RMSK                                                         0xf73U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_ACK_BCAST_BMSK                                        0xf00U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_ACK_BCAST_SHFT                                            8U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_PRIORITY_BMSK                                          0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_PRIORITY_SHFT                                             4U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_URGENCY_DISABLE_SHFT                                      1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_DISABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_0_DT_REQ_DISABLE_SHFT                                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x68U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x68U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_RMSK                                                         0xf73U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_ACK_BCAST_BMSK                                        0xf00U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_ACK_BCAST_SHFT                                            8U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_PRIORITY_BMSK                                          0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_PRIORITY_SHFT                                             4U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_URGENCY_DISABLE_SHFT                                      1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_DISABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_1_DT_REQ_DISABLE_SHFT                                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x6cU)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x6cU)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_RMSK                                                         0xf73U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_ACK_BCAST_BMSK                                        0xf00U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_ACK_BCAST_SHFT                                            8U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_PRIORITY_BMSK                                          0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_PRIORITY_SHFT                                             4U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_URGENCY_DISABLE_SHFT                                      1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_DISABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_2_DT_REQ_DISABLE_SHFT                                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x70U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x70U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_RMSK                                                         0xf73U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_ACK_BCAST_BMSK                                        0xf00U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_ACK_BCAST_SHFT                                            8U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_PRIORITY_BMSK                                          0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_PRIORITY_SHFT                                             4U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_URGENCY_DISABLE_BMSK                                    0x2U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_URGENCY_DISABLE_SHFT                                      1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_DISABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_REQ_CFG_3_DT_REQ_DISABLE_SHFT                                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x74U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x74U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_RMSK                                                             0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_CLK_EN_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_CGC_CFG_CLK_EN_SHFT                                                        0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x78U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x78U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_RMSK                                                            0xf1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_DEBUG_SPARE_BMSK                                                0xf0U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_DEBUG_SPARE_SHFT                                                   4U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_DEBUG_MODE_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CFG_DEBUG_MODE_SHFT                                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_ADDR                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x7cU)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_OFFS                                                      (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x7cU)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_RMSK                                                             0x3U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_ABORT_BMSK                                                       0x2U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_ABORT_SHFT                                                         1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_SINGLE_STEP_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_CTL_SINGLE_STEP_SHFT                                                   0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x80U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x80U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_RMSK                                                     0xfffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DOWNTIME_URGENCY_IN_BMSK                                 0xffff000UL
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DOWNTIME_URGENCY_IN_SHFT                                        12U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_REQ_OUT_BMSK                                            0x800U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_REQ_OUT_SHFT                                               11U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_URGENCY_OUT_BMSK                                        0x700U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_URGENCY_OUT_SHFT                                            8U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_ACK_IN_BMSK                                              0x80U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_DSAT_ACK_IN_SHFT                                                 7U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_STATE_MC_INPUTS_BMSK                                          0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_STATE_MC_INPUTS_SHFT                                             4U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_PRESENT_STATE_BMSK                                             0xfU
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO0_PRESENT_STATE_SHFT                                               0U

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR                                         (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x84U)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_OFFS                                         (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x84U)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_RMSK                                                0x7U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_STOP_ENA_BMSK                                       0x4U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_STOP_ENA_SHFT                                         2U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_SET_ENA_BMSK                                        0x2U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_SET_ENA_SHFT                                          1U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_FREEZE_BMSK                                         0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_CTRL_FREEZE_SHFT                                           0U

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR                                     (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x88U)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_OFFS                                     (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x88U)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_RMSK                                     0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_SET_VAL_BMSK                             0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_SET_CTRL_SET_VAL_SHFT                                      0U

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x8cU)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_OFFS                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x8cU)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_RMSK                                    0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_STOP_VAL_BMSK                           0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_SYNCH_STOP_CTRL_STOP_VAL_SHFT                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x90U)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x90U)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_COUNTER_VAL_BMSK                                0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_GLOBALCNTR_CURRENT_COUNTER_VAL_SHFT                                         0U

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR                                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x94U)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_OFFS                                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x94U)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_RMSK                                                              0x3U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_GPU1_CTG_SEL_BMSK                                                 0x2U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_GPU1_CTG_SEL_SHFT                                                   1U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_GPU0_CTG_SEL_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_CTG_SEL_GPU0_CTG_SEL_SHFT                                                   0U

#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x9cU)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_OFFS                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x9cU)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_RMSK                                                  0x3ffU
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT7_AGG_OPT_BMSK                                0x200U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT7_AGG_OPT_SHFT                                    9U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT6_AGG_OPT_BMSK                                0x100U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT6_AGG_OPT_SHFT                                    8U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_SHRM_INT_AGG_OPT_BMSK                                  0x80U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_SHRM_INT_AGG_OPT_SHFT                                     7U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_AOP_INT_AGG_OPT_BMSK                                   0x40U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_AOP_INT_AGG_OPT_SHFT                                      6U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT5_AGG_OPT_BMSK                                 0x20U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT5_AGG_OPT_SHFT                                    5U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT4_AGG_OPT_BMSK                                 0x10U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT4_AGG_OPT_SHFT                                    4U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT3_AGG_OPT_BMSK                                  0x8U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT3_AGG_OPT_SHFT                                    3U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT2_AGG_OPT_BMSK                                  0x4U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT2_AGG_OPT_SHFT                                    2U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT1_AGG_OPT_BMSK                                  0x2U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT1_AGG_OPT_SHFT                                    1U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT0_AGG_OPT_BMSK                                  0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DDRSS_INTERRUPT_AGG_OPT_APPS_INT0_AGG_OPT_SHFT                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xa0U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xa0U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_RMSK                                                             0x3ff01UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_EN_TWO_CH_MODE_BMSK                                              0x20000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_EN_TWO_CH_MODE_SHFT                                                   17U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_EN_FOUR_CH_MODE_BMSK                                             0x10000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_EN_FOUR_CH_MODE_SHFT                                                  16U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_LLC_NUM_CTRLRS_BMSK                                               0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_LLC_NUM_CTRLRS_SHFT                                                    8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_LLC_PRESENT_BMSK                                                     0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_0_LLC_PRESENT_SHFT                                                       0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xa4U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xa4U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_RMSK                                                            0xfff1ffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_NUM_WAYS_BMSK                                               0xff0000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_NUM_WAYS_SHFT                                                     16U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_NUM_GRANULES_PER_CL_BMSK                                      0xf000U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_NUM_GRANULES_PER_CL_SHFT                                          12U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_GRANULE_SUPPORT_BMSK                                           0x100U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_GRANULE_SUPPORT_SHFT                                               8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_CL_SIZE_BMSK                                                    0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_1_LLC_CL_SIZE_SHFT                                                       0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xa8U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xa8U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_RMSK                                                              0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_LLC_CACHE_SIZE_BMSK                                               0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_2_LLC_CACHE_SIZE_SHFT                                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xacU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xacU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_RMSK                                                                0x1fU
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_LLC_NUM_PCBS_BMSK                                                   0x1fU
#define HWIO_SAIL_TO_MD_DDR_REG_LLC_INFO_3_LLC_NUM_PCBS_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xb8U)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_OFFS                                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xb8U)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_RMSK                                                                0x1fU
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_QMIP_POLICY_SEL_BMSK                                                0x1cU
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_QMIP_POLICY_SEL_SHFT                                                   2U
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_SHRM_POLICY_SEL_BMSK                                                 0x3U
#define HWIO_SAIL_TO_MD_DDR_REG_POLICY_SEL_SHRM_POLICY_SEL_SHFT                                                   0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xbcU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_OFFS                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xbcU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_RMSK                                          0x8000ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_LLCC_POLICY_HYSTERISIS_CTR_LOAD_BMSK          0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_LLCC_POLICY_HYSTERISIS_CTR_LOAD_SHFT                  31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_LLCC_POLICY_HYSTERISIS_CTR_BMSK                   0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC_POLICY_HYSTERISIS_CTR_LLCC_POLICY_HYSTERISIS_CTR_SHFT                        0U

#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xc0U)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_OFFS                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xc0U)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_RMSK                                          0x8000ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                               0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                       31U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                             0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                  8U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                          0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                             0U

#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xc4U)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_OFFS                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xc4U)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_RMSK                                          0xc0000077UL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                        31U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                        0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                30U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                    0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                       4U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                 0x7U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                   0U

#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_ADDR                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xc8U)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_OFFS                                          (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xc8U)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_RMSK                                          0xc777ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                         0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                 31U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                   0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                           30U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                             0x7000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                    24U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                          0x700000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                20U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                          0x70000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                               16U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                           0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                8U
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                        0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_GEMNOC_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                           0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xccU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xccU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_RMSK                                           0x8000ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xd0U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xd0U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xd4U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xd4U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_RMSK                                           0xc777ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC0_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xd8U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xd8U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_RMSK                                           0x8000ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xdcU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xdcU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xe0U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xe0U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_RMSK                                           0xc777ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC1_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xe4U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xe4U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_RMSK                                           0x8000ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xe8U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xe8U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xecU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xecU)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_RMSK                                           0xc777ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC2_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xf0U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xf0U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_RMSK                                           0x8000ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                        31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                              0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                   8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                           0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xf4U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xf4U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_RMSK                                           0xc0000077UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                 0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                         31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                         0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                 30U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                     0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                        4U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                  0x7U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_ADDR                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xf8U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_OFFS                                           (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xf8U)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_RMSK                                           0xc777ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                          0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                  31U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                    0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                            30U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                              0x7000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                     24U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                           0x700000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                 20U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                           0x70000UL
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                16U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                            0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                 8U
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                         0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_LLCC3_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0xfcU)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0xfcU)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_RMSK                                            0x8000ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                                 0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                         31U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                               0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                                    8U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                            0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                               0U

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x100U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x100U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_RMSK                                            0xc0000077UL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                                  0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                          31U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                          0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                                  30U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                      0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                         4U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                                   0x7U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                     0U

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x104U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x104U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_RMSK                                            0xc777ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                           0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                   31U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                     0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                             30U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                               0x7000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                      24U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                            0x700000UL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                  20U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                            0x70000UL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                 16U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                             0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                  8U
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                          0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                             0U

#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x108U)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x108U)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_RMSK                                            0xc777ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                           0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                                   31U
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                     0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                             30U
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                               0x7000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                      24U
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                            0x700000UL
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                                  20U
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                            0x70000UL
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                                 16U
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                             0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                                  8U
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                          0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_MCCC_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                             0U

#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x10cU)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_OFFS                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x10cU)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_RMSK                                       0x8000ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_UPDATE_VAL_BMSK                            0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_UPDATE_VAL_SHFT                                    31U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_BMSK                          0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_SHUB_TRAIL_COUNT_SHFT                               8U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_BMSK                       0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_0_SHUB_HYSTERISIS_COUNT_SHFT                          0U

#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x110U)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_OFFS                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x110U)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_RMSK                                       0xc0000077UL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_HW_RCG_EN_BMSK                             0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_HW_RCG_EN_SHFT                                     31U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_BMSK                     0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_CHILD_COPY_PARENT_SHFT                             30U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_SW_QCHANNEL_BMSK                                 0x70U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_SW_QCHANNEL_SHFT                                    4U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_BMSK                              0x7U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_1_BYPASS_QCHANNEL_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_ADDR                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x114U)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_OFFS                                       (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x114U)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_RMSK                                       0xc777ffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_BMSK                      0x80000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_CLK_EN_STATUS_SHFT                              31U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_BMSK                0x40000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_CHILD_HW_CLK_EN_STATUS_SHFT                        30U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_QSTATE_STATUS_BMSK                          0x7000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_QSTATE_STATUS_SHFT                                 24U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_BMSK                       0x700000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_QACTIVE_STATUS_SHFT                             20U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_BMSK                       0x70000UL
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HW_QCHANNEL_STATUS_SHFT                            16U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_BMSK                        0xff00U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_TRAIL_COUNT_STATUS_SHFT                             8U
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_BMSK                     0xffU
#define HWIO_SAIL_TO_MD_DDR_REG_GLADIATOR_ROOT_CLOCK_GATING_2_HYSTERISIS_COUNT_STATUS_SHFT                        0U

#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x134U)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_OFFS                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x134U)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_RMSK                                                        0x3ffU
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_SOFTWARE_ARES_BMSK                                   0x200U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_SOFTWARE_ARES_SHFT                                       9U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DDRSS_PHY_CLK_CTRL_BMSK                              0x100U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DDRSS_PHY_CLK_CTRL_SHFT                                  8U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_WR_PATH_MODE_BMSK                                     0x80U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_WR_PATH_MODE_SHFT                                        7U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DATA_IN_BMSK                                          0x40U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DATA_IN_SHFT                                             6U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_EN_BMSK                                               0x20U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_EN_SHFT                                                  5U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_WNDW_EN_BMSK                                          0x10U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_WNDW_EN_SHFT                                             4U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RO_CNT_RESET_BMSK                                      0x8U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RO_CNT_RESET_SHFT                                        3U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RD_PATH_MODE_BMSK                                      0x4U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RD_PATH_MODE_SHFT                                        2U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RO_ENABLE_BMSK                                         0x2U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_RO_ENABLE_SHFT                                           1U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DATA_SEL_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL0_SB_TST_DATA_SEL_SHFT                                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x138U)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_OFFS                                                   (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x138U)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_RMSK                                                       0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_SB_TST_WNDW_MAX_CNT_BMSK                                   0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_CTL1_SB_TST_WNDW_MAX_CNT_SHFT                                        0U

#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_ADDR                                                 (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x13cU)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_OFFS                                                 (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x13cU)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_RMSK                                                  0x7ffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_RX_DATA_OUT_BMSK                               0x6000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_RX_DATA_OUT_SHFT                                      25U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_TX_DATA_OUT_BMSK                               0x1000000UL
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_TX_DATA_OUT_SHFT                                      24U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_EN_CNT_STA_BMSK                                 0xf00000UL
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_EN_CNT_STA_SHFT                                       20U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_REQ_CNT_STA_BMSK                                 0xf0000UL
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_REQ_CNT_STA_SHFT                                      16U
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_RO_CNT_STA_BMSK                                   0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_ASYNC_SB_TST_STATUS_SB_TST_RO_CNT_STA_SHFT                                        0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x140U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x140U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_APPS_INTERRUPT6_MASK_0_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_0_APPS_INTERRUPT6_MASK_0_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x144U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x144U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_APPS_INTERRUPT6_STATUS_0_BMSK                   0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_0_APPS_INTERRUPT6_STATUS_0_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x148U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x148U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_APPS_INTERRUPT7_MASK_0_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_0_APPS_INTERRUPT7_MASK_0_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x14cU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x14cU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_APPS_INTERRUPT7_STATUS_0_BMSK                   0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_0_APPS_INTERRUPT7_STATUS_0_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR                                                         (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x150U)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_OFFS                                                         (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x150U)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_RMSK                                                               0x11U
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_DPM_STOP_ACK_BMSK                                                  0x10U
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_DPM_STOP_ACK_SHFT                                                     4U
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_DPM_STOP_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_DPM_DDR_CMD_DPM_STOP_SHFT                                                         0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1a0U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1a0U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_RMSK                                                    0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_DOWNTIME_REQ_IN_BMSK                                    0xffff0000UL
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_DOWNTIME_REQ_IN_SHFT                                            16U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_DOWNTIME_ACK_OUT_BMSK                                       0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO1_DOWNTIME_ACK_OUT_SHFT                                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_ADDR                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1a4U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_OFFS                                                    (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1a4U)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_RMSK                                                    0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_DOWNTIME_REQ_GRANT_BMSK                                 0xffff0000UL
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_DOWNTIME_REQ_GRANT_SHFT                                         16U
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_DOWNTIME_REQ_MAX_PRI_BMSK                                   0xffffU
#define HWIO_SAIL_TO_MD_DDR_REG_DT_AGG_DBG_INFO2_DOWNTIME_REQ_MAX_PRI_SHFT                                        0U

#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1a8U)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_OFFS                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1a8U)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_RMSK                                                  0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_AOP_INTERRUPT_MASK_1_BMSK                             0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_MASK_1_AOP_INTERRUPT_MASK_1_SHFT                                    0U

#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1acU)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1acU)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_AOP_INTERRUPT_STATUS_1_BMSK                         0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_AOP_INTERRUPT_STATUS_1_AOP_INTERRUPT_STATUS_1_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1b0U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1b0U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_APPS_INTERRUPT0_MASK_1_BMSK                         0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_MASK_1_APPS_INTERRUPT0_MASK_1_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1b4U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1b4U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_RMSK                                              0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_APPS_INTERRUPT0_STATUS_1_BMSK                     0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT0_STATUS_1_APPS_INTERRUPT0_STATUS_1_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1b8U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1b8U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_APPS_INTERRUPT1_MASK_1_BMSK                         0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_MASK_1_APPS_INTERRUPT1_MASK_1_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1bcU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1bcU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_RMSK                                              0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_APPS_INTERRUPT1_STATUS_1_BMSK                     0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT1_STATUS_1_APPS_INTERRUPT1_STATUS_1_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1c0U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1c0U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_APPS_INTERRUPT2_MASK_1_BMSK                         0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_MASK_1_APPS_INTERRUPT2_MASK_1_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1c4U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1c4U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_RMSK                                              0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_APPS_INTERRUPT2_STATUS_1_BMSK                     0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT2_STATUS_1_APPS_INTERRUPT2_STATUS_1_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1c8U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1c8U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_APPS_INTERRUPT3_MASK_1_BMSK                         0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_MASK_1_APPS_INTERRUPT3_MASK_1_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1ccU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1ccU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_RMSK                                              0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_APPS_INTERRUPT3_STATUS_1_BMSK                     0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT3_STATUS_1_APPS_INTERRUPT3_STATUS_1_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1d0U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1d0U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_APPS_INTERRUPT4_MASK_1_BMSK                         0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_MASK_1_APPS_INTERRUPT4_MASK_1_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1d4U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1d4U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_RMSK                                              0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_APPS_INTERRUPT4_STATUS_1_BMSK                     0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT4_STATUS_1_APPS_INTERRUPT4_STATUS_1_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1d8U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1d8U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_APPS_INTERRUPT5_MASK_1_BMSK                         0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_MASK_1_APPS_INTERRUPT5_MASK_1_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1dcU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1dcU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_RMSK                                              0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_APPS_INTERRUPT5_STATUS_1_BMSK                     0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT5_STATUS_1_APPS_INTERRUPT5_STATUS_1_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1e0U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1e0U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_APPS_INTERRUPT6_MASK_1_BMSK                         0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_MASK_1_APPS_INTERRUPT6_MASK_1_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1e4U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1e4U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_RMSK                                              0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_APPS_INTERRUPT6_STATUS_1_BMSK                     0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT6_STATUS_1_APPS_INTERRUPT6_STATUS_1_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1e8U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_OFFS                                              (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1e8U)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_APPS_INTERRUPT7_MASK_1_BMSK                         0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_MASK_1_APPS_INTERRUPT7_MASK_1_SHFT                                0U

#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_ADDR                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1ecU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_OFFS                                            (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1ecU)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_RMSK                                              0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_APPS_INTERRUPT7_STATUS_1_BMSK                     0xffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_APPS_INTERRUPT7_STATUS_1_APPS_INTERRUPT7_STATUS_1_SHFT                            0U

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR                                               (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1f0U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_OFFS                                               (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1f0U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_RMSK                                               0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR,v)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_ADDR,m,v,HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_IN)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_SHRM_INTERRUPT_MASK_1_BMSK                         0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_MASK_1_SHRM_INTERRUPT_MASK_1_SHFT                                  0U

#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_ADDR                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1f4U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_OFFS                                             (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1f4U)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_RMSK                                             0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_SHRM_INTERRUPT_STATUS_1_BMSK                     0xffffffffUL
#define HWIO_SAIL_TO_MD_DDR_REG_SHRM_INTERRUPT_STATUS_1_SHRM_INTERRUPT_STATUS_1_SHFT                              0U

#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_ADDR                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE      + 0x1f8U)
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_OFFS                                                (SAIL_TO_MD_DDR_REG_DDR_REG_DDR_SS_REGS_REG_BASE_OFFS + 0x1f8U)
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_RMSK                                                    0x1fffU
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_HPCNT_BMSK                                              0x1f80U
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_HPCNT_SHFT                                                   7U
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_VPCNT_BMSK                                                0x7eU
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_VPCNT_SHFT                                                   1U
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_FLT_BMSK                                                   0x1U
#define HWIO_SAIL_TO_MD_DDR_REG_FUSA_STATUS_REGISTER_FLT_SHFT                                                     0U


#endif /* G_SAIL_TO_MD_DDR_HWIO_H */
