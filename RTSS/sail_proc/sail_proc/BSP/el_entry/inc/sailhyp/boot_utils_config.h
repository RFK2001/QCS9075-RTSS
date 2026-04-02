/**
 * @file boot.h
 * @brief Sail boot API  
 * Header file for the definition of Sail Boot API
 *
 *        Copyright (c) 2021 -2022 Qualcomm Technologies, Inc.
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

#ifndef BOOT_UTILS_CONFIG_H
#define BOOT_UTILS_CONFIG_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "types.h"
#include "arm_acle.h"
#include "target.h"
/*===========================================================================
                           MACROS
===========================================================================*/
#define SAIL_TEE_RESERVED_LENGTH 32
#define BOARD_PROVISION_ERROR    1
#define IMAGE_LOAD_ERROR         2
#define IMAGE_NOT_FOUND          3
/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/



/*===========================================================================
                           EXTERNS
===========================================================================*/

/*
 *===========================================================================
                          FUNCTIONS
 *===========================================================================*/

/*===========================================================================
**  Function :  sailbsp_enable_comparator
** ==========================================================================
*/
/*!
*
* @brief
*   Enable comparators if cluster 0, or cluster 1 is running in lockstep
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
void sailbsp_enable_comparator(void);

/*===========================================================================
**  Function :  sailbsp_iscluster_lockstep
** ==========================================================================
*/
/*!
*
* @brief
*   checks if the cluster is lockstepped or split
*
* @param
    cluster_num
* @par Dependencies
*   None
* @retval
*   TRUE if cluster is locksteped, FALSE otherwise
* @par Side Effects
*   None
*
*/
bool sailbsp_iscluster_lockstep(uint8 cluster_num);


void sailbsp_enable_mem_profiler(void);
 /*===========================================================================
**  Function :  heap_init
** ==========================================================================
*/

/*
*
* @brief
*   Routine which initalizes the ARMLIBs heap allocator.
*
* @param
*   Heap Start  address and Heap End address.
* @par Dependencies
*   Earmark the Heap and Stack paritions. Update the Stack section in Linker script
* @retval
*   None
* @par Side Effects
*   None
*
*/
void heap_init(void);

 /*===========================================================================
**  Function :  qup_mem_init
** ==========================================================================
*/

/*
*
* @brief
*   The QUP MEM is not cleared and rest to 0 on power reset . this routine does the same
  by memsetting the region to 0x0 . Invoke this api as early as posbile before any one
  uses log apis
*
* @param
*    
* @par Dependencies
*    
* @retval
*   None
* @par Side Effects
*   None
*
*/

/**/
void qup_mem_init(void);

/*===========================================================================
**  Function :  boot_config_update_boot_image_info
** ==========================================================================
*/
/*!
*
* @brief
*    
*
* @param
    image_id
    image entry address
    image status
* @par Dependencies
*    
* @retval
*   T 
* @par Side Effects
*   None
*
*/
void boot_config_update_boot_image_info ( boot_image_id_enum_type id, uint32_t image_entry, uint32_t status);

/*===========================================================================
**  Function :  boot_config_get_image_entry
** ==========================================================================
*/
/*!
*
* @brief
*    
*
* @param
    image_id
    cpu_id
* @par Dependencies
*   None
* @retval
*   image entry address
* @par Side Effects
*   None
*
*/
uint32_t boot_config_get_image_entry ( boot_image_id_enum_type id, uint32_t phys_core_id );

void boot_utils_cpu_exit_el2 ( uint32_t phys_core_id);
uint32_t boot_utils_load_elfs(uint32_t phys_core_id);
uint32_t boot_util_smp_os_get_master_core(uint32_t ulSmpOSImage_CoreCfg);
void boot_util_frame_smp_os_core_cfg( void );
uint32_t boot_config_get_loaded_image_id (uint32_t *image_id );
uint32_t boot_config_get_core_image_id(uint32_t phys_core_id);
#endif  
