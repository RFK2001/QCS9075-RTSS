#ifndef SEC_MULTI_IMG_H
#define SEC_MULTI_IMG_H

/*===========================================================================

                      QUALCOMM Multi Image Secboot API

DESCRIPTION
    This header file contains declarations to multi image structures and headers

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None
  
Copyright (c) 2017 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
============================================================================*/

/*===========================================================================
 
                           INCLUDE FILES

===========================================================================*/
#include "sec_img_auth.h"

#define SEC_MULTI_IMG_RESERVED_WORD_SIZE (64)
#define SEC_MULTI_IMG_NUM_ENTRIES        (100)
#define SEC_MULTI_IMG_HASH_SIZE           SECBOOT_OTP_ROOT_OF_TRUST_BYTE_SIZE
#define SEC_MULTI_IMG_SEGMENT_HASH_SIZE_384   SECBOOT_OTP_ROOT_OF_TRUST_BYTE_SIZE
#define SEC_MULTI_IMG_SEGMENT_HASH_SIZE_256   32

typedef enum sec_multi_img_table_id
{
  SEC_OEM_MULTI_IMAGE = 0,
  SEC_QTI_MULTI_IMAGE
} sec_multi_img_table_id;

typedef enum
{
  INVALID = 0,
  QTI_PROD_ROOT,
  QTI_TEST_ROOT,
  OEM_TEST_ROOT,
  OEM_ROOT_FROM_FUSE,
  ROOT_FROM_DP
}sec_multi_img_root_used_t;

typedef PACKED_STRUCT sec_multi_img_entry
{
  uint32_t software_id;
  uint32_t secondary_id;
  uint8_t hash[SEC_MULTI_IMG_SEGMENT_HASH_SIZE_384];
} sec_multi_img_entry;

typedef PACKED_STRUCT sec_multi_img_sha256_entry
{
  uint32_t software_id;
  uint32_t secondary_id;
  uint8_t hash[SEC_MULTI_IMG_SEGMENT_HASH_SIZE_256];
} sec_multi_img_sha256_entry;

/*Definition of secure boot metadata */
typedef PACKED_STRUCT sec_multi_img_type
{
  uint32_t magic;
  uint32_t version;
  uint32_t reserved[SEC_MULTI_IMG_RESERVED_WORD_SIZE];
  uint32_t total_num;
  uint32_t sha_algo;
  sec_multi_img_entry entry[];
}sec_multi_img_type;

typedef struct sec_multi_img_hash_segment_info
{
  uint32_t hash_algo;
  uint8_t hash[SEC_MULTI_IMG_HASH_SIZE];
}sec_multi_img_hash_segment_info;

/*Structure to copy misc data to xbl_sec*/
typedef struct sec_multi_img_xbl_sec_info
{
  sec_multi_img_root_used_t root_used_for_misc;
  uint32_t total_num;
  uint32_t sha_algo;
  sec_multi_img_entry entry[];
}sec_multi_img_xbl_sec_info;

/*Structure to share misc information to TZ*/
typedef struct sec_multi_img_xbl_sec_shared_info
{
  sec_multi_img_xbl_sec_info *oem_entry;
  sec_multi_img_xbl_sec_info *qti_entry;
}sec_multi_img_xbl_sec_shared_info;

typedef enum sec_multi_img_error_type
{
  SEC_MULTI_IMG_SUCCESS = 0,
  SEC_MULTI_IMG_FAILURE,
  SEC_MULTI_IMG_INVALID_MAGIC,
  SEC_MULTI_IMG_INVALID_VERSION,
  SEC_MULTI_IMG_INVALID_PARAM
}sec_multi_img_error_type;

/**
* @brief Initialize the Metadata Structures
*
*
* @return 0 on success, negative on failure.
*/
sec_multi_img_error_type sec_multi_img_init
(
  sec_multi_img_table_id id,
  uintptr_t *multi_img_addr,
  size_t seg_size
);

/**
* @brief Retrieve the hash and hash algorithm of a given image from OEM or QTI Misc given the SW ID and Secondary SW ID
*
*
* @return 0 on success, negative on failure.
*/
sec_multi_img_error_type sec_multi_img_retrieve_hash_info
(
  sec_multi_img_table_id id,
  uint32_t sw_id,
  uint32_t secondary_sw_id,
  sec_multi_img_hash_segment_info *image_hash_info
);

sec_multi_img_xbl_sec_shared_info *get_multi_img_xbl_sec_shared_info(void);
#endif
