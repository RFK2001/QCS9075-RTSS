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
    $Header: //components/dev/bsp.sail/1.0/gmohite.bsp.sail.1.0.new_clone/sleep/src/sailsw1/sleepRegister.c#1 $
    $DateTime: 2025/05/07 23:26:26 $
    $Author: gmohite $

    ===========================================================================
*/


/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

#include "types.h"
#include "sleepEl1.h"
#include "common_functions.h"
#include "sailbsp_mutex.h"
#include "freertos_init.h"
#include "sleep_internal.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "common_functions.h"
#include "err_fatal.h"
#include "debug_log.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#define SLEEP_SAIL_MAX_NOTIFY_CLIENTS  7U

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
    sleepNotificationDataType eDataArray[SLEEP_SAIL_MAX_NOTIFY_CLIENTS];
    uint32 ulDriverStatus;
    int8_t nTail;
}sleepNotificationListType;

typedef struct
{
    uint8 ucCpuId;
    mutex_t stSleepCoreLock;
    sleepNotificationListType eNotifyData;
    uint8 ucSleepInitStatus;
}Sleep_DriverContext_t;


/*=========================================================================================================
**                                        Static variables and constants                                 **
=========================================================================================================*/

SM_APP_DATA static Sleep_DriverContext_t stSleepDriverContext[2] = {0x0u};
SM_APP_DATA static mutex_t stSleepCoreLock;
SM_APP_DATA static uint32 ulGlobalIndex = 32u;

/*=========================================================================================================
**                                        Local function prototypes                                      **
=========================================================================================================*/

sleepErrType_e prvSleepDrvRegisterCallBackEl1(Sleep_DriverContext_t *pPMDriverContext,
                                            Sleep_ClientNotificationCallbackFn pCB,
                                            uint32 *handle);

uint32 ulEncodeValue(uint8 ucIndexValue);

/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/

/*=========================================================================================================
 @Service name        vEl2SleepNotify
 @Description         vEl2SleepNotify is used to do HVC call to EL2 sleep driver so that Deinit of register 
                      function can be called
 @param[in]           xSleepState -> SLEEP_ENTRY,SLEEP_ABORT
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

void vEl2SleepNotify(sleepModeType_e xSleepState)
{
    uint32_t hvcId     = SLEEP_NOTIFY_EL2;
    uint32_t paramId   = SLEEP_NOTIFY_EL2_PARM_ID;
    uint32_t arg1      = (uint32_t)xSleepState;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
    	err_fatal(SLEEP, ERR_FATAL_HVC_CALL_FAILED);
    }
}


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

void vSleepInitEl1(void)
{
    uint32_t core_id = get_curr_phys_cpu_num();
    stSleepDriverContext[core_id].ucCpuId = core_id;

    mutex_init(&stSleepCoreLock);
    
    stSleepDriverContext[core_id].ucSleepInitStatus = 0x1u;
}

/*=========================================================================================================
 @Service name        vNotifySleepEnter
 @Description         vNotifySleepEnter function to notify register call back driver to put their task
                      in sleep state
 @param[in]           xSleepMode < STR_SLEEP_MODE, DEEP_SLEEP_MODE >
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

void vNotifySleepEnterEl1(sleepModeType_e xSleepMode,uint32_t core_id)
{
    sleepNotificationListType *pList;
    pList = &(stSleepDriverContext[core_id].eNotifyData);
    if( pList != NULL){
    DEBUG_LOG(SAIL_ERROR,"===============> ntail -:%d\n\r", pList->nTail);
    }else{
    DEBUG_LOG(SAIL_ERROR,"===============> pList is NULL\n\r");
	}
	

  vLogSetUartState(LOG_UART_STOP);

    __asm volatile ( "  cpsid   i   " ::: "memory" );
    
    for(int index = 0 ; index < pList->nTail ; index++)
    {
        pList->eDataArray[index].pCB(xSleepMode);
    }

    __asm volatile ( "  cpsie   i   " ::: "memory" );

}

/*=========================================================================================================
 @Service name        xSlepRegisterCallBack
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


sleepErrType_e xSleepRegisterCallBackEl1( Sleep_ClientNotificationCallbackFn pCB , uint32 *handle,uint32_t core_id)
{
    return prvSleepDrvRegisterCallBackEl1(&stSleepDriverContext[core_id],pCB,handle);
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

sleepErrType_e xSleepDriverStatusEl1(uint32_t core_id)
{
    uint32 ulDriverStatus = 0x0;
    uint32 ulTimeOut = 128u;
    sleepErrType_e xSleepStatus = SLEEP_ERR_FLAG_SUCCESS;
    sleepNotificationListType *pList;

    pList = &(stSleepDriverContext[core_id].eNotifyData);

    ulDriverStatus = pList->ulDriverStatus;

    while( 0x0u != ulDriverStatus && ulTimeOut < 0)
    {
        vFreeRTOSTaskDelay(1u); // Delay of 20msec
        ulTimeOut--;
        ulDriverStatus = pList->ulDriverStatus;

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

sleepErrType_e xSleepDriverAckEl1(uint32 handle, sleepStateOfDriver_e xStateOfDriver,uint32_t core_id)
{
    sleepNotificationListType *pList;
    uint32 ucDriverIndex = 0x0;
    sleepErrType_e xSleepStatus = SLEEP_ERR_FLAG_SUCCESS;

    if ( stSleepDriverContext[core_id].ucSleepInitStatus != 0x1u )
    {
        return SLEEP_UNINITIALIZED;
    }

//	vTaskPreemptionDisable(NULL);
    mutex_lock(&stSleepCoreLock);
    // Start of Critical section

    ucDriverIndex = (handle&(0xFFFFu));

    if ( ucDriverIndex >= SLEEP_SAIL_MAX_NOTIFY_CLIENTS )
    {
        xSleepStatus =  SLEEP_ERR_FAILURE;
        goto SleepEnd;
    }

    pList = &(stSleepDriverContext[core_id].eNotifyData);

    if ( DRIVER_SLEEP == xStateOfDriver )
    {
        pList->ulDriverStatus &=  ~(0x1u<<ucDriverIndex);
    }

    // End of Critical section

    SleepEnd:
    mutex_unlock(&stSleepCoreLock);
 // vTaskPreemptionEnable(NULL); 

    return SLEEP_ERR_FLAG_SUCCESS;

}

/*=========================================================================================================
**                                        Local function definitions                                     **
=========================================================================================================*/



/*=========================================================================================================
 @Service name        prvSleepDrvRegisterCallBackEl1
 @Description         prvSleepDrvRegisterCallBackEl1 function will register call back needed for sleep use case
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

sleepErrType_e prvSleepDrvRegisterCallBackEl1(Sleep_DriverContext_t *pPMDriverContext,Sleep_ClientNotificationCallbackFn pCB,
                                                                                                uint32 *handle)
{
    sleepNotificationListType *pList;
    sleepErrType_e xSleepStatus = SLEEP_ERR_FLAG_SUCCESS;

    if ( pPMDriverContext->ucSleepInitStatus != 0x1u )
    {
        return SLEEP_UNINITIALIZED;
    }
 //  vTaskPreemptionDisable(NULL);
    mutex_lock(&stSleepCoreLock);

    // Start of Critical Section

    pList = &(pPMDriverContext->eNotifyData);

    if ( pList->nTail >= SLEEP_SAIL_MAX_NOTIFY_CLIENTS )
    {
       xSleepStatus = SLEEP_ERR_FAILURE;
       goto SleepEnd;
    }

    pList->ulDriverStatus |= (0x1u<<pList->nTail);
    
    *handle = ulEncodeValue(pList->nTail);

    pList->eDataArray[pList->nTail].pCB = pCB;
    pList->eDataArray[pList->nTail].ulEncodeHandleValue = *handle;
    pList->nTail++;

    // End of Critical Section

    SleepEnd:
    mutex_unlock(&stSleepCoreLock);
   ///vTaskPreemptionEnable(NULL); 
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

/**********************************************************************************************************
**                                  End of file sleepRegister.c                                          **
**********************************************************************************************************/
