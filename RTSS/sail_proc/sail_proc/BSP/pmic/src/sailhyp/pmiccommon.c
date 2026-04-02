/*
===========================================================================
*/
/**
    @file  pmiccommon.c
    @brief contains defination of function used to fetch config data from pmicconfig.c file

*/
/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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

#include <stdio.h>
#include "types.h"
#include "pmicapi.h"
#include "pmicconfig.h"
#include "pmiccommon.h"

/*=========================================================================================================
**                                        Global variables and constants                                 **
=========================================================================================================*/

/*=========================================================================================================
**                                        Local functions definition                                    **
=========================================================================================================*/

/*=========================================================================================================
 @Service name        prvPmicTargetGetSpecInfo
 @Description         this function is being used to get target specific info from pmic_config.c file
 @param[in]           ulpropId   <based on prop id being passed target specific data will be returned>
 @param[out]          NA
 @param[in, out]      NA
 @return              void pointer
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO
 @Note                None
=========================================================================================================*/


void* prvPmicTargetGetSpecInfo(pmicConfigType_e ulpropId)
{

    void *pvinfo = NULL;

    switch(ulpropId)
    {
        case PMIC_SMPS_CONFIG:
            pvinfo = (void*)&pxpmicSmps;
            break;
        case PMIC_LDO_CONFIG:
            pvinfo = (void*)&pxpmicLdo;
            break;
        case PMIC_MX_CORNER:
            pvinfo = (void*)&psmxVoltagePlan;
            break;
        case PMIC_CX_CORNER:
            pvinfo = (void*)&pscxVoltagePlan;
            break;
        default:
            pvinfo = NULL;
            break;
    }
    return pvinfo;

}

/*=========================================================================================================
 @Service name        <prvPmicTargetGetCountInfo>
 @Description         This function is used to get peripheral count from pmic_config.c file
 @param[in]           <ulpropId>          <based on prop id being passed target specific data will be returned>
 @param[out]          NA
 @param[in, out]      NA
 @return              uint8 <count of peripheral present>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO
 @Note                None
=========================================================================================================*/

uint8 prvPmicTargetGetCountInfo(pmicConfigType_e ulpropId)
{
    uint8 ulperipheralCount = 0;
    switch(ulpropId)
    {
        case PMIC_SMPS_CONFIG:
            ulperipheralCount = ucpmicSmpsCount;
            break;
        case PMIC_LDO_CONFIG:
            ulperipheralCount = ucpmicLdoCount;
            break;
        default:
            ulperipheralCount = 0;
            break;
    }
    return ulperipheralCount;
}

 
/**********************************************************************************************************
**                                  End of file pmiccommon.c                                        **
**********************************************************************************************************/

