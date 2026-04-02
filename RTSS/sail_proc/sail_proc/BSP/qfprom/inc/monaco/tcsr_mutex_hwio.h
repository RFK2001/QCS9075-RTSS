#ifndef TCSR_MUTEX_HWIO_H
#define TCSR_MUTEX_HWIO_H
/*
===========================================================================
*/
/**
    @file tcsr_mutex_hwio.h
    @brief Auto-generated HWIO interface include file.

    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX

    'Include' filters applied: SAIL_TO_MD_TCSR_MUTEX_REG_n[SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX] 

    Generation parameters: 
    { 'exclude-reserved': True,
      'filename': 'tcsr_mutex_hwio.h',
      'header': '#include "msmhwiobase.h"',
      'integer-qualifiers': True,
      'module-filter-include': { 'SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX': [ 'SAIL_TO_MD_TCSR_MUTEX_REG_n']},
      'modules': ['SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX']}
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

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX_REG_BASE                                                       (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x01f40000UL)
#define SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX_REG_BASE_SIZE                                                  0x40000UL
#define SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX_REG_BASE_USED                                                  0x3500cUL

#define HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_ADDR(n)                                                       (SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX_REG_BASE      + 0X0 + (0x1000*(n)))
#define HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_RMSK                                                                0xffU
#define HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_MAXn                                                                  31U
#define HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_INI(n)                \
                in_dword_masked(HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_ADDR(n), HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_RMSK)
#define HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_ADDR(n), mask)
#define HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_OUTI(n,val)        \
                out_dword(HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_ADDR(n),val)
#define HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_ADDR(n),mask,val,HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_INI(n))
#define HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_MUTEX_BMSK                                                          0xffU
#define HWIO_SAIL_TO_MD_TCSR_MUTEX_REG_n_MUTEX_SHFT                                                             0U


#endif /* TCSR_MUTEX_HWIO_H */
