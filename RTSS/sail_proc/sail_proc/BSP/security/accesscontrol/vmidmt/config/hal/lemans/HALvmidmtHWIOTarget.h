#ifndef HALVMIDMTHWIOTARGET_H
#define HALVMIDMTHWIOTARGET_H
/*
===========================================================================
*/
/**
    @file HALvmidmtHWIOTarget.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) r2 [lemansau_2.0_p3q3r42_MTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR
        SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1
        SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1
        SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM
        SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40

    'Include' filters applied: .*VMIDMT.* 

    Generation parameters: 
    { 'filename': 'HALvmidmtHWIOTarget.h',
      'filter-include': ['.*VMIDMT.*'],
      'header': '#include "msmhwiobase.h"',
      'integer-qualifiers': True,
      'modules': [ 'SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR',
                   'SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1',
                   'SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1',
                   'SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM',
                   'SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40'],
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
 * MODULE: SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR
 *--------------------------------------------------------------------------*/

#define SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE             (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_BASE      + 0x00000000U)
#define SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_SIZE        0x1000U
#define SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_USED        0xffcU
#define SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS        0x00000000U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x0U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_RMSK                                0x3ff707f5UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_NSCFG_SHFT                                  28U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_WACFG_BMSK                           0xc000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_WACFG_SHFT                                  26U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_RACFG_BMSK                           0x3000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_RACFG_SHFT                                  24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_SHCFG_SHFT                                  22U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_SMCFCFG_SHFT                                21U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_MTCFG_BMSK                            0x100000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_MTCFG_SHFT                                  20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_MEMATTR_SHFT                                16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_USFCFG_BMSK                              0x400U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_USFCFG_SHFT                                 10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_GSE_BMSK                                 0x200U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_GSE_SHFT                                     9U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_STALLD_BMSK                              0x100U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_STALLD_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_TRANSIENTCFG_SHFT                            6U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_GCFGFIE_SHFT                                 5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_GCFGERE_BMSK                              0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_GCFGERE_SHFT                                 4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_GFIE_BMSK                                  0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_GFIE_SHFT                                    2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR0_CLIENTPD_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_ADDR                                 (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x0U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_OFFS                                 (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_RMSK                                  0xff70ff5UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_WACFG_BMSK                            0xc000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_WACFG_SHFT                                   26U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_RACFG_BMSK                            0x3000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_RACFG_SHFT                                   24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_SHCFG_BMSK                             0xc00000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_SHCFG_SHFT                                   22U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_SMCFCFG_SHFT                                 21U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_MTCFG_BMSK                             0x100000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_MTCFG_SHFT                                   20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_MEMATTR_BMSK                            0x70000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_MEMATTR_SHFT                                 16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_VMIDPNE_BMSK                              0x800U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_VMIDPNE_SHFT                                 11U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_USFCFG_BMSK                               0x400U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_USFCFG_SHFT                                  10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_GSE_BMSK                                  0x200U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_GSE_SHFT                                      9U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_STALLD_BMSK                               0x100U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_STALLD_SHFT                                   8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_TRANSIENTCFG_SHFT                             6U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_GCFGFIE_BMSK                               0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_GCFGFIE_SHFT                                  5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_GCFGERE_BMSK                               0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_GCFGERE_SHFT                                  4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_GFIE_BMSK                                   0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_GFIE_SHFT                                     2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_CLIENTPD_BMSK                               0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR0_CLIENTPD_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x4U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x4U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_RMSK                                 0x100ff00UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_GASRAE_SHFT                                 24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_NSNUMSMRGO_BMSK                         0xff00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR1_NSNUMSMRGO_SHFT                              8U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x8U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_RMSK                                      0x1fU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_BPVMID_BMSK                               0x1fU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SCR2_BPVMID_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_ADDR                                 (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x8U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_OFFS                                 (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_RMSK                                       0x1fU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_BPVMID_BMSK                                0x1fU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_CR2_BPVMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x10U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_RMSK                                0x70000013UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPRCNSH_SHFT                                30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPRCISH_SHFT                                29U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPRCOSH_SHFT                                28U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SACR_BPREQPRIORITY_SHFT                           0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_ADDR                                 (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x10U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_OFFS                                 (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_RMSK                                 0x70000013UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPRCNSH_SHFT                                 30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPRCISH_SHFT                                 29U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPRCOSH_SHFT                                 28U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                         4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_ACR_BPREQPRIORITY_SHFT                            0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x20U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_RMSK                               0x88001effUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_SES_BMSK                           0x80000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_SES_SHFT                                   31U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_SMS_BMSK                            0x8000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_SMS_SHFT                                   27U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_NUMSIDB_SHFT                                9U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR0_NUMSMRG_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x20U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_RMSK                                 0x8001effUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_SMS_BMSK                             0x8000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_SMS_SHFT                                    27U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_NUMSIDB_SHFT                                 9U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_NUMSMRG_BMSK                              0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR0_NUMSMRG_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x24U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_RMSK                                   0x9f00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_SMCD_BMSK                              0x8000U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_SMCD_SHFT                                  15U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_SSDTP_SHFT                                 12U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR1_NUMSSDNDX_SHFT                              8U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x24U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_RMSK                                    0x9f00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_SMCD_BMSK                               0x8000U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_SMCD_SHFT                                   15U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_SSDTP_BMSK                              0x1000U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_SSDTP_SHFT                                  12U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR1_NUMSSDNDX_SHFT                               8U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x28U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_RMSK                                     0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_OAS_BMSK                                 0xf0U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_OAS_SHFT                                    4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_IAS_BMSK                                  0xfU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR2_IAS_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x28U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_RMSK                                      0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_OAS_BMSK                                  0xf0U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_OAS_SHFT                                     4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_IAS_BMSK                                   0xfU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR2_IAS_SHFT                                     0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x30U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_RMSK                               0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_MAJOR_SHFT                                 28U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_MINOR_SHFT                                 16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_STEP_BMSK                              0xffffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR4_STEP_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x30U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_RMSK                                0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_MAJOR_SHFT                                  28U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_MINOR_SHFT                                  16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_STEP_BMSK                               0xffffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR4_STEP_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x34U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_RMSK                                 0xff03ffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_NUMMSDRB_SHFT                              16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_MSAE_BMSK                               0x200U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_MSAE_SHFT                                   9U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_QRIBE_BMSK                              0x100U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_QRIBE_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_NVMID_BMSK                               0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR5_NVMID_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x34U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_RMSK                                  0xff03ffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_NUMMSDRB_SHFT                               16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_MSAE_BMSK                                0x200U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_MSAE_SHFT                                    9U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_QRIBE_BMSK                               0x100U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_QRIBE_SHFT                                   8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_NVMID_BMSK                                0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR5_NVMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_RMSK                                     0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_MAJOR_SHFT                                  4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_MINOR_BMSK                                0xfU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SIDR7_MINOR_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_RMSK                                      0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_MAJOR_BMSK                                0xf0U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_MAJOR_SHFT                                   4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_MINOR_BMSK                                 0xfU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_IDR7_MINOR_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFAR0_ADDR                              (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x40U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFAR0_OFFS                              (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFAR0_RMSK                              0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFAR0_SGFEA0_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFAR0_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x40U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFAR0_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFAR0_RMSK                               0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFAR0_GFEA0_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x48U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_RMSK                               0xc0000026UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                          31U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_MULTI_CFG_SHFT                             30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_CAF_BMSK                                 0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_CAF_SHFT                                    5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_SMCF_BMSK                                 0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_SMCF_SHFT                                   2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_USF_BMSK                                  0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSR_USF_SHFT                                    1U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_ADDR                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x48U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_OFFS                                (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_RMSK                                0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_MULTI_CLIENT_SHFT                           31U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_MULTI_CFG_SHFT                              30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_PF_BMSK                                   0x80U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_PF_SHFT                                      7U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_CAF_BMSK                                  0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_CAF_SHFT                                     5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_SMCF_BMSK                                  0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_SMCF_SHFT                                    2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_USF_BMSK                                   0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSR_USF_SHFT                                     1U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_ADDR                        (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_OFFS                        (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                   31U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                      30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_CAF_SHFT                             5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_SMCF_SHFT                            2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSRRESTORE_USF_SHFT                             1U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_ADDR                         (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_OFFS                         (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                    31U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                       30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_PF_SHFT                               7U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_CAF_SHFT                              5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_SMCF_SHFT                             2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSRRESTORE_USF_SHFT                              1U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_ADDR                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x50U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_OFFS                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_RMSK                                0x132U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                        8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_NSATTR_SHFT                             5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                            4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR0_WNR_SHFT                                1U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_ADDR                            (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x50U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_OFFS                            (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_RMSK                                 0x132U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                         8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_NSATTR_SHFT                              5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_NSSTATE_SHFT                             4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR0_WNR_SHFT                                 1U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_ADDR                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x54U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_OFFS                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_RMSK                            0x10100ffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                   0x1000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                          24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                     0x10000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                          16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                     0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                        0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_ADDR                            (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x54U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_OFFS                            (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_RMSK                             0x10100ffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                    0x1000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                           24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                      0x10000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                           16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                      0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                         0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_ADDR                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x58U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_OFFS                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_ATID_SHFT                              24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_AVMID_SHFT                             16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_ABID_SHFT                              13U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_APID_SHFT                               8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SGFSYNDR2_AMID_SHFT                               0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_ADDR                            (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x58U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_OFFS                            (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_ATID_SHFT                               24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_AVMID_SHFT                              16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_ABID_SHFT                               13U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_APID_SHFT                                8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_AMID_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_GFSYNDR2_AMID_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x80U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x80U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_RMSK                                      0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_RWE_BMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_ADDR                          (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x90U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_OFFS                          (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_RMSK                                 0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                         0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_ADDR                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x90U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_OFFS                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_RMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                          0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_ADDR                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x9cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_OFFS                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x9cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_RMSK                           0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_VMIDMTACR_RWE_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x400U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x400U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_RMSK                                0xff70ff5UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_WACFG_SHFT                                 26U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_RACFG_SHFT                                 24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_SHCFG_SHFT                                 22U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_SMCFCFG_SHFT                               21U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_MTCFG_SHFT                                 20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_MEMATTR_SHFT                               16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_VMIDPNE_SHFT                               11U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_USFCFG_BMSK                             0x400U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_USFCFG_SHFT                                10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_GSE_BMSK                                0x200U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_GSE_SHFT                                    9U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_STALLD_BMSK                             0x100U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_STALLD_SHFT                                 8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                           6U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_GCFGFIE_SHFT                                5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_GCFGERE_SHFT                                4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_GFIE_BMSK                                 0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_GFIE_SHFT                                   2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR0_CLIENTPD_SHFT                               0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x408U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x408U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_RMSK                                     0x1fU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_BPVMID_BMSK                              0x1fU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSCR2_BPVMID_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x410U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x410U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_RMSK                               0x70000013UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPRCNSH_SHFT                               30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPRCISH_SHFT                               29U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPRCOSH_SHFT                               28U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                       4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSACR_BPREQPRIORITY_SHFT                          0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFAR0_ADDR                             (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x440U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFAR0_OFFS                             (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x440U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFAR0_RMSK                             0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFAR0_GFEA0_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_ADDR                              (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x448U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_OFFS                              (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x448U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_RMSK                              0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                         31U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_MULTI_CFG_SHFT                            30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_PF_BMSK                                 0x80U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_PF_SHFT                                    7U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_CAF_BMSK                                0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_CAF_SHFT                                   5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_SMCF_BMSK                                0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_SMCF_SHFT                                  2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_USF_BMSK                                 0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSR_USF_SHFT                                   1U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_ADDR                       (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x44cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_OFFS                       (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x44cU)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                  31U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                     30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_PF_SHFT                             7U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_CAF_SHFT                            5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                           2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSRRESTORE_USF_SHFT                            1U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_ADDR                          (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x450U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_OFFS                          (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x450U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_RMSK                               0x132U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                       8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                            5U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                           4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR0_WNR_SHFT                               1U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_ADDR                          (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x454U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_OFFS                          (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x454U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_RMSK                           0x10100ffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                  0x1000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                         24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                    0x10000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                         16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                    0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                       0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_ADDR                          (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x458U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_OFFS                          (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x458U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_ATID_SHFT                             24U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_AVMID_SHFT                            16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_ABID_SHFT                             13U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_APID_SHFT                              8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSGFSYNDR2_AMID_SHFT                              0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_ADDR                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x480U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_OFFS                               (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x480U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_RMSK                                      0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_RWE_BMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_ADDR                         (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x490U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_OFFS                         (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x490U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_RMSK                                0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                        0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_ADDR                                 (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0x494U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_OFFS                                 (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0x494U)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_RMSK                                        0x7U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_ADDR)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_ADDR,m,v,HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_IN)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_CLKONOFFE_SHFT                                2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_BPMSACFG_BMSK                               0x2U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_BPMSACFG_SHFT                                 1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_MCR_BPSMSACFG_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_ADDR(n)                             (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_OFFS(n)                             (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_RMSK                                0x80ff00ffUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_MAXn                                       127U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_ADDR(n), HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_RMSK)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_INI(n))
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_VALID_BMSK                          0x80000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_VALID_SHFT                                  31U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_MASK_BMSK                             0xff0000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_MASK_SHFT                                   16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_ID_BMSK                                   0xffU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_SMRn_ID_SHFT                                      0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_ADDR(n)                            (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_OFFS(n)                            (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_RMSK                               0x30ff7b1fUL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_MAXn                                      127U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_ADDR(n), HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_RMSK)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_INI(n))
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                          28U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_WACFG_SHFT                                 22U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_RACFG_BMSK                           0x300000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_RACFG_SHFT                                 20U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_NSCFG_SHFT                                 18U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_TYPE_BMSK                             0x30000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_TYPE_SHFT                                  16U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_MEMATTR_SHFT                               12U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_MTCFG_BMSK                              0x800U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_MTCFG_SHFT                                 11U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_SHCFG_BMSK                              0x300U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_SHCFG_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_VMID_BMSK                                0x1fU
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_S2VRn_VMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_ADDR(n)                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE      + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_OFFS(n)                           (SAILSS_VMIDMT_0_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_REG_BASE_OFFS + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_RMSK                              0x70000013UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_MAXn                                     127U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_ADDR(n), HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_RMSK)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_INI(n))
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_RCNSH_SHFT                                30U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_RCISH_SHFT                                29U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_RCOSH_SHFT                                28U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_VMIDMT_0_VMIDMT_AS2VRn_REQPRIORITY_SHFT                           0U

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1
 *--------------------------------------------------------------------------*/

#define SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE                 (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_BASE      + 0x00000000U)
#define SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_SIZE            0x1000U
#define SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_USED            0xe3cU
#define SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS            0x00000000U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x0U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_RMSK                                0x3ff707f5UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_NSCFG_SHFT                                  28U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_WACFG_BMSK                           0xc000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_WACFG_SHFT                                  26U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_RACFG_BMSK                           0x3000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_RACFG_SHFT                                  24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_SHCFG_SHFT                                  22U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_SMCFCFG_SHFT                                21U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_MTCFG_BMSK                            0x100000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_MTCFG_SHFT                                  20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_MEMATTR_SHFT                                16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_USFCFG_BMSK                              0x400U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_USFCFG_SHFT                                 10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_GSE_BMSK                                 0x200U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_GSE_SHFT                                     9U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_STALLD_BMSK                              0x100U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_STALLD_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_TRANSIENTCFG_SHFT                            6U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_GCFGFIE_SHFT                                 5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_GCFGERE_BMSK                              0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_GCFGERE_SHFT                                 4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_GFIE_BMSK                                  0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_GFIE_SHFT                                    2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR0_CLIENTPD_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_ADDR                                 (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x0U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_OFFS                                 (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_RMSK                                  0xff70ff5UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_WACFG_BMSK                            0xc000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_WACFG_SHFT                                   26U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_RACFG_BMSK                            0x3000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_RACFG_SHFT                                   24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_SHCFG_BMSK                             0xc00000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_SHCFG_SHFT                                   22U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_SMCFCFG_SHFT                                 21U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_MTCFG_BMSK                             0x100000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_MTCFG_SHFT                                   20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_MEMATTR_BMSK                            0x70000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_MEMATTR_SHFT                                 16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_VMIDPNE_BMSK                              0x800U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_VMIDPNE_SHFT                                 11U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_USFCFG_BMSK                               0x400U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_USFCFG_SHFT                                  10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_GSE_BMSK                                  0x200U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_GSE_SHFT                                      9U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_STALLD_BMSK                               0x100U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_STALLD_SHFT                                   8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_TRANSIENTCFG_SHFT                             6U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_GCFGFIE_BMSK                               0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_GCFGFIE_SHFT                                  5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_GCFGERE_BMSK                               0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_GCFGERE_SHFT                                  4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_GFIE_BMSK                                   0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_GFIE_SHFT                                     2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_CLIENTPD_BMSK                               0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR0_CLIENTPD_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x4U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x4U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_RMSK                                 0x1001f00UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_GASRAE_SHFT                                 24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_NSNUMSMRGO_BMSK                         0x1f00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR1_NSNUMSMRGO_SHFT                              8U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x8U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_RMSK                                      0x1fU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_BPVMID_BMSK                               0x1fU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SCR2_BPVMID_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_ADDR                                 (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x8U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_OFFS                                 (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_RMSK                                       0x1fU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_BPVMID_BMSK                                0x1fU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_CR2_BPVMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x10U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_RMSK                                0x70000013UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPRCNSH_SHFT                                30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPRCISH_SHFT                                29U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPRCOSH_SHFT                                28U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SACR_BPREQPRIORITY_SHFT                           0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_ADDR                                 (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x10U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_OFFS                                 (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_RMSK                                 0x70000013UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPRCNSH_SHFT                                 30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPRCISH_SHFT                                 29U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPRCOSH_SHFT                                 28U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                         4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_ACR_BPREQPRIORITY_SHFT                            0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x20U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_RMSK                               0x88001effUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_SES_BMSK                           0x80000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_SES_SHFT                                   31U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_SMS_BMSK                            0x8000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_SMS_SHFT                                   27U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_NUMSIDB_SHFT                                9U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR0_NUMSMRG_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x20U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_RMSK                                 0x8001effUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_SMS_BMSK                             0x8000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_SMS_SHFT                                    27U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_NUMSIDB_SHFT                                 9U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_NUMSMRG_BMSK                              0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR0_NUMSMRG_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x24U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_RMSK                                   0x9f00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_SMCD_BMSK                              0x8000U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_SMCD_SHFT                                  15U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_SSDTP_SHFT                                 12U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR1_NUMSSDNDX_SHFT                              8U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x24U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_RMSK                                    0x9f00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_SMCD_BMSK                               0x8000U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_SMCD_SHFT                                   15U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_SSDTP_BMSK                              0x1000U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_SSDTP_SHFT                                  12U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR1_NUMSSDNDX_SHFT                               8U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x28U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_RMSK                                     0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_OAS_BMSK                                 0xf0U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_OAS_SHFT                                    4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_IAS_BMSK                                  0xfU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR2_IAS_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x28U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_RMSK                                      0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_OAS_BMSK                                  0xf0U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_OAS_SHFT                                     4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_IAS_BMSK                                   0xfU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR2_IAS_SHFT                                     0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x30U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_RMSK                               0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_MAJOR_SHFT                                 28U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_MINOR_SHFT                                 16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_STEP_BMSK                              0xffffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR4_STEP_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x30U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_RMSK                                0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_MAJOR_SHFT                                  28U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_MINOR_SHFT                                  16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_STEP_BMSK                               0xffffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR4_STEP_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x34U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_RMSK                                 0xff03ffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_NUMMSDRB_SHFT                              16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_MSAE_BMSK                               0x200U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_MSAE_SHFT                                   9U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_QRIBE_BMSK                              0x100U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_QRIBE_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_NVMID_BMSK                               0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR5_NVMID_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x34U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_RMSK                                  0xff03ffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_NUMMSDRB_SHFT                               16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_MSAE_BMSK                                0x200U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_MSAE_SHFT                                    9U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_QRIBE_BMSK                               0x100U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_QRIBE_SHFT                                   8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_NVMID_BMSK                                0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR5_NVMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_RMSK                                     0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_MAJOR_SHFT                                  4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_MINOR_BMSK                                0xfU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SIDR7_MINOR_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_RMSK                                      0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_MAJOR_BMSK                                0xf0U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_MAJOR_SHFT                                   4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_MINOR_BMSK                                 0xfU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_IDR7_MINOR_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFAR0_ADDR                              (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x40U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFAR0_OFFS                              (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFAR0_RMSK                              0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFAR0_SGFEA0_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFAR0_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x40U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFAR0_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFAR0_RMSK                               0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFAR0_GFEA0_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x48U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_RMSK                               0xc0000026UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                          31U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_MULTI_CFG_SHFT                             30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_CAF_BMSK                                 0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_CAF_SHFT                                    5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_SMCF_BMSK                                 0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_SMCF_SHFT                                   2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_USF_BMSK                                  0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSR_USF_SHFT                                    1U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_ADDR                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x48U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_OFFS                                (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_RMSK                                0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_MULTI_CLIENT_SHFT                           31U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_MULTI_CFG_SHFT                              30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_PF_BMSK                                   0x80U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_PF_SHFT                                      7U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_CAF_BMSK                                  0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_CAF_SHFT                                     5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_SMCF_BMSK                                  0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_SMCF_SHFT                                    2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_USF_BMSK                                   0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSR_USF_SHFT                                     1U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_ADDR                        (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_OFFS                        (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                   31U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                      30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_CAF_SHFT                             5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_SMCF_SHFT                            2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSRRESTORE_USF_SHFT                             1U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_ADDR                         (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_OFFS                         (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                    31U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                       30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_PF_SHFT                               7U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_CAF_SHFT                              5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_SMCF_SHFT                             2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSRRESTORE_USF_SHFT                              1U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_ADDR                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x50U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_OFFS                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_RMSK                                0x132U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                        8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_NSATTR_SHFT                             5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                            4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR0_WNR_SHFT                                1U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_ADDR                            (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x50U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_OFFS                            (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_RMSK                                 0x132U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                         8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_NSATTR_SHFT                              5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_NSSTATE_SHFT                             4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR0_WNR_SHFT                                 1U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_ADDR                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x54U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_OFFS                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_RMSK                            0x101000fUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                   0x1000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                          24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                     0x10000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                          16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                      0xfU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                        0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_ADDR                            (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x54U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_OFFS                            (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_RMSK                             0x101000fUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                    0x1000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                           24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                      0x10000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                           16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                       0xfU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                         0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_ADDR                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x58U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_OFFS                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_ATID_SHFT                              24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_AVMID_SHFT                             16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_ABID_SHFT                              13U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_APID_SHFT                               8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SGFSYNDR2_AMID_SHFT                               0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_ADDR                            (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x58U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_OFFS                            (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_ATID_SHFT                               24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_AVMID_SHFT                              16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_ABID_SHFT                               13U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_APID_SHFT                                8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_AMID_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_GFSYNDR2_AMID_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x80U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x80U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_RMSK                                      0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_RWE_BMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_ADDR                          (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x90U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_OFFS                          (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_RMSK                                 0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                         0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_ADDR                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x90U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_OFFS                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_RMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                          0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_ADDR                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x9cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_OFFS                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x9cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_RMSK                           0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_VMIDMTACR_RWE_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x400U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x400U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_RMSK                                0xff70ff5UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_WACFG_SHFT                                 26U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_RACFG_SHFT                                 24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_SHCFG_SHFT                                 22U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_SMCFCFG_SHFT                               21U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_MTCFG_SHFT                                 20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_MEMATTR_SHFT                               16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_VMIDPNE_SHFT                               11U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_USFCFG_BMSK                             0x400U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_USFCFG_SHFT                                10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_GSE_BMSK                                0x200U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_GSE_SHFT                                    9U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_STALLD_BMSK                             0x100U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_STALLD_SHFT                                 8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                           6U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_GCFGFIE_SHFT                                5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_GCFGERE_SHFT                                4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_GFIE_BMSK                                 0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_GFIE_SHFT                                   2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR0_CLIENTPD_SHFT                               0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x408U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x408U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_RMSK                                     0x1fU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_BPVMID_BMSK                              0x1fU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSCR2_BPVMID_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x410U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x410U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_RMSK                               0x70000013UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPRCNSH_SHFT                               30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPRCISH_SHFT                               29U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPRCOSH_SHFT                               28U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                       4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSACR_BPREQPRIORITY_SHFT                          0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFAR0_ADDR                             (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x440U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFAR0_OFFS                             (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x440U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFAR0_RMSK                             0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFAR0_GFEA0_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_ADDR                              (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x448U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_OFFS                              (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x448U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_RMSK                              0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                         31U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_MULTI_CFG_SHFT                            30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_PF_BMSK                                 0x80U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_PF_SHFT                                    7U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_CAF_BMSK                                0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_CAF_SHFT                                   5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_SMCF_BMSK                                0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_SMCF_SHFT                                  2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_USF_BMSK                                 0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSR_USF_SHFT                                   1U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_ADDR                       (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x44cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_OFFS                       (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x44cU)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                  31U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                     30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_PF_SHFT                             7U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_CAF_SHFT                            5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                           2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSRRESTORE_USF_SHFT                            1U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_ADDR                          (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x450U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_OFFS                          (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x450U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_RMSK                               0x132U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                       8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                            5U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                           4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR0_WNR_SHFT                               1U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_ADDR                          (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x454U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_OFFS                          (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x454U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_RMSK                           0x101000fUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                  0x1000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                         24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                    0x10000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                         16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                     0xfU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                       0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_ADDR                          (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x458U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_OFFS                          (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x458U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_ATID_SHFT                             24U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_AVMID_SHFT                            16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_ABID_SHFT                             13U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_APID_SHFT                              8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xffU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSGFSYNDR2_AMID_SHFT                              0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_ADDR                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x480U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_OFFS                               (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x480U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_RMSK                                      0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_RWE_BMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_ADDR                         (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x490U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_OFFS                         (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x490U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_RMSK                                0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                        0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_ADDR                                 (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x494U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_OFFS                                 (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x494U)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_RMSK                                        0x7U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_ADDR)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_ADDR,m,v,HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_IN)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_CLKONOFFE_SHFT                                2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_BPMSACFG_BMSK                               0x2U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_BPMSACFG_SHFT                                 1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_MCR_BPSMSACFG_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_ADDR(n)                             (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_OFFS(n)                             (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_RMSK                                0x800f000fUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_MAXn                                        15U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_ADDR(n), HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_RMSK)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_INI(n))
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_VALID_BMSK                          0x80000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_VALID_SHFT                                  31U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_MASK_BMSK                              0xf0000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_MASK_SHFT                                   16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_ID_BMSK                                    0xfU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_SMRn_ID_SHFT                                      0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_ADDR(n)                            (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_OFFS(n)                            (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_RMSK                               0x30ff7b1fUL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_MAXn                                       15U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_ADDR(n), HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_RMSK)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_INI(n))
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                          28U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_WACFG_SHFT                                 22U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_RACFG_BMSK                           0x300000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_RACFG_SHFT                                 20U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_NSCFG_SHFT                                 18U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_TYPE_BMSK                             0x30000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_TYPE_SHFT                                  16U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_MEMATTR_SHFT                               12U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_MTCFG_BMSK                              0x800U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_MTCFG_SHFT                                 11U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_SHCFG_BMSK                              0x300U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_SHCFG_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_VMID_BMSK                                0x1fU
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_S2VRn_VMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_ADDR(n)                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_OFFS(n)                           (SAILSS_VMIDMT_1_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_RMSK                              0x70000013UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_MAXn                                      15U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_ADDR(n), HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_RMSK)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_INI(n))
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_RCNSH_SHFT                                30U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_RCISH_SHFT                                29U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_RCOSH_SHFT                                28U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_VMIDMT_1_VMIDMT_AS2VRn_REQPRIORITY_SHFT                           0U

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1
 *--------------------------------------------------------------------------*/

#define SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE                 (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_BASE      + 0x00000000U)
#define SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_SIZE            0x1000U
#define SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_USED            0xe3cU
#define SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS            0x00000000U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x0U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_RMSK                                0x3ff707f5UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_NSCFG_SHFT                                  28U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_WACFG_BMSK                           0xc000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_WACFG_SHFT                                  26U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_RACFG_BMSK                           0x3000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_RACFG_SHFT                                  24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_SHCFG_SHFT                                  22U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_SMCFCFG_SHFT                                21U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_MTCFG_BMSK                            0x100000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_MTCFG_SHFT                                  20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_MEMATTR_SHFT                                16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_USFCFG_BMSK                              0x400U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_USFCFG_SHFT                                 10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_GSE_BMSK                                 0x200U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_GSE_SHFT                                     9U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_STALLD_BMSK                              0x100U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_STALLD_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_TRANSIENTCFG_SHFT                            6U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_GCFGFIE_SHFT                                 5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_GCFGERE_BMSK                              0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_GCFGERE_SHFT                                 4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_GFIE_BMSK                                  0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_GFIE_SHFT                                    2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR0_CLIENTPD_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_ADDR                                 (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x0U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_OFFS                                 (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_RMSK                                  0xff70ff5UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_WACFG_BMSK                            0xc000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_WACFG_SHFT                                   26U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_RACFG_BMSK                            0x3000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_RACFG_SHFT                                   24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_SHCFG_BMSK                             0xc00000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_SHCFG_SHFT                                   22U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_SMCFCFG_SHFT                                 21U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_MTCFG_BMSK                             0x100000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_MTCFG_SHFT                                   20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_MEMATTR_BMSK                            0x70000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_MEMATTR_SHFT                                 16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_VMIDPNE_BMSK                              0x800U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_VMIDPNE_SHFT                                 11U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_USFCFG_BMSK                               0x400U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_USFCFG_SHFT                                  10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_GSE_BMSK                                  0x200U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_GSE_SHFT                                      9U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_STALLD_BMSK                               0x100U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_STALLD_SHFT                                   8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_TRANSIENTCFG_SHFT                             6U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_GCFGFIE_BMSK                               0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_GCFGFIE_SHFT                                  5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_GCFGERE_BMSK                               0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_GCFGERE_SHFT                                  4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_GFIE_BMSK                                   0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_GFIE_SHFT                                     2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_CLIENTPD_BMSK                               0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR0_CLIENTPD_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x4U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x4U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_RMSK                                 0x1001f00UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_GASRAE_SHFT                                 24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_NSNUMSMRGO_BMSK                         0x1f00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR1_NSNUMSMRGO_SHFT                              8U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x8U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_RMSK                                      0x1fU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_BPVMID_BMSK                               0x1fU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SCR2_BPVMID_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_ADDR                                 (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x8U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_OFFS                                 (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_RMSK                                       0x1fU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_BPVMID_BMSK                                0x1fU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_CR2_BPVMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x10U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_RMSK                                0x70000013UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPRCNSH_SHFT                                30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPRCISH_SHFT                                29U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPRCOSH_SHFT                                28U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SACR_BPREQPRIORITY_SHFT                           0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_ADDR                                 (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x10U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_OFFS                                 (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_RMSK                                 0x70000013UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPRCNSH_SHFT                                 30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPRCISH_SHFT                                 29U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPRCOSH_SHFT                                 28U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                         4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_ACR_BPREQPRIORITY_SHFT                            0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x20U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_RMSK                               0x88001effUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_SES_BMSK                           0x80000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_SES_SHFT                                   31U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_SMS_BMSK                            0x8000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_SMS_SHFT                                   27U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_NUMSIDB_SHFT                                9U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR0_NUMSMRG_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x20U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_RMSK                                 0x8001effUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_SMS_BMSK                             0x8000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_SMS_SHFT                                    27U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_NUMSIDB_SHFT                                 9U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_NUMSMRG_BMSK                              0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR0_NUMSMRG_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x24U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_RMSK                                   0x9f00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_SMCD_BMSK                              0x8000U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_SMCD_SHFT                                  15U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_SSDTP_SHFT                                 12U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR1_NUMSSDNDX_SHFT                              8U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x24U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_RMSK                                    0x9f00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_SMCD_BMSK                               0x8000U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_SMCD_SHFT                                   15U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_SSDTP_BMSK                              0x1000U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_SSDTP_SHFT                                  12U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR1_NUMSSDNDX_SHFT                               8U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x28U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_RMSK                                     0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_OAS_BMSK                                 0xf0U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_OAS_SHFT                                    4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_IAS_BMSK                                  0xfU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR2_IAS_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x28U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_RMSK                                      0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_OAS_BMSK                                  0xf0U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_OAS_SHFT                                     4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_IAS_BMSK                                   0xfU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR2_IAS_SHFT                                     0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x30U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_RMSK                               0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_MAJOR_SHFT                                 28U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_MINOR_SHFT                                 16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_STEP_BMSK                              0xffffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR4_STEP_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x30U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_RMSK                                0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_MAJOR_SHFT                                  28U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_MINOR_SHFT                                  16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_STEP_BMSK                               0xffffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR4_STEP_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x34U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_RMSK                                 0xff03ffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_NUMMSDRB_SHFT                              16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_MSAE_BMSK                               0x200U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_MSAE_SHFT                                   9U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_QRIBE_BMSK                              0x100U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_QRIBE_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_NVMID_BMSK                               0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR5_NVMID_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x34U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_RMSK                                  0xff03ffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_NUMMSDRB_SHFT                               16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_MSAE_BMSK                                0x200U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_MSAE_SHFT                                    9U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_QRIBE_BMSK                               0x100U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_QRIBE_SHFT                                   8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_NVMID_BMSK                                0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR5_NVMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_RMSK                                     0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_MAJOR_SHFT                                  4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_MINOR_BMSK                                0xfU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SIDR7_MINOR_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_RMSK                                      0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_MAJOR_BMSK                                0xf0U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_MAJOR_SHFT                                   4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_MINOR_BMSK                                 0xfU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_IDR7_MINOR_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFAR0_ADDR                              (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x40U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFAR0_OFFS                              (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFAR0_RMSK                              0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFAR0_SGFEA0_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFAR0_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x40U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFAR0_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFAR0_RMSK                               0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFAR0_GFEA0_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x48U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_RMSK                               0xc0000026UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                          31U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_MULTI_CFG_SHFT                             30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_CAF_BMSK                                 0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_CAF_SHFT                                    5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_SMCF_BMSK                                 0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_SMCF_SHFT                                   2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_USF_BMSK                                  0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSR_USF_SHFT                                    1U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_ADDR                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x48U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_OFFS                                (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_RMSK                                0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_MULTI_CLIENT_SHFT                           31U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_MULTI_CFG_SHFT                              30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_PF_BMSK                                   0x80U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_PF_SHFT                                      7U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_CAF_BMSK                                  0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_CAF_SHFT                                     5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_SMCF_BMSK                                  0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_SMCF_SHFT                                    2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_USF_BMSK                                   0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSR_USF_SHFT                                     1U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_ADDR                        (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_OFFS                        (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                   31U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                      30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_CAF_SHFT                             5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_SMCF_SHFT                            2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSRRESTORE_USF_SHFT                             1U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_ADDR                         (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_OFFS                         (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                    31U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                       30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_PF_SHFT                               7U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_CAF_SHFT                              5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_SMCF_SHFT                             2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSRRESTORE_USF_SHFT                              1U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_ADDR                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x50U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_OFFS                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_RMSK                                0x132U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                        8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_NSATTR_SHFT                             5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                            4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR0_WNR_SHFT                                1U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_ADDR                            (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x50U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_OFFS                            (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_RMSK                                 0x132U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                         8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_NSATTR_SHFT                              5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_NSSTATE_SHFT                             4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR0_WNR_SHFT                                 1U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_ADDR                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x54U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_OFFS                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_RMSK                            0x101000fUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                   0x1000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                          24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                     0x10000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                          16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                      0xfU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                        0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_ADDR                            (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x54U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_OFFS                            (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_RMSK                             0x101000fUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                    0x1000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                           24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                      0x10000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                           16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                       0xfU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                         0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_ADDR                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x58U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_OFFS                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_ATID_SHFT                              24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_AVMID_SHFT                             16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_ABID_SHFT                              13U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_APID_SHFT                               8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SGFSYNDR2_AMID_SHFT                               0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_ADDR                            (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x58U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_OFFS                            (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_ATID_SHFT                               24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_AVMID_SHFT                              16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_ABID_SHFT                               13U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_APID_SHFT                                8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_AMID_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_GFSYNDR2_AMID_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x80U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x80U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_RMSK                                      0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_RWE_BMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_ADDR                          (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x90U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_OFFS                          (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_RMSK                                 0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                         0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_ADDR                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x90U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_OFFS                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_RMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                          0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_ADDR                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x9cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_OFFS                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x9cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_RMSK                           0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_VMIDMTACR_RWE_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x400U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x400U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_RMSK                                0xff70ff5UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_WACFG_SHFT                                 26U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_RACFG_SHFT                                 24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_SHCFG_SHFT                                 22U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_SMCFCFG_SHFT                               21U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_MTCFG_SHFT                                 20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_MEMATTR_SHFT                               16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_VMIDPNE_SHFT                               11U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_USFCFG_BMSK                             0x400U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_USFCFG_SHFT                                10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_GSE_BMSK                                0x200U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_GSE_SHFT                                    9U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_STALLD_BMSK                             0x100U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_STALLD_SHFT                                 8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                           6U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_GCFGFIE_SHFT                                5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_GCFGERE_SHFT                                4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_GFIE_BMSK                                 0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_GFIE_SHFT                                   2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR0_CLIENTPD_SHFT                               0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x408U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x408U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_RMSK                                     0x1fU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_BPVMID_BMSK                              0x1fU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSCR2_BPVMID_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x410U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x410U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_RMSK                               0x70000013UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPRCNSH_SHFT                               30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPRCISH_SHFT                               29U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPRCOSH_SHFT                               28U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                       4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSACR_BPREQPRIORITY_SHFT                          0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFAR0_ADDR                             (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x440U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFAR0_OFFS                             (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x440U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFAR0_RMSK                             0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFAR0_GFEA0_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_ADDR                              (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x448U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_OFFS                              (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x448U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_RMSK                              0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                         31U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_MULTI_CFG_SHFT                            30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_PF_BMSK                                 0x80U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_PF_SHFT                                    7U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_CAF_BMSK                                0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_CAF_SHFT                                   5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_SMCF_BMSK                                0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_SMCF_SHFT                                  2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_USF_BMSK                                 0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSR_USF_SHFT                                   1U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_ADDR                       (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x44cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_OFFS                       (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x44cU)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                  31U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                     30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_PF_SHFT                             7U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_CAF_SHFT                            5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                           2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSRRESTORE_USF_SHFT                            1U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_ADDR                          (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x450U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_OFFS                          (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x450U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_RMSK                               0x132U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                       8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                            5U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                           4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR0_WNR_SHFT                               1U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_ADDR                          (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x454U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_OFFS                          (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x454U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_RMSK                           0x101000fUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                  0x1000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                         24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                    0x10000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                         16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                     0xfU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                       0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_ADDR                          (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x458U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_OFFS                          (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x458U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_ATID_SHFT                             24U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_AVMID_SHFT                            16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_ABID_SHFT                             13U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_APID_SHFT                              8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xffU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSGFSYNDR2_AMID_SHFT                              0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_ADDR                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x480U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_OFFS                               (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x480U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_RMSK                                      0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_RWE_BMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_ADDR                         (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x490U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_OFFS                         (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x490U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_RMSK                                0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                        0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_ADDR                                 (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0x494U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_OFFS                                 (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0x494U)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_RMSK                                        0x7U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_ADDR)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_ADDR,m,v,HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_IN)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_CLKONOFFE_SHFT                                2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_BPMSACFG_BMSK                               0x2U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_BPMSACFG_SHFT                                 1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_MCR_BPSMSACFG_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_ADDR(n)                             (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_OFFS(n)                             (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_RMSK                                0x800f000fUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_MAXn                                        15U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_ADDR(n), HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_RMSK)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_INI(n))
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_VALID_BMSK                          0x80000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_VALID_SHFT                                  31U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_MASK_BMSK                              0xf0000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_MASK_SHFT                                   16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_ID_BMSK                                    0xfU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_SMRn_ID_SHFT                                      0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_ADDR(n)                            (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_OFFS(n)                            (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_RMSK                               0x30ff7b1fUL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_MAXn                                       15U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_ADDR(n), HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_RMSK)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_INI(n))
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                          28U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_WACFG_SHFT                                 22U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_RACFG_BMSK                           0x300000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_RACFG_SHFT                                 20U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_NSCFG_SHFT                                 18U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_TYPE_BMSK                             0x30000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_TYPE_SHFT                                  16U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_MEMATTR_SHFT                               12U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_MTCFG_BMSK                              0x800U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_MTCFG_SHFT                                 11U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_SHCFG_BMSK                              0x300U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_SHCFG_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_VMID_BMSK                                0x1fU
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_S2VRn_VMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_ADDR(n)                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE      + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_OFFS(n)                           (SAILSS_VMIDMT_2_VMIDMT_SMR_16_SSD0_SID4_MA1_REG_BASE_OFFS + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_RMSK                              0x70000013UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_MAXn                                      15U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_ADDR(n), HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_RMSK)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_INI(n))
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_RCNSH_SHFT                                30U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_RCISH_SHFT                                29U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_RCOSH_SHFT                                28U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_VMIDMT_2_VMIDMT_AS2VRn_REQPRIORITY_SHFT                           0U

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM
 *--------------------------------------------------------------------------*/

#define SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE                                  (SAILSS_CRYPTO0_CRYPTO_TOP_BASE      + 0x00000000U)
#define SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_SIZE                             0x1000U
#define SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_USED                             0xe40U
#define SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS                             0x00000000U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x0U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_RMSK                                0x3ff707f5UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_NSCFG_SHFT                                  28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_WACFG_BMSK                           0xc000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_WACFG_SHFT                                  26U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_RACFG_BMSK                           0x3000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_RACFG_SHFT                                  24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_SHCFG_SHFT                                  22U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_SMCFCFG_SHFT                                21U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_MTCFG_BMSK                            0x100000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_MTCFG_SHFT                                  20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_MEMATTR_SHFT                                16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_USFCFG_BMSK                              0x400U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_USFCFG_SHFT                                 10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GSE_BMSK                                 0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GSE_SHFT                                     9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_STALLD_BMSK                              0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_STALLD_SHFT                                  8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_TRANSIENTCFG_SHFT                            6U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GCFGFIE_SHFT                                 5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GCFGERE_BMSK                              0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GCFGERE_SHFT                                 4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GFIE_BMSK                                  0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_GFIE_SHFT                                    2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR0_CLIENTPD_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR                                 (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x0U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_OFFS                                 (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_RMSK                                  0xff70ff5UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_WACFG_BMSK                            0xc000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_WACFG_SHFT                                   26U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_RACFG_BMSK                            0x3000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_RACFG_SHFT                                   24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_SHCFG_BMSK                             0xc00000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_SHCFG_SHFT                                   22U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_SMCFCFG_SHFT                                 21U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_MTCFG_BMSK                             0x100000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_MTCFG_SHFT                                   20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_MEMATTR_BMSK                            0x70000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_MEMATTR_SHFT                                 16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_VMIDPNE_BMSK                              0x800U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_VMIDPNE_SHFT                                 11U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_USFCFG_BMSK                               0x400U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_USFCFG_SHFT                                  10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GSE_BMSK                                  0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GSE_SHFT                                      9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_STALLD_BMSK                               0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_STALLD_SHFT                                   8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_TRANSIENTCFG_SHFT                             6U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GCFGFIE_BMSK                               0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GCFGFIE_SHFT                                  5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GCFGERE_BMSK                               0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GCFGERE_SHFT                                  4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GFIE_BMSK                                   0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_GFIE_SHFT                                     2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_CLIENTPD_BMSK                               0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR0_CLIENTPD_SHFT                                 0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x4U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x4U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_RMSK                                 0x1001f00UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_GASRAE_SHFT                                 24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_NSNUMSMRGO_BMSK                         0x1f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR1_NSNUMSMRGO_SHFT                              8U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x8U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_RMSK                                      0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_BPVMID_BMSK                               0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SCR2_BPVMID_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR                                 (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x8U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_OFFS                                 (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_RMSK                                       0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_BPVMID_BMSK                                0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_CR2_BPVMID_SHFT                                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x10U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_RMSK                                0x70000013UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCNSH_SHFT                                30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCISH_SHFT                                29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPRCOSH_SHFT                                28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SACR_BPREQPRIORITY_SHFT                           0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR                                 (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x10U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_OFFS                                 (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_RMSK                                 0x70000013UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCNSH_SHFT                                 30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCISH_SHFT                                 29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPRCOSH_SHFT                                 28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                         4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_ACR_BPREQPRIORITY_SHFT                            0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x20U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_RMSK                               0x88001effUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_SES_BMSK                           0x80000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_SES_SHFT                                   31U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_SMS_BMSK                            0x8000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_SMS_SHFT                                   27U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_NUMSIDB_SHFT                                9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR0_NUMSMRG_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x20U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_RMSK                                 0x8001effUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_SMS_BMSK                             0x8000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_SMS_SHFT                                    27U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_NUMSIDB_SHFT                                 9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_NUMSMRG_BMSK                              0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR0_NUMSMRG_SHFT                                 0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x24U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_RMSK                                   0x9f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_SMCD_BMSK                              0x8000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_SMCD_SHFT                                  15U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_SSDTP_SHFT                                 12U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR1_NUMSSDNDX_SHFT                              8U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x24U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_RMSK                                    0x9f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_SMCD_BMSK                               0x8000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_SMCD_SHFT                                   15U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_SSDTP_BMSK                              0x1000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_SSDTP_SHFT                                  12U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR1_NUMSSDNDX_SHFT                               8U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x28U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_RMSK                                     0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_OAS_BMSK                                 0xf0U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_OAS_SHFT                                    4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_IAS_BMSK                                  0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR2_IAS_SHFT                                    0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x28U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_RMSK                                      0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_OAS_BMSK                                  0xf0U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_OAS_SHFT                                     4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_IAS_BMSK                                   0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR2_IAS_SHFT                                     0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x30U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_RMSK                               0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_MAJOR_SHFT                                 28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_MINOR_SHFT                                 16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_STEP_BMSK                              0xffffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR4_STEP_SHFT                                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x30U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_RMSK                                0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_MAJOR_SHFT                                  28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_MINOR_SHFT                                  16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_STEP_BMSK                               0xffffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR4_STEP_SHFT                                    0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x34U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_RMSK                                 0xff03ffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_NUMMSDRB_SHFT                              16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_MSAE_BMSK                               0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_MSAE_SHFT                                   9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_QRIBE_BMSK                              0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_QRIBE_SHFT                                  8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_NVMID_BMSK                               0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR5_NVMID_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x34U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_RMSK                                  0xff03ffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_NUMMSDRB_SHFT                               16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_MSAE_BMSK                                0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_MSAE_SHFT                                    9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_QRIBE_BMSK                               0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_QRIBE_SHFT                                   8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_NVMID_BMSK                                0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR5_NVMID_SHFT                                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_RMSK                                     0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_MAJOR_SHFT                                  4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_MINOR_BMSK                                0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SIDR7_MINOR_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_RMSK                                      0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_MAJOR_BMSK                                0xf0U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_MAJOR_SHFT                                   4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_MINOR_BMSK                                 0xfU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_IDR7_MINOR_SHFT                                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_ADDR                              (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x40U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_OFFS                              (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_RMSK                              0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFAR0_SGFEA0_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x40U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_RMSK                               0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFAR0_GFEA0_SHFT                                  0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x48U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_RMSK                               0xc0000026UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                          31U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_MULTI_CFG_SHFT                             30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_CAF_BMSK                                 0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_CAF_SHFT                                    5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_SMCF_BMSK                                 0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_SMCF_SHFT                                   2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_USF_BMSK                                  0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSR_USF_SHFT                                    1U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x48U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_OFFS                                (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_RMSK                                0xc00000a6UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_MULTI_CLIENT_SHFT                           31U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_MULTI_CFG_SHFT                              30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_PF_BMSK                                   0x80U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_PF_SHFT                                      7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_CAF_BMSK                                  0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_CAF_SHFT                                     5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_SMCF_BMSK                                  0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_SMCF_SHFT                                    2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_USF_BMSK                                   0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSR_USF_SHFT                                     1U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR                        (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_OFFS                        (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                   31U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                      30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_CAF_SHFT                             5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_SMCF_SHFT                            2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSRRESTORE_USF_SHFT                             1U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR                         (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_OFFS                         (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                    31U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                       30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_PF_SHFT                               7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_CAF_SHFT                              5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_SMCF_SHFT                             2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSRRESTORE_USF_SHFT                              1U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_ADDR                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x50U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_OFFS                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_RMSK                                0x132U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                        8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_NSATTR_SHFT                             5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                            4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR0_WNR_SHFT                                1U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_ADDR                            (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x50U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_OFFS                            (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_RMSK                                 0x132U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                         8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_NSATTR_SHFT                              5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_NSSTATE_SHFT                             4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR0_WNR_SHFT                                 1U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_ADDR                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x54U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_OFFS                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_RMSK                           0x1f1f001fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                  0x1f000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                          24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                    0x1f0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                          16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                     0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                        0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_ADDR                            (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x54U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_OFFS                            (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_RMSK                            0x1f1f001fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                   0x1f000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                           24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                     0x1f0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                           16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                      0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                         0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ADDR                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x58U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_OFFS                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ATID_SHFT                              24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_AVMID_SHFT                             16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_ABID_SHFT                              13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_APID_SHFT                               8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SGFSYNDR2_AMID_SHFT                               0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ADDR                            (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x58U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_OFFS                            (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ATID_SHFT                               24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_AVMID_SHFT                              16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_ABID_SHFT                               13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_APID_SHFT                                8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_AMID_BMSK                             0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_GFSYNDR2_AMID_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x80U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x80U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_RMSK                               0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_RWE_BMSK                           0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR                          (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x90U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_OFFS                          (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_RMSK                                 0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                         0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x90U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_OFFS                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_RMSK                                  0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                          0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x9cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_OFFS                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x9cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_RMSK                           0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_VMIDMTACR_RWE_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x400U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x400U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_RMSK                                0xff70ff5UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_WACFG_SHFT                                 26U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_RACFG_SHFT                                 24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_SHCFG_SHFT                                 22U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_SMCFCFG_SHFT                               21U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_MTCFG_SHFT                                 20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_MEMATTR_SHFT                               16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_VMIDPNE_SHFT                               11U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_USFCFG_BMSK                             0x400U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_USFCFG_SHFT                                10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GSE_BMSK                                0x200U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GSE_SHFT                                    9U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_STALLD_BMSK                             0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_STALLD_SHFT                                 8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                           6U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GCFGFIE_SHFT                                5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GCFGERE_SHFT                                4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GFIE_BMSK                                 0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_GFIE_SHFT                                   2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR0_CLIENTPD_SHFT                               0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x408U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x408U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_RMSK                                     0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_BPVMID_BMSK                              0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSCR2_BPVMID_SHFT                                 0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x410U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x410U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_RMSK                               0x70000013UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCNSH_SHFT                               30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCISH_SHFT                               29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPRCOSH_SHFT                               28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                       4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSACR_BPREQPRIORITY_SHFT                          0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_ADDR                             (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x440U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_OFFS                             (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x440U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_RMSK                             0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFAR0_GFEA0_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR                              (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x448U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_OFFS                              (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x448U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_RMSK                              0xc00000a6UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                         31U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_MULTI_CFG_SHFT                            30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_PF_BMSK                                 0x80U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_PF_SHFT                                    7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_CAF_BMSK                                0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_CAF_SHFT                                   5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_SMCF_BMSK                                0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_SMCF_SHFT                                  2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_USF_BMSK                                 0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSR_USF_SHFT                                   1U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR                       (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x44cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_OFFS                       (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x44cU)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                  31U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                     30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_PF_SHFT                             7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_CAF_SHFT                            5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                           2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSRRESTORE_USF_SHFT                            1U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_ADDR                          (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x450U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_OFFS                          (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x450U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_RMSK                               0x132U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                       8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                            5U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                           4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR0_WNR_SHFT                               1U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_ADDR                          (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x454U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_OFFS                          (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x454U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_RMSK                          0x1f1f001fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                 0x1f000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                         24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                   0x1f0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                         16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                    0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                       0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ADDR                          (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x458U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_OFFS                          (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x458U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ATID_SHFT                             24U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_AVMID_SHFT                            16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_ABID_SHFT                             13U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_APID_SHFT                              8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xffU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSGFSYNDR2_AMID_SHFT                              0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x480U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_OFFS                               (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x480U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_RMSK                                  0x1ffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_RWE_BMSK                              0x1ffffUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR                         (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x490U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_OFFS                         (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x490U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_RMSK                                0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                        0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR                                 (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0x494U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_OFFS                                 (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0x494U)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_RMSK                                        0x7U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_IN                    \
                in_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR, m)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR,v)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_ADDR,m,v,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_IN)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_CLKONOFFE_SHFT                                2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_BPMSACFG_BMSK                               0x2U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_BPMSACFG_SHFT                                 1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_MCR_BPSMSACFG_SHFT                                0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_OFFS(n)                             (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_RMSK                                0x801f001fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_MAXn                                        16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_VALID_BMSK                          0x80000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_VALID_SHFT                                  31U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_MASK_BMSK                             0x1f0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_MASK_SHFT                                   16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ID_BMSK                                   0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_SMRn_ID_SHFT                                      0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n)                            (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_OFFS(n)                            (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_RMSK                               0x30ff7b1fUL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MAXn                                       16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                          28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_WACFG_SHFT                                 22U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_RACFG_BMSK                           0x300000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_RACFG_SHFT                                 20U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_NSCFG_SHFT                                 18U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_TYPE_BMSK                             0x30000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_TYPE_SHFT                                  16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MEMATTR_SHFT                               12U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MTCFG_BMSK                              0x800U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_MTCFG_SHFT                                 11U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_SHCFG_BMSK                              0x300U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_SHCFG_SHFT                                  8U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_VMID_BMSK                                0x1fU
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_S2VRn_VMID_SHFT                                   0U

#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n)                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE      + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_OFFS(n)                           (SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_BAM_REG_BASE_OFFS + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RMSK                              0x70000013UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_MAXn                                      16U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n), HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RMSK)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_INI(n))
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCNSH_SHFT                                30U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCISH_SHFT                                29U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_RCOSH_SHFT                                28U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_CRYPTO0_CRYPTO_BAM_VMIDMT_AS2VRn_REQPRIORITY_SHFT                           0U

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40
 *--------------------------------------------------------------------------*/

#define SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE          (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_BASE      + 0x00000000U)
#define SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_SIZE     0x1000U
#define SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_USED     0xffcU
#define SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS     0x00000000U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x0U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_RMSK                                0x3ff707f5UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_NSCFG_BMSK                          0x30000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_NSCFG_SHFT                                  28U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_WACFG_BMSK                           0xc000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_WACFG_SHFT                                  26U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_RACFG_BMSK                           0x3000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_RACFG_SHFT                                  24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_SHCFG_BMSK                            0xc00000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_SHCFG_SHFT                                  22U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_SMCFCFG_BMSK                          0x200000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_SMCFCFG_SHFT                                21U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_MTCFG_BMSK                            0x100000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_MTCFG_SHFT                                  20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_MEMATTR_BMSK                           0x70000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_MEMATTR_SHFT                                16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_USFCFG_BMSK                              0x400U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_USFCFG_SHFT                                 10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_GSE_BMSK                                 0x200U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_GSE_SHFT                                     9U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_STALLD_BMSK                              0x100U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_STALLD_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_TRANSIENTCFG_BMSK                         0xc0U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_TRANSIENTCFG_SHFT                            6U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_GCFGFIE_BMSK                              0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_GCFGFIE_SHFT                                 5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_GCFGERE_BMSK                              0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_GCFGERE_SHFT                                 4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_GFIE_BMSK                                  0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_GFIE_SHFT                                    2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_CLIENTPD_BMSK                              0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR0_CLIENTPD_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_ADDR                                 (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x0U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_OFFS                                 (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x0U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_RMSK                                  0xff70ff5UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_WACFG_BMSK                            0xc000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_WACFG_SHFT                                   26U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_RACFG_BMSK                            0x3000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_RACFG_SHFT                                   24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_SHCFG_BMSK                             0xc00000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_SHCFG_SHFT                                   22U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_SMCFCFG_BMSK                           0x200000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_SMCFCFG_SHFT                                 21U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_MTCFG_BMSK                             0x100000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_MTCFG_SHFT                                   20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_MEMATTR_BMSK                            0x70000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_MEMATTR_SHFT                                 16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_VMIDPNE_BMSK                              0x800U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_VMIDPNE_SHFT                                 11U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_USFCFG_BMSK                               0x400U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_USFCFG_SHFT                                  10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_GSE_BMSK                                  0x200U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_GSE_SHFT                                      9U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_STALLD_BMSK                               0x100U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_STALLD_SHFT                                   8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_TRANSIENTCFG_BMSK                          0xc0U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_TRANSIENTCFG_SHFT                             6U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_GCFGFIE_BMSK                               0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_GCFGFIE_SHFT                                  5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_GCFGERE_BMSK                               0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_GCFGERE_SHFT                                  4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_GFIE_BMSK                                   0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_GFIE_SHFT                                     2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_CLIENTPD_BMSK                               0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR0_CLIENTPD_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x4U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x4U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_RMSK                                 0x100ff00UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_GASRAE_BMSK                          0x1000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_GASRAE_SHFT                                 24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_NSNUMSMRGO_BMSK                         0xff00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR1_NSNUMSMRGO_SHFT                              8U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x8U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_RMSK                                      0x1fU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_BPVMID_BMSK                               0x1fU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SCR2_BPVMID_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_ADDR                                 (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x8U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_OFFS                                 (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x8U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_RMSK                                       0x1fU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_BPVMID_BMSK                                0x1fU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_CR2_BPVMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x10U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_RMSK                                0x70000013UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPRCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPRCNSH_SHFT                                30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPRCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPRCISH_SHFT                                29U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPRCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPRCOSH_SHFT                                28U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPREQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPREQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPREQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SACR_BPREQPRIORITY_SHFT                           0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_ADDR                                 (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x10U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_OFFS                                 (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x10U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_RMSK                                 0x70000013UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPRCNSH_BMSK                         0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPRCNSH_SHFT                                 30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPRCISH_BMSK                         0x20000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPRCISH_SHFT                                 29U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPRCOSH_BMSK                         0x10000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPRCOSH_SHFT                                 28U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPREQPRIORITYCFG_BMSK                      0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPREQPRIORITYCFG_SHFT                         4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPREQPRIORITY_BMSK                          0x3U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_ACR_BPREQPRIORITY_SHFT                            0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x20U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_RMSK                               0x88001effUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_SES_BMSK                           0x80000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_SES_SHFT                                   31U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_SMS_BMSK                            0x8000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_SMS_SHFT                                   27U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_NUMSIDB_BMSK                           0x1e00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_NUMSIDB_SHFT                                9U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_NUMSMRG_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR0_NUMSMRG_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x20U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x20U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_RMSK                                 0x8001effUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_SMS_BMSK                             0x8000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_SMS_SHFT                                    27U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_NUMSIDB_BMSK                            0x1e00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_NUMSIDB_SHFT                                 9U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_NUMSMRG_BMSK                              0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR0_NUMSMRG_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x24U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_RMSK                                   0x9f00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_SMCD_BMSK                              0x8000U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_SMCD_SHFT                                  15U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_SSDTP_BMSK                             0x1000U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_SSDTP_SHFT                                 12U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_NUMSSDNDX_BMSK                          0xf00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR1_NUMSSDNDX_SHFT                              8U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x24U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x24U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_RMSK                                    0x9f00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_SMCD_BMSK                               0x8000U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_SMCD_SHFT                                   15U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_SSDTP_BMSK                              0x1000U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_SSDTP_SHFT                                  12U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_NUMSSDNDX_BMSK                           0xf00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR1_NUMSSDNDX_SHFT                               8U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x28U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_RMSK                                     0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_OAS_BMSK                                 0xf0U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_OAS_SHFT                                    4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_IAS_BMSK                                  0xfU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR2_IAS_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x28U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x28U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_RMSK                                      0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_OAS_BMSK                                  0xf0U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_OAS_SHFT                                     4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_IAS_BMSK                                   0xfU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR2_IAS_SHFT                                     0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x30U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_RMSK                               0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_MAJOR_BMSK                         0xf0000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_MAJOR_SHFT                                 28U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_MINOR_BMSK                          0xfff0000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_MINOR_SHFT                                 16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_STEP_BMSK                              0xffffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR4_STEP_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x30U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x30U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_RMSK                                0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_MAJOR_BMSK                          0xf0000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_MAJOR_SHFT                                  28U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_MINOR_BMSK                           0xfff0000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_MINOR_SHFT                                  16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_STEP_BMSK                               0xffffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR4_STEP_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x34U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_RMSK                                 0xff03ffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_NUMMSDRB_BMSK                        0xff0000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_NUMMSDRB_SHFT                              16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_MSAE_BMSK                               0x200U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_MSAE_SHFT                                   9U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_QRIBE_BMSK                              0x100U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_QRIBE_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_NVMID_BMSK                               0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR5_NVMID_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x34U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x34U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_RMSK                                  0xff03ffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_NUMMSDRB_BMSK                         0xff0000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_NUMMSDRB_SHFT                               16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_MSAE_BMSK                                0x200U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_MSAE_SHFT                                    9U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_QRIBE_BMSK                               0x100U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_QRIBE_SHFT                                   8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_NVMID_BMSK                                0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR5_NVMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_RMSK                                     0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_MAJOR_BMSK                               0xf0U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_MAJOR_SHFT                                  4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_MINOR_BMSK                                0xfU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SIDR7_MINOR_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x3cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x3cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_RMSK                                      0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_MAJOR_BMSK                                0xf0U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_MAJOR_SHFT                                   4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_MINOR_BMSK                                 0xfU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_IDR7_MINOR_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR0_ADDR                              (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x40U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR0_OFFS                              (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR0_RMSK                              0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR0_SGFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR0_SGFEA0_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR0_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x40U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR0_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x40U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR0_RMSK                               0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR0_GFEA0_BMSK                         0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR0_GFEA0_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR1_ADDR                              (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x44U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR1_OFFS                              (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x44U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR1_RMSK                                    0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR1_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR1_SGFEA1_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFAR1_SGFEA1_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR1_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x44U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR1_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x44U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR1_RMSK                                     0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR1_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR1_GFEA1_BMSK                               0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFAR1_GFEA1_SHFT                                  0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x48U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_RMSK                               0xc0000026UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_MULTI_CLIENT_BMSK                  0x80000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_MULTI_CLIENT_SHFT                          31U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_MULTI_CFG_BMSK                     0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_MULTI_CFG_SHFT                             30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_CAF_BMSK                                 0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_CAF_SHFT                                    5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_SMCF_BMSK                                 0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_SMCF_SHFT                                   2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_USF_BMSK                                  0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSR_USF_SHFT                                    1U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_ADDR                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x48U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_OFFS                                (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x48U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_RMSK                                0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_MULTI_CLIENT_BMSK                   0x80000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_MULTI_CLIENT_SHFT                           31U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_MULTI_CFG_BMSK                      0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_MULTI_CFG_SHFT                              30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_PF_BMSK                                   0x80U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_PF_SHFT                                      7U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_CAF_BMSK                                  0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_CAF_SHFT                                     5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_SMCF_BMSK                                  0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_SMCF_SHFT                                    2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_USF_BMSK                                   0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSR_USF_SHFT                                     1U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_ADDR                        (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_OFFS                        (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_RMSK                        0xc0000026UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_BMSK           0x80000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_MULTI_CLIENT_SHFT                   31U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_MULTI_CFG_BMSK              0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_MULTI_CFG_SHFT                      30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_CAF_BMSK                          0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_CAF_SHFT                             5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_SMCF_BMSK                          0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_SMCF_SHFT                            2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_USF_BMSK                           0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSRRESTORE_USF_SHFT                             1U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_ADDR                         (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x4cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_OFFS                         (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x4cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_RMSK                         0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_MULTI_CLIENT_BMSK            0x80000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_MULTI_CLIENT_SHFT                    31U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_MULTI_CFG_BMSK               0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_MULTI_CFG_SHFT                       30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_PF_BMSK                            0x80U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_PF_SHFT                               7U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_CAF_BMSK                           0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_CAF_SHFT                              5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_SMCF_BMSK                           0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_SMCF_SHFT                             2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_USF_BMSK                            0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSRRESTORE_USF_SHFT                              1U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_ADDR                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x50U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_OFFS                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_RMSK                                0x132U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_MSSSELFAUTH_BMSK                    0x100U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_MSSSELFAUTH_SHFT                        8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_NSATTR_BMSK                          0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_NSATTR_SHFT                             5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_NSSTATE_BMSK                         0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_NSSTATE_SHFT                            4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_WNR_BMSK                              0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR0_WNR_SHFT                                1U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_ADDR                            (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x50U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_OFFS                            (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x50U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_RMSK                                 0x132U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_MSSSELFAUTH_BMSK                     0x100U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_MSSSELFAUTH_SHFT                         8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_NSATTR_BMSK                           0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_NSATTR_SHFT                              5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_NSSTATE_BMSK                          0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_NSSTATE_SHFT                             4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_WNR_BMSK                               0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR0_WNR_SHFT                                 1U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_ADDR                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x54U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_OFFS                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_RMSK                            0x10100ffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_MSDINDEX_BMSK                   0x1000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_MSDINDEX_SHFT                          24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_SSDINDEX_BMSK                     0x10000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_SSDINDEX_SHFT                          16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_STREAMINDEX_BMSK                     0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR1_STREAMINDEX_SHFT                        0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_ADDR                            (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x54U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_OFFS                            (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x54U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_RMSK                             0x10100ffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_MSDINDEX_BMSK                    0x1000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_MSDINDEX_SHFT                           24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_SSDINDEX_BMSK                      0x10000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_SSDINDEX_SHFT                           16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_STREAMINDEX_BMSK                      0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR1_STREAMINDEX_SHFT                         0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_ADDR                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x58U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_OFFS                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_RMSK                           0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_ATID_BMSK                      0x3f000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_ATID_SHFT                              24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_AVMID_BMSK                       0x1f0000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_AVMID_SHFT                             16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_ABID_BMSK                          0xe000U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_ABID_SHFT                              13U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_APID_BMSK                          0x1f00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_APID_SHFT                               8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_AMID_BMSK                            0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SGFSYNDR2_AMID_SHFT                               0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_ADDR                            (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x58U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_OFFS                            (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x58U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_RMSK                            0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_ATID_BMSK                       0x3f000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_ATID_SHFT                               24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_AVMID_BMSK                        0x1f0000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_AVMID_SHFT                              16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_ABID_BMSK                           0xe000U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_ABID_SHFT                               13U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_APID_BMSK                           0x1f00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_APID_SHFT                                8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_AMID_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_GFSYNDR2_AMID_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x80U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x80U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_RMSK                                      0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_RWE_BMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_ADDR                          (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x90U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_OFFS                          (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_RMSK                                 0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_CLKONOFFE_BMSK                       0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTSCR0_CLKONOFFE_SHFT                         0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_ADDR                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x90U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_OFFS                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x90U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_RMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_CLKONOFFE_BMSK                        0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTCR0_CLKONOFFE_SHFT                          0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_ADDR                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x9cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_OFFS                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x9cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_RMSK                           0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_RWE_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_VMIDMTACR_RWE_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x400U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x400U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_RMSK                                0xff70ff5UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_WACFG_BMSK                          0xc000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_WACFG_SHFT                                 26U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_RACFG_BMSK                          0x3000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_RACFG_SHFT                                 24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_SHCFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_SHCFG_SHFT                                 22U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_SMCFCFG_BMSK                         0x200000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_SMCFCFG_SHFT                               21U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_MTCFG_BMSK                           0x100000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_MTCFG_SHFT                                 20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_MEMATTR_BMSK                          0x70000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_MEMATTR_SHFT                               16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_VMIDPNE_BMSK                            0x800U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_VMIDPNE_SHFT                               11U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_USFCFG_BMSK                             0x400U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_USFCFG_SHFT                                10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_GSE_BMSK                                0x200U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_GSE_SHFT                                    9U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_STALLD_BMSK                             0x100U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_STALLD_SHFT                                 8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_TRANSIENTCFG_BMSK                        0xc0U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_TRANSIENTCFG_SHFT                           6U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_GCFGFIE_BMSK                             0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_GCFGFIE_SHFT                                5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_GCFGERE_BMSK                             0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_GCFGERE_SHFT                                4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_GFIE_BMSK                                 0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_GFIE_SHFT                                   2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_CLIENTPD_BMSK                             0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR0_CLIENTPD_SHFT                               0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x408U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x408U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_RMSK                                     0x1fU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_BPVMID_BMSK                              0x1fU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSCR2_BPVMID_SHFT                                 0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x410U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x410U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_RMSK                               0x70000013UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPRCNSH_BMSK                       0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPRCNSH_SHFT                               30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPRCISH_BMSK                       0x20000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPRCISH_SHFT                               29U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPRCOSH_BMSK                       0x10000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPRCOSH_SHFT                               28U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPREQPRIORITYCFG_BMSK                    0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPREQPRIORITYCFG_SHFT                       4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPREQPRIORITY_BMSK                        0x3U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSACR_BPREQPRIORITY_SHFT                          0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR0_ADDR                             (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x440U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR0_OFFS                             (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x440U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR0_RMSK                             0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR0_GFEA0_BMSK                       0xffffffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR0_GFEA0_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR1_ADDR                             (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x444U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR1_OFFS                             (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x444U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR1_RMSK                                   0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR1_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR1_GFEA1_BMSK                             0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFAR1_GFEA1_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_ADDR                              (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x448U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_OFFS                              (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x448U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_RMSK                              0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_MULTI_CLIENT_BMSK                 0x80000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_MULTI_CLIENT_SHFT                         31U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_MULTI_CFG_BMSK                    0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_MULTI_CFG_SHFT                            30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_PF_BMSK                                 0x80U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_PF_SHFT                                    7U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_CAF_BMSK                                0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_CAF_SHFT                                   5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_SMCF_BMSK                                0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_SMCF_SHFT                                  2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_USF_BMSK                                 0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSR_USF_SHFT                                   1U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_ADDR                       (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x44cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_OFFS                       (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x44cU)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_RMSK                       0xc00000a6UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_BMSK          0x80000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_MULTI_CLIENT_SHFT                  31U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_MULTI_CFG_BMSK             0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_MULTI_CFG_SHFT                     30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_PF_BMSK                          0x80U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_PF_SHFT                             7U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_CAF_BMSK                         0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_CAF_SHFT                            5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_SMCF_BMSK                         0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_SMCF_SHFT                           2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_USF_BMSK                          0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSRRESTORE_USF_SHFT                            1U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_ADDR                          (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x450U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_OFFS                          (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x450U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_RMSK                               0x132U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_BMSK                   0x100U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_MSSSELFAUTH_SHFT                       8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_NSATTR_BMSK                         0x20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_NSATTR_SHFT                            5U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_NSSTATE_BMSK                        0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_NSSTATE_SHFT                           4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_WNR_BMSK                             0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR0_WNR_SHFT                               1U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_ADDR                          (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x454U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_OFFS                          (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x454U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_RMSK                           0x10100ffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_MSDINDEX_BMSK                  0x1000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_MSDINDEX_SHFT                         24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_SSDINDEX_BMSK                    0x10000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_SSDINDEX_SHFT                         16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_STREAMINDEX_BMSK                    0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR1_STREAMINDEX_SHFT                       0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_ADDR                          (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x458U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_OFFS                          (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x458U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_RMSK                          0x3f1fffffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_ATID_BMSK                     0x3f000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_ATID_SHFT                             24U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_AVMID_BMSK                      0x1f0000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_AVMID_SHFT                            16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_ABID_BMSK                         0xe000U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_ABID_SHFT                             13U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_APID_BMSK                         0x1f00U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_APID_SHFT                              8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_AMID_BMSK                           0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSGFSYNDR2_AMID_SHFT                              0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_ADDR                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x480U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_OFFS                               (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x480U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_RMSK                                      0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_RWE_BMSK                                  0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MSDR0_RWE_SHFT                                    0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_ADDR                         (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x490U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_OFFS                         (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x490U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_RMSK                                0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_CLKONOFFE_BMSK                      0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_NSVMIDMTCR0_CLKONOFFE_SHFT                        0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_ADDR                                 (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0x494U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_OFFS                                 (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0x494U)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_RMSK                                        0x7U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_IN                    \
                in_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_ADDR)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_ADDR, m)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_OUT(v)            \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_ADDR,v)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_ADDR,m,v,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_IN)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_CLKONOFFE_BMSK                              0x4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_CLKONOFFE_SHFT                                2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_BPMSACFG_BMSK                               0x2U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_BPMSACFG_SHFT                                 1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_BPSMSACFG_BMSK                              0x1U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_MCR_BPSMSACFG_SHFT                                0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_ADDR(n)                             (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_OFFS(n)                             (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0X800 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_RMSK                                0x80ff00ffUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_MAXn                                       127U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_ADDR(n), HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_RMSK)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_INI(n))
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_VALID_BMSK                          0x80000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_VALID_SHFT                                  31U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_MASK_BMSK                             0xff0000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_MASK_SHFT                                   16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_ID_BMSK                                   0xffU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_SMRn_ID_SHFT                                      0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_ADDR(n)                            (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_OFFS(n)                            (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0XC00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_RMSK                               0x30ff7b1fUL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_MAXn                                      127U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_ADDR(n), HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_RMSK)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_INI(n))
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_TRANSIENTCFG_BMSK                  0x30000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_TRANSIENTCFG_SHFT                          28U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_WACFG_BMSK                           0xc00000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_WACFG_SHFT                                 22U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_RACFG_BMSK                           0x300000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_RACFG_SHFT                                 20U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_NSCFG_BMSK                            0xc0000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_NSCFG_SHFT                                 18U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_TYPE_BMSK                             0x30000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_TYPE_SHFT                                  16U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_MEMATTR_BMSK                           0x7000U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_MEMATTR_SHFT                               12U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_MTCFG_BMSK                              0x800U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_MTCFG_SHFT                                 11U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_SHCFG_BMSK                              0x300U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_SHCFG_SHFT                                  8U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_VMID_BMSK                                0x1fU
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_S2VRn_VMID_SHFT                                   0U

#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_ADDR(n)                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE      + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_OFFS(n)                           (SAILSS_VMIDMT_NOC_VMIDMT_SMR_128_SSD0_SID8_MA1_QR_40_REG_BASE_OFFS + 0XE00 + (0x4*(n)))
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_RMSK                              0x70000013UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_MAXn                                     127U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_ADDR(n), HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_RMSK)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_ADDR(n), mask)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_ADDR(n),val)
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_ADDR(n),mask,val,HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_INI(n))
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_RCNSH_BMSK                        0x40000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_RCNSH_SHFT                                30U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_RCISH_BMSK                        0x20000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_RCISH_SHFT                                29U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_RCOSH_BMSK                        0x10000000UL
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_RCOSH_SHFT                                28U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_REQPRIORITYCFG_BMSK                     0x10U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_REQPRIORITYCFG_SHFT                        4U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_REQPRIORITY_BMSK                         0x3U
#define HWIO_SAILSS_VMIDMT_NOC_VMIDMT_AS2VRn_REQPRIORITY_SHFT                           0U


#endif /* HALVMIDMTHWIOTARGET_H */
