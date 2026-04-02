#ifndef SEC_IMG_COMMON_H
#define SEC_IMG_COMMON_H

/**
@file seccommon.h
@brief Secure Image Authentication common file
*/

/*===========================================================================
   Copyright (c) 2012-2016 by QUALCOMM Technologies, Incorporated.  All Rights Reserved.
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
#include "sec_img_env.h"
#include "secboot.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
/** 
 * Error code base reserved for UIE. UIE error starts   
 *         from SEC_IMG_AUTH_ERROR_TYPE_UIE_BASE (0x150) to 0x1FF
 */
#define SEC_IMG_AUTH_ERROR_TYPE_UIE_BASE  (0x150)

/** 
 * Type definition of Secimgauth return error. SUCCESS uses enum value of 0 and the error of Secimgauth library 
  * starts with 0x101. The first 0x100 values are reserved for secure boot failures. Please refer secboot.h.
  */
typedef enum sec_img_auth_error_type
{
  SEC_IMG_AUTH_SUCCESS = 0x2EC88FF0,             /**< SUCCESS */
  SEC_IMG_AUTH_FAILURE = 0x101,                  /**< FAILURE */
  SEC_IMG_AUTH_INVALID_ARG = 0x102,              /**< Invalid argument */
  SEC_IMG_AUTH_OUT_OF_RANGE = 0x103,             /**< Value out of range */
  SEC_IMG_ELF_HEADERS_INVALID_DIGEST = 0x104,    /**< Invalid elf header hash digest */ 
  SEC_IMG_AUTH_SEGMENT_INVALID_DIGEST = 0x105,   /**< Invalid elf segment hash digest */
  SEC_IMG_AUTH_NO_MEMORY = 0x106,                /**< No memory */
  SEC_IMG_AUTH_INVALID_DIGEST_LEN = 0x107,       /**< Invalid input disgest length */
  SEC_IMG_AUTH_GET_SW_VERSION_FAILED = 0x108,    /**< Fail to get sw version for unsupported image */
  SEC_IMG_AUTH_GET_SW_ID_FAILED = 0x109,         /**< Fail to get sw id */
  SEC_IMG_AUTH_GET_CODE_SEGMENT_FAILED = 0x10A,  /**< Fail to get code segment for unsupported image */
  SEC_IMG_AUTH_INCORRECT_HASH_LEN = 0x10B,       /**< Incorrect input hash length */
  SEC_IMG_AUTH_INCORRECT_HASH_TOTAL_LEN = 0x10C, /**< Incorrect total hash length */
  SEC_IMG_AUTH_CORRUPTED_IMAGE = 0x10D,          /**< Program header corruption */
  SEC_IMG_AUTH_MI_BOOT_INVALID = 0x10E,          /**< Invalid mi boot header (mbn header) */
  SEC_IMG_AUTH_INVALID_ELF = 0x10F,              /**< Invalid elf format */
  SEC_IMG_AUTH_STATE_INVALID = 0x110,            /**< Invalid sec img state */
  SEC_IMG_AUTH_MI_BOOT_INVALID_SIZE = 0x111,     /**< Invalid size in mi boot header (mbn header) */
  SEC_IMG_AUTH_ELF_INCORRECT_MAGIC = 0x112,      /**< Invalid elf magic */
  SEC_IMG_AUTH_ELF_INVALID_CLASS = 0x113,        /**< Invalid elf format */
  SEC_IMG_AUTH_INVALID_VERSION = 0x114,          /**< Invalid elf version */
  SEC_IMG_AUTH_ELF_INVALID_EHSIZE = 0x115,       /**< Invalid elf ehsize */
  SEC_IMG_AUTH_ELF_INVALID_PHENTSIZE = 0x116,    /**< Invalid elf program hdr entry size */
  SEC_IMG_AUTH_PROG_TBL_INVALID_SIZE = 0x117,    /**< Invalid elf program table size */
  SEC_IMG_AUTH_HASH_SEG_INVALID_SIZE = 0x118,    /**< Invalid hash segment size */
  SEC_IMG_AUTH_ELF_HDR_INVALID_SIZE = 0x119,     /**< Invalid image header (metadata) size */
  SEC_IMG_AUTH_NOT_INITIALIZED = 0x11A,          /**< Initialization failure */
  SEC_IMG_AUTH_ELF_INVALID_NUM_SEGMENTS = 0x11B, /**< Invalid segment number */
  SEC_IMG_AUTH_INVALID_IMG_ID = 0x11C,           /**< Invalid image id */
  SEC_IMG_AUTH_VALIDATE_IMAGE_AREA_INVALID_SEGMENT = 0x11D, /**< Invalid segment area */
  SEC_IMG_AUTH_VALIDATE_IMAGE_AREA_INTEGER_OVERFLOW = 0x11E,/**< Integer overflow */
  SEC_IMG_AUTH_MI_BOOT_INVALID_CERT_CHAIN_SIZE = 0x11F, /**< Invalid cert chain size in mi boot (mbn) header */
  SEC_IMG_AUTH_HASH_SEG_TOTAL_INVALID_SIZE = 0x120, /**< Hash segment size overflow */
  SEC_IMG_AUTH_SIG_INVALID_SIZE = 0x121,         /**< Image signature size overflow */
  SEC_IMG_AUTH_MIHDR_NOT_ALIGNED = 0x122,        /**< Hash segment address not aligned */
  SEC_IMG_AUTH_VALIDATE_IMAGE_AREA_INVALID_ENTRY= 0x123, /**< Invalid elf image entry address */
  SEC_IMG_AUTH_CERT_INVALID_SIZE = 0x124,        /**< Cert chain size overflow */
  SEC_IMG_AUTH_HASH_SEG_ARRAY_INVALID_SIZE = 0x125, /**< Invalid hash segment code size */
  SEC_IMG_AUTH_INCORRECT_HASH_TABLE_SEGMENTS_COUNT = 0x126, /**< Invalid number of hash segment */
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_SIZE =0x127, /**< Invalid encryption parm size */
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_MAGIC = 0x128, /**< Invalid encryption parm magic */
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_VERSION = 0x129, /**< Invalid encryption parm version */
  SEC_IMG_AUTH_ENCRYPTION_INVALID_SIZE = 0x12A,   /**< Invalid size in encryption parm */
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_SOURCE_ID = 0x12B, /**< Invalid source id in encryption parm */
  SEC_IMG_AUTH_ENCRYPTION_PARAMS_INVALID_KEY_LADDER_LEN = 0x12C, /**< Invalid key ladder length */
  SEC_IMG_AUTH_INVALID_ENCRYPTION_KEY_ID = 0x12D, /**< Invalid key id */
  SEC_IMG_AUTH_INVALID_IMAGE_ID = 0x12E,          /**< Invalid image id */
  SEC_IMG_AUTH_INVALID_ENC_PRARM_SIZE = 0x12F,    /**< Invalid encryption parm size */
  SEC_IMG_AUTH_INTEGER_OVERFLOW = 0x130,          /**< Integer overflow */
  SEC_IMG_AUTH_CE_BIST_FAILURE = 0x131,           /**< Crypto engine BIST error */
  SEC_IMG_AUTH_CE_TIMEOUT = 0x132,                /**< Crypto engine timeout error */
  SEC_IMG_AUTH_CE_INIT_FAILURE = 0x133,           /**< Crypto engine init error */
  SEC_IMG_AUTH_CE_HW_BUSY = 0x134, /** < Crypto Engine hardware is busy*/
  SEC_IMG_AUTH_ENCRYPTION_INVALID_IMAGE = 0x135,  /**< Unencrypted image*/
  SEC_IMG_AUTH_INIT_CM_INFO_FAILURE = 0x136,  /**< Fail to initiailize counter measure info.*/
  SEC_IMG_AUTH_UNSUPPORTED_IMAGE = 0x137,  /**< Image is not supported for the functionality. */
  SEC_IMG_AUTH_METADATA_INVALID_SIZE = 0x138, /**< Invalid Metadata Size */
  SEC_IMG_AUTH_INVALID_SIGNED_DATA_SIZE = 0x139, /**< Invalid Signed Metadata Size */
  SEC_IMG_HASH_SEG_INCORRECT_HASH = 0x13A,	/** Hash segment has invalid hash vale */
  SEC_IMG_HASH_SEG_MIHDR_VERSION_NOT_SUPPORTED = 0x13B,   /**< unsupported mi hder version */
  SEC_IMG_HASH_SEG_DATA_NOT_SUPPORTED = 0x13C,   /**< data type not supported */
  SEC_IMG_HASH_SEG_CFG_NOT_PROVIDED = 0x13D,   /**< cfg data not provided */
  SEC_IMG_HASH_SEG_DATA_NOT_EXIST = 0x13E,     /**< data not existing */
  SEC_IMG_HASH_SEG_DATA_NOT_CACHED = 0x13F,    /**< data not cached and cannot be restored */
  SEC_IMG_RELOC_FAILURE = 0x140,	/** General relocation failure */
  SEC_IMG_AUTH_UNSUPPORTED_API = 0x141,  /** unsupported api function */
  SEC_IMG_AUTH_MISC_BASED_AUTHENTICATION_NOT_ALLOWED = 0x142,  /** MISC-based authentication not allowed */

  SEC_IMG_AUTH_MAX                    = 0x7FFFFFFF /**< Maximum unused error code value */
}sec_img_auth_error_type;

/**
 * Type definition of the supported image type
 */
typedef enum sec_img_auth_id_type
{
  SEC_IMG_AUTH_APPS_IMG = 0x00030000,      /**< SBL/XBL/EHOSTDL Image */
  SEC_IMG_AUTH_MBA_IMG = 0x1,              /**< MBA Image */
  SEC_IMG_AUTH_SECPROC_BOOT_IMG = 0x6,     /**< Secure Processor Kernel Image */
  SEC_IMG_AUTH_APPS_SEC_IMG = 0xB,         /**< xBL SEC Image */
  SEC_IMG_AUTH_QTI_MISC = 0x23,            /* QTI MISC Image */
  SEC_IMG_AUTH_UNSUPPORTED_IMG = 0x7FFFFFFF,      /**< Max for unsupported image type */
  SEC_IMG_AUTH_NUM_SUPPORTED_IMG = SEC_IMG_AUTH_UNSUPPORTED_IMG   /**< count of supported image types */
}sec_img_auth_id_type;

/**
 * Identifies the error type returned by the Crypto functions. 
 * Caller-defined Crypto functions return these error type.
 */
typedef enum
{
  E_SECBOOT_CRYPTO_SUCCESS                = E_SECBOOT_CB_SUCCESS,   /**< Operation was successful. */
  E_SECBOOT_CRYPTO_FAILURE                = E_SECBOOT_CB_FAILURE,   /**< General failure. */
  E_SECBOOT_CRYPTO_INVALID_PARAM          = E_SECBOOT_CB_INVALID_PARAM,   /**< Invalid parameter passed into function. */
  E_SECBOOT_CRYPTO_HASH_INIT_FAIL         = E_SECBOOT_CB_HASH_INIT_FAIL,   /**< crypto hash init fail. */
  E_SECBOOT_CRYPTO_HASH_UPDATE_FAIL       = E_SECBOOT_CB_HASH_UPDATE_FAIL,   /**< crypto hash update fail. */
  E_SECBOOT_CRYPTO_HASH_FINAL_FAIL        = E_SECBOOT_CB_HASH_FINAL_FAIL, /**< crypto hash final fail */
  E_SECBOOT_CRYPTO_HASH_DEINIT_FAIL       = E_SECBOOT_CB_HASH_DEINIT_FAIL,   /**< crypto hash deinit fail. */
  E_SECBOOT_CRYPTO_INVALID_CTX_SIZE_FAIL  = E_SECBOOT_CB_INVALID_CTX_SIZE_FAIL,   /**< ctx size is not sufficient. */
  E_SECBOOT_CRYPTO_DECRYPT_CCM_FAIL       = 8,   /**< crypto decrypt key fail. */
  E_SECBOOT_CRYPTO_INIT_TIME_OUT          = 9,   /**< crypto init timeout fail. */
  E_SECBOOT_CRYPTO_DECRYPT_LOAD_KEY_FAIL  = 10,   /**< fail to load decryption key. */
  E_SECBOOT_CRYPTO_CTX_INIT_FAIL          = 11,   /**< crypto context init fail. */
  E_SECBOOT_CRYPTO_UNSUPPORTED_KEY_LEVEL  = 12,   /**< unsupported key level type. */
  E_SECBOOT_CRYPTO_DECRYPT_CBC_FAIL       = 13,   /**< crypto decrypt cbc fail. */
  E_SECBOOT_CRYPTO_DECRYPT_UNLOAD_KEY_FAIL= 14,   /**< fail to unload decryption key. */
  E_SECBOOT_CRYPTO_OVERFLOW_FAIL          = E_SECBOOT_CB_OVERFLOW_FAIL,   /**< overflow error. */
  E_SECBOOT_CRYPTO_RSA_MODEXP_FAIL        = E_SECBOOT_CB_RSA_MODEXP_FAIL,   /**< rsa modexp operation error. */
  E_SECBOOT_CRYPTO_HW_BUSY				  = 17,   /**< Crypto hardware has not finished operation*/
  E_SECBOOT_CRYPTO_HASH_MAX               = 0x7FFFFFFF /**< Max unused error code */
} SECBOOT_CRYPTO_ERR_TYPE;

/* define hash algorithm type used by the api */
typedef enum sec_img_hash_algo_type{
  CRYPTO_HASH_ALGO_NA     = 0x0,
  CRYPTO_HASH_ALGO_SHA256 = 0x2,         /**< Number index of SHA256 Algo. */
  CRYPTO_HASH_ALGO_SHA384 = 0x3,         /**< Number index of SHA384 Algo */
  CRYPTO_HASH_ALGO_SHA512 = 0x5,         /**< Number index of SHA512 Algo */
  CRYPTO_HASH_ALGO_UNSUPPORTED
} sec_img_hash_algo_type;

/**
 * Type definition of the crypto function pointer table. 
 *
 *    Caller passes in caller-defined crypto function, and Secimgauth and Secboot library will use 
 *    caller-defined crypto for image decryption and image authentication. The caller should define  
 *    crypto function based on API signature in the table. The caller can also use default Crypto 
 *    functions defined in the image by passing NULL to function pointers.
 */
typedef struct crypto_ftbl_type {
    crypto_ctx_type crypto_ctx; /**< crypto context */
/**
 * Pointer to the function to initialize the CE (used within Secimgauth, Secboot and UIE Library).
 *        Context memory must be assigned and passed in outside the call.
 *
 * @param[in] ctx   The context
 * @param[in] hash_algo The hash algorithm type
 *
 * @return 0 on success, error code SECBOOT_CRYPTO_ERR_TYPE on failure.
 *
 */
    uint32 (*HashInit) (crypto_ctx_type* ctx, uint32 hash_algo);
/**
 * Pointer to function to hash data into the hash context
 *        structure, which must have been initialized by
 *        HashInit (used within Secimgauth, Secboot and UIE Library).
 *
 * @param[in] ctx   The context
 * @param[in] data  Pointer to input message to be hashed
 * @param[in] data_len The message byte size
 *
 * @return 0 on success, error code SECBOOT_CRYPTO_ERR_TYPE on failure.
 *
 */
    uint32 (*HashUpdate) (crypto_ctx_type* ctx, const void *data, uint64 data_len);
/**
 * Pointer to the function to compute the final digest hash value (used within Secimgauth, 
 *        Secboot and UIE Library).
 *
 * @param[in] ctx   The context
 * @param[out] digest_ptr  Pointer to digest data
 * @param[in] digest_len The digest byte size
 *
 * @return 0 on success, error code SECBOOT_CRYPTO_ERR_TYPE on failure.
 *
 */
    uint32 (*HashFinal) (crypto_ctx_type* ctx, void* digest_ptr, uint32 digest_len);
/**
 * Pointer to the function to deintialize a cipher context (used within Secimgauth, Secboot 
 *        and UIE Library).
 *
 * @param[in] ctx   The context
 *
 * @return 0 on success, error code SECBOOT_CRYPTO_ERR_TYPE on failure.
 *
 */
    uint32 (*HashDeInit) (crypto_ctx_type* ctx);
/**
 * Pointer to the function to decrypt and retrieve Cipher Key for decrypting 
 *        segment (used within UIE library).
 *
 * @param[in] crypto_ctx The crypto context
 * @param[in] uie_header The pointer to uie header data
 * @param[in] uie_header_sz Size of uie header data
 * @param[out] key The cipher key used in image decryption
 * @param[in]  key_len The byte length of the cipher key
 * @param[in]  l1_key The l1 key, passed from UIE Library, can either be from fuse or from caller
 * @param[in]  l1_key_len The byte length of the l1 key
 *
 * @return 0 on success, error code SECBOOT_CRYPTO_ERR_TYPE on failure.
 *
*/
    uint32 (*CipherKeyInit)(
                    crypto_ctx_type* crypto_ctx,         // the crypto context
                    uint8 *uie_header,                   // the pointer to uie parameter header
                    uint32 uie_header_sz,                // size of uie header data
                    uint8 *key,                          // the cipher key used in image decryption
                    uint32 key_len,                      // the byte length of the cipher key
                    uint8 *l1_key,                       // the l1 key, passed from UIE Library, can either be from fuse or from caller
                    uint32 l1_key_len);                  // the byte length of the l1 key
/**
 * Pointer to the function to run the CBC-CTS decryption algorithm using the
 *        block cipher (used within UIE library).
 *
 * @param[in]  crypto_ctx crypto context
 * @param[in]  key_ptr The key to decrypt with
 * @param[in]  key_len The length of the key (16=AES128, 32=AES256)
 * @param[in]  iv_ptr The initialization vector to decrypt with
 * @param[in]  iv_len The byte length of the initialization vector
 * @param[in]  data1_in_ptr The ciphertext to decrypt
 * @param[in]  data_len The byte length of the ciphertext
 * @param[out] digest The optional SHA256 hash digest; a non-NULL
 *                    input address will result in a digest output
 * @param[in]  digest_len The byte length of the digest
 *
 * @return 0 on success, error code SECBOOT_CRYPTO_ERR_TYPE on failure.
 *
 */
    uint32 (*DecryptCBC)(
                    crypto_ctx_type* crypto_ctx,         // the crypto context
                    uint8 *key_ptr, uint32 key_len,      // the cipher key used in image decryption and its the byte length
                    uint8 *iv_ptr, uint32 iv_len,        // the iv for segment decryption and its the byte length
                    uint8 *data1_in_ptr, uint64 data1_len, // the payload data for segment decryption and its the byte length
                    uint8 *digest, uint32 digest_len);   // the output digest and its the byte length
/**
 * Pointer to the function to initialize Crypto (used within Secimgauth Library)
 *
 * @param[in] crypto_ctx   The crypto context
 *
 * @return 0 on success, error code SECBOOT_CRYPTO_ERR_TYPE on failure.
 *
 */
    uint32 (*CryptoInit)(crypto_ctx_type* crypto_ctx); 
	
/**
 * Pointer to the function to decrypt the message in RSA operation with given mod and exp (used within Secboot library).
 *        The mod and exp are sent in big endian for SP PBL, as SP PBL use hardware based RSA.
 *        The hardware based RSA operates in big endian. The APPS and MPSS PBL uses software based RSA,
 *        which works in little endian.
 *
 * @param[in]  ctx crypto context
 * @param[in]  mod_size the modsize (byte size), the same as the return value size
 * @param[in]  exp_size the exp size (byte size)
 * @param[in]  mod the ptr to mod
 * @param[in]  message the ptr to message
 * @param[in]  exp the ptr to exp
 * @param[out]  r the ptr to return value
 *
 * @return 0 on success, error code SECBOOT_CRYPTO_ERR_TYPE on failure.
 *
 */
    uint32 (*ModExp) (
                    crypto_ctx_type* ctx,                // the crypto context
                    uint32 mod_size,                     // the mod size
                    uint32 exp_size,                     // the exp size
                    uint8* mod,                          // the ptr to mod
                    uint8* message,                      // the ptr to message
                    uint8* exp,                          // the ptr to exp
                    uint8* r);                           // the ptr to return value
}crypto_ftbl_type;


/** @}
*/
#endif /* SEC_IMG_COMMON_H */
