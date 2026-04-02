/* Include header file guard */
#ifndef __SLEEPSAFERTOS_H_
#define __SLEEPSAFERTOS_H_

/*
===========================================================================
*/
/**
    @file  sleepSafeRtos.h
    @brief This file contains sleep driver Global Interfaces and global parameters are defined here.

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
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sleep/public/sailsw1/sleepSafeRtos.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*=================================================================================================
**                                      Include files                                            **
===================================================================================================*/
#include <stdbool.h>
#include "types.h"
#include "freertos_init.h"

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

enum
{
    STR_SLEEP_REQ = 0xaau,                  // enum for STR sleep Request
    DEEP_SLEEP_REQ,                         // enum for Deep sleep Request
    SLEEP_PREP_REQUEST_INTERNAL,            // enum for external mailbox to core0 comm
    SLEEP_CORE_0_1_COMM,                    // enum for core0 to core1 comm
    SLEEP_CORE_0_2_COMM,                    // enum for core0 to core2 comm
    SLEEP_CORE_0_3_COMM,                    // enum for core0 to core3 comm
};


/*=================================================================================================
**                                    Global function prototypes                                 **
===================================================================================================*/

BaseType_t xSleepTaskInit_core0( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior );
BaseType_t xSleepTaskInit_core1( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior );
BaseType_t xSleepTaskInit_core2( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior );
								 
BaseType_t xSleep_Task_Resources_Init(CPUIdType_e xSchdCore);

#endif /* __SLEEPSAFERTOS_H_  */
