/*
===========================================================================
*/
/**
    @file  pmicel1client.c
    @brief This file contains API exposed to EL1 which calls HVC calls to EL2

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

#include "types.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "err_fatal.h"
#include "syscall_svc.h"
#include "pmicapi.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/



/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/
/*=========================================================================================================
 @Service name        bSailPmicPresent
 @Description         bSailPmicPresent is used to return if SAIL PMIC is present
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              0 --> SAIL PMIC is not present
                      1 --> SAIL PMIC is present
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC boolean bSailPmicPresent (void)
{
    boolean ucPmicPresent = FALSE;
    uint32_t hvcId     = (uint32_t)PMIC_PRESENT;
    uint32_t paramId   = (uint32_t)PMIC_PRESENT_PARM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    ucPmicPresent = (boolean) paramId;

    return ucPmicPresent;
}


/*=========================================================================================================
 @Service name        xPmicConfigureEnableDrvPinEl1
 @Description         xPmicConfigureEnableDrvPinEl1 is used to configure enable drv pin
 @param[in]           <bpullVal> <PMIC_PULLDOWN,PMIC_PULLUP>
 @param[out]          NA
 @param[in, out]      NA
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC pmicErrFlagType_e xPmicConfigureEnableDrvPin( boolean bpullVal)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;;
    uint32_t hvcId     = (uint32_t)PMIC_CONFIGURE_ENABLEDRV_PIN;
    uint32_t paramId   = (uint32_t)PMIC_CONFIGURE_ENABLEDRV_PIN_PARM_ID;
    uint32_t arg1      = (uint32_t)bpullVal;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(PMIC, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(PMIC, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;
}
/*=========================================================================================================
 @Service name        xPmicSleepConfiguration
 @Description         xPmicSleepConfiguration is function to configure TI PMIC for Sleep
 @param[in]           ucIsSleepEntry => 1 for Sleep Configuration
                      ucIsSleepEntry => 0 for Wakeup Configuration
 @param[out]          NA
 @param[in, out]      NA
 @return              <err> <Return err type based on status of write transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

pmicErrFlagType_e xPmicSleepWakeConfiguration(uint8 ucIsSleepEntry )
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_SLEEP_CONFIG;
    uint32_t paramId   = PMIC_SLEEP_CONFIG_PARM_ID;
    uint32_t arg1      = (uint32_t)ucIsSleepEntry;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
                err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        xPmicLdoWriteEnable
 @Description         xPmicLdoWriteEnable is Trap call to enable any particular ldo
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[in]           <benableStatus>  <PMIC_DISABLE,PMIC_ENABLE>
 @param[out]          <Ptr>
 @param[in, out]      <Ptr>
 @return              <err> <Return err type based on status of write transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC pmicErrFlagType_e xPmicLdoWriteEnable(uint8 ucindex , boolean benableStatus)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_LDO_ENABLE_WRITE;
    uint32_t paramId   = PMIC_LDO_ENABLE_WRITE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)benableStatus;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
                err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;

}


/*=========================================================================================================
 @Service name        xPmicSetResetState
 @Description         xPmicSetResetState is used to configure crash_pad_reg_1 register based on crash 
                      state of system
 @param[in]           <xcrashDebug> < PMIC_CRASH_PASS_0 , PMIC_CRASH_PASS_1 ,PMIC_CRASH_PASS_2 , PMIC_PON_OFF ,PMIC_WARM_RESET >
 @param[out]          NA
 @param[in, out]      NA
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC pmicErrFlagType_e xPmicSetResetState( pmicCrashDebugType_e xcrashDebug)
{

    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;;
    uint32_t hvcId     = (uint32_t)PMIC_SET_RESET_STATE;
    uint32_t paramId   = (uint32_t)PMIC_SET_RESET_STATE_PARM_ID;
    uint32_t arg1      = (uint32_t) xcrashDebug;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;

}




/*=========================================================================================================
 @Service name        xPmicChangeCornerVolt
 @Description         xPmicChangeCornerVolt is used to configure cx/mx rail to the corner being passed
 @param[in]           <xcornerVal> <TURBO_U1,TURBO,NOMINAL,SVS_U1,RETENTION_U1,RETENTION>
 @param[out]          <Ptr>
 @param[in, out]      <Ptr>
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

/* CPR_STRIPPING_CHANGES */ 
PMIC_FUNC pmicErrFlagType_e xPmicChangeCornerVolt( pmicCornerRailType_e xrailType ,ePMICCprVoltageLevelType xcornerVal )
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = (uint32_t)PMIC_CORNER_CHANGE;
    uint32_t paramId   = (uint32_t)PMIC_CORNER_CHANGE_PARM_ID;
    uint32_t arg1      = (uint32_t)xrailType;
    uint32_t arg2      = (uint32_t)xcornerVal;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;
}





/*=========================================================================================================
 @Service name        xPmicSmpsWriteMode
 @Description         xPmicSmpsWriteMode Trap call to Write mode of SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[in]           <xmodeVal> <Mode of SMPS i.e.   PMIC_AUTO_MODE = 0,PMIC_FORCED_NPM>
 @param[in, out]      NA
 @return              <pmicErrFlagType_e> <Return err type based on status of read transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC pmicErrFlagType_e xPmicSmpsWriteMode(uint8 ucindex , pmicRegulatorModeType_e xmodeVal)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_SMPS_MODE_WRITE;
    uint32_t paramId   = PMIC_SMPS_MODE_WRITE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)xmodeVal;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;
}


/*=========================================================================================================
 @Service name        prvPmicSmpsReadMode
 @Description         prvPmicSmpsReadMode is Trap call to read mode of any particular SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[out]          <xmodeVal> <return Mode of SMPS i.e. PWM or Auto mode>
 @param[in, out]      NA
 @return              <pmicErrFlagType_e> <Return err type based on status of read transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC pmicErrFlagType_e xPmicSmpsReadMode(uint8 ucindex , pmicRegulatorModeType_e *xmodeVal)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_READ_SMPS_MODE;
    uint32_t paramId   = PMIC_READ_SMPS_MODE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)xmodeVal;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if (  (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if (  (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = (pmicErrFlagType_e) paramId;
    
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        xPmicGetResetState
 @Description         xPmicGetResetState is used to get reset state of PMIC
 @param[in]           NA
 @param[out]          <pxcrashDebug> < PMIC_CRASH_PASS_0 , PMIC_CRASH_PASS_1 ,PMIC_CRASH_PASS_2 , PMIC_PON_OFF ,PMIC_WARM_RESET >
 @param[in, out]      NA
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC pmicErrFlagType_e xPmicGetResetState( pmicCrashDebugType_e *pxcrashDebug)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    uint32_t hvcId     = (uint32_t)PMIC_GET_RESET_STATE;
    uint32_t paramId   = (uint32_t)PMIC_GET_RESET_STATE_PARM_ID;
    uint32_t arg1      = (uint32_t)pxcrashDebug;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrFlag = (pmicErrFlagType_e)paramId;

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        <xPmicInit>
 @Description         <xPmicInit function to initialization the PMIC Driver>
 @param[in]           <NA>
 @param[out]          <NA>
 @param[in, out]      <NA>
 @return              pmicErrFlagType_e
 @Pre                 I2C init should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC pmicErrFlagType_e xPmicInit(void)
{

    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = (uint32_t)PMIC_INIT;
    uint32_t paramId   = (uint32_t)PMIC_INIT_PARM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;

}


/*=========================================================================================================
 @Service name        <vPmicDeInit>
 @Description         <vPmicDeInit function to de-initialization the PMIC Driver>
 @param[in]           <NA>
 @param[out]          <NA>
 @param[in, out]      <NA>
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC void vPmicDeInit(void)
{

    uint32_t hvcId     = (uint32_t)PMIC_DE_INIT;
    uint32_t paramId   = (uint32_t)PMIC_DE_INIT_PARM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    return;
}



/*=========================================================================================================
 @Service name        xPmicReadCoreRailVolt
 @Description         xPmicReadCoreRailVolt is used to make trap call to read out current cx/mx rail voltages
 @param[in]           <xrailType> <PMIC_CX_RAIL,PMIC_MX_RAIL>
 @param[out]          pullvoltageUv
 @param[in, out]      <Ptr>
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetectEl2 should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/
 

PMIC_FUNC pmicErrFlagType_e xPmicReadCoreRailVolt( pmicCornerRailType_e xrailType , uint64 *pullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;;
    uint32_t hvcId     = (uint32_t)PMIC_READ_VOLTAGE;
    uint32_t paramId   = (uint32_t)PMIC_READ_VOLTAGE_PARM_ID;
    uint32_t arg1      = (uint32_t)xrailType;
    uint32_t arg2      = (uint32_t)pullvoltageUv;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;
}

/*=========================================================================================================
 @Service name        xPmicChangeCoreRailVolt
 @Description         xPmicChangeCoreRailVolt is used to make trap call to configure cx/mx rail to the voltage being passed
 @param[in]           <ullvoltageUv> <Voltage in micro voltage>
 @param[in]           <xrailType> <PMIC_CX_RAIL,PMIC_MX_RAIL>
 @param[out]          <Ptr>
 @param[in, out]      <Ptr>
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetectEl2 should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC pmicErrFlagType_e xPmicChangeCoreRailVolt( pmicCornerRailType_e xrailType , uint64 ullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;;
    uint32_t hvcId     = (uint32_t)PMIC_WRITE_VOLTAGE;
    uint32_t paramId   = (uint32_t)PMIC_WRITE_VOLTAGE_PARM_ID;
    uint32_t arg1      = (uint32_t)xrailType;
    uint32_t arg2      = (uint32_t)ullvoltageUv;
    uint32_t arg3      = (uint32_t)(ullvoltageUv>>32);
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        xPmicEnableRunTimeBist
 @Description         xPmicEnableRunTimeBist is used to initate RunTime BIST of TI PMIC
 @param[in]           NA
 @param[out]          <Ptr>
 @param[in, out]      <Ptr>
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

PMIC_FUNC pmicErrFlagType_e xPmicEnableRunTimeBist(void)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;;
    uint32_t hvcId     = (uint32_t)PMIC_RUNTIME_BIST;
    uint32_t paramId   = (uint32_t)PMIC_RUNTIME_BIST_PARM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrFlag = (pmicErrFlagType_e)paramId;
    
    return xErrFlag;
}


/*=========================================================================================================
 @Service name        xPmicIntrHandler
 @Description         xPmicIntrHandler is to clear and log critical err set in TI PMIC
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/
 
PMIC_FUNC pmicErrFlagType_e xPmicIntrHandler( pmicErrType *pErrData )
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = (uint32_t)PMIC_INTR_HANDLING;
    uint32_t paramId   = (uint32_t)PMIC_INTR_HANDLING_PARM_ID;
    uint32_t arg1      = (uint32_t)pErrData;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = (pmicErrFlagType_e) paramId;

    return xErrFlag;
}







/**********************************************************************************************************
**                                  End of file pmicel1misc.c                                            **
**********************************************************************************************************/
