/*===========================================================================
 Copyright (c) 2023 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/
#ifndef SAIL_SEC_APIS_H
#define SAIL_SEC_APIS_H

#include "sail_sec_img_auth.h"
#include "sail_sec_target.h"
#include "uclib_hash.h"

/**
 * @brief This is image context structure to get memory from caller, i.e. XBL.
 *        This memory will be released at the end of authetication of image.
 */
typedef struct sail_sec_img_ctx_s
{
  sec_img_auth_priv_t img_handle;                         /**< Image Handle */
  sec_img_auth_elf_info_type elf_info;                    /**< ELF Info */
  sec_img_auth_verified_info_s v_info;                    /**< Verified Info */
  sail_sec_img_metadata_info_t img_metadata_info;         /**< Image Metadata Info */
  sec_img_auth_whitelist_area_t segment_list[SAIL_SEC_IMG_WHITELIST_LEN];  /**< Segment List */
  sec_img_auth_whitelist_area_param_t segment_list_area;  /**< Segment List as above & Count */
  uint8_t crypto_ctx[sizeof(UCLIB_MD_HANDLE)];            /**< Crypto Context */
  crypto_ftbl_type crypto_ftbl;                           /**< Crypto Function Pointer Table */
  uie_ctx uie_img_ctx;                                    /**< UIE Context */
}sail_sec_img_ctx_t;

/**
 * @brief Initialize secure boot which includes: 
 *        (1) Copy PBL passed data to secboot data structures
 *        (2) Load, Authenticate and Apply Debug Policy if avaiable
 *        (3) Load, Authenticate and Blow secboot fuses (SEC.ELF)
 *
 * @param[in]  pbl_info     context passed by PBL
 *
 * @return - TRUE on success, FALSE on failure.
 */
bool sail_sec_init(void *pbl_info);

/**
 * @brief Image Metadata verifications.
 *
 * @param[in]  sec_img_id          Image ID
 * @param[in]  elf_hdr             Pointer to the elf header
 * @param[in]  prog_hdr            Pointer to the start of the program header
 * @param[in]  hash_seg_hdr        Pointer to the hash segment header
 * @param[in]  whitelist_count     white list region count
 * @param[in]  whitelist_area      white list regions
 * @param[in]  whitelist_area_size White list size
 *
 * @return SEC_IMG_AUTH_SUCCESS on success, 
 *         error codes from sec_img_auth_error_type enum on failure.
 */
sec_img_auth_error_type sail_sec_img_auth_verify_metadata
(
  uint32_t sec_img_id,
  void *elf_hdr,
  void *prog_hdr,
  uint8* hash_seg_hdr,
  uint32_t whitelist_count,
  sec_img_auth_whitelist_area_t * whitelist_area,
  size_t whitelist_area_size
);

/**
 * @brief Segment hash integrity check.
 *
 * @param[in]  sec_img_id          Image ID
 *
 * @return SEC_IMG_AUTH_SUCCESS on success, 
 *         error codes from sec_img_auth_error_type enum on failure.
 */
sec_img_auth_error_type sail_sec_img_auth_hash_elf_segments
(
  uint32_t sec_img_id
);

/**
 * @brief Validate elf header.
 *
 * @param[in]  format          elf format
 * @param[out] elf_hdr         Verified info 
 * @param[in]  elf_hdr_size    verified info size 
 *
 * @return SEC_IMG_AUTH_SUCCESS on success, 
 *         error codes from sec_img_auth_error_type enum on failure.
 */
sec_img_auth_error_type sail_sec_img_auth_validate_elf
(
  Elf_Class format,
  const void* elf_hdr,
  size_t elf_hdr_size
);

/**
 * @brief Validates on-demand (partial) elf segments against hash table.
 *
 * @param[in] sec_img_id    Image ID
 * @param[in] hash_seg_hdr  Pointer to the hash segment header followed by the
 *                          hashes of segments in sequential order
 * @param[in] seg_buff      Segment Data Buffer
 * @param[in] seg_num       Segment Number (from Program Header)
 * @param[in] seg_size      Segment File Size (Bytes)
 *
 * @return SEC_IMG_AUTH_SUCCESS on success, 
 *         error codes from sec_img_auth_error_type enum on failure.
 */
uint32_t sail_sec_img_auth_hash_partial_segment
(
  uint32_t sec_img_id,
  uint8_t *hash_seg_hdr,
  uint8_t *seg_buff,
  uint32_t seg_num,
  uint32_t seg_size
);

/**
 * @brief This function checks if the code needs to be authenticated. If
 *        authentication is enabled, callers MUST authenticate the
 *        code successfully before it is allowed to execute.
 *
 * @param code_segment   [in]  Segment of SECURE_BOOTn register holding
 *                             authentication information for the code
 *
 * @return FALSE if authentication is not required
 *         TRUE if authentication is required
 *
 */
bool sail_sec_secboot_hw_is_auth_enabled
(
  uint32_t code_segment
);

#endif /* SAIL_SEC_APIS_H */
