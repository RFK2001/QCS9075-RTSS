/**
 * @file el2_asm.h
 * @brief EL2 Hypervisor definitions
 * Header file for the definition of hypervisor register info used in sail
 *
 *        Copyright (c) 2021 - 2023 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
06.02.21   rrahul       Created
=============================================================================*/

#ifndef TARGET_H
#define TARGET_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include "types.h"
#include "sail_mem_map.h"

/*===========================================================================
                            MACROS
===========================================================================*/
#define SAILBSP_CPU_COUNT           0x4
#define SAILBSP_CLUSTER_COUNT       0x2
#define SAILBSP_CPUS_PER_CLUSTER    0x2
#define SAILBSP_CLUSTER_SIZE_SHFT   0x1
#define SAILBSP_CLUSTER_FIELD_MASK  0x1
#define SAILBSP_CPU_SIZE_SHFT       0x1
#define SAILBSP_CPU_FIELD_MASK      0x1

//#define SAILBSP_NUM_DDR_REGIONS     4

#define SAILBSP_MPIDR_CLUSTER_MASK  0xFF00
#define SAILBSP_MPIDR_CLUSTER_SHFT  8
#define SAILBSP_MPIDR_CPU_MASK      0xFF
#define SAILBSP_MPIDR_CPU_SHFT      0


/* How many bits to Consider for masking in order to get the core# from MPIDR
 * register value Check MPIDR registers for 2 aux cores to determine this
 * Usually affinity0 or affinity 1 */
#define MPIDR_TO_CPU_NUM_BITS  16

/* How many bits to shift in order to get the core# from MPIDR register value
 * Check MPIDR registers for 2 aux cores to determine this */
#define MPIDR_TO_CPU_NUM_SHIFT  8

/* How many bits to shift to get the cluster number from MPIDR register */
#define MPIDR_TO_CLUSTER_NUM_SHIFT  8

#define WITH_SMP 1

/*For BOOT Image Loading*/
#define CORE_ID_INVALID                     0xFF
#define BOOT_IMAGE_STATUS_INVALID           0
#define BOOT_IMAGE_STATUS_SUCCESS           1
#define BOOT_IMAGE_STATUS_ERROR             2

/*===========================================================================
                           TYPEDEFS
===========================================================================*/
/* Thie is the ENUM that is used as identifiers for IMAGES running on SAIL SS */
typedef enum _boot_image_id_enum{
    BOOT_IMAGE_ID_SW1,
    BOOT_IMAGE_ID_SW2,
    BOOT_IMAGE_ID_SW3,
    BOOT_IMAGE_ID_SW4,
    BOOT_IMAGE_ID_SEC_ELF,
    BOOT_IMAGE_ID_DBG_POLICY,
    BOOT_IMAGE_ID_MAX
} boot_image_id_enum_type;


/*This type will hold information about the image, start address ...*/
typedef struct _boot_image_info{
    uint32_t                core_id;        // core to boot on
    uint32_t                image_entry;    // binary entry point
    uint32_t                status;         // primary partition or secondary partition
} boot_image_info_type;
/*===========================================================================
                            EXTERN
===========================================================================*/

#endif
