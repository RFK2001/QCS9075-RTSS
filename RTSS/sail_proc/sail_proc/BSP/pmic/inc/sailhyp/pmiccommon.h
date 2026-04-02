/*
===========================================================================
*/
/**
    @file  pmiccommon.h
    @brief This header contains api to get config info of peripheral

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

/* Include header file guard */
#ifndef PMICEL2COMMON_H
#define PMICEL2COMMON_H


/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "pmicapi.h"

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

typedef enum
{
    PMIC_LDO_CONFIG  = 0,
    PMIC_SMPS_CONFIG,
    PMIC_MX_CORNER,
    PMIC_CX_CORNER,
}pmicConfigType_e;


/*=========================================================================================================
**                                    Global function prototypes                                         **
=========================================================================================================*/

void* prvPmicTargetGetSpecInfo(pmicConfigType_e ulpropId);

uint8 prvPmicTargetGetCountInfo(pmicConfigType_e ulpropId);


#endif /* PMICEL2COMMON_H  */
/**********************************************************************************************************
**                                  End of file pmiccommon.h                                             **
**********************************************************************************************************/
