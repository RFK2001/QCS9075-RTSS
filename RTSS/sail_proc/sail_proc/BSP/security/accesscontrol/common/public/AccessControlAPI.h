/*===========================================================================
  Copyright (c) Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/


#ifndef ACCESSCCONTROLAPI_H
#define ACCESSCCONTROLAPI_H

#include "types.h"

/**
 * @brief SAILbspACInit - Initializes AC static configs for VMIDMT and xPU both
 *
 * @return E_SUCCESS on success, failure values on Failure
 */
int32 SAILbspACInit(void);

/**
 * @brief SAILbspACSleepExit - API to be called after waking up from sleep
 *
 * @return E_SUCCESS on success, E_FAILURE value on Failure
 */
int32 SAILbspACSleepExit(void);

int32 SAILbspACCalcMSARGGVTrigger(void);

/**
 * @brief ACInitPostBIST - API to apply R2 Policy configuration post MDBIST
 *
 * @return E_SUCCESS on success, E_FAILURE value on Failure
 */
int32 ACInitPostBIST(void);

#endif /* ACCESSCCONTROLAPI_H */
