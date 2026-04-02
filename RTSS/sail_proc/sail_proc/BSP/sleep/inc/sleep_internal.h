#ifndef __SLEEP_INTERNAL_H_
#define __SLEEP_INTERNAL_H_

/*
===========================================================================
*/
/**
    @file  sleep_internal.h
    @brief prototype of internal function

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
    File Name          : sleep_internal.h
    Component Name     : sleep
    Description        : prototype of internal function
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sleep/inc/sleep_internal.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


#include "types.h"
#include "sleep_cmm.h"

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

typedef enum
{
    SLEEP_ENTRY_MAKER = 0,
    SLEEP_EXIT_MARKER = 1,
}sleepMarkerUpdate_e;

typedef struct
{
    uint64 entryTimeStamp;
    uint64 exitTimeStamp;
    uint32 sleepCount;
    uint64 TimeElapseInSleep;
}sleepDebugInformation;


typedef enum{
    SLEEP_TASK_STARTED = 0x10,
    SLEEP_ENTRY_STARTED = 0x11,
    SLEEP_IRQ_CONFIG_DONE = 0x12,
    SLEEP_CORE_1_2_NOTIFICATION_SENT = 0x13,
    SLEEP_CORE0_EL1_DEINIT_DONE = 0x14,
    SLEEP_CORE1_2_ACK_RECEIVED = 0x15,
    SLEEP_CORE0_EL2_DEINIT_DONE = 0x16,
    SLEEP_CORE0_UART_DEINIT_DONE = 0x17,
    SLEEP_ENTRY_SEQ_TRIGGERED = 0x18,
    SLEEP_CORE1_REQ_RECEIVED = 0x19,
    SLEEP_CORE1_EL1_DEINT_DONE = 0x1A,
    SLEEP_CORE1_EL2_DEINT_DONE = 0x1B,
    SLEEP_CORE1_COMPLETE = 0x1C,
    SLEEP_CORE2_REQ_RECEIVED = 0x1D,
    SLEEP_CORE2_EL1_DEINT_DONE = 0x1E,
    SLEEP_CORE2_EL2_DEINT_DONE = 0x1F,
    SLEEP_CORE2_VIP_UART_DEINT_DONE = 0x20,
    SLEEP_CORE2_COMPLETE = 0x21,
    SLEEP_CORE3_COMPLETE = 0x22,
    SLEEP_INVALID_MARKER = 0xFF
}sleepDebugMarker_e;


/*=================================================================================================
**                                    Global function prototypes                                 **
===================================================================================================*/

/*=========================================================================================================
 @Service name        vsleepDataUpdate
 @Description         vsleepDataUpdate function update sleep marker
                      in sleep state
 @param[in]           sleepMarkerUpdate_e < SLEEP_ENTRY_MAKER, SLEEP_EXIT_MARKER >
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

void vsleepDataUpdate(sleepMarkerUpdate_e xdataType);
void vsleepDataUpdateEl1(sleepMarkerUpdate_e xdataType);

/*=========================================================================================================
 @Service name        vSleepNotifySleepEnter
 @Description         vSleepNotifySleepEnter function to notify register call back driver to put their task
                      in sleep state
 @param[in]           sleepModeType_e -> DEEP SLEEP/ STR SLEEP
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

void vNotifySleepEnter(sleepModeType_e xSleepState);
void vNotifySleepEnterEl1(sleepModeType_e xSleepState,uint32_t core_id);

/*=========================================================================================================
 @Service name        xSleepEnter
 @Description         xSleepEnter function will enable Seq needed on sleep entry path 
 @param[in]           sleepModeType_e --> STR_SLEEP_MODE, DEEP_SLEEP_MODE
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

sleepErrType_e xSleepEnter(sleepModeType_e xSleepMode);

/*=========================================================================================================
 @Service name        xSleepDriverStatus
 @Description         xSleepDriverStatus will be used to find out sleep entry status of all the drivers and 
                      tasks register to sleep driver
 @param[in]           void
 @param[out]          NA
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

sleepErrType_e xSleepDriverStatus(void);
sleepErrType_e xSleepDriverStatusEl1(uint32_t core_id);

#endif