/**
 * @file boot_config.c
 * @brief
 * Source file for Sail Image boot config
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
06.23.22   rrahul       Created
=============================================================================*/


/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "types.h"
#include "errno.h"
#include "boot.h"
#include "target.h"
#include "common_functions.h"

/*===========================================================================
                               MACROS
===========================================================================*/

/*===========================================================================
                               VARIABLES
============================================================================*/
static boot_image_info_type g_boot_image_info[BOOT_IMAGE_ID_MAX] =
{
    {0,               0, BOOT_IMAGE_STATUS_INVALID },  // SW1: executable binary
    {1,               0, BOOT_IMAGE_STATUS_INVALID },  // SW2: executable binary
    {2,               0, BOOT_IMAGE_STATUS_INVALID },  // SW3: executable binary
    {3,               0, BOOT_IMAGE_STATUS_INVALID },  // SW4: executable binary
    {CORE_ID_INVALID, 0, BOOT_IMAGE_STATUS_INVALID },  // sec_elf: nonexecutable binary, fill in with invalid core id
    {CORE_ID_INVALID, 0, BOOT_IMAGE_STATUS_INVALID }   // dbg_policy: nonexecutable binary, fill in with invalid core id
};
 
/*===========================================================================
                               EXTERN
============================================================================*/

/*===========================================================================
                               Helper FUNCTIONS
 *===========================================================================*/


 /*===========================================================================
                               FUNCTIONS
 *===========================================================================*/

void boot_config_update_boot_image_info ( boot_image_id_enum_type id, uint32_t image_entry, uint32_t status)
{
    if ( id < BOOT_IMAGE_ID_MAX )
    {
        g_boot_image_info[id].image_entry = image_entry;
        g_boot_image_info[id].status      = status;
    }
}

uint32_t boot_config_get_image_entry ( boot_image_id_enum_type id, uint32_t cpu_id )
{
    if ( cpu_id == g_boot_image_info[id].core_id &&
         g_boot_image_info[id].image_entry > 0 &&
         g_boot_image_info[id].status == BOOT_IMAGE_STATUS_SUCCESS)
    {
        return g_boot_image_info[id].image_entry;
    }
    else
    {
        return 0x0;
    }
}

uint32_t boot_config_get_loaded_image_id (uint32_t *image_id )
{
    uint32_t id = 0,core_id = get_curr_phys_cpu_num();
    uint32_t ret = E_NOT_ALLOWED;
    for(id = 0;id < BOOT_IMAGE_ID_MAX;id++) {
        if( (g_boot_image_info[id].status == BOOT_IMAGE_STATUS_SUCCESS ) && 
           (g_boot_image_info[id].core_id == core_id)) {
               *image_id = id;
               ret = E_SUCCESS;
               break;
        }
    }
    return ret;
}

uint32_t boot_config_get_core_image_id (uint32_t phys_core_id )
{
    uint32_t id = 0;
    uint32_t ret = BOOT_IMAGE_ID_MAX;
    for(id = 0;id < BOOT_IMAGE_ID_MAX;id++) {
        if(g_boot_image_info[id].core_id == phys_core_id) {
               ret = id;
               break;
        }
    }
    return ret;
}
