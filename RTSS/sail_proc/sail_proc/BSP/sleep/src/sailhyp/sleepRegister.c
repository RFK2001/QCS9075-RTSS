/*
===========================================================================
*/
/**
    @file  sleepRegister.c
    @brief register call back function need for sleep notification to all client

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
    File Name          : sleepEl1.c
    Component Name     : sleep
    Description        : Defination of El1 function of sleep driver
    $Header: //components/dev/bsp.sail/1.0/asuthar.bsp.sail.1.0.sleepExitChanges/sleep/src/sailsw1/sleepRegister.c#1 $
    $DateTime: 2023/01/16 06:28:48 $
    $Author: asuthar $

    ===========================================================================
*/


/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

#include "types.h"
#include "sleepEl2.h"
#include "common_functions.h"
#include "sailbsp_mutex.h"
#include "sleep_internal.h"
#include "syscall.h"
#include "syscall_pub.h"
#include "err_fatal.h"
#include "target.h"
#include "busywait.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#define SLEEP_SAIL_MAX_NOTIFY_CLIENTS  7U

static uint32 ulGlobalIndex = 32u;

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

typedef struct
{
    Sleep_ClientNotificationCallbackFn pCB;
    uint32 ulEncodeHandleValue;
}sleepNotificationDataType;

typedef struct
{
    sleepNotificationDataType eDataArray[SAILBSP_CPU_COUNT][SLEEP_SAIL_MAX_NOTIFY_CLIENTS];
    uint32 ulDriverStatus[SAILBSP_CPU_COUNT];
    int8_t nTail[SAILBSP_CPU_COUNT];
}sleepNotificationListType;

typedef struct
{
    mutex_t stSleepCoreLock;
    sleepNotificationListType eNotifyData;
    uint8 ucSleepInitStatus;
}Sleep_DriverContext_t;


/*=========================================================================================================
**                                        Static variables and constants                                 **
=========================================================================================================*/

static Sleep_DriverContext_t stSleepDriverContext = {0x0u};

/*=========================================================================================================
**                                        Local function prototypes                                      **
=========================================================================================================*/

sleepErrType_e prvSleepDrvRegisterCallBack(Sleep_DriverContext_t *pPMDriverContext,
                                            Sleep_ClientNotificationCallbackFn pCB,
                                            uint32 *handle);

uint32 ulEncodeValue(uint8 ucIndexValue);

/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/

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

void vSleepInit(void)
{
    mutex_init(&stSleepDriverContext.stSleepCoreLock);
    
    stSleepDriverContext.ucSleepInitStatus = 0x1u;
}

/*=========================================================================================================
 @Service name        vNotifySleepEnter
 @Description         vNotifySleepEnter function to notify register call back driver to put their task
                      in sleep state
 @param[in]           xSleepState < SLEEP_ENTER, SLEEP_ABORT >
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

void vNotifySleepEnter(sleepModeType_e xSleepState)
{
    sleepNotificationListType *pList;
    uint32_t phys_core_id = get_curr_phys_cpu_num();

    if ( phys_core_id >= SAILBSP_CPU_COUNT )
    {
        err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
    }

    pList = &(stSleepDriverContext.eNotifyData);
    
    for(int index = 0 ; index < pList->nTail[phys_core_id] ; index++)
    {
        pList->eDataArray[phys_core_id][index].pCB(xSleepState);
    }
}

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


sleepErrType_e xSleepRegisterCallBack( Sleep_ClientNotificationCallbackFn pCB , uint32 *handle)
{
    return prvSleepDrvRegisterCallBack(&stSleepDriverContext,pCB,handle);
}

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

sleepErrType_e xSleepDriverStatus(void)
{
    uint32 ulDriverStatus = 0x0;
    uint32 ulTimeOut = 128u;
    sleepErrType_e xSleepStatus = SLEEP_ERR_FLAG_SUCCESS;
    sleepNotificationListType *pList;
    uint32_t phys_core_id = get_curr_phys_cpu_num();

    if ( phys_core_id >= SAILBSP_CPU_COUNT )
    {
        err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
    }

    pList = &(stSleepDriverContext.eNotifyData);

    ulDriverStatus = pList->ulDriverStatus[phys_core_id];

    while( 0x0u != ulDriverStatus && ulTimeOut < 0)
    {
        busywait(20); //Delay of 2.5msec
        ulTimeOut--;
        ulDriverStatus = pList->ulDriverStatus[phys_core_id];
    }

    if ( 0x0u != ulDriverStatus )
    {
        xSleepStatus = SLEEP_ERR_ENTRY_FAIL;
    }

    return xSleepStatus;
}

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

sleepErrType_e xSleepDriverAck(uint32 handle, sleepStateOfDriver_e xStateOfDriver)
{
    sleepNotificationListType *pList;
    uint32 ucDriverIndex = 0x0;
    sleepErrType_e xSleepStatus = SLEEP_ERR_FLAG_SUCCESS;
    uint32_t phys_core_id = get_curr_phys_cpu_num();

    if ( phys_core_id >= SAILBSP_CPU_COUNT )
    {
        err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
    }

    if ( stSleepDriverContext.ucSleepInitStatus != 0x1u )
    {
        return SLEEP_UNINITIALIZED;
    }

    mutex_lock(&stSleepDriverContext.stSleepCoreLock);

    // Start of Critical section

    ucDriverIndex = (handle&(0xFFFFu));

    if ( ucDriverIndex >= SLEEP_SAIL_MAX_NOTIFY_CLIENTS )
    {
        xSleepStatus =  SLEEP_ERR_FAILURE;
        goto SleepEnd;
    }

    pList = &(stSleepDriverContext.eNotifyData);

    if ( DRIVER_SLEEP == xStateOfDriver )
    {
        pList->ulDriverStatus[phys_core_id] &=  ~(0x1u<<ucDriverIndex);
    }

    // End of Critical section

    SleepEnd:
    mutex_unlock(&stSleepDriverContext.stSleepCoreLock);

    return SLEEP_ERR_FLAG_SUCCESS;

}

/*=========================================================================================================
**                                        Local function definitions                                     **
=========================================================================================================*/



/*=========================================================================================================
 @Service name        prvSleepDrvRegisterCallBack
 @Description         prvSleepDrvRegisterCallBack function will register call back needed for sleep use case
 @param[in]           Sleep_DriverContext_t *pPMDriverContext -> Local context data structure
                      Sleep_ClientNotificationCallbackFn pCB -> Address of void function call
  @param[out]         uint32 *handle -> handle of function
                      getting non-zero value
 @param[in, out]      NA
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

sleepErrType_e prvSleepDrvRegisterCallBack(Sleep_DriverContext_t *pPMDriverContext,Sleep_ClientNotificationCallbackFn pCB,
                                                                                                uint32 *handle)
{
    sleepNotificationListType *pList;
    sleepErrType_e xSleepStatus = SLEEP_ERR_FLAG_SUCCESS;
    uint32_t phys_core_id = get_curr_phys_cpu_num();

    if ( phys_core_id >= SAILBSP_CPU_COUNT )
    {
        err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
    }

    if ( pPMDriverContext->ucSleepInitStatus != 0x1u )
    {
        return SLEEP_UNINITIALIZED;
    }

    mutex_lock(&stSleepDriverContext.stSleepCoreLock);

    // Start of Critical Section

    pList = &(pPMDriverContext->eNotifyData);

    if ( pList->nTail[phys_core_id] >= SLEEP_SAIL_MAX_NOTIFY_CLIENTS )
    {
       xSleepStatus = SLEEP_ERR_FAILURE;
       goto SleepEnd;
    }

    pList->ulDriverStatus[phys_core_id] |= (0x1u<<pList->nTail[phys_core_id]);
    
    *handle = ulEncodeValue(pList->nTail[phys_core_id]);

    pList->eDataArray[phys_core_id][pList->nTail[phys_core_id]].pCB = pCB;
    pList->eDataArray[phys_core_id][pList->nTail[phys_core_id]].ulEncodeHandleValue = *handle;
    pList->nTail[phys_core_id]++;

    // End of Critical Section

    SleepEnd:
    mutex_unlock(&stSleepDriverContext.stSleepCoreLock);
    
    return xSleepStatus;
}

/*=========================================================================================================
 @Service name        ulEncodeValue
 @Description         ulEncodeValue function will return encoded value
 @param[in]           ucIndexValue -> Index of CB to sleep driver 
 @param[out]          uint32 value -> encode value
 @param[in, out]      NA
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

uint32 ulEncodeValue(uint8 ucIndexValue)
{
    ulGlobalIndex++;
    return (ulGlobalIndex<<16)|(ucIndexValue);
}

/*=========================================================================================================
 @Service name        SleepSysCallNotifySleepEnter
 @Description         SleepSysCallNotifySleepEnter Sleep SysCall to notify driver in EL2 about sleep entry
 @param[in]           xSleepState -> SLEEP_ENTRY,SLEEP_ABORT
 @param[out]          NA
 @param[in, out]      NA
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

uint32 SleepSysCallNotifySleepEnter(sleepModeType_e xSleepState, sailbsp_hvc_rsp_t *rsp)
{

    vNotifySleepEnter(xSleepState);

    if ( SLEEP_ERR_FLAG_SUCCESS == xSleepDriverStatus())
    {
        return HVC_SUCCESS;
    }else
    {
        return HVC_ERR_FAILURE;
    }
}


SAIL_DEFINE_SYSCALL(  SLEEP_NOTIFY_EL2,
                      SLEEP_NOTIFY_EL2_PARM_ID,
                      0,
                      SleepSysCallNotifySleepEnter
                    );


/**********************************************************************************************************
**                                  End of file sleepRegister.c                                          **
**********************************************************************************************************/