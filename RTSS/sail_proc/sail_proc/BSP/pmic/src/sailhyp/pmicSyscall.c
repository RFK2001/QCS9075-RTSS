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


/*=================================================================================================
**                                       Local macros, variables and constants                   **
==================================================================================================*/

/* SYS CALL DECLARATIONS */


SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_PRESENT,
                      (uint32_t)PMIC_PRESENT_PARM_ID,
                      0u,
                      PMICHVCCallSlavePmicPresent
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_GET_RESET_STATE,
                      (uint32_t)PMIC_GET_RESET_STATE_PARM_ID,
                      0u,
                      PMICHVCCallGetResetState
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_DE_INIT,
                      (uint32_t)PMIC_DE_INIT_PARM_ID,
                      0u,
                      PMICHVCCallDeInit
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_GET_NVM_ID,
                      (uint32_t)PMIC_GET_NVM_ID_PARM_ID,
                      0u,
                      PMICHVCCallGetSAILPMICINFO
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_INIT,
                      (uint32_t)PMIC_INIT_PARM_ID,
                      0u,
                      PMICHVCCallInit
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_COMM_WRITE,
                      (uint32_t)PMIC_COMM_WRITE_PARM_ID,
                      0u,
                      PMICHVCCallCommWriteByte
                    );


SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_SMPS_VOLTAGE_WRITE,
                      (uint32_t)PMIC_SMPS_VOLTAGE_WRITE_PARM_ID,
                      0u,
                      PMICHVCCallSmpsWriteVoltage
                    );


SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_SMPS_MODE_WRITE,
                      (uint32_t)PMIC_SMPS_MODE_WRITE_PARM_ID,
                      0u,
                      PMICHVCCallSmpsWriteMode
                    );


SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_SMPS_ENABLE_WRITE,
                      (uint32_t)PMIC_SMPS_ENABLE_WRITE_PARM_ID,
                      0u,
                      PMICHVCCallSmpsWriteEnable
                    );


SAIL_DEFINE_SYSCALL( (uint32_t)PMIC_LDO_VOLTAGE_WRITE,
                      (uint32_t)PMIC_LDO_VOLTAGE_WRITE_PARM_ID,
                      0u,
                      PMICHVCCallLdoWriteVoltage
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_LDO_ENABLE_WRITE,
                      (uint32_t)PMIC_LDO_ENABLE_WRITE_PARM_ID,
                      0u,
                      PMICHVCCallLdoWriteEnable
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_COMM_READ,
                      (uint32_t)PMIC_COMM_READ_PARM_ID,
                      0u,
                      PMICHVCCallCommReadByte
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_SET_RESET_STATE,
                      (uint32_t)PMIC_SET_RESET_STATE_PARM_ID,
                      0u,
                      PMICHVCCallSetResetState
                    );

SAIL_DEFINE_SYSCALL(  PMIC_READ_SMPS_MODE,
                      PMIC_READ_SMPS_MODE_PARM_ID,
                      0,
                      PMICHVCCallSmpsReadMode
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_READ_SMPS_ENABLE,
                      (uint32_t)PMIC_READ_SMPS_ENABLE_PARM_ID,
                      0u,
                      PMICHVCCallSmpsReadEnable
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_READ_SMPS_VOLTAGE,
                      (uint32_t)PMIC_READ_SMPS_VOLTAGE_PARM_ID,
                      0u,
                      PMICHVCCallSmpsReadVoltage
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_READ_LDO_ENABLE,
                      (uint32_t)PMIC_READ_LDO_ENABLE_PARM_ID,
                      0u,
                      PMICHVCCallLdoReadEnable
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_READ_LDO_VOLTAGE,
                      (uint32_t)PMIC_READ_LDO_VOLTAGE_PARM_ID,
                      0u,
                      PMICHVCCallLdoReadVoltage
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_WRITE_VOLTAGE,
                      (uint32_t)PMIC_WRITE_VOLTAGE_PARM_ID,
                      0u,
                      PMICHVCCallWriteCoreRailVolt
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_READ_VOLTAGE,
                      (uint32_t)PMIC_READ_VOLTAGE_PARM_ID,
                      0u,
                      PMICHVCCallReadCoreRailVolt
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_CONFIGURE_ENABLEDRV_PIN,
                      (uint32_t)PMIC_CONFIGURE_ENABLEDRV_PIN_PARM_ID,
                      0u,
                      PMICHVCCallConfigEnableDrvPin
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_RUNTIME_BIST,
                      (uint32_t)PMIC_RUNTIME_BIST_PARM_ID,
                      0u,
                      PMICHVCCallRunTimeBIST
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_CORNER_CHANGE,
                      (uint32_t)PMIC_CORNER_CHANGE_PARM_ID,
                      0u,
                      PMICHVCCallChangeCornerVolt
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_INTR_HANDLING,
                      (uint32_t)PMIC_INTR_HANDLING_PARM_ID,
                      0u,
                      PMICHVCCallIntrHandler
                    );

SAIL_DEFINE_SYSCALL(  (uint32_t)PMIC_SLEEP_CONFIG,
                      (uint32_t)PMIC_SLEEP_CONFIG_PARM_ID,
                      0u,
                      PMICHVCCallSleepConfig
                    );

/*=================================================================================================
**                                   Global function definitions                                 **
==================================================================================================*/


/*=================================================================================================
 @Service name        PMICHVCCallSleepConfig
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallSleepConfig(uint32 ulIsSleepEntry,sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicSleepWakeConfiguration((uint8)ulIsSleepEntry);

    return (uint32) HVC_SUCCESS;
}


/*=================================================================================================
 @Service name        PMICHVCCallInit
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallSlavePmicPresent(sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) bSailPmicPresent();

    return (uint32) HVC_SUCCESS;
}


/*=================================================================================================
 @Service name        PMICHVCCallInit
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallInit(sailbsp_hvc_rsp_t *rsp)
{
    vPmicDeInit();

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallDeInit
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallDeInit(sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicInit();

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallGetResetState
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


 uint32 PMICHVCCallGetResetState(uint32 *pxcrashDebug , sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicGetResetState((pmicCrashDebugType_e *)pxcrashDebug);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallGetSAILPMICINFO
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallGetSAILPMICINFO(uint32 ucPmicInfoType,sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) prvGetSAILPMICInfo((pmicInfo_e)ucPmicInfoType);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallSmpsWriteVoltage
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallSmpsWriteVoltage(uint32 ucindex , uint32 ullvoltageLb , uint32 ullvoltageUb, sailbsp_hvc_rsp_t *rsp)
{
    uint64 ullvoltageUv = 0x0;
    ullvoltageUv = ullvoltageUb;
    ullvoltageUv = (ullvoltageUv<<32)|(ullvoltageLb);
    rsp->data[0] = (uint32) prvPmicSmpsWriteVoltage((uint8)ucindex,ullvoltageUv);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallSmpsWriteMode
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallSmpsWriteMode(uint32 ucindex , pmicRegulatorModeType_e xmodeVal , sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicSmpsWriteMode((uint8)ucindex,xmodeVal);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallSmpsWriteEnable
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallSmpsWriteEnable(uint32 ucindex , uint32 benableStatus, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) prvPmicSmpsWriteEnable((uint8)ucindex,(boolean)benableStatus);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallLdoWriteVoltage
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallLdoWriteVoltage(uint32 ucindex , uint32 ullvoltageLb , uint32 ullvoltageUb  ,sailbsp_hvc_rsp_t *rsp)
{
    uint64 ullvoltageUv = 0x0;
    ullvoltageUv = ullvoltageUb;
    ullvoltageUv = (ullvoltageUv<<32)|(ullvoltageLb);

    rsp->data[0] = (uint32) prvPmicLdoWriteVoltage((uint8)ucindex,ullvoltageUv);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallLdoWriteEnable
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallLdoWriteEnable(uint32 ucindex , uint32 benableStatus , sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicLdoWriteEnable((uint8)ucindex,(boolean)benableStatus);

    return (uint32) HVC_SUCCESS;

}

/*=================================================================================================
 @Service name        PMICHVCCallCommReadByte
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallCommReadByte(pmicPageId_e xpageId, uint32 uladdr , uint8 *pcdata , sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) prvPmicCommReadByte(xpageId,uladdr,pcdata);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallSetResetState
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallSetResetState(pmicCrashDebugType_e xcrashDebug , sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicSetResetState(xcrashDebug);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallWriteCoreRailVoltEl2
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallWriteCoreRailVolt(pmicCornerRailType_e xrailType , uint32 ullvoltageLb , uint32 ullvoltageUb , sailbsp_hvc_rsp_t *rsp)
{
    uint64 ullvoltageUv = 0x0;
    ullvoltageUv = ullvoltageUb;
    ullvoltageUv = (ullvoltageUv<<32)|(ullvoltageLb);

    rsp->data[0] = (uint32) xPmicChangeCoreRailVolt(xrailType,ullvoltageUv);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallReadCoreRailVoltEl2
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


 uint32 PMICHVCCallReadCoreRailVolt(pmicCornerRailType_e xrailType , uint64 *pullvoltageUv, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicReadCoreRailVolt(xrailType,pullvoltageUv);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallLdoReadVoltage
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallLdoReadVoltage(uint32 ucindex , uint64 *pullvoltageUv, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) prvPmicLdoReadVoltage((uint8)ucindex,pullvoltageUv);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallLdoReadEnable
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


 uint32 PMICHVCCallLdoReadEnable(uint32 ucindex , boolean *pbenableStatus, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) prvPmicLdoReadEnable((uint8)ucindex,pbenableStatus);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallSmpsReadVoltage
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallSmpsReadVoltage(uint32 ucindex , uint64 *pullvoltageUv, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) prvPmicSmpsReadVoltage((uint8)ucindex,pullvoltageUv);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallSmpsReadEnable
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallSmpsReadEnable(uint32 ucindex , boolean *pbenableStatus, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) prvPmicSmpsReadEnable((uint8)ucindex,pbenableStatus);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallSmpsReadMode
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallSmpsReadMode(uint32 ucindex , pmicRegulatorModeType_e *xmodeVal, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicSmpsReadMode((uint8)ucindex,xmodeVal);

    return (uint32) HVC_SUCCESS;
}


/*=================================================================================================
 @Service name        PMICHVCCallConfigEnableDrvPin
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallConfigEnableDrvPin( uint32 bpullVal, sailbsp_hvc_rsp_t *rsp )
{
     rsp->data[0] = (uint32) xPmicConfigureEnableDrvPin((boolean)bpullVal);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallRunTimeBIST
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallRunTimeBIST( sailbsp_hvc_rsp_t *rsp )
{
     rsp->data[0] = (uint32) xPmicEnableRunTimeBist();

    return (uint32) HVC_SUCCESS;
}



/*=================================================================================================
 @Service name        PMICHVCCallIntrHandler
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 PMICHVCCallIntrHandler(  pmicErrType *pErrData , sailbsp_hvc_rsp_t *rsp )
{
     rsp->data[0] = (uint32) xPmicIntrHandler(pErrData);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallChangeCornerVolt
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
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

 uint32 PMICHVCCallChangeCornerVolt( pmicCornerRailType_e xrailType ,ePMICCprVoltageLevelType xcornerVal, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) xPmicChangeCornerVolt(xrailType,xcornerVal);

    return (uint32) HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICHVCCallCommWriteByte
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


 uint32 PMICHVCCallCommWriteByte(pmicPageId_e xpageId, uint32 uladdr , uint32 uldata , sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) prvPmicCommWriteByte(xpageId,uladdr,(uint8)uldata);

    return (uint32) HVC_SUCCESS;
}
