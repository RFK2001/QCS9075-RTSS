/* Include header file guard */

#ifndef __SLEEP_CMM_H_
#define __SLEEP_CMM_H_

/*
===========================================================================
*/
/**
    @file  sleep_cmm.h
    @brief Header file of Sleep driver where common data is present between EL2/EL1

*/
/*
    ===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.

    ===========================================================================
    File Name          : sleepEl1.h
    Component Name     : sleep
    Description        : Header file of Sleep driver where all required APIs are exposed from El1
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sleep/public/sleep_cmm.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

typedef enum : uint32
{
    SLEEP_ENTRY = 0x0, // Sleep Entry for QNX sleep entry request
    SLEEP_ABORT,       // Sleep Abort in case QNX want to abort sleep
    SLEEP_INVALID      // Place Holder for Invalid Request
}sleepStatesType_e;

typedef enum : uint32
{
    DRIVER_SLEEP = 0x0, // State of Driver in case Sleep entry is initiated by Driver
    DRIVER_ACTIVE = 0x1 // Default State of Driver in active case
}sleepStateOfDriver_e;

typedef enum : uint32
{
    STR_SLEEP_MODE = 0x0, // Suspend to RAM mode
    DEEP_SLEEP_MODE,      // Deep sleep mode
    INVALID_SLEEP_MODE,      // Deep sleep mode
}sleepModeType_e;

typedef void  (*Sleep_ClientNotificationCallbackFn)(const sleepModeType_e eState);

typedef enum{
    SLEEP_ERR_FLAG_SUCCESS = 0x0,               // Success flag
    SLEEP_ERR_ENTRY_FAIL = 0x1,                 // flag if sleep entry has failed
    SLEEP_ERR_EXIT_FAIL = 0x2,                  // flag if sleep exit has failed
    SLEEP_ERR_FAILURE = 0x3,                    // flag if CB registered failed
    SLEEP_UNINITIALIZED = 0x4,                  // flag if Register function is not initalized.
    SLEEP_NULL_PTR = 0x5                        // flag if passed pointer is invalid
}sleepErrType_e;


#endif /* __SLEEP_CMM_H_  */

/**********************************************************************************************************
**                                  End of file sleep_cmm.h                                              **
**********************************************************************************************************/