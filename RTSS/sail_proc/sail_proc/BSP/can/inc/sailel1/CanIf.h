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
#ifndef CAN_IF_H
#define CAN_IF_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Can_GeneralTypes.h"
#include "Std_Types.h"
//#include "fusa.h"

typedef enum
{
    CANIF_CTXT_TYPE_NON_ISR = 0u,
	CANIF_CTXT_TYPE_ISR,
}CanIf_ContextType;

void CanIf_TxConfirmation(uint8 ControllerId, PduIdType CanTxPduId, Can_TimeStampType timeStamp, Can_HwHandleType HwObjId,  CanIf_ContextType CtxtType);
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr, Can_TimeStampType timeStamp,  CanIf_ContextType CtxtType);
void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode, CanIf_ContextType CtxtType);
void CanIf_ControllerBusOff(uint8 ControllerId);
void CanIf_ControllerErrorStatePassive(uint8 ControllerId, uint16 RxErrorCounter, uint16 TxErrorCounter);
void CanIf_ErrorNotification(uint8 ControllerId, Can_ErrorType Can_ErrorType);
//void CanIf_ReportFusaError(uint8 ControllerId, FUSAQueueMsgType CanFUSAMsg);

#ifdef __cplusplus
}
#endif

#endif

