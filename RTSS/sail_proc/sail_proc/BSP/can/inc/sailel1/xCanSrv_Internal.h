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
#ifndef XCAN_INTERNAL_H
#define XCAN_INTERNAL_H
#ifdef __cplusplus
extern "C"{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
#include "Can_GeneralTypes.h"
//#include "fusa.h"


void xCanSrv_Notify_TxConfirmation(uint8 ControllerId, PduIdType CanTxPduId, Can_TimeStampType timeStamp, Can_HwHandleType HwObjId);
void xCanSrv_Notify_TxIsrConfirmation(uint8 ControllerId, PduIdType CanTxPduId, Can_TimeStampType timeStamp, Can_HwHandleType HwObjId);
void xCanSrv_Notify_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr, Can_TimeStampType timeStamp);
void xCanSrv_Notify_RxIsrIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr, Can_TimeStampType timeStamp);
void xCanSrv_Notify_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode);
void xCanSrv_Notify_ControllerModeIsrIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode);
void xCanSrv_Notify_ControllerBusOff(uint8 ControllerId);
void xCanSrv_Notify_ControllerErrorStatePassive(uint8 ControllerId, uint16 RxErrorCounter, uint16 TxErrorCounter);
void xCanSrv_Notify_ErrorNotification(uint8 ControllerId, Can_ErrorType Can_ErrorType);
//void xCanSrv_Notify_ReportFusaError(uint8 ControllerId, FUSAQueueMsgType CanFUSAMsg);
void xCanSrv_Notify_Tcan1044_WakeupIndication(uint8 CanIfTrcvid, uint8 controller_id);
void xCanSrv_Notify_Tcan1146_WakeupIndication(uint8 CanTrcvId, uint8 ControllerId);

#ifdef __cplusplus
}
#endif
#endif /* XCAN_INTERNAL_H*/
/*==============================================================================
==============================================================================*/
