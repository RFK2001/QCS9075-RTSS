/* Include header file guard */

#ifndef __SLEEPEL2_H_
#define __SLEEPEL2_H_

/*
===========================================================================
*/
/**
    @file  sleepEl2.h
    @brief Header file of Sleep driver where all required APIs are exposed from El2

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
    File Name          : sleepEl2.h
    Component Name     : sleep
    Description        : Header file of Sleep driver where all required APIs are exposed from El2
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sleep/public/sailhyp/sleepEl2.h#1 $
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
#include "sleep_cmm.h"


/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

/*=========================================================================================================
**                                    Global function prototypes                                         **
=========================================================================================================*/

/*=========================================================================================================
 @Service name        low_power
 @Description         low_power function will put current CPU in WFI
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


void low_power(void);


/*=========================================================================================================
 @Service name        xSleepEl2Exit
 @Description         xSleepEl2Exit function will enable Seq needed on sleep exit path 
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              sleepErrType_e
 @Pre                 PMICInit,PCInit,ISD,CLKInit should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

sleepErrType_e xSleepEl2Exit(void);

/*=========================================================================================================
 @Service name        vSleepInit
 @Description         vSleepInit function is init mutex call needed for internal locks
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

void vSleepInit(void);

/*=========================================================================================================
 @Service name        xSleepRegisterCallBack
 @Description         xSleepRegisterCallBack function will register call back needed for sleep use case
 @param[in]           Sleep_ClientNotificationCallbackFn pCB -> Address of void function call
 @param[out]          uint32 *handle -> handle of function
 @param[in, out]      NA
 @return              sleepErrType_e <return sleep error type>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


sleepErrType_e xSleepRegisterCallBack( Sleep_ClientNotificationCallbackFn pCB , uint32 *handle);

/*=========================================================================================================
 @Service name        xSleepDriverACk
 @Description         xSleepDriverACk will be used to find out sleep entry status of all the drivers and 
                      tasks register to sleep driver
 @param[in]           handle -> handle of CB function
                      xStateOfDriver -> DRIVER_SLEEP , DRIVER_ACTIVE
 @param[out]          NA
 @param[in, out]      NA
 @return              sleepErrType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

sleepErrType_e xSleepDriverAck(uint32 handle, sleepStateOfDriver_e xStateOfDriver);


#endif /* __SLEEPEL2_H_  */

/**********************************************************************************************************
**                                  End of file sleepEl2.h                                               **
**********************************************************************************************************/