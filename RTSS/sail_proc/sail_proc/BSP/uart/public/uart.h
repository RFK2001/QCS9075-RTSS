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
    File Name          : uart.h
    Component Name     : UART driver header file
    Description        : UART driver header file
    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/uart/public/uart.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $
=================================================================================================*/
#ifndef UART_H
#define UART_H

/*=================================================================================================
**                                     Include files                                             **
=================================================================================================*/
#include "types.h"
#include "common_functions.h"
#include "msmhwiobase.h"
#ifndef SAILEL2
#include "freertos_init.h"
#endif
/*=================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs         **
=================================================================================================*/
/* Update the channel IDs if DTS is updated*/
#ifdef CONFIG1
#define uartVIP_CHANNEL 							UART_CHANNEL_ID_1
#define uartDEBUG_CHANNEL 							UART_CHANNEL_ID_0
#else
#define uartVIP_CHANNEL 							UART_CHANNEL_ID_0
#define uartDEBUG_CHANNEL 							UART_CHANNEL_ID_1
#endif /* CONFIG1 */

/* UART EL1 Init Core */
#define UART_EL1_INIT_CORE      0x2U

#define UART_COMMON_PORT uartVIP_CHANNEL //ToDo: Change the macro name in SSM
#define uartSAIL_MAX_NOTIFY_CLIENTS 64U
#define uartMAX_VIP_MESSAGE_SIZE 	256U

#define UART_DATA __attribute__ ( ( section ( "uart_data" ) ) )

#ifndef SAILEL2
extern uint32_t Image$$lnkUARTDATAStartAddr$$ZI$$Base;
extern uint32_t Image$$lnkUARTDATAEndAddr$$ZI$$Base;
#endif

#define SAILBSP_QUPV3_UART_REG_ADDR_BASE    (void *)SAILSS_QUPV3_1_QUPV3_ID_1_BASE
#define SAILBSP_QupV3_UART_REG_ADDR_SIZE            SAILSS_QUPV3_1_QUPV3_ID_1_BASE_SIZE

#define SAILBSP_UART_DMA_ADDR_BASE	  (void *)UART_VIP_TX_STARTADDR
#define SAILBSP_UART_DMA_ADDR_SIZE	  0x400

#define SAILBSP_UART_DATA_ADDR_BASE        (void *)&Image$$lnkUARTDATAStartAddr$$ZI$$Base
#define SAILBSP_UART_DATA_ADDR_SIZE        (uint32_t)( (uint32_t)&Image$$lnkUARTDATAEndAddr$$ZI$$Base -\
                                                            (uint32_t)&Image$$lnkUARTDATAStartAddr$$ZI$$Base )

#if 0 //ifndef SAILEL2
UART_DATA extern xQueueHandle xUartVipMsgQueueHandle;
extern BaseType_t xUartVIPTaskInit( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior );
extern BaseType_t xUartVIPRTOSFeatureInit( CPUIdType_e           xSchdCore);
#endif
typedef enum
{
    UART_ERROR_UNDEFINED = 0,
    UART_ERROR_CONFIG,
	UART_NOT_INITIALIZED,
    UART_ERROR_CLOCK_ENABLE_FAIL,
	UART_ERROR_CLOCK_DISABLE_FAIL,
	UART_ERROR_INVALID_CHANNEL_ID,
	UART_ERROR_NULL_PTR,
	UART_ERROR_ALREADY_INITIALIZED,
	UART_CHANNEL_READY,
	UART_CHANNEL_INACTIVE,
	UART_CHANNEL_BUSY,
    UART_SUCCESS,
	UART_ERROR_DMA_TRANSFER_ERROR,
	UART_CLIENT_EXCEEDED,
	UART_CLIENT_ALREADY_REGISTERED,
	UART_INVALID_CLIENT_ENTRY,
	UART_HW_NOT_ENABLED,
	UART_HW_NOT_EXIST,
    UART_CLIENT_NOT_FOUND
}uartStatusType_e;

typedef enum : uint32
{
    UART_1_0_STOP_BITS    = 0,
    UART_1_5_STOP_BITS    = 1,
    UART_2_0_STOP_BITS    = 2,
    UART_2_5_STOP_BITS    = 3,
    UART_3_0_STOP_BITS    = 4,
} uartNumStopBitsType_e;

typedef enum : uint32
{
    UART_NO_PARITY        = 4,
    UART_EVEN_PARITY      = 0,
    UART_ODD_PARITY       = 1,
    UART_SPACE_PARITY     = 2,
    UART_MARK_PARITY      = 3
} uartParityModeType_e;

typedef enum : uint32
{
    UART_POLLING_MODE = 0,
    UART_FIFO_MODE = 1,
    UART_DMA_MODE = 2,
}uartOpModeType_e;

/* Driver status type definition*/
typedef enum
{
    UART_UNINITIALIZED = 0,
    UART_INITIALIZED,
	UART_IDLE,
    UART_BUSY,
    UART_DONE
}uartInitStatusType_e;

/*
 * uartChannelIdType_e;
 * UART list of available channels
 */

typedef enum
{
	UART_CHANNEL_ID_0,
	UART_CHANNEL_ID_1,
	UART_CHANNEL_ID_2,
	UART_CHANNEL_ID_3,
	UART_CHANNEL_ID_4,
	UART_CHANNEL_ID_5,
} uartChannelIdType_e;

/* Uart connection status type*/
typedef enum
{
	UART_DISCONNECTED = 0,
	UART_CONNECTED
}uartConnectionStatusType_e;
/* Uart Initialization Core ID*/
typedef enum
{
	CORE_0 = 0,
	CORE_1,
    CORE_2,
    CORE_3,
    UNINITIALIZED, 
}uartInitializationCoreId_e;
/* Uart Job handle type definition*///channeltype
typedef struct
{
	uartStatusType_e        Uart_DriverStatus;
    uint32    				ulTxBufferLength;
    uint32    				ulRxBufferLength;
    uint32    				ulTransmittedLength;
    uint32    				ulReceivedLength;
    uint32    				ulRxWritePtr;
    uint32    				ulRxReadPtr;
    const char     			*psTxBufferPtr;
    uint8     				*psRxBufferPtr;
}uartJobHandleType;

/* Type definition for the Uart_notificationfunctype */
typedef void (*uart_NotificationFunc) (volatile uartJobHandleType *Uart_JobResult);

typedef struct
{
	uint32 uluart_base;
    uint32 ulbaud_rate;
    uint32 ulIRQ_num;
    uartParityModeType_e  eParity_mode;
    uartNumStopBitsType_e eNumStopBit;
    uint32 status;
    uint32  ucLoopback_mode;
    uartOpModeType_e      eUartOpMode;
    uart_NotificationFunc NotifFuncPtr;
    uartChannelIdType_e  ChannelId;
    const char            *psSE_clock;
    uint32 	   ulClkFrequency;
} uartHWConfigType;

typedef struct
{
	uint8 crc8;
	uint8 cmd;
	uint8 version;
	uint8 len;
	uint8 seq_no;
	uint8 msg_id;
	uint8 databuff[250];
}xUartVipMsgType;

//#ifdef TEST_SRC_ENABLED
void HAL_SAIL_UART_Rx_Notification(volatile uartJobHandleType *Uart_JobResult);

void HAL_SAIL_VIPUART_RX_Notif(volatile uartJobHandleType *Uart_JobResult);
//#endif /* TEST_SRC_ENABLED */

/* callback function ptr type*/
typedef void  (*Uart_ClientNotificationCallbackFn)( uint8 *pcRxBufferPtr);

typedef struct
{
	Uart_ClientNotificationCallbackFn pCB;
    uint8 ucCommandID;
} uartNotificationDataType;

typedef struct
{
	uartNotificationDataType xDataArray[uartSAIL_MAX_NOTIFY_CLIENTS];
    uint8 ucTail;
} uartClientNotificationListType;

extern uartClientNotificationListType xNotifyData;

/*=================================================================================================
**                                    Global function prototypes                                 **
=================================================================================================*/
/*=================================================================================================
 @Service name        xUartInit
 @Description         This API Initialize the serial engine which is
                      configured for the UART driver. It will configure the
                      required clock and GPIO.
 @param[in]           ucHardwareID - Hardware ID of UART  
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
uartStatusType_e xUartInit(uint8  ucHardwareID);

/*=================================================================================================
 @Service name        ulUartWrite
 @Description         This API will transmit the data over the UART. It
                      support both polling and interrupt mode.
 @param[in]           ucChannelId - Uart channel to communicate
 	 	 	 	 	  buf - Tx buffer pointer
					  bytes_to_tx - Number of bytes to transfer
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 - number of bytes transferred
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
uartStatusType_e ulUartWrite(uartChannelIdType_e ucChannelId, const char* buf, uint32 bytes_to_tx);

/*=================================================================================================
 @Service name        ulUartRead
 @Description         This API will receive the data over the UART. It
                      support both polling and interrupt mode.
 @param[in]           ucChannelId - Uart channel to communicate
 	 	 	 	 	  bytes_to_rx - Number of bytes to transfer
					  buf - Rx buffer pointer
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
uint32 ulUartRead(uartChannelIdType_e ucChannelId, char* buf, uint32 bytes_to_rx);

/*=================================================================================================
 @Service name        bUartConnectionStatus
 @Description         This function will check if the UART is connected or not
 @param[in]           ucChannelID - ucChannelID number of UART
 @param[out]          NA
 @param[in, out]      NA
 @return              UART Connection status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Asynchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
uartConnectionStatusType_e bUartConnectionStatus(uint8 ucChannelId);

/*=================================================================================================
 @Service name        xUartDeInit
 @Description         This API De-Initialize the serial engine which is
                      configured for the UART driver. It will disable the
                      required clock and GPIO.
 @param[in]           ucHardwareID - Hardware ID of UART
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
uartStatusType_e xUartDeInit(uint8 ucHardwareID);

/*=================================================================================================
 @Service name        eUartRegisterNotification
 @Description         This function is called by uart clients who receive packets from external MCU
 @param[in]           pCB - Callback function name
 	 	 	 	 	  ucCommandID - Command ID specific to each client
 @param[out]          NA
 @param[in, out]      NA
 @return              uartStatusType_e - UART register notification status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/

uartStatusType_e eUartRegisterNotification (
                    Uart_ClientNotificationCallbackFn pCB,
					uint8 ucCommandID );
					
					/*=================================================================================================
 @Service name        eUartDeRegisterNotification
 @Description         This function is called by uart clients to de-register
 	 	 	 	 	  packet reception from external MCU
 @param[in]           pCB - Callback function name
 @param[out]          NA
 @param[in, out]      NA
 @return              uartStatusType_e - UART de-register notification status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
uartStatusType_e eUartDeRegisterNotification (
		Uart_ClientNotificationCallbackFn pCB );

#endif /* UART_H */
