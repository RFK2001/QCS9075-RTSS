/*
===========================================================================
*/
/**
    @file  pmicconfig.h
    @brief This header contains config info of regulator

*/
/*
    ===========================================================================

    Copyright (c) Qualcomm Technologies, Inc.
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
#ifndef PMICCONFIG_H
#define PMICCONFIG_H

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "pmicapi.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#ifdef lemans
    #define PMIC_CONFIG_CUSTOMER_NVM_ID             0x2U  // Current Expected TI PMIC Firmware version for LeMans
    #define PMIC_NVM_CODE2_FW_SUPPORTED             0x1U  // Default NVMCode2 is 0x1 on LeMans PMIC Release
#else
    #define PMIC_CONFIG_CUSTOMER_NVM_ID             0x6U  // Current Expected TI PMIC Firmware version for Monaco
    #define PMIC_CONFIG_CUSTOMER_NVM_ID_REV_1P0     0x0U  // Customer NVM ID is 0x0 for Revision 1p0 on Monaco
    #define PMIC_NVM_CODE2_FW_SUPPORTED             0x0U  // Default NVMCode2 is 0x0 on Monaco PMIC Release
    #define PMIC_NVM_CODE2_FW_REV_1                 0x1U  // NVMcode2 is 0x1 on Monaco for Rev 1p0 and 1p1
#endif

#define PMIC_CONFIG_DEV_REV                     0x82U

#define PMIC_MAX_SMPS_COUNT                     0x5u
#define PMIC_MAX_LDO_COUNT                      0x4u 

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

typedef struct{
    uint32             AccessAllowed:1;
    uint32             AlwaysOn:1; 
    uint32             MinPwrMode:2;
    uint32             SettlingErrorEnabled:1;  //ignore settling failure
    uint32             SettlingEnabled:1;       //ignore settling
    uint32             MinVoltage:16;           // in mV
    uint32             MaxVoltage:16;           // in mV
}pmicRegulatorConfigType;

enum
{
   PMIC_ACCESS_DISALLOWED = 0,
   PMIC_ACCESS_ALLOWED = 1,
};

enum
{
   PMIC_NONE = 0,
   PMIC_ALWAYS_ON = 1,
};

enum
{
   PMIC_SETTLING_DIS = 0,
   PMIC_SETTLING_EN = 1,
};

enum
{
   PMIC_SETTLING_ERR_DIS = 0,
   PMIC_SETTLING_ERR_EN = 1,
};

typedef struct
{
    uint64 currentVoltage;
    pmicRegulatorModeType_e currentMode;
    boolean currentEnable;
}pmicRegulatorStateType;


extern const pmicRegulatorConfigType pxpmicLdo[PMIC_MAX_LDO_COUNT];
extern const pmicRegulatorConfigType pxpmicSmps[PMIC_MAX_SMPS_COUNT];
extern const pmicRegulatorConfigType pxpmicLdo_Monaco[PMIC_MAX_LDO_COUNT];
extern const pmicRegulatorConfigType pxpmicSmps_Monaco[PMIC_MAX_SMPS_COUNT];
extern const uint16 pscxVoltagePlan[PMIC_CPR_VOLTAGE_LEVEL_COUNT];
extern const uint16 psmxVoltagePlan[PMIC_CPR_VOLTAGE_LEVEL_COUNT];
extern uint8 ucpmicLdoCount;
extern uint8 ucpmicSmpsCount;

#endif /* PMICCONFIG_H  */
/**********************************************************************************************************
**                                  End of file <pmicconfig.h>                                           **
**********************************************************************************************************/
