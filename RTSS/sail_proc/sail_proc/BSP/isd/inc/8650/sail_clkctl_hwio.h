#ifndef SAIL_CLKCTL_HWIO_H
#define SAIL_CLKCTL_HWIO_H
/*
===========================================================================
*/
/**
    @file sail_clkctl_hwio.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) r2 [lemansau_2.0_p3q3r42_MTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG

    'Include' filters applied: SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] 

    Generation parameters: 
    { 'filename': 'sail_clkctl_hwio.h',
      'integer-qualifiers': True,
      'module-filter-include': { 'SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG': [ 'SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET']},
      'modules': ['SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG'],
      'output-attrs': True,
      'output-fvals': True,
      'output-offsets': True}

    Attribute definitions for the HWIO_*_ATTR macros are as follows:
        0x0: Command register
        0x1: Read-Only
        0x2: Write-Only
        0x3: Read/Write
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
 * MODULE: SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG
 *--------------------------------------------------------------------------*/

#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE                                                 (SAILSS_CLKCTL_SAILSS_CC_BASE      + 0x00010000UL)
#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_SIZE                                            0xf0000UL
#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_USED                                            0x3c000UL
#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS                                            0x00010000UL

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_ADDR                                                (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x1700U)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_OFFS                                                (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x1700U)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RMSK                                                0x80000001UL
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_ATTR                                                             0x3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTACKN_BMSK                                        0x80000000UL
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTACKN_SHFT                                                31U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTACKN_RSTACKN_ASSERTED_FVAL                              0x0U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTACKN_RSTACKN_DEASSERTED_FVAL                            0x1U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTREQN_BMSK                                               0x1U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTREQN_SHFT                                                 0U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTREQN_ASSERT_RSTREQN_FVAL                                0x0U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTREQN_DEASSERT_RSTREQN_FVAL                              0x1U


#endif /* SAIL_CLKCTL_HWIO_H */
