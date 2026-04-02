/*===========================================================================
  Copyright (c) 2021 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ===========================================================================*/

#ifndef HWKM_DEFS_H
#define HWKM_DEFS_H

#define HWKM_MAX_KEY_SIZE UINT32_C(32)    /* Maximum number of bytes in a key used in a KEY_SLOT_RDWR operation */
#define HWKM_MAX_CTX_SIZE UINT32_C(64)    /* Maximum number of bytes in a SW ctx used in a SYSTEM_KDF operation */
#define HWKM_MAX_BLOB_SIZE UINT32_C(68)   /* Maximum number of bytes in a WKB used in a key wrap or unwrap operation */

/* Algorithm values which can be used in the alg_allowed field of the key policy */
typedef enum
{
  AES128_ECB = 0,
  AES256_ECB = 1,
  DES_ECB = 2,
  TDES_ECB = 3,
  AES128_CBC = 4,
  AES256_CBC = 5,
  DES_CBC = 6,
  TDES_CBC = 7,
  AES128_CCM_TC = 8,
  AES128_CCM_NTC = 9,
  AES256_CCM_TC = 10,
  AES256_CCM_NTC = 11,
  AES256_SIV = 12,
  AES128_CTR = 13,
  AES256_CTR = 14,
  AES128_XTS = 15,
  AES256_XTS = 16,
  SHA1_HMAC = 17,
  SHA256_HMAC = 18,
  AES128_CMAC = 19,
  AES256_CMAC = 20,
  SHA384_HMAC = 21,
  SHA512_HMAC = 22,
  AES128_GCM = 23,
  AES256_GCM = 24,
  KASUMI = 25,
  SNOW3G = 26,
  ZUC = 27,
  PRINCE = 28,
  SIPHASH = 29,
  QARMA64 = 30,
  QARMA128 = 31,

  HWKM_ALG_MAX,

  HWKM_UNDEF_ALG = 0xFF
} hwkm_alg_t;

/* When clients set alg as KDF_NIST on v1, we will use AES_CMAC */
#define KDF_NIST AES256_CMAC

/* Key type values which can be used in the key_type field of the key policy */
typedef enum
{
  KEY_DERIVATION_KEY = 0,
  KEY_WRAPPING_KEY = 1,
  KEY_SWAPPING_KEY = 2,
  TRANSPORT_KEY = 3,
  GENERIC_KEY = 4,

  HWKM_TYPE_MAX,

  HWKM_UNDEF_KEY_TYPE = 0xFF
} hwkm_type_t;

/* Destinations which a context can use */
typedef enum
{
  HWKM_DESTINATION_START = 0,
  KM_MASTER = HWKM_DESTINATION_START,
  GPCE_SLAVE = 1,
  HWKM_DESTINATION_MAX,

  HWKM_UNDEF_DESTINATION = 0xFF
} hwkm_destination_t;

/* Key security levels which can be set in the security_lvl field of key policy */
typedef enum
{
  SW_KEY = 0,      /* Can be read by SW in plaintext using KEY_SLOT_RDWR cmd. */
  MANAGED_KEY = 1, /* Imported key managed by HW. */
  HW_KEY = 2,      /* Key only known to HW. */

  HWKM_SECURITY_LEVEL_MAX,

  HWKM_UNDEF_SECURITY_LEVEL = 0xFF
} hwkm_security_level_t;

typedef enum
{
  /** L1 KDKs. Not usable by SW. Used by HW to derive L2 KDKs */
  NKDK_L1 = 0,
  PKDK_L1 = 1,
  SKDK_L1 = 2,
  UKDK_L1 = 3,

  /** L2 KDKs, used to derive keys by SW. Cannot be used for crypto, only key derivation */
  TZ_NKDK_L2 = 4,
  TZ_PKDK_L2 = 5,
  TZ_SKDK_L2 = 6,
  MODEM_PKDK_L2 = 7,
  MODEM_SKDK_L2 = 8,
  TZ_UKDK_L2 = 9,

  /** Slots reserved for TPKEY */
  TPKEY_SLOT = 10,
  TPKEY_KEY_ODD_SLOT = 11,

  /** Slots reserved for Swap key */
  TZ_SWAP_KEY_SLOT = 12,
  TZ_SWAP_KEY_ODD_SLOT = 13,

  /** Reserved for wrapping keys to persist or unwrap keys */
  TZ_WRAP_KEY_SLOT = 14,
  TZ_WRAP_KEY_ODD_SLOT = 15,

  /** Reserved for intermediate operations in IHWKeyFactory */
  TZ_GENERAL_PURPOSE_SLOT1 = 16,
  TZ_GENERAL_PURPOSE_SLOT2 = 17,

  /** Reserved for mixing keys in KDF */
  TZ_MIXING_KEY_SLOT = 22,

  MASTER_SLOT_MAX = 60,

  UNDEF_SLOT = 0xFF,

} hwkm_master_key_slots_t;

#endif /* HWKM_DEFS_H */
