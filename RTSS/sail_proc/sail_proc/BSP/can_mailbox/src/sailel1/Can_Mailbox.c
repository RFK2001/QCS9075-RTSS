/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/
/*==============================================================================
	File Name.............. : Can_Mailbox.c
	Description............ : This file contains functionality of CAN Mailbox
	Autosar Release Version :
	Platform............... :
	SW Release Version..... :
==============================================================================*/
/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <stdint.h>
#include "stdio.h"
#include "debug_log.h"
#include "Can_Mailbox_Task.h"
#include "Can_Mailbox.h"
#include "isd.h"
#include "mailboxLib.h"
#include "mailboxExt_api.h"
#include "chipinfo.h"
/*=================================================================================================
**                                   Local macros, variables and constants                       **
==================================================================================================*/
#define CAN_MAILBOX_MAX_DATA_LEN (64U)
#define PDU_INFO_COUNT 8u

/* The size of the periodic test task stack - must be a multiple of 64. */
#define CAN_MAILBOX_TASK_STACK_SIZE (1024U)
#define CAN_SAIL_MAX_CONTOLLERS (8u)
#define CAN_MAILBOX_QUEUE_LENGTH (10u * CAN_SAIL_MAX_CONTOLLERS)
#define CAN_MAILBOX_QUEUE_ITEM_SIZE (sizeof(Can_Mb_Packet))
#define CAN_MAILBOX_QUEUE_BUFFER_SIZE (CAN_MAILBOX_QUEUE_LENGTH * CAN_MAILBOX_QUEUE_ITEM_SIZE)

#define DDR_READY_CHECK_DELAY (10U)
#define DDR_MAX_RETRY_COUNT (1000U)
#define MB_READY_CHECK_DELAY (100U)
#define NUM_MB_PACKET (1U)
#define CAN_MAILBOX_HANDSHAKE_PKT_LEN (1U)

#ifndef CAN_DATA
#define CAN_DATA __attribute__((section("can_data")))
#endif

ChipInfoFamilyType chip_family = CHIPINFO_FAMILY_32BITS;
#if defined(CHIPINFO_FAMILY_LEMANS)
#define NUMBER_OF_ACTIVE_CAN_CTRL 8u
#elif defined(CHIPINFO_FAMILY_MONACO)
#define NUMBER_OF_ACTIVE_CAN_CTRL 4u
#else
#define NUMBER_OF_ACTIVE_CAN_CTRL 8u
#endif

typedef enum
{
	CAN_MAILBOX_RX,
	CAN_MAILBOX_TX,
	CAN_MAILBOX_SET_BAUDRATE,
	CAN_MAILBOX_SD_READY,
	CAN_MAILBOX_ERROR,
} Can_Mb_Command;

typedef enum
{
	CAN_MSG_TYPE_PROTO_ERR,
	CAN_MSG_TYPE_FUSA_ERR,
	CAN_MSG_TYPE_PASSIVE_ERR,
	CAN_MSG_TYPE_BUS_OFF_ERR,
} Can_Mb_Error_Msg_Type;

typedef struct can_msg
{
	/* Pre-allocate CAN messages to the max data size */
	uint8_t data[CAN_MAILBOX_MAX_DATA_LEN]; /* CAN message data */
	uint8_t len;							/* Actual CAN message data length */
	uint32_t mid;							/* CAN message identifier */
	bool ext_id;							/* Extended CAN message info : 1=29-bit MID, 0=11-bit MID */
} Can_Mb_Msg;

typedef struct
{
	Can_Mb_Error_Msg_Type Error_Msg_Type;
	Can_ErrorStateType Err_State_Info;
	Can_ErrorType Proto_Err_Info;
	//FUSAQueueMsgType Fusa_Err_Info;
} __attribute__((packed)) Can_Mb_Error;

typedef struct
{
	uint8_t Controller_Id; /*Controller_Id: 0 - 8; 0-7 represents for 8 CAN cores, 8 represent tx for all 8 controllers */
	uint16_t hthObject;
	Can_Mb_Command Cmd;
	union
	{
		uint16_t Baudrate;
		Can_Mb_Msg Can_Msg;
		Can_Mb_Error Error;
	} data;
	uint8_t reserved[45];
} __attribute__((packed)) Can_Mb_Packet;

/* Declare task TCB. */
static StaticTask_t xCanMailboxTaskTCB = {0};

/* Declare task stack:
 * The check task stack is protected by an MPU region, so the alignment must
 * follow MPU alignment rules and aligned to a 64-byte boundary. */
static StackType_t xCanMailboxTaskStack[CAN_MAILBOX_TASK_STACK_SIZE] __attribute__((aligned(MEM_ALIGNMENT_64))) = {0};
static uint8_t xCanMailboxTaskQueueBuffer[CAN_MAILBOX_QUEUE_BUFFER_SIZE] __attribute__((aligned(MEM_ALIGNMENT_4))) = {0};
StaticQueue_t xCanMailboxQueueBuffer;

static TaskHandle_t xCanMailboxTaskHandle = NULL;
static QueueHandle_t xCanMailboxTaskQueueHandle = NULL;

/*=================================================================================================
**                                        Local function definitions                             **
=================================================================================================*/

static void canMailboxTask(void *pvParameters);

static Std_ReturnType Can_Mb_Recv_Pkt_From_Md(Can_Mb_Packet *packet, Can_Mb_Command Cmd);
static Std_ReturnType Can_Mb_Send_Pkt_To_Md(Can_Mb_Packet *mb_packet, Can_Mb_Command Cmd);

static Std_ReturnType Can_Mb_Sd_CanSrv_Write(Can_Mb_Packet *mb_packet);
static Std_ReturnType Can_Mb_Sd_CanSrv_Baud_Rate(Can_Mb_Packet *mb_packet);

static void Can_Mb_Client_Callback(xMailboxExtclienttype MBclient_ID);
static int Can_Mb_Check_Item_In_Mailbox(xMailboxExtclienttype MBclient_ID);

static Std_ReturnType Can_Mb_Write(Can_Mb_Packet *mb_packet);
static Std_ReturnType Can_Mb_Read(Can_Mb_Packet *mb_packet);

static Std_ReturnType Can_Mb_Send_Notify_MD(void);

static void Can_Mb_Sd_CanSrv_Tx_Callback(PduIdType swPduHandle, Can_HwHandleType Hth, Can_TimeStampType timeStamp);						 // need to change
static void Can_Mb_Sd_CanSrv_Rx_Callback(const Can_HwType *Mailbox, uint8 *Data, PduLengthType DataLength, Can_TimeStampType timeStamp); // need to change
static void Can_Mb_Sd_CanSrv_Can_ControllerBusOff(uint8 Controller);
static void Can_Mb_Sd_CanSrv_ControllerErrorStatePassive(uint8 Controller, uint16 RxErrCounter, uint16 TxErrCounter);
static void Can_Mb_Sd_CanSrv_ErrorNotification(uint8 Controller, Can_ErrorType ErrorType);
//static void Can_Mb_Sd_CanSrv_ReportFusaError(uint8 Controller, FUSAQueueMsgType CanFUSAMsg);

/*================================================================================
**  Function :  Can_Mb_Read
**  This function is called from the callback function registered will the mailbox
**  channel. It will read the data comming on mailbox channel from MD
** ===============================================================================
*/
static Std_ReturnType Can_Mb_Read(Can_Mb_Packet *mb_packet)
{
	Std_ReturnType ret = E_OK;
	int32 res = 0;

	res = slMailboxRead(MAILBOX_CAN, NUM_MB_PACKET, (uint8 *)mb_packet);

	if (res > 0)
	{
		DEBUG_LOG(SAIL_INFO, "%s: success \r\n", __func__);
		DEBUG_LOG(SAIL_INFO, "%s : Controller Id = %d, cmd = %d, len = %d, MsgId : %x, Hth = %d \r\n", __func__, mb_packet->Controller_Id, mb_packet->Cmd, mb_packet->data.Can_Msg.len,  mb_packet->data.Can_Msg.mid, mb_packet->hthObject);
		for(int i = 0; i < mb_packet->data.Can_Msg.len; i++)
		{
			DEBUG_LOG(SAIL_INFO, "%s DATA[%d] = %x\r\n",__func__, i, mb_packet->data.Can_Msg.data[i]);
		}
	}
	else
	{
		ret = E_NOT_OK;
		DEBUG_LOG(SAIL_ERROR, "%s : failed res = %lx \r\n", __func__, res);
	}
	return ret;
}

/*===========================================================================
**  Function :  Can_Mb_Write
**  This function will send the can packet to Mailbox channel
** ==========================================================================
*/
static Std_ReturnType Can_Mb_Write(Can_Mb_Packet *mb_packet)
{
	Std_ReturnType ret = E_OK;
	int32 res = 0;
	(void)vFreeRTOSTaskDelay(50);
	res = slMailboxWrite(MAILBOX_CAN, NUM_MB_PACKET, (uint8 *)mb_packet);

	if (res > 0)
	{
		DEBUG_LOG(SAIL_INFO, "%s : success \r\n", __func__);
		DEBUG_LOG(SAIL_INFO, "%s : Controller Id = %d, cmd = %d, len = %d, MsgId : %x\r\n", __func__, mb_packet->Controller_Id, mb_packet->Cmd, mb_packet->data.Can_Msg.len,  mb_packet->data.Can_Msg.mid);
		for(int i = 0; i < mb_packet->data.Can_Msg.len; i++)
		{
			DEBUG_LOG(SAIL_INFO, "%s DATA[%d] = %x\r\n",__func__, i, mb_packet->data.Can_Msg.data[i]);
		}
	}
	else
	{
		ret = E_NOT_OK;
		DEBUG_LOG(SAIL_ERROR, "%s : failed res = %lx \r\n", __func__, res);
	}
	return ret;
}

/*===========================================================================
**  Function :  Can_Mb_Sd_CanSrv_Write
**  This function will extract the data from can mailbox packet coming from
**  MD and set the Can_PduType and HwHandle and trigger can_write
** ==========================================================================
*/
static Std_ReturnType Can_Mb_Sd_CanSrv_Write(Can_Mb_Packet *mb_packet)
{

    Std_ReturnType ret = E_OK;
    Can_PduType pdu_info={0};
    uint8_t sduData[CAN_MAILBOX_MAX_DATA_LEN] = {0};
    Can_HwHandleType can_obj_id = 0;
	can_obj_id = mb_packet->hthObject;
	pdu_info.swPduHandle = 0; // taken dummy
	pdu_info.length = mb_packet->data.Can_Msg.len;
	pdu_info.id = mb_packet->data.Can_Msg.mid;
	pdu_info.sdu = sduData;
	for (uint8_t i = 0; i < pdu_info.length; i++) {
		pdu_info.sdu[i] = mb_packet->data.Can_Msg.data[i];
	}
    ret = xCanSrv_Write(can_obj_id, &pdu_info);
    if (ret != E_OK) {
        DEBUG_LOG(SAIL_ERROR, "%s: Can_Write failed ret = %lx\r\n", __func__, ret);
    }
    return ret;
}
/*===========================================================================
**  Function :  Can_Mb_Sd_CanSrv_Baud_Rate
**  This function will set the can controller baudrate based on the value
**  set from MD
** ==========================================================================
*/
static Std_ReturnType Can_Mb_Sd_CanSrv_Baud_Rate(Can_Mb_Packet *mb_packet)
{
	uint8_t controller_id = mb_packet->Controller_Id;
	uint16_t baudrate_id = mb_packet->data.Baudrate;
	Can_ControllerStateType ControllerMode = CAN_CS_UNINIT;
	Std_ReturnType ret = E_OK;
	DEBUG_LOG(SAIL_LOG_NOUART, "%s: Setting Baudrate configuration to %d \r\n", __func__, baudrate_id);
	ret = xCanSrv_GetControllerMode(controller_id, &ControllerMode);
	if (ret == E_NOT_OK)
	{
		DEBUG_LOG(SAIL_ERROR, "%s: xCanSrv_GetControllerMode failed ret = %d\r\n", __func__, ret);
		return ret;
	}
	if (ControllerMode != CAN_CS_STOPPED)
	{
		ret = xCanSrv_SetControllerMode(controller_id, CAN_CS_STOPPED);
		if (ret == E_NOT_OK)
		{
			DEBUG_LOG(SAIL_ERROR, "%s: xCanSrv_SetControllerMode failed ret = %d\r\n", __func__, ret);
			return ret;
		}

		ret = xCanSrv_GetControllerMode(controller_id, &ControllerMode);
		if (ret == E_NOT_OK)
		{
			DEBUG_LOG(SAIL_ERROR, "%s: xCanSrv_GetControllerMode failed ret = %d\r\n", __func__, ret);
			return ret;
		}

		if (ControllerMode != CAN_CS_STOPPED)
		{
			DEBUG_LOG(SAIL_ERROR, "%s: CAN controller not set to CAN_CS_STOPPED \r\n", __func__);
			return E_NOT_OK;
		}
	}
	ret = xCanSrv_SetBaudrate(controller_id, baudrate_id);
	if (ret == E_NOT_OK)
	{
		DEBUG_LOG(SAIL_ERROR, "%s: xCanSrv_SetBaudrate failed ret = %d\r\n", __func__, ret);
		return ret;
	}
	ret = xCanSrv_SetControllerMode(controller_id, CAN_CS_STARTED);
	if (ret == E_NOT_OK)
	{
		DEBUG_LOG(SAIL_ERROR, "%s: xCanSrv_SetControllerMode failed ret = %d\r\n", __func__, ret);
		return ret;
	}
	ret = xCanSrv_GetControllerMode(controller_id, &ControllerMode);
	if (ret == E_NOT_OK)
	{
		DEBUG_LOG(SAIL_ERROR, "%s: xCanSrv_GetControllerMode failed ret = %d\r\n", __func__, ret);
		return ret;
	}
	if (ControllerMode != CAN_CS_STARTED)
	{
		DEBUG_LOG(SAIL_ERROR, "%s: CAN controller not set to CAN_CS_STARTED \r\n", __func__);
		return E_NOT_OK;
	}
	return ret;
}

/*===========================================================================
**  Function :  Can_Mb_Send_Pkt_To_Md
**  This function will send the can packet to Mailbox channel
** ==========================================================================
*/
static Std_ReturnType Can_Mb_Send_Pkt_To_Md(Can_Mb_Packet *mb_packet, Can_Mb_Command Cmd)
{
	Std_ReturnType ret = E_OK;

	if (mb_packet->Cmd == CAN_MAILBOX_RX)
	{
		ret = Can_Mb_Write(mb_packet);
		if (ret != E_OK)
		{
			DEBUG_LOG(SAIL_WARNING, "%s: CAN_MAILBOX_RX failed ret = %lx\r\n", __func__, ret);
		}
	}
	else if (mb_packet->Cmd == CAN_MAILBOX_SD_READY)
	{
		ret = Can_Mb_Write(mb_packet);
		if (ret != E_OK)
		{
			DEBUG_LOG(SAIL_WARNING, "%s : CAN_MAILBOX_SD_READY failed ret = %lx\r\n", __func__, ret);
		}
	}
	else if (mb_packet->Cmd == CAN_MAILBOX_ERROR)
	{
		ret = Can_Mb_Write(mb_packet);
		if (ret != E_OK)
		{
			DEBUG_LOG(SAIL_WARNING, "%s : CAN_MAILBOX_ERROR failed ret = %lx\r\n", __func__, ret);
		}
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, "%s: Invalid packet cmd! \r\n", __func__);
		ret = E_NOT_OK;
	}
	return ret;
}

/*===========================================================================
**  Function :  Can_Mb_Recv_Pkt_From_Md
**  This function will receive the packet comming from
**  MD and based on the cmd write the can drv or set the baudrate.
** ==========================================================================
*/
static Std_ReturnType Can_Mb_Recv_Pkt_From_Md(Can_Mb_Packet *packet, Can_Mb_Command Cmd)
{
	Std_ReturnType ret = E_OK;
	if (packet->Cmd == CAN_MAILBOX_TX)
	{
		ret = Can_Mb_Sd_CanSrv_Write(packet);
		if (ret != E_OK)
		{
			DEBUG_LOG(SAIL_ERROR, "%s : CAN_MAILBOX_TX failed ret = %lx\r\n", __func__, ret);
		}
	}
	else if (packet->Cmd == CAN_MAILBOX_SET_BAUDRATE)
	{
		ret = Can_Mb_Sd_CanSrv_Baud_Rate(packet);
		if (ret != E_OK)
		{
			DEBUG_LOG(SAIL_ERROR, "%s : CAN_MAILBOX_SET_BAUDRATE failed! ret = %lx \r\n", __func__, ret);
		}
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, "%s: Invalid packet command  \r\n", __func__);
		ret = E_NOT_OK;
	}
	return ret;
}

/*===========================================================================
**  Function :  Can_Mb_Sd_CanSrv_Rx_Callback
**  This function will extract the data from rx msg of can driver packetize it
**   and send it to the xCanMailboxTaskQueueHandle.
** ==========================================================================
*/
static void Can_Mb_Sd_CanSrv_Rx_Callback(const Can_HwType *Mailbox, uint8 *Data, PduLengthType DataLength, Can_TimeStampType timeStamp)
{
	BaseType_t xQSendStatus = pdFAIL;
	Can_Mb_Packet sdDataBuff = {0};
	sdDataBuff.Controller_Id = Mailbox->ControllerId;
	sdDataBuff.Cmd = CAN_MAILBOX_RX;
	sdDataBuff.data.Can_Msg.mid = Mailbox->CanId;
	sdDataBuff.data.Can_Msg.len = DataLength;

	for (int i = 0; i < DataLength; i++)
	{
		sdDataBuff.data.Can_Msg.data[i] = Data[i];
	}

	xQSendStatus = xFreeRTOSQueueSend(xCanMailboxTaskQueueHandle, &sdDataBuff, 0);
	if (xQSendStatus != pdPASS)
	{
		DEBUG_LOG(SAIL_ERROR, "%s : xFreeRTOSQueueSend FAILED = %lx \r\n", __func__, xQSendStatus);
	}
	return;
}
/*===========================================================================
**  Function :  Can_Mb_Sd_CanSrv_Tx_Callback
**  This function will print the data received from MD
** ==========================================================================
*/
static void Can_Mb_Sd_CanSrv_Tx_Callback(PduIdType swPduHandle, Can_HwHandleType Hth, Can_TimeStampType timeStamp)
{
	DEBUG_LOG(SAIL_INFO, "%s with swPduHandle: %d, Hth: %d,  timeStamp.sec:%d timeStamp.ns:%d\r\n",
			  __func__, swPduHandle, Hth, timeStamp.seconds, timeStamp.nanoseconds);
}

/*===========================================================================
**  Function :  Can_Mb_Sd_CanSrv_ErrorNotification
**  This function will extract the error details when a protocol error occurs
**   and packetize it and sends it to the xCanMailboxTaskQueueHandle.
** ==========================================================================
*/
static void Can_Mb_Sd_CanSrv_ErrorNotification(uint8 Controller, Can_ErrorType ErrorType)
{
	BaseType_t xQSendStatus = pdFAIL;
	Can_Mb_Packet can_err_notification_packet = {0};
	can_err_notification_packet.Controller_Id = Controller;
	can_err_notification_packet.Cmd = CAN_MAILBOX_ERROR;
	can_err_notification_packet.data.Error.Error_Msg_Type = CAN_MSG_TYPE_PROTO_ERR;
	can_err_notification_packet.data.Error.Proto_Err_Info = ErrorType;

	xQSendStatus = xFreeRTOSQueueSend(xCanMailboxTaskQueueHandle, &can_err_notification_packet, 0);
	if (xQSendStatus != pdPASS)
	{
		DEBUG_LOG(SAIL_ERROR, "%s : xFreeRTOSQueueSend FAILED = %lx \r\n", __func__, xQSendStatus);
	}
	return;
}

/*===========================================================================
**  Function :  Can_Mb_Sd_CanSrv_ReportFusaError
**  This function will extract the error details when a fusa error occurs
**   and packetize it and sends it to the xCanMailboxTaskQueueHandle.
** ==========================================================================
*/
// static void Can_Mb_Sd_CanSrv_ReportFusaError(uint8 Controller, FUSAQueueMsgType CanFUSAMsg)
// {
// 	portBaseType xQSendStatus = pdFAIL;
// 	Can_Mb_Packet can_fusa_err_packet = {0};
// 	can_fusa_err_packet.Controller_Id = Controller;
// 	can_fusa_err_packet.Cmd = CAN_MAILBOX_ERROR;
// 	can_fusa_err_packet.data.Error.Error_Msg_Type = CAN_MSG_TYPE_FUSA_ERR;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.eEventId = CanFUSAMsg.eEventId;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.eEventType = CanFUSAMsg.eEventType;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.eEventDomain = CanFUSAMsg.eEventDomain;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.eEventSource = CanFUSAMsg.eEventSource;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.ucTSValid = CanFUSAMsg.ucTSValid;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.ulLowTS = CanFUSAMsg.ulLowTS;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.ulHighTS = CanFUSAMsg.ulHighTS;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.ulPayloadLen = CanFUSAMsg.ulPayloadLen;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.ulHighTS = CanFUSAMsg.ulHighTS;
// 	can_fusa_err_packet.data.Error.Fusa_Err_Info.ucErrData[0] = CanFUSAMsg.ucErrData[0];

// 	xQSendStatus = xFreeRTOSQueueSend(xCanMailboxTaskQueueHandle, &can_fusa_err_packet, 0);
// 	if (xQSendStatus != pdPASS)
// 	{
// 		DEBUG_LOG(SAIL_ERROR, "%s : xFreeRTOSQueueSend FAILED = %lx \r\n", __func__, xQSendStatus);
// 	}
// 	return;
// }

/*===========================================================================
**  Function :  Can_Mb_Sd_CanSrv_ControllerErrorStatePassive
**  This function will extract the error details when a passive error occurs
**   and packetize it and sends it to the xCanMailboxTaskQueueHandle.
** ==========================================================================
*/
static void Can_Mb_Sd_CanSrv_ControllerErrorStatePassive(uint8 Controller, uint16 RxErrCounter, uint16 TxErrCounter)
{
	BaseType_t xQSendStatus = pdFAIL;
	Can_Mb_Packet can_err_state_passive_packet = {0};
	can_err_state_passive_packet.Controller_Id = Controller;
	can_err_state_passive_packet.Cmd = CAN_MAILBOX_ERROR;
	can_err_state_passive_packet.data.Error.Error_Msg_Type = CAN_MSG_TYPE_PASSIVE_ERR;
	can_err_state_passive_packet.data.Error.Err_State_Info = CAN_ERRORSTATE_PASSIVE;
	xQSendStatus = xFreeRTOSQueueSend(xCanMailboxTaskQueueHandle, &can_err_state_passive_packet, 0);
	if (xQSendStatus != pdPASS)
	{
		DEBUG_LOG(SAIL_ERROR, "%s : xFreeRTOSQueueSend FAILED = %lx \r\n", __func__, xQSendStatus);
	}
	return;
}

/*===========================================================================
**  Function :  Can_Mb_Sd_CanSrv_Can_ControllerBusOff
**  This function will extract the error details when a busoff error occurs
**   and packetize it and sends it to the xCanMailboxTaskQueueHandle.
** ==========================================================================
*/

static void Can_Mb_Sd_CanSrv_Can_ControllerBusOff(uint8 Controller)
{
	BaseType_t xQSendStatus = pdFAIL;
	Can_Mb_Packet can_err_state_passive_packet = {0};
	can_err_state_passive_packet.Controller_Id = Controller;
	can_err_state_passive_packet.Cmd = CAN_MAILBOX_ERROR;
	can_err_state_passive_packet.data.Error.Error_Msg_Type = CAN_MSG_TYPE_BUS_OFF_ERR;
	can_err_state_passive_packet.data.Error.Err_State_Info = CAN_ERRORSTATE_BUSOFF;

	xQSendStatus = xFreeRTOSQueueSend(xCanMailboxTaskQueueHandle, &can_err_state_passive_packet, 0);
	if (xQSendStatus != pdPASS)
	{
		DEBUG_LOG(SAIL_ERROR, "%s : xFreeRTOSQueueSend FAILED = %lx \r\n", __func__, xQSendStatus);
	}
	return;
}
/*================================================================================
**  Function :  Can_Mb_Check_Item_In_Mailbox
**  This function is called from the callback function registered will the mailbox channel.
**  It will get the count of items present on MB channel
** ===============================================================================
*/
static int Can_Mb_Check_Item_In_Mailbox(xMailboxExtclienttype MBclient_ID)
{
	int32 mbChannelItemCnt = 0;
	/* Get the number of valid item for the requested region*/
	mbChannelItemCnt = slMailbox_Get_ValidItemNum(MBclient_ID);
	if (mbChannelItemCnt <= 0)
	{
		DEBUG_LOG(SAIL_WARNING, "%s: mbChannelItemCnt <= 0 %lx \r\n", __func__, mbChannelItemCnt);
		return 0;
	}

	return mbChannelItemCnt;
}
/*================================================================================
**  Function :  Can_Mb_Client_Callback
**  This function is a callback function registered will the mailbox channel.
** ===============================================================================
*/
static void Can_Mb_Client_Callback(xMailboxExtclienttype MBclient_ID)
{
	Std_ReturnType ret = E_OK;
	BaseType_t xQSendStatus = pdFAIL;
	Can_Mb_Packet mdDatabuff = {0};
	int numItemInMbChannel = 0;
	if ((ISLAND_STATE == eISDGetCurrentState()) && (MBclient_ID != MAILBOX_CAN))
	{
		freertosYIELD_FROM_ISR();
		DEBUG_LOG(SAIL_ERROR, "%s: Invalid client ID \r\n", __func__);
		return;
	}
	numItemInMbChannel = Can_Mb_Check_Item_In_Mailbox(MAILBOX_CAN);
	if (numItemInMbChannel <= 0)
	{
		DEBUG_LOG(SAIL_ERROR, "%s: Vaild items are not present in mb channel \r\n", __func__);
		return;
	}
	for (int i = 0; i < numItemInMbChannel; i++)
	{
		ret = Can_Mb_Read(&mdDatabuff);
		if (ret != E_OK)
		{
			DEBUG_LOG(SAIL_ERROR, "%s: Can_Mb_Read() Failed ret = %lx\r\n", __func__, ret);
			return;
		}
		else
		{
			xQSendStatus = xFreeRTOSQueueSendFromISR(xCanMailboxTaskQueueHandle, (void *)&mdDatabuff);
			if (xQSendStatus != pdPASS)
			{
				DEBUG_LOG(SAIL_ERROR, "%s : xFreeRTOSQueueSendFromISR() FAILED xQSendStatus = %lx \r\n", __func__, xQSendStatus);
			}
			freertosYIELD_FROM_ISR();
		}
	}
}
/*================================================================================
**  Function :  Can_Mb_Init
**  Task to take action from sail side to register for canSrv callbacks
** ===============================================================================
*/
Std_ReturnType Can_Mb_Init(void)
{
	Std_ReturnType ret = E_OK;
	xCan_ClientCtxt_Type CanMbNotifiers = {NULL};
	CanMbNotifiers.xCanSrv_Cb_TxConfirmation = Can_Mb_Sd_CanSrv_Tx_Callback;
	CanMbNotifiers.xCanSrv_Cb_RxIndication = Can_Mb_Sd_CanSrv_Rx_Callback;
	CanMbNotifiers.xCanSrv_Cb_ControllerBusOff = Can_Mb_Sd_CanSrv_Can_ControllerBusOff;
	CanMbNotifiers.xCanSrv_Cb_ControllerErrorStatePassive = Can_Mb_Sd_CanSrv_ControllerErrorStatePassive;
	CanMbNotifiers.xCanSrv_Cb_ErrorNotification = Can_Mb_Sd_CanSrv_ErrorNotification;
	//CanMbNotifiers.xCanSrv_Cb_ReportFusaError = Can_Mb_Sd_CanSrv_ReportFusaError;

    /* Test app subcribes all HOHs */
    for (uint8 i = 0; i < MAX_HW_OBJ_CNT; i++)
    {
        CanMbNotifiers.HwObjId[i] = i;
    }
	CanMbNotifiers.HwObjCnt= MAX_HW_OBJ_CNT;
	
	ret = xCanSrv_Register_Client(CanMbNotifiers);
	if (ret != E_OK)
	{
		DEBUG_LOG(SAIL_WARNING, "%s: xCanSrv_Register_Client failed ret = %lx\r\n", __func__, ret);
		return ret;
	}
	ret = Can_Mb_Send_Notify_MD();
	if (ret != E_OK)
	{
		DEBUG_LOG(SAIL_WARNING, "%s: Can_Mb_Send_Notify_MD failed ret = %lx\r\n", __func__, ret);
		return ret;
	}
	return ret;
}
/*================================================================================
**  Function : Can_Mb_Send_Notify_MD
**  Task to take action from sail side to send handshake pkt to MD stating SAIL
**  is Ready
** ===============================================================================
*/
static Std_ReturnType Can_Mb_Send_Notify_MD(void)
{
	Std_ReturnType ret = E_OK;
	BaseType_t xQSendStatus = pdFAIL;
	Can_Mb_Packet mb_handshake_pkt = {0};
	mb_handshake_pkt.Cmd = CAN_MAILBOX_SD_READY;
	mb_handshake_pkt.data.Can_Msg.len = CAN_MAILBOX_HANDSHAKE_PKT_LEN;
	xQSendStatus = xFreeRTOSQueueSend(xCanMailboxTaskQueueHandle, &mb_handshake_pkt, 0);
	if (xQSendStatus != pdPASS)
	{
		DEBUG_LOG(SAIL_ERROR, "%s : xFreeRTOSQueueSend FAILED = %lx \r\n", __func__, xQSendStatus);
	}
	return ret;
}
/*================================================================================
**  Function :  canMailboxTask
**  Task to take action from sail side to receive can data from Main Domain
**  and send to can Srv and data received from Can controller to MD.
** ===============================================================================
*/
static void canMailboxTask(void *pvParameters)
{
	Can_Mb_Packet mb_packet = {0};
	uint32 ddrRetryCnt = 0;
	Std_ReturnType ret = E_OK;
	BaseType_t xReturn = pdFAIL;
	Std_ReturnType Status = E_OK;
	/* Poll eISDGetStatusEl1 to see when APPS/DDR is ready. */
	while (S1_READY_SUCCESS != eISDGetStatus(ISD_GET_S1_READY_STATUS))
	{
		(void)vFreeRTOSTaskDelay(DDR_READY_CHECK_DELAY);
		ddrRetryCnt++;
		if (ddrRetryCnt % DDR_MAX_RETRY_COUNT == 1U)
		{
			DEBUG_LOG(SAIL_WARNING, "%s: MD S1 NOT READY!!! retry_cnt(%u).\n\r", __func__, ddrRetryCnt);
		}
	}
	DEBUG_LOG(SAIL_WARNING, "%s: DDR READY MD side!!\r\n", __func__);
	/* Check External Mailbox Status */
	while (MB_E2EREADY != eMailbox_Get_Status())
	{
		(void)vFreeRTOSTaskDelay(MB_READY_CHECK_DELAY);
	}
	DEBUG_LOG(SAIL_INFO, "%s: Mailbox is ready \n\r", __func__);
	//vFreeRTOSTaskDelay(pdMS_TO_TICKS(200));/* Give CAN tasks additional time to fully initialize */
	DEBUG_LOG(SAIL_INFO, "%s: Setting CAN controllers to STARTED mode\r\n", __func__);
	for(int Controller = 0; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++)
	{
		DEBUG_LOG(SAIL_INFO, "%s: Setting Controller %d to STARTED\r\n", __func__, Controller);
		ret = xCanSrv_SetControllerMode(Controller, CAN_CS_STARTED);
		if (ret == E_OK)
		{
			DEBUG_LOG(SAIL_INFO, "%s: Controller %d set to STARTED mode successfully\r\n", __func__, Controller);
		}
		else
		{
			DEBUG_LOG(SAIL_ERROR, "%s: Failed to set Controller %d to STARTED mode\r\n", __func__, Controller);
		}
		(void)vFreeRTOSTaskDelay(50); //delay to make sure controller state is updated
	}
	DEBUG_LOG(SAIL_INFO, "%s: All CAN controllers initialized\r\n", __func__);
	Status = Can_Mb_Init();
	if (Status == E_OK)
	{
		DEBUG_LOG(SAIL_INFO, "Can_Mb_Init success\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, "Can_Mb_Init failed\r\n");
	}
	for (;;)
	{
		xReturn = xFreeRTOSQueueReceive(xCanMailboxTaskQueueHandle, &mb_packet, pdMS_TO_TICKS(freertosMAX_DELAY));
		// check if there are any message to receive from queue
		if (pdPASS == xReturn)
		{

			switch (mb_packet.Cmd)
			{
				case CAN_MAILBOX_SD_READY:
				{
					ret = Can_Mb_Send_Pkt_To_Md(&mb_packet, CAN_MAILBOX_SD_READY);
					if (ret != E_OK)
					{
						DEBUG_LOG(SAIL_ERROR, "%s : CAN_MAILBOX_TX failed ret = %lx\r\n", __func__, ret);
					}
				}
				break;
				case CAN_MAILBOX_RX:
				{
					ret = Can_Mb_Send_Pkt_To_Md(&mb_packet, CAN_MAILBOX_RX);
					if (ret != E_OK)
					{
						DEBUG_LOG(SAIL_ERROR, "%s : CAN_MAILBOX_TX failed ret = %lx\r\n", __func__, ret);
					}
				}
				break;
				case CAN_MAILBOX_TX:
				{
					ret = Can_Mb_Recv_Pkt_From_Md(&mb_packet, CAN_MAILBOX_TX);
					if (ret != E_OK)
					{
						DEBUG_LOG(SAIL_ERROR, "%s : CAN_MAILBOX_TX failed ret = %lx\r\n", __func__, ret);
					}
				}
				break;
				case CAN_MAILBOX_SET_BAUDRATE:
				{
					ret = Can_Mb_Recv_Pkt_From_Md(&mb_packet, CAN_MAILBOX_SET_BAUDRATE);
					if (ret != E_OK)
					{
						DEBUG_LOG(SAIL_ERROR, "%s : CAN_MAILBOX_SET_BAUDRATE failed ret = %lx \r\n", __func__, ret);
					}
				}
				break;
				case CAN_MAILBOX_ERROR:
				{
					DEBUG_LOG(SAIL_WARNING, "Size of Can_Mb_Packet = %d\n\r", sizeof(Can_Mb_Packet));
					ret = Can_Mb_Send_Pkt_To_Md(&mb_packet, CAN_MAILBOX_ERROR);
					if (ret != E_OK)
					{
						DEBUG_LOG(SAIL_ERROR, "%s : CAN_MAILBOX_ERROR failed ret = %lx\r\n", __func__, ret);
					}
				}
				break;
				default:
					// Added for MISRA
					break;
			}
		}
		else
		{
			DEBUG_LOG(SAIL_ERROR, "%s :  xFreeRTOSQueueReceive() failed xReturn %lx \r\n", __func__, xReturn);
		}
	}
}

/*=================================================================================================
**                                   Global function definitions                                 **
==================================================================================================*/

/* Can Mailbox task init */
BaseType_t xCanMailboxTaskInit( CPUIdType_e           xSchdCore,
                              UBaseType_t  xTaskPrior )
{
    BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;

	DEBUG_LOG( SAIL_ERROR, "***%s*******\r\n",  __func__);
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
			.pvTaskCode = canMailboxTask,						/* The function that implements the task being created. */
			.pcName = "canMailboxTask",						/* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
			.pxTaskBuffer = &xCanMailboxTaskTCB,				/* The buffer allocated for use as the task TCB. */
			.puxStackBuffer = xCanMailboxTaskStack,				/* The buffer allocated for use as the task stack. */
			.usStackDepth = CAN_MAILBOX_TASK_STACK_SIZE,		/* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
			.pvParameters = NULL,							/* The task parameter, not used in this case. */
			.uxPriority = (xTaskPrior), /* The priority assigned to the task being created. */
			.xRegions = {				   /* The MPU task parameters. */
						 {NULL, 0UL, 0UL}, /* No additional region definitions are required. */
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL}}};

	uxCoreAffinityMask = (1 << xSchdCore);
	/* Create the check task. */
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters, uxCoreAffinityMask, &xCanMailboxTaskHandle); //use affinity 
	if (xResult == pdPASS)
	{
		/* MB channel registration */
		BaseType_t ret = pdFAIL;
		ret = slMailboxClientReg(MAILBOX_CAN, Can_Mb_Client_Callback);
		if (MB_E_SUCCESS == ret)
		{
			DEBUG_LOG(SAIL_LOG_NOUART, " %s: slMailboxClientReg() success \r\n", __func__)
		}
		else
		{
			DEBUG_LOG(SAIL_ERROR, " %s: slMailboxClientReg() failed ret = %lx\r\n", __func__, ret)
		}
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, " %s: xTaskCreate() failed xResult = %lx \r\n", __func__, xResult)
	}
	DEBUG_LOG(SAIL_ERROR,"%s <-- xResult=%ld\n\r", __func__, xResult);
    return xResult;
}

BaseType_t xCanMailboxTaskResourceInit(CPUIdType_e xSchdCore)
{
	DEBUG_LOG(SAIL_LOG_NOUART, "%s : \r\n", __func__);
	BaseType_t xResult = pdPASS;
	xResult = xFreeRTOSQueueCreate(xCanMailboxTaskQueueBuffer,
						   CAN_MAILBOX_QUEUE_LENGTH,
						   CAN_MAILBOX_QUEUE_ITEM_SIZE,
						   &xCanMailboxTaskQueueHandle,
						   &xCanMailboxQueueBuffer);
	if (xResult != pdPASS)
	{
		DEBUG_LOG(SAIL_ERROR, " %s: xFreeRTOSQueueCreate() failed xResult = %lx \r\n", __func__, xResult)
	}

	return xResult;
}
