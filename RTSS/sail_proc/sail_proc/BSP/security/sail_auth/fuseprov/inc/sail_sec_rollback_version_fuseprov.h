/* ============================================================================
 * @file  sail_sec_rollback_version_fuseprov.h
 * @brief This file contains rollback protection fuse provision functions.
 *
 * Copyright (c) 2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SAIL_SEC_ROLLBACK_VERSION_FUSEPROV_H
#define SAIL_SEC_ROLLBACK_VERSION_FUSEPROV_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */
#include "types.h"

/* ----------------------------------------------------------------------------
 * Defines
 * ----------------------------------------------------------------------------
 */
#define VERSION_ROLLBACK_MAX_IMG_NUM_PER_SET (2U)

/* the max number of discontinued supported fuse regions for one given image */
#define RBV_DISCONT_FUSE_REGION_MAX_NUM   (3U)

/* ----------------------------------------------------------------------------
 * Enum & Structure
 * ----------------------------------------------------------------------------
 */
typedef uint32 secboot_sw_type;

/* Error codes */
typedef enum {
    RBV_E_SUCCESS               =  0x0,
    RBV_E_FAILURE               =  0x1,
    RBV_E_BAD_FUSE_ADDRESS      =  0x2,
    RBV_E_NULL_POINTER, 
    RBV_E_QFPROM_READ_ROW_FAILURE, 
    RBV_E_QFPROM_WRITE_ROW_FAILURE, 
    RBV_E_QFPROM_FUSE_NOT_SUPPORTED, 
    RBV_E_NO_LSB_BASE_ADDR,
    RBV_E_NO_MSB_BASE_ADDR,
    RBV_E_NO_AVAIL_VER_BITS,
    RBV_E_UPDATE_FUSE_VER_FAIL,
    RBV_E_IMAGE_NOT_SUPPORTED,
    RBV_E_IMAGE_SET_TABLE_OVERFLOW,
} rollback_version_fuseprov_err_type;

/*
  Data structure that represent a set of images that share the same anti rollback
  version fuses. 
  Each image set can contain a max of BOOT_VERSION_ROLLBACK_MAX_IMG_NUM_PER_SET images.
  Each image set can have up to two fuses to store the version: one is lsb the other is msb,
  which also means an image set's absolute max version number will be 32+32=64.
  Each image set has one fuse which indicates if rollback protection is enable for current image set or not
  Each image set also has one variable that store the current version(obtain from secboot cert after authentication)
*/
struct rollback_version_img_set
{
  /* List of images in current image set*/
  const secboot_sw_type sec_sw_img_list[VERSION_ROLLBACK_MAX_IMG_NUM_PER_SET];
  
  /* Base address of the fuse that defines anti rollback feature for current image set*/
  const uint32 * const feature_enable_base_addr;

  /* Bit Mask that should be applies to the fuse that defines anti rollback feature for current image set*/
  const uint32 feature_enable_mask;
  
  /* Base address of the fuse that defines the LSB of version number of current image set*/
  const uint32 * const version_lsb_base_addr;
  
  /* Bit Mask that should be applies to the LSB fuse to extract LSB of version number*/
  const uint32 version_lsb_mask;
  
  /* Bit Shift that should be applies to the LSB fuse to extract LSB of version number*/
  const uint32 version_lsb_shift;
  
  /* Base address of the fuse that defines the MSB of version number of current image set*/
  const uint32 * const version_msb_base_addr;  
  
  /* Bit Mask that should be applies to the MSB fuse to extract MSB of version number*/
  const uint32 version_msb_mask;
 
  /* Bit Shift that should be applies to the MSB fuse to extract MSB of version number*/
  const uint32 version_msb_shift;

  /* variable that store the current version(obtain from secboot cert after authentication) */
  uint32 current_set_version_num;
  
};

/* ----------------------------------------------------------------------------
 * Public API's
 * ----------------------------------------------------------------------------
 */
/*===========================================================================

**  Function : rollback_version_update

** ==========================================================================
*/
/*!
* 
* @brief
*    This function update the version rollback fuse for images.
*
* @param[in] sw_id software id of images
*
* @param[in] version the version to update to the fuse
*
* @par Dependencies
*    None
* 
* @retval
*    rollback_version_fuseprov_err_type Returns error code in case of error
*                                       Returns RBV_E_SUCCESS in case of no error                                     
* 
* 
*/
rollback_version_fuseprov_err_type rollback_version_update
(
  uint32 sw_id,
  uint32 version
);

#endif /* SAIL_SEC_ROLLBACK_VERSION_FUSEPROV_H */
