/*=========================================================================
FILE: secure_mailbox_el2_pub.h
OVERVIEW: This header file contains APIs and macros to be used by EL2 clients

Copyright (c) 2023 Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Technologies Inc. Confidential and Proprietary
=========================================================================*/
#ifndef SECURE_MAILBOX_EL2_PUB_H
#define SECURE_MAILBOX_EL2_PUB_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */

#include "secure_mailbox_common_pub.h"

/* ----------------------------------------------------------------------------
 * Structures
 * ----------------------------------------------------------------------------
 */
struct customCipherPlaintext_s{
     /** Magic to identify if decryption is done using proper key, */
     /** is the firstblock of plaintext */
     /** this should be all 0xcd of block size */
//    uint8_t	           magic[AES_256_BLOCK_SIZE];
    uint8_t	           *originalCipherPlaintext;
    uint32_t           originalCipherPlaintextLength;
    counterIV_t        iv;
    uint8_t            *aad;
    uint32_t           aad_len;
 	uint8_t            valid;
 } __attribute__((packed,aligned(16)));
typedef struct customCipherPlaintext_s customCipherPlaintext_t;

struct sailSecureMailboxEncryptDecrypt_s {
    ClientUID                  cuid;
    uint8_t                    encrypt;
    customCipherPlaintext_t    customCipherPlaintext;
    uint8_t                    tag[16];
} __attribute__((packed,aligned(16)));
typedef struct sailSecureMailboxEncryptDecrypt_s sailSecureMailboxEncryptDecrypt_t;

/* ----------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------
 */
/* =========================================================================
**  Function : secureMailboxEL2Encrypt
** =========================================================================*/
/**
  @brief reads and validates the main partition header stored in buf and stores
         it in a global variable

  @param buf        [in]    stores the complete data related to encrypting data including plaintext
  @param bufSize    [in]    size of buf
  @param initStatus [out]   status of secure mailbox initialization

  @return E_SECURE_MAILBOX_SUCCESS if initStatus is updated, Secure Mailbox error code otherwise.
*/
SECURE_MAILBOX_STATUS secureMailboxEL2Encrypt
(
  void*     buff,
  size_t    bufSize,
  uint32_t *initStatus
);

/* =========================================================================
**  Function : secureMailboxEL2Decrypt
** =========================================================================*/
/**
  @brief reads and validates the main partition header stored in buf and stores
         it in a global variable

  @param buf        [in]    stores the complete data related to decrypting data including ciphertext
  @param bufSize    [in]    size of buf
  @param initStatus [out]   status of secure mailbox initialization

  @return E_SECURE_MAILBOX_SUCCESS if initStatus is updated, Secure Mailbox error code otherwise.
*/
SECURE_MAILBOX_STATUS secureMailboxEL2Decrypt
(
  void*     buff,
  size_t    bufSize,
  uint32_t *initStatus
);
#endif /* SECURE_MAILBOX_EL2_PUB_H */
