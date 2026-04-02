/*=========================================================================
FILE: secure_storage_el2_pub.h
OVERVIEW: This header file contains APIs and macros to be used by EL2 clients

Copyright (c) Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Technologies Inc. Confidential and Proprietary
=========================================================================*/
#ifndef SECURE_STORAGE_EL2_PUB_H
#define SECURE_STORAGE_EL2_PUB_H

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
**  Function : secureStorageEL2Init
** =========================================================================*/
/**
  @brief wrapper function to perform secure storage EL2 init tasks

  @return E_SECURE_STORAGE_SUCCESS if successful, Secure Storage error code otherwise.
*/

SECURE_STORAGE_STATUS secureStorageEL2Init
(
  void
);

/* =========================================================================
**  Function : secureStorageEL2EncDecData
** =========================================================================*/
/**
  @brief acts as a wrapper function to validate handle, then calls the function responsible
         for the crpyto op

  @param handle             [in]   handle to identify the client and partition
  @param isEncrypt          [in]   true if its encryption op, false if decryption
  @param inputBuffer        [in]   input buffer on which the crypto operation is to be performed
  @param inputBufferSize    [in]   size of input buffer
  @param outputBuffer       [out]  buffer in which output of crypto operation is stored
  @param outputBufferSize   [in]   size of output buffer

  @return E_SECURE_STORAGE_SUCCESS if successful, Secure Storage error code otherwise.
*/


SECURE_STORAGE_STATUS secureStorageEL2EncDecData
(
  uint32_t  handle,
  bool      isEncrypt,
  void*     inputBuffer,
  size_t    inputBufferSize,
  void*     outputBuffer,
  size_t    outputBufferSize
);

#endif /* SECURE_STORAGE_EL2_PUB_H */
