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
#ifdef __cplusplus
extern "C"{
#endif

#include "CanIf.h"
#include "Can_SafeRTOS.h"
#include "xCanSrv_Internal.h"

void CanIf_TxConfirmation(uint8 ControllerId, PduIdType CanTxPduId, Can_TimeStampType timeStamp, Can_HwHandleType HwObjId, CanIf_ContextType CtxtType)
{
	if( CtxtType == CANIF_CTXT_TYPE_ISR)
    {
        xCanSrv_Notify_TxIsrConfirmation(ControllerId, CanTxPduId, timeStamp, HwObjId);
    }
    else
    {
        xCanSrv_Notify_TxConfirmation(ControllerId, CanTxPduId, timeStamp, HwObjId);
    }
}

void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr, Can_TimeStampType timeStamp, CanIf_ContextType CtxtType)
{
	if( CtxtType == CANIF_CTXT_TYPE_ISR)
    {
         xCanSrv_Notify_RxIsrIndication(Mailbox, PduInfoPtr, timeStamp);
    }
    else
    {
         xCanSrv_Notify_RxIndication(Mailbox, PduInfoPtr, timeStamp);
    }
}

void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode, CanIf_ContextType CtxtType)
{
	if( CtxtType == CANIF_CTXT_TYPE_ISR)
	{
		xCanSrv_Notify_ControllerModeIsrIndication(ControllerId, ControllerMode);
	}
	else
	{
		xCanSrv_Notify_ControllerModeIndication(ControllerId, ControllerMode);
	}
}

void CanIf_ControllerBusOff(uint8 ControllerId)
{    
    xCanSrv_Notify_ControllerBusOff(ControllerId);
}

void CanIf_ControllerErrorStatePassive(uint8 ControllerId, uint16 RxErrorCounter, uint16 TxErrorCounter)
{
    xCanSrv_Notify_ControllerErrorStatePassive(ControllerId, RxErrorCounter, TxErrorCounter);
}

void CanIf_ErrorNotification(uint8 ControllerId, Can_ErrorType Can_ErrorType)
{
    xCanSrv_Notify_ErrorNotification(ControllerId, Can_ErrorType);
}

// void CanIf_ReportFusaError(uint8 ControllerId, FUSAQueueMsgType CanFUSAMsg)
// {
//     xCanSrv_Notify_ReportFusaError(ControllerId, CanFUSAMsg);
// }

#ifdef __cplusplus
}
#endif

