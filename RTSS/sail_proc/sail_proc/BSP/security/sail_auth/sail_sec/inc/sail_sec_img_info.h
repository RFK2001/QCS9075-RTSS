/* ============================================================================
 * @file  sail_sec_img_info.h
 * @brief Keeping image information which can shared on need basis.
 *
 * Copyright (c) 2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SAIL_SEC_IMG_INFO_H
#define SAIL_SEC_IMG_INFO_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */
#include "util.h"

/* ----------------------------------------------------------------------------
 * Enum & Structure
 * ----------------------------------------------------------------------------
 */
typedef enum
{
  SEC_IMAGE_SW1,             /* sailsw1 */
  SEC_IMAGE_SW2,             /* sailsw2 */
  SEC_IMAGE_SW3,             /* sailsw3 */
  SEC_IMAGE_SW4,             /* sailsw4 */
  SEC_IMAGE_SEC_ELF,         /* sec elf */
  SEC_IMAGE_DBG_POLICY,      /* DBG policy */
  SEC_IMAGE_HYP,             /* SAIL HYP */
  SEC_IMAGE_MAX              /* max number */
}sail_sec_img_et;

/**
 * @brief Image information strcutures for images authenticated by SAIL HYP
 *
 */
typedef struct sail_sec_img_info_s
{
  uint32_t sec_img_id;                  /* Image ID */
  uint32_t sec_img_ctx;                 /* Image Context */
  uint32_t sec_img_arb;                 /* Image ARB (Anti-Rollback Version) */
  boolean sec_img_verified;             /* Image Verification Status */
}sail_sec_img_info_t;

/* ----------------------------------------------------------------------------
 * Public API's
 * ----------------------------------------------------------------------------
 */
/**
 * @brief Get sw id of image for given image index
 *
 * @param[in] sec_img_idx Image index (for ex: SW1 image idx is SEC_IMAGE_SW1)
 * @return    Image id if image info exist else zero
 */
uint32_t sail_sec_img_info_get_sw_id(uint32_t sec_img_idx);

/**
 * @brief Save image context
 *
 * @param[in] sec_img_id Image ID (for ex: SW1 image id is SECBOOT_SAIL_SW1_SW_TYPE i.e. 0x55)
 * @param[in] sec_img_ctx Image Context
 * @return    None
 */
void sail_sec_img_info_save_img_ctx(uint32_t sec_img_id, uint32_t sec_img_ctx);

/**
 * @brief Get image context
 *
 * @param[in] sec_img_id Image ID (for ex: SW1 image id is SECBOOT_SAIL_SW1_SW_TYPE i.e. 0x55)
 * @return    image context if valid image id else 0
 */
uint32_t sail_sec_img_info_get_img_ctx(uint32_t sec_img_id);

/**
 * @brief Delete image context
 *
 * @param[in] sec_img_id Image ID (for ex: SW1 image id is SECBOOT_SAIL_SW1_SW_TYPE i.e. 0x55)
 * @return    None
 */
void sail_sec_img_info_delete_img_ctx(uint32_t sec_img_id);

/**
 * @brief Save ARB (Anti-Rollback) of image
 *
 * @param[in] sec_img_id Image ID (for ex: SW1 image id is SECBOOT_SAIL_SW1_SW_TYPE i.e. 0x55)
 * @param[in] sec_img_arb ARB of image
 * @return    None
 */
void sail_sec_img_info_save_arb(uint32_t sec_img_id, uint32_t sec_img_arb);

/**
 * @brief Get ARB (Anti-Rollback) of image by image id
 *
 * @param[in] sec_img_id Image ID (for ex: SW1 image id is SECBOOT_SAIL_SW1_SW_TYPE i.e. 0x55)
 * @return    ARB of image if image info exist else zero
 */
uint32_t sail_sec_img_info_get_arb(uint32_t sec_img_id);

/**
 * @brief Set verification status of image by image id
 *
 * @param[in] sec_img_id Image ID (for ex: SW1 image id is SECBOOT_SAIL_SW1_SW_TYPE i.e. 0x55)
 * @param[in] v_status verified status of image
 * @return    None
 */
void sail_sec_img_info_set_verified_status(uint32_t sec_img_id, boolean v_status);

/**
 * @brief Get verification status of image by image id
 *
 * @param[in] sec_img_id Image ID (for ex: SW1 image id is SECBOOT_SAIL_SW1_SW_TYPE i.e. 0x55)
 * @return    Image verification status (TRUE if verified, FALSE otherwise)
 */
boolean sail_sec_img_info_get_verified_status(uint32_t sec_img_id);

#endif /* SAIL_SEC_IMG_INFO_H */
