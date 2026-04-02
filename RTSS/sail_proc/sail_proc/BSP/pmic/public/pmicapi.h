/*
===========================================================================
*/
/**
    @file  pmiceapi.h
    @brief contains declaration all el1 API exposed to client

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

#ifndef PMICAPI_H
#define PMICAPI_H

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
/* CPR_STRIPPING_CHANGES */
/* cpr_api.h header inclusion commented, To be uncommented once CPR directory will be added to external release */
//#include "cpr_api.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/
#ifndef SAILEL2
#define PMIC_FUNC  __attribute__ ( ( section ( "pmic_func" ) ) )
#else
#define PMIC_FUNC
#endif


#define PMIC_MAX_NUM_PMICS 0x1U

#define MAX_ERR_LIST_SIZE       5u

#define MAX_ERR_DATA_INDEX      5u

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

typedef enum
{
    PMIC_REG_1 = 0,
    PMIC_REG_2,
    PMIC_REG_3,
    PMIC_REG_4,
    PMIC_REG_5,
    PMIC_REG_6,
    PMIC_REG_7,
    PMIC_REG_8,
    PMIC_REG_9,
    PMIC_REG_10,
    PMIC_REG_11,
    PMIC_REG_12,
    PMIC_REG_MAX = 0xFF
}pmicRegulatorIndex_e;


typedef enum : uint32
{
  PMIC_AUTO_MODE = 0,
  PMIC_FORCED_NPM_MODE,
  PMIC_NOT_SUPPORTED_MODE
}pmicRegulatorModeType_e;

enum
{
    PMIC_DISABLE = 0,
    PMIC_ENABLE
};

typedef enum
{
    PMIC_ERR_FLAG_SUCCESS = 0,
    PMIC_ERR_DRIVER_INIT_FAILED,
    PMIC_ERR_OUT_OF_BOUNDARY,
    PMIC_ERR_MODULE_NOT_SUPPORTED,
    PMIC_ERR_RAIL_NOT_SUPPORTED,
    PMIC_ERR_I2C_FAILED,
    PMIC_ERR_CRC_TRIGGER_FAILED,
    PMIC_ERR_TEST_MODULE_FAILED,
    PMIC_ERR_PTR_HANDLE,
    PMIC_ERR_NVM_UPDATE_FAILED,
    PMIC_ERR_VERSION_INIT_FAILED,
    PMIC_ERR_PRE_INIT_FAILED,
    PMIC_ERR_POST_INIT_FAILED,
    PMIC_INIT_ERROR,
    PMIC_MX_IVI_VOLTAGE_REQUEST_ERR,
    PMIC_CX_IVI_VOLTAGE_REQUEST_ERR,
    PMIC_LOG_DUMP_ERROR,
	PMIC_ENABLE_DRV_ERROR,
    PMIC_CRC_ERROR,
    PMIC_RUNTIME_BIST_ERROR,
    PMIC_MAX_LIMIT = 0xFF
}pmicErrFlagType_e;

typedef enum : uint32
{
    PMIC_CRASH_PASS_0 = 0,
    PMIC_CRASH_PASS_1,
    PMIC_CRASH_PASS_2,
    PMIC_POFF_PON,
    PMIC_POFF_PON_SKIP_KPD,
    PMIC_WARM_RESET,
    PMIC_POFF,
    PMIC_CRASH_PASS_INVALID
}pmicCrashDebugType_e;

/* CPR_STRIPPING_CHANGES */
/* Below Enum are now defined in PMIC, To be removed once CPR directory will be added to external release */
typedef enum : uint32
{
    PMIC_CPR_VOLTAGE_LEVEL_RETENTION,
    PMIC_CPR_VOLTAGE_LEVEL_RETENTION_BIN1,
    PMIC_CPR_VOLTAGE_LEVEL_SVS_L1,
    PMIC_CPR_VOLTAGE_LEVEL_NOMINAL,
    PMIC_CPR_VOLTAGE_LEVEL_TURBO,
    PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1,
    PMIC_CPR_VOLTAGE_LEVEL_COUNT
} ePMICCprVoltageLevelType;

/* CPR_STRIPPING_CHANGES */
/* Below Enum are now defined in PMIC, To be removed once CPR directory will be added to external release */
typedef enum
{
    PMIC_CPR_RAIL_ID_SAIL_CX = 0,
    PMIC_CPR_RAIL_ID_SAIL_MX,
    PMIC_CPR_SAIL_ID_LAST_NUM
} ePMICCprRailIdType;

typedef enum : uint32
{
    PMIC_CX_RAIL = PMIC_CPR_RAIL_ID_SAIL_CX,
    PMIC_MX_RAIL = PMIC_CPR_RAIL_ID_SAIL_MX,
    PMIC_INVALID_RAIL = PMIC_CPR_SAIL_ID_LAST_NUM
}pmicCornerRailType_e;

typedef struct{
    boolean bStatusOfErr;
    uint8 ErrInfo[MAX_ERR_DATA_INDEX];
}pmicErrInfo;

typedef struct{
    pmicErrInfo FSM_ERR_INT;
    pmicErrInfo SEVERE_ERR_INT;
    pmicErrInfo MODERATE_ERR_INT;
    pmicErrInfo MISC_INT;
    pmicErrInfo STARTUP_INT;
    pmicErrInfo GPIO_INT;
    pmicErrInfo LDO_VMON_INT;
    pmicErrInfo BUCK_INT;
}pmicErrType;


/*=========================================================================================================
**                                    Global function prototypes                                         **
=========================================================================================================*/

pmicErrFlagType_e xPmicLdoWriteEnable(uint8 ucindex , boolean benableStatus);

pmicErrFlagType_e xPmicSetResetState( pmicCrashDebugType_e xcrashDebug);

pmicErrFlagType_e xPmicConfigureEnableDrvPin( boolean bpullVal);

boolean bSailPmicPresent (void);

pmicErrFlagType_e xPmicChangeCornerVolt( pmicCornerRailType_e xrailType ,ePMICCprVoltageLevelType xcornerVal );

boolean bSailPmicFWMCULess (void);

boolean bPmicExtWdgFirstPetComplete (void);
pmicErrFlagType_e xPmicConfigurePoffDelay(uint8 ucdelayEncodedVal);
#if (defined SAILEL2) || (defined SAILSW1 )

pmicErrFlagType_e xPmicInit(void);

pmicErrFlagType_e xPmicChangeCoreRailVolt( pmicCornerRailType_e xrailType , uint64 ullvoltageUv);

pmicErrFlagType_e xPmicReadCoreRailVolt( pmicCornerRailType_e xrailType , uint64 *pullvoltageUv);

pmicErrFlagType_e xPmicEnableRunTimeBist(void);

pmicErrFlagType_e xPmicGetResetState( pmicCrashDebugType_e *pxcrashDebug);

pmicErrFlagType_e xPmicSmpsWriteMode (uint8 ucindex , pmicRegulatorModeType_e xmodeVal);

pmicErrFlagType_e xPmicSmpsReadMode(uint8 ucindex , pmicRegulatorModeType_e *xmodeVal);

pmicErrFlagType_e xPmicExtWdgInit(void);

pmicErrFlagType_e xPmicExtWdgEnable(void);

pmicErrFlagType_e xPmicExtWdgPet(void);

pmicErrFlagType_e xPmicAssertKPD_PWR(bool bPinExpStatus);

pmicErrFlagType_e xPmicExtWdgDisable(void);


void vPmicDeInit(void);

pmicErrFlagType_e xPmicIntrHandler( pmicErrType *pErrData );

pmicErrFlagType_e xPmicSleepWakeConfiguration(uint8 ucIsSleepEntry );

pmicErrFlagType_e xPmicGetSMErrStatus( uint8 *pcstatus );

pmicErrFlagType_e xPmicSMErrHandshake( void );
#endif

#if (defined SAILEL2)
pmicErrFlagType_e xPmicExtWdgDisableFromLongWindow(void);
#endif
#endif /* PMICEL1API_H_  */

/**********************************************************************************************************
**                                  End of file <pmicel1api.h>                                             **
**********************************************************************************************************/
