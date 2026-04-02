/*=========================================================================
FILE: secure_mailbox_el1_pub.h
OVERVIEW: This header file contains APIs and macros to be used by EL1 clients

Copyright (c) 2023 Qualcomm Technologies Incorporated.
All rights reserved.
Qualcomm Technologies Inc. Confidential and Proprietary
=========================================================================*/

#ifndef SECURE_MAILBOX_EL1_PUB_H
#define SECURE_MAILBOX_EL1_PUB_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */

#include "secure_mailbox_common_pub.h"

/* ----------------------------------------------------------------------------
 * Public APIs
 * ----------------------------------------------------------------------------
 */

/* =========================================================================
**  Function : secureMailboxEL1Init
** =========================================================================*/
/**
  @brief initializes the secure mailbox

  @return E_SECURE_MAILBOX_SUCCESS if successful, Secure Storage error code otherwise.
*/

SECURE_MAILBOX_STATUS secureMailboxEL1Init
(
  void
);

/* =========================================================================
**  Function : secureMailboxEL1ResponseFromTZ
** =========================================================================*/
/**
  @brief initializes the secure storage main partition header

  @return E_SECURE_MAILBOX_SUCCESS if successful, Secure Storage error code otherwise.
*/

uint32_t secureMailboxEL1ResponseFromTZ
(
    uint8_t* buff,
    uint32_t buffSize
);

#endif /* SECURE_MAILBOX_EL1_PUB_H */