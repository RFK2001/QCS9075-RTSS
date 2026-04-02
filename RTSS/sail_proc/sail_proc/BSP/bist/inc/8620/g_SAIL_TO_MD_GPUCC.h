#ifndef G_SAIL_TO_MD_GPUCC_H
#define G_SAIL_TO_MD_GPUCC_H
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_GPUCC.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        MonacoAU [monacoau_v1.0_p3q3r53_MTO_rpm]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_GPUCC.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG'],
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
 * MODULE: SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE                                                       (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x03d94000UL)
#define SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_SIZE                                                  0x5800U
#define SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_USED                                                  0x55e8U
#define SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS                                                  0x03d94000UL

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_ADDR                                                    (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_OFFS                                                    (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_RMSK                                                         0x804U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_RETAIN_FF_ENABLE_BMSK                                        0x800U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_RETAIN_FF_ENABLE_SHFT                                           11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_SW_OVERRIDE_BMSK                                               0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_GX_SW_OVERRIDE_SHFT                                                 2U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_ADDR                                                    (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_OFFS                                                    (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_RMSK                                                         0x804U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_RETAIN_FF_ENABLE_BMSK                                        0x800U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_RETAIN_FF_ENABLE_SHFT                                           11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_SW_OVERRIDE_BMSK                                               0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_GDSC_CTRL_GPU_CX_SW_OVERRIDE_SHFT                                                 2U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_RMSK                                                                   0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_SPARE_BITS_BMSK                                                        0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE0_REG_SPARE_BITS_SHFT                                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_ADDR                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x1000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_OFFS                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x1000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_RMSK                                                   0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_CLK_OFF_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_CLK_OFF_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_CLK_ENABLE_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_CLK_CLK_ENABLE_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_ADDR                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x1004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_OFFS                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x1004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_RMSK                                                   0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_PWR_ON_BMSK                                            0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_PWR_ON_SHFT                                                    31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_SW_COLLAPSE_BMSK                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_GPU_SMMU_GDS_SW_COLLAPSE_SHFT                                                0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_ADDR                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x1008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_OFFS                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x1008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_RMSK                                                 0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_CLK_OFF_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_CLK_OFF_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_CLK_ENABLE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_HUB_CX_INT_CLK_CLK_ENABLE_SHFT                                               0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x100cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x100cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_RMSK                                                     0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_TZ_VOTE_CX_GMU_CLK_CLK_ENABLE_SHFT                                                   0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x1010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x1010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_RMSK                                                                   0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_SPARE_BITS_BMSK                                                        0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE1_REG_SPARE_BITS_SHFT                                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_ADDR                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x2000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_OFFS                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x2000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_RMSK                                                  0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_CLK_OFF_BMSK                                          0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_CLK_OFF_SHFT                                                  31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_CLK_ENABLE_BMSK                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_CLK_CLK_ENABLE_SHFT                                                0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_ADDR                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x2004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_OFFS                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x2004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_RMSK                                                  0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_PWR_ON_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_PWR_ON_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_SW_COLLAPSE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_GPU_SMMU_GDS_SW_COLLAPSE_SHFT                                               0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x2008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x2008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_RMSK                                                0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_CLK_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_CLK_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_CLK_ENABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_HUB_CX_INT_CLK_CLK_ENABLE_SHFT                                              0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_ADDR                                                    (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x200cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_OFFS                                                    (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x200cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_RMSK                                                    0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_CLK_OFF_BMSK                                            0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_CLK_OFF_SHFT                                                    31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_CLK_ENABLE_BMSK                                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HYP_VOTE_CX_GMU_CLK_CLK_ENABLE_SHFT                                                  0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x2010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x2010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_RMSK                                                                   0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_SPARE_BITS_BMSK                                                        0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE2_REG_SPARE_BITS_SHFT                                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x3000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x3000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_RMSK                                                0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_CLK_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_CLK_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_CLK_ENABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_CLK_CLK_ENABLE_SHFT                                              0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x3004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x3004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_RMSK                                                0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_PWR_ON_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_PWR_ON_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_SW_COLLAPSE_BMSK                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_GPU_SMMU_GDS_SW_COLLAPSE_SHFT                                             0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_ADDR                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x3008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_OFFS                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x3008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_RMSK                                              0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_CLK_OFF_BMSK                                      0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_CLK_OFF_SHFT                                              31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_CLK_ENABLE_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_HUB_CX_INT_CLK_CLK_ENABLE_SHFT                                            0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_ADDR                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x300cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_OFFS                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x300cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_RMSK                                                  0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_CLK_OFF_BMSK                                          0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_CLK_OFF_SHFT                                                  31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_CLK_ENABLE_BMSK                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HLOS1_VOTE_CX_GMU_CLK_CLK_ENABLE_SHFT                                                0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x3010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x3010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_RMSK                                                                   0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_SPARE_BITS_BMSK                                                        0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE3_REG_SPARE_BITS_SHFT                                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x4000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x4000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_RMSK                                                0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_CLK_OFF_BMSK                                        0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_CLK_OFF_SHFT                                                31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_CLK_ENABLE_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_CLK_CLK_ENABLE_SHFT                                              0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x4004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x4004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_RMSK                                                0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_PWR_ON_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_PWR_ON_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_SW_COLLAPSE_BMSK                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_GPU_SMMU_GDS_SW_COLLAPSE_SHFT                                             0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_ADDR                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x4008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_OFFS                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x4008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_RMSK                                              0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_CLK_OFF_BMSK                                      0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_CLK_OFF_SHFT                                              31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_CLK_ENABLE_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_HUB_CX_INT_CLK_CLK_ENABLE_SHFT                                            0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_ADDR                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x400cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_OFFS                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x400cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_RMSK                                                  0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_CLK_OFF_BMSK                                          0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_CLK_OFF_SHFT                                                  31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_CLK_ENABLE_BMSK                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE_VOTE_CX_GMU_CLK_CLK_ENABLE_SHFT                                                0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x4010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x4010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_RMSK                                                                   0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_SPARE_BITS_BMSK                                                        0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPARE4_REG_SPARE_BITS_SHFT                                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_ADDR                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x4400U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_OFFS                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x4400U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_RMSK                                             0x1fffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_HPCNT_BMSK                                       0x1f80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_HPCNT_SHFT                                            7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_VPCNT_BMSK                                         0x7eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_VPCNT_SHFT                                            1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_FLT_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_RESET_FLT_SHFT                                              0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_ADDR                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x4404U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_OFFS                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x4404U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_RMSK                          0x1fffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_HPCNT_BMSK                    0x1f80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_HPCNT_SHFT                         7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_VPCNT_BMSK                      0x7eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_VPCNT_SHFT                         1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_FLT_BMSK                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_I_GCC_GPU_CC_ACCESS_ARES_FLT_SHFT                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_ADDR                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x4408U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_OFFS                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x4408U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_RMSK                    0x1fffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_HPCNT_BMSK              0x1f80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_HPCNT_SHFT                   7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_VPCNT_BMSK                0x7eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_VPCNT_SHFT                   1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_FLT_BMSK                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FUSA_STATUS_REGISTER_CLK_GPU_CC_CX_GDS_HW_CTRL_IRQ_ARES_FLT_SHFT                     0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_ADDR                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_OFFS                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5000U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_RMSK                                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_BLK_ARES_BMSK                                                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_BLK_ARES_SHFT                                                                 0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_BLK_ARES_DISABLE_FVAL                                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_BCR_BLK_ARES_ENABLE_FVAL                                                        0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5004U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_RMSK                                                           0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_CLK_OFF_BMSK                                                   0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_CLK_OFF_SHFT                                                           31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_IGNORE_ALL_ARES_BMSK                                            0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_IGNORE_ALL_ARES_SHFT                                                   24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                          0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_CLK_DIS_BMSK                                                     0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_CLK_DIS_SHFT                                                           22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_CLK_ARES_BMSK                                                         0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_CLK_ARES_SHFT                                                           2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_CLK_ARES_NO_RESET_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_AON_CBCR_CLK_ARES_RESET_FVAL                                                   0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_ADDR                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_OFFS                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5008U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_RMSK                                                      0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_OFF_BMSK                                              0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_OFF_SHFT                                                      31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_IGNORE_ALL_ARES_SHFT                                              24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_DIS_BMSK                                                0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_DIS_SHFT                                                      22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_ARES_BMSK                                                    0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_ARES_SHFT                                                      2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_ARES_RESET_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_ENABLE_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_ENABLE_SHFT                                                    0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQ_MEASURE_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x500cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x500cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_RMSK                                                             0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_OFF_BMSK                                                     0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_OFF_SHFT                                                             31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_IGNORE_ALL_ARES_BMSK                                              0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_IGNORE_ALL_ARES_SHFT                                                     24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                            0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                  23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_DIS_BMSK                                                       0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_DIS_SHFT                                                             22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_ARES_BMSK                                                           0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_ARES_SHFT                                                             2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_ARES_NO_RESET_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_ARES_RESET_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_ENABLE_BMSK                                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_ENABLE_SHFT                                                           0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_ENABLE_DISABLE_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_CBCR_CLK_ENABLE_ENABLE_FVAL                                                  0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ADDR                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_OFFS                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5010U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_RMSK                                                            0x80000013UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ROOT_OFF_BMSK                                                   0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ROOT_OFF_SHFT                                                           31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                                   0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                      4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ROOT_EN_BMSK                                                           0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ROOT_EN_SHFT                                                             1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_UPDATE_BMSK                                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_UPDATE_SHFT                                                              0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_UPDATE_DISABLE_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CMD_RCGR_UPDATE_ENABLE_FVAL                                                     0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_ADDR                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5014U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_OFFS                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5014U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_RMSK                                                              0x11071fUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_HW_CLK_CONTROL_BMSK                                               0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_HW_CLK_CONTROL_SHFT                                                     20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_RCGLITE_DISABLE_BMSK                                               0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_RCGLITE_DISABLE_SHFT                                                    16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_BMSK                                                         0x700U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_SHFT                                                             8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                      0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                      0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                      0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                      0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                      0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                      0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_BMSK                                                          0x1fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_SHFT                                                             0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                                    0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                      0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                                    0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                      0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                                    0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                      0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                                    0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                      0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                                    0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                      0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                                    0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                      0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                                    0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                      0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                                   0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV9_FVAL                                                     0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                                   0x12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV10_FVAL                                                    0x13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                                  0x14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV11_FVAL                                                    0x15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                                  0x16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV12_FVAL                                                    0x17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                                  0x18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV13_FVAL                                                    0x19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                                  0x1aU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV14_FVAL                                                    0x1bU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                                  0x1cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV15_FVAL                                                    0x1dU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                                  0x1eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_CFG_RCGR_SRC_DIV_DIV16_FVAL                                                    0x1fU

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5050U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5050U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_RMSK                                                                  0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_CLK_DIV_BMSK                                                          0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_XO_DIV_CDIVR_CLK_DIV_SHFT                                                            0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_ADDR                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5054U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_OFFS                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5054U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_RMSK                                                               0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_CLK_DIV_BMSK                                                       0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEMET_DIV_CDIVR_CLK_DIV_SHFT                                                         0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_ADDR                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5058U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_OFFS                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5058U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_RMSK                                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_BLK_ARES_BMSK                                                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_BLK_ARES_SHFT                                                                 0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_BLK_ARES_DISABLE_FVAL                                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_BCR_BLK_ARES_ENABLE_FVAL                                                        0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_ADDR                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x505cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_OFFS                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x505cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RMSK                                                               0xf8ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_PWR_ON_BMSK                                                        0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_PWR_ON_SHFT                                                                31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_GDSC_STATE_BMSK                                                    0x78000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_GDSC_STATE_SHFT                                                            27U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_REST_WAIT_BMSK                                                    0xf00000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_REST_WAIT_SHFT                                                          20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_FEW_WAIT_BMSK                                                      0xf0000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_FEW_WAIT_SHFT                                                           16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLK_DIS_WAIT_BMSK                                                      0xf000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLK_DIS_WAIT_SHFT                                                          12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RETAIN_FF_ENABLE_BMSK                                                   0x800U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RETAIN_FF_ENABLE_SHFT                                                      11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RESTORE_BMSK                                                            0x400U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RESTORE_SHFT                                                               10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RESTORE_DISABLE_FVAL                                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RESTORE_ENABLE_FVAL                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SAVE_BMSK                                                               0x200U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SAVE_SHFT                                                                   9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SAVE_DISABLE_FVAL                                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SAVE_ENABLE_FVAL                                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RETAIN_BMSK                                                             0x100U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RETAIN_SHFT                                                                 8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RETAIN_DISABLE_FVAL                                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_RETAIN_ENABLE_FVAL                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_REST_BMSK                                                             0x80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_REST_SHFT                                                                7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_REST_DISABLE_FVAL                                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_REST_ENABLE_FVAL                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_FEW_BMSK                                                              0x40U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_FEW_SHFT                                                                 6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_FEW_DISABLE_FVAL                                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_EN_FEW_ENABLE_FVAL                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLAMP_IO_BMSK                                                            0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLAMP_IO_SHFT                                                               5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLAMP_IO_DISABLE_FVAL                                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLAMP_IO_ENABLE_FVAL                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLK_DISABLE_BMSK                                                         0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLK_DISABLE_SHFT                                                            4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_PD_ARES_BMSK                                                              0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_PD_ARES_SHFT                                                                3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_PD_ARES_NO_RESET_FVAL                                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_PD_ARES_RESET_FVAL                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SW_OVERRIDE_BMSK                                                          0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SW_OVERRIDE_SHFT                                                            2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_HW_CONTROL_BMSK                                                           0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_HW_CONTROL_SHFT                                                             1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_HW_CONTROL_DISABLE_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_HW_CONTROL_ENABLE_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SW_COLLAPSE_BMSK                                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SW_COLLAPSE_SHFT                                                            0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                                   0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5060U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5060U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_RMSK                                                            0x3ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                                         0x2000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                                25U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                                          0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                                 24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                                   0xf00000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                                         20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                                      0x80000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                           19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                                          0x40000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                               18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                                          0x20000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                               17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                                       0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                            16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                                      0x8000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                                          15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                                     0x7800U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                                         11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                             0x400U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                                10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                                      0x200U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                                          9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                                      0x100U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                                          8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                                          0x80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                             7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                                 0x60U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                                    5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                              4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                                     0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                       3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                                       0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                         1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5064U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5064U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_RMSK                                                             0x7ffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                                 0x40000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                                      18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                             0x20000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                                  17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                           0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                                16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                               0xf000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                                   12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                                        0xf00U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                            8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                           0xf0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                              4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                             0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                               0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5068U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5068U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_RMSK                                                           0x7ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK                         0x4000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                                26U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                                      0x2000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                             25U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                                 0x1e00000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                                        21U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                                  0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                                        20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK                         0x80000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                              19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                             0x40000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                                  18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                              0x20000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                                   17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                                   0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                                        16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                           0xff00U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                                8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                            0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                               0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x506cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x506cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_RMSK                                                            0xffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                              0xf00000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                                    20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                               0xf0000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                                    16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                               0xf000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                                   12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                              0xf00U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                                  8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                                    0xf0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                                       4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_RETAINFF_BMSK                                                    0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CFG4_GDSCR_DLY_RETAINFF_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ADDR                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5070U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_OFFS                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5070U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_RMSK                                                      0x80000013UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ROOT_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ROOT_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                             0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ROOT_EN_BMSK                                                     0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ROOT_EN_SHFT                                                       1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_UPDATE_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_UPDATE_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_UPDATE_DISABLE_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CMD_RCGR_UPDATE_ENABLE_FVAL                                               0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_ADDR                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5074U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_OFFS                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5074U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_RMSK                                                        0x11071fUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_HW_CLK_CONTROL_BMSK                                         0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_HW_CLK_CONTROL_SHFT                                               20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_RCGLITE_DISABLE_BMSK                                         0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_RCGLITE_DISABLE_SHFT                                              16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_BMSK                                                   0x700U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_SHFT                                                       8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_BMSK                                                    0x1fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_SHFT                                                       0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                              0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                              0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                              0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                              0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                              0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                              0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                              0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                             0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV9_FVAL                                               0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                             0x12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV10_FVAL                                              0x13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                            0x14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV11_FVAL                                              0x15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                            0x16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV12_FVAL                                              0x17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                            0x18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV13_FVAL                                              0x19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                            0x1aU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV14_FVAL                                              0x1bU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                            0x1cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV15_FVAL                                              0x1dU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                            0x1eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CFG_RCGR_SRC_DIV_DIV16_FVAL                                              0x1fU

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x50a8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x50a8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_RMSK                                                          0x81c07ff5UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_OFF_BMSK                                                  0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_OFF_SHFT                                                          31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_IGNORE_ALL_ARES_SHFT                                                  24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_DIS_BMSK                                                    0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_DIS_SHFT                                                          22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_CORE_ON_BMSK                                            0x4000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_CORE_ON_SHFT                                                14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                          0x2000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                              13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                         0x1000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                             12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_BMSK                                                        0xf00U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_SHFT                                                            8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK0_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK1_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK2_FVAL                                                   0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK3_FVAL                                                   0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK4_FVAL                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK5_FVAL                                                   0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK6_FVAL                                                   0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK7_FVAL                                                   0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK8_FVAL                                                   0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK9_FVAL                                                   0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK10_FVAL                                                  0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK11_FVAL                                                  0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK12_FVAL                                                  0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK13_FVAL                                                  0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK14_FVAL                                                  0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_WAKEUP_CLOCK15_FVAL                                                  0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_BMSK                                                          0xf0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_SHFT                                                             4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK0_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK1_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK2_FVAL                                                    0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK3_FVAL                                                    0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK4_FVAL                                                    0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK5_FVAL                                                    0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK6_FVAL                                                    0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK7_FVAL                                                    0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK8_FVAL                                                    0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK9_FVAL                                                    0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK10_FVAL                                                   0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK11_FVAL                                                   0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK12_FVAL                                                   0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK13_FVAL                                                   0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK14_FVAL                                                   0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_SLEEP_CLOCK15_FVAL                                                   0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_ARES_BMSK                                                        0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_ARES_SHFT                                                          2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_ARES_NO_RESET_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_ARES_RESET_FVAL                                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_ENABLE_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_ENABLE_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_ENABLE_DISABLE_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_CBCR_CLK_ENABLE_ENABLE_FVAL                                               0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_ADDR                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x50acU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_OFFS                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x50acU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_RMSK                                                         0xfffffffeUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                               0xff000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                       24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                  0xff0000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                        16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                     0x8000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                         15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                      0x4000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                          14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                     0x2000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                         13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                                 0x1000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                     12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                           0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CORE_ON_ACK_BMSK                                              0x800U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CORE_ON_ACK_SHFT                                                 11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_PERIPH_ON_ACK_BMSK                                            0x400U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_PERIPH_ON_ACK_SHFT                                               10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                     0x300U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                         8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                              0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                              0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CPH_ENABLE_BMSK                                                0x80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CPH_ENABLE_SHFT                                                   7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_FORCE_CLK_ON_BMSK                                                  0x40U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_FORCE_CLK_ON_SHFT                                                     6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_RST_SEL_SLP_STG_BMSK                                            0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_RST_SEL_SLP_STG_SHFT                                               5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_RST_SLP_STG_BMSK                                                0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_RST_SLP_STG_SHFT                                                   4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CTRL_PWR_DOWN_BMSK                                               0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CTRL_PWR_DOWN_SHFT                                                 3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                          0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                            2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CLK_EN_SLP_STG_BMSK                                              0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CLK_EN_SLP_STG_SHFT                                                1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                        0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                         0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_ADDR                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x50b0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_OFFS                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x50b0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_RMSK                                                         0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_CLK_OFF_BMSK                                                 0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_CLK_OFF_SHFT                                                         31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_IGNORE_ALL_ARES_BMSK                                          0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_IGNORE_ALL_ARES_SHFT                                                 24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                        0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                              23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_CLK_DIS_BMSK                                                   0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_CLK_DIS_SHFT                                                         22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_CLK_ARES_BMSK                                                       0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_CLK_ARES_SHFT                                                         2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_CLK_ARES_NO_RESET_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_VSENSE_CBCR_CLK_ARES_RESET_FVAL                                                 0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x50b4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x50b4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_RMSK                                                     0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_QDSS_TSCTR_CBCR_CLK_ARES_RESET_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_ADDR                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x50b8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_OFFS                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x50b8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_RMSK                                                            0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_OFF_BMSK                                                    0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_OFF_SHFT                                                            31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_IGNORE_ALL_ARES_BMSK                                             0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_IGNORE_ALL_ARES_SHFT                                                    24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                           0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                 23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_DIS_BMSK                                                      0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_DIS_SHFT                                                            22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_ARES_BMSK                                                          0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_ARES_SHFT                                                            2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_ARES_NO_RESET_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_ARES_RESET_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_ENABLE_BMSK                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_ENABLE_SHFT                                                          0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_ENABLE_DISABLE_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_CXO_CBCR_CLK_ENABLE_ENABLE_FVAL                                                 0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_ADDR                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x50bcU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_OFFS                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x50bcU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_RMSK                                                            0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_OFF_BMSK                                                    0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_OFF_SHFT                                                            31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_IGNORE_ALL_ARES_BMSK                                             0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_IGNORE_ALL_ARES_SHFT                                                    24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                           0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                 23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_DIS_BMSK                                                      0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_DIS_SHFT                                                            22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_ARES_BMSK                                                          0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_ARES_SHFT                                                            2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_ARES_NO_RESET_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_ARES_RESET_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_ENABLE_BMSK                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_ENABLE_SHFT                                                          0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_ENABLE_DISABLE_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GMU_CBCR_CLK_ENABLE_ENABLE_FVAL                                                 0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x50c0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x50c0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_RMSK                                                             0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_OFF_BMSK                                                     0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_OFF_SHFT                                                             31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_IGNORE_ALL_ARES_BMSK                                              0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_IGNORE_ALL_ARES_SHFT                                                     24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                            0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                  23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_DIS_BMSK                                                       0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_DIS_SHFT                                                             22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_ARES_BMSK                                                           0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_ARES_SHFT                                                             2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_ARES_NO_RESET_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_ARES_RESET_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_ENABLE_BMSK                                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_ENABLE_SHFT                                                           0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_ENABLE_DISABLE_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_FF_CBCR_CLK_ENABLE_ENABLE_FVAL                                                  0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x50c8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x50c8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_RMSK                                                     0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GFX3D_RDVM_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_ADDR                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5104U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_OFFS                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5104U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_RMSK                                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_BLK_ARES_BMSK                                                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_BLK_ARES_SHFT                                                                 0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_BLK_ARES_DISABLE_FVAL                                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_BCR_BLK_ARES_ENABLE_FVAL                                                        0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_ADDR                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5108U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_OFFS                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5108U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RMSK                                                               0xf8ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_PWR_ON_BMSK                                                        0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_PWR_ON_SHFT                                                                31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_GDSC_STATE_BMSK                                                    0x78000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_GDSC_STATE_SHFT                                                            27U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_REST_WAIT_BMSK                                                    0xf00000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_REST_WAIT_SHFT                                                          20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_FEW_WAIT_BMSK                                                      0xf0000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_FEW_WAIT_SHFT                                                           16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLK_DIS_WAIT_BMSK                                                      0xf000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLK_DIS_WAIT_SHFT                                                          12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RETAIN_FF_ENABLE_BMSK                                                   0x800U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RETAIN_FF_ENABLE_SHFT                                                      11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RESTORE_BMSK                                                            0x400U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RESTORE_SHFT                                                               10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RESTORE_DISABLE_FVAL                                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RESTORE_ENABLE_FVAL                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SAVE_BMSK                                                               0x200U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SAVE_SHFT                                                                   9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SAVE_DISABLE_FVAL                                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SAVE_ENABLE_FVAL                                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RETAIN_BMSK                                                             0x100U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RETAIN_SHFT                                                                 8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RETAIN_DISABLE_FVAL                                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_RETAIN_ENABLE_FVAL                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_REST_BMSK                                                             0x80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_REST_SHFT                                                                7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_REST_DISABLE_FVAL                                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_REST_ENABLE_FVAL                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_FEW_BMSK                                                              0x40U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_FEW_SHFT                                                                 6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_FEW_DISABLE_FVAL                                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_EN_FEW_ENABLE_FVAL                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLAMP_IO_BMSK                                                            0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLAMP_IO_SHFT                                                               5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLAMP_IO_DISABLE_FVAL                                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLAMP_IO_ENABLE_FVAL                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLK_DISABLE_BMSK                                                         0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLK_DISABLE_SHFT                                                            4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_PD_ARES_BMSK                                                              0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_PD_ARES_SHFT                                                                3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_PD_ARES_NO_RESET_FVAL                                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_PD_ARES_RESET_FVAL                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SW_OVERRIDE_BMSK                                                          0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SW_OVERRIDE_SHFT                                                            2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_HW_CONTROL_BMSK                                                           0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_HW_CONTROL_SHFT                                                             1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_HW_CONTROL_DISABLE_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_HW_CONTROL_ENABLE_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SW_COLLAPSE_BMSK                                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SW_COLLAPSE_SHFT                                                            0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                                   0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x510cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x510cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_RMSK                                                            0x3ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                                         0x2000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                                25U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                                          0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                                 24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                                   0xf00000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                                         20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                                      0x80000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                           19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                                          0x40000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                               18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                                          0x20000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                               17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                                       0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                            16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                                      0x8000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                                          15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                                     0x7800U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                                         11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                             0x400U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                                10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                                      0x200U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                                          9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                                      0x100U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                                          8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                                          0x80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                             7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                                 0x60U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                                    5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                              4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                                     0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                       3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                                       0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                         1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5110U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5110U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_RMSK                                                             0x7ffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                                 0x40000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                                      18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                             0x20000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                                  17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                           0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                                16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                               0xf000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                                   12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                                        0xf00U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                            8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                           0xf0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                              4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                             0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                               0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5114U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5114U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_RMSK                                                           0x7ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK                         0x4000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                                26U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                                      0x2000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                             25U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                                 0x1e00000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                                        21U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                                  0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                                        20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK                         0x80000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                              19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                             0x40000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                                  18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                              0x20000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                                   17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                                   0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                                        16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                           0xff00U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                                8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                            0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                               0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5118U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5118U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_RMSK                                                            0xffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                              0xf00000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                                    20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                               0xf0000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                                    16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                               0xf000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                                   12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                              0xf00U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                                  8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                                    0xf0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                                       4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_RETAINFF_BMSK                                                    0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_CFG4_GDSCR_DLY_RETAINFF_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_ADDR                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x511cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_OFFS                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x511cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_RMSK                                                               0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_CLK_OFF_BMSK                                                       0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_CLK_OFF_SHFT                                                               31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                                0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                                       24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                              0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                    23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_CLK_DIS_BMSK                                                         0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_CLK_DIS_SHFT                                                               22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_CLK_ARES_BMSK                                                             0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_CLK_ARES_SHFT                                                               2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_AHB_CBCR_CLK_ARES_RESET_FVAL                                                       0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5120U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5120U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_RMSK                                                           0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_CLK_OFF_BMSK                                                   0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_CLK_OFF_SHFT                                                           31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                            0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                                   24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                          0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_CLK_DIS_BMSK                                                     0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_CLK_DIS_SHFT                                                           22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_CLK_ARES_BMSK                                                         0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_CLK_ARES_SHFT                                                           2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CRC_AHB_CBCR_CLK_ARES_RESET_FVAL                                                   0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_ADDR                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5124U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_OFFS                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5124U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_RMSK                                                        0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_AT_CBCR_CLK_ARES_RESET_FVAL                                                0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5128U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5128U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_RMSK                                                     0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TSCTR_CBCR_CLK_ARES_RESET_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_ADDR                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x512cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_OFFS                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x512cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_RMSK                                                            0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_CLK_OFF_BMSK                                                    0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_CLK_OFF_SHFT                                                            31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_IGNORE_ALL_ARES_BMSK                                             0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_IGNORE_ALL_ARES_SHFT                                                    24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                           0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                 23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_CLK_DIS_BMSK                                                      0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_CLK_DIS_SHFT                                                            22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_CLK_ARES_BMSK                                                          0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_CLK_ARES_SHFT                                                            2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_CLK_ARES_NO_RESET_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_APB_CBCR_CLK_ARES_RESET_FVAL                                                    0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_ADDR                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5130U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_OFFS                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5130U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_RMSK                                                       0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_CLK_OFF_BMSK                                               0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_CLK_OFF_SHFT                                                       31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_IGNORE_ALL_ARES_BMSK                                        0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_IGNORE_ALL_ARES_SHFT                                               24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                      0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                            23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_CLK_DIS_BMSK                                                 0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_CLK_DIS_SHFT                                                       22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_CLK_ARES_BMSK                                                     0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_CLK_ARES_SHFT                                                       2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_CLK_ARES_NO_RESET_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_SNOC_DVM_CBCR_CLK_ARES_RESET_FVAL                                               0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5134U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5134U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_RMSK                                                             0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_CLK_OFF_BMSK                                                     0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_CLK_OFF_SHFT                                                             31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                                              0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                                     24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                            0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                  23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_CLK_DIS_BMSK                                                       0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_CLK_DIS_SHFT                                                             22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_CLK_ARES_BMSK                                                           0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_CLK_ARES_SHFT                                                             2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                                     0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_ADDR                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5138U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_OFFS                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5138U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_RMSK                                                      0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_CLK_OFF_BMSK                                              0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_CLK_OFF_SHFT                                                      31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_IGNORE_ALL_ARES_SHFT                                              24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_CLK_DIS_BMSK                                                0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_CLK_DIS_SHFT                                                      22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_CLK_ARES_BMSK                                                    0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_CLK_ARES_SHFT                                                      2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_QDSS_TRIG_CBCR_CLK_ARES_RESET_FVAL                                              0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_ADDR                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x513cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_OFFS                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x513cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_RMSK                                                            0x81c07ff5UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_OFF_BMSK                                                    0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_OFF_SHFT                                                            31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_IGNORE_ALL_ARES_BMSK                                             0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_IGNORE_ALL_ARES_SHFT                                                    24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                           0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                 23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_DIS_BMSK                                                      0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_DIS_SHFT                                                            22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_CORE_ON_BMSK                                              0x4000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_CORE_ON_SHFT                                                  14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                            0x2000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                                13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                           0x1000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                               12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_BMSK                                                          0xf00U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_SHFT                                                              8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK0_FVAL                                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK1_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK2_FVAL                                                     0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK3_FVAL                                                     0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK4_FVAL                                                     0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK5_FVAL                                                     0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK6_FVAL                                                     0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK7_FVAL                                                     0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK8_FVAL                                                     0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK9_FVAL                                                     0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK10_FVAL                                                    0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK11_FVAL                                                    0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK12_FVAL                                                    0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK13_FVAL                                                    0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK14_FVAL                                                    0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_WAKEUP_CLOCK15_FVAL                                                    0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_BMSK                                                            0xf0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_SHFT                                                               4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK0_FVAL                                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK1_FVAL                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK2_FVAL                                                      0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK3_FVAL                                                      0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK4_FVAL                                                      0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK5_FVAL                                                      0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK6_FVAL                                                      0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK7_FVAL                                                      0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK8_FVAL                                                      0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK9_FVAL                                                      0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK10_FVAL                                                     0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK11_FVAL                                                     0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK12_FVAL                                                     0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK13_FVAL                                                     0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK14_FVAL                                                     0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_SLEEP_CLOCK15_FVAL                                                     0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_ARES_BMSK                                                          0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_ARES_SHFT                                                            2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_ARES_NO_RESET_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_ARES_RESET_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_ENABLE_BMSK                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_ENABLE_SHFT                                                          0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_ENABLE_DISABLE_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_CBCR_CLK_ENABLE_ENABLE_FVAL                                                 0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5140U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5140U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_RMSK                                                           0xfffffffeUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                                 0xff000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                         24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                    0xff0000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                          16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                       0x8000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                           15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                        0x4000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                            14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                           0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                       0x2000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                           13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                                   0x1000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                       12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CORE_ON_ACK_BMSK                                                0x800U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CORE_ON_ACK_SHFT                                                   11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_PERIPH_ON_ACK_BMSK                                              0x400U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_PERIPH_ON_ACK_SHFT                                                 10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                       0x300U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                           8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                                0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                                0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CPH_ENABLE_BMSK                                                  0x80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CPH_ENABLE_SHFT                                                     7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_FORCE_CLK_ON_BMSK                                                    0x40U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_FORCE_CLK_ON_SHFT                                                       6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_RST_SEL_SLP_STG_BMSK                                              0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_RST_SEL_SLP_STG_SHFT                                                 5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_RST_SLP_STG_BMSK                                                  0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_RST_SLP_STG_SHFT                                                     4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CTRL_PWR_DOWN_BMSK                                                 0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CTRL_PWR_DOWN_SHFT                                                   3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                            0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                              2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CLK_EN_SLP_STG_BMSK                                                0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CLK_EN_SLP_STG_SHFT                                                  1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GMU_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                           0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_ADDR                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5144U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_OFFS                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5144U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_RMSK                                                               0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_OFF_BMSK                                                       0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_OFF_SHFT                                                               31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_IGNORE_ALL_ARES_BMSK                                                0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_IGNORE_ALL_ARES_SHFT                                                       24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                              0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                    23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_DIS_BMSK                                                         0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_DIS_SHFT                                                               22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_ARES_BMSK                                                             0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_ARES_SHFT                                                               2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_ARES_NO_RESET_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_ARES_RESET_FVAL                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_ENABLE_BMSK                                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_ENABLE_SHFT                                                             0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_ENABLE_DISABLE_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CBCR_CLK_ENABLE_ENABLE_FVAL                                                    0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_ADDR                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5148U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_OFFS                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5148U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_RMSK                                                        0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x514cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x514cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_RMSK                                                             0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_OFF_BMSK                                                     0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_OFF_SHFT                                                             31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_IGNORE_ALL_ARES_BMSK                                              0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_IGNORE_ALL_ARES_SHFT                                                     24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                            0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                  23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_DIS_BMSK                                                       0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_DIS_SHFT                                                             22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_ARES_BMSK                                                           0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_ARES_SHFT                                                             2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_ARES_NO_RESET_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_ARES_RESET_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_ENABLE_BMSK                                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_ENABLE_SHFT                                                           0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_ENABLE_DISABLE_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_FF_CBCR_CLK_ENABLE_ENABLE_FVAL                                                  0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_ADDR                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5150U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_OFFS                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5150U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_RMSK                                                        0x81c07ff5UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_IGNORE_ALL_ARES_SHFT                                                24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_DIS_BMSK                                                  0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_DIS_SHFT                                                        22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_CORE_ON_BMSK                                          0x4000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_CORE_ON_SHFT                                              14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                        0x2000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                            13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                             0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                       0x1000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                           12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_BMSK                                                      0xf00U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_SHFT                                                          8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK0_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK1_FVAL                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK2_FVAL                                                 0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK3_FVAL                                                 0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK4_FVAL                                                 0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK5_FVAL                                                 0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK6_FVAL                                                 0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK7_FVAL                                                 0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK8_FVAL                                                 0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK9_FVAL                                                 0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK10_FVAL                                                0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK11_FVAL                                                0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK12_FVAL                                                0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK13_FVAL                                                0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK14_FVAL                                                0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_WAKEUP_CLOCK15_FVAL                                                0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_BMSK                                                        0xf0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_SHFT                                                           4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK0_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK1_FVAL                                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK2_FVAL                                                  0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK3_FVAL                                                  0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK4_FVAL                                                  0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK5_FVAL                                                  0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK6_FVAL                                                  0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK7_FVAL                                                  0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK8_FVAL                                                  0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK9_FVAL                                                  0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK10_FVAL                                                 0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK11_FVAL                                                 0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK12_FVAL                                                 0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK13_FVAL                                                 0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK14_FVAL                                                 0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_SLEEP_CLOCK15_FVAL                                                 0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_ARES_BMSK                                                      0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_ARES_SHFT                                                        2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_ARES_RESET_FVAL                                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_ENABLE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_ENABLE_SHFT                                                      0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_ADDR                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5154U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_OFFS                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5154U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_RMSK                                                       0xfffffffeUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                             0xff000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                     24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                                0xff0000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                      16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                   0x8000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                       15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                    0x4000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                        14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                   0x2000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                       13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                               0x1000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                   12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CORE_ON_ACK_BMSK                                            0x800U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CORE_ON_ACK_SHFT                                               11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_PERIPH_ON_ACK_BMSK                                          0x400U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_PERIPH_ON_ACK_SHFT                                             10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                   0x300U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                       8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                            0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                            0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CPH_ENABLE_BMSK                                              0x80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CPH_ENABLE_SHFT                                                 7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_FORCE_CLK_ON_BMSK                                                0x40U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_FORCE_CLK_ON_SHFT                                                   6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                        0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_RST_SEL_SLP_STG_BMSK                                          0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_RST_SEL_SLP_STG_SHFT                                             5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_RST_SLP_STG_BMSK                                              0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_RST_SLP_STG_SHFT                                                 4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CTRL_PWR_DOWN_BMSK                                             0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CTRL_PWR_DOWN_SHFT                                               3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                        0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                          2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CLK_EN_SLP_STG_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CLK_EN_SLP_STG_SHFT                                              1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                       0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5198U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5198U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_RMSK                                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_BLK_ARES_BMSK                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_BLK_ARES_SHFT                                                          0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_BLK_ARES_DISABLE_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_BCR_BLK_ARES_ENABLE_FVAL                                                 0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x519cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x519cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_RMSK                                                          0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_CLK_OFF_BMSK                                                  0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_CLK_OFF_SHFT                                                          31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_IGNORE_ALL_ARES_SHFT                                                  24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_CLK_DIS_BMSK                                                    0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_CLK_DIS_SHFT                                                          22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_CLK_ARES_BMSK                                                        0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_CLK_ARES_SHFT                                                          2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_CLK_ARES_NO_RESET_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_CBCR_CLK_ARES_RESET_FVAL                                                  0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_ADDR                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x51a0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_OFFS                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x51a0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_RMSK                                                      0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_CLK_OFF_BMSK                                              0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_CLK_OFF_SHFT                                                      31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_IGNORE_ALL_ARES_SHFT                                              24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_CLK_DIS_BMSK                                                0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_CLK_DIS_SHFT                                                      22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_CLK_ARES_BMSK                                                    0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_CLK_ARES_SHFT                                                      2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GFX3D_SLV_CBCR_CLK_ARES_RESET_FVAL                                              0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_ADDR                                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x51e0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_OFFS                                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x51e0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_RMSK                                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_BLK_ARES_BMSK                                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_BLK_ARES_SHFT                                                              0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_BLK_ARES_DISABLE_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_BCR_BLK_ARES_ENABLE_FVAL                                                     0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ADDR                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x51e4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_OFFS                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x51e4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_RMSK                                                         0x80000013UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ROOT_OFF_BMSK                                                0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ROOT_OFF_SHFT                                                        31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                                0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                   4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ROOT_EN_BMSK                                                        0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ROOT_EN_SHFT                                                          1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_UPDATE_BMSK                                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_UPDATE_SHFT                                                           0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_UPDATE_DISABLE_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CMD_RCGR_UPDATE_ENABLE_FVAL                                                  0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_ADDR                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x51e8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_OFFS                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x51e8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_RMSK                                                           0x11071fUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_HW_CLK_CONTROL_BMSK                                            0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_HW_CLK_CONTROL_SHFT                                                  20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_RCGLITE_DISABLE_BMSK                                            0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_RCGLITE_DISABLE_SHFT                                                 16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_BMSK                                                      0x700U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_SHFT                                                          8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                   0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                   0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                   0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                   0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                   0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_BMSK                                                       0x1fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_SHFT                                                          0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                                 0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                   0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                                 0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                   0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                                 0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                   0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                                 0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                   0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                                 0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                   0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                                 0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                   0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                                 0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                   0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                                0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV9_FVAL                                                  0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                                0x12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV10_FVAL                                                 0x13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                               0x14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV11_FVAL                                                 0x15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                               0x16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV12_FVAL                                                 0x17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                               0x18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV13_FVAL                                                 0x19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                               0x1aU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV14_FVAL                                                 0x1bU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                               0x1cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV15_FVAL                                                 0x1dU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                               0x1eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CFG_RCGR_SRC_DIV_DIV16_FVAL                                                 0x1fU

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5224U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5224U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_RMSK                                                             0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_OFF_BMSK                                                     0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_OFF_SHFT                                                             31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_IGNORE_ALL_ARES_BMSK                                              0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_IGNORE_ALL_ARES_SHFT                                                     24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                            0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                  23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_DIS_BMSK                                                       0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_DIS_SHFT                                                             22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_ARES_BMSK                                                           0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_ARES_SHFT                                                             2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_ARES_NO_RESET_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_ARES_RESET_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_ENABLE_BMSK                                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_ENABLE_SHFT                                                           0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_ENABLE_DISABLE_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_CBCR_CLK_ENABLE_ENABLE_FVAL                                                  0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_ADDR                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5228U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_OFFS                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5228U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_RMSK                                                         0x81c00004UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_CLK_OFF_BMSK                                                 0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_CLK_OFF_SHFT                                                         31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                          0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                                 24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                        0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                              23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_CLK_DIS_BMSK                                                   0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_CLK_DIS_SHFT                                                         22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_CLK_ARES_BMSK                                                       0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_CLK_ARES_SHFT                                                         2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RBCPR_AHB_CBCR_CLK_ARES_RESET_FVAL                                                 0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_ADDR                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5270U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_OFFS                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5270U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_RMSK                                                               0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_CLK_DIV_BMSK                                                       0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_DIV_CDIVR_CLK_DIV_SHFT                                                         0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_ADDR                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5274U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_OFFS                                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5274U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_RMSK                                                             0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_OFF_BMSK                                                     0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_OFF_SHFT                                                             31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_IGNORE_ALL_ARES_BMSK                                              0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_IGNORE_ALL_ARES_SHFT                                                     24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                            0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                  23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_DIS_BMSK                                                       0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_DIS_SHFT                                                             22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_ARES_BMSK                                                           0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_ARES_SHFT                                                             2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_ARES_NO_RESET_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_ARES_RESET_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_ENABLE_BMSK                                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_ENABLE_SHFT                                                           0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_ENABLE_DISABLE_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_CBCR_CLK_ENABLE_ENABLE_FVAL                                                  0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5278U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5278U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_RMSK                                                     0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5280U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5280U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_RMSK                                                            0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_CLK_DIV_BMSK                                                    0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_DIV_CDIVR_CLK_DIV_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5284U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5284U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_RMSK                                                          0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_OFF_BMSK                                                  0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_OFF_SHFT                                                          31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_IGNORE_ALL_ARES_SHFT                                                  24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_DIS_BMSK                                                    0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_DIS_SHFT                                                          22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_ARES_BMSK                                                        0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_ARES_SHFT                                                          2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_ARES_NO_RESET_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_ARES_RESET_FVAL                                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_ENABLE_BMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_ENABLE_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_ENABLE_DISABLE_FVAL                                              0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_CBCR_CLK_ENABLE_ENABLE_FVAL                                               0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x528cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x528cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_RMSK                                                     0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MND1X_1_GFX3D_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_ADDR                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x52ccU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_OFFS                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x52ccU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_RMSK                                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_BLK_ARES_BMSK                                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_BLK_ARES_SHFT                                                               0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_BLK_ARES_DISABLE_FVAL                                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_BCR_BLK_ARES_ENABLE_FVAL                                                      0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x52d0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x52d0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_RMSK                                                       0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_CLK_DIV_BMSK                                               0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CDIVR_CLK_DIV_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_ADDR                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x52d4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_OFFS                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x52d4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_RMSK                                                 0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_OFF_BMSK                                         0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_OFF_SHFT                                                 31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_IGNORE_ALL_ARES_BMSK                                  0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_IGNORE_ALL_ARES_SHFT                                         24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                      23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_DIS_BMSK                                           0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_DIS_SHFT                                                 22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_ARES_BMSK                                               0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_ARES_SHFT                                                 2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_ARES_NO_RESET_FVAL                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_ARES_RESET_FVAL                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_ENABLE_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_ENABLE_SHFT                                               0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_ENABLE_DISABLE_FVAL                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SPDM_GX_GFX3D_DIV_CBCR_CLK_ENABLE_ENABLE_FVAL                                      0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_ADDR                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5314U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_OFFS                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5314U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_RMSK                                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_BLK_ARES_BMSK                                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_BLK_ARES_SHFT                                                                0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_BLK_ARES_DISABLE_FVAL                                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_BCR_BLK_ARES_ENABLE_FVAL                                                       0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5318U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5318U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_RMSK                                                           0x80000013UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ROOT_OFF_BMSK                                                  0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ROOT_OFF_SHFT                                                          31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                                  0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                     4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ROOT_EN_BMSK                                                          0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ROOT_EN_SHFT                                                            1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_UPDATE_BMSK                                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_UPDATE_SHFT                                                             0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_UPDATE_DISABLE_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CMD_RCGR_UPDATE_ENABLE_FVAL                                                    0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x531cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x531cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_RMSK                                                             0x11071fUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_HW_CLK_CONTROL_BMSK                                              0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_HW_CLK_CONTROL_SHFT                                                    20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_RCGLITE_DISABLE_BMSK                                              0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_RCGLITE_DISABLE_SHFT                                                   16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_BMSK                                                        0x700U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_SHFT                                                            8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                     0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                     0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                     0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                     0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                     0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                     0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_BMSK                                                         0x1fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_SHFT                                                            0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                                   0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                     0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                     0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                                   0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                     0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                                   0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                     0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                                   0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                     0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                                   0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                     0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                                   0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                     0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                                  0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV9_FVAL                                                    0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                                  0x12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV10_FVAL                                                   0x13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                                 0x14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV11_FVAL                                                   0x15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                                 0x16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV12_FVAL                                                   0x17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                                 0x18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV13_FVAL                                                   0x19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                                 0x1aU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV14_FVAL                                                   0x1bU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                                 0x1cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV15_FVAL                                                   0x1dU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                                 0x1eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GMU_CFG_RCGR_SRC_DIV_DIV16_FVAL                                                   0x1fU

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_ADDR                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5358U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_OFFS                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5358U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_RMSK                                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_BLK_ARES_BMSK                                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_BLK_ARES_SHFT                                                                0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_BLK_ARES_DISABLE_FVAL                                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_BCR_BLK_ARES_ENABLE_FVAL                                                       0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x535cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x535cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_RMSK                                                           0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_OFF_BMSK                                                   0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_OFF_SHFT                                                           31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_IGNORE_ALL_ARES_BMSK                                            0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_IGNORE_ALL_ARES_SHFT                                                   24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                          0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_DIS_BMSK                                                     0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_DIS_SHFT                                                           22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_ARES_BMSK                                                         0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_ARES_SHFT                                                           2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_ARES_NO_RESET_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_ARES_RESET_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_ENABLE_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_ENABLE_SHFT                                                         0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_ENABLE_DISABLE_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_CXO_CBCR_CLK_ENABLE_ENABLE_FVAL                                                0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5360U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5360U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_RMSK                                                           0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_OFF_BMSK                                                   0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_OFF_SHFT                                                           31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                            0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                                   24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                          0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_DIS_BMSK                                                     0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_DIS_SHFT                                                           22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_ARES_BMSK                                                         0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_ARES_SHFT                                                           2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_ARES_RESET_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_ENABLE_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_ENABLE_SHFT                                                         0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_ENABLE_DISABLE_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB_CBCR_CLK_ENABLE_ENABLE_FVAL                                                0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_ADDR                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x53a0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_OFFS                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x53a0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_RMSK                                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_BLK_ARES_BMSK                                                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_BLK_ARES_SHFT                                                                 0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_BLK_ARES_DISABLE_FVAL                                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_BCR_BLK_ARES_ENABLE_FVAL                                                        0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_ADDR                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x53a4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_OFFS                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x53a4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_RMSK                                                                0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_OFF_BMSK                                                        0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_OFF_SHFT                                                                31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_IGNORE_ALL_ARES_BMSK                                                 0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_IGNORE_ALL_ARES_SHFT                                                        24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                               0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                     23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_DIS_BMSK                                                          0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_DIS_SHFT                                                                22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_ARES_BMSK                                                              0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_ARES_SHFT                                                                2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_ARES_NO_RESET_FVAL                                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_ARES_RESET_FVAL                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_ENABLE_BMSK                                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_ENABLE_SHFT                                                              0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_ENABLE_DISABLE_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CB_CBCR_CLK_ENABLE_ENABLE_FVAL                                                     0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x53e4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x53e4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_RMSK                                                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_BLK_ARES_BMSK                                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_BLK_ARES_SHFT                                                           0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_BLK_ARES_DISABLE_FVAL                                                 0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FAST_HUB_BCR_BLK_ARES_ENABLE_FVAL                                                  0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x53e8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x53e8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_RMSK                                                           0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_OFF_BMSK                                                   0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_OFF_SHFT                                                           31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_IGNORE_ALL_ARES_BMSK                                            0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_IGNORE_ALL_ARES_SHFT                                                   24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                          0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_DIS_BMSK                                                     0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_DIS_SHFT                                                           22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_ARES_BMSK                                                         0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_ARES_SHFT                                                           2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_ARES_NO_RESET_FVAL                                                0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_ARES_RESET_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_ENABLE_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_ENABLE_SHFT                                                         0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_ENABLE_DISABLE_FVAL                                               0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AON_CBCR_CLK_ENABLE_ENABLE_FVAL                                                0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x53ecU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x53ecU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_RMSK                                                           0x80000013UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ROOT_OFF_BMSK                                                  0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ROOT_OFF_SHFT                                                          31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                                  0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                     4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ROOT_EN_BMSK                                                          0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ROOT_EN_SHFT                                                            1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_UPDATE_BMSK                                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_UPDATE_SHFT                                                             0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_UPDATE_DISABLE_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CMD_RCGR_UPDATE_ENABLE_FVAL                                                    0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_ADDR                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x53f0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_OFFS                                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x53f0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_RMSK                                                             0x11071fUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_HW_CLK_CONTROL_BMSK                                              0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_HW_CLK_CONTROL_SHFT                                                    20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                           0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_RCGLITE_DISABLE_BMSK                                              0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_RCGLITE_DISABLE_SHFT                                                   16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_BMSK                                                        0x700U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_SHFT                                                            8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                     0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                     0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                     0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                     0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                     0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                     0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                     0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_BMSK                                                         0x1fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_SHFT                                                            0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                                   0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                     0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                     0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                                   0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                     0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                                   0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                     0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                                   0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                     0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                                   0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                     0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                                   0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                     0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                                  0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV9_FVAL                                                    0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                                  0x12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV10_FVAL                                                   0x13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                                 0x14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV11_FVAL                                                   0x15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                                 0x16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV12_FVAL                                                   0x17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                                 0x18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV13_FVAL                                                   0x19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                                 0x1aU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV14_FVAL                                                   0x1bU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                                 0x1cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV15_FVAL                                                   0x1dU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                                 0x1eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CFG_RCGR_SRC_DIV_DIV16_FVAL                                                   0x1fU

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_ADDR                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x542cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_OFFS                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x542cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_RMSK                                                          0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_CLK_DIV_BMSK                                                  0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_CX_INT_DIV_CDIVR_CLK_DIV_SHFT                                                    0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_ADDR                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5430U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_OFFS                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5430U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_RMSK                                                             0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_CLK_DIV_BMSK                                                     0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_HUB_AHB_DIV_CDIVR_CLK_DIV_SHFT                                                       0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_ADDR                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5470U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_OFFS                                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5470U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_RMSK                                                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_BLK_ARES_BMSK                                                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_BLK_ARES_SHFT                                                                 0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_BLK_ARES_DISABLE_FVAL                                                       0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_BCR_BLK_ARES_ENABLE_FVAL                                                        0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ADDR                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5474U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_OFFS                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5474U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_RMSK                                                            0x80000013UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ROOT_OFF_BMSK                                                   0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ROOT_OFF_SHFT                                                           31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                                   0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                                      4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ROOT_EN_BMSK                                                           0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ROOT_EN_SHFT                                                             1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_UPDATE_BMSK                                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_UPDATE_SHFT                                                              0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_UPDATE_DISABLE_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CMD_RCGR_UPDATE_ENABLE_FVAL                                                     0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_ADDR                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5478U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_OFFS                                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5478U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_RMSK                                                              0x11071fUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_HW_CLK_CONTROL_BMSK                                               0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_HW_CLK_CONTROL_SHFT                                                     20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                            0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_RCGLITE_DISABLE_BMSK                                               0x10000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_RCGLITE_DISABLE_SHFT                                                    16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                                   0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_BMSK                                                         0x700U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_SHFT                                                             8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_SRC0_FVAL                                                      0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_SRC1_FVAL                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_SRC2_FVAL                                                      0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_SRC3_FVAL                                                      0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_SRC4_FVAL                                                      0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_SRC5_FVAL                                                      0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_SRC6_FVAL                                                      0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_SEL_SRC7_FVAL                                                      0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_BMSK                                                          0x1fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_SHFT                                                             0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV1_FVAL                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                                    0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV2_FVAL                                                      0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                                    0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV3_FVAL                                                      0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                                    0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV4_FVAL                                                      0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                                    0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV5_FVAL                                                      0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                                    0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV6_FVAL                                                      0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                                    0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV7_FVAL                                                      0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                                    0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV8_FVAL                                                      0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                                   0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV9_FVAL                                                     0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                                   0x12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV10_FVAL                                                    0x13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                                  0x14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV11_FVAL                                                    0x15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                                  0x16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV12_FVAL                                                    0x17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                                  0x18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV13_FVAL                                                    0x19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                                  0x1aU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV14_FVAL                                                    0x1bU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                                  0x1cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV15_FVAL                                                    0x1dU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                                  0x1eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FF_CFG_RCGR_SRC_DIV_DIV16_FVAL                                                    0x1fU

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_ADDR                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5500U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_OFFS                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5500U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_RMSK                                                              0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_ENABLE_FSM_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_ENABLE_FSM_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_SMMU_CLK_ON_REQ_STATUS_BMSK                                       0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_SMMU_CLK_ON_REQ_STATUS_SHFT                                         1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_DVM_FSM_ACTIVE_STATUS_BMSK                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_CTL_DVM_FSM_ACTIVE_STATUS_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_ADDR                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5504U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_OFFS                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5504U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_RMSK                                                          0x3c0011UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_RAC_ENR_STATUS_BMSK                                           0x200000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_RAC_ENR_STATUS_SHFT                                                 21U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_RAC_ENF_STATUS_BMSK                                           0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_RAC_ENF_STATUS_SHFT                                                 20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_SPTP_ENR_STATUS_BMSK                                           0x80000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_SPTP_ENR_STATUS_SHFT                                                19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_SPTP_ENF_STATUS_BMSK                                           0x40000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_SPTP_ENF_STATUS_SHFT                                                18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_GPU_GX_RAIL_RESET_BMSK                                            0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_GPU_GX_RAIL_RESET_SHFT                                               4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_GPU_GX_RAIL_CLAMP_IO_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC3_GPU_GX_RAIL_CLAMP_IO_SHFT                                            0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_ADDR                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5508U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_OFFS                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5508U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_RMSK                                                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_GFX_CLAMP_MEM_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC4_GFX_CLAMP_MEM_SHFT                                                   0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x550cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x550cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_RMSK                                                            0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_DIV_BY_BMSK                                                     0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_AON_DIV_CTRL_DIV_BY_SHFT                                                       0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_ADDR                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5510U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_OFFS                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5510U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_RMSK                                                     0x3fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_BHS_REST_STRENGTH_BMSK                                   0x3cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_BHS_REST_STRENGTH_SHFT                                      2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_BHS_FEW_STRENGTH_BMSK                                     0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_STRENGTH_CTRL_BHS_FEW_STRENGTH_SHFT                                       0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_ADDR                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5514U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_OFFS                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5514U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_RMSK                                                        0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_BHS_REST_DELAY_SEL_BMSK                                     0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_BHS_REST_DELAY_SEL_SHFT                                        4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_BHS_FEW_DELAY_SEL_BMSK                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_HM_BHS_DELAY_CTRL_BHS_FEW_DELAY_SEL_SHFT                                         0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_ADDR                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5518U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_OFFS                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5518U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_RMSK                                                   0x3fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_BHS_REST_STRENGTH_BMSK                                 0x3cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_BHS_REST_STRENGTH_SHFT                                    2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_BHS_FEW_STRENGTH_BMSK                                   0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_STRENGTH_CTRL_BHS_FEW_STRENGTH_SHFT                                     0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x551cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x551cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_RMSK                                                      0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_BHS_REST_DELAY_SEL_BMSK                                   0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_BHS_REST_DELAY_SEL_SHFT                                      4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_BHS_FEW_DELAY_SEL_BMSK                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_SPTP_BHS_DELAY_CTRL_BHS_FEW_DELAY_SEL_SHFT                                       0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_ADDR                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5520U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_OFFS                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5520U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_RMSK                                                    0x3fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_BHS_REST_STRENGTH_BMSK                                  0x3cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_BHS_REST_STRENGTH_SHFT                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_BHS_FEW_STRENGTH_BMSK                                    0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_STRENGTH_CTRL_BHS_FEW_STRENGTH_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_ADDR                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5524U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_OFFS                                                 (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5524U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_RMSK                                                       0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_BHS_REST_DELAY_SEL_BMSK                                    0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_BHS_REST_DELAY_SEL_SHFT                                       4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_BHS_FEW_DELAY_SEL_BMSK                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX_RAC_BHS_DELAY_CTRL_BHS_FEW_DELAY_SEL_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5528U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5528U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_RMSK                                                          0x1fbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL1_MAIN_ACTIVE_SW_OVERRIDE_BMSK                         0x100U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL1_MAIN_ACTIVE_SW_OVERRIDE_SHFT                             8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL0_MAIN_ACTIVE_SW_OVERRIDE_BMSK                          0x80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL0_MAIN_ACTIVE_SW_OVERRIDE_SHFT                             7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL1_ODD_ACTIVE_SW_OVERRIDE_BMSK                           0x40U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL1_ODD_ACTIVE_SW_OVERRIDE_SHFT                              6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL1_EVEN_ACTIVE_SW_OVERRIDE_BMSK                          0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL1_EVEN_ACTIVE_SW_OVERRIDE_SHFT                             5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL0_ODD_ACTIVE_SW_OVERRIDE_BMSK                           0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL0_ODD_ACTIVE_SW_OVERRIDE_SHFT                              4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL0_EVEN_ACTIVE_SW_OVERRIDE_BMSK                           0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GPU_PLL0_EVEN_ACTIVE_SW_OVERRIDE_SHFT                             3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GCC_GPLL0_DIV_ACTIVE_SW_OVERRIDE_BMSK                           0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GCC_GPLL0_DIV_ACTIVE_SW_OVERRIDE_SHFT                             1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GCC_GPLL0_ACTIVE_SW_OVERRIDE_BMSK                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_CTL_GCC_GPLL0_ACTIVE_SW_OVERRIDE_SHFT                                 0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_ADDR                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x552cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_OFFS                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x552cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_RMSK                                                       0x1fbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL1_MAIN_ACTIVE_BMSK                                  0x100U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL1_MAIN_ACTIVE_SHFT                                      8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL0_MAIN_ACTIVE_BMSK                                   0x80U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL0_MAIN_ACTIVE_SHFT                                      7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL1_ODD_ACTIVE_BMSK                                    0x40U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL1_ODD_ACTIVE_SHFT                                       6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL1_EVEN_ACTIVE_BMSK                                   0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL1_EVEN_ACTIVE_SHFT                                      5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL0_ODD_ACTIVE_BMSK                                    0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL0_ODD_ACTIVE_SHFT                                       4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL0_EVEN_ACTIVE_BMSK                                    0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GPU_PLL0_EVEN_ACTIVE_SHFT                                      3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GCC_GPLL0_DIV_ACTIVE_BMSK                                    0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GCC_GPLL0_DIV_ACTIVE_SHFT                                      1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GCC_GPLL0_ACTIVE_BMSK                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_RCG_SRC_ACTIVE_STATUS_GCC_GPLL0_ACTIVE_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_STATUS_ADDR                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5530U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_STATUS_OFFS                                           (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5530U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_STATUS_RMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_STATUS_STATUS_BMSK                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_STATUS_STATUS_SHFT                                             0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_ADDR                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5534U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_OFFS                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5534U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_RMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_MASK_BMSK                                               0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_MASK_MASK_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_ADDR                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5538U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_OFFS                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5538U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_RMSK                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_CLEAR_BMSK                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_FREQUENCY_LIMITER_IRQ_CLEAR_CLEAR_SHFT                                               0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_ADDR                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x553cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_OFFS                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x553cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_RMSK                                                         0xb888dfffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_PWR_ON_STATUS_BMSK                                           0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_PWR_ON_STATUS_SHFT                                                   31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_DVM_HALT1_PWR_DOWN_ACK_STATUS_BMSK                           0x20000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_DVM_HALT1_PWR_DOWN_ACK_STATUS_SHFT                                   29U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_DVM_HALT1_PWR_UP_ACK_STATUS_BMSK                             0x10000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_DVM_HALT1_PWR_UP_ACK_STATUS_SHFT                                     28U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT1_PWR_DOWN_ACK_STATUS_BMSK                                0x8000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT1_PWR_DOWN_ACK_STATUS_SHFT                                       27U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT1_PWR_UP_ACK_STATUS_BMSK                                   0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT1_PWR_UP_ACK_STATUS_SHFT                                         23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT2_PWR_DOWN_ACK_STATUS_BMSK                                  0x80000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT2_PWR_DOWN_ACK_STATUS_SHFT                                       19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT2_PWR_UP_ACK_STATUS_BMSK                                     0x8000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT2_PWR_UP_ACK_STATUS_SHFT                                         15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_COLLAPSE_OUT_BMSK                                                0x4000U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_COLLAPSE_OUT_SHFT                                                    14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT_ACK_TIMEOUT_BMSK                                            0x1fe0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_HALT_ACK_TIMEOUT_SHFT                                                 5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_GDS_HW_STATE_BMSK                                                  0x1eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_GDS_HW_STATE_SHFT                                                     1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SW_OVERRIDE_BMSK                                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SW_OVERRIDE_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5540U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5540U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_RMSK                                                       0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_DVM_HALT_REQ_BMSK                                          0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_DVM_HALT_REQ_SHFT                                            2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_SMMU_HALT_REQ_BMSK                                         0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_SMMU_HALT_REQ_SHFT                                           1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_NOC_HALT_REQ_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_HALT_REQ_GDS_HW_CTRL_NOC_HALT_REQ_SHFT                                            0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_STATUS_ADDR                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5544U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_STATUS_OFFS                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5544U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_STATUS_RMSK                                                     0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_STATUS_STATUS_BMSK                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_STATUS_STATUS_SHFT                                                0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5548U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5548U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_RMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_MASK_BMSK                                                  0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_MASK_MASK_SHFT                                                    0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_ADDR                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x554cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_OFFS                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x554cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_RMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_CLEAR_BMSK                                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_IRQ_CLEAR_CLEAR_SHFT                                                  0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_ADDR                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5550U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_OFFS                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5550U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_RMSK                                                0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_SMMU_HALT_ACK_BMSK                                  0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_SMMU_HALT_ACK_SHFT                                    1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_SMMU_HALT_IDLE_BMSK                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTL_SMMU_HALT_STATUS_SMMU_HALT_IDLE_SHFT                                   0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_ADDR                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5554U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_OFFS                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5554U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_RMSK                                                         0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_SPARE_BMSK                                                   0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDS_HW_CTRL_SPARE_SPARE_SHFT                                                      0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5558U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5558U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_RMSK                                                           0x33U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_EN_FEW_ACK_SW_BMSK                                             0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_EN_FEW_ACK_SW_SHFT                                                5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_EN_REST_ACK_SW_BMSK                                            0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_EN_REST_ACK_SW_SHFT                                               4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_EN_FEW_ACK_STATUS_BMSK                                          0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_EN_FEW_ACK_STATUS_SHFT                                            1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_EN_REST_ACK_STATUS_BMSK                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_GDSC_EN_ACK_CTL_EN_REST_ACK_STATUS_SHFT                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x555cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x555cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_RMSK                                                           0x33U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_EN_FEW_ACK_SW_BMSK                                             0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_EN_FEW_ACK_SW_SHFT                                                5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_EN_REST_ACK_SW_BMSK                                            0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_EN_REST_ACK_SW_SHFT                                               4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_EN_FEW_ACK_STATUS_BMSK                                          0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_EN_FEW_ACK_STATUS_SHFT                                            1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_EN_REST_ACK_STATUS_BMSK                                         0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_GDSC_EN_ACK_CTL_EN_REST_ACK_STATUS_SHFT                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_STATE_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5560U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_STATE_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5560U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_STATE_RMSK                                                            0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_STATE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_STATE_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_STATE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_STATE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_STATE_FSM_STATE_BMSK                                                  0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_IDLE_REQ_FSM_STATE_FSM_STATE_SHFT                                                    0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_ADDR                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5564U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_OFFS                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5564U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_RMSK                                                               0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_BMSK                                                       0xffU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_SHFT                                                          0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GCC_GPU_CFG_AHB_CLK_FVAL                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GCC_GPU_SNOC_DVM_GFX_CLK_FVAL                               0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GCC_QDSS_TSCTR_DIV16_CLK_FVAL                               0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GCC_GPU_TRIG_CLK_FVAL                                       0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GCC_GPU_VS_CLK_FVAL                                         0x5U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GCC_GPU_APB_CLK_FVAL                                        0x6U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GCC_GPU_AT_CLK_FVAL                                         0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GCC_GPU_SLEEP_CLK_FVAL                                      0x8U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_CB_CLK_FVAL                                                 0x9U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GCC_GPU_MEMNOC_AXI_CLK_FVAL                                 0xaU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CXO_AON_CLK_FVAL                                     0xbU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_FREQ_MEASURE_CLK_FVAL                                0xcU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_DEMET_CLK_FVAL                                       0xdU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_GX_GFX3D_CLK_FVAL                                    0xeU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_GX_VSENSE_CLK_FVAL                                   0xfU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_GX_QDSS_TSCTR_CLK_FVAL                              0x10U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_GX_CXO_CLK_FVAL                                     0x11U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_GX_GMU_CLK_FVAL                                     0x12U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_GX_FF_CLK_FVAL                                      0x13U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_GX_GFX3D_SLP_STG_CLK_FVAL                           0x14U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_GX_GFX3D_RDVM_CLK_FVAL                              0x15U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_AHB_CLK_FVAL                                        0x16U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CRC_AHB_CLK_FVAL                                    0x17U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_QDSS_AT_CLK_FVAL                                 0x18U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_QDSS_TSCTR_CLK_FVAL                              0x19U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_APB_CLK_FVAL                                     0x1aU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_SNOC_DVM_CLK_FVAL                                0x1bU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_SLEEP_CLK_FVAL                                      0x1cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_QDSS_TRIG_CLK_FVAL                               0x1dU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_GMU_CLK_FVAL                                     0x1eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CXO_CLK_FVAL                                        0x1fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_HUB_CX_INT_CLK_FVAL                                 0x20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_FF_CLK_FVAL                                      0x21U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_MEMNOC_GFX_CLK_FVAL                                 0x22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_MEMNOC_GFX_SLP_STG_CLK_FVAL                         0x23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_GMU_SLP_STG_CLK_FVAL                             0x24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_GFX3D_CLK_FVAL                                   0x25U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_GFX3D_SLV_CLK_FVAL                               0x26U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_RBCPR_CLK_FVAL                                      0x27U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_RBCPR_AHB_CLK_FVAL                                  0x28U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_MND1X_1_GFX3D_CLK_FVAL                              0x2aU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_SPDM_GX_GFX3D_DIV_CLK_FVAL                          0x2bU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_ACD_CXO_CLK_FVAL                                    0x2cU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_ACD_AHB_CLK_FVAL                                    0x2dU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CB_CLK_FVAL                                         0x2eU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_HUB_AON_CLK_FVAL                                    0x2fU
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_GX_ACCU_SHIFT_CLK_FVAL                              0x30U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MUX_MUXR_MUX_SEL_GPU_CC_CX_ACCU_SHIFT_CLK_FVAL                              0x31U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_ADDR                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5568U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_OFFS                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5568U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_RMSK                                                             0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_MUX_SEL_BMSK                                                     0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_MUX_SEL_SHFT                                                       0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_MUX_SEL_GPU_CC_PLL0_TEST_FVAL                                    0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_TEST_MUX_MUXR_MUX_SEL_GPU_CC_PLL1_TEST_FVAL                                    0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_ADDR                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x556cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_OFFS                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x556cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_RMSK                                                              0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_MUX_SEL_BMSK                                                      0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_MUX_SEL_SHFT                                                        0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_MUX_SEL_GPU_CC_PLL0_RESET_N_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_RESET_N_MUXR_MUX_SEL_GPU_CC_PLL1_RESET_N_FVAL                                  0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_ADDR                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5570U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_OFFS                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5570U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_RMSK                                                               0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_MUX_SEL_BMSK                                                       0x7U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_MUX_SEL_SHFT                                                         0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_MUX_SEL_ZERO_FVAL                                                  0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_MUX_SEL_GPU_CC_PLL0_STATUS_FVAL                                    0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_MUX_SEL_GPU_CC_PLL1_STATUS_FVAL                                    0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_MUX_SEL_ACD_DEBUG_BUS_FVAL                                         0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_MUX_SEL_GX_GDSC_FSM_STATE_FVAL                                     0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_PLL_STATUS_MUXR_MUX_SEL_CX_GDSC_FSM_STATE_FVAL                                     0x5U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_ADDR                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5574U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_OFFS                                                          (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5574U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_RMSK                                                          0xe0000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_FSM_STATE_BMSK                                                0xe0000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_FSM_STATE_SHFT                                                        29U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_HANDSHAKE_FSM_EN_BMSK                                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SMMU_TLBI_CTL_HANDSHAKE_FSM_EN_SHFT                                                  0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_ADDR                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5578U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_OFFS                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5578U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_RMSK                                                    0x3fffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_CLR_CNT_BMSK                                            0x200000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_CLR_CNT_SHFT                                                  21U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_CLR_CNT_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_CLR_CNT_ENABLE_FVAL                                          0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_CNT_EN_BMSK                                             0x100000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_CNT_EN_SHFT                                                   20U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_CNT_EN_DISABLE_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_CNT_EN_ENABLE_FVAL                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_XO_DIV4_TERM_CNT_BMSK                                    0xfffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_CTL_XO_DIV4_TERM_CNT_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_ADDR                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x557cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_OFFS                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x557cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_RMSK                                               0x3ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_XO_DIV4_CNT_DONE_BMSK                              0x2000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_XO_DIV4_CNT_DONE_SHFT                                     25U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_MEASURE_CNT_BMSK                                   0x1ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS0_MEASURE_CNT_SHFT                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_ADDR                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5584U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_OFFS                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5584U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_RMSK                                               0x3ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_XO_DIV4_CNT_DONE_BMSK                              0x2000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_XO_DIV4_CNT_DONE_SHFT                                     25U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_MEASURE_CNT_BMSK                                   0x1ffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CLOCK_FRQ_MEASURE_STATUS2_MEASURE_CNT_SHFT                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_DEBUG_STATUS_ADDR                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5588U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_DEBUG_STATUS_OFFS                                                       (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5588U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_DEBUG_STATUS_RMSK                                                       0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_DEBUG_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_DEBUG_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_DEBUG_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_DEBUG_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_DEBUG_STATUS_DATA_BMSK                                                  0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_DEBUG_STATUS_DATA_SHFT                                                           0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_ADDR                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x558cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_OFFS                                                               (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x558cU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_RMSK                                                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_IROOT_ARES_BMSK                                                           0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_MISC_IROOT_ARES_SHFT                                                             0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_ADDR                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x5590U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_OFFS                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x5590U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_RMSK                                                                0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_ACK_BMSK                                                            0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_ACK_SHFT                                                                    31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_REQ_BMSK                                                                   0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_SPM_REQ_SHFT                                                                     0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_DEBUG_STATUS1_ADDR                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55a0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_DEBUG_STATUS1_OFFS                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55a0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_DEBUG_STATUS1_RMSK                                             0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_DEBUG_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_DEBUG_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_DEBUG_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_DEBUG_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_DEBUG_STATUS1_DATA_BMSK                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_DEBUG_STATUS1_DATA_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55a4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55a4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_RMSK                                                     0x80000001UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_ARES_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO_1X_MISC1_ARES_SHFT                                                         0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_ADDR                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55a8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_OFFS                                                   (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55a8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_RMSK                                                   0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_MND_CFG_BMSK                                           0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GFX3D_MNDRC_PRO_CFG1_MND_CFG_SHFT                                                    0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO1_CNT_ADDR                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55b0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO1_CNT_OFFS                                                         (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55b0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO1_CNT_RMSK                                                         0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO1_CNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO1_CNT_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO1_CNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO1_CNT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO1_CNT_DATA_BMSK                                                    0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MNDRC_PRO1_CNT_DATA_SHFT                                                             0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CNT_ADDR                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55b4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CNT_OFFS                                                      (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55b4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CNT_RMSK                                                      0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CNT_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CNT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CNT_DATA_BMSK                                                 0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_DEBUG_MEASURE_CNT_DATA_SHFT                                                          0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CNT_ADDR                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55b8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CNT_OFFS                                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55b8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CNT_RMSK                                                                0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CNT_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CNT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CNT_DATA_BMSK                                                           0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CXO_CNT_DATA_SHFT                                                                    0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_ADDR                                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55bcU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_OFFS                                                              (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55bcU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_RMSK                                                                     0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_EN_BMSK                                                                  0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_EN_SHFT                                                                    1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_ARES_BMSK                                                                0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CNT_CNTRL_ARES_SHFT                                                                  0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_ADDR                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55c0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_OFFS                                                  (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55c0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_RMSK                                                         0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_PIPELINE_AXI_CLK_DIS_BMSK                                    0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_PIPELINE_AXI_CLK_DIS_SHFT                                      1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_MEMNOC_GFX_CLK_DIS_BMSK                                      0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_MEMNOC_GFX_SW_CLK_DIS_MEMNOC_GFX_CLK_DIS_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SM_CBC_CLK_OFF_REG_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55c8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SM_CBC_CLK_OFF_REG_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55c8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SM_CBC_CLK_OFF_REG_RMSK                                                            0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SM_CBC_CLK_OFF_REG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SM_CBC_CLK_OFF_REG_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SM_CBC_CLK_OFF_REG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SM_CBC_CLK_OFF_REG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SM_CBC_CLK_OFF_REG_SM_CMU_CBCR_CLK_OFF_BMSK                                        0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_SM_CBC_CLK_OFF_REG_SM_CMU_CBCR_CLK_OFF_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_ADDR                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55d4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_OFFS                                                (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55d4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_RMSK                                                       0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_MASTER_EN_BMSK                                             0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_MASTER_EN_SHFT                                               1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_SLAVE_EN_BMSK                                              0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_TEST_BUS_EN_SLAVE_EN_SHFT                                                0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_SLAVE_TEST_BUS_ADDR                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55d8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_SLAVE_TEST_BUS_OFFS                                             (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55d8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_SLAVE_TEST_BUS_RMSK                                             0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_SLAVE_TEST_BUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_SLAVE_TEST_BUS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_SLAVE_TEST_BUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_SLAVE_TEST_BUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_SLAVE_TEST_BUS_DATA_BMSK                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_SLAVE_TEST_BUS_DATA_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_MASTER_TEST_BUS_ADDR                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55dcU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_MASTER_TEST_BUS_OFFS                                            (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55dcU)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_MASTER_TEST_BUS_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_MASTER_TEST_BUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_MASTER_TEST_BUS_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_MASTER_TEST_BUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_MASTER_TEST_BUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_MASTER_TEST_BUS_DATA_BMSK                                       0xffffffffUL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_ACD_AHB2AHB_MASTER_TEST_BUS_DATA_SHFT                                                0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_ADDR                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55e0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_OFFS                                                        (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55e0U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_RMSK                                                               0x3U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_RESTORE_FF_BMSK                                                    0x2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_RESTORE_FF_SHFT                                                      1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_SAVE_FF_BMSK                                                       0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_DOMAIN_MISC5_SAVE_FF_SHFT                                                         0U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55e4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55e4U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_RMSK                                                     0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_GX_ACCU_SHIFT_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U

#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_ADDR                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE      + 0x55e8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_OFFS                                                     (SAIL_TO_MD_GPUCC_GPU_CC_GPU_CC_GPU_CC_REG_REG_BASE_OFFS + 0x55e8U)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_RMSK                                                     0x81c00005UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_IN)
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_OFF_BMSK                                             0x80000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_OFF_SHFT                                                     31U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_IGNORE_ALL_ARES_SHFT                                             24U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_DIS_BMSK                                               0x400000UL
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_DIS_SHFT                                                     22U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_ARES_BMSK                                                   0x4U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_ARES_SHFT                                                     2U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_ARES_RESET_FVAL                                             0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_ENABLE_BMSK                                                 0x1U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_ENABLE_SHFT                                                   0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0U
#define HWIO_SAIL_TO_MD_GPUCC_GPU_CC_CX_ACCU_SHIFT_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1U


#endif /* G_SAIL_TO_MD_GPUCC_H */
