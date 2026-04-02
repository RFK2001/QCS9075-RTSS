#ifndef __G_SAIL_TO_MD_DPC_HWIO_H__
#define __G_SAIL_TO_MD_DPC_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_DPC_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_DPC_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/bist/inc/common_inc/g_SAIL_TO_MD_DPC_HWIO.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE                                                   (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x090a8000ul)
#define SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_SIZE                                              0x5000u
#define SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_USED                                              0x4200u
#define SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS                                              0x090a8000ul

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xccu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xccu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_RMSK                                                       0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_CLK_DIV_BMSK                                               0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_DIV_CDIVR_CLK_DIV_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_ADDR                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xd0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_OFFS                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xd0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_RMSK                                                     0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_IGNORE_ALL_ARES_SHFT                                             24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_DIS_BMSK                                               0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_DIS_SHFT                                                     22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_ARES_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_ARES_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_ENABLE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_ENABLE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xd8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xd8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_RMSK                                                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_CLK_DIV_BMSK                                            0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_DIV_CDIVR_CLK_DIV_SHFT                                              0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xdcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xdcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_RMSK                                                  0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_OFF_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_OFF_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_IGNORE_ALL_ARES_BMSK                                   0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_IGNORE_ALL_ARES_SHFT                                          24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                 0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                       23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_DIS_BMSK                                            0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_DIS_SHFT                                                  22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_ARES_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_ARES_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_ARES_NO_RESET_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_ARES_RESET_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_ENABLE_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_ENABLE_SHFT                                                0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_ENABLE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_CBCR_CLK_ENABLE_ENABLE_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_ADDR                                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xe0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_OFFS                                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xe0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_RMSK                                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_BLK_ARES_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_BLK_ARES_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_BLK_ARES_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_BCR_BLK_ARES_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_ADDR                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xe4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_OFFS                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xe4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RMSK                                                     0xf8fffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_PWR_ON_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_PWR_ON_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_GDSC_STATE_BMSK                                          0x78000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_GDSC_STATE_SHFT                                                  27u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_REST_WAIT_BMSK                                          0xf00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_REST_WAIT_SHFT                                                20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_FEW_WAIT_BMSK                                            0xf0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_FEW_WAIT_SHFT                                                 16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLK_DIS_WAIT_BMSK                                            0xf000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLK_DIS_WAIT_SHFT                                                12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RETAIN_FF_ENABLE_BMSK                                         0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RETAIN_FF_ENABLE_SHFT                                            11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RESTORE_BMSK                                                  0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RESTORE_SHFT                                                     10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RESTORE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RESTORE_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SAVE_BMSK                                                     0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SAVE_SHFT                                                         9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SAVE_DISABLE_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SAVE_ENABLE_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RETAIN_BMSK                                                   0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RETAIN_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RETAIN_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_RETAIN_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_REST_BMSK                                                   0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_REST_SHFT                                                      7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_REST_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_REST_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_FEW_BMSK                                                    0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_FEW_SHFT                                                       6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_FEW_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_EN_FEW_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLAMP_IO_BMSK                                                  0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLAMP_IO_SHFT                                                     5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLAMP_IO_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLAMP_IO_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLK_DISABLE_BMSK                                               0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLK_DISABLE_SHFT                                                  4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_PD_ARES_BMSK                                                    0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_PD_ARES_SHFT                                                      3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_PD_ARES_NO_RESET_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_PD_ARES_RESET_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SW_OVERRIDE_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SW_OVERRIDE_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_HW_CONTROL_BMSK                                                 0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_HW_CONTROL_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_HW_CONTROL_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_HW_CONTROL_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SW_COLLAPSE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SW_COLLAPSE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xe8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xe8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_RMSK                                                  0x3fffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                               0x2000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                      25u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                                0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                       24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                         0xf00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                               20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                            0x80000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                 19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                                0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                     18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                                0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                     17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                  16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                            0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                                15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                           0x7800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                               11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                   0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                      10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                            0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                                9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                            0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                                8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                                0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                   7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                       0x60u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                          5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                    4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                           0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                             3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                         0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                           2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                            0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xecu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xecu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_RMSK                                                   0x7fffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                       0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                            18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                   0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                        17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                 0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                      16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                     0xf000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                         12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                              0xf00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                  8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                 0xf0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                    4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                   0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                     0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xf0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xf0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_RMSK                                                 0x7fffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK               0x4000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                      26u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                            0x2000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                   25u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                       0x1e00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                              21u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                        0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                              20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK               0x80000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                    19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                   0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                        18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL               0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                    0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                         17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                         0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                              16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                 0xff00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                      8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                     0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xf4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xf4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_RMSK                                                  0xfffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                    0xf00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                          20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                     0xf0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                          16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                     0xf000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                         12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                    0xf00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                        8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                          0xf0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_RETAINFF_BMSK                                          0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CFG4_GDSCR_DLY_RETAINFF_SHFT                                            0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xf8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xf8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_RMSK                                                 0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_SW_ONLY_EN_BMSK                                             0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_SW_ONLY_EN_SHFT                                               3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_ARES_RESET_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_HW_CTL_BMSK                                                 0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_HW_CTL_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_HW_CTL_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_HW_CTL_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0xfcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0xfcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC0_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x100u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x100u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC1_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x104u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x104u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_RMSK                                                 0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_SW_ONLY_EN_BMSK                                             0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_SW_ONLY_EN_SHFT                                               3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_ARES_RESET_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_HW_CTL_BMSK                                                 0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_HW_CTL_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LAGG_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x108u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x108u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_RMSK                                               0x81c07ffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_OFF_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_OFF_SHFT                                               31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                                0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                       24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                              0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                    23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_DIS_BMSK                                         0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_DIS_SHFT                                               22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_CORE_ON_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_CORE_ON_SHFT                                     14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_PERIPH_ON_BMSK                               0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                   13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                              0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                  12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_BMSK                                             0xf00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_SHFT                                                 8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK0_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK1_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK2_FVAL                                        0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK3_FVAL                                        0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK4_FVAL                                        0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK5_FVAL                                        0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK6_FVAL                                        0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK7_FVAL                                        0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK8_FVAL                                        0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK9_FVAL                                        0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK10_FVAL                                       0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK11_FVAL                                       0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK12_FVAL                                       0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK13_FVAL                                       0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK14_FVAL                                       0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_WAKEUP_CLOCK15_FVAL                                       0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_BMSK                                               0xf0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_SHFT                                                  4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK0_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK1_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK2_FVAL                                         0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK3_FVAL                                         0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK4_FVAL                                         0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK5_FVAL                                         0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK6_FVAL                                         0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK7_FVAL                                         0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK8_FVAL                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK9_FVAL                                         0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK10_FVAL                                        0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK11_FVAL                                        0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK12_FVAL                                        0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK13_FVAL                                        0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK14_FVAL                                        0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SLEEP_CLOCK15_FVAL                                        0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SW_ONLY_EN_BMSK                                           0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_SW_ONLY_EN_SHFT                                             3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_ARES_BMSK                                             0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_ARES_SHFT                                               2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_ARES_RESET_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_HW_CTL_BMSK                                               0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_HW_CTL_SHFT                                                 1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_ENABLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_ENABLE_SHFT                                             0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                    0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x10cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x10cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_RMSK                                              0xfffffffeul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                    0xff000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                            24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                       0xff0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                             16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                          0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                              15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                           0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                               14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                          0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                              13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                      0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                          12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CORE_ON_ACK_BMSK                                   0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CORE_ON_ACK_SHFT                                      11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_PERIPH_ON_ACK_BMSK                                 0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_PERIPH_ON_ACK_SHFT                                    10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                          0x300u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                              8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                   0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CPH_ENABLE_BMSK                                     0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CPH_ENABLE_SHFT                                        7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_FORCE_CLK_ON_BMSK                                       0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_FORCE_CLK_ON_SHFT                                          6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_RST_SEL_SLP_STG_BMSK                                 0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_RST_SEL_SLP_STG_SHFT                                    5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_RST_SLP_STG_BMSK                                     0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_RST_SLP_STG_SHFT                                        4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CTRL_PWR_DOWN_BMSK                                    0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CTRL_PWR_DOWN_SHFT                                      3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                               0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                 2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CLK_EN_SLP_STG_BMSK                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CLK_EN_SLP_STG_SHFT                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GEMNOC_SHUB_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL              0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x110u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x110u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC1_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_ADDR                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x114u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_OFFS                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x114u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_RMSK                                                    0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_IGNORE_ALL_ARES_BMSK                                     0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_IGNORE_ALL_ARES_SHFT                                            24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                   0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                         23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_DIS_BMSK                                              0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_DIS_SHFT                                                    22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_SW_ONLY_EN_BMSK                                                0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_SW_ONLY_EN_SHFT                                                  3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_ARES_BMSK                                                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_ARES_SHFT                                                    2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_ARES_NO_RESET_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_ARES_RESET_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_HW_CTL_BMSK                                                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_HW_CTL_SHFT                                                      1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_HW_CTL_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_HW_CTL_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_ENABLE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_ENABLE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_ENABLE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_NSPNOC_CBCR_CLK_ENABLE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_ADDR                                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x118u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_OFFS                                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x118u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_RMSK                                                       0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_OFF_BMSK                                               0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_OFF_SHFT                                                       31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_IGNORE_ALL_ARES_BMSK                                        0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_IGNORE_ALL_ARES_SHFT                                               24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                      0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                            23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_DIS_BMSK                                                 0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_DIS_SHFT                                                       22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_SW_ONLY_EN_BMSK                                                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_SW_ONLY_EN_SHFT                                                     3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_ARES_BMSK                                                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_ARES_SHFT                                                       2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_ARES_NO_RESET_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_ARES_RESET_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_HW_CTL_BMSK                                                       0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_HW_CTL_SHFT                                                         1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_HW_CTL_DISABLE_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_HW_CTL_ENABLE_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_ENABLE_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_ENABLE_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_ENABLE_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GPU_CBCR_CLK_ENABLE_ENABLE_FVAL                                            0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x11cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x11cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_HF_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x120u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x120u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MNOC_SF_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x124u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x124u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CNOC_SF_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x128u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x128u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_GC_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x12cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x12cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SNOC_SF_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x130u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x130u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SYS_TCU_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_ADDR                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x134u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_OFFS                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x134u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_RMSK                                                      0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_OFF_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_OFF_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_IGNORE_ALL_ARES_SHFT                                              24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_DIS_BMSK                                                0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_DIS_SHFT                                                      22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_SW_ONLY_EN_BMSK                                                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_SW_ONLY_EN_SHFT                                                    3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_ARES_BMSK                                                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_ARES_SHFT                                                      2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_ARES_RESET_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_HW_CTL_BMSK                                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_HW_CTL_SHFT                                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_HW_CTL_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_HW_CTL_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_ENABLE_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_ENABLE_SHFT                                                    0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SAIL_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x138u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x138u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_CFG_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x13cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x13cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH01_ATB_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x140u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x140u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_TS_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x144u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x144u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PCIE_SF_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x148u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x148u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC2_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x14cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x14cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC3_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x150u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x150u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_CFG_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x154u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x154u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH23_ATB_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x158u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x158u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC4_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x15cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x15cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_LLCC5_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x160u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x160u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_CFG_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x164u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x164u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_CH45_ATB_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_ADDR                                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x168u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_OFFS                                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x168u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_RMSK                                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_BLK_ARES_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_BLK_ARES_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_BLK_ARES_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_BCR_BLK_ARES_ENABLE_FVAL                                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_ADDR                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x16cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_OFFS                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x16cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RMSK                                                      0xf8fffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_PWR_ON_BMSK                                               0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_PWR_ON_SHFT                                                       31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_GDSC_STATE_BMSK                                           0x78000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_GDSC_STATE_SHFT                                                   27u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_REST_WAIT_BMSK                                           0xf00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_REST_WAIT_SHFT                                                 20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_FEW_WAIT_BMSK                                             0xf0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_FEW_WAIT_SHFT                                                  16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLK_DIS_WAIT_BMSK                                             0xf000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLK_DIS_WAIT_SHFT                                                 12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RETAIN_FF_ENABLE_BMSK                                          0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RETAIN_FF_ENABLE_SHFT                                             11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RESTORE_BMSK                                                   0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RESTORE_SHFT                                                      10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RESTORE_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RESTORE_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SAVE_BMSK                                                      0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SAVE_SHFT                                                          9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SAVE_DISABLE_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SAVE_ENABLE_FVAL                                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RETAIN_BMSK                                                    0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RETAIN_SHFT                                                        8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RETAIN_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_RETAIN_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_REST_BMSK                                                    0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_REST_SHFT                                                       7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_REST_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_REST_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_FEW_BMSK                                                     0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_FEW_SHFT                                                        6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_FEW_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_EN_FEW_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLAMP_IO_BMSK                                                   0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLAMP_IO_SHFT                                                      5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLAMP_IO_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLAMP_IO_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLK_DISABLE_BMSK                                                0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLK_DISABLE_SHFT                                                   4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_PD_ARES_BMSK                                                     0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_PD_ARES_SHFT                                                       3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_PD_ARES_NO_RESET_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_PD_ARES_RESET_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SW_OVERRIDE_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SW_OVERRIDE_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_HW_CONTROL_BMSK                                                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_HW_CONTROL_SHFT                                                    1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_HW_CONTROL_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_HW_CONTROL_ENABLE_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SW_COLLAPSE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SW_COLLAPSE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x170u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x170u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_RMSK                                                   0x3fffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                                0x2000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                       25u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                          0xf00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                                20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                             0x80000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                  19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                                 0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                      18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                                 0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                      17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                              0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                   16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                             0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                                 15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                            0x7800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                                11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                    0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                       10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                             0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                                 9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                             0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                                 8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                                 0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                    7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                        0x60u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                           5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                     4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                          0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                            2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                             0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x174u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x174u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_RMSK                                                    0x7fffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                        0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                             18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                    0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                         17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                  0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                       16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                      0xf000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                          12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                               0xf00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                   8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                  0xf0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                     4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                      0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x178u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x178u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_RMSK                                                  0x7fffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK                0x4000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                       26u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                             0x2000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                    25u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                        0x1e00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                               21u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                         0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                               20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK                0x80000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                     19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                    0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                         18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                     0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                          17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                          0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                               16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                  0xff00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                       8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                   0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                      0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x17cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x17cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_RMSK                                                   0xfffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                     0xf00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                           20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                      0xf0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                           16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                      0xf000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                          12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                     0xf00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                         8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                           0xf0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                              4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_RETAINFF_BMSK                                           0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC5_CFG4_GDSCR_DLY_RETAINFF_SHFT                                             0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x180u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x180u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x184u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x184u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x188u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x188u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x18cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x18cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x190u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x190u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH0_MC5_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x194u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x194u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH1_MC5_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x198u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x198u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_CFG_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x19cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x19cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH01_MC5_ATB_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1a0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1a0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1a4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1a4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1a8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1a8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1acu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1acu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1b0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1b0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH2_MC5_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1b4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1b4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH3_MC5_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1b8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1b8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_CFG_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1bcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1bcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH23_MC5_ATB_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1c0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1c0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1c4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1c4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_RMSK                                                0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_SW_ONLY_EN_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_SW_ONLY_EN_SHFT                                              3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_HW_CTL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_HW_CTL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_HW_CTL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_HW_CTL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1c8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1c8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_ADDR                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1ccu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_OFFS                                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1ccu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_RMSK                                             0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_OFF_BMSK                                     0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_OFF_SHFT                                             31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                              0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                     24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                            0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                  23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_DIS_BMSK                                       0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_DIS_SHFT                                             22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_SW_ONLY_EN_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_SW_ONLY_EN_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_ARES_BMSK                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_ARES_SHFT                                             2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_HW_CTL_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_HW_CTL_SHFT                                               1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_HW_CTL_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_HW_CTL_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_ENABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_ENABLE_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                  0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1d0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1d0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH4_MC5_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1d4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1d4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH5_MC5_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1d8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1d8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_CFG_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1dcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1dcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_RMSK                                              0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_SW_ONLY_EN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_SW_ONLY_EN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_HW_CTL_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_HW_CTL_SHFT                                                1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_HW_CTL_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_HW_CTL_ENABLE_FVAL                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_CH45_MC5_ATB_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_ADDR                                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1e0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_OFFS                                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1e0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_RMSK                                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_BLK_ARES_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_BLK_ARES_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_BLK_ARES_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_BCR_BLK_ARES_ENABLE_FVAL                                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1e4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1e4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1e8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1e8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_RMSK                                                0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1ecu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1ecu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_RMSK                                                  0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_OFF_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_OFF_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_IGNORE_ALL_ARES_BMSK                                   0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_IGNORE_ALL_ARES_SHFT                                          24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                 0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                       23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_DIS_BMSK                                            0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_DIS_SHFT                                                  22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_ARES_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_ARES_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_ARES_NO_RESET_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_ARES_RESET_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_ENABLE_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_ENABLE_SHFT                                                0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_ENABLE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_ATB_CBCR_CLK_ENABLE_ENABLE_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1f0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1f0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_RMSK                                               0x81c00004ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_CLK_OFF_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_CLK_OFF_SHFT                                               31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_IGNORE_ALL_ARES_BMSK                                0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_IGNORE_ALL_ARES_SHFT                                       24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                              0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                    23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_CLK_DIS_BMSK                                         0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_CLK_DIS_SHFT                                               22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_CLK_ARES_BMSK                                             0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_CLK_ARES_SHFT                                               2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_CLK_ARES_NO_RESET_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_XO_REF_CBCR_CLK_ARES_RESET_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1f4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1f4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1f8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1f8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_RMSK                                                0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1fcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1fcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_RMSK                                                  0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_OFF_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_OFF_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_IGNORE_ALL_ARES_BMSK                                   0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_IGNORE_ALL_ARES_SHFT                                          24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                 0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                       23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_DIS_BMSK                                            0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_DIS_SHFT                                                  22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_ARES_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_ARES_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_ARES_NO_RESET_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_ARES_RESET_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_ENABLE_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_ENABLE_SHFT                                                0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_ENABLE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_ATB_CBCR_CLK_ENABLE_ENABLE_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x200u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x200u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_RMSK                                               0x81c00004ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_CLK_OFF_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_CLK_OFF_SHFT                                               31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_IGNORE_ALL_ARES_BMSK                                0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_IGNORE_ALL_ARES_SHFT                                       24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                              0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                    23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_CLK_DIS_BMSK                                         0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_CLK_DIS_SHFT                                               22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_CLK_ARES_BMSK                                             0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_CLK_ARES_SHFT                                               2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_CLK_ARES_NO_RESET_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_XO_REF_CBCR_CLK_ARES_RESET_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x204u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x204u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x208u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x208u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_RMSK                                                0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                                 0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                        24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                               0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                     23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_DIS_BMSK                                          0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_DIS_SHFT                                                22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_ARES_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_ARES_SHFT                                                2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_ENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_ENABLE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x20cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x20cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_RMSK                                                  0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_OFF_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_OFF_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_IGNORE_ALL_ARES_BMSK                                   0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_IGNORE_ALL_ARES_SHFT                                          24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                 0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                       23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_DIS_BMSK                                            0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_DIS_SHFT                                                  22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_ARES_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_ARES_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_ARES_NO_RESET_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_ARES_RESET_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_ENABLE_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_ENABLE_SHFT                                                0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_ENABLE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_ATB_CBCR_CLK_ENABLE_ENABLE_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x210u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x210u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_RMSK                                               0x81c00004ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_CLK_OFF_BMSK                                       0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_CLK_OFF_SHFT                                               31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_IGNORE_ALL_ARES_BMSK                                0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_IGNORE_ALL_ARES_SHFT                                       24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                              0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                    23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_CLK_DIS_BMSK                                         0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_CLK_DIS_SHFT                                               22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_CLK_ARES_BMSK                                             0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_CLK_ARES_SHFT                                               2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_CLK_ARES_NO_RESET_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_XO_REF_CBCR_CLK_ARES_RESET_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_ADDR                                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x214u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_OFFS                                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x214u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_RMSK                                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_BLK_ARES_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_BLK_ARES_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_BLK_ARES_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_BCR_BLK_ARES_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x218u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x218u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_ADDR                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x21cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_OFFS                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x21cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_RMSK                                                      0x81c07ffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_OFF_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_OFF_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_IGNORE_ALL_ARES_SHFT                                              24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_DIS_BMSK                                                0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_DIS_SHFT                                                      22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_CORE_ON_BMSK                                        0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_CORE_ON_SHFT                                            14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                      0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                          13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                     0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                         12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_BMSK                                                    0xf00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_SHFT                                                        8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK0_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK2_FVAL                                               0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK3_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK4_FVAL                                               0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK5_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK6_FVAL                                               0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK7_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK8_FVAL                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK9_FVAL                                               0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK10_FVAL                                              0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK11_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK12_FVAL                                              0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK13_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK14_FVAL                                              0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_WAKEUP_CLOCK15_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_BMSK                                                      0xf0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_SHFT                                                         4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK0_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK1_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK2_FVAL                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK3_FVAL                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK4_FVAL                                                0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK5_FVAL                                                0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK6_FVAL                                                0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK7_FVAL                                                0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK8_FVAL                                                0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK9_FVAL                                                0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK10_FVAL                                               0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK11_FVAL                                               0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK12_FVAL                                               0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK13_FVAL                                               0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK14_FVAL                                               0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SLEEP_CLOCK15_FVAL                                               0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SW_ONLY_EN_BMSK                                                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_SW_ONLY_EN_SHFT                                                    3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_ARES_BMSK                                                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_ARES_SHFT                                                      2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_ARES_RESET_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_HW_CTL_BMSK                                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_HW_CTL_SHFT                                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_HW_CTL_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_HW_CTL_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_ENABLE_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_ENABLE_SHFT                                                    0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_ADDR                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x220u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_OFFS                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x220u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_RMSK                                                     0xfffffffeul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                           0xff000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                   24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                              0xff0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                    16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                 0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                     15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                  0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                      14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                     13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                 12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CORE_ON_ACK_BMSK                                          0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CORE_ON_ACK_SHFT                                             11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_PERIPH_ON_ACK_BMSK                                        0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_PERIPH_ON_ACK_SHFT                                           10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                 0x300u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                     8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                          0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                          0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CPH_ENABLE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CPH_ENABLE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_FORCE_CLK_ON_BMSK                                              0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_FORCE_CLK_ON_SHFT                                                 6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_RST_SEL_SLP_STG_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_RST_SEL_SLP_STG_SHFT                                           5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_RST_SLP_STG_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_RST_SLP_STG_SHFT                                               4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CTRL_PWR_DOWN_BMSK                                           0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CTRL_PWR_DOWN_SHFT                                             3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                        2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CLK_EN_SLP_STG_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CLK_EN_SLP_STG_SHFT                                            1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHRM_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_ADDR                                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x224u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_OFFS                                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x224u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_RMSK                                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_BLK_ARES_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_BLK_ARES_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_BLK_ARES_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_BCR_BLK_ARES_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x228u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x228u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_RMSK                                                   0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_ADDR                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x22cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_OFFS                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x22cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_RMSK                                                      0x81c0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_OFF_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_OFF_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_IGNORE_ALL_ARES_SHFT                                              24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_DIS_BMSK                                                0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_DIS_SHFT                                                      22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_SW_ONLY_EN_BMSK                                                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_SW_ONLY_EN_SHFT                                                    3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_ARES_BMSK                                                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_ARES_SHFT                                                      2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_ARES_RESET_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_HW_CTL_BMSK                                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_HW_CTL_SHFT                                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_HW_CTL_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_HW_CTL_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_ENABLE_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_ENABLE_SHFT                                                    0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MCCC_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x230u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x230u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_RMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_BLK_ARES_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_BLK_ARES_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_BLK_ARES_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_BCR_BLK_ARES_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x234u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x234u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_RMSK                                                    0x80000013ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ROOT_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ROOT_EN_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ROOT_EN_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_UPDATE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_UPDATE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x238u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x238u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_RMSK                                                      0x11071ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_RCGLITE_DISABLE_BMSK                                       0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_RCGLITE_DISABLE_SHFT                                            16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_BMSK                                                 0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_SHFT                                                     8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x24cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x24cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_RMSK                                                 0x80000013ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ROOT_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ROOT_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                           4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ROOT_EN_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ROOT_EN_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_UPDATE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_UPDATE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_UPDATE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CMD_RCGR_UPDATE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x250u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x250u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_RMSK                                                   0x11071ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_BMSK                                    0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_SHFT                                          20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_BMSK                                    0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_SHFT                                         16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_BMSK                                              0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_SHFT                                                  8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_SRC0_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_SRC1_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_SRC2_FVAL                                           0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_SRC3_FVAL                                           0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_SRC4_FVAL                                           0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_SRC5_FVAL                                           0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_SRC6_FVAL                                           0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_SEL_SRC7_FVAL                                           0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_BMSK                                               0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV1_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                         0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV2_FVAL                                           0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                         0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV3_FVAL                                           0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                         0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV4_FVAL                                           0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV5_FVAL                                           0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                         0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV6_FVAL                                           0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                         0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV7_FVAL                                           0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                         0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV8_FVAL                                           0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                        0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV9_FVAL                                          0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                        0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV10_FVAL                                         0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                       0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV11_FVAL                                         0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                       0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV12_FVAL                                         0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                       0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV13_FVAL                                         0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                       0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV14_FVAL                                         0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                       0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV15_FVAL                                         0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                       0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CFG_RCGR_SRC_DIV_DIV16_FVAL                                         0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_ADDR                                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x264u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_OFFS                                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x264u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_RMSK                                                        0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_OFF_BMSK                                                0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_OFF_SHFT                                                        31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_IGNORE_ALL_ARES_SHFT                                                24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_DIS_BMSK                                                  0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_DIS_SHFT                                                        22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_ARES_BMSK                                                      0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_ARES_SHFT                                                        2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_ARES_RESET_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_ENABLE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_ENABLE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x268u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x268u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_RMSK                                              0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_OFF_BMSK                                      0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_OFF_SHFT                                              31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_IGNORE_ALL_ARES_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_IGNORE_ALL_ARES_SHFT                                      24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                             0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                   23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_DIS_BMSK                                        0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_DIS_SHFT                                              22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_ARES_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_ARES_SHFT                                              2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_ARES_RESET_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_ENABLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_ENABLE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DDRSS_TOP_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x26cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x26cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_RMSK                                                   0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_AHB2PHY_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_ADDR                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x270u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_OFFS                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x270u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_RMSK                                                    0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_IGNORE_ALL_ARES_BMSK                                     0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_IGNORE_ALL_ARES_SHFT                                            24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                   0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                         23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_DIS_BMSK                                              0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_DIS_SHFT                                                    22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_ARES_BMSK                                                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_ARES_SHFT                                                    2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_ARES_RESET_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_ENABLE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_ENABLE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TGU_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x274u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x274u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_RMSK                                          0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_OFF_BMSK                                  0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_OFF_SHFT                                          31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_ARES_BMSK                           0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_ARES_SHFT                                  24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_CLK_DIS_BMSK                         0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_CLK_DIS_SHFT                               23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_DIS_BMSK                                    0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_DIS_SHFT                                          22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_ARES_BMSK                                        0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_ARES_SHFT                                          2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_ARES_NO_RESET_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_ARES_RESET_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_SHFT                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_ENABLE_FVAL                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_ADDR                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x278u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_OFFS                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x278u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_RMSK                                                     0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                             24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_DIS_BMSK                                               0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_DIS_SHFT                                                     22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_ARES_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_ARES_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_ENABLE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_ENABLE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_ADDR                                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x27cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_OFFS                                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x27cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_RMSK                                                   0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_CLK_DIV_BMSK                                           0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_DIV_CDIVR_CLK_DIV_SHFT                                             0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x280u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x280u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_RMSK                                                 0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_IGNORE_ALL_ARES_SHFT                                         24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_DIS_BMSK                                           0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_DIS_SHFT                                                 22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_ARES_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_ARES_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_ARES_RESET_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DCNOC_CFG_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x284u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x284u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_RMSK                                                   0x81d0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_IGNORE_RPMH_CLK_DIS_BMSK                                 0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_IGNORE_RPMH_CLK_DIS_SHFT                                       20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_ADDR                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x288u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_OFFS                                                   (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x288u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_RMSK                                                   0x81d0000ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_IGNORE_ALL_ARES_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_IGNORE_ALL_ARES_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                  0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                        23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_DIS_BMSK                                             0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_DIS_SHFT                                                   22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_IGNORE_RPMH_CLK_DIS_BMSK                                 0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_IGNORE_RPMH_CLK_DIS_SHFT                                       20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_SW_ONLY_EN_BMSK                                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_SW_ONLY_EN_SHFT                                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_ARES_BMSK                                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_ARES_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_ARES_NO_RESET_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_ARES_RESET_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_HW_CTL_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_HW_CTL_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_HW_CTL_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_HW_CTL_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_ENABLE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_ENABLE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_CBCR_CLK_ENABLE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x28cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x28cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_RMSK                                          0x80000013ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ROOT_OFF_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ROOT_OFF_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                    4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ROOT_EN_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ROOT_EN_SHFT                                           1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_UPDATE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_UPDATE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_UPDATE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CMD_RCGR_UPDATE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x290u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x290u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_RMSK                                            0x11071ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_HW_CLK_CONTROL_BMSK                             0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_HW_CLK_CONTROL_SHFT                                   20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_RCGLITE_DISABLE_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_RCGLITE_DISABLE_SHFT                                  16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_BMSK                                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_SHFT                                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_SRC0_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_SRC1_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_SRC2_FVAL                                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_SRC3_FVAL                                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_SRC4_FVAL                                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_SRC5_FVAL                                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_SRC6_FVAL                                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_SEL_SRC7_FVAL                                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_BMSK                                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV1_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV2_FVAL                                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV3_FVAL                                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV4_FVAL                                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV5_FVAL                                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV6_FVAL                                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV7_FVAL                                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV8_FVAL                                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV9_FVAL                                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV10_FVAL                                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV11_FVAL                                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV12_FVAL                                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV13_FVAL                                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV14_FVAL                                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV15_FVAL                                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_CFG_RCGR_SRC_DIV_DIV16_FVAL                                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2a0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2a0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_RMSK                                              0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_RCG_SW_CTRL_BMSK                                  0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_RCG_SW_CTRL_SHFT                                      15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_SW_PERF_STATE_BMSK                                0x7800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_SW_PERF_STATE_SHFT                                    11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_SW_OVERRIDE_BMSK                                   0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_SW_OVERRIDE_SHFT                                      10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_PERF_STATE_UPDATE_STATUS_BMSK                      0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_PERF_STATE_UPDATE_STATUS_SHFT                          9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_DFS_FSM_STATE_BMSK                                 0x1c0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_DFS_FSM_STATE_SHFT                                     6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_HW_CLK_CONTROL_BMSK                                 0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_HW_CLK_CONTROL_SHFT                                    5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_CURR_PERF_STATE_BMSK                                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_CURR_PERF_STATE_SHFT                                   1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_DFS_EN_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_DFS_EN_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_DFS_EN_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_CMD_DFSR_DFS_EN_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2a8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2a8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF0_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2acu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2acu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF1_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2b0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2b0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF2_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2b4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2b4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF3_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2b8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2b8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF4_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2bcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2bcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF5_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2c0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2c0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF6_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2c4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2c4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF7_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2c8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2c8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF8_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2ccu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2ccu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF9_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2d0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2d0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF10_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2d4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2d4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF11_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2d8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2d8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF12_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2dcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2dcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF13_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2e0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2e0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF14_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2e4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2e4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC0_MC_SRC0_ROOT_PERF15_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_ADDR                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3b8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_OFFS                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3b8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_RMSK                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_DCD_ENABLE_BMSK                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_DCD_ENABLE_SHFT                                    0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_DCD_ENABLE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC0_ROOT_DCD_DIV_DCDR_DCD_ENABLE_ENABLE_FVAL                           0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3bcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3bcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_RMSK                                          0x80000013ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ROOT_OFF_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ROOT_OFF_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                    4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ROOT_EN_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ROOT_EN_SHFT                                           1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_UPDATE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_UPDATE_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_UPDATE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CMD_RCGR_UPDATE_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3c0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3c0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_RMSK                                            0x11071ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_HW_CLK_CONTROL_BMSK                             0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_HW_CLK_CONTROL_SHFT                                   20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_RCGLITE_DISABLE_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_RCGLITE_DISABLE_SHFT                                  16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_BMSK                                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_SHFT                                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_SRC0_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_SRC1_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_SRC2_FVAL                                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_SRC3_FVAL                                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_SRC4_FVAL                                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_SRC5_FVAL                                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_SRC6_FVAL                                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_SEL_SRC7_FVAL                                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_BMSK                                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_SHFT                                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV1_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV2_FVAL                                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV3_FVAL                                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV4_FVAL                                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV5_FVAL                                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV6_FVAL                                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV7_FVAL                                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV8_FVAL                                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV9_FVAL                                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV10_FVAL                                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV11_FVAL                                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV12_FVAL                                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV13_FVAL                                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV14_FVAL                                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV15_FVAL                                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_CFG_RCGR_SRC_DIV_DIV16_FVAL                                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3d0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3d0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_RMSK                                              0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_RCG_SW_CTRL_BMSK                                  0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_RCG_SW_CTRL_SHFT                                      15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_SW_PERF_STATE_BMSK                                0x7800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_SW_PERF_STATE_SHFT                                    11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_SW_OVERRIDE_BMSK                                   0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_SW_OVERRIDE_SHFT                                      10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_PERF_STATE_UPDATE_STATUS_BMSK                      0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_PERF_STATE_UPDATE_STATUS_SHFT                          9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_DFS_FSM_STATE_BMSK                                 0x1c0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_DFS_FSM_STATE_SHFT                                     6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_HW_CLK_CONTROL_BMSK                                 0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_HW_CLK_CONTROL_SHFT                                    5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_CURR_PERF_STATE_BMSK                                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_CURR_PERF_STATE_SHFT                                   1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_DFS_EN_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_DFS_EN_SHFT                                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_DFS_EN_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_CMD_DFSR_DFS_EN_ENABLE_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3d8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3d8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF0_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3dcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3dcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF1_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3e0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3e0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF2_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3e4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3e4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF3_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3e8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3e8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF4_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3ecu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3ecu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF5_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3f0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3f0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF6_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3f4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3f4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF7_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3f8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3f8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF8_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_ADDR                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3fcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_OFFS                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3fcu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_RMSK                                0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_BMSK                        0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_SHFT                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_SRC0_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_SRC1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_SRC2_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_SRC3_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_SRC4_FVAL                     0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_SRC5_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_SRC6_FVAL                     0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_SEL_SRC7_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_BMSK                         0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_SHFT                            0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_BYPASS_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV1_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV1_5_FVAL                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV2_FVAL                     0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV2_5_FVAL                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV3_FVAL                     0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV3_5_FVAL                   0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV4_FVAL                     0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV4_5_FVAL                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV5_FVAL                     0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV5_5_FVAL                   0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV6_FVAL                     0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV6_5_FVAL                   0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV7_FVAL                     0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV7_5_FVAL                   0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV8_FVAL                     0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV8_5_FVAL                  0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV9_FVAL                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV9_5_FVAL                  0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV10_FVAL                   0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV10_5_FVAL                 0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV11_FVAL                   0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV11_5_FVAL                 0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV12_FVAL                   0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV12_5_FVAL                 0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV13_FVAL                   0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV13_5_FVAL                 0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV14_FVAL                   0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV14_5_FVAL                 0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV15_FVAL                   0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV15_5_FVAL                 0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF9_DFSR_SRC_DIV_DIV16_FVAL                   0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x400u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x400u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF10_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x404u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x404u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF11_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x408u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x408u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF12_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x40cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x40cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF13_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x410u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x410u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF14_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_ADDR                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x414u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_OFFS                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x414u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_RMSK                               0x71fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_SHFT                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_SRC0_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_SRC1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_SRC2_FVAL                    0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_SRC3_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_SRC4_FVAL                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_SRC5_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_SRC6_FVAL                    0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_SEL_SRC7_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_BMSK                        0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_SHFT                           0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_BYPASS_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV1_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV1_5_FVAL                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV2_FVAL                    0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV2_5_FVAL                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV3_FVAL                    0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV3_5_FVAL                  0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV4_FVAL                    0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV4_5_FVAL                  0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV5_FVAL                    0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV5_5_FVAL                  0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV6_FVAL                    0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV6_5_FVAL                  0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV7_FVAL                    0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV7_5_FVAL                  0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV8_FVAL                    0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV8_5_FVAL                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV9_FVAL                   0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV9_5_FVAL                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV10_FVAL                  0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV10_5_FVAL                0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV11_FVAL                  0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV11_5_FVAL                0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV12_FVAL                  0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV12_5_FVAL                0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV13_FVAL                  0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV13_5_FVAL                0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV14_FVAL                  0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV14_5_FVAL                0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV15_FVAL                  0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV15_5_FVAL                0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_SRC1_MC_SRC1_ROOT_PERF15_DFSR_SRC_DIV_DIV16_FVAL                  0x1fu

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_ADDR                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x4e8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_OFFS                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x4e8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_RMSK                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_DCD_ENABLE_BMSK                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_DCD_ENABLE_SHFT                                    0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_DCD_ENABLE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_SRC1_ROOT_DCD_DIV_DCDR_DCD_ENABLE_ENABLE_FVAL                           0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_ADDR                                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x4ecu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_OFFS                                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x4ecu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_RMSK                                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_BLK_ARES_BMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_BLK_ARES_SHFT                                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_BLK_ARES_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_BCR_BLK_ARES_ENABLE_FVAL                                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_ADDR                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x4f0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_OFFS                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x4f0u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_RMSK                                                    0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_IGNORE_ALL_ARES_BMSK                                     0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_IGNORE_ALL_ARES_SHFT                                            24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                   0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                         23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_DIS_BMSK                                              0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_DIS_SHFT                                                    22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_ARES_BMSK                                                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_ARES_SHFT                                                    2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_ARES_NO_RESET_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_ARES_RESET_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_ENABLE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_ENABLE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_ENABLE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_CB_CBCR_CLK_ENABLE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x4f4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x4f4u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_RMSK                                                  0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_OFF_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_OFF_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_IGNORE_ALL_ARES_BMSK                                   0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_IGNORE_ALL_ARES_SHFT                                          24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                 0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                       23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_DIS_BMSK                                            0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_DIS_SHFT                                                  22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_ARES_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_ARES_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_ARES_NO_RESET_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_ARES_RESET_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_ENABLE_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_ENABLE_SHFT                                                0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_ENABLE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHUB_CBCR_CLK_ENABLE_ENABLE_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x4f8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x4f8u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_RMSK                                                  0x81c00005ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_OFF_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_OFF_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_IGNORE_ALL_ARES_BMSK                                   0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_IGNORE_ALL_ARES_SHFT                                          24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                 0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                       23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_DIS_BMSK                                            0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_DIS_SHFT                                                  22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_ARES_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_ARES_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_ARES_NO_RESET_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_ARES_RESET_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_ENABLE_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_ENABLE_SHFT                                                0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_ENABLE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DPM_SHRM_CBCR_CLK_ENABLE_ENABLE_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x700u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x700u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_RMSK                                                       0x7fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_BMSK                                               0x7fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_BI_TCXO_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_CORE_PI_SLEEP_CLK_FVAL                              0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_CORE_BI_PLL_TEST_SE_FVAL                            0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_GEMNOC_XO_CLK_FVAL                             0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_LLCC0_SHUB_CLK_FVAL                            0x5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_LLCC1_SHUB_CLK_FVAL                            0x6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_LAGG_SHUB_CLK_FVAL                             0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_GEMNOC_SHUB_CLK_FVAL                           0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_GEMNOC_SHUB_SLP_STG_CLK_FVAL                   0x9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_NSPNOC_CLK_FVAL                                0xau
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_GPU_CLK_FVAL                                   0xbu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_MNOC_HF_CLK_FVAL                               0xcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_MNOC_SF_CLK_FVAL                               0xdu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CNOC_SF_CLK_FVAL                               0xeu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SNOC_GC_CLK_FVAL                               0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SNOC_SF_CLK_FVAL                              0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SYS_TCU_CLK_FVAL                              0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SAIL_CLK_FVAL                                 0x12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SHUB_CH01_CFG_CLK_FVAL                        0x13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SHUB_CH01_ATB_CLK_FVAL                        0x14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SHUB_TS_CLK_FVAL                              0x15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PCIE_SF_CLK_FVAL                              0x16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_LLCC2_SHUB_CLK_FVAL                           0x17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_LLCC3_SHUB_CLK_FVAL                           0x18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SHUB_CH23_CFG_CLK_FVAL                        0x19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SHUB_CH23_ATB_CLK_FVAL                        0x1au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_LLCC4_SHUB_CLK_FVAL                           0x1bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_LLCC5_SHUB_CLK_FVAL                           0x1cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SHUB_CH45_CFG_CLK_FVAL                        0x1du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SHUB_CH45_ATB_CLK_FVAL                        0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH0_MC5_XO_CLK_FVAL                           0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH1_MC5_XO_CLK_FVAL                           0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH0_MC5_SLEEP_CLK_FVAL                        0x21u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH1_MC5_SLEEP_CLK_FVAL                        0x22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH0_MC5_SHUB_CLK_FVAL                         0x23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH1_MC5_SHUB_CLK_FVAL                         0x24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH01_MC5_CFG_CLK_FVAL                         0x25u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH01_MC5_ATB_CLK_FVAL                         0x26u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH2_MC5_XO_CLK_FVAL                           0x27u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH3_MC5_XO_CLK_FVAL                           0x28u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH2_MC5_SLEEP_CLK_FVAL                        0x29u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH3_MC5_SLEEP_CLK_FVAL                        0x2au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH2_MC5_SHUB_CLK_FVAL                         0x2bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH3_MC5_SHUB_CLK_FVAL                         0x2cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH23_MC5_CFG_CLK_FVAL                         0x2du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH23_MC5_ATB_CLK_FVAL                         0x2eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH4_MC5_XO_CLK_FVAL                           0x2fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH5_MC5_XO_CLK_FVAL                           0x30u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH4_MC5_SLEEP_CLK_FVAL                        0x31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH5_MC5_SLEEP_CLK_FVAL                        0x32u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH4_MC5_SHUB_CLK_FVAL                         0x33u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH5_MC5_SHUB_CLK_FVAL                         0x34u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH45_MC5_CFG_CLK_FVAL                         0x35u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_CH45_MC5_ATB_CLK_FVAL                         0x36u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY0_XO_CLK_FVAL                              0x37u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY0_SLEEP_CLK_FVAL                           0x38u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY0_ATB_CLK_FVAL                             0x39u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY0_XO_REF_CLK_FVAL                          0x3au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY1_XO_CLK_FVAL                              0x3bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY1_SLEEP_CLK_FVAL                           0x3cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY1_ATB_CLK_FVAL                             0x3du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY1_XO_REF_CLK_FVAL                          0x3eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY2_XO_CLK_FVAL                              0x3fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY2_SLEEP_CLK_FVAL                           0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY2_ATB_CLK_FVAL                             0x41u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PHY2_XO_REF_CLK_FVAL                          0x42u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SHRM_XO_CLK_FVAL                              0x43u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SHRM_CLK_FVAL                                 0x44u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_MCCC_XO_CLK_FVAL                              0x45u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_MCCC_CLK_FVAL                                 0x46u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_XO_CLK_FVAL                                   0x47u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_DDRSS_TOP_XO_CLK_FVAL                         0x48u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_AHB2PHY_CLK_FVAL                              0x49u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_TGU_XO_CLK_FVAL                               0x4au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_PLL_LOCK_MONITOR_CLK_FVAL                     0x4bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_SLEEP_CLK_FVAL                                0x4cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_DCNOC_CFG_CLK_FVAL                            0x4du
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_MC_SRC0_CLK_FVAL                              0x4eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_MC_SRC1_CLK_FVAL                              0x4fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_DPM_CB_CLK_FVAL                               0x50u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_DPM_SHUB_CLK_FVAL                             0x51u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_DPM_SHRM_CLK_FVAL                             0x52u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_MCCC_MSTR_DEBUG_CLK_FVAL                           0x53u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DDRPHY0_PLL_TEST_CLK_FVAL                          0x54u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DDRPHY1_PLL_TEST_CLK_FVAL                          0x55u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DDRPHY2_PLL_TEST_CLK_FVAL                          0x56u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_MCCC_SLV0_PLL_TEST_CLK_FVAL                        0x57u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_MCCC_SLV1_PLL_TEST_CLK_FVAL                        0x58u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_MCCC_SLV2_PLL_TEST_CLK_FVAL                        0x59u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_MCCC_SLV3_PLL_TEST_CLK_FVAL                        0x5au
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_MCCC_SLV4_PLL_TEST_CLK_FVAL                        0x5bu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_MCCC_SLV5_PLL_TEST_CLK_FVAL                        0x5cu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_MUX_MUXR_MUX_SEL_DPCC_NSPNOC1_CLK_FVAL                              0x5du

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x704u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x704u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_RMSK                                                    0x3fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_MUX_SEL_BMSK                                            0x3fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_TEST_MUX_MUXR_MUX_SEL_SHFT                                               0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_STATUS_ADDR                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x80cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_STATUS_OFFS                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x80cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_STATUS_RMSK                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_STATUS_STATUS_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_STATUS_STATUS_SHFT                                      0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_ADDR                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x810u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_OFFS                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x810u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_RMSK                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_MASK_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_MASK_MASK_SHFT                                          0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_ADDR                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x814u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_OFFS                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x814u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_RMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_CLEAR_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IRQ_CLEAR_CLEAR_SHFT                                        0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x818u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x818u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_RMSK                                               0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_SPARE_BMSK                                         0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SPARE_SPARE_SHFT                                            0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_ADDR                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x830u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_OFFS                                       (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x830u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_RMSK                                             0x37u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_MC_ACTIVE_SEL_BMSK                               0x30u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_MC_ACTIVE_SEL_SHFT                                  4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_SHUB_ACTIVE_SEL_BMSK                              0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_CFG_SHUB_ACTIVE_SEL_SHFT                                0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_ADDR                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x834u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_OFFS                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x834u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_RMSK                                         0x3f1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_MC_ACTIVE_BMSK                               0x3f0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_MC_ACTIVE_SHFT                                   4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_SHUB_ACTIVE_BMSK                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FAL_TOL_DDRSS_ACTIVE_STATUS_SHUB_ACTIVE_SHFT                                 0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_ADDR                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x840u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_OFFS                                                     (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x840u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_RMSK                                                     0x7ffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_DPCC_MODE_BMSK                                        0x40000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_DPCC_MODE_SHFT                                                30u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_PLL_PRE_WORK_OVRD_BMSK                                0x20000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_PLL_PRE_WORK_OVRD_SHFT                                        29u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_PLL_POST_WORK_OVRD_BMSK                               0x10000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_PLL_POST_WORK_OVRD_SHFT                                       28u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_PERF_CHNG_OVRD_BMSK                               0x8000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_PERF_CHNG_OVRD_SHFT                                      27u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_PERF_CHNG_OVRD_BMSK                               0x4000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_PERF_CHNG_OVRD_SHFT                                      26u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_PERF_STATE_OVRD_BMSK                              0x3c00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_PERF_STATE_OVRD_SHFT                                     22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_PERF_STATE_OVRD_BMSK                               0x3c0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_PERF_STATE_OVRD_SHFT                                     18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_SRC_SEL_OVRD_BMSK                                   0x38000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_SRC_SEL_OVRD_SHFT                                        15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_SRC_SEL_OVRD_BMSK                                    0x7000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_SRC_SEL_OVRD_SHFT                                        12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_DFS_SRC_SEL_BMSK                                      0xe00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_DFS_SRC_SEL_SHFT                                          9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_DFS_SRC_SEL_BMSK                                      0x1c0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_DFS_SRC_SEL_SHFT                                          6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_PERF_CHANGE_DONE_BMSK                                       0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_PERF_CHANGE_DONE_SHFT                                          5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_PLL_PRE_WORK_DONE_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_PLL_PRE_WORK_DONE_SHFT                                         4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_PERF_CHANGE_DONE_BMSK                                   0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC1_PERF_CHANGE_DONE_SHFT                                     3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_PERF_CHANGE_DONE_BMSK                                   0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_MC_SRC0_PERF_CHANGE_DONE_SHFT                                     2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_PLL1_IN_STANDBY_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_PLL1_IN_STANDBY_SHFT                                              1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_PLL0_IN_STANDBY_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FSW_STATUS_PLL0_IN_STANDBY_SHFT                                              0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x844u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x844u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_RMSK                                                     0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_MC_SRC1_CLK_ON_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_MC_SRC1_CLK_ON_SHFT                                         4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_MC_SRC0_CLK_ON_BMSK                                       0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_MC_SRC0_CLK_ON_SHFT                                         3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_SLEEP_CLK_ANY_CBC_ON_BMSK                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_SLEEP_CLK_ANY_CBC_ON_SHFT                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_SLEEP_CLK_SRC_ON_BMSK                                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_SLEEP_CLK_SRC_ON_SHFT                                       1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_XO_CLK_SRC_ON_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RCG_CLKON_STATUS_XO_CLK_SRC_ON_SHFT                                          0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x850u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x850u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_RMSK                                                        0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_SW_FREEZEIO_1_SET_BMSK                                      0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_SW_FREEZEIO_1_SET_SHFT                                        3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_SW_FREEZEIO_1_RESET_BMSK                                    0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_SW_FREEZEIO_1_RESET_SHFT                                      2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_SW_FREEZEIO_0_SET_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_SW_FREEZEIO_0_SET_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_SW_FREEZEIO_0_RESET_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_CTRL_SW_FREEZEIO_0_RESET_SHFT                                      0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x854u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x854u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_RMSK                                                   0x127fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_MC_PRE_ARES_DONE_BMSK                                  0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_MC_PRE_ARES_DONE_SHFT                                      12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_PHY_FREEZE_IO_1_PREDFT_BMSK                             0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_PHY_FREEZE_IO_1_PREDFT_SHFT                                 9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_PHY_FREEZE_IO_0_PREDFT_BMSK                              0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_PHY_FREEZE_IO_0_PREDFT_SHFT                                 6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_PHY_FREEZE_IO_1_BMSK                                     0x38u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_PHY_FREEZE_IO_1_SHFT                                        3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_PHY_FREEZE_IO_0_BMSK                                      0x7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FREEZE_IO_STATUS_PHY_FREEZE_IO_0_SHFT                                        0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x858u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x858u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_RMSK                                                     0x7313u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_MEM_PWR_DWN_LPBK_BMSK                               0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_MEM_PWR_DWN_LPBK_SHFT                                   14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_QACCEPTN_LPBK_BMSK                                  0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_QACCEPTN_LPBK_SHFT                                      13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_SW_COLLAPSE_BYPASS_MASK_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_SW_COLLAPSE_BYPASS_MASK_SHFT                                 12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_MEM_PWR_DWN_BMSK                                     0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_MEM_PWR_DWN_SHFT                                         9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_MEM_PWR_DWN_SW_CTL_BMSK                              0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_MEM_PWR_DWN_SW_CTL_SHFT                                  8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_GEMNOC_MEM_RET_SW_CTL_BMSK                                 0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_GEMNOC_MEM_RET_SW_CTL_SHFT                                    4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_CLAMP_MEM_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_CLAMP_MEM_SHFT                                           1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_CLAMP_MEM_SW_CTL_BMSK                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_CTRL_LLCC_CLAMP_MEM_SW_CTL_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x860u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x860u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_RMSK                                                  0x1fff009ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_CLAMP_MEM_BMSK                                    0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_CLAMP_MEM_SHFT                                           24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_ENR_ACK_BMSK                                       0xfc0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_ENR_ACK_SHFT                                             18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_ENF_ACK_BMSK                                        0x3f000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_ENF_ACK_SHFT                                             12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_RETAIN_FF_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_RETAIN_FF_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_CLAMP_IO_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_STATUS_MC5_CLAMP_IO_SHFT                                             0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x864u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x864u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_RMSK                                                0xfffffc9ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_LLCC_PWR_DWN_ACK_BMSK                               0xfc00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_LLCC_PWR_DWN_ACK_SHFT                                      22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_GEMNOC_ENR_ACK_BMSK                                  0x200000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_GEMNOC_ENR_ACK_SHFT                                        21u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_GEMNOC_ENF_ACK_BMSK                                  0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_GEMNOC_ENF_ACK_SHFT                                        20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_LLCC_ENR_ACK_BMSK                                     0xfc000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_LLCC_ENR_ACK_SHFT                                          14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_LLCC_ENF_ACK_BMSK                                      0x3f00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_LLCC_ENF_ACK_SHFT                                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_LLCC_CLAMP_MEM_BMSK                                      0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_LLCC_CLAMP_MEM_SHFT                                         7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_GEMNOC_CLAMP_MEM_BMSK                                    0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_GEMNOC_CLAMP_MEM_SHFT                                       6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_SHUB_RETAIN_FF_BMSK                                       0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_SHUB_RETAIN_FF_SHFT                                         3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_SHUB_CLAMP_IO_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDSC_STATUS_SHUB_CLAMP_IO_SHFT                                          0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x868u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x868u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_RMSK                                                0x3ffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_CLAMP_MEM_BMSK                                  0x3f000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_CLAMP_MEM_SHFT                                          24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_RETAIN_FF_BMSK                                    0xfc0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_RETAIN_FF_SHFT                                          18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_CLAMP_CLKS_BMSK                                    0x3f000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_CLAMP_CLKS_SHFT                                         12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_CLAMP_DFT_BMSK                                       0xfc0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_CLAMP_DFT_SHFT                                           6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_CLAMP_IO_BMSK                                         0x3fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_GDSC_STATUS_PHY_CLAMP_IO_SHFT                                            0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x86cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x86cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_RMSK                                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_MC5_GDSC_EN_ACK_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_MC_GDSC_SW_OVRD_MC5_GDSC_EN_ACK_SHFT                                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_ADDR                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x870u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_OFFS                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x870u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_RMSK                                              0x73ffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_NSPNOC1_CLK_BMSK                                  0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_NSPNOC1_CLK_SHFT                                       18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SAIL_CLK_BMSK                                     0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SAIL_CLK_SHFT                                          17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_GPLL0_CLK_BMSK                                    0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_GPLL0_CLK_SHFT                                         16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_PHY_ATB_CLK_BMSK                                   0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_PHY_ATB_CLK_SHFT                                       13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_TS_CLK_BMSK                                        0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_TS_CLK_SHFT                                            12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_CNOC_SF_CLK_BMSK                                    0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_CNOC_SF_CLK_SHFT                                       11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SNOC_SF_CLK_BMSK                                    0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SNOC_SF_CLK_SHFT                                       10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SNOC_GC_CLK_BMSK                                    0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SNOC_GC_CLK_SHFT                                        9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SYS_TCU_CLK_BMSK                                    0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SYS_TCU_CLK_SHFT                                        8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_PCIE_SF_CLK_BMSK                                     0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_PCIE_SF_CLK_SHFT                                        7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_MNOC_SF_CLK_BMSK                                     0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_MNOC_SF_CLK_SHFT                                        6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_MNOC_HF_CLK_BMSK                                     0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_MNOC_HF_CLK_SHFT                                        5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_GPU_CLK_BMSK                                         0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_GPU_CLK_SHFT                                            4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_NSPNOC_CLK_BMSK                                       0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_NSPNOC_CLK_SHFT                                         3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_ATB_CLK_BMSK                                          0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_ATB_CLK_SHFT                                            2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SHUB_CLK_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SHUB_CLK_SHFT                                           1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SHRM_CLK_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_EN_SHRM_CLK_SHFT                                           0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x874u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x874u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_RMSK                                             0x73ffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_NSPNOC1_CLK_BMSK                                 0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_NSPNOC1_CLK_SHFT                                      18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SAIL_CLK_BMSK                                    0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SAIL_CLK_SHFT                                         17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_GPLL0_CLK_BMSK                                   0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_GPLL0_CLK_SHFT                                        16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_PHY_ATB_CLK_BMSK                                  0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_PHY_ATB_CLK_SHFT                                      13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_TS_CLK_BMSK                                       0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_TS_CLK_SHFT                                           12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_CNOC_SF_CLK_BMSK                                   0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_CNOC_SF_CLK_SHFT                                      11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SNOC_SF_CLK_BMSK                                   0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SNOC_SF_CLK_SHFT                                      10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SNOC_GC_CLK_BMSK                                   0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SNOC_GC_CLK_SHFT                                       9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SYS_TCU_CLK_BMSK                                   0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SYS_TCU_CLK_SHFT                                       8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_PCIE_SF_CLK_BMSK                                    0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_PCIE_SF_CLK_SHFT                                       7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_MNOC_SF_CLK_BMSK                                    0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_MNOC_SF_CLK_SHFT                                       6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_MNOC_HF_CLK_BMSK                                    0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_MNOC_HF_CLK_SHFT                                       5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_GPU_CLK_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_GPU_CLK_SHFT                                           4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_NSPNOC_CLK_BMSK                                      0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_NSPNOC_CLK_SHFT                                        3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_ATB_CLK_BMSK                                         0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_ATB_CLK_SHFT                                           2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SHUB_CLK_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SHUB_CLK_SHFT                                          1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SHRM_CLK_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_CSR_HW_DIS_SHRM_CLK_SHFT                                          0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x878u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x878u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_RMSK                                                 0x73ffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_NSPNOC1_CLK_BMSK                                     0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_NSPNOC1_CLK_SHFT                                          18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SAIL_CLK_BMSK                                        0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SAIL_CLK_SHFT                                             17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_GPLL0_CLK_BMSK                                       0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_GPLL0_CLK_SHFT                                            16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_PHY_ATB_CLK_BMSK                                      0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_PHY_ATB_CLK_SHFT                                          13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_TS_CLK_BMSK                                           0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_TS_CLK_SHFT                                               12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_CNOC_SF_CLK_BMSK                                       0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_CNOC_SF_CLK_SHFT                                          11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SNOC_SF_CLK_BMSK                                       0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SNOC_SF_CLK_SHFT                                          10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SNOC_GC_CLK_BMSK                                       0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SNOC_GC_CLK_SHFT                                           9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SYS_TCU_CLK_BMSK                                       0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SYS_TCU_CLK_SHFT                                           8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_PCIE_SF_CLK_BMSK                                        0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_PCIE_SF_CLK_SHFT                                           7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_MNOC_SF_CLK_BMSK                                        0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_MNOC_SF_CLK_SHFT                                           6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_MNOC_HF_CLK_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_MNOC_HF_CLK_SHFT                                           5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_GPU_CLK_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_GPU_CLK_SHFT                                               4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_NSPNOC_CLK_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_NSPNOC_CLK_SHFT                                            3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_ATB_CLK_BMSK                                             0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_ATB_CLK_SHFT                                               2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SHUB_CLK_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SHUB_CLK_SHFT                                              1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SHRM_CLK_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_CLK_ON_STATUS_SHRM_CLK_SHFT                                              0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x87cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x87cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_RMSK                                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_SHUB_DCD_ENABLE_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_GCC_DCD_SW_OVRD_SHUB_DCD_ENABLE_SHFT                                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x880u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x880u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_RMSK                                           0x1ffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_LLCC_DIS_ACK_BMSK                        0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_LLCC_DIS_ACK_SHFT                              20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_GEMNOC_DIS_ACK_BMSK                       0x80000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_GEMNOC_DIS_ACK_SHFT                            19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_LLCC_QDENY_BMSK                           0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_LLCC_QDENY_SHFT                                18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC5_QDENY_BMSK                                0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC5_QDENY_SHFT                                     17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC4_QDENY_BMSK                                0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC4_QDENY_SHFT                                     16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC3_QDENY_BMSK                                 0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC3_QDENY_SHFT                                     15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC2_QDENY_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC2_QDENY_SHFT                                     14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC1_QDENY_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC1_QDENY_SHFT                                     13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC0_QDENY_BMSK                                 0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC0_QDENY_SHFT                                     12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_GEMNOC_QDENY_BMSK                                 0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_GEMNOC_QDENY_SHFT                                    11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_LLCC_QACCEPTN_BMSK                          0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_LLCC_QACCEPTN_SHFT                             10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC5_QACCEPTN_BMSK                               0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC5_QACCEPTN_SHFT                                   9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC4_QACCEPTN_BMSK                               0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC4_QACCEPTN_SHFT                                   8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC3_QACCEPTN_BMSK                                0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC3_QACCEPTN_SHFT                                   7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC2_QACCEPTN_BMSK                                0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC2_QACCEPTN_SHFT                                   6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC1_QACCEPTN_BMSK                                0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC1_QACCEPTN_SHFT                                   5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC0_QACCEPTN_BMSK                                0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC0_QACCEPTN_SHFT                                   4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_GEMNOC_QACCEPTN_BMSK                                0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_GEMNOC_QACCEPTN_SHFT                                  3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_QACTIVE_BMSK                                  0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_DCNOC_QACTIVE_SHFT                                    2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC_QACTIVE_BMSK                                   0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_LLCC_QACTIVE_SHFT                                     1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_GEMNOC_QACTIVE_BMSK                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_EN_GEMNOC_QACTIVE_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_ADDR                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x884u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_OFFS                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x884u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_RMSK                                          0x1ffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_LLCC_DIS_ACK_BMSK                       0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_LLCC_DIS_ACK_SHFT                             20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_GEMNOC_DIS_ACK_BMSK                      0x80000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_GEMNOC_DIS_ACK_SHFT                           19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_LLCC_QDENY_BMSK                          0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_LLCC_QDENY_SHFT                               18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC5_QDENY_BMSK                               0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC5_QDENY_SHFT                                    17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC4_QDENY_BMSK                               0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC4_QDENY_SHFT                                    16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC3_QDENY_BMSK                                0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC3_QDENY_SHFT                                    15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC2_QDENY_BMSK                                0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC2_QDENY_SHFT                                    14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC1_QDENY_BMSK                                0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC1_QDENY_SHFT                                    13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC0_QDENY_BMSK                                0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC0_QDENY_SHFT                                    12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_GEMNOC_QDENY_BMSK                                0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_GEMNOC_QDENY_SHFT                                   11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_LLCC_QACCEPTN_BMSK                         0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_LLCC_QACCEPTN_SHFT                            10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC5_QACCEPTN_BMSK                              0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC5_QACCEPTN_SHFT                                  9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC4_QACCEPTN_BMSK                              0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC4_QACCEPTN_SHFT                                  8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC3_QACCEPTN_BMSK                               0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC3_QACCEPTN_SHFT                                  7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC2_QACCEPTN_BMSK                               0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC2_QACCEPTN_SHFT                                  6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC1_QACCEPTN_BMSK                               0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC1_QACCEPTN_SHFT                                  5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC0_QACCEPTN_BMSK                               0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC0_QACCEPTN_SHFT                                  4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_GEMNOC_QACCEPTN_BMSK                               0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_GEMNOC_QACCEPTN_SHFT                                 3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_QACTIVE_BMSK                                 0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_DCNOC_QACTIVE_SHFT                                   2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC_QACTIVE_BMSK                                  0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_LLCC_QACTIVE_SHFT                                    1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_GEMNOC_QACTIVE_BMSK                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_CSR_HW_DIS_GEMNOC_QACTIVE_SHFT                                  0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_ADDR                                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x888u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_OFFS                                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x888u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_RMSK                                            0x1ffdfffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_LLCC_DIS_ACK_BMSK                         0x10000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_LLCC_DIS_ACK_SHFT                                 28u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_GEMNOC_DIS_ACK_BMSK                        0x8000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_GEMNOC_DIS_ACK_SHFT                               27u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_LLCC_DIS_REQ_BMSK                          0x4000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_LLCC_DIS_REQ_SHFT                                 26u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_GEMNOC_DIS_REQ_BMSK                        0x2000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_GEMNOC_DIS_REQ_SHFT                               25u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_GEMNOC_QACTIVE_BMSK                        0x1000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_GEMNOC_QACTIVE_SHFT                               24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_LLCC_QACTIVE_BMSK                           0x800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_LLCC_QACTIVE_SHFT                                 23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC3_QACTIVE_BMSK                                0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC3_QACTIVE_SHFT                                      22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC2_QACTIVE_BMSK                                0x200000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC2_QACTIVE_SHFT                                      21u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC1_QACTIVE_BMSK                                0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC1_QACTIVE_SHFT                                      20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC0_QACTIVE_BMSK                                 0x80000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC0_QACTIVE_SHFT                                      19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_GEMNOC_QACTIVE_BMSK                                0x40000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_GEMNOC_QACTIVE_SHFT                                     18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC5_QACTIVE_BMSK                                 0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC5_QACTIVE_SHFT                                      16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC4_QACTIVE_BMSK                                  0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC4_QACTIVE_SHFT                                      15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_LLCC_QACCEPTN_BMSK                            0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_DCNOC_LLCC_QACCEPTN_SHFT                                14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC5_QACCEPTN_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC5_QACCEPTN_SHFT                                     13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC4_QACCEPTN_BMSK                                 0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC4_QACCEPTN_SHFT                                     12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC3_QACCEPTN_BMSK                                  0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC3_QACCEPTN_SHFT                                     11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC2_QACCEPTN_BMSK                                  0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC2_QACCEPTN_SHFT                                     10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC1_QACCEPTN_BMSK                                  0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC1_QACCEPTN_SHFT                                      9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC0_QACCEPTN_BMSK                                  0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC0_QACCEPTN_SHFT                                      8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_GEMNOC_QACCEPTN_BMSK                                  0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_GEMNOC_QACCEPTN_SHFT                                     7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC5_QREQN_BMSK                                      0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC5_QREQN_SHFT                                         6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC4_QREQN_BMSK                                      0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC4_QREQN_SHFT                                         5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC3_QREQN_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC3_QREQN_SHFT                                         4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC2_QREQN_BMSK                                       0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC2_QREQN_SHFT                                         3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC1_QREQN_BMSK                                       0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC1_QREQN_SHFT                                         2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC0_QREQN_BMSK                                       0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_LLCC0_QREQN_SHFT                                         1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_GEMNOC_QREQN_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PWR_QCH_STATUS_GEMNOC_QREQN_SHFT                                        0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_ADDR                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x900u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_OFFS                                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x900u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_PWR_ON_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_PWR_ON_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_SPARE_CTRL_OUT_BMSK                            0x7f800000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                    23u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_PWR_DWN_START_BMSK                               0x400000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_PWR_DWN_START_SHFT                                     22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_PWR_UP_START_BMSK                                0x200000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_PWR_UP_START_SHFT                                      21u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_POWER_UP_COMPLETE_BMSK                           0x100000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                 20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                          0x80000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                               19u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_STATE_BMSK                                        0x7f800ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_GDSC_STATE_SHFT                                             11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_MULTI_MODE_GDSC_CTRL_BMSK                                0x7f8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_MULTI_MODE_GDSC_CTRL_SHFT                                    3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_RETAIN_FF_ENABLE_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_RETAIN_FF_ENABLE_SHFT                                        2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_HW_CONTROL_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_HW_CONTROL_SHFT                                              1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_HW_CONTROL_SW_CONTROL_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_HW_CONTROL_HW_CONTROL_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_SW_COLLAPSE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_SW_COLLAPSE_SHFT                                             0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_SW_COLLAPSE_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG_MCGDSCR_SW_COLLAPSE_ENABLE_FVAL                                    0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x904u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x904u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_RMSK                                                  0x3fffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                      0x20000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                           17u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                  0x10000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                       16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_SPARE_CTRL_IN_BMSK                                0xf000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_SPARE_CTRL_IN_SHFT                                    12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                          0xf00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                              8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_HANDSHAKE_DIS_BMSK                                  0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_HANDSHAKE_DIS_SHFT                                     7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                              0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                 6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                     0x30u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                        4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                       0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                         2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                           0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                             1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG2_MCGDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                          0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x908u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x908u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_CLK_DIS_WAIT_BMSK                                  0xf0000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_CLK_DIS_WAIT_SHFT                                          28u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_EN_REST_WAIT_BMSK                                   0xf000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_EN_REST_WAIT_SHFT                                          24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_EN_FEW_WAIT_BMSK                                     0xf00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_EN_FEW_WAIT_SHFT                                           20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_DLY_ENF_STAGGER_BMSK                                  0xf0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_DLY_ENF_STAGGER_SHFT                                       16u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_DLY_MEM_PWR_UP_BMSK                                    0xf000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_DLY_MEM_PWR_UP_SHFT                                        12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                             0xf00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                 8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                0xf0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                   4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                  0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY_CFG3_MCGDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_ADDR                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x90cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_OFFS                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x90cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_RMSK                                               0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                       0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                           15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_DOWN_COMPLETED_FVAL        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_UP_COMPLETED_FVAL        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_BMSK                           0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_SHFT                               14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_BMSK                           0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_SHFT                               13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_SHFT                                 12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_ENABLE_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                      0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                         11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                      0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                         10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                          0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                              9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_RESTORE_BMSK                                        0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_RESTORE_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_RESTORE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_RESTORE_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_SAVE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_SAVE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_SAVE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_SAVE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_RETAIN_BMSK                                          0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_RETAIN_SHFT                                             6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_RETAIN_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_RETAIN_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_EN_REST_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_EN_REST_SHFT                                            5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_EN_REST_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_EN_REST_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_EN_FEW_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_EN_FEW_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_EN_FEW_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_EN_FEW_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_CLAMP_IO_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_CLAMP_IO_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_CLAMP_IO_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_CLAMP_IO_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_CLK_DISABLE_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_CLK_DISABLE_SHFT                                        2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_DISABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_PD_ARES_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_PD_ARES_SHFT                                            1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_PD_ARES_NO_RESET_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_PD_ARES_RESET_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_SW_OVERRIDE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_SW_OVERRIDE_SHFT                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_SW_OVERRIDE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY0_SW_OVRD_MCGDSCR_SW_OVERRIDE_ENABLE_FVAL                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_ADDR                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x910u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_OFFS                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x910u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_RMSK                                               0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                       0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                           15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_DOWN_COMPLETED_FVAL        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_UP_COMPLETED_FVAL        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_BMSK                           0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_SHFT                               14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_BMSK                           0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_SHFT                               13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_SHFT                                 12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_ENABLE_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                      0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                         11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                      0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                         10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                          0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                              9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_RESTORE_BMSK                                        0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_RESTORE_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_RESTORE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_RESTORE_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_SAVE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_SAVE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_SAVE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_SAVE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_RETAIN_BMSK                                          0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_RETAIN_SHFT                                             6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_RETAIN_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_RETAIN_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_EN_REST_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_EN_REST_SHFT                                            5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_EN_REST_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_EN_REST_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_EN_FEW_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_EN_FEW_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_EN_FEW_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_EN_FEW_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_CLAMP_IO_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_CLAMP_IO_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_CLAMP_IO_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_CLAMP_IO_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_CLK_DISABLE_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_CLK_DISABLE_SHFT                                        2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_DISABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_PD_ARES_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_PD_ARES_SHFT                                            1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_PD_ARES_NO_RESET_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_PD_ARES_RESET_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_SW_OVERRIDE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_SW_OVERRIDE_SHFT                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_SW_OVERRIDE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY1_SW_OVRD_MCGDSCR_SW_OVERRIDE_ENABLE_FVAL                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_ADDR                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x914u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_OFFS                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x914u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_RMSK                                               0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                       0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                           15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_DOWN_COMPLETED_FVAL        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_UP_COMPLETED_FVAL        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_BMSK                           0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_SHFT                               14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_BMSK                           0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_SHFT                               13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_SHFT                                 12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_ENABLE_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                      0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                         11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                      0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                         10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                          0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                              9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_RESTORE_BMSK                                        0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_RESTORE_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_RESTORE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_RESTORE_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_SAVE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_SAVE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_SAVE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_SAVE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_RETAIN_BMSK                                          0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_RETAIN_SHFT                                             6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_RETAIN_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_RETAIN_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_EN_REST_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_EN_REST_SHFT                                            5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_EN_REST_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_EN_REST_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_EN_FEW_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_EN_FEW_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_EN_FEW_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_EN_FEW_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_CLAMP_IO_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_CLAMP_IO_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_CLAMP_IO_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_CLAMP_IO_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_CLK_DISABLE_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_CLK_DISABLE_SHFT                                        2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_DISABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_PD_ARES_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_PD_ARES_SHFT                                            1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_PD_ARES_NO_RESET_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_PD_ARES_RESET_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_SW_OVERRIDE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_SW_OVERRIDE_SHFT                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_SW_OVERRIDE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY2_SW_OVRD_MCGDSCR_SW_OVERRIDE_ENABLE_FVAL                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_ADDR                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x918u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_OFFS                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x918u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_RMSK                                               0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                       0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                           15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_DOWN_COMPLETED_FVAL        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_UP_COMPLETED_FVAL        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_BMSK                           0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_SHFT                               14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_BMSK                           0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_SHFT                               13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_SHFT                                 12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_ENABLE_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                      0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                         11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                      0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                         10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                          0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                              9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_RESTORE_BMSK                                        0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_RESTORE_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_RESTORE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_RESTORE_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_SAVE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_SAVE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_SAVE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_SAVE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_RETAIN_BMSK                                          0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_RETAIN_SHFT                                             6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_RETAIN_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_RETAIN_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_EN_REST_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_EN_REST_SHFT                                            5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_EN_REST_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_EN_REST_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_EN_FEW_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_EN_FEW_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_EN_FEW_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_EN_FEW_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_CLAMP_IO_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_CLAMP_IO_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_CLAMP_IO_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_CLAMP_IO_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_CLK_DISABLE_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_CLK_DISABLE_SHFT                                        2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_DISABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_PD_ARES_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_PD_ARES_SHFT                                            1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_PD_ARES_NO_RESET_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_PD_ARES_RESET_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_SW_OVERRIDE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_SW_OVERRIDE_SHFT                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_SW_OVERRIDE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY3_SW_OVRD_MCGDSCR_SW_OVERRIDE_ENABLE_FVAL                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1040u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1040u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1044u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1044u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1048u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1048u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x104cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x104cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1050u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1050u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1054u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1054u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1058u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1058u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x105cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x105cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1060u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1060u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_ADDR                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1064u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_OFFS                                (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1064u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_RMSK                                      0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                                0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                   0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_ADDR                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1068u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_OFFS                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1068u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_RMSK                                     0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                               0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                  0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_ADDR                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x106cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_OFFS                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x106cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_RMSK                                     0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                               0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                  0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_ADDR                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1070u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_OFFS                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1070u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_RMSK                                     0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                               0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                  0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_ADDR                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1074u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_OFFS                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1074u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_RMSK                                     0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                               0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                  0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_ADDR                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1078u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_OFFS                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1078u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_RMSK                                     0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                               0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                  0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_ADDR                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x107cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_OFFS                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x107cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_RMSK                                     0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_PLL_L_BMSK                               0xffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_L_VAL_PLL_L_SHFT                                  0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1080u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1080u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1084u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1084u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1088u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1088u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x108cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x108cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1090u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1090u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1094u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1094u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1098u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1098u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x109cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x109cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1100u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1100u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_ADDR                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1104u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_OFFS                             (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1104u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_RMSK                                 0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                    0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_ADDR                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1108u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_OFFS                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1108u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_RMSK                                0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                   0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                        0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_ADDR                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x110cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_OFFS                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x110cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_RMSK                                0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                   0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                        0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_ADDR                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1110u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_OFFS                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1110u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_RMSK                                0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                   0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                        0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_ADDR                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1114u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_OFFS                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1114u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_RMSK                                0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                   0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                        0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_ADDR                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1118u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_OFFS                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1118u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_RMSK                                0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                   0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                        0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_ADDR                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x111cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_OFFS                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x111cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_RMSK                                0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_BMSK                   0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_DPCC_PLL0_1_FRAC_VAL_PLL_FRAC_VAL_SHFT                        0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_ADDR                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1120u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_OFFS                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1120u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_RMSK                                             0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_RCG_TOGGLE_EN_BMSK                               0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_RCG_TOGGLE_EN_SHFT                                 1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_PLL_TOGGLE_EN_BMSK                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_FAKE_SWITCH_DEBUG_PLL_TOGGLE_EN_SHFT                                 0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_ADDR                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1124u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_OFFS                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1124u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_RESERVE_BIT31_7_BMSK                      0xffffff80ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_RESERVE_BIT31_7_SHFT                               7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_PLL_PP_STATE_STATUS_BMSK                        0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_PLL_PP_STATE_STATUS_SHFT                           6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_RCG_PP_STATE_STATUS_BMSK                        0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_RCG_PP_STATE_STATUS_SHFT                           5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_CLOCK_SWITCH_FSM_STATUS_BMSK                    0x1fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLOCK_SWITCH_MISC_CLOCK_SWITCH_FSM_STATUS_SHFT                       0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_ADDR                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1130u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_OFFS                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1130u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_RMSK                                             0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_PERF_STATE_BMSK                                  0xfu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERFORMANCE_STATE_PERF_STATE_SHFT                                    0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1134u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1134u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_RMSK                                                     0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_STATUS_BMSK                                              0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_STATUS_SHFT                                                 4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_PRE_WORK_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PRE_WORK_PRE_WORK_SHFT                                               0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_ADDR                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1138u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_OFFS                                              (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1138u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_RMSK                                                    0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_STATUS_BMSK                                             0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_STATUS_SHFT                                                4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_POST_WORK_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_POST_WORK_POST_WORK_SHFT                                             0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_ADDR                                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x113cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_OFFS                                            (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x113cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_RMSK                                                  0x11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_STATUS_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_STATUS_SHFT                                              4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_CLK_DISABLE_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_CLK_DISABLE_CLK_DISABLE_SHFT                                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1200u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1200u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_RMSK                                               0xffffdffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_PWR_ON_STATUS_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_PWR_ON_STATUS_SHFT                                         31u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_RESERVE_30_15_BMSK                                 0x7fff8000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_RESERVE_30_15_SHFT                                         15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_COLLAPSE_OUT_BMSK                                      0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_COLLAPSE_OUT_SHFT                                          14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_HALT_ACK_TIMEOUT_BMSK                                  0x1fe0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_HALT_ACK_TIMEOUT_SHFT                                       5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_GDS_HW_STATE_BMSK                                        0x1eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_GDS_HW_STATE_SHFT                                           1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SW_OVERRIDE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_SW_OVERRIDE_SHFT                                            0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_ADDR                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1204u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_OFFS                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1204u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_RMSK                                        0xfffcfe7ful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_RESERVE_31_30_BMSK                          0xc0000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_RESERVE_31_30_SHFT                                  30u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_DVM_HALT1_PWR_DOWN_ACK_STATUS_BMSK          0x30000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_DVM_HALT1_PWR_DOWN_ACK_STATUS_SHFT                  28u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_RESERVE_27_26_BMSK                           0xc000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_RESERVE_27_26_SHFT                                  26u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_DVM_HALT1_PWR_UP_ACK_STATUS_BMSK             0x3000000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_DVM_HALT1_PWR_UP_ACK_STATUS_SHFT                    24u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_RESERVE_23_22_BMSK                            0xc00000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_RESERVE_23_22_SHFT                                  22u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_HALT1_PWR_DOWN_ACK_STATUS_BMSK                0x300000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_HALT1_PWR_DOWN_ACK_STATUS_SHFT                      20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_HALT1_PWR_UP_ACK_STATUS_BMSK                   0xc0000ul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_HALT1_PWR_UP_ACK_STATUS_SHFT                        18u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_HALT2_PWR_DOWN_ACK_STATUS_BMSK                  0xfe00u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_HALT2_PWR_DOWN_ACK_STATUS_SHFT                       9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_HALT2_PWR_UP_ACK_STATUS_BMSK                      0x7fu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_GDS_HW_CTRL_STATUS_HALT2_PWR_UP_ACK_STATUS_SHFT                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_ADDR                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1208u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_OFFS                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1208u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_RMSK                                          0x19ffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_DVM_HALT_REQ_BMSK                             0x1800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_DVM_HALT_REQ_SHFT                                 11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_SHUB_HALT_REQ_BMSK                             0x1fcu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_SHUB_HALT_REQ_SHFT                                 2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_DCNOC_HALT_REQ_BMSK                              0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_HALT_REQ_GDS_HW_CTRL_DCNOC_HALT_REQ_SHFT                                0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x1260u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x1260u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_RMSK                                                     0x13feu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_GEMNOC_FORCE_CORE_ON_BMSK                                0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_GEMNOC_FORCE_CORE_ON_SHFT                                    12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_SHUB_PSCBC_CLK_DIS_ACK_BMSK                               0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_SHUB_PSCBC_CLK_DIS_ACK_SHFT                                   9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_SHUB_GDSC_CLK_DIS_BMSK                                    0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_SHUB_GDSC_CLK_DIS_SHFT                                        8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_SHUB_GDSC_CLK_DIS_COND_BMSK                                0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_SHUB_GDSC_CLK_DIS_COND_SHFT                                   7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_GEMNOC_PSCBC_PWR_DWN_ACK_BMSK                              0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_GEMNOC_PSCBC_PWR_DWN_ACK_SHFT                                 6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_SHUB_GDSC_PSCBC_PWR_DWN_BMSK                               0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_SHUB_GDSC_PSCBC_PWR_DWN_SHFT                                  5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_LLCC_CLAMP_MEM_SRAM_BMSK                                   0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_LLCC_CLAMP_MEM_SRAM_SHFT                                      4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_LLCC_CLAMP_MEM_LB_BMSK                                      0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_LLCC_CLAMP_MEM_LB_SHFT                                        3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_PWR_QCH_CLK_ON_BMSK                                         0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_PWR_QCH_CLK_ON_SHFT                                           2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_PWR_GATE_REQ_BMSK                                           0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SHUB_PC_STATUS_PWR_GATE_REQ_SHFT                                             1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_ADDR                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2000u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_OFFS                                                 (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2000u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_RMSK                                                        0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_RETAIN_FF_ENABLE_BMSK                                       0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_RETAIN_FF_ENABLE_SHFT                                         1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_SW_OVERRIDE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_SW_OVERRIDE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_SW_OVERRIDE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_SHUB_SGDSCR_SW_OVERRIDE_ENABLE_FVAL                                     0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2004u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2004u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_RMSK                                                         0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_RETAIN_FF_ENABLE_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_RETAIN_FF_ENABLE_SHFT                                          1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_SW_OVERRIDE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_SW_OVERRIDE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_SW_OVERRIDE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_MC5_SGDSCR_SW_OVERRIDE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_ADDR                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x202cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_OFFS                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x202cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_RMSK                                               0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                       0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                           15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_DOWN_COMPLETED_FVAL        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_UP_COMPLETED_FVAL        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_BMSK                           0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_SHFT                               14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_BMSK                           0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_SHFT                               13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_SHFT                                 12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_ENABLE_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                      0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                         11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                      0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                         10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                          0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                              9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_RESTORE_BMSK                                        0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_RESTORE_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_RESTORE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_RESTORE_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_SAVE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_SAVE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_SAVE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_SAVE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_RETAIN_BMSK                                          0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_RETAIN_SHFT                                             6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_RETAIN_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_RETAIN_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_EN_REST_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_EN_REST_SHFT                                            5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_EN_REST_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_EN_REST_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_EN_FEW_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_EN_FEW_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_EN_FEW_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_EN_FEW_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_CLAMP_IO_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_CLAMP_IO_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_CLAMP_IO_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_CLAMP_IO_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_CLK_DISABLE_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_CLK_DISABLE_SHFT                                        2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_DISABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_PD_ARES_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_PD_ARES_SHFT                                            1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_PD_ARES_NO_RESET_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_PD_ARES_RESET_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_SW_OVERRIDE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_SW_OVERRIDE_SHFT                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_SW_OVERRIDE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY4_SW_OVRD_MCGDSCR_SW_OVERRIDE_ENABLE_FVAL                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_ADDR                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2030u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_OFFS                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2030u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_RMSK                                               0xffffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                       0x8000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                           15u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_DOWN_COMPLETED_FVAL        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_MEM_PWR_ACK_STATUS_MEMORY_POWER_UP_COMPLETED_FVAL        0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_BMSK                           0x4000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_SHFT                               14u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_ENR_ACK_STATUS_ENR_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_BMSK                           0x2000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_SHFT                               13u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_OFF_FVAL           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_ENF_ACK_STATUS_ENF_SWITCH_ARE_ON_FVAL            0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_SHFT                                 12u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_CLAMP_MEM_SW_ENABLE_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                      0x800u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                         11u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                      0x400u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                         10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                          0x200u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                              9u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_RESTORE_BMSK                                        0x100u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_RESTORE_SHFT                                            8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_RESTORE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_RESTORE_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_SAVE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_SAVE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_SAVE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_SAVE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_RETAIN_BMSK                                          0x40u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_RETAIN_SHFT                                             6u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_RETAIN_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_RETAIN_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_EN_REST_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_EN_REST_SHFT                                            5u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_EN_REST_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_EN_REST_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_EN_FEW_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_EN_FEW_SHFT                                             4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_EN_FEW_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_EN_FEW_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_CLAMP_IO_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_CLAMP_IO_SHFT                                           3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_CLAMP_IO_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_CLAMP_IO_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_CLK_DISABLE_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_CLK_DISABLE_SHFT                                        2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_CLK_DISABLE_CLK_DISABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_PD_ARES_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_PD_ARES_SHFT                                            1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_PD_ARES_NO_RESET_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_PD_ARES_RESET_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_SW_OVERRIDE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_SW_OVERRIDE_SHFT                                        0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_SW_OVERRIDE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PHY5_SW_OVRD_MCGDSCR_SW_OVERRIDE_ENABLE_FVAL                               0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_ADDR                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2040u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_OFFS                                                  (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2040u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_RMSK                                                         0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_RETAIN_FF_ENABLE_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_RETAIN_FF_ENABLE_SHFT                                          1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_SW_OVERRIDE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_SW_OVERRIDE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_SW_OVERRIDE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_TZ_PHY_SGDSCR_SW_OVERRIDE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_ADDR                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2068u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_OFFS                                               (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2068u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_RMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_ENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CLK_ENABLE_ENABLE_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_ADDR                                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x206cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_OFFS                                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x206cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_RMSK                                                          0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_SPARE_BMSK                                                    0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_SPARE_SPARE_SHFT                                                             0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_STATUS_ADDR                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2070u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_STATUS_OFFS                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2070u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_STATUS_RMSK                                                    0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_STATUS_STATUS_31_0_BMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_STATUS_STATUS_31_0_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_STATUS_ADDR                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x2074u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_STATUS_OFFS                                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x2074u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_STATUS_RMSK                                                    0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_STATUS_STATUS_31_0_BMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_STATUS_STATUS_31_0_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3000u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3000u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF0_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3004u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3004u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF1_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3008u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3008u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF2_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x300cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x300cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF3_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3010u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3010u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF4_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3014u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3014u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF5_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3018u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3018u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF6_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x301cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x301cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF7_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3020u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3020u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF8_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_ADDR                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3024u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_OFFS                                         (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3024u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_RMSK                                                0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_DPCC_MODE_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_DPCC_MODE_SHFT                                        1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_DPCC_PLL0_1_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_DPCC_PLL0_1_SHFT                                      0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF9_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_ADDR                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3028u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_OFFS                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3028u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_RMSK                                               0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_DPCC_MODE_BMSK                                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_DPCC_MODE_SHFT                                       1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_DPCC_PLL0_1_BMSK                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_DPCC_PLL0_1_SHFT                                     0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF10_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                            0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_ADDR                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x302cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_OFFS                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x302cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_RMSK                                               0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_DPCC_MODE_BMSK                                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_DPCC_MODE_SHFT                                       1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_DPCC_PLL0_1_BMSK                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_DPCC_PLL0_1_SHFT                                     0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF11_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                            0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_ADDR                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3030u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_OFFS                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3030u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_RMSK                                               0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_DPCC_MODE_BMSK                                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_DPCC_MODE_SHFT                                       1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_DPCC_PLL0_1_BMSK                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_DPCC_PLL0_1_SHFT                                     0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF12_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                            0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_ADDR                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3034u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_OFFS                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3034u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_RMSK                                               0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_DPCC_MODE_BMSK                                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_DPCC_MODE_SHFT                                       1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_DPCC_PLL0_1_BMSK                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_DPCC_PLL0_1_SHFT                                     0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF13_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                            0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_ADDR                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3038u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_OFFS                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3038u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_RMSK                                               0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_DPCC_MODE_BMSK                                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_DPCC_MODE_SHFT                                       1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_DPCC_PLL0_1_BMSK                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_DPCC_PLL0_1_SHFT                                     0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF14_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                            0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_ADDR                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x303cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_OFFS                                        (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x303cu)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_RMSK                                               0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_DPCC_MODE_BMSK                                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_DPCC_MODE_SHFT                                       1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_DPCC_MODE_DPCC_MODE_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_DPCC_MODE_DPCC_MODE_ENABLE_FVAL                    0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_DPCC_PLL0_1_BMSK                                   0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_DPCC_PLL0_1_SHFT                                     0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_DPCC_PLL0_1_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_RPMH_MC_PERF15_ENA_VOTE_DPCC_PLL0_1_ENABLE_FVAL                            0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_ADDR                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x3040u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_OFFS                                    (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x3040u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_RMSK                                           0x3u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_DPCC_PLL0_OUT_MAIN_EN_BMSK                     0x2u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_DPCC_PLL0_OUT_MAIN_EN_SHFT                       1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_DPCC_PLL0_OUT_MAIN_EN_DISABLE_FVAL             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_DPCC_PLL0_OUT_MAIN_EN_ENABLE_FVAL              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_DPCC_PLL1_OUT_MAIN_EN_BMSK                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_DPCC_PLL1_OUT_MAIN_EN_SHFT                       0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_DPCC_PLL1_OUT_MAIN_EN_DISABLE_FVAL             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL_DEBUG_MUX_RAW_OUTPUT_EN_DPCC_PLL1_OUT_MAIN_EN_ENABLE_FVAL              0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x4004u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x4004u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_RMSK                                             0x1fffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_REF_TIME_OUT_BMSK                                0x1fffeul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_REF_TIME_OUT_SHFT                                      1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_BMSK                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_SHFT                       0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_DISABLE_FVAL             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL0_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_ENABLE_FVAL              0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_ADDR                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x4008u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_OFFS                                          (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x4008u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_RMSK                                             0x1fffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_IN)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_REF_TIME_OUT_BMSK                                0x1fffeul
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_REF_TIME_OUT_SHFT                                      1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_BMSK                     0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_SHFT                       0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_DISABLE_FVAL             0x0u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_PLL1_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_ENABLE_FVAL              0x1u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CSR_ADDR                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x4010u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CSR_OFFS                                                      (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x4010u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CSR_RMSK                                                      0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CSR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CSR_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CSR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CSR_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CSR_SPARE_BMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_DEBUG_CSR_SPARE_SHFT                                                         0u

#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_ADDR                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE      + 0x4200u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_OFFS                                           (SAIL_TO_MD_DPC_REG_DPCC_DPCC_DPCC_REG_REG_BASE_OFFS + 0x4200u)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_RMSK                                               0x1fffu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_HPCNT_BMSK                                         0x1f80u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_HPCNT_SHFT                                              7u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_VPCNT_BMSK                                           0x7eu
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_VPCNT_SHFT                                              1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_FLT_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_DPC_REG_DPCC_FUSA_STATUS_REGISTER_FLT_SHFT                                                0u


#endif /* __G_SAIL_TO_MD_DPC_HWIO_H__ */
