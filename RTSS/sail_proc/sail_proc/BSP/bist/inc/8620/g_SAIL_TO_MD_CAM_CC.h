#ifndef G_SAIL_TO_MD_CAM_CC_H
#define G_SAIL_TO_MD_CAM_CC_H
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_CAM_CC.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        MonacoAU [monacoau_v1.0_p3q3r53_MTO_rpm]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_CAM_CC.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG'],
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
 * MODULE: SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE                                                  (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x0adf0000UL)
#define SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_SIZE                                             0x10000UL
#define SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_USED                                             0x6218U
#define SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS                                             0x0adf0000UL

#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_ADDR                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x0U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_OFFS                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x0U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_RMSK                                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_BLK_ARES_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_BLK_ARES_SHFT                                                         0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_BLK_ARES_DISABLE_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_0_BCR_BLK_ARES_ENABLE_FVAL                                                0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x4U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x4U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_RMSK                                                      0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ROOT_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ROOT_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                             0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ROOT_EN_BMSK                                                     0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ROOT_EN_SHFT                                                       1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_UPDATE_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_UPDATE_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_UPDATE_DISABLE_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CMD_RCGR_UPDATE_ENABLE_FVAL                                               0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x8U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x8U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_RMSK                                                        0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_HW_CLK_CONTROL_BMSK                                         0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_HW_CLK_CONTROL_SHFT                                               20U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_RCGLITE_DISABLE_BMSK                                         0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_RCGLITE_DISABLE_SHFT                                              16U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_BMSK                                                   0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_SHFT                                                       8U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_BMSK                                                    0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_SHFT                                                       0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                              0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                              0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                              0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                              0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                             0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV9_FVAL                                               0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                             0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV10_FVAL                                              0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                            0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV11_FVAL                                              0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                            0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV12_FVAL                                              0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                            0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV13_FVAL                                              0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                            0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV14_FVAL                                              0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                            0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV15_FVAL                                              0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                            0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CFG_RCGR_SRC_DIV_DIV16_FVAL                                              0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_ADDR                                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_OFFS                                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_RMSK                                                          0x81c07ff5UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_OFF_BMSK                                                  0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_OFF_SHFT                                                          31U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_IGNORE_ALL_ARES_SHFT                                                  24U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_DIS_BMSK                                                    0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_DIS_SHFT                                                          22U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_CORE_ON_BMSK                                            0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_CORE_ON_SHFT                                                14U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                          0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                              13U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                         0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                             12U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_BMSK                                                        0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_SHFT                                                            8U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK0_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK1_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK2_FVAL                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK3_FVAL                                                   0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK4_FVAL                                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK5_FVAL                                                   0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK6_FVAL                                                   0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK7_FVAL                                                   0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK8_FVAL                                                   0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK9_FVAL                                                   0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK10_FVAL                                                  0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK11_FVAL                                                  0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK12_FVAL                                                  0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK13_FVAL                                                  0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK14_FVAL                                                  0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_WAKEUP_CLOCK15_FVAL                                                  0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_BMSK                                                          0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_SHFT                                                             4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK0_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK1_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK2_FVAL                                                    0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK3_FVAL                                                    0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK4_FVAL                                                    0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK5_FVAL                                                    0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK6_FVAL                                                    0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK7_FVAL                                                    0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK8_FVAL                                                    0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK9_FVAL                                                    0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK10_FVAL                                                   0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK11_FVAL                                                   0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK12_FVAL                                                   0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK13_FVAL                                                   0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK14_FVAL                                                   0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_SLEEP_CLOCK15_FVAL                                                   0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_ARES_BMSK                                                        0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_ARES_SHFT                                                          2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_ARES_NO_RESET_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_ARES_RESET_FVAL                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_ENABLE_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_ENABLE_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_ENABLE_DISABLE_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_CBCR_CLK_ENABLE_ENABLE_FVAL                                               0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_ADDR                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x20U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_OFFS                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x20U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_RMSK                                                         0xfffffffeUL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                               0xff000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                       24U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                  0xff0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                        16U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                     0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                         15U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                      0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                          14U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                     0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                         13U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                                 0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                     12U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CORE_ON_ACK_BMSK                                              0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CORE_ON_ACK_SHFT                                                 11U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_PERIPH_ON_ACK_BMSK                                            0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_PERIPH_ON_ACK_SHFT                                               10U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                     0x300U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                         8U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CPH_ENABLE_BMSK                                                0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CPH_ENABLE_SHFT                                                   7U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_FORCE_CLK_ON_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_FORCE_CLK_ON_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_RST_SEL_SLP_STG_BMSK                                            0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_RST_SEL_SLP_STG_SHFT                                               5U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_RST_SLP_STG_BMSK                                                0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_RST_SLP_STG_SHFT                                                   4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CTRL_PWR_DOWN_BMSK                                               0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CTRL_PWR_DOWN_SHFT                                                 3U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                          0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                            2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CLK_EN_SLP_STG_BMSK                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CLK_EN_SLP_STG_SHFT                                                1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                         0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_ADDR                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x24U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_OFFS                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x24U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_RMSK                                                     0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IPE_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_ADDR                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x28U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_OFFS                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x28U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_RMSK                                                       0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_CLK_DIV_BMSK                                               0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_DIV_CDIVR_CLK_DIV_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_ADDR                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x2cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_OFFS                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x2cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_RMSK                                                     0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_SPDM_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_RMSK                                                      0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_OFF_BMSK                                              0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_OFF_SHFT                                                      31U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                              24U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_DIS_BMSK                                                0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_DIS_SHFT                                                      22U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_ARES_BMSK                                                    0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_ARES_SHFT                                                      2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_ARES_RESET_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_ENABLE_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_ENABLE_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x34U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x34U)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_RMSK                                                 0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_OFF_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_OFF_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                         24U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_DIS_BMSK                                           0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_DIS_SHFT                                                 22U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_ARES_BMSK                                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_ARES_SHFT                                                 2U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_ARES_RESET_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_ENABLE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_ENABLE_SHFT                                               0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IPE_FAST_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_ADDR                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1000U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_OFFS                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1000U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_RMSK                                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_BLK_ARES_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_BLK_ARES_SHFT                                                         0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_BLK_ARES_DISABLE_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_BCR_BLK_ARES_ENABLE_FVAL                                                0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1004U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1004U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_RMSK                                                    0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ROOT_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ROOT_EN_BMSK                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ROOT_EN_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_UPDATE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_UPDATE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1008U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1008U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_RMSK                                                      0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_RCGLITE_DISABLE_BMSK                                       0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_RCGLITE_DISABLE_SHFT                                            16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_BMSK                                                 0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x101cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x101cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_RMSK                                                        0x81c07ff5UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_CORE_ON_BMSK                                          0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_CORE_ON_SHFT                                              14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                        0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                            13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                       0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                           12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_BMSK                                                      0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_SHFT                                                          8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK0_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK1_FVAL                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK2_FVAL                                                 0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK3_FVAL                                                 0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK4_FVAL                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK5_FVAL                                                 0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK6_FVAL                                                 0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK7_FVAL                                                 0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK8_FVAL                                                 0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK9_FVAL                                                 0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK10_FVAL                                                0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK11_FVAL                                                0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK12_FVAL                                                0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK13_FVAL                                                0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK14_FVAL                                                0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_WAKEUP_CLOCK15_FVAL                                                0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_BMSK                                                        0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_SHFT                                                           4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK0_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK1_FVAL                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK2_FVAL                                                  0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK3_FVAL                                                  0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK4_FVAL                                                  0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK5_FVAL                                                  0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK6_FVAL                                                  0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK7_FVAL                                                  0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK8_FVAL                                                  0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK9_FVAL                                                  0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK10_FVAL                                                 0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK11_FVAL                                                 0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK12_FVAL                                                 0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK13_FVAL                                                 0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK14_FVAL                                                 0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_SLEEP_CLOCK15_FVAL                                                 0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_ADDR                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1020U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_OFFS                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1020U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_RMSK                                                       0xfffffffeUL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                             0xff000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                     24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                0xff0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                      16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                   0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                       15U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                    0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                        14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                   0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                       13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                               0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                   12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CORE_ON_ACK_BMSK                                            0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CORE_ON_ACK_SHFT                                               11U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_PERIPH_ON_ACK_BMSK                                          0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_PERIPH_ON_ACK_SHFT                                             10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                   0x300U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                       8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                            0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CPH_ENABLE_BMSK                                              0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CPH_ENABLE_SHFT                                                 7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_FORCE_CLK_ON_BMSK                                                0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_FORCE_CLK_ON_SHFT                                                   6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_RST_SEL_SLP_STG_BMSK                                          0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_RST_SEL_SLP_STG_SHFT                                             5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_RST_SLP_STG_BMSK                                              0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_RST_SLP_STG_SHFT                                                 4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CTRL_PWR_DOWN_BMSK                                             0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CTRL_PWR_DOWN_SHFT                                               3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                        0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                          2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CLK_EN_SLP_STG_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CLK_EN_SLP_STG_SHFT                                              1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                       0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1024U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1024U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_RMSK                                                   0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_IGNORE_ALL_ARES_SHFT                                           24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_DIS_BMSK                                             0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_DIS_SHFT                                                   22U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_ARES_BMSK                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_ARES_SHFT                                                   2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_ARES_RESET_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_ENABLE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_ENABLE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_0_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1028U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1028U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_RMSK                                                     0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_CLK_DIV_BMSK                                             0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_DIV_CDIVR_CLK_DIV_SHFT                                               0U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x102cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x102cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_RMSK                                                   0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_IGNORE_ALL_ARES_SHFT                                           24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_DIS_BMSK                                             0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_DIS_SHFT                                                   22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_ARES_BMSK                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_ARES_SHFT                                                   2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_ARES_RESET_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_ENABLE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_ENABLE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_SPDM_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1030U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1030U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_RMSK                                               0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_OFF_BMSK                                       0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_OFF_SHFT                                               31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                       24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                              0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                    23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_DIS_BMSK                                         0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_DIS_SHFT                                               22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_ARES_BMSK                                             0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_ARES_SHFT                                               2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_ARES_RESET_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_ENABLE_BMSK                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_ENABLE_SHFT                                             0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_0_FAST_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                    0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ADDR                                                  (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1034U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_OFFS                                                  (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1034U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_RMSK                                                  0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ROOT_OFF_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ROOT_OFF_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                         0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                            4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ROOT_EN_BMSK                                                 0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ROOT_EN_SHFT                                                   1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_UPDATE_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_UPDATE_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_UPDATE_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CMD_RCGR_UPDATE_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_ADDR                                                  (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x1038U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_OFFS                                                  (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x1038U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_RMSK                                                    0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_HW_CLK_CONTROL_BMSK                                     0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_HW_CLK_CONTROL_SHFT                                           20U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_RCGLITE_DISABLE_BMSK                                     0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_RCGLITE_DISABLE_SHFT                                          16U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_BMSK                                               0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_SHFT                                                   8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_SRC0_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_SRC1_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_SRC2_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_SRC3_FVAL                                            0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_SRC4_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_SRC5_FVAL                                            0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_SRC6_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_SEL_SRC7_FVAL                                            0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_BMSK                                                0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV1_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                          0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV2_FVAL                                            0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                          0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV3_FVAL                                            0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                          0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV4_FVAL                                            0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                          0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV5_FVAL                                            0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                          0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV6_FVAL                                            0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                          0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV7_FVAL                                            0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                          0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV8_FVAL                                            0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                         0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV9_FVAL                                           0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                         0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV10_FVAL                                          0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                        0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV11_FVAL                                          0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                        0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV12_FVAL                                          0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                        0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV13_FVAL                                          0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                        0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV14_FVAL                                          0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                        0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV15_FVAL                                          0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                        0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_CPHY_RX_CFG_RCGR_SRC_DIV_DIV16_FVAL                                          0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_ADDR                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x2000U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_OFFS                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x2000U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_RMSK                                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_BLK_ARES_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_BLK_ARES_SHFT                                                         0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_BLK_ARES_DISABLE_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_BCR_BLK_ARES_ENABLE_FVAL                                                0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x2004U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x2004U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_RMSK                                                    0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ROOT_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ROOT_EN_BMSK                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ROOT_EN_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_UPDATE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_UPDATE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x2008U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x2008U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_RMSK                                                      0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_RCGLITE_DISABLE_BMSK                                       0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_RCGLITE_DISABLE_SHFT                                            16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_BMSK                                                 0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x201cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x201cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_RMSK                                                        0x81c07ff5UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_CORE_ON_BMSK                                          0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_CORE_ON_SHFT                                              14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                        0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                            13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                       0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                           12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_BMSK                                                      0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_SHFT                                                          8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK0_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK1_FVAL                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK2_FVAL                                                 0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK3_FVAL                                                 0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK4_FVAL                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK5_FVAL                                                 0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK6_FVAL                                                 0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK7_FVAL                                                 0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK8_FVAL                                                 0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK9_FVAL                                                 0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK10_FVAL                                                0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK11_FVAL                                                0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK12_FVAL                                                0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK13_FVAL                                                0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK14_FVAL                                                0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_WAKEUP_CLOCK15_FVAL                                                0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_BMSK                                                        0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_SHFT                                                           4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK0_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK1_FVAL                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK2_FVAL                                                  0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK3_FVAL                                                  0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK4_FVAL                                                  0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK5_FVAL                                                  0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK6_FVAL                                                  0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK7_FVAL                                                  0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK8_FVAL                                                  0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK9_FVAL                                                  0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK10_FVAL                                                 0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK11_FVAL                                                 0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK12_FVAL                                                 0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK13_FVAL                                                 0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK14_FVAL                                                 0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_SLEEP_CLOCK15_FVAL                                                 0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_ADDR                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x2020U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_OFFS                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x2020U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_RMSK                                                       0xfffffffeUL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                             0xff000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                     24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                0xff0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                      16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                   0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                       15U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                    0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                        14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                   0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                       13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                               0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                   12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CORE_ON_ACK_BMSK                                            0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CORE_ON_ACK_SHFT                                               11U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_PERIPH_ON_ACK_BMSK                                          0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_PERIPH_ON_ACK_SHFT                                             10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                   0x300U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                       8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                            0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CPH_ENABLE_BMSK                                              0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CPH_ENABLE_SHFT                                                 7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_FORCE_CLK_ON_BMSK                                                0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_FORCE_CLK_ON_SHFT                                                   6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_RST_SEL_SLP_STG_BMSK                                          0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_RST_SEL_SLP_STG_SHFT                                             5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_RST_SLP_STG_BMSK                                              0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_RST_SLP_STG_SHFT                                                 4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CTRL_PWR_DOWN_BMSK                                             0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CTRL_PWR_DOWN_SHFT                                               3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                        0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                          2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CLK_EN_SLP_STG_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CLK_EN_SLP_STG_SHFT                                              1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                       0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x2024U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x2024U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_RMSK                                                   0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_IGNORE_ALL_ARES_SHFT                                           24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_DIS_BMSK                                             0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_DIS_SHFT                                                   22U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_ARES_BMSK                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_ARES_SHFT                                                   2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_ARES_RESET_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_ENABLE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_ENABLE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_1_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x2028U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x2028U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_RMSK                                                     0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_CLK_DIV_BMSK                                             0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_DIV_CDIVR_CLK_DIV_SHFT                                               0U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x202cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x202cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_RMSK                                                   0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_IGNORE_ALL_ARES_SHFT                                           24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_DIS_BMSK                                             0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_DIS_SHFT                                                   22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_ARES_BMSK                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_ARES_SHFT                                                   2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_ARES_RESET_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_ENABLE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_ENABLE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_SPDM_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x2030U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x2030U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_RMSK                                               0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_OFF_BMSK                                       0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_OFF_SHFT                                               31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                       24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                              0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                    23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_DIS_BMSK                                         0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_DIS_SHFT                                               22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_ARES_BMSK                                             0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_ARES_SHFT                                               2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_ARES_RESET_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_ENABLE_BMSK                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_ENABLE_SHFT                                             0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_1_FAST_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                    0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3000U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3000U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_RMSK                                                 0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ROOT_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ROOT_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                        0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                           4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ROOT_EN_BMSK                                                0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ROOT_EN_SHFT                                                  1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_UPDATE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_UPDATE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_UPDATE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CMD_RCGR_UPDATE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3004U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3004U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_RMSK                                                   0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_HW_CLK_CONTROL_BMSK                                    0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_HW_CLK_CONTROL_SHFT                                          20U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_RCGLITE_DISABLE_BMSK                                    0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_RCGLITE_DISABLE_SHFT                                         16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_BMSK                                              0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_SHFT                                                  8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_SRC0_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_SRC1_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_SRC2_FVAL                                           0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_SRC3_FVAL                                           0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_SRC4_FVAL                                           0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_SRC5_FVAL                                           0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_SRC6_FVAL                                           0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_SEL_SRC7_FVAL                                           0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_BMSK                                               0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_SHFT                                                  0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV1_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV2_FVAL                                           0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                         0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV3_FVAL                                           0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                         0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV4_FVAL                                           0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                         0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV5_FVAL                                           0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                         0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV6_FVAL                                           0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                         0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV7_FVAL                                           0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                         0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV8_FVAL                                           0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                        0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV9_FVAL                                          0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                        0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV10_FVAL                                         0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                       0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV11_FVAL                                         0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                       0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV12_FVAL                                         0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                       0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV13_FVAL                                         0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                       0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV14_FVAL                                         0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                       0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV15_FVAL                                         0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                       0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CFG_RCGR_SRC_DIV_DIV16_FVAL                                         0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_ADDR                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3018U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_OFFS                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3018U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_RMSK                                                     0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_ADDR                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x301cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_OFFS                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x301cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_RMSK                                                0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_IGNORE_ALL_ARES_SHFT                                        24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_DIS_BMSK                                          0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_DIS_SHFT                                                22U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_ARES_BMSK                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_ARES_SHFT                                                2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_ARES_RESET_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_ENABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_ENABLE_SHFT                                              0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_IFE_LITE_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ADDR                                            (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3020U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_OFFS                                            (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3020U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_RMSK                                            0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ROOT_OFF_BMSK                                   0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ROOT_OFF_SHFT                                           31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                   0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                      4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ROOT_EN_BMSK                                           0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ROOT_EN_SHFT                                             1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_UPDATE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_UPDATE_SHFT                                              0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_UPDATE_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CMD_RCGR_UPDATE_ENABLE_FVAL                                     0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_ADDR                                            (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3024U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_OFFS                                            (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3024U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_RMSK                                              0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_HW_CLK_CONTROL_BMSK                               0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_HW_CLK_CONTROL_SHFT                                     20U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_RCGLITE_DISABLE_BMSK                               0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_RCGLITE_DISABLE_SHFT                                    16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_BMSK                                         0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_SHFT                                             8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_SRC0_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_SRC1_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_SRC2_FVAL                                      0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_SRC3_FVAL                                      0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_SRC4_FVAL                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_SRC5_FVAL                                      0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_SRC6_FVAL                                      0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_SEL_SRC7_FVAL                                      0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_BMSK                                          0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_SHFT                                             0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV1_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                    0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV2_FVAL                                      0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                    0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV3_FVAL                                      0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                    0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV4_FVAL                                      0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                    0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV5_FVAL                                      0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                    0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV6_FVAL                                      0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                    0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV7_FVAL                                      0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                    0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV8_FVAL                                      0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                   0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV9_FVAL                                     0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                   0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV10_FVAL                                    0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                  0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV11_FVAL                                    0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                  0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV12_FVAL                                    0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                  0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV13_FVAL                                    0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                  0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV14_FVAL                                    0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                  0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV15_FVAL                                    0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                  0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CFG_RCGR_SRC_DIV_DIV16_FVAL                                    0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_ADDR                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3038U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_OFFS                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3038U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_RMSK                                                0x81c07ff5UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_IGNORE_ALL_ARES_SHFT                                        24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_DIS_BMSK                                          0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_DIS_SHFT                                                22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_CORE_ON_BMSK                                  0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_CORE_ON_SHFT                                      14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                    13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                               0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                   12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_BMSK                                              0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_SHFT                                                  8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK0_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK1_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK2_FVAL                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK3_FVAL                                         0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK4_FVAL                                         0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK5_FVAL                                         0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK6_FVAL                                         0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK7_FVAL                                         0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK8_FVAL                                         0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK9_FVAL                                         0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK10_FVAL                                        0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK11_FVAL                                        0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK12_FVAL                                        0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK13_FVAL                                        0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK14_FVAL                                        0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_WAKEUP_CLOCK15_FVAL                                        0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_BMSK                                                0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_SHFT                                                   4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK0_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK1_FVAL                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK2_FVAL                                          0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK3_FVAL                                          0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK4_FVAL                                          0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK5_FVAL                                          0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK6_FVAL                                          0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK7_FVAL                                          0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK8_FVAL                                          0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK9_FVAL                                          0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK10_FVAL                                         0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK11_FVAL                                         0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK12_FVAL                                         0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK13_FVAL                                         0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK14_FVAL                                         0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_SLEEP_CLOCK15_FVAL                                         0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_ARES_BMSK                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_ARES_SHFT                                                2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_ARES_RESET_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_ENABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_ENABLE_SHFT                                              0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x303cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x303cU)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_RMSK                                               0xfffffffeUL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                     0xff000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                             24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                        0xff0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                              16U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                           0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                               15U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                            0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                14U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                           0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                               13U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                       0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                           12U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CORE_ON_ACK_BMSK                                    0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CORE_ON_ACK_SHFT                                       11U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_PERIPH_ON_ACK_BMSK                                  0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_PERIPH_ON_ACK_SHFT                                     10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                           0x300U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                               8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                    0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                    0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CPH_ENABLE_BMSK                                      0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CPH_ENABLE_SHFT                                         7U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_FORCE_CLK_ON_BMSK                                        0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_FORCE_CLK_ON_SHFT                                           6U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_RST_SEL_SLP_STG_BMSK                                  0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_RST_SEL_SLP_STG_SHFT                                     5U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_RST_SLP_STG_BMSK                                      0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_RST_SLP_STG_SHFT                                         4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CTRL_PWR_DOWN_BMSK                                     0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CTRL_PWR_DOWN_SHFT                                       3U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                  2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CLK_EN_SLP_STG_BMSK                                    0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CLK_EN_SLP_STG_SHFT                                      1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CSID_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL               0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_ADDR                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3040U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_OFFS                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3040U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_RMSK                                             0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_OFF_BMSK                                     0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_OFF_SHFT                                             31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_IGNORE_ALL_ARES_SHFT                                     24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_DIS_BMSK                                       0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_DIS_SHFT                                             22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_ARES_BMSK                                           0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_ARES_SHFT                                             2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_ARES_RESET_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_ENABLE_BMSK                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_ENABLE_SHFT                                           0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_CPHY_RX_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3044U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3044U)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_RMSK                                                 0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_OFF_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_OFF_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                         24U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_DIS_BMSK                                           0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_DIS_SHFT                                                 22U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_ARES_BMSK                                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_ARES_SHFT                                                 2U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_ARES_RESET_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_ENABLE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_ENABLE_SHFT                                               0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_IFE_LITE_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3048U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3048U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_RMSK                                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_BLK_ARES_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_BLK_ARES_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_BLK_ARES_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_BCR_BLK_ARES_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x304cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x304cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_RMSK                                                   0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_IGNORE_ALL_ARES_SHFT                                           24U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_DIS_BMSK                                             0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_DIS_SHFT                                                   22U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_ARES_BMSK                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_ARES_SHFT                                                   2U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_ARES_RESET_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_ENABLE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_ENABLE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3050U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3050U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_RMSK                                              0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_OFF_BMSK                                      0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_OFF_SHFT                                              31U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_IGNORE_ALL_ARES_SHFT                                      24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_DIS_BMSK                                        0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_DIS_SHFT                                              22U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_ARES_BMSK                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_ARES_SHFT                                              2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_ARES_RESET_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_ENABLE_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_ENABLE_SHFT                                            0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_0_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_ADDR                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3054U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_OFFS                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3054U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_RMSK                                                0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_CLK_DIV_BMSK                                        0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_DIV_CDIVR_CLK_DIV_SHFT                                          0U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3058U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3058U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_RMSK                                              0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_OFF_BMSK                                      0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_OFF_SHFT                                              31U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_IGNORE_ALL_ARES_SHFT                                      24U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_DIS_BMSK                                        0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_DIS_SHFT                                              22U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_ARES_BMSK                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_ARES_SHFT                                              2U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_ARES_RESET_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_ENABLE_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_ENABLE_SHFT                                            0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_SPDM_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_ADDR                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x305cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_OFFS                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x305cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_RMSK                                          0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_OFF_BMSK                                  0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_OFF_SHFT                                          31U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_IGNORE_ALL_ARES_BMSK                           0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                  24U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                         0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                               23U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_DIS_BMSK                                    0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_DIS_SHFT                                          22U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_ARES_BMSK                                        0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_ARES_SHFT                                          2U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_ARES_RESET_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_ENABLE_BMSK                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_ENABLE_SHFT                                        0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_0_FAST_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                               0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3060U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3060U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_RMSK                                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_BLK_ARES_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_BLK_ARES_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_BLK_ARES_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_BCR_BLK_ARES_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3064U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3064U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_RMSK                                                   0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_IGNORE_ALL_ARES_SHFT                                           24U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_DIS_BMSK                                             0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_DIS_SHFT                                                   22U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_ARES_BMSK                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_ARES_SHFT                                                   2U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_ARES_RESET_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_ENABLE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_ENABLE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3068U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3068U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_RMSK                                              0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_OFF_BMSK                                      0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_OFF_SHFT                                              31U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_IGNORE_ALL_ARES_SHFT                                      24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_DIS_BMSK                                        0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_DIS_SHFT                                              22U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_ARES_BMSK                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_ARES_SHFT                                              2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_ARES_RESET_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_ENABLE_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_ENABLE_SHFT                                            0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_SFE_LITE_1_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_ADDR                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x306cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_OFFS                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x306cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_RMSK                                                0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_CLK_DIV_BMSK                                        0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_DIV_CDIVR_CLK_DIV_SHFT                                          0U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3070U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3070U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_RMSK                                              0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_OFF_BMSK                                      0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_OFF_SHFT                                              31U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_IGNORE_ALL_ARES_SHFT                                      24U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_DIS_BMSK                                        0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_DIS_SHFT                                              22U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_ARES_BMSK                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_ARES_SHFT                                              2U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_ARES_RESET_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_ENABLE_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_ENABLE_SHFT                                            0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_SPDM_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_ADDR                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3074U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_OFFS                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3074U)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_RMSK                                          0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_OFF_BMSK                                  0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_OFF_SHFT                                          31U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_IGNORE_ALL_ARES_BMSK                           0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                  24U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                         0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                               23U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_DIS_BMSK                                    0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_DIS_SHFT                                          22U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_ARES_BMSK                                        0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_ARES_SHFT                                          2U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_ARES_RESET_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_ENABLE_BMSK                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_ENABLE_SHFT                                        0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SFE_LITE_1_FAST_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                               0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3078U)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3078U)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_RMSK                                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_BLK_ARES_BMSK                                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_BLK_ARES_SHFT                                                           0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_BLK_ARES_DISABLE_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_BCR_BLK_ARES_ENABLE_FVAL                                                  0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x307cU)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x307cU)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_RMSK                                                      0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ROOT_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ROOT_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                             0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ROOT_EN_BMSK                                                     0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ROOT_EN_SHFT                                                       1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_UPDATE_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_UPDATE_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_UPDATE_DISABLE_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CMD_RCGR_UPDATE_ENABLE_FVAL                                               0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3080U)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3080U)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_RMSK                                                        0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_HW_CLK_CONTROL_BMSK                                         0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_HW_CLK_CONTROL_SHFT                                               20U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_RCGLITE_DISABLE_BMSK                                         0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_RCGLITE_DISABLE_SHFT                                              16U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_BMSK                                                   0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_SHFT                                                       8U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_BMSK                                                    0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_SHFT                                                       0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                              0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                              0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                              0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                              0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                             0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV9_FVAL                                               0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                             0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV10_FVAL                                              0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                            0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV11_FVAL                                              0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                            0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV12_FVAL                                              0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                            0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV13_FVAL                                              0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                            0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV14_FVAL                                              0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                            0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV15_FVAL                                              0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                            0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CFG_RCGR_SRC_DIV_DIV16_FVAL                                              0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_ADDR                                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3094U)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_OFFS                                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3094U)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_RMSK                                                          0x81c07ff5UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_OFF_BMSK                                                  0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_OFF_SHFT                                                          31U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_IGNORE_ALL_ARES_SHFT                                                  24U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_DIS_BMSK                                                    0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_DIS_SHFT                                                          22U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_CORE_ON_BMSK                                            0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_CORE_ON_SHFT                                                14U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                          0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                              13U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                         0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                             12U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_BMSK                                                        0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_SHFT                                                            8U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK0_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK1_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK2_FVAL                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK3_FVAL                                                   0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK4_FVAL                                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK5_FVAL                                                   0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK6_FVAL                                                   0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK7_FVAL                                                   0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK8_FVAL                                                   0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK9_FVAL                                                   0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK10_FVAL                                                  0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK11_FVAL                                                  0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK12_FVAL                                                  0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK13_FVAL                                                  0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK14_FVAL                                                  0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_WAKEUP_CLOCK15_FVAL                                                  0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_BMSK                                                          0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_SHFT                                                             4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK0_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK1_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK2_FVAL                                                    0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK3_FVAL                                                    0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK4_FVAL                                                    0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK5_FVAL                                                    0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK6_FVAL                                                    0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK7_FVAL                                                    0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK8_FVAL                                                    0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK9_FVAL                                                    0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK10_FVAL                                                   0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK11_FVAL                                                   0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK12_FVAL                                                   0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK13_FVAL                                                   0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK14_FVAL                                                   0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_SLEEP_CLOCK15_FVAL                                                   0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_ARES_BMSK                                                        0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_ARES_SHFT                                                          2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_ARES_NO_RESET_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_ARES_RESET_FVAL                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_ENABLE_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_ENABLE_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_ENABLE_DISABLE_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_CBCR_CLK_ENABLE_ENABLE_FVAL                                               0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_ADDR                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3098U)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_OFFS                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3098U)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_RMSK                                                         0xfffffffeUL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                               0xff000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                       24U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                  0xff0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                        16U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                     0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                         15U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                      0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                          14U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                     0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                         13U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                                 0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                     12U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CORE_ON_ACK_BMSK                                              0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CORE_ON_ACK_SHFT                                                 11U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_PERIPH_ON_ACK_BMSK                                            0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_PERIPH_ON_ACK_SHFT                                               10U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                     0x300U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                         8U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CPH_ENABLE_BMSK                                                0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CPH_ENABLE_SHFT                                                   7U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_FORCE_CLK_ON_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_FORCE_CLK_ON_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_RST_SEL_SLP_STG_BMSK                                            0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_RST_SEL_SLP_STG_SHFT                                               5U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_RST_SLP_STG_BMSK                                                0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_RST_SLP_STG_SHFT                                                   4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CTRL_PWR_DOWN_BMSK                                               0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CTRL_PWR_DOWN_SHFT                                                 3U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                          0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                            2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CLK_EN_SLP_STG_BMSK                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CLK_EN_SLP_STG_SHFT                                                1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                         0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x309cU)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x309cU)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_RMSK                                                      0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_OFF_BMSK                                              0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_OFF_SHFT                                                      31U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                              24U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_DIS_BMSK                                                0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_DIS_SHFT                                                      22U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_ARES_BMSK                                                    0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_ARES_SHFT                                                      2U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_ARES_RESET_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_ENABLE_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_ENABLE_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_ICP_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30a0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30a0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_RMSK                                                    0x800000f3UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ROOT_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_DIRTY_D_BMSK                                                  0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_DIRTY_D_SHFT                                                     7U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_DIRTY_N_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_DIRTY_N_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_DIRTY_M_BMSK                                                  0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_DIRTY_M_SHFT                                                     5U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ROOT_EN_BMSK                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ROOT_EN_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_UPDATE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_UPDATE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30a4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30a4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_RMSK                                                      0x10371fUL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_MODE_BMSK                                                   0x3000U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_MODE_SHFT                                                       12U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_MODE_BYPASS_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_MODE_SWALLOW_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                          0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_BMSK                                                 0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30a8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30a8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_M_BMSK                                                               0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_M_M_SHFT                                                                  0U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30acU)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30acU)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_NOT_N_MINUS_M_BMSK                                                   0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_N_NOT_N_MINUS_M_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30b0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30b0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_NOT_2D_BMSK                                                          0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_D_NOT_2D_SHFT                                                             0U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30b8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30b8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_RMSK                                                        0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_0_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30bcU)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30bcU)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_RMSK                                                    0x800000f3UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ROOT_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_DIRTY_D_BMSK                                                  0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_DIRTY_D_SHFT                                                     7U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_DIRTY_N_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_DIRTY_N_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_DIRTY_M_BMSK                                                  0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_DIRTY_M_SHFT                                                     5U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ROOT_EN_BMSK                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ROOT_EN_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_UPDATE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_UPDATE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30c0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30c0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_RMSK                                                      0x10371fUL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_MODE_BMSK                                                   0x3000U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_MODE_SHFT                                                       12U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_MODE_BYPASS_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_MODE_SWALLOW_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                          0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_BMSK                                                 0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30c4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30c4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_M_BMSK                                                               0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_M_M_SHFT                                                                  0U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30c8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30c8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_NOT_N_MINUS_M_BMSK                                                   0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_N_NOT_N_MINUS_M_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30ccU)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30ccU)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_NOT_2D_BMSK                                                          0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_D_NOT_2D_SHFT                                                             0U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30d4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30d4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_RMSK                                                        0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_1_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30d8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30d8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_RMSK                                                    0x800000f3UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ROOT_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_DIRTY_D_BMSK                                                  0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_DIRTY_D_SHFT                                                     7U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_DIRTY_N_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_DIRTY_N_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_DIRTY_M_BMSK                                                  0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_DIRTY_M_SHFT                                                     5U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ROOT_EN_BMSK                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ROOT_EN_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_UPDATE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_UPDATE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30dcU)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30dcU)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_RMSK                                                      0x10371fUL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_MODE_BMSK                                                   0x3000U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_MODE_SHFT                                                       12U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_MODE_BYPASS_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_MODE_SWALLOW_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                          0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_BMSK                                                 0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30e0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30e0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_M_BMSK                                                               0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_M_M_SHFT                                                                  0U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30e4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30e4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_NOT_N_MINUS_M_BMSK                                                   0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_N_NOT_N_MINUS_M_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30e8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30e8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_NOT_2D_BMSK                                                          0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_D_NOT_2D_SHFT                                                             0U

#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30f0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30f0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_RMSK                                                        0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CCI_2_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_ADDR                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30f4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_OFFS                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30f4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_RMSK                                                     0x81c07ff5UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_CORE_ON_BMSK                                       0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_CORE_ON_SHFT                                           14U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                     0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                         13U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                    0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                        12U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_BMSK                                                   0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_SHFT                                                       8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK8_FVAL                                              0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK9_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK10_FVAL                                             0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK11_FVAL                                             0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK12_FVAL                                             0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK13_FVAL                                             0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK14_FVAL                                             0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_WAKEUP_CLOCK15_FVAL                                             0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_BMSK                                                     0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_SHFT                                                        4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK0_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK1_FVAL                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK2_FVAL                                               0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK3_FVAL                                               0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK4_FVAL                                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK5_FVAL                                               0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK6_FVAL                                               0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK7_FVAL                                               0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK8_FVAL                                               0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK9_FVAL                                               0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK10_FVAL                                              0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK11_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK12_FVAL                                              0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK13_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK14_FVAL                                              0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_SLEEP_CLOCK15_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30f8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30f8U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_RMSK                                                    0xfffffffeUL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                          0xff000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                  24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                             0xff0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                   16U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                    15U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                 0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                     14U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                    13U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                            0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                12U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CORE_ON_ACK_BMSK                                         0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CORE_ON_ACK_SHFT                                            11U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_PERIPH_ON_ACK_BMSK                                       0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_PERIPH_ON_ACK_SHFT                                          10U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                0x300U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                    8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                         0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CPH_ENABLE_BMSK                                           0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CPH_ENABLE_SHFT                                              7U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_FORCE_CLK_ON_BMSK                                             0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_FORCE_CLK_ON_SHFT                                                6U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_RST_SEL_SLP_STG_BMSK                                       0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_RST_SEL_SLP_STG_SHFT                                          5U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_RST_SLP_STG_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_RST_SLP_STG_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CTRL_PWR_DOWN_BMSK                                          0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CTRL_PWR_DOWN_SHFT                                            3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                     0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                       2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CLK_EN_SLP_STG_BMSK                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CLK_EN_SLP_STG_SHFT                                           1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_AHB_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                    0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_ADDR                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x30fcU)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_OFFS                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x30fcU)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_RMSK                                                0x81c07ff5UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                        24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_DIS_BMSK                                          0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_DIS_SHFT                                                22U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_CORE_ON_BMSK                                  0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_CORE_ON_SHFT                                      14U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                    13U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                               0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                   12U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_BMSK                                              0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_SHFT                                                  8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK0_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK1_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK2_FVAL                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK3_FVAL                                         0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK4_FVAL                                         0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK5_FVAL                                         0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK6_FVAL                                         0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK7_FVAL                                         0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK8_FVAL                                         0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK9_FVAL                                         0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK10_FVAL                                        0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK11_FVAL                                        0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK12_FVAL                                        0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK13_FVAL                                        0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK14_FVAL                                        0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_WAKEUP_CLOCK15_FVAL                                        0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_BMSK                                                0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_SHFT                                                   4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK0_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK1_FVAL                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK2_FVAL                                          0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK3_FVAL                                          0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK4_FVAL                                          0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK5_FVAL                                          0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK6_FVAL                                          0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK7_FVAL                                          0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK8_FVAL                                          0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK9_FVAL                                          0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK10_FVAL                                         0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK11_FVAL                                         0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK12_FVAL                                         0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK13_FVAL                                         0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK14_FVAL                                         0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_SLEEP_CLOCK15_FVAL                                         0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_ARES_BMSK                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_ARES_SHFT                                                2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_ARES_RESET_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_ENABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_ENABLE_SHFT                                              0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3100U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3100U)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_RMSK                                               0xfffffffeUL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                     0xff000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                             24U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                        0xff0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                              16U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                           0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                               15U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                            0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                14U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                           0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                               13U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                       0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                           12U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CORE_ON_ACK_BMSK                                    0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CORE_ON_ACK_SHFT                                       11U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_PERIPH_ON_ACK_BMSK                                  0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_PERIPH_ON_ACK_SHFT                                     10U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                           0x300U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                               8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                    0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                    0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CPH_ENABLE_BMSK                                      0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CPH_ENABLE_SHFT                                         7U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_FORCE_CLK_ON_BMSK                                        0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_FORCE_CLK_ON_SHFT                                           6U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_RST_SEL_SLP_STG_BMSK                                  0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_RST_SEL_SLP_STG_SHFT                                     5U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_RST_SLP_STG_BMSK                                      0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_RST_SLP_STG_SHFT                                         4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CTRL_PWR_DOWN_BMSK                                     0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CTRL_PWR_DOWN_SHFT                                       3U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                  2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CLK_EN_SLP_STG_BMSK                                    0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CLK_EN_SLP_STG_SHFT                                      1U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CPAS_FAST_AHB_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL               0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3104U)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3104U)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_RMSK                                                 0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ROOT_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ROOT_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                        0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                           4U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ROOT_EN_BMSK                                                0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ROOT_EN_SHFT                                                  1U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_UPDATE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_UPDATE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_UPDATE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CMD_RCGR_UPDATE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3108U)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3108U)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_RMSK                                                   0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_HW_CLK_CONTROL_BMSK                                    0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_HW_CLK_CONTROL_SHFT                                          20U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_RCGLITE_DISABLE_BMSK                                    0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_RCGLITE_DISABLE_SHFT                                         16U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_BMSK                                              0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_SHFT                                                  8U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_SRC0_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_SRC1_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_SRC2_FVAL                                           0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_SRC3_FVAL                                           0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_SRC4_FVAL                                           0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_SRC5_FVAL                                           0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_SRC6_FVAL                                           0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_SEL_SRC7_FVAL                                           0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_BMSK                                               0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_SHFT                                                  0U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV1_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV2_FVAL                                           0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                         0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV3_FVAL                                           0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                         0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV4_FVAL                                           0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                         0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV5_FVAL                                           0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                         0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV6_FVAL                                           0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                         0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV7_FVAL                                           0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                         0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV8_FVAL                                           0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                        0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV9_FVAL                                          0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                        0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV10_FVAL                                         0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                       0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV11_FVAL                                         0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                       0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV12_FVAL                                         0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                       0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV13_FVAL                                         0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                       0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV14_FVAL                                         0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                       0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV15_FVAL                                         0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                       0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_FAST_AHB_CFG_RCGR_SRC_DIV_DIV16_FVAL                                         0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x311cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x311cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_RMSK                                                 0x800000f3UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ROOT_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ROOT_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_DIRTY_D_BMSK                                               0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_DIRTY_D_SHFT                                                  7U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_DIRTY_N_BMSK                                               0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_DIRTY_N_SHFT                                                  6U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_DIRTY_M_BMSK                                               0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_DIRTY_M_SHFT                                                  5U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                        0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                           4U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ROOT_EN_BMSK                                                0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ROOT_EN_SHFT                                                  1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_UPDATE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_UPDATE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_UPDATE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CMD_RCGR_UPDATE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3120U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3120U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_RMSK                                                   0x10371fUL
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_HW_CLK_CONTROL_BMSK                                    0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_HW_CLK_CONTROL_SHFT                                          20U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_MODE_BMSK                                                0x3000U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_MODE_SHFT                                                    12U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_MODE_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_MODE_SWALLOW_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                       0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_BMSK                                              0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_SHFT                                                  8U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_SRC0_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_SRC1_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_SRC2_FVAL                                           0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_SRC3_FVAL                                           0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_SRC4_FVAL                                           0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_SRC5_FVAL                                           0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_SRC6_FVAL                                           0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_SEL_SRC7_FVAL                                           0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_BMSK                                               0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_SHFT                                                  0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV1_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV2_FVAL                                           0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                         0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV3_FVAL                                           0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                         0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV4_FVAL                                           0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                         0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV5_FVAL                                           0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                         0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV6_FVAL                                           0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                         0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV7_FVAL                                           0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                         0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV8_FVAL                                           0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                        0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV9_FVAL                                          0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                        0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV10_FVAL                                         0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                       0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV11_FVAL                                         0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                       0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV12_FVAL                                         0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                       0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV13_FVAL                                         0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                       0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV14_FVAL                                         0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                       0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV15_FVAL                                         0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                       0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_CFG_RCGR_SRC_DIV_DIV16_FVAL                                         0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3124U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3124U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_RMSK                                                              0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_M_BMSK                                                            0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_M_M_SHFT                                                               0U

#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3128U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3128U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_RMSK                                                              0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_NOT_N_MINUS_M_BMSK                                                0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_N_NOT_N_MINUS_M_SHFT                                                   0U

#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x312cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x312cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_RMSK                                                              0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_NOT_2D_BMSK                                                       0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_SLOW_AHB_D_NOT_2D_SHFT                                                          0U

#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ADDR                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3134U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_OFFS                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3134U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_RMSK                                                     0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ROOT_OFF_BMSK                                            0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ROOT_OFF_SHFT                                                    31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                            0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                               4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ROOT_EN_BMSK                                                    0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ROOT_EN_SHFT                                                      1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_UPDATE_BMSK                                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_UPDATE_SHFT                                                       0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_UPDATE_DISABLE_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CMD_RCGR_UPDATE_ENABLE_FVAL                                              0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_ADDR                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3138U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_OFFS                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3138U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_RMSK                                                       0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_HW_CLK_CONTROL_BMSK                                        0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_HW_CLK_CONTROL_SHFT                                              20U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_RCGLITE_DISABLE_BMSK                                        0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_RCGLITE_DISABLE_SHFT                                             16U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_BMSK                                                  0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_SHFT                                                      8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_SRC0_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_SRC1_FVAL                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_SRC2_FVAL                                               0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_SRC3_FVAL                                               0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_SRC4_FVAL                                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_SRC5_FVAL                                               0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_SRC6_FVAL                                               0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_SEL_SRC7_FVAL                                               0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_BMSK                                                   0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV1_FVAL                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                             0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV2_FVAL                                               0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                             0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV3_FVAL                                               0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                             0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV4_FVAL                                               0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                             0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV5_FVAL                                               0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                             0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV6_FVAL                                               0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                             0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV7_FVAL                                               0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                             0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV8_FVAL                                               0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                            0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV9_FVAL                                              0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                            0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV10_FVAL                                             0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                           0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV11_FVAL                                             0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                           0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV12_FVAL                                             0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                           0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV13_FVAL                                             0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                           0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV14_FVAL                                             0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                           0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV15_FVAL                                             0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                           0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CFG_RCGR_SRC_DIV_DIV16_FVAL                                             0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_ADDR                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x314cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_OFFS                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x314cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_RMSK                                                         0x81c07ff5UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_OFF_BMSK                                                 0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_OFF_SHFT                                                         31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_IGNORE_ALL_ARES_BMSK                                          0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_IGNORE_ALL_ARES_SHFT                                                 24U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                        0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                              23U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_DIS_BMSK                                                   0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_DIS_SHFT                                                         22U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_CORE_ON_BMSK                                           0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_CORE_ON_SHFT                                               14U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                                0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                         0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                             13U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                        0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                            12U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_BMSK                                                       0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_SHFT                                                           8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK0_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK1_FVAL                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK2_FVAL                                                  0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK3_FVAL                                                  0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK4_FVAL                                                  0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK5_FVAL                                                  0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK6_FVAL                                                  0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK7_FVAL                                                  0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK8_FVAL                                                  0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK9_FVAL                                                  0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK10_FVAL                                                 0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK11_FVAL                                                 0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK12_FVAL                                                 0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK13_FVAL                                                 0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK14_FVAL                                                 0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_WAKEUP_CLOCK15_FVAL                                                 0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_BMSK                                                         0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_SHFT                                                            4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK0_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK1_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK2_FVAL                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK3_FVAL                                                   0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK4_FVAL                                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK5_FVAL                                                   0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK6_FVAL                                                   0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK7_FVAL                                                   0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK8_FVAL                                                   0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK9_FVAL                                                   0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK10_FVAL                                                  0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK11_FVAL                                                  0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK12_FVAL                                                  0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK13_FVAL                                                  0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK14_FVAL                                                  0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_SLEEP_CLOCK15_FVAL                                                  0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_ARES_BMSK                                                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_ARES_SHFT                                                         2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_ARES_NO_RESET_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_ARES_RESET_FVAL                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_ENABLE_BMSK                                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_ENABLE_SHFT                                                       0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_ENABLE_DISABLE_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CBCR_CLK_ENABLE_ENABLE_FVAL                                              0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3150U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3150U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_RMSK                                                        0xfffffffeUL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                              0xff000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                      24U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                 0xff0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                       16U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                    0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                        15U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                     0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                         14U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                    0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                        13U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                                0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                    12U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CORE_ON_ACK_BMSK                                             0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CORE_ON_ACK_SHFT                                                11U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_PERIPH_ON_ACK_BMSK                                           0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_PERIPH_ON_ACK_SHFT                                              10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                    0x300U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                        8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                             0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                             0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CPH_ENABLE_BMSK                                               0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CPH_ENABLE_SHFT                                                  7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_FORCE_CLK_ON_BMSK                                                 0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_FORCE_CLK_ON_SHFT                                                    6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_RST_SEL_SLP_STG_BMSK                                           0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_RST_SEL_SLP_STG_SHFT                                              5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_RST_SLP_STG_BMSK                                               0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_RST_SLP_STG_SHFT                                                  4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CTRL_PWR_DOWN_BMSK                                              0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CTRL_PWR_DOWN_SHFT                                                3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                         0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                           2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CLK_EN_SLP_STG_BMSK                                             0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CLK_EN_SLP_STG_SHFT                                               1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3154U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3154U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_RMSK                                               0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ROOT_OFF_BMSK                                      0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ROOT_OFF_SHFT                                              31U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                      0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                         4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ROOT_EN_BMSK                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ROOT_EN_SHFT                                                1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_UPDATE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_UPDATE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_UPDATE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CMD_RCGR_UPDATE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3158U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3158U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_RMSK                                                 0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_HW_CLK_CONTROL_BMSK                                  0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_HW_CLK_CONTROL_SHFT                                        20U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_RCGLITE_DISABLE_BMSK                                  0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_RCGLITE_DISABLE_SHFT                                       16U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_BMSK                                            0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_SHFT                                                8U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_SRC0_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_SRC1_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_SRC2_FVAL                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_SRC3_FVAL                                         0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_SRC4_FVAL                                         0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_SRC5_FVAL                                         0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_SRC6_FVAL                                         0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_SEL_SRC7_FVAL                                         0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_BMSK                                             0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_SHFT                                                0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV1_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                       0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV2_FVAL                                         0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV3_FVAL                                         0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                       0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV4_FVAL                                         0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                       0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV5_FVAL                                         0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                       0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV6_FVAL                                         0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                       0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV7_FVAL                                         0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                       0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV8_FVAL                                         0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                      0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV9_FVAL                                        0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                      0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV10_FVAL                                       0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                     0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV11_FVAL                                       0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                     0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV12_FVAL                                       0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                     0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV13_FVAL                                       0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                     0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV14_FVAL                                       0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                     0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV15_FVAL                                       0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                     0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CFG_RCGR_SRC_DIV_DIV16_FVAL                                       0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x316cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x316cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_RMSK                                                   0x81c07ff5UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_IGNORE_ALL_ARES_SHFT                                           24U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_DIS_BMSK                                             0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_DIS_SHFT                                                   22U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_CORE_ON_BMSK                                     0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_CORE_ON_SHFT                                         14U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                   0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                       13U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                  0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                      12U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_BMSK                                                 0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK0_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK1_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK2_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK3_FVAL                                            0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK4_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK5_FVAL                                            0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK6_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK7_FVAL                                            0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK8_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK9_FVAL                                            0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK10_FVAL                                           0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK11_FVAL                                           0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK12_FVAL                                           0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK13_FVAL                                           0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK14_FVAL                                           0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_WAKEUP_CLOCK15_FVAL                                           0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_BMSK                                                   0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_SHFT                                                      4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK0_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK1_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK2_FVAL                                             0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK3_FVAL                                             0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK4_FVAL                                             0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK5_FVAL                                             0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK6_FVAL                                             0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK7_FVAL                                             0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK8_FVAL                                             0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK9_FVAL                                             0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK10_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK11_FVAL                                            0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK12_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK13_FVAL                                            0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK14_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_SLEEP_CLOCK15_FVAL                                            0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_ARES_BMSK                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_ARES_SHFT                                                   2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_ARES_RESET_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_ENABLE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_ENABLE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_ADDR                                                  (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3170U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_OFFS                                                  (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3170U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_RMSK                                                  0xfffffffeUL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                        0xff000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                           0xff0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                 16U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                              0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                  15U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                               0x4000U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                   14U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                              0x2000U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                  13U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                          0x1000U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                              12U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CORE_ON_ACK_BMSK                                       0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CORE_ON_ACK_SHFT                                          11U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_PERIPH_ON_ACK_BMSK                                     0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_PERIPH_ON_ACK_SHFT                                        10U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                              0x300U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                  8U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                       0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                       0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CPH_ENABLE_BMSK                                         0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CPH_ENABLE_SHFT                                            7U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_FORCE_CLK_ON_BMSK                                           0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_FORCE_CLK_ON_SHFT                                              6U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_RST_SEL_SLP_STG_BMSK                                     0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_RST_SEL_SLP_STG_SHFT                                        5U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_RST_SLP_STG_BMSK                                         0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_RST_SLP_STG_SHFT                                            4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CTRL_PWR_DOWN_BMSK                                        0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CTRL_PWR_DOWN_SHFT                                          3U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                     2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CLK_EN_SLP_STG_BMSK                                       0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CLK_EN_SLP_STG_SHFT                                         1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_AXI_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                  0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_ADDR                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3174U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_OFFS                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3174U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_RMSK                                                0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_IGNORE_ALL_ARES_SHFT                                        24U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_DIS_BMSK                                          0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_DIS_SHFT                                                22U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_ARES_BMSK                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_ARES_SHFT                                                2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_ARES_RESET_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_ENABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_ENABLE_SHFT                                              0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_DCD_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3178U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3178U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_RMSK                                                    0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_OFF_BMSK                                            0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_OFF_SHFT                                                    31U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_IGNORE_ALL_ARES_BMSK                                     0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_IGNORE_ALL_ARES_SHFT                                            24U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                   0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                         23U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_DIS_BMSK                                              0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_DIS_SHFT                                                    22U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_ARES_BMSK                                                  0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_ARES_SHFT                                                    2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_ARES_RESET_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_ENABLE_BMSK                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_ENABLE_SHFT                                                  0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMNOC_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                         0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x317cU)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x317cU)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_RMSK                                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_BLK_ARES_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_BLK_ARES_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_BLK_ARES_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_BCR_BLK_ARES_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3180U)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3180U)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_RMSK                                               0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ROOT_OFF_BMSK                                      0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ROOT_OFF_SHFT                                              31U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                      0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                         4U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ROOT_EN_BMSK                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ROOT_EN_SHFT                                                1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_UPDATE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_UPDATE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_UPDATE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CMD_RCGR_UPDATE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3184U)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3184U)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_RMSK                                                 0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_HW_CLK_CONTROL_BMSK                                  0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_HW_CLK_CONTROL_SHFT                                        20U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_RCGLITE_DISABLE_BMSK                                  0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_RCGLITE_DISABLE_SHFT                                       16U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_BMSK                                            0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_SHFT                                                8U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_SRC0_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_SRC1_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_SRC2_FVAL                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_SRC3_FVAL                                         0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_SRC4_FVAL                                         0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_SRC5_FVAL                                         0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_SRC6_FVAL                                         0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_SEL_SRC7_FVAL                                         0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_BMSK                                             0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_SHFT                                                0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV1_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                       0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV2_FVAL                                         0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV3_FVAL                                         0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                       0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV4_FVAL                                         0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                       0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV5_FVAL                                         0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                       0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV6_FVAL                                         0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                       0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV7_FVAL                                         0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                       0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV8_FVAL                                         0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                      0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV9_FVAL                                        0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                      0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV10_FVAL                                       0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                     0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV11_FVAL                                       0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                     0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV12_FVAL                                       0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                     0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV13_FVAL                                       0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                     0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV14_FVAL                                       0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                     0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV15_FVAL                                       0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                     0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CFG_RCGR_SRC_DIV_DIV16_FVAL                                       0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x3198U)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x3198U)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_RMSK                                                   0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_IGNORE_ALL_ARES_SHFT                                           24U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_DIS_BMSK                                             0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_DIS_SHFT                                                   22U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_ARES_BMSK                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_ARES_SHFT                                                   2U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_ARES_RESET_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_ENABLE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_ENABLE_SHFT                                                 0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_ADDR                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x319cU)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_OFFS                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x319cU)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_RMSK                                                0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_IGNORE_ALL_ARES_SHFT                                        24U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_DIS_BMSK                                          0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_DIS_SHFT                                                22U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_ARES_BMSK                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_ARES_SHFT                                                2U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_ARES_RESET_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_ENABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_ENABLE_SHFT                                              0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_QDSS_DEBUG_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31a0U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31a0U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RMSK                                                   0xf8ffffffUL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_PWR_ON_BMSK                                            0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_PWR_ON_SHFT                                                    31U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_GDSC_STATE_BMSK                                        0x78000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_GDSC_STATE_SHFT                                                27U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_REST_WAIT_BMSK                                        0xf00000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_REST_WAIT_SHFT                                              20U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_FEW_WAIT_BMSK                                          0xf0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_FEW_WAIT_SHFT                                               16U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLK_DIS_WAIT_BMSK                                          0xf000U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLK_DIS_WAIT_SHFT                                              12U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RETAIN_FF_ENABLE_BMSK                                       0x800U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RETAIN_FF_ENABLE_SHFT                                          11U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RESTORE_BMSK                                                0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RESTORE_SHFT                                                   10U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RESTORE_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RESTORE_ENABLE_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SAVE_BMSK                                                   0x200U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SAVE_SHFT                                                       9U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SAVE_DISABLE_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SAVE_ENABLE_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RETAIN_BMSK                                                 0x100U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RETAIN_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RETAIN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_RETAIN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_REST_BMSK                                                 0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_REST_SHFT                                                    7U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_REST_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_REST_ENABLE_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_FEW_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_FEW_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_FEW_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_EN_FEW_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLAMP_IO_BMSK                                                0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLAMP_IO_SHFT                                                   5U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLAMP_IO_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLAMP_IO_ENABLE_FVAL                                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLK_DISABLE_BMSK                                             0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLK_DISABLE_SHFT                                                4U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_PD_ARES_BMSK                                                  0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_PD_ARES_SHFT                                                    3U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_PD_ARES_NO_RESET_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_PD_ARES_RESET_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SW_OVERRIDE_BMSK                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SW_OVERRIDE_SHFT                                                2U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_HW_CONTROL_BMSK                                               0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_HW_CONTROL_SHFT                                                 1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_HW_CONTROL_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_HW_CONTROL_ENABLE_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SW_COLLAPSE_BMSK                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SW_COLLAPSE_SHFT                                                0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                       0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31a4U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31a4U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_RMSK                                                0x3ffffffUL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                             0x2000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                    25U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                              0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                     24U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                       0xf00000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                          0x80000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                               19U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                              0x40000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                   18U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                              0x20000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                   17U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                           0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                16U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                          0x8000U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                              15U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                         0x7800U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                             11U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                 0x400U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                    10U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                          0x200U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                              9U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                          0x100U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                              8U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                              0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                 7U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                     0x60U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                        5U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                               0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                  4U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                         0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                           3U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                         2U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                           0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                             1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                          0U

#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31a8U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31a8U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_RMSK                                                 0x7ffffUL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                     0x40000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                          18U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                 0x20000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                      17U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                               0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                    16U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                   0xf000U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                       12U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                            0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                8U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                               0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                  4U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                 0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                   0U

#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31acU)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31acU)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_RMSK                                               0x7ffffffUL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK             0x4000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                    26U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                          0x2000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                 25U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                        0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                     0x1e00000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                            21U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                      0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                            20U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK             0x80000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                  19U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                 0x40000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                      18U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                  0x20000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                       17U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                       0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                            16U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                               0xff00U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                    8U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                   0U

#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31b0U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31b0U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_RMSK                                                0xffffffUL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                  0xf00000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                        20U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                   0xf0000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                        16U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                   0xf000U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                       12U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                  0xf00U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                      8U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                        0xf0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                           4U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_RETAINFF_BMSK                                        0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_CFG4_GDSCR_DLY_RETAINFF_SHFT                                          0U

#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_ADDR                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31b4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_OFFS                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31b4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_RMSK                                                     0x81c00004UL
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CORE_AHB_CBCR_CLK_ARES_RESET_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ADDR                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31b8U)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_OFFS                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31b8U)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_RMSK                                                       0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ROOT_OFF_BMSK                                              0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ROOT_OFF_SHFT                                                      31U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                              0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                 4U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ROOT_EN_BMSK                                                      0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ROOT_EN_SHFT                                                        1U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_UPDATE_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_UPDATE_SHFT                                                         0U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_UPDATE_DISABLE_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CMD_RCGR_UPDATE_ENABLE_FVAL                                                0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_ADDR                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31bcU)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_OFFS                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31bcU)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_RMSK                                                         0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_HW_CLK_CONTROL_BMSK                                          0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_HW_CLK_CONTROL_SHFT                                                20U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_RCGLITE_DISABLE_BMSK                                          0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_RCGLITE_DISABLE_SHFT                                               16U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_BMSK                                                    0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_SHFT                                                        8U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                 0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                 0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                 0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                 0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                 0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                 0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_BMSK                                                     0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                               0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                 0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                 0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                               0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                 0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                               0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                 0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                               0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                 0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                               0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                 0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                               0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                 0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                              0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV9_FVAL                                                0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                              0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV10_FVAL                                               0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                             0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV11_FVAL                                               0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                             0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV12_FVAL                                               0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                             0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV13_FVAL                                               0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                             0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV14_FVAL                                               0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                             0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV15_FVAL                                               0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                             0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_XO_CFG_RCGR_SRC_DIV_DIV16_FVAL                                               0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_ADDR                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31d0U)
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_OFFS                                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31d0U)
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_RMSK                                                         0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_OFF_BMSK                                                 0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_OFF_SHFT                                                         31U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_IGNORE_ALL_ARES_BMSK                                          0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_IGNORE_ALL_ARES_SHFT                                                 24U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                        0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                              23U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_DIS_BMSK                                                   0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_DIS_SHFT                                                         22U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_ARES_BMSK                                                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_ARES_SHFT                                                         2U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_ARES_NO_RESET_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_ARES_RESET_FVAL                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_ENABLE_BMSK                                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_ENABLE_SHFT                                                       0U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_ENABLE_DISABLE_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_GDSC_CBCR_CLK_ENABLE_ENABLE_FVAL                                              0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31d4U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31d4U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_RMSK                                                    0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ROOT_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ROOT_EN_BMSK                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ROOT_EN_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_UPDATE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_UPDATE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31d8U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31d8U)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_RMSK                                                      0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_BMSK                                       0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_SHFT                                            16U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_BMSK                                                 0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31ecU)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31ecU)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_RMSK                                                        0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_ADDR                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x31f0U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_OFFS                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x31f0U)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_RMSK                                         0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_OFF_BMSK                                 0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_OFF_SHFT                                         31U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_IGNORE_ALL_ARES_BMSK                          0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_IGNORE_ALL_ARES_SHFT                                 24U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_IGNORE_ALL_CLK_DIS_BMSK                        0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_IGNORE_ALL_CLK_DIS_SHFT                              23U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_DIS_BMSK                                   0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_DIS_SHFT                                         22U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_ARES_BMSK                                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_ARES_SHFT                                         2U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_ARES_NO_RESET_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_ARES_RESET_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_ENABLE_BMSK                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_ENABLE_SHFT                                       0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_ENABLE_DISABLE_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_TITAN_TOP_ACCU_SHIFT_CBCR_CLK_ENABLE_ENABLE_FVAL                              0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x4004U)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x4004U)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_RMSK                                                          0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_CLK_DIV_BMSK                                                  0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_DIV_CDIVR_CLK_DIV_SHFT                                                    0U

#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x4008U)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x4008U)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_RMSK                                                        0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_ADDR                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x4010U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_OFFS                                                (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x4010U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_RMSK                                                       0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_CLK_DIV_BMSK                                               0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_DIV_CDIVR_CLK_DIV_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_ADDR                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x4014U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_OFFS                                                     (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x4014U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_RMSK                                                     0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5000U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5000U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_RMSK                                                    0x800000f3UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ROOT_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_DIRTY_D_BMSK                                                  0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_DIRTY_D_SHFT                                                     7U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_DIRTY_N_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_DIRTY_N_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_DIRTY_M_BMSK                                                  0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_DIRTY_M_SHFT                                                     5U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ROOT_EN_BMSK                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ROOT_EN_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_UPDATE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_UPDATE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5004U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5004U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_RMSK                                                      0x10371fUL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_MODE_BMSK                                                   0x3000U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_MODE_SHFT                                                       12U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_MODE_BYPASS_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_MODE_SWALLOW_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                          0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_BMSK                                                 0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5008U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5008U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_M_BMSK                                                               0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_M_M_SHFT                                                                  0U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x500cU)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x500cU)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_NOT_N_MINUS_M_BMSK                                                   0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_N_NOT_N_MINUS_M_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5010U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5010U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_NOT_2D_BMSK                                                          0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_D_NOT_2D_SHFT                                                             0U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5018U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5018U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_RMSK                                                        0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK0_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x501cU)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x501cU)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_RMSK                                                    0x800000f3UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ROOT_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_DIRTY_D_BMSK                                                  0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_DIRTY_D_SHFT                                                     7U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_DIRTY_N_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_DIRTY_N_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_DIRTY_M_BMSK                                                  0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_DIRTY_M_SHFT                                                     5U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ROOT_EN_BMSK                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ROOT_EN_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_UPDATE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_UPDATE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5020U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5020U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_RMSK                                                      0x10371fUL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_MODE_BMSK                                                   0x3000U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_MODE_SHFT                                                       12U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_MODE_BYPASS_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_MODE_SWALLOW_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                          0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_BMSK                                                 0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5024U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5024U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_M_BMSK                                                               0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_M_M_SHFT                                                                  0U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5028U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5028U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_NOT_N_MINUS_M_BMSK                                                   0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_N_NOT_N_MINUS_M_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x502cU)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x502cU)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_NOT_2D_BMSK                                                          0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_D_NOT_2D_SHFT                                                             0U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5034U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5034U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_RMSK                                                        0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK1_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5038U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5038U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_RMSK                                                    0x800000f3UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ROOT_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_DIRTY_D_BMSK                                                  0x80U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_DIRTY_D_SHFT                                                     7U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_DIRTY_N_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_DIRTY_N_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_DIRTY_M_BMSK                                                  0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_DIRTY_M_SHFT                                                     5U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ROOT_EN_BMSK                                                   0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ROOT_EN_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_UPDATE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_UPDATE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x503cU)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x503cU)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_RMSK                                                      0x10371fUL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_MODE_BMSK                                                   0x3000U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_MODE_SHFT                                                       12U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_MODE_BYPASS_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_MODE_SWALLOW_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_MODE_DUAL_EDGE_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_MODE_SINGLE_EDGE_FVAL                                          0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_BMSK                                                 0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5040U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5040U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_M_BMSK                                                               0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_M_M_SHFT                                                                  0U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5044U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5044U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_NOT_N_MINUS_M_BMSK                                                   0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_N_NOT_N_MINUS_M_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_ADDR                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5048U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_OFFS                                                           (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5048U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_RMSK                                                                 0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_NOT_2D_BMSK                                                          0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_D_NOT_2D_SHFT                                                             0U

#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5050U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5050U)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_RMSK                                                        0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_MCLK2_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ADDR                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5054U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_OFFS                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5054U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_RMSK                                             0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ROOT_OFF_SHFT                                            31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ROOT_EN_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ROOT_EN_SHFT                                              1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_UPDATE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_UPDATE_SHFT                                               0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_ADDR                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5058U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_OFFS                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5058U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_RMSK                                               0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_BMSK                                0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_SHFT                                     16U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_BMSK                                          0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_SHFT                                              8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_BMSK                                           0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_SHFT                                              0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x506cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x506cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_RMSK                                                 0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_OFF_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_OFF_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_IGNORE_ALL_ARES_SHFT                                         24U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_DIS_BMSK                                           0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_DIS_SHFT                                                 22U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_ARES_BMSK                                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_ARES_SHFT                                                 2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_ARES_RESET_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_ENABLE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_ENABLE_SHFT                                               0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI0PHYTIMER_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5070U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5070U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_RMSK                                                      0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_OFF_BMSK                                              0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_OFF_SHFT                                                      31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_IGNORE_ALL_ARES_SHFT                                              24U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_DIS_BMSK                                                0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_DIS_SHFT                                                      22U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_ARES_BMSK                                                    0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_ARES_SHFT                                                      2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_ARES_RESET_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_ENABLE_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_ENABLE_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY0_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_ADDR                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5074U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_OFFS                                               (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5074U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_RMSK                                               0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_OFF_BMSK                                       0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_OFF_SHFT                                               31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_IGNORE_ALL_ARES_BMSK                                0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_IGNORE_ALL_ARES_SHFT                                       24U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_IGNORE_ALL_CLK_DIS_BMSK                              0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                    23U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_DIS_BMSK                                         0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_DIS_SHFT                                               22U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_ARES_BMSK                                             0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_ARES_SHFT                                               2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_ARES_NO_RESET_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_ARES_RESET_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_ENABLE_BMSK                                           0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_ENABLE_SHFT                                             0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_ENABLE_DISABLE_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSID_CSIPHY_RX_CBCR_CLK_ENABLE_ENABLE_FVAL                                    0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ADDR                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5078U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_OFFS                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5078U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_RMSK                                             0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ROOT_OFF_SHFT                                            31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ROOT_EN_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ROOT_EN_SHFT                                              1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_UPDATE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_UPDATE_SHFT                                               0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_ADDR                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x507cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_OFFS                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x507cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_RMSK                                               0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_BMSK                                0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_SHFT                                     16U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_BMSK                                          0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_SHFT                                              8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_BMSK                                           0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_SHFT                                              0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5090U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5090U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_RMSK                                                 0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_OFF_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_OFF_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_IGNORE_ALL_ARES_SHFT                                         24U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_DIS_BMSK                                           0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_DIS_SHFT                                                 22U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_ARES_BMSK                                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_ARES_SHFT                                                 2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_ARES_RESET_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_ENABLE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_ENABLE_SHFT                                               0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI1PHYTIMER_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5094U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5094U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_RMSK                                                      0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_OFF_BMSK                                              0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_OFF_SHFT                                                      31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_IGNORE_ALL_ARES_SHFT                                              24U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_DIS_BMSK                                                0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_DIS_SHFT                                                      22U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_ARES_BMSK                                                    0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_ARES_SHFT                                                      2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_ARES_RESET_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_ENABLE_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_ENABLE_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY1_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ADDR                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5098U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_OFFS                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5098U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_RMSK                                             0x80000013UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ROOT_OFF_BMSK                                    0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ROOT_OFF_SHFT                                            31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                    0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                       4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ROOT_EN_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ROOT_EN_SHFT                                              1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_UPDATE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_UPDATE_SHFT                                               0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_UPDATE_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CMD_RCGR_UPDATE_ENABLE_FVAL                                      0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_ADDR                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x509cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_OFFS                                             (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x509cU)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_RMSK                                               0x11071fUL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_BMSK                                0x100000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_SHFT                                      20U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_BMSK                                0x10000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_SHFT                                     16U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_BMSK                                          0x700U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_SHFT                                              8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_SRC0_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_SRC1_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_SRC2_FVAL                                       0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_SRC3_FVAL                                       0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_SRC4_FVAL                                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_SRC5_FVAL                                       0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_SRC6_FVAL                                       0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_SEL_SRC7_FVAL                                       0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_BMSK                                           0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_SHFT                                              0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV1_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                     0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV2_FVAL                                       0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                     0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV3_FVAL                                       0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                     0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV4_FVAL                                       0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                     0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV5_FVAL                                       0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                     0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV6_FVAL                                       0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                     0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV7_FVAL                                       0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                     0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV8_FVAL                                       0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                    0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV9_FVAL                                      0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                    0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV10_FVAL                                     0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                   0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV11_FVAL                                     0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                   0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV12_FVAL                                     0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                   0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV13_FVAL                                     0x19U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                   0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV14_FVAL                                     0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                   0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV15_FVAL                                     0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                   0x1eU
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CFG_RCGR_SRC_DIV_DIV16_FVAL                                     0x1fU

#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x50b0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x50b0U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_RMSK                                                 0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_OFF_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_OFF_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_IGNORE_ALL_ARES_SHFT                                         24U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_DIS_BMSK                                           0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_DIS_SHFT                                                 22U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_ARES_BMSK                                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_ARES_SHFT                                                 2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_ARES_RESET_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_ENABLE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_ENABLE_SHFT                                               0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSI2PHYTIMER_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x50b4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x50b4U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_RMSK                                                      0x81c00005UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_OFF_BMSK                                              0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_OFF_SHFT                                                      31U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_IGNORE_ALL_ARES_SHFT                                              24U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_DIS_BMSK                                                0x400000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_DIS_SHFT                                                      22U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_ARES_BMSK                                                    0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_ARES_SHFT                                                      2U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_ARES_RESET_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_ENABLE_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_ENABLE_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CSIPHY2_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_ADDR                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x50f8U)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_OFFS                                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x50f8U)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_RMSK                                                          0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_BMSK                                                  0xffU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_MCLK0_CLK_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_MCLK1_CLK_FVAL                                  0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_MCLK2_CLK_FVAL                                  0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_TITAN_TOP_ACCU_SHIFT_CLK_FVAL                   0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CCI_2_CLK_FVAL                                  0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CSI0PHYTIMER_CLK_FVAL                           0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CSIPHY0_CLK_FVAL                                0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CSID_CSIPHY_RX_CLK_FVAL                         0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CSI1PHYTIMER_CLK_FVAL                           0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CSIPHY1_CLK_FVAL                                0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CSI2PHYTIMER_CLK_FVAL                           0xeU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CSIPHY2_CLK_FVAL                                0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IPE_CLK_FVAL                                   0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CPAS_IPE_CLK_FVAL                              0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IPE_SPDM_CLK_FVAL                              0x14U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IPE_AHB_CLK_FVAL                               0x15U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IPE_FAST_AHB_CLK_FVAL                          0x16U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_0_CLK_FVAL                                 0x17U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CPAS_IFE_0_CLK_FVAL                            0x18U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_0_SPDM_CLK_FVAL                            0x1aU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_0_FAST_AHB_CLK_FVAL                        0x1bU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_1_CLK_FVAL                                 0x1cU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CPAS_IFE_1_CLK_FVAL                            0x1dU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_1_SPDM_CLK_FVAL                            0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_1_FAST_AHB_CLK_FVAL                        0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_LITE_CLK_FVAL                              0x21U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CPAS_IFE_LITE_CLK_FVAL                         0x22U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_LITE_CSID_CLK_FVAL                         0x23U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_LITE_CPHY_RX_CLK_FVAL                      0x24U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_IFE_LITE_AHB_CLK_FVAL                          0x25U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_SFE_LITE_0_CLK_FVAL                            0x26U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CPAS_SFE_LITE_0_CLK_FVAL                       0x27U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_SFE_LITE_0_SPDM_CLK_FVAL                       0x28U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_SFE_LITE_0_FAST_AHB_CLK_FVAL                   0x29U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_SFE_LITE_1_CLK_FVAL                            0x2aU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CPAS_SFE_LITE_1_CLK_FVAL                       0x2bU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_SFE_LITE_1_SPDM_CLK_FVAL                       0x2cU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_SFE_LITE_1_FAST_AHB_CLK_FVAL                   0x2dU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_ICP_CLK_FVAL                                   0x2eU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_ICP_AHB_CLK_FVAL                               0x2fU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CCI_0_CLK_FVAL                                 0x30U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CCI_1_CLK_FVAL                                 0x31U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CPAS_AHB_CLK_FVAL                              0x32U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CPAS_FAST_AHB_CLK_FVAL                         0x33U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CSID_CLK_FVAL                                  0x34U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CAMNOC_AXI_CLK_FVAL                            0x35U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CAMNOC_DCD_XO_CLK_FVAL                         0x36U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CAMNOC_XO_CLK_FVAL                             0x37U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_QDSS_DEBUG_CLK_FVAL                            0x38U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_QDSS_DEBUG_XO_CLK_FVAL                         0x39U
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_CORE_AHB_CLK_FVAL                              0x3aU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_GDSC_CLK_FVAL                                  0x3bU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CAM_CC_SLEEP_CLK_FVAL                                 0x3cU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CSIPHY0_CAM_CC_DEBUG_CLK_FVAL                         0x3dU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CSIPHY1_CAM_CC_DEBUG_CLK_FVAL                         0x3eU
#define HWIO_SAIL_TO_MD_CAM_CC_DEBUG_MUX_MUXR_MUX_SEL_CSIPHY2_CAM_CC_DEBUG_CLK_FVAL                         0x3fU

#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x50fcU)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x50fcU)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_RMSK                                                        0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_MUX_SEL_BMSK                                                0xfU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_MUX_SEL_SHFT                                                  0U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_MUX_SEL_CAM_CC_PLL0_TEST_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_MUX_SEL_CAM_CC_PLL2_TEST_FVAL                               0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_MUX_SEL_CAM_CC_PLL3_TEST_FVAL                               0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_MUX_SEL_CAM_CC_PLL4_TEST_FVAL                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_TEST_MUX_MUXR_MUX_SEL_CAM_CC_PLL5_TEST_FVAL                               0x5U

#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_ADDR                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5100U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_OFFS                                                   (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5100U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_RMSK                                                         0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_BMSK                                                 0x1fU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_ZERO_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_PLL0_STATUS_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_PLL2_STATUS_FVAL                               0x3U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_PLL3_STATUS_FVAL                               0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_PLL4_STATUS_FVAL                               0x5U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_TITAN_TOP_GDSC_FSM_STATE_FVAL                  0x6U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_IFE_0_GDSC_FSM_STATE_FVAL                      0x7U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_IFE_1_GDSC_FSM_STATE_FVAL                      0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_IPE_0_GDSC_FSM_STATE_FVAL                      0x9U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_BPS_GDSC_FSM_STATE_FVAL                        0xaU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_SBI_GDSC_FSM_STATE_FVAL                        0xbU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_IFE_2_GDSC_FSM_STATE_FVAL                      0xcU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_PLL5_STATUS_FVAL                               0xdU
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_SFE_0_GDSC_FSM_STATE_FVAL                     0x11U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_SFE_1_GDSC_FSM_STATE_FVAL                     0x12U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_DEBUG_BUS_SLP_RET_SIGNALS_1_FVAL              0x13U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL_STATUS_MUXR_MUX_SEL_CAM_CC_DEBUG_BUS_SLP_RET_SIGNALS_2_FVAL              0x14U

#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_ADDR                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5104U)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_OFFS                                                        (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5104U)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_RMSK                                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_SPARE_CTRL_OUT_BMSK                                         0xffffffffUL
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_CTRL_SPARE_CTRL_OUT_SHFT                                                  0U

#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_STATUS_ADDR                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5108U)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_STATUS_OFFS                                                      (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5108U)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_STATUS_RMSK                                                      0xffffffffUL
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SPARE_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SPARE_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_STATUS_SPARE_STATUS_IN_BMSK                                      0xffffffffUL
#define HWIO_SAIL_TO_MD_CAM_CC_SPARE_STATUS_SPARE_STATUS_IN_SHFT                                               0U

#define HWIO_SAIL_TO_MD_CAM_CC_SM_OBS_CBCR_ADDR                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x510cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SM_OBS_CBCR_OFFS                                                       (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x510cU)
#define HWIO_SAIL_TO_MD_CAM_CC_SM_OBS_CBCR_RMSK                                                              0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SM_OBS_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_SM_OBS_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_SM_OBS_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_SM_OBS_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_SM_OBS_CBCR_CLK_OFF_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_SM_OBS_CBCR_CLK_OFF_SHFT                                                        0U

#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_ADDR                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x5110U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_OFFS                                              (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x5110U)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_RMSK                                              0x80000003UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_STATUS_BMSK                                       0x80000000UL
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_STATUS_SHFT                                               31U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_SW_OVRD_VAL_BMSK                                         0x2U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_SW_OVRD_VAL_SHFT                                           1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_SW_OVRD_SEL_BMSK                                         0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_SW_OVRD_SEL_SHFT                                           0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_SW_OVRD_SEL_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_CAM_CC_CAMSS_FAL10_VETO_REG_SW_OVRD_SEL_ENABLE_FVAL                                  0x1U

#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_ADDR                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x6000U)
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_OFFS                                    (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x6000U)
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_RMSK                                        0x1fffU
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_HPCNT_BMSK                                  0x1f80U
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_HPCNT_SHFT                                       7U
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_VPCNT_BMSK                                    0x7eU
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_VPCNT_SHFT                                       1U
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_FLT_BMSK                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_RESET_FLT_SHFT                                         0U

#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_ADDR                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x6004U)
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_OFFS                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x6004U)
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_RMSK                              0x1fffU
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_HPCNT_BMSK                        0x1f80U
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_HPCNT_SHFT                             7U
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_VPCNT_BMSK                          0x7eU
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_VPCNT_SHFT                             1U
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_FLT_BMSK                             0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_FUSA_STATUS_REGISTER_CLK_CAM_CC_AHB_ARES_FLT_SHFT                               0U

#define HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_ADDR                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x6200U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_OFFS                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x6200U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_RMSK                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_BMSK                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL0_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_SHFT                                    0U

#define HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_ADDR                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x6204U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_OFFS                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x6204U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_RMSK                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_BMSK                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL2_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_SHFT                                    0U

#define HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_ADDR                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x6208U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_OFFS                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x6208U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_RMSK                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_BMSK                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL3_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_SHFT                                    0U

#define HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_ADDR                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x620cU)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_OFFS                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x620cU)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_RMSK                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_BMSK                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL4_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_SHFT                                    0U

#define HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_ADDR                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x6210U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_OFFS                                         (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x6210U)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_RMSK                                                0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_BMSK                                  0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PLL5_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_SHFT                                    0U

#define HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_ADDR                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x6214U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_OFFS                                          (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x6214U)
#define HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_RMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_ADDR,v)
#define HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_ADDR,m,v,HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_IN)
#define HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_BMSK                                   0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_CSR_PARITY_INTR_MASK_BIT_MASK_INTR_BIT_SHFT                                     0U

#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_ADDR                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE      + 0x6218U)
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_OFFS                                                 (SAIL_TO_MD_CAM_CC_CAM_CC_CAM_CC_REG_REG_BASE_OFFS + 0x6218U)
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_RMSK                                                       0x7dU
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_ADDR)
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_ADDR, m)
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_CC_CSR_PARITY_INTR_BMSK                                    0x40U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_CC_CSR_PARITY_INTR_SHFT                                       6U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL5_PARITY_INTR_BMSK                                      0x20U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL5_PARITY_INTR_SHFT                                         5U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL4_PARITY_INTR_BMSK                                      0x10U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL4_PARITY_INTR_SHFT                                         4U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL3_PARITY_INTR_BMSK                                       0x8U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL3_PARITY_INTR_SHFT                                         3U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL2_PARITY_INTR_BMSK                                       0x4U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL2_PARITY_INTR_SHFT                                         2U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL0_PARITY_INTR_BMSK                                       0x1U
#define HWIO_SAIL_TO_MD_CAM_CC_PARITY_STATUS_REG_PLL0_PARITY_INTR_SHFT                                         0U


#endif /* G_SAIL_TO_MD_CAM_CC_H */
