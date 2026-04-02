/*===========================================================================
 Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

#ifndef SAIL_SEC_SEC_IMG_AUTH_H
#define SAIL_SEC_SEC_IMG_AUTH_H

/**
@file sec_img_auth.h
@brief Secure Image Authentication 
*/
#include "sail_sec_errno.h"
#include "sec_multi_img.h"
#include "sec_img_auth.h"

#define CRYPTO_DIGEST_BYTE_SIZE_SHA256  (32)  /**< Byte length of SHA256 hash digest. */
#define CRYPTO_DIGEST_BYTE_SIZE_SHA384  (48)  /**< Byte length of SHA384 hash digest. */


/**
 * The hash commands for parllel hashing.
 */
typedef enum
{
  SEC_IMG_AUTH_PARALLEL_HASH_INIT = 1,
  SEC_IMG_AUTH_PARALLEL_HASH_UPDATE,
  SEC_IMG_AUTH_PARALLEL_HASH_FINALIZE,
  SEC_IMG_AUTH_PARALLEL_HASH_DEINIT
}sec_img_auth_parallel_hash_cmd_et;

typedef struct {
  Elf_Class elf_type;
  size_t elf_hdr_len;
  size_t prog_hdr_len;
  size_t hash_seg_len;
} sail_sec_img_metadata_info_t;

typedef struct
{
  uint32_t sw_id;
  bool is_valid;
}sail_sec_img_list_t;

typedef struct
{
  uint32_t sw_id;
  uint32_t arb_fuse_addr;
  uint32_t mask;
}sail_sec_arb_list_t;

extern sail_sec_img_list_t sail_double_signed_img_list[];
extern const size_t double_signed_img_list_size;

extern const sail_sec_arb_list_t arb_fuse_img_list[];
extern const size_t arb_fuse_img_list_size;

/**
 * @brief This function calls to secboot to check if the code needs to be authenticated.
 *
 * @param code_seg            [in]  Segment of SECURE_BOOTn register holding
 *                             authentication information for the code
 * @param is_auth_enabled     [in,out] uint32 value is
 *                                assigned by the caller
 *
 * @return \c FALSE if authentication is not required
 *         \c TRUE if authentication IS required
 *
 */
sec_img_auth_error_type sec_img_auth_is_auth_enabled
(
  uint32_t code_seg,
  uint32_t * is_auth_enabled
);

sec_img_auth_error_type sec_img_auth_is_auth_enabled_target
(
  uint32_t code_segment,
  uint32_t * is_auth_enabled,
  secboot_cm_ftbl_type *cm_ftbl
);

void sec_img_auth_set_crypto_ctx
(
  sec_img_auth_priv_t *h,
  uint8_t *buf,
  size_t size
);

crypto_ftbl_type * sec_img_auth_get_crypto_ftbl
(
  sec_img_auth_priv_t *h
);

void sec_img_auth_set_img_id
(
  sec_img_auth_priv_t *h,
  uint32_t img_id
);

void sec_img_auth_set_img_data
(
  sec_img_auth_priv_t *h,
  sec_img_auth_elf_info_type *img_data
);

void sec_img_auth_set_img_ver
(
  sec_img_auth_priv_t *h,
  uint32_t ver
);

void sec_img_auth_set_whitelist
(
  sec_img_auth_priv_t *h,
  sec_img_auth_whitelist_area_param_t *l
);

secboot_error_type sec_img_auth_verify_sig
(
  sec_img_auth_priv_t *h,
  secboot_image_info_type *img_info,
  uint32_t code_segment,
  sec_img_auth_verified_info_s * v_info
);

/* Given an 'image-info' structure with the certificate chain and signature
 * pointers filled in, pass that on to the secboot authentication routine
 * This supports authentication of OEM signed image
 */
secboot_error_type secboot_validate_signature
(
  crypto_ftbl_type * crypto_ftbl_ptr,
  secboot_cm_ftbl_type * secboot_cm_ftbl_ptr,
  secboot_image_info_type * image_info_ptr,
  uint32_t code_segment,
  sec_img_auth_verified_info_s * v_info_ptr
);

sec_img_auth_error_type sec_img_auth_misc
(
  sec_img_auth_priv_t *s_img_handle,
  sec_img_auth_verified_info_s * v_info,
  sec_multi_img_table_id id,
  sail_sec_img_metadata_info_t * img_metadata_info
);

int sail_sec_validate_metadata
(
  sec_img_auth_elf_info_type * sec_img_data,
  sail_sec_img_metadata_info_t * img_metadata_info,
  bool sail_loader
);


/**
* This function is used to read the oem_metadata (root_cert_num) and get the corresponding 
* fuse value for segment hashing algorithm and length to be used 
*
* @param[in] img_handle Pointer to the image verification context
*
* @return returns length of segment hash to be used
*/
int sec_img_auth_get_segment_hash_len
(
  sec_img_auth_priv_t *img_handle
);

/* Given an 'image-info' structure with the certificate chain and signature
 * pointers filled in, verified info image hash info pointer is updated with
 * code address/code length (it is needed only for VIP image)
 */
secboot_error_type sec_img_auth_update_address( 
  secboot_image_info_type * image_info_ptr,
  secboot_image_hash_info_type* image_hash_info_ptr
);


int read_metadata
(
 const void * base,
 size_t size,
 bool sail_loader
);

size_t read_hash_seg_sz(const void *ptbl, size_t num_segs, Elf_Class e);

/**
 * This function returns the length of mbn header */
size_t sail_sec_img_signing_hdr_len(void* mbn_header_ptr, size_t hash_seg_len);

/**
 * This function is to relocate hash table to secure region */
sec_img_auth_error_type sail_sec_copy_hash_table(
  uint32_t sec_img_id, 
  sail_sec_img_metadata_info_t * img_metadata_info, 
  sec_img_auth_priv_t * img_handle, 
  sec_img_auth_elf_info_type *img_data
);

/**
 * This function returns the length of segment hash depending on hash algo 
 * @param[in] algo Hash algorithm SHA256/384 as input
 *
 * @return segment hash length or -1 on error.
 */
int sec_img_get_hash_length(sec_img_hash_algo_type algo);

/**
 *@brief This function is to check if the image is double signed image
 *@return TRUE if it is qsee signed image, FALSE otherwise
 */
bool is_double_signed_img(uint32_t img_id);

/**
 *@brief This function is to check if the image is qc only signed image
 *@return TRUE if it is qsee signed image, FALSE otherwise
 */
bool is_qc_only_signed_img(uint32_t img_id);

/**
 *@brief This function is to check if the image is 
 * qc signed image (either qc signed or both qc and oem signed)
 *@return TRUE if it is qsee signed image, FALSE otherwise
 */
bool is_qc_signed_img(uint32_t img_id);

/**
 * @brief This function is to get the root used to authenticate misc image
 *
 * @return root used oftype sec_multi_img_root_used_t
 *
 */

sec_multi_img_root_used_t sail_sec_get_sec_multi_img_root_used(void);

/**
 * @brief This function is to set the root used to authenticate misc image
 *
 * @param root_used_for_misc   [in] root used for misc of type sec_multi_img_root_used_t
 *
 */
void sail_sec_set_sec_multi_img_root_used(sec_multi_img_root_used_t root_used_for_misc);

/**
 * Authenticates hash table segment against its signature.
 *
 * @param[in,out] s_img_handle Pointer to the image verification context
 * @param[in,out] img_metadata_info Pointer 
 * @param[in,out] v_info Pointer to the verified info
 *
 * @return SEC_IMG_AUTH_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 */
sec_img_auth_error_type sec_img_auth_verify_metadata_common (
  sec_img_auth_priv_t *s_img_handle,
  sail_sec_img_metadata_info_t * img_metadata_info,
  sec_img_auth_verified_info_s *v_info
);

/*
 * This function is used to set the auth info intialized parameter
 * for oem signature API 
 * @param[in,out] initialized set values for auth_info initialized for oem sig
 *
 * @return E_SUCESS/E_FAILURE
 */
int sec_img_auth_set_auth_info_initialized(uint32_t *initialized);

/*
 * This function is used to set the hash algo and digest sz
 * for partial segment hashing
 * @param[in,out] hash_algo Algorithm to be used for segment hashing
 * @param[in,out] digest_sz size of digest
 *
 * @return E_SUCESS/E_FAILURE
 */
int sec_img_set_partial_hashing_algo_dgst_sz(uint32_t *hash_algo, int *digest_sz);

/*
 *@brief This API is to update double signed image list. Currently supported for HYP image
 *Can be extened later by adding new list in target specific config if more images need to be supported
 */
void sail_sec_update_dbl_signed_img_list(void);

void* secure_memset(void* ptr, int32 value, size_t len);

/**
 * @brief 
 *     Check whether debug policy is double signed.
 *
 * @retval    TRUE if the flag is set, FALSE otherwise
 *
 */
bool sail_sec_is_debug_policy_double_signed(void);

/**
 * @brief 
 *     Check whether debug policy QC signature is tied with serial number.
 *
 * @retval    TRUE if tied to serial number, FALSE otherwise
 *
 */
bool sail_sec_is_dp_qc_signature_tied_with_serial_num(void);

/**
 * @brief 
 *     Check whether debug policy oem signature is tied with serial number.
 *
 * @retval    TRUE if tied to serial number, FALSE otherwise
 *
 */
bool sail_sec_is_dp_oem_signature_tied_with_serial_num(void);

#endif
