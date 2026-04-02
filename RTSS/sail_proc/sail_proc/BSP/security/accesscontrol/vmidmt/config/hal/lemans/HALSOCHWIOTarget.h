#ifndef HALSOCHWIOTARGET_H
#define HALSOCHWIOTARGET_H
/*
===========================================================================
*/
/**
    @file HALSOCHWIOTarget.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) r2 [lemansau_2.0_p3q3r42_MTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_CSR_SAILSS_CSR

    'Include' filters applied: .*SOC_HW.* 

    Generation parameters: 
    { 'filename': 'HALSOCHWIOTarget.h',
      'filter-include': ['.*SOC_HW.*'],
      'header': '#include "msmhwiobase.h"',
      'integer-qualifiers': True,
      'modules': ['SAILSS_CSR_SAILSS_CSR'],
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
 * MODULE: SAILSS_CSR_SAILSS_CSR
 *--------------------------------------------------------------------------*/

#define SAILSS_CSR_SAILSS_CSR_REG_BASE                                                                                    (SAILSS_CSR_SAILSS_CSR_BASE      + 0x00000000U)
#define SAILSS_CSR_SAILSS_CSR_REG_BASE_SIZE                                                                               0xa000U
#define SAILSS_CSR_SAILSS_CSR_REG_BASE_USED                                                                               0x90f8U
#define SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS                                                                               0x00000000U

#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE      + 0x38U)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_OFFS                                                                          (SAILSS_CSR_SAILSS_CSR_REG_BASE_OFFS + 0x38U)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_RMSK                                                                          0xffffffffUL
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_IN                    \
                in_dword(HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR, m)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_OUT(v)            \
                out_dword(HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR,v)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_ADDR,m,v,HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_IN)
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_FAMILY_NUMBER_BMSK                                                   0xf0000000UL
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_FAMILY_NUMBER_SHFT                                                           28U
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_DEVICE_NUMBER_BMSK                                                    0xfff0000UL
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_DEVICE_NUMBER_SHFT                                                           16U
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_MAJOR_VERSION_BMSK                                                       0xff00U
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_MAJOR_VERSION_SHFT                                                            8U
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_MINOR_VERSION_BMSK                                                         0xffU
#define HWIO_SAILSS_CSR_SW_WONCE_SOC_HW_VER_SW_WONCE_MINOR_VERSION_SHFT                                                            0U


#endif /* HALSOCHWIOTARGET_H */
