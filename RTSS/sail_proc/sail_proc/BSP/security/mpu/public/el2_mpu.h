/*
 * el2_mpu.h
 *
 * Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Qualcomm Technologies Inc. Proprietary and Confidential.
 * 
 *  Created on: Oct 25, 2021
 *      Author: shaygold
 
                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

   when        who         what, where, why
   --------    -----       -----------------------------------------------------
   25/10/21    shaygold    Initial version
   27/06/23    shaygold    Add API for validation
 */

#ifndef EL2_MPU_H_
#define EL2_MPU_H_

#include <stdint.h>
#include <types.h>

#include "target.h"

#define MPU_SUCCESS 0
#define MPU_CONFIGURATION_ERROR -1
#define MPU_MISMATCH_STATE -2
#define MPU_IMAGE_ID_ERROR -3

/**
 * @brief Initializes el2 MPU according to configuration hardcoded in el2_mpu_configuration.c
 * @return Returns 0 on success , otherwise returns -1.
 * 
 * Note, this function should be called in each core.
 */
int32_t el2_mpu_init(void);

/**
 * @brief Update el2 MPU according to current image configuration.     
 * @return Returns 0 on success , otherwise reverts EL2 MPU status to uninitialied state and return -1.
 * 
 * Note, this function should be called only after successful init.
 * Note, this function should be called for each core.
 */
int32_t el2_mpu_update(void);

/**
 * @brief Mark EL2 MPU as not initialized to allow re-initialization after sleep or core reset.     
 * 
 * Note, this function should be called for each core.
 */
void el2_mpu_mark_deinit(void);

/**
 * @brief Enable MD DDR EL2 MPU region.
 * 
 * Note, this function should be called for each core.
 */
void el2_mpu_enable_ddr_region(void);

typedef enum {
    EL1_READ = 0,
    EL1_READ_WRITE = 1,
} el2_mpu_permissions;

/**
 * @brief Check if specified region is blocked for el1 operations
 *
 * @param address [in]  Memory rage start address
 * @param len     [in]  Memory range len
 * @param perms     [in]  Pointer to RSP descriptor
 *
 * @return True  - If the requested range is included in EL2 MPU region and has the requested permissions for EL1
 *         False - Otherwise
 * 
 * Note, this function will return false in case the requested range intersects more than one EL2 MPU region.
 */
bool el2_mpu_is_el1_accessible(void* address, size_t len, el2_mpu_permissions perms);

typedef enum {
    MPU_ERROR = -1,
    MPU_NOT_INITIALIZED = 0,
    MPU_INITIALIZED = 1,
    MPU_UPDATED = 2,
    MPU_DE_INIT = 3,
} el2_mpu_status;

/**
 * @brief Provide hash of currently implemented EL2 MPU configuration
 *
 * @param hash [out]  calculated hash
 *
 * @return current MPU status
 * 
 */
el2_mpu_status el2_mpu_get_hash(uint8_t* hash);

typedef enum : u32 {
    READ_WRITE_EL2 = 0,
    READ_WRITE_ANY = 1,
    READ_ONLY_EL2 = 2,
    READ_ONLY = 3,
} el2_mpu_ap;

typedef enum : u32 {
    NON_SHAREABLE = 0,
    // UNPREDICTABLE = 1, // NOT TO BE USED
    OUTER_SHAREABLE = 2,
    INNER_SHAREABLE = 3,
} el2_mpu_sh;

typedef enum : u32 {
    REGION_DISABLE = 0,
    REGION_ENABLE  = 1,
} el2_mpu_region_enable;

typedef struct {
    u32 base;                // Lower inclusive limit of the memory region.
    enable_disable nx;       // Execute never bit.
    el2_mpu_ap ap;           // Access permission bits.
    el2_mpu_sh sh;           // Shareability field.
    u32 last;                // Upper inclusive limit of the memory region.
    u32 att;                 // Index oto attribute in HMAIRx registers. 
    u32 enable;              // Region enable bit.
} region_configuration;

typedef struct {
    u32 num_of_regions;        // Number of regions to configure.
    region_configuration* rc;  // Pointer to region configuration array.
    enable_disable br[SAILBSP_CPU_COUNT];   // Background region flag for each core.
    enable_disable wnx[SAILBSP_CPU_COUNT];  // Write Never eXecute flag for each core.
} el2_mpu_configuration;

#define BM(base, count, val) (((val) & ((0x1 << (count)) - 1)) << (base))

#define MPU_HMAIR_ATTR(index, attr)              BM((index) * 8, 8, (attr))

/* Device-nGnRnE memory */
#define MPU_HMAIR_ATTR0                  MPU_HMAIR_ATTR(0, 0x00)
#define HMAIR_ATT_IDX_DEVICE_nGnRnE 0

/* Device-nGnRE memory */
#define MPU_HMAIR_ATTR1                  MPU_HMAIR_ATTR(1, 0x04)
#define HMAIR_ATT_IDX_DEVICE_nGnRE 1

/* Device-GRE Memory, Inner write-back non transient */
#define MPU_HMAIR_ATTR2                  MPU_HMAIR_ATTR(2, 0xcc)
#define HMAIR_ATT_IDX_DEVICE_GRE 2

/* Normal Memory, Outer Write-back non-transient Read/Write allocate,
* Inner Write-back non-transient Read/Write allocate
*/
#define MPU_HMAIR_ATTR3                  MPU_HMAIR_ATTR(3, 0xff)
#define HMAIR_ATT_IDX_NORMAL 3

/* Normal Memory, Inner Non-cacheable */
#define MPU_HMAIR_ATTR4                  MPU_HMAIR_ATTR(0, 0x44)
#define HMAIR_ATT_IDX_NORMAL_NON_CACHE 4

/* Add more Memory Types as per the requirement and assign them to one remaining
 * indexes below.
*/
#define MPU_HMAIR_ATTR5                  (0)
#define MPU_HMAIR_ATTR6                  (0)
#define MPU_HMAIR_ATTR7                  (0)

#endif /* EL2_MPU_H_ */
