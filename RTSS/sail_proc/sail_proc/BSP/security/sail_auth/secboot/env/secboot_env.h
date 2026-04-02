/* ============================================================================
 * @file  secboot_env.h
 * @brief Define functions or parameters for particular environment
 *
 * Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SECBOOT_ENV_H
#define SECBOOT_ENV_H

#include "secboot_chipset.h"

/*----------------------------------------------------------------------------
 * Environment Supporting Preprocessor Definition
 * -------------------------------------------------------------------------*/
#ifndef PACKED_STRUCT
	#define PACKED_STRUCT struct __attribute__((__packed__)) 
#endif

/*----------------------------------------------------------------------------
 * Preprocessor Definitions for Environment Constants
 * -------------------------------------------------------------------------*/
#define SECBOOT_HASH_DIGEST_BYTE_SIZE SECBOOT_OTP_ROOT_OF_TRUST_BYTE_SIZE
                                             /**< The MAX Digest Size that secboot supports (in bytes). 
                                                     This impacts the size of image hash and certificate hash,
                                                     and the size of root of trust hash provided by caller to
                                                     verify the root certificate. the OTP root of trust is not
                                                     impacted because that is fixed for chipset. */
#define SECBOOT_MAX_CERT_SIZE_IN_BYTE (2048U) /**< buffer for certificate */

#define SECBOOT_MAX_KEY_SIZE_IN_BITS (4096U) /**< Max public key size supported by secboot (in bits) */
#define SECBOOT_MIN_KEY_SIZE_IN_BITS (2048U) /**< minimum cert size to support */

#define SECBOOT_MIN_NUM_CERTS        (2U) /**< Minimum number of cert levels in a cert chain*/
#define SECBOOT_MAX_CERT_CHAIN_LEVEL (3U) /**< Maximum number of cert levels in a cert chain */
#define SECBOOT_MAX_NUM_ROOT_CERTS   (4U) /**< Maximum number of Root Certs for APPS/MODEM */

/** Total number of certs including max root certs */
#define SECBOOT_TOTAL_MAX_CERTS      (SECBOOT_MAX_NUM_ROOT_CERTS + SECBOOT_MAX_CERT_CHAIN_LEVEL - 1)

/*----------------------------------------------------------------------------
 * Preprocessor Definitions for Feature Enablement
 * -------------------------------------------------------------------------*/
#define SECBOOT_SUPPORT_METADATA_FROM_MBN_HEADER (TRUE)

/**
 * Data Type for crypto run-time buffer. Caller MUST provide run-time buffer.
 */
typedef struct crypto_ctx_t {
  uint8_t    *ctx_imem;  /**< pointer to crypto internal memory, assigned by caller for crypto operation */
  uint32_t   ctx_imem_size;   /**< Crypto driver to provide the size of crypto run-time buffer */
} crypto_ctx_type;

#endif /* SECBOOT_ENV_H */
