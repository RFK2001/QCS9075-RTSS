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
    File Name.............. : Can_Irq.h
    Description............ : This file contains declarations of ISR interfaces of CAN Driver
    Platform............... :
    SW Release Version..... :
==============================================================================*/
/*==============================================================================
|                       MISRA-C VIOLATIONS                                     |
==============================================================================*/
/*
*/
#ifndef XCAN_H
#define XCAN_H
#ifdef __cplusplus
extern "C"{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
#include "Can_GeneralTypes.h"
#include "Std_Types.h"
//#include "fusa.h"

#define MAX_HW_OBJ_CNT  	40

typedef struct
{
	void (*xCanSrv_Cb_Reg_Client)(uint32 xCanClientHandle, Std_ReturnType Status);
	void (*xCanSrv_Cb_Dereg_Client)(uint32 xCanClientHandle, Std_ReturnType Status);
    void (*xCanSrv_Cb_TxConfirmation)(PduIdType swPduHandle, Can_HwHandleType Hth, Can_TimeStampType timeStamp);
    void (*xCanSrv_Cb_RxIndication)(const Can_HwType* Mailbox, uint8 *Data, PduLengthType DataLength, Can_TimeStampType timeStamp);
    void (*xCanSrv_Cb_ControllerBusOff)(uint8 Controller);
	void (*xCanSrv_Cb_ControllerMode)(uint8 Controller, Can_ControllerStateType ControllerMode);
    void (*xCanSrv_Cb_ControllerErrorStatePassive)(uint8 Controller, uint16 RxErrorCounter, uint16 TxErrorCounter);
    void (*xCanSrv_Cb_ErrorNotification) (uint8 Controller, Can_ErrorType Can_ErrorType);
	void (*xCanSrv_Cb_GetCurrentTimeStamp) (uint8 Controller, Can_TimeStampType timeStampPtr);
 // void (*xCanSrv_Cb_ReportFusaError) (uint8 Controller, FUSAQueueMsgType CanFUSAMsg);
    void (*xCanSrv_Cb_184_Tcan1044_WakeupIndication)(uint8 CanTrcvid, uint8 controller_id);
    void (*xCanSrv_Cb_184_Tcan1146_WakeupIndication)(uint8 CanTrcvid, uint8 controller_id);
	
	Can_HwHandleType  HwObjId[MAX_HW_OBJ_CNT];
	Can_HwHandleType  HwObjCnt;
}xCan_ClientCtxt_Type;

Std_ReturnType xCanSrv_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID);
Std_ReturnType xCanSrv_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition);
Std_ReturnType xCanSrv_GetControllerMode(uint8 Controller, Can_ControllerStateType *ControllerModePtr);
Std_ReturnType xCanSrv_GetControllerErrorState(uint8 Controller, Can_ErrorStateType *ErrorStatePtr);
Std_ReturnType xCanSrv_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo);
Std_ReturnType xCanSrv_GetCurrentTime(uint8 Controller);

Std_ReturnType xCanSrv_Register_Client(xCan_ClientCtxt_Type ClientCtxt);
Std_ReturnType xCanSrv_Deregister_Client(uint32 ClientHandle);
Std_ReturnType xCanSrv_Can_MainFunction_Read(void);
Std_ReturnType xCanSrv_Can_MainFunction_Write(void);

#ifdef __cplusplus
}
#endif
#endif /* XCAN_INTERNAL_H*/
/*==============================================================================
==============================================================================*/
