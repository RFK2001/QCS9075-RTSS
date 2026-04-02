/*=========================================================================
FILE: secure_storage_el2_arb_cfg.h
OVERVIEW: Defines all the configuration for ARB feature in secure storage

Copyright (c) Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Technologies Inc. Confidential and Proprietary
=========================================================================*/
#ifndef SECURE_STORAGE_EL2_ARB_CFG_H
#define SECURE_STORAGE_EL2_ARB_CFG_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */

#include "types.h"
#include "secure_storage_el2_types.h"
#include "secure_storage_cfg.h"
#include "sail_sec_hwio.h"
#include "HALhwio.h"

/* ----------------------------------------------------------------------------
 * Defines
 * ----------------------------------------------------------------------------
 */

/* Total ARB bits available */
#define TOTAL_ARB_BITS                          200U

/* ARB bits allocated for Client 0 */
#define NUM_ARB_BITS_CLIENT_0                   150U

/* Starting offset for ARB bits allocated for Client 0 */
#define START_OFFSET_ARB_BITS_CLIENT_0          0U

/* ARB bits allocated for Client 1 */
#define NUM_ARB_BITS_CLIENT_1                   50U

/* Starting offset for ARB bits allocated for Client 1 */
#define START_OFFSET_ARB_BITS_CLIENT_1          (START_OFFSET_ARB_BITS_CLIENT_0 + NUM_ARB_BITS_CLIENT_0)

#ifdef SECURE_STORAGE_ENABLE_TEST_MODE
/* ARB bits allocated for Test Client */
#define NUM_ARB_BITS_CLIENT_TEST                0U

/* Starting offset for ARB bits allocated for Client Test */
#define START_OFFSET_ARB_BITS_CLIENT_TEST       (START_OFFSET_ARB_BITS_CLIENT_1 + NUM_ARB_BITS_CLIENT_1)
#endif

#define FUSE_WORD_SIZE_IN_BITS                  32U

/* ----------------------------------------------------------------------------
 * Fuse info
 * ----------------------------------------------------------------------------
 */

#define SECURE_STORAGE_ARB_FUSE_0_RAW_ADDR      HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_7_LSB)
#define SECURE_STORAGE_ARB_FUSE_0_CORR_ADDR     HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_7_LSB)
#define SECURE_STORAGE_ARB_FUSE_1_RAW_ADDR      HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_8_LSB)
#define SECURE_STORAGE_ARB_FUSE_1_CORR_ADDR     HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_8_LSB)
#define SECURE_STORAGE_ARB_FUSE_2_RAW_ADDR      HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_9_LSB)
#define SECURE_STORAGE_ARB_FUSE_2_CORR_ADDR     HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_9_LSB)
#define SECURE_STORAGE_ARB_FUSE_3_RAW_ADDR      HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_10_LSB)
#define SECURE_STORAGE_ARB_FUSE_3_CORR_ADDR     HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_10_LSB)

/* ----------------------------------------------------------------------------
 * Configuration data
 * ----------------------------------------------------------------------------
 */

/* array storing ARB bits allocation for each client (sequence should be in increasing order) */
static const ClientARBBitsAlloc_t clientARBBitsAlloc[] = {
    {
        .clientID = SECURE_STORAGE_CLIENT_0,
        .startOffset = START_OFFSET_ARB_BITS_CLIENT_0,
        .numBitsAllocated = NUM_ARB_BITS_CLIENT_0
    },
    {
        .clientID = SECURE_STORAGE_CLIENT_1,
        .startOffset = START_OFFSET_ARB_BITS_CLIENT_1,
        .numBitsAllocated = NUM_ARB_BITS_CLIENT_1
    },
#ifdef SECURE_STORAGE_ENABLE_TEST_MODE
    {
        .clientID = SECURE_STORAGE_CLIENT_TEST,
        .startOffset = START_OFFSET_ARB_BITS_CLIENT_TEST,
        .numBitsAllocated = NUM_ARB_BITS_CLIENT_TEST
    }
#endif
};

/* array storing ARB fuse info (sequence should be in increasing order) */
static const ARBFuseInfo_t arbFuseInfo[] = {
    {
        .readAddress = SECURE_STORAGE_ARB_FUSE_0_CORR_ADDR,
        .writeAddress = SECURE_STORAGE_ARB_FUSE_0_RAW_ADDR,
        .startBit = 0U,
        .numBits = 64U,
    },
    {
        .readAddress = SECURE_STORAGE_ARB_FUSE_1_CORR_ADDR,
        .writeAddress = SECURE_STORAGE_ARB_FUSE_1_RAW_ADDR,
        .startBit = 0U,
        .numBits = 64U,
    },
    {
        .readAddress = SECURE_STORAGE_ARB_FUSE_2_CORR_ADDR,
        .writeAddress = SECURE_STORAGE_ARB_FUSE_2_RAW_ADDR,
        .startBit = 0U,
        .numBits = 64U,
    },
    {
        .readAddress = SECURE_STORAGE_ARB_FUSE_3_CORR_ADDR,
        .writeAddress = SECURE_STORAGE_ARB_FUSE_3_RAW_ADDR,
        .startBit = 0U,
        .numBits = 8U,
    },
};

#endif /* SECURE_STORAGE_EL2_ARB_CFG_H */
