/*=========================================================================
FILE: secure_storage_el2_crypto_cfg.h
OVERVIEW: Defines all the configuration for crypto ops in secure storage

Copyright (c) Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Technologies Inc. Confidential and Proprietary
=========================================================================*/
#ifndef SECURE_STORAGE_EL2_CRYPTO_CFG_H
#define SECURE_STORAGE_EL2_CRYPTO_CFG_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */

#include "types.h"
#include "secure_storage_el2_types.h"

/* ----------------------------------------------------------------------------
 * Defines
 * ----------------------------------------------------------------------------
 */

/* algortithm to be used for HMAC op in HWKM */
#define HWKM_HMAC_ALG               SHA256_HMAC

/* algortithm to be used for crypto op in HWKM */
#define HWKM_CRYPTO_ALG             AES256_GCM

/* algortithm to be used for HMAC op in UCLIB */
#define UCLIB_HMAC_ALG              UCLIB_SHA2_256

/* algortithm to be used for crypto op in HWKM */
#define UCLIB_CRYPTO_ALG            UCLIB_AES256

/* mode of algortithm to be used for ccrpto op in UCLIB */
#define UCLIB_CRYPTO_ALG_MODE       UCLIB_GCM

/* Tag size in bytes for AES256-GCM */
#define TAG_SIZE_IN_BYTES           0x10U

/* Nonce size in bytes for AES256-GCM */
#define NONCE_SIZE_IN_BYTES         0xCU

/* HMAC digest size */
#define HMAC_DIGEST_SIZE            0x20U

/* ----------------------------------------------------------------------------
 * Crypto Parameters
 * ----------------------------------------------------------------------------
 */

/* statically defined addtional authenticated data, acts as parameter for AES256-GCM */
static uint8_t aad[] = 
{
    0x71, 0x82, 0xa0, 0x5b, 0xe4, 0xb4, 0x61, 0x18, 0xe1, 0x9e, 0xd0, 0xda,
};


#endif /* SECURE_STORAGE_EL2_CRYPTO_CFG_H */
