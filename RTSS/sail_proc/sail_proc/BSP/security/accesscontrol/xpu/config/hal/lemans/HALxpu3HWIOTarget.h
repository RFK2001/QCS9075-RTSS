#ifndef HALXPU3HWIOTARGET_H
#define HALXPU3HWIOTARGET_H
/*
===========================================================================
*/
/**
    @file HALxpu3HWIOTarget.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) r2 [lemansau_2.0_p3q3r42_MTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_CRYPTO0_CRYPTO_BAM_XPU3
        SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_BAM
        SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3
        SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3
        SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3

    'Include' filters applied: .*XPU.* .*RPU.* .*APU.* .*MPU.* 

    Generation parameters: 
    { 'filename': 'HALxpu3HWIOTarget.h',
      'filter-include': ['.*XPU.*', '.*RPU.*', '.*APU.*', '.*MPU.*'],
      'header': '#include "msmhwiobase.h"',
      'integer-qualifiers': True,
      'modules': [ 'SAILSS_CRYPTO0_CRYPTO_BAM_XPU3',
                   'SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_BAM',
                   'SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3',
                   'SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3',
                   'SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3'],
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

    ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_CRYPTO0_CRYPTO_BAM_XPU3
 *--------------------------------------------------------------------------*/

#define SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE                                          (SAILSS_CRYPTO0_CRYPTO_TOP_BASE      + 0x00001000U)
#define SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_SIZE                                     0x1e80U
#define SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_USED                                     0x1e60U
#define SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS                                     0x00001000U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_ADDR                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x0U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_OFFS                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_RMSK                                           0x3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_AALOG_MODE_DIS_BMSK                            0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_AALOG_MODE_DIS_SHFT                              1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_AADEN_BMSK                                     0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_GCR0_AADEN_SHFT                                       0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_ADDR                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x8U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_OFFS                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_RMSK                                         0x10fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_DYNAMIC_CLK_EN_BMSK                          0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_DYNAMIC_CLK_EN_SHFT                              8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_SCLEIE_BMSK                                    0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_SCLEIE_SHFT                                      3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_SCFGEIE_BMSK                                   0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_SCFGEIE_SHFT                                     2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_SCLERE_BMSK                                    0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_SCLERE_SHFT                                      1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_SCFGERE_BMSK                                   0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SCR0_SCFGERE_SHFT                                     0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_ADDR                                     (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x10U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_OFFS                                     (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_RMSK                                          0x18fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_DYNAMIC_CLK_EN_BMSK                           0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_DYNAMIC_CLK_EN_SHFT                               8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_VMIDEN_BMSK                                    0x80U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_VMIDEN_SHFT                                       7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_CLEIE_BMSK                                      0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_CLEIE_SHFT                                        3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_CFGEIE_BMSK                                     0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_CFGEIE_SHFT                                       2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_CLERE_BMSK                                      0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_CLERE_SHFT                                        1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_CFGERE_BMSK                                     0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_CR0_CFGERE_SHFT                                       0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x20U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_RMSK                                0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_SUVMID_BMSK                         0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RPU_ACR0_SUVMID_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x80U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x80U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_RMSK                                      0x3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_QAD0LOG_MODE_DIS_BMSK                     0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_QAD0LOG_MODE_DIS_SHFT                       1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_QAD0DEN_BMSK                              0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_GCR0_QAD0DEN_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x90U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_RMSK                                     0x10fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_DYNAMIC_CLK_EN_BMSK                      0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_DYNAMIC_CLK_EN_SHFT                          8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_CLEIE_BMSK                                 0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_CLEIE_SHFT                                   3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_CFGEIE_BMSK                                0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_CFGEIE_SHFT                                  2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_CLERE_BMSK                                 0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_CLERE_SHFT                                   1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_CFGERE_BMSK                                0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_CR0_CFGERE_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x100U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x100U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_RMSK                                      0x3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_QAD1LOG_MODE_DIS_BMSK                     0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_QAD1LOG_MODE_DIS_SHFT                       1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_QAD1DEN_BMSK                              0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_GCR0_QAD1DEN_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x110U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x110U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_RMSK                                     0x10fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_DYNAMIC_CLK_EN_BMSK                      0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_DYNAMIC_CLK_EN_SHFT                          8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_CLEIE_BMSK                                 0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_CLEIE_SHFT                                   3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_CFGEIE_BMSK                                0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_CFGEIE_SHFT                                  2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_CLERE_BMSK                                 0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_CLERE_SHFT                                   1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_CFGERE_BMSK                                0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_CR0_CFGERE_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_ADDR                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x3ecU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_OFFS                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x3ecU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_RMSK                                         0x3ffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_PT_BMSK                                      0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_PT_SHFT                                          9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_MV_BMSK                                      0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_MV_SHFT                                          8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_NVMID_BMSK                                    0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR3_NVMID_SHFT                                       0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_ADDR                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x3f0U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_OFFS                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x3f0U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_RMSK                                    0xffffff0fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_NONSEC_EN_BMSK                          0xff000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_NONSEC_EN_SHFT                                  24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_SEC_EN_BMSK                               0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_SEC_EN_SHFT                                     16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_VMIDACR_EN_BMSK                             0xff00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_VMIDACR_EN_SHFT                                  8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_NUM_QAD_BMSK                                   0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR2_NUM_QAD_SHFT                                     0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_ADDR                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x3f4U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_OFFS                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x3f4U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_RMSK                                    0x3f3f0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_CLIENT_ADDR_WIDTH_BMSK                  0x3f000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_CLIENT_ADDR_WIDTH_SHFT                          24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_CONFIG_ADDR_WIDTH_BMSK                    0x3f0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR1_CONFIG_ADDR_WIDTH_SHFT                          16U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_ADDR                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x3f8U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_OFFS                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x3f8U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_RMSK                                     0x3ff0027UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_NRG_BMSK                                 0x3ff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_NRG_SHFT                                        16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_CLIENTREQ_HALT_ACK_HW_EN_BMSK                 0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_CLIENTREQ_HALT_ACK_HW_EN_SHFT                    5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_XPRESS_CFG_EN_BMSK                             0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_XPRESS_CFG_EN_SHFT                               2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_XPUTYPE_BMSK                                   0x3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_IDR0_XPUTYPE_SHFT                                     0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_ADDR                                     (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x3fcU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_OFFS                                     (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x3fcU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_RMSK                                     0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_MAJOR_BMSK                               0xf0000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_MAJOR_SHFT                                       28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_MINOR_BMSK                                0xfff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_MINOR_SHFT                                       16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_STEP_BMSK                                    0xffffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REV_STEP_SHFT                                         0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_ADDR                            (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x400U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_OFFS                            (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x400U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_RMSK                                   0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_LOG_MODE_DIS_BMSK                      0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_LOG_MODE_DIS_LOG_MODE_DIS_SHFT                        0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_ADDR(r)                      (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X500 + (0x4*(r)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_OFFS(r)                      (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X500 + (0x4*(r)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_RMSK                         0x1fffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_MAXr                                  0U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_INI(r)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_ADDR(r), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_INMI(r,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_ADDR(r), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_RGFREESTATUS_BMSK            0x1fffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_FREESTATUSr_RGFREESTATUS_SHFT                     0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR0_ADDR                                   (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x800U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR0_OFFS                                   (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x800U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR0_RMSK                                   0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR0_ADDR_31_0_BMSK                         0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR0_ADDR_31_0_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR1_ADDR                                   (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x804U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR1_OFFS                                   (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x804U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR1_RMSK                                   0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR1_ADDR_63_32_BMSK                        0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SEAR1_ADDR_63_32_SHFT                                 0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_ADDR                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x808U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_OFFS                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x808U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_RMSK                                           0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_CLMULTI_BMSK                                   0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_CLMULTI_SHFT                                     3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_CFGMULTI_BMSK                                  0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_CFGMULTI_SHFT                                    2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_CLIENT_BMSK                                    0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_CLIENT_SHFT                                      1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_CFG_BMSK                                       0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESR_CFG_SHFT                                         0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_ADDR                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x80cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_OFFS                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x80cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_RMSK                                    0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_CLMULTI_BMSK                            0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_CLMULTI_SHFT                              3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_CFGMULTI_BMSK                           0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_CFGMULTI_SHFT                             2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_CLIENT_BMSK                             0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_CLIENT_SHFT                               1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_CFG_BMSK                                0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESRRESTORE_CFG_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_ADDR                                 (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x810U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_OFFS                                 (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x810U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_RMSK                                 0x67ffff0fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_AC_BMSK                              0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_AC_SHFT                                      30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_BURSTLEN_BMSK                        0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_BURSTLEN_SHFT                                29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_ASIZE_BMSK                            0x7000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_ASIZE_SHFT                                   24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_ALEN_BMSK                              0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_ALEN_SHFT                                    16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_QAD_BMSK                                 0xff00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_QAD_SHFT                                      8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_XPRIV_BMSK                                  0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_XPRIV_SHFT                                    3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_XINST_BMSK                                  0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_XINST_SHFT                                    2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_AWRITE_BMSK                                 0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_AWRITE_SHFT                                   1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_XPROTNS_BMSK                                0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR0_XPROTNS_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_ADDR                                 (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x814U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_OFFS                                 (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x814U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_RMSK                                 0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_TID_BMSK                             0xff000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_TID_SHFT                                     24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_VMID_BMSK                              0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_VMID_SHFT                                    16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_BID_BMSK                                 0xe000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_BID_SHFT                                     13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_PID_BMSK                                 0x1f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_PID_SHFT                                      8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_MID_BMSK                                   0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR1_MID_SHFT                                      0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_ADDR                                 (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x818U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_OFFS                                 (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x818U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_RMSK                                 0xffffff87UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_BAR_BMSK                             0xc0000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_BAR_SHFT                                     30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_BURST_BMSK                           0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_BURST_SHFT                                   29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_CACHEABLE_BMSK                       0x10000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_CACHEABLE_SHFT                               28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_DEVICE_BMSK                           0x8000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_DEVICE_SHFT                                  27U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_DEVICE_TYPE_BMSK                      0x6000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_DEVICE_TYPE_SHFT                             25U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_EARLYWRRESP_BMSK                      0x1000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_EARLYWRRESP_SHFT                             24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_ERROR_BMSK                             0x800000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_ERROR_SHFT                                   23U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_EXCLUSIVE_BMSK                         0x400000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_EXCLUSIVE_SHFT                               22U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_FULL_BMSK                              0x200000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_FULL_SHFT                                    21U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_SHARED_BMSK                            0x100000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_SHARED_SHFT                                  20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_WRITETHROUGH_BMSK                       0x80000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_WRITETHROUGH_SHFT                            19U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERNOALLOCATE_BMSK                    0x40000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERNOALLOCATE_SHFT                         18U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERCACHEABLE_BMSK                     0x20000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERCACHEABLE_SHFT                          17U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERSHARED_BMSK                        0x10000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERSHARED_SHFT                             16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERTRANSIENT_BMSK                      0x8000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERTRANSIENT_SHFT                          15U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERWRITETHROUGH_BMSK                   0x4000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_INNERWRITETHROUGH_SHFT                       14U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_PORTMREL_BMSK                            0x2000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_PORTMREL_SHFT                                13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_ORDEREDRD_BMSK                           0x1000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_ORDEREDRD_SHFT                               12U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_ORDEREDWR_BMSK                            0x800U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_ORDEREDWR_SHFT                               11U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_OOORD_BMSK                                0x400U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_OOORD_SHFT                                   10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_OOOWR_BMSK                                0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_OOOWR_SHFT                                    9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_NOALLOCATE_BMSK                           0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_NOALLOCATE_SHFT                               8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_TRANSIENT_BMSK                             0x80U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_TRANSIENT_SHFT                                7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_MEMTYPE_BMSK                                0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_SESYNR2_MEMTYPE_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR0_ADDR                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR0_OFFS                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR0_RMSK                                    0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR0_ADDR_31_0_BMSK                          0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR0_ADDR_31_0_SHFT                                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR0_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR0_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR0_RMSK                               0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR0_ADDR_31_0_BMSK                     0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR0_ADDR_31_0_SHFT                              0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR0_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR0_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR0_RMSK                               0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR0_ADDR_31_0_BMSK                     0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR0_ADDR_31_0_SHFT                              0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR1_ADDR                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR1_OFFS                                    (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR1_RMSK                                    0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR1_ADDR_63_32_BMSK                         0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_EAR1_ADDR_63_32_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR1_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR1_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR1_RMSK                               0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR1_ADDR_63_32_BMSK                    0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_EAR1_ADDR_63_32_SHFT                             0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR1_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR1_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR1_RMSK                               0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR1_ADDR_63_32_BMSK                    0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_EAR1_ADDR_63_32_SHFT                             0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_ADDR                                     (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_OFFS                                     (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_RMSK                                            0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_CLMULTI_BMSK                                    0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_CLMULTI_SHFT                                      3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_CFGMULTI_BMSK                                   0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_CFGMULTI_SHFT                                     2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_CLIENT_BMSK                                     0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_CLIENT_SHFT                                       1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_CFG_BMSK                                        0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESR_CFG_SHFT                                          0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_RMSK                                       0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_CLMULTI_BMSK                               0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_CLMULTI_SHFT                                 3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_CFGMULTI_BMSK                              0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_CFGMULTI_SHFT                                2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_CLIENT_BMSK                                0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_CLIENT_SHFT                                  1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_CFG_BMSK                                   0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESR_CFG_SHFT                                     0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_RMSK                                       0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_CLMULTI_BMSK                               0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_CLMULTI_SHFT                                 3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_CFGMULTI_BMSK                              0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_CFGMULTI_SHFT                                2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_CLIENT_BMSK                                0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_CLIENT_SHFT                                  1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_CFG_BMSK                                   0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESR_CFG_SHFT                                     0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_ADDR                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_OFFS                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_RMSK                                     0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_CLMULTI_BMSK                             0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_CLMULTI_SHFT                               3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_CFGMULTI_BMSK                            0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_CFGMULTI_SHFT                              2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_CLIENT_BMSK                              0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_CLIENT_SHFT                                1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_CFG_BMSK                                 0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESRRESTORE_CFG_SHFT                                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_ADDR                         (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_OFFS                         (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_RMSK                                0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_CLMULTI_BMSK                        0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_CLMULTI_SHFT                          3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_CFGMULTI_BMSK                       0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_CFGMULTI_SHFT                         2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_CLIENT_BMSK                         0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_CLIENT_SHFT                           1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_CFG_BMSK                            0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESRRESTORE_CFG_SHFT                              0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_ADDR                         (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_OFFS                         (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_RMSK                                0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_CLMULTI_BMSK                        0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_CLMULTI_SHFT                          3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_CFGMULTI_BMSK                       0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_CFGMULTI_SHFT                         2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_CLIENT_BMSK                         0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_CLIENT_SHFT                           1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_CFG_BMSK                            0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESRRESTORE_CFG_SHFT                              0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_ADDR                                  (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_OFFS                                  (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_RMSK                                  0x67ffff0fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_AC_BMSK                               0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_AC_SHFT                                       30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_BURSTLEN_BMSK                         0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_BURSTLEN_SHFT                                 29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_ASIZE_BMSK                             0x7000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_ASIZE_SHFT                                    24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_ALEN_BMSK                               0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_ALEN_SHFT                                     16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_QAD_BMSK                                  0xff00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_QAD_SHFT                                       8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_XPRIV_BMSK                                   0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_XPRIV_SHFT                                     3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_XINST_BMSK                                   0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_XINST_SHFT                                     2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_AWRITE_BMSK                                  0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_AWRITE_SHFT                                    1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_XPROTNS_BMSK                                 0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR0_XPROTNS_SHFT                                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_ADDR                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_OFFS                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_RMSK                             0x67ffff0fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_AC_BMSK                          0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_AC_SHFT                                  30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_BURSTLEN_BMSK                    0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_BURSTLEN_SHFT                            29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_ASIZE_BMSK                        0x7000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_ASIZE_SHFT                               24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_ALEN_BMSK                          0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_ALEN_SHFT                                16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_QAD_BMSK                             0xff00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_QAD_SHFT                                  8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_XPRIV_BMSK                              0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_XPRIV_SHFT                                3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_XINST_BMSK                              0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_XINST_SHFT                                2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_AWRITE_BMSK                             0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_AWRITE_SHFT                               1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_XPROTNS_BMSK                            0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR0_XPROTNS_SHFT                              0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_ADDR                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_OFFS                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_RMSK                             0x67ffff0fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_AC_BMSK                          0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_AC_SHFT                                  30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_BURSTLEN_BMSK                    0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_BURSTLEN_SHFT                            29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_ASIZE_BMSK                        0x7000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_ASIZE_SHFT                               24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_ALEN_BMSK                          0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_ALEN_SHFT                                16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_QAD_BMSK                             0xff00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_QAD_SHFT                                  8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_XPRIV_BMSK                              0x8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_XPRIV_SHFT                                3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_XINST_BMSK                              0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_XINST_SHFT                                2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_AWRITE_BMSK                             0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_AWRITE_SHFT                               1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_XPROTNS_BMSK                            0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR0_XPROTNS_SHFT                              0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_ADDR                                  (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_OFFS                                  (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_TID_BMSK                              0xff000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_TID_SHFT                                      24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_VMID_BMSK                               0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_VMID_SHFT                                     16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_BID_BMSK                                  0xe000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_BID_SHFT                                      13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_PID_BMSK                                  0x1f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_PID_SHFT                                       8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_MID_BMSK                                    0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR1_MID_SHFT                                       0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_ADDR                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_OFFS                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_RMSK                             0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_TID_BMSK                         0xff000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_TID_SHFT                                 24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_VMID_BMSK                          0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_VMID_SHFT                                16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_BID_BMSK                             0xe000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_BID_SHFT                                 13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_PID_BMSK                             0x1f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_PID_SHFT                                  8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_MID_BMSK                               0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR1_MID_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_ADDR                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_OFFS                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_RMSK                             0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_TID_BMSK                         0xff000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_TID_SHFT                                 24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_VMID_BMSK                          0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_VMID_SHFT                                16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_BID_BMSK                             0xe000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_BID_SHFT                                 13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_PID_BMSK                             0x1f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_PID_SHFT                                  8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_MID_BMSK                               0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR1_MID_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_ADDR                                  (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_OFFS                                  (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_RMSK                                  0xffffff87UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_BAR_BMSK                              0xc0000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_BAR_SHFT                                      30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_BURST_BMSK                            0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_BURST_SHFT                                    29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_CACHEABLE_BMSK                        0x10000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_CACHEABLE_SHFT                                28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_DEVICE_BMSK                            0x8000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_DEVICE_SHFT                                   27U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_DEVICE_TYPE_BMSK                       0x6000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_DEVICE_TYPE_SHFT                              25U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_EARLYWRRESP_BMSK                       0x1000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_EARLYWRRESP_SHFT                              24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_ERROR_BMSK                              0x800000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_ERROR_SHFT                                    23U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_EXCLUSIVE_BMSK                          0x400000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_EXCLUSIVE_SHFT                                22U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_FULL_BMSK                               0x200000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_FULL_SHFT                                     21U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_SHARED_BMSK                             0x100000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_SHARED_SHFT                                   20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_WRITETHROUGH_BMSK                        0x80000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_WRITETHROUGH_SHFT                             19U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERNOALLOCATE_BMSK                     0x40000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERNOALLOCATE_SHFT                          18U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERCACHEABLE_BMSK                      0x20000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERCACHEABLE_SHFT                           17U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERSHARED_BMSK                         0x10000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERSHARED_SHFT                              16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERTRANSIENT_BMSK                       0x8000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERTRANSIENT_SHFT                           15U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERWRITETHROUGH_BMSK                    0x4000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_INNERWRITETHROUGH_SHFT                        14U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_PORTMREL_BMSK                             0x2000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_PORTMREL_SHFT                                 13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_ORDEREDRD_BMSK                            0x1000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_ORDEREDRD_SHFT                                12U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_ORDEREDWR_BMSK                             0x800U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_ORDEREDWR_SHFT                                11U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_OOORD_BMSK                                 0x400U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_OOORD_SHFT                                    10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_OOOWR_BMSK                                 0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_OOOWR_SHFT                                     9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_NOALLOCATE_BMSK                            0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_NOALLOCATE_SHFT                                8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_TRANSIENT_BMSK                              0x80U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_TRANSIENT_SHFT                                 7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_MEMTYPE_BMSK                                 0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_ESYNR2_MEMTYPE_SHFT                                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_ADDR                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_OFFS                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_RMSK                             0xffffff87UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_BAR_BMSK                         0xc0000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_BAR_SHFT                                 30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_BURST_BMSK                       0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_BURST_SHFT                               29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_CACHEABLE_BMSK                   0x10000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_CACHEABLE_SHFT                           28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_DEVICE_BMSK                       0x8000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_DEVICE_SHFT                              27U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_DEVICE_TYPE_BMSK                  0x6000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_DEVICE_TYPE_SHFT                         25U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_EARLYWRRESP_BMSK                  0x1000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_EARLYWRRESP_SHFT                         24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_ERROR_BMSK                         0x800000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_ERROR_SHFT                               23U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_EXCLUSIVE_BMSK                     0x400000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_EXCLUSIVE_SHFT                           22U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_FULL_BMSK                          0x200000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_FULL_SHFT                                21U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_SHARED_BMSK                        0x100000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_SHARED_SHFT                              20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_WRITETHROUGH_BMSK                   0x80000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_WRITETHROUGH_SHFT                        19U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERNOALLOCATE_BMSK                0x40000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERNOALLOCATE_SHFT                     18U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERCACHEABLE_BMSK                 0x20000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERCACHEABLE_SHFT                      17U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERSHARED_BMSK                    0x10000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERSHARED_SHFT                         16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERTRANSIENT_BMSK                  0x8000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERTRANSIENT_SHFT                      15U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERWRITETHROUGH_BMSK               0x4000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_INNERWRITETHROUGH_SHFT                   14U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_PORTMREL_BMSK                        0x2000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_PORTMREL_SHFT                            13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_ORDEREDRD_BMSK                       0x1000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_ORDEREDRD_SHFT                           12U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_ORDEREDWR_BMSK                        0x800U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_ORDEREDWR_SHFT                           11U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_OOORD_BMSK                            0x400U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_OOORD_SHFT                               10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_OOOWR_BMSK                            0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_OOOWR_SHFT                                9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_NOALLOCATE_BMSK                       0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_NOALLOCATE_SHFT                           8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_TRANSIENT_BMSK                         0x80U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_TRANSIENT_SHFT                            7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_MEMTYPE_BMSK                            0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD0_ESYNR2_MEMTYPE_SHFT                              0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_ADDR                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_OFFS                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_RMSK                             0xffffff87UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_BAR_BMSK                         0xc0000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_BAR_SHFT                                 30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_BURST_BMSK                       0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_BURST_SHFT                               29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_CACHEABLE_BMSK                   0x10000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_CACHEABLE_SHFT                           28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_DEVICE_BMSK                       0x8000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_DEVICE_SHFT                              27U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_DEVICE_TYPE_BMSK                  0x6000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_DEVICE_TYPE_SHFT                         25U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_EARLYWRRESP_BMSK                  0x1000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_EARLYWRRESP_SHFT                         24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_ERROR_BMSK                         0x800000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_ERROR_SHFT                               23U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_EXCLUSIVE_BMSK                     0x400000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_EXCLUSIVE_SHFT                           22U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_FULL_BMSK                          0x200000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_FULL_SHFT                                21U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_SHARED_BMSK                        0x100000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_SHARED_SHFT                              20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_WRITETHROUGH_BMSK                   0x80000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_WRITETHROUGH_SHFT                        19U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERNOALLOCATE_BMSK                0x40000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERNOALLOCATE_SHFT                     18U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERCACHEABLE_BMSK                 0x20000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERCACHEABLE_SHFT                      17U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERSHARED_BMSK                    0x10000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERSHARED_SHFT                         16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERTRANSIENT_BMSK                  0x8000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERTRANSIENT_SHFT                      15U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERWRITETHROUGH_BMSK               0x4000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_INNERWRITETHROUGH_SHFT                   14U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_PORTMREL_BMSK                        0x2000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_PORTMREL_SHFT                            13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_ORDEREDRD_BMSK                       0x1000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_ORDEREDRD_SHFT                           12U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_ORDEREDWR_BMSK                        0x800U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_ORDEREDWR_SHFT                           11U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_OOORD_BMSK                            0x400U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_OOORD_SHFT                               10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_OOOWR_BMSK                            0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_OOOWR_SHFT                                9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_NOALLOCATE_BMSK                       0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_NOALLOCATE_SHFT                           8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_TRANSIENT_BMSK                         0x80U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_TRANSIENT_SHFT                            7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_MEMTYPE_BMSK                            0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_QAD1_ESYNR2_MEMTYPE_SHFT                              0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_ADDR(r)                     (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X900 + (0x4*(r)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_OFFS(r)                     (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X900 + (0x4*(r)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_RMSK                        0x1fffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_MAXr                                 0U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_INI(r)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_ADDR(r), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_INMI(r,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_ADDR(r), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_RGOWNERSTATUS_BMSK          0x1fffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGN_OWNERSTATUSr_RGOWNERSTATUS_SHFT                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_ADDR(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X1000 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_OFFS(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X1000 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_RMSK                                     0x107U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_MAXn                                        28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_RG_SEC_APPS_BMSK                         0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_RG_SEC_APPS_SHFT                             8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_RG_OWNER_BMSK                              0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR0_RG_OWNER_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_ADDR(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X100C + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_OFFS(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X100C + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_RMSK                                       0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_MAXn                                        28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_SECURE_ACCESS_LOCK_BMSK                    0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_GCR3_SECURE_ACCESS_LOCK_SHFT                      0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_ADDR(n)                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X1010 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_OFFS(n)                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X1010 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_RMSK                                        0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_MAXn                                         28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_RGSCLRDEN_APPS_BMSK                         0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR0_RGSCLRDEN_APPS_SHFT                           0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_ADDR(n)                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X1014 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_OFFS(n)                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X1014 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_RMSK                                        0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_MAXn                                         28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_RGCLRDEN_BMSK                               0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR1_RGCLRDEN_SHFT                                 0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_ADDR(n)                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X1018 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_OFFS(n)                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X1018 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_RMSK                                        0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_MAXn                                         28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_RGSCLWREN_APPS_BMSK                         0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR2_RGSCLWREN_APPS_SHFT                           0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_ADDR(n)                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X101C + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_OFFS(n)                              (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X101C + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_RMSK                                        0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_MAXn                                         28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_RGCLWREN_BMSK                               0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_CR3_RGCLWREN_SHFT                                 0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_ADDR(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X1040 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_OFFS(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X1040 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_RMSK                                0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_MAXn                                        28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_RE_BMSK                             0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_RACR_RE_SHFT                                      0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_ADDR(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE      + 0X1060 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_OFFS(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_REG_BASE_OFFS + 0X1060 + (0x80*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_RMSK                                0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_MAXn                                        28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_WE_BMSK                             0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_RGn_WACR_WE_SHFT                                      0U

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_BAM
 *--------------------------------------------------------------------------*/

#define SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_BAM_REG_BASE (SAILSS_CRYPTO0_CRYPTO_TOP_BASE      + 0x00001000U)
#define SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_BAM_REG_BASE_SIZE 0x1e80U
#define SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_BAM_REG_BASE_USED 0x0U
#define SAILSS_CRYPTO0_CRYPTO_BAM_XPU3_BAM_REG_BASE_OFFS 0x00001000U

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3
 *--------------------------------------------------------------------------*/

#define SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE                                            (SAILSS_ASIL_D_SAIL_ASIL_D_NOC_WRAPPER_BASE      + 0x00038000UL)
#define SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_SIZE                                       0x3000U
#define SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_USED                                       0x2fe0U
#define SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS                                       0x00038000UL

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_ADDR                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_OFFS                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_RMSK                                             0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_AALOG_MODE_DIS_BMSK                              0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_AALOG_MODE_DIS_SHFT                                1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_AADEN_BMSK                                       0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_GCR0_AADEN_SHFT                                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_ADDR                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_OFFS                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_RMSK                                           0x10fU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_DYNAMIC_CLK_EN_BMSK                            0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_DYNAMIC_CLK_EN_SHFT                                8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_SCLEIE_BMSK                                      0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_SCLEIE_SHFT                                        3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_SCFGEIE_BMSK                                     0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_SCFGEIE_SHFT                                       2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_SCLERE_BMSK                                      0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_SCLERE_SHFT                                        1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_SCFGERE_BMSK                                     0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SCR0_SCFGERE_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_ADDR                                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x10U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_OFFS                                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_RMSK                                            0x18fU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_DYNAMIC_CLK_EN_BMSK                             0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_DYNAMIC_CLK_EN_SHFT                                 8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_VMIDEN_BMSK                                      0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_VMIDEN_SHFT                                         7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_CLEIE_BMSK                                        0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_CLEIE_SHFT                                          3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_CFGEIE_BMSK                                       0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_CFGEIE_SHFT                                         2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_CLERE_BMSK                                        0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_CLERE_SHFT                                          1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_CFGERE_BMSK                                       0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_CR0_CFGERE_SHFT                                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_ADDR                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x20U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_OFFS                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_SUVMID_BMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RPU_ACR0_SUVMID_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_ADDR                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x40U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_OFFS                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_RE_BMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_RACR_RE_SHFT                                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_ADDR                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x60U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_OFFS                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x60U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_WE_BMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_WACR_WE_SHFT                                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_ADDR                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x80U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_OFFS                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x80U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_RMSK                                        0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_QAD0LOG_MODE_DIS_BMSK                       0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_QAD0LOG_MODE_DIS_SHFT                         1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_QAD0DEN_BMSK                                0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_GCR0_QAD0DEN_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_ADDR                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x90U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_OFFS                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_RMSK                                       0x10fU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_DYNAMIC_CLK_EN_BMSK                        0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_DYNAMIC_CLK_EN_SHFT                            8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_CLEIE_BMSK                                   0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_CLEIE_SHFT                                     3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_CFGEIE_BMSK                                  0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_CFGEIE_SHFT                                    2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_CLERE_BMSK                                   0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_CLERE_SHFT                                     1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_CFGERE_BMSK                                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_CR0_CFGERE_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_ADDR                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x100U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_OFFS                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x100U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_RMSK                                        0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_QAD1LOG_MODE_DIS_BMSK                       0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_QAD1LOG_MODE_DIS_SHFT                         1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_QAD1DEN_BMSK                                0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_GCR0_QAD1DEN_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_ADDR                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x110U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_OFFS                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x110U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_RMSK                                       0x10fU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_DYNAMIC_CLK_EN_BMSK                        0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_DYNAMIC_CLK_EN_SHFT                            8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_CLEIE_BMSK                                   0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_CLEIE_SHFT                                     3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_CFGEIE_BMSK                                  0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_CFGEIE_SHFT                                    2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_CLERE_BMSK                                   0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_CLERE_SHFT                                     1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_CFGERE_BMSK                                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_CR0_CFGERE_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_ADDR                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x300U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_OFFS                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x300U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_RMSK                                       0x107U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_UMR_SEC_APPS_BMSK                          0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_UMR_SEC_APPS_SHFT                              8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_UMR_OWNER_BMSK                               0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR0_UMR_OWNER_SHFT                                 0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_ADDR                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x30cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_OFFS                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x30cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_RMSK                                         0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_UMR_SECURE_ACCESS_LOCK_BMSK                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_GCR3_UMR_SECURE_ACCESS_LOCK_SHFT                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_ADDR                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x310U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_OFFS                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x310U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_UMRSCLRDEN_APPS_BMSK                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR0_UMRSCLRDEN_APPS_SHFT                            0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_ADDR                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x314U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_OFFS                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x314U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_RMSK                                          0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_ARM_QC_APPROACH_BMSK                          0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_ARM_QC_APPROACH_SHFT                            3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_UMRCLRDEN_BMSK                                0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR1_UMRCLRDEN_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_ADDR                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x318U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_OFFS                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x318U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_UMRSCLWREN_APPS_BMSK                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR2_UMRSCLWREN_APPS_SHFT                            0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_ADDR                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x31cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_OFFS                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x31cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_RMSK                                          0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_UMRCLWREN_BMSK                                0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_UMR_CR3_UMRCLWREN_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_ADDR                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x3ecU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_OFFS                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x3ecU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_RMSK                                           0x3ffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_PT_BMSK                                        0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_PT_SHFT                                            9U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_MV_BMSK                                        0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_MV_SHFT                                            8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_NVMID_BMSK                                      0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR3_NVMID_SHFT                                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_ADDR                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x3f0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_OFFS                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x3f0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_RMSK                                      0xffffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_NONSEC_EN_BMSK                            0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_NONSEC_EN_SHFT                                    24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_SEC_EN_BMSK                                 0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_SEC_EN_SHFT                                       16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_VMIDACR_EN_BMSK                               0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_VMIDACR_EN_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_NUM_QAD_BMSK                                     0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR2_NUM_QAD_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_ADDR                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x3f4U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_OFFS                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x3f4U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_RMSK                                      0x3f3f3f3fUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_CLIENT_ADDR_WIDTH_BMSK                    0x3f000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_CLIENT_ADDR_WIDTH_SHFT                            24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_CONFIG_ADDR_WIDTH_BMSK                      0x3f0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_CONFIG_ADDR_WIDTH_SHFT                            16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_MSB_MPU_BMSK                                  0x3f00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_MSB_MPU_SHFT                                       8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_LSB_BMSK                                        0x3fU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR1_LSB_SHFT                                           0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_ADDR                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x3f8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_OFFS                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x3f8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_RMSK                                       0x3ff0077UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_NRG_BMSK                                   0x3ff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_NRG_SHFT                                          16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_BLED_BMSK                                       0x40U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_BLED_SHFT                                          6U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_CLIENTREQ_HALT_ACK_HW_EN_BMSK                   0x20U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_CLIENTREQ_HALT_ACK_HW_EN_SHFT                      5U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_XPU_CLIENT_PIPELINE_EN_BMSK                     0x10U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_XPU_CLIENT_PIPELINE_EN_SHFT                        4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_XPRESS_CFG_EN_BMSK                               0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_XPRESS_CFG_EN_SHFT                                 2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_XPUTYPE_BMSK                                     0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_IDR0_XPUTYPE_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_ADDR                                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x3fcU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_OFFS                                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x3fcU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_RMSK                                       0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_MAJOR_BMSK                                 0xf0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_MAJOR_SHFT                                         28U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_MINOR_BMSK                                  0xfff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_MINOR_SHFT                                         16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_STEP_BMSK                                      0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REV_STEP_SHFT                                           0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_ADDR                              (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x400U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_OFFS                              (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x400U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_RMSK                                     0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_LOG_MODE_DIS_BMSK                        0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_LOG_MODE_DIS_LOG_MODE_DIS_SHFT                          0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_ADDR(r)                        (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X500 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_OFFS(r)                        (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X500 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_RMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_MAXr                                    0U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_INI(r)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_ADDR(r), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_INMI(r,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_ADDR(r), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_RGFREESTATUS_BMSK              0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSr_RGFREESTATUS_SHFT                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_ADDR(s)                        (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X500 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_OFFS(s)                        (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X500 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_RMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_MAXs                                    1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_INI(s)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_ADDR(s), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_INMI(s,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_ADDR(s), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_RGFREESTATUS_BMSK              0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_FREESTATUSs_RGFREESTATUS_SHFT                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR0_ADDR                                     (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x800U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR0_OFFS                                     (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x800U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR0_RMSK                                     0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR0_ADDR_31_0_BMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR0_ADDR_31_0_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR1_ADDR                                     (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x804U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR1_OFFS                                     (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x804U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR1_RMSK                                     0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR1_ADDR_63_32_BMSK                          0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SEAR1_ADDR_63_32_SHFT                                   0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_ADDR                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x808U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_OFFS                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x808U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_RMSK                                             0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_CLMULTI_BMSK                                     0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_CLMULTI_SHFT                                       3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_CFGMULTI_BMSK                                    0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_CFGMULTI_SHFT                                      2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_CLIENT_BMSK                                      0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_CLIENT_SHFT                                        1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_CFG_BMSK                                         0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESR_CFG_SHFT                                           0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x80cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x80cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_RMSK                                      0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_CLMULTI_BMSK                              0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_CLMULTI_SHFT                                3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_CFGMULTI_BMSK                             0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_CFGMULTI_SHFT                               2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_CLIENT_BMSK                               0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_CLIENT_SHFT                                 1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_CFG_BMSK                                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESRRESTORE_CFG_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_ADDR                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x810U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_OFFS                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x810U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_RMSK                                   0x67ffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_AC_BMSK                                0x40000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_AC_SHFT                                        30U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_BURSTLEN_BMSK                          0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_BURSTLEN_SHFT                                  29U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_ASIZE_BMSK                              0x7000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_ASIZE_SHFT                                     24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_ALEN_BMSK                                0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_ALEN_SHFT                                      16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_QAD_BMSK                                   0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_QAD_SHFT                                        8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_XPRIV_BMSK                                    0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_XPRIV_SHFT                                      3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_XINST_BMSK                                    0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_XINST_SHFT                                      2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_AWRITE_BMSK                                   0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_AWRITE_SHFT                                     1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_XPROTNS_BMSK                                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR0_XPROTNS_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_ADDR                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x814U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_OFFS                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x814U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_RMSK                                   0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_TID_BMSK                               0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_TID_SHFT                                       24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_VMID_BMSK                                0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_VMID_SHFT                                      16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_BID_BMSK                                   0xe000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_BID_SHFT                                       13U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_PID_BMSK                                   0x1f00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_PID_SHFT                                        8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_MID_BMSK                                     0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR1_MID_SHFT                                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_ADDR                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x818U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_OFFS                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x818U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_RMSK                                   0xffffff87UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_BAR_BMSK                               0xc0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_BAR_SHFT                                       30U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_BURST_BMSK                             0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_BURST_SHFT                                     29U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_CACHEABLE_BMSK                         0x10000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_CACHEABLE_SHFT                                 28U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_DEVICE_BMSK                             0x8000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_DEVICE_SHFT                                    27U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_DEVICE_TYPE_BMSK                        0x6000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_DEVICE_TYPE_SHFT                               25U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_EARLYWRRESP_BMSK                        0x1000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_EARLYWRRESP_SHFT                               24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_ERROR_BMSK                               0x800000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_ERROR_SHFT                                     23U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_EXCLUSIVE_BMSK                           0x400000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_EXCLUSIVE_SHFT                                 22U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_FULL_BMSK                                0x200000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_FULL_SHFT                                      21U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_SHARED_BMSK                              0x100000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_SHARED_SHFT                                    20U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_WRITETHROUGH_BMSK                         0x80000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_WRITETHROUGH_SHFT                              19U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERNOALLOCATE_BMSK                      0x40000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERNOALLOCATE_SHFT                           18U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERCACHEABLE_BMSK                       0x20000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERCACHEABLE_SHFT                            17U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERSHARED_BMSK                          0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERSHARED_SHFT                               16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERTRANSIENT_BMSK                        0x8000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERTRANSIENT_SHFT                            15U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERWRITETHROUGH_BMSK                     0x4000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_INNERWRITETHROUGH_SHFT                         14U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_PORTMREL_BMSK                              0x2000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_PORTMREL_SHFT                                  13U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_ORDEREDRD_BMSK                             0x1000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_ORDEREDRD_SHFT                                 12U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_ORDEREDWR_BMSK                              0x800U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_ORDEREDWR_SHFT                                 11U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_OOORD_BMSK                                  0x400U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_OOORD_SHFT                                     10U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_OOOWR_BMSK                                  0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_OOOWR_SHFT                                      9U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_NOALLOCATE_BMSK                             0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_NOALLOCATE_SHFT                                 8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_TRANSIENT_BMSK                               0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_TRANSIENT_SHFT                                  7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_MEMTYPE_BMSK                                  0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR2_MEMTYPE_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_ADDR                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x81cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_OFFS                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x81cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_RMSK                                       0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_SEC_AD_RG_MATCH_BMSK                       0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_SEC_AD_RG_MATCH_SHFT                            8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_NONSEC_AD_RG_MATCH_BMSK                      0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR3_NONSEC_AD_RG_MATCH_SHFT                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_ADDR                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x820U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_OFFS                                   (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x820U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_RMSK                                    0x3ffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_ACACHEOPTYPE_BMSK                       0x3c00000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_ACACHEOPTYPE_SHFT                              22U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_ASID_BMSK                                0x3e0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_ASID_SHFT                                      17U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_ACGRANULETRANS_BMSK                       0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_ACGRANULETRANS_SHFT                            16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_AUATTR_BMSK                                0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_SESYNR4_AUATTR_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR                        (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x830U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_OFFS                        (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x830U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_RMSK                        0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR_31_0_BMSK              0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR_31_0_SHFT                      12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR                          (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x838U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_OFFS                          (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x838U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_RMSK                          0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR_31_0_BMSK                0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR_31_0_SHFT                        12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR0_ADDR                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR0_OFFS                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR0_RMSK                                      0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR0_ADDR_31_0_BMSK                            0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR0_ADDR_31_0_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR0_ADDR                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR0_OFFS                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR0_RMSK                                 0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR0_ADDR_31_0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR0_ADDR_31_0_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR0_ADDR                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR0_OFFS                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR0_RMSK                                 0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR0_ADDR_31_0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR0_ADDR_31_0_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR1_ADDR                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR1_OFFS                                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR1_RMSK                                      0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR1_ADDR_63_32_BMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_EAR1_ADDR_63_32_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR1_ADDR                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR1_OFFS                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR1_RMSK                                 0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR1_ADDR_63_32_BMSK                      0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_EAR1_ADDR_63_32_SHFT                               0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR1_ADDR                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR1_OFFS                                 (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR1_RMSK                                 0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR1_ADDR_63_32_BMSK                      0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_EAR1_ADDR_63_32_SHFT                               0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_ADDR                                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_OFFS                                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_RMSK                                              0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_CLMULTI_BMSK                                      0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_CLMULTI_SHFT                                        3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_CFGMULTI_BMSK                                     0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_CFGMULTI_SHFT                                       2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_CLIENT_BMSK                                       0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_CLIENT_SHFT                                         1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_CFG_BMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESR_CFG_SHFT                                            0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_ADDR                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_OFFS                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_RMSK                                         0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_CLMULTI_BMSK                                 0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_CLMULTI_SHFT                                   3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_CFGMULTI_BMSK                                0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_CFGMULTI_SHFT                                  2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_CLIENT_BMSK                                  0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_CLIENT_SHFT                                    1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_CFG_BMSK                                     0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESR_CFG_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_ADDR                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_OFFS                                  (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_RMSK                                         0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_CLMULTI_BMSK                                 0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_CLMULTI_SHFT                                   3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_CFGMULTI_BMSK                                0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_CFGMULTI_SHFT                                  2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_CLIENT_BMSK                                  0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_CLIENT_SHFT                                    1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_CFG_BMSK                                     0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESR_CFG_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_ADDR                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_OFFS                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_RMSK                                       0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_CLMULTI_BMSK                               0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_CLMULTI_SHFT                                 3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_CFGMULTI_BMSK                              0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_CFGMULTI_SHFT                                2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_CLIENT_BMSK                                0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_CLIENT_SHFT                                  1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_CFG_BMSK                                   0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESRRESTORE_CFG_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR                           (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_OFFS                           (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_RMSK                                  0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_CLMULTI_BMSK                          0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_CLMULTI_SHFT                            3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_CFGMULTI_BMSK                         0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_CFGMULTI_SHFT                           2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_CLIENT_BMSK                           0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_CLIENT_SHFT                             1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_CFG_BMSK                              0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESRRESTORE_CFG_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR                           (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_OFFS                           (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_RMSK                                  0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_CLMULTI_BMSK                          0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_CLMULTI_SHFT                            3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_CFGMULTI_BMSK                         0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_CFGMULTI_SHFT                           2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_CLIENT_BMSK                           0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_CLIENT_SHFT                             1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_CFG_BMSK                              0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESRRESTORE_CFG_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_ADDR                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_OFFS                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_RMSK                                    0x67ffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_AC_BMSK                                 0x40000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_AC_SHFT                                         30U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_BURSTLEN_BMSK                           0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_BURSTLEN_SHFT                                   29U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_ASIZE_BMSK                               0x7000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_ASIZE_SHFT                                      24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_ALEN_BMSK                                 0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_ALEN_SHFT                                       16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_QAD_BMSK                                    0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_QAD_SHFT                                         8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_XPRIV_BMSK                                     0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_XPRIV_SHFT                                       3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_XINST_BMSK                                     0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_XINST_SHFT                                       2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_AWRITE_BMSK                                    0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_AWRITE_SHFT                                      1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_XPROTNS_BMSK                                   0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR0_XPROTNS_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_RMSK                               0x67ffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_AC_BMSK                            0x40000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_AC_SHFT                                    30U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_BURSTLEN_BMSK                      0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_BURSTLEN_SHFT                              29U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_ASIZE_BMSK                          0x7000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_ASIZE_SHFT                                 24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_ALEN_BMSK                            0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_ALEN_SHFT                                  16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_QAD_BMSK                               0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_QAD_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_XPRIV_BMSK                                0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_XPRIV_SHFT                                  3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_XINST_BMSK                                0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_XINST_SHFT                                  2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_AWRITE_BMSK                               0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_AWRITE_SHFT                                 1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_XPROTNS_BMSK                              0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR0_XPROTNS_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_RMSK                               0x67ffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_AC_BMSK                            0x40000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_AC_SHFT                                    30U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_BURSTLEN_BMSK                      0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_BURSTLEN_SHFT                              29U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_ASIZE_BMSK                          0x7000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_ASIZE_SHFT                                 24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_ALEN_BMSK                            0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_ALEN_SHFT                                  16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_QAD_BMSK                               0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_QAD_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_XPRIV_BMSK                                0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_XPRIV_SHFT                                  3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_XINST_BMSK                                0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_XINST_SHFT                                  2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_AWRITE_BMSK                               0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_AWRITE_SHFT                                 1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_XPROTNS_BMSK                              0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR0_XPROTNS_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_ADDR                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_OFFS                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_RMSK                                    0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_TID_BMSK                                0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_TID_SHFT                                        24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_VMID_BMSK                                 0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_VMID_SHFT                                       16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_BID_BMSK                                    0xe000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_BID_SHFT                                        13U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_PID_BMSK                                    0x1f00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_PID_SHFT                                         8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_MID_BMSK                                      0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR1_MID_SHFT                                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_RMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_TID_BMSK                           0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_TID_SHFT                                   24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_VMID_BMSK                            0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_VMID_SHFT                                  16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_BID_BMSK                               0xe000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_BID_SHFT                                   13U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_PID_BMSK                               0x1f00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_PID_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_MID_BMSK                                 0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR1_MID_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_RMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_TID_BMSK                           0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_TID_SHFT                                   24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_VMID_BMSK                            0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_VMID_SHFT                                  16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_BID_BMSK                               0xe000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_BID_SHFT                                   13U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_PID_BMSK                               0x1f00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_PID_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_MID_BMSK                                 0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR1_MID_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_ADDR                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_OFFS                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_RMSK                                    0xffffff87UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_BAR_BMSK                                0xc0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_BAR_SHFT                                        30U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_BURST_BMSK                              0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_BURST_SHFT                                      29U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_CACHEABLE_BMSK                          0x10000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_CACHEABLE_SHFT                                  28U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_DEVICE_BMSK                              0x8000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_DEVICE_SHFT                                     27U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_DEVICE_TYPE_BMSK                         0x6000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_DEVICE_TYPE_SHFT                                25U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_EARLYWRRESP_BMSK                         0x1000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_EARLYWRRESP_SHFT                                24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_ERROR_BMSK                                0x800000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_ERROR_SHFT                                      23U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_EXCLUSIVE_BMSK                            0x400000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_EXCLUSIVE_SHFT                                  22U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_FULL_BMSK                                 0x200000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_FULL_SHFT                                       21U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_SHARED_BMSK                               0x100000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_SHARED_SHFT                                     20U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_WRITETHROUGH_BMSK                          0x80000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_WRITETHROUGH_SHFT                               19U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERNOALLOCATE_BMSK                       0x40000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERNOALLOCATE_SHFT                            18U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERCACHEABLE_BMSK                        0x20000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERCACHEABLE_SHFT                             17U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERSHARED_BMSK                           0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERSHARED_SHFT                                16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERTRANSIENT_BMSK                         0x8000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERTRANSIENT_SHFT                             15U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERWRITETHROUGH_BMSK                      0x4000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_INNERWRITETHROUGH_SHFT                          14U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_PORTMREL_BMSK                               0x2000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_PORTMREL_SHFT                                   13U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_ORDEREDRD_BMSK                              0x1000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_ORDEREDRD_SHFT                                  12U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_ORDEREDWR_BMSK                               0x800U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_ORDEREDWR_SHFT                                  11U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_OOORD_BMSK                                   0x400U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_OOORD_SHFT                                      10U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_OOOWR_BMSK                                   0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_OOOWR_SHFT                                       9U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_NOALLOCATE_BMSK                              0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_NOALLOCATE_SHFT                                  8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_TRANSIENT_BMSK                                0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_TRANSIENT_SHFT                                   7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_MEMTYPE_BMSK                                   0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR2_MEMTYPE_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_RMSK                               0xffffff87UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_BAR_BMSK                           0xc0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_BAR_SHFT                                   30U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_BURST_BMSK                         0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_BURST_SHFT                                 29U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_CACHEABLE_BMSK                     0x10000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_CACHEABLE_SHFT                             28U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_BMSK                         0x8000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_SHFT                                27U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_TYPE_BMSK                    0x6000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_TYPE_SHFT                           25U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_EARLYWRRESP_BMSK                    0x1000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_EARLYWRRESP_SHFT                           24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_ERROR_BMSK                           0x800000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_ERROR_SHFT                                 23U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_EXCLUSIVE_BMSK                       0x400000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_EXCLUSIVE_SHFT                             22U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_FULL_BMSK                            0x200000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_FULL_SHFT                                  21U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_SHARED_BMSK                          0x100000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_SHARED_SHFT                                20U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_WRITETHROUGH_BMSK                     0x80000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_WRITETHROUGH_SHFT                          19U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERNOALLOCATE_BMSK                  0x40000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERNOALLOCATE_SHFT                       18U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERCACHEABLE_BMSK                   0x20000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERCACHEABLE_SHFT                        17U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERSHARED_BMSK                      0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERSHARED_SHFT                           16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERTRANSIENT_BMSK                    0x8000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERTRANSIENT_SHFT                        15U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERWRITETHROUGH_BMSK                 0x4000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_INNERWRITETHROUGH_SHFT                     14U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_PORTMREL_BMSK                          0x2000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_PORTMREL_SHFT                              13U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDRD_BMSK                         0x1000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDRD_SHFT                             12U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDWR_BMSK                          0x800U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDWR_SHFT                             11U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_OOORD_BMSK                              0x400U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_OOORD_SHFT                                 10U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_OOOWR_BMSK                              0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_OOOWR_SHFT                                  9U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_NOALLOCATE_BMSK                         0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_NOALLOCATE_SHFT                             8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_TRANSIENT_BMSK                           0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_TRANSIENT_SHFT                              7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_MEMTYPE_BMSK                              0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR2_MEMTYPE_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_RMSK                               0xffffff87UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_BAR_BMSK                           0xc0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_BAR_SHFT                                   30U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_BURST_BMSK                         0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_BURST_SHFT                                 29U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_CACHEABLE_BMSK                     0x10000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_CACHEABLE_SHFT                             28U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_BMSK                         0x8000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_SHFT                                27U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_TYPE_BMSK                    0x6000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_TYPE_SHFT                           25U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_EARLYWRRESP_BMSK                    0x1000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_EARLYWRRESP_SHFT                           24U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_ERROR_BMSK                           0x800000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_ERROR_SHFT                                 23U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_EXCLUSIVE_BMSK                       0x400000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_EXCLUSIVE_SHFT                             22U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_FULL_BMSK                            0x200000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_FULL_SHFT                                  21U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_SHARED_BMSK                          0x100000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_SHARED_SHFT                                20U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_WRITETHROUGH_BMSK                     0x80000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_WRITETHROUGH_SHFT                          19U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERNOALLOCATE_BMSK                  0x40000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERNOALLOCATE_SHFT                       18U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERCACHEABLE_BMSK                   0x20000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERCACHEABLE_SHFT                        17U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERSHARED_BMSK                      0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERSHARED_SHFT                           16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERTRANSIENT_BMSK                    0x8000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERTRANSIENT_SHFT                        15U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERWRITETHROUGH_BMSK                 0x4000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_INNERWRITETHROUGH_SHFT                     14U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_PORTMREL_BMSK                          0x2000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_PORTMREL_SHFT                              13U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDRD_BMSK                         0x1000U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDRD_SHFT                             12U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDWR_BMSK                          0x800U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDWR_SHFT                             11U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_OOORD_BMSK                              0x400U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_OOORD_SHFT                                 10U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_OOOWR_BMSK                              0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_OOOWR_SHFT                                  9U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_NOALLOCATE_BMSK                         0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_NOALLOCATE_SHFT                             8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_TRANSIENT_BMSK                           0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_TRANSIENT_SHFT                              7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_MEMTYPE_BMSK                              0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR2_MEMTYPE_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_ADDR                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_OFFS                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_RMSK                                        0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_SEC_AD_RG_MATCH_BMSK                        0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_SEC_AD_RG_MATCH_SHFT                             8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_NONSEC_AD_RG_MATCH_BMSK                       0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR3_NONSEC_AD_RG_MATCH_SHFT                          0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_RMSK                                   0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_SEC_AD_RG_MATCH_BMSK                   0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_SEC_AD_RG_MATCH_SHFT                        8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_NONSEC_AD_RG_MATCH_BMSK                  0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR3_NONSEC_AD_RG_MATCH_SHFT                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_RMSK                                   0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_SEC_AD_RG_MATCH_BMSK                   0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_SEC_AD_RG_MATCH_SHFT                        8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_NONSEC_AD_RG_MATCH_BMSK                  0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR3_NONSEC_AD_RG_MATCH_SHFT                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_ADDR                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_OFFS                                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_RMSK                                     0x3ffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_ACACHEOPTYPE_BMSK                        0x3c00000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_ACACHEOPTYPE_SHFT                               22U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_ASID_BMSK                                 0x3e0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_ASID_SHFT                                       17U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_ACGRANULETRANS_BMSK                        0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_ACGRANULETRANS_SHFT                             16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_AUATTR_BMSK                                 0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_ESYNR4_AUATTR_SHFT                                      0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_RMSK                                0x3ffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_ACACHEOPTYPE_BMSK                   0x3c00000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_ACACHEOPTYPE_SHFT                          22U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_ASID_BMSK                            0x3e0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_ASID_SHFT                                  17U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_ACGRANULETRANS_BMSK                   0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_ACGRANULETRANS_SHFT                        16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_AUATTR_BMSK                            0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_ESYNR4_AUATTR_SHFT                                 0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_ADDR                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_OFFS                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_RMSK                                0x3ffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_ACACHEOPTYPE_BMSK                   0x3c00000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_ACACHEOPTYPE_SHFT                          22U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_ASID_BMSK                            0x3e0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_ASID_SHFT                                  17U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_ACGRANULETRANS_BMSK                   0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_ACGRANULETRANS_SHFT                        16U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_AUATTR_BMSK                            0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_ESYNR4_AUATTR_SHFT                                 0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR                         (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_OFFS                         (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_RMSK                         0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR_31_0_BMSK               0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR_31_0_SHFT                       12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_OFFS                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_RMSK                    0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR_31_0_BMSK          0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR_31_0_SHFT                  12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_OFFS                    (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_RMSK                    0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR_31_0_BMSK          0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR_31_0_SHFT                  12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR                           (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_OFFS                           (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_RMSK                           0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR_31_0_BMSK                 0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR_31_0_SHFT                         12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_OFFS                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_RMSK                      0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR_31_0_BMSK            0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR_31_0_SHFT                    12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_OFFS                      (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_RMSK                      0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR_31_0_BMSK            0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR_31_0_SHFT                    12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_ADDR(r)                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X900 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_OFFS(r)                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X900 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_RMSK                          0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_MAXr                                   0U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_INI(r)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_ADDR(r), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_INMI(r,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_ADDR(r), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_RGOWNERSTATUS_BMSK            0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSr_RGOWNERSTATUS_SHFT                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_ADDR(s)                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X900 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_OFFS(s)                       (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X900 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_RMSK                          0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_MAXs                                   1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_INI(s)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_ADDR(s), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_INMI(s,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_ADDR(s), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_RGOWNERSTATUS_BMSK            0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGN_OWNERSTATUSs_RGOWNERSTATUS_SHFT                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_ADDR(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1000 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_OFFS(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1000 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_RMSK                                       0x107U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_RG_SEC_APPS_BMSK                           0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_RG_SEC_APPS_SHFT                               8U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_RG_OWNER_BMSK                                0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR0_RG_OWNER_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_ADDR(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1004 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_OFFS(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1004 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_RMSK                                  0x80000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_PD_BMSK                               0x80000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR1_PD_SHFT                                       31U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_ADDR(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1008 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_OFFS(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1008 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_RMSK                                         0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_ASRC_BMSK                                    0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_ASRC_SHFT                                      1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_CSRC_BMSK                                    0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR2_CSRC_SHFT                                      0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_ADDR(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X100C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_OFFS(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X100C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_RMSK                                         0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_SECURE_ACCESS_LOCK_BMSK                      0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_GCR3_SECURE_ACCESS_LOCK_SHFT                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_ADDR(n)                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1010 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_OFFS(n)                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1010 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_MAXn                                           63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_RGSCLRDEN_APPS_BMSK                           0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR0_RGSCLRDEN_APPS_SHFT                             0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_ADDR(n)                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1014 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_OFFS(n)                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1014 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_RMSK                                          0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_MAXn                                           63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_RGCLRDEN_BMSK                                 0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR1_RGCLRDEN_SHFT                                   0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_ADDR(n)                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1018 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_OFFS(n)                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1018 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_MAXn                                           63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_RGSCLWREN_APPS_BMSK                           0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR2_RGSCLWREN_APPS_SHFT                             0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_ADDR(n)                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X101C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_OFFS(n)                                (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X101C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_RMSK                                          0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_MAXn                                           63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_RGCLWREN_BMSK                                 0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_CR3_RGCLWREN_SHFT                                   0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_ADDR(n)                             (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1030 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_OFFS(n)                             (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1030 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_RMSK                                0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_MAXn                                        63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_ADDR_31_0_BMSK                      0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_START0_ADDR_31_0_SHFT                              12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_ADDR(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1038 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_OFFS(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1038 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_RMSK                                  0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_ADDR_31_0_BMSK                        0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_END0_ADDR_31_0_SHFT                                12U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_ADDR(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1040 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_OFFS(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1040 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_RE_BMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_RACR_RE_SHFT                                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_ADDR(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE      + 0X1060 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_OFFS(n)                               (SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_REG_BASE_OFFS + 0X1060 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_WE_BMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_NOC_DMA_MS_MPU_XPU3_RGn_WACR_WE_SHFT                                        0U

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3
 *--------------------------------------------------------------------------*/

#define SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE                                            (SAILSS_ASIL_D_SAIL_ASIL_D_NOC_WRAPPER_BASE      + 0x0003c000UL)
#define SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_SIZE                                       0x3000U
#define SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_USED                                       0x2fe0U
#define SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS                                       0x0003c000UL

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_OFFS                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_RMSK                                             0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_AALOG_MODE_DIS_BMSK                              0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_AALOG_MODE_DIS_SHFT                                1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_AADEN_BMSK                                       0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_GCR0_AADEN_SHFT                                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_OFFS                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_RMSK                                           0x10fU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_DYNAMIC_CLK_EN_BMSK                            0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_DYNAMIC_CLK_EN_SHFT                                8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_SCLEIE_BMSK                                      0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_SCLEIE_SHFT                                        3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_SCFGEIE_BMSK                                     0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_SCFGEIE_SHFT                                       2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_SCLERE_BMSK                                      0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_SCLERE_SHFT                                        1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_SCFGERE_BMSK                                     0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SCR0_SCFGERE_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR                                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x10U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_OFFS                                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_RMSK                                            0x18fU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_DYNAMIC_CLK_EN_BMSK                             0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_DYNAMIC_CLK_EN_SHFT                                 8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_VMIDEN_BMSK                                      0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_VMIDEN_SHFT                                         7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_CLEIE_BMSK                                        0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_CLEIE_SHFT                                          3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_CFGEIE_BMSK                                       0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_CFGEIE_SHFT                                         2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_CLERE_BMSK                                        0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_CLERE_SHFT                                          1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_CFGERE_BMSK                                       0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_CR0_CFGERE_SHFT                                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x20U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_OFFS                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_SUVMID_BMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_SUVMID_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x40U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_OFFS                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_RE_BMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_RE_SHFT                                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x60U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_OFFS                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x60U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_WE_BMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_WE_SHFT                                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x80U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_OFFS                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x80U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_RMSK                                        0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_QAD0LOG_MODE_DIS_BMSK                       0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_QAD0LOG_MODE_DIS_SHFT                         1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_QAD0DEN_BMSK                                0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_QAD0DEN_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x90U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_OFFS                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_RMSK                                       0x10fU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_DYNAMIC_CLK_EN_BMSK                        0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_DYNAMIC_CLK_EN_SHFT                            8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CLEIE_BMSK                                   0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CLEIE_SHFT                                     3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CFGEIE_BMSK                                  0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CFGEIE_SHFT                                    2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CLERE_BMSK                                   0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CLERE_SHFT                                     1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CFGERE_BMSK                                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CFGERE_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x100U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_OFFS                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x100U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_RMSK                                        0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_QAD1LOG_MODE_DIS_BMSK                       0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_QAD1LOG_MODE_DIS_SHFT                         1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_QAD1DEN_BMSK                                0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_QAD1DEN_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x110U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_OFFS                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x110U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_RMSK                                       0x10fU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_DYNAMIC_CLK_EN_BMSK                        0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_DYNAMIC_CLK_EN_SHFT                            8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CLEIE_BMSK                                   0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CLEIE_SHFT                                     3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CFGEIE_BMSK                                  0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CFGEIE_SHFT                                    2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CLERE_BMSK                                   0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CLERE_SHFT                                     1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CFGERE_BMSK                                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CFGERE_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x300U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_OFFS                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x300U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_RMSK                                       0x107U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_UMR_SEC_APPS_BMSK                          0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_UMR_SEC_APPS_SHFT                              8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_UMR_OWNER_BMSK                               0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_UMR_OWNER_SHFT                                 0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x30cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_OFFS                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x30cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_RMSK                                         0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_UMR_SECURE_ACCESS_LOCK_BMSK                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_UMR_SECURE_ACCESS_LOCK_SHFT                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x310U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_OFFS                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x310U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_UMRSCLRDEN_APPS_BMSK                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_UMRSCLRDEN_APPS_SHFT                            0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x314U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_OFFS                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x314U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_RMSK                                          0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ARM_QC_APPROACH_BMSK                          0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ARM_QC_APPROACH_SHFT                            3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_UMRCLRDEN_BMSK                                0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_UMRCLRDEN_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x318U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_OFFS                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x318U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_UMRSCLWREN_APPS_BMSK                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_UMRSCLWREN_APPS_SHFT                            0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x31cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_OFFS                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x31cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_RMSK                                          0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_UMRCLWREN_BMSK                                0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_UMRCLWREN_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_ADDR                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3ecU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_OFFS                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3ecU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_RMSK                                           0x3ffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_PT_BMSK                                        0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_PT_SHFT                                            9U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_MV_BMSK                                        0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_MV_SHFT                                            8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_NVMID_BMSK                                      0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR3_NVMID_SHFT                                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_ADDR                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3f0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_OFFS                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3f0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_RMSK                                      0xffffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_NONSEC_EN_BMSK                            0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_NONSEC_EN_SHFT                                    24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_SEC_EN_BMSK                                 0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_SEC_EN_SHFT                                       16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_VMIDACR_EN_BMSK                               0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_VMIDACR_EN_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_NUM_QAD_BMSK                                     0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR2_NUM_QAD_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_ADDR                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3f4U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_OFFS                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3f4U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_RMSK                                      0x3f3f3f3fUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_CLIENT_ADDR_WIDTH_BMSK                    0x3f000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_CLIENT_ADDR_WIDTH_SHFT                            24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_CONFIG_ADDR_WIDTH_BMSK                      0x3f0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_CONFIG_ADDR_WIDTH_SHFT                            16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_MSB_MPU_BMSK                                  0x3f00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_MSB_MPU_SHFT                                       8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_LSB_BMSK                                        0x3fU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR1_LSB_SHFT                                           0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_ADDR                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3f8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_OFFS                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3f8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_RMSK                                       0x3ff0077UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_NRG_BMSK                                   0x3ff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_NRG_SHFT                                          16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_BLED_BMSK                                       0x40U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_BLED_SHFT                                          6U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_CLIENTREQ_HALT_ACK_HW_EN_BMSK                   0x20U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_CLIENTREQ_HALT_ACK_HW_EN_SHFT                      5U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_XPU_CLIENT_PIPELINE_EN_BMSK                     0x10U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_XPU_CLIENT_PIPELINE_EN_SHFT                        4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_XPRESS_CFG_EN_BMSK                               0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_XPRESS_CFG_EN_SHFT                                 2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_XPUTYPE_BMSK                                     0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_IDR0_XPUTYPE_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_ADDR                                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3fcU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_OFFS                                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3fcU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_RMSK                                       0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_MAJOR_BMSK                                 0xf0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_MAJOR_SHFT                                         28U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_MINOR_BMSK                                  0xfff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_MINOR_SHFT                                         16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_STEP_BMSK                                      0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REV_STEP_SHFT                                           0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR                              (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x400U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_OFFS                              (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x400U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_RMSK                                     0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_LOG_MODE_DIS_BMSK                        0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_LOG_MODE_DIS_SHFT                          0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_ADDR(r)                        (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X500 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_OFFS(r)                        (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X500 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_RMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_MAXr                                    0U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_INI(r)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_ADDR(r), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_INMI(r,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_ADDR(r), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_RGFREESTATUS_BMSK              0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_RGFREESTATUS_SHFT                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_ADDR(s)                        (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X500 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_OFFS(s)                        (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X500 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_RMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_MAXs                                    1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_INI(s)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_ADDR(s), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_INMI(s,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_ADDR(s), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_RGFREESTATUS_BMSK              0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_RGFREESTATUS_SHFT                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR                                     (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x800U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR0_OFFS                                     (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x800U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR0_RMSK                                     0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR_31_0_BMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR_31_0_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR                                     (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x804U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR1_OFFS                                     (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x804U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR1_RMSK                                     0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR_63_32_BMSK                          0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR_63_32_SHFT                                   0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x808U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_OFFS                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x808U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_RMSK                                             0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_CLMULTI_BMSK                                     0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_CLMULTI_SHFT                                       3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_CFGMULTI_BMSK                                    0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_CFGMULTI_SHFT                                      2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_CLIENT_BMSK                                      0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_CLIENT_SHFT                                        1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_CFG_BMSK                                         0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESR_CFG_SHFT                                           0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x80cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x80cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_RMSK                                      0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CLMULTI_BMSK                              0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CLMULTI_SHFT                                3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CFGMULTI_BMSK                             0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CFGMULTI_SHFT                               2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CLIENT_BMSK                               0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CLIENT_SHFT                                 1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CFG_BMSK                                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CFG_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ADDR                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x810U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_OFFS                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x810U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_RMSK                                   0x67ffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_AC_BMSK                                0x40000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_AC_SHFT                                        30U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_BURSTLEN_BMSK                          0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_BURSTLEN_SHFT                                  29U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ASIZE_BMSK                              0x7000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ASIZE_SHFT                                     24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ALEN_BMSK                                0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ALEN_SHFT                                      16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_QAD_BMSK                                   0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_QAD_SHFT                                        8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XPRIV_BMSK                                    0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XPRIV_SHFT                                      3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XINST_BMSK                                    0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XINST_SHFT                                      2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_AWRITE_BMSK                                   0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_AWRITE_SHFT                                     1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XPROTNS_BMSK                                  0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XPROTNS_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_ADDR                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x814U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_OFFS                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x814U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_RMSK                                   0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_TID_BMSK                               0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_TID_SHFT                                       24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_VMID_BMSK                                0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_VMID_SHFT                                      16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_BID_BMSK                                   0xe000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_BID_SHFT                                       13U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_PID_BMSK                                   0x1f00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_PID_SHFT                                        8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_MID_BMSK                                     0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR1_MID_SHFT                                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ADDR                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x818U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OFFS                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x818U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_RMSK                                   0xffffff87UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_BAR_BMSK                               0xc0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_BAR_SHFT                                       30U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_BURST_BMSK                             0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_BURST_SHFT                                     29U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_CACHEABLE_BMSK                         0x10000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_CACHEABLE_SHFT                                 28U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_DEVICE_BMSK                             0x8000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_DEVICE_SHFT                                    27U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_DEVICE_TYPE_BMSK                        0x6000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_DEVICE_TYPE_SHFT                               25U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_EARLYWRRESP_BMSK                        0x1000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_EARLYWRRESP_SHFT                               24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ERROR_BMSK                               0x800000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ERROR_SHFT                                     23U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_EXCLUSIVE_BMSK                           0x400000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_EXCLUSIVE_SHFT                                 22U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_FULL_BMSK                                0x200000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_FULL_SHFT                                      21U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_SHARED_BMSK                              0x100000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_SHARED_SHFT                                    20U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_WRITETHROUGH_BMSK                         0x80000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_WRITETHROUGH_SHFT                              19U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERNOALLOCATE_BMSK                      0x40000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERNOALLOCATE_SHFT                           18U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERCACHEABLE_BMSK                       0x20000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERCACHEABLE_SHFT                            17U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERSHARED_BMSK                          0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERSHARED_SHFT                               16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERTRANSIENT_BMSK                        0x8000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERTRANSIENT_SHFT                            15U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERWRITETHROUGH_BMSK                     0x4000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERWRITETHROUGH_SHFT                         14U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_PORTMREL_BMSK                              0x2000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_PORTMREL_SHFT                                  13U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ORDEREDRD_BMSK                             0x1000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ORDEREDRD_SHFT                                 12U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ORDEREDWR_BMSK                              0x800U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ORDEREDWR_SHFT                                 11U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OOORD_BMSK                                  0x400U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OOORD_SHFT                                     10U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OOOWR_BMSK                                  0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OOOWR_SHFT                                      9U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_NOALLOCATE_BMSK                             0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_NOALLOCATE_SHFT                                 8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_TRANSIENT_BMSK                               0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_TRANSIENT_SHFT                                  7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_MEMTYPE_BMSK                                  0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR2_MEMTYPE_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_ADDR                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x81cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_OFFS                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x81cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_RMSK                                       0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_SEC_AD_RG_MATCH_BMSK                       0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_SEC_AD_RG_MATCH_SHFT                            8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_NONSEC_AD_RG_MATCH_BMSK                      0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR3_NONSEC_AD_RG_MATCH_SHFT                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ADDR                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x820U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_OFFS                                   (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x820U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_RMSK                                    0x3ffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ACACHEOPTYPE_BMSK                       0x3c00000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ACACHEOPTYPE_SHFT                              22U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ASID_BMSK                                0x3e0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ASID_SHFT                                      17U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ACGRANULETRANS_BMSK                       0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ACGRANULETRANS_SHFT                            16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_AUATTR_BMSK                                0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_SESYNR4_AUATTR_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR                        (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x830U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_OFFS                        (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x830U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_RMSK                        0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR_31_0_BMSK              0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR_31_0_SHFT                      12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR                          (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x838U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_OFFS                          (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x838U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_RMSK                          0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR_31_0_BMSK                0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR_31_0_SHFT                        12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR0_OFFS                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR0_RMSK                                      0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR_31_0_BMSK                            0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR_31_0_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_OFFS                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_RMSK                                 0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR_31_0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR_31_0_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_OFFS                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_RMSK                                 0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR_31_0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR_31_0_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR1_OFFS                                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR1_RMSK                                      0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR_63_32_BMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR_63_32_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_OFFS                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_RMSK                                 0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR_63_32_BMSK                      0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR_63_32_SHFT                               0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_OFFS                                 (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_RMSK                                 0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR_63_32_BMSK                      0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR_63_32_SHFT                               0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR                                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_OFFS                                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_RMSK                                              0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_CLMULTI_BMSK                                      0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_CLMULTI_SHFT                                        3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_CFGMULTI_BMSK                                     0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_CFGMULTI_SHFT                                       2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_CLIENT_BMSK                                       0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_CLIENT_SHFT                                         1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_CFG_BMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESR_CFG_SHFT                                            0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_OFFS                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_RMSK                                         0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CLMULTI_BMSK                                 0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CLMULTI_SHFT                                   3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CFGMULTI_BMSK                                0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CFGMULTI_SHFT                                  2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CLIENT_BMSK                                  0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CLIENT_SHFT                                    1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CFG_BMSK                                     0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CFG_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_OFFS                                  (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_RMSK                                         0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CLMULTI_BMSK                                 0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CLMULTI_SHFT                                   3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CFGMULTI_BMSK                                0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CFGMULTI_SHFT                                  2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CLIENT_BMSK                                  0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CLIENT_SHFT                                    1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CFG_BMSK                                     0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CFG_SHFT                                       0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_OFFS                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_RMSK                                       0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CLMULTI_BMSK                               0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CLMULTI_SHFT                                 3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CFGMULTI_BMSK                              0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CFGMULTI_SHFT                                2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CLIENT_BMSK                                0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CLIENT_SHFT                                  1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CFG_BMSK                                   0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CFG_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR                           (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_OFFS                           (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_RMSK                                  0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CLMULTI_BMSK                          0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CLMULTI_SHFT                            3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CFGMULTI_BMSK                         0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CFGMULTI_SHFT                           2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CLIENT_BMSK                           0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CLIENT_SHFT                             1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CFG_BMSK                              0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CFG_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR                           (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_OFFS                           (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_RMSK                                  0xfU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CLMULTI_BMSK                          0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CLMULTI_SHFT                            3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CFGMULTI_BMSK                         0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CFGMULTI_SHFT                           2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CLIENT_BMSK                           0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CLIENT_SHFT                             1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CFG_BMSK                              0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CFG_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ADDR                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_OFFS                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_RMSK                                    0x67ffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_AC_BMSK                                 0x40000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_AC_SHFT                                         30U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_BURSTLEN_BMSK                           0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_BURSTLEN_SHFT                                   29U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ASIZE_BMSK                               0x7000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ASIZE_SHFT                                      24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ALEN_BMSK                                 0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ALEN_SHFT                                       16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_QAD_BMSK                                    0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_QAD_SHFT                                         8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XPRIV_BMSK                                     0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XPRIV_SHFT                                       3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XINST_BMSK                                     0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XINST_SHFT                                       2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_AWRITE_BMSK                                    0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_AWRITE_SHFT                                      1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XPROTNS_BMSK                                   0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XPROTNS_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_RMSK                               0x67ffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_AC_BMSK                            0x40000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_AC_SHFT                                    30U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_BURSTLEN_BMSK                      0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_BURSTLEN_SHFT                              29U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ASIZE_BMSK                          0x7000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ASIZE_SHFT                                 24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ALEN_BMSK                            0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ALEN_SHFT                                  16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_QAD_BMSK                               0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_QAD_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XPRIV_BMSK                                0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XPRIV_SHFT                                  3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XINST_BMSK                                0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XINST_SHFT                                  2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_AWRITE_BMSK                               0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_AWRITE_SHFT                                 1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XPROTNS_BMSK                              0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XPROTNS_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_RMSK                               0x67ffff0fUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_AC_BMSK                            0x40000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_AC_SHFT                                    30U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_BURSTLEN_BMSK                      0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_BURSTLEN_SHFT                              29U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ASIZE_BMSK                          0x7000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ASIZE_SHFT                                 24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ALEN_BMSK                            0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ALEN_SHFT                                  16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_QAD_BMSK                               0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_QAD_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XPRIV_BMSK                                0x8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XPRIV_SHFT                                  3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XINST_BMSK                                0x4U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XINST_SHFT                                  2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_AWRITE_BMSK                               0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_AWRITE_SHFT                                 1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XPROTNS_BMSK                              0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XPROTNS_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_ADDR                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_OFFS                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_RMSK                                    0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_TID_BMSK                                0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_TID_SHFT                                        24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_VMID_BMSK                                 0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_VMID_SHFT                                       16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_BID_BMSK                                    0xe000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_BID_SHFT                                        13U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_PID_BMSK                                    0x1f00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_PID_SHFT                                         8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_MID_BMSK                                      0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR1_MID_SHFT                                         0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_RMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_TID_BMSK                           0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_TID_SHFT                                   24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_VMID_BMSK                            0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_VMID_SHFT                                  16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_BID_BMSK                               0xe000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_BID_SHFT                                   13U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_PID_BMSK                               0x1f00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_PID_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_MID_BMSK                                 0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_MID_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_RMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_TID_BMSK                           0xff000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_TID_SHFT                                   24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_VMID_BMSK                            0xff0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_VMID_SHFT                                  16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_BID_BMSK                               0xe000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_BID_SHFT                                   13U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_PID_BMSK                               0x1f00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_PID_SHFT                                    8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_MID_BMSK                                 0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_MID_SHFT                                    0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ADDR                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OFFS                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_RMSK                                    0xffffff87UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_BAR_BMSK                                0xc0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_BAR_SHFT                                        30U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_BURST_BMSK                              0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_BURST_SHFT                                      29U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_CACHEABLE_BMSK                          0x10000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_CACHEABLE_SHFT                                  28U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_DEVICE_BMSK                              0x8000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_DEVICE_SHFT                                     27U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_DEVICE_TYPE_BMSK                         0x6000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_DEVICE_TYPE_SHFT                                25U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_EARLYWRRESP_BMSK                         0x1000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_EARLYWRRESP_SHFT                                24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ERROR_BMSK                                0x800000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ERROR_SHFT                                      23U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_EXCLUSIVE_BMSK                            0x400000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_EXCLUSIVE_SHFT                                  22U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_FULL_BMSK                                 0x200000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_FULL_SHFT                                       21U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_SHARED_BMSK                               0x100000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_SHARED_SHFT                                     20U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_WRITETHROUGH_BMSK                          0x80000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_WRITETHROUGH_SHFT                               19U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERNOALLOCATE_BMSK                       0x40000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERNOALLOCATE_SHFT                            18U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERCACHEABLE_BMSK                        0x20000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERCACHEABLE_SHFT                             17U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERSHARED_BMSK                           0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERSHARED_SHFT                                16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERTRANSIENT_BMSK                         0x8000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERTRANSIENT_SHFT                             15U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERWRITETHROUGH_BMSK                      0x4000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERWRITETHROUGH_SHFT                          14U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_PORTMREL_BMSK                               0x2000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_PORTMREL_SHFT                                   13U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ORDEREDRD_BMSK                              0x1000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ORDEREDRD_SHFT                                  12U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ORDEREDWR_BMSK                               0x800U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ORDEREDWR_SHFT                                  11U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OOORD_BMSK                                   0x400U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OOORD_SHFT                                      10U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OOOWR_BMSK                                   0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OOOWR_SHFT                                       9U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_NOALLOCATE_BMSK                              0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_NOALLOCATE_SHFT                                  8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_TRANSIENT_BMSK                                0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_TRANSIENT_SHFT                                   7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_MEMTYPE_BMSK                                   0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR2_MEMTYPE_SHFT                                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_RMSK                               0xffffff87UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_BAR_BMSK                           0xc0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_BAR_SHFT                                   30U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_BURST_BMSK                         0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_BURST_SHFT                                 29U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_CACHEABLE_BMSK                     0x10000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_CACHEABLE_SHFT                             28U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_BMSK                         0x8000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_SHFT                                27U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_TYPE_BMSK                    0x6000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_TYPE_SHFT                           25U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_EARLYWRRESP_BMSK                    0x1000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_EARLYWRRESP_SHFT                           24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ERROR_BMSK                           0x800000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ERROR_SHFT                                 23U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_EXCLUSIVE_BMSK                       0x400000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_EXCLUSIVE_SHFT                             22U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_FULL_BMSK                            0x200000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_FULL_SHFT                                  21U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_SHARED_BMSK                          0x100000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_SHARED_SHFT                                20U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_WRITETHROUGH_BMSK                     0x80000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_WRITETHROUGH_SHFT                          19U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERNOALLOCATE_BMSK                  0x40000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERNOALLOCATE_SHFT                       18U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERCACHEABLE_BMSK                   0x20000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERCACHEABLE_SHFT                        17U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERSHARED_BMSK                      0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERSHARED_SHFT                           16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERTRANSIENT_BMSK                    0x8000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERTRANSIENT_SHFT                        15U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERWRITETHROUGH_BMSK                 0x4000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERWRITETHROUGH_SHFT                     14U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_PORTMREL_BMSK                          0x2000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_PORTMREL_SHFT                              13U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDRD_BMSK                         0x1000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDRD_SHFT                             12U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDWR_BMSK                          0x800U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDWR_SHFT                             11U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OOORD_BMSK                              0x400U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OOORD_SHFT                                 10U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OOOWR_BMSK                              0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OOOWR_SHFT                                  9U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_NOALLOCATE_BMSK                         0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_NOALLOCATE_SHFT                             8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_TRANSIENT_BMSK                           0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_TRANSIENT_SHFT                              7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_MEMTYPE_BMSK                              0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_MEMTYPE_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_RMSK                               0xffffff87UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_BAR_BMSK                           0xc0000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_BAR_SHFT                                   30U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_BURST_BMSK                         0x20000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_BURST_SHFT                                 29U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_CACHEABLE_BMSK                     0x10000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_CACHEABLE_SHFT                             28U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_BMSK                         0x8000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_SHFT                                27U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_TYPE_BMSK                    0x6000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_TYPE_SHFT                           25U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_EARLYWRRESP_BMSK                    0x1000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_EARLYWRRESP_SHFT                           24U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ERROR_BMSK                           0x800000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ERROR_SHFT                                 23U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_EXCLUSIVE_BMSK                       0x400000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_EXCLUSIVE_SHFT                             22U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_FULL_BMSK                            0x200000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_FULL_SHFT                                  21U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_SHARED_BMSK                          0x100000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_SHARED_SHFT                                20U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_WRITETHROUGH_BMSK                     0x80000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_WRITETHROUGH_SHFT                          19U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERNOALLOCATE_BMSK                  0x40000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERNOALLOCATE_SHFT                       18U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERCACHEABLE_BMSK                   0x20000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERCACHEABLE_SHFT                        17U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERSHARED_BMSK                      0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERSHARED_SHFT                           16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERTRANSIENT_BMSK                    0x8000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERTRANSIENT_SHFT                        15U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERWRITETHROUGH_BMSK                 0x4000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERWRITETHROUGH_SHFT                     14U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_PORTMREL_BMSK                          0x2000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_PORTMREL_SHFT                              13U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDRD_BMSK                         0x1000U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDRD_SHFT                             12U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDWR_BMSK                          0x800U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDWR_SHFT                             11U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OOORD_BMSK                              0x400U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OOORD_SHFT                                 10U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OOOWR_BMSK                              0x200U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OOOWR_SHFT                                  9U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_NOALLOCATE_BMSK                         0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_NOALLOCATE_SHFT                             8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_TRANSIENT_BMSK                           0x80U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_TRANSIENT_SHFT                              7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_MEMTYPE_BMSK                              0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_MEMTYPE_SHFT                                0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_ADDR                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_OFFS                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_RMSK                                        0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_SEC_AD_RG_MATCH_BMSK                        0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_SEC_AD_RG_MATCH_SHFT                             8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_NONSEC_AD_RG_MATCH_BMSK                       0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR3_NONSEC_AD_RG_MATCH_SHFT                          0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_RMSK                                   0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_SEC_AD_RG_MATCH_BMSK                   0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_SEC_AD_RG_MATCH_SHFT                        8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_NONSEC_AD_RG_MATCH_BMSK                  0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_NONSEC_AD_RG_MATCH_SHFT                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x89cU)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_RMSK                                   0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_SEC_AD_RG_MATCH_BMSK                   0xff00U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_SEC_AD_RG_MATCH_SHFT                        8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_NONSEC_AD_RG_MATCH_BMSK                  0xffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_NONSEC_AD_RG_MATCH_SHFT                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ADDR                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_OFFS                                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_RMSK                                     0x3ffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ACACHEOPTYPE_BMSK                        0x3c00000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ACACHEOPTYPE_SHFT                               22U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ASID_BMSK                                 0x3e0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ASID_SHFT                                       17U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ACGRANULETRANS_BMSK                        0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ACGRANULETRANS_SHFT                             16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_AUATTR_BMSK                                 0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_ESYNR4_AUATTR_SHFT                                      0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_RMSK                                0x3ffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ACACHEOPTYPE_BMSK                   0x3c00000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ACACHEOPTYPE_SHFT                          22U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ASID_BMSK                            0x3e0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ASID_SHFT                                  17U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ACGRANULETRANS_BMSK                   0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ACGRANULETRANS_SHFT                        16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_AUATTR_BMSK                            0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_AUATTR_SHFT                                 0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ADDR                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_OFFS                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8a0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_RMSK                                0x3ffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ACACHEOPTYPE_BMSK                   0x3c00000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ACACHEOPTYPE_SHFT                          22U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ASID_BMSK                            0x3e0000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ASID_SHFT                                  17U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ACGRANULETRANS_BMSK                   0x10000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ACGRANULETRANS_SHFT                        16U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_AUATTR_BMSK                            0xffffU
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_AUATTR_SHFT                                 0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR                         (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_OFFS                         (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_RMSK                         0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR_31_0_BMSK               0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR_31_0_SHFT                       12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_OFFS                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_RMSK                    0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR_31_0_BMSK          0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR_31_0_SHFT                  12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_OFFS                    (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b0U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_RMSK                    0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR_31_0_BMSK          0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR_31_0_SHFT                  12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR                           (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_OFFS                           (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_RMSK                           0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR_31_0_BMSK                 0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR_31_0_SHFT                         12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_OFFS                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_RMSK                      0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR_31_0_BMSK            0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR_31_0_SHFT                    12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_OFFS                      (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b8U)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_RMSK                      0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR_31_0_BMSK            0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR_31_0_SHFT                    12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_ADDR(r)                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X900 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_OFFS(r)                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X900 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_RMSK                          0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_MAXr                                   0U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_INI(r)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_ADDR(r), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_INMI(r,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_ADDR(r), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_RGOWNERSTATUS_BMSK            0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_RGOWNERSTATUS_SHFT                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_ADDR(s)                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X900 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_OFFS(s)                       (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X900 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_RMSK                          0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_MAXs                                   1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_INI(s)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_ADDR(s), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_INMI(s,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_ADDR(s), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_RGOWNERSTATUS_BMSK            0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_RGOWNERSTATUS_SHFT                     0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1000 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_OFFS(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1000 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RMSK                                       0x107U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RG_SEC_APPS_BMSK                           0x100U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RG_SEC_APPS_SHFT                               8U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RG_OWNER_BMSK                                0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RG_OWNER_SHFT                                  0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1004 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_OFFS(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1004 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_RMSK                                  0x80000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_PD_BMSK                               0x80000000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_PD_SHFT                                       31U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1008 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_OFFS(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1008 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_RMSK                                         0x3U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ASRC_BMSK                                    0x2U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ASRC_SHFT                                      1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_CSRC_BMSK                                    0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_CSRC_SHFT                                      0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X100C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_OFFS(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X100C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_RMSK                                         0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_SECURE_ACCESS_LOCK_BMSK                      0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_SECURE_ACCESS_LOCK_SHFT                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n)                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1010 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_OFFS(n)                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1010 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_MAXn                                           63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_RGSCLRDEN_APPS_BMSK                           0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_RGSCLRDEN_APPS_SHFT                             0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n)                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1014 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_OFFS(n)                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1014 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_RMSK                                          0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_MAXn                                           63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_RGCLRDEN_BMSK                                 0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_RGCLRDEN_SHFT                                   0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n)                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1018 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_OFFS(n)                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1018 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_MAXn                                           63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_RGSCLWREN_APPS_BMSK                           0x1U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_RGSCLWREN_APPS_SHFT                             0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n)                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X101C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_OFFS(n)                                (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X101C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_RMSK                                          0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_MAXn                                           63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_RGCLWREN_BMSK                                 0x7U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_RGCLWREN_SHFT                                   0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n)                             (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1030 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_OFFS(n)                             (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1030 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_RMSK                                0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_MAXn                                        63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR_31_0_BMSK                      0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR_31_0_SHFT                              12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1038 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_OFFS(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1038 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_RMSK                                  0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR_31_0_BMSK                        0xfffff000UL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR_31_0_SHFT                                12U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1040 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_OFFS(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1040 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_RE_BMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_RE_SHFT                                        0U

#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1060 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_OFFS(n)                               (SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1060 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_MAXn                                          63U
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n), HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_RMSK)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n),val)
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n),mask,val,HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_INI(n))
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_WE_BMSK                               0xffffffffUL
#define HWIO_SAILSS_ASIL_D_ASILD_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_WE_SHFT                                        0U

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3
 *--------------------------------------------------------------------------*/

#define SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE                                             (SAILSS_ASIL_B_SAIL_ASIL_B_NOC_WRAPPER_BASE      + 0x00060000UL)
#define SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_SIZE                                        0x3000U
#define SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_USED                                        0x2fe0U
#define SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS                                        0x00060000UL

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_OFFS                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_RMSK                                              0x3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_AALOG_MODE_DIS_BMSK                               0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_AALOG_MODE_DIS_SHFT                                 1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_AADEN_BMSK                                        0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_GCR0_AADEN_SHFT                                          0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_OFFS                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_RMSK                                            0x10fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_DYNAMIC_CLK_EN_BMSK                             0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_DYNAMIC_CLK_EN_SHFT                                 8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_SCLEIE_BMSK                                       0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_SCLEIE_SHFT                                         3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_SCFGEIE_BMSK                                      0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_SCFGEIE_SHFT                                        2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_SCLERE_BMSK                                       0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_SCLERE_SHFT                                         1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_SCFGERE_BMSK                                      0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SCR0_SCFGERE_SHFT                                        0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR                                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x10U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_OFFS                                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_RMSK                                             0x18fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_DYNAMIC_CLK_EN_BMSK                              0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_DYNAMIC_CLK_EN_SHFT                                  8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_VMIDEN_BMSK                                       0x80U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_VMIDEN_SHFT                                          7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_CLEIE_BMSK                                         0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_CLEIE_SHFT                                           3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_CFGEIE_BMSK                                        0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_CFGEIE_SHFT                                          2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_CLERE_BMSK                                         0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_CLERE_SHFT                                           1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_CFGERE_BMSK                                        0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_CR0_CFGERE_SHFT                                          0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x20U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_OFFS                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_RMSK                                   0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_SUVMID_BMSK                            0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RPU_ACR0_SUVMID_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x40U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_OFFS                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_RMSK                                   0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_RE_BMSK                                0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_RACR_RE_SHFT                                         0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x60U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_OFFS                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x60U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_RMSK                                   0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_WE_BMSK                                0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_WACR_WE_SHFT                                         0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x80U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_OFFS                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x80U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_RMSK                                         0x3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_QAD0LOG_MODE_DIS_BMSK                        0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_QAD0LOG_MODE_DIS_SHFT                          1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_QAD0DEN_BMSK                                 0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_GCR0_QAD0DEN_SHFT                                   0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x90U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_OFFS                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_RMSK                                        0x10fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_DYNAMIC_CLK_EN_BMSK                         0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_DYNAMIC_CLK_EN_SHFT                             8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CLEIE_BMSK                                    0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CLEIE_SHFT                                      3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CFGEIE_BMSK                                   0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CFGEIE_SHFT                                     2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CLERE_BMSK                                    0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CLERE_SHFT                                      1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CFGERE_BMSK                                   0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_CR0_CFGERE_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x100U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_OFFS                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x100U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_RMSK                                         0x3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_QAD1LOG_MODE_DIS_BMSK                        0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_QAD1LOG_MODE_DIS_SHFT                          1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_QAD1DEN_BMSK                                 0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_GCR0_QAD1DEN_SHFT                                   0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x110U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_OFFS                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x110U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_RMSK                                        0x10fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_DYNAMIC_CLK_EN_BMSK                         0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_DYNAMIC_CLK_EN_SHFT                             8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CLEIE_BMSK                                    0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CLEIE_SHFT                                      3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CFGEIE_BMSK                                   0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CFGEIE_SHFT                                     2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CLERE_BMSK                                    0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CLERE_SHFT                                      1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CFGERE_BMSK                                   0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_CR0_CFGERE_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x300U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_OFFS                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x300U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_RMSK                                        0x107U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_UMR_SEC_APPS_BMSK                           0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_UMR_SEC_APPS_SHFT                               8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_UMR_OWNER_BMSK                                0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR0_UMR_OWNER_SHFT                                  0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x30cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_OFFS                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x30cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_UMR_SECURE_ACCESS_LOCK_BMSK                   0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_GCR3_UMR_SECURE_ACCESS_LOCK_SHFT                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x310U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_OFFS                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x310U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_RMSK                                           0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_UMRSCLRDEN_APPS_BMSK                           0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR0_UMRSCLRDEN_APPS_SHFT                             0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x314U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_OFFS                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x314U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_RMSK                                           0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ARM_QC_APPROACH_BMSK                           0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_ARM_QC_APPROACH_SHFT                             3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_UMRCLRDEN_BMSK                                 0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR1_UMRCLRDEN_SHFT                                   0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x318U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_OFFS                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x318U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_RMSK                                           0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_UMRSCLWREN_APPS_BMSK                           0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR2_UMRSCLWREN_APPS_SHFT                             0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x31cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_OFFS                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x31cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_RMSK                                           0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_UMRCLWREN_BMSK                                 0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_UMR_CR3_UMRCLWREN_SHFT                                   0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_ADDR                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3ecU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_OFFS                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3ecU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_RMSK                                            0x3ffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_PT_BMSK                                         0x200U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_PT_SHFT                                             9U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_MV_BMSK                                         0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_MV_SHFT                                             8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_NVMID_BMSK                                       0xffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR3_NVMID_SHFT                                          0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_ADDR                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3f0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_OFFS                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3f0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_RMSK                                       0xffffff0fUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_NONSEC_EN_BMSK                             0xff000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_NONSEC_EN_SHFT                                     24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_SEC_EN_BMSK                                  0xff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_SEC_EN_SHFT                                        16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_VMIDACR_EN_BMSK                                0xff00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_VMIDACR_EN_SHFT                                     8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_NUM_QAD_BMSK                                      0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR2_NUM_QAD_SHFT                                        0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_ADDR                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3f4U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_OFFS                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3f4U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_RMSK                                       0x3f3f3f3fUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_CLIENT_ADDR_WIDTH_BMSK                     0x3f000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_CLIENT_ADDR_WIDTH_SHFT                             24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_CONFIG_ADDR_WIDTH_BMSK                       0x3f0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_CONFIG_ADDR_WIDTH_SHFT                             16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_MSB_MPU_BMSK                                   0x3f00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_MSB_MPU_SHFT                                        8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_LSB_BMSK                                         0x3fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR1_LSB_SHFT                                            0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_ADDR                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3f8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_OFFS                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3f8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_RMSK                                        0x3ff0077UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_NRG_BMSK                                    0x3ff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_NRG_SHFT                                           16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_BLED_BMSK                                        0x40U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_BLED_SHFT                                           6U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_CLIENTREQ_HALT_ACK_HW_EN_BMSK                    0x20U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_CLIENTREQ_HALT_ACK_HW_EN_SHFT                       5U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_XPU_CLIENT_PIPELINE_EN_BMSK                      0x10U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_XPU_CLIENT_PIPELINE_EN_SHFT                         4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_XPRESS_CFG_EN_BMSK                                0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_XPRESS_CFG_EN_SHFT                                  2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_XPUTYPE_BMSK                                      0x3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_IDR0_XPUTYPE_SHFT                                        0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_ADDR                                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x3fcU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_OFFS                                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x3fcU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_RMSK                                        0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_MAJOR_BMSK                                  0xf0000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_MAJOR_SHFT                                          28U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_MINOR_BMSK                                   0xfff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_MINOR_SHFT                                          16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_STEP_BMSK                                       0xffffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REV_STEP_SHFT                                            0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR                               (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x400U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_OFFS                               (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x400U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_RMSK                                      0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_LOG_MODE_DIS_BMSK                         0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_LOG_MODE_DIS_LOG_MODE_DIS_SHFT                           0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_ADDR(r)                         (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X500 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_OFFS(r)                         (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X500 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_RMSK                            0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_MAXr                                     0U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_INI(r)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_ADDR(r), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_INMI(r,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_ADDR(r), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_RGFREESTATUS_BMSK               0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSr_RGFREESTATUS_SHFT                        0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_ADDR(s)                         (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X500 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_OFFS(s)                         (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X500 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_RMSK                            0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_MAXs                                     1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_INI(s)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_ADDR(s), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_INMI(s,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_ADDR(s), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_RGFREESTATUS_BMSK               0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_FREESTATUSs_RGFREESTATUS_SHFT                        0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR                                      (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x800U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR0_OFFS                                      (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x800U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR0_RMSK                                      0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR_31_0_BMSK                            0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR0_ADDR_31_0_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR                                      (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x804U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR1_OFFS                                      (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x804U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR1_RMSK                                      0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR_63_32_BMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SEAR1_ADDR_63_32_SHFT                                    0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x808U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_OFFS                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x808U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_RMSK                                              0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_CLMULTI_BMSK                                      0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_CLMULTI_SHFT                                        3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_CFGMULTI_BMSK                                     0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_CFGMULTI_SHFT                                       2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_CLIENT_BMSK                                       0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_CLIENT_SHFT                                         1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_CFG_BMSK                                          0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESR_CFG_SHFT                                            0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x80cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x80cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_RMSK                                       0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CLMULTI_BMSK                               0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CLMULTI_SHFT                                 3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CFGMULTI_BMSK                              0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CFGMULTI_SHFT                                2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CLIENT_BMSK                                0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CLIENT_SHFT                                  1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CFG_BMSK                                   0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESRRESTORE_CFG_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ADDR                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x810U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_OFFS                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x810U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_RMSK                                    0x67ffff0fUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_AC_BMSK                                 0x40000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_AC_SHFT                                         30U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_BURSTLEN_BMSK                           0x20000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_BURSTLEN_SHFT                                   29U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ASIZE_BMSK                               0x7000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ASIZE_SHFT                                      24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ALEN_BMSK                                 0xff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_ALEN_SHFT                                       16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_QAD_BMSK                                    0xff00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_QAD_SHFT                                         8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XPRIV_BMSK                                     0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XPRIV_SHFT                                       3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XINST_BMSK                                     0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XINST_SHFT                                       2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_AWRITE_BMSK                                    0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_AWRITE_SHFT                                      1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XPROTNS_BMSK                                   0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR0_XPROTNS_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_ADDR                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x814U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_OFFS                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x814U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_RMSK                                    0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_TID_BMSK                                0xff000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_TID_SHFT                                        24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_VMID_BMSK                                 0xff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_VMID_SHFT                                       16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_BID_BMSK                                    0xe000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_BID_SHFT                                        13U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_PID_BMSK                                    0x1f00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_PID_SHFT                                         8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_MID_BMSK                                      0xffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR1_MID_SHFT                                         0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ADDR                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x818U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OFFS                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x818U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_RMSK                                    0xffffff87UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_BAR_BMSK                                0xc0000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_BAR_SHFT                                        30U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_BURST_BMSK                              0x20000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_BURST_SHFT                                      29U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_CACHEABLE_BMSK                          0x10000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_CACHEABLE_SHFT                                  28U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_DEVICE_BMSK                              0x8000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_DEVICE_SHFT                                     27U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_DEVICE_TYPE_BMSK                         0x6000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_DEVICE_TYPE_SHFT                                25U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_EARLYWRRESP_BMSK                         0x1000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_EARLYWRRESP_SHFT                                24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ERROR_BMSK                                0x800000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ERROR_SHFT                                      23U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_EXCLUSIVE_BMSK                            0x400000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_EXCLUSIVE_SHFT                                  22U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_FULL_BMSK                                 0x200000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_FULL_SHFT                                       21U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_SHARED_BMSK                               0x100000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_SHARED_SHFT                                     20U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_WRITETHROUGH_BMSK                          0x80000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_WRITETHROUGH_SHFT                               19U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERNOALLOCATE_BMSK                       0x40000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERNOALLOCATE_SHFT                            18U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERCACHEABLE_BMSK                        0x20000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERCACHEABLE_SHFT                             17U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERSHARED_BMSK                           0x10000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERSHARED_SHFT                                16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERTRANSIENT_BMSK                         0x8000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERTRANSIENT_SHFT                             15U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERWRITETHROUGH_BMSK                      0x4000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_INNERWRITETHROUGH_SHFT                          14U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_PORTMREL_BMSK                               0x2000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_PORTMREL_SHFT                                   13U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ORDEREDRD_BMSK                              0x1000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ORDEREDRD_SHFT                                  12U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ORDEREDWR_BMSK                               0x800U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_ORDEREDWR_SHFT                                  11U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OOORD_BMSK                                   0x400U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OOORD_SHFT                                      10U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OOOWR_BMSK                                   0x200U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_OOOWR_SHFT                                       9U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_NOALLOCATE_BMSK                              0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_NOALLOCATE_SHFT                                  8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_TRANSIENT_BMSK                                0x80U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_TRANSIENT_SHFT                                   7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_MEMTYPE_BMSK                                   0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR2_MEMTYPE_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_ADDR                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x81cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_OFFS                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x81cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_RMSK                                        0xffffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_SEC_AD_RG_MATCH_BMSK                        0xff00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_SEC_AD_RG_MATCH_SHFT                             8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_NONSEC_AD_RG_MATCH_BMSK                       0xffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR3_NONSEC_AD_RG_MATCH_SHFT                          0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ADDR                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x820U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_OFFS                                    (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x820U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_RMSK                                     0x3ffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ACACHEOPTYPE_BMSK                        0x3c00000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ACACHEOPTYPE_SHFT                               22U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ASID_BMSK                                 0x3e0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ASID_SHFT                                       17U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ACGRANULETRANS_BMSK                        0x10000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_ACGRANULETRANS_SHFT                             16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_AUATTR_BMSK                                 0xffffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_SESYNR4_AUATTR_SHFT                                      0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR                         (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x830U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_OFFS                         (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x830U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_RMSK                         0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR_31_0_BMSK               0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SSHADOW_ADDR_31_0_SHFT                       12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_ADDR                         (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x834U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_OFFS                         (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x834U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_RMSK                               0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_ADDR_63_32_BMSK                    0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SSHADOW_ADDR_63_32_SHFT                       0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR                           (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x838U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_OFFS                           (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x838U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_RMSK                           0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR_31_0_BMSK                 0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SSHADOW_ADDR_31_0_SHFT                         12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_ADDR                           (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x83cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_OFFS                           (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x83cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_RMSK                                 0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_ADDR_63_32_BMSK                      0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SSHADOW_ADDR_63_32_SHFT                         0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR0_OFFS                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR0_RMSK                                       0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR_31_0_BMSK                             0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR0_ADDR_31_0_SHFT                                      0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_OFFS                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR_31_0_BMSK                        0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR0_ADDR_31_0_SHFT                                 0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x880U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_OFFS                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x880U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR_31_0_BMSK                        0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR0_ADDR_31_0_SHFT                                 0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR1_OFFS                                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR1_RMSK                                       0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR_63_32_BMSK                            0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_EAR1_ADDR_63_32_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_OFFS                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR_63_32_BMSK                       0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_EAR1_ADDR_63_32_SHFT                                0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x884U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_OFFS                                  (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x884U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_RMSK                                  0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR_63_32_BMSK                       0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_EAR1_ADDR_63_32_SHFT                                0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR                                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_OFFS                                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_RMSK                                               0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_CLMULTI_BMSK                                       0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_CLMULTI_SHFT                                         3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_CFGMULTI_BMSK                                      0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_CFGMULTI_SHFT                                        2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_CLIENT_BMSK                                        0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_CLIENT_SHFT                                          1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_CFG_BMSK                                           0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESR_CFG_SHFT                                             0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_OFFS                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_RMSK                                          0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CLMULTI_BMSK                                  0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CLMULTI_SHFT                                    3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CFGMULTI_BMSK                                 0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CFGMULTI_SHFT                                   2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CLIENT_BMSK                                   0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CLIENT_SHFT                                     1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CFG_BMSK                                      0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESR_CFG_SHFT                                        0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x888U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_OFFS                                   (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x888U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_RMSK                                          0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CLMULTI_BMSK                                  0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CLMULTI_SHFT                                    3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CFGMULTI_BMSK                                 0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CFGMULTI_SHFT                                   2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CLIENT_BMSK                                   0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CLIENT_SHFT                                     1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CFG_BMSK                                      0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESR_CFG_SHFT                                        0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_OFFS                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_RMSK                                        0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CLMULTI_BMSK                                0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CLMULTI_SHFT                                  3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CFGMULTI_BMSK                               0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CFGMULTI_SHFT                                 2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CLIENT_BMSK                                 0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CLIENT_SHFT                                   1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CFG_BMSK                                    0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESRRESTORE_CFG_SHFT                                      0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR                            (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_OFFS                            (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_RMSK                                   0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CLMULTI_BMSK                           0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CLMULTI_SHFT                             3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CFGMULTI_BMSK                          0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CFGMULTI_SHFT                            2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CLIENT_BMSK                            0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CLIENT_SHFT                              1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CFG_BMSK                               0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESRRESTORE_CFG_SHFT                                 0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR                            (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x88cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_OFFS                            (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x88cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_RMSK                                   0xfU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CLMULTI_BMSK                           0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CLMULTI_SHFT                             3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CFGMULTI_BMSK                          0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CFGMULTI_SHFT                            2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CLIENT_BMSK                            0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CLIENT_SHFT                              1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CFG_BMSK                               0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESRRESTORE_CFG_SHFT                                 0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ADDR                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_OFFS                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_RMSK                                     0x67ffff0fUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_AC_BMSK                                  0x40000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_AC_SHFT                                          30U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_BURSTLEN_BMSK                            0x20000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_BURSTLEN_SHFT                                    29U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ASIZE_BMSK                                0x7000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ASIZE_SHFT                                       24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ALEN_BMSK                                  0xff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_ALEN_SHFT                                        16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_QAD_BMSK                                     0xff00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_QAD_SHFT                                          8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XPRIV_BMSK                                      0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XPRIV_SHFT                                        3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XINST_BMSK                                      0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XINST_SHFT                                        2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_AWRITE_BMSK                                     0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_AWRITE_SHFT                                       1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XPROTNS_BMSK                                    0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR0_XPROTNS_SHFT                                      0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_RMSK                                0x67ffff0fUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_AC_BMSK                             0x40000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_AC_SHFT                                     30U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_BURSTLEN_BMSK                       0x20000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_BURSTLEN_SHFT                               29U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ASIZE_BMSK                           0x7000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ASIZE_SHFT                                  24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ALEN_BMSK                             0xff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_ALEN_SHFT                                   16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_QAD_BMSK                                0xff00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_QAD_SHFT                                     8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XPRIV_BMSK                                 0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XPRIV_SHFT                                   3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XINST_BMSK                                 0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XINST_SHFT                                   2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_AWRITE_BMSK                                0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_AWRITE_SHFT                                  1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XPROTNS_BMSK                               0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR0_XPROTNS_SHFT                                 0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x890U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x890U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_RMSK                                0x67ffff0fUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_AC_BMSK                             0x40000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_AC_SHFT                                     30U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_BURSTLEN_BMSK                       0x20000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_BURSTLEN_SHFT                               29U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ASIZE_BMSK                           0x7000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ASIZE_SHFT                                  24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ALEN_BMSK                             0xff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_ALEN_SHFT                                   16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_QAD_BMSK                                0xff00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_QAD_SHFT                                     8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XPRIV_BMSK                                 0x8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XPRIV_SHFT                                   3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XINST_BMSK                                 0x4U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XINST_SHFT                                   2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_AWRITE_BMSK                                0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_AWRITE_SHFT                                  1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XPROTNS_BMSK                               0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR0_XPROTNS_SHFT                                 0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_ADDR                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_OFFS                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_RMSK                                     0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_TID_BMSK                                 0xff000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_TID_SHFT                                         24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_VMID_BMSK                                  0xff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_VMID_SHFT                                        16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_BID_BMSK                                     0xe000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_BID_SHFT                                         13U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_PID_BMSK                                     0x1f00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_PID_SHFT                                          8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_MID_BMSK                                       0xffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR1_MID_SHFT                                          0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_RMSK                                0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_TID_BMSK                            0xff000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_TID_SHFT                                    24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_VMID_BMSK                             0xff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_VMID_SHFT                                   16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_BID_BMSK                                0xe000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_BID_SHFT                                    13U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_PID_BMSK                                0x1f00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_PID_SHFT                                     8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_MID_BMSK                                  0xffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR1_MID_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x894U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x894U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_RMSK                                0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_TID_BMSK                            0xff000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_TID_SHFT                                    24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_VMID_BMSK                             0xff0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_VMID_SHFT                                   16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_BID_BMSK                                0xe000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_BID_SHFT                                    13U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_PID_BMSK                                0x1f00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_PID_SHFT                                     8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_MID_BMSK                                  0xffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR1_MID_SHFT                                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ADDR                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OFFS                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_RMSK                                     0xffffff87UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_BAR_BMSK                                 0xc0000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_BAR_SHFT                                         30U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_BURST_BMSK                               0x20000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_BURST_SHFT                                       29U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_CACHEABLE_BMSK                           0x10000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_CACHEABLE_SHFT                                   28U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_DEVICE_BMSK                               0x8000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_DEVICE_SHFT                                      27U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_DEVICE_TYPE_BMSK                          0x6000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_DEVICE_TYPE_SHFT                                 25U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_EARLYWRRESP_BMSK                          0x1000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_EARLYWRRESP_SHFT                                 24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ERROR_BMSK                                 0x800000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ERROR_SHFT                                       23U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_EXCLUSIVE_BMSK                             0x400000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_EXCLUSIVE_SHFT                                   22U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_FULL_BMSK                                  0x200000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_FULL_SHFT                                        21U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_SHARED_BMSK                                0x100000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_SHARED_SHFT                                      20U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_WRITETHROUGH_BMSK                           0x80000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_WRITETHROUGH_SHFT                                19U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERNOALLOCATE_BMSK                        0x40000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERNOALLOCATE_SHFT                             18U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERCACHEABLE_BMSK                         0x20000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERCACHEABLE_SHFT                              17U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERSHARED_BMSK                            0x10000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERSHARED_SHFT                                 16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERTRANSIENT_BMSK                          0x8000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERTRANSIENT_SHFT                              15U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERWRITETHROUGH_BMSK                       0x4000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_INNERWRITETHROUGH_SHFT                           14U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_PORTMREL_BMSK                                0x2000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_PORTMREL_SHFT                                    13U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ORDEREDRD_BMSK                               0x1000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ORDEREDRD_SHFT                                   12U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ORDEREDWR_BMSK                                0x800U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_ORDEREDWR_SHFT                                   11U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OOORD_BMSK                                    0x400U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OOORD_SHFT                                       10U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OOOWR_BMSK                                    0x200U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_OOOWR_SHFT                                        9U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_NOALLOCATE_BMSK                               0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_NOALLOCATE_SHFT                                   8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_TRANSIENT_BMSK                                 0x80U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_TRANSIENT_SHFT                                    7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_MEMTYPE_BMSK                                    0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR2_MEMTYPE_SHFT                                      0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_RMSK                                0xffffff87UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_BAR_BMSK                            0xc0000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_BAR_SHFT                                    30U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_BURST_BMSK                          0x20000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_BURST_SHFT                                  29U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_CACHEABLE_BMSK                      0x10000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_CACHEABLE_SHFT                              28U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_BMSK                          0x8000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_SHFT                                 27U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_TYPE_BMSK                     0x6000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_DEVICE_TYPE_SHFT                            25U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_EARLYWRRESP_BMSK                     0x1000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_EARLYWRRESP_SHFT                            24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ERROR_BMSK                            0x800000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ERROR_SHFT                                  23U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_EXCLUSIVE_BMSK                        0x400000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_EXCLUSIVE_SHFT                              22U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_FULL_BMSK                             0x200000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_FULL_SHFT                                   21U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_SHARED_BMSK                           0x100000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_SHARED_SHFT                                 20U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_WRITETHROUGH_BMSK                      0x80000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_WRITETHROUGH_SHFT                           19U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERNOALLOCATE_BMSK                   0x40000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERNOALLOCATE_SHFT                        18U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERCACHEABLE_BMSK                    0x20000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERCACHEABLE_SHFT                         17U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERSHARED_BMSK                       0x10000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERSHARED_SHFT                            16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERTRANSIENT_BMSK                     0x8000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERTRANSIENT_SHFT                         15U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERWRITETHROUGH_BMSK                  0x4000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_INNERWRITETHROUGH_SHFT                      14U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_PORTMREL_BMSK                           0x2000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_PORTMREL_SHFT                               13U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDRD_BMSK                          0x1000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDRD_SHFT                              12U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDWR_BMSK                           0x800U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_ORDEREDWR_SHFT                              11U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OOORD_BMSK                               0x400U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OOORD_SHFT                                  10U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OOOWR_BMSK                               0x200U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_OOOWR_SHFT                                   9U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_NOALLOCATE_BMSK                          0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_NOALLOCATE_SHFT                              8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_TRANSIENT_BMSK                            0x80U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_TRANSIENT_SHFT                               7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_MEMTYPE_BMSK                               0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR2_MEMTYPE_SHFT                                 0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x898U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x898U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_RMSK                                0xffffff87UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_BAR_BMSK                            0xc0000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_BAR_SHFT                                    30U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_BURST_BMSK                          0x20000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_BURST_SHFT                                  29U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_CACHEABLE_BMSK                      0x10000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_CACHEABLE_SHFT                              28U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_BMSK                          0x8000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_SHFT                                 27U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_TYPE_BMSK                     0x6000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_DEVICE_TYPE_SHFT                            25U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_EARLYWRRESP_BMSK                     0x1000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_EARLYWRRESP_SHFT                            24U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ERROR_BMSK                            0x800000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ERROR_SHFT                                  23U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_EXCLUSIVE_BMSK                        0x400000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_EXCLUSIVE_SHFT                              22U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_FULL_BMSK                             0x200000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_FULL_SHFT                                   21U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_SHARED_BMSK                           0x100000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_SHARED_SHFT                                 20U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_WRITETHROUGH_BMSK                      0x80000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_WRITETHROUGH_SHFT                           19U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERNOALLOCATE_BMSK                   0x40000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERNOALLOCATE_SHFT                        18U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERCACHEABLE_BMSK                    0x20000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERCACHEABLE_SHFT                         17U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERSHARED_BMSK                       0x10000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERSHARED_SHFT                            16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERTRANSIENT_BMSK                     0x8000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERTRANSIENT_SHFT                         15U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERWRITETHROUGH_BMSK                  0x4000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_INNERWRITETHROUGH_SHFT                      14U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_PORTMREL_BMSK                           0x2000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_PORTMREL_SHFT                               13U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDRD_BMSK                          0x1000U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDRD_SHFT                              12U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDWR_BMSK                           0x800U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_ORDEREDWR_SHFT                              11U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OOORD_BMSK                               0x400U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OOORD_SHFT                                  10U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OOOWR_BMSK                               0x200U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_OOOWR_SHFT                                   9U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_NOALLOCATE_BMSK                          0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_NOALLOCATE_SHFT                              8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_TRANSIENT_BMSK                            0x80U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_TRANSIENT_SHFT                               7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_MEMTYPE_BMSK                               0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR2_MEMTYPE_SHFT                                 0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_ADDR                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x89cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_OFFS                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x89cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_RMSK                                         0xffffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_SEC_AD_RG_MATCH_BMSK                         0xff00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_SEC_AD_RG_MATCH_SHFT                              8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_NONSEC_AD_RG_MATCH_BMSK                        0xffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR3_NONSEC_AD_RG_MATCH_SHFT                           0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x89cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x89cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_RMSK                                    0xffffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_SEC_AD_RG_MATCH_BMSK                    0xff00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_SEC_AD_RG_MATCH_SHFT                         8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_NONSEC_AD_RG_MATCH_BMSK                   0xffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR3_NONSEC_AD_RG_MATCH_SHFT                      0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x89cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x89cU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_RMSK                                    0xffffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_SEC_AD_RG_MATCH_BMSK                    0xff00U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_SEC_AD_RG_MATCH_SHFT                         8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_NONSEC_AD_RG_MATCH_BMSK                   0xffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR3_NONSEC_AD_RG_MATCH_SHFT                      0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ADDR                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8a0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_OFFS                                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8a0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_RMSK                                      0x3ffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ACACHEOPTYPE_BMSK                         0x3c00000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ACACHEOPTYPE_SHFT                                22U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ASID_BMSK                                  0x3e0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ASID_SHFT                                        17U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ACGRANULETRANS_BMSK                         0x10000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_ACGRANULETRANS_SHFT                              16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_AUATTR_BMSK                                  0xffffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_ESYNR4_AUATTR_SHFT                                       0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8a0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8a0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_RMSK                                 0x3ffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ACACHEOPTYPE_BMSK                    0x3c00000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ACACHEOPTYPE_SHFT                           22U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ASID_BMSK                             0x3e0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ASID_SHFT                                   17U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ACGRANULETRANS_BMSK                    0x10000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_ACGRANULETRANS_SHFT                         16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_AUATTR_BMSK                             0xffffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_ESYNR4_AUATTR_SHFT                                  0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ADDR                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8a0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_OFFS                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8a0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_RMSK                                 0x3ffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ACACHEOPTYPE_BMSK                    0x3c00000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ACACHEOPTYPE_SHFT                           22U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ASID_BMSK                             0x3e0000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ASID_SHFT                                   17U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ACGRANULETRANS_BMSK                    0x10000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_ACGRANULETRANS_SHFT                         16U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_AUATTR_BMSK                             0xffffU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_ESYNR4_AUATTR_SHFT                                  0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR                          (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_OFFS                          (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_RMSK                          0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR_31_0_BMSK                0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START0_SHADOW_ADDR_31_0_SHFT                        12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_OFFS                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_RMSK                     0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR_31_0_BMSK           0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START0_SHADOW_ADDR_31_0_SHFT                   12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_OFFS                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b0U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_RMSK                     0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR_31_0_BMSK           0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START0_SHADOW_ADDR_31_0_SHFT                   12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_ADDR                          (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b4U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_OFFS                          (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b4U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_RMSK                                0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_ADDR_63_32_BMSK                     0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_START1_SHADOW_ADDR_63_32_SHFT                        0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_ADDR                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b4U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_OFFS                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b4U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_RMSK                           0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_ADDR_63_32_BMSK                0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_START1_SHADOW_ADDR_63_32_SHFT                   0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_ADDR                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b4U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_OFFS                     (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b4U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_RMSK                           0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_ADDR_63_32_BMSK                0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_START1_SHADOW_ADDR_63_32_SHFT                   0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR                            (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_OFFS                            (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_RMSK                            0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR_31_0_BMSK                  0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END0_SHADOW_ADDR_31_0_SHFT                          12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_OFFS                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_RMSK                       0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR_31_0_BMSK             0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END0_SHADOW_ADDR_31_0_SHFT                     12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8b8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_OFFS                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8b8U)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_RMSK                       0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR_31_0_BMSK             0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END0_SHADOW_ADDR_31_0_SHFT                     12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_ADDR                            (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8bcU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_OFFS                            (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8bcU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_RMSK                                  0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_ADDR_63_32_BMSK                       0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_END1_SHADOW_ADDR_63_32_SHFT                          0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_ADDR                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8bcU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_OFFS                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8bcU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_RMSK                             0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_ADDR_63_32_BMSK                  0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD0_RGN_END1_SHADOW_ADDR_63_32_SHFT                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_ADDR                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0x8bcU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_OFFS                       (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0x8bcU)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_RMSK                             0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_IN                    \
                in_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_ADDR)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_INM(m)            \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_ADDR, m)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_ADDR,m,v,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_IN)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_ADDR_63_32_BMSK                  0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_QAD1_RGN_END1_SHADOW_ADDR_63_32_SHFT                     0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_ADDR(r)                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X900 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_OFFS(r)                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X900 + (0x4*(r)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_RMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_MAXr                                    0U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_INI(r)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_ADDR(r), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_INMI(r,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_ADDR(r), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_RGOWNERSTATUS_BMSK             0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSr_RGOWNERSTATUS_SHFT                      0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_ADDR(s)                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X900 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_OFFS(s)                        (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X900 + (0x4*(s)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_RMSK                           0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_MAXs                                    1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_INI(s)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_ADDR(s), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_INMI(s,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_ADDR(s), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_RGOWNERSTATUS_BMSK             0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGN_OWNERSTATUSs_RGOWNERSTATUS_SHFT                      0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1000 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_OFFS(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1000 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RMSK                                        0x107U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_MAXn                                           63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RG_SEC_APPS_BMSK                            0x100U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RG_SEC_APPS_SHFT                                8U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RG_OWNER_BMSK                                 0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR0_RG_OWNER_SHFT                                   0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1004 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_OFFS(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1004 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_RMSK                                   0x80000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_MAXn                                           63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_PD_BMSK                                0x80000000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR1_PD_SHFT                                        31U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1008 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_OFFS(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1008 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_RMSK                                          0x3U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_MAXn                                           63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ASRC_BMSK                                     0x2U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_ASRC_SHFT                                       1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_CSRC_BMSK                                     0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR2_CSRC_SHFT                                       0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X100C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_OFFS(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X100C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_RMSK                                          0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_MAXn                                           63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_SECURE_ACCESS_LOCK_BMSK                       0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_GCR3_SECURE_ACCESS_LOCK_SHFT                         0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n)                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1010 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_OFFS(n)                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1010 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_RMSK                                           0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_MAXn                                            63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_RGSCLRDEN_APPS_BMSK                            0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR0_RGSCLRDEN_APPS_SHFT                              0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n)                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1014 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_OFFS(n)                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1014 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_RMSK                                           0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_MAXn                                            63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_RGCLRDEN_BMSK                                  0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR1_RGCLRDEN_SHFT                                    0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n)                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1018 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_OFFS(n)                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1018 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_RMSK                                           0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_MAXn                                            63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_RGSCLWREN_APPS_BMSK                            0x1U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR2_RGSCLWREN_APPS_SHFT                              0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n)                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X101C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_OFFS(n)                                 (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X101C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_RMSK                                           0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_MAXn                                            63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_RGCLWREN_BMSK                                  0x7U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_CR3_RGCLWREN_SHFT                                    0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n)                              (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1030 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_OFFS(n)                              (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1030 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_RMSK                                 0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_MAXn                                         63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR_31_0_BMSK                       0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START0_ADDR_31_0_SHFT                               12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_ADDR(n)                              (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1034 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_OFFS(n)                              (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1034 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_RMSK                                       0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_MAXn                                         63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_ADDR_63_32_BMSK                            0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_START1_ADDR_63_32_SHFT                               0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1038 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_OFFS(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1038 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_RMSK                                   0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_MAXn                                           63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR_31_0_BMSK                         0xfffff000UL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END0_ADDR_31_0_SHFT                                 12U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_ADDR(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X103C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_OFFS(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X103C + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_RMSK                                         0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_MAXn                                           63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_ADDR_63_32_BMSK                              0x1fU
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_END1_ADDR_63_32_SHFT                                 0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1040 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_OFFS(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1040 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_RMSK                                   0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_MAXn                                           63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_RE_BMSK                                0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_RACR_RE_SHFT                                         0U

#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE      + 0X1060 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_OFFS(n)                                (SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_REG_BASE_OFFS + 0X1060 + (0x80*(n)))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_RMSK                                   0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_MAXn                                           63U
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_INI(n)                \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n), HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_RMSK)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n), mask)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n),val)
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_ADDR(n),mask,val,HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_INI(n))
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_WE_BMSK                                0xffffffffUL
#define HWIO_SAILSS_ASIL_B_ASILB_NOC_MS_MPU_XPU3_RGn_WACR_WE_SHFT                                         0U


#endif /* HALXPU3HWIOTARGET_H */
