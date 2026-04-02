#ifndef G_SAIL_TO_MD_GPU_GBIF_HWIO_H
#define G_SAIL_TO_MD_GPU_GBIF_HWIO_H
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_GPU_GBIF_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        MonacoAU [monacoau_v1.0_p3q3r53_MTO_rpm]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_GPU_GBIF_BLK_DEC0


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_GPU_GBIF_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_GPU_GBIF_BLK_DEC0'],
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
 * MODULE: SAIL_TO_MD_GPU_GBIF_BLK_DEC0
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE                                           (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x03d0c000UL)
#define SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_SIZE                                      0x14000UL
#define SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_USED                                      0x3344U
#define SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS                                      0x03d0c000UL

#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3000U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3000U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_RMSK                                         0x1fffcfffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_CGCTRLCGCKEEPON_BMSK                         0x1c000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_CGCTRLCGCKEEPON_SHFT                                 26U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_CGCTRLCGCKEEPONHYST_BMSK                      0x3c00000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_CGCTRLCGCKEEPONHYST_SHFT                             22U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_CGCTRLCGCDELAY_BMSK                            0x380000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_CGCTRLCGCDELAY_SHFT                                  19U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_CGCTRLMODE_BMSK                                 0x70000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_CGCTRLMODE_SHFT                                      16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_FORCECLKON_BMSK                                  0x8000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_FORCECLKON_SHFT                                      15U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_QOSARBITRATIONEN_BMSK                            0x4000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_QOSARBITRATIONEN_SHFT                                14U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_READDATACNTL_BMSK                                 0xc00U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_READDATACNTL_SHFT                                    10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_WRITEREQCNTL_BMSK                                 0x300U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_WRITEREQCNTL_SHFT                                     8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_READREQCNTL_BMSK                                   0xc0U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_READREQCNTL_SHFT                                      6U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_RFDEPTH_BMSK                                       0x30U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_RFDEPTH_SHFT                                          4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_DISABLERUF_BMSK                                     0x8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_DISABLERUF_SHFT                                       3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_EXTRBUBBLE_BMSK                                     0x4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_EXTRBUBBLE_SHFT                                       2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_RTNEXTRDLY_BMSK                                     0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_RTNEXTRDLY_SHFT                                       1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_REQEXTRDLY_BMSK                                     0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_CX_CONFIG_REQEXTRDLY_SHFT                                       0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_ADDR                                      (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3004U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_OFFS                                      (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3004U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_RMSK                                           0x10fU
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_GFOEN_BMSK                                     0x100U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_GFOEN_SHFT                                         8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_RNOALLOCVALUE_BMSK                               0x8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_RNOALLOCVALUE_SHFT                                 3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_RNOALLOCORIDEEN_BMSK                             0x4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_RNOALLOCORIDEEN_SHFT                               2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_WNOALLOCVALUE_BMSK                               0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_WNOALLOCVALUE_SHFT                                 1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_WNOALLOCORIDEEN_BMSK                             0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL0_WNOALLOCORIDEEN_SHFT                               0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_ADDR                                      (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3008U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_OFFS                                      (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3008U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_RMSK                                      0x3fffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORGMU_BMSK                           0x3e000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORGMU_SHFT                                   25U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORFLAG_BMSK                           0x1f00000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORFLAG_SHFT                                  20U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORCCU_BMSK                              0xf8000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORCCU_SHFT                                   15U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORVFD_BMSK                               0x7c00U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORVFD_SHFT                                   10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORTP_BMSK                                 0x3e0U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORTP_SHFT                                     5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORCP_BMSK                                  0x1fU
#define HWIO_SAIL_TO_MD_GPU_GBIF_SCACHE_CNTL1_SCIDFORCP_SHFT                                     0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x300cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x300cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_RMSK                                            0x7ffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIABURST_BMSK                                  0x40000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIABURST_SHFT                                       18U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAPROTNS_BMSK                                 0x20000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAPROTNS_SHFT                                      17U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIASHARE_BMSK                                  0x10000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIASHARE_SHFT                                       16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAINNERSHARE_BMSK                              0x8000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAINNERSHARE_SHFT                                  15U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIADEVICE_BMSK                                  0x4000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIADEVICE_SHFT                                      14U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIADEVICETYPE_BMSK                              0x2000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIADEVICETYPE_SHFT                                  13U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIACACHEABLE_BMSK                               0x1000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIACACHEABLE_SHFT                                   12U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAINNERCACHEABLE_BMSK                           0x800U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAINNERCACHEABLE_SHFT                              11U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAOOORD_BMSK                                    0x400U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAOOORD_SHFT                                       10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAOOOWR_BMSK                                    0x200U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAOOOWR_SHFT                                        9U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIANOALLOC_BMSK                                  0x100U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIANOALLOC_SHFT                                      8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIATRANSIENT_BMSK                                 0x80U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIATRANSIENT_SHFT                                    7U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIARDBEATNDXEN_BMSK                               0x40U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIARDBEATNDXEN_SHFT                                  6U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIASSDNDEX_BMSK                                   0x20U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIASSDNDEX_SHFT                                      5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIASSID_BMSK                                      0x10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIASSID_SHFT                                         4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAMSSSELFAUTH_BMSK                                0x8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAMSSSELFAUTH_SHFT                                  3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAREDIRECT_BMSK                                   0x4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIAREDIRECT_SHFT                                     2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIASSDINDEX_BMSK                                   0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXIASSDINDEX_SHFT                                     1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXINLOS_BMSK                                        0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE0_AXINLOS_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3010U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3010U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_RMSK                                            0x7ffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIABURST_BMSK                                  0x40000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIABURST_SHFT                                       18U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAPROTNS_BMSK                                 0x20000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAPROTNS_SHFT                                      17U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIASHARE_BMSK                                  0x10000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIASHARE_SHFT                                       16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAINNERSHARE_BMSK                              0x8000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAINNERSHARE_SHFT                                  15U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIADEVICE_BMSK                                  0x4000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIADEVICE_SHFT                                      14U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIADEVICETYPE_BMSK                              0x2000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIADEVICETYPE_SHFT                                  13U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIACACHEABLE_BMSK                               0x1000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIACACHEABLE_SHFT                                   12U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAINNERCACHEABLE_BMSK                           0x800U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAINNERCACHEABLE_SHFT                              11U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAOOORD_BMSK                                    0x400U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAOOORD_SHFT                                       10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAOOOWR_BMSK                                    0x200U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAOOOWR_SHFT                                        9U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIANOALLOC_BMSK                                  0x100U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIANOALLOC_SHFT                                      8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIATRANSIENT_BMSK                                 0x80U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIATRANSIENT_SHFT                                    7U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIARDBEATNDXEN_BMSK                               0x40U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIARDBEATNDXEN_SHFT                                  6U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIASSDNDEX_BMSK                                   0x20U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIASSDNDEX_SHFT                                      5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIASSID_BMSK                                      0x10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIASSID_SHFT                                         4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAMSSSELFAUTH_BMSK                                0x8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAMSSSELFAUTH_SHFT                                  3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAREDIRECT_BMSK                                   0x4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIAREDIRECT_SHFT                                     2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIASSDINDEX_BMSK                                   0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXIASSDINDEX_SHFT                                     1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXINLOS_BMSK                                        0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE1_AXINLOS_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3014U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3014U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_RMSK                                            0x7ffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIABURST_BMSK                                  0x40000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIABURST_SHFT                                       18U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAPROTNS_BMSK                                 0x20000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAPROTNS_SHFT                                      17U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIASHARE_BMSK                                  0x10000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIASHARE_SHFT                                       16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAINNERSHARE_BMSK                              0x8000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAINNERSHARE_SHFT                                  15U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIADEVICE_BMSK                                  0x4000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIADEVICE_SHFT                                      14U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIADEVICETYPE_BMSK                              0x2000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIADEVICETYPE_SHFT                                  13U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIACACHEABLE_BMSK                               0x1000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIACACHEABLE_SHFT                                   12U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAINNERCACHEABLE_BMSK                           0x800U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAINNERCACHEABLE_SHFT                              11U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAOOORD_BMSK                                    0x400U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAOOORD_SHFT                                       10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAOOOWR_BMSK                                    0x200U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAOOOWR_SHFT                                        9U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIANOALLOC_BMSK                                  0x100U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIANOALLOC_SHFT                                      8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIATRANSIENT_BMSK                                 0x80U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIATRANSIENT_SHFT                                    7U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIARDBEATNDXEN_BMSK                               0x40U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIARDBEATNDXEN_SHFT                                  6U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIASSDNDEX_BMSK                                   0x20U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIASSDNDEX_SHFT                                      5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIASSID_BMSK                                      0x10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIASSID_SHFT                                         4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAMSSSELFAUTH_BMSK                                0x8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAMSSSELFAUTH_SHFT                                  3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAREDIRECT_BMSK                                   0x4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIAREDIRECT_SHFT                                     2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIASSDINDEX_BMSK                                   0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXIASSDINDEX_SHFT                                     1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXINLOS_BMSK                                        0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE2_AXINLOS_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3018U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3018U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_RMSK                                            0x7ffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIABURST_BMSK                                  0x40000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIABURST_SHFT                                       18U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAPROTNS_BMSK                                 0x20000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAPROTNS_SHFT                                      17U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIASHARE_BMSK                                  0x10000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIASHARE_SHFT                                       16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAINNERSHARE_BMSK                              0x8000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAINNERSHARE_SHFT                                  15U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIADEVICE_BMSK                                  0x4000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIADEVICE_SHFT                                      14U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIADEVICETYPE_BMSK                              0x2000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIADEVICETYPE_SHFT                                  13U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIACACHEABLE_BMSK                               0x1000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIACACHEABLE_SHFT                                   12U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAINNERCACHEABLE_BMSK                           0x800U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAINNERCACHEABLE_SHFT                              11U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAOOORD_BMSK                                    0x400U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAOOORD_SHFT                                       10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAOOOWR_BMSK                                    0x200U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAOOOWR_SHFT                                        9U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIANOALLOC_BMSK                                  0x100U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIANOALLOC_SHFT                                      8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIATRANSIENT_BMSK                                 0x80U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIATRANSIENT_SHFT                                    7U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIARDBEATNDXEN_BMSK                               0x40U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIARDBEATNDXEN_SHFT                                  6U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIASSDNDEX_BMSK                                   0x20U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIASSDNDEX_SHFT                                      5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIASSID_BMSK                                      0x10U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIASSID_SHFT                                         4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAMSSSELFAUTH_BMSK                                0x8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAMSSSELFAUTH_SHFT                                  3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAREDIRECT_BMSK                                   0x4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIAREDIRECT_SHFT                                     2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIASSDINDEX_BMSK                                   0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXIASSDINDEX_SHFT                                     1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXINLOS_BMSK                                        0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE3_AXINLOS_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x301cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x301cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_RMSK                                         0x1fff1fffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_AXIAMIDC1_BMSK                               0x1fe00000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_AXIAMIDC1_SHFT                                       21U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_AXIAVMIDC1_BMSK                                0x1f0000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_AXIAVMIDC1_SHFT                                      16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_AXIAWMIDC0_BMSK                                  0x1fe0U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_AXIAWMIDC0_SHFT                                       5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_AXIAMIDC0_BMSK                                     0x1fU
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE4_AXIAMIDC0_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3020U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3020U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_RMSK                                         0x1fff1fffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_AXIAMIDC1_BMSK                               0x1fe00000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_AXIAMIDC1_SHFT                                       21U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_AXIAVMIDC1_BMSK                                0x1f0000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_AXIAVMIDC1_SHFT                                      16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_AXIAWMIDC0_BMSK                                  0x1fe0U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_AXIAWMIDC0_SHFT                                       5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_AXIAMIDC0_BMSK                                     0x1fU
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE5_AXIAMIDC0_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3024U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3024U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_RMSK                                         0x1fffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_SYSTEMCACHESIDEBANDOVERRIDEEN_BMSK           0x10000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_SYSTEMCACHESIDEBANDOVERRIDEEN_SHFT                   28U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIACACHEOPTYPE_BMSK                          0xf000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIACACHEOPTYPE_SHFT                                 24U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIWBID_BMSK                                   0xe00000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIWBID_SHFT                                         21U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIWPID_BMSK                                   0x1f0000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIWPID_SHFT                                         16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIHURRYLVL_BMSK                                 0xe000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIHURRYLVL_SHFT                                     13U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIASCID_BMSK                                    0x1f00U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIASCID_SHFT                                         8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIABID_BMSK                                       0xe0U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIABID_SHFT                                          5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIAPID_BMSK                                       0x1fU
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE6_AXIAPID_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3028U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3028U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_RMSK                                         0x1fffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_SYSTEMCACHESIDEBANDOVERRIDEEN_BMSK           0x10000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_SYSTEMCACHESIDEBANDOVERRIDEEN_SHFT                   28U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIACACHEOPTYPE_BMSK                          0xf000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIACACHEOPTYPE_SHFT                                 24U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIWBID_BMSK                                   0xe00000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIWBID_SHFT                                         21U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIWPID_BMSK                                   0x1f0000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIWPID_SHFT                                         16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIHURRYLVL_BMSK                                 0xe000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIHURRYLVL_SHFT                                     13U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIASCID_BMSK                                    0x1f00U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIASCID_SHFT                                         8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIABID_BMSK                                       0xe0U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIABID_SHFT                                          5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIAPID_BMSK                                       0x1fU
#define HWIO_SAIL_TO_MD_GPU_GBIF_QSB_SIDE7_AXIAPID_SHFT                                          0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_ADDR                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x302cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_OFFS                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x302cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_RMSK                                        0x1fffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_SYSTEMCACHESIDEBANDOVERRIDEEN_BMSK          0x10000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_SYSTEMCACHESIDEBANDOVERRIDEEN_SHFT                  28U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIACACHEOPTYPE_BMSK                         0xf000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIACACHEOPTYPE_SHFT                                24U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIWBID_BMSK                                  0xe00000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIWBID_SHFT                                        21U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIWPID_BMSK                                  0x1f0000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIWPID_SHFT                                        16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIHURRYLVL_BMSK                                0xe000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIHURRYLVL_SHFT                                    13U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIASCID_BMSK                                   0x1f00U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIASCID_SHFT                                        8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIABID_BMSK                                      0xe0U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIABID_SHFT                                         5U
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIAPID_BMSK                                      0x1fU
#define HWIO_SAIL_TO_MD_GPU_GBIF_XIN_CONFIG_AXIAPID_SHFT                                         0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_ADDR                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3100U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_OFFS                                         (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3100U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_RMSK                                           0xff0ff1UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_AXIDBGSEL3_BMSK                                0xf00000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_AXIDBGSEL3_SHFT                                      20U
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_AXIDBGSEL2_BMSK                                 0xf0000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_AXIDBGSEL2_SHFT                                      16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_AXIDBGSEL1_BMSK                                   0xf00U
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_AXIDBGSEL1_SHFT                                       8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_AXIDBGSEL0_BMSK                                    0xf0U
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_AXIDBGSEL0_SHFT                                       4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_DBGEN_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_CTL_DBGEN_SHFT                                            0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA0_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3104U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA0_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3104U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA0_RMSK                                       0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA0_DBGDATA_BMSK                               0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA0_DBGDATA_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA1_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3108U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA1_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3108U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA1_RMSK                                       0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA1_DBGDATA_BMSK                               0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_DEBUG_DATA1_DBGDATA_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ADDR                                              (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3114U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_OFFS                                              (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3114U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_RMSK                                                     0x3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_HALT_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ARBHALT_BMSK                                             0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ARBHALT_SHFT                                               1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_CLIENTHALT_BMSK                                          0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_CLIENTHALT_SHFT                                            0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_ADDR                                          (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3118U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_OFFS                                          (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3118U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_RMSK                                                 0x3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_ARBHALTACK_BMSK                                      0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_ARBHALTACK_SHFT                                        1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_CLIENTHALTACK_BMSK                                   0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_HALT_ACK_CLIENTHALTACK_SHFT                                     0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_ADDR                                     (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x311cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_OFFS                                     (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x311cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_RMSK                                     0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXIWRITEVALID_BMSK                       0xc0000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXIWRITEVALID_SHFT                               30U
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXI1WRITEMID_BMSK                        0x3f800000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXI1WRITEMID_SHFT                                23U
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXI0WRITEMID_BMSK                          0x7f0000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXI0WRITEMID_SHFT                                16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXIREADVALID_BMSK                            0xc000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXIREADVALID_SHFT                                14U
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXI1READMID_BMSK                             0x3f80U
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXI1READMID_SHFT                                  7U
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXI0READMID_BMSK                               0x7fU
#define HWIO_SAIL_TO_MD_GPU_GBIF_INTERRUPT_LOG_AXI0READMID_SHFT                                  0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_ENABLE_ADDR                                     (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3124U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_ENABLE_OFFS                                     (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3124U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_ENABLE_RMSK                                            0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_ENABLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_ENABLE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_ENABLE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_ENABLE_REINITEN_BMSK                                   0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_ENABLE_REINITEN_SHFT                                     0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3128U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3128U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_RMSK                                              0xfU
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_CYC_PENDING1_GX_BMSK                              0x8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_CYC_PENDING1_GX_SHFT                                3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_CYC_PENDING0_GX_BMSK                              0x4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_CYC_PENDING0_GX_SHFT                                2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_GBIF_CX_IDLE_BMSK                                 0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_GBIF_CX_IDLE_SHFT                                   1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_GBIF_GX_IDLE_BMSK                                 0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_REINIT_DONE_GBIF_GX_IDLE_SHFT                                   0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_ADDR                                   (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3300U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_OFFS                                   (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3300U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_RMSK                                      0x7000fUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PWRCNT2EN_BMSK                            0x40000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PWRCNT2EN_SHFT                                 18U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PWRCNT1EN_BMSK                            0x20000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PWRCNT1EN_SHFT                                 17U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PWRCNT0EN_BMSK                            0x10000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PWRCNT0EN_SHFT                                 16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PERFCNT3EN_BMSK                               0x8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PERFCNT3EN_SHFT                                 3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PERFCNT2EN_BMSK                               0x4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PERFCNT2EN_SHFT                                 2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PERFCNT1EN_BMSK                               0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PERFCNT1EN_SHFT                                 1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PERFCNT0EN_BMSK                               0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_EN_PERFCNT0EN_SHFT                                 0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_ADDR                                  (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3304U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_OFFS                                  (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3304U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_RMSK                                  0x8007800fUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PWRCNTCLRALL_BMSK                     0x80000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PWRCNTCLRALL_SHFT                             31U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PWRCNT2CLR_BMSK                          0x40000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PWRCNT2CLR_SHFT                               18U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PWRCNT1CLR_BMSK                          0x20000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PWRCNT1CLR_SHFT                               17U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PWRCNT0CLR_BMSK                          0x10000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PWRCNT0CLR_SHFT                               16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNTCLRALL_BMSK                        0x8000U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNTCLRALL_SHFT                            15U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNT3CLR_BMSK                             0x8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNT3CLR_SHFT                               3U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNT2CLR_BMSK                             0x4U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNT2CLR_SHFT                               2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNT1CLR_BMSK                             0x2U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNT1CLR_SHFT                               1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNT0CLR_BMSK                             0x1U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_PWR_CNT_CLR_PERFCNT0CLR_SHFT                               0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_ADDR                                      (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3308U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_OFFS                                      (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3308U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_RMSK                                      0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_PERFCNT3SEL_BMSK                          0xff000000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_PERFCNT3SEL_SHFT                                  24U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_PERFCNT2SEL_BMSK                            0xff0000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_PERFCNT2SEL_SHFT                                  16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_PERFCNT1SEL_BMSK                              0xff00U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_PERFCNT1SEL_SHFT                                   8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_PERFCNT0SEL_BMSK                                0xffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_SEL_PERFCNT0SEL_SHFT                                   0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x330cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x330cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_RMSK                                         0xffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_IN)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_PWRCNT2SEL_BMSK                              0xff0000UL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_PWRCNT2SEL_SHFT                                    16U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_PWRCNT1SEL_BMSK                                0xff00U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_PWRCNT1SEL_SHFT                                     8U
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_PWRCNT0SEL_BMSK                                  0xffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_SEL_PWRCNT0SEL_SHFT                                     0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L0_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3310U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L0_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3310U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L0_RMSK                                       0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L0_PERFCNTL0_BMSK                             0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L0_PERFCNTL0_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L1_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3314U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L1_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3314U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L1_RMSK                                       0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L1_PERFCNTL1_BMSK                             0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L1_PERFCNTL1_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L2_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3318U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L2_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3318U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L2_RMSK                                       0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L2_PERFCNTL2_BMSK                             0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L2_PERFCNTL2_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L3_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x331cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L3_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x331cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L3_RMSK                                       0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L3_PERFCNTL3_BMSK                             0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_L3_PERFCNTL3_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H0_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3320U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H0_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3320U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H0_RMSK                                           0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H0_PERFCNTH0_BMSK                                 0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H0_PERFCNTH0_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H1_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3324U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H1_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3324U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H1_RMSK                                           0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H1_PERFCNTH1_BMSK                                 0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H1_PERFCNTH1_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H2_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3328U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H2_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3328U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H2_RMSK                                           0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H2_PERFCNTH2_BMSK                                 0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H2_PERFCNTH2_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H3_ADDR                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x332cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H3_OFFS                                       (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x332cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H3_RMSK                                           0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H3_PERFCNTH3_BMSK                                 0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PERF_CNT_H3_PERFCNTH3_SHFT                                      0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L0_ADDR                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3330U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L0_OFFS                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3330U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L0_RMSK                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L0_PWRCNTL0_BMSK                               0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L0_PWRCNTL0_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L1_ADDR                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3334U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L1_OFFS                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3334U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L1_RMSK                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L1_PWRCNTL1_BMSK                               0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L1_PWRCNTL1_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L2_ADDR                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3338U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L2_OFFS                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3338U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L2_RMSK                                        0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L2_PWRCNTL2_BMSK                               0xffffffffUL
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_L2_PWRCNTL2_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H0_ADDR                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x333cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H0_OFFS                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x333cU)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H0_RMSK                                            0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H0_PWRCNTH0_BMSK                                   0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H0_PWRCNTH0_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H1_ADDR                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3340U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H1_OFFS                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3340U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H1_RMSK                                            0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H1_PWRCNTH1_BMSK                                   0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H1_PWRCNTH1_SHFT                                        0U

#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H2_ADDR                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE      + 0x3344U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H2_OFFS                                        (SAIL_TO_MD_GPU_GBIF_BLK_DEC0_REG_BASE_OFFS + 0x3344U)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H2_RMSK                                            0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H2_PWRCNTH2_BMSK                                   0xffffU
#define HWIO_SAIL_TO_MD_GPU_GBIF_PWR_CNT_H2_PWRCNTH2_SHFT                                        0U


#endif /* G_SAIL_TO_MD_GPU_GBIF_HWIO_H */
