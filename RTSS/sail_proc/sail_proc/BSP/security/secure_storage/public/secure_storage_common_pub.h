/*=========================================================================
FILE: secure_storage_common_pub.h
OVERVIEW: This header file contains macros and enums to be used by EL1 and EL2 clients

Copyright (c) Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Technologies Inc. Confidential and Proprietary
=========================================================================*/

#ifndef SECURE_STORAGE_COMMON_PUB_H
#define SECURE_STORAGE_COMMON_PUB_H


/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */

#include <types.h>
#include "secure_storage_cfg.h"

/* ----------------------------------------------------------------------------
 * Enums
 * ----------------------------------------------------------------------------
 */

/* Secure storage client IDs, to be used to identify clients and for maintaining ARB fuses */
typedef enum
{
  SECURE_STORAGE_CLIENT_0 = 0U, /* Used by SHE */
  SECURE_STORAGE_CLIENT_1, /* Unused (please consult with SAIL security before using) */
#ifdef SECURE_STORAGE_ENABLE_TEST_MODE
  SECURE_STORAGE_CLIENT_TEST, /* Reserved for test client */
#endif
  SECURE_STORAGE_CLIENT_MAX_NUM /* Should never go beyond SECURE_STORAGE_MAX_NUM_CLIENT_SUPPORTED */
} SecureStorageClientID;

/* Different statuses for main partion header init */
typedef enum
{
    MAIN_PARTITION_HEADER_INIT_NOT_DONE = 0U,
    MAIN_PARTITION_HEADER_INIT_DONE,
    MAIN_PARTITION_HEADER_INIT_INVALID,
    MAIN_PARTITION_HEADER_INIT_MAX_STATUS
} SecureStorageMPHInitStatus;

/* ----------------------------------------------------------------------------
 * Error codes
 * ----------------------------------------------------------------------------
 */
typedef enum{
    /* Success */ 
    E_SECURE_STORAGE_SUCCESS = 0U,                      /* 0 */

    /* Generic Failure */
    E_SECURE_STORAGE_ERROR,                             /* 1 */

    /* Invalid arguments passed */
    E_SECURE_STORAGE_PARAM_INVALID,                     /* 2 */

    /* Partition does not exist */
    E_SECURE_STORAGE_PARTITION_DOES_NOT_EXIST,          /* 3 */

    /* Partition exists */
    E_SECURE_STORAGE_PARTITION_EXISTS,                  /* 4 */

    /* Partition not opened */
    E_SECURE_STORAGE_PARTITION_NOT_OPENED,              /* 5 */

    /* Partition already opened */
    E_SECURE_STORAGE_PARTITION_ALREADY_OPENED,          /* 6 */

    /* Main partition header not initialized */
    E_SECURE_STORAGE_MPH_NOT_INITED,                    /* 7 */

    /* Main partition header already initialized */
    E_SECURE_STORAGE_MPH_IS_INITED,                     /* 8 */

    /* Client handle invalid */
    E_SECURE_STORAGE_INVALID_HANDLE,                    /* 9 */

    /* Out of memory/other resources */
    E_SECURE_STORAGE_OUT_OF_RESOURCES,                  /* 10 */

    /* Trying to access memory out of range */
    E_SECURE_STORAGE_ACCESS_OUT_RANGE,                  /* 11 */

    /* HVC failed */
    E_SECURE_STORAGE_HVC_FAILED,                        /* 12 */

    /* SPINOR operation failed */
    E_SECURE_STORAGE_SPINOR_OPERATION_FAILED,           /* 13 */

    /* Access not aligned */
    E_SECURE_STORAGE_UNALIGNED_ACCESS,                  /* 14 */

    /* QPFROM operation failed */
    E_SECURE_STORAGE_QFPROM_OP_FAILED,                  /* 15 */

    /* ARB Fuse bits for client exhausted */
    E_SECURE_STORAGE_ARB_CHECK_FAILED,                  /* 16 */

    /* ARB Fuse bits for client exhausted */
    E_SECURE_STORAGE_FUSE_BITS_EXHAUSTED,               /* 17 */

    /* UCLIB operation failed */
    E_SECURE_STORAGE_UCLIB_OP_FAILED,                   /* 18 */

    /* HWKM operation failed */
    E_SECURE_STORAGE_HWKM_OP_FAILED,                    /* 19 */

    /* Secure storage EL2 init failed */
    E_SECURE_STORAGE_EL2_INIT_FAILED,                   /* 20 */

    /* Secure storage job queue empty */
    E_SECURE_STORAGE_JOB_QUEUE_EMPTY,                   /* 21 */

    /* Secure storage job queue full */
    E_SECURE_STORAGE_JOB_QUEUE_FULL,                    /* 22 */

    /* Secure storage job queue full */
    E_SECURE_STORAGE_JOB_QUEUE_NOT_INITIALIZED,         /* 23 */

    /* Job state invalid */
    E_SECURE_STORAGE_JOB_STATE_INVALID,                 /* 24 */

    /* SPINOR job pending */
    E_SECURE_STORAGE_SPINOR_PENDING,                    /* 25 */

    /* SPINOR job pending */
    E_SECURE_STORAGE_MPH_UNRECOVERABLE                  /* 26 */
} SECURE_STORAGE_STATUS;

#endif /* SECURE_STORAGE_COMMON_PUB_H */