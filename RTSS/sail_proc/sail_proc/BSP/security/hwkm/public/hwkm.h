/*===========================================================================
  Copyright (c) 2022 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ===========================================================================*/

#ifndef HWKM_H
#define HWKM_H

#include "hwkm_defs.h"
#include "types.h"

typedef void* HWKM_HANDLE;

/* Opcodes to be set in the op field of a command */
typedef enum
{
  NIST_KEYGEN = 0,    /* Opcode to generate a random key */
  SYSTEM_KDF,         /* Opcode to derive a key */
  QFPROM_KEY_RDWR,    /* Used only by HW */
  KEY_WRAP_EXPORT,    /* Opcode to wrap a key and export the wrapped key */
  KEY_UNWRAP_IMPORT,  /* Opcode to import a wrapped key and unwrap it in the specified key slot */
  KEY_SLOT_CLEAR,     /* Opcode to clear a slot */
  KEY_SLOT_RDWR,      /* Opcode to read or write a key from/to a slot */
  SET_TPKEY,          /* Opcode to broadcast a TPKEY to all slaves configured to receive a TPKEY */

  HWKM_MAX_OP,

  HWKM_UNDEF_OP = 0xFF
} hwkm_op_t;

typedef struct
{
  uint32 ipcat_version;
  uint32 key_policy_version;
  uint32 key_table_size;
  boolean tpkey_ready;
  uint8 tpkey_slot;
  boolean bist_failed;
  boolean bist_done;
} hwkm_info_t;

typedef struct
{
  boolean km_by_spu_allowed;
  boolean km_by_modem_allowed;
  boolean km_by_nsec_allowed;
  boolean km_by_tz_allowed;

  hwkm_alg_t alg_allowed;

  boolean enc_allowed;
  boolean dec_allowed;

  hwkm_type_t key_type;
  uint8 kdf_depth;

  boolean wrap_export_allowed;
  boolean swap_export_allowed;

  hwkm_security_level_t security_lvl;

  hwkm_destination_t hw_destination;

  boolean wrap_with_tpk_allowed;
} hwkm_key_policy_t;

typedef struct
{
  boolean enabled;
  boolean km_key_policy_ver_en;
  boolean km_apps_secure_en;
  boolean km_msa_secure_en;
  boolean km_lcm_fuse_en;
  boolean km_boot_stage_otp_en;
  boolean km_swc_en;
  boolean km_child_key_policy_en;
  boolean km_mks_en;
  uint64 km_fuse_region_sha_digest_en;
  boolean km_oem_id_en;
  boolean km_pkhash_en;
  boolean km_oem_product_id_en;
  boolean km_oem_product_seed_en;
} hwkm_bsve_t;

typedef struct
{
  uint8 dks;                          /* Destination Key Slot */
  hwkm_key_policy_t policy;           /* Key policy */
} hwkm_keygen_cmd_t;

typedef struct
{
  uint8 slot;                         /* Key Slot */
  boolean is_write;                   /* Whether this is a write or read op */
  hwkm_key_policy_t policy;           /* Key policy. Needed for is_write = true */
  uint8 key[HWKM_MAX_KEY_SIZE];       /* Key. Needed for is_write = true */
  size_t sz;                          /* Length of key in bytes. Needed for is_write = true */
} hwkm_rdwr_cmd_t;

typedef struct
{
  uint8 dks;                          /* Destination Key Slot */
  uint8 kdk;                          /* Key Derivation Key Slot */
  uint8 mks;                          /* Mixing key slot. Only used if bsve.km_mks_en == true */
  hwkm_key_policy_t policy;           /* Key policy. */
  hwkm_bsve_t bsve;                   /* Binding state vector */
  uint8 ctx[HWKM_MAX_CTX_SIZE];       /* Context */
  size_t sz;                          /* Length of context in bytes */
  hwkm_alg_t parent_alg;              /* Underlying KDF algorithm (required for TME) */
} hwkm_kdf_cmd_t;

typedef struct
{
  uint8 sks;                        /* The slot to use as the TPKEY */
} hwkm_set_tpkey_cmd_t;

typedef struct
{
  uint8 dks;                        /* Destination Key Slot */
  uint8 kwk;                        /* Key Wrapping Key Slot */
  uint8 wkb[HWKM_MAX_BLOB_SIZE];    /* Wrapped Key Blob */
  uint8 sz;                         /* Length of WKB in bytes */
} hwkm_unwrap_cmd_t;

typedef struct
{
  uint8 sks;                        /* Destination Key Slot */
  uint8 kwk;                        /* Key Wrapping Key Slot */
  hwkm_bsve_t bsve;                 /* Binding state vector */
} hwkm_wrap_cmd_t;

typedef struct
{
  uint8 dks;                        /* Destination key slot */
  boolean is_double_key;            /* Whether this is a double key */
} hwkm_clear_cmd_t;

typedef struct
{
  hwkm_op_t op; /* Operation */

  union /* Structs with opcode specific parameters */
  {
    hwkm_keygen_cmd_t keygen;
    hwkm_rdwr_cmd_t rdwr;
    hwkm_kdf_cmd_t kdf;
    hwkm_set_tpkey_cmd_t set_tpkey;
    hwkm_unwrap_cmd_t unwrap;
    hwkm_wrap_cmd_t wrap;
    hwkm_clear_cmd_t clear;
  };
} hwkm_cmd_t;

typedef struct
{
  hwkm_key_policy_t policy;         /* Key policy. Only available for read operations */
  uint8 key[HWKM_MAX_KEY_SIZE];     /* Only available for read operations */
  size_t sz;                        /* Length of the key (bytes) */
} hwkm_rdwr_rsp_t;

typedef struct
{
  uint8 wkb[HWKM_MAX_BLOB_SIZE];    /* Wrapping key blob */
  size_t sz;                        /* Length of the key blob (bytes) */
} hwkm_wrap_rsp_t;

typedef struct
{
  uint32 status;

  union /* Structs with opcode specific outputs */
  {
    hwkm_rdwr_rsp_t rdwr;
    hwkm_wrap_rsp_t wrap;
  };
} hwkm_rsp_t;

/* These key slots are laid out in figure 3-4 of the CE HPG */
typedef enum
{
  /* Default slot to use for TPKEY */
  CRYPTO_DEFAULT_TPKEY = 0x3E,
  CRYPTO_DEFAULT_TPKEY_SECOND_SLOT = 0x3F,

  /** First key slot available for general purpose use cases */
  CRYPTO_GENERIC_SLOTS_START,
  /** Last key slot available for general purpose use cases */
  CRYPTO_GENERIC_SLOTS_END = 0x9F
} hwkm_gpce_key_slots_t;

/**
 * @brief Creates a context for HWKM operation and returns a
 *        handle to the caller. It is the caller responsiblity
 *        to call hwkm_free() to properly clean up
 *        HWKM context and release the resources.
 *
 * @return Non zero value if successful.
 */
HWKM_HANDLE hwkm_new(void);

/**
 * @brief Clears HWKM context and releases internal resources.
 *
 * @param h      [in] handle to the HWKM context
 */
void hwkm_free(HWKM_HANDLE h);

/**
 * @brief Initializes HWKM context in order to access an specific
 *        HWKM instance in SOC.
 *
 * @param h       [in] handle to the HWKM context
 * @param dest    [in] HWKM instance to use in this context
 *
 * @return HWKM_SUCCESS if successful. HWKM Error Code otherwise.
 */
status_t hwkm_init(HWKM_HANDLE h, hwkm_destination_t dest);

/**
 * @brief Add a new request to the list of CMD/RSP pair of
 *        the HWKM context.
 *
 * @param h       [in]  handle to the HWKM context
 * @param cmd     [in]  Pointer to CMD descriptor
 * @param rsp     [in]  Pointer to RSP descriptor
 *
 * @return HWKM_SUCCESS if successful. HWKM Error Code otherwise.
 */
status_t hwkm_add_req(HWKM_HANDLE h, hwkm_cmd_t* cmd, hwkm_rsp_t* rsp);

/**
 * @brief Get information about KM instance handled in this context
 *
 * @param h       [in]  handle to the HWKM context
 * @param info    [out] info about HWKM (versioning, key table size)
 *
 * @return HWKM_SUCCESS if successful. HWKM Error Code otherwise.
 */
status_t hwkm_get_info(HWKM_HANDLE h, hwkm_info_t* info);

/**
 * @brief Run queued commands. Commands will be executed in the
 *        order that they are recieved through hwkm_add_req() API.
 *        If a command causes a HW error, an error will be returned
 *        and the queue will be cleared. Otherwise the response's status
 *        field should be checked to see if the command succeeded.
 *
 * @param h       [in] handle to the HWKM context
 *
 * @return HWKM_SUCCESS if successful. HWKM Error Code otherwise.
 */
status_t hwkm_run_cmds(HWKM_HANDLE h);

/**
 * @brief Release HW resources held by the handle. This API is intended
 *        to allow a client to vote to turn clocks off without freeing
 *        their handle.
 *
 * @param h       [in] handle to the HWKM context
 *
 * @return HWKM_SUCCESS if successful. HWKM Error Code otherwise.
 */
status_t hwkm_deinit(HWKM_HANDLE h);

/**
 * @brief Extract the policy for a key from a wrapped key blob
 *
 * @param wkb      [in]  pointer to the wrapped key blob
 * @param wkb_size [in]  size of the wrapped key blob in bytes
 * @param policy   [out] policy extracted from wkb
 *
 * @return HWKM_SUCCESS if successful. HWKM Error Code otherwise.
 */
status_t hwkm_extract_policy(const uint8* wkb, size_t wkb_size, hwkm_key_policy_t* policy);

/**
 * @brief Do HWKM operations before system shutdown
 *
 * @param void
 *
 * @return HWKM_SUCCESS if successful. HWKM Error Code otherwise.
 */
status_t hwkm_shutdown(void);

#endif /* HWKM_H */
