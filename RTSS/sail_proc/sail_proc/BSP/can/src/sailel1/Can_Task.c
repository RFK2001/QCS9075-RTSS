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
/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

#include "CanTrcv_184_Tcan1146.h"
#include "CanTrcv_184_Tcan1044.h"
#include "CanTrcv_184_Tcan1044_Plt_Cfg.h"
#include "CanTrcv_184_Tcan1146_Plt_Cfg.h"

#include "Can_Plt_Cfg.h"
#include "CanIf.h"
#include "Can_SafeRTOS.h"
#include "Can.h"
#include "Can_Drv.h"
#include "Can_Task.h"
#include "SchM_Can.h"
#include "xCanSrv.h"
#include "xCanSrv_Internal.h"

#include "chipinfo.h"
#include "sleepEl1.h"
#include "sleep_cmm.h"
#include "sailbsp_mutex.h"
#include "sail_canss_hwio.h"
#include "sail_tlmm_hwio.h"
//#include "sail_eam_hwio.h"
//#include "sail_qupv3_hwio.h"

/*=========================================================================================================
**                                        Local defines and macros                                       **
=========================================================================================================*/

#define SAILCAN_CANSS_0_CANSS_BASE                       (void *)SAILSS_CANSS_0_CANSS_BASE

#define SAILCAN_TLMM_SAILSS_TLMM_BASE                    (void*)SAILSS_TLMM_SAILSS_SAILSS_SAILSS_TLMM_REG_REG_BASE
#define SAILCAN_TLMM_SAILSS_TLMM_BASE_SIZE               SAILSS_TLMM_SAILSS_SAILSS_SAILSS_TLMM_REG_REG_BASE_SIZE

#define SAILCAN_QUPV3_1_QUPV3_ID_1_BASE                  (void*)QUPV3_COMMON_REG_BASE
#define SAILCAN_QUPV3_1_QUPV3_ID_1_BASE_SIZE             QUPV3_COMMON_REG_BASE_SIZE

#define SAILCAN_CSR_SAILSS_CSR_BASE				         (void *)SAILSS_EAM_SAILSS_EAM_REG_BASE
#define SAILCAN_CSR_SAILSS_CSR_BASE_SIZE 				 SAILSS_EAM_SAILSS_EAM_REG_BASE_SIZE

extern uint32_t Image$$lnkCANDATAStartAddr$$ZI$$Base;
extern uint32_t Image$$lnkCANDATAEndAddr$$ZI$$Base;

#define SAIL_CAN_DATA_ADDR_BASE        ((void *)&Image$$lnkCANDATAStartAddr$$ZI$$Base)
#define SAIL_CAN_DATA_ADDR_SIZE        (uint32_t)( (uint32_t)&Image$$lnkCANDATAEndAddr$$ZI$$Base -\
                                                             (uint32_t)&Image$$lnkCANDATAStartAddr$$ZI$$Base )
extern uint32_t Image$$lnkSPIDATAStartAddr$$ZI$$Base;
extern uint32_t Image$$lnkSPIDATAEndAddr$$ZI$$Base;

#define SAILBSP_SPI_DATA_ADDR_BASE        (void *)&Image$$lnkSPIDATAStartAddr$$ZI$$Base
#define SAILBSP_SPI_DATA_ADDR_SIZE        (uint32_t)( (uint32_t)&Image$$lnkSPIDATAEndAddr$$ZI$$Base -\
                                                            (uint32_t)&Image$$lnkSPIDATAStartAddr$$ZI$$Base )
extern uint32_t Image$$lnkTESTDATAStartAddr$$ZI$$Base;
extern uint32_t Image$$lnkTESTDATAEndAddr$$ZI$$Base;
#define SAIL_TEST_DATA_ADDR_BASE        ((void *)&Image$$lnkTESTDATAStartAddr$$ZI$$Base)
#define SAIL_TEST_DATA_ADDR_SIZE        (uint32_t)( (uint32_t)&Image$$lnkTESTDATAEndAddr$$ZI$$Base -\
                                                            (uint32_t)&Image$$lnkTESTDATAStartAddr$$ZI$$Base )

#ifdef CAN_DMA_DDR_ADDR_ENABLE
	extern uint32_t Image$$lnkCANDDRDATAStartAddr$$ZI$$Base;
	extern uint32_t Image$$lnkCANDDRDATAEndAddr$$ZI$$Base;
	#define SAIL_CAN_DMA_DDR_ADDR_BASE		((void *)&Image$$lnkCANDDRDATAStartAddr$$ZI$$Base)
	#define SAIL_CAN_DMA_DDR_ADDR_SIZE		(uint32_t)( (uint32_t)&Image$$lnkCANDDRDATAEndAddr$$ZI$$Base -\
																(uint32_t)&Image$$lnkCANDDRDATAStartAddr$$ZI$$Base )
#else
	extern uint32_t Image$$lnkCANSRAMDATAStartAddr$$ZI$$Base;
	extern uint32_t Image$$lnkCANSRAMDATAEndAddr$$ZI$$Base;
	#define SAIL_CAN_DMA_SRAM_ADDR_BASE		((void *)&Image$$lnkCANSRAMDATAStartAddr$$ZI$$Base)
	#define SAIL_CAN_DMA_SRAM_ADDR_SIZE		(uint32_t)( (uint32_t)&Image$$lnkCANSRAMDATAEndAddr$$ZI$$Base -\
																(uint32_t)&Image$$lnkCANSRAMDATAStartAddr$$ZI$$Base )
#endif

/*Set CAN baudrate event*/
#define XCAN_EVENT_BIT_SET_BAUD_RATE_E_OK			BIT( 0 )
#define XCAN_EVENT_BIT_SET_BAUD_RATE_E_NOT_OK		BIT( 1 )

/*Set CAN controller mode event*/
#define XCAN_EVENT_BIT_SET_CNTLR_MODE_E_OK			BIT( 0 )
#define XCAN_EVENT_BIT_SET_CNTLR_MODE_E_NOT_OK		BIT( 1 )

/*Get CAN controller mode event*/
#define XCAN_EVENT_BIT_GET_CNTLR_MODE_E_OK			BIT( 0 )
#define XCAN_EVENT_BIT_GET_CNTLR_MODE_E_NOT_OK		BIT( 1 )
#define XCAN_EVENT_BIT_GET_CNTLR_STATE_UNINIT		BIT( 2 )
#define XCAN_EVENT_BIT_GET_CNTLR_STATE_STARTED		BIT( 3 )
#define XCAN_EVENT_BIT_GET_CNTLR_STATE_STOPPED		BIT( 4 )
#define XCAN_EVENT_BIT_GET_CNTLR_STATE_SLEEP		BIT( 5 )

/*Can Write events*/
#define XCAN_EVENT_BIT_WRITE_E_OK					BIT( 0 )
#define XCAN_EVENT_BIT_WRITE_E_NOT_OK 				BIT( 1 )
#define XCAN_EVENT_BIT_WRITE_E_BUSY					BIT( 2 )

/*Get Can controller error state events*/
#define XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_E_OK		BIT( 0 )
#define XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_E_NOT_OK BIT( 1 )
#define XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_ACTIVE	BIT( 2 )
#define XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_PASSIVE 	BIT( 3 )
#define XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_BUS_OFF	BIT( 4 )


#define XCAN_EVENT_BIT_GET_CUR_TIME_E_OK			BIT( 0 )
#define XCAN_EVENT_BIT_GET_CUR_TIME_E_NOT_OK		BIT( 1 )	

/*Set Can Trcv mode event*/
#define XCAN_EVENT_BIT_SET_TRCV_MODE_E_OK			BIT( 0 )
#define XCAN_EVENT_BIT_SET_TRCV_MODE_E_NOT_OK		BIT( 1 )

#define XCAN_EVENT_BIT_CB_REG_E_OK					BIT( 0 )
#define XCAN_EVENT_BIT_CB_REG_E_NOT_OK				BIT( 1 )		

#define XCAN_EVENT_BIT_CB_DEREG_E_OK				BIT( 0 )
#define XCAN_EVENT_BIT_CB_DEREG_E_NOT_OK			BIT( 1 )	

/*CAN API type events*/
#define XCAN_EVENT_BIT_API_TYPE_SET_BAUDRATE     	BIT( 31 )
#define XCAN_EVENT_BIT_API_TYPE_SET_CNTLR_MODE     	BIT( 30 )
#define XCAN_EVENT_BIT_API_TYPE_GET_CNTLR_MODE		BIT( 29 )
#define XCAN_EVENT_BIT_API_TYPE_GET_ERR_STATE     	BIT( 28 )
#define XCAN_EVENT_BIT_API_TYPE_WRITE     			BIT( 27 )


typedef enum
{
    XCAN_MSG_TYPE_SET_BAUD_RATE = 0u,
    XCAN_MSG_TYPE_SET_CNTLR_MODE,
	XCAN_MSG_TYPE_GET_CNTLR_MODE,
	XCAN_MSG_TYPE_GET_CNTLR_ERR_STATE,
	XCAN_MSG_TYPE_WRITE,
	XCAN_MSG_TYPE_CUR_TIME,
	XCAN_MSG_TYPE_REG_CALLBACK,
	XCAN_MSG_TYPE_TX_CNF,
	XCAN_MSG_TYPE_RX_CNF,
	XCAN_MSG_TYPE_NTFY_CNTLR_MODE,
	XCAN_MSG_TYPE_PROTO_ERR,
	XCAN_MSG_TYPE_ERR_STATE_PASSIVE,
	XCAN_MSG_TYPE_ERR_STATE_BUS_OFF,
	XCAN_MSG_TYPE_FUSA_ERR,
	XCAN_MSG_TYPE_TCAN1146_WAKEUP,
	XCAN_MSG_TYPE_TCAN1044_WAKEUP,
	XCAN_MSG_TYPE_REG_CLIENT,
	XCAN_MSG_TYPE_DEREG_CLIENT,
	XCAN_MSG_TYPE_SET_BAUD_RATE_STATUS,
	XCAN_MSG_TYPE_SET_CNTLR_MODE_STATUS,
	XCAN_MSG_TYPE_GET_CNTLR_MODE_STATUS,
	XCAN_MSG_TYPE_GET_CNTLR_ERR_STATE_STATUS,
	XCAN_MSG_TYPE_WRITE_STATUS,
	XCAN_MSG_TYPE_CUR_TIME_STATUS,
    XCAN_MSG_TYPE_SET_TRCV_MODE,
    XCAN_MSG_TYPE_SET_TRCV_MODE_STATUS,
	XCAN_MSG_TYPE_CAN_MAINFUNCTION_READ,
	XCAN_MSG_TYPE_CAN_MAINFUNCTION_WRITE,
}xCan_MsgType;

typedef struct         
{
	uint32 					Handle;
	xCan_ClientCtxt_Type 	ClientInfo;	
}xCan_ClientCtxt; 

typedef struct
{
	Can_HwHandleType	Hth;
    PduIdType           swPduHandle;
    Can_IdType          id;
    PduLengthType 		DataLength;
	uint8 				Data[CAN_MAX_BUFF_DLC];
	Can_TimeStampType	TimeStamp;
    Can_HwHandleType    HwObjId;
} xCan_TxPduInfoType;

typedef struct
{
	Can_HwHandleType	Hrh;
	Can_PduType	        Pdu;
	Can_TimeStampType	TimeStamp;
	PduLengthType 		DataLength;
	uint8 				Data[CAN_MAX_BUFF_DLC];
	Can_HwType 			MailBox;
} xCan_RxPduInfoType;

typedef union
{
	xCan_TxPduInfoType 		TxPdu;
	xCan_RxPduInfoType		RxPdu;
}xCan_PduInfoType;

typedef union
{
	uint16 				RxErrCnt;
    uint16 				TxErrCnt;
    Can_ErrorType		ErrType;
	//FUSAQueueMsgType	Fusa;  
}xCan_ErrInfoType;

typedef union
{
	uint16					BaudRateConfigID;
	Can_ControllerStateType State;
	Can_TimeStampType		CurrTimeStamp;
	xCan_ClientCtxt			ClientCtxt;
} xCan_CfgInfoType;

typedef union
{
	xCan_CfgInfoType	CfgInfo;
	xCan_PduInfoType	PduInfo;
	xCan_ErrInfoType    ErrInfo;
}xCan_MsgInfoType; 

/* xCan Queue Message  */
typedef struct         
{
	uint8				CanCtrlID;
   	uint8				CanTrcvType; 
	uint8 				CanTrcvId;
	uint32				MsgTypeStatus;
	xCan_MsgType		MsgType;
	xCan_MsgInfoType	MsgInfo;	
}xCan_QueueMsgType;  

#define XCANSRV_TASK_QUEUE_LENGTH                ( 10u * CAN_MTTCAN_MAX_CNT )
#define XCANSRV_TASK_QUEUE_ITEM_SIZE             ( sizeof(xCan_QueueMsgType) )
#define XCANSRV_TASK_QUEUE_BUFFER_SIZE 			 (XCANSRV_TASK_QUEUE_LENGTH * XCANSRV_TASK_QUEUE_ITEM_SIZE)

/* The size of the periodic test task stack - must be a multiple of 64. */
#define XCANSRV_TASK_STACK_SIZE            ( 1024U )

#define XCAN_TASK_QUEUE_LENGTH                ( 10u * CAN_MTTCAN_MAX_CNT )
#define XCAN_TASK_QUEUE_ITEM_SIZE             ( sizeof(xCan_QueueMsgType) )
#define XCAN_TASK_QUEUE_BUFFER_SIZE 		  (XCAN_TASK_QUEUE_LENGTH * XCAN_TASK_QUEUE_ITEM_SIZE)

/* The size of the periodic test task stack - must be a multiple of 64. */
#define XCAN_TASK_STACK_SIZE            ( 2048U )


#define XCANTRCV_TASK_QUEUE_LENGTH                ( 10u * CAN_MTTCAN_MAX_CNT )  // to be checked later
#define XCANTRCV_TASK_QUEUE_ITEM_SIZE             ( sizeof(xCan_QueueMsgType) )
#define XCANTRCV_TASK_QUEUE_BUFFER_SIZE 		  (XCANTRCV_TASK_QUEUE_LENGTH * XCANTRCV_TASK_QUEUE_ITEM_SIZE)

/* The size of the periodic test task stack - must be a multiple of 64. */
#define XCANTRCV_TASK_STACK_SIZE            ( 1024U )

//CAN controller event for CAN_MTTCAN_MAX_CNT
CAN_DATA static mutex_t xCanCtrlLock[CAN_MTTCAN_MAX_CNT] = { 0 };
CAN_DATA static StaticEventGroup_t xCanCtrlEventGroup[CAN_MTTCAN_MAX_CNT] = { 0U };
CAN_DATA static EventGroupHandle_t  xCanCtrlEventGroupHandle[CAN_MTTCAN_MAX_CNT] = {NULL};

//Write event for CAN_MAX_H0H_CONFIGURED
CAN_DATA static mutex_t xCanWriteLock[CAN_MAX_HOH_CONFIGURED] = { 0 };
CAN_DATA static StaticEventGroup_t xCanWriteEventGroup[CAN_MAX_HOH_CONFIGURED] = { 0U };
CAN_DATA static EventGroupHandle_t  xCanWriteEventGroupHandle[CAN_MAX_HOH_CONFIGURED] = {NULL};
/*
//CAN Trcv event for CAN_MTTCAN_MAX_CNT
CAN_DATA static eventGroupType xCanTrcvEventGroup[CAN_MTTCAN_MAX_CNT] = { 0U };
CAN_DATA static eventGroupHandleType  xCanTrcvEventGroupHandle[CAN_MTTCAN_MAX_CNT] = {NULL};
*/
 CAN_DATA static uint32 xCanTaskSleepHandle = 0U;

//CanTask
static StaticTask_t xCanTaskTCB = { 0 };
/* Declare task stack:
 * The check task stack is protected by an MPU region, so the alignment must
 * follow MPU alignment rules and aligned to a 64-byte boundary. */
static StackType_t xCanTaskStack[XCAN_TASK_STACK_SIZE] __attribute__((aligned(MEM_ALIGNMENT_64))) = {0}; // changed from portInt8Type to StackType_t
static uint8_t xCanTaskQueueBuffer[XCAN_TASK_QUEUE_BUFFER_SIZE] __attribute__((aligned(MEM_ALIGNMENT_4))) = {0};
CAN_DATA static QueueHandle_t xCanTaskQueueHandle = NULL;   
StaticQueue_t xCanQueueBuffer;
CAN_DATA static TaskHandle_t xCanTaskHandle = NULL;

//CanTrcvTask
static StaticTask_t xCanTrcvTaskTCB = { 0 };
/* Declare task stack:
 * The check task stack is protected by an MPU region, so the alignment must
 * follow MPU alignment rules and aligned to a 64-byte boundary. */
static StackType_t xCanTrcvTaskStack[XCANTRCV_TASK_STACK_SIZE] __attribute__((aligned(MEM_ALIGNMENT_64))) = {0}; // changed from portInt8Type to StackType_t
static uint8_t xCanTrcvTaskQueueBuffer[XCANTRCV_TASK_QUEUE_BUFFER_SIZE] __attribute__((aligned(MEM_ALIGNMENT_4))) = {0};
CAN_DATA static QueueHandle_t xCanTrcvTaskQueueHandle = NULL;   
StaticQueue_t xCanTrcvQueueBuffer;
CAN_DATA static TaskHandle_t xCanTrcvTaskHandle = NULL;

//CanSrvTask
static StaticTask_t xCanSrvTaskTCB = { 0 };
/* Declare task stack:
 * The check task stack is protected by an MPU region, so the alignment must
 * follow MPU alignment rules and aligned to a 64-byte boundary. */
static StackType_t xCanSrvTaskStack[XCANSRV_TASK_STACK_SIZE] __attribute__((aligned(MEM_ALIGNMENT_64))) = {0};
static uint8_t xCanSrvTaskQueueBuffer[XCANSRV_TASK_QUEUE_BUFFER_SIZE] __attribute__((aligned(MEM_ALIGNMENT_4))) = {0};
CAN_DATA static TaskHandle_t xCanSrvTaskHandle = NULL;
CAN_DATA static QueueHandle_t xCanSrvTaskQueueHandle = NULL;   
StaticQueue_t xCanSrvQueueBuffer;

//Can Client Ctxt
#define XCAN_CLIENT_HANDLE_PREFIX 	   0xFFFF0000
#define XCAN_MAX_CLIENT_CNT            16

CAN_DATA static xCan_ClientCtxt xCanClient[XCAN_MAX_CLIENT_CNT] = { 0 };
 

/*=========================================================================================================
**                                          FUNCTION DEFINITIONS                                         **
=========================================================================================================*/
/*******************************************************************************************************************************/

static EventBits_t xCanSrv_Get_CmdType_Eventbits(xCan_MsgType MsgType)
{
	EventBits_t eventBits = 0;
	
	switch (MsgType)
	{
		case XCAN_MSG_TYPE_SET_BAUD_RATE:
		{
			eventBits = XCAN_EVENT_BIT_SET_BAUD_RATE_E_OK|XCAN_EVENT_BIT_SET_BAUD_RATE_E_NOT_OK;
		}
		break;
		case XCAN_MSG_TYPE_SET_CNTLR_MODE:
		{
			eventBits = XCAN_EVENT_BIT_SET_CNTLR_MODE_E_OK|XCAN_EVENT_BIT_SET_CNTLR_MODE_E_NOT_OK;
		}
		break;
		case XCAN_MSG_TYPE_GET_CNTLR_MODE:
		{
			eventBits = XCAN_EVENT_BIT_GET_CNTLR_MODE_E_OK | XCAN_EVENT_BIT_GET_CNTLR_MODE_E_NOT_OK |
	            XCAN_EVENT_BIT_GET_CNTLR_STATE_UNINIT| XCAN_EVENT_BIT_GET_CNTLR_STATE_STARTED|
				XCAN_EVENT_BIT_GET_CNTLR_STATE_STOPPED| XCAN_EVENT_BIT_GET_CNTLR_STATE_SLEEP;
		}
		break;
		case XCAN_MSG_TYPE_GET_CNTLR_ERR_STATE:
		{
			eventBits = XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_E_OK | XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_E_NOT_OK |
	            XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_ACTIVE| XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_PASSIVE|
				XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_BUS_OFF;
		}
		break;
		case XCAN_MSG_TYPE_WRITE:
		{
			eventBits = XCAN_EVENT_BIT_WRITE_E_OK|XCAN_EVENT_BIT_WRITE_E_NOT_OK|XCAN_EVENT_BIT_WRITE_E_BUSY;
		}
		break;
		case XCAN_MSG_TYPE_CUR_TIME:
		{
			eventBits = XCAN_EVENT_BIT_GET_CUR_TIME_E_OK|XCAN_EVENT_BIT_GET_CUR_TIME_E_NOT_OK;
		}
		break;
		case XCAN_MSG_TYPE_REG_CALLBACK:
		break;
		case XCAN_MSG_TYPE_TX_CNF:
		break;
		case XCAN_MSG_TYPE_RX_CNF:
		break;
		case XCAN_MSG_TYPE_NTFY_CNTLR_MODE:
		break;
		case XCAN_MSG_TYPE_PROTO_ERR:
		break;
	    case XCAN_MSG_TYPE_ERR_STATE_PASSIVE:
		break;
		case XCAN_MSG_TYPE_ERR_STATE_BUS_OFF:
		break;
	// case XCAN_MSG_TYPE_FUSA_ERR:
	// break;
		case XCAN_MSG_TYPE_TCAN1146_WAKEUP:
		break;
		case XCAN_MSG_TYPE_TCAN1044_WAKEUP:	
		break;
        case XCAN_MSG_TYPE_SET_TRCV_MODE:
		{
			eventBits = XCAN_EVENT_BIT_SET_TRCV_MODE_E_OK|XCAN_EVENT_BIT_SET_TRCV_MODE_E_NOT_OK;
		}
		break;
		default:
		break;
	}
	
	return eventBits;
}

static BaseType_t xCanTask_QueueCmd(xCan_QueueMsgType xCanMsg)
{
	BaseType_t xQSendStatus = pdFAIL;

    
	xQSendStatus = xFreeRTOSQueueSend(xCanTaskQueueHandle, &xCanMsg, 0);
	
	if(pdPASS != xQSendStatus)
	{ 
		DEBUG_LOG( SAIL_ERROR, "%s  xQSendStatus: %ld for MsgType: %d \r\n", __func__, xQSendStatus, xCanMsg.MsgType );
	}
	return xQSendStatus;
}

static void xCanTask_QueueCmd_FromISR(xCan_QueueMsgType xCanMsg)
{
	BaseType_t xQSendStatus = pdFAIL;
	
    
	xQSendStatus = xFreeRTOSQueueSendFromISR(xCanTaskQueueHandle, &xCanMsg);
	
	if(pdPASS != xQSendStatus)
	{ 
		DEBUG_LOG( SAIL_ERROR, "%s failed xQSendStatus: %ld for MsgType: %d \r\n", __func__, xQSendStatus, xCanMsg.MsgType );
	}	

	freertosYIELD_FROM_ISR();
	
	return;
}

static BaseType_t xCanTrcvTask_QueueCmd(xCan_QueueMsgType xCanMsg)
{
	BaseType_t xQSendStatus = pdFAIL;
	
	xQSendStatus = xFreeRTOSQueueSend(xCanTrcvTaskQueueHandle, &xCanMsg, 0);
	
	if(pdPASS != xQSendStatus)
	{ 
		DEBUG_LOG( SAIL_ERROR, "%s FAIL xQSendStatus: %d for MsgType: %d \r\n", __func__, xQSendStatus, xCanMsg.MsgType );
	}	
	DEBUG_LOG( SAIL_DEBUG, "%s Success xQSendStatus : %d for MsgType:%d \r\n", __func__, xQSendStatus, xCanMsg.MsgType );
	return xQSendStatus;
}

static BaseType_t xCanSrvTask_QueueCmd(xCan_QueueMsgType xCanMsg)
{
	BaseType_t xQSendStatus = pdFAIL;
    
    
	xQSendStatus = xFreeRTOSQueueSend(xCanSrvTaskQueueHandle, &xCanMsg, 0);
	
	if(pdPASS != xQSendStatus)
	{ 
		DEBUG_LOG( SAIL_ERROR, "%s xFreeRTOSQueueSend failed %ld for cmd: %d \r\n", __func__, xQSendStatus, xCanMsg.MsgType );
	}	
	return xQSendStatus;
}

static void xCanSrvTask_QueueCmd_FromISR(xCan_QueueMsgType xCanMsg)
{
	BaseType_t xQSendStatus = pdFAIL;
	
    
	xQSendStatus = xFreeRTOSQueueSendFromISR(xCanSrvTaskQueueHandle, &xCanMsg);
	
	if(pdPASS != xQSendStatus)
	{ 
		DEBUG_LOG(SAIL_ERROR, "%s xFreeRTOSQueueSendFromISR failed %ld for cmd: %d \r\n", __func__, xQSendStatus, xCanMsg.MsgType);
	}	
	
	freertosYIELD_FROM_ISR();
	
	return;
}


static BaseType_t xCanSrv_QueueCmd_WaitEvent(xCan_QueueMsgType xCanMsg, EventBits_t *event)
{
	EventBits_t BitsToWaitFor = 0;
	BaseType_t xReturn = pdFAIL;
	EventBits_t eventBitsSet = 0x0;
	EventGroupHandle_t xEventGroupHandle = NULL;
			
    
	BitsToWaitFor |= xCanSrv_Get_CmdType_Eventbits(xCanMsg.MsgType);
	
	if(xCanMsg.MsgType == XCAN_MSG_TYPE_WRITE)
	{
		xEventGroupHandle = xCanWriteEventGroupHandle[xCanMsg.MsgInfo.PduInfo.TxPdu.Hth];
	}
	else
	{
		xEventGroupHandle = xCanCtrlEventGroupHandle[xCanMsg.CanCtrlID];
	}
	
	xReturn = xFreeRTOSEventGroupWaitBits(xEventGroupHandle, BitsToWaitFor, pdFALSE, pdFALSE , 						
								&eventBitsSet, freertosMAX_DELAY );	
	
	if(pdPASS == xReturn)
	{
		*event = eventBitsSet;
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR,"%s:  xFreeRTOSEventGroupWaitBits failed xReturn = %ld for xCan_MsgType: %d\r\n", __func__, xReturn, xCanMsg.MsgType);
	}						
								
	return xReturn;
}


static BaseType_t xCanSrv_QueueCmd_WaitEvent_Clr(xCan_QueueMsgType xCanMsg)
{
	EventBits_t BitsToClear =  0;
	BaseType_t xReturn = pdFAIL;
	EventGroupHandle_t xEventGroupHandle = NULL;
		
	BitsToClear |= xCanSrv_Get_CmdType_Eventbits(xCanMsg.MsgType);
	
	if(xCanMsg.MsgType == XCAN_MSG_TYPE_WRITE)
	{
		xEventGroupHandle = xCanWriteEventGroupHandle[xCanMsg.MsgInfo.PduInfo.TxPdu.Hth];
	}
	else
	{
		xEventGroupHandle = xCanCtrlEventGroupHandle[xCanMsg.CanCtrlID];
	}
	
	xReturn = xFreeRTOSEventGroupClearBits(xEventGroupHandle, BitsToClear );
	
	if(pdPASS != xReturn)
	{
		DEBUG_LOG(SAIL_ERROR,"%s:  xFreeRTOSEventGroupClearBits failed xReturn = %ld for cmd: %d\r\n", __func__, xReturn, xCanMsg.MsgType);
	}
								
	return xReturn;
}

//--------------API wrapper functions

Std_ReturnType xCanSrv_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID)
{
	Std_ReturnType Status = E_NOT_OK;

	if (mutex_try_lock(&xCanCtrlLock[ControllerId]) != 0u)
	{
		xCan_QueueMsgType xCanMsg = { 0 };
		BaseType_t QueueCmdStatus = pdFAIL;
		
		xCanMsg.CanCtrlID = ControllerId;
		xCanMsg.MsgType = XCAN_MSG_TYPE_SET_BAUD_RATE;
		xCanMsg.MsgInfo.CfgInfo.BaudRateConfigID = BaudRateConfigID;
	
		QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
		if(pdPASS == QueueCmdStatus)
		{ 
			EventBits_t eventBitsSet = 0x0;
			BaseType_t xReturn = pdFAIL;
	
			xReturn = xCanSrv_QueueCmd_WaitEvent(xCanMsg, &eventBitsSet);
			
			if(pdPASS == xReturn )
			{
				if(pdPASS == xCanSrv_QueueCmd_WaitEvent_Clr(xCanMsg))
				{
					if(eventBitsSet == XCAN_EVENT_BIT_SET_BAUD_RATE_E_OK)
						Status = E_OK;
				}
			}
		}

		mutex_unlock(&xCanCtrlLock[ControllerId]);
	}
	
	return Status;
}

Std_ReturnType xCanSrv_SetControllerMode(uint8 ControllerId,  Can_ControllerStateType Transition)
{
	Std_ReturnType Status = E_NOT_OK;
	Std_ReturnType SetCtrlStatus = E_NOT_OK;
    
	if (mutex_try_lock(&xCanCtrlLock[ControllerId]) != 0u)
	{	
		xCan_QueueMsgType xCanMsg = { 0 };
		xCan_QueueMsgType xCanTrcvMsg = { 0 };
		BaseType_t QueueCmdStatus = pdFAIL;

		xCanMsg.CanCtrlID = ControllerId;
		xCanMsg.MsgType = XCAN_MSG_TYPE_SET_CNTLR_MODE;
		xCanMsg.MsgInfo.CfgInfo.State = Transition;

		QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
		if(pdPASS == QueueCmdStatus)
		{ 
			EventBits_t eventBitsSet = 0x0;
			BaseType_t xReturn = pdFAIL;
	
			xReturn = xCanSrv_QueueCmd_WaitEvent(xCanMsg, &eventBitsSet);
			
			if(pdPASS == xReturn )
			{
				if(pdPASS == xCanSrv_QueueCmd_WaitEvent_Clr(xCanMsg))
				{
					if(eventBitsSet == XCAN_EVENT_BIT_SET_CNTLR_MODE_E_OK)
						SetCtrlStatus = E_OK;
				}
			}
		}

        if (SetCtrlStatus == E_OK)
        {
    		xCanMsg.MsgType = XCAN_MSG_TYPE_SET_TRCV_MODE;
            
    		QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
    	
    		if(pdPASS == QueueCmdStatus)
    		{ 
    			EventBits_t eventBitsSet = 0x0;
    			BaseType_t xReturn = pdFAIL;
    	
    			xReturn = xCanSrv_QueueCmd_WaitEvent(xCanMsg, &eventBitsSet);
    			
    			if(pdPASS == xReturn )
    			{
    				if(pdPASS == xCanSrv_QueueCmd_WaitEvent_Clr(xCanTrcvMsg))
    				{
    					if(eventBitsSet == XCAN_EVENT_BIT_SET_CNTLR_MODE_E_OK)
    						Status = E_OK;
    				}
    			}
    		}
        }
		mutex_unlock(&xCanCtrlLock[ControllerId]);
	}
	return Status;
}


Std_ReturnType xCanSrv_GetControllerMode(uint8 ControllerId, Can_ControllerStateType* ControllerModePtr)
{
	Std_ReturnType Status = E_NOT_OK;

	if (mutex_try_lock(&xCanCtrlLock[ControllerId]) != 0u)
	{	
		xCan_QueueMsgType xCanMsg = { 0 };
		BaseType_t QueueCmdStatus = pdFAIL;
		
		xCanMsg.CanCtrlID = ControllerId;
		xCanMsg.MsgType = XCAN_MSG_TYPE_GET_CNTLR_MODE;
		
		QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
		if(pdPASS == QueueCmdStatus)
		{ 
			EventBits_t eventBitsSet = 0x0;
			BaseType_t xReturn = pdFAIL;
	
			xReturn = xCanSrv_QueueCmd_WaitEvent(xCanMsg, &eventBitsSet);
			
			if(pdPASS == xReturn )
			{
				if(pdPASS == xCanSrv_QueueCmd_WaitEvent_Clr(xCanMsg))
				{
					if(eventBitsSet&XCAN_EVENT_BIT_GET_CNTLR_MODE_E_OK)
					{			
						Status = E_OK;
						
						if (eventBitsSet&XCAN_EVENT_BIT_GET_CNTLR_STATE_UNINIT)
						{
							*ControllerModePtr = CAN_CS_UNINIT;
						}
						else if (eventBitsSet&XCAN_EVENT_BIT_GET_CNTLR_STATE_STARTED)
						{
							*ControllerModePtr = CAN_CS_STARTED;
						}
						else if (eventBitsSet&XCAN_EVENT_BIT_GET_CNTLR_STATE_STOPPED)
						{
							*ControllerModePtr = CAN_CS_STOPPED;
						}
						else if (eventBitsSet&XCAN_EVENT_BIT_GET_CNTLR_STATE_SLEEP)
						{
							*ControllerModePtr = CAN_CS_SLEEP;
						}
						else
						{
						}
					}
				}					
			}
		}
		
		mutex_unlock(&xCanCtrlLock[ControllerId]);
	}
	return Status;
}



Std_ReturnType xCanSrv_GetControllerErrorState(uint8 ControllerId, Can_ErrorStateType* ErrorStatePtr)
{
	Std_ReturnType Status = E_NOT_OK;
	
	if (mutex_try_lock(&xCanCtrlLock[ControllerId]) != 0u)
	{
		xCan_QueueMsgType xCanMsg = { 0 };
		BaseType_t QueueCmdStatus = pdFAIL;
	
		xCanMsg.CanCtrlID = ControllerId;
		xCanMsg.MsgType = XCAN_MSG_TYPE_GET_CNTLR_ERR_STATE;
		
		QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
		if(pdPASS == QueueCmdStatus)
		{ 
			EventBits_t eventBitsSet = 0x0;
			BaseType_t xReturn = pdFAIL;
	
			xReturn = xCanSrv_QueueCmd_WaitEvent(xCanMsg, &eventBitsSet);
			
			if(pdPASS == xReturn )
			{
				if(pdPASS == xCanSrv_QueueCmd_WaitEvent_Clr(xCanMsg))
				{
					if(eventBitsSet&XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_E_OK)
					{	
						Status = E_OK;
						
						if (eventBitsSet&XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_BUS_OFF)
						{
							*ErrorStatePtr = CAN_ERRORSTATE_BUSOFF;
						}
						else if (eventBitsSet&XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_PASSIVE)
						{
							*ErrorStatePtr = CAN_ERRORSTATE_PASSIVE;
						}
						else if (eventBitsSet&XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_ACTIVE)
						{
							*ErrorStatePtr = CAN_ERRORSTATE_ACTIVE;
						}
						else
						{
							
						}	
					}
					else
					{
					}
				}
				else
				{
				}
			}
			else
			{
			}
		}
	
		mutex_unlock(&xCanCtrlLock[ControllerId]);
	}
	
	return Status;
}

Std_ReturnType xCanSrv_GetCurrentTime(uint8 ControllerId)
{
	Std_ReturnType Status = E_NOT_OK;

	if (mutex_try_lock(&xCanCtrlLock[ControllerId]) != 0u)
	{
		xCan_QueueMsgType xCanMsg = { 0 };
		BaseType_t QueueCmdStatus = pdFAIL;
		
		xCanMsg.CanCtrlID = ControllerId;
		xCanMsg.MsgType = XCAN_MSG_TYPE_CUR_TIME;
		
		QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
		if(pdPASS == QueueCmdStatus)
		{ 
			EventBits_t eventBitsSet = 0x0;
			BaseType_t xReturn = pdFAIL;
	
			xReturn = xCanSrv_QueueCmd_WaitEvent(xCanMsg, &eventBitsSet);
			
			if(pdPASS == xReturn )
			{
				if(pdPASS == xCanSrv_QueueCmd_WaitEvent_Clr(xCanMsg))
				{
					if((eventBitsSet) & (XCAN_EVENT_BIT_GET_CUR_TIME_E_OK))
						Status = E_OK;
				}
				else
				{
				}
			}
			else
			{
			}
		}
		else
		{
		}

		mutex_unlock(&xCanCtrlLock[ControllerId]);
	}
	
	return Status;
}

Std_ReturnType xCanSrv_Write( Can_HwHandleType Hth, const Can_PduType* PduInfo)
{
	Std_ReturnType Status = E_NOT_OK;
	
	if (mutex_try_lock(&xCanWriteLock[Hth]) != 0u)
	{	

		xCan_QueueMsgType xCanMsg = { 0 };
		BaseType_t QueueCmdStatus = pdFAIL;
        uint8 *p = PduInfo->sdu;
		
		xCanMsg.MsgType = XCAN_MSG_TYPE_WRITE;
		xCanMsg.MsgInfo.PduInfo.TxPdu.Hth = Hth;
		xCanMsg.MsgInfo.PduInfo.TxPdu.swPduHandle = PduInfo->swPduHandle;
        xCanMsg.MsgInfo.PduInfo.TxPdu.id = PduInfo->id;
        xCanMsg.MsgInfo.PduInfo.TxPdu.DataLength = PduInfo->length;
        for (uint8 i=0; i<PduInfo->length; i++)
        {
            xCanMsg.MsgInfo.PduInfo.TxPdu.Data[i] = *p;
            p++;
        }

		QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
		if(pdPASS == QueueCmdStatus)
		{ 
			EventBits_t eventBitsSet = 0x0;
			BaseType_t xReturn = pdFAIL;
		
			xReturn = xCanSrv_QueueCmd_WaitEvent(xCanMsg, &eventBitsSet);
			
			if(pdPASS == xReturn )
			{
				if(pdPASS == xCanSrv_QueueCmd_WaitEvent_Clr(xCanMsg))
				{
					if((eventBitsSet) & (XCAN_EVENT_BIT_WRITE_E_OK))
					{
						Status = E_OK;
					}
					else
					{
					}
				}
				else
				{
				}
			}
			else
			{
				
			}
		}
		
		mutex_unlock(&xCanWriteLock[Hth]);
	}
	else
	{
		Status = CAN_BUSY;
	}

	return Status;
}

/*************************************************************************************************/

static void xCanSrv_Add_Client_Ctxt(xCan_QueueMsgType xCanMsg)
{
	uint8 i = 0;
	uint32 handle = 0;
	Std_ReturnType Status = E_NOT_OK;
	xCan_ClientCtxt ClientCtxt = xCanMsg.MsgInfo.CfgInfo.ClientCtxt;
	Can_HwHandleType HwObjCnt = xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.HwObjCnt;
    
	for(i=0 ; i < XCAN_MAX_CLIENT_CNT; i++)
	{
		if(xCanClient[i].Handle == 0)
		{
			xCanClient[i].Handle = ( XCAN_CLIENT_HANDLE_PREFIX | ( 1 << i) );
			handle = xCanClient[i].Handle;

			xCanClient[i].ClientInfo.xCanSrv_Cb_Reg_Client = ClientCtxt.ClientInfo.xCanSrv_Cb_Reg_Client;
			xCanClient[i].ClientInfo.xCanSrv_Cb_Dereg_Client = ClientCtxt.ClientInfo.xCanSrv_Cb_Dereg_Client;
			xCanClient[i].ClientInfo.xCanSrv_Cb_TxConfirmation = ClientCtxt.ClientInfo.xCanSrv_Cb_TxConfirmation;
			xCanClient[i].ClientInfo.xCanSrv_Cb_RxIndication = ClientCtxt.ClientInfo.xCanSrv_Cb_RxIndication;
			xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerBusOff = ClientCtxt.ClientInfo.xCanSrv_Cb_ControllerBusOff;
			xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerMode = ClientCtxt.ClientInfo.xCanSrv_Cb_ControllerMode;
			xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerErrorStatePassive = ClientCtxt.ClientInfo.xCanSrv_Cb_ControllerErrorStatePassive;
			xCanClient[i].ClientInfo.xCanSrv_Cb_ErrorNotification = ClientCtxt.ClientInfo.xCanSrv_Cb_ErrorNotification;
			xCanClient[i].ClientInfo.xCanSrv_Cb_GetCurrentTimeStamp = ClientCtxt.ClientInfo.xCanSrv_Cb_GetCurrentTimeStamp;
			// xCanClient[i].ClientInfo.xCanSrv_Cb_ReportFusaError = ClientCtxt.ClientInfo.xCanSrv_Cb_ReportFusaError;
			xCanClient[i].ClientInfo.xCanSrv_Cb_184_Tcan1044_WakeupIndication = ClientCtxt.ClientInfo.xCanSrv_Cb_184_Tcan1044_WakeupIndication;
			xCanClient[i].ClientInfo.xCanSrv_Cb_184_Tcan1146_WakeupIndication = ClientCtxt.ClientInfo.xCanSrv_Cb_184_Tcan1146_WakeupIndication;

            /* subscribe Hw Object ID for the client */
            xCanClient[i].ClientInfo.HwObjCnt = HwObjCnt;
            for(uint8 j = 0; j < HwObjCnt; j++)
        	{
        		xCanClient[i].ClientInfo.HwObjId[j] = xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.HwObjId[j];
                DEBUG_LOG( SAIL_INFO, "%s: set xCanClient[%d].ClientInfo.HwObjId[%d] = %d \r\n",  __func__, i, j, xCanClient[i].ClientInfo.HwObjId[j]);
        	}
    
			Status = E_OK;
			break;
		}
			
	}
	
	if(ClientCtxt.ClientInfo.xCanSrv_Cb_Reg_Client != NULL)
	{
		DEBUG_LOG( SAIL_INFO, "%s: ClientHandle[0x%x] Status:%d \r\n",  __func__, handle, Status);
		ClientCtxt.ClientInfo.xCanSrv_Cb_Reg_Client(handle, Status);
	}
				
	return;
}

static void  xCanSrv_Remove_Client_Ctxt(xCan_QueueMsgType xCanMsg)
{
	uint8 i = 0;
	uint32 handle = xCanMsg.MsgInfo.CfgInfo.ClientCtxt.Handle;
	
	for (i = 0; i < XCAN_MAX_CLIENT_CNT; i++)
	{
		if(xCanClient[i].Handle == handle)
		{
			xCanClient[i].Handle = 0;

			xCanClient[i].ClientInfo.xCanSrv_Cb_Reg_Client = NULL;
			xCanClient[i].ClientInfo.xCanSrv_Cb_TxConfirmation = NULL;
			xCanClient[i].ClientInfo.xCanSrv_Cb_RxIndication = NULL;	
			xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerBusOff = NULL;
			xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerMode  = NULL;
			xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerErrorStatePassive = NULL;
			xCanClient[i].ClientInfo.xCanSrv_Cb_ErrorNotification = NULL;
			xCanClient[i].ClientInfo.xCanSrv_Cb_GetCurrentTimeStamp = NULL;
			// xCanClient[i].ClientInfo.xCanSrv_Cb_ReportFusaError = NULL;
			xCanClient[i].ClientInfo.xCanSrv_Cb_184_Tcan1044_WakeupIndication = NULL;
			xCanClient[i].ClientInfo.xCanSrv_Cb_184_Tcan1146_WakeupIndication = NULL;
			
			if(xCanClient[i].ClientInfo.xCanSrv_Cb_Dereg_Client != NULL)
			{
				xCanClient[i].ClientInfo.xCanSrv_Cb_Dereg_Client(handle, E_OK);
				xCanClient[i].ClientInfo.xCanSrv_Cb_Dereg_Client = NULL;
			}
            
            xCanClient[i].ClientInfo.HwObjCnt = 0;
            for(uint8 j = 0; j < MAX_HW_OBJ_CNT; j++)
        	{
        		xCanClient[i].ClientInfo.HwObjId[j] = 0;
        	}
			break;
		}
	}
	
	return;
}



Std_ReturnType xCanSrv_Deregister_Client(uint32 ClientHandle)
{
	Std_ReturnType Status = E_NOT_OK;
	
	xCan_QueueMsgType xCanMsg = { 0 };
	BaseType_t QueueCmdStatus = pdFAIL;
		
	xCanMsg.MsgType = XCAN_MSG_TYPE_DEREG_CLIENT;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.Handle = ClientHandle;

	QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
	if(pdPASS == QueueCmdStatus)
	{
		Status = E_OK;	
	}
	
	return Status;
}


Std_ReturnType xCanSrv_Register_Client(xCan_ClientCtxt_Type ClientCtxt)
{
	Std_ReturnType Status = E_NOT_OK;
	
	xCan_QueueMsgType xCanMsg = { 0 };
	BaseType_t QueueCmdStatus = pdFAIL;
	Can_HwHandleType i = 0;
	Can_HwHandleType HwObjCnt = ClientCtxt.HwObjCnt;
		
	xCanMsg.MsgType = XCAN_MSG_TYPE_REG_CLIENT;
	
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_Reg_Client = ClientCtxt.xCanSrv_Cb_Reg_Client;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_Dereg_Client = ClientCtxt.xCanSrv_Cb_Dereg_Client;		
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_TxConfirmation = ClientCtxt.xCanSrv_Cb_TxConfirmation;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_RxIndication = ClientCtxt.xCanSrv_Cb_RxIndication;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_ControllerBusOff = ClientCtxt.xCanSrv_Cb_ControllerBusOff;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_ControllerMode = ClientCtxt.xCanSrv_Cb_ControllerMode;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_ControllerErrorStatePassive = ClientCtxt.xCanSrv_Cb_ControllerErrorStatePassive;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_ErrorNotification = ClientCtxt.xCanSrv_Cb_ErrorNotification;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_GetCurrentTimeStamp = ClientCtxt.xCanSrv_Cb_GetCurrentTimeStamp;
	// xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_ReportFusaError = ClientCtxt.xCanSrv_Cb_ReportFusaError;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_184_Tcan1044_WakeupIndication = ClientCtxt.xCanSrv_Cb_184_Tcan1044_WakeupIndication;
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.xCanSrv_Cb_184_Tcan1146_WakeupIndication = ClientCtxt.xCanSrv_Cb_184_Tcan1146_WakeupIndication;

    /* subscribe Hw Obj for the client */
	xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.HwObjCnt = HwObjCnt;
	for(i=0; i < HwObjCnt; i++)
	{
		xCanMsg.MsgInfo.CfgInfo.ClientCtxt.ClientInfo.HwObjId[i] = ClientCtxt.HwObjId[i];
	}
	
	QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
	if(pdPASS == QueueCmdStatus)
	{
		Status = E_OK;	
	}
	
	return Status;
}

static bool xCanSrv_IsRegistered(uint8 ClientId, Can_HwHandleType HwObjId)
{
    bool retval = FALSE;
    Can_HwHandleType Client_HwObjCnt = xCanClient[ClientId].ClientInfo.HwObjCnt;
    for (uint8 i=0; i< Client_HwObjCnt; i++)
    {
        if(xCanClient[ClientId].ClientInfo.HwObjId[i] == HwObjId)
        {
            retval = TRUE;
            break;
        }
    }
    return retval;
}
/*******************************Main Functions **********************************/
Std_ReturnType xCanSrv_Can_MainFunction_Read(void)
{
	Std_ReturnType Status = E_NOT_OK;
	
	xCan_QueueMsgType xCanMsg = { 0 };
	BaseType_t QueueCmdStatus = pdFAIL;
		
	xCanMsg.MsgType = XCAN_MSG_TYPE_CAN_MAINFUNCTION_READ;

	QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
	if(pdPASS == QueueCmdStatus)
	{
		Status = E_OK;	
	}
	
	return Status;
}

Std_ReturnType xCanSrv_Can_MainFunction_Write(void)
{
	Std_ReturnType Status = E_NOT_OK;
	
	xCan_QueueMsgType xCanMsg = { 0 };
	BaseType_t QueueCmdStatus = pdFAIL;
		
	xCanMsg.MsgType = XCAN_MSG_TYPE_CAN_MAINFUNCTION_WRITE;

	QueueCmdStatus = xCanSrvTask_QueueCmd(xCanMsg);
	
	if(pdPASS == QueueCmdStatus)
	{
		Status = E_OK;	
	}
	
	return Status;
}


static void xCanSrv_InvokeClientCallbacks(xCan_QueueMsgType xCanMsg)
{
	uint8 i = 0;
	for (i = 0; i < XCAN_MAX_CLIENT_CNT; i++)
	{			
		switch(xCanMsg.MsgType)
		{
				case XCAN_MSG_TYPE_TX_CNF:
				{
					 if (xCanClient[i].ClientInfo.xCanSrv_Cb_TxConfirmation != NULL) 
					 {
                         if (xCanSrv_IsRegistered(i,xCanMsg.MsgInfo.PduInfo.TxPdu.Hth) == TRUE)
                         {
						     xCanClient[i].ClientInfo.xCanSrv_Cb_TxConfirmation(xCanMsg.MsgInfo.PduInfo.TxPdu.swPduHandle,
                                    xCanMsg.MsgInfo.PduInfo.TxPdu.Hth,xCanMsg.MsgInfo.PduInfo.TxPdu.TimeStamp);				
                         }
                     }
				}
				break;
				case XCAN_MSG_TYPE_RX_CNF:
				{
					if (xCanClient[i].ClientInfo.xCanSrv_Cb_RxIndication != NULL) 
					{
					if (xCanSrv_IsRegistered(i,xCanMsg.MsgInfo.PduInfo.RxPdu.MailBox.Hoh) == TRUE)
						xCanClient[i].ClientInfo.xCanSrv_Cb_RxIndication(&xCanMsg.MsgInfo.PduInfo.RxPdu.MailBox, 
									xCanMsg.MsgInfo.PduInfo.RxPdu.Data, xCanMsg.MsgInfo.PduInfo.RxPdu.DataLength,
									xCanMsg.MsgInfo.PduInfo.RxPdu.TimeStamp);
                    }
				}
				break;
				case XCAN_MSG_TYPE_NTFY_CNTLR_MODE:
				{
					if (xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerMode != NULL) 
					{
						xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerMode(xCanMsg.CanCtrlID, xCanMsg.MsgInfo.CfgInfo.State);
                    }
				}
				break;
				case XCAN_MSG_TYPE_PROTO_ERR:
				{	
					if (xCanClient[i].ClientInfo.xCanSrv_Cb_ErrorNotification != NULL) 
					{
						xCanClient[i].ClientInfo.xCanSrv_Cb_ErrorNotification(xCanMsg.CanCtrlID, xCanMsg.MsgInfo.ErrInfo.ErrType);
                    }
				}
				break;
				case XCAN_MSG_TYPE_ERR_STATE_PASSIVE:
				{
					if (xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerErrorStatePassive != NULL)
					{
						xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerErrorStatePassive(xCanMsg.CanCtrlID, 
												xCanMsg.MsgInfo.ErrInfo.RxErrCnt, xCanMsg.MsgInfo.ErrInfo.TxErrCnt);
                    }
				}
				break;
				case XCAN_MSG_TYPE_ERR_STATE_BUS_OFF:
				{
					if (xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerBusOff != NULL)
					{
						xCanClient[i].ClientInfo.xCanSrv_Cb_ControllerBusOff(xCanMsg.CanCtrlID);
                    }
				}
				break;	
			// case XCAN_MSG_TYPE_FUSA_ERR:
			// {
			// 	if (xCanClient[i].ClientInfo.xCanSrv_Cb_ReportFusaError != NULL)
			// 	{
			// 		xCanClient[i].ClientInfo.xCanSrv_Cb_ReportFusaError(xCanMsg.CanCtrlID, xCanMsg.MsgInfo.ErrInfo.Fusa);
			// 	}
			// }
			// 	break;
				case XCAN_MSG_TYPE_TCAN1146_WAKEUP:
				{
					if (xCanClient[i].ClientInfo.xCanSrv_Cb_184_Tcan1146_WakeupIndication != NULL)
					{
						xCanClient[i].ClientInfo.xCanSrv_Cb_184_Tcan1146_WakeupIndication(xCanMsg.CanTrcvId, xCanMsg.CanCtrlID);
                    }
				}
				break;
				case XCAN_MSG_TYPE_TCAN1044_WAKEUP:
				{
					if (xCanClient[i].ClientInfo.xCanSrv_Cb_184_Tcan1044_WakeupIndication != NULL)
					{
						xCanClient[i].ClientInfo.xCanSrv_Cb_184_Tcan1044_WakeupIndication(xCanMsg.CanTrcvId, xCanMsg.CanCtrlID);
                    }
				}
				break;
				case XCAN_MSG_TYPE_CUR_TIME_STATUS:
				{
					if (xCanClient[i].ClientInfo.xCanSrv_Cb_GetCurrentTimeStamp != NULL)
					{
						xCanClient[i].ClientInfo.xCanSrv_Cb_GetCurrentTimeStamp(xCanMsg.CanCtrlID, xCanMsg.MsgInfo.CfgInfo.CurrTimeStamp);
                    }	
				}
				break;
				default:
				break;
		}
	}
}



//-----------------Notify Functions



void xCanSrv_Notify_TxConfirmation(uint8 ControllerId, PduIdType CanTxPduId, Can_TimeStampType timeStamp, Can_HwHandleType HwObjId)
{
	xCan_QueueMsgType xCanMsg = { 0 };
	
	xCanMsg.MsgType = XCAN_MSG_TYPE_TX_CNF;
	xCanMsg.MsgInfo.PduInfo.TxPdu.swPduHandle = CanTxPduId;
	xCanMsg.MsgInfo.PduInfo.TxPdu.TimeStamp = timeStamp;
    xCanMsg.MsgInfo.PduInfo.TxPdu.Hth = HwObjId;
	xCanMsg.CanCtrlID = ControllerId;
	xCanTask_QueueCmd(xCanMsg);

	return;
}

void xCanSrv_Notify_TxIsrConfirmation(uint8 ControllerId, PduIdType CanTxPduId, Can_TimeStampType timeStamp, Can_HwHandleType HwObjId)
{
	xCan_QueueMsgType xCanMsg = { 0 };
	
	xCanMsg.MsgType = XCAN_MSG_TYPE_TX_CNF;
	xCanMsg.MsgInfo.PduInfo.TxPdu.swPduHandle = CanTxPduId;
	xCanMsg.MsgInfo.PduInfo.TxPdu.TimeStamp = timeStamp;
    xCanMsg.MsgInfo.PduInfo.TxPdu.Hth = HwObjId;
	xCanMsg.CanCtrlID = ControllerId;
	xCanTask_QueueCmd_FromISR(xCanMsg);
		
	return;
}

void xCanSrv_Notify_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr, Can_TimeStampType timeStamp)
{
	xCan_QueueMsgType xCanMsg = { 0 };
		
	xCanMsg.MsgType = XCAN_MSG_TYPE_RX_CNF;
	xCanMsg.MsgInfo.PduInfo.RxPdu.MailBox = *Mailbox;
	xCanMsg.MsgInfo.PduInfo.RxPdu.DataLength = PduInfoPtr->SduLength;
	xCanMsg.MsgInfo.PduInfo.RxPdu.TimeStamp = timeStamp;
	xCanMsg.CanCtrlID = xCanMsg.MsgInfo.PduInfo.RxPdu.MailBox.ControllerId;
	
	for(uint8 i=0;i<PduInfoPtr->SduLength;i++)
	{
		xCanMsg.MsgInfo.PduInfo.RxPdu.Data[i] = PduInfoPtr->SduDataPtr[i];
	}	
	xCanTask_QueueCmd(xCanMsg);
	
	return;
}

void xCanSrv_Notify_RxIsrIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr, Can_TimeStampType timeStamp)
{
	xCan_QueueMsgType xCanMsg = { 0 };
		
	xCanMsg.MsgType = XCAN_MSG_TYPE_RX_CNF;
	xCanMsg.MsgInfo.PduInfo.RxPdu.MailBox = *Mailbox;
	xCanMsg.MsgInfo.PduInfo.RxPdu.DataLength = PduInfoPtr->SduLength;
	xCanMsg.MsgInfo.PduInfo.RxPdu.TimeStamp = timeStamp;
	xCanMsg.CanCtrlID = xCanMsg.MsgInfo.PduInfo.RxPdu.MailBox.ControllerId;
	
	for(uint8 i=0;i<PduInfoPtr->SduLength;i++)
	{
		xCanMsg.MsgInfo.PduInfo.RxPdu.Data[i] = PduInfoPtr->SduDataPtr[i];
	}
		
	xCanTask_QueueCmd_FromISR(xCanMsg);
	
	return;
}
	
void xCanSrv_Notify_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode)
{
	xCan_QueueMsgType xCanMsg = { 0 };
	
	xCanMsg.MsgType = XCAN_MSG_TYPE_NTFY_CNTLR_MODE;
	xCanMsg.CanCtrlID = ControllerId;
	xCanMsg.MsgInfo.CfgInfo.State = ControllerMode;
	
	DEBUG_LOG( SAIL_DEBUG, "%s: MsgType=%d CanCtrlID=%d State=%d\r\n",  __func__, 
							xCanMsg.MsgType, xCanMsg.CanCtrlID, xCanMsg.MsgInfo.CfgInfo.State);
	xCanTask_QueueCmd(xCanMsg);
	
	return;
}

void xCanSrv_Notify_ControllerModeIsrIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode)
{
	xCan_QueueMsgType xCanMsg = { 0 };

	xCanMsg.MsgType = XCAN_MSG_TYPE_NTFY_CNTLR_MODE;
	xCanMsg.CanCtrlID = ControllerId;
	xCanMsg.MsgInfo.CfgInfo.State = ControllerMode;
	xCanTask_QueueCmd_FromISR(xCanMsg);

	return;
}

void xCanSrv_Notify_ControllerBusOff(uint8 ControllerId)
{
	xCan_QueueMsgType xCanMsg = { 0 };
	
	xCanMsg.MsgType = XCAN_MSG_TYPE_ERR_STATE_BUS_OFF;
	xCanMsg.CanCtrlID = ControllerId;
	xCanTask_QueueCmd_FromISR(xCanMsg);
	
	return;
}

void xCanSrv_Notify_ControllerErrorStatePassive(uint8 ControllerId, uint16 RxErrorCounter, uint16 TxErrorCounter)
{
	xCan_QueueMsgType xCanMsg = { 0 };
	
	xCanMsg.MsgType = XCAN_MSG_TYPE_ERR_STATE_PASSIVE;
	xCanMsg.CanCtrlID = ControllerId;
	xCanMsg.MsgInfo.ErrInfo.TxErrCnt = TxErrorCounter;
	xCanMsg.MsgInfo.ErrInfo.RxErrCnt = RxErrorCounter;
		
	xCanTask_QueueCmd_FromISR(xCanMsg);
	return;
}

void xCanSrv_Notify_ErrorNotification(uint8 ControllerId, Can_ErrorType Can_ErrorType)
{
	xCan_QueueMsgType xCanMsg = { 0 };
	
	xCanMsg.MsgType = XCAN_MSG_TYPE_PROTO_ERR;
	xCanMsg.CanCtrlID = ControllerId;
	xCanMsg.MsgInfo.ErrInfo.ErrType = Can_ErrorType;	
	xCanSrvTask_QueueCmd_FromISR(xCanMsg);

	return;
}

// void xCanSrv_Notify_ReportFusaError(uint8 ControllerId, FUSAQueueMsgType CanFUSAMsg)
// {
// 	xCan_QueueMsgType xCanMsg = { 0 };
	
// 	xCanMsg.MsgType = XCAN_MSG_TYPE_FUSA_ERR;
// 	xCanMsg.CanCtrlID = ControllerId;
// 	xCanMsg.MsgInfo.ErrInfo.Fusa = CanFUSAMsg;
		
// 	xCanSrvTask_QueueCmd_FromISR(xCanMsg);
	
// 	return;
// }


void xCanSrv_Notify_Tcan1044_WakeupIndication(uint8 CanTrcvId, uint8 ControllerId)
{
	xCan_QueueMsgType xCanMsg = { 0 };
	
	xCanMsg.MsgType = XCAN_MSG_TYPE_TCAN1044_WAKEUP;
	xCanMsg.CanCtrlID = ControllerId;
	xCanMsg.CanTrcvId = CanTrcvId;
		
	xCanTask_QueueCmd_FromISR(xCanMsg);
	return;
}

void xCanSrv_Notify_Tcan1146_WakeupIndication(uint8 CanTrcvId, uint8 ControllerId)
{
	xCan_QueueMsgType xCanMsg = { 0 };
	
	xCanMsg.MsgType = XCAN_MSG_TYPE_TCAN1146_WAKEUP;
	xCanMsg.CanCtrlID = ControllerId;
	xCanMsg.CanTrcvId = CanTrcvId;
		
	xCanTask_QueueCmd_FromISR(xCanMsg);
	return;

}

static Std_ReturnType xCanTrcv_SetOpMode(uint8 ControllerId, uint8 Transition)
{
    Std_ReturnType Status = E_NOT_OK;
    CAN_TRCV_MAP_Type  trcv_type = CAN_NO_TRCV;
    uint8 trcv_channel = 0xff;
    CanTrcv_TrcvModeType trcv_mode = CANTRCV_TRCVMODE_NORMAL;
    CanTrcv_TrcvModeType OpMode = CANTRCV_TRCVMODE_NORMAL;
    
    Can_Safertos_Get_TransceiverId_For_Can(ControllerId, &trcv_type, &trcv_channel);

	if(trcv_type ==  CAN_NO_TRCV)
	{
		Status = E_OK;
	}
    else 
	{
	    /* get op mode */
	    if (Transition == CAN_CS_STARTED) {
            trcv_mode = CANTRCV_TRCVMODE_NORMAL;
        }
        else if (Transition == CAN_CS_SLEEP) {
            trcv_mode = CANTRCV_TRCVMODE_SLEEP;
        }
        else if (Transition == CAN_CS_STOPPED) {
            trcv_mode = CANTRCV_TRCVMODE_STANDBY;
        }

        /* set and read back OpMode*/
		if (trcv_type == CAN_TCAN1044_MAPPED) 
		{
			if( E_OK == CanTrcv_184_Tcan1044_SetOpMode(trcv_channel, trcv_mode))
			{
				Status = CanTrcv_184_Tcan1044_GetOpMode(trcv_channel,&OpMode);
			}
		}
		else 
		{
			 if( E_OK == CanTrcv_184_Tcan1146_SetOpMode(trcv_channel, trcv_mode))
			 {
				Status = CanTrcv_184_Tcan1146_GetOpMode(trcv_channel,&OpMode);
			 }
		}

        if (Status == E_OK)
        {
            if(trcv_mode != OpMode)
            {
                DEBUG_LOG(SAIL_ERROR, "%s: GetOpMode %d, Expect %d \r\n", __func__, OpMode, trcv_mode);
                Status = E_NOT_OK;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "%s: SetOpMode %d success, trcv type = %d, channel = %d \r\n",
                                        __func__, OpMode, trcv_type, trcv_channel);
            }
        }
    }
    return Status;
}
//----------------------------------Task 

void xCanTask(void *pvParameters)
{
	(void)pvParameters;
    xCan_QueueMsgType xCanMsg = { 0 };
    BaseType_t xReturn = pdFAIL;	
	
    for(;;)
    {    
		xReturn = xFreeRTOSQueueReceive( xCanTaskQueueHandle, &xCanMsg, pdMS_TO_TICKS(freertosMAX_DELAY));

        if ( pdPASS == xReturn )
        {
			switch(xCanMsg.MsgType)
            {	
				case XCAN_MSG_TYPE_SET_BAUD_RATE:
				{
					Std_ReturnType Status = E_NOT_OK;
					
					Status = Can_SetBaudrate(xCanMsg.CanCtrlID, xCanMsg.MsgInfo.CfgInfo.BaudRateConfigID);
					
					if(Status == E_OK)
					{
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_SET_BAUD_RATE_E_OK;
					}
					else
					{
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_SET_BAUD_RATE_E_NOT_OK;
					}
					
					xCanMsg.MsgType = XCAN_MSG_TYPE_SET_BAUD_RATE_STATUS;		
					if( pdFALSE ==  xCanSrvTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}					
				}
				break;
				case XCAN_MSG_TYPE_SET_CNTLR_MODE:
				{
					Std_ReturnType Status = E_NOT_OK;
					Can_ControllerStateType state = CAN_CS_UNINIT;
	
					Status = Can_SetControllerMode(xCanMsg.CanCtrlID,  xCanMsg.MsgInfo.CfgInfo.State);
					
					if(Status == E_NOT_OK)
					{	
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_SET_CNTLR_MODE_E_NOT_OK;
					}
					else
					{	
						Can_MainFunction_Mode();
						Status = Can_GetControllerMode(xCanMsg.CanCtrlID,&state);

                        if(state == xCanMsg.MsgInfo.CfgInfo.State)
						{					
							xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_SET_CNTLR_MODE_E_OK;
						} else {
                            xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_SET_CNTLR_MODE_E_NOT_OK;
                        }
					}		

					xCanMsg.MsgType = XCAN_MSG_TYPE_SET_CNTLR_MODE_STATUS;
					if( pdFALSE ==  xCanSrvTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}
					
				}
				break;
				case XCAN_MSG_TYPE_GET_CNTLR_MODE:
				{
					Std_ReturnType Status = E_NOT_OK;
					Can_ControllerStateType state = CAN_CS_UNINIT;
										
					Status = Can_GetControllerMode(xCanMsg.CanCtrlID,&state);
									
					if(Status == E_NOT_OK)
					{					
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_GET_CNTLR_MODE_E_NOT_OK;
					}
					else
					{
						xCanMsg.MsgTypeStatus =  XCAN_EVENT_BIT_GET_CNTLR_MODE_E_OK;
						
						switch(state)
						{
							case CAN_CS_UNINIT:
							{
								xCanMsg.MsgTypeStatus |=  XCAN_EVENT_BIT_GET_CNTLR_STATE_UNINIT;
							}
							break;
							case CAN_CS_STARTED:
							{
								xCanMsg.MsgTypeStatus |=  XCAN_EVENT_BIT_GET_CNTLR_STATE_STARTED;
							}
							break;
							case CAN_CS_STOPPED:
							{
								xCanMsg.MsgTypeStatus |=  XCAN_EVENT_BIT_GET_CNTLR_STATE_STOPPED;
							}
							break;
							case CAN_CS_SLEEP:
							{
								xCanMsg.MsgTypeStatus |=  XCAN_EVENT_BIT_GET_CNTLR_STATE_SLEEP;
							}
							break;
							
						}
					}
					xCanMsg.MsgType = XCAN_MSG_TYPE_GET_CNTLR_MODE_STATUS;
					if( pdFALSE ==  xCanSrvTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}					
				}
				break;
				case XCAN_MSG_TYPE_GET_CNTLR_ERR_STATE:
				{
					Std_ReturnType Status = E_NOT_OK;
					Can_ErrorStateType ErrorState = CAN_ERRORSTATE_ACTIVE;
							
					Status = Can_GetControllerErrorState(xCanMsg.CanCtrlID, &ErrorState);
					
					if(Status == E_NOT_OK)
					{
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_E_NOT_OK;
					}
					else
					{
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_E_OK;
						
						if(ErrorState == CAN_ERRORSTATE_BUSOFF)
						{
							xCanMsg.MsgTypeStatus |=  XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_BUS_OFF;
						}
						else if(ErrorState == CAN_ERRORSTATE_PASSIVE)
						{
							xCanMsg.MsgTypeStatus |=  XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_PASSIVE;
						}
						else
						{
							xCanMsg.MsgTypeStatus |=  XCAN_EVENT_BIT_GET_CNTLR_ERR_STATE_ACTIVE;
						}
					}	
					xCanMsg.MsgType = XCAN_MSG_TYPE_GET_CNTLR_ERR_STATE_STATUS;					
					if( pdFALSE ==  xCanSrvTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}	
				}
				break;
				case XCAN_MSG_TYPE_WRITE:
				{
					Std_ReturnType Status = E_NOT_OK;
					
                    Can_PduType write_pdu = {   xCanMsg.MsgInfo.PduInfo.TxPdu.swPduHandle,
                                                xCanMsg.MsgInfo.PduInfo.TxPdu.DataLength,
                                                xCanMsg.MsgInfo.PduInfo.TxPdu.id,
                                                (uint8 *)&xCanMsg.MsgInfo.PduInfo.TxPdu.Data};
                    
                    Status = Can_Write( xCanMsg.MsgInfo.PduInfo.TxPdu.Hth, &write_pdu);

					if(Status == E_NOT_OK)
					{
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_WRITE_E_NOT_OK;
					}
					else
					{
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_WRITE_E_OK;
					}
					
					xCanMsg.MsgType = XCAN_MSG_TYPE_WRITE_STATUS;	
					if( pdFALSE ==  xCanSrvTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}
				}
				break;
				case XCAN_MSG_TYPE_CUR_TIME:
				{
					Std_ReturnType Status = E_NOT_OK;
					Can_TimeStampType timeStamp = {0};
					
					Status = Can_GetCurrentTime (xCanMsg.CanCtrlID, &timeStamp);
					
					if(Status == E_NOT_OK)
					{
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_GET_CUR_TIME_E_NOT_OK;
					}
					else
					{
						xCanMsg.MsgInfo.CfgInfo.CurrTimeStamp = timeStamp;
						xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_GET_CUR_TIME_E_OK;
					}
					xCanMsg.MsgType = XCAN_MSG_TYPE_CUR_TIME_STATUS;															
					if( pdFALSE ==  xCanSrvTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}
				}
				break;
				case XCAN_MSG_TYPE_TX_CNF:
				case XCAN_MSG_TYPE_RX_CNF:
				case XCAN_MSG_TYPE_NTFY_CNTLR_MODE:
				case XCAN_MSG_TYPE_PROTO_ERR:
				case XCAN_MSG_TYPE_ERR_STATE_PASSIVE:
				case XCAN_MSG_TYPE_ERR_STATE_BUS_OFF:
				case XCAN_MSG_TYPE_FUSA_ERR:
				case XCAN_MSG_TYPE_TCAN1146_WAKEUP:
				case XCAN_MSG_TYPE_TCAN1044_WAKEUP:
				{
					if( pdFALSE ==  xCanSrvTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}
				}
				break;
				case XCAN_MSG_TYPE_CAN_MAINFUNCTION_READ:
				{
					Can_MainFunction_Read();
				}
				break;
				case XCAN_MSG_TYPE_CAN_MAINFUNCTION_WRITE:
				{
					Can_MainFunction_Write();
				}
				break;
				default:
				break;
			}
		}
	}	
	return;
}



/*========================================================================================================
 @Service name        xCanTask_SleepCallback
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           eState -> SLEEP_ENTRY = arg from sleep driver to Deinit CAN Driver
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
 static void xCanTask_SleepCallback(const sleepStatesType_e eState)
{
 	BaseType_t ret;
			DEBUG_LOG(SAIL_ERROR, "##### xCanTask_SleepCallback\n\r");
	if (SLEEP_ENTRY == eState)
	{
		/* Deinitialize the CAN driver here */
		Can_DeInit();
		CanTrcv_184_Tcan1044_DeInit();
		CanTrcv_184_Tcan1146_DeInit();

		if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(xCanTaskSleepHandle, DRIVER_SLEEP,get_curr_phys_cpu_num()))
		{
			vTaskSuspend(xCanTaskHandle);
			vTaskSuspend(xCanTrcvTaskHandle);//vTaskSuspend
			vTaskSuspend(xCanSrvTaskHandle);
		}
		else
		{
			DEBUG_LOG(SAIL_ERROR, "%s: xSleepDriverAck Failed\n\r", __func__);
		}
	}
}

BaseType_t xCanTaskQueueInit(CPUIdType_e xSchdCore)
{
    BaseType_t xQSendStatus = pdFAIL;
	
	xQSendStatus = xFreeRTOSQueueCreate(xCanTaskQueueBuffer, XCAN_TASK_QUEUE_LENGTH,
										XCAN_TASK_QUEUE_ITEM_SIZE, &xCanTaskQueueHandle,&xCanQueueBuffer);
	if(xQSendStatus == pdFAIL)
	{
		DEBUG_LOG( SAIL_ERROR, "%s : Queue Init FAILED = %ld \r\n", __func__, xQSendStatus);
	}

    return xQSendStatus;
}



/*===========================================================================
**  Function :  xCANTaskInit
** ==========================================================================
*/
/*!
*
* @brief
*   CAN SafeRTOS Task Init function for primary core
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
BaseType_t xCanTaskInit( CPUIdType_e           xSchdCore,
                              UBaseType_t  xTaskPrior )
{
    BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;

	DEBUG_LOG( SAIL_ERROR, "***%s*******\r\n",  __func__);
    TaskParams_t xInitTaskParameters =
    {
			.pvTaskCode = xCanTask,				  /* The function that implements the task being created. */
			.pcName = "xCanTask",				  /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
			.pxTaskBuffer = &xCanTaskTCB,		  /* The buffer allocated for use as the task TCB. */
			.puxStackBuffer = xCanTaskStack,	  /* The buffer allocated for use as the task stack. */
			.usStackDepth = XCAN_TASK_STACK_SIZE, /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
			.pvParameters = NULL,				  /* The task parameter, not used in this case. */
			.uxPriority = (xTaskPrior),
			.xRegions = {				   /* The MPU task parameters. */
						 {NULL, 0UL, 0UL}, /* No additional region definitions are required. */
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL}}};

    //Can_Plt_Cfg_Init();

	uxCoreAffinityMask = (1 << xSchdCore);
	/* Create the check task. */
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters, uxCoreAffinityMask, &xCanTaskHandle);
	if(xResult != pdPASS)
	{
		DEBUG_LOG( SAIL_ERROR, "%s : xCanTask creation failed = %ld \r\n",  __func__, xResult);
	}
	else 
    {	
		uint8 i = 0;
		
		for(i = 0; i < CAN_MTTCAN_MAX_CNT; i++)
		{
			xResult = xFreeRTOSEventGroupCreate(&xCanCtrlEventGroup[i],&xCanCtrlEventGroupHandle[i]);
	
			if( pdPASS != xResult )
			{
				DEBUG_LOG( SAIL_ERROR, "%s: xCanCtrlEventGroup failed for controller: %d xResult:%ld\n\r", __func__, i, xResult);
				break;
			}
            (void)mutex_init(&xCanCtrlLock[i]);
		}
		
		if ( pdPASS == xResult)
		{
			uint8 j = 0;
			
			for (j = 0; j < CAN_MAX_HOH_CONFIGURED; j++ )
			{
				xResult = xFreeRTOSEventGroupCreate(&xCanWriteEventGroup[j],&xCanWriteEventGroupHandle[j]);
		
				if( pdPASS != xResult )
				{
					DEBUG_LOG( SAIL_ERROR, "%s: xCanWriteEventGroup failed for controller: %d xResult:%ld\n\r", __func__, j, xResult);
					break;
				}
                (void)mutex_init(&xCanWriteLock[j]);
			}			
			
			if(	xResult == pdPASS )
			{
				 if (xCanTaskSleepHandle == 0u)
				 {
				 	if (SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1((Sleep_ClientNotificationCallbackFn)&xCanTask_SleepCallback, &xCanTaskSleepHandle,xSchdCore))
				 	{
				 		DEBUG_LOG(SAIL_ERROR, "%s: xSleepRegisterCallBack failed \n\r", __func__);
				 	}
				 	else
				 	{
				 		DEBUG_LOG(SAIL_ERROR, "%s: xSleepRegisterCallBack Reg success\n\r", __func__);
				 	}
				 }
			 }
		}

    }
	DEBUG_LOG(SAIL_ERROR,"%s <-- xResult=%ld\n\r", __func__, xResult);
    return xResult;
}


void xCanTrcvTask(void *pvParameters)
{
	(void)pvParameters;
    xCan_QueueMsgType xCanMsg = { 0 };
    BaseType_t xReturn = pdFAIL;	
	
    for(;;)
    {    
		xReturn = xFreeRTOSQueueReceive( xCanTrcvTaskQueueHandle, &xCanMsg, 
								pdMS_TO_TICKS(freertosMAX_DELAY));
		
        if ( pdPASS == xReturn )
        {
			switch(xCanMsg.MsgType)
            {	
				case XCAN_MSG_TYPE_SET_TRCV_MODE:
				{
                    if (E_OK == xCanTrcv_SetOpMode(xCanMsg.CanCtrlID, xCanMsg.MsgInfo.CfgInfo.State))
                    {
                        xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_SET_TRCV_MODE_E_OK;
                    }
                    else
                    {

                        xCanMsg.MsgTypeStatus = XCAN_EVENT_BIT_SET_TRCV_MODE_E_NOT_OK;
                    }

					xCanMsg.MsgType = XCAN_MSG_TYPE_SET_TRCV_MODE_STATUS;
					if( pdFALSE ==  xCanSrvTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}
				}
				break;
				
				default:
				break;
			}
        }
	}
}


BaseType_t xCanTrcvTaskQueueInit(CPUIdType_e xSchdCore)
{   
	BaseType_t xQSendStatus = pdFAIL;
		
	xQSendStatus = xFreeRTOSQueueCreate(xCanTrcvTaskQueueBuffer, XCANTRCV_TASK_QUEUE_LENGTH,
													XCANTRCV_TASK_QUEUE_ITEM_SIZE,&xCanTrcvTaskQueueHandle,&xCanTrcvQueueBuffer);
	if(xQSendStatus == pdFAIL)
	{
		DEBUG_LOG( SAIL_ERROR, "%s : Queue Init FAILED = %ld \r\n", __func__, xQSendStatus);
	}
    return xQSendStatus;	
}



/*===========================================================================
**  Function :  xCanTrcvTaskInit
** ==========================================================================
*/
/*!
*
* @brief
*   CAN Trcv SafeRTOS Task Init function for primary core
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
BaseType_t xCanTrcvTaskInit( CPUIdType_e           xSchdCore,
                              UBaseType_t  xTaskPrior )
{
    BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;

	DEBUG_LOG( SAIL_ERROR, "***%s*******\r\n",  __func__);
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
			.pvTaskCode = xCanTrcvTask,						/* The function that implements the task being created. */
			.pcName = "xCanTrcvTask",						/* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
			.pxTaskBuffer = &xCanTrcvTaskTCB,				/* The buffer allocated for use as the task TCB. */
			.puxStackBuffer = xCanTrcvTaskStack,			/* The buffer allocated for use as the task stack. */
			.usStackDepth = XCANTRCV_TASK_STACK_SIZE,		/* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
			.pvParameters = NULL,							/* The task parameter, not used in this case. */
			.uxPriority = (xTaskPrior), /* The priority assigned to the task being created. */
			.xRegions = {				   /* The MPU task parameters. */
						 {NULL, 0UL, 0UL}, /* No additional region definitions are required. */
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL}}};
	// CanTcrv1146_Plt_Cfg_Init();
	//CanTcrv1044_Plt_Cfg_Init();
	uxCoreAffinityMask = (1 << xSchdCore);
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters, uxCoreAffinityMask, &xCanTrcvTaskHandle);
	if(xResult != pdPASS)
	{
		DEBUG_LOG( SAIL_ERROR, "%s : xCanTrcvTask creation failed = %ld \r\n",  __func__, xResult);
	}
	else 
    {
    }
	DEBUG_LOG(SAIL_ERROR,"%s <-- xResult=%ld\n\r", __func__, xResult);
    return xResult;
}

void xCanSrvTask(void *pvParameters)
{
	(void)pvParameters;
    xCan_QueueMsgType xCanMsg = { 0 };
    BaseType_t xReturn = pdFAIL;	
	
    for(;;)
    {    
		xReturn = xFreeRTOSQueueReceive( xCanSrvTaskQueueHandle, &xCanMsg, 
								pdMS_TO_TICKS(freertosMAX_DELAY));
		
        if ( pdPASS == xReturn )
        {
			switch(xCanMsg.MsgType)
            {	
				case XCAN_MSG_TYPE_SET_BAUD_RATE:
				case XCAN_MSG_TYPE_SET_CNTLR_MODE:
				case XCAN_MSG_TYPE_GET_CNTLR_MODE:
				case XCAN_MSG_TYPE_GET_CNTLR_ERR_STATE:
				case XCAN_MSG_TYPE_WRITE:
				case XCAN_MSG_TYPE_CUR_TIME:
				case XCAN_MSG_TYPE_CAN_MAINFUNCTION_READ:
				case XCAN_MSG_TYPE_CAN_MAINFUNCTION_WRITE:
				{
					if( pdFALSE ==  xCanTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}
				
				}
				break;
				case XCAN_MSG_TYPE_REG_CLIENT:
				{					
					xCanSrv_Add_Client_Ctxt(xCanMsg);
				}
				break;
				case XCAN_MSG_TYPE_DEREG_CLIENT:
				{			
					xCanSrv_Remove_Client_Ctxt(xCanMsg);
				}
				break;
				case XCAN_MSG_TYPE_SET_BAUD_RATE_STATUS:
				case XCAN_MSG_TYPE_SET_CNTLR_MODE_STATUS:
				case XCAN_MSG_TYPE_GET_CNTLR_MODE_STATUS:
				case XCAN_MSG_TYPE_GET_CNTLR_ERR_STATE_STATUS:
                case XCAN_MSG_TYPE_SET_TRCV_MODE_STATUS:
				{
					EventBits_t eventBit = (EventBits_t)xCanMsg.MsgTypeStatus;															
					
					DEBUG_LOG(SAIL_DEBUG,"%s: Status for MsgType: %d command \r\n", __func__, xCanMsg.MsgType);
					xReturn = xFreeRTOSEventGroupSetBits ( xCanCtrlEventGroupHandle[xCanMsg.CanCtrlID], eventBit );		
									
					if(xReturn != pdPASS)
					{
						DEBUG_LOG(SAIL_ERROR,"%s: xFreeRTOSEventGroupSetBits failed for Msg %d xReturn =%ld\r\n", __func__, xCanMsg.MsgType, xReturn);
					}
				}
				break;				
				case XCAN_MSG_TYPE_CUR_TIME_STATUS:
				{
					EventBits_t eventBit = (EventBits_t)xCanMsg.MsgTypeStatus;
					
					if(pdFALSE == xFreeRTOSEventGroupSetBits( xCanCtrlEventGroupHandle[xCanMsg.CanCtrlID], eventBit ))
					{
						DEBUG_LOG(SAIL_ERROR,"%s: xFreeRTOSEventGroupSetBits failed for XCAN_MSG_TYPE_WRITE : MsgType status = %d \r\n", __func__,xCanMsg.MsgTypeStatus);
					}
					else
					{
						if (xCanMsg.MsgTypeStatus == XCAN_EVENT_BIT_GET_CUR_TIME_E_OK)
						{
							xCanSrv_InvokeClientCallbacks(xCanMsg);
						}
					}
				}
				break;
				case XCAN_MSG_TYPE_WRITE_STATUS:
				{
					EventBits_t eventBit = (EventBits_t)xCanMsg.MsgTypeStatus;
					
					if(pdFALSE == xFreeRTOSEventGroupSetBits ( xCanWriteEventGroupHandle[xCanMsg.MsgInfo.PduInfo.TxPdu.Hth], eventBit ))
					{
						DEBUG_LOG(SAIL_ERROR,"%s : %d\r\n",__func__, __LINE__);
					}
				
				}
				break;
				case XCAN_MSG_TYPE_TX_CNF:
				case XCAN_MSG_TYPE_RX_CNF:
				case XCAN_MSG_TYPE_NTFY_CNTLR_MODE:
				case XCAN_MSG_TYPE_PROTO_ERR:
				case XCAN_MSG_TYPE_ERR_STATE_PASSIVE:
				case XCAN_MSG_TYPE_ERR_STATE_BUS_OFF:
			 // case XCAN_MSG_TYPE_FUSA_ERR:
				{
					xCanSrv_InvokeClientCallbacks(xCanMsg);
				}
				break;
				case XCAN_MSG_TYPE_TCAN1146_WAKEUP:
				{
					xCanSrv_InvokeClientCallbacks(xCanMsg);
				}
				break;
				case XCAN_MSG_TYPE_TCAN1044_WAKEUP:
				{
					xCanSrv_InvokeClientCallbacks(xCanMsg);
				}
				break;
			    case XCAN_MSG_TYPE_SET_TRCV_MODE:
				{
					if( pdFALSE ==  xCanTrcvTask_QueueCmd(xCanMsg))
					{
						DEBUG_LOG(SAIL_ERROR,"%s:  failed for MsgType: %d \r\n", __func__, xCanMsg.MsgType);
					}
				
				}
				break;
				default:
				break;
			}
				
		}
	}

}


BaseType_t xCanSrvTaskQueueInit(CPUIdType_e xSchdCore)
{   
	BaseType_t xQSendStatus = pdFAIL;
		
	xQSendStatus = xFreeRTOSQueueCreate(xCanSrvTaskQueueBuffer, XCANSRV_TASK_QUEUE_LENGTH,
													XCANSRV_TASK_QUEUE_ITEM_SIZE,&xCanSrvTaskQueueHandle,&xCanSrvQueueBuffer);
	if(xQSendStatus == pdFAIL)
	{
		DEBUG_LOG( SAIL_ERROR, "%s : Queue Init FAILED = %ld \r\n", __func__, xQSendStatus);
	}
    return xQSendStatus;	
}



/*===========================================================================
**  Function :  xCANNewTaskInit
** ==========================================================================
*/
/*!
*
* @brief
*   CAN SafeRTOS Task Init function for primary core
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
BaseType_t xCanSrvTaskInit( CPUIdType_e           xSchdCore,
                              UBaseType_t  xTaskPrior )
{
    BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;

	DEBUG_LOG( SAIL_ERROR, "***%s*******\r\n",  __func__);
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
			.pvTaskCode = xCanSrvTask,						/* The function that implements the task being created. */
			.pcName = "xCanSrvTask",						/* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
			.pxTaskBuffer = &xCanSrvTaskTCB,				/* The buffer allocated for use as the task TCB. */
			.puxStackBuffer = xCanSrvTaskStack,				/* The buffer allocated for use as the task stack. */
			.usStackDepth = XCANSRV_TASK_STACK_SIZE,		/* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
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
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters, uxCoreAffinityMask, &xCanSrvTaskHandle); //use affinity 
	if(xResult != pdPASS)
	{
		DEBUG_LOG( SAIL_ERROR, "%s : xCanTask creation failed = %ld \r\n",  __func__, xResult);
	}
	DEBUG_LOG(SAIL_ERROR,"%s <-- xResult=%ld\n\r", __func__, xResult);
    return xResult;
}
