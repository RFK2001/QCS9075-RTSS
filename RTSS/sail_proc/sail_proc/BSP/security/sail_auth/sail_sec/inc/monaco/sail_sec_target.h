/* ============================================================================
 * @file  sail_sec_target.h
 *
 * Copyright (c) Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef _SAIL_SEC_TARGET_H
#define _SAIL_SEC_TARGET_H

#include "target_linker_map.h"

#define SAIL_SEC_IMG_WHITELIST_LEN       (20)
 
#define SAIL_SECDBG_POLICY_BASE          MANDATORY_DBG_POLICY_LR1_START /* Sail debug policy start */
#define SAIL_SECDBG_POLICY_SIZE          MANDATORY_DBG_POLICY_LR1_SIZE /* Sail debug policy size */

/* Reserving for OEM and QTI MISC image */
#define SAIL_SEC_OEM_MISC_SIZE           0 /* Not used */
#define SAIL_SEC_QTI_MISC_SIZE           0 /* Not used */
#define SAIL_SEC_OEM_MISC_ADDR           0 /* Not used */
#define SAIL_SEC_QTI_MISC_ADDR           0 /* Not used */

/* Revision number of debug policy */
#define SAIL_SECDBG_REVISION_NUMBER         7

#endif /* _SAIL_SEC_TARGET_H */
