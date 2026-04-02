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
/*=============================================================================
  File Name.............. : CanTrcv_184_Tcan1146_Internal.h
  Description............ : Header file of CanTrcv_184_TCAN1146_Internal.c
  Autosar Release Version : R22-11
  Platform............... :
  SW Release Version..... :

  =============================================================================*/

/*=============================================================================
  |                       REVISION HISTORY                                      |
  ===============================================================================
  | Revision  Date            Changed By        Description                     |
  ===============================================================================

  =============================================================================*/
#ifndef CANTRCV_184_TCAN1146_INTERNAL_H
#define CANTRCV_184_TCAN1146_INTERNAL_H

/*=============================================================================
  |                       INCLUDE FILES                                         |
  =============================================================================*/
#include "CanTrcv_184_Tcan1146.h"
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"

typedef enum
{
    CANTRCV_E_OK,
    CANTRCV_E_NOT_OK,
    CANTRCV_E_CFG_FAILURE,
    CANTRCV_E_PNCFG_FAILURE
}
CanTrcv_ReturnType;

/*=============================================================================
  |                       Function Declarations                                 |
  =============================================================================*/

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvSPIInit(uint8 transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvSetPnEnable(uint8 transceiver, boolean PNEnable);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvInterruptDis(uint8 transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvInterruptClr(uint8 transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvInit(uint8 transceiver,
        CanTrcv_TrcvModeType opMode,
        boolean* PNCfgWritten);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvSetOpMode(uint8 transceiver,
        CanTrcv_TrcvModeType opMode);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvSetModeReg(uint8 transceiver,
        CanTrcv_TrcvModeType opMode);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvGetTrcvStatusBits(uint8 transceiver,
        uint8* statusBits);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvCheckBusErrFlag(uint8 transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* FlagState);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
void Tcan1146DrvReportStatus(const CanTrcv_Tcan1146ChConfigType *channelPtr, uint8 statusBits);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"


#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvClearBusErrFlag(uint8 transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvGetTrcvSystemData(uint8 transceiver,
        uint32* trcvSysData);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvClearTrcvWufFlag(uint8 transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvReadTrcvTimeoutFlag(uint8 transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* flagState);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvClearTrcvTimeoutFlag(uint8 transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvReadTrcvSilenceFlag(uint8 transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* flagState);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvSoftReset(uint8 transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

// #ifdef CAN_PLT_SAFERTOS_ENABLE
// CanTrcv_ReturnType Tcan1146DelSpiEventGroup(uint8 transceiver);
// #endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#endif /* CANTRCV_184_TCAN1146_INTERNAL_H */

/*=============================================================================
  |                       END OF FILE                                           |
  =============================================================================*/
