#ifndef __G_SAIL_TO_MD_GPU_GMU_CX_HWIO_H__
#define __G_SAIL_TO_MD_GPU_GMU_CX_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_GPU_GMU_CX_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_GPU_GMU_CX_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0'],
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
 * MODULE: SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE                                                             (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x03d7d000ul)
#define SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_SIZE                                                        0x2000u
#define SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_USED                                                        0x180cu
#define SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS                                                        0x03d7d000ul

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_RMSK                                                       0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_CACHEREDUCT_BMSK                                           0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_CACHEREDUCT_SHFT                                             1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_BYPASSMODE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_L1_ICACHE_CONFIG_BYPASSMODE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_RMSK                                                          0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_DCACHEREDUCT_BMSK                                             0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_DCACHEREDUCT_SHFT                                               1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_BYPASSMODE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CONFIG_BYPASSMODE_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_RMSK                                                      0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_INDEX_BMSK                                                0xfcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_INDEX_SHFT                                                   2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_CLEANINVALIDOP_BMSK                                        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_CLEANINVALIDOP_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_STATUS_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0xcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_STATUS_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0xcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_STATUS_RMSK                                                0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_STATUS_CLEANINVSTATUS_BMSK                                 0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_CLEAN_IDX_STATUS_CLEANINVSTATUS_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x10u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x10u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_RMSK                                                      0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_INVALIDATEL1_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_INVALIDATEL1_SHFT                                           1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_INVALIDATEL0_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_INVALIDATEL0_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x14u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x14u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_RMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_INVALIDATE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_INVALIDATE_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x18u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x18u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_RMSK                                                    0x73ffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_WORDSELECT_BMSK                                         0x70000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_WORDSELECT_SHFT                                              16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_WAYSELECT_BMSK                                           0x3000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_WAYSELECT_SHFT                                               12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_WRITEENABLE_BMSK                                          0x800u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_WRITEENABLE_SHFT                                             11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_SETSELECT_BMSK                                            0x7f0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_SETSELECT_SHFT                                                4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_RAMSELECT_BMSK                                              0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_RAMSELECT_SHFT                                                2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_CACHESELECT_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_CACHESELECT_SHFT                                              1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_DEBUGENABLE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DESC_DEBUGENABLE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_RMSK                                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_L1DATA_BMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_DATA_L1DATA_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_STATUS_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x20u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_STATUS_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x20u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_STATUS_RMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_STATUS_L1DATA_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_L1_CACHE_DEBUG_STATUS_L1DATA_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_STATUS_ADDR                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x24u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_STATUS_OFFS                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x24u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_STATUS_RMSK                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_STATUS_INVALIDATEL1DONE_BMSK                              0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ICACHE_INVALIDATE_STATUS_INVALIDATEL1DONE_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_STATUS_ADDR                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x28u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_STATUS_OFFS                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x28u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_STATUS_RMSK                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_STATUS_INVALIDATEDONE_BMSK                                0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_INVALIDATE_STATUS_INVALIDATEDONE_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_ADDR                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x2cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_OFFS                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x2cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_RMSK                                             0xf00eful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_RDTID3_BMSK                                      0x80000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_RDTID3_SHFT                                           19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_RDTID2_BMSK                                      0x40000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_RDTID2_SHFT                                           18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_RDTID1_BMSK                                      0x20000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_RDTID1_SHFT                                           17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_RDTID0_BMSK                                      0x10000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_RDTID0_SHFT                                           16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID7_BMSK                                         0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID7_SHFT                                            7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID6_BMSK                                         0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID6_SHFT                                            6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID5_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID5_SHFT                                            5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID3_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID3_SHFT                                            3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID2_BMSK                                          0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID2_SHFT                                            2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID1_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID1_SHFT                                            1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID0_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_VBIF_OUTSTANDING_TRANS_WRTID0_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_ADDR                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x30u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_OFFS                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x30u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_RMSK                                            0xffffffe0ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_ADDRESS_BMSK                                    0xffffffe0ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_ADDR_LO_ADDRESS_SHFT                                             5u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x34u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x34u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_RMSK                                                  0x1fffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_ENABLE_BMSK                                           0x10000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_ENABLE_SHFT                                                16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_SIZE_BMSK                                              0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_DCACHE_NFLOW_CTRL_SIZE_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x3cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x3cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_RMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_SYSBUSBUFFERBYPASS_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_BUS_CONFIG_SYSBUSBUFFERBYPASS_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_ADDR                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x40u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_OFFS                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x40u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_RMSK                                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_WRBUFFERFLUSH_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_WRBUFFERFLUSH_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_STATUS_ADDR                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x44u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_STATUS_OFFS                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x44u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_STATUS_RMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_STATUS_WRBUFFERFLUSHSTATUS_BMSK                                0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_WB_FLUSH_STATUS_WRBUFFERFLUSHSTATUS_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_RB_INVALID_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x48u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_RB_INVALID_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x48u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_RB_INVALID_RMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_RB_INVALID_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_RB_INVALID_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_RB_INVALID_RDBUFFERINV_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SYS_RB_INVALID_RDBUFFERINV_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_ADDR                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x400u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_OFFS                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x400u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_RMSK                                                       0x7fffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_UVMBASE_BMSK                                               0x7fffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_UVM_BASE_UVMBASE_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x41cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x41cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_RMSK                                                       0x7fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_WRITEBUFFERWRITEERREN_BMSK                                 0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_WRITEBUFFERWRITEERREN_SHFT                                    6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_PREFETCHREADERREN_BMSK                                     0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_PREFETCHREADERREN_SHFT                                        5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ATOMICHWWRITEERREN_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ATOMICHWWRITEERREN_SHFT                                       4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ATOMICHWREADERREN_BMSK                                      0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ATOMICHWREADERREN_SHFT                                        3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_DCACHEWRITEERREN_BMSK                                       0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_DCACHEWRITEERREN_SHFT                                         2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_DCACHEREADERREN_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_DCACHEREADERREN_SHFT                                          1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ICACHEREADERREN_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_EN_ICACHEREADERREN_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x420u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x420u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_RMSK                                                      0x7fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_WRITEBUFFERWRITEERRCLR_BMSK                               0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_WRITEBUFFERWRITEERRCLR_SHFT                                  6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_PREFETCHREADERRCLR_BMSK                                   0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_PREFETCHREADERRCLR_SHFT                                      5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_ATOMICHWWRITEERRCLR_BMSK                                  0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_ATOMICHWWRITEERRCLR_SHFT                                     4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_ATOMICHWREADERRCLR_BMSK                                    0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_ATOMICHWREADERRCLR_SHFT                                      3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_DCACHEWRITEERRCLR_BMSK                                     0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_DCACHEWRITEERRCLR_SHFT                                       2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_DCACHEREADERRCLR_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_DCACHEREADERRCLR_SHFT                                        1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_ICACHEREADERRCLR_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_CLR_ICACHEREADERRCLR_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_ADDR                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x424u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_OFFS                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x424u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_RMSK                                                   0x7fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_WRITEBUFFERWRITEERR_BMSK                               0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_WRITEBUFFERWRITEERR_SHFT                                  6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_PREFETCHREADERR_BMSK                                   0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_PREFETCHREADERR_SHFT                                      5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_ATOMICHWWRITEERR_BMSK                                  0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_ATOMICHWWRITEERR_SHFT                                     4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_ATOMICHWREADERR_BMSK                                    0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_ATOMICHWREADERR_SHFT                                      3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_DCACHEWRITEERR_BMSK                                     0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_DCACHEWRITEERR_SHFT                                       2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_DCACHEREADERR_BMSK                                      0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_DCACHEREADERR_SHFT                                        1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_ICACHEREADERR_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_INT_STATUS_ICACHEREADERR_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_BADVA_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x428u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_BADVA_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x428u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_BADVA_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_BADVA_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_BADVA_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_BADVA_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_BADVA_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_BADVA_BADVA_BMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_VBIF_BADVA_BADVA_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x42cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x42cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_RMSK                                                     0x77u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_CPRIORITYLV1_BMSK                                        0x70u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_CPRIORITYLV1_SHFT                                           4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_CREQPRIORITY_BMSK                                         0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_GBIF_QOS_CTRL_CREQPRIORITY_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_ADDR                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1000u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_OFFS                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1000u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_RMSK                                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_SYSRESET_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_SYSRESET_SYSRESET_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1004u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1004u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_RMSK                                                        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_BOOTMODE_BMSK                                               0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_BOOT_CONFIG_BOOTMODE_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1008u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1008u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_RMSK                                                             0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_SLEEPINTRCTRLCGCDISABLE_BMSK                                     0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_SLEEPINTRCTRLCGCDISABLE_SHFT                                       2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_PROCCLKHALT_BMSK                                                 0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_PROCCLKHALT_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_BUSCLKHALT_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WFI_CONFIG_BUSCLKHALT_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x100cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x100cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_RMSK                                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_INTRPOLARITY0_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_0_INTRPOLARITY0_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1010u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1010u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_RMSK                                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_INTRPOLARITY1_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_POLARITY_1_INTRPOLARITY1_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x101cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x101cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_INTREDGLVL0_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_0_INTREDGLVL0_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1020u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1020u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_INTREDGLVL1_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_EDGE_LEVEL_1_INTREDGLVL1_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_0_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x102cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_0_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x102cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_0_RMSK                                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_0_INTRSTATUS0_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_0_INTRSTATUS0_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_1_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1030u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_1_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1030u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_1_RMSK                                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_1_INTRSTATUS1_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_STATUS_1_INTRSTATUS1_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x103cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x103cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_RMSK                                                       0x7fffe0ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_AOSSCLXIRQINTREN_BMSK                                      0x400000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_AOSSCLXIRQINTREN_SHFT                                            22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_BCLCBINTREN_BMSK                                           0x200000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_BCLCBINTREN_SHFT                                                 21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_GENERICCBINTREN_BMSK                                       0x100000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_GENERICCBINTREN_SHFT                                             20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_DCEDELTATHINTREN_BMSK                                       0x80000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_DCEDELTATHINTREN_SHFT                                            19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_UNUSEDEN_BMSK                                               0x40000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_UNUSEDEN_SHFT                                                    18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_HOSTTOGMUINTR_BMSK                                          0x20000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_HOSTTOGMUINTR_SHFT                                               17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_LMAVECURRINTR_BMSK                                          0x10000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_LMAVECURRINTR_SHFT                                               16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_PWRTHRESHOLDCHANGEINTR_BMSK                                  0x8000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_PWRTHRESHOLDCHANGEINTR_SHFT                                      15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_VOLTAGECHANGEINTR_BMSK                                       0x4000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_VOLTAGECHANGEINTR_SHFT                                           14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_LONGHISTFIFOINTR_BMSK                                        0x2000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_LONGHISTFIFOINTR_SHFT                                            13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_WDOGBARKINTR_BMSK                                            0x1000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_WDOGBARKINTR_SHFT                                                12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER6INTR_BMSK                                               0x800u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER6INTR_SHFT                                                  11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER5INTR_BMSK                                               0x400u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER5INTR_SHFT                                                  10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER4INTR_BMSK                                               0x200u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER4INTR_SHFT                                                   9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER3INTR_BMSK                                               0x100u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER3INTR_SHFT                                                   8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER2INTR_BMSK                                                0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER2INTR_SHFT                                                   7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER1INTR_BMSK                                                0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER1INTR_SHFT                                                   6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER0INTR_BMSK                                                0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_GEN_EN_TIMER0INTR_SHFT                                                   5u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1040u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1040u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_RMSK                                                        0x7dffe0ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_AOSSCLXIRQINTRCLEAR_BMSK                                    0x400000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_AOSSCLXIRQINTRCLEAR_SHFT                                          22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_BCLCBINTRCLEAR_BMSK                                         0x200000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_BCLCBINTRCLEAR_SHFT                                               21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_GENERICCBINTRCLEAR_BMSK                                     0x100000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_GENERICCBINTRCLEAR_SHFT                                           20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_DCEDELTATHINTRCLEAR_BMSK                                     0x80000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_DCEDELTATHINTRCLEAR_SHFT                                          19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_HOSTTOGMUINTRCLEAR_BMSK                                      0x40000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_HOSTTOGMUINTRCLEAR_SHFT                                           18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_LMAVECURRINTRCLEAR_BMSK                                      0x10000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_LMAVECURRINTRCLEAR_SHFT                                           16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_PWRTHRESHOLDCHANGEINTRCLEAR_BMSK                              0x8000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_PWRTHRESHOLDCHANGEINTRCLEAR_SHFT                                  15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_VOLTAGECHANGEINTRCLEAR_BMSK                                   0x4000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_VOLTAGECHANGEINTRCLEAR_SHFT                                       14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_LONGHISTFIFOINTRCLEAR_BMSK                                    0x2000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_LONGHISTFIFOINTRCLEAR_SHFT                                        13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_WDOGBARKINTRCLEAR_BMSK                                        0x1000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_WDOGBARKINTRCLEAR_SHFT                                            12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER6INTRCLEAR_BMSK                                           0x800u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER6INTRCLEAR_SHFT                                              11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER5INTRCLEAR_BMSK                                           0x400u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER5INTRCLEAR_SHFT                                              10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER4INTRCLEAR_BMSK                                           0x200u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER4INTRCLEAR_SHFT                                               9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER3INTRCLEAR_BMSK                                           0x100u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER3INTRCLEAR_SHFT                                               8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER2INTRCLEAR_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER2INTRCLEAR_SHFT                                               7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER1INTRCLEAR_BMSK                                            0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER1INTRCLEAR_SHFT                                               6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER0INTRCLEAR_BMSK                                            0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_INTR_CLEAR_TIMER0INTRCLEAR_SHFT                                               5u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1044u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1044u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_RMSK                                                       0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_WDOGTIMERCLKOFF_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CLK_OFF_CTL_WDOGTIMERCLKOFF_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_RESET_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1048u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_RESET_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1048u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_RESET_RMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_RESET_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_RESET_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_RESET_WDOGRESET_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_RESET_WDOGRESET_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x104cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x104cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_RMSK                                                              0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_WDOGENABLE_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_WDOGENABLE_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_WDOGFREEZECM3SLEEP_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_CTRL_WDOGFREEZECM3SLEEP_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1050u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1050u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS_RMSK                                                     0x3ffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS_WDOGCOUNT_BMSK                                           0x3ffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS_WDOGCOUNT_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_ADDR                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1054u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_OFFS                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1054u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_RMSK                                                      0x1f0007ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGTESTSYNCSTATUS_BMSK                                   0x100000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGTESTSYNCSTATUS_SHFT                                         20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGTESTLOADSYNCSTATUS_BMSK                                0x80000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGTESTLOADSYNCSTATUS_SHFT                                     19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGBITETIMESYNCSTATUS_BMSK                                0x40000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGBITETIMESYNCSTATUS_SHFT                                     18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGBARKTIMESYNCSTATUS_BMSK                                0x20000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGBARKTIMESYNCSTATUS_SHFT                                     17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGRESETSYNCSTATUS_BMSK                                   0x10000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGRESETSYNCSTATUS_SHFT                                        16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGEXPIREDSTATUS_BMSK                                         0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGEXPIREDSTATUS_SHFT                                           2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGFROZEN_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGFROZEN_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGCNTRESETSTATUS_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_STATUS2_WDOGCNTRESETSTATUS_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1058u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1058u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_RMSK                                                  0x3ffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_WDOGBARKVAL_BMSK                                      0x3ffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BARK_TIME_WDOGBARKVAL_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x105cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x105cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_RMSK                                                  0x3ffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_WDOGBITEVAL_BMSK                                      0x3ffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_BITE_TIME_WDOGBITEVAL_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_LOAD_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1060u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_LOAD_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1060u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_LOAD_RMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_LOAD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_LOAD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_LOAD_LOAD_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_LOAD_LOAD_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1064u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1064u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_RMSK                                                       0x3ffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_LOADVALUE_BMSK                                             0x3ffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_WDOG_TEST_LOADVALUE_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1068u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1068u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_RMSK                                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_GMUCM3FWBUSY_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_BUSY_GMUCM3FWBUSY_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x106cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x106cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_RMSK                                                      0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_GMUCM3FWPERFCNTR_BMSK                                     0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_PERF_CNTR_GMUCM3FWPERFCNTR_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_ADDR                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1070u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_OFFS                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1070u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_GMUCM3FWINITRESULT_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_FW_INIT_RESULT_GMUCM3FWINITRESULT_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_ADDR                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1090u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_OFFS                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1090u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_RMSK                                                          0xe000fffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_ENABLE_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_ENABLE_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_ROLLOVER_BMSK                                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_ROLLOVER_SHFT                                                         30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_START_BMSK                                                    0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_START_SHFT                                                            29u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_TIMERCOUNT_BMSK                                                   0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER0_TIMERCOUNT_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_ADDR                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1094u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_OFFS                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1094u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_RMSK                                                          0xe000fffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_ENABLE_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_ENABLE_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_ROLLOVER_BMSK                                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_ROLLOVER_SHFT                                                         30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_START_BMSK                                                    0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_START_SHFT                                                            29u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_TIMERCOUNT_BMSK                                                   0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER1_TIMERCOUNT_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_ADDR                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1098u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_OFFS                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1098u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_RMSK                                                          0xe0fffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_ENABLE_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_ENABLE_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_ROLLOVER_BMSK                                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_ROLLOVER_SHFT                                                         30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_START_BMSK                                                    0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_START_SHFT                                                            29u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_TIMERCOUNT_BMSK                                                 0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER2_TIMERCOUNT_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_ADDR                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x109cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_OFFS                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x109cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_RMSK                                                          0xe0fffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_ENABLE_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_ENABLE_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_ROLLOVER_BMSK                                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_ROLLOVER_SHFT                                                         30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_START_BMSK                                                    0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_START_SHFT                                                            29u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_TIMERCOUNT_BMSK                                                 0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER3_TIMERCOUNT_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_ADDR                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x10a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_OFFS                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x10a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_RMSK                                                          0xe0fffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_ENABLE_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_ENABLE_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_ROLLOVER_BMSK                                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_ROLLOVER_SHFT                                                         30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_START_BMSK                                                    0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_START_SHFT                                                            29u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_TIMERCOUNT_BMSK                                                 0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER4_TIMERCOUNT_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_ADDR                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x10a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_OFFS                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x10a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_RMSK                                                          0xe0fffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_ENABLE_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_ENABLE_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_ROLLOVER_BMSK                                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_ROLLOVER_SHFT                                                         30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_START_BMSK                                                    0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_START_SHFT                                                            29u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_TIMERCOUNT_BMSK                                                 0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER5_TIMERCOUNT_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_ADDR                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x10a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_OFFS                                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x10a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_RMSK                                                          0xe0fffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_ENABLE_BMSK                                                   0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_ENABLE_SHFT                                                           31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_ROLLOVER_BMSK                                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_ROLLOVER_SHFT                                                         30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_START_BMSK                                                    0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_START_SHFT                                                            29u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_TIMERCOUNT_BMSK                                                 0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TIMER6_TIMERCOUNT_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_ADDR                                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x10b4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_OFFS                                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x10b4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_RMSK                                                             0x43ffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_VBIFAPRIVOVERWRITE_BMSK                                          0x4000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_VBIFAPRIVOVERWRITE_SHFT                                              14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_NONMASKINTR_BMSK                                                  0x200u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_NONMASKINTR_SHFT                                                      9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_DNOTITRANS_BMSK                                                   0x100u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_DNOTITRANS_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_IFLUSH_BMSK                                                        0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_IFLUSH_SHFT                                                           7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_MPUDISEN_BMSK                                                      0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_MPUDISEN_SHFT                                                         6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_WICENREQ_BMSK                                                      0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_WICENREQ_SHFT                                                         5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_FIXMASTERTYPE_BMSK                                                 0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_FIXMASTERTYPE_SHFT                                                    4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_DEBUGREQ_BMSK                                                       0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_DEBUGREQ_SHFT                                                         3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_EVENTWAKEUP_BMSK                                                    0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_EVENTWAKEUP_SHFT                                                      2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_ISOLATIONN_BMSK                                                     0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_ISOLATIONN_SHFT                                                       1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_BIGEND_BMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_CFG_BIGEND_SHFT                                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x10b8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x10b8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_RMSK                                                   0x3fffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_STCALIBREF_BMSK                                        0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_STCALIBREF_SHFT                                               25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_STCALIBSKEW_BMSK                                       0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_STCALIBSKEW_SHFT                                              24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_STCALIBTENMS_BMSK                                       0xfffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_TICK_CALIB_STCALIBTENMS_SHFT                                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_ADDR                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x10bcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_OFFS                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x10bcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_RMSK                                                    0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_AUXFAULT_BMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_AUXFAULT_AUXFAULT_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x10c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x10c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_RMSK                                                         0x7fffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_SLEEPDEEP_BMSK                                               0x40000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_SLEEPDEEP_SHFT                                                    18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_SLEEPING_BMSK                                                0x20000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_SLEEPING_SHFT                                                     17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_LOCKUP_BMSK                                                  0x10000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_LOCKUP_SHFT                                                       16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_DBGRESTART_BMSK                                               0x8000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_DBGRESTART_SHFT                                                   15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_COREISHALTED_BMSK                                             0x4000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_COREISHALTED_SHFT                                                 14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_GATEHCLK_BMSK                                                 0x2000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_GATEHCLK_SHFT                                                     13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_INTRNUMSERVICED_BMSK                                          0x1ff0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_INTRNUMSERVICED_SHFT                                               4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_BRANCHSTATUS_BMSK                                                0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CM3_STATUS_BRANCHSTATUS_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_ADDR                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1100u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_OFFS                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1100u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_RMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_POWERCOUNTERENABLE_BMSK                                0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_ENABLE_POWERCOUNTERENABLE_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_ADDR                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1104u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_OFFS                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1104u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_BMSK                 0xff000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_SHFT                         24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL3_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_BMSK                   0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_SHFT                         16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL2_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_BMSK                     0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_SHFT                          8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL1_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_BMSK                       0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_SHFT                          0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_0_GMUPOWERCOUNTERXOCLKSEL0_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_ADDR                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1108u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_OFFS                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1108u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_BMSK                0xff000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_SHFT                        24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_FW_INCREMENT_0_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_FW_INCREMENT_1_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_FW_INCREMENT_2_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_FW_INCREMENT_3_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_FW_INCREMENT_4_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_FW_INCREMENT_5_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_FW_INCREMENT_6_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_FW_INCREMENT_7_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_SOC_MIN_IDLE_VOTE_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_TSENSE_CBCAST_MSG_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_MXA_CBCAST_MSG_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_CX_CBCAST_MSG_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_GX_CBCAST_MSG_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_BCL_CBCAST_MSG_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_MXC_CBCAST_MSG_FVAL        0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_GENERIC_CBCAST_MSG_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_PMIC_CBCAST_MSG_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_LAW_CBCAST_MSG_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL1_GMU_CX_0_GMU_PWC_PMICARB_CLX_IRQ_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_BMSK                  0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_SHFT                        16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_FW_INCREMENT_0_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_FW_INCREMENT_1_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_FW_INCREMENT_2_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_FW_INCREMENT_3_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_FW_INCREMENT_4_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_FW_INCREMENT_5_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_FW_INCREMENT_6_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_FW_INCREMENT_7_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_SOC_MIN_IDLE_VOTE_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_TSENSE_CBCAST_MSG_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_MXA_CBCAST_MSG_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_CX_CBCAST_MSG_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_GX_CBCAST_MSG_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_BCL_CBCAST_MSG_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_MXC_CBCAST_MSG_FVAL        0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_GENERIC_CBCAST_MSG_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_PMIC_CBCAST_MSG_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_LAW_CBCAST_MSG_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERGMUCLKSEL0_GMU_CX_0_GMU_PWC_PMICARB_CLX_IRQ_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_BMSK                     0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_SHFT                          8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL5_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_BMSK                       0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_SHFT                          0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_1_GMUPOWERCOUNTERXOCLKSEL4_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_ADDR                                           (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x110cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_OFFS                                           (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x110cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_RMSK                                                 0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRSOCMINIDLEVOTE_BMSK                            0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRSOCMINIDLEVOTE_SHFT                               4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRGPUTOPIDLEPHASE2OUTLATENCY_BMSK                 0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRGPUTOPIDLEPHASE2OUTLATENCY_SHFT                   3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRGPUTOPIDLEPHASE1OUTLATENCY_BMSK                 0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRGPUTOPIDLEPHASE1OUTLATENCY_SHFT                   2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRGPUTOPIDLEPHASE2INLATENCY_BMSK                  0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRGPUTOPIDLEPHASE2INLATENCY_SHFT                    1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRGPUTOPIDLEPHASE1INLATENCY_BMSK                  0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_FW_INCR_GMUPWRGPUTOPIDLEPHASE1INLATENCY_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1110u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1110u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1114u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1114u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_0_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1118u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1118u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x111cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x111cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_1_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1120u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1120u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1124u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1124u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_2_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1128u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1128u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x112cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x112cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_3_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1130u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1130u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1134u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1134u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_4_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1138u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1138u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x113cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x113cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_5_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_L_ADDR                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1140u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_L_OFFS                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1140u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_L_RMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_L_COUNTLOW_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_L_COUNTLOW_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_H_ADDR                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1144u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_H_OFFS                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1144u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_H_RMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_H_COUNTHIGH_BMSK                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_0_H_COUNTHIGH_SHFT                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_L_ADDR                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1148u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_L_OFFS                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1148u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_L_RMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_L_COUNTLOW_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_L_COUNTLOW_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_H_ADDR                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x114cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_H_OFFS                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x114cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_H_RMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_H_COUNTHIGH_BMSK                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_GMUCLK_1_H_COUNTHIGH_SHFT                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_ADDR                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1180u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_OFFS                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1180u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_RMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_BMSK                 0xff000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_SHFT                         24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL9_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_BMSK                   0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_SHFT                         16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL8_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_BMSK                     0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_SHFT                          8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL7_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_BMSK                       0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_SHFT                          0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_SWITCHING_CYCLES_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_OFF_CYCLES_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_ON_SWITCHING_CYCLES_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_TOP_POWER_COLLAPSED_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_CYCLES_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_SWITCHING_CYCLES_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_OFF_CYCLES_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_ON_SWITCHING_CYCLES_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SPTPRAC_POWER_COLLAPSED_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_IN_LATENCY_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_IN_LATENCY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE1_OUT_LATENCY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_TOP_IDLE_PHASE2_OUT_LATENCY_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_VOID_FVAL          0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_TOTAL_THROTTLED_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_0_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_1_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_2_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_3_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_4_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_5_FVAL       0x15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_6_FVAL       0x16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_7_FVAL       0x17u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_8_FVAL       0x18u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_9_FVAL       0x19u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_NUM_GDPM_EPOCH_TOO_SHORT_INTR_FVAL       0x1au
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_NUM_GDPM_INVALID_OPCODE_INTR_FVAL       0x1bu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_NUM_MAX_THRESHOLD_BREACH_FVAL       0x1cu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_NUM_MIN_THRESHOLD_BREACH_FVAL       0x1du
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_CYCLE_MAX_THRESHOLD_BREACH_FVAL       0x1eu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_CYCLE_MIN_THRESHOLD_BREACH_FVAL       0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_BUSY_CYCLES_FVAL       0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_CYCLE_ALM_LOW_THROTTLE_CYCLES_FVAL       0x21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_CYCLE_ALM_HIGH_THROTTLE_CYCLES_FVAL       0x22u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_10_FVAL       0x23u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_SID_N_TOTAL_THROTTLED_CYCLES_11_FVAL       0x24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_CLX_TOTAL_THROTTLE_CYCLES_FVAL       0x25u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_LPAC_BUSY_CYCLES_FVAL       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_SELECT_2_GMUPOWERCOUNTERXOCLKSEL6_GMU_CX_0_GMU_PWC_GPU_OR_LPAC_BUSY_CYCLES_FVAL       0x31u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x11c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x11c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x11c4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x11c4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_6_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x11c8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x11c8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x11ccu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x11ccu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_7_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x11d0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x11d0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x11d4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x11d4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_8_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_L_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x11d8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_L_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x11d8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_L_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_L_COUNTLOW_BMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_L_COUNTLOW_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_H_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x11dcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_H_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x11dcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_H_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_H_COUNTHIGH_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_POWER_COUNTER_XOCLK_9_H_COUNTHIGH_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_RESET_ADDR                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x121cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_RESET_OFFS                                         (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x121cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_RESET_RMSK                                                0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_RESET_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_RESET_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_RESET_ALWAYSONCOUNTERRESET_BMSK                           0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_RESET_ALWAYSONCOUNTERRESET_SHFT                             0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_L_ADDR                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1220u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_L_OFFS                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1220u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_L_RMSK                                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_L_COUNTLOW_BMSK                                    0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_L_COUNTLOW_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_H_ADDR                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1224u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_H_OFFS                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1224u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_H_RMSK                                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_H_COUNTHIGH_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ALWAYS_ON_COUNTER_H_COUNTHIGH_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_ADDR                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1280u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_OFFS                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1280u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_RMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_GMUPERFCOUNTERENABLE_BMSK                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_ENABLE_GMUPERFCOUNTERENABLE_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_ADDR                                           (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1284u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_OFFS                                           (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1284u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_RMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_BMSK                        0xff000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_SHFT                                24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_CM3_BUSY_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_DATA_CACHE_READ_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_DATA_CACHE_READ_MISS_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_DATA_CACHE_WRITE_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_DATA_CACHE_WRITE_MISS_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_DATA_CACHE_EVICTIONS_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_MISS_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_MISS_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_SYS_AHB_WRITE_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_SYS_AHB_WRITE_BUFFER_MISS_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_SYS_AHB_READ_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_SYS_AHB_READ_BUFFER_MISS_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_DATA_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL        0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_DATA_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_INSTRUCTION_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_INSTRUCTION_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_SYS_VBIF_AHB_TOTAL_WAIT_CYCLES_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_SYS_AHB_TOTAL_WAIT_CYCLES_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL3_GMU_CX_0_GMU_TOTAL_INTR_LATENCY_CYCLES_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_BMSK                          0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_SHFT                                16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_CM3_BUSY_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_DATA_CACHE_READ_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_DATA_CACHE_READ_MISS_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_DATA_CACHE_WRITE_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_DATA_CACHE_WRITE_MISS_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_DATA_CACHE_EVICTIONS_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_MISS_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_MISS_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_SYS_AHB_WRITE_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_SYS_AHB_WRITE_BUFFER_MISS_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_SYS_AHB_READ_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_SYS_AHB_READ_BUFFER_MISS_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_DATA_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL        0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_DATA_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_INSTRUCTION_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_INSTRUCTION_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_SYS_VBIF_AHB_TOTAL_WAIT_CYCLES_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_SYS_AHB_TOTAL_WAIT_CYCLES_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL2_GMU_CX_0_GMU_TOTAL_INTR_LATENCY_CYCLES_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_BMSK                            0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_SHFT                                 8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_CM3_BUSY_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_DATA_CACHE_READ_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_DATA_CACHE_READ_MISS_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_DATA_CACHE_WRITE_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_DATA_CACHE_WRITE_MISS_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_DATA_CACHE_EVICTIONS_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_MISS_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_MISS_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_SYS_AHB_WRITE_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_SYS_AHB_WRITE_BUFFER_MISS_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_SYS_AHB_READ_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_SYS_AHB_READ_BUFFER_MISS_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_DATA_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL        0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_DATA_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_INSTRUCTION_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_INSTRUCTION_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_SYS_VBIF_AHB_TOTAL_WAIT_CYCLES_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_SYS_AHB_TOTAL_WAIT_CYCLES_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL1_GMU_CX_0_GMU_TOTAL_INTR_LATENCY_CYCLES_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_BMSK                              0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_SHFT                                 0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_CM3_BUSY_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_DATA_CACHE_READ_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_DATA_CACHE_READ_MISS_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_DATA_CACHE_WRITE_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_DATA_CACHE_WRITE_MISS_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_DATA_CACHE_EVICTIONS_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_MISS_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_MISS_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_SYS_AHB_WRITE_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_SYS_AHB_WRITE_BUFFER_MISS_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_SYS_AHB_READ_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_SYS_AHB_READ_BUFFER_MISS_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_DATA_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL        0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_DATA_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_INSTRUCTION_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_INSTRUCTION_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_SYS_VBIF_AHB_TOTAL_WAIT_CYCLES_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_SYS_AHB_TOTAL_WAIT_CYCLES_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_0_GMUPERFCOUNTERSEL0_GMU_CX_0_GMU_TOTAL_INTR_LATENCY_CYCLES_FVAL       0x14u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_ADDR                                           (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1288u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_OFFS                                           (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1288u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_RMSK                                               0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_BMSK                            0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_SHFT                                 8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_CM3_BUSY_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_DATA_CACHE_READ_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_DATA_CACHE_READ_MISS_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_DATA_CACHE_WRITE_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_DATA_CACHE_WRITE_MISS_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_DATA_CACHE_EVICTIONS_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_MISS_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_MISS_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_SYS_AHB_WRITE_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_SYS_AHB_WRITE_BUFFER_MISS_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_SYS_AHB_READ_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_SYS_AHB_READ_BUFFER_MISS_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_DATA_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL        0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_DATA_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_INSTRUCTION_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_INSTRUCTION_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_SYS_VBIF_AHB_TOTAL_WAIT_CYCLES_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_SYS_AHB_TOTAL_WAIT_CYCLES_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL5_GMU_CX_0_GMU_TOTAL_INTR_LATENCY_CYCLES_FVAL       0x14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_BMSK                              0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_SHFT                                 0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_CM3_BUSY_CYCLES_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_DATA_CACHE_READ_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_DATA_CACHE_READ_MISS_FVAL        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_DATA_CACHE_WRITE_FVAL        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_DATA_CACHE_WRITE_MISS_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_DATA_CACHE_EVICTIONS_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_L0_INSTRUCTION_CACHE_READ_MISS_FVAL        0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_L1_INSTRUCTION_CACHE_READ_MISS_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_SYS_AHB_WRITE_FVAL        0xau
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_SYS_AHB_WRITE_BUFFER_MISS_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_SYS_AHB_READ_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_SYS_AHB_READ_BUFFER_MISS_FVAL        0xdu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_DATA_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL        0xeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_DATA_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL        0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_INSTRUCTION_CACHE_AHB_TOTAL_WAIT_CYCLES_FVAL       0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_INSTRUCTION_CACHE_VBIF_TOTAL_WAIT_CYCLES_FVAL       0x11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_SYS_VBIF_AHB_TOTAL_WAIT_CYCLES_FVAL       0x12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_SYS_AHB_TOTAL_WAIT_CYCLES_FVAL       0x13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_SELECT_1_GMUPERFCOUNTERSEL4_GMU_CX_0_GMU_TOTAL_INTR_LATENCY_CYCLES_FVAL       0x14u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_L_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1290u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_L_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1290u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_L_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_L_COUNTLOW_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_L_COUNTLOW_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_H_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1294u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_H_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1294u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_H_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_H_COUNTHIGH_BMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_0_H_COUNTHIGH_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_L_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1298u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_L_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1298u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_L_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_L_COUNTLOW_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_L_COUNTLOW_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_H_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x129cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_H_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x129cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_H_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_H_COUNTHIGH_BMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_1_H_COUNTHIGH_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_L_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x12a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_L_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x12a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_L_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_L_COUNTLOW_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_L_COUNTLOW_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_H_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x12a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_H_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x12a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_H_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_H_COUNTHIGH_BMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_2_H_COUNTHIGH_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_L_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x12a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_L_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x12a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_L_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_L_COUNTLOW_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_L_COUNTLOW_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_H_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x12acu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_H_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x12acu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_H_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_H_COUNTHIGH_BMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_3_H_COUNTHIGH_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_L_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x12b0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_L_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x12b0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_L_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_L_COUNTLOW_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_L_COUNTLOW_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_H_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x12b4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_H_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x12b4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_H_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_H_COUNTHIGH_BMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_4_H_COUNTHIGH_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_L_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x12b8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_L_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x12b8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_L_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_L_COUNTLOW_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_L_COUNTLOW_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_H_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x12bcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_H_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x12bcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_H_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_H_COUNTHIGH_BMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PERF_COUNTER_5_H_COUNTHIGH_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_ADDR                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1300u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_OFFS                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1300u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_RMSK                                        0xfffffc03ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_MINPASSLENGTH_BMSK                          0xffffc000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_MINPASSLENGTH_SHFT                                  14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_NUMPASSSKIPSAFTERSHORTPASS_BMSK                 0x3c00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_NUMPASSSKIPSAFTERSHORTPASS_SHFT                     10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_HMPWRCOLEN_BMSK                                    0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_HMPWRCOLEN_SHFT                                      1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_IFPCENABLE_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_CTRL_IFPCENABLE_SHFT                                      0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_ADDR                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1304u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_OFFS                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1304u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_RMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_PWROFFSHORTHYSTERESIS_BMSK                  0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_PWROFFSHORTHYSTERESIS_SHFT                          16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_PWROFFMAINHYSTERESIS_BMSK                       0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_INTER_FRAME_HYST_PWROFFMAINHYSTERESIS_SHFT                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x130cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x130cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_RMSK                                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_HMKEEPALIVE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_KEEPALIVE_HMKEEPALIVE_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_ADDR                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1310u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_OFFS                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1310u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_RMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_HMPREMPTIONKEEPALIVE_BMSK                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_PREEMPTION_KEEPALIVE_HMPREMPTIONKEEPALIVE_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_ADDR                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1340u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_OFFS                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1340u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_RMSK                                                0xc0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_GXHMCLKOFF_BMSK                                     0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_GXHMCLKOFF_SHFT                                        7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_GXHMGDSCPOWEROFF_BMSK                               0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SPTPRAC_PWR_CLK_STATUS_GXHMGDSCPOWEROFF_SHFT                                  6u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_ADDR                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1390u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_OFFS                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1390u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_RMSK                                                         0x1f1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_SID_BMSK                                                     0x1f0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_SID_SHFT                                                         4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_ENABLE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_NAP_CTRL_ENABLE_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x13a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x13a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_RMSK                                                           0xff11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_GFXMINVOTEEN_BMSK                                              0x8000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_GFXMINVOTEEN_SHFT                                                  15u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_CXMINVOTEEN_BMSK                                               0x4000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_CXMINVOTEEN_SHFT                                                   14u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_MXMINVOTEEN_BMSK                                               0x2000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_MXMINVOTEEN_SHFT                                                   13u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_DDRMINVOTEEN_BMSK                                              0x1000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_DDRMINVOTEEN_SHFT                                                  12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_GFXVOTEEN_BMSK                                                  0x800u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_GFXVOTEEN_SHFT                                                     11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_CXVOTEEN_BMSK                                                   0x400u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_CXVOTEEN_SHFT                                                      10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_MXVOTEEN_BMSK                                                   0x200u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_MXVOTEEN_SHFT                                                       9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_DDRVOTEEN_BMSK                                                  0x100u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_DDRVOTEEN_SHFT                                                      8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_LLCVOTEEN_BMSK                                                   0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_LLCVOTEEN_SHFT                                                      4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_RPMINTERFACEENABLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_CTRL_RPMINTERFACEENABLE_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x13a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x13a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_CXMXHYST_BMSK                                         0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_CXMXHYST_SHFT                                                 16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_DDRLLCHYST_BMSK                                           0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_HYST_CTRL_DDRLLCHYST_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x13a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x13a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_RMSK                                                     0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_DDRMINBW_BMSK                                            0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_MIN_CONFIG_DDRMINBW_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x13acu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x13acu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_RMSK                                                      0xf1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_GFXVOTESTATUS_BMSK                                        0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_GFXVOTESTATUS_SHFT                                           7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_CXVOTESTATUS_BMSK                                         0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_CXVOTESTATUS_SHFT                                            6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_MXVOTESTATUS_BMSK                                         0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_MXVOTESTATUS_SHFT                                            5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_DDRVOTESTATUS_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_DDRVOTESTATUS_SHFT                                           4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_LLCVOTESTATUS_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_VOTE_STATUS_LLCVOTESTATUS_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x13b0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x13b0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_RMSK                                                       0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_POWERSTATE_BMSK                                            0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RPMH_POWER_STATE_POWERSTATE_SHFT                                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x13c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x13c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_RMSK                                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_FAL10VETO_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FAL_INTF_FAL10VETO_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x13c4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x13c4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_RMSK                                                        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_QACTIVE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CX_FALNEXT_INTF_QACTIVE_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1400u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1400u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_ADDITIONALINFO_BMSK                                   0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_ADDITIONALINFO_SHFT                                           16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_WORKLOADSIZE_BMSK                                         0xff00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_WORKLOADSIZE_SHFT                                              8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_SEQUENCENUM_BMSK                                            0xf0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_SEQUENCENUM_SHFT                                               4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_MARKER_BMSK                                                  0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_MSG_MARKER_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1404u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1404u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_RMSK                                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_ADDITIONALINFO_BMSK                                  0xfffffff0ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_ADDITIONALINFO_SHFT                                           4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_SEQUENCENUM_BMSK                                            0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_CP_RESP_SEQUENCENUM_SHFT                                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1408u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1408u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_RMSK                                                  0xff03fful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITDIRECTRENDERMARKERMESSAGE_BMSK                   0xf00000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITDIRECTRENDERMARKERMESSAGE_SHFT                         20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITPREEMPTIONREQMARKERMESSAGE_BMSK                   0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITPREEMPTIONREQMARKERMESSAGE_SHFT                        16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITDIRECTRENDERMARKEREN_BMSK                           0x200u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITDIRECTRENDERMARKEREN_SHFT                               9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITPREEMPTIONREQMARKEREN_BMSK                          0x100u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITPREEMPTIONREQMARKEREN_SHFT                              8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITRBCCUTYPE1MARKEREN_BMSK                              0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITRBCCUTYPE1MARKEREN_SHFT                                 7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITPOP2DMODMARKEREN_BMSK                                0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITPOP2DMODMARKEREN_SHFT                                   6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLIT2DMOD1AND2AND3MARKEREN_BMSK                          0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLIT2DMOD1AND2AND3MARKEREN_SHFT                             5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLIT2DMOD1AND2MARKEREN_BMSK                              0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLIT2DMOD1AND2MARKEREN_SHFT                                 4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLIT2DMOD1MARKEREN_BMSK                                   0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLIT2DMOD1MARKEREN_SHFT                                     3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITCOMPUTEMARKEREN_BMSK                                  0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITCOMPUTEMARKEREN_SHFT                                    2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITBINRENDERMARKEREN_BMSK                                0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITBINRENDERMARKEREN_SHFT                                  1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITBINNINGMARKEREN_BMSK                                  0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_EN_SPLITBINNINGMARKEREN_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_ADDR                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x140cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_OFFS                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x140cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITRBCCUTYPE1MARKERMESSAGE_BMSK               0xf0000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITRBCCUTYPE1MARKERMESSAGE_SHFT                       28u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITPOP2DMODEMARKERMESSAGE_BMSK                 0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITPOP2DMODEMARKERMESSAGE_SHFT                        24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLIT2DMOD1AND2AND3MARKERMESSAGE_BMSK             0xf00000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLIT2DMOD1AND2AND3MARKERMESSAGE_SHFT                   20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLIT2DMOD1AND2MARKERMESSAGE_BMSK                  0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLIT2DMOD1AND2MARKERMESSAGE_SHFT                       16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLIT2DMOD1MARKERMESSAGE_BMSK                       0xf000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLIT2DMOD1MARKERMESSAGE_SHFT                           12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITCOMPUTEMARKERMESSAGE_BMSK                       0xf00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITCOMPUTEMARKERMESSAGE_SHFT                           8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITBINRENDERMARKERMESSAGE_BMSK                      0xf0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITBINRENDERMARKERMESSAGE_SHFT                         4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITBINNINGMARKERMESSAGE_BMSK                         0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_COL_STALL_MARKER_SPLITBINNINGMARKERMESSAGE_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1440u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1440u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_TEMPDELTA_BMSK                                        0xff000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_TEMPDELTA_SHFT                                                24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_TEMPTHRESHOLDH_BMSK                                     0xfff000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_TEMPTHRESHOLDH_SHFT                                           12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_TEMPTHRESHOLDL_BMSK                                        0xfffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_0_TEMPTHRESHOLDL_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1444u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1444u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_TEMPDELTA_BMSK                                        0xff000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_TEMPDELTA_SHFT                                                24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_TEMPTHRESHOLDH_BMSK                                     0xfff000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_TEMPTHRESHOLDH_SHFT                                           12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_TEMPTHRESHOLDL_BMSK                                        0xfffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_THRESHOLD_1_TEMPTHRESHOLDL_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1480u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1480u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_RMSK                                                        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_INTREN_BMSK                                                 0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_EN_INTREN_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_STATUS_ADDR                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1484u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_STATUS_OFFS                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1484u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_STATUS_RMSK                                                    0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_STATUS_INTRSTATUS_BMSK                                         0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_STATUS_INTRSTATUS_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_CLR_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1488u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_CLR_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1488u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_CLR_RMSK                                                       0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_CLR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_CLR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_CLR_INTRCLR_BMSK                                               0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_HIGH_INTR_CLR_INTRCLR_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1490u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1490u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_RMSK                                                         0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_INTREN_BMSK                                                  0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_EN_INTREN_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_STATUS_ADDR                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1494u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_STATUS_OFFS                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1494u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_STATUS_RMSK                                                     0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_STATUS_INTRSTATUS_BMSK                                          0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_STATUS_INTRSTATUS_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_CLR_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1498u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_CLR_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1498u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_CLR_RMSK                                                        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_CLR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_CLR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_CLR_INTRCLR_BMSK                                                0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_LOW_INTR_CLR_INTRCLR_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x14a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x14a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_RMSK                                                       0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_INTREN_BMSK                                                0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_EN_INTREN_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_STATUS_ADDR                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x14a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_STATUS_OFFS                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x14a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_STATUS_RMSK                                                   0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_STATUS_INTRSTATUS_BMSK                                        0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_STATUS_INTRSTATUS_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_CLR_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x14a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_CLR_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x14a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_CLR_RMSK                                                      0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_CLR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_CLR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_CLR_INTRCLR_BMSK                                              0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_DELTA_INTR_CLR_INTRCLR_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x14b0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x14b0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_RMSK                                                      0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_INTREN_BMSK                                               0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_EN_INTREN_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_STATUS_ADDR                                           (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x14b4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_STATUS_OFFS                                           (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x14b4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_STATUS_RMSK                                                  0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_STATUS_INTRSTATUS_BMSK                                       0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_STATUS_INTRSTATUS_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_CLR_ADDR                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x14b8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_CLR_OFFS                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x14b8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_CLR_RMSK                                                     0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_CLR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_CLR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_CLR_INTRCLR_BMSK                                             0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_TSENSE_UPDATE_INTR_CLR_INTRCLR_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_ADDR                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1500u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_OFFS                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1500u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_RMSK                                              0xffff00f1ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_SPIDLEHYST_BMSK                                   0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_SPIDLEHYST_SHFT                                           16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_CLOCKCYCLECOUNTSEL_BMSK                                 0xf0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_CLOCKCYCLECOUNTSEL_SHFT                                    4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_RAMPTHROTTLEEN_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_RAMP_THROTTLE_CTRL_RAMPTHROTTLEEN_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1508u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1508u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_RMSK                                                          0x1f1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_FWCRCSID_BMSK                                                 0x1f0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_FWCRCSID_SHFT                                                     4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_FWCRCSET_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_FW_CRC_CTRL_FWCRCSET_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x150cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x150cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_RMSK                                                          0x1f1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_SWCRCSID_BMSK                                                 0x1f0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_SWCRCSID_SHFT                                                     4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_SWCRCSET_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_SW_CRC_CTRL_SWCRCSET_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1510u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1510u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_RMSK                                                     0x1f7fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_CURRENTSID_BMSK                                          0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_CURRENTSID_SHFT                                               8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_SLOWLASTUPDATE_BMSK                                        0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_SLOWLASTUPDATE_SHFT                                           6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_GPUIDLELASTUPDATE_BMSK                                     0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_GPUIDLELASTUPDATE_SHFT                                        5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_SWLASTUPDATE_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_SWLASTUPDATE_SHFT                                             4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_RUTLASTUPDATE_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_RUTLASTUPDATE_SHFT                                            3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_LLMLASTUPDATE_BMSK                                          0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_LLMLASTUPDATE_SHFT                                            2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_HWLASTUPDATE_BMSK                                           0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_HWLASTUPDATE_SHFT                                             1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_FWLASTUPDATE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CRC_CTRL_STATUS_FWLASTUPDATE_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1520u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1520u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_RMSK                                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_CALMUXSEL_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_MUX_SEL_CALMUXSEL_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_ADDR                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1524u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_OFFS                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1524u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_RMSK                                                   0x71u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_URGENTSID_BMSK                                         0x70u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_URGENTSID_SHFT                                            4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_URGENTSTEPEN_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_URGENTSTEPEN_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_ADDR                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1528u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_OFFS                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1528u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_RMSK                                             0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_URGENTSTEPACK_BMSK                               0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_URGENTSTEPACK_SHFT                                 2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_URGENTSTEPINVALID_BMSK                           0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_URGENTSTEPINVALID_SHFT                             1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_URGENTRAMPACTIVE_BMSK                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_CAL_URGENT_CRC_CTRL_STATUS_URGENTRAMPACTIVE_SHFT                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1530u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1530u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_RMSK                                                           0x3fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_VOLTAGEVALID_BMSK                                              0x20u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_VOLTAGEVALID_SHFT                                                 5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_SEQUENCERORDER_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_SEQUENCERORDER_SHFT                                               4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_VOLTAGEINDEX_BMSK                                               0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GPU_VOLTAGE_VOLTAGEINDEX_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1534u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1534u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_RMSK                                                   0x8000fffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_PWRTHRESHOLDVALID_BMSK                                 0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_PWRTHRESHOLDVALID_SHFT                                         31u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_PWRTHRESHOLDVALUE_BMSK                                     0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_PWR_THRESHOLD_PWRTHRESHOLDVALUE_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_ADDR                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x153cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_OFFS                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x153cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_RMSK                                       0xffff0ff1ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_AVERAGETHRESHOLD_BMSK                      0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_AVERAGETHRESHOLD_SHFT                              16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_AVERAGEDURATION_BMSK                            0xff0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_AVERAGEDURATION_SHFT                                4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_THRESHOLDENABLE_BMSK                              0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_AVERAGE_CURRENT_THRESHOLD_THRESHOLDENABLE_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_ADDR                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1540u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_OFFS                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1540u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_RMSK                                                        0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_CURRENTTHRESHOLD_BMSK                                       0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_THRESHOLD_CURRENTTHRESHOLD_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1544u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1544u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_GPULEAKAGECURRENT_BMSK                                0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_GPULEAKAGECURRENT_SHFT                                        16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_GPUTOTALCURRENT_BMSK                                      0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_GPU_CURRENT_GPUTOTALCURRENT_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_ADDR                                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1550u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_OFFS                                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1550u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_RMSK                                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_USELLMTHROTTLE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_CTRL_USELLMTHROTTLE_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_ADDR                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x155cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_OFFS                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x155cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_RMSK                                                    0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_STATEOFCHILD_BMSK                                       0x30u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_CTRL_STATEOFCHILD_SHFT                                          4u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_STATUS_ADDR                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1560u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_STATUS_OFFS                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1560u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_STATUS_RMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_STATUS_WAKEUPACK_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LLM_GLM_SLEEP_STATUS_WAKEUPACK_SHFT                                           1u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1574u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1574u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_RMSK                                                           0x57u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSEALLCGCENABLENONGXTOP_BMSK                                0x40u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSEALLCGCENABLENONGXTOP_SHFT                                   6u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSEEXTCALIBHMISOLATION_BMSK                                 0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSEEXTCALIBHMISOLATION_SHFT                                    4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSEALLCGCENABLEHM_BMSK                                       0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSEALLCGCENABLEHM_SHFT                                         2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSEINTCALIBENABLE_BMSK                                       0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSEINTCALIBENABLE_SHFT                                         1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSECGCENDISABLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_ISENSE_CTRL_ISENSECGCENDISABLE_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1588u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1588u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_RMSK                                                           0x1e08u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_DISABLECRCINTERFACE_BMSK                                       0x1000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_DISABLECRCINTERFACE_SHFT                                           12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_ENABLEGPUIDLETHROTTLE_BMSK                                      0x800u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_ENABLEGPUIDLETHROTTLE_SHFT                                         11u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_LMCURRENTTYPE_BMSK                                              0x400u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_LMCURRENTTYPE_SHFT                                                 10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_LMCURRENTSRC_BMSK                                               0x200u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_LMCURRENTSRC_SHFT                                                   9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_ALU2XEXECENABLE_BMSK                                              0x8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_CONFIG_ALU2XEXECENABLE_SHFT                                                3u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_RESULTS_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1590u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_RESULTS_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1590u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_RESULTS_RMSK                                                   0x1fffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_RESULTS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_RESULTS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_RESULTS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_RESULTS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_RESULTS_HISTTOTALPOWER_BMSK                                    0x1fffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_RESULTS_HISTTOTALPOWER_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1594u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1594u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_RMSK                                                        0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_HISTFIFOEN_BMSK                                             0x10u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_HISTFIFOEN_SHFT                                                4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_DEPTH_BMSK                                                   0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HIST_PWR_DEPTH_DEPTH_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1598u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1598u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_RMSK                                                   0xff1fe7ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMAVEDEPTHSEL2_BMSK                            0xe00000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMAVEDEPTHSEL2_SHFT                                  21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMLOWERTHROTTLERATE_BMSK                       0x1f0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMLOWERTHROTTLERATE_SHFT                             16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMHIGHERTHROTTLERATE_BMSK                        0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMHIGHERTHROTTLERATE_SHFT                             8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMEXITSEL_BMSK                                     0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMEXITSEL_SHFT                                        7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMSATURATESEL_BMSK                                 0x60u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMSATURATESEL_SHFT                                    5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMLOWERTHROTTLEENABLE_BMSK                          0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMLOWERTHROTTLEENABLE_SHFT                            2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMHIGHERTHROTTLEENABLE_BMSK                         0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMHIGHERTHROTTLEENABLE_SHFT                           1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMENABLE_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_CONFIG_ADAPTIVELMENABLE_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x159cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x159cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_RMSK                                                  0xff1fe7ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMAVEDEPTHSEL2_BMSK                           0xe00000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMAVEDEPTHSEL2_SHFT                                 21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMLOWERTHROTTLERATE_BMSK                      0x1f0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMLOWERTHROTTLERATE_SHFT                            16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMHIGHERTHROTTLERATE_BMSK                       0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMHIGHERTHROTTLERATE_SHFT                            8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMEXITSEL_BMSK                                    0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMEXITSEL_SHFT                                       7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMSATURATESEL_BMSK                                0x60u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMSATURATESEL_SHFT                                   5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMLOWERTHROTTLEENABLE_BMSK                         0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMLOWERTHROTTLEENABLE_SHFT                           2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMHIGHERTHROTTLEENABLE_BMSK                        0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMHIGHERTHROTTLEENABLE_SHFT                          1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMENABLE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_CONFIG_ADAPTIVELMENABLE_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15a0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_RMSK                                                    0xff1fe7ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMAVEDEPTHSEL2_BMSK                             0xe00000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMAVEDEPTHSEL2_SHFT                                   21u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMLOWERTHROTTLERATE_BMSK                        0x1f0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMLOWERTHROTTLERATE_SHFT                              16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMHIGHERTHROTTLERATE_BMSK                         0x1f00u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMHIGHERTHROTTLERATE_SHFT                              8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMEXITSEL_BMSK                                      0x80u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMEXITSEL_SHFT                                         7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMSATURATESEL_BMSK                                  0x60u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMSATURATESEL_SHFT                                     5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMLOWERTHROTTLEENABLE_BMSK                           0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMLOWERTHROTTLEENABLE_SHFT                             2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMHIGHERTHROTTLEENABLE_BMSK                          0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMHIGHERTHROTTLEENABLE_SHFT                            1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMENABLE_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_CONFIG_ADAPTIVELMENABLE_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_ADDR                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_OFFS                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15a4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_ADAPTIVELMLOWERTHRESHOLD_BMSK                     0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_ADAPTIVELMLOWERTHRESHOLD_SHFT                             16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_ADAPTIVELMHIGHERTHRESHOLD_BMSK                        0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_SHORT_THRESHOLD_ADAPTIVELMHIGHERTHRESHOLD_SHFT                             0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_ADDR                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_OFFS                                             (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15a8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_RMSK                                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_ADAPTIVELMLOWERTHRESHOLD_BMSK                    0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_ADAPTIVELMLOWERTHRESHOLD_SHFT                            16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_ADAPTIVELMHIGHERTHRESHOLD_BMSK                       0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_MEDIUM_THRESHOLD_ADAPTIVELMHIGHERTHRESHOLD_SHFT                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15acu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15acu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_ADAPTIVELMLOWERTHRESHOLD_BMSK                      0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_ADAPTIVELMLOWERTHRESHOLD_SHFT                              16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_ADAPTIVELMHIGHERTHRESHOLD_BMSK                         0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_LM_LONG_THRESHOLD_ADAPTIVELMHIGHERTHRESHOLD_SHFT                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_ADDR                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_OFFS                                                     (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_RMSK                                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_CLRACCUM_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CLEAR_ACCUM_CMD_CLRACCUM_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15c4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15c4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_RMSK                                                             0x7u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_ISENSETOTPWRACCUMEN_BMSK                                         0x4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_ISENSETOTPWRACCUMEN_SHFT                                           2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_DCELKGPWRACCUMEN_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_DCELKGPWRACCUMEN_SHFT                                              1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_DCETOTPWRACCUMEN_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_EN_DCETOTPWRACCUMEN_SHFT                                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15c8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15c8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_RMSK                                                  0x7001ffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_SHIFT_BMSK                                            0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_SHIFT_SHFT                                                   24u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_DELTATH_BMSK                                             0x1fffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_DCE_ISENSE_DELTA_TH_DELTATH_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15ccu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15ccu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_RMSK                                                              0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_DPMLKGIPENABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GDPM_LKG_CTRL_DPMLKGIPENABLE_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_L_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15d0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_L_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15d0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_L_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_L_LKGL_BMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_L_LKGL_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_H_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15d4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_H_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15d4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_H_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_H_LKGH_BMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_LKG_DCE_H_LKGH_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_L_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15d8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_L_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15d8u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_L_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_L_TOTL_BMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_L_TOTL_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_H_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15dcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_H_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15dcu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_H_RMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_H_TOTH_BMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_DCE_H_TOTH_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_L_ADDR                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15e0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_L_OFFS                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15e0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_L_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_L_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_L_TOTL_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_L_TOTL_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_H_ADDR                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x15e4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_H_OFFS                                            (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x15e4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_H_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_H_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_H_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_H_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_H_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_H_TOTH_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_ACCUM_POWER_TOT_ISENSE_H_TOTH_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_ADDR                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1600u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_OFFS                                                 (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1600u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_RMSK                                                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_ADDITIONALSTATUS_BMSK                                0xffffff00ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_ADDITIONALSTATUS_SHFT                                         8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_ERRORSTATUS_BMSK                                           0xfeu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_ERRORSTATUS_SHFT                                              1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_HFISTATUS_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_STATUS_HFISTATUS_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1604u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1604u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_MAJOR_BMSK                                          0xf0000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_MAJOR_SHFT                                                  28u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_MINOR_BMSK                                           0xfffffe0ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_MINOR_SHFT                                                   5u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_BRANCH_BMSK                                               0x1fu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_VERSION_INFO_BRANCH_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_ADDR                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1608u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_OFFS                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1608u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_RMSK                                                    0xfffffffcul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_STARTADDR_BMSK                                          0xfffffffcul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_SFR_ADDR_STARTADDR_SHFT                                                   2u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x160cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x160cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_RMSK                                                   0xfffffffcul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_MMAPADDR_BMSK                                          0xfffffffcul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_MMAP_ADDR_MMAPADDR_SHFT                                                   2u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1610u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1610u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_RMSK                                                         0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_ADDR_BMSK                                                    0xffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_INFO_ADDR_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1614u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1614u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_RMSK                                                   0xfffffffcul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_QTBLADDR_BMSK                                          0xfffffffcul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_QTBL_ADDR_QTBLADDR_SHFT                                                   2u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1618u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1618u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_RMSK                                                          0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_INITSTATUS_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HFI_CTRL_INIT_INITSTATUS_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_SET_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1640u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_SET_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1640u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_SET_RMSK                                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_SET_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_SET_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_SET_INTRSET_BMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_SET_INTRSET_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_CLR_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1644u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_CLR_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1644u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_CLR_RMSK                                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_CLR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_CLR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_CLR_INTRCLR_BMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_CLR_INTRCLR_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_INFO_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1648u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_INFO_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1648u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_INFO_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_INFO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_INFO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_INFO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_INFO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_INFO_INTRINFO_BMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_INFO_INTRINFO_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x164cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x164cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_INTRMASK_BMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU2HOST_INTR_MASK_INTRMASK_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_SET_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1650u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_SET_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1650u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_SET_RMSK                                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_SET_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_SET_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_SET_INTRSET_BMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_SET_INTRSET_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_CLR_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1654u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_CLR_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1654u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_CLR_RMSK                                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_CLR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_CLR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_CLR_INTRCLR_BMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_CLR_INTRCLR_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_RAW_INFO_ADDR                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1658u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_RAW_INFO_OFFS                                              (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1658u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_RAW_INFO_RMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_RAW_INFO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_RAW_INFO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_RAW_INFO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_RAW_INFO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_RAW_INFO_INTRRAWINFO_BMSK                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_RAW_INFO_INTRRAWINFO_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x165cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x165cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_INTREN_BMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_0_INTREN_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1660u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1660u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_INTREN_BMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_1_INTREN_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1664u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1664u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_INTREN_BMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_2_INTREN_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1668u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1668u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_INTREN_BMSK                                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_EN_3_INTREN_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_0_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x166cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_0_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x166cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_0_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_0_INTRINFO_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_0_INTRINFO_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_1_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1670u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_1_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1670u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_1_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_1_INTRINFO_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_1_INTRINFO_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_2_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1674u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_2_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1674u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_2_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_2_INTRINFO_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_2_INTRINFO_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_3_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1678u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_3_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1678u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_3_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_3_INTRINFO_BMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_HOST2GMU_INTR_INFO_3_INTRINFO_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1700u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1700u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_RMSK                                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_MAJOR_BMSK                                                0xf0000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_MAJOR_SHFT                                                        28u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_MINOR_BMSK                                                 0xfff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_MINOR_SHFT                                                        16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_STEP_BMSK                                                     0xffffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_HW_VERSION_STEP_SHFT                                                          0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1714u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1714u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_0_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1718u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1718u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_1_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x171cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x171cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_2_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1720u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1720u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_3_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1724u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1724u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_4_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1728u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1728u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_5_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x172cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x172cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_6_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1730u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1730u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_7_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1734u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1734u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_8_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1738u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1738u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_GENERAL_BMSK                                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_9_GENERAL_SHFT                                                        0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x173cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x173cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_RMSK                                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_GENERAL_BMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_10_GENERAL_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1740u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1740u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_RMSK                                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_GENERAL_BMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_11_GENERAL_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1744u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1744u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_RMSK                                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_GENERAL_BMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_12_GENERAL_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1748u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1748u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_RMSK                                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_GENERAL_BMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_13_GENERAL_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x174cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x174cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_RMSK                                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_GENERAL_BMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_14_GENERAL_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_ADDR                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1750u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_OFFS                                                      (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1750u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_RMSK                                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_GENERAL_BMSK                                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_GENERAL_15_GENERAL_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_ADDR                                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1780u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_OFFS                                                        (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1780u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_RMSK                                                        0x1fff1ffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_TEMPVALID1_BMSK                                             0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_TEMPVALID1_SHFT                                                     28u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_TEMPVALUE1_BMSK                                              0xfff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_TEMPVALUE1_SHFT                                                     16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_TEMPVALID0_BMSK                                                 0x1000u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_TEMPVALID0_SHFT                                                     12u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_TEMPVALUE0_BMSK                                                  0xfffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_VAL_TEMPVALUE0_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_ADDR                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1784u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_OFFS                                                  (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1784u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_RMSK                                                   0xfff0ffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_TEMPTHRESHOLDH_BMSK                                    0xfff0000ul
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_TEMPTHRESHOLDH_SHFT                                           16u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_TEMPTHRESHOLDL_BMSK                                        0xfffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_THRESHOLD_TEMPTHRESHOLDL_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_ADDR                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1788u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_OFFS                                          (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1788u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_RMSK                                               0xfffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_TEMP1CINTRTHRD_BMSK                                0xfffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_TEMP_1C_INTR_THRESHOLD_TEMP1CINTRTHRD_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_ADDR                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x17c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_OFFS                                               (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x17c0u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_RMSK                                                    0x3ffu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_LLMHWSTATUS_BMSK                                        0x200u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_LLMHWSTATUS_SHFT                                            9u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_LMHFEATURESTATUS_BMSK                                   0x100u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_LMHFEATURESTATUS_SHFT                                       8u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_BCLSTATUS_BMSK                                           0xf0u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_BCLSTATUS_SHFT                                              4u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_ISENSECALIBSTATUS_BMSK                                    0xfu
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_BOOT_KMD_LM_HANDSHAKE_ISENSECALIBSTATUS_SHFT                                      0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_ADDR                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x17c4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_OFFS                                                       (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x17c4u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_RMSK                                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_CHICKENBIT_BMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_CHICKEN_BIT_0_CHICKENBIT_SHFT                                                     0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_ADDR                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1800u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_OFFS                                                    (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1800u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_RMSK                                                           0x3u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_STCMD_BMSK                                                     0x2u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_STCMD_SHFT                                                       1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_LDCMD_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_CMD_LDCMD_SHFT                                                       0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_ADDR                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1804u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_OFFS                                                   (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1804u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_RMSK                                                   0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_LDSTADDR_BMSK                                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_ADDR_LDSTADDR_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x1808u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x1808u)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_LDSTDATALO_BMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_LO_LDSTDATALO_SHFT                                              0u

#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_ADDR                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE      + 0x180cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_OFFS                                                (SAIL_TO_MD_GPU_GMU_CX_BLK_DEC0_REG_BASE_OFFS + 0x180cu)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_RMSK                                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_LDSTDATAHI_BMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_GMU_CX_GMU_MRC_LDST_DATA_HI_LDSTDATAHI_SHFT                                              0u


#endif /* __G_SAIL_TO_MD_GPU_GMU_CX_HWIO_H__ */
