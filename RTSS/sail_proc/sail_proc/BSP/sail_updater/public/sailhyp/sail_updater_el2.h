
#ifndef __SAIL_UPDATER_EL2_H__
#define __SAIL_UPDATER_EL2_H__

/*
===========================================================================
*/
/**
    @file  sail_updater_el2.h
    @brief Public interface declaration for the SAIL Updater for EL2.

*/
/*
    ===========================================================================

    Copyright (c) 2022-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sail_updater/public/sailhyp/sail_updater_el2.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


#include "sail_updater_cmn.h"

/**********************************************************
 * SAIL Updater Initalization
 *
 *
 * @param void [IN]
 *   None
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterEl2Init(void);

/**********************************************************
 * SAIL Updater Task
 *
 *
 * @param pvParameters [IN/OUT]
 *   Pointer for Input Params
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSailUpdaterTask(void * pvParameters);

/**********************************************************
 * SAIL Updater De-Initalization
 *
 *
 * @param void [IN]
 *   None
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void xSAILUpdaterDeinit(void);

/**********************************************************
 * SAIL OTA Updater Is Boot Type OTA Boot
 *
 *
 * @param void [IN]
 *   None
 *
 * @return boolean TRUE/FALSE [OUT]
 *   retun values
 *
 **********************************************************/
boolean xSAILUpdaterIsBootTypeOTA(void);

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
SAILUpdaterOTAStateValType xSAILUpdaterGetCurrentOTAState(void);

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
SAILUpdaterStatusType_e xSAILUpdaterGetLoaderFlow(boolean *bootType);
#endif /* __SAIL_UPDATER_EL2_H__ */
