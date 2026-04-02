#ifndef SAIL_SEC_CRYPTO_H
#define SAIL_SEC_CRYPTO_H

/*===========================================================================
 Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

#include <stdint.h>
#include <stddef.h>
#include "uclib_cipher.h"

#define _IS_BYTEALLIGNED(v)         (((uint32)(v) & 0x03) == 0)
#define _IS_NOT_BYTEALLIGNED(v)     (!(_IS_BYTEALLIGNED(v)))

/*For uie feature detection*/
typedef enum
{
 UIE_IS_ENABLE,
 UIE_IS_DISABLE,
 UIE_FAILURE = 0xFF
}uie_img_encr_info;

/** Crypto handle type */
typedef void * sail_sec_crypto_handle_t;

/** Hash algorithms supported */
typedef enum
{
  SAIL_SEC_SHA256,
  SAIL_SEC_SHA384,
  SAIL_SEC_INVALID_HASH_ALGO,
} sail_sec_hash_algo_t;

/** Control parameters supported */
typedef enum
{
  SAIL_SEC_CRYPTO_HASH_NONBLOCK_MODE,
  SAIL_SEC_CRYPTO_HASH_INVALID_PARAM,
} sail_sec_hash_param_t;

/**
 * ECDSA sig verification error codes.
 */
typedef enum
{
  ECDSA_SIG_VERIFY_SUCCESS = 0,
  ECDSA_SIG_VERIFY_INV_ARG,
  ECDSA_SIG_VERIFY_NOT_SUPPORTED,
  ECDSA_SIG_VERIFY_FAILED
} ecdsa_err_code_t;

/**
 * ECC curve type.
 */
typedef enum
{
  EC_STD_CURVE_P384,
  EC_STD_CURVE_COUNT,
  EC_STD_CURVE_MAX  = 0x7FFFFFFF
} ec_std_curve_t;

/**
 * @brief Retrieves the size of the PBL shared crypto table.
 *
 * @return Size of the PBL shared crypto table
 *
 */
size_t sail_sec_get_shared_crypto_data_size(void);

/**
 * @brief Retrieves the internal pointer to the copy of the PBL shared crypto
 * table. This is used when making a local copy of the PBL crypto table.
 *
 * @return Internal pointer to the copy of the PBL shared crypto table
 *
 */
void * sail_sec_get_shared_crypto_data_copy(void);

/**
 * @brief Retrieves the size of the PBL shared ECC table.
 *
 * @return Size of the PBL shared ECC table
 *
 */
size_t sail_sec_get_shared_ecc_data_size(void);

/**
 * @brief Retrieves the internal pointer to the copy of the PBL shared ECC
 * table. This is used when making a local copy of the PBL ECC table.
 *
 * @return Internal pointer to the copy of the PBL shared ECC table
 *
 */
void * sail_sec_get_shared_ecc_data_copy(void);

/**
 * @brief Top-level Crypto initialization.
 * This should be called before performing any crypto related operations. On
 * targets using CEML crypto, this is typically an empty implementation. But
 * for targets using UCLIB, this writes the address of the XBL-sec UCLIB
 * environment structure into a shared location that PBL can read from.
 *
 * @return 0 on success, error code otherwise.
 *
 */
int sail_sec_crypto_init(void);

/**
 * @brief Top-level Crypto de-initialization.
 *
 * @return 0 on success, error code otherwise.
 *
 */
int sail_sec_crypto_deinit(void);

/**
 * @brief Allocates space (if necessary) for and initializes the crypto context
 * for a hash operation.
 *
 * @param ctx[in] Pointer to the crypto context buffer
 * @param hash_algo[in] Hash algorithm to use
 *
 * @return 0 on success, error code otherwise.
 *
 */
int sail_sec_hash_init(void** ctx, uint32_t hash_algo);

/**
 * @brief Updates the crypto hash context with additional message data
 *
 * @param ctx[in] crypto context buffer
 * @param msg[in] Message byte-array
 * @param msg_sz[in] Length of message byte-array
 *
 * @return 0 on success, error code otherwise.
 *
 */
int sail_sec_hash_update(void* ctx, const uint8_t *msg, size_t msg_sz);

/**
 * @brief Generates the final hash digest
 *
 * @param ctx[in] crypto context buffer
 * @param dgst[out] Hash digest
 * @param dgst_sz[in] Length of the hash digest array
 *
 * @return 0 on success, error code otherwise.
 *
 */
int sail_sec_hash_final(void* ctx, uint8_t * dgst, size_t dgst_sz);

/**
 * @brief Releases any resources allocated when initializing the crypto
 * context for hashing.
 *
 * @param ctx[in] Pointer to the crypto context buffer
 *
 * @return 0 on success, error code otherwise.
 *
 */
int sail_sec_hash_deinit(void** ctx);

/**
 * @brief  This function will create a message digest hash using the
 *         algorithm specified.
 *
 * @param alg[in]          The hash algorithm
 * @param buf[in]          The message to hash
 * @param buf_sz[in]       The length of the message
 * @param digest[in,out]   The digest to store
 * @param digest_len[in]   Length of the output message digest hash
 *                         buffer in bytes. Must be 20 bytes for SHA1 and
 *                         32 bytes for SHA256
 *
 * @return 0 on success, negative on failure
 */
int sail_sec_hash
(
  uint32_t alg,
  const uint8_t *buf,
  uint32_t buf_sz,
  uint8_t *digest,
  uint32_t digest_len
);

/**
 * @brief Generates the final hash digest
 *
 * @param ctx[in] crypto context buffer
 * @param param[in] Parameter/flag type
 * @param val[in] Integer data associated with/required by the parameter type
 * @param ibuf[in/out] Buffer to provide or retrieve non-integer data
 * associated with/required by the parameter type
 * @param isz[in] Size of the provided buffer
 * @param osz[out] Size of data written out into the provided buffer
 *
 * @return 0 on success, error code otherwise.
 *
 */
int sail_sec_hash_ctrl
(
  void * ctx,
  int param,
  int val,
  uint8_t *ibuf,
  size_t isz,
  size_t *osz
);

/**
 * @brief Writes the given value into one of the thread context registers. This
 * functionality is used on targets that use the UCLIB crypto library in the
 * boot-ROM.
 *
 * @param val[in] Value to write into the register
 *
 * @return None
 *
 */
void xbl_sec_write_tpidr(void *val);

/**
 * @brief Retrieves the dcache cache line size
 *
 * @param None
 *
 * @return DCache cache line size
 *
 */
size_t xbl_sec_get_dcache_line_size(void);


/**
 * @brief Calculates the maximum data size that can be transferred/queued to 
 * CE in each update call for parallel hash
 *
 * @param None
 *
 * @return Max data size in bytes
 *
 */
size_t xbl_sec_get_max_parallel_hash_update_size(void);

/**
 * @brief Initializes cipher context based on requested cipher
 *        algorithm, cipher mode and acceleration engine. If
 *        engine parameter is passed as zero, the default engine
 *        will be used. The default engine is defined in UCLIB
 *        configuration file. User can set key and iv parameters
 *        later using uclib_cipher_ctx_ctrl API and passes NULL
 *        as either of key and iv parameters. Key and IV buffers
 *        size are implicitly specified by the cipher mode
 *        passed in the api. Encrypt parameter controls cipher
 *        direction in the context (Encryption vs. Decryption)
 *
 * @param h       [in] handle to the cipher context
 * @param alg     [in] cipher alg enumerated in UCLIB_CIPHER_ALG
 * @param mode    [in] cipher mode enumerated in
 *                UCLIB_CIPHER_MODE
 * @param engine  [in] engine type enumerated in
 *                UCLIB_ENGINE_TYPE
 * @param encrypt [in] direction (true: Encrypt, false:
 *                 Decrypt)
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int sail_sec_cipher_init(UCLIB_CIPHER_HANDLE *h,
                        UCLIB_CIPHER_ALG alg,
                        UCLIB_CIPHER_MODE mode,
                        UCLIB_ENGINE_TYPE engine,
                        bool  encrypt);

/**
 * @brief Writes/reads cipher context parameters. Parameters can
 *        be passed as value using [val] or as an array of bytes
 *        (8-bit) using [ibuf, isz] arguments. If client does
 *        not know the required buffer size for a type, it can
 *        call the API with ibuf as NULL and provide valid
 *        pointer to osz to retrieve required buffer size for
 *        associated parameter. Refer to UCLIB_CIPHER_PARAM_TYPE
 *        definition for more details of each parameter type. To
 *        read any cipher parameter, [ibuf, isz] are required.
 *
 * @param h      [in] handle to the cipher context
 * @param type   [in] Cipher context parameter type
 * @param val    [in] Cipher context parameter can be passed by
 *               value using this parameter.
 * @param ibuf   [in, out] pointer to buffer in order to
 *               write/read to/from cipher context
 * @param isz    [in] ibuf size in bytes
 * @param osz    [out] pointer to required size on return from
 *               API
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int sail_sec_cipher_ctrl(UCLIB_CIPHER_HANDLE h,
                        UCLIB_CIPHER_PARAM_TYPE type,
                        int val,
                        uint8_t *ibuf,
                        size_t isz,
                        size_t *osz);

/**
 * @brief  Encrypts/Decrypts input buffer [ibuf, isz] and saves
 *         the cipher/plain text to output buffer [obuf, osz]
 *         and saves cipher context for further updates. The API
 *         will update output size on successful return in
 *         vld_osz pointer if provided by caller.
 *
 * @param h        [in]  handle to the cipher context
 * @param ibuf     [in]  pointer to input buffer
 * @param isz      [in]  input buffer size
 * @param obuf     [in]  pointer to output buffer
 * @param osz      [in]  output buffer size
 * @param vld_osz  [out] pointer to output buffer size after
 *                 returning from API (optional)
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int sail_sec_cipher_update(UCLIB_CIPHER_HANDLE h,
                          const uint8_t *ibuf, size_t isz,
                          uint8_t *obuf, size_t osz,
                          size_t *vld_osz);

/**
 * @brief  Updates additional authentication data when
 *         authenticated cipher mode (e.g CCM/GCM) is selected.
 *         It returns failure for other cipher modes.
 *
 * @param h        [in]  handle to the cipher context
 * @param aad      [in]  pointer to AAD buffer
 * @param aad_sz   [in]  AAD buffer size
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int sail_sec_cipher_update_aad(UCLIB_CIPHER_HANDLE h,
                              const uint8_t *aad, size_t aad_sz);

/**
 * @brief  Encrypt/Decrypt the last segment of input buffer
 *         saved in cipher context and saves the cipher/plain
 *         text to output buffer [obuf, osz]. The API will
 *         update output size on successful return in vld_osz
 *         pointer if provided by caller.
 *
 * @param h        [in] handle to the cipher context
 * @param obuf     [in] pointer to output buffer
 * @param osz      [in] pointer output buffer size
 * @param vld_osz  [out] pointer output buffer size after
 *                 returning from API (optional)
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int sail_sec_cipher_final(UCLIB_CIPHER_HANDLE h,
                         uint8_t *obuf, size_t osz,
                         size_t *vld_osz);

/**
 * @brief Resets internal states in order to use the handle for
 *        fresh cipher operation. The interface retains the
 *        cipher algorithm, mode, engine, direction, and key
 *        that user has already initialized for the same handle
 *        using Cipher Init and Ctrl interfaces. IV/Nonce has to
 *        be re-initialized.
 *
 * @param h      [in] handle to the cipher context
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int sail_sec_cipher_reset(UCLIB_CIPHER_HANDLE h);

size_t sail_get_prng_data(uint8_t *buf, size_t buf_sz);

#endif
