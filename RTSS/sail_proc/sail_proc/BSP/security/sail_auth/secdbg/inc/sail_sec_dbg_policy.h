/* ============================================================================
 * @file  sail_sec_dbg_policy.h
 * @brief provides APIs to apply SAIL debug policy.
 *
 * Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SAIL_SEC_DBG_POLICY_H
#define SAIL_SEC_DBG_POLICY_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */
#include <stdbool.h>
#include "types.h"
#include "secboot_chipset.h"

/* ----------------------------------------------------------------------------
 * Defines
 * ----------------------------------------------------------------------------
 */
/* The number of certificates that can be tried for testing/engineering */
#define SECDBG_CERT_ARRAY_SIZE                      4U

/* Serial numbers minimum count value */
#define SECDBG_SERIAL_NUM_MIN_COUNT                 0

/* Unique serial numbers that are allowed */
#define SECDBG_SERIAL_NUM_MAX_COUNT                 200

/* ----------------------------------------------------------------------------
 * Enum & Structure
 * ----------------------------------------------------------------------------
 */
/* Error status codes */
typedef enum secdbg_error_type_t
{
  SECDBG_STATUS_SUCCESS = 0x0,
  SECDBG_STATUS_FAILURE = 0x101,
  SECDBG_STATUS_INVALID_ARG = 0x102,
  SECDBG_STATUS_OUT_OF_RANGE = 0x103,
  SECDBG_STATUS_HASH_IMAGE_ID_MISMATCH = 0x104,
  SECDBG_STATUS_INVALID_SIZE= 0x105,
  SECDBG_STATUS_NO_MEMORY = 0x106,
  SECDBG_STATUS_INVALID_REVISION_NUMBER = 0x107,
  SECDBG_STATUS_INVALID_COUNT = 0x108,
  SECDBG_STATUS_INVALID_RESERVED_BITS= 0x109,
  SECDBG_STATUS_HASH_ARRAY_COUNT_INVALID = 0x10A,
  SECDBG_STATUS_SERIAL_NUM_READ_ERROR= 0x10B,
  SECDBG_STATUS_INCORRECT_HASH_TOTAL_LEN = 0x10C,
  SECDBG_STATUS_CORRUPTED_IMAGE = 0x10D,
  SECDBG_STATUS_INVALID_MAGIC = 0x10E,
  SECDBG_STATUS_DP_DISABLE_FUSE_SET  = 0x10F,
  SECDBG_SERIAL_NUM_NOT_FOUND = 0x110,
  SECDBG_STATUS_MAX = 0x7FFFFFFF /**< Force to 32 bits */
}secdbg_error_type;

/* The value of these flags must match the 'flags' element of secdbg_dp_t.
   Bit position 0, 4 to 8, 19 to 23, 25 to 30 are not applicable for SAIL Debug
   Policy, and Bit position 31 onwards are reserved for future use */
typedef enum secdbg_flag_type_t
{
  SECDBG_ENABLE_SAIL_SECURE_CRASH_DUMPS = 1,
  SECDBG_ENABLE_SAIL_JTAG_DEBUG = 2,
  SECDBG_ENABLE_SAIL_HYPERVISOR_LOGS = 3,
  SECDBG_ENABLE_SAIL_HYPERVISOR_JTAG_DEBUG = 9,
  SECDBG_ENABLE_SAIL_HYPERVISOR_TRACES = 10,
  SECDBG_ENABLE_SAIL_CORE_0_JTAG_DEBUG = 11,
  SECDBG_ENABLE_SAIL_CORE_0_TRACES = 12,
  SECDBG_ENABLE_SAIL_CORE_1_JTAG_DEBUG = 13,
  SECDBG_ENABLE_SAIL_CORE_1_TRACES = 14,
  SECDBG_ENABLE_SAIL_CORE_2_JTAG_DEBUG = 15,
  SECDBG_ENABLE_SAIL_CORE_2_TRACES = 16,
  SECDBG_ENABLE_SAIL_CORE_3_JTAG_DEBUG = 17,
  SECDBG_ENABLE_SAIL_CORE_3_TRACES = 18,
  SECDBG_ENABLE_SAIL_NONSECURE_CRASH_DUMPS = 24,
  SECDBG_FLAG_MAX = 64
} secdbg_flag_type;

/* QC or OEM Root */
typedef enum
{
  DBGP_OEM = 0,
  DBGP_QC
} secdbg_root_type;

/* Debug policy structure */
typedef struct __attribute__((__packed__))
{
        uint32_t magic; /* Version of Debug Policy */
        uint32_t size;  /* Fixed size debug policy*/
        uint32_t revision; /* Revision of the debug policy*/
        struct {
                uint32_t reserved_bits_with_serialnum_01    :  1; // reserved for QCT, must be 0
                uint32_t enable_sail_secure_crash_dumps     :  1;
                uint32_t enable_sail_jtag_debug             :  1;
                uint32_t enable_sail_hypervisor_logs        :  1;
                uint32_t reserved_bits_with_serialnum_02    :  5; // reserved for QCT, must be 0
                uint32_t enable_sail_hypervisor_jtag_debug  :  1;
                uint32_t enable_sail_hypervisor_traces      :  1;
                uint32_t enable_sail_core_0_jtag_debug      :  1;
                uint32_t enable_sail_core_0_traces          :  1;
                uint32_t enable_sail_core_1_jtag_debug      :  1;
                uint32_t enable_sail_core_1_traces          :  1;
                uint32_t enable_sail_core_2_jtag_debug      :  1;
                uint32_t enable_sail_core_2_traces          :  1;
                uint32_t enable_sail_core_3_jtag_debug      :  1;
                uint32_t enable_sail_core_3_traces          :  1;
                uint32_t reserved_bits_with_serialnum_03    :  5; // reserved for QCT, must be 0
                uint32_t enable_sail_nonsecure_crash_dumps  :  1;
                uint32_t reserved_bits_without_serialnum_01 :  7; // reserved for QCT, must be 0
                uint32_t reserved_bits_without_serialnum_02 : 16; // reserved for QCT, must be 0
                uint32_t oem_reserved_bits                  : 16; // reserved for OEM
        } flags;
        uint32_t image_id_bitmap; /* Image ID Bit Map */
        uint32_t root_cert_hash_count; /* Root Cert Hash Count */
        uint8_t  root_cert_hash_array[SECDBG_CERT_ARRAY_SIZE][SECBOOT_OTP_ROOT_OF_TRUST_BYTE_SIZE]; /* Hash Array*/
        int32_t serial_num_count; /* Serial Number Count */
        uint32_t serial_num_array[SECDBG_SERIAL_NUM_MAX_COUNT]; /* Serial Numbers */
        uint32_t root_cert_hash_count_qc; /* Root Cert Hash Count */
        uint8_t  root_cert_hash_array_qc[SECDBG_CERT_ARRAY_SIZE][SECBOOT_OTP_ROOT_OF_TRUST_BYTE_SIZE]; /* Hash Array*/
} secdbg_dp_t;

/* ----------------------------------------------------------------------------
 * Public API's (but only for secure boot module to use, internal to security)
 * ----------------------------------------------------------------------------
 */
/**
 * @brief Check if authentication allowed using Debug Policy QC Root.
 */
bool secdbg_is_auth_using_dp_qc_root(void);

/**
 * @brief Get number of roots from debug policy (oem/qc).
 */
size_t secdbg_get_num_roots(secdbg_root_type root_type);

/**
 * @brief Get root from debug policy (oem/qc).
 *
 * @param[in]  root_type (oem/qc)
 * @param[in]  idx: root_index 
 * @param[out] size: root_size
 * @retval     pointer to the root
 */
uint8_t * secdbg_get_root( secdbg_root_type root_type,
                           size_t idx,
                           size_t *size );

/* ----------------------------------------------------------------------------
 * Public API's
 * ----------------------------------------------------------------------------
 */
/**
 * @brief Debug Policy Verification and Apply.
 */
secdbg_error_type secdbg_dp_verify_and_apply(uintptr_t dp_addr, size_t dp_size);

/**
 * @brief Check if particular flag is enabled in debug policy.
 *
 * @param[in] flag Debug policy flag
 * @return    TRUE if the flag is enabled, FALSE otherwise
 */
bool secdbg_dp_is_flag_enabled(secdbg_flag_type flag);

/**
 * @brief Check if all debug (JTAG, Logs & Traces) enabled.
 */
bool secdbg_dp_is_all_debug_enabled(void);

/**
 * @brief Check if debug disabled.
 */
bool secdbg_dp_is_debug_disabled(void);

#endif /* SAIL_SEC_DBG_POLICY_H */
