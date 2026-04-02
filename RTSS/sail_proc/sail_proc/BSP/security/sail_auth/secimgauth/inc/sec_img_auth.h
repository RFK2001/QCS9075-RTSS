#ifndef SEC_IMG_AUTH_H
#define SEC_IMG_AUTH_H

/**
@file sec_img_auth.h
@brief Secure Image Authentication 
*/

/*===========================================================================
   Copyright (c) 2022-2023 by QUALCOMM Technologies, Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE


when       who      what, where, why
--------   ---      ------------------------------------
15/08/14   mm       Adapted for 64 bit 
10/26/13   mm       Adapted for Boot ROM 
02/20/12   vg       Ported from TZ PIL.

===========================================================================*/

/**
 * @addtogroup SecImgAuthentication
 *
 * @{
 */
/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include "IxErrno.h"
#include "secboot.h"
#include "seccommon.h"
#include "sec_img_env.h"
#include "uie.h"
/* header files that can be removed if not needed by image env. */
#include "miprogressive.h"
#include "elf_header.h"
/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Data Type Definition
 * -------------------------------------------------------------------------*/
/**
 * Structure for holding elf header, program header and hash segment
 *        header information.
 */
typedef struct sec_img_auth_elf_info_type
{
  void *elf_hdr;       /**< Pointer to the elf header */
  void *prog_hdr;      /**< Pointer to the start of the program header */
  uint8* hash_seg_hdr;   /**< Pointer to the hash segment header*/
} sec_img_auth_elf_info_type;


/**
 * Structure for holding whitelist.
 */
typedef struct sec_img_auth_whitelist_area_s
{
  uintnt start; /**< Start address of the memory area. Start is inclusive. */
  uintnt end;   /**< End address of the memory area. End is exclusive.*/
} sec_img_auth_whitelist_area_t;

/**
 * Structure for passing the whitelist and the count.
 */
typedef struct sec_img_auth_whitelist_area_param_s
{
  uint32 count;  /**< count of whitelist area. */
  sec_img_auth_whitelist_area_t *area;  /**< Pointer to whitelist area data. */
}sec_img_auth_whitelist_area_param_t;

/** State of Secure Image Authentication. */
typedef enum
{
  SEC_IMG_AUTH_STATE_INIT = 1,   /**< initial state */
  SEC_IMG_AUTH_STATE_ELF_AND_PROG_HDRS_HASH_MATCH, /**< Elf image metadata authentication passes */
  SEC_IMG_AUTH_STATE_COMPLETE_SEGMENTS_HASH_MATCH  /**< Elf image segment verification passes */
}sec_img_auth_state_et;

/** 
 * Structure holds the state of the secure image auth,
 *        verified information in case of success, and 
 *        error information in case of error for both OEM and QTI signing. 
 *        (QTI signing information is only present on APPS side for double signing support)
 */
typedef struct sec_img_auth_verified_info_t
{
  uint32 version_id; /**< The version of this structure */
  uint32 ph_segment; /**< Segment that caused the hash failure */
  sec_img_auth_state_et state; /**< State of the Secure Image Authentication */
  secboot_verified_info_type v_info; /**< Secure Boot verified information for OEM signing */
  secboot_verified_info_type qc_v_info; /**< Secure Boot verified information for QTI signing 
                                             (only present on APPS for double signing support)*/
  sec_img_auth_error_type oem_auth_status; /**< State of the Secure Image Authentication for OEM signing 
                                                (only present on APPS for double signing support)*/
  sec_img_auth_error_type qc_auth_status; /**< State of the Secure Image Authentication for QTI signing 
                                               (only present on APPS for double signing support)*/
}sec_img_auth_verified_info_s;

/**
 * Information about the header of the image for 32 bit elf format.
 */
typedef struct sec_img_elf_prog_hdr_32
{
  Elf32_Ehdr  *elf_hdr;       /**< Pointer to the elf header */
  Elf32_Phdr  *prog_hdr;      /**< Pointer to the start of the program header */
}sec_img_elf_prog_hdr_32_type;

/**
 * Information about the header of the image for 64 bit elf format.
 */
typedef struct sec_img_elf_prog_hdr_64
{
  Elf64_Ehdr  *elf_hdr;       /**< Pointer to the elf header */
  Elf64_Phdr  *prog_hdr;      /**< Pointer to the start of the program header */
}sec_img_elf_prog_hdr_64_type;

/**
 * Information about the header of the image.
 */
typedef union sec_img_elf_prog_hdr 
{
  sec_img_elf_prog_hdr_32_type  hdr_32;       /**< Pointer to the 32 bit elf header */
  sec_img_elf_prog_hdr_64_type  hdr_64;       /**< Pointer to the 64 bit elf header */
} sec_img_elf_prog_hdr_type;

/**
 * Information about the elf image to be authenticated.
 */
typedef struct sec_img_auth_elf_info_s
{
  Elf_Class elf_format;         /**< Elf image format */
  sec_img_elf_prog_hdr_type  elf_prg_hdr;  /**< Pointer to the elf header */
  uint32        prog_hdr_num;   /**< Number of program header entries */
  uint8*        hash_seg_hdr;   /**< Pointer to the hash segment header*/
  uint32        hash_seg_hdr_sz;/**< Hash segment header size in bytes */
  uint8*        hash_seg;       /**< Pointer to the hash segment */
  uint32        hash_array_sz;  /**< Hash Array size in bytes */
  uint8*        sig_ptr;        /**< Pointer to the signature */
  uint32        sig_sz;         /**< Signature Size */
  uint8*        cert_ptr;       /**< Pointer to the certificate */
  uint32        cert_sz;        /**< Size of the certificate */
  uint8*        uie_hdr_ptr;    /**< Pointer to the UIE header */
  uint8*        signed_data_start_ptr; /**< start of the signed data */
  uint32        signed_data_size; /**< Size of the signed data*/
  } sec_img_auth_elf_info_t;

/**
 * Information about the authentication (image version, auth_en, code segment), which
 *        can be provided by the caller.
 */
typedef struct sec_img_info_type
{
  uint32       initialized;    /**< Set only by user, if initialized, will use info provided by user */
  uint32       sw_version;     /**< Minimum version of the image */
  uint32       code_segment;   /**< The code segment for ths image */
  uint32       auth_enabled;   /**< The auth_en fuse value. */
  uint32       hash_algo;      /**< The hash algorithm */
  uint8        hash[SECBOOT_HASH_DIGEST_BYTE_SIZE]; /**< Hash of the root certificate */
  uint32       validate_metadata; /* Validate Metadata */
} sec_img_info_type;

typedef struct sec_boot_mrc_fuse_info_type
{
  uint32   is_root_sel_enabled;  /**< Is Root Cert Selection enabled  */
  uint32   num_root_certs;       /**< valid only if root cert selection is enabled */
  uint32   revocation_list; /**< list of revoked root cert indicies */
  uint32   activation_list; /**< list of active root cert indicies */
} sec_boot_mrc_fuse_info_type;

typedef struct sec_boot_fuse_info_type
{
  uint8        use_supplied_info; /**< User supplied fuse information */
  uint8        root_of_trust[SECBOOT_HASH_DIGEST_BYTE_SIZE]; /**< sha256 hash of the root certificate */
  uint64       msm_hw_id;              /**< Fuse to the device's hw id */
  uint32       auth_use_serial_num;    /**< Use serial number in device's hw id */
  uint32       serial_num;             /**< Fuse to device's serial number */
  uint32       use_root_of_trust_only; /**< Caller sets this variable to TRUE if 
                                            secboot needs to use only root of trust from the 
                                            supplied fuses */
  sec_boot_mrc_fuse_info_type    mrc_fuse_info; /**< contains mrc specific values */
  uint32       reserved1;              /**< reserved */
  uint32       soc_hw_version;         /**< The fuse value of family number and 
                                                       device number of the soc hw version */
  uint32       oem_id_indp_disabled;   /**< Fuse to disable oem independent id */
  uint32       auth_use_oem_id;        /**< Enforce the usage of oem_id and model_id provided already
                                      as part of msm_hw_id. No change could be made to msm_hw_id
                                      to replace the oem_id and model_id */
  uint32       rsa_disable; /**< Variable for DISABLE_RSA fuse, 
                                 if 0x0 RSA is enabled,
                                 if 0x1 RSA is disabled */
  uint32       reserved2;   /**< reserved */
} sec_boot_fuse_info_type;

/**
 * Fuse information, which can be read from fuses or be provided by caller.
 */
typedef struct sec_img_fuse_info_type 
{
  uint32       initialized;    /**< If initialized, image authentication uses fuse values 
                                    from fuse_info struct */
  sec_boot_fuse_info_type fuse_info; /**< Fuse information for image */
}sec_img_fuse_info_type;

typedef struct sec_img_auth_handle_priv_s
{
  sec_img_auth_id_type img_id;                         /* Image Id */
  sec_img_auth_whitelist_area_param_t *whitelist_area; /* Whitelist */
  sec_img_auth_elf_info_type *img_data;                /* ELF information */
  crypto_ctx_type * crypto_ctx;                      /* Crypto Context */
} sec_img_auth_handle_priv_t;

/**
 * The handle of sec img auth api, with internal and external status.
 * (QTI signing information is only present on APPS side for double signing support)
 */
typedef struct sec_img_auth_priv_s
{
  sec_img_auth_id_type img_id;                         /**< Image Id */
  uint32               secondary_sw_id;                /**< Secondary SW ID */
  sec_img_auth_whitelist_area_param_t *whitelist_area; /**< Whitelist */
  sec_img_auth_elf_info_type *img_data;                /**< ELF information */
  sec_img_info_type auth_info;                         /**< Image authentication information for OEM signing*/
  sec_img_fuse_info_type fuse_info;                    /**< Fuse Info for OEM signing*/
  uie_ctx *uie_img_ctx;                                /**< UIE Img Context */ 
  crypto_ftbl_type * crypto_ftbl;                      /**< Crypto Table */
  sec_img_auth_elf_info_t elf;                         /**< Elf Info */
  sec_img_auth_state_et state;                         /**< Image authenication call state */
  sec_img_info_type qc_auth_info;                      /**< Image authentication information for QTI signing 
                                                            (only present on APPS for double signing support)*/
  sec_img_fuse_info_type qc_fuse_info;                 /**< Fuse Info for QTI signing 
                                                            (only present on APPS for double signing support)*/
  secboot_cm_ftbl_type* cm_ftbl;                       /**< Counter Meature Function Table (MUST-HAVE from caller)*/
  secboot_ftbl_type*    secboot_ftbl;                  /**< secboot function pointers provided by caller (set it NULL if not used)*/
} sec_img_auth_priv_t;


/**
 * The hash commands for partial hashing.
 */
typedef enum
{
  SEC_IMG_AUTH_PARTIAL_HASH_INIT = 1,                /** Hash init command for algorithm supported by secboot on target*/
  SEC_IMG_AUTH_PARTIAL_HASH_UPDATE,                  /** Hash update */
  SEC_IMG_AUTH_PARTIAL_HASH_FINALIZE,                /** Hash finalize for hash final and to compare the digest against the input from hash table */
  SEC_IMG_AUTH_PARTIAL_HASH_DEINIT,                  /** Hash de-init */
  SEC_IMG_AUTH_PARTIAL_HASH_FINALIZE_WITH_RETURN     /** Hash finalize for hash final and to return digest to the caller */
}sec_img_auth_partial_hash_cmd_et;

/**
 * The type for the partial hashing function.
 */
typedef struct sec_img_auth_partial_seg_hash_s
{
  sec_img_auth_partial_hash_cmd_et hash_cmd; /**< Hash Command */
  uint8 *partial_buff;			/**< Partial Segment Data Buffer */
  uint32 partial_buff_size;		/**< Partial Buffer Size (Bytes) */
  uint32 seg_num; 				/**< Segment Number (from Program Header) */
  uint32 seg_size;				/**< Segment File Size (Bytes) */
} sec_img_auth_partial_seg_hash_t;

/*----------------------------------------------------------------------------
 * Function Declarations and Documentation
 * -------------------------------------------------------------------------*/

/**
 * Initializes the handle for sec_img_auth APIs, within which crypto hw functions 
 *        are initialized. if crypto functions are missing, crypto_ftbl will be populated  
 *        with pbl internal crypto function pointers (for BOTH hash and image decrypt).
 *
 *        For the counter measure function table within sec_img_auth_priv_t handler: 
 *        The counter measure (CM) functions are owned and should be provided by the caller through
 *        CM function table. The caller provided CM functions will be used by CM protection within
 *        Secboot and SecImgAuth Libraries. 
 *
 * @param[in,out] s_img_handle Pointer to sec_img_auth handle
 *
 * @return SEC_IMG_AUTH_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 */
sec_img_auth_error_type sec_img_auth_init(sec_img_auth_priv_t* s_img_handle);

/**
 * Authenticates hash table segment against its signature.
 *
 * @param[in,out] s_img_handle Pointer to the image verification context
 * @param[in,out] v_info Pointer to the verified info 
 *
 * @return SEC_IMG_AUTH_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 */
sec_img_auth_error_type sec_img_auth_verify_metadata (
  sec_img_auth_priv_t *s_img_handle,
  sec_img_auth_verified_info_s *v_info
);

/**
 * Validates the metadata in the hash table segment against its signature and the hash matches
 * the hash in the Multi Image Metadata table. 
 *
 * @param[in,out] s_img_handle Pointer to the image verification context
 * @param[in,out] v_info Pointer to the verified info 
 * @param[in] hash Hash of the hash segment from Multi Image Metadata Table
 *
 * @return SEC_IMG_AUTH_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 */
sec_img_auth_error_type sec_img_auth_validate_metadata (
  sec_img_auth_priv_t *s_img_handle,
  sec_img_auth_verified_info_s *v_info
);


/**
 * Validates Elf segments against hash table.
 *
 * @param[in,out] s_img_handle Pointer to the image verification context
 * @param[in,out] v_info Pointer to the verified info 
 *
 * @return SEC_IMG_AUTH_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 */
sec_img_auth_error_type sec_img_auth_hash_elf_segments(
  sec_img_auth_priv_t *s_img_handle,
  sec_img_auth_verified_info_s *v_info);




/**
 * Elf header parser, to validate the correct elf format.
 *
 * @param[in] elf_hdr   Pointer to the ELF header.
 *
 * @return SEC_IMG_AUTH_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 */

sec_img_auth_error_type sec_img_auth_validate_elf(const void* elf_hdr);

/**
 * Check for loadable and non-paged segments.
 *
 * @param[in] format   ELF object class format
 * @param[in] entry    Program hdr entry for the segment
 *
 * @return \c TRUE if the segment is valid, \c FALSE otherwise.
 */
uint32 sec_img_auth_is_valid_segment(Elf_Class format, const void * entry);

/**
 * Parse and get elf image header format.
 *
 * @param[in] elf_hdr   Pointer to the ELF header.
 *
 * @param[out] elf_format   Pointer to the ELF header format.
 *
 * @return SEC_IMG_AUTH_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 */

sec_img_auth_error_type sec_img_auth_get_elf_format( const  void * elf_hdr,
                                                     Elf_Class *elf_format);

/**
 * Secimgauth API function table, 
 *        through which post-PBL user calls into Secimgauth APIs in PBL.
 */
typedef struct sec_img_auth_ftbl_type
{
  uint32 version_id;   /**< define function table version */
  sec_img_auth_error_type (*sec_img_auth_init)  /** Pointer to sec_img_auth_init */
                       (sec_img_auth_priv_t* s_img_handle);
  sec_img_auth_error_type (*sec_img_auth_verify_metadata)  /** Pointer to sec_img_auth_verify_metadata */
                       (sec_img_auth_priv_t *s_img_handle,
                        sec_img_auth_verified_info_s *v_info);
  sec_img_auth_error_type (*sec_img_auth_hash_elf_segments)  /** Pointer to sec_img_auth_hash_elf_segments */
                       (sec_img_auth_priv_t *s_img_handle,
                        sec_img_auth_verified_info_s *v_info);
  sec_img_auth_error_type(*sec_img_auth_hash_partial_segment) /** Pointer to sec_img_auth_hash_partial_segments */
                       (uint8      *hash_seg_hdr,
                        crypto_ftbl_type  *crypto_ftbl_ptr,
                        sec_img_auth_partial_seg_hash_t *s_partial_seg_hash,
                        secboot_cm_ftbl_type* cm_ftbl);
  sec_img_auth_error_type (*sec_img_auth_validate_elf)  /** Pointer to sec_img_auth_validate_elf */
                       (const void* elf_hdr);
  uint32 (*sec_img_auth_is_valid_segment)  /** Pointer to sec_img_auth_is_valid_segment */
                       (Elf_Class format, const void * entry);
  sec_img_auth_error_type (*sec_img_auth_get_elf_format)  /** Pointer to sec_img_auth_get_elf_format */
                       (const  void * elf_hdr,
                        Elf_Class *elf_format);
  sec_img_auth_error_type (*sec_img_auth_validate_metadata) /** Pointer to sec_img_auth_validate metadata */
                          (sec_img_auth_priv_t *s_img_handle,
                          sec_img_auth_verified_info_s *v_info);

}sec_img_auth_ftbl_type;

/**
 * Validates Elf segments against hash table using partial data input.
 *
 * @param[in] hash_seg_hdr Pointer to the hash segment header followed by 
 *                         the hashes of segments in sequential order
 * @param[in] crypto_ftbl_ptr Pointer to the crypto function table, 
 *                            expects hash functions to be initialized
 * @param[in] s_partial_seg_hash Pointer to the partial segment hash context 
 *
 * @param[in] cm_ftbl Pointer to Counter Measure function table (MUST be
 *                    provided, otherwise the auth would fail)
 *
 * @return SEC_IMG_AUTH_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects 
 *
 */
sec_img_auth_error_type sec_img_auth_hash_partial_segment
(
uint8 *hash_seg_hdr,
crypto_ftbl_type  *crypto_ftbl_ptr,
sec_img_auth_partial_seg_hash_t *s_partial_seg_hash,
secboot_cm_ftbl_type* cm_ftbl
);

/**
 * This function return pointers to the secimgauth functions linked into
 *        the image.
 *
 * @param[out] ftbl_ptr              Pointer to the function table structure
 *                                      to populate. The pointer must be allocated
 *                                      by the caller.
 *
 * @return SEC_IMG_AUTH_SUCCESS on success. Appropriate error code on failure.
 *
 * @sideeffects  None
 *
 *
 */
sec_img_auth_error_type sec_img_auth_get_ftbl
(
  sec_img_auth_ftbl_type* ftbl_ptr
);

/**
* Secboot Shared Info,
*        information shared with post-PBL.
*/
typedef struct secboot_pbl_shared_info_type
{
  secboot_verified_info_type pbl_verified_info;    /**<  */
  secboot_ftbl_type          pbl_secboot_ftbl;     /**< Contains pointers to PBL secboot routines */
  sec_img_auth_ftbl_type     pbl_sec_img_auth_ftbl;/**< Contains pointers to PBL secimg routines */
} secboot_pbl_shared_info_type;

/**
 * @brief Get Image end address
 *
 * @param[in] s_img_handle Pointer to the image info of the xbl_sec image.
 * @param[in] end_address Pointer to the inclusive end address of xbl_sec image in memory.
 *
 * @return 0 on success, negative on failure
 */
sec_img_auth_error_type
sec_img_auth_get_image_memory_end_address
(
 sec_img_auth_priv_t *s_img_handle,
 uint64 *end_address
);

uint32_t sail_sec_get_soc_id(void);

/** @}
*/
#endif /* SEC_IMG_AUTH_H */
