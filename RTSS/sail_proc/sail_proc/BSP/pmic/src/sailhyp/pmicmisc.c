/*
===========================================================================
*/
/**
    @file  pmicmisc.c
    @brief This files contains function defination of generic APIs support on 
    PMIC driver

*/
/*
    ===========================================================================

    Copyright (c) 2021-2024 Qualcomm Technologies, Inc.
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
#include "pmicapi.h"
#include "pmichwio.h"
#include "pmici2c.h"
#include "pmicinternal.h"
#include "pmiccommon.h"
#include "gpio_summary_intr.h"
#include "timetick.h"
#include "busywait.h"
#include "pmicconfig.h"
#include "i2c.h"
#include "Crashdbg_api.h"
#include "syscall.h"
#include "syscall_pub.h"
#include "debug_log.h"
#include "chipinfo.h"
#include "chipinfodefs.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#define TRIGGER_I2C_2                       0x4
#define GPIO_64                             64
#define SLOW_RAMP_EN_DELAY                  3500
#define SLOW_RAMP_DIS_DELAY                 1000
#define RUNTIME_TOTAL_MAX_TIME_USEC         1800 // 1.8msec
#define RUNTIME_TIME_INTERVAL_STEP          20  // 20usec

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

/* CPR_STRIPPING_CHANGES */
static char const *pxCornerStringConversion[PMIC_CPR_VOLTAGE_LEVEL_COUNT] =
{
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION] = "retention",
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION_BIN1] = "retention_bin1",
    [PMIC_CPR_VOLTAGE_LEVEL_SVS_L1] = "svs_l1",
    [PMIC_CPR_VOLTAGE_LEVEL_NOMINAL] = "nominal",
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO] = "turbo",
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1] = "turbo_l1"
};


static char const *pxRailString[PMIC_INVALID_RAIL] = 
{
    [PMIC_CX_RAIL] = "CX",
    [PMIC_MX_RAIL] = "MX",
};


/*=========================================================================================================
**                                        Local function prototypes                                      **
=========================================================================================================*/

/* CPR_STRIPPING_CHANGES */
static pmicErrFlagType_e prvPmicChangeMxCornerVolt( ePMICCprVoltageLevelType xcornerVal );
static pmicErrFlagType_e prvPmicChangeCxCornerVolt( ePMICCprVoltageLevelType xcornerVal );
static pmicErrFlagType_e prvPmicPostBistConfig(uint8 ucmaxLdoPeripheralCount,uint8 ucmaxSmpsPeripheralCount);
static pmicErrFlagType_e prvPmicPreBistConfig(uint8 ucmaxLdoPeripheralCount,uint8 ucmaxSmpsPeripheralCount);
static pmicErrFlagType_e prvPmicSevErrClear(uint8 ucINTTopData , pmicErrType *pErrData);
static pmicErrFlagType_e prvPmicFsmErrClear(uint8 ucINTTopData , pmicErrType *pErrData);
static pmicErrFlagType_e prvPmicModerateErrClear(uint8 ucINTTopData , pmicErrType *pErrData);
static pmicErrFlagType_e prvPmicMiscINTClear(uint8 ucINTTopData , pmicErrType *pErrData);
static pmicErrFlagType_e prvPmicStartUpINTClear(uint8 ucINTTopData , pmicErrType *pErrData);
static pmicErrFlagType_e prvPmicGpioINTClear(uint8 ucINTTopData , pmicErrType *pErrData);
static pmicErrFlagType_e prvPmicLdoVmonINTClear (uint8 ucINTTopData , pmicErrType *pErrData);
static pmicErrFlagType_e prvPmicBuckINTClear (uint8 ucINTTopData , pmicErrType *pErrData);

/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/

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

   /*
    * LPM_EN sets device in a low power mode.Intended use case is for the PFSM to set LPM_EN upon entering a deep sleep state.
    * The end objective is to disable the digital oscillator to reduce power consumption
    */

    xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0,HWIO_PMIC(MISC_CTRL),PMIC_BMSK(MISC_CTRL,LPM_EN),ucIsSleepEntry<<PMIC_SHFT(MISC_CTRL,LPM_EN));

    return xErrFlag;
}


/*=========================================================================================================
 @Service name        xPmicGetResetState
 @Description         xPmicGetResetState is used to get reset state of PMIC
 @param[in]           NA
 @param[out]          <pxcrashDebug> < PMIC_CRASH_PASS_0, PMIC_CRASH_PASS_1, PMIC_CRASH_PASS_2, PMIC_PON_OFF, PMIC_POFF_PON_SKIP_KPD, PMIC_WARM_RESET, PMIC_POFF >
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
 
pmicErrFlagType_e xPmicGetResetState( pmicCrashDebugType_e *pxcrashDebug)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdataScratchPad1 = 0x0;
    uint8 ucdataScratchPad3 = 0x0;
    uint8 ucdataScratchPad4 = 0x0;
    i2cStatus_e xI2CStatus = I2C_SUCCESS;


    if ( Crashdbg_GetSailResetCtrlFSMState() >= SP_PRE_DDR_INIT_ST) // PASS2 Case
    {
        xI2CStatus = xI2cRead((uint8) PAGE_ID_0, HWIO_PMIC(SCRATCH_PAD_REG_1),1,&ucdataScratchPad1);
        if(I2C_SUCCESS != xI2CStatus)
        {
            xErrFlag = PMIC_ERR_I2C_FAILED;
        }
        
        xI2CStatus = xI2cRead((uint8) PAGE_ID_0, HWIO_PMIC(SCRATCH_PAD_REG_4),1,&ucdataScratchPad4);
        if(I2C_SUCCESS != xI2CStatus)
        {
            xErrFlag = PMIC_ERR_I2C_FAILED;
        }

    }
    else
    {

        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(SCRATCH_PAD_REG_1),&ucdataScratchPad1);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(SCRATCH_PAD_REG_4),&ucdataScratchPad4);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

    }

    if ( (0x2u == ucdataScratchPad1) && (0x0u == ucdataScratchPad4 ))
    {
        *pxcrashDebug = PMIC_CRASH_PASS_0;
    }else if ( ( 0x4u == ucdataScratchPad1 ) && ( 0x0u == ucdataScratchPad4 ) )
    {
        *pxcrashDebug = PMIC_CRASH_PASS_1;
    }else if ( ( 0x8u == ucdataScratchPad1 ) && ( 0x0u == ucdataScratchPad4 ) )
    {
        *pxcrashDebug = PMIC_CRASH_PASS_2;
    }else if ( ( 0x1u == ucdataScratchPad1 ) && ( 0x0u == ucdataScratchPad4 ) )
    {
        *pxcrashDebug = PMIC_WARM_RESET;
    }else if ( ( 0x0u == ucdataScratchPad1 ) && ( 0x1u == ucdataScratchPad4 ) )
    {
        *pxcrashDebug = PMIC_POFF_PON;
    }else if ( ( 0x80u == ucdataScratchPad1 ) && ( 0x1u == ucdataScratchPad4 ) )
    {
        *pxcrashDebug = PMIC_POFF_PON_SKIP_KPD;
    }else if ( ( 0x0u == ucdataScratchPad1 ) && ( 0x0u == ucdataScratchPad4 ) )
    {
        *pxcrashDebug = PMIC_POFF;
    }else
    {
        *pxcrashDebug = PMIC_CRASH_PASS_INVALID;
    }

    return xErrFlag;
}


/*=========================================================================================================
 @Service name        xPmicSetResetState
 @Description         xPmicSetResetState is used to configure crash_pad_reg_1 register based on crash 
                      state of system
 @param[in]           <xcrashDebug> < PMIC_CRASH_PASS_0, PMIC_CRASH_PASS_1, PMIC_CRASH_PASS_2, PMIC_PON_OFF, PMIC_POFF_PON_SKIP_KPD, PMIC_WARM_RESET, PMIC_POFF >
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
 
pmicErrFlagType_e xPmicSetResetState( pmicCrashDebugType_e xcrashDebug)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdataScratchPad1 = 0x0u;
    uint8 ucdataScratchPad3 = 0x0u;
    uint8 ucdataScratchPad4 = 0x0u;
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    ChipInfoIdType xChipInfo = CHIPINFO_ID_UNKNOWN;

    //TODO: need to check if the API requires mask when writing to scratch pad registers as Scratch_pad1 higer bits have different functionality. 
    switch(xcrashDebug)
    {
        case PMIC_CRASH_PASS_0 :
            ucdataScratchPad1 = 0x2u;
            ucdataScratchPad3 = 0xAu;
            ucdataScratchPad4 = 0x0u;
        break;

        case PMIC_CRASH_PASS_1:
            ucdataScratchPad1 = 0x4u;
            ucdataScratchPad3 = 0xAu;
            ucdataScratchPad4 = 0x0u;
        break;

        case PMIC_CRASH_PASS_2:
            ucdataScratchPad1 = 0x8u;
            ucdataScratchPad3 = 0xAu;
            ucdataScratchPad4 = 0x0u;
        break;

        case PMIC_WARM_RESET:
            ucdataScratchPad1 = 0x1u;
            ucdataScratchPad3 = 0xAu;
            ucdataScratchPad4 = 0x0u;
        break;

        case PMIC_POFF_PON:
            ucdataScratchPad1 = 0x0u;
            ucdataScratchPad3 = 0xAu;
            ucdataScratchPad4 = 0x1u;
        break;
        case PMIC_POFF:
            ucdataScratchPad1 = 0x0u;
            ucdataScratchPad3 = 0xAu;
            ucdataScratchPad4 = 0x0u;
        break;

        default:
            return PMIC_ERR_OUT_OF_BOUNDARY;
        break;
    }

    if (Crashdbg_GetSailResetCtrlFSMState() >= SP_PRE_DDR_INIT_ST) // PASS2 Case
    {

        if ( SLAVE_NOT_PRESENT == ucGetPmicPingStatus(PAGE_ID_0))
        {
            return PMIC_ERR_FLAG_SUCCESS;
        }

        xI2CStatus = xI2cWrite((uint8) PAGE_ID_0, HWIO_PMIC(SCRATCH_PAD_REG_1),1u,&ucdataScratchPad1);
        if(I2C_SUCCESS != xI2CStatus)
        {
            xErrFlag = PMIC_ERR_I2C_FAILED;
        }

        xI2CStatus = xI2cWrite((uint8) PAGE_ID_0, HWIO_PMIC(SCRATCH_PAD_REG_3),1u,&ucdataScratchPad3);
        if(I2C_SUCCESS != xI2CStatus)
        {
            xErrFlag = PMIC_ERR_I2C_FAILED;
        }

        xI2CStatus = xI2cWrite((uint8) PAGE_ID_0, HWIO_PMIC(SCRATCH_PAD_REG_4),1u,&ucdataScratchPad4);
        if(I2C_SUCCESS != xI2CStatus)
        {
            xErrFlag = PMIC_ERR_I2C_FAILED;
        }

    }
    else
    {

        xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(SCRATCH_PAD_REG_1),ucdataScratchPad1);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(SCRATCH_PAD_REG_3),ucdataScratchPad3);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(SCRATCH_PAD_REG_4),ucdataScratchPad4);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

    }


    return xErrFlag;
}

/*=========================================================================================================
 @Service name        xPmicReadCoreRailVolt
 @Description         xPmicReadCoreRailVolt is used to read out current cx/mx rail voltages
 @param[in]           <xrailType> <PMIC_CX_RAIL,PMIC_MX_RAIL>
 @param[out]          pullvoltageUv
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
 
pmicErrFlagType_e xPmicReadCoreRailVolt( pmicCornerRailType_e xrailType , uint64 *pullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    switch(xrailType)
    {
        case PMIC_CX_RAIL:
            xErrFlag = prvPmicSmpsReadVoltage((uint8)PMIC_REG_3 ,pullvoltageUv); // BUCK3 SAIL_CX
            break;

        case PMIC_MX_RAIL:
            xErrFlag = prvPmicSmpsReadVoltage((uint8)PMIC_REG_4 ,pullvoltageUv); //BUCK4 SAIL_MX
            break;

        default:
            xErrFlag = PMIC_ERR_RAIL_NOT_SUPPORTED;
            break;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        xPmicChangeCoreRailVolt
 @Description         xPmicChangeCoreRailVolt is used to configure cx/mx rail to the voltage being passed
 @param[in]           <ullvoltageUv> <Voltage in micro voltage>
 @param[in]           <xrailType> <PMIC_CX_RAIL,PMIC_MX_RAIL>
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
 
pmicErrFlagType_e xPmicChangeCoreRailVolt( pmicCornerRailType_e xrailType , uint64 ullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    switch(xrailType)
    {
        case PMIC_CX_RAIL:
            xErrFlag = prvPmicSmpsWriteVoltage((uint8) PMIC_REG_3 ,ullvoltageUv); // BUCK3 SAIL_CX
            break;

        case PMIC_MX_RAIL:
            xErrFlag = prvPmicSmpsWriteVoltage((uint8) PMIC_REG_4 ,ullvoltageUv); //BUCK4 SAIL_MX
            break;

        default:
            xErrFlag = PMIC_ERR_RAIL_NOT_SUPPORTED;
            break;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        xPmicChangeCornerVolt
 @Description         xPmicChangeCornerVolt is used to configure cx/mx rail to the corner being passed
 @param[in]           <xcornerVal> <TURBO_U1,TURBO,NOMINAL,SVS_U1,RETENTION_U1,RETENTION>
 @param[in]           <xrailType> <PMIC_CX_RAIL,PMIC_MX_RAIL>
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
pmicErrFlagType_e xPmicChangeCornerVolt( pmicCornerRailType_e xrailType ,ePMICCprVoltageLevelType xcornerVal )
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    switch(xrailType)
    {
        case PMIC_CX_RAIL:
            xErrFlag = prvPmicChangeCxCornerVolt(xcornerVal);
            break;

        case PMIC_MX_RAIL:
            xErrFlag = prvPmicChangeMxCornerVolt(xcornerVal);
            break;

        default:
            xErrFlag = PMIC_ERR_RAIL_NOT_SUPPORTED;
            goto pmic_exit;
            break;
    }

    if( PMIC_ERR_FLAG_SUCCESS == xErrFlag )
    {
        DEBUG_LOG(SAIL_INFO,"%s Set To %s Corner\n\r",pxRailString[xrailType],pxCornerStringConversion[xcornerVal]);
    }else
    {   
        if ( PMIC_ERR_OUT_OF_BOUNDARY == xErrFlag )
        {
            DEBUG_LOG(SAIL_ERROR,"%s Failed Invalid Corner passed %d\n\r",pxRailString[xrailType],xcornerVal);
        }else
    {
        DEBUG_LOG(SAIL_ERROR,"%s Failed To Set %s Corner\n\r",pxRailString[xrailType],pxCornerStringConversion[xcornerVal]);
    }
    }

    pmic_exit:
    return xErrFlag;
}



/*=========================================================================================================
 @Service name        xPmicConfigureEnableDrvPin
 @Description         xPmicConfigureEnableDrvPin is used to configure the ENABLE_DRV pin
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
 
pmicErrFlagType_e xPmicConfigureEnableDrvPin( boolean bpullVal)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;

    xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0,HWIO_PMIC(ENABLE_DRV_STAT),PMIC_BMSK(ENABLE_DRV_STAT,FORCE_EN_DRV_LOW),&ucdata);

    if( 0x0u == ucdata) // To get the I2C access to control ENABLE_DRV signal FORCE_EN_DRV_LOW need to be low . Current done by PON Seq
    {
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_4,HWIO_PMIC(WD_THR_CFG),PMIC_BMSK(WD_THR_CFG,WD_EN),PMIC_DISABLE); // TODO: When Wdog driver is enabled
                                                                                                                        // this can be removed later
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0,HWIO_PMIC(ENABLE_DRV_REG),PMIC_BMSK(ENABLE_DRV_REG,ENABLE_DRV),(uint8) bpullVal);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0,HWIO_PMIC(ENABLE_DRV_STAT),PMIC_BMSK(ENABLE_DRV_STAT,EN_DRV_IN),&ucdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        ucdata = ucdata>>PMIC_SHFT(ENABLE_DRV_STAT,EN_DRV_IN);

        if( ucdata != (uint8) bpullVal ) // ENABLE DRV didn't configure to match requested level
        {
            DEBUG_LOG(SAIL_ERROR,"PMIC CfgEnDrvPin Fail. Expected: %d\n\r", bpullVal);
            xErrFlag = PMIC_ENABLE_DRV_ERROR;
        }else
        {
            DEBUG_LOG(SAIL_INFO,"PMIC CfgEnDrvPin Success\n\r");
        }

    }else
    {
        DEBUG_LOG(SAIL_ERROR,"PMIC FORCE_EN_DRV_LOW Fail\n\r");
		xErrFlag = PMIC_ENABLE_DRV_ERROR;
    }

    return xErrFlag;
}



/*=========================================================================================================
 @Service name        xPmicEnableRunTimeBist
 @Description         xPmicEnableRunTimeBist is used to enable Runtime BIST
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      <Ptr>
 @return              <pmicErrFlagType_e> <Return xErrFlag type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

pmicErrFlagType_e xPmicEnableRunTimeBist(void)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;
    uint8 ucmaxLdoPeripheralCount = 0x0u;
    uint8 ucmaxSmpsPeripheralCount = 0x0u;
    uint8 ucindex = 0x0u;
    uint8 ucOVEnableData = 0x0u;
    uint8 ucUVEnableData = 0x0u;
    uint8 ucUVMask = 0x0u;
    uint8 ucOVMask = 0x0u;
    uint8 ucEnableStatus = 0x0u;
    uint8 ucBISTPass = 0x0u;
    uint8 ucCLKMonEn = 0x0u;
    uint8 ucpmicNVMCode2 = 0x0u;
    uint8 ucpmicCustomerNVMID = 0x0u;
    uint32 ulAddr = 0x0u;

    ucpmicNVMCode2 = prvGetSAILPMICInfo(NVMCODE2);

    ucpmicCustomerNVMID = prvGetSAILPMICInfo(CUSTOMER_NVMID);


    ucmaxLdoPeripheralCount = prvPmicTargetGetCountInfo(PMIC_LDO_CONFIG);

    ucmaxSmpsPeripheralCount = prvPmicTargetGetCountInfo(PMIC_SMPS_CONFIG);

    if ( PMIC_MAX_LDO_COUNT != ucmaxLdoPeripheralCount || PMIC_MAX_SMPS_COUNT != ucmaxSmpsPeripheralCount )
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    /* Pre Configuration neeed before Initiating RunTime BIST */

    xErrFlag = prvPmicPreBistConfig(ucmaxLdoPeripheralCount,ucmaxSmpsPeripheralCount);

    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }


    // Code to iniate RunTime BIST by writing 0x4 to FSM_I2C_TRIGGERS(0x85) register
    ulAddr =  HWIO_PMIC(FSM_I2C_TRIGGERS);
    xErrFlag = prvPmicCommWriteByte(PAGE_ID_0 ,ulAddr ,TRIGGER_I2C_2);
    if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
    {
        return xErrFlag;
    }

    busywait(RUNTIME_TOTAL_MAX_TIME_USEC);

    // Check if RunTime BIST completed successfully by reading out BIST_PASS_INT[0:0] bit of INT_MISC(0x66) register and CLKMON_EN[3:3] of MISC_CTRL(0x81) register
    ulAddr = HWIO_PMIC(INT_MISC);
    xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0 , ulAddr, PMIC_BMSK(INT_MISC,BIST_PASS_INT),&ucBISTPass);
    if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
    {
        return xErrFlag;
    }

    ulAddr = HWIO_PMIC(MISC_CTRL);
    xErrFlag = prvPmicCommReadByteMask( PAGE_ID_0 , ulAddr, PMIC_BMSK(MISC_CTRL,CLKMON_EN) , &ucCLKMonEn );
    if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
    {
        return xErrFlag;
    }

    ucCLKMonEn = ucCLKMonEn>>PMIC_SHFT(MISC_CTRL,CLKMON_EN);

    if ( 0x0u == ucBISTPass )
    {
        return PMIC_RUNTIME_BIST_ERROR;
    }

    if ( 0x0u == ucCLKMonEn )
    {
        // Skip CLK_MON Check for MONACO Rev 1p0 (MCU FW supported) release
        #ifdef monaco
        if ( ( PMIC_NVM_CODE2_FW_REV_1 == ucpmicNVMCode2 ) && ( PMIC_CONFIG_CUSTOMER_NVM_ID_REV_1P0 == ucpmicCustomerNVMID ) )
        {
            goto pmic_post_bist;
        }
        #endif
        return PMIC_RUNTIME_BIST_ERROR;
    }

    /* Post Configuration needed after Initiating RunTime BIST */
    pmic_post_bist:
        xErrFlag = prvPmicPostBistConfig(ucmaxLdoPeripheralCount,ucmaxSmpsPeripheralCount);

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

pmicErrFlagType_e xPmicIntrHandler( pmicErrType *pErrData )
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;
    uint8 ucINTTopData = 0x0u;

    if ( NULL == pErrData )
    {
        return PMIC_ERR_PTR_HANDLE;
    }
    
    xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_TOP),&ucINTTopData);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /* Clear out FSM Error Latched IRQ present on NINT Pin */

    xErrFlag = prvPmicFsmErrClear(ucINTTopData,pErrData);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /* Clear out Severe Error Latched IRQ present on NINT Pin */

    xErrFlag = prvPmicSevErrClear(ucINTTopData,pErrData);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /* Clear out Moderate Error Latched IRQ present on NINT Pin */

    xErrFlag = prvPmicModerateErrClear(ucINTTopData,pErrData);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /* Clear out MISC INT Latched IRQ present on NINT Pin */

    xErrFlag = prvPmicMiscINTClear(ucINTTopData,pErrData);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /* Clear out Startup INT Latched IRQ present on NINT Pin */

    xErrFlag = prvPmicStartUpINTClear(ucINTTopData,pErrData);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /* Clear out GPIO INT Latched IRQ present on NINT Pin */

    xErrFlag = prvPmicGpioINTClear(ucINTTopData,pErrData);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /* Clear out LDO VMON Latched IRQ present on NINT Pin */

    xErrFlag = prvPmicLdoVmonINTClear(ucINTTopData,pErrData);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /* Clear out BUCK INT Latched IRQ present on NINT Pin */

    xErrFlag = prvPmicBuckINTClear(ucINTTopData,pErrData);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }


    xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_TOP),&ucdata); // Reading out INT_TOP ( 0x5A ) register to ensure that all Pending INTR are cleared

    if( (0x0u == ucdata)&&(PMIC_ERR_FLAG_SUCCESS == xErrFlag))
    {
        DEBUG_LOG(SAIL_INFO,"PMIC INTR Success\n\r");
    }else
    {
        DEBUG_LOG(SAIL_ERROR,"PMIC INTR Failed INT_TOP:0x%x, Err:%d\n\r",ucdata,xErrFlag);
    }

    return xErrFlag;
}

/*=========================================================================================================
**                                        Local functions definition                                     **
=========================================================================================================*/

/*=========================================================================================================
 @Service name        prvPmicChangeMxCornerVolt
 @Description         prvPmicChangeMxCornerVolt is used to configure mx rail to the corner being passed
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
static pmicErrFlagType_e prvPmicChangeMxCornerVolt( ePMICCprVoltageLevelType xcornerVal )
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint16* pupmicRsrcInfo = NULL;
    uint64 ullVoltageuV = 0x0ULL;
/* CPR_STRIPPING_CHANGES */
    if ( xcornerVal >= PMIC_CPR_VOLTAGE_LEVEL_COUNT )
    {
        xErrFlag = PMIC_ERR_OUT_OF_BOUNDARY;
    }else
    {
        pupmicRsrcInfo = (uint16*) prvPmicTargetGetSpecInfo(PMIC_MX_CORNER);

        ullVoltageuV = pupmicRsrcInfo[xcornerVal]*1000ULL;

        xErrFlag = prvPmicSmpsWriteVoltage((uint8)PMIC_REG_4 ,ullVoltageuV); //BUCK4 SAIL_MX   
    }

    return xErrFlag;
}



/*=========================================================================================================
 @Service name        prvPmicChangeCxCornerVolt
 @Description         prvPmicChangeCxCornerVolt is used to configure cx rail to the corner being passed
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
static pmicErrFlagType_e prvPmicChangeCxCornerVolt( ePMICCprVoltageLevelType xcornerVal )
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint16* pupmicRsrcInfo = NULL;
    uint64 ullVoltageuV = 0x0ULL;
/* CPR_STRIPPING_CHANGES */
    if ( xcornerVal >= PMIC_CPR_VOLTAGE_LEVEL_COUNT )
    {
        xErrFlag = PMIC_ERR_OUT_OF_BOUNDARY;
    }else
    {
        pupmicRsrcInfo = (uint16*) prvPmicTargetGetSpecInfo(PMIC_CX_CORNER);

        ullVoltageuV = pupmicRsrcInfo[xcornerVal]*1000ULL;

        xErrFlag = prvPmicSmpsWriteVoltage((uint8)PMIC_REG_3 ,ullVoltageuV); // BUCK3 SAIL_CX   
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicPreBistConfig
 @Description         prvPmicPreBistConfig is used to do BIST configuration needed before intiaiting BIST
 @param[in]           <ucmaxLdoPeripheralCount> <Count of LDO>
 @param[in]           <ucmaxSmpsPeripheralCount> <Count of SMPS>
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

pmicErrFlagType_e prvPmicPreBistConfig(uint8 ucmaxLdoPeripheralCount,uint8 ucmaxSmpsPeripheralCount)
{

    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucindex = 0x0u;
    uint8 ucOVEnableData = 0x0u;
    uint8 ucUVEnableData = 0x0u;
    uint8 ucUVMask = 0x0u;
    uint8 ucOVMask = 0x0u;
    uint8 ucPgoodMask = 0x0u;
    uint8 ucEnableStatus = 0x0u;
    uint32 ulAddr = 0x0u;

    // Before RUNTIME_BIST request clear all LDOx_VMON_EN bits to 0

    for (ucindex = 0x0u ; ucindex < ucmaxLdoPeripheralCount ; ucindex++)
    {
        xErrFlag = prvPmicLdoReadEnable(ucindex,&ucEnableStatus);
        if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }

        if ( (uint8)PMIC_ENABLE == ucEnableStatus )
        {
            ulAddr = (HWIO_PMIC(LDO1_CTRL)+ucindex);
            xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0,ulAddr, PMIC_BMSK(LDO_CTRL,LDO_VMON_EN),(uint8)PMIC_DISABLE);
            if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
            {
                return xErrFlag;
            }

        }
    }

    // Before RUNTIME_BIST request Set VCCA_UV_MASK, VCCA_OV_MASK to 1
    ulAddr = HWIO_PMIC(MASK_VMON);
    xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 ,ulAddr, PMIC_BMSK(MASK_VMON,VCCA_UV_MASK),(uint8)PMIC_ENABLE<<PMIC_SHFT(MASK_VMON,VCCA_UV_MASK));
    if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
    {
        return xErrFlag;
    }

    ulAddr =  HWIO_PMIC(MASK_VMON);
    xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 , ulAddr, PMIC_BMSK(MASK_VMON,VCCA_OV_MASK),(uint8)PMIC_ENABLE<<PMIC_SHFT(MASK_VMON,VCCA_OV_MASK));
    if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
    {
        return xErrFlag;
    }


    // Before RUNTIME_BIST request all BUCKx_UV_MASK, BUCKx_OV_MASK to 1

    for (ucindex = 0x0u ; ucindex < ucmaxSmpsPeripheralCount ; ucindex++)
    {
        if ( ucindex %2u == 0u )
        {
            ucUVMask = (uint8)PMIC_BMSK(MASK_BUCK,BUCK1_UV_MASK);
            ucOVMask = (uint8)PMIC_BMSK(MASK_BUCK,BUCK1_OV_MASK);
            ucUVEnableData = (uint8) ((uint8)PMIC_ENABLE)<<PMIC_SHFT(MASK_BUCK,BUCK1_UV_MASK);
            ucOVEnableData = (uint8) ((uint8)PMIC_ENABLE)<<PMIC_SHFT(MASK_BUCK,BUCK1_OV_MASK);

        }else
        {
            ucUVMask = (uint8) (PMIC_BMSK(MASK_BUCK,BUCK1_UV_MASK)<<4u);
            ucOVMask = (uint8) (PMIC_BMSK(MASK_BUCK,BUCK1_OV_MASK)<<4u);
            ucUVEnableData = (uint8)((((uint8)PMIC_ENABLE)<<PMIC_SHFT(MASK_BUCK,BUCK1_UV_MASK))<<4u);
            ucOVEnableData = (uint8)((((uint8)PMIC_ENABLE)<<PMIC_SHFT(MASK_BUCK,BUCK1_OV_MASK))<<4u);
        }

        ulAddr = HWIO_PMIC(MASK_BUCK1_2) + (uint32)(ucindex/2u);
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0, ulAddr, ucUVMask, ucUVEnableData);
        if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }
        
        ulAddr = HWIO_PMIC(MASK_BUCK1_2) + (uint32)(ucindex/2u);
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0, ulAddr, ucOVMask, ucOVEnableData);
        if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }
    }

    // Before RUNTIME_BIST request LDOx_UV_MASK , LDOx_OV_MASK to 1

    for (ucindex = 0x0u ; ucindex < ucmaxLdoPeripheralCount ; ucindex++)
    {

        if ( ucindex %2u == 0u )
        {
            ucUVMask = (uint8)PMIC_BMSK(MASK_LDO,LDO1_UV_MASK);
            ucOVMask = (uint8)PMIC_BMSK(MASK_LDO,LDO1_OV_MASK);
            ucUVEnableData = (uint8) (((uint8)PMIC_ENABLE)<<PMIC_SHFT(MASK_LDO,LDO1_UV_MASK));
            ucOVEnableData = (uint8) (((uint8)PMIC_ENABLE)<<PMIC_SHFT(MASK_LDO,LDO1_OV_MASK));

        }else
        {
            ucUVMask = (uint8)PMIC_BMSK(MASK_LDO,LDO1_UV_MASK)<<4u;
            ucOVMask = (uint8)PMIC_BMSK(MASK_LDO,LDO1_OV_MASK)<<4u;
            ucUVEnableData =(uint8) ((((uint8)(PMIC_ENABLE))<<PMIC_SHFT(MASK_LDO,LDO1_UV_MASK))<<4u);
            ucOVEnableData =(uint8) ((((uint8)(PMIC_ENABLE))<<PMIC_SHFT(MASK_LDO,LDO1_OV_MASK))<<4u);

        }
        ulAddr = HWIO_PMIC(MASK_LDO1_2) + (uint32)(ucindex/2u);
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0, ulAddr, ucUVMask ,ucUVEnableData);
        if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }

        ulAddr = HWIO_PMIC(MASK_LDO1_2) + (uint32)(ucindex/2u);
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0, ulAddr, ucOVMask ,ucOVEnableData);
        if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }
    }



    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicPostBistConfig
 @Description         prvPmicPostBistConfig is used to do BIST configuration needed after intiaiting BIST
 @param[in]           <ucmaxLdoPeripheralCount> <Count of LDO>
 @param[in]           <ucmaxSmpsPeripheralCount> <Count of SMPS>
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

pmicErrFlagType_e prvPmicPostBistConfig(uint8 ucmaxLdoPeripheralCount,uint8 ucmaxSmpsPeripheralCount)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucindex = 0x0u;
    uint8 ucOVEnableData = 0x0u;
    uint8 ucUVEnableData = 0x0u;
    uint8 ucUVMask = 0x0u;
    uint8 ucOVMask = 0x0u;
    uint8 ucPgoodMask = 0x0u;
    uint8 ucEnableStatus = 0x0u;
    uint32 ulAddr = 0x0u;
    uint8 ucdata = 0x0u;

    // After RUNTIME_BIST request clear VCCA_UV_MASK, VCCA_OV_MASK
    ulAddr =  HWIO_PMIC(MASK_VMON);
    xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 ,ulAddr , PMIC_BMSK(MASK_VMON,VCCA_UV_MASK),(uint8)PMIC_DISABLE);
    if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
    {
        return xErrFlag;
    }
    ulAddr =  HWIO_PMIC(MASK_VMON);
    xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 , ulAddr, PMIC_BMSK(MASK_VMON,VCCA_OV_MASK),(uint8)PMIC_DISABLE);
    if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
    {
        return xErrFlag;
    }

    // After RUNTIME_BIST request clear BUCKx_UV_MASK, BUCKx_OV_MASK

    for (ucindex = 0x0u ; ucindex < ucmaxSmpsPeripheralCount ; ucindex++)
    {
        if ( ucindex %2u == 0u )
        {
            ucUVMask = (uint8)PMIC_BMSK(MASK_BUCK,BUCK1_UV_MASK);
            ucOVMask = (uint8)PMIC_BMSK(MASK_BUCK,BUCK1_OV_MASK);
        }else
        {
            ucUVMask = (uint8)(PMIC_BMSK(MASK_BUCK,BUCK1_UV_MASK)<<4u);
            ucOVMask = (uint8)(PMIC_BMSK(MASK_BUCK,BUCK1_OV_MASK)<<4u);
        }

        ulAddr = (HWIO_PMIC(MASK_BUCK1_2) + (uint32)(ucindex/2u));
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0,ulAddr, ucUVMask,(uint8)PMIC_DISABLE);
        if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }

        ulAddr = (HWIO_PMIC(MASK_BUCK1_2) + (uint32)(ucindex/2u));
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0, ulAddr, ucOVMask,(uint8)PMIC_DISABLE);
        if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }
    }

    // After RUNTIME_BIST request set all LDOx_VMON_EN bits to 1 if LDO is enable

    for (ucindex = 0x0 ; ucindex < ucmaxLdoPeripheralCount ; ucindex++)
    {
        xErrFlag = prvPmicLdoReadEnable(ucindex,&ucEnableStatus);
        if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }

        if ( (uint8) PMIC_ENABLE == ucEnableStatus )
        {
            ulAddr = (HWIO_PMIC(LDO1_CTRL)+ucindex);
            xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0,ulAddr, PMIC_BMSK(LDO_CTRL,LDO_VMON_EN),(uint8)PMIC_ENABLE<<PMIC_SHFT(LDO_CTRL,LDO_VMON_EN));
            if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
            {
                return xErrFlag;
            }
        }
    }

    // After RUNTIME_BIST request clear LDOx_UV_MASK , LDOx_OV_MASK

    for (ucindex = 0x0u ; ucindex < ucmaxLdoPeripheralCount ; ucindex++)
    {
        ucdata = 0x0u;
        ulAddr = (HWIO_PMIC(LDO1_CTRL) + ucindex);
        xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0, ulAddr, PMIC_BMSK(LDO_CTRL,LDO_SLOW_RAMP) , &ucdata);
        if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }
        ucdata = ucdata>>PMIC_SHFT(LDO_CTRL,LDO_SLOW_RAMP);

        if( ucdata == 0x1u )
        {
            busywait(SLOW_RAMP_EN_DELAY); // Delay of 3.5mSec Delay if LDO_SLOW_RAMP is enable
        }else
        {
            busywait(SLOW_RAMP_DIS_DELAY); // Delay of 1.0mSec Delay if LDO_SLOW_RAMP is disable
        }

        if ( ucindex %2u == 0u )
        {
            ucUVMask = (uint8)PMIC_BMSK(MASK_LDO,LDO1_UV_MASK);
            ucOVMask = (uint8)PMIC_BMSK(MASK_LDO,LDO1_OV_MASK);
        }else
        {
            ucUVMask = (uint8)(PMIC_BMSK(MASK_LDO,LDO1_UV_MASK)<<4u);
            ucOVMask = (uint8)(PMIC_BMSK(MASK_LDO,LDO1_OV_MASK)<<4u);
        }

        ulAddr = HWIO_PMIC(MASK_LDO1_2)+(uint32)(ucindex/2u);
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0, ulAddr, ucUVMask ,(uint8)PMIC_DISABLE);
        if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }

        ulAddr =  HWIO_PMIC(MASK_LDO1_2)+(uint32)(ucindex/2u);
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0, ulAddr, ucOVMask ,(uint8)PMIC_DISABLE);
        if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }
    }


    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicBuckINTClear
 @Description         prvPmicBuckINTClear is used to BUCK_INT latched IRQ
 @param[in]           <ucINTTopData> <Top IRQ Data of TI PMIC>
 @param[in]           <pErrData> <Packed Data of Latched IRQ>
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

static pmicErrFlagType_e prvPmicBuckINTClear (uint8 ucINTTopData , pmicErrType *pErrData)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;
    uint8 ucINTBUCKdata = 0x0u;

    if(0x0u !=(ucINTTopData&PMIC_BMSK(INT_TOP,BUCK_INT))>>PMIC_SHFT(INT_TOP,BUCK_INT))
    {
        pErrData->BUCK_INT.bStatusOfErr = TRUE;

        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_BUCK),&ucINTBUCKdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        pErrData->BUCK_INT.ErrInfo[0] = ucINTBUCKdata;

        if (0x0u != (ucINTBUCKdata&PMIC_BMSK(INT_BUCK,BUCK5_INT))>>PMIC_SHFT(INT_BUCK,BUCK5_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_BUCK5),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_BUCK5),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->BUCK_INT.ErrInfo[3] = ucdata;
        }

        if (0x0u != (ucINTBUCKdata&PMIC_BMSK(INT_BUCK,BUCK3_4_INT))>>PMIC_SHFT(INT_BUCK,BUCK3_4_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_BUCK3_4),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_BUCK3_4),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }
            pErrData->BUCK_INT.ErrInfo[2] = ucdata;
        }

        if(0x0u !=(ucINTBUCKdata&PMIC_BMSK(INT_BUCK,BUCK1_2_INT))>>PMIC_SHFT(INT_BUCK,BUCK1_2_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_BUCK1_2),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_BUCK1_2),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->BUCK_INT.ErrInfo[1] = ucdata;
        }
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicLdoVmonINTClear
 @Description         prvPmicLdoVmonINTClear is used to LDO_VMON_INT latched IRQ
 @param[in]           <ucINTTopData> <Top IRQ Data of TI PMIC>
 @param[in]           <pErrData> <Packed Data of Latched IRQ>
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

static pmicErrFlagType_e prvPmicLdoVmonINTClear (uint8 ucINTTopData , pmicErrType *pErrData)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;
    uint8 ucINTLDOVMONData = 0x0u;

    if(0x0u !=(ucINTTopData&PMIC_BMSK(INT_TOP,LDO_VMON_INT))>>PMIC_SHFT(INT_TOP,LDO_VMON_INT))
    {

        pErrData->LDO_VMON_INT.bStatusOfErr = TRUE;

        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_LDO_VMON),&ucINTLDOVMONData);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        pErrData->LDO_VMON_INT.ErrInfo[0] = ucINTLDOVMONData;

        if(0x0u != (ucINTLDOVMONData&PMIC_BMSK(INT_LDO_VMON,VCCA_INT))>>PMIC_SHFT(INT_LDO_VMON,VCCA_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_VMON),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_VMON),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->LDO_VMON_INT.ErrInfo[3]  = ucdata;
        }

        if(0x0u !=(ucINTLDOVMONData&PMIC_BMSK(INT_LDO_VMON,LDO3_4_INT))>>PMIC_SHFT(INT_LDO_VMON,LDO3_4_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_LDO3_4),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_LDO3_4),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->LDO_VMON_INT.ErrInfo[2]  = ucdata;
        }

        if(0x0u !=(ucINTLDOVMONData&PMIC_BMSK(INT_LDO_VMON,LDO1_2_INT))>>PMIC_SHFT(INT_LDO_VMON,LDO1_2_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_LDO1_2),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_LDO1_2),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->LDO_VMON_INT.ErrInfo[1]  = ucdata;
        }
    }

    return xErrFlag; 
}

/*=========================================================================================================
 @Service name        prvPmicGpioINTClear
 @Description         prvPmicGpioINTClear is used to GPIO_INT latched IRQ
 @param[in]           <ucINTTopData> <Top IRQ Data of TI PMIC>
 @param[in]           <pErrData> <Packed Data of Latched IRQ>
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

static pmicErrFlagType_e prvPmicGpioINTClear(uint8 ucINTTopData , pmicErrType *pErrData)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;
    uint8 ucINTGPIOData = 0x0u;

    if(0x0u !=(ucINTTopData&PMIC_BMSK(INT_TOP,GPIO_INT))>>PMIC_SHFT(INT_TOP,GPIO_INT))
    {

        pErrData->GPIO_INT.bStatusOfErr = TRUE;

        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_GPIO),&ucINTGPIOData);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        pErrData->GPIO_INT.ErrInfo[0] = ucINTGPIOData;

        if(0x0u !=(ucINTGPIOData& PMIC_BMSK(INT_GPIO,GPIO1_8_INT))>>PMIC_SHFT(INT_GPIO,GPIO1_8_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_GPIO1_8),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_GPIO1_8),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->GPIO_INT.ErrInfo[1] = ucdata;
        }

        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_GPIO),&ucINTGPIOData);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_GPIO),ucINTGPIOData);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicStartUpINTClear
 @Description         prvPmicStartUpINTClear is used to STARTUP_INT latched IRQ
 @param[in]           <ucINTTopData> <Top IRQ Data of TI PMIC>
 @param[in]           <pErrData> <Packed Data of Latched IRQ>
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

static pmicErrFlagType_e prvPmicStartUpINTClear(uint8 ucINTTopData , pmicErrType *pErrData)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;

    if(0x0u !=(ucINTTopData&PMIC_BMSK(INT_TOP,STARTUP_INT))>>PMIC_SHFT(INT_TOP,STARTUP_INT))
    {
        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_STARTUP),&ucdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_STARTUP),ucdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        pErrData->STARTUP_INT.bStatusOfErr = TRUE;
        pErrData->STARTUP_INT.ErrInfo[0] = ucdata;
    }

    return xErrFlag;

}

/*=========================================================================================================
 @Service name        prvPmicMiscINTClear
 @Description         prvPmicMiscINTClear is used to MISC_INT latched IRQ
 @param[in]           <ucINTTopData> <Top IRQ Data of TI PMIC>
 @param[in]           <pErrData> <Packed Data of Latched IRQ>
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

static pmicErrFlagType_e prvPmicMiscINTClear(uint8 ucINTTopData , pmicErrType *pErrData)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;

    if(0x0u !=(ucINTTopData&PMIC_BMSK(INT_TOP,MISC_INT))>>PMIC_SHFT(INT_TOP,MISC_INT))
    {
        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_MISC),&ucdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_MISC),ucdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        pErrData->MISC_INT.bStatusOfErr = TRUE;
        pErrData->MISC_INT.ErrInfo[0] = ucdata;
    }

    return xErrFlag; 
}

/*=========================================================================================================
 @Service name        prvPmicModerateErrClear
 @Description         prvPmicModerateErrClear is used to MODERATE_ERR_INT latched IRQ
 @param[in]           <ucINTTopData> <Top IRQ Data of TI PMIC>
 @param[in]           <pErrData> <Packed Data of Latched IRQ>
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

static pmicErrFlagType_e prvPmicModerateErrClear(uint8 ucINTTopData , pmicErrType *pErrData)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;

    if(0x0u !=(ucINTTopData&PMIC_BMSK(INT_TOP,MODERATE_ERR_INT))>>PMIC_SHFT(INT_TOP,MODERATE_ERR_INT))
    {
        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_MODERATE_ERR),&ucdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_MODERATE_ERR),ucdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        pErrData->MODERATE_ERR_INT.bStatusOfErr = TRUE;
        pErrData->MODERATE_ERR_INT.ErrInfo[0] = ucdata;

    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicFsmErrClear
 @Description         prvPmicFsmErrClear is used to FSM_ERR_INT latched IRQ
 @param[in]           <ucINTTopData> <Top IRQ Data of TI PMIC>
 @param[in]           <pErrData> <Packed Data of Latched IRQ>
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

static pmicErrFlagType_e prvPmicFsmErrClear(uint8 ucINTTopData , pmicErrType *pErrData)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;
    uint8 ucFSMdata = 0x0u;

    if( 0x0u != (ucINTTopData&PMIC_BMSK(INT_TOP,FSM_ERR_INT))>>PMIC_SHFT(INT_TOP,FSM_ERR_INT))
    {

        pErrData->FSM_ERR_INT.bStatusOfErr = TRUE;

        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_FSM_ERR),&ucFSMdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        pErrData->FSM_ERR_INT.ErrInfo[0] = ucFSMdata;

        if(0x0u !=(ucFSMdata&PMIC_BMSK(INT_FSM_ERR,WD_INT))>>PMIC_SHFT(INT_FSM_ERR,WD_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_4,HWIO_PMIC(WD_ERR_STATUS),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_4,HWIO_PMIC(WD_ERR_STATUS),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->FSM_ERR_INT.ErrInfo[4] = ucdata;
        }

        if(0x0u !=(ucFSMdata&PMIC_BMSK(INT_FSM_ERR,ESM_INT))>>PMIC_SHFT(INT_FSM_ERR,ESM_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_ESM),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_ESM),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->FSM_ERR_INT.ErrInfo[3] = ucdata;
        }

        if(0x0u !=(ucFSMdata&PMIC_BMSK(INT_FSM_ERR,READBACK_ERR_INT))>>PMIC_SHFT(INT_FSM_ERR,READBACK_ERR_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_READBACK_ERR),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_READBACK_ERR),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->FSM_ERR_INT.ErrInfo[2] = ucdata;
        }

        if(0x0u !=(ucFSMdata&PMIC_BMSK(INT_FSM_ERR,COMM_ERR_INT))>>PMIC_SHFT(INT_FSM_ERR,COMM_ERR_INT))
        {
            xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_COMM_ERR),&ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_COMM_ERR),ucdata);
            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return xErrFlag;
            }

            pErrData->FSM_ERR_INT.ErrInfo[1] = ucdata;
        }

        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_FSM_ERR),&ucFSMdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }
          

        xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_FSM_ERR),ucFSMdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicSevErrClear
 @Description         prvPmicSevErrClear is used to SEVERE_ERR_INT latched IRQ
 @param[in]           <ucINTTopData> <Top IRQ Data of TI PMIC>
 @param[in]           <pErrData> <Packed Data of Latched IRQ>
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

static pmicErrFlagType_e prvPmicSevErrClear(uint8 ucINTTopData , pmicErrType *pErrData)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdata = 0x0u;

    if(0x0u !=(ucINTTopData&PMIC_BMSK(INT_TOP,SEVERE_ERR_INT))>>PMIC_SHFT(INT_TOP,SEVERE_ERR_INT))
    {
        xErrFlag = prvPmicCommReadByte(PAGE_ID_0,HWIO_PMIC(INT_SEVERE_ERR),&ucdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommWriteByte(PAGE_ID_0,HWIO_PMIC(INT_SEVERE_ERR),ucdata);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        pErrData->SEVERE_ERR_INT.bStatusOfErr = TRUE;
        pErrData->SEVERE_ERR_INT.ErrInfo[0] = ucdata;
    }

    return xErrFlag;
}



/**********************************************************************************************************
**                                  End of file pmicmisc.c                                            **
**********************************************************************************************************/

