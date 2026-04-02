/* ============================================================================
 * @file  secure_storage_cfg.h
 * @brief This header file contains configuration parameters for secure storage.
 *
 * Copyright (c) Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SECURE_STORAGE_CFG_H
#define SECURE_STORAGE_CFG_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */

#include <types.h>

/* ----------------------------------------------------------------------------
 * Configuration macros
 * ----------------------------------------------------------------------------
 */

/* No. of partitions supported by secure storage */
#define SECURE_STORAGE_MAX_CLIENT_PARTITION_NUM             20U

/* Maximum number of clients that can be supported, 2 partitions per client */
#define SECURE_STORAGE_MAX_NUM_CLIENT_SUPPORTED             10U

/* 1 block = 4096 bytes */
#define SECURE_STORAGE_BLOCK_SIZE                           0x1000U

/* Total size of non volatile memory */
#define SECURE_STORAGE_PARTITION_SIZE                       0x100000UL

/* Number of blocks reserved for main partition header */
#define SECURE_STORAGE_BLOCKS_RESERVED_FOR_MPH              2U

/* Length of client partition name */
#define SECURE_STORAGE_CLIENT_PARTITION_NAME_LENGTH         8U

/* GUID for secure storage in non volatile memory */
#define SECURE_STORAGE_PARTITION_GUID                       "c6fba11c-3562-4e87-b0f6-baae13c8eb21"

/* Offset value to write main partition table into non volatile memory */
#define SECURE_STORAGE_PRIMARY_MPH_OFFSET                   0x0U

/* Offset value to write redundant main partition table into non volatile memory */
#define SECURE_STORAGE_SECONDARY_MPH_OFFSET                 SECURE_STORAGE_PARTITION_SIZE - SECURE_STORAGE_BLOCK_SIZE

/* Flag to disable ARB */
//#define SECURE_STORAGE_DISABLE_ARB

/* Flag to disable crypto operations */
//#define SECURE_STORAGE_DISABLE_CRYPTO

/* Flag to enable test mode */
//#define SECURE_STORAGE_ENABLE_TEST_MODE

#endif /* SECURE_STORAGE_CFG_H */