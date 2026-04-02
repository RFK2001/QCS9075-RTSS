/*
===========================================================================
*/
/**
    @file  pmicsmps.c
    @brief contains smps api to set/get mode/voltage/enable

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
#include "pmichwio.h"
#include "pmici2c.h"
#include "pmiccommon.h"
#include "pmicconfig.h"
#include "busywait.h"
#include "pmicinternal.h"


/*=========================================================================================================
**                                        Global variables and constants                                 **
=========================================================================================================*/

static pmicRegulatorStateType pxsmpsState[5] = {0};

/*=========================================================================================================
**                                        Global function definitions                                     **
=========================================================================================================*/

/*=========================================================================================================
 @Service name        xPmicSmpsWriteMode
 @Description         xPmicSmpsWriteMode is used to set mode of any particular SMPS
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


pmicErrFlagType_e xPmicSmpsWriteMode(uint8 ucindex , pmicRegulatorModeType_e xmodeVal)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32 ulbuckCtrl = 0x0u;
    uint8 ucmaxPeripheralCount = 0x0u;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_SMPS_CONFIG);

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_SMPS_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        xErrFlag = PMIC_ERR_OUT_OF_BOUNDARY;
    }else if ( pmicRsrcInfo[ucindex].AccessAllowed == (uint32) PMIC_ACCESS_DISALLOWED 
                    || xmodeVal == (pmicRegulatorModeType_e) pxsmpsState[ucindex].currentMode ) // If access is disallowed no need to do any I2C operation on any LDO   
    {
        xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    }else
    {
        ulbuckCtrl = HWIO_PMIC(BUCK1_CTRL)+(uint32)(ucindex*2U);

        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 ,ulbuckCtrl,PMIC_BMSK(BUCK_CTRL,BUCK_FPWM), ((uint8)xmodeVal)<<PMIC_SHFT(BUCK_CTRL,BUCK_FPWM));

        pxsmpsState[ucindex].currentMode = xmodeVal;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        xPmicSmpsReadMode
 @Description         xPmicSmpsReadMode is used to mode of any particular SMPS
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

pmicErrFlagType_e xPmicSmpsReadMode(uint8 ucindex , pmicRegulatorModeType_e *xmodeVal)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32 ulbuckCtrl = 0x0u;
    uint8 ucdata = 0x0u;
    uint8 ucmaxPeripheralCount = 0x0u;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_SMPS_CONFIG);

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_SMPS_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        xErrFlag =  PMIC_ERR_OUT_OF_BOUNDARY;
    }else
    {
        ulbuckCtrl = HWIO_PMIC(BUCK1_CTRL)+(uint32)(ucindex*2U);

        xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0 ,ulbuckCtrl, PMIC_BMSK(BUCK_CTRL,BUCK_FPWM) ,&ucdata);

        *xmodeVal = (ucdata==0x0u) ? PMIC_AUTO_MODE : PMIC_FORCED_NPM_MODE;

        pxsmpsState[ucindex].currentMode = *xmodeVal;
    }

    return xErrFlag;
}



/*=========================================================================================================
**                                        Local function definitions                                     **
=========================================================================================================*/

/*=========================================================================================================
 @Service name        prvPmicSmpsVoltageDecoding
 @Description         prvPmicSmpsVoltageDecoding is used Decode the voltage(uV) to RAW value need to be written in HW
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      <Ptr>
 @return              ucbuckVset need to be written into HW 
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
 ==========================================================================================================*/

uint8 prvPmicSmpsVoltageEncoding( uint64 *pullvoltageUv )
{
    uint8 ucbuckVset = 0x0u;

    /*  Here , V is voltage in mV and N is value need to be written in BUCK_VOUT_1 or BUCK_VOUT_2 register of TI PMIC
                [300-600) :- N =  0 + (V-300)/20
                [600-1100) :- N =   0xF + (V-600)/5
                [1100 - 1660) :- N =  0x73 + (V-1100)/10
                [1660 - 3340] :- N =  0xAB + (V - 1660)/20
    */

    /* Voltage value encoding for LDOs */
	if ( (*pullvoltageUv) < 300000ULL )
	{
		
	}else if( (*pullvoltageUv) < 600000ULL )
    {

        if(0x0ULL != (*pullvoltageUv)%20000ULL)
        {
            *pullvoltageUv = ((*pullvoltageUv)/20000ULL)*20000ULL + 20000ULL;
        }

        ucbuckVset = (uint8) (((*pullvoltageUv)-300000ULL)/20000ULL);

    }else if( (*pullvoltageUv) < 1100000ULL )
    {

        if(0x0ULL != (*pullvoltageUv)%5000ULL)
        {
            *pullvoltageUv = ((*pullvoltageUv)/5000ULL)*5000ULL + 5000ULL ;
        }

        ucbuckVset = (uint8)(0xFULL + ((*pullvoltageUv)-600000ULL)/5000ULL);

    }else if((*pullvoltageUv) < 1660000ULL)
    {
        if(0x0ULL != (*pullvoltageUv)%10000u)
        {
            *pullvoltageUv = ((*pullvoltageUv)/10000ULL)*10000ULL + 10000ULL ;
        }
        
        ucbuckVset = (uint8) (0x73ULL + ((*pullvoltageUv)-1100000ULL)/10000ULL);
    }else if((*pullvoltageUv) <= 3340000ULL )
    {

        if(0x0ULL != (*pullvoltageUv)%20000ULL)
        {
            *pullvoltageUv = ((*pullvoltageUv)/20000ULL)*20000ULL + 20000ULL;
        }
        
        ucbuckVset = (uint8)(0xABULL + ((*pullvoltageUv)-1660000ULL)/20000ULL);

    }else
    {
        // Added for misra
    }

    return ucbuckVset;
}

/*=========================================================================================================
 @Service name        prvPmicSmpsReadVoltage
 @Description         prvPmicSmpsReadVoltage is used to read voltage of any particular SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[out]          <pullvoltageUv>  <Read voltage in micro Voltage>
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
=========================================================================================================*/



pmicErrFlagType_e prvPmicSmpsReadVoltage(uint8 ucindex , uint64 *pullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucsmpsVoltageSel = 0x0u;
    uint32 ulvoltageAdd = 0x0u;
    uint8 ucmaxPeripheralCount = 0x0u;
    uint32 ulbuckCtrl = 0x0u;
    uint8 ucbuckVset = 0x0u;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_SMPS_CONFIG);

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_SMPS_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    ulbuckCtrl = HWIO_PMIC(BUCK1_CTRL)+ (uint32)(ucindex*2U);

    xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0 ,ulbuckCtrl,PMIC_BMSK(BUCK_CTRL,BUCK_VSEL),&ucsmpsVoltageSel);
    if (PMIC_ERR_FLAG_SUCCESS != xErrFlag)
    {
        return xErrFlag;
    }

    if( ucsmpsVoltageSel == 0u)
    {
        ulvoltageAdd = HWIO_PMIC(BUCK1_VOUT_1) + (uint32)(ucindex*2U);
    }
    else
    {
        ulvoltageAdd = HWIO_PMIC(BUCK1_VOUT_2) + (uint32)(ucindex*2U);   
    }


    xErrFlag = prvPmicCommReadByte(PAGE_ID_0 , ulvoltageAdd , &ucbuckVset);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
    {
        return xErrFlag;
    }

    /*
        Here , n is value read from BUCK_VOUT_1 or BUCK_VOUT_2 register of TI PMIC
               [0-0xE] :- op = 300 + (n-0)*20
               [0xF- 0x72] :- op =  600 + ( n - 15)*5
               [0x73  - 0xAA ] :- op = 1100 + ( n - 115)*10
               [0xAB - 0xFF ] :- op = 1660+ ( n - 171)*20
    */


    /* Voltage mv decoding for LDOs */

    if( ucbuckVset <= 0xEu )
    {
        *pullvoltageUv = 300000ULL + (uint64) ucbuckVset*20000ULL;
    }
    else if( ucbuckVset <= 0x72u )
    {
        ucbuckVset = ucbuckVset-0xFu;
        *pullvoltageUv = 600000ULL + (uint64)ucbuckVset*5000ULL;
    }else if( ucbuckVset <= 0xAAu )
    {
        ucbuckVset = ucbuckVset-0x73u;
        *pullvoltageUv = 1100000ULL + (uint64) ucbuckVset*10000ULL;
    }else
    {
        ucbuckVset = ucbuckVset-0xABu;
        *pullvoltageUv = 1660000ULL + (uint64) ucbuckVset*20000ULL;
    }

    pxsmpsState[ucindex].currentVoltage = *pullvoltageUv;

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicSmpsWriteVoltage
 @Description         prvPmicSmpsWriteVoltage is used to read voltage of any particular SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[in]           <ullvoltageUv>  <Voltage need to be configured in micro volt i.e. 600000 if 600mV need to be configure>
 @param[out]          NA
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



pmicErrFlagType_e prvPmicSmpsWriteVoltage(uint8 ucindex , uint64 ullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucsmpsVoltageSel = 0x0u;
    uint32 ulvoltageAdd = 0x0u;
    uint32 ulbuckCtrl = 0x0u;
    uint32 ulbuckConf = 0x0u;
    uint8 ucmaxPeripheralCount = 0x0u;
    uint8 ucbuckSlewRate = 0x0u;
    uint64 ullmultipleFactor = 0x1ULL;
    uint32 ultimeDelta = 0x0UL;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;
    uint64 ullMaxVoltageConfig = 0x0u;
    uint64 ullMinVoltageConfig = 0x0u;
    uint8 pxBuckSlewRate[] = { 33u /*33 mV/μs*/, 20u /* 20 mV/μs*/ ,10u /* 10 mV/μs*/ ,5u /* 5 mV/μs */,25u /*2.5 mV/μs*/ , 13u /* 1.3 mV/μS */ ,
                               63u /* 0.63 mV/μs*/ ,31u /* 0.31 mV/μs*/};

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_SMPS_CONFIG);

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_SMPS_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    ullMaxVoltageConfig = (uint64) pmicRsrcInfo[ucindex].MaxVoltage*1000U;

    ullMinVoltageConfig = (uint64) pmicRsrcInfo[ucindex].MinVoltage*1000U;

    if ( pmicRsrcInfo[ucindex].AccessAllowed == (uint32) PMIC_ACCESS_DISALLOWED || ullvoltageUv == pxsmpsState[ucindex].currentVoltage ) // If access is disallowed no need to do any I2C operation on any LDO
    {
        return xErrFlag;
    }

    if ( ullvoltageUv < ullMinVoltageConfig || ullvoltageUv > ullMaxVoltageConfig)
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    ulbuckCtrl = HWIO_PMIC(BUCK1_CTRL)+(uint32)(ucindex*2U);

    xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0,ulbuckCtrl,PMIC_BMSK(BUCK_CTRL,BUCK_VSEL),&ucsmpsVoltageSel);
    if ( PMIC_ERR_FLAG_SUCCESS == xErrFlag )
    {
        if( ucsmpsVoltageSel == 0u)
        {
            ulvoltageAdd = HWIO_PMIC(BUCK1_VOUT_1) + (uint32)(ucindex*2U);
        }
        else
        {
            ulvoltageAdd = HWIO_PMIC(BUCK1_VOUT_2) + (uint32)(ucindex*2U);
        }

        xErrFlag = prvPmicCommWriteByte( PAGE_ID_0, ulvoltageAdd,prvPmicSmpsVoltageEncoding(&ullvoltageUv));

        if ( PMIC_ERR_FLAG_SUCCESS == xErrFlag  )
        {
            if ( ullvoltageUv > pxsmpsState[ucindex].currentVoltage )
            {
                ulbuckConf = HWIO_PMIC(BUCK1_CONF) + (uint32)(ucindex*2U);
                xErrFlag = prvPmicCommReadByteMask( PAGE_ID_0, ulbuckConf , PMIC_BMSK(BUCK_CTRL,BUCK_SLEW_RATE) ,&ucbuckSlewRate);

                if ( PMIC_ERR_FLAG_SUCCESS == xErrFlag )
                {
                    ucbuckSlewRate = ucbuckSlewRate>>PMIC_SHFT(BUCK_CTRL,BUCK_SLEW_RATE);

                    if ( ucbuckSlewRate <= 0x3U)
                    {
                        ullmultipleFactor = 0x1ULL;
                    }else if ( ucbuckSlewRate <= 0x5U )
                    {
                        ullmultipleFactor = 0xAULL;
                    }else //if ( ucbuckSlewRate <= 0x7U )
                    {
                        ullmultipleFactor = 0x64ULL;
                    }

                    ultimeDelta = (uint32) (((ullvoltageUv- pxsmpsState[ucindex].currentVoltage)*ullmultipleFactor)/((uint64)(pxBuckSlewRate[ucbuckSlewRate]*1000ULL)));
                }else
                {
                     /*added for Misra */
                }

            }else
            {
                /* In case of down side voltage no need add any wait time */
                ultimeDelta = 0u;
            }

            busywait(ultimeDelta);  // Adding delay based on delta of voltage in case of voltage rampup  .. For ramp down no need to add any delay

            pxsmpsState[ucindex].currentVoltage = ullvoltageUv;
        }else
        {
            /*added for Misra */       
        }
    }else
    {
        /*added for Misra */
    }

 

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicSmpsReadEnable
 @Description         prvPmicSmpsReadEnable is used to get the enable status of SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[out]          <benableStatus> <PMIC_DISABLE,PMIC_ENABLE>
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

pmicErrFlagType_e prvPmicSmpsReadEnable(uint8 ucindex , boolean *benableStatus)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32 ulbuckCtrl = 0x0u;    
    uint8 ucmaxPeripheralCount = 0x0u;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_SMPS_CONFIG);

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_SMPS_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        xErrFlag = PMIC_ERR_OUT_OF_BOUNDARY;
    }else
    {
        ulbuckCtrl = HWIO_PMIC(BUCK1_CTRL)+(uint32)(ucindex*2U);

        xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0 , ulbuckCtrl,PMIC_BMSK(BUCK_CTRL,BUCK_EN), benableStatus);

        pxsmpsState[ucindex].currentEnable = *benableStatus;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicSmpsWriteEnable
 @Description         prvPmicSmpsWriteEnable is used to enable any SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[in]           <benableStatus>  <PMIC_DISABLE,PMIC_ENABLE>
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

pmicErrFlagType_e prvPmicSmpsWriteEnable(uint8 ucindex , boolean benableStatus)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32 ulbuckCtrl = 0x0u;
    uint8 ucmaxPeripheralCount = 0x0u;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;


    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_SMPS_CONFIG);

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_SMPS_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    if ( pmicRsrcInfo[ucindex].AccessAllowed == (uint32) PMIC_ACCESS_DISALLOWED || 
        (pmicRsrcInfo[ucindex].AlwaysOn == (uint32) PMIC_ALWAYS_ON && pxsmpsState[ucindex].currentEnable)
        || benableStatus == pxsmpsState[ucindex].currentEnable ) // If access is disallowed or Rail is always on no need to do any I2C operation
    {
        return xErrFlag;
    }
    
    ulbuckCtrl = HWIO_PMIC(BUCK1_CTRL)+(uint32)(ucindex*2U);

    if( benableStatus == (boolean) PMIC_DISABLE )
    { 
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 ,ulbuckCtrl,PMIC_BMSK(BUCK_CTRL,BUCK_VMON_EN),0u);
        if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 ,ulbuckCtrl ,PMIC_BMSK(BUCK_CTRL,BUCK_EN), 0u);
        if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            return xErrFlag;
        }

    }else
    {
       xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 ,ulbuckCtrl,PMIC_BMSK(BUCK_CTRL,BUCK_EN), 1u);
       if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
       {
            return xErrFlag;
       }

       xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 , ulbuckCtrl,PMIC_BMSK(BUCK_CTRL,BUCK_VMON_EN),0x30u);
       if(PMIC_ERR_FLAG_SUCCESS != xErrFlag)
       {
            return xErrFlag;
       }
    }

    /* 

      TODO : Here Settling logic need to be added so that whenever write goes to any SMPS we need to give enough delay so that SMPS
      can have enough time to settled at required voltage for now adding delay of 1msec which can be removed later

    */

    busywait(1000u);  // Adding delay of 1msec

    pxsmpsState[ucindex].currentEnable = benableStatus;

    return xErrFlag;
}


/**********************************************************************************************************
**                                  End of file pmicsmps.c                                            **
**********************************************************************************************************/
