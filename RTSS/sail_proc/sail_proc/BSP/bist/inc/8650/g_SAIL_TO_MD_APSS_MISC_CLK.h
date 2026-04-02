#ifndef __G_SAIL_TO_MD_APSS_MISC_CLK_H__
#define __G_SAIL_TO_MD_APSS_MISC_CLK_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_APSS_MISC_CLK.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_APSS_MISC_CLK.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK'],
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
 * MODULE: SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE                                                    (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x182a0000ul)
#define SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_SIZE                                               0x1000u
#define SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_USED                                               0xff0u
#define SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS                                               0x182a0000ul

#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_ADDR                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_OFFS                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_RMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_ADDR)
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_IN)
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_CLK_BMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_CLK_SHFT                                                           0u
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_CLK_SEC_FVAL                                                     0x0u
#define HWIO_SAIL_TO_MD_APSS_MISC_CLK_SECURE_CLK_NSEC_FVAL                                                    0x1u

#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x8u)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x8u)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_RMSK                                                               0x3u
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_ADDR)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_IN)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_LMH_DISABLE_VOTE_OUT_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_LMH_DISABLE_VOTE_OUT_SHFT                                            1u
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_LMH_GFMUX_HALT_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CMD_LMH_GFMUX_HALT_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xcu)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xcu)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_RMSK                                                        0xf0000003ul
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_ADDR)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_IN)
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_STS_SEL_A_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_STS_SEL_A_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_STS_SEL_B_BMSK                                          0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_STS_SEL_B_SHFT                                                  30u
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_STS_SEL_C_BMSK                                          0x20000000ul
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_STS_SEL_C_SHFT                                                  29u
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_STS_SEL_D_BMSK                                          0x10000000ul
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_STS_SEL_D_SHFT                                                  28u
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_GFMUX_SRC_SEL_BMSK                                             0x3u
#define HWIO_SAIL_TO_MD_APSS_LMH_GFMUX_CFG_LMH_GFMUX_SRC_SEL_SHFT                                               0u

#define HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_ADDR                                                       (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x10u)
#define HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_OFFS                                                       (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x10u)
#define HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_RMSK                                                              0x7u
#define HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_ADDR)
#define HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_IN)
#define HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_CDIV_COUNT_BMSK                                                   0x7u
#define HWIO_SAIL_TO_MD_APSS_LMH_CDIV_COUNT_CDIV_COUNT_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_ADDR                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x14u)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_OFFS                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x14u)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RMSK                                                             0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_LMH_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_LMH_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_LMH_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_LMH_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_LMH_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_CLK_OFF_BMSK                                                     0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_CLK_OFF_SHFT                                                             31u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_CBC_CLK_ON_BMSK                                                  0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_CBC_CLK_ON_SHFT                                                          30u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_HW_CTL_BMSK                                                             0x2u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_HW_CTL_SHFT                                                               1u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_SW_CTL_BMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_SW_CTL_SHFT                                                               0u

#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_ADDR                                                         (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x18u)
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_OFFS                                                         (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x18u)
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_RMSK                                                             0x7fffu
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_ADDR)
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_IN)
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CDIV_BMSK                                                    0x7800u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CDIV_SHFT                                                        11u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CDIV_DIV1_FVAL                                                  0x0u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CDIV_DIV2_FVAL                                                  0x1u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CDIV_DIV3_FVAL                                                  0x2u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CDIV_DIV4_FVAL                                                  0x3u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CLK_LVL3_SEL_BMSK                                             0x600u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CLK_LVL3_SEL_SHFT                                                 9u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CLK_LVL2_SEL_BMSK                                             0x1c0u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CLK_LVL2_SEL_SHFT                                                 6u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CLK_LVL1_SEL_BMSK                                              0x30u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_DBG_CLK_LVL1_SEL_SHFT                                                 4u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_PLLTEST_CDIV_BMSK                                                   0xcu
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_PLLTEST_CDIV_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_PLLTEST_CDIV_DIV1_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_PLLTEST_CDIV_DIV2_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_PLLTEST_CDIV_DIV3_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_PLLTEST_CDIV_DIV4_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_PLLTEST_CLK_SEL_BMSK                                                0x3u
#define HWIO_SAIL_TO_MD_APSS_GLB_CLK_DIAG_PLLTEST_CLK_SEL_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_ADDR                                                              (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x1cu)
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_OFFS                                                              (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_RMSK                                                              0x80000003ul
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_CLK_OFF_BMSK                                                      0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_CLK_OFF_SHFT                                                              31u
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_HW_CTL_BMSK                                                              0x2u
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_HW_CTL_SHFT                                                                1u
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_SW_CTL_BMSK                                                              0x1u
#define HWIO_SAIL_TO_MD_APSS_XO_CBCR_SW_CTL_SHFT                                                                0u

#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_ADDR                                                           (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x20u)
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_OFFS                                                           (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x20u)
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_RMSK                                                           0x80000003ul
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_CLK_OFF_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_CLK_OFF_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_HW_CTL_BMSK                                                           0x2u
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_HW_CTL_SHFT                                                             1u
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_SW_CTL_BMSK                                                           0x1u
#define HWIO_SAIL_TO_MD_APSS_SLEEP_CBCR_SW_CTL_SHFT                                                             0u

#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_ADDR                                                            (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x28u)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_OFFS                                                            (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x28u)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_RMSK                                                                   0x1u
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_IN)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_BLK_ARES_BMSK                                                          0x1u
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_BLK_ARES_SHFT                                                            0u
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_BLK_ARES_DISABLE_FVAL                                                  0x0u
#define HWIO_SAIL_TO_MD_APSS_RBCPR_BCR_BLK_ARES_ENABLE_FVAL                                                   0x1u

#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_ADDR                                                           (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x2cu)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_OFFS                                                           (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x2cu)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_RMSK                                                           0x80000003ul
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_CLK_OFF_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_CLK_OFF_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_HW_CTL_BMSK                                                           0x2u
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_HW_CTL_SHFT                                                             1u
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_SW_CTL_BMSK                                                           0x1u
#define HWIO_SAIL_TO_MD_APSS_RBCPR_CBCR_SW_CTL_SHFT                                                             0u

#define HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_ADDR                                                           (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x30u)
#define HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_OFFS                                                           (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x30u)
#define HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_RMSK                                                                  0x1u
#define HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_ADDR)
#define HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_IN)
#define HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_AUX_CLK_ON_REQ_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_APSS_AUX_CLK_ON_AUX_CLK_ON_REQ_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_ADDR                                                   (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x34u)
#define HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_OFFS                                                   (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x34u)
#define HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_RMSK                                                          0x1u
#define HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_FAULT_MON_CLK_SEL_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_APSS_FAULT_MONITOR_CBCR_FAULT_MON_CLK_SEL_SHFT                                          0u

#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_ADDR                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x3cu)
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_OFFS                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x3cu)
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_RMSK                                                                    0x1u
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_FFWD_BCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_FFWD_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_FFWD_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_FFWD_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_FFWD_BCR_IN)
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_BLK_ARES_BMSK                                                           0x1u
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_BLK_ARES_SHFT                                                             0u
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_BLK_ARES_DISABLE_FVAL                                                   0x0u
#define HWIO_SAIL_TO_MD_APSS_FFWD_BCR_BLK_ARES_ENABLE_FVAL                                                    0x1u

#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_ADDR                                                            (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x40u)
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_OFFS                                                            (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x40u)
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_RMSK                                                            0x80000003ul
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_CLK_OFF_BMSK                                                    0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_CLK_OFF_SHFT                                                            31u
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_HW_CTL_BMSK                                                            0x2u
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_HW_CTL_SHFT                                                              1u
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_SW_CTL_BMSK                                                            0x1u
#define HWIO_SAIL_TO_MD_APSS_FFWD_CBCR_SW_CTL_SHFT                                                              0u

#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_ADDR                                                         (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x44u)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_OFFS                                                         (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x44u)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_RMSK                                                         0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_ADDR)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_IN)
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_CLK_OFF_BMSK                                                 0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_CLK_OFF_SHFT                                                         31u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_CBC_CLK_ON_BMSK                                              0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_CBC_CLK_ON_SHFT                                                      30u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_HW_CTL_BMSK                                                         0x2u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_HW_CTL_SHFT                                                           1u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_SW_CTL_BMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_APSS_LMH_CBCR_RET_SW_CTL_SHFT                                                           0u

#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_ADDR                                                     (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x54u)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_OFFS                                                     (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x54u)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_RMSK                                                          0xfffu
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_ADDR)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_IN)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_CNT_CLK_EN_BMSK                                       0x800u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_CNT_CLK_EN_SHFT                                          11u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_CORE_CLK_EN_BMSK                                      0x7f8u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_CORE_CLK_EN_SHFT                                          3u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_PCLK_EN_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_PCLK_EN_SHFT                                              2u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_ACLK_EN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_ACLK_EN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_ATCLK_EN_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_CLK_GATE_CLUSTER_ATCLK_EN_SHFT                                             0u

#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_ADDR                                                     (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x58u)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_OFFS                                                     (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x58u)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_RMSK                                                            0x3u
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_ADDR)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_IN)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_PERIPH_DISABLE_VOTE_OUT_BMSK                                    0x2u
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_PERIPH_DISABLE_VOTE_OUT_SHFT                                      1u
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_PERIPH_SOFT_HALT_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_APSS_PERIPH_GFMUX_CMD_PERIPH_SOFT_HALT_SHFT                                             0u

#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_ADDR                                                  (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x5cu)
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_OFFS                                                  (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x5cu)
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_RMSK                                                  0xf0000003ul
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_ADDR)
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_IN)
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_STS_SEL_A_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_STS_SEL_A_SHFT                                         31u
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_STS_SEL_B_BMSK                                 0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_STS_SEL_B_SHFT                                         30u
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_STS_SEL_C_BMSK                                 0x20000000ul
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_STS_SEL_C_SHFT                                         29u
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_STS_SEL_D_BMSK                                 0x10000000ul
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_STS_SEL_D_SHFT                                         28u
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_SRC_SEL_BMSK                                          0x3u
#define HWIO_SAIL_TO_MD_APSS_PERIPHCLK_GFMUX_CFG_PERIPH_SRC_SEL_SHFT                                            0u

#define HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_ADDR                                                    (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x60u)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_OFFS                                                    (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x60u)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_RMSK                                                           0xfu
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_ADDR)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_IN)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_CDIV_COUNT_BMSK                                                0xfu
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CDIV_COUNT_CDIV_COUNT_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_ADDR                                                          (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x64u)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_OFFS                                                          (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x64u)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_RMSK                                                          0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_CLK_OFF_BMSK                                                  0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_CLK_OFF_SHFT                                                          31u
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_CBC_CLK_ON_BMSK                                               0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_CBC_CLK_ON_SHFT                                                       30u
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_HW_CTL_BMSK                                                          0x2u
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_HW_CTL_SHFT                                                            1u
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_SW_CTL_BMSK                                                          0x1u
#define HWIO_SAIL_TO_MD_APSS_PERIPH_CBCR_SW_CTL_SHFT                                                            0u

#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x68u)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x68u)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_RMSK                                                               0x3u
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_ADDR)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_IN)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_GIC_DISABLE_VOTE_OUT_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_GIC_DISABLE_VOTE_OUT_SHFT                                            1u
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_GIC_GFMUX_HALT_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CMD_GIC_GFMUX_HALT_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x6cu)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x6cu)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_RMSK                                                        0xf0000003ul
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_ADDR)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_IN)
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_STS_SEL_A_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_STS_SEL_A_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_STS_SEL_B_BMSK                                          0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_STS_SEL_B_SHFT                                                  30u
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_STS_SEL_C_BMSK                                          0x20000000ul
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_STS_SEL_C_SHFT                                                  29u
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_STS_SEL_D_BMSK                                          0x10000000ul
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_STS_SEL_D_SHFT                                                  28u
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_GFMUX_SRC_SEL_BMSK                                             0x3u
#define HWIO_SAIL_TO_MD_APSS_GIC_GFMUX_CFG_GIC_GFMUX_SRC_SEL_SHFT                                               0u

#define HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_ADDR                                                       (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x70u)
#define HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_OFFS                                                       (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x70u)
#define HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_RMSK                                                              0xfu
#define HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_ADDR)
#define HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_IN)
#define HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_CDIV_COUNT_BMSK                                                   0xfu
#define HWIO_SAIL_TO_MD_APSS_GIC_CDIV_COUNT_CDIV_COUNT_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_ADDR                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x74u)
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_OFFS                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x74u)
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_RMSK                                                             0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_GIC_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_GIC_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_GIC_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_GIC_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_GIC_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_CLK_OFF_BMSK                                                     0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_CLK_OFF_SHFT                                                             31u
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_CBC_CLK_ON_BMSK                                                  0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_CBC_CLK_ON_SHFT                                                          30u
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_HW_CTL_BMSK                                                             0x2u
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_HW_CTL_SHFT                                                               1u
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_SW_CTL_BMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_APSS_GIC_CBCR_SW_CTL_SHFT                                                               0u

#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x78u)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x78u)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_RMSK                                                               0x3u
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_ADDR)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_IN)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_OSM_DISABLE_VOTE_OUT_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_OSM_DISABLE_VOTE_OUT_SHFT                                            1u
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_OSM_GFMUX_HALT_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CMD_OSM_GFMUX_HALT_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x7cu)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x7cu)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_RMSK                                                        0xf0000003ul
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_ADDR)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_IN)
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_STS_SEL_A_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_STS_SEL_A_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_STS_SEL_B_BMSK                                          0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_STS_SEL_B_SHFT                                                  30u
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_STS_SEL_C_BMSK                                          0x20000000ul
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_STS_SEL_C_SHFT                                                  29u
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_STS_SEL_D_BMSK                                          0x10000000ul
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_STS_SEL_D_SHFT                                                  28u
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_GFMUX_SRC_SEL_BMSK                                             0x3u
#define HWIO_SAIL_TO_MD_APSS_OSM_GFMUX_CFG_OSM_GFMUX_SRC_SEL_SHFT                                               0u

#define HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_ADDR                                                       (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x80u)
#define HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_OFFS                                                       (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x80u)
#define HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_RMSK                                                              0x7u
#define HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_ADDR)
#define HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_IN)
#define HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_CDIV_COUNT_BMSK                                                   0x7u
#define HWIO_SAIL_TO_MD_APSS_OSM_CDIV_COUNT_CDIV_COUNT_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_ADDR                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x84u)
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_OFFS                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x84u)
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_RMSK                                                             0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_OSM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_OSM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_OSM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_OSM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_OSM_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_CLK_OFF_BMSK                                                     0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_CLK_OFF_SHFT                                                             31u
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_CBC_CLK_ON_BMSK                                                  0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_CBC_CLK_ON_SHFT                                                          30u
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_HW_CTL_BMSK                                                             0x2u
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_HW_CTL_SHFT                                                               1u
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_SW_CTL_BMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_APSS_OSM_CBCR_SW_CTL_SHFT                                                               0u

#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x88u)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x88u)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_RMSK                                                               0x3u
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_ADDR)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_IN)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_IPM_DISABLE_VOTE_OUT_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_IPM_DISABLE_VOTE_OUT_SHFT                                            1u
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_IPM_GFMUX_HALT_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CMD_IPM_GFMUX_HALT_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x8cu)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x8cu)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_RMSK                                                        0xf0000003ul
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_ADDR)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IN)
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_STS_SEL_A_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_STS_SEL_A_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_STS_SEL_B_BMSK                                          0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_STS_SEL_B_SHFT                                                  30u
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_STS_SEL_C_BMSK                                          0x20000000ul
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_STS_SEL_C_SHFT                                                  29u
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_STS_SEL_D_BMSK                                          0x10000000ul
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_STS_SEL_D_SHFT                                                  28u
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_GFMUX_SRC_SEL_BMSK                                             0x3u
#define HWIO_SAIL_TO_MD_APSS_IPM_GFMUX_CFG_IPM_GFMUX_SRC_SEL_SHFT                                               0u

#define HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_ADDR                                                       (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x90u)
#define HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_OFFS                                                       (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x90u)
#define HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_RMSK                                                              0xfu
#define HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_ADDR)
#define HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_IN)
#define HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_CDIV_COUNT_BMSK                                                   0xfu
#define HWIO_SAIL_TO_MD_APSS_IPM_CDIV_COUNT_CDIV_COUNT_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_ADDR                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x94u)
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_OFFS                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x94u)
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_RMSK                                                             0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_IPM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_IPM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_IPM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_IPM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_IPM_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_CLK_OFF_BMSK                                                     0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_CLK_OFF_SHFT                                                             31u
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_CBC_CLK_ON_BMSK                                                  0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_CBC_CLK_ON_SHFT                                                          30u
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_HW_CTL_BMSK                                                             0x2u
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_HW_CTL_SHFT                                                               1u
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_SW_CTL_BMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_APSS_IPM_CBCR_SW_CTL_SHFT                                                               0u

#define HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_ADDR                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x98u)
#define HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_OFFS                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x98u)
#define HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_RMSK                                                             0xfu
#define HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_ADDR)
#define HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_IN)
#define HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_CDIV_COUNT_BMSK                                                  0xfu
#define HWIO_SAIL_TO_MD_APSS_GNOC_CDIV_COUNT_CDIV_COUNT_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_ADDR                                                            (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0x9cu)
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_OFFS                                                            (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0x9cu)
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_RMSK                                                            0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_CLK_OFF_BMSK                                                    0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_CLK_OFF_SHFT                                                            31u
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_CBC_CLK_ON_BMSK                                                 0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_CBC_CLK_ON_SHFT                                                         30u
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_HW_CTL_BMSK                                                            0x2u
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_HW_CTL_SHFT                                                              1u
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_SW_CTL_BMSK                                                            0x1u
#define HWIO_SAIL_TO_MD_APSS_EPCB_CBCR_SW_CTL_SHFT                                                              0u

#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_ADDR                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xa0u)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_OFFS                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xa0u)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_RMSK                                                      0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_CLK_OFF_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_CLK_OFF_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_CBC_CLK_ON_BMSK                                           0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_CBC_CLK_ON_SHFT                                                   30u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_HW_CTL_BMSK                                                      0x2u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_HW_CTL_SHFT                                                        1u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_SW_CTL_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC0_CBCR_SW_CTL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_ADDR                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xa4u)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_OFFS                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xa4u)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_RMSK                                                      0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_CLK_OFF_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_CLK_OFF_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_CBC_CLK_ON_BMSK                                           0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_CBC_CLK_ON_SHFT                                                   30u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_HW_CTL_BMSK                                                      0x2u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_HW_CTL_SHFT                                                        1u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_SW_CTL_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_APSS_TSENS_APC1_CBCR_SW_CTL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_ADDR                                                    (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xa8u)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_OFFS                                                    (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xa8u)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_RMSK                                                    0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_CLK_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_CLK_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_CBC_CLK_ON_BMSK                                         0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_CBC_CLK_ON_SHFT                                                 30u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_HW_CTL_BMSK                                                    0x2u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_HW_CTL_SHFT                                                      1u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_SW_CTL_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC0_CBCR_SW_CTL_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_ADDR                                                    (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xacu)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_OFFS                                                    (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xacu)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_RMSK                                                    0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_CLK_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_CLK_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_CBC_CLK_ON_BMSK                                         0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_CBC_CLK_ON_SHFT                                                 30u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_HW_CTL_BMSK                                                    0x2u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_HW_CTL_SHFT                                                      1u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_SW_CTL_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_APSS_GLM_LLM_APC1_CBCR_SW_CTL_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_ADDR                                                          (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xb0u)
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_OFFS                                                          (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xb0u)
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_RMSK                                                               0xf03u
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_ADDR)
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_IN)
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_CDIV_COUNT_BMSK                                                    0xf00u
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_CDIV_COUNT_SHFT                                                        8u
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_AHB_GFMUX_SRC_SEL_BMSK                                               0x3u
#define HWIO_SAIL_TO_MD_APSS_AHB_CLK_CFG_AHB_GFMUX_SRC_SEL_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_ADDR                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xb4u)
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_OFFS                                                             (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xb4u)
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_RMSK                                                             0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_CLK_OFF_BMSK                                                     0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_CLK_OFF_SHFT                                                             31u
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_CBC_CLK_ON_BMSK                                                  0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_CBC_CLK_ON_SHFT                                                          30u
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_HW_CTL_BMSK                                                             0x2u
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_HW_CTL_SHFT                                                               1u
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_SW_CTL_BMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_APSS_AHB_CBCR_SW_CTL_SHFT                                                               0u

#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_ADDR                                                            (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xb8u)
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_OFFS                                                            (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xb8u)
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_RMSK                                                            0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_CLK_OFF_BMSK                                                    0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_CLK_OFF_SHFT                                                            31u
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_CBC_CLK_ON_BMSK                                                 0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_CBC_CLK_ON_SHFT                                                         30u
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_HW_CTL_BMSK                                                            0x2u
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_HW_CTL_SHFT                                                              1u
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_SW_CTL_BMSK                                                            0x1u
#define HWIO_SAIL_TO_MD_APSS_MIBU_CBCR_SW_CTL_SHFT                                                              0u

#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xbcu)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xbcu)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_RMSK                                                               0x3u
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_ADDR)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_IN)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_AHB_DISABLE_VOTE_OUT_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_AHB_DISABLE_VOTE_OUT_SHFT                                            1u
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_AHB_GFMUX_HALT_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CMD_AHB_GFMUX_HALT_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_ADDR                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xc0u)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_OFFS                                                        (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xc0u)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_RMSK                                                        0xf0000000ul
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_ADDR)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_AHB_STS_SEL_A_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_AHB_STS_SEL_A_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_AHB_STS_SEL_B_BMSK                                          0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_AHB_STS_SEL_B_SHFT                                                  30u
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_AHB_STS_SEL_C_BMSK                                          0x20000000ul
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_AHB_STS_SEL_C_SHFT                                                  29u
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_AHB_STS_SEL_D_BMSK                                          0x10000000ul
#define HWIO_SAIL_TO_MD_APSS_AHB_GFMUX_CFG_AHB_STS_SEL_D_SHFT                                                  28u

#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_ADDR                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xc4u)
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_OFFS                                                      (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xc4u)
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_RMSK                                                      0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_CLK_OFF_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_CLK_OFF_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_CBC_CLK_ON_BMSK                                           0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_CBC_CLK_ON_SHFT                                                   30u
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_HW_CTL_BMSK                                                      0x2u
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_HW_CTL_SHFT                                                        1u
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_SW_CTL_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_APSS_MEMRED_S2P_CBCR_SW_CTL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_ADDR                                                         (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xc8u)
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_OFFS                                                         (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xc8u)
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_RMSK                                                         0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_CLK_OFF_BMSK                                                 0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_CLK_OFF_SHFT                                                         31u
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_CBC_CLK_ON_BMSK                                              0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_CBC_CLK_ON_SHFT                                                      30u
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_HW_CTL_BMSK                                                         0x2u
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_HW_CTL_SHFT                                                           1u
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_SW_CTL_BMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_APSS_MEM_ACC_CBCR_SW_CTL_SHFT                                                           0u

#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_ADDR                                                (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xccu)
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_OFFS                                                (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xccu)
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_RMSK                                                0x81e0000dul
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_IGNORE_PMU_CLK_DIS_BMSK                               0x200000ul
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_IGNORE_PMU_CLK_DIS_SHFT                                     21u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_APSS_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_ADDR                                                   (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xd4u)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_OFFS                                                   (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xd4u)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_RMSK                                                   0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_CBC_CLK_ON_BMSK                                        0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_CBC_CLK_ON_SHFT                                                30u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_SW_CTL_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_GIC_CBCR_SW_CTL_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_ADDR                                                (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xd8u)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_OFFS                                                (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xd8u)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_RMSK                                                0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_CLUSTER_1_CLK_OFF_BMSK                              0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_CLUSTER_1_CLK_OFF_SHFT                                      31u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_CLUSTER_1_CBC_CLK_ON_BMSK                           0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_CLUSTER_1_CBC_CLK_ON_SHFT                                   30u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_CLUSTER_1_HW_CTL_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_CLUSTER_1_HW_CTL_SHFT                                        1u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_CLUSTER_1_SW_CTL_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_PERIPH_CBCR_CLUSTER_1_SW_CTL_SHFT                                        0u

#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_ADDR                                                  (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xe0u)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_OFFS                                                  (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xe0u)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_RMSK                                                  0xc0000003ul
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_IN)
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_CLK_OFF_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_CLK_OFF_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_CBC_CLK_ON_BMSK                                       0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_CBC_CLK_ON_SHFT                                               30u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_HW_CTL_BMSK                                                  0x2u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_HW_CTL_SHFT                                                    1u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_SW_CTL_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_APSS_CLUSTER_1_MIBU_CBCR_SW_CTL_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_ADDR                                                 (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xe8u)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_OFFS                                                 (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xe8u)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_RMSK                                                        0x3u
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_ADDR)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_IN)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_CL1_PERIPH_DISABLE_VOTE_OUT_BMSK                            0x2u
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_CL1_PERIPH_DISABLE_VOTE_OUT_SHFT                              1u
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_CL1_PERIPH_SOFT_HALT_BMSK                                   0x1u
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_GFMUX_CMD_CL1_PERIPH_SOFT_HALT_SHFT                                     0u

#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_ADDR                                              (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xecu)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_OFFS                                              (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xecu)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_RMSK                                              0xf0000003ul
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_ADDR)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_IN)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_STS_SEL_A_BMSK                         0x80000000ul
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_STS_SEL_A_SHFT                                 31u
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_STS_SEL_B_BMSK                         0x40000000ul
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_STS_SEL_B_SHFT                                 30u
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_STS_SEL_C_BMSK                         0x20000000ul
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_STS_SEL_C_SHFT                                 29u
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_STS_SEL_D_BMSK                         0x10000000ul
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_STS_SEL_D_SHFT                                 28u
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_SRC_SEL_BMSK                                  0x3u
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPHCLK_GFMUX_CFG_CL1_PERIPH_SRC_SEL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_ADDR                                                (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xf0u)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_OFFS                                                (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xf0u)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_RMSK                                                       0xfu
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_ADDR)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_ADDR,v)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_ADDR,m,v,HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_IN)
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_CL1_CDIV_COUNT_BMSK                                        0xfu
#define HWIO_SAIL_TO_MD_APSS_CL1_PERIPH_CDIV_COUNT_CL1_CDIV_COUNT_SHFT                                          0u

#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_ADDR                    (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xfdcu)
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_OFFS                    (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xfdcu)
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_RMSK                        0x1fffu
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_ADDR)
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_HPCNT_BMSK                  0x1f80u
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_HPCNT_SHFT                       7u
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_VPCNT_BMSK                    0x7eu
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_VPCNT_SHFT                       1u
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_FLT_BMSK                       0x1u
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSAHB_ARES_FLT_SHFT                         0u

#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_ADDR                (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE      + 0xff0u)
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_OFFS                (SAIL_TO_MD_APSS_APSS_APSS_MISC_CLK_REG_BASE_OFFS + 0xff0u)
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_RMSK                    0x1fffu
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_IN                    \
                in_dword(HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_ADDR)
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_ADDR, m)
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_HPCNT_BMSK              0x1f80u
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_HPCNT_SHFT                   7u
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_VPCNT_BMSK                0x7eu
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_VPCNT_SHFT                   1u
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_FLT_BMSK                   0x1u
#define HWIO_SAIL_TO_MD_APSS_FUSA_STATUS_REGISTER_SYS_AHB_CLK_SYS_APCSFUNCALT_ARES_FLT_SHFT                     0u


#endif /* __G_SAIL_TO_MD_APSS_MISC_CLK_H__ */
