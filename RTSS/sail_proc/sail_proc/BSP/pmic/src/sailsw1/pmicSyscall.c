/*
===========================================================================
*/
/**
    @file  pmicSysCall.c
    @brief contains top level API exposed to EL1 which is calling internal 
    driver API

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



/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <stdbool.h>
#include "debug_log.h"
#include "types.h"
#include "pmicapi.h"
#include "syscall.h"
#include "syscall_pub.h"
#include "pmicinternal.h"
#include "pmici2c.h"
#include "pmiccommon.h"
#include "pmicapi.h"


/*=================================================================================================
**                                       Local macros, variables and constants                   **
==================================================================================================*/

#ifdef SAILSW1
/* SYS CALL DECLARATIONS */

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_GET_RESET_STATE,
                      (uint32_t)PMIC_GET_RESET_STATE_PARM_ID,
                      0u,
                      PMICSysCallGetResetState
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_DE_INIT,
                      (uint32_t)PMIC_DE_INIT_PARM_ID,
                      0u,
                      PMICSysCallDeInit
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_INIT,
                      (uint32_t)PMIC_INIT_PARM_ID,
                      0u,
                      PMICSysCallInit
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_WRITE_VOLTAGE,
                      (uint32_t)PMIC_WRITE_VOLTAGE_PARM_ID,
                      0u,
                      PMICSysCallWriteCoreRailVolt
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_READ_VOLTAGE,
                      (uint32_t)PMIC_READ_VOLTAGE_PARM_ID,
                      0u,
                      PMICSysCallReadCoreRailVolt
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_RUNTIME_BIST,
                      (uint32_t)PMIC_RUNTIME_BIST_PARM_ID,
                      0u,
                      PMICSysCallRunTimeBIST
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_INTR_HANDLING,
                      (uint32_t)PMIC_INTR_HANDLING_PARM_ID,
                      0u,
                      PMICSysCallIntrHandler
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_SMPS_MODE_WRITE,
                      (uint32_t)PMIC_SMPS_MODE_WRITE_PARM_ID,
                      0u,
                      PMICSysCallSmpsWriteMode
                    );

SAIL_DEFINE_SYSCALL(  PMIC_READ_SMPS_MODE,
                      PMIC_READ_SMPS_MODE_PARM_ID,
                      0,
                      PMICSysCallSmpsReadMode
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_SLEEP_CONFIG,
                      (uint32_t)PMIC_SLEEP_CONFIG_PARM_ID,
                      0u,
                      PMICSysCallSleepConfig
                    );

#endif

SAIL_DEFINE_SYSCALL(  PMIC_LDO_ENABLE_WRITE,
                      PMIC_LDO_ENABLE_WRITE_PARM_ID,
                      0,
                      PMICSysCallLdoWriteEnable
                    );


SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_PRESENT,
                      (uint32_t)PMIC_PRESENT_PARM_ID,
                      0u,
                      PMICSysCallSlavePmicPresent
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_CORNER_CHANGE,
                      (uint32_t)PMIC_CORNER_CHANGE_PARM_ID,
                      0u,
                      PMICSysCallChangeCornerVolt
                    );



SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_SET_RESET_STATE,
                      (uint32_t)PMIC_SET_RESET_STATE_PARM_ID,
                      0u,
                      PMICSysCallSetResetState
                    );



SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_CONFIGURE_ENABLEDRV_PIN,
                      (uint32_t)PMIC_CONFIGURE_ENABLEDRV_PIN_PARM_ID,
                      0u,
                      PMICSysCallConfigEnableDrvPin
                    );

/*=================================================================================================
**                                   Local function definitions                                 **
==================================================================================================*/


/*=================================================================================================
 @Service name        PMICSysCallLdoWriteEnable
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC uint32 PMICSysCallLdoWriteEnable(uint32 ucindex , uint32 benableStatus , sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicLdoWriteEnable((uint8)ucindex,(boolean)benableStatus);

    return  (uint32) SVC_SUCCESS;

}

/*=================================================================================================
 @Service name        PMICSysCallChangeCornerVolt
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/
/* CPR_STRIPPING_CHANGES */
PMIC_FUNC uint32 PMICSysCallChangeCornerVolt( pmicCornerRailType_e xrailType ,ePMICCprVoltageLevelType xcornerVal, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicChangeCornerVolt(xrailType,xcornerVal);

    return (uint32) SVC_SUCCESS;
}


/*=================================================================================================
 @Service name        PMICSysCallInit
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC  uint32 PMICSysCallSlavePmicPresent(sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) bSailPmicPresent();

    return (uint32) SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallSetResetState
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC  uint32 PMICSysCallSetResetState(pmicCrashDebugType_e xcrashDebug , sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicSetResetState(xcrashDebug);

    return (uint32) SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallConfigEnableDrvPin
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC  uint32 PMICSysCallConfigEnableDrvPin( uint32 bpullVal, sailbsp_svc_rsp_t *rsp )
{
     rsp->data[0] = (uint32) xPmicConfigureEnableDrvPin((boolean)bpullVal);

    return (uint32) SVC_SUCCESS;
}


#ifdef SAILSW1




/*=================================================================================================
 @Service name        PMICSysCallSleepConfig
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC uint32 PMICSysCallSleepConfig( uint32 ulIsSleepEntry, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicSleepWakeConfiguration((uint8)ulIsSleepEntry);

    return (uint32) SVC_SUCCESS;
}


/*=================================================================================================
 @Service name        PMICSysCallSmpsReadMode
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC uint32 PMICSysCallSmpsReadMode(uint32 ucindex , pmicRegulatorModeType_e *xmodeVal, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicSmpsReadMode((uint8)ucindex,xmodeVal);

    return (uint32) SVC_SUCCESS;
}


/*=================================================================================================
 @Service name        PMICSysCallSmpsWriteMode
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICSysCallSmpsWriteMode(uint32 ucindex , pmicRegulatorModeType_e xmodeVal , sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicSmpsWriteMode((uint8)ucindex,xmodeVal);

    return (uint32) SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallInit
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC  uint32 PMICSysCallInit(sailbsp_svc_rsp_t *rsp)
{

    vPmicDeInit();

    return (uint32) SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallDeInit
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC  uint32 PMICSysCallDeInit(sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicInit();

    return (uint32) SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallGetResetState
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


PMIC_FUNC  uint32 PMICSysCallGetResetState(uint32 *pxcrashDebug , sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicGetResetState(pxcrashDebug);

    return (uint32) SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallWriteCoreRailVoltEl2
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC  uint32 PMICSysCallWriteCoreRailVolt(pmicCornerRailType_e xrailType , uint32 ullvoltageLb , uint32 ullvoltageUb , sailbsp_svc_rsp_t *rsp)
{
    uint64 ullvoltageUv = 0x0;
    ullvoltageUv = ullvoltageUb;
    ullvoltageUv = (ullvoltageUv<<32)|(ullvoltageLb);

    rsp->data[0] = (uint32) xPmicChangeCoreRailVolt(xrailType,ullvoltageUv);

    return (uint32) SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallReadCoreRailVoltEl2
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


PMIC_FUNC  uint32 PMICSysCallReadCoreRailVolt(pmicCornerRailType_e xrailType , uint64 *pullvoltageUv, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicReadCoreRailVolt(xrailType,pullvoltageUv);

    return (uint32) SVC_SUCCESS;
}


/*=================================================================================================
 @Service name        PMICSysCallRunTimeBIST
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC  uint32 PMICSysCallRunTimeBIST( sailbsp_svc_rsp_t *rsp )
{
     rsp->data[0] = (uint32) xPmicEnableRunTimeBist();

    return (uint32) SVC_SUCCESS;
}



/*=================================================================================================
 @Service name        PMICSysCallIntrHandler
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PMIC_FUNC  uint32 PMICSysCallIntrHandler(  pmicErrType *pErrData , sailbsp_svc_rsp_t *rsp )
{
     rsp->data[0] = (uint32) xPmicIntrHandler(pErrData);

    return (uint32) SVC_SUCCESS;
}



#endif