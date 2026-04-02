/*
===========================================================================
*/
/**
    @file  psailel1.h
    @brief This file contains PSAIL driver Global Interfaces and global parameters are defined here.

*/
/*
    ===========================================================================

    Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
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
#ifndef PSAIL_H
#define PSAIL_H
/*=================================================================================================
**                                      Include files                                            **
===================================================================================================*/
#include <stdbool.h>
#include "types.h"
#include "freertos_init.h"

/*=================================================================================================
**                                    Global function prototypes                                 **
===================================================================================================*/

BaseType_t xPsailTaskInit( CPUIdType_e           xSchdCore,UBaseType_t  xTaskPrior );
BaseType_t xPsail_Task_Resources_Init(CPUIdType_e xSchdCore);
#endif /* PSAIL_H  */
