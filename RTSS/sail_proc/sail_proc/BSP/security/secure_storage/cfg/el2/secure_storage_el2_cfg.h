/*=========================================================================
FILE: secure_storage_el2_cfg.h
OVERVIEW: Defines all the configuration for secure storage EL2

Copyright (c) Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Technologies Inc. Confidential and Proprietary
=========================================================================*/
#ifndef SECURE_STORAGE_EL2_CFG_H
#define SECURE_STORAGE_EL2_CFG_H

#include "types.h"

/* ----------------------------------------------------------------------------
 * Defines
 * ----------------------------------------------------------------------------
 */

/* To scramble the pointer */
#define ENV_SCRAMBLE(n, msk) ((uintptr_t)(n) ^ (uintptr_t)(msk))

/* To unscramble the pointer */
#define ENV_UNSCRAMBLE(n, msk) ((uintptr_t)(n) ^ (uintptr_t)(msk))

/* For Morphing */
#define MASK_VAL                                0x312542UL

/* Main partition table identifier */
#define MAIN_PARTITION_HEADER_IDENTIFIER        0xAF00AF00UL

/* Main partition table version */
#define MAIN_PARTITION_HEADER_INIT_VERSION      0x01U

/* Value to identify that main partition table is created */
#define MAIN_PARTITION_HEADER_INIT_DONE_VAL     0x01U

/* No partition created at device init*/
#define NO_PARTITION                            0x00U

#endif /* SECURE_STRORAGE_EL2_CFG_H */
