#ifndef G_SAIL_TO_MD_LLC_BROADCAST_DRP_HWIO_H
#define G_SAIL_TO_MD_LLC_BROADCAST_DRP_HWIO_H
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_LLC_BROADCAST_DRP_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        MonacoAU [monacoau_v1.0_p3q3r53_MTO_rpm]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_LLC_BROADCAST_DRP


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_LLC_BROADCAST_DRP_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_LLC_BROADCAST_DRP'],
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
 * MODULE: SAIL_TO_MD_LLC_BROADCAST_DRP
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE                                                                        (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x09a50000UL)
#define SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_SIZE                                                                   0x6000U
#define SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_USED                                                                   0x4008U
#define SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS                                                                   0x09a50000UL

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_RMSK                                                    0xff00ff31UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_SB_ERROR_THRESHOLD_BMSK                                 0xff000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_SB_ERROR_THRESHOLD_SHFT                                         24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_SB_ERROR_DEBUG_EVENT_THRESHOLD_BIT_BMSK                     0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_SB_ERROR_DEBUG_EVENT_THRESHOLD_BIT_SHFT                          8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_DB_QDSS_EVENT_LOGGING_EN_BMSK                                 0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_DB_QDSS_EVENT_LOGGING_EN_SHFT                                    5U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_SB_QDSS_EVENT_LOGGING_EN_BMSK                                 0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_SB_QDSS_EVENT_LOGGING_EN_SHFT                                    4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_DATA_RAM_ECC_DISABLE_BMSK                                      0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CFG_DATA_RAM_ECC_DISABLE_SHFT                                        0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CNTR_CLEAR_ADDR                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CNTR_CLEAR_OFFS                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CNTR_CLEAR_RMSK                                                    0x3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CNTR_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CNTR_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CNTR_CLEAR_DB_COUNTER_CLEAR_BMSK                                   0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CNTR_CLEAR_DB_COUNTER_CLEAR_SHFT                                     1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CNTR_CLEAR_SB_COUNTER_CLEAR_BMSK                                   0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_CNTR_CLEAR_SB_COUNTER_CLEAR_SHFT                                     0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x10U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x10U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_RMSK                                            0xe0000003UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_DOWN_COUNTER_EN_BMSK                            0x80000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_DOWN_COUNTER_EN_SHFT                                    31U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_REPEAT_BMSK                                     0x40000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_REPEAT_SHFT                                             30U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_INJECT_ERROR_ON_ACCESS_BMSK                     0x20000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_INJECT_ERROR_ON_ACCESS_SHFT                             29U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_DB_ERR_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_DB_ERR_SHFT                                              1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_SB_ERR_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_0_SB_ERR_SHFT                                              0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x14U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x14U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_DOWN_COUNTER_VAL_BMSK                           0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_ECC_ERROR_INJECTION_1_DOWN_COUNTER_VAL_SHFT                                    0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_ADDR                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_OFFS                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_RMSK                                                        0x3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_DB_ECC_ERROR_BMSK                                           0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_DB_ECC_ERROR_SHFT                                             1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_SB_ECC_ERROR_BMSK                                           0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_STATUS_SB_ECC_ERROR_SHFT                                             0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_CLEAR_ADDR                                                  (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x28U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_CLEAR_OFFS                                                  (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x28U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_CLEAR_RMSK                                                         0x3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_CLEAR_DB_ECC_ERROR_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_CLEAR_DB_ECC_ERROR_SHFT                                              1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_CLEAR_SB_ECC_ERROR_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_CLEAR_SB_ECC_ERROR_SHFT                                              0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_ADDR                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_OFFS                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_RMSK                                                        0x3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_DB_ECC_ERROR_BMSK                                           0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_DB_ECC_ERROR_SHFT                                             1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_SB_ECC_ERROR_BMSK                                           0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_INTERRUPT_ENABLE_SB_ECC_ERROR_SHFT                                             0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x1000U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x1000U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_RMSK                                                      0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_PCB_EARLY_HINT_INV_MATCH_BMSK                             0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_PCB_EARLY_HINT_INV_MATCH_SHFT                               3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_PCB_WAKEUP_INV_MATCH_BMSK                                 0x4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_PCB_WAKEUP_INV_MATCH_SHFT                                   2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_PCB_SLP_NRET_INV_MATCH_BMSK                               0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_PCB_SLP_NRET_INV_MATCH_SHFT                                 1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_PCB_SLP_RET_INV_MATCH_BMSK                                0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG0_PCB_SLP_RET_INV_MATCH_SHFT                                  0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x1004U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x1004U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_RMSK                                               0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_PCB_EARLY_HINT_MASK_BMSK                           0xff000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_PCB_EARLY_HINT_MASK_SHFT                                   24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_PCB_WAKEUP_MASK_BMSK                                 0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_PCB_WAKEUP_MASK_SHFT                                       16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_PCB_SLP_NRET_MASK_BMSK                                 0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_PCB_SLP_NRET_MASK_SHFT                                      8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_PCB_SLP_RET_MASK_BMSK                                    0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG1_PCB_SLP_RET_MASK_SHFT                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x1008U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x1008U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_RMSK                                                      0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_PCB_EARLY_HINT_INV_MATCH_BMSK                             0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_PCB_EARLY_HINT_INV_MATCH_SHFT                               3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_PCB_WAKEUP_INV_MATCH_BMSK                                 0x4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_PCB_WAKEUP_INV_MATCH_SHFT                                   2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_PCB_SLP_NRET_INV_MATCH_BMSK                               0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_PCB_SLP_NRET_INV_MATCH_SHFT                                 1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_PCB_SLP_RET_INV_MATCH_BMSK                                0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG0_PCB_SLP_RET_INV_MATCH_SHFT                                  0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x100cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x100cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_RMSK                                               0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_PCB_EARLY_HINT_MASK_BMSK                           0xff000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_PCB_EARLY_HINT_MASK_SHFT                                   24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_PCB_WAKEUP_MASK_BMSK                                 0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_PCB_WAKEUP_MASK_SHFT                                       16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_PCB_SLP_NRET_MASK_BMSK                                 0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_PCB_SLP_NRET_MASK_SHFT                                      8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_PCB_SLP_RET_MASK_BMSK                                    0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG1_PCB_SLP_RET_MASK_SHFT                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_ADDR(n)                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0X1010 + (0x4*(n)))
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_OFFS(n)                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0X1010 + (0x4*(n)))
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_RMSK                                                 0x8001007fUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_MAXn                                                         15U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_INI(n)                \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_ADDR(n), HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_RMSK)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_INMI(n,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_ADDR(n), mask)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_OUTI(n,val)        \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_ADDR(n),val)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_ADDR(n),mask,val,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_INI(n))
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_FILTER_EN_BMSK                                       0x80000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_FILTER_EN_SHFT                                               31U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_FILTER_SEL_BMSK                                         0x10000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_FILTER_SEL_SHFT                                              16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_EVENT_SEL_BMSK                                             0x7fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_EVENT_n_CFG_EVENT_SEL_SHFT                                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_ADDR                                                         (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x1050U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_OFFS                                                         (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x1050U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_RMSK                                                             0xff01U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_BEAT_SCALING_BMSK                                                0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_BEAT_SCALING_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_PROF_EN_BMSK                                                        0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_CFG_PROF_EN_SHFT                                                          0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x1054U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x1054U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_RMSK                                                            0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_FERC_RD_BEAT_OVERFLOW_BMSK                                      0x80U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_FERC_RD_BEAT_OVERFLOW_SHFT                                         7U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_FEWC_RD_BEAT_OVERFLOW_BMSK                                      0x40U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_FEWC_RD_BEAT_OVERFLOW_SHFT                                         6U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_BIST_RD_BEAT_OVERFLOW_BMSK                                      0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_BIST_RD_BEAT_OVERFLOW_SHFT                                         5U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_EVICT_RD_BEAT_OVERFLOW_BMSK                                     0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_EVICT_RD_BEAT_OVERFLOW_SHFT                                        4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_BERC_WR_BEAT_OVERFLOW_BMSK                                       0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_BERC_WR_BEAT_OVERFLOW_SHFT                                         3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_FEWC_WR_BEAT_OVERFLOW_BMSK                                       0x4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_FEWC_WR_BEAT_OVERFLOW_SHFT                                         2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_BIST_WR_BEAT_OVERFLOW_BMSK                                       0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_BIST_WR_BEAT_OVERFLOW_SHFT                                         1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_DRIE_WR_BEAT_OVERFLOW_BMSK                                       0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_STATUS_DRIE_WR_BEAT_OVERFLOW_SHFT                                         0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x1060U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x1060U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_RMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_PCB_IDLE_INV_MATCH_BMSK                                   0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG2_PCB_IDLE_INV_MATCH_SHFT                                     0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x1064U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x1064U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_RMSK                                                     0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_PCB_IDLE_MASK_BMSK                                       0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_0_CFG3_PCB_IDLE_MASK_SHFT                                          0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x1068U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x1068U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_RMSK                                                      0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_PCB_IDLE_INV_MATCH_BMSK                                   0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG2_PCB_IDLE_INV_MATCH_SHFT                                     0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_ADDR                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x106cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_OFFS                                               (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x106cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_RMSK                                                     0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_PCB_IDLE_MASK_BMSK                                       0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PROF_FILTER_1_CFG3_PCB_IDLE_MASK_SHFT                                          0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_ADDR                                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2000U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_OFFS                                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2000U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_RMSK                                                                 0x1111U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_FEWC_STR_FWD_EN_BMSK                                                 0x1000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_FEWC_STR_FWD_EN_SHFT                                                     12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_RAMC_BANK_ARB_PRIORITY_RR_EN_BMSK                                     0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_RAMC_BANK_ARB_PRIORITY_RR_EN_SHFT                                         8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_WR_ARB_PRIORITY_RR_EN_BMSK                                             0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_WR_ARB_PRIORITY_RR_EN_SHFT                                                4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_RD_ARB_PRIORITY_RR_EN_BMSK                                              0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG1_RD_ARB_PRIORITY_RR_EN_SHFT                                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_ADDR                                                       (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2004U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_OFFS                                                       (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2004U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RMSK                                                       0x55d5555fUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_DEBUG_CLK_EN_BMSK                                          0x40000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_DEBUG_CLK_EN_SHFT                                                  30U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_PROF_CLK_EN_BMSK                                           0x10000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_PROF_CLK_EN_SHFT                                                   28U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_ERROR_LOG_CLK_EN_BMSK                                       0x4000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_ERROR_LOG_CLK_EN_SHFT                                              26U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_DCRSW_CLK_EN_BMSK                                           0x1000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_DCRSW_CLK_EN_SHFT                                                  24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_LB_CLK_EN_BMSK                                               0x800000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_LB_CLK_EN_SHFT                                                     23U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_SLP_CTRL_CLK_EN_BMSK                                         0x400000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_SLP_CTRL_CLK_EN_SHFT                                               22U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_EVICT_CMD_DPG_CLK_EN_BMSK                                    0x100000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_EVICT_CMD_DPG_CLK_EN_SHFT                                          20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_EVICT_DFIFO_CLK_EN_BMSK                                0x40000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_EVICT_DFIFO_CLK_EN_SHFT                                     18U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_FEWC_DFIFO_CLK_EN_BMSK                                 0x10000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_FEWC_DFIFO_CLK_EN_SHFT                                      16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_FERC_DFIFO_CLK_EN_BMSK                                  0x4000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_FERC_DFIFO_CLK_EN_SHFT                                      14U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_EVICT_CFIFO_CLK_EN_BMSK                                 0x1000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_EVICT_CFIFO_CLK_EN_SHFT                                     12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_FEWC_CFIFO_CLK_EN_BMSK                                   0x400U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_FEWC_CFIFO_CLK_EN_SHFT                                      10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_FERC_CFIFO_CLK_EN_BMSK                                   0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RDPROC_FERC_CFIFO_CLK_EN_SHFT                                       8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_RD_CHUNKCTRL_FIFO_CLK_EN_BMSK                               0x40U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_RD_CHUNKCTRL_FIFO_CLK_EN_SHFT                                  6U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_ALL_BANK_CLK_EN_BMSK                                        0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_ALL_BANK_CLK_EN_SHFT                                           4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_BANK3_CLK_EN_BMSK                                            0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_BANK3_CLK_EN_SHFT                                              3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_BANK2_CLK_EN_BMSK                                            0x4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_BANK2_CLK_EN_SHFT                                              2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_BANK1_CLK_EN_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_BANK1_CLK_EN_SHFT                                              1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_BANK0_CLK_EN_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CLK_EN_CFG_RAMC_BANK0_CLK_EN_SHFT                                              0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_ADDR                                                         (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2008U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_OFFS                                                         (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2008U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_RMSK                                                           0x751311UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_LATENCY_RED_CNTR_VALUE_BMSK                                    0x700000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_LATENCY_RED_CNTR_VALUE_SHFT                                          20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_LATENCY_RED_ENABLE_BMSK                                         0x40000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_LATENCY_RED_ENABLE_SHFT                                              18U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_DISABLE_DYNAMIC_ECC_PIPELINE_BMSK                               0x10000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_DISABLE_DYNAMIC_ECC_PIPELINE_SHFT                                    16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_GATE_FEWC_WR_ON_LFILL_EN_BMSK                                    0x1000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_GATE_FEWC_WR_ON_LFILL_EN_SHFT                                        12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_EVICT_BUFFER_STR_FWD_EN_BMSK                                      0x200U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_EVICT_BUFFER_STR_FWD_EN_SHFT                                          9U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_EVICT_BUFFER_PRIORITY_EN_BMSK                                     0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_EVICT_BUFFER_PRIORITY_EN_SHFT                                         8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_EVICT_CMD_DPG_EN_BMSK                                              0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_EVICT_CMD_DPG_EN_SHFT                                                 4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_GATE_RD_ON_LFILL_CONFLICT_EN_BMSK                                   0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_QOS_CTRL_GATE_RD_ON_LFILL_CONFLICT_EN_SHFT                                     0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x200cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x200cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_RMSK                                                      0xffff000fUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_ARB_DEBUG_SELECT_BMSK                                     0xffff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_ARB_DEBUG_SELECT_SHFT                                             16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_DEBUG_SELECT_BMSK                                                0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL0_DEBUG_SELECT_SHFT                                                  0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2010U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2010U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_RMSK                                                      0x80ffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_INTERFACE_VALID_READY_FLOP_EN_BMSK                        0x80000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_INTERFACE_VALID_READY_FLOP_EN_SHFT                                31U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_ACTIVE_HW_EVENT_PCB_EN_BMSK                                 0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_ACTIVE_HW_EVENT_PCB_EN_SHFT                                       16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_NRET_SLP_HW_EVENT_PCB_EN_BMSK                                 0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_NRET_SLP_HW_EVENT_PCB_EN_SHFT                                      8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_RET_SLP_HW_EVENT_PCB_EN_BMSK                                    0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DEBUG_CTRL1_RET_SLP_HW_EVENT_PCB_EN_SHFT                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2014U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2014U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_RMSK                                                      0xf0fffff1UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_WT_BMSK                                                   0x80000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_WT_SHFT                                                           31U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_WB_BMSK                                                   0x40000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_WB_SHFT                                                           30U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_RA_BMSK                                                   0x20000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_RA_SHFT                                                           29U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_WA_BMSK                                                   0x10000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_WA_SHFT                                                           28U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_NUM_SETS_BMSK                                               0xfff000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_NUM_SETS_SHFT                                                     12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_ASSOCIATIVITY_BMSK                                             0xff0U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_ASSOCIATIVITY_SHFT                                                 4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_ASSOCIATIVITY_ASSOCIATIVITY_8_WAY_FVAL                           0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_ASSOCIATIVITY_ASSOCIATIVITY_12_WAY_FVAL                          0xcU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_ASSOCIATIVITY_ASSOCIATIVITY_16_WAY_FVAL                         0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_ASSOCIATIVITY_ASSOCIATIVITY_32_WAY_FVAL                         0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_LINE_SIZE_BMSK                                                   0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_LINE_SIZE_SHFT                                                     0U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_LINE_SIZE_CL_SIZE_64_BYTES_FVAL                                  0x0U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SRAM_STATUS_LINE_SIZE_CL_SIZE_128_BYTES_FVAL                                 0x1U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_ADDR                                                (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2018U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_OFFS                                                (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2018U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_RMSK                                                     0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_LCPB_EVICT_RD_DATA_FIFO_EMPTY_BMSK                       0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_LCPB_EVICT_RD_DATA_FIFO_EMPTY_SHFT                           8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_LCPB_EVICT_RD_CMD_FIFO_EMPTY_BMSK                         0x80U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_LCPB_EVICT_RD_CMD_FIFO_EMPTY_SHFT                            7U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_EVICT_RD_DATA_FIFO_EMPTY_BMSK                             0x40U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_EVICT_RD_DATA_FIFO_EMPTY_SHFT                                6U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_EVICT_RD_CMD_FIFO_EMPTY_BMSK                              0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_EVICT_RD_CMD_FIFO_EMPTY_SHFT                                 5U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_FEWC_RD_DATA_FIFO_EMPTY_BMSK                              0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_FEWC_RD_DATA_FIFO_EMPTY_SHFT                                 4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_FEWC_RD_CMD_FIFO_EMPTY_BMSK                                0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_FEWC_RD_CMD_FIFO_EMPTY_SHFT                                  3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_FERC_RD_DATA_FIFO_EMPTY_BMSK                               0x4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_FERC_RD_DATA_FIFO_EMPTY_SHFT                                 2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_FERC_RD_CMD_FIFO_EMPTY_BMSK                                0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_FERC_RD_CMD_FIFO_EMPTY_SHFT                                  1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_RD_CHUNKCTRL_FIFO_EMPTY_BMSK                               0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_EMPTY_STATUS_RD_CHUNKCTRL_FIFO_EMPTY_SHFT                                 0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_ADDR                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x201cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_OFFS                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x201cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_RMSK                                                      0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_LCPB_EVICT_RD_DATA_FIFO_FULL_BMSK                         0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_LCPB_EVICT_RD_DATA_FIFO_FULL_SHFT                             8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_LCPB_EVICT_RD_CMD_FIFO_FULL_BMSK                           0x80U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_LCPB_EVICT_RD_CMD_FIFO_FULL_SHFT                              7U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_EVICT_RD_DATA_FIFO_FULL_BMSK                               0x40U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_EVICT_RD_DATA_FIFO_FULL_SHFT                                  6U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_EVICT_RD_CMD_FIFO_FULL_BMSK                                0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_EVICT_RD_CMD_FIFO_FULL_SHFT                                   5U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_FEWC_RD_DATA_FIFO_FULL_BMSK                                0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_FEWC_RD_DATA_FIFO_FULL_SHFT                                   4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_FEWC_RD_CMD_FIFO_FULL_BMSK                                  0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_FEWC_RD_CMD_FIFO_FULL_SHFT                                    3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_FERC_RD_DATA_FIFO_FULL_BMSK                                 0x4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_FERC_RD_DATA_FIFO_FULL_SHFT                                   2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_FERC_RD_CMD_FIFO_FULL_BMSK                                  0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_FERC_RD_CMD_FIFO_FULL_SHFT                                    1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_RD_CHUNKCTRL_FIFO_FULL_BMSK                                 0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_FIFO_FULL_STATUS_RD_CHUNKCTRL_FIFO_FULL_SHFT                                   0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2028U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2028U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_RMSK                                                    0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB7_BMSK                                               0xf0000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB7_SHFT                                                       28U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB6_BMSK                                                0xf000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB6_SHFT                                                       24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB5_BMSK                                                 0xf00000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB5_SHFT                                                       20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB4_BMSK                                                  0xf0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB4_SHFT                                                       16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB3_BMSK                                                   0xf000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB3_SHFT                                                       12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB2_BMSK                                                    0xf00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB2_SHFT                                                        8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB1_BMSK                                                     0xf0U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB1_SHFT                                                        4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB0_BMSK                                                      0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCBSLP_STATUS_PCB0_SHFT                                                        0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_ADDR                                                   (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x202cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_OFFS                                                   (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x202cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_RMSK                                                       0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_SLEEP_STATUS_BMSK                                          0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_SLEEP_STATUS_SHFT                                               8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_WAKEUP_STATUS_BMSK                                           0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_STATUS_WAKEUP_STATUS_SHFT                                              0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_0_ADDR                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2030U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_0_OFFS                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2030U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_0_RMSK                                             0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_0_DATA_BMSK                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_0_DATA_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_1_ADDR                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2034U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_1_OFFS                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2034U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_1_RMSK                                             0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_1_DATA_BMSK                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_1_DATA_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_2_ADDR                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2038U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_2_OFFS                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2038U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_2_RMSK                                             0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_2_DATA_BMSK                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_2_DATA_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_3_ADDR                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x203cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_3_OFFS                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x203cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_3_RMSK                                             0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_3_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_3_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_3_DATA_BMSK                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_DATA_CAPTURE_3_DATA_SHFT                                                 0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_ECC_CAPTURE_ADDR                                                (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2040U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_ECC_CAPTURE_OFFS                                                (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2040U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_ECC_CAPTURE_RMSK                                                     0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_ECC_CAPTURE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_ECC_CAPTURE_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_ECC_CAPTURE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_ECC_CAPTURE_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_ECC_CAPTURE_ECC_BMSK                                                 0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DCRSW_ECC_CAPTURE_ECC_SHFT                                                     0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2044U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2044U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_WAYS_DB_ERROR_OCCURRED_BMSK                     0xffff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_WAYS_DB_ERROR_OCCURRED_SHFT                             16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_WAYS_SB_ERROR_OCCURRED_BMSK                         0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS0_WAYS_SB_ERROR_OCCURRED_SHFT                              0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2048U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2048U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_RMSK                                              0xff001fUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_SB_ERROR_COUNTER_BMSK                             0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_SB_ERROR_COUNTER_SHFT                                   16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_DB_ERROR_COUNTER_BMSK                                 0x1fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_ERROR_STATUS1_DB_ERROR_COUNTER_SHFT                                    0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x204cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x204cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_RMSK                                               0x73ff00fUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_BLK_OFFSET_BMSK                                    0x7000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_BLK_OFFSET_SHFT                                           24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_SET_NDX_BMSK                                        0x3ff000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_SET_NDX_SHFT                                              12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_WAY_NDX_BMSK                                             0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN0_WAY_NDX_SHFT                                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN1_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2050U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN1_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2050U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN1_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN1_UNCORRECTED_DATA_31_0_BMSK                        0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN1_UNCORRECTED_DATA_31_0_SHFT                                 0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN2_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2054U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN2_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2054U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN2_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN2_UNCORRECTED_DATA_63_32_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN2_UNCORRECTED_DATA_63_32_SHFT                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN3_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2058U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN3_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2058U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN3_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN3_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN3_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN3_UNCORRECTED_DATA_95_64_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN3_UNCORRECTED_DATA_95_64_SHFT                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN4_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x205cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN4_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x205cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN4_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN4_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN4_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN4_UNCORRECTED_DATA_127_96_BMSK                      0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN4_UNCORRECTED_DATA_127_96_SHFT                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN5_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2060U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN5_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2060U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN5_RMSK                                                   0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN5_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN5_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN5_UNCORRECTED_PARITY_BITS_BMSK                           0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN5_UNCORRECTED_PARITY_BITS_SHFT                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN6_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2064U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN6_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2064U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN6_RMSK                                              0x3fffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN6_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN6_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN6_ADDRESS_BMSK                                      0x3fffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN6_ADDRESS_SHFT                                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN7_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2068U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN7_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2068U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN7_RMSK                                                  0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN7_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN7_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN7_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN7_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN7_AMID_BMSK                                             0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_SB_ERR_SYN7_AMID_SHFT                                                  0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2070U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2070U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_RMSK                                               0x73ff00fUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_BLK_OFFSET_BMSK                                    0x7000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_BLK_OFFSET_SHFT                                           24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_SET_NDX_BMSK                                        0x3ff000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_SET_NDX_SHFT                                              12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_WAY_NDX_BMSK                                             0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN0_WAY_NDX_SHFT                                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN1_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2074U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN1_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2074U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN1_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN1_UNCORRECTED_DATA_31_0_BMSK                        0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN1_UNCORRECTED_DATA_31_0_SHFT                                 0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN2_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2078U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN2_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2078U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN2_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN2_UNCORRECTED_DATA_63_32_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN2_UNCORRECTED_DATA_63_32_SHFT                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN3_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x207cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN3_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x207cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN3_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN3_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN3_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN3_UNCORRECTED_DATA_95_64_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN3_UNCORRECTED_DATA_95_64_SHFT                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN4_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2080U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN4_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2080U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN4_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN4_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN4_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN4_UNCORRECTED_DATA_127_96_BMSK                      0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN4_UNCORRECTED_DATA_127_96_SHFT                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN5_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2084U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN5_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2084U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN5_RMSK                                                   0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN5_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN5_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN5_UNCORRECTED_PARITY_BITS_BMSK                           0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN5_UNCORRECTED_PARITY_BITS_SHFT                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN6_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2088U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN6_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2088U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN6_RMSK                                              0x3fffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN6_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN6_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN6_ADDRESS_BMSK                                      0x3fffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN6_ADDRESS_SHFT                                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN7_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x208cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN7_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x208cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN7_RMSK                                                  0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN7_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN7_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN7_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN7_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN7_AMID_BMSK                                             0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH0_ECC_DB_ERR_SYN7_AMID_SHFT                                                  0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2098U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2098U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_RMSK                                                         0xfffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_WAKEUP_IN_PROGRESS_BMSK                                      0x800U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_WAKEUP_IN_PROGRESS_SHFT                                         11U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_WAKEUP_PCB_INDEX_BMSK                                        0x700U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_WAKEUP_PCB_INDEX_SHFT                                            8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_SLP_IN_PROGRESS_BMSK                                          0x80U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_SLP_IN_PROGRESS_SHFT                                             7U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_SLP_PCB_INDEX_BMSK                                            0x70U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_SLP_PCB_INDEX_SHFT                                               4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_RAMSLP_FSM_CURR_STATE_BMSK                                     0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAMSLP_STATUS_RAMSLP_FSM_CURR_STATE_SHFT                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_STATUS_ADDR                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20a0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_STATUS_OFFS                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20a0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_STATUS_RMSK                                                       0x7fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_STATUS_INTERNAL_DEBUG_EVENTS_BMSK                                 0x7fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_STATUS_INTERNAL_DEBUG_EVENTS_SHFT                                    0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_CLEAR_ADDR                                                  (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20a8U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_CLEAR_OFFS                                                  (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20a8U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_CLEAR_RMSK                                                        0x7fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_CLEAR_INTERNAL_DEBUG_EVENTS_BMSK                                  0x7fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_CLEAR_INTERNAL_DEBUG_EVENTS_SHFT                                     0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20acU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20acU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_RMSK                                                          0x7fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_INTERNAL_DEBUG_EVENTS_BMSK                                    0x7fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DBG_EVENT_FWD_INTERNAL_DEBUG_EVENTS_SHFT                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_ADDR                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20b0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_OFFS                                                 (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20b0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_RMSK                                                      0x11fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_LB_RESTRICT_SINGLE_ACCESS_BMSK                            0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_LB_RESTRICT_SINGLE_ACCESS_SHFT                                8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_LB_THROTTLE_EN_BMSK                                        0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_LB_THROTTLE_EN_SHFT                                           4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_LB_THROTTLE_CYCLES_BMSK                                     0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LB_THROTTLE_CTRL_LB_THROTTLE_CYCLES_SHFT                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_PWR_STATUS_ADDR                                                   (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20b4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_PWR_STATUS_OFFS                                                   (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20b4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_PWR_STATUS_RMSK                                                       0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_PWR_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_PWR_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_PWR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_PWR_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_PWR_STATUS_PCB_PWR_STATUS_BMSK                                        0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_PWR_STATUS_PCB_PWR_STATUS_SHFT                                             0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_ADDR                                                  (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20c0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_OFFS                                                  (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20c0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_RMSK                                                         0x3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_PRE_ARES_SEEN_BMSK                                           0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_PRE_ARES_SEEN_SHFT                                             1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_PRE_ARES_DONE_BMSK                                           0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PRE_ARES_STATUS_PRE_ARES_DONE_SHFT                                             0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_ADDR                                       (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20c4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_OFFS                                       (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20c4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_RMSK                                        0x3333333UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P7_UNDERRUN_BMSK                            0x2000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P7_UNDERRUN_SHFT                                   25U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P7_OVERRUN_BMSK                             0x1000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P7_OVERRUN_SHFT                                    24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P6_UNDERRUN_BMSK                             0x200000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P6_UNDERRUN_SHFT                                   21U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P6_OVERRUN_BMSK                              0x100000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P6_OVERRUN_SHFT                                    20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P5_UNDERRUN_BMSK                              0x20000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P5_UNDERRUN_SHFT                                   17U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P5_OVERRUN_BMSK                               0x10000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P5_OVERRUN_SHFT                                    16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P4_UNDERRUN_BMSK                               0x2000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P4_UNDERRUN_SHFT                                   13U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P4_OVERRUN_BMSK                                0x1000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P4_OVERRUN_SHFT                                    12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P3_UNDERRUN_BMSK                                0x200U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P3_UNDERRUN_SHFT                                    9U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P3_OVERRUN_BMSK                                 0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P3_OVERRUN_SHFT                                     8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P2_UNDERRUN_BMSK                                 0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P2_UNDERRUN_SHFT                                    5U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P2_OVERRUN_BMSK                                  0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P2_OVERRUN_SHFT                                     4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P1_UNDERRUN_BMSK                                  0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P1_UNDERRUN_SHFT                                    1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P1_OVERRUN_BMSK                                   0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS0_P1_OVERRUN_SHFT                                     0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_ADDR                                       (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20c8U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_OFFS                                       (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20c8U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_RMSK                                       0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_P4_CTR_BMSK                                0xff000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_P4_CTR_SHFT                                        24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_P3_CTR_BMSK                                  0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_P3_CTR_SHFT                                        16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_P2_CTR_BMSK                                    0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_P2_CTR_SHFT                                         8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_P1_CTR_BMSK                                      0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS1_P1_CTR_SHFT                                         0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_ADDR                                       (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20ccU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_OFFS                                       (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20ccU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_RMSK                                         0xffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_P7_CTR_BMSK                                  0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_P7_CTR_SHFT                                        16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_P6_CTR_BMSK                                    0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_P6_CTR_SHFT                                         8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_P5_CTR_BMSK                                      0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_LCPB_EVICT_CMD_DPG_STATUS2_P5_CTR_SHFT                                         0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20d0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20d0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_RMSK                                             0x3333333UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P7_UNDERRUN_BMSK                                 0x2000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P7_UNDERRUN_SHFT                                        25U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P7_OVERRUN_BMSK                                  0x1000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P7_OVERRUN_SHFT                                         24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P6_UNDERRUN_BMSK                                  0x200000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P6_UNDERRUN_SHFT                                        21U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P6_OVERRUN_BMSK                                   0x100000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P6_OVERRUN_SHFT                                         20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P5_UNDERRUN_BMSK                                   0x20000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P5_UNDERRUN_SHFT                                        17U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P5_OVERRUN_BMSK                                    0x10000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P5_OVERRUN_SHFT                                         16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P4_UNDERRUN_BMSK                                    0x2000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P4_UNDERRUN_SHFT                                        13U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P4_OVERRUN_BMSK                                     0x1000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P4_OVERRUN_SHFT                                         12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P3_UNDERRUN_BMSK                                     0x200U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P3_UNDERRUN_SHFT                                         9U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P3_OVERRUN_BMSK                                      0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P3_OVERRUN_SHFT                                          8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P2_UNDERRUN_BMSK                                      0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P2_UNDERRUN_SHFT                                         5U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P2_OVERRUN_BMSK                                       0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P2_OVERRUN_SHFT                                          4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P1_UNDERRUN_BMSK                                       0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P1_UNDERRUN_SHFT                                         1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P1_OVERRUN_BMSK                                        0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS0_P1_OVERRUN_SHFT                                          0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20d4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20d4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_P4_CTR_BMSK                                     0xff000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_P4_CTR_SHFT                                             24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_P3_CTR_BMSK                                       0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_P3_CTR_SHFT                                             16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_P2_CTR_BMSK                                         0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_P2_CTR_SHFT                                              8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_P1_CTR_BMSK                                           0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS1_P1_CTR_SHFT                                              0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20d8U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20d8U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_RMSK                                              0xffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_P7_CTR_BMSK                                       0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_P7_CTR_SHFT                                             16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_P6_CTR_BMSK                                         0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_P6_CTR_SHFT                                              8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_P5_CTR_BMSK                                           0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_EVICT_CMD_DPG_STATUS2_P5_CTR_SHFT                                              0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_ADDR                                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20e0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_OFFS                                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20e0U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_RMSK                                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_SPARE_FIELD_BMSK                                                0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_SPARE_SPARE_FIELD_SHFT                                                         0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20f4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20f4U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_RMSK                                            0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_WAYS_DB_ERROR_OCCURRED_BMSK                     0xffff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_WAYS_DB_ERROR_OCCURRED_SHFT                             16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_WAYS_SB_ERROR_OCCURRED_BMSK                         0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS0_WAYS_SB_ERROR_OCCURRED_SHFT                              0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_ADDR                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20f8U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_OFFS                                            (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20f8U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_RMSK                                              0xff001fUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_SB_ERROR_COUNTER_BMSK                             0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_SB_ERROR_COUNTER_SHFT                                   16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_DB_ERROR_COUNTER_BMSK                                 0x1fU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_ERROR_STATUS1_DB_ERROR_COUNTER_SHFT                                    0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x20fcU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x20fcU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_RMSK                                               0x73ff00fUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_BLK_OFFSET_BMSK                                    0x7000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_BLK_OFFSET_SHFT                                           24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_SET_NDX_BMSK                                        0x3ff000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_SET_NDX_SHFT                                              12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_WAY_NDX_BMSK                                             0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN0_WAY_NDX_SHFT                                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN1_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2100U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN1_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2100U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN1_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN1_UNCORRECTED_DATA_31_0_BMSK                        0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN1_UNCORRECTED_DATA_31_0_SHFT                                 0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN2_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2104U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN2_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2104U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN2_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN2_UNCORRECTED_DATA_63_32_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN2_UNCORRECTED_DATA_63_32_SHFT                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN3_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2108U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN3_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2108U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN3_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN3_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN3_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN3_UNCORRECTED_DATA_95_64_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN3_UNCORRECTED_DATA_95_64_SHFT                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN4_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x210cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN4_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x210cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN4_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN4_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN4_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN4_UNCORRECTED_DATA_127_96_BMSK                      0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN4_UNCORRECTED_DATA_127_96_SHFT                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN5_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2110U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN5_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2110U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN5_RMSK                                                   0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN5_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN5_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN5_UNCORRECTED_PARITY_BITS_BMSK                           0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN5_UNCORRECTED_PARITY_BITS_SHFT                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN6_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2114U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN6_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2114U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN6_RMSK                                              0x1fffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN6_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN6_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN6_ADDRESS_BMSK                                      0x1fffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN6_ADDRESS_SHFT                                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN7_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2118U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN7_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2118U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN7_RMSK                                                  0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN7_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN7_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN7_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN7_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN7_AMID_BMSK                                             0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_SB_ERR_SYN7_AMID_SHFT                                                  0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2120U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2120U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_RMSK                                               0x73ff00fUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_BLK_OFFSET_BMSK                                    0x7000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_BLK_OFFSET_SHFT                                           24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_SET_NDX_BMSK                                        0x3ff000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_SET_NDX_SHFT                                              12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_WAY_NDX_BMSK                                             0xfU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN0_WAY_NDX_SHFT                                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN1_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2124U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN1_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2124U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN1_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN1_UNCORRECTED_DATA_31_0_BMSK                        0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN1_UNCORRECTED_DATA_31_0_SHFT                                 0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN2_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2128U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN2_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2128U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN2_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN2_UNCORRECTED_DATA_63_32_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN2_UNCORRECTED_DATA_63_32_SHFT                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN3_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x212cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN3_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x212cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN3_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN3_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN3_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN3_UNCORRECTED_DATA_95_64_BMSK                       0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN3_UNCORRECTED_DATA_95_64_SHFT                                0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN4_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2130U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN4_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2130U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN4_RMSK                                              0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN4_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN4_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN4_UNCORRECTED_DATA_127_96_BMSK                      0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN4_UNCORRECTED_DATA_127_96_SHFT                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN5_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2134U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN5_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2134U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN5_RMSK                                                   0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN5_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN5_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN5_UNCORRECTED_PARITY_BITS_BMSK                           0x1ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN5_UNCORRECTED_PARITY_BITS_SHFT                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN6_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2138U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN6_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2138U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN6_RMSK                                              0x1fffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN6_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN6_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN6_ADDRESS_BMSK                                      0x1fffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN6_ADDRESS_SHFT                                               0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN7_ADDR                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x213cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN7_OFFS                                              (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x213cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN7_RMSK                                                  0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN7_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN7_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN7_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN7_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN7_AMID_BMSK                                             0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CH1_ECC_DB_ERR_SYN7_AMID_SHFT                                                  0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS0_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2140U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS0_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2140U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS0_RMSK                                                     0x7ffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS0_VALID_BMSK                                               0x7ffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS0_VALID_SHFT                                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS1_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2144U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS1_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2144U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS1_RMSK                                                         0xfffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS1_VALID_BMSK                                                   0xfffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_VALID_STATUS1_VALID_SHFT                                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS0_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x2148U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS0_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x2148U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS0_RMSK                                                       0x3ffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS0_READY_BMSK                                                 0x3ffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS0_READY_SHFT                                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS1_ADDR                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x214cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS1_OFFS                                                    (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x214cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS1_RMSK                                                         0x3ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS1_READY_BMSK                                                   0x3ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_READY_STATUS1_READY_SHFT                                                       0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_ADDR                                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x3000U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_OFFS                                                             (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x3000U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_RMSK                                                                    0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_IGNORE_PMGR_IDLE_FEEDBACK_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_CFG0_IGNORE_PMGR_IDLE_FEEDBACK_SHFT                                            0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x3010U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x3010U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_RMSK                                                      0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_TPD4_BMSK                                                 0xff000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_TPD4_SHFT                                                         24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_TPD3_BMSK                                                   0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_TPD3_SHFT                                                         16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_TPD2_BMSK                                                     0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_TPD2_SHFT                                                          8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_TPD1_BMSK                                                       0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING0_TPD1_SHFT                                                          0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x3014U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x3014U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_RMSK                                                       0x1ffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_OVERLAP_TH1_TPD4_BMSK                                      0x1000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_OVERLAP_TH1_TPD4_SHFT                                             24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_TH3_DUMMY_BMSK                                              0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_TH3_DUMMY_SHFT                                                    16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_TPD1_PRE_BMSK                                                 0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_TPD1_PRE_SHFT                                                      8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_TH1_BMSK                                                        0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING1_TH1_SHFT                                                           0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x3018U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x3018U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_RMSK                                                        0xffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_TSTAG_NRET_BMSK                                             0xff0000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_TSTAG_NRET_SHFT                                                   16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_TSTAG_RET_BMSK                                                0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_TSTAG_RET_SHFT                                                     8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_TPD2_NRET_TO_ACTIVE_BMSK                                        0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_RAM_TIMING2_TPD2_NRET_TO_ACTIVE_SHFT                                           0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_ADDR                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x3024U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_OFFS                                                      (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x3024U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_RMSK                                                          0xffffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_NRET_SEL_BMSK                                                 0xff00U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_NRET_SEL_SHFT                                                      8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_SEL_BMSK                                                        0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_SLP_SEL_SEL_SHFT                                                           0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_ADDR                                                   (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x3028U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_OFFS                                                   (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x3028U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_RMSK                                                         0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_SEL_BMSK                                                     0xffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_WAKEUP_SEL_SEL_SHFT                                                        0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_ADDR                                                          (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x302cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_OFFS                                                          (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x302cU)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_RMSK                                                                 0x3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_WAKEUP_COMMAND_BMSK                                                  0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_WAKEUP_COMMAND_SHFT                                                    1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_SLEEP_COMMAND_BMSK                                                   0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PCB_CMD_SLEEP_COMMAND_SHFT                                                     0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_ADDR                                                  (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x3040U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_OFFS                                                  (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x3040U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_RMSK                                                      0x1733U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_ADDR,v)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_ADDR,m,v,HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_IN)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_MICRO_SLEEP_MODE_EN_BMSK                                  0x1000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_MICRO_SLEEP_MODE_EN_SHFT                                      12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_DISABLE_PCB_STAGGERING_BMSK                                0x400U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_DISABLE_PCB_STAGGERING_SHFT                                   10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_CLAMP_MEM_WAKEUP_EN_BMSK                                   0x200U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_CLAMP_MEM_WAKEUP_EN_SHFT                                       9U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_CLAMP_MEM_SLEEP_EN_BMSK                                    0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_CLAMP_MEM_SLEEP_EN_SHFT                                        8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_MICRO_WAKEUP_BATCH_BMSK                                     0x30U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_MICRO_WAKEUP_BATCH_SHFT                                        4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_MICRO_SLEEP_BATCH_BMSK                                       0x3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_DPC_RAMSLP_MODE_MICRO_SLEEP_BATCH_SHFT                                         0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_ADDR                                          (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x4000U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_OFFS                                          (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x4000U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_RMSK                                          0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT31_BMSK                                    0x80000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT31_SHFT                                            31U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT30_BMSK                                    0x40000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT30_SHFT                                            30U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT29_BMSK                                    0x20000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT29_SHFT                                            29U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT28_BMSK                                    0x10000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT28_SHFT                                            28U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT27_BMSK                                     0x8000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT27_SHFT                                            27U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT26_BMSK                                     0x4000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT26_SHFT                                            26U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT25_BMSK                                     0x2000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT25_SHFT                                            25U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT24_BMSK                                     0x1000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT24_SHFT                                            24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT23_BMSK                                      0x800000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT23_SHFT                                            23U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT22_BMSK                                      0x400000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT22_SHFT                                            22U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT21_BMSK                                      0x200000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT21_SHFT                                            21U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT20_BMSK                                      0x100000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT20_SHFT                                            20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT19_BMSK                                       0x80000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT19_SHFT                                            19U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT18_BMSK                                       0x40000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT18_SHFT                                            18U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT17_BMSK                                       0x20000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT17_SHFT                                            17U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT16_BMSK                                       0x10000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT16_SHFT                                            16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT15_BMSK                                        0x8000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT15_SHFT                                            15U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT14_BMSK                                        0x4000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT14_SHFT                                            14U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT13_BMSK                                        0x2000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT13_SHFT                                            13U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT12_BMSK                                        0x1000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT12_SHFT                                            12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT11_BMSK                                         0x800U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT11_SHFT                                            11U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT10_BMSK                                         0x400U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT10_SHFT                                            10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT9_BMSK                                          0x200U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT9_SHFT                                              9U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT8_BMSK                                          0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT8_SHFT                                              8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT7_BMSK                                           0x80U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT7_SHFT                                              7U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT6_BMSK                                           0x40U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT6_SHFT                                              6U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT5_BMSK                                           0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT5_SHFT                                              5U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT4_BMSK                                           0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT4_SHFT                                              4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT3_BMSK                                            0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT3_SHFT                                              3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT2_BMSK                                            0x4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT2_SHFT                                              2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT1_BMSK                                            0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT1_SHFT                                              1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT0_BMSK                                            0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_VER_STATUS_BIT0_SHFT                                              0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_ADDR                                         (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x4004U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_OFFS                                         (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x4004U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_RMSK                                         0xffffffffUL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_DEBUG_CTRL0_BMSK                    0x80000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_DEBUG_CTRL0_SHFT                            31U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_QOS_CTRL_BMSK                       0x40000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_QOS_CTRL_SHFT                               30U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_CLK_EN_CFG_BMSK                     0x20000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_CLK_EN_CFG_SHFT                             29U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_CFG1_BMSK                           0x10000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_CFG1_SHFT                                   28U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_CFG_BMSK                        0x8000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_CFG_SHFT                               27U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_15_CFG_BMSK               0x4000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_15_CFG_SHFT                      26U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_14_CFG_BMSK               0x2000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_14_CFG_SHFT                      25U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_13_CFG_BMSK               0x1000000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_13_CFG_SHFT                      24U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_12_CFG_BMSK                0x800000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_12_CFG_SHFT                      23U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_11_CFG_BMSK                0x400000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_11_CFG_SHFT                      22U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_10_CFG_BMSK                0x200000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_10_CFG_SHFT                      21U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_9_CFG_BMSK                 0x100000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_9_CFG_SHFT                       20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_8_CFG_BMSK                  0x80000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_8_CFG_SHFT                       19U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_7_CFG_BMSK                  0x40000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_7_CFG_SHFT                       18U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_6_CFG_BMSK                  0x20000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_6_CFG_SHFT                       17U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_5_CFG_BMSK                  0x10000UL
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_5_CFG_SHFT                       16U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_4_CFG_BMSK                   0x8000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_4_CFG_SHFT                       15U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_3_CFG_BMSK                   0x4000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_3_CFG_SHFT                       14U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_2_CFG_BMSK                   0x2000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_2_CFG_SHFT                       13U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_1_CFG_BMSK                   0x1000U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_1_CFG_SHFT                       12U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_0_CFG_BMSK                    0x800U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_EVENT_0_CFG_SHFT                       11U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_1_CFG3_BMSK                  0x400U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_1_CFG3_SHFT                     10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_1_CFG2_BMSK                  0x200U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_1_CFG2_SHFT                      9U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_1_CFG1_BMSK                  0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_1_CFG1_SHFT                      8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_1_CFG0_BMSK                   0x80U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_1_CFG0_SHFT                      7U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_0_CFG3_BMSK                   0x40U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_0_CFG3_SHFT                      6U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_0_CFG2_BMSK                   0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_0_CFG2_SHFT                      5U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_0_CFG1_BMSK                   0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_0_CFG1_SHFT                      4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_0_CFG0_BMSK                    0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_PROF_FILTER_0_CFG0_SHFT                      3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_ECC_ERROR_INJECTION_1_BMSK                 0x4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_ECC_ERROR_INJECTION_1_SHFT                   2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_ECC_ERROR_INJECTION_0_BMSK                 0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_ECC_ERROR_INJECTION_0_SHFT                   1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_ECC_ERROR_CFG_BMSK                         0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR0_STATUS_LLCC_DRP_ECC_ERROR_CFG_SHFT                           0U

#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_ADDR                                         (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE      + 0x4008U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_OFFS                                         (SAIL_TO_MD_LLC_BROADCAST_DRP_REG_BASE_OFFS + 0x4008U)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_RMSK                                              0x7ffU
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_DPC_RAMSLP_MODE_BMSK                     0x400U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_DPC_RAMSLP_MODE_SHFT                        10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_PCB_CMD_BMSK                             0x200U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_PCB_CMD_SHFT                                 9U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_PCB_WAKEUP_SEL_BMSK                      0x100U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_PCB_WAKEUP_SEL_SHFT                          8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_PCB_SLP_SEL_BMSK                          0x80U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_PCB_SLP_SEL_SHFT                             7U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_RAM_TIMING2_BMSK                          0x40U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_RAM_TIMING2_SHFT                             6U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_RAM_TIMING1_BMSK                          0x20U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_RAM_TIMING1_SHFT                             5U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_RAM_TIMING0_BMSK                          0x10U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_RAM_TIMING0_SHFT                             4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_CFG0_BMSK                                  0x8U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_CFG0_SHFT                                    3U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_SPARE_BMSK                                 0x4U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_SPARE_SHFT                                   2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_LB_THROTTLE_CTRL_BMSK                      0x2U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_LB_THROTTLE_CTRL_SHFT                        1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_DEBUG_CTRL1_BMSK                           0x1U
#define HWIO_SAIL_TO_MD_LLC_BROADCAST_LLCC_DRP_PARITY_ERROR_HOR1_STATUS_LLCC_DRP_DEBUG_CTRL1_SHFT                             0U


#endif /* G_SAIL_TO_MD_LLC_BROADCAST_DRP_HWIO_H */
