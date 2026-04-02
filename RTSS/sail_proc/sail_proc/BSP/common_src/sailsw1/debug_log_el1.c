/*
 * Copyright (c) 2021-2022, 2024 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Export of this technology or software is regulated by the U.S. Government.
 * Diversion contrary to U.S. law prohibited.
 *
 * All ideas, data and information contained in or disclosed by
 * this document are confidential and proprietary information of
 * Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
 * By accepting this material the recipient agrees that this material
 * and the information contained therein are held in confidence and in
 * trust and will not be used, copied, reproduced in whole or in part,
 * nor its contents revealed in any manner to others without the express
 * written permission of Qualcomm Technologies, Inc.
 */

#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <stdatomic.h>

#include <uart.h>
#include <HALhwio.h>

#include "debug_log.h"
#include "g_SAIL_QTMR.h"
#include "IPCC.h"
#include "freertos_init.h"
#include "cache_ops.h"
#include "mailboxExt_api.h"
#include "busywait.h"

#define TIMESTAMP_FREQ_DIV                   (192ULL)
#define UartConsoleTASK_STACK_SIZE 		     (2048U )
#define ComputeUartWaitTime(DataLen)         ((((DataLen) * 1000000) / 14400) + 5000)
#define Convert_Microsecs_to_Millisecs(x)    ((x) / 1000)

#define UartConsoleSIGID                 (29)
typedef void (*pvDebug_Log_UART_Rx_Notification)(volatile void *rslt);
static pvDebug_Log_UART_Rx_Notification pvDebugLogUARTRxNotifyCb = NULL;
SM_APP_DATA static atomic_uint      *pLogMemoryPos = (atomic_uint *)OS_DEBUGLOG_MEM_INDEX_ADDR;
SM_APP_DATA static atomic_uint      *pLogUartWritePos = (atomic_uint *)DEBUGLOG_UART_WRINDEX_ADDR;
SM_APP_DATA static atomic_uint      *pLogUartReadPos = (atomic_uint *)DEBUGLOG_UART_RDINDEX_ADDR;
SM_APP_DATA static char             *pcLogBuffer = (char *)OS_DEBUGLOG_STARTADDRESS;
SM_APP_DATA static UartLogType      *pcUartLogBuffer = (UartLogType *)UART_SHARED_AREA_STARTADDRESS;


static const uint32_t   ulDebugLogSize = OS_DEBUGLOG_SIZE;
static const uint32_t   ulDebugExtraSize = OS_DEBUGLOG_EXTRA_SIZE;
static const uint32_t   ulUartLogSize = UART_SHARED_LOG_SIZE;
static uint8 Uart_DebugLogStatus = 0;

SM_APP_DATA static LogLevel_e       eLogMemoryLevel = LOG_INFO;
SM_APP_DATA static LogLevel_e       eLogUartLevel = LOG_WARNING;
SM_APP_DATA static LogUartState_e   eLogUartState = LOG_UART_STOP;
SM_APP_DATA static LogMBState_e     eLogMBState = LOG_MB_STOP;

static StaticTask_t xUartConsoleTaskTCB = {0};
static StackType_t xUartConsoleTaskStack[ UartConsoleTASK_STACK_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };

static StaticEventGroup_t xEventGroupBufferUartConsole = { 0U };

SM_APP_DATA EventGroupHandle_t xEventGroupUartConsole __attribute__ ( ( aligned( MEM_ALIGNMENT_4 ) ) ) = NULL;

 SM_APP_DATA static IPCC_Handle xUartConsoleTask_IpccHandle[NUM_OF_CORES] = { NULL }; 

static void prvPrintToUart(void);
void vUartConsoleHandler( IPCC_CBData nData, IPCC_Client eSenderID, IPCC_Signal nSignal);

SM_APP_DATA TaskHandle_t xSAILConsoleUartTaskHandle = NULL;

int32_t memcpy_s(void *pDest, uint32_t ulDestSize, void *pSrc, uint32_t ulSrcSize)
{
    uint32_t    i = 0U;
    int32_t     slRet = -E_SUCCESS;

    if (ulDestSize >= ulSrcSize)
    {
        for (i = 0U; i < ulSrcSize; i++)
        {
            ((uint8_t *)pDest)[i] = ((uint8_t *)pSrc)[i];
        }
    }
    else
    {
        slRet = -E_INVALID_ARG;
    }

    return slRet;
}

void vDebugLogInit(void)
{
    /* PBL is not clearing UART since we moved region out, we must clear it */
    memset((void *)UART_SHARED_AREA_STARTADDRESS, 0x0, UART_SHARED_LOG_SIZE);
}

void vDebugLogRegNotifyCb( void (*pvDbgLogRxCb)(volatile void *rslt) )
{
  pvDebugLogUARTRxNotifyCb = pvDbgLogRxCb;
}

void HAL_SAIL_UART_Rx_Notification(volatile uartJobHandleType *Uart_JobResult)
{
  pvDebug_Log_UART_Rx_Notification tmp = pvDebugLogUARTRxNotifyCb;
  if ( NULL != tmp )
  {
    tmp ((volatile void *)Uart_JobResult);
  }
  else
  {
    LOG_ERROR("%s: Error, dbg_log rx cb is NULL\r\n", __func__);
  }
}
void vLogSetUartState(LogUartState_e eNewState)
{
    eLogUartState = eNewState;
    uint8 ulcpu_ID;

    if (LOG_UART_WORKING == eLogUartState)
    {
    	/* Get the Current CPU Id.*/
    	ulcpu_ID = get_curr_phys_cpu_num();
    	if(ulcpu_ID !=0)
    	{
            /* Attach the MD MPROC  for the sail*/
                if (  IPCC_EOK != IPCC_AttachEx(&xUartConsoleTask_IpccHandle[ulcpu_ID],IPCC_P_SAIL_MPROC,(IPCC_Client)(IPCC_C_SAIL0+ulcpu_ID),ulcpu_ID))
            {
                DEBUG_LOG( SAIL_ERROR,"<vLogSetUartState>IPCC Attach failed.\n\r");
            }
    	}
    	else
    	{
            /* print memory buffer to UART when UART is enabled. This will take time */
	   /*Core0 hang is causing, so disabling the below function call and handling in safertos context */
           /* prvPrintToUart();*/
    	}
    }
}

void vLogSetLevel(LogLevel_e eNewLevel)
{
    eLogUartLevel = eNewLevel;
}

LogLevel_e vLogGetLevel(void){
    return eLogUartLevel;
}

void vLogSetMemoryLevel(LogLevel_e eNewLevel)
{
    eLogMemoryLevel = eNewLevel;
}

void vLogUartLogBufferDeinit(void)
{
    atomic_store(pLogUartReadPos, atomic_load(pLogUartWritePos));
}

void vLogToMBSAILConsole(void)
{
	uint16 num_item;


	num_item = ((uint16)(*(uint16 *)HYP_DEBUGLOG_MEM_INDEX_ADDR));

    if ( HYP_DEBUGLOG_STARTADDRESS+num_item < OS_DEBUGLOG_STARTADDRESS )
    {
	   (void)slMailboxWrite(MAILBOX_CONSOLE,num_item,(uint8 *)HYP_DEBUGLOG_STARTADDRESS);
    }else
    {
        // Here , truncating the EL2 logs data to avoid noc error due to out of boundary access
        (void)slMailboxWrite(MAILBOX_CONSOLE,num_item-(((HYP_DEBUGLOG_STARTADDRESS+num_item)-OS_DEBUGLOG_STARTADDRESS)-1),(uint8 *)HYP_DEBUGLOG_STARTADDRESS);
    }

	num_item = ((uint16)(*(uint16 *)OS_DEBUGLOG_MEM_INDEX_ADDR));
    if ( OS_DEBUGLOG_STARTADDRESS+num_item <=  ( OS_DEBUGLOG_STARTADDRESS + OS_DEBUGLOG_SIZE + OS_DEBUGLOG_EXTRA_SIZE ) )
    {
	(void)slMailboxWrite(MAILBOX_CONSOLE,num_item,(uint8 *)OS_DEBUGLOG_STARTADDRESS);
    }else
    {
        // Here , truncating the EL1 logs data to avoid noc error due to out of boundary access

        (void)slMailboxWrite(MAILBOX_CONSOLE,num_item- ( (OS_DEBUGLOG_STARTADDRESS+num_item) - ( OS_DEBUGLOG_STARTADDRESS + OS_DEBUGLOG_SIZE + OS_DEBUGLOG_EXTRA_SIZE ) ),(uint8 *)OS_DEBUGLOG_STARTADDRESS);
    }

	eLogMBState = LOG_MB_WORKING;
}

LogMBState_e eLogToMBSAILConsoleOff(void)
{
	eLogMBState = LOG_MB_STOP;
	return eLogMBState;
}
static void prvPrintToMemory(TimeStampInfo Time_Stamp, const LogLevel_e eLevel, const char *pcMessage,va_list vargs)
{
    uint32_t ulLocalPos = 0;
    uint32_t ulMbLocPos = 0;
    uint32_t ulLocalPosUart = 0;
    uint32_t ulStrleng     = 0;
    UartLogType UartLog;
	uint64 ulHighRes; 
	
	if ( Time_Stamp != TIMESTAMP_DISABLE )
	{
		uint64 ulReadTmr  =   ( ( uint64 ) HWIO_IN( SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0 ) |
							  ( ( uint64 ) HWIO_IN( SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0 ) & ( uint64 )0x0FFFU ) << 32U );

		/* NOTE: 1 tick time in micro second = 1000000/19200000 = 10/192, freq 19.2Mhz */
		ulHighRes  =   ( ( ulReadTmr * 10U ) / TIMESTAMP_FREQ_DIV );
		ulStrleng = TIMESTAMP_STRING_SIZE + CORE_INDEX_PRINT_SIZE;
	}

    ulStrleng += vsnprintf(NULL, 0, pcMessage, vargs );

    ulLocalPos = atomic_fetch_add(pLogMemoryPos, ulStrleng);
    ulLocalPos %= ulDebugLogSize;
	ulMbLocPos = ulLocalPos;
	
	if ( Time_Stamp != TIMESTAMP_DISABLE )
	{
		ulLocalPos += (uint32_t)snprintf(&pcLogBuffer[ulLocalPos],
										 (ulDebugLogSize + ulDebugExtraSize - ulLocalPos),
										 "c%1u[%6d.%06ds]",
										 get_curr_phys_cpu_num(),
										 ( uint32_t ) ( ulHighRes / configXO_MICROSEC ),
										 ( uint32_t ) ( ulHighRes % configXO_MICROSEC ) );
	}

    if (ulLocalPos < (ulDebugLogSize + ulDebugExtraSize))
    {
        ulLocalPos += (uint32_t)vsnprintf(&pcLogBuffer[ulLocalPos],
                                          (ulDebugLogSize + ulDebugExtraSize - ulLocalPos),
                                          pcMessage,
										  vargs);
    }

    /* check wrap around and copy trailing string to the head of the buffer */
    if ((ulLocalPos % ulDebugLogSize) < ulStrleng)
    {
        (void)memcpy_s(pcLogBuffer,
                       ulDebugLogSize,
                       &pcLogBuffer[ulDebugLogSize],
                       (ulLocalPos % ulDebugLogSize));
    }
    if ( eLevel <= eLogUartLevel ) {
    ulLocalPosUart = atomic_fetch_add(pLogUartWritePos, 1);
    ulLocalPosUart %= (ulUartLogSize/8);
    UartLog.PrintAddress = (OS_DEBUGLOG_STARTADDRESS + ulLocalPos) - ulStrleng;
    UartLog.DataLen = ulStrleng;
    pcUartLogBuffer[ulLocalPosUart] = UartLog;
    }
}

static void prvPrintToUart(void)
{

    uint32_t UartLogWritePtr;
    uint32_t UartLogReadPtr;
    UartLogType Uart_LogDetails;
    uint32_t ulUartWaitTimeUs = 0;
    uint32_t ulUartWaitTimeMs = 0;

    invalidate_dcache();
    while (atomic_load(pLogUartReadPos) < atomic_load(pLogUartWritePos))
    {
        UartLogReadPtr = atomic_fetch_add(pLogUartReadPos, 1);
        UartLogReadPtr%=(ulUartLogSize/8);
        Uart_LogDetails = pcUartLogBuffer[UartLogReadPtr];
        
        if((Uart_LogDetails.PrintAddress >= 0x01f00000 && Uart_LogDetails.PrintAddress <= 0x01f05fff) &&(Uart_LogDetails.DataLen !=0)&&(Uart_LogDetails.DataLen <2048))
        {
            if(bUartConnectionStatus(uartDEBUG_CHANNEL) == UART_CONNECTED)
            {
                // currently the length is restricted to 2048 bytes
                (void)ulUartWrite(uartDEBUG_CHANNEL, (const char *)Uart_LogDetails.PrintAddress, Uart_LogDetails.DataLen);
                ulUartWaitTimeUs = (uint32_t)ComputeUartWaitTime(Uart_LogDetails.DataLen);

                if(Uart_DebugLogStatus == 0)
                {
                    busywait(ulUartWaitTimeUs);
                }
                else
                {
                    ulUartWaitTimeMs = (uint32_t)Convert_Microsecs_to_Millisecs(ulUartWaitTimeUs);
                    ( void ) vFreeRTOSTaskDelay(ulUartWaitTimeMs);
                }
            }
            if(eLogMBState == LOG_MB_WORKING)
            {
                (void)slMailboxWrite(MAILBOX_CONSOLE,Uart_LogDetails.DataLen,(uint8 *)(Uart_LogDetails.PrintAddress));
            }
            Uart_LogDetails.PrintAddress =0;
            Uart_LogDetails.DataLen = 0;
            pcUartLogBuffer[UartLogReadPtr] = Uart_LogDetails;
        }
        else
        {
            break;
        }
    }
}

void vLogMessage(TimeStampInfo Time_Stamp, LogLevel_e eLevel, const char *pcMessage, ...)
{
	va_list args = { 0 };
    uint8 cpu_id = get_curr_phys_cpu_num();
    uint32 pLogUartReadyPosLoc =0;
    if (eLevel <= eLogMemoryLevel)
    {
    	va_start(args, pcMessage);
        prvPrintToMemory(Time_Stamp, eLevel,pcMessage,args);
        va_end(args);
    }

    pLogUartReadyPosLoc = *(volatile uint32*)DEBUGLOG_UART_READYSTATE_ADDR;
        if ((LOG_UART_WORKING == eLogUartState) &&
            (LOG_NOUART != eLevel) &&
            (eLevel <= eLogUartLevel) &&
			(pLogUartReadyPosLoc == 0xAA))
        {
			      if(  IPCC_EOK != IPCC_Trigger(xUartConsoleTask_IpccHandle[cpu_id], (IPCC_C_SAIL0),UartConsoleSIGID,UartConsoleSIGID))
            {
                // DEBUG_LOG( SAIL_ERROR,"IPCC_Trigger to APSS_NS failed.\n\r");
            }

        }
}

void vUartConsoleHandler( IPCC_CBData nData, IPCC_Client eSenderID, IPCC_Signal nSignal)
{
    BaseType_t xQueue_Pushstatus = pdFAIL;
    EventBits_t xEventBitsToSet = 0x1;
    /* Set the corresponding event*/
    xQueue_Pushstatus = xFreeRTOSEventGroupSetBitsFromISR( xEventGroupUartConsole,
                                                   xEventBitsToSet );
    freertosYIELD_FROM_ISR();

}

void vSAILConsoleUarttask(void *pvParameters)
{
    (void)pvParameters;
    const EventBits_t  xFaultEventBitMask  =  0x1;
    EventBits_t xEventBitStatus = 0x0;
    uint8 ucCoreCount;
    uint8 ulcpu_ID;
    /* default lock */
    Uart_DebugLogStatus = 1;
    /* Get the Current CPU Id.*/
	ulcpu_ID = get_curr_phys_cpu_num();
    /* Attach the MD MPROC  for the sail*/
    if (  IPCC_EOK != IPCC_AttachEx(&xUartConsoleTask_IpccHandle[ulcpu_ID],IPCC_P_SAIL_MPROC,(IPCC_Client)(IPCC_C_SAIL0+ulcpu_ID),ulcpu_ID))
    {
        DEBUG_LOG( SAIL_ERROR,"IPCC Attach failed.\n\r");

    }
    for(ucCoreCount = 0;ucCoreCount<4;ucCoreCount++)
    {
        if ( IPCC_EOK != IPCC_RegisterInterrupt(xUartConsoleTask_IpccHandle[ulcpu_ID],(IPCC_C_SAIL0+ucCoreCount),
    	    	UartConsoleSIGID,UartConsoleSIGID,(IPCC_CB)vUartConsoleHandler,(IPCC_CBData)&ulcpu_ID))
        {
            DEBUG_LOG( SAIL_ERROR,"IPCC Register interrupt failed.\n\r");
        }
    }
    *(volatile uint32*)DEBUGLOG_UART_READYSTATE_ADDR = 0xAA;
    prvPrintToUart();
	for( ; ; )
	{
		xEventBitStatus = 0x0;
        if( xFreeRTOSEventGroupWaitBits( xEventGroupUartConsole,        /* The event group handle */
                xFaultEventBitMask,     /* The event bits to be waited for */
                pdTRUE,                 /* pdTRUE: Clear bits (in kernel ) on exiting the API */
                pdFALSE,                /* pdFALSE: Wait for ANY of the bits set in xFaultEventBitMask */
                &xEventBitStatus,       /* Retrieve the status of the event bits on exit */
                freertosMAX_DELAY           /* Maximum wait */
        ) == pdPASS )
        {
		    prvPrintToUart();
        }
	}
	return;

}

BaseType_t xSAILConsoleUartTaskRTOSFeatureInit( CPUIdType_e  xSchdCore)
{
    BaseType_t xCreateResult = pdPASS;

    xCreateResult = xFreeRTOSEventGroupCreate(&xEventGroupBufferUartConsole,&xEventGroupUartConsole);

    if( pdPASS != xCreateResult )
    {
        DEBUG_LOG( SAIL_DEBUG, "Mailbox Event Group Creation Failed.\n\r" );
    }
    return xCreateResult;
}

BaseType_t xSAILConsoleUartTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  xTaskPrior  )   //added to initialize the task
{
    BaseType_t xCreateResult;
    UBaseType_t uxCoreAffinityMask;
	/* Shell task param. */
	TaskParams_t xShellTaskParam =
	{
        .pvTaskCode     = vSAILConsoleUarttask,                 /* The function that implements the task being created. */
        .pcName         = "vSAILConsoleUarttask",              /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer   = &xUartConsoleTaskTCB,              /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer = xUartConsoleTaskStack,             /* The buffer allocated for use as the task stack. */
		.usStackDepth   = UartConsoleTASK_STACK_SIZE,      /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters   = NULL,                               /* The task parameter, not used in this case. */
        .uxPriority     = ( xTaskPrior ),                         /* The priority assigned to the task being created. */
        .xRegions       = {                                   /* The MPU task parameters. */
                                    { NULL, 0UL, 0UL},    /* No additional region definitions are required. */
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL}
            }
	};
    uxCoreAffinityMask = ( 1 << xSchdCore );

	xCreateResult = xFreeRTOSTaskCreateAffinitySet( &xShellTaskParam, uxCoreAffinityMask, &xSAILConsoleUartTaskHandle);

	if(xCreateResult != pdPASS)
	{
		xCreateResult = pdFAIL;
	}


    return xCreateResult;
}
