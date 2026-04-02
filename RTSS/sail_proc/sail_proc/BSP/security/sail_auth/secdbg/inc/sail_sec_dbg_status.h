/* ============================================================================
 * @file  sail_sec_dbg_status.h
 * @brief provides APIs to check debug info of sail.
 *
 * Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SAIL_SEC_DBG_STATUS_H
#define SAIL_SEC_DBG_STATUS_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */
#include <stdbool.h>
#include "types.h"

/* ----------------------------------------------------------------------------
 * Public API's ( Only for debug policy use, please use debug policy header for 
 *                 outside debug policy module or external use )
 * ----------------------------------------------------------------------------
 */
/**
 * @brief Check debug policy disable fuse bit. 
 *        Debug policy is bypassed when this bit is 1.
 * 
 * @return  0x0: ENABLE - Debug Policy Enabled
 *          0x1: DISABLE - Debug Policy Disabled
 */
bool secdbg_is_dbg_policy_disabled(void);

/**
 * @brief Read debug status of all debug control bits.
 */
uint32_t secdbg_read_debug_fuse_status(void);

/**
 * @brief Enable HYP invasive/non-invasive debug for EL2.
 */
void secdbg_enable_hyp_inv_debug(void);
void secdbg_enable_hyp_ni_debug(void);

/**
 * @brief Enable C0-C3 invasive/non-invasive debug for EL0/1.
 */
void secdbg_enable_c0_inv_debug(void);
void secdbg_enable_c0_ni_debug(void);
void secdbg_enable_c1_inv_debug(void);
void secdbg_enable_c1_ni_debug(void);
void secdbg_enable_c2_inv_debug(void);
void secdbg_enable_c2_ni_debug(void);
void secdbg_enable_c3_inv_debug(void);
void secdbg_enable_c3_ni_debug(void);

/**
 * @brief Enable APB scan dump of CPU cores.
 */
void secdbg_enable_cpu_scan(void);

/**
 * @brief Enable DCC functionality.
 */
void secdbg_enable_dcc(void);

/**
 * @brief Enable all debug (JTAG, Logs & Traces).
 */
void secdbg_enable_all_debug(void);

/**
 * @brief Blow all override fuses.
 * This is only one time possible and need to call while applying debug policy.
 */
void secdbg_blow_override_fuses(void);

/**
 * @brief Check if all debug (JTAG, Logs & Traces) enabled.
 */
bool secdbg_is_all_debug_enabled(void);

/**
 * @brief Check if debug disabled.
 *        Note: ns_disbaled is same as debug_disabled.
 *        Note: sec_disabled not required currently, can be implemented.
 */
bool secdbg_is_debug_disabled(void);

/**
 * @brief Check if HYP invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_hyp_inv_debug_enabled(void);

/**
 * @brief Check if HYP non-invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_hyp_ni_debug_enabled(void);

/**
 * @brief Check if C0 invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_c0_inv_debug_enabled(void);

/**
 * @brief Check if C0 non-invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_c0_ni_debug_enabled(void);

/**
 * @brief Check if C1 invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_c1_inv_debug_enabled(void);

/**
 * @brief Check if C1 non-invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_c1_ni_debug_enabled(void);

/**
 * @brief Check if C2 invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_c2_inv_debug_enabled(void);

/**
 * @brief Check if C2 non-invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_c2_ni_debug_enabled(void);

/**
 * @brief Check if C3 invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_c3_inv_debug_enabled(void);

/**
 * @brief Check if C3 non-invasive debug is enabled
 * @return TRUE if enabled, FALSE if not enabled
 *         (Note: FALSE dosen't mean disabled)
 */
bool secdbg_is_c3_ni_debug_enabled(void);

/**
 * @brief Read device serial number
 */
uint32_t secdbg_read_serial_num(void);

#endif /* SAIL_SEC_DBG_STATUS_H */