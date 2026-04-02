/**************************************************************************************************
    Copyright (c) 2021, 2024-2025 Qualcomm Technologies, Inc.
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
**************************************************************************************************/
/*=================================================================================================
    File Name          : uart.c
    Component Name     : UART Device driver
    Description        : UART Device driver Initial version
    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/uart/src/uart.c#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <stdio.h>
#include "types.h"
#include "debug_log.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "uart.h"
#include "qup_common_hwio.h"
#include "busywait.h"
#include "ClockDriver.h"
#include "interrupts.h"
#include "cache_ops.h"
#include "common_functions.h"
#include <string.h>
#include <libfdt.h>
#include "fdt_utils.h"
#include "gpio.h"
#include "chipinfo.h"
#include "chipinfodefs.h"
#include "platforminfodefs.h"
#include "err_fatal.h"
#include "sailbsp_mutex.h"
#ifndef SAILEL2
#include "sleepEl1.h"
#endif

/*=================================================================================================
**                                        Local defines and macros                               **
=================================================================================================*/
#define uartNUMBER_OF_UART_PINS                2U
#define uartIRQ_CLEAR_MASK                     0xFFFFFFFFU
#define uartINITIATE_TRANSFER                  0x08000000U
#define uartBYTES_PER_FIFO_REG                 4
#define uartBITS_PER_BYTE                      8
#define uartM_IRQ_ERROR_MSK                    0x3320000EU
#define uartWORD_LEN                           8
#define uartSTALE_COUNT                        220
#define uartPACKING_CFG0                       0x4380EU
#define uartPACKING_CFG1                       0xC3E0EU
#define uartPOLLING_PERIOD		               2500U
#define uartRX_NOTIFY_THRESHOLD                100U
#define uartCABLE_DETECTION_LOOP_CNT           20U
#define uartCABLE_DETECTION_DELAY              20U
#define SIZE_4                                 4U
#define TICK_IS_DISCONNECTED                   0xABU
#define CONNECTION_DONE                        0xAAU
#define UART_FIFO_BUFF_SIZE                    256U
#ifdef SAILEL2
#define  UART_CRITCAL_SECTION_START()                            mutex_lock(&stUartCoreLock)
#define  UART_CRITCAL_SECTION_END()                              mutex_unlock(&stUartCoreLock)
#endif
/*=================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs         **
=================================================================================================*/
/* Clock settings type definition*/
typedef struct
{
    uint32 ulbit_rate;
    uint32 ulinput_freq;
    uint16  ucdivider;
} uartClockSettingsType;

UART_DATA static uint32  ulPollingTimeoutus;
UART_DATA static uint32  ulRxNotifThreshold;

UART_DATA static uint32  ulPollingTimeoutus =  uartPOLLING_PERIOD;
UART_DATA static uint32  ulRxNotifThreshold =  uartRX_NOTIFY_THRESHOLD;
/*=================================================================================================
**                                        Global variables and constants                         **
=================================================================================================*/
/* UartActiveJob variable will hold the Current job information*/
UART_DATA static volatile uartJobHandleType UartActiveJob[MAX_NO_OF_SERIAL_ENGINE];
/* UART Receiver buffer. Since the UART can receive the data without calling an
   read API in Interrupt mode this buffer is required to store the received data.
   Later this data will be read from the user by calling Uart read API.*/
UART_DATA static uartInitStatusType_e xUartInitStatus[MAX_NO_OF_SERIAL_ENGINE];
/* Uart clock settings for different baud rate */
static const uartClockSettingsType Uart_BaudTable[] =
{
    /* bit_rate, input_freq, divider */
	{       9600,    7372800,     768 },
	{     115200,    7372800,      64 },
	{     230400,    7372800,      32 },
	{     921600,   14745600,      16 },
    {0U}
};

#ifdef SAILEL2
/* Uart connection status type*/
typedef enum
{
     TIC_DISCONNECTED = 0,
     TIC_CONNECTED = 1
} ticConnectionStatusType_e;

mutex_t stUartCoreLock = {0};
#endif
UART_DATA static uartHWConfigType xUartHwConfig[MAX_NO_OF_SERIAL_ENGINE] = {0};
UART_DATA static uartConnectionStatusType_e uartConnectionStatus = UART_CONNECTED;
UART_DATA static uint8 *UartVIP_SendDataDMA = (uint8 *) UART_VIP_TX_STARTADDR;
UART_DATA static uint32 ulQupCommonBase;
UART_DATA static GPIOConfigType UartResetStatePinCfg[MAX_NO_OF_SERIAL_ENGINE][uartNUMBER_OF_UART_PINS] = {0x0u};

UART_DATA uint8 ucFIFOReadBuf[UART_FIFO_BUFF_SIZE]   = {0x00};
UART_DATA static uint32 uartSleepHandle = 0U;
volatile uartInitializationCoreId_e uartInitCoreId = UNINITIALIZED;
/*=================================================================================================
**                                Local function prototypes                                       **
=================================================================================================*/
static uartStatusType_e prvUartSEInit(uartHWConfigType *config, uint8 ucHardwareID);
static void prvUartFiFoRead(uint32 ulSE_Base, uartChannelIdType_e ucChannelId);
static void prvUartFIFOWrite(uint32 ulSE_Base, uartChannelIdType_e ucChannelId);
static uartStatusType_e prvUartWriteErrorcheck(const uartChannelIdType_e ucChannelId);
static uartStatusType_e prvUartChannelIdcheck(const uartChannelIdType_e ucChannelId);
static uartStatusType_e prvUartReadErrorcheck(const uartChannelIdType_e ucChannelId);
static void prvUARTCfgIntrRegister( uartHWConfigType *config);
static uartStatusType_e prvUartInitErrorCheck(uartHWConfigType *pxUartHwConfig);
static uartStatusType_e prvUartInitStatusCheck(uint8 ucChannelId);
static void uartINTRInit(uartHWConfigType *config);
static void prvUARTClockDisable( uint8 ucHardwareID);
static ClockResult prvUartClockEnable( uint8 ucHardwareID);
static void prvUartSEDeInit(uint8 ucChannelId);
static uartStatusType_e prvUartLoadDeviceTreeSettings(uint8 ucHardwareID);
static uartConnectionStatusType_e uartConnectionCheck(uint32 ulSE_Base);
static void prvUartPinCtlReset(uint8 ucHardwareID);
static void prvUartEnableInterrupt(uint8 ucHardwareId, bool enable);
#ifdef SAILEL2
static ticConnectionStatusType_e prvIsTicCardConnected();
#endif
#ifndef SAILEL2
    static void prvUartDeInit_Sleep( const sleepModeType_e eState );
#endif
/*=================================================================================================
**                                        Interrupt Handler                                      **
=================================================================================================*/
#ifndef SAILEL2
static void UartGeniSEIsr(void *arg);
#else
static enum handler_return UartGeniSEIsr(void *arg);
#endif


/*=================================================================================================
**                                        Global functions definition                            **
=================================================================================================*/
/*=================================================================================================
 @Service name        xUartInit
 @Description         This API Initialize the serial engine which is
                      configured for the UART driver. It will configure the
                      required clock and GPIO.
 @param[in]           uartCoreCfgType - Configuration pointer of UART
 @param[out]          NA
 @param[in, out]      NA
 @return              uartStatusType_e - UART initialization status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
/* Common Uart driver is used for El2 and El1. Init is done only in El2. TODO: enalbe RX Notifications for SAIL console/test framework */
uartStatusType_e xUartInit( uint8 ucHardwareID)
{
    uartStatusType_e eStatus = UART_ERROR_UNDEFINED;
    uint32 ulSE_Base;

	#ifdef SAILEL2
    	UART_CRITCAL_SECTION_START();
	#endif
	if(ucHardwareID >= MAX_NO_OF_SERIAL_ENGINE)
	{
		eStatus = UART_HW_NOT_EXIST;
		return eStatus;
	}

	#ifdef lemans

		/*
		 * Applicable only for LeMans.
		 * TIC Detection happened in EL2. Now , EL1 Uart will readout Status register
		 * and decided whether to do UartInit or not.
		 */

		if ( *(volatile uint32*)UART_DEBUG_CONNECTION_STATUS == TICK_IS_DISCONNECTED && ucHardwareID == uartDEBUG_HW) 
		{
			eStatus = UART_SUCCESS;
			goto End;
		}

		#ifdef SAILEL2

		    if(ucHardwareID == uartDEBUG_HW && prvIsTicCardConnected() == TIC_DISCONNECTED)
		    {
		        xUartInitStatus[uartDEBUG_HW] = UART_UNINITIALIZED;
		        uartConnectionStatus = UART_DISCONNECTED;
		        *(volatile uint32*)UART_DEBUG_CONNECTION_STATUS = TICK_IS_DISCONNECTED; // Marked for TIC Connected signal
		        eStatus =  UART_SUCCESS;
		        goto End;
		    }

	    #endif

	#endif
 
    eStatus = prvUartLoadDeviceTreeSettings(ucHardwareID);
    if( eStatus == UART_SUCCESS)
    {
		eStatus = prvUartInitErrorCheck(&xUartHwConfig[ucHardwareID]);
		/* Check if the Configuration is not NULL*/
		if (UART_SUCCESS == eStatus)
		{
			ulSE_Base = xUartHwConfig[ucHardwareID].uluart_base;

			if (CLOCK_SUCCESS == prvUartClockEnable(ucHardwareID))
			{
				/* Initialize the Serial Engine*/
				eStatus = prvUartSEInit(&xUartHwConfig[ucHardwareID],ucHardwareID);
				if(eStatus == UART_SUCCESS)
				{
                    #ifdef CONFIG1
					if(ucHardwareID == uartDEBUG_HW)
                    #else
					if(ucHardwareID == uartDEBUG_CHANNEL)
                    #endif /* CONFIG1 */
					{
		                if((*(volatile uint32*)UART_CONNECTION_TEST) != CONNECTION_DONE)
		                {
                            uint32 cable_detection_loop_count = 0;
                            /* Query Serial Cable Status weather its connected or not.
                            Update uart_connection_status to TRUE if cable is connected
                            Update uart_connection_status to FALSE if cable is not connected */
                            do{
                                uartConnectionStatus = uartConnectionCheck(ulSE_Base);
                                if(uartConnectionStatus == UART_CONNECTED) 
						    	{
                                    break;
                                }
                                busywait(uartCABLE_DETECTION_DELAY);
                                cable_detection_loop_count++;
                            }while ((cable_detection_loop_count) < uartCABLE_DETECTION_LOOP_CNT);
							*(volatile uint32*)UART_CONNECTION_TEST = CONNECTION_DONE;
			                *(volatile uint32*)UART_DEBUG_CONNECTION_STATUS = uartConnectionStatus;
						}else
						{
							uartConnectionStatus = (*(volatile uint32*)UART_DEBUG_CONNECTION_STATUS);
						}
                        if(UART_CONNECTED == uartConnectionStatus)
                        {
                            eStatus = UART_SUCCESS;
                        }
                        else
                        {
                            eStatus = UART_ERROR_CONFIG;
                            prvUartSEDeInit(ucHardwareID);
                            prvUARTClockDisable(ucHardwareID);
                        }
					}
				    /* Check if the Initialization is success*/
				    if(eStatus == UART_SUCCESS)
				    {
					    if(xUartHwConfig[ucHardwareID].eUartOpMode == UART_DMA_MODE)
					    {
						    if( ucHardwareID == uartVIP_HW)
						    {
							    UartActiveJob[ucHardwareID].psRxBufferPtr = (uint8 *)UART_VIP_RX_STARTADDR;
						    }
						    else if( ucHardwareID == uartDEBUG_HW)
						    {
							    UartActiveJob[ucHardwareID].psRxBufferPtr = (uint8 *)UART_RXBUFF_STARTADDR;
                                if(uartInitCoreId == UNINITIALIZED)
                                {
                                    uartInitCoreId = (uartInitializationCoreId_e)get_curr_phys_cpu_num();
                                }
						    }
						    else
						    {
							    ; /* For MCDC*/
						    }
						    /* Update the buffer address that needs to be updated*/
						    REG_OUT(ulSE_Base,DMA_RX_PTR_L,
							    FLD_SET(DMA_RX_PTR_L,RX_PTR_L,
									    (uint8 *)UartActiveJob[ucHardwareID].psRxBufferPtr));
						    REG_OUT(ulSE_Base,DMA_RX_PTR_H,
							    FLD_SET(DMA_RX_PTR_H,RX_PTR_H,0U));
						    /* reset the DMA RX attribute*/
						    REG_OUT(ulSE_Base,DMA_RX_ATTR,0U);
						    /* update the buffer length for the DMA transfer*/
						    REG_OUT(ulSE_Base,DMA_RX_LENGTH,
							    FLD_SET(DMA_RX_LENGTH,RX_LENGTH,UART_RXBUFF_SIZE));
					    }
					    else
					    {
						    if( ucHardwareID == uartVIP_HW)
						    {
							    UartActiveJob[ucHardwareID].psRxBufferPtr = (uint8 *)&ucFIFOReadBuf;
						    }
						    else if( ucHardwareID == uartDEBUG_HW)
						    {
							    UartActiveJob[ucHardwareID].psRxBufferPtr = (uint8 *)UART_RXBUFF_STARTADDR;
                                if(uartInitCoreId == UNINITIALIZED)
                                {
                                    uartInitCoreId = (uartInitializationCoreId_e)get_curr_phys_cpu_num();
                                }
						    }
						    else
						    {
							    ; /* For MCDC*/
						    } 
					    }
					    REG_OUT(ulSE_Base, GENI_M_IRQ_CLEAR, uartIRQ_CLEAR_MASK);
					    REG_OUT(ulSE_Base, GENI_S_IRQ_CLEAR, uartIRQ_CLEAR_MASK);
					    REG_OUT(ulSE_Base, DMA_TX_IRQ_CLR, uartIRQ_CLEAR_MASK);
					    REG_OUT(ulSE_Base, DMA_RX_IRQ_CLR, uartIRQ_CLEAR_MASK);
					    
					    UartActiveJob[ucHardwareID].Uart_DriverStatus  =  UART_CHANNEL_READY;
					    xUartInitStatus[ucHardwareID] = UART_INITIALIZED;
					    /* Configure and enable the Interrupt handler  */
					    uartINTRInit(&xUartHwConfig[ucHardwareID]);
					    #if 0
						    if(ucHardwareID == uartVIP_HW)
						    {
							    if ( 0x0u == uartSleepHandle )
							    {
							        if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1(&prvUartDeInit_Sleep,&uartSleepHandle))
							        {
							            DEBUG_LOG(SAIL_INFO,"prvUartDeInit_Sleep Sleep Reg Failed\n\r");
							        }
							    }
						    }
					    #endif
				    }
			    }
			    else
			    {
				    eStatus = UART_ERROR_CLOCK_ENABLE_FAIL;
			    }
		    }
		}
    }

    End:
		#ifdef SAILEL2
        	UART_CRITCAL_SECTION_END();
		#endif
	    /* Return the Status*/
	    return eStatus;
}



/*=================================================================================================
 @Service name        ulUartWrite
 @Description         This API will transmit the data over the UART. It
                      support both polling and interrupt mode.
 @param[in]           buf - Tx buffer pointer
					  bytes_to_tx - Number of bytes to transfer
					  ucChannelId - ucChannelID number of UART
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 - number of bytes transferred
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous / asynchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
uartStatusType_e ulUartWrite(uartChannelIdType_e ucChannelId, const char* buf, uint32 bytes_to_tx)
{
    uint32 ulSE_base;
    uint32 ulTxSize = 0U;
    uint32 ulPolling_counter = 0U;
	uartStatusType_e xErrorValue = UART_SUCCESS;
	uint16 count = 0;
	
	if(ucChannelId >= MAX_NO_OF_SERIAL_ENGINE)
	{
		xErrorValue = UART_HW_NOT_EXIST;
		return xErrorValue;
	}
    xErrorValue = prvUartWriteErrorcheck(ucChannelId);
    if(UART_SUCCESS == xErrorValue)
    {
        /* Check the input parameter is valid*/
        if((buf != NULL) && (bytes_to_tx != 0U))
        {
            /* Update the transfer request information into the ActiveJob handle*/
            UartActiveJob[ucChannelId].ulTxBufferLength = bytes_to_tx;
            UartActiveJob[ucChannelId].psTxBufferPtr = buf;
            UartActiveJob[ucChannelId].ulTransmittedLength = 0U;
            /* Read the SE base address*/
            ulSE_base = xUartHwConfig[ucChannelId].uluart_base;
            /* Write the length for transfer*/
            REG_OUT(ulSE_base, UART_TX_TRANS_LEN, bytes_to_tx);
            /* Initiate the Command to transfer the UART data */
            REG_OUT(ulSE_base, GENI_M_CMD0, uartINITIATE_TRANSFER);
            if(xUartHwConfig[ucChannelId].eUartOpMode == UART_FIFO_MODE)
            {
                /* Update the TX water mark register*/
                REG_OUT(ulSE_base, GENI_TX_WATERMARK_REG, 1);
            }
            else if(xUartHwConfig[ucChannelId].eUartOpMode == UART_DMA_MODE)
            {
            	if(ucChannelId == uartDEBUG_CHANNEL )
            	{
                    /* Update the buffer address that needs to be transfered*/
                    REG_OUT(ulSE_base,DMA_TX_PTR_L,
                            FLD_SET(DMA_TX_PTR_L,TX_PTR_L,UartActiveJob[ucChannelId].psTxBufferPtr));
            	}
            	else if(ucChannelId == uartVIP_CHANNEL)
            	{
            		for(count = 0; count < bytes_to_tx; count++)
            		{
            			UartVIP_SendDataDMA[count] = buf[count];
            		}
                    /* Update the buffer address that needs to be transfered*/
                    REG_OUT(ulSE_base,DMA_TX_PTR_L,
                            FLD_SET(DMA_TX_PTR_L,TX_PTR_L,0x01F05200));
            	}
            	else
            	{
            		;/* For MCDC*/
            	}

                REG_OUT(ulSE_base,DMA_TX_PTR_H,
                             FLD_SET(DMA_TX_PTR_H,TX_PTR_H,0U));

                /* Set the End of Transfer attribute.*/
                REG_OUT(ulSE_base,DMA_TX_ATTR,
                             FLD_SET(DMA_TX_ATTR,EOT,1));
                /* Configure the buffer length*/
                REG_OUT(ulSE_base,DMA_TX_LENGTH,
                        FLD_SET(DMA_TX_LENGTH,TX_LENGTH,
						        UartActiveJob[ucChannelId].ulTxBufferLength));
            }
            /* Check if the Polling mode is configured*/
            else if(xUartHwConfig[ucChannelId].eUartOpMode == UART_POLLING_MODE)
            {
                /* Continue to send the data till all the requested number of data is transferred*/
                do
                {
                    REG_OUTF(ulSE_base, GENI_M_IRQ_CLEAR,M_CMD_DONE_CLEAR,1);
                    /* Write the Data into the TX FIFO*/
                    prvUartFIFOWrite(ulSE_base, ucChannelId);
                    ulPolling_counter = 0U;
                    /* Wait till all the data written in the FIFO are transferred*/
                    while(   (REG_INF(ulSE_base, GENI_M_IRQ_STATUS,M_CMD_DONE) != 1U)
                          && (  ulPolling_counter
					          < ulPollingTimeoutus))
                    {
                        /* Wait for 1us */
                        busywait(1);
                        ulPolling_counter++;
                    }
                }while( UartActiveJob[ucChannelId].ulTransmittedLength
                                	   < bytes_to_tx);
                /*}while( UartActiveJob[ucChannelId].ulTransmittedLength
                 	   < UartActiveJob[ucChannelId].ulTxBufferLength);*/
                /* Set the UART status to done to indicate that the transfer is done*/
                UartActiveJob[ucChannelId].Uart_DriverStatus = UART_CHANNEL_READY;
            }
            else
            {
                /* Dummy else*/
            }

        }
        else
        {
        	xErrorValue = UART_ERROR_NULL_PTR;
        }
    }
    /* Return the stauts */
    return xErrorValue;
}

/*=================================================================================================
 @Service name        ulUartRead
 @Description         This API will receive the data over the UART. It
                      support both polling and interrupt mode.
 @param[in]           bytes_to_rx - Number of bytes to transfer
					  buf - Rx buffer pointer
					  ucChannelId - ucChannelID number of UART
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 - number of bytes received
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Asynchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
uint32 ulUartRead(uartChannelIdType_e ucChannelId, char* buf, uint32 bytes_to_rx)
{
    uint32 ulSE_base;
    uint32 ulRxSize = 0U;
    uint32 ulcount;
	uartStatusType_e xErrorValue = UART_SUCCESS;

	if(ucChannelId >= MAX_NO_OF_SERIAL_ENGINE)
	{
		xErrorValue = UART_HW_NOT_EXIST;
		return xErrorValue;
	}
    xErrorValue = prvUartReadErrorcheck(ucChannelId);

    if( UART_SUCCESS == xErrorValue)
    {
        /* Check the input parameter is valid*/
        if((buf != NULL) && (bytes_to_rx != 0U))
        {
			/* Read the SE base address*/
            ulSE_base = xUartHwConfig[ucChannelId].uluart_base;
            /* update the RX buffer length*/
            UartActiveJob[ucChannelId].ulRxBufferLength = bytes_to_rx;
            /* Check if the polling mode is configured*/
            if(xUartHwConfig[ucChannelId].eUartOpMode == UART_POLLING_MODE)
            {
                /* Initialize the RX related information. In Interrupt mode the RX related
                informaiton will be reseted by notification function.*/
                UartActiveJob[ucChannelId].ulReceivedLength = 0U;
                UartActiveJob[ucChannelId].ulRxWritePtr = 0U;
                UartActiveJob[ucChannelId].ulRxReadPtr = 0U;
                /* Read the data from the FIFO*/
                prvUartFiFoRead(ulSE_base, ucChannelId);
                UartActiveJob[ucChannelId].Uart_DriverStatus = UART_CHANNEL_BUSY;
			}
            /* Calculate the number of data can be read*/
            ulRxSize = (bytes_to_rx < UartActiveJob[ucChannelId].ulReceivedLength) ? (bytes_to_rx) : (UartActiveJob[ucChannelId].ulReceivedLength);
            /* Copy the received data from receive buffer to the user buffer*/
            for(ulcount = 0U; ulcount < ulRxSize ; ulcount++)
            {
                *buf++ = UartActiveJob[ucChannelId].psRxBufferPtr[UartActiveJob[ucChannelId].ulRxReadPtr];
                UartActiveJob[ucChannelId].ulRxReadPtr = (UartActiveJob[ucChannelId].ulRxReadPtr + 1U)
                       				                      % UART_RXBUFF_SIZE ;
            }
        }
        else
        {
        	xErrorValue = UART_ERROR_NULL_PTR;
        }
    }
	/* Set the UART status to Busy to indicate the transfer is completed*/
    UartActiveJob[ucChannelId].Uart_DriverStatus = UART_CHANNEL_READY;
    /* Return the number of data read.*/
    return ulRxSize;
}

/*=================================================================================================
 @Service name        xUartDeInit
 @Description         This API De-Initialize the serial engine which is
                      configured for the UART driver. It will disable the
                      required clock and GPIO.
 @param[in]           uartCoreCfgType - Configuration pointer of UART
 @param[out]          NA
 @param[in, out]      NA
 @return              uartStatusType_e - UART de-initialization status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
uartStatusType_e xUartDeInit(uint8 ucHardwareID)
{
    uartStatusType_e eStatus = UART_SUCCESS;
    uint32 ulSE_Base;
	uint8 ucCount = 0U;
	
	if(ucHardwareID >= MAX_NO_OF_SERIAL_ENGINE)
	{
		eStatus = UART_HW_NOT_EXIST;
		return eStatus;
	}
	if( xUartInitStatus[ucHardwareID] == UART_UNINITIALIZED )
    {
		eStatus = UART_NOT_INITIALIZED;
    }
	else
	{
		xUartInitStatus[ucHardwareID] = UART_UNINITIALIZED;
		/* DeInitialize the Serial Engine*/
		prvUartSEDeInit(ucHardwareID);
		prvUARTClockDisable(ucHardwareID);
        prvUartPinCtlReset(ucHardwareID);
        UartActiveJob[ucHardwareID].Uart_DriverStatus 	 = UART_CHANNEL_INACTIVE;
        UartActiveJob[ucHardwareID].ulTxBufferLength   	 = 0U;
        UartActiveJob[ucHardwareID].ulRxBufferLength  	 = 0U;
        UartActiveJob[ucHardwareID].ulTransmittedLength  = 0U;
        UartActiveJob[ucHardwareID].ulReceivedLength     = 0U;
        UartActiveJob[ucHardwareID].ulRxWritePtr  		 = 0U;
        UartActiveJob[ucHardwareID].ulRxReadPtr  		 = 0U;
        UartActiveJob[ucHardwareID].psTxBufferPtr        = NULL;
        UartActiveJob[ucHardwareID].psRxBufferPtr	     = NULL;
		eStatus = UART_SUCCESS;

        if (uartDEBUG_HW == ucHardwareID )
        {
            *(volatile uint32*)DEBUGLOG_UART_READYSTATE_ADDR = 0x0; // in Case of Debug Channel Deinit Reset the Ready Marker
			*(volatile uint32*)UART_CONNECTION_TEST = 0U;
            uartInitCoreId = UNINITIALIZED;
        }
        
    }

    /* Return the Status*/
    return eStatus;
}

/*=================================================================================================
 @Service name        getUartClkRegValue
 @Description         This API return UART clock divider value for requested baud rate value.
 @param[in]           uint32 baudrate (UART communication speed)
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 usclkRegValue (UART clock divider value)
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
uint32 getUartClkRegValue(uint32 baudrate)
{
    uint8 ucCount = 0U;
    uint32 ulQupv3HwVer = REG_IN(ulQupCommonBase, QUPV3_HW_VERSION);
    uint32 usclkRegValue = 0x0;

    /* UART Specific configuration */
    /* Get the requested baud rate configuration*/
    ucCount = 0U;
    while(Uart_BaudTable[ucCount].ulbit_rate !=0U)
    {
        if (Uart_BaudTable[ucCount].ulbit_rate == baudrate)
        {
            break;
        }
        ucCount++;
    }

    /* Calculate the clock config Register as per the HPG 3.2.2.2.
        Check if the HW version is greater then 0x10030000*/
    if (ulQupv3HwVer >= 0x10030000U)
    {
        usclkRegValue = ((Uart_BaudTable[ucCount].ucdivider/16U) << 0x4U) | 0x1U;
    }
    else
    {
        usclkRegValue = ((Uart_BaudTable[ucCount].ucdivider/16U/32U) << 0x4U) | 0x1U;
    }

    return usclkRegValue;
}

/*=================================================================================================
**                                        Local function definitions                             **
=================================================================================================*/
/*=================================================================================================
 @Service name        uartConnectionCheck
 @Description         This function check if there UART cable is connected or not.
 @param[in]           ulSE_Base - Base address of QUP SE
 @param[out]          NA
 @param[in, out]      NA
 @return              uartConnectionStatusType_e -> uart cable connected/disconnected
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
static uartConnectionStatusType_e uartConnectionCheck(uint32 ulSE_Base)
{
	uint32 Uart_S_IrqStatus;
	uartConnectionStatusType_e connection_status = UART_CONNECTED;
	
	Uart_S_IrqStatus = REG_IN(ulSE_Base, GENI_S_IRQ_STATUS);
	
	if ((FLD_GET(Uart_S_IrqStatus, GENI_S_IRQ_STATUS, S_GP_IRQ_2)) 
		& !(FLD_GET(Uart_S_IrqStatus, GENI_S_IRQ_STATUS, S_GP_IRQ_3)))
	{
        connection_status =  UART_DISCONNECTED;
 	}
	return connection_status;
}
/*=================================================================================================
 @Service name        UartGeniSEIsr_CB
 @Description         ISR handler for the SE. This ISR will be called for all
                      the events configured at Init function.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              handler_return
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
static void UartGeniSEIsr_CB(void *arg)
{
    uint32 ulSE_base;
    uint32 ulUart_M_IrqStatus;
    uint32 Uart_S_IrqStatus;
    uint32 Dma_TxIrqStatus;
    uint32 Dma_RxIrqStatus;
	uint32 ucHardwareId = (uint32)arg;
    uartStatusType_e lStatus;

	prvUartEnableInterrupt((uint8)ucHardwareId, FALSE);
	/* Read the SE base address*/
	ulSE_base = xUartHwConfig[ucHardwareId].uluart_base;
	/* Read the IRQ status register*/
	ulUart_M_IrqStatus = REG_IN(ulSE_base, GENI_M_IRQ_STATUS);
	/* Read the IRQ status register*/
	Uart_S_IrqStatus = REG_IN(ulSE_base, GENI_S_IRQ_STATUS);

	if((ulUart_M_IrqStatus & uartM_IRQ_ERROR_MSK) != 0U)
	{
		lStatus = UART_ERROR_UNDEFINED;
	}
	if(xUartHwConfig[ucHardwareId].eUartOpMode == UART_FIFO_MODE)
	{
		/* Check if the interrupt is due to RX FIFO Watermark level or RX read last byte*/
        if((FLD_GET( ulUart_M_IrqStatus, GENI_M_IRQ_STATUS, RX_FIFO_WATERMARK) != 0U) ||
            (FLD_GET( ulUart_M_IrqStatus, GENI_M_IRQ_STATUS, RX_FIFO_LAST) != 0U))
        {
            UartActiveJob[ucHardwareId].Uart_DriverStatus = UART_CHANNEL_BUSY;
            /* Call the FIFO read function to read data from the RX FIFO or RX WATERMARK*/
            prvUartFiFoRead(ulSE_base, (uartChannelIdType_e)ucHardwareId);
        }
        if((FLD_GET( ulUart_M_IrqStatus, GENI_M_IRQ_STATUS, RX_FIFO_LAST) != 0U))
        {
            if(xUartHwConfig[ucHardwareId].NotifFuncPtr != NULL)
            {
                /* Call the notification function.
                Note: Expectation is after reading the data the received_length is set to 0. 
                So that the Uart driver will start the new cycle.*/
                xUartHwConfig[ucHardwareId].NotifFuncPtr(&UartActiveJob[ucHardwareId]);
                UartActiveJob[ucHardwareId].ulReceivedLength = 0U;
                /* Make Uart Channel Status to Ready for next Tx/Rx operation */
                UartActiveJob[ucHardwareId].Uart_DriverStatus = UART_CHANNEL_READY;
            }            
        }
        /* Check if the interrupt is due to TX Watermark level*/
        if ( FLD_GET(ulUart_M_IrqStatus, GENI_M_IRQ_STATUS, TX_FIFO_WATERMARK) != 0U)
        {
            /* Call the FIFO write function to write data to the FIFO*/
            prvUartFIFOWrite(ulSE_base, (uartChannelIdType_e)ucHardwareId);
             /* Make Uart Channel Status to Ready for next Tx/Rx operation */
        }
        if (FLD_GET(ulUart_M_IrqStatus, GENI_M_IRQ_STATUS, M_CMD_DONE) != 0U)
        {
            /* Make Uart Channel Status to Ready for next Tx/Rx operation */
            UartActiveJob[ucHardwareId].Uart_DriverStatus = UART_CHANNEL_READY;
        }
	}
	else if(xUartHwConfig[ucHardwareId].eUartOpMode == UART_DMA_MODE)
	{
		/* Read the DMA interrupt status register*/
		Dma_TxIrqStatus = REG_IN(ulSE_base, DMA_TX_IRQ_STAT);
		Dma_RxIrqStatus = REG_IN(ulSE_base, DMA_RX_IRQ_STAT);
		/* Check if there is any error*/
		if(FLD_GET(Dma_TxIrqStatus, DMA_TX_IRQ_STAT, SBE) ||
							 FLD_GET(Dma_RxIrqStatus, DMA_RX_IRQ_STAT, SBE))
		{
			/* Set the Status as UART_ERROR_DMA_TRANSFER_ERROR*/
			lStatus = UART_ERROR_DMA_TRANSFER_ERROR;
		}
		/* Check if the TX DMA done*/
		if(FLD_GET(Dma_TxIrqStatus, DMA_TX_IRQ_STAT, DMA_DONE) != 0U)
		{
			/* Set the UART status to done to indicate that the transfer is done*/
			UartActiveJob[ucHardwareId].Uart_DriverStatus = UART_CHANNEL_READY;
		}
		/* Check if the RX DMA done*/
		if(FLD_GET(Dma_RxIrqStatus, DMA_RX_IRQ_STAT, DMA_DONE) != 0U)
		{
			/* Set the UART status to done to indicate that the transfer is done*/
			UartActiveJob[ucHardwareId].Uart_DriverStatus = UART_CHANNEL_READY;

			if(xUartHwConfig[ucHardwareId].NotifFuncPtr != NULL)
			{
				UartActiveJob[ucHardwareId].ulReceivedLength = REG_IN(ulSE_base, DMA_RX_LENGTH_IN);
				xUartHwConfig[ucHardwareId].NotifFuncPtr(&UartActiveJob[ucHardwareId]);
			}
			/* Update the buffer address that needs to be updated*/
			REG_OUT(ulSE_base,DMA_RX_PTR_L,
					FLD_SET(DMA_RX_PTR_L,RX_PTR_L,
					        (uint8 *)UartActiveJob[ucHardwareId].psRxBufferPtr));
			REG_OUT(ulSE_base,DMA_RX_PTR_H,
					FLD_SET(DMA_RX_PTR_H,RX_PTR_H,0U));
			/* reset the DMA RX attribute*/
			REG_OUT(ulSE_base,DMA_RX_ATTR,0U);
			/* update the buffer length for the DMA transfer*/
			REG_OUT(ulSE_base,DMA_RX_LENGTH,
					FLD_SET(DMA_RX_LENGTH,RX_LENGTH,UART_RXBUFF_SIZE));
		}
		if(Dma_TxIrqStatus != 0U)
		{
			/* Clear the Interrupt flag*/
			REG_OUT(ulSE_base, DMA_TX_IRQ_CLR, Dma_TxIrqStatus);
		}
		if(Dma_RxIrqStatus != 0U)
		{
		/* Clear the Interrupt flag*/
		REG_OUT(ulSE_base, DMA_RX_IRQ_CLR, Dma_RxIrqStatus);
		}
	}
	else
	{
		/* Dummy else */
	}
	/* Clear the Interrupt*/
	if(ulUart_M_IrqStatus != 0U)
	{
		/* Clear the Interrupt flag*/
		REG_OUT(ulSE_base, GENI_M_IRQ_CLEAR, ulUart_M_IrqStatus);
	}
	if(Uart_S_IrqStatus != 0U)
	{
		/* Clear the Interrupt flag*/
		REG_OUT(ulSE_base, GENI_S_IRQ_CLEAR, Uart_S_IrqStatus);
	}
	// Unmasking GENI interrupts, SW is ready to take new interrupts from GENI
	prvUartEnableInterrupt((uint8)ucHardwareId, TRUE);
}

#ifndef SAILEL2
static void UartGeniSEIsr(void *arg)
#else
static enum handler_return UartGeniSEIsr(void *arg)
#endif
{
    //EL1(Freertos)/EL2 ISR handles FPU registers save/restore.
    UartGeniSEIsr_CB(arg);
#ifdef SAILEL2
    return INT_NO_RESCHEDULE;
#endif
}

/*=================================================================================================
 @Service name        bUartConnectionStatus
 @Description         This function will check if the UART is connected or not
 @param[in]           ucChannelId - ucChannelId number of UART
 @param[out]          NA
 @param[in, out]      NA
 @return              UART Connection status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
uartConnectionStatusType_e bUartConnectionStatus(uint8 ucChannelId)
{
    uartConnectionStatusType_e bStatus = UART_DISCONNECTED;
	
	if(ucChannelId >= MAX_NO_OF_SERIAL_ENGINE)
	{
		bStatus = UART_DISCONNECTED;
		return bStatus;
	}

        bStatus = uartConnectionStatus;

    return bStatus;
}

/*=================================================================================================
**                                   Local function definitions                                 **
=================================================================================================*/
/*=================================================================================================
 @Service name        prvUartLoadDeviceTreeSettings
 @Description         This function loads hardware specific parameters from DTS file
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uartStatusType_e - Initialization status
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
static uartStatusType_e prvUartLoadDeviceTreeSettings(uint8 ucHardwareID)
{
	uartStatusType_e ret = UART_ERROR_UNDEFINED;
	int offset = 0, root_offset = 0;
	const char *path;
	int valSize_st = 5;
    uint32_t UARTrequired = 0; 
    int retval_dtb = -1;
	char uart_name[6] = {'u', 'a', 'r', 't','0','\0'};
	void *pDTB = NULL;
    uint32_t val_array0[uartNUMBER_OF_UART_PINS] = {0};
    uint32_t val_array1[uartNUMBER_OF_UART_PINS] = {0};
    uint32_t val_array2[uartNUMBER_OF_UART_PINS] = {0};
    uint32_t val_array3[uartNUMBER_OF_UART_PINS] = {0};
    uint32_t val_array4[uartNUMBER_OF_UART_PINS] = {0};
    int valSize = uartNUMBER_OF_UART_PINS;
    ChipInfoFamilyType xIsMonacoChip = CHIPINFO_FAMILY_32BITS;
    GPIOConfigType xqupPinCfg = {0x0u};
    uint8 ucGpioNumbers = 0x0u;

    //TODO: Add El1 support for chipinfo. currently Uart Init is done only in El2.
    xIsMonacoChip = ChipInfo_GetChipFamily();

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
        #ifdef SAILEL2
            root_offset = fdt_path_offset(pDTB, "/UARTconfig");
            if(root_offset > 0)
            {
                retval_dtb = fdt_getprop_u32(pDTB, root_offset, "UART_REQUIRED", &UARTrequired);
                if(retval_dtb == 0)
                {
                    if(UARTrequired==0)
                    {
                        *(volatile uint32*)UART_DEBUG_CONNECTION_STATUS = UART_DISCONNECTED;
                        *(volatile uint32*)UART_CONNECTION_TEST = CONNECTION_DONE;
                        DEBUG_LOG(SAIL_WARNING,"Uart Driver Disable SW DTS Setting\n\r");
                        ret = UART_HW_NOT_ENABLED;
                        return ret;
                    }
                }
            }
        #endif
		root_offset = fdt_path_offset(pDTB, "/qup");
		(void)fdt_getprop_u32(pDTB, root_offset, "common-addr", &ulQupCommonBase);
		root_offset = fdt_path_offset(pDTB, "/aliases");
		uart_name[4] = (ucHardwareID + 48U);
		path = (const char*)fdt_getprop(pDTB, root_offset, uart_name , NULL);
		if (path != NULL) {
			offset = fdt_path_offset(pDTB, path);
			(void)fdt_getprop_u32(pDTB, offset, "reg-base", &xUartHwConfig[ucHardwareID].uluart_base);
			(void)fdt_getprop_u32(pDTB, offset, "baudrate", &xUartHwConfig[ucHardwareID].ulbaud_rate);
			(void)fdt_getprop_u32(pDTB, offset, "interrupt", &xUartHwConfig[ucHardwareID].ulIRQ_num);
			(void)fdt_getprop_u32(pDTB, offset, "parity", &xUartHwConfig[ucHardwareID].eParity_mode);
			(void)fdt_getprop_u32(pDTB, offset, "stop-bit", &xUartHwConfig[ucHardwareID].eNumStopBit);
			(void)fdt_getprop_u32(pDTB, offset, "loopback", &xUartHwConfig[ucHardwareID].ucLoopback_mode);
			(void)fdt_getprop_u32(pDTB, offset, "status", &xUartHwConfig[ucHardwareID].status);
			(void)fdt_getprop_u32(pDTB, offset, "access-mode", &xUartHwConfig[ucHardwareID].eUartOpMode);
			(void)fdt_getprop_u32(pDTB, offset, "clock-frequency", &xUartHwConfig[ucHardwareID].ulClkFrequency);
			xUartHwConfig[ucHardwareID].psSE_clock = (char*) fdt_getprop(pDTB, offset, "clock-name", &valSize_st);
			xUartHwConfig[ucHardwareID].ChannelId = (uartChannelIdType_e)ucHardwareID;

            if ( CHIPINFO_FAMILY_MONACOAU == xIsMonacoChip )
            {
                path = (char*)fdt_getprop(pDTB, offset, "pinctrl-monaco", NULL);
            }else
            {
                path = (char*)fdt_getprop(pDTB, offset, "pinctrl", NULL);
            }
            if( NULL != path)
            {
                offset = fdt_path_offset(pDTB, path);
                (void)fdt_getprop_u32_array(pDTB, offset, "pins", val_array0, &valSize);
                (void)fdt_getprop_u32_array(pDTB, offset, "func", val_array1, &valSize);
                (void)fdt_getprop_u32_array(pDTB, offset, "drive-strength", val_array2, &valSize);
                (void)fdt_getprop_u32_array(pDTB, offset, "dir", val_array3, &valSize);
                (void)fdt_getprop_u32_array(pDTB, offset, "bias", val_array4, &valSize);
                for( int i = 0; i < valSize; i++)
                {
                    ucGpioNumbers = (uint8)val_array0[i];
                    sail_gpio_get_pin_config(ucGpioNumbers,&UartResetStatePinCfg[ucHardwareID][i]);
                    xqupPinCfg.func = val_array1[i];
                    xqupPinCfg.drive = val_array2[i];
                    xqupPinCfg.dir = val_array3[i];
                    xqupPinCfg.pull = val_array4[i];
                    sail_gpio_config_pin(ucGpioNumbers,xqupPinCfg);
                }
            }else
            {
                ret = UART_HW_NOT_EXIST;
            }
		}
		else
		{
			ret = UART_HW_NOT_EXIST;
		}
		if( ucHardwareID == uartVIP_HW)
		{
	#if 0 //SAILSW3
			xUartHwConfig[uartVIP_HW].NotifFuncPtr = HAL_SAIL_VIPUART_RX_Notif;
	#else
			xUartHwConfig[uartVIP_HW].NotifFuncPtr = NULL;
	#endif
		}
	#ifndef SAILJTAGPROGRAMMER

		if( ucHardwareID == uartDEBUG_HW )
		{
			xUartHwConfig[uartDEBUG_HW].NotifFuncPtr = HAL_SAIL_UART_Rx_Notification;
		}
	#endif
		if( xUartHwConfig[ucHardwareID].status == 0x0U)
		{
			ret = UART_HW_NOT_ENABLED;
		}
		else
		{
			ret = UART_SUCCESS;
		}
	}

	return ret;
}

/*=================================================================================================
 @Service name        prvUartClockEnable
 @Description         This function will Enable the clock for UART
 @param[in]           ucHardwareID - Hardware ID
 @param[out]          NA
 @param[in, out]      NA
 @return              ClockResult - Clock is enabled/disabled.
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static ClockResult prvUartClockEnable( uint8 ucHardwareID)
{
	ClockResult eResult = CLOCK_ERROR;
	ClockIdType nClockId   = {0};
	uint32 ulNfreq;
	ClockHandle hClient = 0U;

	  if( CLOCK_SUCCESS == Clock_GetHandle(&hClient))
	  {
		if ( CLOCK_SUCCESS == Clock_GetClockId( hClient, xUartHwConfig[ucHardwareID].psSE_clock, &nClockId ) )
		{
			eResult = Clock_SetClockFrequency( hClient, nClockId, xUartHwConfig[ucHardwareID].ulClkFrequency,
					CLOCK_FREQUENCY_HZ_AT_LEAST, &ulNfreq);
			if( CLOCK_SUCCESS == eResult )
			{
				eResult = Clock_EnableClock( hClient, nClockId);
				if ( CLOCK_SUCCESS != eResult )
				{
					DEBUG_LOG(SAIL_ERROR,"Failed to enable serial engine clock \r\n");
				}
			}
		}

    }

	return eResult;
}

/*=================================================================================================
 @Service name        prvUARTClockDisable
 @Description         This function will disable the clock for UART
 @param[in]           ucHardwareID - Hardware ID
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static void prvUARTClockDisable( uint8 ucHardwareID)
{
    ClockIdType nClockId   = {0};
    ClockHandle hClient = 0U;

    if( CLOCK_SUCCESS == Clock_GetHandle(&hClient))
    {
        if ( CLOCK_SUCCESS == Clock_GetClockId( hClient, xUartHwConfig[ucHardwareID].psSE_clock , &nClockId ) )
        {
            if( CLOCK_SUCCESS != Clock_DisableClock( hClient, nClockId))
            {
                DEBUG_LOG(SAIL_ERROR,"Failed to disable serial engine clock \r\n");
            }
        }
    }
}

/*=================================================================================================
 @Service name        prvUartInitStatusCheck
 @Description         This function check if the driver initialization is done
 @param[in]           ucChannelId - ucChannelId number of UART
 @param[out]          NA
 @param[in, out]      NA
 @return              Error status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static uartStatusType_e prvUartInitStatusCheck(uint8 ucChannelId)
{
    uartStatusType_e xErrorVal = UART_SUCCESS;

    if(xUartInitStatus[ucChannelId] == UART_UNINITIALIZED)
    {
        xErrorVal = UART_NOT_INITIALIZED;
    }
    return xErrorVal;
}

/*=================================================================================================
 @Service name        prvUartWriteErrorcheck
 @Description         This function check for any error for the UART write function
 @param[in]           ucChannelId  - Channel ID
 @param[out]          NA
 @param[in, out]      NA
 @return              Error status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static uartStatusType_e prvUartWriteErrorcheck(const uartChannelIdType_e ucChannelId)
{
    volatile uint32 Dma_TxIrqStatus;
	uint32 ulSE_base;
	uartStatusType_e xErrorVal = UART_SUCCESS;
	uint32_t ultimeout_timer = 0u;
    xErrorVal = prvUartInitStatusCheck(ucChannelId);
    if(xErrorVal == UART_SUCCESS)
    {
			/* Need to put SpinLock to avoid data inconsistency*/
		if(UartActiveJob[ucChannelId].Uart_DriverStatus != UART_CHANNEL_READY)
		{
			//TODO: Need to remove spinlock after freeRTOS
			ulSE_base = xUartHwConfig[ucChannelId].uluart_base;
			/* Read the DMA interrupt status register*/
			Dma_TxIrqStatus = REG_IN(ulSE_base, DMA_TX_IRQ_STAT);

			while((!FLD_GET(Dma_TxIrqStatus, DMA_TX_IRQ_STAT,DMA_DONE))
							  && (UartActiveJob[ucChannelId].Uart_DriverStatus != UART_CHANNEL_READY)
							  && (ultimeout_timer != SIZE_4))
			{
				Dma_TxIrqStatus = REG_IN(ulSE_base, DMA_TX_IRQ_STAT);

				busywait(5000);
				ultimeout_timer++;
			}
			if((UartActiveJob[ucChannelId].Uart_DriverStatus != UART_CHANNEL_READY)
					&& (!FLD_GET(Dma_TxIrqStatus, DMA_TX_IRQ_STAT,DMA_DONE)))
			{
				UartActiveJob[ucChannelId].Uart_DriverStatus = UART_CHANNEL_READY;
				xErrorVal = UART_ERROR_UNDEFINED;
			}
			else
			{
				UartActiveJob[ucChannelId].Uart_DriverStatus = UART_CHANNEL_BUSY;
			}

		}
		else
		{
			UartActiveJob[ucChannelId].Uart_DriverStatus = UART_CHANNEL_BUSY;
		}
			/*End of SpinLock*/
    }

    return xErrorVal;
}

/*=================================================================================================
 @Service name        prvUartReadErrorcheck
 @Description         This function check for nay error for the UART read API
 @param[in]           ucChannelId  - Channel ID
 @param[out]          NA
 @param[in, out]      NA
 @return              Error status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static uartStatusType_e prvUartReadErrorcheck(const uartChannelIdType_e ucChannelId)
{
    uartStatusType_e xErrorVal = UART_SUCCESS;
    uint8 ucHardwareId;

    xErrorVal = prvUartInitStatusCheck(ucChannelId);
    if(xErrorVal == UART_SUCCESS)
    {
		/* Need to put SpinLock to avoid data inconsistency*/
		if(UartActiveJob[ucChannelId].Uart_DriverStatus != UART_CHANNEL_READY)
		{
			xErrorVal = UART_CHANNEL_BUSY;
		}
		else
		{
			UartActiveJob[ucChannelId].Uart_DriverStatus = UART_CHANNEL_BUSY;
		}
		/*End of SpinLock*/
    }

    return xErrorVal;
}

/*=================================================================================================
 @Service name        prvUartInitErrorCheck
 @Description         This function check and report any Error for the Init function
 @param[in]           pxConfigPtr      - Pointer to the Configuration
 @param[out]          NA
 @param[in, out]      NA
 @return              Error status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static uartStatusType_e prvUartInitErrorCheck(uartHWConfigType *pxUartHwConfig)
{
	uartStatusType_e xStatus = UART_SUCCESS;

    if(pxUartHwConfig == NULL)
    {
        xStatus = UART_ERROR_NULL_PTR;
    }
    else if(xUartInitStatus[pxUartHwConfig->ChannelId] == UART_INITIALIZED)
	{
		xStatus = UART_ERROR_ALREADY_INITIALIZED;
	}
    else
    {
    	; /* For MCDC*/
    }
    return xStatus;
}

/*=================================================================================================
 @Service name        prvUartSEInit
 @Description         This function will Initialize the Serial engine
 @param[in]           Config -Configuration pointer
                      ucChannelId - UART channel ID
 @param[out]          NA
 @param[in, out]      NA
 @return              uartStatusType_e - Error status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/

static uartStatusType_e prvUartSEInit(uartHWConfigType *config, uint8 ucHardwareID)
{
    const uint32 ulSE_Base = config->uluart_base;
    uint32 ulQupv3HwVer = REG_IN(ulQupCommonBase, QUPV3_HW_VERSION);
    uint32 ulFifoDepth;
    uint16 usclkRegValue;
    uint32 ulTimeoutMax = 500;
    uint32 ulRegMIRQ = 0U;
    uint32 ulRegSIRQ = 0U;
    uint32 ulRegDMAIRQ = 0U;
    uint8 ucCount;
    uartStatusType_e eResult = UART_SUCCESS;
    PlatformInfoPlatformType xPlatformType = PLATFORMINFO_TYPE_UNKNOWN;

    xPlatformType = PlatformInfo_Platform();

    /* HPG section 3.1.7.1 is skipped since the DFS enabling is not required*/
    /* Check if the DMA mode is configured. As per 3.1.7.2*/
    if(config->eUartOpMode == UART_DMA_MODE)
    {
        /* Reset the DMA*/
        REG_OUT(ulSE_Base,DMA_RX_FSM_RST,
                                  FLD_SET(DMA_RX_FSM_RST, RX_FSM_RST, 0x1));
        REG_OUT(ulSE_Base,DMA_TX_FSM_RST,
                                  FLD_SET(DMA_TX_FSM_RST, TX_FSM_RST, 0x1));
        /* Wait till the reset is done or timeout occured*/
        do
        {
            /* Check if the Reset is done*/
            if( REG_INF(ulSE_Base,DMA_RX_IRQ_STAT,RESET_DONE) != 0U)
            {
                // Clear the Reset done IRQ bit
                REG_OUT(ulSE_Base, DMA_RX_IRQ_CLR, HWIO_DMA_RX_IRQ_CLR_RESET_DONE_CLR_BMSK);
                break;
            }
            else
            {
                /* Wait for UART_POLLINTERVAL_US*/
                busywait(5U);
                /* Decrement the timeout*/
                ulTimeoutMax -= 5U;
				if ( 0U == ulTimeoutMax )
				{
					eResult = UART_ERROR_CONFIG;
				}
            }
        }while ((ulTimeoutMax != 0U));
    }

	REG_OUT(ulSE_Base, GENI_OUTPUT_CTRL,
                FLD_SET(GENI_OUTPUT_CTRL, IO_OUTPUT_CTRL, 0x0));

	/* HW Controls the CGC. As per HPG section 3.1.7.3 */
    REG_OUTF(ulSE_Base, QUPV3_COMMON_CGC_CTRL, COMMON_CSR_SLV_CLK_CGC_ON,1);

    REG_OUTF(ulSE_Base, GENI_DFS_IF_CFG, DFS_IF_EN, 0U);


    /* Check if the DMA mode is configured*. As per 3.1.7.3 */
    if(config->eUartOpMode == UART_DMA_MODE)
    {
        // Clock related to DMA. As per HPG. 3.1.7.3.
        REG_OUT(ulSE_Base, DMA_GENERAL_CFG,
                    FLD_SET(DMA_GENERAL_CFG, AHB_SEC_SLV_CLK_CGC_ON, 1U) |
                    FLD_SET(DMA_GENERAL_CFG, DMA_AHB_SLV_CLK_CGC_ON, 1U) |
                    FLD_SET(DMA_GENERAL_CFG, DMA_TX_CLK_CGC_ON, 1U) |
                    FLD_SET(DMA_GENERAL_CFG, DMA_RX_CLK_CGC_ON, 1U));

    }

    /* Clock gating control for GENI.As per HPG section 3.1.7.3 */
    REG_OUT(ulSE_Base, GENI_CGC_CTRL,
                FLD_SET(GENI_CGC_CTRL, EXT_CLK_CGC_ON, 1U) |
                FLD_SET(GENI_CGC_CTRL, RX_CLK_CGC_ON, 1U) |
                FLD_SET(GENI_CGC_CTRL, TX_CLK_CGC_ON, 1U) |
                FLD_SET(GENI_CGC_CTRL, SCLK_CGC_ON, 1U) |
                FLD_SET(GENI_CGC_CTRL, DATA_AHB_CLK_CGC_ON, 1U) |
                FLD_SET(GENI_CGC_CTRL, CFG_AHB_WR_CLK_CGC_ON, 1U) |
                FLD_SET(GENI_CGC_CTRL, CFG_AHB_CLK_CGC_ON, 1U));

    	/* HPG section 3.1.7.9 */
    	/* UART RX Configuration */
    	ulFifoDepth = REG_INF(ulSE_Base, SE_HW_PARAM_1, RX_FIFO_DEPTH);

        /* Making RX Watermark to 9, 
           Uart ISR will be triggered when there 40 bytes of data in FIFO */
        REG_OUT(ulSE_Base, GENI_RX_WATERMARK_REG, 9U);

    	REG_OUT(ulSE_Base, GENI_RX_RFR_WATERMARK_REG,
         FLD_SET(GENI_RX_RFR_WATERMARK_REG, RX_RFR_WATERMARK, (ulFifoDepth - 2)));


    	/* Enable the force Default. */
    	REG_OUT(ulSE_Base, GENI_FORCE_DEFAULT_REG,
        FLD_SET(GENI_FORCE_DEFAULT_REG, FORCE_DEFAULT, 1));

        /* Enable IO GENI output. As per HPG section 3.1.7.5*/
        REG_OUT(ulSE_Base, GENI_OUTPUT_CTRL,
                    FLD_SET(GENI_OUTPUT_CTRL, IO_OUTPUT_CTRL, 0x7fU));

        /* Check the configured mode is DMA mode. As per HPG section 3.1.7.6 */
        if(config->eUartOpMode == UART_DMA_MODE)
        {
            /* Enable the DMA*/
            REG_OUT(ulSE_Base, GENI_DMA_MODE_EN,
                    FLD_SET(GENI_DMA_MODE_EN, GENI_DMA_MODE_EN, 1U));
        }
        else
        {
            /* Disable the DMA*/
            REG_OUT(ulSE_Base, GENI_DMA_MODE_EN,
                    FLD_SET(GENI_DMA_MODE_EN, GENI_DMA_MODE_EN, 0U));
        }

        if(config->eUartOpMode != UART_DMA_MODE)
        {
            /* Disable the DMA mode*/
            REG_OUT(ulSE_Base, DMA_IF_EN,
                    FLD_SET(DMA_IF_EN, DMA_IF_EN, 0x0));
            /* Enable the FIFO mode*/
            REG_OUT(ulSE_Base, FIFO_IF_DISABLE,
                    FLD_SET(FIFO_IF_DISABLE, FIFO_IF_DISABLE, 0x0));
        }
        else
        {
             /* Enable the DMA mode*/
             REG_OUT(ulSE_Base, DMA_IF_EN,
                        FLD_SET(DMA_IF_EN, DMA_IF_EN, 0x1U));
             /* Enable the FIFO mode*/
             REG_OUT(ulSE_Base, FIFO_IF_DISABLE,
                        FLD_SET(FIFO_IF_DISABLE, FIFO_IF_DISABLE, 0x1U));
            /* Set the Granularity for the DMA mode. Fixed 4x8 */
            REG_OUT(ulSE_Base, GENI_BYTE_GRANULARITY,
                         FLD_SET(GENI_BYTE_GRANULARITY, GENI_BYTE_GRANULARITY, 0U));
        }

        /* UART Specific configuration */
        /* Get the requested baud rate configuration*/
        ucCount = 0U;
        while(Uart_BaudTable[ucCount].ulbit_rate !=0U)
        {
            if (Uart_BaudTable[ucCount].ulbit_rate == config->ulbaud_rate)
            {
               break;
            }
            ucCount++;
        }

        /* 
         * As in monaco Pre-Sil phase uart clock are running at very low freq so divider 
         * value need to be adjusted according to clock frequency 
         */
        if ( PLATFORMINFO_TYPE_RUMI == xPlatformType && uartDEBUG_CHANNEL == ucHardwareID)
        {
            if (ulQupv3HwVer >= 0x10030000U)
            {
                usclkRegValue = ((65U/16U) << 0x4U) | 0x1U;
            }
            else
            {
                usclkRegValue = ((65/16U/32U) << 0x4U) | 0x1U;
            }
        }else
        {
             /* Calculate the clock config Register as per the HPG 3.2.2.2.
                Check if the HW version is greater then 0x10030000*/
            if (ulQupv3HwVer >= 0x10030000U)
            {
            	usclkRegValue = ((Uart_BaudTable[ucCount].ucdivider/16U) << 0x4U) | 0x1U;
            }
            else
            {
            	usclkRegValue = ((Uart_BaudTable[ucCount].ucdivider/16U/32U) << 0x4U) | 0x1U;
            }

        }

        /* Configure the clock configuration according to the baud rate*/
        REG_OUT(ulSE_Base, GENI_SER_M_CLK_CFG, usclkRegValue);
        REG_OUT(ulSE_Base, GENI_SER_S_CLK_CFG, usclkRegValue);

        REG_OUTF(ulSE_Base, GENI_CGC_CTRL,PROG_RAM_SCLK_OFF,1);
        REG_OUTF(ulSE_Base, GENI_CGC_CTRL,PROG_RAM_HCLK_OFF,1);

        REG_OUT(ulSE_Base, GENI_CLK_CTRL,
                FLD_SET(GENI_CLK_CTRL, SER_CLK_SEL, 0x1));

        REG_OUTF(ulSE_Base, GENI_CGC_CTRL,PROG_RAM_SCLK_OFF,0U);
        REG_OUTF(ulSE_Base, GENI_CGC_CTRL,PROG_RAM_HCLK_OFF,0U);

        /* TX word length configuration*/
        REG_OUT(ulSE_Base, UART_TX_WORD_LEN, uartWORD_LEN);
        /* RX word length configuration*/
        REG_OUT(ulSE_Base, UART_RX_WORD_LEN, uartWORD_LEN);
        /* TX Transaction configuration. Ignore CTS line.*/
        REG_OUTF(ulSE_Base, UART_TX_TRANS_CFG,UART_CTS_MASK,1);
        if(config->eParity_mode != UART_NO_PARITY)
        {
            /* Enable the Parity bit for TX line*/
            REG_OUTF(ulSE_Base, UART_TX_TRANS_CFG,UART_PARITY_EN,1);
            /* TX parity configuration*/
            REG_OUT(ulSE_Base, UART_TX_PARITY_CFG,
                    (FLD_SET(UART_TX_PARITY_CFG,
					         TX_PAR_MODE, config->eParity_mode) |
                             FLD_SET(UART_TX_PARITY_CFG, TX_PAR_CALC_EN, 1)));
            /* Enable the Parity bit for RX line*/
            REG_OUTF(ulSE_Base, UART_RX_TRANS_CFG,UART_PARITY_EN,1);
            /* RX parity configuration*/
            REG_OUT(ulSE_Base, UART_RX_PARITY_CFG,
                    (FLD_SET(UART_RX_PARITY_CFG, RX_PAR_MODE, config->eParity_mode) |
                     FLD_SET(UART_RX_PARITY_CFG, RX_PAR_CALC_EN, 1)));
        }
        else
        {
            /* RX Transaction configuration*/
            REG_OUT(ulSE_Base, UART_RX_TRANS_CFG, 0x0);
            /* RX parity configuration*/
            REG_OUT(ulSE_Base, UART_RX_PARITY_CFG, 0x0);
        }
        /* TX stop bit configuration*/
        REG_OUT(ulSE_Base, UART_TX_STOP_BIT_LEN, config->eNumStopBit);
        /* RX stale count configuration*/
        REG_OUT(ulSE_Base, UART_RX_STALE_CNT, uartSTALE_COUNT);
        /* As per H.P.G 3.2.1. clock select*/
        REG_OUT(ulSE_Base, GENI_CLK_SEL, FLD_SET(GENI_CLK_SEL, CLK_SEL, 0U));
        /* TX packing configuration*/
        REG_OUT(ulSE_Base, GENI_TX_PACKING_CFG0, uartPACKING_CFG0);
        REG_OUT(ulSE_Base, GENI_TX_PACKING_CFG1, uartPACKING_CFG1);
        /* RX Packing configuration*/
        REG_OUT(ulSE_Base, GENI_RX_PACKING_CFG0, uartPACKING_CFG0);
        REG_OUT(ulSE_Base, GENI_RX_PACKING_CFG1, uartPACKING_CFG1);
        /* Clear the connection Failure status */
        REG_OUTF(ulSE_Base, GENI_S_IRQ_CLEAR,S_GP_IRQ_2_CLEAR,1);
        REG_OUTF(ulSE_Base, GENI_S_IRQ_CLEAR, S_GP_IRQ_3_CLEAR,1);
        /* Check if the loopback mode is enabled*/
        if (config->ucLoopback_mode == 1U)
        {
            REG_OUT(ulSE_Base, UART_LOOPBACK_CFG, 0x1);
        }
        else
        {
            REG_OUT(ulSE_Base, UART_LOOPBACK_CFG, 0x0);
        }
		#ifdef SAILEL2
            REG_OUT(ulSE_Base, GENI_S_CMD0, uartINITIATE_TRANSFER);

            if ( ucHardwareID ==  uartDEBUG_CHANNEL)
            {
                /* 
                *  In Uart Cable disconnected use case GENI_S_IRQ_STATUS is getting reflected 
                *  immediately .. Hence below delay is required to ensure status has been updated 
                *  properly
                */
                busywait(600u);
           }

		#endif

            if (UART_EL1_INIT_CORE == get_curr_cpu_num ())
            {
                REG_OUT(ulSE_Base, GENI_S_CMD0, uartINITIATE_TRANSFER);
            }

    return eResult;
}

/*=================================================================================================
 @Service name        prvUartSEDeInit
 @Description         This function will De-Initialize the Serial engine
 @param[in]           Config -Configuration pointer
                      ucChannelId - UART channel ID
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static void prvUartSEDeInit(uint8 ucChannelId)
{
    const uint32 ulSE_Base = xUartHwConfig[ucChannelId].uluart_base;
    uint8  ucUARTFWRev_Reset = 0xFFU;
    if(xUartHwConfig[ucChannelId].eUartOpMode != UART_POLLING_MODE)
    {
        /* Disable the Interrupts*/
        REG_OUT(ulSE_Base, SE_IRQ_EN,
                         FLD_SET(SE_IRQ_EN, DMA_RX_IRQ_EN, 0) |
                         FLD_SET(SE_IRQ_EN, DMA_TX_IRQ_EN, 0) |
                         FLD_SET(SE_IRQ_EN, GENI_M_IRQ_EN, 0) |
                         FLD_SET(SE_IRQ_EN, GENI_S_IRQ_EN, 0));
        REG_OUT(ulSE_Base, SE_GSI_EVENT_EN,0);
        /* Clear any pending Interrupt.*/
    	/* Unregister the Interrupt handler*/
#ifndef SAILEL2
            xGicSetIntEnable( xUartHwConfig[ucChannelId].ulIRQ_num, (boolean)FALSE);
            xGicUnRegisterIntHandler( xUartHwConfig[ucChannelId].ulIRQ_num, (uint32_t)0U);

#else
            mask_interrupt( xUartHwConfig[ucChannelId].ulIRQ_num);
            unregister_int_handler( xUartHwConfig[ucChannelId].ulIRQ_num, 0U);
#endif

    }
	REG_OUT(ulSE_Base, GENI_M_IRQ_CLEAR, uartIRQ_CLEAR_MASK);
    REG_OUT(ulSE_Base, GENI_S_IRQ_CLEAR, uartIRQ_CLEAR_MASK);
    REG_OUT(ulSE_Base, DMA_TX_IRQ_CLR, uartIRQ_CLEAR_MASK);
    REG_OUT(ulSE_Base, DMA_RX_IRQ_CLR, uartIRQ_CLEAR_MASK);
}
/*=================================================================================================
 @Service name        prvUartFiFoRead
 @Description         This function will read from the FIFO.
 @param[in]           ulSE_Base - SE base address
 @param[in]           uint8 ucChannelId
 @param[out]          NA
 @param[in, out]      NA
 @return              receive done status.
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static void prvUartFiFoRead(uint32 ulSE_Base, uartChannelIdType_e ucChannelId)
{
    uint32 ulRx_FifoStatus = REG_IN(ulSE_Base, GENI_RX_FIFO_STATUS);
    uint32 ulBytes_ToRead =  FLD_GET(ulRx_FifoStatus, GENI_RX_FIFO_STATUS, RX_FIFO_WC)
                            * uartBYTES_PER_FIFO_REG;
    uint32 ulWord = 0U;
    uint32 ucReadCount;
    uint32 ulBytes_InLastWord = 0U;
    uint32 ulReceived = UartActiveJob[ucChannelId].ulReceivedLength;
    uint8 *puBuffer = UartActiveJob[ucChannelId].psRxBufferPtr + ulReceived;
    uint32 actualBytesToRead = 0U;

    /* Check if the Last waord is set */
    if(FLD_GET(ulRx_FifoStatus, GENI_RX_FIFO_STATUS, RX_LAST) != 0U)
    {
        /* Get the last valid byte*/
    	ulBytes_InLastWord = FLD_GET(ulRx_FifoStatus, GENI_RX_FIFO_STATUS, RX_LAST_BYTE_VALID);
        /* update the bytes to read*/
        /* If both ulBytes_ToRead & ulBytes_InLastWord is 0 then no FIFO read is required*/
        if((ulBytes_ToRead == 0U) && (UartActiveJob[ucChannelId].ulReceivedLength == 0U) && 
        (ulBytes_InLastWord == 0U))
        {
            ulBytes_ToRead = 0;
        }
        /* As pre the IPCAT When RX_LAST is set then number of valid bytes for the last FIFO word 
           is specified in RX_LAST_BYTE_VALID field where 0 & 4 value means all 4 bytes are valid */
        else if((ulBytes_ToRead != 0U) && ((ulBytes_InLastWord == 0U) || (ulBytes_InLastWord == 4U)))
        {
            ulBytes_InLastWord = 4U;
            ulBytes_ToRead = (ulBytes_ToRead - uartBYTES_PER_FIFO_REG) + ulBytes_InLastWord;
        }
        else
        {
            ulBytes_ToRead = (ulBytes_ToRead - uartBYTES_PER_FIFO_REG) + ulBytes_InLastWord;
        }
    }

    if((UART_FIFO_BUFF_SIZE - ulReceived) < ulBytes_ToRead)
    {
        actualBytesToRead = ((UART_FIFO_BUFF_SIZE - ulReceived));
    }
    else
    {
        actualBytesToRead = ulBytes_ToRead;
    }

    for(ucReadCount = 0U; ucReadCount < ulBytes_ToRead; ucReadCount++)
    {
        if((ucReadCount % uartBYTES_PER_FIFO_REG) == 0U)
        {
            ulWord = REG_INI(ulSE_Base, GENI_RX_FIFOn, 0);
        }
        if(ucReadCount < actualBytesToRead)
        {
            puBuffer[ucReadCount] = (uint8)( ulWord >> ( ( ucReadCount % uartBYTES_PER_FIFO_REG)*uartBITS_PER_BYTE)) & 0xFFU;
        }
    }
    
    /* Update the transfered count*/
    UartActiveJob[ucChannelId].ulReceivedLength += actualBytesToRead;

    /* Clear the Watermark status bit*/
    REG_OUT(ulSE_Base, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_WATERMARK_CLEAR_BMSK);
    return;
}

/*=================================================================================================
 @Service name        prvUartFIFOWrite
 @Description         This function will write into the FIFO.
 @param[in]           ulSE_Base - SE base address
 @param[in]           uint8 ucChannelId
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static void prvUartFIFOWrite(uint32 ulSE_Base, uartChannelIdType_e ucChannelId)
{
    uint32 ulTxBufLength = UartActiveJob[ucChannelId].ulTxBufferLength;
    uint32 ulTx_WaterMark = REG_INF(ulSE_Base, GENI_TX_WATERMARK_REG, TX_WATERMARK);
    uint32 ulTx_FifoDepth = REG_INF(ulSE_Base, SE_HW_PARAM_0, TX_FIFO_DEPTH);
    uint32 ulBytes_ToWrite = (ulTx_FifoDepth << 2) - (ulTx_WaterMark << 2);
    uint32 ulWord = 0U;
    uint32 ulWriteCount;
    const char *buffer =  UartActiveJob[ucChannelId].psTxBufferPtr
	                    + UartActiveJob[ucChannelId].ulTransmittedLength;

    /* Check if the data to be write is less then the Fifo size*/
    if ((ulTxBufLength - UartActiveJob[ucChannelId].ulTransmittedLength) < ulBytes_ToWrite)
    {
        /* Calculate the bytes to be write*/
        ulBytes_ToWrite = ulTxBufLength - UartActiveJob[ucChannelId].ulTransmittedLength;
        /* reset the TX watermark level*/
        REG_OUT(ulSE_Base, GENI_TX_WATERMARK_REG,
                FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 0U));
    }
    /* Write the data into FIFO*/
    for (ulWriteCount = 0U; ulWriteCount < ulBytes_ToWrite; ulWriteCount++)
    {
        /* Pack the 4 bytes to a single 32 bit. So it can be write directly to TX FIFO */
        if ((ulWriteCount !=0U) && ((ulWriteCount % uartBYTES_PER_FIFO_REG) == 0U))
        {
            REG_OUTI(ulSE_Base, GENI_TX_FIFOn, 0U, ulWord);
            ulWord = 0U;
        }
        ulWord = ulWord | (   buffer[ulWriteCount]
		                   << ((ulWriteCount % uartBYTES_PER_FIFO_REG)*uartBITS_PER_BYTE));
    }
    REG_OUTI(ulSE_Base, GENI_TX_FIFOn, 0U, ulWord); //REG_OUT(SE_Base, GENI_TX_FIFOn, ulWord);
    /* Update the data count to be transfered*/
    UartActiveJob[ucChannelId].ulTransmittedLength += ulBytes_ToWrite;
    /* Clear the TX Watermark status bit*/
    REG_OUT(ulSE_Base, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_TX_FIFO_WATERMARK_CLEAR_BMSK);
}

/*=================================================================================================
 @Service name        prvUARTCfgIntrRegister
 @Description         This function Register UART ISR Handlers to GIC vector table.
 @param[in]           Config -Configuration pointer
                      ucChannelId - UART channel ID
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
static void prvUARTCfgIntrRegister(uartHWConfigType *config)
{
#ifndef SAILEL2
        //TODO: add Error checks.
        (void) xGicSetIntEnable(config->ulIRQ_num, (boolean)FALSE);
        (void) xGicConfigureInt(config->ulIRQ_num, EL1_INT_CONFIG_EDGE_TRIGGER, NULL);
        (void) xGicRegisterIntHandler(config->ulIRQ_num,
                                    (InterruptHandle_t)UartGeniSEIsr, (void *)(uint32)config->ChannelId);
        (void) xGicSetIntPriority(config->ulIRQ_num, (uint32_t)0x0U);
        (void) xGicSetIntEnable(config->ulIRQ_num, (boolean)TRUE);

#else
        (void) mask_interrupt(config->ulIRQ_num);
        (void) configure_interrupt(config->ulIRQ_num, INT_CONFIG_EDGE_TRIGGER, 0);
        (void) register_int_handler(config->ulIRQ_num,
                                    (int_handler)UartGeniSEIsr, (void *)(uint32)config->ChannelId);
        (void) set_int_priority(config->ulIRQ_num, 0x8U);
        (void) unmask_interrupt(config->ulIRQ_num);
#endif

}

static void uartINTRInit( uartHWConfigType *config)
{
	const uint32 ulSE_Base = config->uluart_base;
	uint32 ulRegMIRQ = 0U;
    uint32 ulRegSIRQ = 0U;
	uint32 ulRegDMAIRQ = 0U;
	/* check if the configured mode is not polling*/
        if(config->eUartOpMode != UART_POLLING_MODE)
        {
            /* Configure the Interrupt handler*/
			prvUARTCfgIntrRegister(config);

            /* Clear any pending Interrupt. This will ensure the fresh start*/
            REG_OUT(ulSE_Base, GENI_M_IRQ_CLEAR, uartIRQ_CLEAR_MASK);
            REG_OUT(ulSE_Base, GENI_S_IRQ_CLEAR, uartIRQ_CLEAR_MASK);
            if(config->eUartOpMode == UART_DMA_MODE)
            {
                REG_OUT(ulSE_Base, DMA_TX_IRQ_CLR, uartIRQ_CLEAR_MASK);
                REG_OUT(ulSE_Base, DMA_RX_IRQ_CLR, uartIRQ_CLEAR_MASK);
                ulRegDMAIRQ = (ulRegDMAIRQ | FLD_SET(SE_IRQ_EN, DMA_RX_IRQ_EN, 1) |
                                           FLD_SET(SE_IRQ_EN, DMA_TX_IRQ_EN, 1));
            }

            /* Enable the Interrupts*/
            REG_OUT(ulSE_Base, SE_IRQ_EN, ulRegDMAIRQ |
                                FLD_SET(SE_IRQ_EN, GENI_M_IRQ_EN, 1) |
                                FLD_SET(SE_IRQ_EN, GENI_S_IRQ_EN, 1));
            REG_OUT(ulSE_Base, SE_GSI_EVENT_EN,0U);

            /*Frame for the Common MIRQ*/
            ulRegMIRQ = (ulRegMIRQ | FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_OVERRUN_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_ILLEGAL_CMD_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_TIMESTAMP_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, IO_DATA_ASSERT_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, IO_DATA_DEASSERT_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_RD_ERR_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_WR_ERR_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_RD_ERR_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_WR_ERR_EN, 1));

            /* Frame the common S_IRQ enable*/
            ulRegSIRQ = (ulRegSIRQ | FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_OVERRUN_EN, 1) |
                                 FLD_SET(GENI_S_IRQ_ENABLE, S_ILLEGAL_CMD_EN, 1) |
                                 FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_0_EN, 1) |
                                 FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_1_EN, 1) |
                                 FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_2_EN, 1) |
                                 FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_3_EN, 1) |
                                 FLD_SET(GENI_S_IRQ_ENABLE, RX_FIFO_WR_ERR_EN, 1) |
                                 FLD_SET(GENI_S_IRQ_ENABLE, RX_FIFO_RD_ERR_EN, 1) |
                                 FLD_SET(GENI_S_IRQ_ENABLE, RX_FIFO_LAST_EN, 1));

            /* Check if the Mode is configured as FIFO*/
            if(config->eUartOpMode == UART_FIFO_MODE)
            {
                REG_OUT(ulSE_Base, GENI_M_IRQ_ENABLE,
                        ulRegMIRQ | FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_WATERMARK_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_WATERMARK_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_LAST_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_DONE_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_FAILURE_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_CANCEL_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_ABORT_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, SEC_IRQ_EN, 1));

                REG_OUT(ulSE_Base, GENI_S_IRQ_ENABLE,
                        ulRegSIRQ | FLD_SET(GENI_S_IRQ_ENABLE, RX_FIFO_WATERMARK_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_CANCEL_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_ABORT_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_DONE_EN, 1));
            }
            /* Enable IRQ for DMA mode*/
            else
            {
                /* Main Frame Engine interrupt configuration*/
                REG_OUT(ulSE_Base, GENI_M_IRQ_ENABLE, ulRegMIRQ);
                /* Secondary Frame Engine interrupt configuration*/
                REG_OUT(ulSE_Base, GENI_S_IRQ_ENABLE, ulRegSIRQ);
                /* DMA TX configuration */
                REG_OUT(ulSE_Base, DMA_TX_IRQ_EN_SET,
                        FLD_SET(DMA_TX_IRQ_EN_SET, DMA_DONE_EN_SET, 1U) |
                        FLD_SET(DMA_TX_IRQ_EN_SET, SBE_EN_SET, 1U) |
                        FLD_SET(DMA_TX_IRQ_EN_SET, RESET_DONE_EN_SET, 1U));
                /* DMA RX Configuration*/
                REG_OUT(ulSE_Base, DMA_RX_IRQ_EN_SET,
                        FLD_SET(DMA_RX_IRQ_EN_SET, DMA_DONE_EN_SET, 1U) |
                        FLD_SET(DMA_RX_IRQ_EN_SET, SBE_EN_SET, 1U) |
                        FLD_SET(DMA_RX_IRQ_EN_SET, RESET_DONE_EN_SET, 1U));
            }
        }
}

/*=================================================================================================
 @Service name        prvUartPinCtlReset
 @Description         Reset the Pin configuration of Uart before DeInitialization 
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ================================================================================================*/
static void prvUartPinCtlReset(uint8 ucHardwareID)
{
    int offset = 0;
    int root_offset = 0;
    char uart_name[6] = {'u', 'a', 'r', 't','0','\0'};
    void *pDTB = NULL;
    const char *path = NULL;
    int valSize = 2;
    uint32_t val_array0[2] = {0};
    uint8 ucGpioNumbers = 0x0u;

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/aliases");
		uart_name[4] = (ucHardwareID + 48U);
		path = (const char*)fdt_getprop(pDTB, root_offset, uart_name , NULL);
		if (path != NULL) {
			offset = fdt_path_offset(pDTB, path);
            #ifndef lemans
                path = (char*)fdt_getprop(pDTB, offset, "pinctrl-monaco", NULL);
            #else
                path = (char*)fdt_getprop(pDTB, offset, "pinctrl", NULL);
            #endif
            if( NULL != path)
            {
                offset = fdt_path_offset(pDTB, path);
                (void)fdt_getprop_u32_array(pDTB, offset, "pins", val_array0, &valSize);
                for( int i = 0; i < valSize; i++)
                {
                    ucGpioNumbers    = (uint8)val_array0[i];
                    sail_gpio_config_pin(ucGpioNumbers,UartResetStatePinCfg[ucHardwareID][i]);
                }
            }
        }
    }
}

#ifndef SAILEL2

/*========================================================================================================
 @Service name        prvUartDeInit_Sleep
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           eState -> SLEEP_ENTRY = arg from sleep driver to Deinit VIP UART channel
                                SLEEP_ABORT = arg from sleep driver in case sleep Driver want to abort sleep
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 =========================================================================================================*/

static void prvUartDeInit_Sleep( const sleepModeType_e eState )
{
    uint8 timeout = 5U;
    uint32_t phys_core_id = get_curr_phys_cpu_num();
    uartStatusType_e xUartStatus = UART_SUCCESS;

    if(( STR_SLEEP_MODE == eState ) || (DEEP_SLEEP_MODE == eState))
    {
        if(phys_core_id == 2U)
        {
#if 0		
            if(UartActiveJob[uartVIP_HW].Uart_DriverStatus == UART_CHANNEL_BUSY)
            {
                DEBUG_LOG(SAIL_ERROR,"Final UART transcation before UART DeInitialization\n\r");
                do
                {
                    xTaskDelay(1u);
                    timeout--;
                }while(UartActiveJob[uartVIP_HW].Uart_DriverStatus == UART_CHANNEL_BUSY && timeout > 0U);             
            }
#endif	            
            xUartStatus = xUartDeInit(uartVIP_HW);
            if(xUartStatus != UART_SUCCESS)
            {
                DEBUG_LOG(SAIL_ERROR,"[UART]: xUartDeInit UART_VIP_CHANNEL Fail\r\n");
                err_fatal(UART,ERR_FATAL_FAULT_DETECTED);
            }else
		
            {
            
            if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(uartSleepHandle,DRIVER_SLEEP,get_curr_cpu_num()))
            {
                DEBUG_LOG(SAIL_ERROR,"prvUartDeInit_Sleep xSleepDriverAck Success\n\r");
                }
            }
        }
    }
}

#endif // ifndef SAILEL2

#ifdef SAILEL2

/*=================================================================================================
 @Service name        prvIsTicCardConnected
 @Description         API to check if TIC Card is connected or not based on SAIL GPIO 47 state.
 					  SAIL GPIO 47 is active high signal
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              ticConnectionStatusType_e
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ================================================================================================*/
static ticConnectionStatusType_e prvIsTicCardConnected()
{
    int retval;
    void *pDTB = NULL;
    int offset = 0;
    uint32_t  ipnext_check_enable = 0;
    uint32_t  tic_gpio_num = 0;
    uint32_t  tic_gpio_func = 0;
    uint32_t  tic_gpio_dir = 0;
    uint32_t  tic_gpio_pull = 0;
    uint32_t  tic_gpio_drv = 0;
    uint32_t  tic_gpio_val = 0;

    ticConnectionStatusType_e is_connected = TIC_CONNECTED;
    GPIOValueType gpio_value = 0;
    GPIOConfigType gpio_cfg = {0};

    pDTB = fdt_get_dtb();
    if (NULL != pDTB)
    {
         offset = fdt_path_offset(pDTB, "/ipnext_config");
         if (offset < 0)
         {
              /* if the node is not found in the DT, assume that the
               * TIC card is connected and continue probing of the
               * uart cable normally */
              return TIC_CONNECTED;
         }

         retval  = fdt_getprop_u32(pDTB, offset, "ipnext_check_enable", &ipnext_check_enable);
         retval |= fdt_getprop_u32(pDTB, offset, "tic_gpio_num", &tic_gpio_num);
         retval |= fdt_getprop_u32(pDTB, offset, "tic_gpio_func", &tic_gpio_func);
         retval |= fdt_getprop_u32(pDTB, offset, "tic_gpio_dir", &tic_gpio_dir);
         retval |= fdt_getprop_u32(pDTB, offset, "tic_gpio_pull", &tic_gpio_pull);
         retval |= fdt_getprop_u32(pDTB, offset, "tic_gpio_drv", &tic_gpio_drv);
         retval |= fdt_getprop_u32(pDTB, offset, "tic_gpio_val", &tic_gpio_val);

         if (retval || ipnext_check_enable == 0)
         {
              /* if there are errors parsing the properties or TIC check is
               * disabled, assume that the TIC card is connected and
               * continue probing of the uart cable normally */
              return TIC_CONNECTED;
         }

         gpio_cfg.func = tic_gpio_func;
         gpio_cfg.dir = tic_gpio_dir;
         gpio_cfg.pull = tic_gpio_pull;
         gpio_cfg.drive = tic_gpio_drv;

         sail_gpio_config_pin(tic_gpio_num, gpio_cfg);
         gpio_value = sail_gpio_ReadPin(tic_gpio_num);

         if (gpio_value == tic_gpio_val)
         {
              is_connected = TIC_CONNECTED;
         }
         else
         {
              is_connected = TIC_DISCONNECTED;
         }
    }

    return is_connected;
}

#endif

/*========================================================================================================
 @Service name        prvUartEnableInterrupt
 @Description         Call Back to enable or disable UART peripheral interrupt
 @param[in]           ucHardwareId: Uart Hardware ID
                      enable: Interrupt enable/disable
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
=========================================================================================================*/

static void prvUartEnableInterrupt(uint8 ucHardwareId, bool enable)
{
    uint32 ulSE_base;

    ulSE_base = xUartHwConfig[ucHardwareId].uluart_base;

    /* Disable/Enable Rx/Tx FIFO Watermark, FIFO Last and M_CMD_DONE interrupts
       for Main sequencer */
    REG_OUT(ulSE_base, GENI_M_IRQ_ENABLE, 
        (FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_WATERMARK_EN, enable) |
         FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_WATERMARK_EN, enable) |
         FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_LAST_EN, enable) |
         FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_DONE_EN, enable)));

    REG_OUT(ulSE_base, DMA_TX_IRQ_EN_SET,
        FLD_SET(DMA_TX_IRQ_EN_SET, DMA_DONE_EN_SET, enable) |
        FLD_SET(DMA_TX_IRQ_EN_SET, SBE_EN_SET, enable) |
        FLD_SET(DMA_TX_IRQ_EN_SET, RESET_DONE_EN_SET, enable));
    /* DMA RX Configuration*/
    REG_OUT(ulSE_base, DMA_RX_IRQ_EN_SET,
            FLD_SET(DMA_RX_IRQ_EN_SET, DMA_DONE_EN_SET, enable) |
            FLD_SET(DMA_RX_IRQ_EN_SET, SBE_EN_SET, enable) |
            FLD_SET(DMA_RX_IRQ_EN_SET, RESET_DONE_EN_SET, enable));

    /* Disable/Enable Rx FIFO Watermark interrupts for secondary sequencer */
    REG_OUT(ulSE_base, GENI_S_IRQ_ENABLE, FLD_SET(GENI_S_IRQ_ENABLE, RX_FIFO_WATERMARK_EN, enable));
  
    /* Disable/Enable SE IRQs enable for CPU */
    REG_OUT(ulSE_base, SE_IRQ_EN,
            FLD_SET(SE_IRQ_EN, DMA_RX_IRQ_EN, enable) |
            FLD_SET(SE_IRQ_EN, DMA_TX_IRQ_EN, enable) |
            FLD_SET(SE_IRQ_EN, GENI_M_IRQ_EN, enable) |
            FLD_SET(SE_IRQ_EN, GENI_S_IRQ_EN, enable));

}
/* End of File*/
