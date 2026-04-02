/*
===========================================================================
*/
/**
    @file  pmictarget.c
    @brief This file contains pre/post driver init call to add any WA or additional setting

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

#include <stdio.h>
#include "pmicapi.h"
#include "pmici2c.h"
#include "pmichwio.h"
#include "gpio_summary_intr.h"
#include "pmicinternal.h"
#include "chipinfo.h"
#include "platforminfodefs.h"
#include "Crashdbg_api.h"
#include "debug_log.h"
#include "pmictarget.h"
#include "pmicconfig.h"
#include "pmici2c.h"


/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#define PMIC_I2C_CRC_ENABLE         1u
#define ALL_GPIO                    0xFFu
#define GPIO9_11                    0x3Fu
#define PMIC_RUN_TIME_BIST_ENABLE   0x1U

#define CPR_BUMP_UP_VOLTAGE         0x1U
/*=========================================================================================================
**                                        Local function definitions                                     **
=========================================================================================================*/



/*=========================================================================================================
 @Service name        prvPmicPreTargetInit
 @Description         prvPmicPreTargetInit is used to add WA or do any register config before driver init happens
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      <Ptr>
 @return              <pmicErrFlagType_e> <Return err type based on status of read transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
 ==========================================================================================================*/

pmicErrFlagType_e prvPmicPreTargetInit(void)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    PlatformInfoPlatformType xPlatformType = PLATFORMINFO_TYPE_UNKNOWN;
    uint8 ucslewRate = 0x5u;  // configuring slew rate as 1.3 mV/μs
    uint8 ucBISTPass = 0x0u;
    uint8 ucCLKMonEn = 0x0u;
    uint64 ullvoltageUv = 0x0u;
    uint8 ucEnableINT = 0x0u;
    uint8 ucpmicNVMCode2 = 0x0u;
    uint8 ucpmicCustomerNVMID = 0x0u;
    uint8 ucEnableRuntimeBIST = 0x0u;
    //uint8 ucPsHoldPinBISTFail = 0x0u;
    //boolean isPmicFWMCULess = FALSE;
    pmicErrType xpmicErrorData = {0};

    #if PMIC_I2C_CRC_ENABLE  // CRC is disable

    xErrFlag = prvPmicCRCEnable();

    #endif

    ucpmicNVMCode2 = prvGetSAILPMICInfo(NVMCODE2);

    ucpmicCustomerNVMID = prvGetSAILPMICInfo(CUSTOMER_NVMID);

    //isPmicFWMCULess = (boolean)bSailPmicFWMCULess();

    xPlatformType = PlatformInfo_Platform();

    if ( PLATFORMINFO_TYPE_RUMI == xPlatformType )
    {
        /******* 
          On RUMI Platform Due sudden loss of energy on Buck5 there is glitch seen on VCCA because of which POFF Seq is failing
          by changing Slew rate of Buck5 to 1.3 mV/μs energy loss at Buck5 is controlled and no glitch is seen on VCCA line
        **********/

        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0,HWIO_PMIC(BUCK5_CONF),PMIC_BMSK(BUCK5_CONF,BUCK5_SLEW_RATE),
                    ucslewRate<<PMIC_SHFT(BUCK5_CONF,BUCK5_SLEW_RATE));
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }
    }

    /* 
        Turbo/Nominal voltage of CX/MX are configured in PFSM_DELAY_REG

        |--------------------------|-----------------------------|
        |      PFSM_DELAY_REG_1    | NOM Voltage of Buck3 (CX)   |
        |--------------------------|-----------------------------|
        |      PFSM_DELAY_REG_2    | NOM voltage of Buck4 (MX)   |
        |--------------------------|-----------------------------|
        |      PFSM_DELAY_REG_3    | Turbo voltage of Buck3 (CX) |
        |--------------------------|-----------------------------|
        |      PFSM_DELAY_REG_4    | Turbo voltage of Buck4 (MX) |
        |--------------------------|-----------------------------|

    */

    ullvoltageUv = 820u*1000u;
    xErrFlag = prvPmicCommWriteByte(PAGE_ID_0 , HWIO_PMIC(PFSM_DELAY_REG_1), prvPmicSmpsVoltageEncoding(&ullvoltageUv) );
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    ullvoltageUv = 820u*1000u;
    xErrFlag = prvPmicCommWriteByte(PAGE_ID_0 , HWIO_PMIC(PFSM_DELAY_REG_2), prvPmicSmpsVoltageEncoding(&ullvoltageUv) );
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    ullvoltageUv = 890u*1000u;
    xErrFlag = prvPmicCommWriteByte(PAGE_ID_0 , HWIO_PMIC(PFSM_DELAY_REG_3), prvPmicSmpsVoltageEncoding(&ullvoltageUv) );
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    ullvoltageUv = 890u*1000u;
    xErrFlag = prvPmicCommWriteByte(PAGE_ID_0 , HWIO_PMIC(PFSM_DELAY_REG_4), prvPmicSmpsVoltageEncoding(&ullvoltageUv) );
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }


    /* Programing SCRATCH_PAD_REG_2 register to 0x3 value ( Consider Cx/Mx are running at Turbo voltage from boot up) */   

    xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 , HWIO_PMIC(SCRATCH_PAD_REG_2), PMIC_BMSK(SCRATCH_PAD_REG_2,BUCK) , 0x3u );
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /*****

    [SA_24] Safety island software checks for BIST_PASS_INT and BIST_FAIL_INT both after startup and after RUNTIME_BIST
    
    *****/

    xErrFlag = prvPmicCommReadByteMask( PAGE_ID_0 , HWIO_PMIC(INT_MISC), PMIC_BMSK(INT_MISC,BIST_PASS_INT) , &ucBISTPass );
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    ucBISTPass = ucBISTPass>>PMIC_SHFT(INT_MISC,BIST_PASS_INT);

    /*****

    [SA_28] Safety island software should check that the CLKMON_EN=1 after completing every BIST operation

    *****/

    xErrFlag = prvPmicCommReadByteMask( PAGE_ID_0 , HWIO_PMIC(MISC_CTRL), PMIC_BMSK(MISC_CTRL,CLKMON_EN) , &ucCLKMonEn );
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    ucCLKMonEn = ucCLKMonEn>>PMIC_SHFT(MISC_CTRL,CLKMON_EN);

    xErrFlag = xPmicIntrHandler(&xpmicErrorData); // clear latched Interrupt on NINT Pin
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    if ( 0x0u == ucBISTPass )
    {
        ucEnableRuntimeBIST = PMIC_RUN_TIME_BIST_ENABLE;
    }
    else if ( 0x0u == ucCLKMonEn )
    {
        // Skip CLK_MON Check for MONACO Rev 1p0 (MCU FW supported) release
        #ifdef monaco
        if ( ( PMIC_NVM_CODE2_FW_REV_1 == ucpmicNVMCode2 ) && ( PMIC_CONFIG_CUSTOMER_NVM_ID_REV_1P0 == ucpmicCustomerNVMID ) )
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC BOOT UP BIST PASS\n\r");
            goto end;
        }
        #endif
        ucEnableRuntimeBIST = PMIC_RUN_TIME_BIST_ENABLE;
    }
    else
    {
        ucEnableRuntimeBIST = 0x0u;
    }

    if ( PMIC_RUN_TIME_BIST_ENABLE == ucEnableRuntimeBIST )
    {
      /*
       * In case boot up bist did not run/executed, run runtime bist.
       */
        DEBUG_LOG(SAIL_WARNING,"PMIC Boot up BIST status, BIST Pass = 0x%x, ClkMon Enable = 0x%x\n\r", ucBISTPass, ucCLKMonEn);
        xErrFlag = xPmicEnableRunTimeBist();
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            DEBUG_LOG(SAIL_ERROR,"RunTime BIST FAIL \n\r");
        }else
        {
            DEBUG_LOG(SAIL_WARNING,"RunTime BIST Pass \n\r");
        }

    }else
    {
        DEBUG_LOG(SAIL_WARNING,"PMIC BOOT UP BIST PASS\n\r");
    }

    end:
        return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicPostTargetInit
 @Description         prvPmicPostTargetInit is used to add WA or do any register config after driver init happens
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      <Ptr>
 @return              <pmicErrFlagType_e> <Return err type based on status of read transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
 ==========================================================================================================*/


pmicErrFlagType_e prvPmicPostTargetInit(void)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    /* 
     * Configuring PMIC for POff Sequence so that in case of secure device where
     * crash debug driver is disabled . Device will go POFF state instead of
     * dump collection
     */
            xErrFlag = xPmicSetResetState(PMIC_POFF);

        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            goto end;
        }
//    }

    /*
     * MASK Falling and rising edge of all GPIO so NINT IRQ wont trigger if there
     * is falling or rising edge on any of GPIO
     */
    xErrFlag = prvPmicCommWriteByte(PAGE_ID_0 , HWIO_PMIC(MASK_GPIO1_8_FALL), ALL_GPIO);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        goto end;
    }

    xErrFlag = prvPmicCommWriteByte(PAGE_ID_0 , HWIO_PMIC(MASK_GPIO1_8_RISE), ALL_GPIO);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        goto end;
    }

    xErrFlag = prvPmicCommWriteByte(PAGE_ID_0 , HWIO_PMIC(MASK_GPIO9_11), GPIO9_11);

    #ifdef CPR_BUMP_UP_VOLTAGE // TODO: Remove once CPR is enabled.
//        xErrFlag = xPmicChangeCornerVolt(PMIC_CX_RAIL,PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1);
//        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
//        {
//            goto end;
//        }
//        
//        xErrFlag = xPmicChangeCornerVolt(PMIC_MX_RAIL,PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1);
    #endif
    end:
        return xErrFlag;
}

 
/**********************************************************************************************************
**                                  End of file pmic__target.c                                        **
**********************************************************************************************************/

