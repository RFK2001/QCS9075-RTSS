#ifndef __G_SAIL_ASIL_B_H__
#define __G_SAIL_ASIL_B_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_ASIL_B.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_ASIL_B_SAIL_ASIL_B_NOC

    'Include' filters applied: SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW[SAILSS_ASIL_B_SAIL_ASIL_B_NOC] 

    Generation parameters: 
    { 'filename': 'g_SAIL_ASIL_B.h',
      'integer-qualifiers': True,
      'module-filter-include': { 'SAILSS_ASIL_B_SAIL_ASIL_B_NOC': [ 'SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW']},
      'modules': ['SAILSS_ASIL_B_SAIL_ASIL_B_NOC'],
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
 * MODULE: SAILSS_ASIL_B_SAIL_ASIL_B_NOC
 *--------------------------------------------------------------------------*/

#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE                                                                                        (SAILSS_ASIL_B_SAIL_ASIL_B_NOC_BASE      + 0x00000000u)
#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE_SIZE                                                                                   0x48080ul
#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE_USED                                                                                   0x48018ul
#define SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE_OFFS                                                                                   0x00000000u

#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_ADDR                                            (SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE      + 0x2088u)
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_OFFS                                            (SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE_OFFS + 0x2088u)
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_RMSK                                               0xffffful
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_OUT(v)            \
                out_dword(HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_ADDR,v)
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT19_BMSK                                        0x80000ul
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT19_SHFT                                             19u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT18_BMSK                                        0x40000ul
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT18_SHFT                                             18u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT17_BMSK                                        0x20000ul
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT17_SHFT                                             17u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT16_BMSK                                        0x10000ul
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT16_SHFT                                             16u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT15_BMSK                                         0x8000u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT15_SHFT                                             15u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT14_BMSK                                         0x4000u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT14_SHFT                                             14u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT13_BMSK                                         0x2000u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT13_SHFT                                             13u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT12_BMSK                                         0x1000u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT12_SHFT                                             12u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT11_BMSK                                          0x800u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT11_SHFT                                             11u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT10_BMSK                                          0x400u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT10_SHFT                                             10u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT9_BMSK                                           0x200u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT9_SHFT                                               9u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT8_BMSK                                           0x100u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT8_SHFT                                               8u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT7_BMSK                                            0x80u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT7_SHFT                                               7u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT6_BMSK                                            0x40u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT6_SHFT                                               6u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT5_BMSK                                            0x20u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT5_SHFT                                               5u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT4_BMSK                                            0x10u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT4_SHFT                                               4u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT3_BMSK                                             0x8u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT3_SHFT                                               3u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT2_BMSK                                             0x4u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT2_SHFT                                               2u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT1_BMSK                                             0x2u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT1_SHFT                                               1u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT0_BMSK                                             0x1u
#define HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT0_SHFT                                               0u


#endif /* __G_SAIL_ASIL_B_H__ */
