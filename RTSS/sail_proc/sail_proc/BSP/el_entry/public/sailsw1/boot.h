/**
 * @file boot.h
 * @brief Sail boot API  
 * Header file for the definition of Sail Boot API
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
07.08.21   rrahul       Created
=============================================================================*/

#ifndef BOOT_H
#define BOOT_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "types.h"
#include "arm_acle.h"
#include "common_functions.h"
/*===========================================================================
                           MACROS
===========================================================================*/
#define SAIL_TEE_RESERVED_LENGTH 32
#define SAILHEAP_EL1_SIZE                  (0x2000)   /* 8KB */
/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/


/*===========================================================================
                           EXTERNS
===========================================================================*/
extern uint8_t ucSailHeapEL1[4][SAILHEAP_EL1_SIZE] __attribute__ ((aligned(EL_SHARED_CACHELINE_SIZE)));
/*
 *===========================================================================
                          FUNCTIONS
 *===========================================================================*/

/*===========================================================================
**  Function :  sailbsp_boot_cold_init
** ==========================================================================
*/
/*!
*
* @brief
*   sailbsp_boot_cold_init is the cold boot initialization routine called during power on.
*   This will be called only once on and only on the boot core.
*
* @param
*   cpu_index
*   pbl_shared info
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   This function never returns.
*
*/
uint32_t  sailbsp_boot_cold_init(int cpu_id);

/*===========================================================================
**  Function :  sailbsp_boot_secondary_init
** ==========================================================================
*/
/*!
*
* @brief
*   sailbsp_boot_secondary_init is the cold boot initialization routine called during power on.
*   This will be called for the secondary core.
*
* @param
*   cpu_index
*   cluster_index
* @par Dependencies
*   Boot core should be up. 
* @retval
*   None
* @par Side Effects
*   None
*
*/
void sailbsp_boot_secondary_init(int cpu_id, int cluster_id);

/*===========================================================================
**  Function :  sailbsp_boot_warm_init
** ==========================================================================
*/
/*!
*
* @brief
*   // Warm (second or later) power-on of any CPU.
*
* @param
*   cpu_index
*   cluster_index
* @par Dependencies
*   Cold boot should be done.And it should have gone to Lower power mode.
* @retval
*   None
* @par Side Effects
*   None
*
*/
// Warm (second or later) power-on of any CPU.
void  sailbsp_boot_warm_init(int cpu_id, int cluster_id);



#endif  
