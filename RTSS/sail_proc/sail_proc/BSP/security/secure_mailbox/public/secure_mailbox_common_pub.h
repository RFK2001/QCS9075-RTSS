/*=========================================================================
FILE: SECURE_MAILBOX_common_pub.h
OVERVIEW: This header file contains macros and enums to be used by EL1 and EL2 clients

Copyright (c) 2023 Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Technologies Inc. Confidential and Proprietary
=========================================================================*/

#ifndef SECURE_MAILBOX_COMMON_PUB_H
#define SECURE_MAILBOX_COMMON_PUB_H


/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */

#include <types.h>
#include "secure_mailboxlib_utils.h"

#define    NONCE_LENGTH    12U
#define    TAG_LENGTH      16U

/* ----------------------------------------------------------------------------
 * Enums
 * ----------------------------------------------------------------------------
 */

/* Secure mailbox client IDs, to be used to identify clients */
/* allowed to use secure mailbox */
typedef enum
{
    FIRST_CLIENT_ID = 0U,
    SECURE_MAILBOX_CLIENT_SECURE_STORAGE = 1U, /* Used by Secure storage */
    SECURE_MAILBOX_CLIENT_MAX_NUM
} ClientUID;

/* ----------------------------------------------------------------------------
 * Error codes
 * ----------------------------------------------------------------------------
 */
typedef enum{
/* Success */ 
E_SECURE_MAILBOX_SUCCESS = 0U,                   /* 0 */

/* Generic Failure */
E_SECURE_MAILBOX_ERROR,                          /* 1 */

/* Invalid arguments passed */
E_SECURE_MAILBOX_PARAM_INVALID,                  /* 2 */

/* Client not allowed to use secure storage */
E_SECURE_MAILBOX_CLIENT_DOES_NOT_EXIST,          /* 3 */

/* Client allowed to use secure storage */
E_SECURE_MAILBOX_CLIENT_EXISTS,                  /* 4 */

/* Client allowed already in use */
E_SECURE_MAILBOX_CLIENT_ALREADY_IN_USE,          /* 5 */

/* Secure mailbox not initialized */
E_SECURE_MAILBOX_SECURE_MAILBOX_NOT_INITED,      /* 6 */

/* Secure mailbox already initialized */
E_SECURE_MAILBOX_SECURE_MAILBOX_IS_INITED,       /* 7 */

/* Invalid passed structure */
E_SECURE_MAILBOX_INVALID_STRUCTURE,              /* 9 */

/* Out of memory/other resources */
E_SECURE_MAILBOX_OUT_OF_RESOURCES,               /* 10 */

/* Trying to access memory out of range */
E_SECURE_MAILBOX_ACCESS_OUT_RANGE,               /* 11 */

/* HVC failed */
E_SECURE_MAILBOX_HVC_FAILED,                     /* 12 */

/* SPINOR operation failed */
E_SECURE_MAILBOX_SPINOR_OPERATION_FAILED,        /* 13 */

/* Access not aligned */
E_SECURE_MAILBOX_UNALIGNED_ACCESS,               /* 14 */

/* PRNG related failure */
E_SECURE_MAILBOX_PRNG_FAILURE,                    /* 15 */

/* HWKM related failure */
E_SECURE_MAILBOX_HWKM_FAILURE,                    /* 16 */

/* UCLIB(GPCE) related failure */
E_SECURE_MAILBOX_UCLIB_FAILURE                    /* 16 */

} SECURE_MAILBOX_STATUS;

/* Different statuses for secure mailbox init */
typedef enum
{
    SECURE_MAILBOX_INIT_NOT_DONE = 0U,
    SECURE_MAILBOX_INIT_DONE,
    SECURE_MAILBOX_INIT_INVALID,
    SECURE_MAILBOX_INIT_MAX_STATUS
} SecureMailboxInitStatus;

/* ----------------------------------------------------------------------------
 * Structure defination
 * ----------------------------------------------------------------------------
 */

struct counterIV_s {
    uint8_t         ctr[NONCE_LENGTH];
}__attribute__((packed,aligned(16)));
typedef struct counterIV_s counterIV_t;

struct clientIdList_s {
	/** All client added here, provided by client at registering code */
	ClientUID         cuid[SECURE_MAILBOX_CLIENT_MAX_NUM];
	/** Number of client-ID registered */
	uint8_t           numClientId;
}__attribute__((packed,aligned(16)));
typedef struct clientIdList_s clientIdList_t;

struct ClientUIDCtr_s {
	ClientUID      cuid;	/** all client added here, provided by client at registering code */
	counterIV_t    rCtr;	/** Read counter */
	counterIV_t    tCtr;	/** Write counter*/
}__attribute__((packed,aligned(16)));
typedef struct ClientUIDCtr_s ClientUIDCtr_t;

struct clientIdRspList_s {
	ClientUIDCtr_t	cuid[SECURE_MAILBOX_CLIENT_MAX_NUM];	/** all client added here, provided by client at registering code */
	uint8_t numClientId;	/** Number of client-ID registered */
}__attribute__((packed,aligned(16)));
typedef struct clientIdRspList_s clientIdRspList_t ;

struct keyExchangeEncryptedData_s {
    /** Cipher Algorithm       */
    //UCLIB_CIPHER_ALG      alg;
    /** Cipher Mode            */
    //UCLIB_CIPHER_MODE     mode;
    /** Acceleration Engine    */
    //UCLIB_ENGINE_TYPE     engine;
    /** Padding type           */
    //UCLIB_CIPHER_PAD      pad_type;
    const uint8_t           *aad;
    const uintptr_t         aad_len;
    clientIdRspList_t     encryptedClientIdRspList;
    uint8_t               authTag[TAG_LENGTH];
}__attribute__((packed,aligned(16)));
typedef struct keyExchangeEncryptedData_s keyExchangeEncryptedData_t;

/* ----------------------------------------------------------------------------
 * For SAIL to TZ key-exchange call
 * ----------------------------------------------------------------------------
 */
struct sailtzSecureMailboxKeyExchange_s {
    /** to be generated by SAIL-SMB-EL2*/
    uint8_t                 sailNonce[NONCE_LENGTH];
    /** List of client id authorized to use SMB */
    clientIdList_t          clientIdList;
}__attribute__((packed,aligned(16)));
typedef struct sailtzSecureMailboxKeyExchange_s sailtzSecureMailboxKeyExchange_t;

/* ----------------------------------------------------------------------------
 * For TZ to SAIL key-exchange call
 * ----------------------------------------------------------------------------
 */
struct tzSailSecureMailboxKeyExchange_s {
    uint8_t         tzNonce[NONCE_LENGTH];
    /** Encrypted data passed from TZ */
    /** List of client id authorized to use SMB,*/
    /** with read/write counter value for each */
    keyExchangeEncryptedData_t      keyExchangeEncryptedData;
}__attribute__((packed,aligned(16)));
typedef struct tzSailSecureMailboxKeyExchange_s tzSailSecureMailboxKeyExchange_t;

#endif /* SECURE_MAILBOX_COMMON_PUB_H */