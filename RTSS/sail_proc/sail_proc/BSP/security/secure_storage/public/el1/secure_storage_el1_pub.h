/*=========================================================================
FILE: secure_storage_el1_pub.h
OVERVIEW: This header file contains APIs and macros to be used by EL1 clients

Copyright (c) Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Technologies Inc. Confidential and Proprietary
=========================================================================*/

#ifndef SECURE_STORAGE_EL1_PUB_H
#define SECURE_STORAGE_EL1_PUB_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */

#include "secure_storage_common_pub.h"

/* ----------------------------------------------------------------------------
 * Public APIs
 * ----------------------------------------------------------------------------
 */

/* =========================================================================
**  Function : secureStorageEL1Init
** =========================================================================*/
/**
  @brief initializes the secure storage main partition header

  @return E_SECURE_STORAGE_SUCCESS if successful, Secure Storage error code otherwise.
*/

SECURE_STORAGE_STATUS secureStorageEL1Init
(
  void
);

/* =========================================================================
**  Function : secureStorageEL1CreatePartition
** =========================================================================*/
/**
  @brief creates a client partition

  @param clientID           [in]   secure storage client identifier
  @param partitionName      [in]   name of client partition
  @param partitionLength    [in]   length of client partition  name
  @param partitionSize      [in]   size of client partition to be createds

  @return E_SECURE_STORAGE_SUCCESS if successful, Secure Storage error code otherwise.
*/

SECURE_STORAGE_STATUS secureStorageEL1CreatePartition
(
  SecureStorageClientID clientID,
  uint8_t*              partitionName,
  size_t                partitionNameLength,
  uint32_t              partitionSize
);

/* =========================================================================
**  Function : secureStorageEL1OpenPartition
** =========================================================================*/
/**
  @brief marks a client partition as opened and returns the handle to access it

  @param clientID           [in]    secure storage client identifier
  @param partitionName      [in]    name of client partition
  @param partitionLength    [in]    length of client partition  name
  @param handle             [out]   handle to access the opened client partition

  @return E_SECURE_STORAGE_SUCCESS if successful, Secure Storage error code otherwise.
*/

SECURE_STORAGE_STATUS secureStorageEL1OpenPartition
(
  SecureStorageClientID clientID,
  uint8_t*              partitionName,
  size_t                partitionNameLength,
  uint32_t *            handle
);

/* =========================================================================
**  Function : secureStorageEL1ClosePartition
** =========================================================================*/
/**
  @brief marks a client partition as closed, blocking any further access

  @param handle [in]    handle to close the opened client partition

  @return E_SECURE_STORAGE_SUCCESS if successful, Secure Storage error code otherwise.
*/

SECURE_STORAGE_STATUS secureStorageEL1ClosePartition
(
  uint32_t handle
);

/* =========================================================================
**  Function : secureStorageEL1ReadPartition
** =========================================================================*/
/**
  @brief validates the handle and range of memory being accessed and
         reads data from storage and copies it to output buffer

  @param handle                 [in]    handle to access the opened client partition
  @param byteOffset             [in]    starting byte offset within the client the partition
  @param numberOfBytesToAccess  [in]    number of bytes to be access starting from offset
  @param outputBuffer           [out]   buffer where data is to be written

  @return E_SECURE_STORAGE_SUCCESS if successful, Secure Storage error code otherwise.
*/

SECURE_STORAGE_STATUS secureStorageEL1ReadPartition
(
  uint32_t  handle,
  uint32_t  byteOffset,
  uint32_t  numberOfBytes,
  void *    outputBuffer
);

/* =========================================================================
**  Function : secureStorageEL1WritePartition
** =========================================================================*/
/**
  @brief validates the handle and range of memory being accessed and
         writes data in input buffer to storage

  @param handle                 [in]    handle to access the opened client partition
  @param byteOffset             [in]    starting byte offset within the client the partition
  @param numberOfBytesToAccess  [in]    number of bytes to be access starting from offset
  @param inputBuffer            [in]    buffer containing the data to be written

  @return E_SECURE_STORAGE_SUCCESS if successful, Secure Storage error code otherwise.
*/

SECURE_STORAGE_STATUS secureStorageEL1WritePartition
(
  uint32_t  handle,
  uint32_t  byteOffset,
  uint32_t  numberOfBytes,
  void *    inputBuffer
);

#endif /* SECURE_STORAGE_EL1_PUB_H */