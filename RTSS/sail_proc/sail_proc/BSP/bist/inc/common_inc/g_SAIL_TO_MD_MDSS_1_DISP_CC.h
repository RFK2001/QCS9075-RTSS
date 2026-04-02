#ifndef __G_SAIL_TO_MD_MDSS_1_DISP_CC_H__
#define __G_SAIL_TO_MD_MDSS_1_DISP_CC_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_MDSS_1_DISP_CC.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_MDSS_1_DISP_CC.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/bist/inc/common_inc/g_SAIL_TO_MD_MDSS_1_DISP_CC.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE                                                     (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x22108000ul)
#define SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_SIZE                                                0x18000ul
#define SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_USED                                                0xa414u
#define SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS                                                0x22108000ul

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_ADDR                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_OFFS                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_RMSK                                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_BLK_ARES_BMSK                                                        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_BLK_ARES_SHFT                                                          0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_BLK_ARES_DISABLE_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_BCR_BLK_ARES_ENABLE_FVAL                                                 0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_ADDR                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_OFFS                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_RMSK                                                        0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_OFF_BMSK                                                0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_OFF_SHFT                                                        31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_IGNORE_ALL_ARES_SHFT                                                24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_DIS_BMSK                                                  0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_DIS_SHFT                                                        22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_ARES_BMSK                                                      0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_ARES_SHFT                                                        2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_ARES_RESET_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_ENABLE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_ENABLE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_ADDR                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_OFFS                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_RMSK                                                        0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_OFF_BMSK                                                0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_OFF_SHFT                                                        31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_IGNORE_ALL_ARES_SHFT                                                24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_DIS_BMSK                                                  0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_DIS_SHFT                                                        22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_ARES_BMSK                                                      0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_ARES_SHFT                                                        2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_ARES_RESET_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_ENABLE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_ENABLE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_ADDR                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xcu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_OFFS                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xcu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_RMSK                                                          0x81c07ff5ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_OFF_BMSK                                                  0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_OFF_SHFT                                                          31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_IGNORE_ALL_ARES_SHFT                                                  24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_DIS_BMSK                                                    0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_DIS_SHFT                                                          22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_CORE_ON_BMSK                                            0x4000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_CORE_ON_SHFT                                                14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                          0x2000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                              13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                         0x1000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                             12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_BMSK                                                        0xf00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_SHFT                                                            8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK0_FVAL                                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK1_FVAL                                                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK2_FVAL                                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK3_FVAL                                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK4_FVAL                                                   0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK5_FVAL                                                   0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK6_FVAL                                                   0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK7_FVAL                                                   0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK8_FVAL                                                   0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK9_FVAL                                                   0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK10_FVAL                                                  0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK11_FVAL                                                  0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK12_FVAL                                                  0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK13_FVAL                                                  0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK14_FVAL                                                  0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_WAKEUP_CLOCK15_FVAL                                                  0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_BMSK                                                          0xf0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_SHFT                                                             4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK0_FVAL                                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK1_FVAL                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK2_FVAL                                                    0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK3_FVAL                                                    0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK4_FVAL                                                    0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK5_FVAL                                                    0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK6_FVAL                                                    0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK7_FVAL                                                    0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK8_FVAL                                                    0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK9_FVAL                                                    0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK10_FVAL                                                   0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK11_FVAL                                                   0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK12_FVAL                                                   0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK13_FVAL                                                   0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK14_FVAL                                                   0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_SLEEP_CLOCK15_FVAL                                                   0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_ARES_BMSK                                                        0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_ARES_SHFT                                                          2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_ARES_NO_RESET_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_ARES_RESET_FVAL                                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_ENABLE_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_ENABLE_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_ENABLE_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CBCR_CLK_ENABLE_ENABLE_FVAL                                               0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_ADDR                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x10u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_OFFS                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x10u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_RMSK                                                         0xfffffffeul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                               0xff000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                       24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                  0xff0000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                        16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                     0x8000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                         15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                      0x4000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                          14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                     0x2000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                         13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                                 0x1000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                     12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CORE_ON_ACK_BMSK                                              0x800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CORE_ON_ACK_SHFT                                                 11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_PERIPH_ON_ACK_BMSK                                            0x400u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_PERIPH_ON_ACK_SHFT                                               10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                     0x300u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                         8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CPH_ENABLE_BMSK                                                0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CPH_ENABLE_SHFT                                                   7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_FORCE_CLK_ON_BMSK                                                  0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_FORCE_CLK_ON_SHFT                                                     6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_RST_SEL_SLP_STG_BMSK                                            0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_RST_SEL_SLP_STG_SHFT                                               5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_RST_SLP_STG_BMSK                                                0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_RST_SLP_STG_SHFT                                                   4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CTRL_PWR_DOWN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CTRL_PWR_DOWN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                          0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                            2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CLK_EN_SLP_STG_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CLK_EN_SLP_STG_SHFT                                                1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                         0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_ADDR                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x14u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_OFFS                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x14u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_RMSK                                                         0x81c07ff5ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_OFF_BMSK                                                 0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_OFF_SHFT                                                         31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_IGNORE_ALL_ARES_BMSK                                          0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_IGNORE_ALL_ARES_SHFT                                                 24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                        0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                              23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_DIS_BMSK                                                   0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_DIS_SHFT                                                         22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_CORE_ON_BMSK                                           0x4000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_CORE_ON_SHFT                                               14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                         0x2000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                             13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                        0x1000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                            12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_BMSK                                                       0xf00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_SHFT                                                           8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK0_FVAL                                                  0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK1_FVAL                                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK2_FVAL                                                  0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK3_FVAL                                                  0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK4_FVAL                                                  0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK5_FVAL                                                  0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK6_FVAL                                                  0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK7_FVAL                                                  0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK8_FVAL                                                  0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK9_FVAL                                                  0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK10_FVAL                                                 0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK11_FVAL                                                 0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK12_FVAL                                                 0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK13_FVAL                                                 0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK14_FVAL                                                 0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_WAKEUP_CLOCK15_FVAL                                                 0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_BMSK                                                         0xf0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_SHFT                                                            4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK0_FVAL                                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK1_FVAL                                                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK2_FVAL                                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK3_FVAL                                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK4_FVAL                                                   0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK5_FVAL                                                   0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK6_FVAL                                                   0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK7_FVAL                                                   0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK8_FVAL                                                   0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK9_FVAL                                                   0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK10_FVAL                                                  0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK11_FVAL                                                  0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK12_FVAL                                                  0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK13_FVAL                                                  0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK14_FVAL                                                  0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_SLEEP_CLOCK15_FVAL                                                  0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_ARES_BMSK                                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_ARES_SHFT                                                         2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_ARES_NO_RESET_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_ARES_RESET_FVAL                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_ENABLE_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_ENABLE_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_ENABLE_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_CBCR_CLK_ENABLE_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_ADDR                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x18u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_OFFS                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x18u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_RMSK                                                        0xfffffffeul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                              0xff000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                      24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                 0xff0000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                       16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                    0x8000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                        15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                     0x4000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                         14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                    0x2000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                        13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                                0x1000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                    12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CORE_ON_ACK_BMSK                                             0x800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CORE_ON_ACK_SHFT                                                11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_PERIPH_ON_ACK_BMSK                                           0x400u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_PERIPH_ON_ACK_SHFT                                              10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                    0x300u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                        8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                             0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                             0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CPH_ENABLE_BMSK                                               0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CPH_ENABLE_SHFT                                                  7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_FORCE_CLK_ON_BMSK                                                 0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_FORCE_CLK_ON_SHFT                                                    6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_RST_SEL_SLP_STG_BMSK                                           0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_RST_SEL_SLP_STG_SHFT                                              5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_RST_SLP_STG_BMSK                                               0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_RST_SLP_STG_SHFT                                                  4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CTRL_PWR_DOWN_BMSK                                              0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CTRL_PWR_DOWN_SHFT                                                3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                         0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                           2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CLK_EN_SLP_STG_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CLK_EN_SLP_STG_SHFT                                               1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP1_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_ADDR                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_OFFS                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_RMSK                                                      0x81c07ff5ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_OFF_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_OFF_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_IGNORE_ALL_ARES_SHFT                                              24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_DIS_BMSK                                                0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_DIS_SHFT                                                      22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_CORE_ON_BMSK                                        0x4000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_CORE_ON_SHFT                                            14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                      0x2000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                          13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                     0x1000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                         12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_BMSK                                                    0xf00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_SHFT                                                        8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK0_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK2_FVAL                                               0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK3_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK4_FVAL                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK5_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK6_FVAL                                               0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK7_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK8_FVAL                                               0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK9_FVAL                                               0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK10_FVAL                                              0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK11_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK12_FVAL                                              0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK13_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK14_FVAL                                              0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_WAKEUP_CLOCK15_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_BMSK                                                      0xf0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_SHFT                                                         4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK0_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK1_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK2_FVAL                                                0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK3_FVAL                                                0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK4_FVAL                                                0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK5_FVAL                                                0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK6_FVAL                                                0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK7_FVAL                                                0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK8_FVAL                                                0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK9_FVAL                                                0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK10_FVAL                                               0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK11_FVAL                                               0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK12_FVAL                                               0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK13_FVAL                                               0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK14_FVAL                                               0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_SLEEP_CLOCK15_FVAL                                               0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_ARES_BMSK                                                    0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_ARES_SHFT                                                      2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_ARES_RESET_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_ENABLE_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_ENABLE_SHFT                                                    0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_ADDR                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x20u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_OFFS                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x20u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_RMSK                                                     0xfffffffeul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                           0xff000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                   24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                              0xff0000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                    16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                 0x8000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                     15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                  0x4000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                      14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                     13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                 12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CORE_ON_ACK_BMSK                                          0x800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CORE_ON_ACK_SHFT                                             11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_PERIPH_ON_ACK_BMSK                                        0x400u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_PERIPH_ON_ACK_SHFT                                           10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                 0x300u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                     8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                          0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                          0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CPH_ENABLE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CPH_ENABLE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_FORCE_CLK_ON_BMSK                                              0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_FORCE_CLK_ON_SHFT                                                 6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_RST_SEL_SLP_STG_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_RST_SEL_SLP_STG_SHFT                                           5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_RST_SLP_STG_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_RST_SLP_STG_SHFT                                               4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CTRL_PWR_DOWN_BMSK                                           0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CTRL_PWR_DOWN_SHFT                                             3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                        2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CLK_EN_SLP_STG_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CLK_EN_SLP_STG_SHFT                                            1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                     0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_ADDR                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x24u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_OFFS                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x24u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_RMSK                                                     0x81c07ff5ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_IGNORE_ALL_ARES_SHFT                                             24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_DIS_BMSK                                               0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_DIS_SHFT                                                     22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_CORE_ON_BMSK                                       0x4000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_CORE_ON_SHFT                                           14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                     0x2000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                         13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                    0x1000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                        12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_BMSK                                                   0xf00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK8_FVAL                                              0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK9_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK10_FVAL                                             0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK11_FVAL                                             0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK12_FVAL                                             0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK13_FVAL                                             0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK14_FVAL                                             0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_WAKEUP_CLOCK15_FVAL                                             0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_BMSK                                                     0xf0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_SHFT                                                        4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK0_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK2_FVAL                                               0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK3_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK4_FVAL                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK5_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK6_FVAL                                               0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK7_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK8_FVAL                                               0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK9_FVAL                                               0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK10_FVAL                                              0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK11_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK12_FVAL                                              0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK13_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK14_FVAL                                              0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_SLEEP_CLOCK15_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_ARES_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_ARES_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_ENABLE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_ENABLE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x28u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x28u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_RMSK                                                    0xfffffffeul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                          0xff000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                  24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                             0xff0000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                   16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                0x8000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                    15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                     14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                0x2000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                    13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                            0x1000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CORE_ON_ACK_BMSK                                         0x800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CORE_ON_ACK_SHFT                                            11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_PERIPH_ON_ACK_BMSK                                       0x400u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_PERIPH_ON_ACK_SHFT                                          10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                0x300u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                    8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                         0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                         0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CPH_ENABLE_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CPH_ENABLE_SHFT                                              7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_FORCE_CLK_ON_BMSK                                             0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_FORCE_CLK_ON_SHFT                                                6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_RST_SEL_SLP_STG_BMSK                                       0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_RST_SEL_SLP_STG_SHFT                                          5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_RST_SLP_STG_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_RST_SLP_STG_SHFT                                              4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CTRL_PWR_DOWN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CTRL_PWR_DOWN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                       2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CLK_EN_SLP_STG_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CLK_EN_SLP_STG_SHFT                                           1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_LUT1_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                    0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_ADDR                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x2cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_OFFS                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x2cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_RMSK                                                        0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_OFF_BMSK                                                0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_OFF_SHFT                                                        31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_IGNORE_ALL_ARES_SHFT                                                24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_DIS_BMSK                                                  0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_DIS_SHFT                                                        22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_ARES_BMSK                                                      0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_ARES_SHFT                                                        2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_ARES_RESET_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_ENABLE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_ENABLE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_ADDR                                                       (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x30u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_OFFS                                                       (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x30u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_RMSK                                                       0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_OFF_BMSK                                               0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_OFF_SHFT                                                       31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_IGNORE_ALL_ARES_BMSK                                        0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_IGNORE_ALL_ARES_SHFT                                               24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                      0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                            23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_DIS_BMSK                                                 0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_DIS_SHFT                                                       22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_ARES_BMSK                                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_ARES_SHFT                                                       2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_ARES_NO_RESET_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_ARES_RESET_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_ENABLE_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_ENABLE_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_ENABLE_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC1_CBCR_CLK_ENABLE_ENABLE_FVAL                                            0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_ADDR                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x34u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_OFFS                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x34u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_RMSK                                                        0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_OFF_BMSK                                                0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_OFF_SHFT                                                        31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_IGNORE_ALL_ARES_SHFT                                                24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_DIS_BMSK                                                  0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_DIS_SHFT                                                        22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_ARES_BMSK                                                      0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_ARES_SHFT                                                        2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_ARES_RESET_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_ENABLE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_ENABLE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x38u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x38u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_INTF_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_ADDR                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x3cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_OFFS                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x3cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_RMSK                                                        0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_OFF_BMSK                                                0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_OFF_SHFT                                                        31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_IGNORE_ALL_ARES_SHFT                                                24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_DIS_BMSK                                                  0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_DIS_SHFT                                                        22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_ARES_BMSK                                                      0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_ARES_SHFT                                                        2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_ARES_RESET_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_ENABLE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_ENABLE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x40u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x40u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_INTF_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_ADDR                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x44u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_OFFS                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x44u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_RMSK                                                         0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_OFF_BMSK                                                 0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_OFF_SHFT                                                         31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_IGNORE_ALL_ARES_BMSK                                          0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_IGNORE_ALL_ARES_SHFT                                                 24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                        0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                              23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_DIS_BMSK                                                   0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_DIS_SHFT                                                         22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_ARES_BMSK                                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_ARES_SHFT                                                         2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_ARES_NO_RESET_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_ARES_RESET_FVAL                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_ENABLE_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_ENABLE_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_ENABLE_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CBCR_CLK_ENABLE_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_ADDR                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x48u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_OFFS                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x48u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_RMSK                                                         0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_OFF_BMSK                                                 0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_OFF_SHFT                                                         31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_IGNORE_ALL_ARES_BMSK                                          0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_IGNORE_ALL_ARES_SHFT                                                 24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                        0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                              23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_DIS_BMSK                                                   0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_DIS_SHFT                                                         22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_ARES_BMSK                                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_ARES_SHFT                                                         2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_ARES_NO_RESET_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_ARES_RESET_FVAL                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_ENABLE_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_ENABLE_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_ENABLE_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CBCR_CLK_ENABLE_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x50u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x50u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_RMSK                                              0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_INTF_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_ADDR                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x54u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_OFFS                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x54u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_RMSK                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_OFF_BMSK                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_OFF_SHFT                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_IGNORE_ALL_ARES_BMSK                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_IGNORE_ALL_ARES_SHFT                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_DIS_BMSK                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_DIS_SHFT                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_ARES_BMSK                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_ARES_SHFT                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_ARES_NO_RESET_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_ARES_RESET_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_ENABLE_BMSK                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_ENABLE_SHFT                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_ENABLE_DISABLE_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CBCR_CLK_ENABLE_ENABLE_FVAL                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_ADDR                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x58u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_OFFS                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x58u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_RMSK                                                 0x81c00004ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CBCR_CLK_ARES_RESET_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x5cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x5cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_RMSK                                                    0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_IGNORE_ALL_ARES_BMSK                                     0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_IGNORE_ALL_ARES_SHFT                                            24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                   0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                         23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_DIS_BMSK                                              0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_DIS_SHFT                                                    22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_ARES_BMSK                                                  0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_ARES_SHFT                                                    2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_ARES_NO_RESET_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_ARES_RESET_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_ENABLE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_ENABLE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_ENABLE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CBCR_CLK_ENABLE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_ADDR                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x60u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_OFFS                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x60u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_RMSK                                                 0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_ARES_RESET_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_ADDR                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x64u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_OFFS                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x64u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_RMSK                                                 0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_ARES_RESET_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_ADDR                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x68u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_OFFS                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x68u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_RMSK                                                 0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_ARES_RESET_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_ADDR                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x6cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_OFFS                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x6cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_RMSK                                                 0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_ARES_RESET_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x70u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x70u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x74u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x74u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_RMSK                                              0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_INTF_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_ADDR                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x78u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_OFFS                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x78u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_RMSK                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_OFF_BMSK                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_OFF_SHFT                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_IGNORE_ALL_ARES_BMSK                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_IGNORE_ALL_ARES_SHFT                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_DIS_BMSK                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_DIS_SHFT                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_ARES_BMSK                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_ARES_SHFT                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_ARES_NO_RESET_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_ARES_RESET_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_ENABLE_BMSK                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_ENABLE_SHFT                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_ENABLE_DISABLE_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CBCR_CLK_ENABLE_ENABLE_FVAL                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_ADDR                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x7cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_OFFS                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x7cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_RMSK                                                 0x81c00004ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CBCR_CLK_ARES_RESET_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x80u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x80u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_RMSK                                                    0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_IGNORE_ALL_ARES_BMSK                                     0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_IGNORE_ALL_ARES_SHFT                                            24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                   0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                         23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_DIS_BMSK                                              0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_DIS_SHFT                                                    22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_ARES_BMSK                                                  0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_ARES_SHFT                                                    2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_ARES_NO_RESET_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_ARES_RESET_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_ENABLE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_ENABLE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_ENABLE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CBCR_CLK_ENABLE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_ADDR                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x84u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_OFFS                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x84u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_RMSK                                                          0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_OFF_BMSK                                                  0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_OFF_SHFT                                                          31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                                  24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_DIS_BMSK                                                    0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_DIS_SHFT                                                          22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_ARES_BMSK                                                        0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_ARES_SHFT                                                          2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_ARES_RESET_FVAL                                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_ENABLE_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_ENABLE_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                               0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_ADDR                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x88u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_OFFS                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x88u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_RMSK                                                         0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_OFF_BMSK                                                 0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_OFF_SHFT                                                         31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_IGNORE_ALL_ARES_BMSK                                          0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_IGNORE_ALL_ARES_SHFT                                                 24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                        0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                              23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_DIS_BMSK                                                   0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_DIS_SHFT                                                         22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_ARES_BMSK                                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_ARES_SHFT                                                         2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_ARES_NO_RESET_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_ARES_RESET_FVAL                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_ENABLE_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_ENABLE_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_ENABLE_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB1_CBCR_CLK_ENABLE_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x8cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x8cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_RMSK                                                    0x800000f3ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ROOT_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_DIRTY_D_BMSK                                                  0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_DIRTY_D_SHFT                                                     7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_DIRTY_N_BMSK                                                  0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_DIRTY_N_SHFT                                                     6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_DIRTY_M_BMSK                                                  0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_DIRTY_M_SHFT                                                     5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ROOT_EN_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ROOT_EN_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_UPDATE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_UPDATE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x90u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x90u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_RMSK                                                      0x10371ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_MODE_BMSK                                                   0x3000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_MODE_SHFT                                                       12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_MODE_BYPASS_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_MODE_SWALLOW_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                          0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_BMSK                                                 0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_SHFT                                                     8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_ADDR                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x94u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_OFFS                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x94u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_RMSK                                                                 0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_M_BMSK                                                               0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_M_M_SHFT                                                                  0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_ADDR                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x98u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_OFFS                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x98u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_RMSK                                                                 0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_NOT_N_MINUS_M_BMSK                                                   0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_N_NOT_N_MINUS_M_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_ADDR                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x9cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_OFFS                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x9cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_RMSK                                                                 0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_NOT_2D_BMSK                                                          0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK0_D_NOT_2D_SHFT                                                             0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xa4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xa4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_RMSK                                                    0x800000f3ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ROOT_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_DIRTY_D_BMSK                                                  0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_DIRTY_D_SHFT                                                     7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_DIRTY_N_BMSK                                                  0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_DIRTY_N_SHFT                                                     6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_DIRTY_M_BMSK                                                  0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_DIRTY_M_SHFT                                                     5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ROOT_EN_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ROOT_EN_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_UPDATE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_UPDATE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xa8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xa8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_RMSK                                                      0x10371ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_MODE_BMSK                                                   0x3000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_MODE_SHFT                                                       12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_MODE_BYPASS_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_MODE_SWALLOW_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                          0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_BMSK                                                 0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_SHFT                                                     8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_ADDR                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xacu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_OFFS                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xacu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_RMSK                                                                 0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_M_BMSK                                                               0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_M_M_SHFT                                                                  0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_ADDR                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xb0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_OFFS                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xb0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_RMSK                                                                 0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_NOT_N_MINUS_M_BMSK                                                   0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_N_NOT_N_MINUS_M_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_ADDR                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xb4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_OFFS                                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xb4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_RMSK                                                                 0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_NOT_2D_BMSK                                                          0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PCLK1_D_NOT_2D_SHFT                                                             0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ADDR                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xbcu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_OFFS                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xbcu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_RMSK                                                      0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ROOT_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ROOT_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                             0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ROOT_EN_BMSK                                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ROOT_EN_SHFT                                                       1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_UPDATE_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_UPDATE_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_UPDATE_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CMD_RCGR_UPDATE_ENABLE_FVAL                                               0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_ADDR                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xc0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_OFFS                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xc0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_RMSK                                                        0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_HW_CLK_CONTROL_BMSK                                         0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_HW_CLK_CONTROL_SHFT                                               20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_RCGLITE_DISABLE_BMSK                                         0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_RCGLITE_DISABLE_SHFT                                              16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_BMSK                                                   0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_BMSK                                                    0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                              0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                              0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                              0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                              0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                             0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV9_FVAL                                               0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                             0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV10_FVAL                                              0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                            0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV11_FVAL                                              0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                            0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV12_FVAL                                              0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                            0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV13_FVAL                                              0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                            0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV14_FVAL                                              0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                            0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV15_FVAL                                              0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                            0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_MDP_CFG_RCGR_SRC_DIV_DIV16_FVAL                                              0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xd4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xd4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_RMSK                                                    0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ROOT_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ROOT_EN_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ROOT_EN_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_UPDATE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_UPDATE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xd8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xd8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_RMSK                                                      0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_RCGLITE_DISABLE_BMSK                                       0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_RCGLITE_DISABLE_SHFT                                            16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_BMSK                                                 0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_SHFT                                                     8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_VSYNC_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xecu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xecu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_RMSK                                                    0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ROOT_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ROOT_EN_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ROOT_EN_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_UPDATE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_UPDATE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xf0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xf0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_RMSK                                                      0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_RCGLITE_DISABLE_BMSK                                       0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_RCGLITE_DISABLE_SHFT                                            16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_BMSK                                                 0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_SHFT                                                     8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x104u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x104u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_RMSK                                                          0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_CLK_DIV_BMSK                                                  0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE0_DIV_CDIVR_CLK_DIV_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x108u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x108u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_RMSK                                                    0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ROOT_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ROOT_EN_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ROOT_EN_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_UPDATE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_UPDATE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x10cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x10cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_RMSK                                                      0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_RCGLITE_DISABLE_BMSK                                       0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_RCGLITE_DISABLE_SHFT                                            16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_BMSK                                                 0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_SHFT                                                     8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x120u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x120u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_RMSK                                                          0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_CLK_DIV_BMSK                                                  0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_BYTE1_DIV_CDIVR_CLK_DIV_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ADDR                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x124u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_OFFS                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x124u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_RMSK                                                     0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ROOT_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ROOT_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                               4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ROOT_EN_BMSK                                                    0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ROOT_EN_SHFT                                                      1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_UPDATE_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_UPDATE_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_UPDATE_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CMD_RCGR_UPDATE_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_ADDR                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x128u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_OFFS                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x128u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_RMSK                                                       0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_HW_CLK_CONTROL_BMSK                                        0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_HW_CLK_CONTROL_SHFT                                              20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_RCGLITE_DISABLE_BMSK                                        0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_RCGLITE_DISABLE_SHFT                                             16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_BMSK                                                  0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_SHFT                                                      8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_SRC0_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_SRC1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_SRC2_FVAL                                               0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_SRC3_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_SRC4_FVAL                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_SRC5_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_SRC6_FVAL                                               0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_SEL_SRC7_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_BMSK                                                   0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                             0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV2_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                             0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV3_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                             0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV4_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                             0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV5_FVAL                                               0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                             0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV6_FVAL                                               0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                             0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV7_FVAL                                               0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                             0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV8_FVAL                                               0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                            0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV9_FVAL                                              0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                            0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV10_FVAL                                             0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                           0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV11_FVAL                                             0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                           0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV12_FVAL                                             0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                           0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV13_FVAL                                             0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                           0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV14_FVAL                                             0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                           0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV15_FVAL                                             0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                           0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC0_CFG_RCGR_SRC_DIV_DIV16_FVAL                                             0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ADDR                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x13cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_OFFS                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x13cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_RMSK                                                     0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ROOT_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ROOT_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                               4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ROOT_EN_BMSK                                                    0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ROOT_EN_SHFT                                                      1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_UPDATE_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_UPDATE_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_UPDATE_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CMD_RCGR_UPDATE_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_ADDR                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x140u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_OFFS                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x140u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_RMSK                                                       0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_HW_CLK_CONTROL_BMSK                                        0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_HW_CLK_CONTROL_SHFT                                              20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_RCGLITE_DISABLE_BMSK                                        0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_RCGLITE_DISABLE_SHFT                                             16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_BMSK                                                  0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_SHFT                                                      8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_SRC0_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_SRC1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_SRC2_FVAL                                               0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_SRC3_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_SRC4_FVAL                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_SRC5_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_SRC6_FVAL                                               0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_SEL_SRC7_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_BMSK                                                   0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                             0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV2_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                             0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV3_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                             0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV4_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                             0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV5_FVAL                                               0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                             0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV6_FVAL                                               0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                             0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV7_FVAL                                               0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                             0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV8_FVAL                                               0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                            0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV9_FVAL                                              0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                            0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV10_FVAL                                             0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                           0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV11_FVAL                                             0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                           0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV12_FVAL                                             0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                           0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV13_FVAL                                             0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                           0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV14_FVAL                                             0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                           0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV15_FVAL                                             0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                           0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_ESC1_CFG_RCGR_SRC_DIV_DIV16_FVAL                                             0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ADDR                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x154u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_OFFS                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x154u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_RMSK                                               0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ROOT_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ROOT_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                         4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ROOT_EN_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ROOT_EN_SHFT                                                1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_UPDATE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_UPDATE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_UPDATE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CMD_RCGR_UPDATE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_ADDR                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x158u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_OFFS                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x158u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_RMSK                                                 0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_HW_CLK_CONTROL_BMSK                                  0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_HW_CLK_CONTROL_SHFT                                        20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_RCGLITE_DISABLE_BMSK                                  0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_RCGLITE_DISABLE_SHFT                                       16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_BMSK                                            0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_SHFT                                                8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_SRC0_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_SRC1_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_SRC2_FVAL                                         0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_SRC3_FVAL                                         0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_SRC4_FVAL                                         0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_SRC5_FVAL                                         0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_SRC6_FVAL                                         0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_SEL_SRC7_FVAL                                         0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_BMSK                                             0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_SHFT                                                0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV1_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV2_FVAL                                         0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV3_FVAL                                         0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV4_FVAL                                         0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                       0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV5_FVAL                                         0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                       0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV6_FVAL                                         0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                       0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV7_FVAL                                         0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                       0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV8_FVAL                                         0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                      0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV9_FVAL                                        0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                      0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV10_FVAL                                       0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                     0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV11_FVAL                                       0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                     0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV12_FVAL                                       0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                     0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV13_FVAL                                       0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                     0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV14_FVAL                                       0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                     0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV15_FVAL                                       0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                     0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_CFG_RCGR_SRC_DIV_DIV16_FVAL                                       0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x16cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x16cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_RMSK                                                     0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_CLK_DIV_BMSK                                             0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_LINK_DIV_CDIVR_CLK_DIV_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x170u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x170u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_RMSK                                             0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ROOT_OFF_SHFT                                            31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ROOT_EN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ROOT_EN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_UPDATE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_UPDATE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x174u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x174u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_RMSK                                               0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_RCGLITE_DISABLE_BMSK                                0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_RCGLITE_DISABLE_SHFT                                     16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_BMSK                                          0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_SHFT                                              8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_BMSK                                           0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_SHFT                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_CRYPTO_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x188u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x188u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_RMSK                                             0x800000f3ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ROOT_OFF_SHFT                                            31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_DIRTY_D_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_DIRTY_D_SHFT                                              7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_DIRTY_N_BMSK                                           0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_DIRTY_N_SHFT                                              6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_DIRTY_M_BMSK                                           0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_DIRTY_M_SHFT                                              5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ROOT_EN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ROOT_EN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_UPDATE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_UPDATE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x18cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x18cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_RMSK                                               0x10371ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_MODE_BMSK                                            0x3000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_MODE_SHFT                                                12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_MODE_BYPASS_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_MODE_SWALLOW_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_BMSK                                          0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_SHFT                                              8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_BMSK                                           0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_SHFT                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x190u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x190u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_M_BMSK                                                      0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_M_M_SHFT                                                           0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x194u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x194u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_NOT_N_MINUS_M_BMSK                                          0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_N_NOT_N_MINUS_M_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x198u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x198u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_NOT_2D_BMSK                                                 0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL0_D_NOT_2D_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1a0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1a0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_RMSK                                             0x800000f3ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ROOT_OFF_SHFT                                            31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_DIRTY_D_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_DIRTY_D_SHFT                                              7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_DIRTY_N_BMSK                                           0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_DIRTY_N_SHFT                                              6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_DIRTY_M_BMSK                                           0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_DIRTY_M_SHFT                                              5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ROOT_EN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ROOT_EN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_UPDATE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_UPDATE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1a4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1a4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_RMSK                                               0x10371ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_MODE_BMSK                                            0x3000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_MODE_SHFT                                                12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_MODE_BYPASS_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_MODE_SWALLOW_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_BMSK                                          0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_SHFT                                              8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_BMSK                                           0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_SHFT                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1a8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1a8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_M_BMSK                                                      0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_M_M_SHFT                                                           0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1acu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1acu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_NOT_N_MINUS_M_BMSK                                          0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_N_NOT_N_MINUS_M_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1b0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1b0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_NOT_2D_BMSK                                                 0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL1_D_NOT_2D_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ADDR                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1b8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_OFFS                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1b8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_RMSK                                                0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ROOT_OFF_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ROOT_OFF_SHFT                                               31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                       0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                          4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ROOT_EN_BMSK                                               0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ROOT_EN_SHFT                                                 1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_UPDATE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_UPDATE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_UPDATE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CMD_RCGR_UPDATE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_ADDR                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1bcu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_OFFS                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1bcu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_RMSK                                                  0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_HW_CLK_CONTROL_BMSK                                   0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_HW_CLK_CONTROL_SHFT                                         20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_RCGLITE_DISABLE_BMSK                                   0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_RCGLITE_DISABLE_SHFT                                        16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_BMSK                                             0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_SHFT                                                 8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_SRC0_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_SRC1_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_SRC2_FVAL                                          0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_SRC3_FVAL                                          0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_SRC4_FVAL                                          0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_SRC5_FVAL                                          0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_SRC6_FVAL                                          0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_SEL_SRC7_FVAL                                          0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_BMSK                                              0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV1_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                        0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV2_FVAL                                          0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                        0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV3_FVAL                                          0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                        0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV4_FVAL                                          0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                        0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV5_FVAL                                          0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                        0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV6_FVAL                                          0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                        0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV7_FVAL                                          0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                        0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV8_FVAL                                          0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                       0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV9_FVAL                                         0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                       0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV10_FVAL                                        0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                      0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV11_FVAL                                        0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                      0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV12_FVAL                                        0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                      0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV13_FVAL                                        0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                      0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV14_FVAL                                        0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                      0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV15_FVAL                                        0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                      0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_AUX_CFG_RCGR_SRC_DIV_DIV16_FVAL                                        0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1d0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1d0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_RMSK                                             0x800000f3ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ROOT_OFF_SHFT                                            31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_DIRTY_D_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_DIRTY_D_SHFT                                              7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_DIRTY_N_BMSK                                           0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_DIRTY_N_SHFT                                              6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_DIRTY_M_BMSK                                           0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_DIRTY_M_SHFT                                              5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ROOT_EN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ROOT_EN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_UPDATE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_UPDATE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1d4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1d4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_RMSK                                               0x10371ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_MODE_BMSK                                            0x3000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_MODE_SHFT                                                12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_MODE_BYPASS_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_MODE_SWALLOW_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_BMSK                                          0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_SHFT                                              8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_BMSK                                           0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_SHFT                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1d8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1d8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_M_BMSK                                                      0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_M_M_SHFT                                                           0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1dcu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1dcu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_NOT_N_MINUS_M_BMSK                                          0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_N_NOT_N_MINUS_M_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1e0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1e0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_NOT_2D_BMSK                                                 0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL0_D_NOT_2D_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1e8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1e8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_RMSK                                             0x800000f3ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ROOT_OFF_SHFT                                            31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_DIRTY_D_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_DIRTY_D_SHFT                                              7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_DIRTY_N_BMSK                                           0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_DIRTY_N_SHFT                                              6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_DIRTY_M_BMSK                                           0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_DIRTY_M_SHFT                                              5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ROOT_EN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ROOT_EN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_UPDATE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_UPDATE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1ecu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1ecu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_RMSK                                               0x10371ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_MODE_BMSK                                            0x3000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_MODE_SHFT                                                12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_MODE_BYPASS_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_MODE_SWALLOW_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_BMSK                                          0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_SHFT                                              8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_BMSK                                           0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_SHFT                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1f0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1f0u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_M_BMSK                                                      0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_M_M_SHFT                                                           0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1f4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1f4u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_NOT_N_MINUS_M_BMSK                                          0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_N_NOT_N_MINUS_M_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1f8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1f8u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_NOT_2D_BMSK                                                 0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_PIXEL1_D_NOT_2D_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ADDR                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x200u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_OFFS                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x200u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_RMSK                                               0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ROOT_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ROOT_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                         4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ROOT_EN_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ROOT_EN_SHFT                                                1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_UPDATE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_UPDATE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_UPDATE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CMD_RCGR_UPDATE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_ADDR                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x204u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_OFFS                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x204u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_RMSK                                                 0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_HW_CLK_CONTROL_BMSK                                  0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_HW_CLK_CONTROL_SHFT                                        20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_RCGLITE_DISABLE_BMSK                                  0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_RCGLITE_DISABLE_SHFT                                       16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_BMSK                                            0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_SHFT                                                8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_SRC0_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_SRC1_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_SRC2_FVAL                                         0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_SRC3_FVAL                                         0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_SRC4_FVAL                                         0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_SRC5_FVAL                                         0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_SRC6_FVAL                                         0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_SEL_SRC7_FVAL                                         0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_BMSK                                             0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_SHFT                                                0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV1_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV2_FVAL                                         0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV3_FVAL                                         0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV4_FVAL                                         0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                       0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV5_FVAL                                         0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                       0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV6_FVAL                                         0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                       0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV7_FVAL                                         0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                       0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV8_FVAL                                         0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                      0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV9_FVAL                                        0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                      0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV10_FVAL                                       0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                     0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV11_FVAL                                       0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                     0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV12_FVAL                                       0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                     0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV13_FVAL                                       0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                     0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV14_FVAL                                       0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                     0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV15_FVAL                                       0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                     0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_CFG_RCGR_SRC_DIV_DIV16_FVAL                                       0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x218u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x218u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_RMSK                                                     0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_CLK_DIV_BMSK                                             0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_LINK_DIV_CDIVR_CLK_DIV_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x21cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x21cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_RMSK                                             0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ROOT_OFF_SHFT                                            31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ROOT_EN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ROOT_EN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_UPDATE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_UPDATE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x220u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x220u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_RMSK                                               0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_RCGLITE_DISABLE_BMSK                                0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_RCGLITE_DISABLE_SHFT                                     16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_BMSK                                          0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_SHFT                                              8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_BMSK                                           0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_SHFT                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_CRYPTO_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ADDR                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x234u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_OFFS                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x234u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_RMSK                                                0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ROOT_OFF_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ROOT_OFF_SHFT                                               31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                       0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                          4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ROOT_EN_BMSK                                               0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ROOT_EN_SHFT                                                 1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_UPDATE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_UPDATE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_UPDATE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CMD_RCGR_UPDATE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_ADDR                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x238u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_OFFS                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x238u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_RMSK                                                  0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_HW_CLK_CONTROL_BMSK                                   0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_HW_CLK_CONTROL_SHFT                                         20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_RCGLITE_DISABLE_BMSK                                   0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_RCGLITE_DISABLE_SHFT                                        16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_BMSK                                             0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_SHFT                                                 8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_SRC0_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_SRC1_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_SRC2_FVAL                                          0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_SRC3_FVAL                                          0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_SRC4_FVAL                                          0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_SRC5_FVAL                                          0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_SRC6_FVAL                                          0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_SEL_SRC7_FVAL                                          0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_BMSK                                              0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV1_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                        0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV2_FVAL                                          0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                        0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV3_FVAL                                          0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                        0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV4_FVAL                                          0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                        0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV5_FVAL                                          0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                        0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV6_FVAL                                          0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                        0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV7_FVAL                                          0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                        0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV8_FVAL                                          0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                       0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV9_FVAL                                         0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                       0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV10_FVAL                                        0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                      0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV11_FVAL                                        0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                      0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV12_FVAL                                        0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                      0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV13_FVAL                                        0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                      0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV14_FVAL                                        0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                      0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV15_FVAL                                        0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                      0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX1_AUX_CFG_RCGR_SRC_DIV_DIV16_FVAL                                        0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ADDR                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x24cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_OFFS                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x24cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_RMSK                                                      0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ROOT_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ROOT_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                             0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ROOT_EN_BMSK                                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ROOT_EN_SHFT                                                       1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_UPDATE_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_UPDATE_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_UPDATE_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CMD_RCGR_UPDATE_ENABLE_FVAL                                               0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_ADDR                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x250u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_OFFS                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x250u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_RMSK                                                        0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_HW_CLK_CONTROL_BMSK                                         0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_HW_CLK_CONTROL_SHFT                                               20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_RCGLITE_DISABLE_BMSK                                         0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_RCGLITE_DISABLE_SHFT                                              16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_BMSK                                                   0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_BMSK                                                    0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                              0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                              0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                              0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                              0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                             0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV9_FVAL                                               0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                             0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV10_FVAL                                              0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                            0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV11_FVAL                                              0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                            0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV12_FVAL                                              0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                            0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV13_FVAL                                              0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                            0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV14_FVAL                                              0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                            0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV15_FVAL                                              0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                            0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_AHB_CFG_RCGR_SRC_DIV_DIV16_FVAL                                              0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_ADDR                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x264u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_OFFS                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x264u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_RMSK                                                 0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_ARES_RESET_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_ADDR                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x268u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_OFFS                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x268u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_RMSK                                                 0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_ARES_RESET_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x26cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x26cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_RMSK                                             0x800000f3ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ROOT_OFF_SHFT                                            31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_DIRTY_D_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_DIRTY_D_SHFT                                              7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_DIRTY_N_BMSK                                           0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_DIRTY_N_SHFT                                              6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_DIRTY_M_BMSK                                           0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_DIRTY_M_SHFT                                              5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ROOT_EN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ROOT_EN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_UPDATE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_UPDATE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x270u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x270u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_RMSK                                               0x10371ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_MODE_BMSK                                            0x3000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_MODE_SHFT                                                12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_MODE_BYPASS_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_MODE_SWALLOW_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_BMSK                                          0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_SHFT                                              8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_BMSK                                           0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_SHFT                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x274u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x274u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_M_BMSK                                                      0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_M_M_SHFT                                                           0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x278u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x278u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_NOT_N_MINUS_M_BMSK                                          0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_N_NOT_N_MINUS_M_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x27cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x27cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_NOT_2D_BMSK                                                 0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL2_D_NOT_2D_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x284u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x284u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_RMSK                                             0x800000f3ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ROOT_OFF_SHFT                                            31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_DIRTY_D_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_DIRTY_D_SHFT                                              7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_DIRTY_N_BMSK                                           0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_DIRTY_N_SHFT                                              6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_DIRTY_M_BMSK                                           0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_DIRTY_M_SHFT                                              5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ROOT_EN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ROOT_EN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_UPDATE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_UPDATE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x288u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x288u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_RMSK                                               0x10371ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_MODE_BMSK                                            0x3000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_MODE_SHFT                                                12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_MODE_BYPASS_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_MODE_SWALLOW_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_BMSK                                          0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_SHFT                                              8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_BMSK                                           0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_SHFT                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x28cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x28cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_M_BMSK                                                      0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_M_M_SHFT                                                           0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x290u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x290u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_NOT_N_MINUS_M_BMSK                                          0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_N_NOT_N_MINUS_M_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x294u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x294u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_NOT_2D_BMSK                                                 0xffffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_DPTX0_PIXEL3_D_NOT_2D_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_ADDR                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_OFFS                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RMSK                                                        0xf8fffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_PWR_ON_BMSK                                                 0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_PWR_ON_SHFT                                                         31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_GDSC_STATE_BMSK                                             0x78000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_GDSC_STATE_SHFT                                                     27u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_REST_WAIT_BMSK                                             0xf00000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_REST_WAIT_SHFT                                                   20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_FEW_WAIT_BMSK                                               0xf0000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_FEW_WAIT_SHFT                                                    16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLK_DIS_WAIT_BMSK                                               0xf000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLK_DIS_WAIT_SHFT                                                   12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RETAIN_FF_ENABLE_BMSK                                            0x800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RETAIN_FF_ENABLE_SHFT                                               11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RESTORE_BMSK                                                     0x400u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RESTORE_SHFT                                                        10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RESTORE_DISABLE_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RESTORE_ENABLE_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SAVE_BMSK                                                        0x200u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SAVE_SHFT                                                            9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SAVE_DISABLE_FVAL                                                  0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SAVE_ENABLE_FVAL                                                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RETAIN_BMSK                                                      0x100u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RETAIN_SHFT                                                          8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RETAIN_DISABLE_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_RETAIN_ENABLE_FVAL                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_REST_BMSK                                                      0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_REST_SHFT                                                         7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_REST_DISABLE_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_REST_ENABLE_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_FEW_BMSK                                                       0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_FEW_SHFT                                                          6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_FEW_DISABLE_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_EN_FEW_ENABLE_FVAL                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLAMP_IO_BMSK                                                     0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLAMP_IO_SHFT                                                        5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLAMP_IO_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLAMP_IO_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLK_DISABLE_BMSK                                                  0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLK_DISABLE_SHFT                                                     4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_PD_ARES_BMSK                                                       0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_PD_ARES_SHFT                                                         3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_PD_ARES_NO_RESET_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_PD_ARES_RESET_FVAL                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SW_OVERRIDE_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SW_OVERRIDE_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_HW_CONTROL_BMSK                                                    0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_HW_CONTROL_SHFT                                                      1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_HW_CONTROL_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_HW_CONTROL_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SW_COLLAPSE_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SW_COLLAPSE_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                            0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_ADDR                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_OFFS                                                    (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_RMSK                                                     0x3fffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                                  0x2000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                         25u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                                   0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                          24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                            0xf00000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                                  20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                               0x80000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                    19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                                   0x40000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                        18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                                   0x20000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                        17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                                0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                     16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                               0x8000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                                   15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                              0x7800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                                  11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                      0x400u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                         10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                               0x200u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                                   9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                               0x100u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                                   8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                                   0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                      7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                          0x60u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                             5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                              0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                            0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                              2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                                0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                  1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_RMSK                                                      0x7fffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                          0x40000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                               18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                      0x20000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                           17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                    0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                         16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                        0xf000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                            12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                                 0xf00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                     8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                    0xf0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                       4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                      0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                        0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x100cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x100cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_RMSK                                                    0x7fffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK                  0x4000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                         26u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                               0x2000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                      25u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                          0x1e00000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                                 21u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                           0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                                 20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK                  0x80000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                       19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                      0x40000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                           18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                       0x20000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                            17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                            0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                                 16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                    0xff00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                         8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                     0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                        0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x1010u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x1010u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_RMSK                                                     0xfffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                       0xf00000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                             20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                        0xf0000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                             16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                        0xf000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                            12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                       0xf00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                           8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                             0xf0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                                4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_RETAINFF_BMSK                                             0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_CFG4_GDSCR_DLY_RETAINFF_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_ADDR                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x2000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_OFFS                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x2000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_RMSK                                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_BLK_ARES_BMSK                                                        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_BLK_ARES_SHFT                                                          0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_BLK_ARES_DISABLE_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_BCR_BLK_ARES_ENABLE_FVAL                                                 0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_ADDR                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x2004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_OFFS                                                 (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x2004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_RMSK                                                 0x81c00004ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_NON_GDSC_AHB_CBCR_CLK_ARES_RESET_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x2008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x2008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_VSYNC_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_ADDR                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x200cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_OFFS                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x200cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_RMSK                                                     0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                             24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_DIS_BMSK                                               0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_DIS_SHFT                                                     22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_ARES_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_ARES_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_ENABLE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_ENABLE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_RSCC_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_ADDR                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x3000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_OFFS                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x3000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_RMSK                                                               0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_CLK_DIV_BMSK                                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_DIV_CDIVR_CLK_DIV_SHFT                                                         0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_ADDR                                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x3004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_OFFS                                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x3004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_RMSK                                                             0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_OFF_BMSK                                                     0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_OFF_SHFT                                                             31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_IGNORE_ALL_ARES_BMSK                                              0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_IGNORE_ALL_ARES_SHFT                                                     24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                            0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                  23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_DIS_BMSK                                                       0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_DIS_SHFT                                                             22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_ARES_BMSK                                                           0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_ARES_SHFT                                                             2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_ARES_NO_RESET_FVAL                                                  0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_ARES_RESET_FVAL                                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_ENABLE_BMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_ENABLE_SHFT                                                           0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_ENABLE_DISABLE_FVAL                                                 0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_CBCR_CLK_ENABLE_ENABLE_FVAL                                                  0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_ADDR                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x300cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_OFFS                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x300cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_RMSK                                                            0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_CLK_DIV_BMSK                                                    0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_DIV_CDIVR_CLK_DIV_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_ADDR                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x3010u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_OFFS                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x3010u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_RMSK                                                          0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_OFF_BMSK                                                  0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_OFF_SHFT                                                          31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_IGNORE_ALL_ARES_SHFT                                                  24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_DIS_BMSK                                                    0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_DIS_SHFT                                                          22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_ARES_BMSK                                                        0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_ARES_SHFT                                                          2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_ARES_NO_RESET_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_ARES_RESET_FVAL                                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_ENABLE_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_ENABLE_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_ENABLE_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_CBCR_CLK_ENABLE_ENABLE_FVAL                                               0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_ADDR                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_OFFS                                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_RMSK                                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_BLK_ARES_BMSK                                                        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_BLK_ARES_SHFT                                                          0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_BLK_ARES_DISABLE_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_BCR_BLK_ARES_ENABLE_FVAL                                                 0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_ADDR                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x400cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_OFFS                                                     (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x400cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_RMSK                                                     0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_IGNORE_ALL_ARES_SHFT                                             24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_DIS_BMSK                                               0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_DIS_SHFT                                                     22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_ARES_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_ARES_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_ENABLE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_ENABLE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_ADDR                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4010u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_OFFS                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4010u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_RMSK                                               0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_OFF_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_OFF_SHFT                                               31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_IGNORE_ALL_ARES_BMSK                                0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_IGNORE_ALL_ARES_SHFT                                       24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                              0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                    23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_DIS_BMSK                                         0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_DIS_SHFT                                               22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_ARES_BMSK                                             0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_ARES_SHFT                                               2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_ARES_NO_RESET_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_ARES_RESET_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_ENABLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_ENABLE_SHFT                                             0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_ENABLE_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR_CLK_ENABLE_ENABLE_FVAL                                    0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_ADDR                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4014u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_OFFS                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4014u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_RMSK                                                0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_ADDR                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4018u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_OFFS                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4018u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_RMSK                                               0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_OFF_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_OFF_SHFT                                               31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_IGNORE_ALL_ARES_BMSK                                0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_IGNORE_ALL_ARES_SHFT                                       24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                              0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                    23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_DIS_BMSK                                         0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_DIS_SHFT                                               22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_ARES_BMSK                                             0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_ARES_SHFT                                               2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_ARES_NO_RESET_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_ARES_RESET_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_ENABLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_ENABLE_SHFT                                             0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_ENABLE_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR_CLK_ENABLE_ENABLE_FVAL                                    0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x401cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x401cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4020u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4020u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_RMSK                                                     0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_CLK_DIV_BMSK                                             0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR_CLK_DIV_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4024u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4024u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_RMSK                                                     0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_CLK_DIV_BMSK                                             0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR_CLK_DIV_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_ADDR                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4028u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_OFFS                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4028u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_RMSK                                                       0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_CLK_DIV_BMSK                                               0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR_CLK_DIV_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_ADDR                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x402cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_OFFS                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x402cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_RMSK                                                 0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_CLK_DIV_BMSK                                         0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR_CLK_DIV_SHFT                                           0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_ADDR                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4030u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_OFFS                                           (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4030u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_RMSK                                                  0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_CLK_DIV_BMSK                                          0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR_CLK_DIV_SHFT                                            0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_ADDR                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4034u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_OFFS                                          (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4034u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_RMSK                                                 0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_CLK_DIV_BMSK                                         0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR_CLK_DIV_SHFT                                           0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4038u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4038u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_RMSK                                                     0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_CLK_DIV_BMSK                                             0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR_CLK_DIV_SHFT                                               0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ADDR                                                            (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x403cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_OFFS                                                            (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x403cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_RMSK                                                            0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ROOT_OFF_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ROOT_OFF_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                                   0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                      4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ROOT_EN_BMSK                                                           0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ROOT_EN_SHFT                                                             1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_UPDATE_BMSK                                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_UPDATE_SHFT                                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_UPDATE_DISABLE_FVAL                                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CMD_RCGR_UPDATE_ENABLE_FVAL                                                     0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_ADDR                                                            (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4040u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_OFFS                                                            (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4040u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_RMSK                                                              0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_HW_CLK_CONTROL_BMSK                                               0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_HW_CLK_CONTROL_SHFT                                                     20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_RCGLITE_DISABLE_BMSK                                               0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_RCGLITE_DISABLE_SHFT                                                    16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_BMSK                                                         0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_SHFT                                                             8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                      0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                      0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                      0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                      0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                      0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                      0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_BMSK                                                          0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_SHFT                                                             0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                      0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                                    0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                      0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                                    0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                      0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                                    0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                      0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                                    0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                      0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                                    0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                      0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                                    0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                      0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                                    0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                      0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                                   0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV9_FVAL                                                     0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                                   0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV10_FVAL                                                    0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                                  0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV11_FVAL                                                    0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                                  0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV12_FVAL                                                    0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                                  0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV13_FVAL                                                    0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                                  0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV14_FVAL                                                    0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                                  0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV15_FVAL                                                    0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                                  0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CFG_RCGR_SRC_DIV_DIV16_FVAL                                                    0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_ADDR                                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4054u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_OFFS                                                                (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4054u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_RMSK                                                                0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_OFF_BMSK                                                        0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_OFF_SHFT                                                                31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_IGNORE_ALL_ARES_BMSK                                                 0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_IGNORE_ALL_ARES_SHFT                                                        24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                               0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                     23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_DIS_BMSK                                                          0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_DIS_SHFT                                                                22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_ARES_BMSK                                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_ARES_SHFT                                                                2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                                     0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_ARES_RESET_FVAL                                                        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_ENABLE_BMSK                                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_ENABLE_SHFT                                                              0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                                    0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                                     0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ADDR                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4058u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_OFFS                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4058u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_RMSK                                                         0x80000013ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ROOT_OFF_BMSK                                                0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ROOT_OFF_SHFT                                                        31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                                0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                   4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ROOT_EN_BMSK                                                        0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ROOT_EN_SHFT                                                          1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                                 0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_UPDATE_BMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_UPDATE_SHFT                                                           0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_UPDATE_DISABLE_FVAL                                                 0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CMD_RCGR_UPDATE_ENABLE_FVAL                                                  0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_ADDR                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x405cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_OFFS                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x405cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_RMSK                                                           0x11071ful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_BMSK                                            0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_SHFT                                                  20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_BMSK                                            0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_SHFT                                                 16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_BMSK                                                      0x700u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_SHFT                                                          8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                   0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                   0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                   0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                   0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_BMSK                                                       0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_SHFT                                                          0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                                 0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                                 0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                   0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                                 0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                   0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                                 0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                   0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                                 0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                   0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                                 0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                   0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                                 0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                   0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                                 0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                   0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                                0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV9_FVAL                                                  0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                                0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV10_FVAL                                                 0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                               0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV11_FVAL                                                 0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                               0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV12_FVAL                                                 0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                               0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV13_FVAL                                                 0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                               0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV14_FVAL                                                 0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                               0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV15_FVAL                                                 0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                               0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV16_FVAL                                                 0x1fu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_ADDR                                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x4070u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_OFFS                                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x4070u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_RMSK                                                             0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_OFF_BMSK                                                     0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_OFF_SHFT                                                             31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                                              0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                                     24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                            0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                  23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_DIS_BMSK                                                       0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_DIS_SHFT                                                             22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_ARES_BMSK                                                           0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_ARES_SHFT                                                             2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                                  0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_ENABLE_BMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_ENABLE_SHFT                                                           0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                                 0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                                  0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_ADDR                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x5000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_OFFS                                                   (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x5000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RMSK                                                   0xf8fffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_PWR_ON_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_PWR_ON_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_GDSC_STATE_BMSK                                        0x78000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_GDSC_STATE_SHFT                                                27u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_REST_WAIT_BMSK                                        0xf00000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_REST_WAIT_SHFT                                              20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_FEW_WAIT_BMSK                                          0xf0000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_FEW_WAIT_SHFT                                               16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLK_DIS_WAIT_BMSK                                          0xf000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLK_DIS_WAIT_SHFT                                              12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RETAIN_FF_ENABLE_BMSK                                       0x800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RETAIN_FF_ENABLE_SHFT                                          11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RESTORE_BMSK                                                0x400u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RESTORE_SHFT                                                   10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RESTORE_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RESTORE_ENABLE_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SAVE_BMSK                                                   0x200u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SAVE_SHFT                                                       9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SAVE_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SAVE_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RETAIN_BMSK                                                 0x100u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RETAIN_SHFT                                                     8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RETAIN_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_RETAIN_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_REST_BMSK                                                 0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_REST_SHFT                                                    7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_REST_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_REST_ENABLE_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_FEW_BMSK                                                  0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_FEW_SHFT                                                     6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_FEW_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_EN_FEW_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLAMP_IO_BMSK                                                0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLAMP_IO_SHFT                                                   5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLAMP_IO_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLAMP_IO_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLK_DISABLE_BMSK                                             0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLK_DISABLE_SHFT                                                4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_PD_ARES_BMSK                                                  0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_PD_ARES_SHFT                                                    3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_PD_ARES_NO_RESET_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_PD_ARES_RESET_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SW_OVERRIDE_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SW_OVERRIDE_SHFT                                                2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_HW_CONTROL_BMSK                                               0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_HW_CONTROL_SHFT                                                 1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_HW_CONTROL_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_HW_CONTROL_ENABLE_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SW_COLLAPSE_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SW_COLLAPSE_SHFT                                                0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_ADDR                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x5004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_OFFS                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x5004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_RMSK                                                0x3fffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                             0x2000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                    25u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                     24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                       0xf00000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                             20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                          0x80000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                               19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                              0x40000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                   18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                              0x20000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                   17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                           0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                          0x8000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                              15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                         0x7800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                             11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                 0x400u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                    10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                          0x200u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                              9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                          0x100u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                              8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                              0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                 7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                     0x60u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                        5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                               0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                  4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                         0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                           3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                       0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                         2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                           0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                             1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                        0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                          0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x5008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x5008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_RMSK                                                 0x7fffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                     0x40000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                          18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                 0x20000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                      17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                               0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                    16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                   0xf000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                       12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                            0xf00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                               0xf0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                  4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                 0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                   0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x500cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x500cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_RMSK                                               0x7fffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK             0x4000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                    26u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                          0x2000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                 25u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                     0x1e00000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                            21u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                      0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                            20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK             0x80000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                  19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL         0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL          0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                 0x40000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                      18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL             0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL              0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                  0x20000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                       17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL              0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL               0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                       0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                            16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                               0xff00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                    8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                   0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_ADDR                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x5010u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_OFFS                                              (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x5010u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_RMSK                                                0xfffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                  0xf00000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                        20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                   0xf0000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                        16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                   0xf000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                       12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                  0xf00u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                      8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                        0xf0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                           4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_RETAINFF_BMSK                                        0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_CORE_INT2_CFG4_GDSCR_DLY_RETAINFF_SHFT                                          0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_ADDR                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x6000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_OFFS                                             (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x6000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_RMSK                                             0x81c00005ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MDSS_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_ADDR                                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x7000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_OFFS                                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x7000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_RMSK                                                               0xfffffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_31_BMSK                                                        0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_31_SHFT                                                                31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_30_BMSK                                                        0x40000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_30_SHFT                                                                30u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_29_BMSK                                                        0x20000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_29_SHFT                                                                29u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_28_BMSK                                                        0x10000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_28_SHFT                                                                28u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_27_BMSK                                                         0x8000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_27_SHFT                                                                27u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_26_BMSK                                                         0x4000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_26_SHFT                                                                26u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_25_BMSK                                                         0x2000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_25_SHFT                                                                25u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_24_BMSK                                                         0x1000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_24_SHFT                                                                24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_23_BMSK                                                          0x800000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_23_SHFT                                                                23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_22_BMSK                                                          0x400000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_22_SHFT                                                                22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_21_BMSK                                                          0x200000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_21_SHFT                                                                21u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_20_BMSK                                                          0x100000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_20_SHFT                                                                20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_19_BMSK                                                           0x80000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_19_SHFT                                                                19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_18_BMSK                                                           0x40000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_18_SHFT                                                                18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_17_BMSK                                                           0x20000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_17_SHFT                                                                17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_16_BMSK                                                           0x10000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_16_SHFT                                                                16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_15_BMSK                                                            0x8000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_15_SHFT                                                                15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_14_BMSK                                                            0x4000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_14_SHFT                                                                14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_13_BMSK                                                            0x2000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_13_SHFT                                                                13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_12_BMSK                                                            0x1000u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_12_SHFT                                                                12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_11_BMSK                                                             0x800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_11_SHFT                                                                11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_10_BMSK                                                             0x400u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_10_SHFT                                                                10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_9_BMSK                                                              0x200u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_9_SHFT                                                                  9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_8_BMSK                                                              0x100u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_8_SHFT                                                                  8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_7_BMSK                                                               0x80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_7_SHFT                                                                  7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_6_BMSK                                                               0x40u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_6_SHFT                                                                  6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_5_BMSK                                                               0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_5_SHFT                                                                  5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_4_BMSK                                                               0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_4_SHFT                                                                  4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_3_BMSK                                                                0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_3_SHFT                                                                  3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_2_BMSK                                                                0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_2_SHFT                                                                  2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_1_BMSK                                                                0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_1_SHFT                                                                  1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_0_BMSK                                                                0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_CMD_BIT_0_SHFT                                                                  0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_STATUS_ADDR                                                            (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x7004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_STATUS_OFFS                                                            (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x7004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_STATUS_RMSK                                                            0xfffffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_STATUS_STATUS_BITS_BMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_MISC_STATUS_STATUS_BITS_SHFT                                                         0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_ADDR                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x8000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_OFFS                                               (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x8000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_RMSK                                                    0x804u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_RETAIN_FF_ENABLE_BMSK                                   0x800u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_RETAIN_FF_ENABLE_SHFT                                      11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_SW_OVERRIDE_BMSK                                          0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_TZ_MDSS_CORE_GDSC_SW_CTL_SW_OVERRIDE_SHFT                                            2u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_ADDR                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x9000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_OFFS                                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x9000u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_RMSK                                                               0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_BMSK                                                       0xffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_SHFT                                                          0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_CHIP_SLEEP_CLK_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DP0_PHY_PLL_LINK_CLK_FVAL                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DP0_PHY_PLL_VCO_DIV_CLK_FVAL                                0x3u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DSI0_PHY_PLL_OUT_DSICLK_FVAL                                0x4u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DSI0_PHY_PLL_OUT_BYTECLK_FVAL                               0x5u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DSI1_PHY_PLL_OUT_DSICLK_FVAL                                0x6u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DSI1_PHY_PLL_OUT_BYTECLK_FVAL                               0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DP1_PHY_PLL_LINK_CLK_FVAL                                   0x8u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DP1_PHY_PLL_VCO_DIV_CLK_FVAL                                0x9u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_PCLK0_CLK_FVAL                                 0xau
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_PCLK1_CLK_FVAL                                 0xbu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_MDP_CLK_FVAL                                   0xcu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_MDP1_CLK_FVAL                                  0xdu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_MDP_LUT_CLK_FVAL                               0xeu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_MDP_LUT1_CLK_FVAL                              0xfu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_VSYNC_CLK_FVAL                                0x10u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_VSYNC1_CLK_FVAL                               0x11u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_BYTE0_CLK_FVAL                                0x12u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_BYTE0_INTF_CLK_FVAL                           0x13u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_BYTE1_CLK_FVAL                                0x14u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_BYTE1_INTF_CLK_FVAL                           0x15u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_ESC0_CLK_FVAL                                 0x16u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_ESC1_CLK_FVAL                                 0x17u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX0_LINK_CLK_FVAL                           0x18u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX0_LINK_INTF_CLK_FVAL                      0x19u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX0_USB_ROUTER_LINK_INTF_CLK_FVAL           0x1au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX0_CRYPTO_CLK_FVAL                         0x1bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX0_AUX_CLK_FVAL                            0x1cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX0_PIXEL0_CLK_FVAL                         0x1du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX0_PIXEL1_CLK_FVAL                         0x1eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX1_PIXEL0_CLK_FVAL                         0x1fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX1_PIXEL1_CLK_FVAL                         0x20u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX1_LINK_CLK_FVAL                           0x21u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX1_LINK_INTF_CLK_FVAL                      0x22u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX1_USB_ROUTER_LINK_INTF_CLK_FVAL           0x23u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX1_CRYPTO_CLK_FVAL                         0x24u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX1_AUX_CLK_FVAL                            0x25u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_AHB_CLK_FVAL                                  0x26u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_AHB1_CLK_FVAL                                 0x27u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX0_PIXEL2_CLK_FVAL                         0x28u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_DPTX0_PIXEL3_CLK_FVAL                         0x29u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_NON_GDSC_AHB_CLK_FVAL                         0x2au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_RSCC_VSYNC_CLK_FVAL                           0x2bu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_RSCC_AHB_CLK_FVAL                             0x2cu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_PLL_LOCK_MONITOR_CLK_FVAL                     0x2du
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_SPDM_PCLK0_CLK_FVAL                           0x2eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_SPDM_PCLK1_CLK_FVAL                           0x2fu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_SPDM_MDP_CLK_FVAL                             0x30u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_SPDM_DP_CRYPTO_CLK_FVAL                       0x31u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_SPDM_DP_PIXEL_CLK_FVAL                        0x32u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_MDSS_SPDM_DP_PIXEL1_CLK_FVAL                       0x33u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_XO_CLK_FVAL                                        0x34u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_DISP_CC_SLEEP_CLK_FVAL                                     0x35u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_PHY_DEBUG0_CLK_FVAL                                        0x36u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_PHY_DEBUG1_CLK_FVAL                                        0x37u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_PHY_DEBUG2_CLK_FVAL                                        0x38u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_PHY_DEBUG3_CLK_FVAL                                        0x39u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_PHY_DEBUG4_CLK_FVAL                                        0x3au
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_DEBUG_MUX_MUXR_MUX_SEL_PHY_DEBUG5_CLK_FVAL                                        0x3bu

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_ADDR                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x9004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_OFFS                                                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x9004u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_RMSK                                                             0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_MUX_SEL_BMSK                                                     0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_MUX_SEL_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_MUX_SEL_DISP_CC_PLL0_TEST_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_TEST_MUX_MUXR_MUX_SEL_DISP_CC_PLL1_TEST_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_ADDR                                                       (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x9008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_OFFS                                                       (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x9008u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_RMSK                                                              0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_MUX_SEL_BMSK                                                      0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_MUX_SEL_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_MUX_SEL_DISP_CC_PLL0_RESET_N_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_RESET_N_MUXR_MUX_SEL_DISP_CC_PLL1_RESET_N_FVAL                                 0x1u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_ADDR                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x900cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_OFFS                                                        (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x900cu)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_RMSK                                                               0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_IN)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_MUX_SEL_BMSK                                                       0x7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_MUX_SEL_SHFT                                                         0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_MUX_SEL_DEFAULT_ZERO_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_MUX_SEL_DISP_CC_PLL0_STATUS_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_MUX_SEL_DISP_CC_PLL1_STATUS_FVAL                                   0x2u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_PLL_STATUS_MUXR_MUX_SEL_DISP_CC_PLL_LOCK_DET_STATUS_FVAL                           0x3u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR_ADDR                                                            (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0x9014u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR_OFFS                                                            (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0x9014u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR_RMSK                                                            0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR_CLK_OFF_BMSK                                                    0x80000000ul
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_SM_OBS_CBCR_CLK_OFF_SHFT                                                            31u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_ADDR                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xa410u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_OFFS                                         (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xa410u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_RMSK                                             0x1fffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_HPCNT_BMSK                                       0x1f80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_HPCNT_SHFT                                            7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_VPCNT_BMSK                                         0x7eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_VPCNT_SHFT                                            1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_FLT_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_RESET_FLT_SHFT                                              0u

#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_ADDR                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE      + 0xa414u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_OFFS                      (SAIL_TO_MD_MDSS_1_DISP_CC_DISP_CC_DISP_CC_REG_REG_BASE_OFFS + 0xa414u)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_RMSK                          0x1fffu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_IN                    \
                in_dword(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_ADDR)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_ADDR, m)
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_HPCNT_BMSK                    0x1f80u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_HPCNT_SHFT                         7u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_VPCNT_BMSK                      0x7eu
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_VPCNT_SHFT                         1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_FLT_BMSK                         0x1u
#define HWIO_SAIL_TO_MD_MDSS_1_DISP_CC_FUSA_STATUS_REGISTER_CLK_DISP_CC_MDSS_ACCESS_ARES_FLT_SHFT                           0u


#endif /* __G_SAIL_TO_MD_MDSS_1_DISP_CC_H__ */
