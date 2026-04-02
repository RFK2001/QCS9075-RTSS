#ifndef __G_SAIL_TO_MD_SECURITY_CONTROL_CORE_HWIO_H__
#define __G_SAIL_TO_MD_SECURITY_CONTROL_CORE_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_SECURITY_CONTROL_CORE_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_SECURITY_CONTROL_CORE

    'Include' filters applied: SAIL_TO_MD_BOOT_CONFIG[SAIL_TO_MD_SECURITY_CONTROL_CORE] SAIL_TO_MD_CAPT_SEC*[SAIL_TO_MD_SECURITY_CONTROL_CORE] 

    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_SECURITY_CONTROL_CORE_HWIO.h',
      'integer-qualifiers': True,
      'module-filter-include': { 'SAIL_TO_MD_SECURITY_CONTROL_CORE': [ 'SAIL_TO_MD_BOOT_CONFIG',
                                                                       'SAIL_TO_MD_CAPT_SEC*']},
      'modules': ['SAIL_TO_MD_SECURITY_CONTROL_CORE'],
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
 * MODULE: SAIL_TO_MD_SECURITY_CONTROL_CORE
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_SECURITY_CONTROL_CORE_REG_BASE                                                                           (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x00780000ul)
#define SAIL_TO_MD_SECURITY_CONTROL_CORE_REG_BASE_SIZE                                                                      0x7000u
#define SAIL_TO_MD_SECURITY_CONTROL_CORE_REG_BASE_USED                                                                      0x6474u
#define SAIL_TO_MD_SECURITY_CONTROL_CORE_REG_BASE_OFFS                                                                      0x00780000ul

#define HWIO_SAIL_TO_MD_BOOT_CONFIG_ADDR                                                                                    (SAIL_TO_MD_SECURITY_CONTROL_CORE_REG_BASE      + 0x6064u)
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_OFFS                                                                                    (SAIL_TO_MD_SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x6064u)
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_RMSK                                                                                         0x1ffu
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_IN                    \
                in_dword(HWIO_SAIL_TO_MD_BOOT_CONFIG_ADDR)
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_BOOT_CONFIG_ADDR, m)
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_SKIP_MD_BIST_BMSK                                                                            0x100u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_SKIP_MD_BIST_SHFT                                                                                8u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_BMSK                                                                      0xc0u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_SHFT                                                                         6u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_ENUM_600_MZ_FVAL                                                           0x0u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_CXO_FVAL                                                                   0x1u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_ENUM_600_MHZ_FVAL                                                          0x2u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_NA_FVAL                                                                    0x3u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_FAST_BOOT_BMSK                                                                                0x3eu
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_FAST_BOOT_SHFT                                                                                   1u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_FAST_BOOT_DEFAULT_FVAL                                                                         0x0u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_FAST_BOOT_SD_USB_FVAL                                                                          0x1u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_FAST_BOOT_QSPI_USB_FVAL                                                                        0x2u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_FAST_BOOT_SPI_USB_FVAL                                                                         0x3u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_FAST_BOOT_UFS_USB_FVAL                                                                         0x4u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_FAST_BOOT_USB_FVAL                                                                             0x5u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_WDOG_EN_BMSK                                                                                   0x1u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_WDOG_EN_SHFT                                                                                     0u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_WDOG_EN_GPIO_CONTROLLED_FVAL                                                                   0x0u
#define HWIO_SAIL_TO_MD_BOOT_CONFIG_WDOG_EN_ENABLE_WDOG_FVAL                                                                       0x1u

#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_ADDR                                                                                  (SAIL_TO_MD_SECURITY_CONTROL_CORE_REG_BASE      + 0x6100u)
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_OFFS                                                                                  (SAIL_TO_MD_SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x6100u)
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_RMSK                                                                                     0x1fffful
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_ADDR)
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_ADDR, m)
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_ADDR,v)
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_ADDR,m,v,HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_IN)
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_EUD_ENUM_EN_GPIO_BMSK                                                                    0x10000ul
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_EUD_ENUM_EN_GPIO_SHFT                                                                         16u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_FORCE_USB_BOOT_GPIO_BMSK                                                                  0x8000u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_FORCE_USB_BOOT_GPIO_SHFT                                                                      15u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_SKIP_MD_BIST_BMSK                                                        0x4000u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_SKIP_MD_BIST_SHFT                                                            14u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_DDR_CH_SEL_BMSK                                                          0x3000u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_DDR_CH_SEL_SHFT                                                              12u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_RSVD_BMSK                                                                 0x800u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_RSVD_SHFT                                                                    11u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_PK_HASH_IN_FUSE_BMSK                                                   0x400u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_PK_HASH_IN_FUSE_SHFT                                                      10u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_ALL_USE_SERIAL_NUM_BMSK                                                   0x200u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_ALL_USE_SERIAL_NUM_SHFT                                                       9u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_PK_HASH_INDEX_SRC_BMSK                                                    0x100u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_PK_HASH_INDEX_SRC_SHFT                                                        8u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_AUTH_EN_BMSK                                                            0x80u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_AUTH_EN_SHFT                                                               7u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_PBL_BOOT_SPEED_BMSK                                                   0x60u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_PBL_BOOT_SPEED_SHFT                                                      5u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_FAST_BOOT_BMSK                                                             0x1eu
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_FAST_BOOT_SHFT                                                                1u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_WDOG_DISABLE_BMSK                                                           0x1u
#define HWIO_SAIL_TO_MD_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_WDOG_DISABLE_SHFT                                                             0u


#endif /* __G_SAIL_TO_MD_SECURITY_CONTROL_CORE_HWIO_H__ */
