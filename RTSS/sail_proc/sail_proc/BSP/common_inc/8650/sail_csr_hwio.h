#ifndef __SAIL_CSR_HWIO_H__
#define __SAIL_CSR_HWIO_H__
/*
===========================================================================
*/
/**
    @file sail_csr_hwio.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_CSR_SAILSS_CSR


    Generation parameters: 
    { 'filename': 'sail_csr_hwio.h',
      'header': '#include "msmhwiobase.h"',
      'integer-qualifiers': True,
      'modules': ['SAILSS_CSR_SAILSS_CSR'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/common_inc/8650/sail_csr_hwio.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_CSR_SAILSS_CSR
 *--------------------------------------------------------------------------*/

#define SAILSS_CSR_SAILSS_CSR_REG_BASE                                                                                    (SAILSS_CSR_SAILSS_CSR_BASE      + 0x00000000u)
#define SAILSS_CSR_SAILSS_CSR_REG_BASE_SIZE                                                                               0xa000u
#define SAILSS_CSR_SAILSS_CSR_REG_BASE_USED                                                                               0x90f8u
#define SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS                                                                               0x00000000u

#define HWIO_SAILSS_CSR_SPARE_CSR0_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1cu)
#define HWIO_SAILSS_CSR_SPARE_CSR0_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAILSS_CSR_SPARE_CSR0_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_CSR0_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_CSR0_ADDR)
#define HWIO_SAILSS_CSR_SPARE_CSR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_CSR0_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_CSR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_CSR0_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_CSR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_CSR0_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_CSR0_IN)
#define HWIO_SAILSS_CSR_SPARE_CSR0_SPARE_BMSK                                                                             0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_CSR0_SPARE_SHFT                                                                                      0u

#define HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_ADDR                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x24u)
#define HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_OFFS                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x24u)
#define HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_RMSK                                                                                  0x3u
#define HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_ADDR)
#define HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_ADDR, m)
#define HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_ADDR,v)
#define HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_ADDR,m,v,HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_IN)
#define HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_SPARE_BMSK                                                                            0x3u
#define HWIO_SAILSS_CSR_SAILSS_DEBUG_SPARE_SPARE_SHFT                                                                              0u

#define HWIO_SAILSS_CSR_SAIL_HW_VER_ADDR                                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x28u)
#define HWIO_SAILSS_CSR_SAIL_HW_VER_OFFS                                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x28u)
#define HWIO_SAILSS_CSR_SAIL_HW_VER_RMSK                                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_SAIL_HW_VER_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_HW_VER_ADDR)
#define HWIO_SAILSS_CSR_SAIL_HW_VER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_HW_VER_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_HW_VER_FAMILY_NUMBER_BMSK                                                                    0xf0000000ul
#define HWIO_SAILSS_CSR_SAIL_HW_VER_FAMILY_NUMBER_SHFT                                                                            28u
#define HWIO_SAILSS_CSR_SAIL_HW_VER_DEVICE_NUMBER_BMSK                                                                     0xfff0000ul
#define HWIO_SAILSS_CSR_SAIL_HW_VER_DEVICE_NUMBER_SHFT                                                                            16u
#define HWIO_SAILSS_CSR_SAIL_HW_VER_MAJOR_VERSION_BMSK                                                                        0xff00u
#define HWIO_SAILSS_CSR_SAIL_HW_VER_MAJOR_VERSION_SHFT                                                                             8u
#define HWIO_SAILSS_CSR_SAIL_HW_VER_MINOR_VERSION_BMSK                                                                          0xffu
#define HWIO_SAILSS_CSR_SAIL_HW_VER_MINOR_VERSION_SHFT                                                                             0u

#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x38u)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x38u)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_IN                    \
                in_dword(HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR, m)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR,v)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR,m,v,HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_IN)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_FAMILY_NUMBER_BMSK                                                   0xf0000000ul
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_FAMILY_NUMBER_SHFT                                                           28u
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_DEVICE_NUMBER_BMSK                                                    0xfff0000ul
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_DEVICE_NUMBER_SHFT                                                           16u
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_MAJOR_VERSION_BMSK                                                       0xff00u
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_MAJOR_VERSION_SHFT                                                            8u
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_MINOR_VERSION_BMSK                                                         0xffu
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_MINOR_VERSION_SHFT                                                            0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_ADDR                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x40u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_OFFS                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x40u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_RMSK                                                                           0x7fffeul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_CFGMPIDRAFF1_BMSK                                                              0x7f800ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_CFGMPIDRAFF1_SHFT                                                                   11u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_CFGMPIDRAFF2_BMSK                                                                0x7f8u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_CFGMPIDRAFF2_SHFT                                                                    3u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_CFGINITREG_BMSK                                                                    0x4u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_CFGINITREG_SHFT                                                                      2u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_CFGRAMPROTEN_BMSK                                                                  0x2u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CONFIG0_CFGRAMPROTEN_SHFT                                                                    1u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x44u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x44u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGHALT_BMSK                                                           0x80000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGHALT_SHFT                                                                   31u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGENDIANESS_BMSK                                                      0x40000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGENDIANESS_SHFT                                                              30u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGTHUMBEXCEPTIONS_BMSK                                                0x20000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGTHUMBEXCEPTIONS_SHFT                                                        29u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGL1CACHEINVDIS_BMSK                                                  0x10000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGL1CACHEINVDIS_SHFT                                                          28u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGTCMBOOT_BMSK                                                         0x8000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGTCMBOOT_SHFT                                                                27u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGVECTABLE_BMSK                                                        0x7fffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0_CFGVECTABLE_SHFT                                                                0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x48u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x48u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGHALT_BMSK                                                           0x80000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGHALT_SHFT                                                                   31u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGENDIANESS_BMSK                                                      0x40000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGENDIANESS_SHFT                                                              30u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGTHUMBEXCEPTIONS_BMSK                                                0x20000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGTHUMBEXCEPTIONS_SHFT                                                        29u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGL1CACHEINVDIS_BMSK                                                  0x10000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGL1CACHEINVDIS_SHFT                                                          28u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGTCMBOOT_BMSK                                                         0x8000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGTCMBOOT_SHFT                                                                27u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGVECTABLE_BMSK                                                        0x7fffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0_CFGVECTABLE_SHFT                                                                0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_ADDR                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x4cu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_OFFS                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x4cu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_RMSK                                                                           0x7fffeul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_CFGMPIDRAFF1_BMSK                                                              0x7f800ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_CFGMPIDRAFF1_SHFT                                                                   11u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_CFGMPIDRAFF2_BMSK                                                                0x7f8u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_CFGMPIDRAFF2_SHFT                                                                    3u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_CFGINITREG_BMSK                                                                    0x4u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_CFGINITREG_SHFT                                                                      2u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_CFGRAMPROTEN_BMSK                                                                  0x2u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CONFIG0_CFGRAMPROTEN_SHFT                                                                    1u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGHALT_BMSK                                                           0x80000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGHALT_SHFT                                                                   31u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGENDIANESS_BMSK                                                      0x40000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGENDIANESS_SHFT                                                              30u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGTHUMBEXCEPTIONS_BMSK                                                0x20000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGTHUMBEXCEPTIONS_SHFT                                                        29u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGL1CACHEINVDIS_BMSK                                                  0x10000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGL1CACHEINVDIS_SHFT                                                          28u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGTCMBOOT_BMSK                                                         0x8000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGTCMBOOT_SHFT                                                                27u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGVECTABLE_BMSK                                                        0x7fffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0_CFGVECTABLE_SHFT                                                                0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGHALT_BMSK                                                           0x80000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGHALT_SHFT                                                                   31u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGENDIANESS_BMSK                                                      0x40000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGENDIANESS_SHFT                                                              30u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGTHUMBEXCEPTIONS_BMSK                                                0x20000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGTHUMBEXCEPTIONS_SHFT                                                        29u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGL1CACHEINVDIS_BMSK                                                  0x10000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGL1CACHEINVDIS_SHFT                                                          28u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGTCMBOOT_BMSK                                                         0x8000000ul
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGTCMBOOT_SHFT                                                                27u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGVECTABLE_BMSK                                                        0x7fffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0_CFGVECTABLE_SHFT                                                                0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x58u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x58u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_COMPARATOR_ID_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN_COMPARATOR_ID_SHFT                                                              0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5cu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5cu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_COMPARATOR_ID_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC_COMPARATOR_ID_SHFT                                                             0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_ADDR                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x60u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_OFFS                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x60u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_RMSK                                                             0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_COMPARATOR_ID_BMSK                                               0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_COMPARATOR_ID_SHFT                                                        0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_CLEAR_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x64u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_CLEAR_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x64u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_CLEAR_RMSK                                                              0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_CLEAR_CLEAR_BMSK                                                        0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_CLEAR_CLEAR_SHFT                                                          0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x68u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x68u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_COMPARATOR_ID_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN_COMPARATOR_ID_SHFT                                                              0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6cu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6cu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_COMPARATOR_ID_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC_COMPARATOR_ID_SHFT                                                             0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_ADDR                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x70u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_OFFS                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x70u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_RMSK                                                             0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_COMPARATOR_ID_BMSK                                               0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_COMPARATOR_ID_SHFT                                                        0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_CLEAR_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x74u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_CLEAR_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x74u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_CLEAR_RMSK                                                              0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_CLEAR_CLEAR_BMSK                                                        0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_CLEAR_CLEAR_SHFT                                                          0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_ADDR(n)                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0X80 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_OFFS(n)                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0X80 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_MAXn                                                                              1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_ADDR(n), HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_RMSK)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_ADDR(n), mask)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_ADDR(n),val)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_ADDR(n),mask,val,HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_INI(n))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_ERROR_ID_BMSK                                                            0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_EN_n_ERROR_ID_SHFT                                                                     0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_ADDR(n)                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0X88 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_OFFS(n)                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0X88 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_MAXn                                                                        1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_ADDR(n), HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_RMSK)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_ADDR(n), mask)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_ERROR_ID_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_n_ERROR_ID_SHFT                                                               0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_CLEAR_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_CLEAR_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_CLEAR_RMSK                                                                  0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_CLEAR_CLEAR_BMSK                                                            0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_CLEAR_CLEAR_SHFT                                                              0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_ADDR(n)                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0XA0 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_OFFS(n)                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0XA0 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_MAXn                                                                              1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_ADDR(n), HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_RMSK)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_ADDR(n), mask)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_ADDR(n),val)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_ADDR(n),mask,val,HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_INI(n))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_ERROR_ID_BMSK                                                            0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_EN_n_ERROR_ID_SHFT                                                                     0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_ADDR(n)                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0XA8 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_OFFS(n)                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0XA8 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_MAXn                                                                        1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_ADDR(n), HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_RMSK)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_ADDR(n), mask)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_ERROR_ID_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_n_ERROR_ID_SHFT                                                               0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_CLEAR_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0xb0u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_CLEAR_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0xb0u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_CLEAR_RMSK                                                                  0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_CLEAR_CLEAR_BMSK                                                            0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_CLEAR_CLEAR_SHFT                                                              0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0xb4u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0xb4u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_WARNING_ID_BMSK                                                          0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_EN_WARNING_ID_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_ADDR                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0xb8u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_OFFS                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0xb8u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_WARNING_ID_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_WARNING_ID_SHFT                                                             0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_CLEAR_ADDR                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0xbcu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_CLEAR_OFFS                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0xbcu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_CLEAR_RMSK                                                                0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_CLEAR_CLEAR_BMSK                                                          0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME_CLEAR_CLEAR_SHFT                                                            0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0xc0u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0xc0u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_IN)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_WARNING_ID_BMSK                                                          0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_EN_WARNING_ID_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_ADDR                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0xc8u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_OFFS                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0xc8u)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_WARNING_ID_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_WARNING_ID_SHFT                                                             0u

#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_CLEAR_ADDR                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0xccu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_CLEAR_OFFS                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0xccu)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_CLEAR_RMSK                                                                0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_CLEAR_CLEAR_BMSK                                                          0x1u
#define HWIO_SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME_CLEAR_CLEAR_SHFT                                                            0u

#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_ADDR(n)                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0XE0 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_OFFS(n)                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0XE0 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_RMSK                                                                    0xffffful
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_MAXn                                                                          3u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_ADDR(n), HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_RMSK)
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_ADDR(n), mask)
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_DCACHE_COUNT_BMSK                                                       0xf0000ul
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_DCACHE_COUNT_SHFT                                                            16u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_ICACHE_COUNT_BMSK                                                        0xf000u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_ICACHE_COUNT_SHFT                                                            12u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CTCM_COUNT_BMSK                                                           0xf00u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CTCM_COUNT_SHFT                                                               8u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_BTCM_COUNT_BMSK                                                            0xf0u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_BTCM_COUNT_SHFT                                                               4u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_ATCM_COUNT_BMSK                                                             0xfu
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_ATCM_COUNT_SHFT                                                               0u

#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CLEAR_ADDR(n)                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0XF0 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CLEAR_OFFS(n)                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0XF0 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CLEAR_RMSK                                                                  0x1u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CLEAR_MAXn                                                                    3u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CLEAR_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CLEAR_ADDR(n),val)
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CLEAR_CLEAR_BMSK                                                            0x1u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_MEMORY_PROFILING_CLEAR_CLEAR_SHFT                                                              0u

#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_ADDR(n)                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0X100 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_OFFS(n)                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0X100 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_RMSK                                                                            0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_MAXn                                                                                    29u
#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_ADDR(n), HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_RMSK)
#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_ADDR(n), mask)
#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_ADDR(n),val)
#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_ADDR(n),mask,val,HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_INI(n))
#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_SPI_NUMBER_BMSK                                                                 0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_SPI_NUMBER_SHFT                                                                          0u

#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_ADDR                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1f0u)
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_OFFS                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1f0u)
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_RMSK                                                                           0x1ffu
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_ADDR)
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_IN)
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_COUNT_BMSK                                                                     0x1feu
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_COUNT_SHFT                                                                         1u
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_ENABLE_BMSK                                                                      0x1u
#define HWIO_SAILSS_CSR_RTCU_WARM_RESET_CONTROL_ENABLE_SHFT                                                                        0u

#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_ADDR                                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1f4u)
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_OFFS                                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1f4u)
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_RMSK                                                                                   0x1fu
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_ADDR)
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_IN)
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLREXMON_LOOPBACK_BMSK                                                                 0x10u
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLREXMON_LOOPBACK_SHFT                                                                    4u
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLUSTER1_CLREXMONREQ_EN_BMSK                                                            0x8u
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLUSTER1_CLREXMONREQ_EN_SHFT                                                              3u
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLUSTER0_CLREXMONREQ_EN_BMSK                                                            0x4u
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLUSTER0_CLREXMONREQ_EN_SHFT                                                              2u
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLUSTER1_EVENTI_EN_BMSK                                                                 0x2u
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLUSTER1_EVENTI_EN_SHFT                                                                   1u
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLUSTER0_EVENTI_EN_BMSK                                                                 0x1u
#define HWIO_SAILSS_CSR_RTCU_WFE_CONTROL_CLUSTER0_EVENTI_EN_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_RTCU_CONTROL_ADDR                                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1f8u)
#define HWIO_SAILSS_CSR_RTCU_CONTROL_OFFS                                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1f8u)
#define HWIO_SAILSS_CSR_RTCU_CONTROL_RMSK                                                                                 0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_CONTROL_ADDR)
#define HWIO_SAILSS_CSR_RTCU_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CONTROL_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_CONTROL_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CONTROL_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_CONTROL_IN)
#define HWIO_SAILSS_CSR_RTCU_CONTROL_CONTROL_BIT_BMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_CONTROL_CONTROL_BIT_SHFT                                                                              0u

#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_ADDR                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1fcu)
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_OFFS                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1fcu)
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_RMSK                                                                         0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_ADDR)
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_IN)
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_SPARE_BIT_BMSK                                                               0xffffff00ul
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_SPARE_BIT_SHFT                                                                        8u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_CORE_3_MEM_AGG_INJ_BMSK                                                            0x80u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_CORE_3_MEM_AGG_INJ_SHFT                                                               7u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_CORE_2_MEM_AGG_INJ_BMSK                                                            0x40u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_CORE_2_MEM_AGG_INJ_SHFT                                                               6u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_CORE_1_MEM_AGG_INJ_BMSK                                                            0x20u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_CORE_1_MEM_AGG_INJ_SHFT                                                               5u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_CORE_0_MEM_AGG_INJ_BMSK                                                            0x10u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_CORE_0_MEM_AGG_INJ_SHFT                                                               4u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_WDOG_3_FAULT_INJ_BMSK                                                               0x8u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_WDOG_3_FAULT_INJ_SHFT                                                                 3u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_WDOG_2_FAULT_INJ_BMSK                                                               0x4u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_WDOG_2_FAULT_INJ_SHFT                                                                 2u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_WDOG_1_FAULT_INJ_BMSK                                                               0x2u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_WDOG_1_FAULT_INJ_SHFT                                                                 1u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_WDOG_0_FAULT_INJ_BMSK                                                               0x1u
#define HWIO_SAILSS_CSR_RTCU_FAULT_INJECTION_WDOG_0_FAULT_INJ_SHFT                                                                 0u

#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_ADDR                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x200u)
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_OFFS                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x200u)
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_RMSK                                                                             0xffffu
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_ADDR)
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_ADDR, m)
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_ADDR,v)
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_ADDR,m,v,HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_IN)
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE3_LIVELOCK_BMSK                                                              0x8000u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE3_LIVELOCK_SHFT                                                                  15u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE2_LIVELOCK_BMSK                                                              0x4000u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE2_LIVELOCK_SHFT                                                                  14u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE1_LIVELOCK_BMSK                                                              0x2000u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE1_LIVELOCK_SHFT                                                                  13u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE0_LIVELOCK_BMSK                                                              0x1000u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE0_LIVELOCK_SHFT                                                                  12u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE3_WDOG_BITE_BMSK                                                              0x800u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE3_WDOG_BITE_SHFT                                                                 11u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE2_WDOG_BITE_BMSK                                                              0x400u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE2_WDOG_BITE_SHFT                                                                 10u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE1_WDOG_BITE_BMSK                                                              0x200u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE1_WDOG_BITE_SHFT                                                                  9u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE0_WDOG_BITE_BMSK                                                              0x100u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_CORE0_WDOG_BITE_SHFT                                                                  8u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_LIVELOCK_PRIORITY_BMSK                                                             0xf0u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_LIVELOCK_PRIORITY_SHFT                                                                4u
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_WDOG_BITE_PRIORITY_BMSK                                                             0xfu
#define HWIO_SAILSS_CSR_RTCU_PS_HOLD_CONTROL_WDOG_BITE_PRIORITY_SHFT                                                               0u

#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_ADDR(n)                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0X300 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_OFFS(n)                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0X300 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_RMSK                                                                            0x1ffu
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_MAXn                                                                                3u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_ADDR(n), HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_RMSK)
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_ADDR(n), mask)
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_ADDR(n),val)
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_ADDR(n),mask,val,HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_INI(n))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_PPI_NUMBER_BMSK                                                                 0x1ffu
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_PPI_NUMBER_SHFT                                                                     0u

#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_ADDR(n)                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0X500 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_OFFS(n)                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0X500 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_RMSK                                                                              0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_MAXn                                                                                      29u
#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_ADDR(n), HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_RMSK)
#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_ADDR(n), mask)
#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_ADDR(n),val)
#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_ADDR(n),mask,val,HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_INI(n))
#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_SPI_NUMBER_BMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_RTCU_SPI_MASK_n_SPI_NUMBER_SHFT                                                                            0u

#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_ADDR(n)                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0X700 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_OFFS(n)                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0X700 + (0x4*(n)))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_RMSK                                                                              0x1ffu
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_MAXn                                                                                  3u
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_ADDR(n), HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_RMSK)
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_ADDR(n), mask)
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_ADDR(n),val)
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_ADDR(n),mask,val,HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_INI(n))
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_PPI_NUMBER_BMSK                                                                   0x1ffu
#define HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_MASK_PPI_NUMBER_SHFT                                                                       0u

#define HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_ADDR                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1004u)
#define HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_OFFS                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1004u)
#define HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_RMSK                                                                             0x1u
#define HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_IN                    \
                in_dword(HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_ADDR)
#define HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_ADDR, m)
#define HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_ADDR,v)
#define HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_ADDR,m,v,HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_IN)
#define HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_START_BMSK                                                                       0x1u
#define HWIO_SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET_START_SHFT                                                                         0u

#define HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_ADDR                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1008u)
#define HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_OFFS                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1008u)
#define HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_RMSK                                                                              0xffu
#define HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_IN                    \
                in_dword(HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_ADDR)
#define HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_ADDR, m)
#define HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_ADDR,v)
#define HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_ADDR,m,v,HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_IN)
#define HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_TERM_VAL_BMSK                                                                     0xffu
#define HWIO_SAILSS_CSR_LBIST_CHIP_RESET_TERM_TERM_VAL_SHFT                                                                        0u

#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_ADDR                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x100cu)
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_OFFS                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x100cu)
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_RMSK                                                                                0x1ffu
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_ADDR)
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_ADDR, m)
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_ADDR,v)
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_ADDR,m,v,HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_IN)
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_DETECTION_EN_BMSK                                                                   0x100u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_DETECTION_EN_SHFT                                                                       8u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_IGD_FAULT_INJECTION_BMSK                                                             0x80u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_IGD_FAULT_INJECTION_SHFT                                                                7u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_INPUT_GLITCH_DETECTED_BMSK                                                           0x40u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_INPUT_GLITCH_DETECTED_SHFT                                                              6u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_OVERRIDE_EN_BMSK                                                                     0x20u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_OVERRIDE_EN_SHFT                                                                        5u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_CAPTURE_EN_BMSK                                                                      0x10u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_CAPTURE_EN_SHFT                                                                         4u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_INPUT_ISO_ENABLE_BMSK                                                                 0xcu
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_INPUT_ISO_ENABLE_SHFT                                                                   2u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_ARC_ISO_ENB_BMSK                                                                      0x3u
#define HWIO_SAILSS_CSR_SAFETY_ISO_CONTROL_ARC_ISO_ENB_SHFT                                                                        0u

#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1014u)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1014u)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_RMSK                                                                          0xffffful
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_ADDR)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_ADDR, m)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_ADDR,v)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_ADDR,m,v,HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_IN)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_PWD_CHECK_EN_BMSK                                                             0xf0000ul
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_PWD_CHECK_EN_SHFT                                                                  16u
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_PWD_VALUE_BMSK                                                                 0xffffu
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_CONTROL_PWD_VALUE_SHFT                                                                      0u

#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_ADDR                                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1018u)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_OFFS                                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1018u)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_RMSK                                                                                   0xffffu
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAFETY_CSR_PWD_ADDR)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAFETY_CSR_PWD_ADDR, m)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAFETY_CSR_PWD_ADDR,v)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAFETY_CSR_PWD_ADDR,m,v,HWIO_SAILSS_CSR_SAFETY_CSR_PWD_IN)
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_PWD_CSR_VALUE_BMSK                                                                     0xffffu
#define HWIO_SAILSS_CSR_SAFETY_CSR_PWD_PWD_CSR_VALUE_SHFT                                                                          0u

#define HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_ADDR                                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x101cu)
#define HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_OFFS                                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x101cu)
#define HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_RMSK                                                                             0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_ADDR)
#define HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_IN)
#define HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_SPARE_BMSK                                                                       0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_OUTPUT_CSR_SPARE_SHFT                                                                                0u

#define HWIO_SAILSS_CSR_SPARE_CSR1_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1020u)
#define HWIO_SAILSS_CSR_SPARE_CSR1_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1020u)
#define HWIO_SAILSS_CSR_SPARE_CSR1_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_CSR1_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_CSR1_ADDR)
#define HWIO_SAILSS_CSR_SPARE_CSR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_CSR1_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_CSR1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_CSR1_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_CSR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_CSR1_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_CSR1_IN)
#define HWIO_SAILSS_CSR_SPARE_CSR1_SPARE_BMSK                                                                             0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_CSR1_SPARE_SHFT                                                                                      0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1024u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1024u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_RMSK                                                                       0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_FUSA_ERROR_MASK_4_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_4_FUSA_ERROR_MASK_4_SHFT                                                              0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1028u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1028u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_RMSK                                                                       0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_FUSA_ERROR_MASK_5_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_5_FUSA_ERROR_MASK_5_SHFT                                                              0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x102cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x102cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_RMSK                                                                       0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_FUSA_ERROR_MASK_6_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_6_FUSA_ERROR_MASK_6_SHFT                                                              0u

#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1030u)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1030u)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_ADDR)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_ADDR, m)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_ADDR,v)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_ADDR,m,v,HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_IN)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_CSR_BMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_OVERRIDE_CSR_SHFT                                                                        0u

#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_ADDR                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1034u)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_OFFS                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1034u)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_ADDR)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_ADDR, m)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_ADDR,v)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_ADDR,m,v,HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_IN)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_CSR_BMSK                                                           0xfffffffful
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_OVERRIDE_CSR_SHFT                                                                    0u

#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_ADDR                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1038u)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_OFFS                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1038u)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_RMSK                                                                      0xfffffffful
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_ADDR)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_ADDR, m)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_ADDR,v)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_ADDR,m,v,HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_IN)
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_CSR_BMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_SAILSS_QUPV3_INTR_VALUE_CSR_SHFT                                                                           0u

#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x103cu)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x103cu)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_ADDR)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_ADDR, m)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_ADDR,v)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_ADDR,m,v,HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_IN)
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_CSR_BMSK                                                              0xfffffffful
#define HWIO_SAILSS_CSR_SAILSS_NON_QUPV3_INTR_VALUE_CSR_SHFT                                                                       0u

#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_ADDR                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1040u)
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_OFFS                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1040u)
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_RMSK                                                                           0xfffffffful
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_ADDR)
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_ADDR, m)
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_ADDR,v)
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_ADDR,m,v,HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_IN)
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_ARC2BM_TESTBUS_SEL_BMSK                                                        0xc0000000ul
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_ARC2BM_TESTBUS_SEL_SHFT                                                                30u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AXIS_TESTBUS_SEL_BMSK                                                          0x3f000000ul
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AXIS_TESTBUS_SEL_SHFT                                                                  24u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AXIM_TESTBUS_SEL_BMSK                                                            0xfc0000ul
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AXIM_TESTBUS_SEL_SHFT                                                                  18u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AHBE_TESTBUS_SEL_BMSK                                                             0x38000ul
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AHBE_TESTBUS_SEL_SHFT                                                                  15u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AHB_DEC_TESTBUS_SEL_BMSK                                                           0x7000u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AHB_DEC_TESTBUS_SEL_SHFT                                                               12u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_PRAM_TESTBUS_SEL_BMSK                                                               0xf00u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_PRAM_TESTBUS_SEL_SHFT                                                                   8u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AHBM_TESTBUS_SEL_BMSK                                                                0xc0u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AHBM_TESTBUS_SEL_SHFT                                                                   6u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AHBS_TESTBUS_SEL_BMSK                                                                0x30u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_AHBS_TESTBUS_SEL_SHFT                                                                   4u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_GPIO_TESTBUS_SEL_BMSK                                                                 0xcu
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_GPIO_TESTBUS_SEL_SHFT                                                                   2u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_TESTBUS_SEL_BMSK                                                                      0x3u
#define HWIO_SAILSS_CSR_SAILSS_TESTBUS_SEL_TESTBUS_SEL_SHFT                                                                        0u

#define HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1044u)
#define HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1044u)
#define HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_RMSK                                                                              0x1u
#define HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_ADDR)
#define HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_ADDR, m)
#define HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_ADDR,v)
#define HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_ADDR,m,v,HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_IN)
#define HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_ENABLE_BMSK                                                                       0x1u
#define HWIO_SAILSS_CSR_SAILSS_AHB2AHB_POST_EN_ENABLE_SHFT                                                                         0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1048u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1048u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_RMSK                                                                       0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_FUSA_ERROR_MASK_2_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_2_FUSA_ERROR_MASK_2_SHFT                                                              0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x104cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x104cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_RMSK                                                                       0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_FUSA_ERROR_MASK_3_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_3_FUSA_ERROR_MASK_3_SHFT                                                              0u

#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_ADDR                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1050u)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_OFFS                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1050u)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_RMSK                                                                                     0x1u
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_ADDR)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_ADDR, m)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_ADDR,v)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_ADDR,m,v,HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_IN)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_CFG_SM_ERR_BMSK                                                                          0x1u
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_0_CFG_SM_ERR_SHFT                                                                            0u

#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_ADDR                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1054u)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_OFFS                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1054u)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_RMSK                                                                                0x1ffffful
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_ADDR)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_ADDR, m)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_ADDR,v)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_ADDR,m,v,HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_IN)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_CFG_SM_ERROR_TIMER_VAL_BMSK                                                         0x1ffffeul
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_CFG_SM_ERROR_TIMER_VAL_SHFT                                                                1u
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_CFG_SM_ERROR_TIMER_EN_BMSK                                                               0x1u
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_1_CFG_SM_ERROR_TIMER_EN_SHFT                                                                 0u

#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_ADDR                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1058u)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_OFFS                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1058u)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_RMSK                                                                                     0x1u
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_IN                    \
                in_dword(HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_ADDR)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_ADDR, m)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_ADDR,v)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_ADDR,m,v,HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_IN)
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_CFG_SW_ASSERT_ERR_BMSK                                                                   0x1u
#define HWIO_SAILSS_CSR_SM_ERROR_CTRL_2_CFG_SW_ASSERT_ERR_SHFT                                                                     0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x105cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x105cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_RMSK                                                                       0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_FUSA_ERROR_MASK_0_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_0_FUSA_ERROR_MASK_0_SHFT                                                              0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1060u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1060u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_RMSK                                                                       0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_FUSA_ERROR_MASK_1_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_1_FUSA_ERROR_MASK_1_SHFT                                                              0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1064u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1064u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_FUSA_ERROR_MASK_R_0_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_0_FUSA_ERROR_MASK_R_0_SHFT                                                          0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1068u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1068u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_FUSA_ERROR_MASK_R_1_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_1_FUSA_ERROR_MASK_R_1_SHFT                                                          0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_ADDR                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x106cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_OFFS                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x106cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_RMSK                                                                               0xfu
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_INPUT_GLITCH_DETECTED_MASK_R_BMSK                                                  0x8u
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_INPUT_GLITCH_DETECTED_MASK_R_SHFT                                                    3u
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_INPUT_GLITCH_DETECTED_MASK_BMSK                                                    0x4u
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_INPUT_GLITCH_DETECTED_MASK_SHFT                                                      2u
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_ACMU_RO_REFCLK_FAIL_MASK_R_BMSK                                                    0x2u
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_ACMU_RO_REFCLK_FAIL_MASK_R_SHFT                                                      1u
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_ACMU_RO_REFCLK_FAIL_MASK_BMSK                                                      0x1u
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_OTHER_ACMU_RO_REFCLK_FAIL_MASK_SHFT                                                        0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1070u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1070u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_FUSA_ERROR_STATUS_0_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_0_FUSA_ERROR_STATUS_0_SHFT                                                               0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1074u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1074u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_FUSA_ERROR_STATUS_1_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_1_FUSA_ERROR_STATUS_1_SHFT                                                               0u

#define HWIO_SAILSS_CSR_SM_ERROR_STATUS_ADDR                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1078u)
#define HWIO_SAILSS_CSR_SM_ERROR_STATUS_OFFS                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1078u)
#define HWIO_SAILSS_CSR_SM_ERROR_STATUS_RMSK                                                                                     0x3u
#define HWIO_SAILSS_CSR_SM_ERROR_STATUS_IN                    \
                in_dword(HWIO_SAILSS_CSR_SM_ERROR_STATUS_ADDR)
#define HWIO_SAILSS_CSR_SM_ERROR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SM_ERROR_STATUS_ADDR, m)
#define HWIO_SAILSS_CSR_SM_ERROR_STATUS_SM_ERROR_BMSK                                                                            0x3u
#define HWIO_SAILSS_CSR_SM_ERROR_STATUS_SM_ERROR_SHFT                                                                              0u

#define HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_ADDR                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x107cu)
#define HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_OFFS                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x107cu)
#define HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_RMSK                                                                                0xffffu
#define HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_ADDR)
#define HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_ADDR, m)
#define HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_ADDR,v)
#define HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_ADDR,m,v,HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_IN)
#define HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_MPM_WAKEUP_INT_EN_BMSK                                                              0xffffu
#define HWIO_SAILSS_CSR_MPM_WAKEUP_INT_EN_MPM_WAKEUP_INT_EN_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1080u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1080u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_FUSA_ERROR_MASK_R_2_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_2_FUSA_ERROR_MASK_R_2_SHFT                                                          0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1084u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1084u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_FUSA_ERROR_MASK_R_3_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_3_FUSA_ERROR_MASK_R_3_SHFT                                                          0u

#define HWIO_SAILSS_CSR_SAILSS_IPC_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1088u)
#define HWIO_SAILSS_CSR_SAILSS_IPC_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1088u)
#define HWIO_SAILSS_CSR_SAILSS_IPC_RMSK                                                                                          0x1u
#define HWIO_SAILSS_CSR_SAILSS_IPC_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAILSS_IPC_ADDR)
#define HWIO_SAILSS_CSR_SAILSS_IPC_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAILSS_IPC_ADDR, m)
#define HWIO_SAILSS_CSR_SAILSS_IPC_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAILSS_IPC_ADDR,v)
#define HWIO_SAILSS_CSR_SAILSS_IPC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAILSS_IPC_ADDR,m,v,HWIO_SAILSS_CSR_SAILSS_IPC_IN)
#define HWIO_SAILSS_CSR_SAILSS_IPC_SAILSS_INTR_BMSK                                                                              0x1u
#define HWIO_SAILSS_CSR_SAILSS_IPC_SAILSS_INTR_SHFT                                                                                0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x108cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x108cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_FUSA_ERROR_MASK_R_4_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_4_FUSA_ERROR_MASK_R_4_SHFT                                                          0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1090u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1090u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_FUSA_ERROR_MASK_R_5_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_5_FUSA_ERROR_MASK_R_5_SHFT                                                          0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1094u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1094u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_FUSA_ERROR_MASK_R_6_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_6_FUSA_ERROR_MASK_R_6_SHFT                                                          0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_ADDR                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1098u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_OFFS                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1098u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_RMSK                                                                             0x1u
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_ERR_TS_EN_BMSK                                                                   0x1u
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MAIN_ERR_TS_EN_SHFT                                                                     0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x109cu)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x109cu)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_RMSK                                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_ERR_TS_MASK_0_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_0_ERR_TS_MASK_0_SHFT                                                               0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10a0u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10a0u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_RMSK                                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_ERR_TS_MASK_1_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_1_ERR_TS_MASK_1_SHFT                                                               0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10a4u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10a4u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_RMSK                                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_ERR_TS_MASK_2_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_2_ERR_TS_MASK_2_SHFT                                                               0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10a8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10a8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_RMSK                                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_ERR_TS_MASK_3_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_3_ERR_TS_MASK_3_SHFT                                                               0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10acu)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10acu)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_RMSK                                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_ERR_TS_MASK_4_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_CTRL_MASK_4_ERR_TS_MASK_4_SHFT                                                               0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10b0u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10b0u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_RMSK                                                                       0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_FUSA_ERROR_MASK_7_BMSK                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_MAIN_7_FUSA_ERROR_MASK_7_SHFT                                                              0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10b4u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10b4u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_FUSA_ERROR_MASK_R_7_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_MASK_REDUND_7_FUSA_ERROR_MASK_R_7_SHFT                                                          0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10c8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10c8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_RMSK                                                                           0x3u
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_ERR_TS_OVERFLOW_BMSK                                                           0x2u
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_ERR_TS_OVERFLOW_SHFT                                                             1u
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_ERR_TS_VALID_BMSK                                                              0x1u
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN_ERR_TS_VALID_SHFT                                                                0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10ccu)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10ccu)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0_ERR_TS_SRC_0_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0_ERR_TS_SRC_0_SHFT                                                               0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10d0u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10d0u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1_ERR_TS_SRC_1_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1_ERR_TS_SRC_1_SHFT                                                               0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_L_ADDR                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10d4u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_L_OFFS                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10d4u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_L_RMSK                                                                0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_L_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_L_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_L_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_L_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_L_ERR_TS_VAL_L_BMSK                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_L_ERR_TS_VAL_L_SHFT                                                            0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_H_ADDR                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10d8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_H_OFFS                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10d8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_H_RMSK                                                                0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_H_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_H_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_H_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_H_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_H_ERR_TS_VAL_H_BMSK                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_TS_VAL_H_ERR_TS_VAL_H_SHFT                                                            0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10dcu)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10dcu)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_RMSK                                                                            0x1u
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_WARN_TS_EN_BMSK                                                                 0x1u
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MAIN_WARN_TS_EN_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10e0u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10e0u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_WARN_TS_MASK_0_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_0_WARN_TS_MASK_0_SHFT                                                             0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10e4u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10e4u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_WARN_TS_MASK_1_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_1_WARN_TS_MASK_1_SHFT                                                             0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10e8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10e8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_RMSK                                                                          0x3u
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_WARN_TS_OVERFLOW_BMSK                                                         0x2u
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_WARN_TS_OVERFLOW_SHFT                                                           1u
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_WARN_TS_VALID_BMSK                                                            0x1u
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_MAIN_WARN_TS_VALID_SHFT                                                              0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_0_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10ecu)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_0_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10ecu)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_0_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_0_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_0_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_0_WARN_TS_SRC_0_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_0_WARN_TS_SRC_0_SHFT                                                             0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_1_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10f0u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_1_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10f0u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_1_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_1_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_1_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_1_WARN_TS_SRC_1_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_1_WARN_TS_SRC_1_SHFT                                                             0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_L_ADDR                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10f4u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_L_OFFS                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10f4u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_L_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_L_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_L_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_L_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_L_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_L_WARN_TS_VAL_L_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_L_WARN_TS_VAL_L_SHFT                                                          0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_H_ADDR                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10f8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_H_OFFS                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10f8u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_H_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_H_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_H_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_H_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_H_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_H_WARN_TS_VAL_H_BMSK                                                 0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_TS_VAL_H_WARN_TS_VAL_H_SHFT                                                          0u

#define HWIO_SAILSS_CSR_ACC_OVERRIDE0_ADDR                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x10fcu)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE0_OFFS                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x10fcu)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE0_RMSK                                                                                0xfffffffful
#define HWIO_SAILSS_CSR_ACC_OVERRIDE0_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_OVERRIDE0_ADDR)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_OVERRIDE0_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_ACC_OVERRIDE0_ADDR,v)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_ACC_OVERRIDE0_ADDR,m,v,HWIO_SAILSS_CSR_ACC_OVERRIDE0_IN)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE0_ACC_BMSK                                                                            0xfffffffful
#define HWIO_SAILSS_CSR_ACC_OVERRIDE0_ACC_SHFT                                                                                     0u

#define HWIO_SAILSS_CSR_ACC_OVERRIDE1_ADDR                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1100u)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE1_OFFS                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1100u)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE1_RMSK                                                                                0xfffffffful
#define HWIO_SAILSS_CSR_ACC_OVERRIDE1_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_OVERRIDE1_ADDR)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_OVERRIDE1_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_ACC_OVERRIDE1_ADDR,v)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_ACC_OVERRIDE1_ADDR,m,v,HWIO_SAILSS_CSR_ACC_OVERRIDE1_IN)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE1_ACC_BMSK                                                                            0xfffffffful
#define HWIO_SAILSS_CSR_ACC_OVERRIDE1_ACC_SHFT                                                                                     0u

#define HWIO_SAILSS_CSR_ACC_OVERRIDE2_ADDR                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1104u)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE2_OFFS                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1104u)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE2_RMSK                                                                                    0xffffu
#define HWIO_SAILSS_CSR_ACC_OVERRIDE2_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_OVERRIDE2_ADDR)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_OVERRIDE2_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_ACC_OVERRIDE2_ADDR,v)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_ACC_OVERRIDE2_ADDR,m,v,HWIO_SAILSS_CSR_ACC_OVERRIDE2_IN)
#define HWIO_SAILSS_CSR_ACC_OVERRIDE2_ACC_BMSK                                                                                0xffffu
#define HWIO_SAILSS_CSR_ACC_OVERRIDE2_ACC_SHFT                                                                                     0u

#define HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_ADDR                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1108u)
#define HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_OFFS                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1108u)
#define HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_RMSK                                                                                  0x1u
#define HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_ADDR)
#define HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_ADDR, m)
#define HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_ADDR,v)
#define HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_ADDR,m,v,HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_IN)
#define HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_CORE_IE_BMSK                                                                          0x1u
#define HWIO_SAILSS_CSR_SM_CXO_PAD_CONTROL_CORE_IE_SHFT                                                                            0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x110cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x110cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_FUSA_ERROR_STATUS_2_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_FUSA_ERROR_STATUS_2_SHFT                                                               0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1110u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1110u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_FUSA_ERROR_STATUS_3_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_3_FUSA_ERROR_STATUS_3_SHFT                                                               0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1114u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1114u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_FUSA_ERROR_STATUS_4_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_FUSA_ERROR_STATUS_4_SHFT                                                               0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1118u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1118u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_FUSA_ERROR_STATUS_5_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_5_FUSA_ERROR_STATUS_5_SHFT                                                               0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x111cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x111cu)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_FUSA_ERROR_STATUS_6_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_6_FUSA_ERROR_STATUS_6_SHFT                                                               0u

#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_ADDR                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1120u)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_OFFS                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1120u)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_RMSK                                                                                     0x1u
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_ADDR)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_ADDR, m)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_ADDR,v)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_ADDR,m,v,HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_IN)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_IPCC_ERR_INJ_EN_BMSK                                                                     0x1u
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_IPCC_ERR_INJ_EN_SHFT                                                                       0u

#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1124u)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1124u)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_RMSK                                                                                 0x1u
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_IN                    \
                in_dword(HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_ADDR)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_ADDR, m)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_ADDR,v)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_ADDR,m,v,HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_IN)
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_IPCC_ERR_INJ_EN_CLR_BMSK                                                             0x1u
#define HWIO_SAILSS_CSR_IPCC_ERR_INJ_EN_CLR_IPCC_ERR_INJ_EN_CLR_SHFT                                                               0u

#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_ADDR                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1128u)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_OFFS                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1128u)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_RMSK                                                                                   0x1u
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_IN                    \
                in_dword(HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_ADDR)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_ADDR, m)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_ADDR,v)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_ADDR,m,v,HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_IN)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_IPCC_FUSA_ERR_CLR_BMSK                                                                 0x1u
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_CLR_IPCC_FUSA_ERR_CLR_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_STATUS_ADDR                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x112cu)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_STATUS_OFFS                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x112cu)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_STATUS_RMSK                                                                                0x3u
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_STATUS_IN                    \
                in_dword(HWIO_SAILSS_CSR_IPCC_FUSA_ERR_STATUS_ADDR)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_IPCC_FUSA_ERR_STATUS_ADDR, m)
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_STATUS_IPCC_FUSA_ERR_STATUS_BMSK                                                           0x3u
#define HWIO_SAILSS_CSR_IPCC_FUSA_ERR_STATUS_IPCC_FUSA_ERR_STATUS_SHFT                                                             0u

#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1130u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1130u)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_ADDR)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_IN)
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_FUSA_ERROR_STATUS_7_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_7_FUSA_ERROR_STATUS_7_SHFT                                                               0u

#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_ADDR                                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1178u)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_OFFS                                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1178u)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_RMSK                                                                                0x3fffful
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_ADDR)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_ADDR, m)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_ADDR,v)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_ADDR,m,v,HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_IN)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_POLARITY_SEL_BMSK                                                                   0x3fffful
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_1_POLARITY_SEL_SHFT                                                                         0u

#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_ADDR                                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x117cu)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_OFFS                                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x117cu)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_RMSK                                                                                0x3fffful
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_IN                    \
                in_dword(HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_ADDR)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_ADDR, m)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_ADDR,v)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_ADDR,m,v,HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_IN)
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_EDGE_LVL_SEL_BMSK                                                                   0x3fffful
#define HWIO_SAILSS_CSR_GPIO_INTR_CTRL_2_EDGE_LVL_SEL_SHFT                                                                         0u

#define HWIO_SAILSS_CSR_GPIO_EDGE_INT_ADDR                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1180u)
#define HWIO_SAILSS_CSR_GPIO_EDGE_INT_OFFS                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1180u)
#define HWIO_SAILSS_CSR_GPIO_EDGE_INT_RMSK                                                                                   0x3fffful
#define HWIO_SAILSS_CSR_GPIO_EDGE_INT_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_GPIO_EDGE_INT_ADDR,v)
#define HWIO_SAILSS_CSR_GPIO_EDGE_INT_CLEAR_BMSK                                                                             0x3fffful
#define HWIO_SAILSS_CSR_GPIO_EDGE_INT_CLEAR_SHFT                                                                                   0u

#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_ADDR                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1184u)
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_OFFS                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1184u)
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_RMSK                                                                              0x8000003ful
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_ADDR)
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_ADDR,v)
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_ADDR,m,v,HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_IN)
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_SAILSS_PARITY_ERROR_BMSK                                               0x80000000ul
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_SAILSS_PARITY_ERROR_SHFT                                                       31u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_APBCSR_RIF_CLK_RIF_ASYNC_RESET_BMSK                                          0x20u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_APBCSR_RIF_CLK_RIF_ASYNC_RESET_SHFT                                             5u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_TLMM_RIF_CLK_RIF_ASYNC_RESET_BMSK                                            0x10u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_TLMM_RIF_CLK_RIF_ASYNC_RESET_SHFT                                               4u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_AHB_CLK_ALT_ARES_BMSK                                                         0x8u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_AHB_CLK_ALT_ARES_SHFT                                                           3u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_AHB_CLK_SAILSS_POR_LBIST_RESET_BMSK                                           0x4u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_AHB_CLK_SAILSS_POR_LBIST_RESET_SHFT                                             2u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_AHB_CLK_POR_ARES_BMSK                                                         0x2u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_AHB_CLK_POR_ARES_SHFT                                                           1u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_AHB_CLK_RIF_ASYNC_RESET_BMSK                                                  0x1u
#define HWIO_SAILSS_CSR_FUSA_FAULT_CTRL_INJ_FLTOUT_AHB_CLK_RIF_ASYNC_RESET_SHFT                                                    0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1188u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1188u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_ADDR,v)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_ADDR,m,v,HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_IN)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_WARN_TS_MASK_2_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_CTRL_MASK_2_WARN_TS_MASK_2_SHFT                                                             0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1190u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1190u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2_ERR_TS_SRC_2_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2_ERR_TS_SRC_2_SHFT                                                               0u

#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_2_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1194u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_2_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1194u)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_2_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_2_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_2_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_2_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_2_WARN_TS_SRC_2_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_WARN_STATUS_SRC_2_WARN_TS_SRC_2_SHFT                                                             0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x1198u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x1198u)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3_ERR_TS_SRC_3_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3_ERR_TS_SRC_3_SHFT                                                               0u

#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x119cu)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x119cu)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4_RMSK                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4_IN                    \
                in_dword(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4_ADDR)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4_ADDR, m)
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4_ERR_TS_SRC_4_BMSK                                                      0xfffffffful
#define HWIO_SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4_ERR_TS_SRC_4_SHFT                                                               0u

#define HWIO_SAILSS_CSR_SAFE_SPARE_P2_ADDR                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x2014u)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P2_OFFS                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x2014u)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P2_RMSK                                                                                0xfffffffful
#define HWIO_SAILSS_CSR_SAFE_SPARE_P2_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAFE_SPARE_P2_ADDR)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAFE_SPARE_P2_ADDR, m)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAFE_SPARE_P2_ADDR,v)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAFE_SPARE_P2_ADDR,m,v,HWIO_SAILSS_CSR_SAFE_SPARE_P2_IN)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P2_SAFE_SPARE_P2_BMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_SAFE_SPARE_P2_SAFE_SPARE_P2_SHFT                                                                           0u

#define HWIO_SAILSS_CSR_SAFE_SPARE_P3_ADDR                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x3014u)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P3_OFFS                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x3014u)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P3_RMSK                                                                                0xfffffffful
#define HWIO_SAILSS_CSR_SAFE_SPARE_P3_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAFE_SPARE_P3_ADDR)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAFE_SPARE_P3_ADDR, m)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P3_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAFE_SPARE_P3_ADDR,v)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAFE_SPARE_P3_ADDR,m,v,HWIO_SAILSS_CSR_SAFE_SPARE_P3_IN)
#define HWIO_SAILSS_CSR_SAFE_SPARE_P3_SAFE_SPARE_P3_BMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_SAFE_SPARE_P3_SAFE_SPARE_P3_SHFT                                                                           0u

#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x3f00u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x3f00u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_RMSK                                                            0x1fffu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_ADDR)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_HPCNT_BMSK                                                      0x1f80u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_HPCNT_SHFT                                                           7u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_VPCNT_BMSK                                                        0x7eu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_VPCNT_SHFT                                                           1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_FLT_BMSK                                                           0x1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_POR_ARES_FLT_SHFT                                                             0u

#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x3f20u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x3f20u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_RMSK                                                               0x1fffu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_ADDR)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_HPCNT_BMSK                                                         0x1f80u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_HPCNT_SHFT                                                              7u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_VPCNT_BMSK                                                           0x7eu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_VPCNT_SHFT                                                              1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_FLT_BMSK                                                              0x1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_RESET_FLT_SHFT                                                                0u

#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x3f40u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x3f40u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_RMSK                                                            0x1fffu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_ADDR)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_HPCNT_BMSK                                                      0x1f80u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_HPCNT_SHFT                                                           7u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_VPCNT_BMSK                                                        0x7eu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_VPCNT_SHFT                                                           1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_FLT_BMSK                                                           0x1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ALT_ARES_FLT_SHFT                                                             0u

#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_ADDR                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x3f80u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_OFFS                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x3f80u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_RMSK                                                       0x1fffu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_ADDR)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_HPCNT_BMSK                                                 0x1f80u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_HPCNT_SHFT                                                      7u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_VPCNT_BMSK                                                   0x7eu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_VPCNT_SHFT                                                      1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_FLT_BMSK                                                      0x1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DEBUG_ARES_CX_FLT_SHFT                                                        0u

#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_ADDR                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x3fa0u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_OFFS                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x3fa0u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_RMSK                                                      0x1fffu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_ADDR)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_HPCNT_BMSK                                                0x1f80u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_HPCNT_SHFT                                                     7u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_VPCNT_BMSK                                                  0x7eu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_VPCNT_SHFT                                                     1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_FLT_BMSK                                                     0x1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_ACCESS_ARES_CX_FLT_SHFT                                                       0u

#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_ADDR                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x3fc0u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_OFFS                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x3fc0u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_RMSK                                                          0x1fffu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_ADDR)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_HPCNT_BMSK                                                    0x1f80u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_HPCNT_SHFT                                                         7u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_VPCNT_BMSK                                                      0x7eu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_VPCNT_SHFT                                                         1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_FLT_BMSK                                                         0x1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DUMMY_ARES_FLT_SHFT                                                           0u

#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_ADDR                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x3fe0u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_OFFS                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x3fe0u)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_RMSK                                              0x1fffu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_ADDR)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_ADDR, m)
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_HPCNT_BMSK                                        0x1f80u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_HPCNT_SHFT                                             7u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_VPCNT_BMSK                                          0x7eu
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_VPCNT_SHFT                                             1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_FLT_BMSK                                             0x1u
#define HWIO_SAILSS_CSR_FUSA_STATUS_REGISTER_AHB_CLK_DFT_ACCESS_ARES_CX_DFT_FLT_SHFT                                               0u

#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_ADDR                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5010u)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_OFFS                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5010u)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_RMSK                                                             0xfffffffful
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_IN)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_SPARE_REG_BMSK                                                   0xffffffe0ul
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_SPARE_REG_SHFT                                                            5u
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_SAIL_GEMNOC_ISOLATION_ENABLE_BMSK                                      0x1fu
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG_SAIL_GEMNOC_ISOLATION_ENABLE_SHFT                                         0u

#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_ADDR                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5014u)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_OFFS                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5014u)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_RMSK                                                         0xfffffffful
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_IN)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_SPARE_REG_BMSK                                               0xffffffe0ul
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_SPARE_REG_SHFT                                                        5u
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_BMSK                              0x1fu
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_SHFT                                 0u

#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_ADDR                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5018u)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_OFFS                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5018u)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_IN)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_SPARE_REG_BMSK                                                  0xffffffe0ul
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_SPARE_REG_SHFT                                                           5u
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_SAIL_GEMNOC_MBIST_CLKC_ENABLE_BMSK                                    0x1fu
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_MBIST_CLKC_ENABLE_REG_SAIL_GEMNOC_MBIST_CLKC_ENABLE_SHFT                                       0u

#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_ADDR                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x501cu)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_OFFS                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x501cu)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_RMSK                                                                0xfffffffful
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_IN)
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_SPARE_REG_BMSK                                                      0xfffffffeul
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_SPARE_REG_SHFT                                                               1u
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_SAIL_GEMNOC_RESET_CONTROL_BMSK                                             0x1u
#define HWIO_SAILSS_CSR_SAIL_GEMNOC_RESET_CONTROL_REG_SAIL_GEMNOC_RESET_CONTROL_SHFT                                               0u

#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_ADDR                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5020u)
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_OFFS                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5020u)
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_IN)
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_SPARE_REG_BMSK                                                     0xffff0000ul
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_SPARE_REG_SHFT                                                             16u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_SMMU0_LBIST_PASS_BMSK                                           0x8000u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_SMMU0_LBIST_PASS_SHFT                                               15u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_SMMU0_MBIST_PASS_BMSK                                           0x4000u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_SMMU0_MBIST_PASS_SHFT                                               14u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_SMMU0_LBIST_COMP_BMSK                                           0x2000u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_SMMU0_LBIST_COMP_SHFT                                               13u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_SMMU0_MBIST_COMP_BMSK                                           0x1000u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_SMMU0_MBIST_COMP_SHFT                                               12u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_SMMU0_LBIST_PASS_BMSK                                             0x800u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_SMMU0_LBIST_PASS_SHFT                                                11u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_SMMU0_MBIST_PASS_BMSK                                             0x400u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_SMMU0_MBIST_PASS_SHFT                                                10u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_SMMU0_LBIST_COMP_BMSK                                             0x200u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_SMMU0_LBIST_COMP_SHFT                                                 9u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_SMMU0_MBIST_COMP_BMSK                                             0x100u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_SMMU0_MBIST_COMP_SHFT                                                 8u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_GEMNOC_LBIST_PASS_BMSK                                            0x80u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_GEMNOC_LBIST_PASS_SHFT                                               7u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_GEMNOC_MBIST_PASS_BMSK                                            0x40u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_GEMNOC_MBIST_PASS_SHFT                                               6u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_GEMNOC_LBIST_COMP_BMSK                                            0x20u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_GEMNOC_LBIST_COMP_SHFT                                               5u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_GEMNOC_MBIST_COMP_BMSK                                            0x10u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWROFF_GEMNOC_MBIST_COMP_SHFT                                               4u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_GEMNOC_LBIST_PASS_BMSK                                              0x8u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_GEMNOC_LBIST_PASS_SHFT                                                3u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_GEMNOC_MBIST_PASS_BMSK                                              0x4u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_GEMNOC_MBIST_PASS_SHFT                                                2u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_GEMNOC_LBIST_COMP_BMSK                                              0x2u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_GEMNOC_LBIST_COMP_SHFT                                                1u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_GEMNOC_MBIST_COMP_BMSK                                              0x1u
#define HWIO_SAILSS_CSR_SAIL_MD_GEMNOC_BIST_STATUS_REG_PWRON_GEMNOC_MBIST_COMP_SHFT                                                0u

#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_ADDR                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5024u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_OFFS                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5024u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_RMSK                                                                      0x1u
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_IN                    \
                in_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_ADDR)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_ADDR, m)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_ADDR,v)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_ADDR,m,v,HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_IN)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_MBIST_STARTED_BMSK                                                        0x1u
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED_MBIST_STARTED_SHFT                                                          0u

#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5028u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5028u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_RMSK                                                                         0x1u
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_IN                    \
                in_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_ADDR)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_ADDR, m)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_ADDR,v)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_ADDR,m,v,HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_IN)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_MBIST_DONE_BMSK                                                              0x1u
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE_MBIST_DONE_SHFT                                                                0u

#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x502cu)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x502cu)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_RMSK                                                                         0x1u
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_IN                    \
                in_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_ADDR)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_ADDR, m)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_ADDR,v)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_ADDR,m,v,HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_IN)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_MBIST_PASS_BMSK                                                              0x1u
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS_MBIST_PASS_SHFT                                                                0u

#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_ADDR                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5030u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_OFFS                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5030u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_RMSK                                                                      0xfu
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_IN                    \
                in_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_ADDR)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_ADDR, m)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_ADDR,v)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_ADDR,m,v,HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_IN)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_LBIST_STARTED_BMSK                                                        0xfu
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED_LBIST_STARTED_SHFT                                                          0u

#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5034u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5034u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_RMSK                                                                         0xfu
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_IN                    \
                in_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_ADDR)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_ADDR, m)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_ADDR,v)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_ADDR,m,v,HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_IN)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_LBIST_DONE_BMSK                                                              0xfu
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE_LBIST_DONE_SHFT                                                                0u

#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5038u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5038u)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_RMSK                                                                         0xfu
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_IN                    \
                in_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_ADDR)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_ADDR, m)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_ADDR,v)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_ADDR,m,v,HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_IN)
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_LBIST_PASS_BMSK                                                              0xfu
#define HWIO_SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS_LBIST_PASS_SHFT                                                                0u

#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_ADDR                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x503cu)
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_OFFS                                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x503cu)
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_RMSK                                                                        0xfffffffful
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_ADDR)
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_SAIL_CORES_WFI_STATUS_R_BMSK                                                0xfffffff0ul
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_SAIL_CORES_WFI_STATUS_R_SHFT                                                         4u
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_CPU3_STANDBYWFI_STATUS_3_BMSK                                                      0x8u
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_CPU3_STANDBYWFI_STATUS_3_SHFT                                                        3u
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_CPU3_STANDBYWFI_STATUS_2_BMSK                                                      0x4u
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_CPU3_STANDBYWFI_STATUS_2_SHFT                                                        2u
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_CPU3_STANDBYWFI_STATUS_1_BMSK                                                      0x2u
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_CPU3_STANDBYWFI_STATUS_1_SHFT                                                        1u
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_CPU3_STANDBYWFI_STATUS_0_BMSK                                                      0x1u
#define HWIO_SAILSS_CSR_SAIL_CORES_WFI_STATUS_CPU3_STANDBYWFI_STATUS_0_SHFT                                                        0u

#define HWIO_SAILSS_CSR_HBCU_CONTROL_ADDR                                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5068u)
#define HWIO_SAILSS_CSR_HBCU_CONTROL_OFFS                                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5068u)
#define HWIO_SAILSS_CSR_HBCU_CONTROL_RMSK                                                                                        0x3u
#define HWIO_SAILSS_CSR_HBCU_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_CSR_HBCU_CONTROL_ADDR)
#define HWIO_SAILSS_CSR_HBCU_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_HBCU_CONTROL_ADDR, m)
#define HWIO_SAILSS_CSR_HBCU_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_HBCU_CONTROL_ADDR,v)
#define HWIO_SAILSS_CSR_HBCU_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_HBCU_CONTROL_ADDR,m,v,HWIO_SAILSS_CSR_HBCU_CONTROL_IN)
#define HWIO_SAILSS_CSR_HBCU_CONTROL_REDUNDANT_BMSK                                                                              0x2u
#define HWIO_SAILSS_CSR_HBCU_CONTROL_REDUNDANT_SHFT                                                                                1u
#define HWIO_SAILSS_CSR_HBCU_CONTROL_DISABLE_BMSK                                                                                0x1u
#define HWIO_SAILSS_CSR_HBCU_CONTROL_DISABLE_SHFT                                                                                  0u

#define HWIO_SAILSS_CSR_HBCU_ISOLATION_ADDR                                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x506cu)
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_OFFS                                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x506cu)
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_RMSK                                                                                      0x3u
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_IN                    \
                in_dword(HWIO_SAILSS_CSR_HBCU_ISOLATION_ADDR)
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_HBCU_ISOLATION_ADDR, m)
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_HBCU_ISOLATION_ADDR,v)
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_HBCU_ISOLATION_ADDR,m,v,HWIO_SAILSS_CSR_HBCU_ISOLATION_IN)
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_REDUNDANT_ISOLATION_BMSK                                                                  0x2u
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_REDUNDANT_ISOLATION_SHFT                                                                    1u
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_ISOLATION_CONTROL_BMSK                                                                    0x1u
#define HWIO_SAILSS_CSR_HBCU_ISOLATION_ISOLATION_CONTROL_SHFT                                                                      0u

#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5084u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5084u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_RMSK                                                             0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_IN)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_SAIL_BOOT_STATUS_BMSK                                            0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG_SAIL_BOOT_STATUS_SHFT                                               0u

#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5088u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5088u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_RMSK                                                             0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_IN)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_SAIL_BOOT_STATUS_BMSK                                            0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG_SAIL_BOOT_STATUS_SHFT                                               0u

#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x508cu)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x508cu)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_RMSK                                                             0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_IN)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_SAIL_BOOT_STATUS_BMSK                                            0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG_SAIL_BOOT_STATUS_SHFT                                               0u

#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5090u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5090u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_RMSK                                                             0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_IN)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_SAIL_BOOT_STATUS_BMSK                                            0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG_SAIL_BOOT_STATUS_SHFT                                               0u

#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5094u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5094u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_RMSK                                                             0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_IN)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_SAIL_BOOT_STATUS_BMSK                                            0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_SAIL_BOOT_STATUS_SHFT                                               0u

#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5098u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5098u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_RMSK                                                             0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_IN)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_SAIL_BOOT_STATUS_BMSK                                            0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_SAIL_BOOT_STATUS_SHFT                                               0u

#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x509cu)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x509cu)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_RMSK                                                             0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_IN)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_SAIL_BOOT_STATUS_BMSK                                            0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_SAIL_BOOT_STATUS_SHFT                                               0u

#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50a0u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50a0u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_RMSK                                                             0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_IN)
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_SAIL_BOOT_STATUS_BMSK                                            0xffu
#define HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_SAIL_BOOT_STATUS_SHFT                                               0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50a4u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50a4u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_RMSK                                                                    0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_MD_BOOT_STATUS_BMSK                                                     0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_MD_BOOT_STATUS_SHFT                                                        0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50a8u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50a8u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_RMSK                                                                    0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_MD_BOOT_STATUS_BMSK                                                     0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_MD_BOOT_STATUS_SHFT                                                        0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50acu)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50acu)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_RMSK                                                                    0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_MD_BOOT_STATUS_BMSK                                                     0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_MD_BOOT_STATUS_SHFT                                                        0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50b0u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50b0u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_RMSK                                                                    0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_MD_BOOT_STATUS_BMSK                                                     0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_MD_BOOT_STATUS_SHFT                                                        0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50b4u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50b4u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_RMSK                                                                    0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_MD_BOOT_STATUS_BMSK                                                     0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_MD_BOOT_STATUS_SHFT                                                        0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50b8u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50b8u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_RMSK                                                                    0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_MD_BOOT_STATUS_BMSK                                                     0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_MD_BOOT_STATUS_SHFT                                                        0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50bcu)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50bcu)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_RMSK                                                                    0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_MD_BOOT_STATUS_BMSK                                                     0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_MD_BOOT_STATUS_SHFT                                                        0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50c0u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50c0u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_RMSK                                                                    0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_MD_BOOT_STATUS_BMSK                                                     0xffu
#define HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_MD_BOOT_STATUS_SHFT                                                        0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50c4u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50c4u)
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_BIST_READY_RESERVED_BMSK                                           0xfffffff0ul
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_BIST_READY_RESERVED_SHFT                                                    4u
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH2_BIST_READY_BMSK                                                       0xcu
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH2_BIST_READY_SHFT                                                         2u
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH1_BIST_READY_BMSK                                                       0x3u
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH1_BIST_READY_SHFT                                                         0u

#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_ADDR                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50c8u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_OFFS                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50c8u)
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_IN)
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_MD_BIST_COMPLETE_RESERVED_BMSK                                     0xfffffff0ul
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_MD_BIST_COMPLETE_RESERVED_SHFT                                              4u
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_MD_PH2_BIST_COMPLETE_BMSK                                                 0xcu
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_MD_PH2_BIST_COMPLETE_SHFT                                                   2u
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_MD_PH1_BIST_COMPLETE_BMSK                                                 0x3u
#define HWIO_SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG_MD_PH1_BIST_COMPLETE_SHFT                                                   0u

#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_ADDR                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x50ccu)
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_OFFS                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x50ccu)
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_RMSK                                                                        0x7u
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_ADDR)
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_ADDR, m)
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_BOOT_COMPLETE_BMSK                                                          0x4u
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_BOOT_COMPLETE_SHFT                                                            2u
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_EARLY_DDR_APERTURE_AVAILABLE_BMSK                                           0x2u
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_EARLY_DDR_APERTURE_AVAILABLE_SHFT                                             1u
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_LLCC_TCM_AVAILABLE_BMSK                                                     0x1u
#define HWIO_SAILSS_CSR_MAIN2SAIL_MD_MISC_STATUS_REG_LLCC_TCM_AVAILABLE_SHFT                                                       0u

#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_ADDR                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5200u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_OFFS                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5200u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_RMSK                                                                        0x3u
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_ADDR)
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_ADDR,v)
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_ADDR,m,v,HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_IN)
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_ACC_SERIAL_CLK_EN_FORCE_LOW_BMSK                                            0x2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_ACC_SERIAL_CLK_EN_FORCE_LOW_SHFT                                              1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_ACC_SERIAL_CLK_EN_FORCE_HIGH_BMSK                                           0x1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_HW_CLK_GATING_REG_ACC_SERIAL_CLK_EN_FORCE_HIGH_SHFT                                             0u

#define HWIO_SAILSS_CSR_ACC_SERIAL_CLK_ACTIVE_REG_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5204u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CLK_ACTIVE_REG_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5204u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CLK_ACTIVE_REG_RMSK                                                                           0x1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CLK_ACTIVE_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_SERIAL_CLK_ACTIVE_REG_ADDR)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CLK_ACTIVE_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_SERIAL_CLK_ACTIVE_REG_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CLK_ACTIVE_REG_ACC_SERIAL_CLK_ACTIVE_BMSK                                                     0x1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CLK_ACTIVE_REG_ACC_SERIAL_CLK_ACTIVE_SHFT                                                       0u

#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ADDR                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5208u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_OFFS                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5208u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_RMSK                                                                             0xfu
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ADDR)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ADDR,v)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ADDR,m,v,HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_IN)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ACC_SERIAL_SW_START_NOCB_TILE_BMSK                                               0x8u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ACC_SERIAL_SW_START_NOCB_TILE_SHFT                                                 3u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ACC_SERIAL_SW_START_TOP_TILE_BMSK                                                0x4u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ACC_SERIAL_SW_START_TOP_TILE_SHFT                                                  2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ACC_SERIAL_SW_START_IOS_TILE_BMSK                                                0x2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ACC_SERIAL_SW_START_IOS_TILE_SHFT                                                  1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ACC_SERIAL_SW_START_RTCU_BMSK                                                    0x1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_START_REG_ACC_SERIAL_SW_START_RTCU_SHFT                                                      0u

#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ADDR                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x520cu)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_OFFS                                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x520cu)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_RMSK                                                                              0xfu
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ADDR)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ACC_SERIAL_SW_DONE_NOCB_TILE_BMSK                                                 0x8u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ACC_SERIAL_SW_DONE_NOCB_TILE_SHFT                                                   3u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ACC_SERIAL_SW_DONE_TOP_TILE_BMSK                                                  0x4u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ACC_SERIAL_SW_DONE_TOP_TILE_SHFT                                                    2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ACC_SERIAL_SW_DONE_IOS_TILE_BMSK                                                  0x2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ACC_SERIAL_SW_DONE_IOS_TILE_SHFT                                                    1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ACC_SERIAL_SW_DONE_RTCU_BMSK                                                      0x1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_SW_DONE_REG_ACC_SERIAL_SW_DONE_RTCU_SHFT                                                        0u

#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5210u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5210u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_RMSK                                                                                 0xfu
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ADDR)
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ACC_SERIAL_DONE_NOCB_TILE_BMSK                                                       0x8u
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ACC_SERIAL_DONE_NOCB_TILE_SHFT                                                         3u
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ACC_SERIAL_DONE_TOP_TILE_BMSK                                                        0x4u
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ACC_SERIAL_DONE_TOP_TILE_SHFT                                                          2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ACC_SERIAL_DONE_IOS_TILE_BMSK                                                        0x2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ACC_SERIAL_DONE_IOS_TILE_SHFT                                                          1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ACC_SERIAL_DONE_RTCU_BMSK                                                            0x1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_DONE_REG_ACC_SERIAL_DONE_RTCU_SHFT                                                              0u

#define HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_ADDR                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5214u)
#define HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_OFFS                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5214u)
#define HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_RMSK                                                                  0xffu
#define HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_DBGOVR_COMPILER_MEM_ACC_SEL_0_BMSK                                    0xffu
#define HWIO_SAILSS_CSR_DBGOVR_COMPILER_MEM_ACC_SEL_0_REG_DBGOVR_COMPILER_MEM_ACC_SEL_0_SHFT                                       0u

#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5218u)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5218u)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_RMSK                                                              0xfffffffful
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_DBGOVR_CUSTOM_MEM_ACC_SEL_0_BMSK                                  0xfffffffful
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_0_REG_DBGOVR_CUSTOM_MEM_ACC_SEL_0_SHFT                                           0u

#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x521cu)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x521cu)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_RMSK                                                                   0x7ffu
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_DBGOVR_CUSTOM_MEM_ACC_SEL_1_BMSK                                       0x7ffu
#define HWIO_SAILSS_CSR_DBGOVR_CUSTOM_MEM_ACC_SEL_1_REG_DBGOVR_CUSTOM_MEM_ACC_SEL_1_SHFT                                           0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5220u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5220u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_RMSK                                                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_7_BMSK                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_7_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_7_SHFT                                   0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5224u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5224u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_RMSK                                                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_6_BMSK                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_6_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_6_SHFT                                   0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5228u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5228u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_RMSK                                                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_5_BMSK                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_5_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_5_SHFT                                   0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x522cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x522cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_RMSK                                                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_4_BMSK                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_4_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_4_SHFT                                   0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5230u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5230u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_RMSK                                                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_3_BMSK                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_3_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_3_SHFT                                   0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5234u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5234u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_RMSK                                                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_2_BMSK                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_2_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_2_SHFT                                   0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5238u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5238u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_RMSK                                                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_1_BMSK                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_1_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_1_SHFT                                   0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x523cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x523cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_RMSK                                                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_0_BMSK                               0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_COMPILER_MEM_ACC_0_REG_DBGOVR_VALUE_COMPILER_MEM_ACC_0_SHFT                                   0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5240u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5240u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_RMSK                                                             0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_BMSK                           0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE1_SHFT                               0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5244u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5244u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_RMSK                                                             0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_BMSK                           0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE2_SHFT                               0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5248u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5248u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_RMSK                                                             0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_BMSK                           0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE3_SHFT                               0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x524cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x524cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_RMSK                                                             0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_BMSK                           0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE4_SHFT                               0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5250u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5250u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_RMSK                                                             0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_BMSK                           0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE5_SHFT                               0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5254u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5254u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_RMSK                                                             0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_BMSK                           0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE6_SHFT                               0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5258u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5258u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_RMSK                                                             0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_BMSK                           0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE7_SHFT                               0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x525cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x525cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_RMSK                                                             0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_BMSK                           0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE8_SHFT                               0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5260u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5260u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_RMSK                                                             0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_BMSK                           0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE9_SHFT                               0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5264u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5264u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE10_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5268u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5268u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE11_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x526cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x526cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE12_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5270u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5270u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE13_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5274u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5274u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE14_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5278u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5278u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE15_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x527cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x527cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE16_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5280u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5280u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE17_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5284u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5284u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE18_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5288u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5288u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE19_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x528cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x528cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE20_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5290u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5290u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE21_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5294u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5294u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE22_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5298u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5298u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE23_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x529cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x529cu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE24_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52a0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52a0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE25_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52a4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52a4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE26_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52a8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52a8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE27_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52acu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52acu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE28_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52b0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52b0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE29_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52b4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52b4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE30_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52b8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52b8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE31_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52bcu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52bcu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE32_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52c0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52c0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE33_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52c4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52c4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE34_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52c8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52c8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE35_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52ccu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52ccu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE36_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52d0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52d0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE37_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52d4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52d4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE38_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52d8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52d8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE39_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52dcu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52dcu)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE40_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52e0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52e0u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE41_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52e4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52e4u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE42_SHFT                             0u

#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x52e8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x52e8u)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_RMSK                                                            0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_ADDR)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_ADDR,m,v,HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_IN)
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_BMSK                         0x1ffu
#define HWIO_SAILSS_CSR_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_REG_DBGOVR_VALUE_CUSTOM_MEM_ACC_TYPE43_SHFT                             0u

#define HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_ADDR                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5400u)
#define HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_OFFS                                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5400u)
#define HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_RMSK                                                                             0x3u
#define HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_AOSS_MEM_TURBO_VDDMX_READ_BMSK                                                   0x2u
#define HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_AOSS_MEM_TURBO_VDDMX_READ_SHFT                                                     1u
#define HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_AOSS_MEM_TURBO_VDDCX_READ_BMSK                                                   0x1u
#define HWIO_SAILSS_CSR_AOSS_MEM_TURBO_READ_REG_AOSS_MEM_TURBO_VDDCX_READ_SHFT                                                     0u

#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_0_READ_REG_ADDR                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5404u)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_0_READ_REG_OFFS                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5404u)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_0_READ_REG_RMSK                                                             0xfffffffful
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_0_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_0_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_0_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_0_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_0_READ_REG_FUSE_COMPILER_MEM_ACC_0_READ_BMSK                                0xfffffffful
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_0_READ_REG_FUSE_COMPILER_MEM_ACC_0_READ_SHFT                                         0u

#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_1_READ_REG_ADDR                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5408u)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_1_READ_REG_OFFS                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5408u)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_1_READ_REG_RMSK                                                             0xfffffffful
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_1_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_1_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_1_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_1_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_1_READ_REG_FUSE_COMPILER_MEM_ACC_1_READ_BMSK                                0xfffffffful
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_1_READ_REG_FUSE_COMPILER_MEM_ACC_1_READ_SHFT                                         0u

#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_2_READ_REG_ADDR                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x540cu)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_2_READ_REG_OFFS                                                             (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x540cu)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_2_READ_REG_RMSK                                                                 0xffffu
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_2_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_2_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_2_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_2_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_2_READ_REG_FUSE_COMPILER_MEM_ACC_2_READ_BMSK                                    0xffffu
#define HWIO_SAILSS_CSR_FUSE_COMPILER_MEM_ACC_2_READ_REG_FUSE_COMPILER_MEM_ACC_2_READ_SHFT                                         0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_REG_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5410u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_REG_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5410u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_REG_RMSK                                                                0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_BMSK                                 0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE1_READ_SHFT                                     0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_REG_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5414u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_REG_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5414u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_REG_RMSK                                                                0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_BMSK                                 0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE2_READ_SHFT                                     0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_REG_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5418u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_REG_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5418u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_REG_RMSK                                                                0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_BMSK                                 0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE3_READ_SHFT                                     0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_REG_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x541cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_REG_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x541cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_REG_RMSK                                                                0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_BMSK                                 0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE4_READ_SHFT                                     0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_REG_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5420u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_REG_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5420u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_REG_RMSK                                                                0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_BMSK                                 0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE5_READ_SHFT                                     0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_REG_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5424u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_REG_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5424u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_REG_RMSK                                                                0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_BMSK                                 0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE6_READ_SHFT                                     0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_REG_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5428u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_REG_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5428u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_REG_RMSK                                                                0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_BMSK                                 0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE7_READ_SHFT                                     0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_REG_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x542cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_REG_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x542cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_REG_RMSK                                                                0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_BMSK                                 0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE8_READ_SHFT                                     0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_REG_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5430u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_REG_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5430u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_REG_RMSK                                                                0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_BMSK                                 0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE9_READ_SHFT                                     0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5434u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5434u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE10_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5438u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5438u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE11_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x543cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x543cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE12_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5440u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5440u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE13_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5444u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5444u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE14_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5448u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5448u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE15_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x544cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x544cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE16_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5450u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5450u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE17_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5454u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5454u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE18_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5458u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5458u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE19_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x545cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x545cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE20_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5460u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5460u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE21_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5464u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5464u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE22_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5468u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5468u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE23_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x546cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x546cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE24_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5470u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5470u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE25_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5474u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5474u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE26_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5478u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5478u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE27_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x547cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x547cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE28_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5480u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5480u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE29_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5484u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5484u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE30_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5488u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5488u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE31_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x548cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x548cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE32_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5490u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5490u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE33_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5494u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5494u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE34_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5498u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5498u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE35_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x549cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x549cu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE36_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54a0u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54a0u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE37_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54a4u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54a4u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE38_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54a8u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54a8u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE39_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54acu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54acu)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE40_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54b0u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54b0u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE41_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54b4u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54b4u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE42_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_REG_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54b8u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_REG_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54b8u)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_REG_RMSK                                                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_REG_ADDR)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_REG_ADDR, m)
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_BMSK                               0x3ffu
#define HWIO_SAILSS_CSR_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_REG_FUSE_CUSTOM_MEM_ACC_TYPE43_READ_SHFT                                   0u

#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_ADDR                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54ecu)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_OFFS                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54ecu)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_RMSK                                                                                   0x1u
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_IN                    \
                in_dword(HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_ADDR)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_ADDR, m)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_ADDR,v)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_ADDR,m,v,HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_IN)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_MEM_SVS_SEL_VDDCX_BMSK                                                                 0x1u
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDCX_MEM_SVS_SEL_VDDCX_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_ADDR                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54f0u)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_OFFS                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54f0u)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_RMSK                                                                                   0x1u
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_IN                    \
                in_dword(HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_ADDR)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_ADDR, m)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_ADDR,v)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_ADDR,m,v,HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_IN)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_MEM_SVS_SEL_VDDMX_BMSK                                                                 0x1u
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_VDDMX_MEM_SVS_SEL_VDDMX_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_ADDR                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54f4u)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_OFFS                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54f4u)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_RMSK                                                                                   0x1u
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_IN                    \
                in_dword(HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_ADDR)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_ADDR, m)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_ADDR,v)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_ADDR,m,v,HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_IN)
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_MEM_SVS_SEL_SPARE_BMSK                                                                 0x1u
#define HWIO_SAILSS_CSR_MEM_SVS_SEL_SPARE_MEM_SVS_SEL_SPARE_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54f8u)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54f8u)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_RMSK                                                                                 0x2u
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_IN                    \
                in_dword(HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_ADDR)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_ADDR, m)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_ADDR,v)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_ADDR,m,v,HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_IN)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_MEM_TURBO_SEL_VDDCX_BMSK                                                             0x2u
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDCX_MEM_TURBO_SEL_VDDCX_SHFT                                                               1u

#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x54fcu)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x54fcu)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_RMSK                                                                                 0x2u
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_IN                    \
                in_dword(HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_ADDR)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_ADDR, m)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_ADDR,v)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_ADDR,m,v,HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_IN)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_MEM_TURBO_SEL_VDDMX_BMSK                                                             0x2u
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_VDDMX_MEM_TURBO_SEL_VDDMX_SHFT                                                               1u

#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x5500u)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x5500u)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_RMSK                                                                                 0x2u
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_IN                    \
                in_dword(HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_ADDR)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_ADDR, m)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_ADDR,v)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_ADDR,m,v,HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_IN)
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_MEM_TURBO_SEL_SPARE_BMSK                                                             0x2u
#define HWIO_SAILSS_CSR_MEM_TURBO_SEL_SPARE_MEM_TURBO_SEL_SPARE_SHFT                                                               1u

#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_ADDR                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6000u)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_OFFS                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6000u)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_RMSK                                                                0x3fu
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_RESERVE_18_VMIDMT_NSGCFGIRPT_BMSK                                   0x20u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_RESERVE_18_VMIDMT_NSGCFGIRPT_SHFT                                      5u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_SAIL_TOP_VMIDMT_NSGCFGIRPT_BMSK                                     0x10u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_SAIL_TOP_VMIDMT_NSGCFGIRPT_SHFT                                        4u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_DMA_WR_VMIDMT_NSGCFGIRPT_BMSK                                        0x8u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_DMA_WR_VMIDMT_NSGCFGIRPT_SHFT                                          3u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_DMA_RD_VMIDMT_NSGCFGIRPT_BMSK                                        0x4u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_DMA_RD_VMIDMT_NSGCFGIRPT_SHFT                                          2u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_QUPV3_0_VMIDMT_NSGCFGIRPT_BMSK                                       0x2u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_QUPV3_0_VMIDMT_NSGCFGIRPT_SHFT                                         1u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_CRYPTO0_VMIDMT_NSGCFGIRPT_BMSK                                       0x1u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_STATUS_REG_0_CRYPTO0_VMIDMT_NSGCFGIRPT_SHFT                                         0u

#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6040u)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6040u)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_RMSK                                                              0x3fu
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_RESERVE_18_VMIDMT_NSGCFGIRPT_ENABLE_BMSK                          0x20u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_RESERVE_18_VMIDMT_NSGCFGIRPT_ENABLE_SHFT                             5u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_SAIL_TOP_VMIDMT_NSGCFGIRPT_ENABLE_BMSK                            0x10u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_SAIL_TOP_VMIDMT_NSGCFGIRPT_ENABLE_SHFT                               4u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_DMA_WR_VMIDMT_NSGCFGIRPT_ENABLE_BMSK                               0x8u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_DMA_WR_VMIDMT_NSGCFGIRPT_ENABLE_SHFT                                 3u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_DMA_RD_VMIDMT_NSGCFGIRPT_ENABLE_BMSK                               0x4u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_DMA_RD_VMIDMT_NSGCFGIRPT_ENABLE_SHFT                                 2u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_VMIDMT_NSGCFGIRPT_ENABLE_BMSK                              0x2u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_VMIDMT_NSGCFGIRPT_ENABLE_SHFT                                1u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_VMIDMT_NSGCFGIRPT_ENABLE_BMSK                              0x1u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_NON_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_VMIDMT_NSGCFGIRPT_ENABLE_SHFT                                0u

#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6080u)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6080u)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_RMSK                                                                    0x3fu
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_RESERVE_18_VMIDMT_GCFGIRPT_BMSK                                         0x20u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_RESERVE_18_VMIDMT_GCFGIRPT_SHFT                                            5u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_SAIL_TOP_VMIDMT_GCFGIRPT_BMSK                                           0x10u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_SAIL_TOP_VMIDMT_GCFGIRPT_SHFT                                              4u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_DMA_WR_VMIDMT_GCFGIRPT_BMSK                                              0x8u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_DMA_WR_VMIDMT_GCFGIRPT_SHFT                                                3u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_DMA_RD_VMIDMT_GCFGIRPT_BMSK                                              0x4u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_DMA_RD_VMIDMT_GCFGIRPT_SHFT                                                2u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_QUPV3_0_VMIDMT_GCFGIRPT_BMSK                                             0x2u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_QUPV3_0_VMIDMT_GCFGIRPT_SHFT                                               1u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_CRYPTO0_VMIDMT_GCFGIRPT_BMSK                                             0x1u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_STATUS_REG_0_CRYPTO0_VMIDMT_GCFGIRPT_SHFT                                               0u

#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_ADDR                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x60c0u)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_OFFS                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x60c0u)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_RMSK                                                                  0x3fu
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_RESERVE_18_VMIDMT_GCFGIRPT_ENABLE_BMSK                                0x20u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_RESERVE_18_VMIDMT_GCFGIRPT_ENABLE_SHFT                                   5u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_SAIL_TOP_VMIDMT_GCFGIRPT_ENABLE_BMSK                                  0x10u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_SAIL_TOP_VMIDMT_GCFGIRPT_ENABLE_SHFT                                     4u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_DMA_WR_VMIDMT_GCFGIRPT_ENABLE_BMSK                                     0x8u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_DMA_WR_VMIDMT_GCFGIRPT_ENABLE_SHFT                                       3u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_DMA_RD_VMIDMT_GCFGIRPT_ENABLE_BMSK                                     0x4u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_DMA_RD_VMIDMT_GCFGIRPT_ENABLE_SHFT                                       2u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_VMIDMT_GCFGIRPT_ENABLE_BMSK                                    0x2u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_VMIDMT_GCFGIRPT_ENABLE_SHFT                                      1u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_VMIDMT_GCFGIRPT_ENABLE_BMSK                                    0x1u
#define HWIO_SAILSS_CSR_VMIDMT_CFG_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_VMIDMT_GCFGIRPT_ENABLE_SHFT                                      0u

#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_ADDR                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6100u)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_OFFS                                                       (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6100u)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_RMSK                                                             0x3fu
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_RESERVE_18_VMIDMT_NSGIRPT_BMSK                                   0x20u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_RESERVE_18_VMIDMT_NSGIRPT_SHFT                                      5u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_SAIL_TOP_VMIDMT_NSGIRPT_BMSK                                     0x10u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_SAIL_TOP_VMIDMT_NSGIRPT_SHFT                                        4u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_DMA_WR_VMIDMT_NSGIRPT_BMSK                                        0x8u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_DMA_WR_VMIDMT_NSGIRPT_SHFT                                          3u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_DMA_RD_VMIDMT_NSGIRPT_BMSK                                        0x4u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_DMA_RD_VMIDMT_NSGIRPT_SHFT                                          2u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_QUPV3_0_VMIDMT_NSGIRPT_BMSK                                       0x2u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_QUPV3_0_VMIDMT_NSGIRPT_SHFT                                         1u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_CRYPTO0_VMIDMT_NSGIRPT_BMSK                                       0x1u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_STATUS_REG_0_CRYPTO0_VMIDMT_NSGIRPT_SHFT                                         0u

#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6140u)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_OFFS                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6140u)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_RMSK                                                           0x3fu
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_RESERVE_18_VMIDMT_NSGIRPT_ENABLE_BMSK                          0x20u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_RESERVE_18_VMIDMT_NSGIRPT_ENABLE_SHFT                             5u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_SAIL_TOP_VMIDMT_NSGIRPT_ENABLE_BMSK                            0x10u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_SAIL_TOP_VMIDMT_NSGIRPT_ENABLE_SHFT                               4u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_DMA_WR_VMIDMT_NSGIRPT_ENABLE_BMSK                               0x8u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_DMA_WR_VMIDMT_NSGIRPT_ENABLE_SHFT                                 3u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_DMA_RD_VMIDMT_NSGIRPT_ENABLE_BMSK                               0x4u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_DMA_RD_VMIDMT_NSGIRPT_ENABLE_SHFT                                 2u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_VMIDMT_NSGIRPT_ENABLE_BMSK                              0x2u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_VMIDMT_NSGIRPT_ENABLE_SHFT                                1u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_VMIDMT_NSGIRPT_ENABLE_BMSK                              0x1u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_NON_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_VMIDMT_NSGIRPT_ENABLE_SHFT                                0u

#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_ADDR                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6180u)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_OFFS                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6180u)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_RMSK                                                                 0x3fu
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_RESERVE_18_VMIDMT_GIRPT_BMSK                                         0x20u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_RESERVE_18_VMIDMT_GIRPT_SHFT                                            5u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_SAIL_TOP_VMIDMT_GIRPT_BMSK                                           0x10u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_SAIL_TOP_VMIDMT_GIRPT_SHFT                                              4u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_DMA_WR_VMIDMT_GIRPT_BMSK                                              0x8u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_DMA_WR_VMIDMT_GIRPT_SHFT                                                3u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_DMA_RD_VMIDMT_GIRPT_BMSK                                              0x4u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_DMA_RD_VMIDMT_GIRPT_SHFT                                                2u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_QUPV3_0_VMIDMT_GIRPT_BMSK                                             0x2u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_QUPV3_0_VMIDMT_GIRPT_SHFT                                               1u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_CRYPTO0_VMIDMT_GIRPT_BMSK                                             0x1u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_STATUS_REG_0_CRYPTO0_VMIDMT_GIRPT_SHFT                                               0u

#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_ADDR                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x61c0u)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_OFFS                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x61c0u)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_RMSK                                                               0x3fu
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_RESERVE_18_VMIDMT_GIRPT_ENABLE_BMSK                                0x20u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_RESERVE_18_VMIDMT_GIRPT_ENABLE_SHFT                                   5u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_SAIL_TOP_VMIDMT_GIRPT_ENABLE_BMSK                                  0x10u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_SAIL_TOP_VMIDMT_GIRPT_ENABLE_SHFT                                     4u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_DMA_WR_VMIDMT_GIRPT_ENABLE_BMSK                                     0x8u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_DMA_WR_VMIDMT_GIRPT_ENABLE_SHFT                                       3u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_DMA_RD_VMIDMT_GIRPT_ENABLE_BMSK                                     0x4u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_DMA_RD_VMIDMT_GIRPT_ENABLE_SHFT                                       2u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_VMIDMT_GIRPT_ENABLE_BMSK                                    0x2u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_VMIDMT_GIRPT_ENABLE_SHFT                                      1u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_VMIDMT_GIRPT_ENABLE_BMSK                                    0x1u
#define HWIO_SAILSS_CSR_VMIDMT_CLIENT_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_VMIDMT_GIRPT_ENABLE_SHFT                                      0u

#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6200u)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6200u)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_RMSK                                                                           0x7fu
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_XM_DMA_MS_MPU_XPU3_SP_INTR_BMSK                                                0x40u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_XM_DMA_MS_MPU_XPU3_SP_INTR_SHFT                                                   6u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_BOOT_ROM_XPU_SP_INTR_BMSK                                                      0x20u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_BOOT_ROM_XPU_SP_INTR_SHFT                                                         5u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_CRYPTO_KM_XPU_SP_INTR_BMSK                                                     0x10u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_CRYPTO_KM_XPU_SP_INTR_SHFT                                                        4u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_SP_INTR_BMSK                                    0x8u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_SP_INTR_SHFT                                      3u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_SEC_CTRL_XPU_SP_INTR_BMSK                                                       0x4u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_SEC_CTRL_XPU_SP_INTR_SHFT                                                         2u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_CRYPTO0_XPU_SP_INTR_BMSK                                                        0x2u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_CRYPTO0_XPU_SP_INTR_SHFT                                                          1u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_QUPV3_0_XPU_SP_INTR_BMSK                                                        0x1u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_STATUS_REG_0_QUPV3_0_XPU_SP_INTR_SHFT                                                          0u

#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6240u)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6240u)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_RMSK                                                                         0x7fu
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_XM_DMA_MS_MPU_XPU3_SP_INTR_ENABLE_BMSK                                       0x40u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_XM_DMA_MS_MPU_XPU3_SP_INTR_ENABLE_SHFT                                          6u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_BOOT_ROM_XPU_SP_INTR_ENABLE_BMSK                                             0x20u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_BOOT_ROM_XPU_SP_INTR_ENABLE_SHFT                                                5u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_CRYPTO_KM_XPU_SP_INTR_ENABLE_BMSK                                            0x10u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_CRYPTO_KM_XPU_SP_INTR_ENABLE_SHFT                                               4u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_SP_INTR_ENABLE_BMSK                           0x8u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_SP_INTR_ENABLE_SHFT                             3u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_SEC_CTRL_XPU_SP_INTR_ENABLE_BMSK                                              0x4u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_SEC_CTRL_XPU_SP_INTR_ENABLE_SHFT                                                2u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_CRYPTO0_XPU_SP_INTR_ENABLE_BMSK                                               0x2u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_CRYPTO0_XPU_SP_INTR_ENABLE_SHFT                                                 1u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_QUPV3_0_XPU_SP_INTR_ENABLE_BMSK                                               0x1u
#define HWIO_SAILSS_CSR_XPU3_SP_IRQ_ENABLE_0_REG_0_QUPV3_0_XPU_SP_INTR_ENABLE_SHFT                                                 0u

#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6280u)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6280u)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_RMSK                                                                          0x7fu
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_XM_DMA_MS_MPU_XPU3_MSA_INTR_BMSK                                              0x40u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_XM_DMA_MS_MPU_XPU3_MSA_INTR_SHFT                                                 6u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_BOOT_ROM_XPU_MSA_INTR_BMSK                                                    0x20u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_BOOT_ROM_XPU_MSA_INTR_SHFT                                                       5u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_CRYPTO_KM_XPU_MSA_INTR_BMSK                                                   0x10u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_CRYPTO_KM_XPU_MSA_INTR_SHFT                                                      4u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_MSA_INTR_BMSK                                  0x8u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_MSA_INTR_SHFT                                    3u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_SEC_CTRL_XPU_MSA_INTR_BMSK                                                     0x4u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_SEC_CTRL_XPU_MSA_INTR_SHFT                                                       2u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_CRYPTO0_XPU_MSA_INTR_BMSK                                                      0x2u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_CRYPTO0_XPU_MSA_INTR_SHFT                                                        1u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_QUPV3_0_XPU_MSA_INTR_BMSK                                                      0x1u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_STATUS_REG_0_QUPV3_0_XPU_MSA_INTR_SHFT                                                        0u

#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x62c0u)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x62c0u)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_RMSK                                                                        0x7fu
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_XM_DMA_MS_MPU_XPU3_MSA_INTR_ENABLE_BMSK                                     0x40u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_XM_DMA_MS_MPU_XPU3_MSA_INTR_ENABLE_SHFT                                        6u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_BOOT_ROM_XPU_MSA_INTR_ENABLE_BMSK                                           0x20u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_BOOT_ROM_XPU_MSA_INTR_ENABLE_SHFT                                              5u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_CRYPTO_KM_XPU_MSA_INTR_ENABLE_BMSK                                          0x10u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_CRYPTO_KM_XPU_MSA_INTR_ENABLE_SHFT                                             4u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_MSA_INTR_ENABLE_BMSK                         0x8u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_MSA_INTR_ENABLE_SHFT                           3u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_SEC_CTRL_XPU_MSA_INTR_ENABLE_BMSK                                            0x4u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_SEC_CTRL_XPU_MSA_INTR_ENABLE_SHFT                                              2u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_CRYPTO0_XPU_MSA_INTR_ENABLE_BMSK                                             0x2u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_CRYPTO0_XPU_MSA_INTR_ENABLE_SHFT                                               1u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_QUPV3_0_XPU_MSA_INTR_ENABLE_BMSK                                             0x1u
#define HWIO_SAILSS_CSR_XPU3_MSA_IRQ_ENABLE_0_REG_0_QUPV3_0_XPU_MSA_INTR_ENABLE_SHFT                                               0u

#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_ADDR                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6300u)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_OFFS                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6300u)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_RMSK                                                                      0x7fu
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_XM_DMA_MS_MPU_XPU3_NON_SEC_INTR_BMSK                                      0x40u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_XM_DMA_MS_MPU_XPU3_NON_SEC_INTR_SHFT                                         6u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_BOOT_ROM_XPU_NON_SEC_INTR_BMSK                                            0x20u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_BOOT_ROM_XPU_NON_SEC_INTR_SHFT                                               5u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_CRYPTO_KM_XPU_NON_SEC_INTR_BMSK                                           0x10u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_CRYPTO_KM_XPU_NON_SEC_INTR_SHFT                                              4u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_NON_SEC_INTR_BMSK                          0x8u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_NON_SEC_INTR_SHFT                            3u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_SEC_CTRL_XPU_NON_SEC_INTR_BMSK                                             0x4u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_SEC_CTRL_XPU_NON_SEC_INTR_SHFT                                               2u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_CRYPTO0_XPU_NON_SEC_INTR_BMSK                                              0x2u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_CRYPTO0_XPU_NON_SEC_INTR_SHFT                                                1u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_QUPV3_0_XPU_NON_SEC_INTR_BMSK                                              0x1u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_STATUS_REG_0_QUPV3_0_XPU_NON_SEC_INTR_SHFT                                                0u

#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6340u)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_OFFS                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6340u)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_RMSK                                                                    0x7fu
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_XM_DMA_MS_MPU_XPU3_NON_SEC_INTR_ENABLE_BMSK                             0x40u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_XM_DMA_MS_MPU_XPU3_NON_SEC_INTR_ENABLE_SHFT                                6u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_BOOT_ROM_XPU_NON_SEC_INTR_ENABLE_BMSK                                   0x20u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_BOOT_ROM_XPU_NON_SEC_INTR_ENABLE_SHFT                                      5u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_CRYPTO_KM_XPU_NON_SEC_INTR_ENABLE_BMSK                                  0x10u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_CRYPTO_KM_XPU_NON_SEC_INTR_ENABLE_SHFT                                     4u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_NON_SEC_INTR_ENABLE_BMSK                 0x8u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_NON_SEC_INTR_ENABLE_SHFT                   3u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_SEC_CTRL_XPU_NON_SEC_INTR_ENABLE_BMSK                                    0x4u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_SEC_CTRL_XPU_NON_SEC_INTR_ENABLE_SHFT                                      2u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_XPU_NON_SEC_INTR_ENABLE_BMSK                                     0x2u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_XPU_NON_SEC_INTR_ENABLE_SHFT                                       1u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_XPU_NON_SEC_INTR_ENABLE_BMSK                                     0x1u
#define HWIO_SAILSS_CSR_XPU3_NON_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_XPU_NON_SEC_INTR_ENABLE_SHFT                                       0u

#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6380u)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6380u)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_RMSK                                                                          0x7fu
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_XM_DMA_MS_MPU_XPU3_SEC_INTR_BMSK                                              0x40u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_XM_DMA_MS_MPU_XPU3_SEC_INTR_SHFT                                                 6u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_BOOT_ROM_XPU_SEC_INTR_BMSK                                                    0x20u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_BOOT_ROM_XPU_SEC_INTR_SHFT                                                       5u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_CRYPTO_KM_XPU_SEC_INTR_BMSK                                                   0x10u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_CRYPTO_KM_XPU_SEC_INTR_SHFT                                                      4u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_SEC_INTR_BMSK                                  0x8u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_SEC_INTR_SHFT                                    3u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_SEC_CTRL_XPU_SEC_INTR_BMSK                                                     0x4u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_SEC_CTRL_XPU_SEC_INTR_SHFT                                                       2u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_CRYPTO0_XPU_SEC_INTR_BMSK                                                      0x2u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_CRYPTO0_XPU_SEC_INTR_SHFT                                                        1u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_QUPV3_0_XPU_SEC_INTR_BMSK                                                      0x1u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_STATUS_REG_0_QUPV3_0_XPU_SEC_INTR_SHFT                                                        0u

#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x63c0u)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x63c0u)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_RMSK                                                                        0x7fu
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_XM_DMA_MS_MPU_XPU3_SEC_INTR_ENABLE_BMSK                                     0x40u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_XM_DMA_MS_MPU_XPU3_SEC_INTR_ENABLE_SHFT                                        6u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_BOOT_ROM_XPU_SEC_INTR_ENABLE_BMSK                                           0x20u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_BOOT_ROM_XPU_SEC_INTR_ENABLE_SHFT                                              5u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_CRYPTO_KM_XPU_SEC_INTR_ENABLE_BMSK                                          0x10u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_CRYPTO_KM_XPU_SEC_INTR_ENABLE_SHFT                                             4u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_SEC_INTR_ENABLE_BMSK                         0x8u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_QNM_ASILD_ASILB_NOC_MS_MPU_XPU3_SEC_INTR_ENABLE_SHFT                           3u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_SEC_CTRL_XPU_SEC_INTR_ENABLE_BMSK                                            0x4u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_SEC_CTRL_XPU_SEC_INTR_ENABLE_SHFT                                              2u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_XPU_SEC_INTR_ENABLE_BMSK                                             0x2u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_CRYPTO0_XPU_SEC_INTR_ENABLE_SHFT                                               1u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_XPU_SEC_INTR_ENABLE_BMSK                                             0x1u
#define HWIO_SAILSS_CSR_XPU3_SEC_IRQ_ENABLE_0_REG_0_QUPV3_0_XPU_SEC_INTR_ENABLE_SHFT                                               0u

#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_0_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6400u)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_0_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6400u)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_0_RMSK                                                                         0x1fu
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_0_I_TOP_QUPV3_0_SE_INTR_BMSK                                                   0x1fu
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_0_I_TOP_QUPV3_0_SE_INTR_SHFT                                                      0u

#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_1_ADDR                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6404u)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_1_OFFS                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6404u)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_1_RMSK                                                                        0xfffu
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_1_ADDR)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_1_ADDR, m)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_1_I_TOP_QUPV3_0_GSI_INTR_BMSK                                                 0xfffu
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_STATUS_REG_1_I_TOP_QUPV3_0_GSI_INTR_SHFT                                                     0u

#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_ADDR                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6408u)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_OFFS                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6408u)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_RMSK                                                                       0x1fu
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_I_TOP_QUPV3_0_SE_INTR_ENABLE_BMSK                                          0x1fu
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_0_I_TOP_QUPV3_0_SE_INTR_ENABLE_SHFT                                             0u

#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_ADDR                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x640cu)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_OFFS                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x640cu)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_RMSK                                                                      0xfffu
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_ADDR)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_ADDR, m)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_ADDR,v)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_ADDR,m,v,HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_IN)
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_I_TOP_QUPV3_0_GSI_INTR_ENABLE_BMSK                                        0xfffu
#define HWIO_SAILSS_CSR_TOP_QUPV3_IRQ_ENABLE_0_REG_1_I_TOP_QUPV3_0_GSI_INTR_ENABLE_SHFT                                            0u

#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_ADDR                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6600u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_OFFS                                                        (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6600u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_RMSK                                                               0xfu
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_ADDR)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_CRC_ERROR_OUT_ACC_NOCB_TILE_DONE_BMSK                              0x8u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_CRC_ERROR_OUT_ACC_NOCB_TILE_DONE_SHFT                                3u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_CRC_ERROR_OUT_ACC_TOP_TILE_DONE_BMSK                               0x4u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_CRC_ERROR_OUT_ACC_TOP_TILE_DONE_SHFT                                 2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_CRC_ERROR_OUT_ACC_IOS_TILE_DONE_BMSK                               0x2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_CRC_ERROR_OUT_ACC_IOS_TILE_DONE_SHFT                                 1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_CRC_ERROR_OUT_ACC_RTCU_DONE_BMSK                                   0x1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_STATUS_REG_0_CRC_ERROR_OUT_ACC_RTCU_DONE_SHFT                                     0u

#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_ADDR                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x6604u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_OFFS                                                      (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x6604u)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_RMSK                                                             0xfu
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_ADDR)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_ADDR, m)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_ADDR,v)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_ADDR,m,v,HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_IN)
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_CRC_ERROR_OUT_ACC_NOCB_TILE_DONE_ENABLE_BMSK                     0x8u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_CRC_ERROR_OUT_ACC_NOCB_TILE_DONE_ENABLE_SHFT                       3u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_CRC_ERROR_OUT_ACC_TOP_TILE_DONE_ENABLE_BMSK                      0x4u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_CRC_ERROR_OUT_ACC_TOP_TILE_DONE_ENABLE_SHFT                        2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_CRC_ERROR_OUT_ACC_IOS_TILE_DONE_ENABLE_BMSK                      0x2u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_CRC_ERROR_OUT_ACC_IOS_TILE_DONE_ENABLE_SHFT                        1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_CRC_ERROR_OUT_ACC_RTCU_DONE_ENABLE_BMSK                          0x1u
#define HWIO_SAILSS_CSR_ACC_SERIAL_CRC_ERROR_IRQ_ENABLE_0_REG_0_CRC_ERROR_OUT_ACC_RTCU_DONE_ENABLE_SHFT                            0u

#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_0_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x7000u)
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_0_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x7000u)
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_0_RMSK                                                                    0xfffffffful
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_0_IN                    \
                in_dword(HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_0_ADDR)
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_0_ADDR, m)
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_0_SRAM_REDUNDANCY_CRC_ERR_BMSK                                            0xfffffffful
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_0_SRAM_REDUNDANCY_CRC_ERR_SHFT                                                     0u

#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_1_ADDR                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x7004u)
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_1_OFFS                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x7004u)
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_1_RMSK                                                                    0xfffffffful
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_1_IN                    \
                in_dword(HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_1_ADDR)
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_1_ADDR, m)
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_1_SRAM_REDUNDANCY_CRC_ERR_BMSK                                            0xfffffffful
#define HWIO_SAILSS_CSR_SRAM_REDUNDANCY_CRC_ERR_1_SRAM_REDUNDANCY_CRC_ERR_SHFT                                                     0u

#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_ADDR                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x7008u)
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_OFFS                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x7008u)
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_RMSK                                                                       0x3u
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_IN                    \
                in_dword(HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_ADDR)
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_ADDR, m)
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_ADDR,v)
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_ADDR,m,v,HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_IN)
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_SWAO_TSYNCREADY_OVERRIDE_BMSK                                              0x2u
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_SWAO_TSYNCREADY_OVERRIDE_SHFT                                                1u
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_QDSS_TSYNCREADY_OVERRIDE_BMSK                                              0x1u
#define HWIO_SAILSS_CSR_TCSR_QDSS_TSYNCREADY_OVERRIDE_QDSS_TSYNCREADY_OVERRIDE_SHFT                                                0u

#define HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_ADDR                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x700cu)
#define HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_OFFS                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x700cu)
#define HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_RMSK                                                                                  0x1u
#define HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_ADDR)
#define HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_ADDR, m)
#define HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_ADDR,v)
#define HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_ADDR,m,v,HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_IN)
#define HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_AXI_AP_EN_BMSK                                                                        0x1u
#define HWIO_SAILSS_CSR_QDSS_AXI_AP_ENABLE_AXI_AP_EN_SHFT                                                                          0u

#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x7010u)
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x7010u)
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_RMSK                                                                         0x3u
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_IN                    \
                in_dword(HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_ADDR)
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_ADDR, m)
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_ADDR,v)
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_ADDR,m,v,HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_IN)
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_QDSS_NS_ENABLE_BACKPRESSURE_BMSK                                             0x2u
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_QDSS_NS_ENABLE_BACKPRESSURE_SHFT                                               1u
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_QDSS_NS_ENABLE_EVENT_IFACE_BMSK                                              0x1u
#define HWIO_SAILSS_CSR_QDSS_NS_STM_ENABLE_SWEVENTS_QDSS_NS_ENABLE_EVENT_IFACE_SHFT                                                0u

#define HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x7014u)
#define HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x7014u)
#define HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_RMSK                                                                            0x1u
#define HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_IN                    \
                in_dword(HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_ADDR)
#define HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_ADDR, m)
#define HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_ADDR,v)
#define HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_ADDR,m,v,HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_IN)
#define HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_QDSS_NS_ETR_TRACE_BMSK                                                          0x1u
#define HWIO_SAILSS_CSR_QDSS_NS_ETR_ENABLE_TRACE_QDSS_NS_ETR_TRACE_SHFT                                                            0u

#define HWIO_SAILSS_CSR_CRYPTO_HALTREQ_ADDR                                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x8000u)
#define HWIO_SAILSS_CSR_CRYPTO_HALTREQ_OFFS                                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x8000u)
#define HWIO_SAILSS_CSR_CRYPTO_HALTREQ_RMSK                                                                                      0x1u
#define HWIO_SAILSS_CSR_CRYPTO_HALTREQ_IN                    \
                in_dword(HWIO_SAILSS_CSR_CRYPTO_HALTREQ_ADDR)
#define HWIO_SAILSS_CSR_CRYPTO_HALTREQ_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_CRYPTO_HALTREQ_ADDR, m)
#define HWIO_SAILSS_CSR_CRYPTO_HALTREQ_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_CRYPTO_HALTREQ_ADDR,v)
#define HWIO_SAILSS_CSR_CRYPTO_HALTREQ_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_CRYPTO_HALTREQ_ADDR,m,v,HWIO_SAILSS_CSR_CRYPTO_HALTREQ_IN)
#define HWIO_SAILSS_CSR_CRYPTO_HALTREQ_CRYPTO_HALTREQ_BMSK                                                                       0x1u
#define HWIO_SAILSS_CSR_CRYPTO_HALTREQ_CRYPTO_HALTREQ_SHFT                                                                         0u

#define HWIO_SAILSS_CSR_CRYPTO_HALTACK_ADDR                                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x8004u)
#define HWIO_SAILSS_CSR_CRYPTO_HALTACK_OFFS                                                                               (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x8004u)
#define HWIO_SAILSS_CSR_CRYPTO_HALTACK_RMSK                                                                                      0x1u
#define HWIO_SAILSS_CSR_CRYPTO_HALTACK_IN                    \
                in_dword(HWIO_SAILSS_CSR_CRYPTO_HALTACK_ADDR)
#define HWIO_SAILSS_CSR_CRYPTO_HALTACK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_CRYPTO_HALTACK_ADDR, m)
#define HWIO_SAILSS_CSR_CRYPTO_HALTACK_CRYPTO_HALTACK_BMSK                                                                       0x1u
#define HWIO_SAILSS_CSR_CRYPTO_HALTACK_CRYPTO_HALTACK_SHFT                                                                         0u

#define HWIO_SAILSS_CSR_CRYPTO_MASTER_IDLE_ADDR                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x8008u)
#define HWIO_SAILSS_CSR_CRYPTO_MASTER_IDLE_OFFS                                                                           (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x8008u)
#define HWIO_SAILSS_CSR_CRYPTO_MASTER_IDLE_RMSK                                                                                  0x1u
#define HWIO_SAILSS_CSR_CRYPTO_MASTER_IDLE_IN                    \
                in_dword(HWIO_SAILSS_CSR_CRYPTO_MASTER_IDLE_ADDR)
#define HWIO_SAILSS_CSR_CRYPTO_MASTER_IDLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_CRYPTO_MASTER_IDLE_ADDR, m)
#define HWIO_SAILSS_CSR_CRYPTO_MASTER_IDLE_CRYPTO_MASTER_IDLE_BMSK                                                               0x1u
#define HWIO_SAILSS_CSR_CRYPTO_MASTER_IDLE_CRYPTO_MASTER_IDLE_SHFT                                                                 0u

#define HWIO_SAILSS_CSR_SPARE_REG0_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9000u)
#define HWIO_SAILSS_CSR_SPARE_REG0_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9000u)
#define HWIO_SAILSS_CSR_SPARE_REG0_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG0_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG0_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG0_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_REG0_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_REG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_REG0_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_REG0_IN)
#define HWIO_SAILSS_CSR_SPARE_REG0_SPARE_REG0_BMSK                                                                        0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG0_SPARE_REG0_SHFT                                                                                 0u

#define HWIO_SAILSS_CSR_SPARE_REG1_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9004u)
#define HWIO_SAILSS_CSR_SPARE_REG1_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9004u)
#define HWIO_SAILSS_CSR_SPARE_REG1_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG1_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG1_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG1_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_REG1_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_REG1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_REG1_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_REG1_IN)
#define HWIO_SAILSS_CSR_SPARE_REG1_SPARE_REG1_BMSK                                                                        0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG1_SPARE_REG1_SHFT                                                                                 0u

#define HWIO_SAILSS_CSR_SPARE_REG2_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9008u)
#define HWIO_SAILSS_CSR_SPARE_REG2_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9008u)
#define HWIO_SAILSS_CSR_SPARE_REG2_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG2_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG2_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG2_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_REG2_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_REG2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_REG2_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_REG2_IN)
#define HWIO_SAILSS_CSR_SPARE_REG2_SPARE_REG2_BMSK                                                                        0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG2_SPARE_REG2_SHFT                                                                                 0u

#define HWIO_SAILSS_CSR_SPARE_REG3_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x900cu)
#define HWIO_SAILSS_CSR_SPARE_REG3_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x900cu)
#define HWIO_SAILSS_CSR_SPARE_REG3_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG3_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG3_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG3_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG3_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_REG3_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_REG3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_REG3_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_REG3_IN)
#define HWIO_SAILSS_CSR_SPARE_REG3_SPARE_REG3_BMSK                                                                        0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG3_SPARE_REG3_SHFT                                                                                 0u

#define HWIO_SAILSS_CSR_SPARE_REG4_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9014u)
#define HWIO_SAILSS_CSR_SPARE_REG4_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9014u)
#define HWIO_SAILSS_CSR_SPARE_REG4_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG4_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG4_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG4_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG4_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_REG4_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_REG4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_REG4_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_REG4_IN)
#define HWIO_SAILSS_CSR_SPARE_REG4_SPARE_REG4_BMSK                                                                        0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG4_SPARE_REG4_SHFT                                                                                 0u

#define HWIO_SAILSS_CSR_SPARE_REG5_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9018u)
#define HWIO_SAILSS_CSR_SPARE_REG5_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9018u)
#define HWIO_SAILSS_CSR_SPARE_REG5_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG5_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG5_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG5_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG5_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_REG5_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_REG5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_REG5_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_REG5_IN)
#define HWIO_SAILSS_CSR_SPARE_REG5_SPARE_REG5_BMSK                                                                        0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG5_SPARE_REG5_SHFT                                                                                 0u

#define HWIO_SAILSS_CSR_SPARE_REG_RD6_ADDR                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x901cu)
#define HWIO_SAILSS_CSR_SPARE_REG_RD6_OFFS                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x901cu)
#define HWIO_SAILSS_CSR_SPARE_REG_RD6_RMSK                                                                                0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG_RD6_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG_RD6_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG_RD6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG_RD6_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG_RD6_SPARE_REG_RD6_BMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG_RD6_SPARE_REG_RD6_SHFT                                                                           0u

#define HWIO_SAILSS_CSR_SPARE_REG_RD7_ADDR                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9020u)
#define HWIO_SAILSS_CSR_SPARE_REG_RD7_OFFS                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9020u)
#define HWIO_SAILSS_CSR_SPARE_REG_RD7_RMSK                                                                                0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG_RD7_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG_RD7_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG_RD7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG_RD7_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG_RD7_SPARE_REG_RD7_BMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG_RD7_SPARE_REG_RD7_SHFT                                                                           0u

#define HWIO_SAILSS_CSR_SPARE_REG8_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9024u)
#define HWIO_SAILSS_CSR_SPARE_REG8_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9024u)
#define HWIO_SAILSS_CSR_SPARE_REG8_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG8_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG8_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG8_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG8_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_REG8_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_REG8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_REG8_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_REG8_IN)
#define HWIO_SAILSS_CSR_SPARE_REG8_SPARE_REG8_BMSK                                                                        0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG8_SPARE_REG8_SHFT                                                                                 0u

#define HWIO_SAILSS_CSR_SPARE_REG9_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9028u)
#define HWIO_SAILSS_CSR_SPARE_REG9_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9028u)
#define HWIO_SAILSS_CSR_SPARE_REG9_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG9_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG9_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG9_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG9_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_REG9_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_REG9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_REG9_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_REG9_IN)
#define HWIO_SAILSS_CSR_SPARE_REG9_SPARE_REG9_BMSK                                                                        0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG9_SPARE_REG9_SHFT                                                                                 0u

#define HWIO_SAILSS_CSR_SPARE_REG10_ADDR                                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x902cu)
#define HWIO_SAILSS_CSR_SPARE_REG10_OFFS                                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x902cu)
#define HWIO_SAILSS_CSR_SPARE_REG10_RMSK                                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG10_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPARE_REG10_ADDR)
#define HWIO_SAILSS_CSR_SPARE_REG10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPARE_REG10_ADDR, m)
#define HWIO_SAILSS_CSR_SPARE_REG10_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPARE_REG10_ADDR,v)
#define HWIO_SAILSS_CSR_SPARE_REG10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPARE_REG10_ADDR,m,v,HWIO_SAILSS_CSR_SPARE_REG10_IN)
#define HWIO_SAILSS_CSR_SPARE_REG10_SPARE_REG10_BMSK                                                                      0xfffffffful
#define HWIO_SAILSS_CSR_SPARE_REG10_SPARE_REG10_SHFT                                                                               0u

#define HWIO_SAILSS_CSR_TCSR_CLK_EN_ADDR                                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x907cu)
#define HWIO_SAILSS_CSR_TCSR_CLK_EN_OFFS                                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x907cu)
#define HWIO_SAILSS_CSR_TCSR_CLK_EN_RMSK                                                                                         0x1u
#define HWIO_SAILSS_CSR_TCSR_CLK_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_TCSR_CLK_EN_ADDR)
#define HWIO_SAILSS_CSR_TCSR_CLK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_TCSR_CLK_EN_ADDR, m)
#define HWIO_SAILSS_CSR_TCSR_CLK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_TCSR_CLK_EN_ADDR,v)
#define HWIO_SAILSS_CSR_TCSR_CLK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_TCSR_CLK_EN_ADDR,m,v,HWIO_SAILSS_CSR_TCSR_CLK_EN_IN)
#define HWIO_SAILSS_CSR_TCSR_CLK_EN_TCSR_CLK_EN_BMSK                                                                             0x1u
#define HWIO_SAILSS_CSR_TCSR_CLK_EN_TCSR_CLK_EN_SHFT                                                                               0u

#define HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_ADDR                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9080u)
#define HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_OFFS                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9080u)
#define HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_RMSK                                                                                0xffffu
#define HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_ADDR)
#define HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_ADDR, m)
#define HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_ADDR,v)
#define HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_ADDR,m,v,HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_IN)
#define HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_SPDM_CNT_CLK_MUX_SEL_BMSK                                                           0xffffu
#define HWIO_SAILSS_CSR_SPDM_CNT_CLK_CTRL_SPDM_CNT_CLK_MUX_SEL_SHFT                                                                0u

#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_ADDR                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9084u)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_OFFS                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9084u)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_RMSK                                                                            0xfffffffful
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_ADDR)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_ADDR, m)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_ADDR,v)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_ADDR,m,v,HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_IN)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_SPDM_WRP_CTI_CTL0_BMSK                                                          0xfffffffful
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL0_SPDM_WRP_CTI_CTL0_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_ADDR                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9088u)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_OFFS                                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9088u)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_RMSK                                                                            0xfffffffful
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_IN                    \
                in_dword(HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_ADDR)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_ADDR, m)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_ADDR,v)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_ADDR,m,v,HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_IN)
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_SPDM_WRP_CTI_CTL1_BMSK                                                          0xfffffffful
#define HWIO_SAILSS_CSR_SPDM_WRP_CTI_CTL1_SPDM_WRP_CTI_CTL1_SHFT                                                                   0u

#define HWIO_SAILSS_CSR_CLOCK_GATE_ADDR                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x908cu)
#define HWIO_SAILSS_CSR_CLOCK_GATE_OFFS                                                                                   (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x908cu)
#define HWIO_SAILSS_CSR_CLOCK_GATE_RMSK                                                                                   0xfffffffful
#define HWIO_SAILSS_CSR_CLOCK_GATE_IN                    \
                in_dword(HWIO_SAILSS_CSR_CLOCK_GATE_ADDR)
#define HWIO_SAILSS_CSR_CLOCK_GATE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_CLOCK_GATE_ADDR, m)
#define HWIO_SAILSS_CSR_CLOCK_GATE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_CLOCK_GATE_ADDR,v)
#define HWIO_SAILSS_CSR_CLOCK_GATE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_CLOCK_GATE_ADDR,m,v,HWIO_SAILSS_CSR_CLOCK_GATE_IN)
#define HWIO_SAILSS_CSR_CLOCK_GATE_CLOCK_GATE_SPARE_BMSK                                                                  0xffffffe0ul
#define HWIO_SAILSS_CSR_CLOCK_GATE_CLOCK_GATE_SPARE_SHFT                                                                           5u
#define HWIO_SAILSS_CSR_CLOCK_GATE_UMCMN_CE_IDLE_REQ_BMSK                                                                       0x10u
#define HWIO_SAILSS_CSR_CLOCK_GATE_UMCMN_CE_IDLE_REQ_SHFT                                                                          4u
#define HWIO_SAILSS_CSR_CLOCK_GATE_TCSR_CE_GLOBAL_CLKGATEDIS_CE_APB_BMSK                                                         0x8u
#define HWIO_SAILSS_CSR_CLOCK_GATE_TCSR_CE_GLOBAL_CLKGATEDIS_CE_APB_SHFT                                                           3u
#define HWIO_SAILSS_CSR_CLOCK_GATE_TCSR_CE_GLOBAL_CLKGATEDIS_CE_BMSK                                                             0x4u
#define HWIO_SAILSS_CSR_CLOCK_GATE_TCSR_CE_GLOBAL_CLKGATEDIS_CE_SHFT                                                               2u
#define HWIO_SAILSS_CSR_CLOCK_GATE_CRCM_CE_CLKGATEDIS_CE_APB_BMSK                                                                0x2u
#define HWIO_SAILSS_CSR_CLOCK_GATE_CRCM_CE_CLKGATEDIS_CE_APB_SHFT                                                                  1u
#define HWIO_SAILSS_CSR_CLOCK_GATE_CRCM_CE_CLKGATEDIS_CE_BMSK                                                                    0x1u
#define HWIO_SAILSS_CSR_CLOCK_GATE_CRCM_CE_CLKGATEDIS_CE_SHFT                                                                      0u

#define HWIO_SAILSS_CSR_ERROR_STATUS_ADDR                                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9090u)
#define HWIO_SAILSS_CSR_ERROR_STATUS_OFFS                                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9090u)
#define HWIO_SAILSS_CSR_ERROR_STATUS_RMSK                                                                                 0xfffffffful
#define HWIO_SAILSS_CSR_ERROR_STATUS_IN                    \
                in_dword(HWIO_SAILSS_CSR_ERROR_STATUS_ADDR)
#define HWIO_SAILSS_CSR_ERROR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ERROR_STATUS_ADDR, m)
#define HWIO_SAILSS_CSR_ERROR_STATUS_ERROR_STATUS_SPARE_BMSK                                                              0xfffffff8ul
#define HWIO_SAILSS_CSR_ERROR_STATUS_ERROR_STATUS_SPARE_SHFT                                                                       3u
#define HWIO_SAILSS_CSR_ERROR_STATUS_FUSA_ERR_INJ_AXI_BMSK                                                                       0x4u
#define HWIO_SAILSS_CSR_ERROR_STATUS_FUSA_ERR_INJ_AXI_SHFT                                                                         2u
#define HWIO_SAILSS_CSR_ERROR_STATUS_FUSA_ERR_INJ_AHB_BMSK                                                                       0x2u
#define HWIO_SAILSS_CSR_ERROR_STATUS_FUSA_ERR_INJ_AHB_SHFT                                                                         1u
#define HWIO_SAILSS_CSR_ERROR_STATUS_FUSA_ERR_INJ_APB_BMSK                                                                       0x1u
#define HWIO_SAILSS_CSR_ERROR_STATUS_FUSA_ERR_INJ_APB_SHFT                                                                         0u

#define HWIO_SAILSS_CSR_DUMMY_REG_ADDR                                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9094u)
#define HWIO_SAILSS_CSR_DUMMY_REG_OFFS                                                                                    (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9094u)
#define HWIO_SAILSS_CSR_DUMMY_REG_RMSK                                                                                           0x1u
#define HWIO_SAILSS_CSR_DUMMY_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_DUMMY_REG_ADDR)
#define HWIO_SAILSS_CSR_DUMMY_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DUMMY_REG_ADDR, m)
#define HWIO_SAILSS_CSR_DUMMY_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DUMMY_REG_ADDR,v)
#define HWIO_SAILSS_CSR_DUMMY_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DUMMY_REG_ADDR,m,v,HWIO_SAILSS_CSR_DUMMY_REG_IN)
#define HWIO_SAILSS_CSR_DUMMY_REG_DUMMY_BMSK                                                                                     0x1u
#define HWIO_SAILSS_CSR_DUMMY_REG_DUMMY_SHFT                                                                                       0u

#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_ADDR                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x9098u)
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_OFFS                                                                                (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x9098u)
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_RMSK                                                                                       0x7u
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_QMIP_REG_ADDR)
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_QMIP_REG_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL_QMIP_REG_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL_QMIP_REG_ADDR,m,v,HWIO_SAILSS_CSR_SAIL_QMIP_REG_IN)
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_SAFE_BMSK                                                                                  0x4u
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_SAFE_SHFT                                                                                    2u
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_DANGER_BMSK                                                                                0x3u
#define HWIO_SAILSS_CSR_SAIL_QMIP_REG_DANGER_SHFT                                                                                  0u

#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x909cu)
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x909cu)
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_RMSK                                                                                0x3fu
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_IN                    \
                in_dword(HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_ADDR)
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_ADDR, m)
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER1_S_VLD_RDY_ERR_BMSK                                                         0x20u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER1_S_VLD_RDY_ERR_SHFT                                                            5u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER0_S_VLD_RDY_ERR_BMSK                                                         0x10u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER0_S_VLD_RDY_ERR_SHFT                                                            4u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER1_M1_VLD_RDY_ERR_BMSK                                                         0x8u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER1_M1_VLD_RDY_ERR_SHFT                                                           3u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER1_M0_VLD_RDY_ERR_BMSK                                                         0x4u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER1_M0_VLD_RDY_ERR_SHFT                                                           2u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER0_M1_VLD_RDY_ERR_BMSK                                                         0x2u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER0_M1_VLD_RDY_ERR_SHFT                                                           1u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER0_M0_VLD_RDY_ERR_BMSK                                                         0x1u
#define HWIO_SAILSS_CSR_CLUSTER_VLD_RDY_ERR_CLUSTER0_M0_VLD_RDY_ERR_SHFT                                                           0u

#define HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90a0u)
#define HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90a0u)
#define HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_RMSK                                                                                 0x1u
#define HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_IN                    \
                in_dword(HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_ADDR)
#define HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_ADDR, m)
#define HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_ADDR,v)
#define HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_ADDR,m,v,HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_IN)
#define HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_CSR_VLD_RDY_ERR_CLR_BMSK                                                             0x1u
#define HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_CSR_VLD_RDY_ERR_CLR_SHFT                                                               0u

#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90a4u)
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90a4u)
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_RMSK                                                                         0xfu
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_ADDR)
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_ADDR, m)
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_ADDR,v)
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_ADDR,m,v,HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_IN)
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_QSPI2_ASILB_PIPE_TEST_BUS_EN_BMSK                                            0xcu
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_QSPI2_ASILB_PIPE_TEST_BUS_EN_SHFT                                              2u
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_AHB2AHB_SLAVE_TEST_BUS_EN_BMSK                                               0x2u
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_AHB2AHB_SLAVE_TEST_BUS_EN_SHFT                                                 1u
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_AHB2AHB_MASTER_TEST_BUS_EN_BMSK                                              0x1u
#define HWIO_SAILSS_CSR_BRIDGE_PIPE_TEST_BUS_EN_REG_AHB2AHB_MASTER_TEST_BUS_EN_SHFT                                                0u

#define HWIO_SAILSS_CSR_CE_UMCMN_REG_ADDR                                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90a8u)
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_OFFS                                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90a8u)
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_RMSK                                                                                        0xfu
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_CE_UMCMN_REG_ADDR)
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_CE_UMCMN_REG_ADDR, m)
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_CE_WCMN_IDLE_BMSK                                                                           0x8u
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_CE_WCMN_IDLE_SHFT                                                                             3u
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_CE_UMCMN_IDLE_RESP_BMSK                                                                     0x4u
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_CE_UMCMN_IDLE_RESP_SHFT                                                                       2u
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_CE_UMCMN_IDLE_REQ_ACK_BMSK                                                                  0x2u
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_CE_UMCMN_IDLE_REQ_ACK_SHFT                                                                    1u
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_CE_UMCMN_CMD_RING_NOT_EMPTY_BMSK                                                            0x1u
#define HWIO_SAILSS_CSR_CE_UMCMN_REG_CE_UMCMN_CMD_RING_NOT_EMPTY_SHFT                                                              0u

#define HWIO_SAILSS_CSR_CE_WIFICMN_TRACEBUS_MA_REG1_ADDR                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90acu)
#define HWIO_SAILSS_CSR_CE_WIFICMN_TRACEBUS_MA_REG1_OFFS                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90acu)
#define HWIO_SAILSS_CSR_CE_WIFICMN_TRACEBUS_MA_REG1_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_CSR_CE_WIFICMN_TRACEBUS_MA_REG1_IN                    \
                in_dword(HWIO_SAILSS_CSR_CE_WIFICMN_TRACEBUS_MA_REG1_ADDR)
#define HWIO_SAILSS_CSR_CE_WIFICMN_TRACEBUS_MA_REG1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_CE_WIFICMN_TRACEBUS_MA_REG1_ADDR, m)
#define HWIO_SAILSS_CSR_CE_WIFICMN_TRACEBUS_MA_REG1_CE_WIFICMN_TRACEBUS_MA_REG1_BMSK                                      0xfffffffful
#define HWIO_SAILSS_CSR_CE_WIFICMN_TRACEBUS_MA_REG1_CE_WIFICMN_TRACEBUS_MA_REG1_SHFT                                               0u

#define HWIO_SAILSS_CSR_ERROR_INJECTION_ADDR                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90b4u)
#define HWIO_SAILSS_CSR_ERROR_INJECTION_OFFS                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90b4u)
#define HWIO_SAILSS_CSR_ERROR_INJECTION_RMSK                                                                                     0x3u
#define HWIO_SAILSS_CSR_ERROR_INJECTION_IN                    \
                in_dword(HWIO_SAILSS_CSR_ERROR_INJECTION_ADDR)
#define HWIO_SAILSS_CSR_ERROR_INJECTION_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_ERROR_INJECTION_ADDR, m)
#define HWIO_SAILSS_CSR_ERROR_INJECTION_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_ERROR_INJECTION_ADDR,v)
#define HWIO_SAILSS_CSR_ERROR_INJECTION_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_ERROR_INJECTION_ADDR,m,v,HWIO_SAILSS_CSR_ERROR_INJECTION_IN)
#define HWIO_SAILSS_CSR_ERROR_INJECTION_INJ_ERR_RST_BMSK                                                                         0x2u
#define HWIO_SAILSS_CSR_ERROR_INJECTION_INJ_ERR_RST_SHFT                                                                           1u
#define HWIO_SAILSS_CSR_ERROR_INJECTION_INJ_ERR_EN_BMSK                                                                          0x1u
#define HWIO_SAILSS_CSR_ERROR_INJECTION_INJ_ERR_EN_SHFT                                                                            0u

#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_ADDR                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90b8u)
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_OFFS                                                                              (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90b8u)
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_RMSK                                                                                     0x3u
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_IN                    \
                in_dword(HWIO_SAILSS_CSR_AXPROT_OVERRIDE_ADDR)
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_AXPROT_OVERRIDE_ADDR, m)
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_AXPROT_OVERRIDE_ADDR,v)
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_AXPROT_OVERRIDE_ADDR,m,v,HWIO_SAILSS_CSR_AXPROT_OVERRIDE_IN)
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_AXPROT_OVERRIDE_DMA_BMSK                                                                 0x2u
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_AXPROT_OVERRIDE_DMA_SHFT                                                                   1u
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_AXPROT_OVERRIDE_RTCU_BMSK                                                                0x1u
#define HWIO_SAILSS_CSR_AXPROT_OVERRIDE_AXPROT_OVERRIDE_RTCU_SHFT                                                                  0u

#define HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_ADDR                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90bcu)
#define HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_OFFS                                                            (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90bcu)
#define HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_RMSK                                                                   0x1u
#define HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_ADDR)
#define HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_ADDR,m,v,HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_IN)
#define HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_BMSK                                 0x1u
#define HWIO_SAILSS_CSR_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_SAIL_QTIC_INTERNAL_BRIDGE_POST_EN_SHFT                                   0u

#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_ADDR                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90c0u)
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_OFFS                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90c0u)
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_RMSK                                                                                0x3u
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_IN                    \
                in_dword(HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_ADDR)
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_ADDR, m)
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_ADDR,v)
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_ADDR,m,v,HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_IN)
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_QDSS_DCC_SPIDEN_OVR_BMSK                                                            0x2u
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_QDSS_DCC_SPIDEN_OVR_SHFT                                                              1u
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_QDSS_QSEE_SPIDEN_OVR_BMSK                                                           0x1u
#define HWIO_SAILSS_CSR_QDSS_SPIDEN_OVERRIDE_QDSS_QSEE_SPIDEN_OVR_SHFT                                                             0u

#define HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_ADDR                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90c4u)
#define HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_OFFS                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90c4u)
#define HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_RMSK                                                                            0x1u
#define HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_IN                    \
                in_dword(HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_ADDR)
#define HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_ADDR, m)
#define HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_ADDR,v)
#define HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_ADDR,m,v,HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_IN)
#define HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_SAIL_QTIC_BRIDGE_POST_EN_BMSK                                                   0x1u
#define HWIO_SAILSS_CSR_SAIL_QTIC_BRIDGE_POST_EN_SAIL_QTIC_BRIDGE_POST_EN_SHFT                                                     0u

#define HWIO_SAILSS_CSR_DMA_CSR0_ADDR                                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90c8u)
#define HWIO_SAILSS_CSR_DMA_CSR0_OFFS                                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90c8u)
#define HWIO_SAILSS_CSR_DMA_CSR0_RMSK                                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_DMA_CSR0_IN                    \
                in_dword(HWIO_SAILSS_CSR_DMA_CSR0_ADDR)
#define HWIO_SAILSS_CSR_DMA_CSR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DMA_CSR0_ADDR, m)
#define HWIO_SAILSS_CSR_DMA_CSR0_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DMA_CSR0_ADDR,v)
#define HWIO_SAILSS_CSR_DMA_CSR0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DMA_CSR0_ADDR,m,v,HWIO_SAILSS_CSR_DMA_CSR0_IN)
#define HWIO_SAILSS_CSR_DMA_CSR0_DMA_CSR0_BMSK                                                                            0xfffffffful
#define HWIO_SAILSS_CSR_DMA_CSR0_DMA_CSR0_SHFT                                                                                     0u

#define HWIO_SAILSS_CSR_DMA_CSR1_ADDR                                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90ccu)
#define HWIO_SAILSS_CSR_DMA_CSR1_OFFS                                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90ccu)
#define HWIO_SAILSS_CSR_DMA_CSR1_RMSK                                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_DMA_CSR1_IN                    \
                in_dword(HWIO_SAILSS_CSR_DMA_CSR1_ADDR)
#define HWIO_SAILSS_CSR_DMA_CSR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DMA_CSR1_ADDR, m)
#define HWIO_SAILSS_CSR_DMA_CSR1_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DMA_CSR1_ADDR,v)
#define HWIO_SAILSS_CSR_DMA_CSR1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DMA_CSR1_ADDR,m,v,HWIO_SAILSS_CSR_DMA_CSR1_IN)
#define HWIO_SAILSS_CSR_DMA_CSR1_DMA_CSR1_BMSK                                                                            0xfffffffful
#define HWIO_SAILSS_CSR_DMA_CSR1_DMA_CSR1_SHFT                                                                                     0u

#define HWIO_SAILSS_CSR_DMA_CSR2_ADDR                                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90d0u)
#define HWIO_SAILSS_CSR_DMA_CSR2_OFFS                                                                                     (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90d0u)
#define HWIO_SAILSS_CSR_DMA_CSR2_RMSK                                                                                     0xfffffffful
#define HWIO_SAILSS_CSR_DMA_CSR2_IN                    \
                in_dword(HWIO_SAILSS_CSR_DMA_CSR2_ADDR)
#define HWIO_SAILSS_CSR_DMA_CSR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_DMA_CSR2_ADDR, m)
#define HWIO_SAILSS_CSR_DMA_CSR2_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_DMA_CSR2_ADDR,v)
#define HWIO_SAILSS_CSR_DMA_CSR2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_DMA_CSR2_ADDR,m,v,HWIO_SAILSS_CSR_DMA_CSR2_IN)
#define HWIO_SAILSS_CSR_DMA_CSR2_DMA_CSR2_BMSK                                                                            0xfffffffful
#define HWIO_SAILSS_CSR_DMA_CSR2_DMA_CSR2_SHFT                                                                                     0u

#define HWIO_SAILSS_CSR_QDSS_AC_REG_ADDR                                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90d4u)
#define HWIO_SAILSS_CSR_QDSS_AC_REG_OFFS                                                                                  (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90d4u)
#define HWIO_SAILSS_CSR_QDSS_AC_REG_RMSK                                                                                         0x7u
#define HWIO_SAILSS_CSR_QDSS_AC_REG_IN                    \
                in_dword(HWIO_SAILSS_CSR_QDSS_AC_REG_ADDR)
#define HWIO_SAILSS_CSR_QDSS_AC_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_QDSS_AC_REG_ADDR, m)
#define HWIO_SAILSS_CSR_QDSS_AC_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_QDSS_AC_REG_ADDR,v)
#define HWIO_SAILSS_CSR_QDSS_AC_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_QDSS_AC_REG_ADDR,m,v,HWIO_SAILSS_CSR_QDSS_AC_REG_IN)
#define HWIO_SAILSS_CSR_QDSS_AC_REG_DCC_APPS_SPIDEN_BMSK                                                                         0x4u
#define HWIO_SAILSS_CSR_QDSS_AC_REG_DCC_APPS_SPIDEN_SHFT                                                                           2u
#define HWIO_SAILSS_CSR_QDSS_AC_REG_FUSE_QSEE_SPIDEN_BMSK                                                                        0x2u
#define HWIO_SAILSS_CSR_QDSS_AC_REG_FUSE_QSEE_SPIDEN_SHFT                                                                          1u
#define HWIO_SAILSS_CSR_QDSS_AC_REG_DCC_HPRIV_OVERRIDE_BMSK                                                                      0x1u
#define HWIO_SAILSS_CSR_QDSS_AC_REG_DCC_HPRIV_OVERRIDE_SHFT                                                                        0u

#define HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_ADDR                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x90d8u)
#define HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_OFFS                                                                         (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x90d8u)
#define HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_RMSK                                                                         0xfffffffful
#define HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_IN                    \
                in_dword(HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_ADDR)
#define HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_ADDR, m)
#define HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_ADDR,v)
#define HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_ADDR,m,v,HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_IN)
#define HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_CSR_BOOT_MISC_DETECT_BMSK                                                    0xfffffffful
#define HWIO_SAILSS_CSR_CSR_BOOT_MISC_DETECT_CSR_BOOT_MISC_DETECT_SHFT                                                             0u

#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_ADDR(n)                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0X90DC + (0x4*(n)))
#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_OFFS(n)                                                                 (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0X90DC + (0x4*(n)))
#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_RMSK                                                                    0xfffffffful
#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_MAXn                                                                             7u
#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_ADDR(n), HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_RMSK)
#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_ADDR(n), mask)
#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_ADDR(n),val)
#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_ADDR(n),mask,val,HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_INI(n))
#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_SAIL_PRNG_FIPS_MODE_REG_BMSK                                            0xfffffffful
#define HWIO_SAILSS_CSR_SAIL_PRNG_FIPS_MODE_REG_n_SAIL_PRNG_FIPS_MODE_REG_SHFT                                                     0u


#endif /* __SAIL_CSR_HWIO_H__ */
