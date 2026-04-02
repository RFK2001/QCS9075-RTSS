
#ifndef __SAIL_UPDATER_OTABOOKKEEP_H__
#define __SAIL_UPDATER_OTABOOKKEEP_H__

/*
===========================================================================
*/
/**
    @file  sail_updater_otabookkeep.h
    @brief Public interface declaration for the SAIL Updater OTA Bookkeeping.

*/
/*
    ===========================================================================

    Copyright (c) 2023-2025 Qualcomm Technologies, Inc.
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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/
#include "sail_updater_cmn.h"

typedef struct
{
    uint32_t OTAState:7;           /* State */
    uint32_t logicGuidASwapped:1;  /* Is the GPT1’s GUID_A physical offset swapped from original mem map */
}__attribute__((packed)) SAILUpdaterOTARawStateType;

typedef struct
{
    union{
        uint8_t rawState;
        SAILUpdaterOTARawStateType rawStateExt;             /* OTA status */
    };
    uint8_t crc;                                     /* CRC for the status */
}__attribute__((packed)) SAILUpdaterOTAStateType;

typedef struct
{
    uint32_t ulMagicNumber;
    uint32_t ulMagicNumCRC;
    uint32_t ulReserved[2];
}__attribute__((packed)) SAILUpdaterOTAMagicType;

typedef struct
{
    SAILUpdaterOTAStateType OTAState[8];         /* 16 byte aligned for ECC */
    uint16_t RetryCnt[8];                        /* 16 byte aligned for ECC. 0 value indicates a retry.
                                                  * Actual Number of retries is number of 0s in the array */
    SAILUpdaterOTAMagicType xMagic;
}__attribute__((packed)) SAILUpdaterOTARebootCtrlType;

/**********************************************************
 * SAIL_UPDATER Set OTA Status
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param SAILUpdaterOTAStateValType [IN]
 *   state to be set
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterSetOtaStatus (void *norHandle, SAILUpdaterOTAStateValType state);

/**********************************************************
 * SAIL_UPDATER Get OTA Status
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param SAILUpdaterOTAStateValType [OUT]
 *   state to be Read
 *
 * @param guidMap [OUT]
 *   GUID Mapping Information for GUIDA
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterGetOtaStatus (void *norHandle, SAILUpdaterOTAStateValType *otaStatus, uint8_t* guidMap);

/**********************************************************
 * SAIL OTA Updater Get Loader Flow
 *
 *
 * @param bootType [IN/OUT]
 *   pointer to return the boot mode
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterOtaBookGetLdrFlow(boolean *bootType);

/**********************************************************
 * SAIL OTA Updater Is Boot Type OTA Boot
 *
 *
 * @param void [IN]
 *   None
 *
 * @return bool TRUE/FALSE [OUT]
 *   retun values
 *
 **********************************************************/
boolean bSAILUpdaterOtaBookIsBootOTA(void);

/**********************************************************
 * SAIL OTA Updater get Current OTA state
 *
 *
 * @param void [IN]
 *   None
 *
 * @return SAILUpdaterOTAStateValType currentOTAState [OUT]
 *   return current OTA State
 *
 **********************************************************/
SAILUpdaterOTAStateValType xSAILUpdaterOtaBookGetCurrentOTAState(void);

/**********************************************************
 * SAIL_UPDATER Get Magic Number
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param pMagicNum [IN/OUT]
 *   magic num to be read
 *
 * @param pValid [IN/OUT]
 *   whether magic num is valid
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterGetMagicNum (void *norHandle, uint32_t *pMagicNum, boolean *pValid);

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
/**********************************************************
 * SAIL_UPDATER Set OTA Status
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param testCmdID [IN]
 *   Test Trigger ID
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterTestCorruptOtaStatus (void *norHandle, uint32_t testCmdID);
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

#endif /* __SAIL_UPDATER_OTABOOKKEEP_H__ */
