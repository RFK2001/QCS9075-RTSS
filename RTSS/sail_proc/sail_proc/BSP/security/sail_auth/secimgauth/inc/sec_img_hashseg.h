#ifndef SEC_IMG_HASHSEG_H
#define SEC_IMG_HASHSEG_H

/**
* @file sec_img_hashseg.h
* @brief define hash segment related public data and APIs
*/

/*===========================================================================
   Copyright (c) 2017 by QUALCOMM Technologies, Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE


when       who      what, where, why
--------   ---      ------------------------------------
09/20/17   hw       Initial version.

===========================================================================*/
/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include "sec_img_auth.h"
#include "secboot.h"

struct sec_img_hashseg_info_s;
typedef struct sec_img_hashseg_info_s sec_img_hashseg_info_t;
struct sec_img_auth_handle_priv_s;
struct sec_img_info_type;

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
#define SEC_IMG_HASH_SEG_CONTEXT_SIZE     (0x190)
#define SEC_IMG_MULTIP_VERS_CONTEXT_SIZE  (0x8)

#define SEC_IMG_MBNv7_HASH_SEGMENT_HDR_VERSION  (7) //mbn v7
#define SEC_IMG_MBNv6_HASH_SEGMENT_HDR_VERSION  (6) //mbn v6

/*----------------------------------------------------------------------------
 * hash segment related data type declarations
 * -------------------------------------------------------------------------*/
typedef enum
{
    SEC_IMG_HS_HDR_VERSION,
    SEC_IMG_HS_HDR_ADDR,
    SEC_IMG_HS_HDR_SIZE,
    SEC_IMG_HS_PAYLOAD_ADDR,
    SEC_IMG_HS_PAYLOAD_SIZE,
    SEC_IMG_HS_COMMON_METADATA_ADDR,
    SEC_IMG_HS_COMMON_METADATA_SIZE,
    SEC_IMG_HS_OEM_METADATA_ADDR,
    SEC_IMG_HS_OEM_METADATA_SIZE,
    SEC_IMG_HS_QTI_METADATA_ADDR,
    SEC_IMG_HS_QTI_METADATA_SIZE,
    SEC_IMG_HS_HASH_TABLE_ADDR,
    SEC_IMG_HS_HASH_TABLE_SIZE,
    SEC_IMG_HS_HASH_TABLE_ENTRY_SIZE,
    SEC_IMG_HS_HASH_TABLE_HASH_ALGO,
    SEC_IMG_HS_OEM_SIG_ADDR,
    SEC_IMG_HS_OEM_SIG_SIZE,
    SEC_IMG_HS_OEM_CERTS_ADDR,
    SEC_IMG_HS_OEM_CERTS_SIZE,
    SEC_IMG_HS_QTI_SIG_ADDR,
    SEC_IMG_HS_QTI_SIG_SIZE,
    SEC_IMG_HS_QTI_CERTS_ADDR,
    SEC_IMG_HS_QTI_CERTS_SIZE,
    SEC_IMG_HS_UIE_PARM_ADDR,
    SEC_IMG_HS_UIE_PARM_SIZE,
    SEC_IMG_HS_DATA_TYPE_MAX
} sec_img_hashseg_data_e;

/* purpose of caching hash segment data */
typedef enum {
    SEC_IMG_HS_OEM_SIGNING_INFO,
    SEC_IMG_HS_QTI_SIGNING_INFO,
    SEC_IMG_HS_CACHE_TYPE_MAX
} sec_img_hashseg_cache_type_e;

/**
* The context struct for sec image hash segment
*/
struct sec_img_hashseg_info_s
{
    // public configuration
    // caller's config (required for validating hash segment)
    struct _hs_cfg {
        // REQUIRED by init - parsing hash segment
        uint64 hs_num_table_entry;  // number of hash table entry
    } cfg;

    // --- private data to support internal context --- 
    uint8 _priv[SEC_IMG_HASH_SEG_CONTEXT_SIZE];
    // --- private data to support api usage --- 
    uint8 _priv_api[SEC_IMG_MULTIP_VERS_CONTEXT_SIZE];
};

 /*----------------------------------------------------------------------------
 * Function Declarations for hashseg Module 
 * -------------------------------------------------------------------------*/
 /**
 * @brief parse hash segment and initialize hashseg info data structure
 *
 * @param[in] s_img_hseg_handle - Pointer to context handle. hash segment config
 *                                is required from context handle
 * @param[in] data_type - data type
 *
 * @return 0 on success,  else failure.
 */
sec_img_auth_error_type
sec_img_hashseg_init
(
    sec_img_hashseg_info_t  *s_img_hseg_handle,
    const uint8             *hash_seg_addr,
    uint64                  hash_seg_sz
);

 /**
 * @brief initialize hashseg info data structure from existing secimgauth handle.
 *        hash segment data are already parsed by sec_img_auth_verify_metadata() call.
 *        This function only extracts exsiting data to hashseg info handle and the
 *        same sec_img_hashseg apis apply.
 *
 * @param[in] s_img_hseg_handle - Pointer to context handle with hash segment config
 * @param[in] s_img_handle - secimgauth handler
 *
 * @return 0 on success,  else failure.
 */
sec_img_auth_error_type
sec_img_hashseg_init_p
(
    sec_img_hashseg_info_t  *s_img_hseg_handle,
    sec_img_auth_priv_t     *s_img_handle
);

/**
* @brief de-initialize hashseg info data structure
* @return 0 on success,  else failure.
*/
sec_img_auth_error_type
sec_img_hashseg_deinit
(
    sec_img_hashseg_info_t  *s_img_hseg_handle
);

/**
* @brief get hash segment data
*
* @param[in] s_img_hseg_handle - Pointer to context handle
* @param[in] data_type - data type
* @param[out] data - pointer to data buffer
* @return address value.
*/
sec_img_auth_error_type
sec_img_hashseg_get_data
(
    sec_img_hashseg_info_t  *s_img_hseg_handle,
    sec_img_hashseg_data_e  data_type, /* data type */
    uint64 *data // buf to retrieve data
);

/**
* @brief return base address to hash segment data
*
* @param[in] s_img_hseg_handle - Pointer to context handle
* @param[in] data_type - data type
* @return address value.
*/
uint8*
sec_img_hashseg_get_addr
(
    sec_img_hashseg_info_t  *s_img_hseg_handle,
    sec_img_hashseg_data_e  addr_data_type
);

/**
* @brief return non-address data of hash segment
*
* @param[in] s_img_hseg_handle - Pointer to context handle
* @param[in] data_type - data type
* @return size value.
*/
uint32
sec_img_hashseg_get_size
(
    sec_img_hashseg_info_t  *s_img_hseg_handle,
    sec_img_hashseg_data_e  size_type
);

/**
* @brief return hash algorithm used by hash table
*
* @param[in] s_img_hseg_handle - Pointer to context handle
* @return sec_img_hash_algo_type.
*/
sec_img_hash_algo_type
sec_img_hashseg_get_hash_algo
(
    sec_img_hashseg_info_t  *s_img_hseg_handle
);

/**
* @brief return if hash segment is qti signed
*
* @param[in] s_img_hseg_handle - Pointer to context handle
*/
boolean
sec_img_hashseg_is_qti_signed
(
    sec_img_hashseg_info_t  *s_img_hseg_handle
);

/**
* @brief clean and cache hash segment data for verification
*        this modifies hash segment data. OEM/QTI data needs
*        to be memset'ed to 0 for authentication
*        (when called the second time without restoring the
*        data cached in the first call, that data can be lost)
*
* @param[in] s_img_hseg_handle - Pointer to context handle
* @param[in] data_type - cache data type
*/
uint32 sec_img_hashseg_clean_cache
(
    sec_img_hashseg_info_t   *s_img_hseg_handle,
    sec_img_hashseg_cache_type_e   data_type
);

/**
* @brief restore and recover the hashsegment data
*
* @param[in] s_img_hseg_handle - Pointer to context handle
* @param[in] data_type - cache data type
*/
uint32 sec_img_hashseg_restore_data
(
    sec_img_hashseg_info_t   *s_img_hseg_handle,
    sec_img_hashseg_cache_type_e   data_type
);
/*----------------------------------------------------------------------------
* Functions to verify hash segment
* -------------------------------------------------------------------------*/
typedef struct sec_auth_handle_t {
    struct env{
        struct secboot_cm_ftbl_type       *cm_ftbl;  // Pointers for countermeasure functions
        struct secboot_handle_type        *secboot_handle;
        struct secboot_crypto_ftbl_type   *secboot_crypto;
    } env;
} sec_auth_handle_t;

/**
* @brief With privided OEM MISC hash, this function validates
*        metadata of the OEM signed hash segment or checks
*        unsigned hash segment integrity
*
* defined as sec_img_hashseg.h header
*/
sec_img_auth_error_type
sec_img_auth_validate_oem_metadata
(
    sec_auth_handle_t             *handle,
    sec_img_hashseg_info_t        *s_img_hseg,
    uint32                        sw_id,
    uint32                        secondary_sw_id,
    sec_img_info_type             *s_img_auth_info,
    secboot_verified_info_type    *verified_info
);

/**
* @brief With privided QTI MISC hash, validate QTI signed hash segment
*
* defined as sec_img_hashseg.h header
*/
sec_img_auth_error_type
sec_img_auth_validate_qti_metadata
(
    sec_auth_handle_t             *handle,
    sec_img_hashseg_info_t        *s_img_hseg_handle,
    uint32                        sw_id,
    uint32                        secondary_sw_id,
    sec_img_info_type             *s_img_auth_info,
    secboot_verified_info_type    *verified_info
);

/**
* @brief For the unsigned image, this function only validates
*        unsigned hash segment integrity
*
* defined as sec_img_hashseg.h header
*/
sec_img_auth_error_type
sec_img_auth_misc_validate_unsigned_image
(
    sec_auth_handle_t             *handle,
    sec_img_hashseg_info_t        *s_img_hseg,
    sec_img_info_type             *s_img_auth_info
);

/**
* @brief Returns secondary_sw_id field from the
*        hash segment.
*
* defined as sec_img_hashseg.h header
*/

sec_img_auth_error_type
sec_img_hashseg_get_secondary_sw_id_oem
(
    sec_img_hashseg_info_t  *s_img_hseg_handle,
    uint32                  *out_secondary_sw_id
);

sec_img_auth_error_type
sec_img_hashseg_get_secondary_sw_id_qti
(
    sec_img_hashseg_info_t  *s_img_hseg_handle,
    uint32                  *out_secondary_sw_id
);


#endif /* SEC_IMG_HASHSEG_H */
