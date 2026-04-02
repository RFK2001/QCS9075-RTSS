#ifndef __G_SAIL_TO_MD_GPU_GMU_GX_HWIO_H__
#define __G_SAIL_TO_MD_GPU_GMU_GX_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_GPU_GMU_GX_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_GPU_GMU_GX_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1'],
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
 * MODULE: SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE                                                         (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x03d6a000ul)
#define SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_SIZE                                                    0x800u
#define SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_USED                                                    0x500u
#define SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS                                                    0x03d6a000ul

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_ADDR                                                   (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_OFFS                                                   (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_RMSK                                                        0x1ffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACHMENABLE_BMSK                                         0x100u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACHMENABLE_SHFT                                             8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACUCHEENABLE_BMSK                                        0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACUCHEENABLE_SHFT                                           7u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACCMPCCUFCHEENABLE_BMSK                                  0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACCMPCCUFCHEENABLE_SHFT                                     6u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACCCUENABLE_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACCCUENABLE_SHFT                                            5u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACRBENABLE_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACRBENABLE_SHFT                                             4u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACTPENABLE_BMSK                                           0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACTPENABLE_SHFT                                             3u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACUSPENABLE_BMSK                                          0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_BPCBACUSPENABLE_SHFT                                            2u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_GDPMENABLE_BMSK                                               0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_GDPMENABLE_SHFT                                                 1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_DPMSSENABLE_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DPM_SS_ENABLE_DPMSSENABLE_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_ADDR                                               (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_OFFS                                               (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_RMSK                                                      0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_DPMOUTPUTSHIFT_BMSK                                       0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GDPM_RESULT_SHIFT_DPMOUTPUTSHIFT_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_ADDR                                             (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x10u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_OFFS                                             (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x10u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_RMSK                                                    0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_BACBCCEPOCH_BMSK                                        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DCEV2_BAC_BCC_EPOCH_BACBCCEPOCH_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_ADDR                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x58u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_OFFS                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x58u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_RMSK                                                  0x1fffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_SHIFTINDEX_BMSK                                       0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_SHIFTINDEX_SHFT                                            8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_SCALECOEFF_BMSK                                         0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_SP_COEFFICIENT_SCALECOEFF_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_ADDR                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x78u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_OFFS                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x78u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_RMSK                                                  0x1fffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_SHIFTINDEX_BMSK                                       0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_SHIFTINDEX_SHFT                                            8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_SCALECOEFF_BMSK                                         0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_TP_COEFFICIENT_SCALECOEFF_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_ADDR                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x98u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_OFFS                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x98u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_RMSK                                                  0x1fffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_SHIFTINDEX_BMSK                                       0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_SHIFTINDEX_SHFT                                            8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_SCALECOEFF_BMSK                                         0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_RB_COEFFICIENT_SCALECOEFF_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_ADDR                                             (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0xb8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_OFFS                                             (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0xb8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_RMSK                                                 0x1fffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_SHIFTINDEX_BMSK                                      0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_SHIFTINDEX_SHFT                                           8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_SCALECOEFF_BMSK                                        0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_CCU_COEFFICIENT_SCALECOEFF_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0xd8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0xd8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_RMSK                                                0x1fffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_SHIFTINDEX_BMSK                                     0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_SHIFTINDEX_SHFT                                          8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_SCALECOEFF_BMSK                                       0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_UCHE_COEFFICIENT_SCALECOEFF_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_ADDR                                    (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0xf8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_OFFS                                    (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0xf8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_RMSK                                        0x1fffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_SHIFTINDEX_BMSK                             0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_SHIFTINDEX_SHFT                                  8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_SCALECOEFF_BMSK                               0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_COMP_CCUFCHE_COEFFICIENT_SCALECOEFF_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_ADDR                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x118u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_OFFS                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x118u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_RMSK                                                  0x1fffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_SHIFTINDEX_BMSK                                       0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_SHIFTINDEX_SHFT                                            8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_SCALECOEFF_BMSK                                         0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_BPC_HM_COEFFICIENT_SCALECOEFF_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_ADDR                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x180u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_OFFS                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x180u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_RMSK                                              0x7f7f7f7ful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_RIGHT_SHIFT_USP_ALU_ADD_EN_CNT_BMSK               0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_RIGHT_SHIFT_USP_ALU_ADD_EN_CNT_SHFT                       28u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_WEIGHT_USP_ALU_ADD_EN_CNT_BMSK                     0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_WEIGHT_USP_ALU_ADD_EN_CNT_SHFT                            24u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_RIGHT_SHIFT_USP_ALU_INST_EN_EX0_CNT_BMSK            0x700000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_RIGHT_SHIFT_USP_ALU_INST_EN_EX0_CNT_SHFT                  20u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_WEIGHT_USP_ALU_INST_EN_EX0_CNT_BMSK                  0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_WEIGHT_USP_ALU_INST_EN_EX0_CNT_SHFT                       16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_RIGHT_SHIFT_USP_REG_RD_CNT_BMSK                       0x7000u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_RIGHT_SHIFT_USP_REG_RD_CNT_SHFT                           12u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_WEIGHT_USP_REG_RD_CNT_BMSK                             0xf00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_WEIGHT_USP_REG_RD_CNT_SHFT                                 8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_RIGHT_SHIFT_USP_REG_WE_CNT_BMSK                         0x70u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_RIGHT_SHIFT_USP_REG_WE_CNT_SHFT                            4u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_WEIGHT_USP_REG_WE_CNT_BMSK                               0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_0_WEIGHT_USP_REG_WE_CNT_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_ADDR                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x184u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_OFFS                                              (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x184u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_RMSK                                                  0x7f7fu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_RIGHT_SHIFT_USP_ALU_HP_MUL_EN_CNT_BMSK                0x7000u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_RIGHT_SHIFT_USP_ALU_HP_MUL_EN_CNT_SHFT                    12u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_WEIGHT_USP_ALU_HP_MUL_EN_CNT_BMSK                      0xf00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_WEIGHT_USP_ALU_HP_MUL_EN_CNT_SHFT                          8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_RIGHT_SHIFT_USP_ALU_DUAL_MUL_EN_CNT_BMSK                0x70u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_RIGHT_SHIFT_USP_ALU_DUAL_MUL_EN_CNT_SHFT                   4u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_WEIGHT_USP_ALU_DUAL_MUL_EN_CNT_BMSK                      0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_WEIGHTS_1_WEIGHT_USP_ALU_DUAL_MUL_EN_CNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ADDR                                       (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x188u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_OFFS                                       (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x188u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_RMSK                                       0x3ffffff3ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ACD_MODE_BMSK                              0x30000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ACD_MODE_SHFT                                      28u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_DIDT_CRC_MULT_BMSK                          0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_DIDT_CRC_MULT_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_DIDT_FLUSH_COUNT_BMSK                        0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_DIDT_FLUSH_COUNT_SHFT                              16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ACD_THROTTLE_COUNT_BMSK                        0xfff0u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ACD_THROTTLE_COUNT_SHFT                             4u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ACD_THROTTLE_BYPASS_BMSK                          0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ACD_THROTTLE_BYPASS_SHFT                            1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ACD_INTERACTION_ENABLED_BMSK                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_ACD_INTEROP_CNTL_ACD_INTERACTION_ENABLED_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_ADDR                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x190u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_OFFS                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x190u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_RMSK                                           0x1fff1ffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_THROTTLESID_BMSK                               0x1f000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_THROTTLESID_SHFT                                       24u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_RESILIENCECYCLES_BMSK                            0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_RESILIENCECYCLES_SHFT                                  16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_RESILIENCEEN_BMSK                                  0x1000u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_RESILIENCEEN_SHFT                                      12u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_RAMPWINDOW_BMSK                                     0xff0u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_RAMPWINDOW_SHFT                                         4u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_EPOCH_BMSK                                            0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_EPOCH_SHFT                                              1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_DIDTEN_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_0_DIDTEN_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_ADDR                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x194u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_OFFS                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x194u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_RMSK                                            0xfff0ffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_UNTHROTTLETHRESHOLD_BMSK                        0xfff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_UNTHROTTLETHRESHOLD_SHFT                               16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_THROTTLETHRESHOLD_BMSK                              0xfffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_SHORT_CNTL_1_THROTTLETHRESHOLD_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x198u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x198u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_RMSK                                            0x1fff1ffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_THROTTLESID_BMSK                                0x1f000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_THROTTLESID_SHFT                                        24u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_RESILIENCECYCLES_BMSK                             0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_RESILIENCECYCLES_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_RESILIENCEEN_BMSK                                   0x1000u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_RESILIENCEEN_SHFT                                       12u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_RAMPWINDOW_BMSK                                      0xff0u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_RAMPWINDOW_SHFT                                          4u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_EPOCH_BMSK                                             0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_EPOCH_SHFT                                               1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_DIDTEN_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_0_DIDTEN_SHFT                                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x19cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x19cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_RMSK                                             0xfff0ffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_UNTHROTTLETHRESHOLD_BMSK                         0xfff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_UNTHROTTLETHRESHOLD_SHFT                                16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_THROTTLETHRESHOLD_BMSK                               0xfffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_DIDT_LONG_CNTL_1_THROTTLETHRESHOLD_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DIDT_THROTTLE_CNT_ADDR                                               (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x1c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DIDT_THROTTLE_CNT_OFFS                                               (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x1c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DIDT_THROTTLE_CNT_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DIDT_THROTTLE_CNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_DIDT_THROTTLE_CNT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DIDT_THROTTLE_CNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_DIDT_THROTTLE_CNT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DIDT_THROTTLE_CNT_DIDTTHROTTLECNT_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_DIDT_THROTTLE_CNT_DIDTTHROTTLECNT_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_ADDR                                             (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x20cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_OFFS                                             (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x20cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_RMSK                                                  0x7ffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0FORCECOREON_BMSK                                 0x400u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0FORCECOREON_SHFT                                    10u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0FORCEPERIPHON_BMSK                               0x200u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0FORCEPERIPHON_SHFT                                   9u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0WAKEUPTIMER_BMSK                                 0x1e0u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0WAKEUPTIMER_SHFT                                     5u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0SLEEPTIMER_BMSK                                   0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0SLEEPTIMER_SHFT                                      1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0ICGCMODE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_0_SPRF0ICGCMODE_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_ADDR                                             (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x210u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_OFFS                                             (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x210u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_RMSK                                                  0x7ffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1FORCECOREON_BMSK                                 0x400u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1FORCECOREON_SHFT                                    10u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1FORCEPERIPHON_BMSK                               0x200u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1FORCEPERIPHON_SHFT                                   9u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1WAKEUPTIMER_BMSK                                 0x1e0u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1WAKEUPTIMER_SHFT                                     5u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1SLEEPTIMER_BMSK                                   0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1SLEEPTIMER_SHFT                                      1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1ICGCMODE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GMU_SP_RF_CONTROL_1_SPRF1ICGCMODE_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_ADDR                                               (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x310u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_OFFS                                               (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x310u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_RMSK                                                 0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_GXTOPTAPACK_BMSK                                     0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_GXTOPTAPACK_SHFT                                           16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_RACTAPACK_BMSK                                         0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_RACTAPACK_SHFT                                              8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_SPTPTAPACK_BMSK                                          0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_ACK_SPTPTAPACK_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_ADDR                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x320u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_OFFS                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x320u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_RMSK                                               0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_UCHETAPENABLE_BMSK                                 0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_UCHETAPENABLE_SHFT                                      8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_GXTOPTAPENABLE_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_HM_GXTOPTAPENABLE_SHFT                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_ADDR                                        (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x324u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_OFFS                                        (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x324u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_RMSK                                          0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_RACTAPENABLE_BMSK                             0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_RACTAPENABLE_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_TPTAPENABLE_BMSK                                0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_TPTAPENABLE_SHFT                                     8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_SPTAPENABLE_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_0_SPTAPENABLE_SHFT                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_ADDR                                        (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x328u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_OFFS                                        (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x328u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_RMSK                                          0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_RACTAPENABLE_BMSK                             0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_RACTAPENABLE_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_TPTAPENABLE_BMSK                                0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_TPTAPENABLE_SHFT                                     8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_SPTAPENABLE_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_1_SPTAPENABLE_SHFT                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_ADDR                                        (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x32cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_OFFS                                        (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x32cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_RMSK                                          0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_RACTAPENABLE_BMSK                             0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_RACTAPENABLE_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_TPTAPENABLE_BMSK                                0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_TPTAPENABLE_SHFT                                     8u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_SPTAPENABLE_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GRIDSENSE_TAP_CNTL_STR_2_SPTAPENABLE_SHFT                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x400u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x400u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x404u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x404u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_0_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x408u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x408u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x40cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x40cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_1_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x410u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x410u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x414u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x414u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_2_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x418u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x418u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x41cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x41cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_SP_POWER_COUNTER_3_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x420u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x420u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x424u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x424u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_0_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x428u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x428u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x42cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x42cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_1_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x430u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x430u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x434u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x434u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_2_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x438u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x438u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x43cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x43cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_TP_POWER_COUNTER_3_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x440u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x440u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x444u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x444u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_0_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x448u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x448u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x44cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x44cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_1_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x450u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x450u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x454u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x454u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_2_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x458u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x458u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x45cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x45cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_RB_POWER_COUNTER_3_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_L_ADDR                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x460u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_L_OFFS                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x460u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_L_RMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_L_COUNTLOW_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_L_COUNTLOW_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_H_ADDR                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x464u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_H_OFFS                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x464u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_H_RMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_H_COUNTHIGH_BMSK                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_0_H_COUNTHIGH_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_L_ADDR                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x468u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_L_OFFS                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x468u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_L_RMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_L_COUNTLOW_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_L_COUNTLOW_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_H_ADDR                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x46cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_H_OFFS                                           (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x46cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_H_RMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_H_COUNTHIGH_BMSK                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CCU_POWER_COUNTER_1_H_COUNTHIGH_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_L_ADDR                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x470u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_L_OFFS                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x470u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_L_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_L_COUNTLOW_BMSK                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_L_COUNTLOW_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_H_ADDR                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x474u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_H_OFFS                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x474u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_H_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_H_COUNTHIGH_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_0_H_COUNTHIGH_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_L_ADDR                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x478u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_L_OFFS                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x478u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_L_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_L_COUNTLOW_BMSK                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_L_COUNTLOW_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_H_ADDR                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x47cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_H_OFFS                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x47cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_H_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_H_COUNTHIGH_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_1_H_COUNTHIGH_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_L_ADDR                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x480u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_L_OFFS                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x480u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_L_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_L_COUNTLOW_BMSK                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_L_COUNTLOW_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_H_ADDR                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x484u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_H_OFFS                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x484u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_H_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_H_COUNTHIGH_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_2_H_COUNTHIGH_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_L_ADDR                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x488u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_L_OFFS                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x488u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_L_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_L_COUNTLOW_BMSK                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_L_COUNTLOW_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_H_ADDR                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x48cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_H_OFFS                                          (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x48cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_H_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_H_COUNTHIGH_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_UCHE_POWER_COUNTER_3_H_COUNTHIGH_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x490u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x490u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x494u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x494u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_0_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x498u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x498u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x49cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x49cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_1_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x4a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x4a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x4a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x4a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_2_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x4a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x4a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_L_COUNTLOW_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_L_COUNTLOW_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x4acu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x4acu)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_H_COUNTHIGH_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_CP_POWER_COUNTER_3_H_COUNTHIGH_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_ADDR                                        (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE      + 0x500u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_OFFS                                        (SAIL_TO_MD_GPU_GMU_GX_BLK_DEC1_REG_BASE_OFFS + 0x500u)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_RMSK                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_POWERCOUNTERENABLE_BMSK                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_GX_GPU_POWER_COUNTER_ENABLE_POWERCOUNTERENABLE_SHFT                              0u


#endif /* __G_SAIL_TO_MD_GPU_GMU_GX_HWIO_H__ */
