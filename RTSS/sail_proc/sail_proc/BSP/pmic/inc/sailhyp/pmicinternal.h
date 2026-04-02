/*
===========================================================================
*/
/**
    @file  pmicel2internal.h
    @brief This file contains all the internal api used to initialize the pmic driver

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
#ifndef PMICINERNAL_H
#define PMICINERNAL_H


/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

typedef enum
{
    PMIC_LDO = 0,
    PMIC_SMPS,
    PMIC_RSRC_INVALID
}pmicRegulatorType_e;


/*=========================================================================================================
**                                    Local function prototypes                                         **
=========================================================================================================*/

uint8 prvPmicSmpsVoltageEncoding( uint64 *pullvoltageUv );

pmicErrFlagType_e prvPmicDriverInit(void);

pmicErrFlagType_e prvPmicLdoReadVoltage(uint8 ucindex , uint64 *pullvoltageUv);

pmicErrFlagType_e prvPmicSmpsReadVoltage(uint8 ucindex , uint64 *pullvoltageUv);

pmicErrFlagType_e prvPmicLdoWriteVoltage(uint8 ucindex , uint64 ullvoltageUv);

pmicErrFlagType_e prvPmicSmpsWriteVoltage(uint8 ucindex , uint64 ullvoltageUv);

pmicErrFlagType_e prvPmicSmpsReadEnable(uint8 ucindex , boolean *benableStatus);

pmicErrFlagType_e prvPmicLdoReadEnable(uint8 ucindex , boolean *benableStatus);

pmicErrFlagType_e prvPmicSmpsWriteEnable(uint8 ucindex , boolean benableStatus);


#endif /* PMICEL2INERNAL_H_  */
/**********************************************************************************************************
**                                  End of file pmiceinternal.h                                          **
**********************************************************************************************************/
