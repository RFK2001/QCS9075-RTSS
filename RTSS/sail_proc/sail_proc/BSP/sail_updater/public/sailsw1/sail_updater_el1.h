
#ifndef __SAIL_UPDATER_EL1_H__
#define __SAIL_UPDATER_EL1_H__

/*
===========================================================================
*/
/**
    @file  sail_updater_el1.h
    @brief Public interface declaration for the SAIL Updater driver in EL1.

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sail_updater/public/sailsw1/sail_updater_el1.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


#include "freertos_init.h"

/**********************************************************
 * SAIL Updater Task Init
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @param xTaskPrior [IN]
 *   Task Priority
 *
 * @return portBaseType [OUT]
 *   Status of the operation
 *
 **********************************************************/
BaseType_t xSAILUpdaterTaskInit( CPUIdType_e  xSchdCore, UBaseType_t  xTaskPrior );

/**********************************************************
 * SAIL Updater Initalization
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @return portBaseType [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
BaseType_t xSAILUpdaterInit(CPUIdType_e xSchdCore);

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

#endif /* __SAIL_UPDATER_EL1_H__ */
