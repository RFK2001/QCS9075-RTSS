/*==============================================================================

FILE:      NOC_safertos.c

DESCRIPTION: This file implements ICB SPINOR logging.

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A

Edit History

When        Who    What, where, why
----------  ---    ----------------------------------------------------------- 
    Copyright (c) 2024 Qualcomm Technologies, Inc.
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
==============================================================================*/

#include "icb_error.h"
/*#include "interrupts.h" */ /* for EL 2 */
#include "debug_log.h"
#include "icb_error.h"
#include "msmhwiobase.h"
#include "spinor_el1_api.h"
#include "err_fatal.h"

/*============================================================================
                          DEFINEs/MACROs
============================================================================*/

/*============================================================================
                                 FUNCTIONS
============================================================================*/
ICB_DATA QueueHandle_t xIcbQueueHandle = NULL;
ICB_DATA TaskHandle_t xIcbTaskHandle = NULL;

/* Number of ICB Tasks */
/* The size of the periodic test task stack - must be a multiple of 64. */
#define ICB_TASK_STACK_SIZE                   ( 4096u )
/* Declare task TCB. */
static StaticTask_t xIcbTaskTCB = { 0 };
static void xIcbLogTask(void *pvParameters);

#define ICB_QUEUE_LENGTH                ( 3U )
#define ICB_QUEUE_ITEM_SIZE             ( sizeof(NOCERRORrecordType) )
#define ICB_QUEUE_BUFFER_SIZE           ( ICB_QUEUE_LENGTH * ICB_QUEUE_ITEM_SIZE )

/* Declare task stack:
 * The check task stack is protected by an MPU region, so the alignment must
 * follow MPU alignment rules and aligned to a 64-byte boundary. */
static StackType_t xIcbTaskStack[ICB_TASK_STACK_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
static uint8_t xIcbQueueBuffer[ICB_QUEUE_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
static StaticQueue_t xIcbQueueBufferStatic;
/*=================================================================================================
**                                   Global function definitions                                 **
==================================================================================================*/


/*=================================================================================================
 @Service name        xIcb_LogResourcesInit
 @Description         Resource Init Function to create task Queue
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              portBaseType <pdFail , pdPass> Based on status of task creation
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

BaseType_t xIcb_LogResourcesInit(CPUIdType_e xSchdCore)
{
    BaseType_t xResult = pdPASS ;
        /* Create Queue */
    xResult = xFreeRTOSQueueCreate(xIcbQueueBuffer, ICB_QUEUE_LENGTH, ICB_QUEUE_ITEM_SIZE, &xIcbQueueHandle,&xIcbQueueBufferStatic);

    return xResult;
}

/*=================================================================================================
 @Service name        xIcbLogTask
 @Description         Init Function used to log the error in SPINOR
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              portBaseType <pdFail , pdPass> Based on status of task creation
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


static void xIcbLogTask(void *pvParameters)
{
	(void)pvParameters;
	NOCERRORrecordType xMsg = {0};
	BaseType_t xReturn = pdFAIL;
    if(ICB_NOCErr_SPINOR_readAndClear ()== 0x0U)
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:ICB get NOC Error from the previous boot failed\r\n");
    }
    for(;;)
        {
            /* Receive msg on queue and parse message */
            xReturn = xFreeRTOSQueueReceive(xIcbQueueHandle, &xMsg, freertosMAX_DELAY);
            if ( pdPASS == xReturn )
            {
                if ( xMsg.magicNumber == ICB_MAGIC_NUMBER )
                {
                    if(ICB_NocErrLogData_WtToSpiNOR (&xMsg)== 0x0U)
                    {
                        DEBUG_LOG(SAIL_ERROR,"[ICB]:ICB_NocErrLogData write to SPINOR failed\r\n");
                    }
                }else
                {
                    DEBUG_LOG(SAIL_ERROR,"[ICB]:Magic number is not set\r\n");
                    err_fatal(ICB,xReturn);
                }
            }else
            {
                DEBUG_LOG(SAIL_ERROR,"[ICB]:xQueueReceive() failed\r\n");
                err_fatal(SAFERTOS,xReturn);
            }
        }
}

/*=================================================================================================
 @Service name        xIcbTaskInit
 @Description         Init Function to take schedule ICB task
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              portBaseType <pdFail , pdPass> Based on status of task creation
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

BaseType_t xIcbTaskInit( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior )
{
    BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
        .pvTaskCode =xIcbLogTask,                 /* The function that implements the task being created. */
        .pcName ="xIcbLogTask",                 /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer =&xIcbTaskTCB,              /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer =xIcbTaskStack,             /* The buffer allocated for use as the task stack. */
        .usStackDepth = ICB_TASK_STACK_SIZE,      /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters =NULL,                               /* The task parameter, not used in this case. */
        .uxPriority = (xTaskPrior),                         /* The priority assigned to the task being created. */
        .xRegions = {				   /* The MPU task parameters. */
						 {NULL, 0UL, 0UL}, /* No additional region definitions are required. */
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL}}};

    /* Create the check task. */
    uxCoreAffinityMask = (1 << xSchdCore);
    xResult = xFreeRTOSTaskCreateAffinitySet( &xInitTaskParameters,uxCoreAffinityMask, /* The structure containing the task parameters created at the start of this function. */
                                        &xIcbTaskHandle );
    return xResult;
}

 /****************************************************************************
 **                                  End of file Icb_safertos.c             **
 *****************************************************************************/
