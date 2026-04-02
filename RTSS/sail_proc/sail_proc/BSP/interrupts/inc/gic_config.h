/**
 * @file gic_config.c
 * @brief
 * Header file for GIC config paramenteres.
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
08.11.21   rrahul       Created
=============================================================================*/
#ifndef __GIC_CONFIG_H
#define __GIC_CONFIG_H

/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include "target.h"



/*===========================================================================
                               DEFINES
============================================================================*/
typedef struct __gic_hw_config {
    //ToDO check if we need to add anything else here
    //ToDo we shoud have a better type for HWIO address to change it to uint64.
    uint32_t    gic_distributor_offset;
    uint32_t    gic_redistributor_offset;
    uint32_t    gic_redistributor_stride;
}gic_hw_config;



 /*===========================================================================
                               VARIABLES
============================================================================*/
gic_hw_config sailbsp_gic_instances[2] = {
                                    { 0xFD200000, 0xFD300000, 0x20000},
                                    { 0xFD400000, 0xFD500000, 0x20000}
                                    };

#endif

