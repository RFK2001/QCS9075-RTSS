/*
 * Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
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
#include "busywait.h"

#define TIMESTAMP_FREQ_DIV              (192ULL)
#define ComputeUartWaitTime(DataLen)    ((((DataLen) * 1000000) / 14400) + 3000)

typedef void (*pvDebug_Log_UART_Rx_Notification)(volatile void *rslt);
static pvDebug_Log_UART_Rx_Notification pvDebugLogUARTRxNotifyCb = NULL;
static atomic_uint      *pLogMemoryPos = (atomic_uint *)HYP_DEBUGLOG_MEM_INDEX_ADDR;
static atomic_uint      *pLogUartWritePos = (atomic_uint *)DEBUGLOG_UART_WRINDEX_ADDR;
static atomic_uint      *pLogUartReadPos = (atomic_uint *)DEBUGLOG_UART_RDINDEX_ADDR;
static char             *pcLogBuffer = (char *)HYP_DEBUGLOG_STARTADDRESS;
static UartLogType      *pcUartLogBuffer = (UartLogType *)UART_SHARED_AREA_STARTADDRESS;

static const uint32_t   ulDebugLogSize = HYP_DEBUGLOG_SIZE;
static const uint32_t   ulDebugExtraSize = HYP_DEBUGLOG_EXTRA_SIZE;
static const uint32_t   ulUartLogSize = UART_SHARED_LOG_SIZE;

static LogLevel_e       eLogMemoryLevel = LOG_INFO;
static LogLevel_e       eLogUartLevel = LOG_WARNING;
static LogUartState_e   eLogUartState = LOG_UART_STOP;

extern volatile uartInitializationCoreId_e uartInitCoreId;

static void prvPrintToUart(void);

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

    if (LOG_UART_WORKING == eLogUartState && uartInitCoreId == (uartInitializationCoreId_e)get_curr_phys_cpu_num())
    {
        /* print memory buffer to UART when UART is enabled. This will take time */
        prvPrintToUart();
    }
}

void vLogSetLevel(LogLevel_e eNewLevel)
{
    eLogUartLevel = eNewLevel;
}

LogLevel_e vLogGetLevel(void){
    return 	eLogUartLevel;
}

void vLogSetMemoryLevel(LogLevel_e eNewLevel)
{
    eLogMemoryLevel = eNewLevel;
}

void vLogUartLogBufferDeinit(void)
{
    atomic_store(pLogUartReadPos, atomic_load(pLogUartWritePos));
}

static void prvPrintToMemory(TimeStampInfo Time_Stamp, const LogLevel_e eLevel, const char *pcMessage,va_list vargs)
{
    uint32_t ulLocalPos = 0;
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
	
	if ( Time_Stamp != TIMESTAMP_DISABLE )
	{
		ulLocalPos += (uint32_t)snprintf(&pcLogBuffer[ulLocalPos],
										 (ulDebugLogSize + ulDebugExtraSize - ulLocalPos),
										 "h%1u[%6d.%06ds]",
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
		// Clearing the extra size region buffer into which the string overflowed
        memset((void *)OS_DEBUGLOG_STARTADDRESS+OS_DEBUGLOG_SIZE, 0x0, (ulLocalPos % ulDebugLogSize));
        
    }
	/* Filter to print only eLogUartLevel logs to UART console. */
    if ( eLevel <= eLogUartLevel ) {
		ulLocalPosUart = atomic_fetch_add(pLogUartWritePos, 1);
		ulLocalPosUart %= (ulUartLogSize/8);
		UartLog.PrintAddress = (HYP_DEBUGLOG_STARTADDRESS + ulLocalPos) - ulStrleng;
		UartLog.DataLen = ulStrleng;
		pcUartLogBuffer[ulLocalPosUart] = UartLog;
	}
}

static void prvPrintToUart(void)
{

    uint32_t UartLogWritePtr;
    uint32_t UartLogReadPtr;
    UartLogType Uart_LogDetails;
    uint32_t ulUartWaitTime = 0;

    if(bUartConnectionStatus(uartDEBUG_CHANNEL) == UART_CONNECTED)
    {
        while (atomic_load(pLogUartReadPos) < atomic_load(pLogUartWritePos))
        {
        	
        	UartLogReadPtr = atomic_fetch_add(pLogUartReadPos, 1);
        	UartLogReadPtr%=(ulUartLogSize/8);
        	Uart_LogDetails = pcUartLogBuffer[UartLogReadPtr];
        	if(Uart_LogDetails.PrintAddress != 0 && Uart_LogDetails.DataLen !=0)
        	{
        	    (void)ulUartWrite(uartDEBUG_CHANNEL, (const char *)Uart_LogDetails.PrintAddress, Uart_LogDetails.DataLen);
        	    ulUartWaitTime = (uint32_t)ComputeUartWaitTime(Uart_LogDetails.DataLen);
    			busywait(ulUartWaitTime); /* Add delay to push log going out of UART Tx FIFO */
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
}

void vLogMessage(TimeStampInfo Time_Stamp, LogLevel_e eLevel, const char *pcMessage, ...)
{
	va_list args = { 0 };
    uint8 cpu_id = get_curr_phys_cpu_num();
    if (eLevel <= eLogMemoryLevel)
    {
    	va_start(args, pcMessage);
        prvPrintToMemory(Time_Stamp, eLevel,pcMessage,args);
        va_end(args);
    }

    if(cpu_id == 0)
    {
        if ((LOG_UART_WORKING == eLogUartState) &&
            (LOG_NOUART != eLevel) &&
            (eLevel <= eLogUartLevel))
        {
            prvPrintToUart();
        }
    }
}

