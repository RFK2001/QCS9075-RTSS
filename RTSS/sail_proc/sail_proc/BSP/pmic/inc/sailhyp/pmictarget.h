/*
===========================================================================
*/
/**
    @file  pmicel2target.h
    @brief This file contains post and pre api to add any WA

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
#ifndef PMICTARGET_H
#define PMICTARGET_H


/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "pmicapi.h"

/*=========================================================================================================
**                                    Local function prototypes                                         **
=========================================================================================================*/

pmicErrFlagType_e prvPmicPreTargetInit(void);

pmicErrFlagType_e prvPmicPostTargetInit(void);

#endif /* PMICTARGET_H  */
/**********************************************************************************************************
**                                  End of file pmictarget.h                                             **
**********************************************************************************************************/
