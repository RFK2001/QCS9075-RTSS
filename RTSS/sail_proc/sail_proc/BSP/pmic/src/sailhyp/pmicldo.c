/*
===========================================================================
*/
/**
    @file  pmicldo.c
    @brief Contains API support for LDOs

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

static pmicRegulatorStateType pxldoState[4] = 
{
    {0,PMIC_NOT_SUPPORTED_MODE,0},
    {0,PMIC_NOT_SUPPORTED_MODE,0},
    {0,PMIC_NOT_SUPPORTED_MODE,0},
    {0,PMIC_NOT_SUPPORTED_MODE,0}
};

/*=========================================================================================================
**                                        Global function definitions                                     **
=========================================================================================================*/


/*=========================================================================================================
 @Service name        xPmicLdoWriteEnable
 @Description         xPmicLdoWriteEnable is used to enable any particular ldo
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

pmicErrFlagType_e xPmicLdoWriteEnable(uint8 ucindex , boolean benableStatus)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32 ulldoCtrl = 0x0u;
    uint8 ucmaxPeripheralCount = 0x0u;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_LDO_CONFIG);

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_LDO_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    if ( pmicRsrcInfo[ucindex].AccessAllowed == (uint32) PMIC_ACCESS_DISALLOWED || 
        (pmicRsrcInfo[ucindex].AlwaysOn == (uint32) PMIC_ALWAYS_ON && pxldoState[ucindex].currentEnable)
        || benableStatus == pxldoState[ucindex].currentEnable ) // If access is disallowed or Rail is always on no need to do any I2C operation
    {
        return xErrFlag;
    }

    ulldoCtrl = HWIO_PMIC(LDO1_CTRL)+(uint32)ucindex;

    if( benableStatus == (boolean) PMIC_DISABLE )
    {

        #if lemans

            /*
            * FB_B2 is used to monitor LDO2. After turning on LDO2 BUCK_VMON_EN need to be set on Buck2 to start monitoring of LDO2
            * This is required only for PMIC NVM 2 and RTL Release i.e. for PMIC NVM 1 this changes are not required 
            */

            if ( (uint8) PMIC_REG_2 ==  ucindex &&  ! ( PMIC_NVM_CODE2_FW_SUPPORTED == prvGetSAILPMICInfo(CUSTOMER_NVMID) && PMIC_NVM_CODE2_FW_SUPPORTED == prvGetSAILPMICInfo(NVMCODE2)) )
            {
                xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0,HWIO_PMIC(BUCK2_CTRL),PMIC_BMSK(BUCK_CTRL,BUCK_VMON_EN),PMIC_DISABLE);
                if( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
                {
                    return xErrFlag;
                }
            }

        #endif

        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 ,ulldoCtrl, PMIC_BMSK(LDO_CTRL,LDO_VMON_EN),(uint8) benableStatus);
        if( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 , ulldoCtrl,PMIC_BMSK(LDO_CTRL,LDO_EN) ,(uint8) benableStatus);
        if( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }

    }else
    {
        xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 , ulldoCtrl,PMIC_BMSK(LDO_CTRL,LDO_EN) ,(uint8) benableStatus<<PMIC_SHFT(LDO_CTRL,LDO_EN));
        if( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }
       
       xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0 , ulldoCtrl,PMIC_BMSK(LDO_CTRL,LDO_VMON_EN) ,(uint8) benableStatus<<PMIC_SHFT(LDO_CTRL,LDO_VMON_EN));
       if( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
       {
            return xErrFlag;
        }

        #if lemans

            /*
            * FB_B2 is used to monitor LDO2. After turning on LDO2 BUCK_VMON_EN need to be set on Buck2 to start monitoring of LDO2
            * This is required only for PMIC NVM 2 and RTL Release i.e. for PMIC NVM 1 this changes are not required 
            */

            if ( (uint8) PMIC_REG_2 ==  ucindex &&  ! ( PMIC_NVM_CODE2_FW_SUPPORTED == prvGetSAILPMICInfo(CUSTOMER_NVMID) && PMIC_NVM_CODE2_FW_SUPPORTED == prvGetSAILPMICInfo(NVMCODE2)) )
            {
                xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0,HWIO_PMIC(BUCK2_CTRL),PMIC_BMSK(BUCK_CTRL,BUCK_VMON_EN),(uint8)benableStatus<<PMIC_SHFT(BUCK_CTRL,BUCK_VMON_EN));
                if( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
                {
                    return xErrFlag;
                }
            }

        #endif
    }


    /* 

      TODO : Here Settling logic need to be added so that whenever write goes to any LDO we need to give enough delay so that LDO
      can have enough time to settled at required voltage for now adding delay of 1msec which can be removed later

    */

    busywait(1000);  // Adding delay of 1msec

    pxldoState[ucindex].currentEnable = benableStatus;

    return xErrFlag;
}

/*=========================================================================================================
**                                        Local function definitions                                     **
=========================================================================================================*/


/*=========================================================================================================
 @Service name        prvPmicLdoReadVoltage
 @Description         prvPmicLdoReadVoltage is used to read voltage of any particular ldo
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[out]          <pullvoltageUv>  <read voltage in micro Voltage>
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

pmicErrFlagType_e prvPmicLdoReadVoltage(uint8 ucindex , uint64 *pullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint64 ucmultipleFactor = 0x1u;
    uint32 ulvoltageAdd = 0x0UL;   
    uint8 ucmaxPeripheralCount = 0x0u;
    uint8 ucoffsetval = 0x4u;
    uint8 ucldoVset = 0x0u;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;
    uint8 ucMaskBit = 0x0u;
    uint8 ucShiftBit = 0x0u;

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_LDO_CONFIG);

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_LDO_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    if(ucindex == 3u) // For LDO4
    {
        ucmultipleFactor = 0x2u;
        ucoffsetval = 0x20u;
        ucMaskBit = PMIC_BMSK(LDO_VOUT_4,LDO_VSET);
        ucShiftBit = PMIC_SHFT(LDO_VOUT_4,LDO_VSET);
    }else
    {
        ucmultipleFactor = 0x1u;
        ucoffsetval = 0x4u;
        ucMaskBit = PMIC_BMSK(LDO_VOUT_1,LDO_VSET);
        ucShiftBit = PMIC_SHFT(LDO_VOUT_1,LDO_VSET);
    }

    /*
        For LDO1/LDO2/LDO3 op = 600 + (N-0x4)*50  ( N is value of LDO1_VOUT[6:1] = LDO1_VSET)
        
        For LDO4  op = 1200 + (N-0x20)*25  ( N is value of LDO1_VOUT[6:1] = LDO1_VSET) 
    */

    ulvoltageAdd = HWIO_PMIC(LDO1_VOUT) + (uint32)ucindex;

    xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0 ,ulvoltageAdd, ucMaskBit , &ucldoVset);

    ucldoVset = ((uint8)(ucldoVset>>ucShiftBit)&(0xFFU))-ucoffsetval;

    /* Voltage mv decoding for LDOs */

    *pullvoltageUv = (uint64) (600u*ucmultipleFactor + ((uint64)ucldoVset*50u)/ucmultipleFactor)*1000U;

    pxldoState[ucindex].currentVoltage = *pullvoltageUv;

    return xErrFlag;

}


/*=========================================================================================================
 @Service name        prvPmicLdoWriteVoltage
 @Description         prvPmicLdoWriteVoltage is used to write voltage of any particular ldo
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[in]           <ullvoltageUv>  <Configure voltage in micro Voltage i.e. 600000 to configure 600mV or 0.6V>
 @param[out]          <Ptr>
 @param[in, out]      <Ptr>
 @return              <pmicErrFlagType_e> <Return err type based on status of write transaction or input paramter being passed>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

pmicErrFlagType_e prvPmicLdoWriteVoltage(uint8 ucindex , uint64 ullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucldoVset = 0x0u;
    uint8 ucmultipleFactor = 0x1u;
    uint32 ulvoltageAdd = 0x0UL;
    uint8 ucmaxPeripheralCount = 0x0u;
    uint8 ucoffsetval = 0x4u;
    uint8 ucMaskBit = 0x0u;
    uint8 ucShiftBit = 0x0u;
    uint32 ultimeDelta = 0x0u;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;
    uint64 ullMinVoltageConfig = 0x0u;
    uint64 ullMaxVoltageConfig = 0x0u;
    uint64 ullVoltageOffset = 600u;
    uint64 ullDivideFactor = 50u;

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_LDO_CONFIG);

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_LDO_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    ullMinVoltageConfig = (uint64 )pmicRsrcInfo[ucindex].MinVoltage*1000U;

    ullMaxVoltageConfig = (uint64 )pmicRsrcInfo[ucindex].MaxVoltage*1000U;

    if ( pmicRsrcInfo[ucindex].AccessAllowed == (uint32) PMIC_ACCESS_DISALLOWED ||  ullvoltageUv == (uint64) pxldoState[ucindex].currentVoltage*1000U) // If access is disallowed no need to do any I2C operation on any LDO
    {
        return xErrFlag;
    }

    if ( ullvoltageUv < ullMinVoltageConfig || ullvoltageUv > ullMaxVoltageConfig )
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    if(ucindex == 3u) // For LDO4
    {
        ucmultipleFactor = 0x2u;
        ucoffsetval = 0x20u;
        ucMaskBit = PMIC_BMSK(LDO_VOUT_4,LDO_VSET);
        ucShiftBit = PMIC_SHFT(LDO_VOUT_4,LDO_VSET);
    }else
    {
        ucmultipleFactor = 0x1u;
        ucoffsetval = 0x4u;
        ucMaskBit = PMIC_BMSK(LDO_VOUT_1,LDO_VSET);
        ucShiftBit = PMIC_SHFT(LDO_VOUT_1,LDO_VSET);
    }

    ulvoltageAdd = HWIO_PMIC(LDO1_VOUT) + (uint32)ucindex;

    /*
        For LDO1/LDO2/LDO3 V = [600 , 3300] ,N = (V-600)/50 + 0x4 ( N need to be written in LDO1_VOUT[6:1] = LDO1_VSET)
        
        For LDO4 V = [ 1200 , 3300 ], N = (V-1200)/25 + 0x20 ( N need to be written in LDO1_VOUT[6:1] = LDO1_VSET )
    */

    /* Voltage value encoding for LDOs */

    ullvoltageUv = ullvoltageUv/1000u;

    ullvoltageUv = ((ullvoltageUv-ullVoltageOffset*ucmultipleFactor)*ucmultipleFactor)/ullDivideFactor;

    ucldoVset = ((uint8)ullvoltageUv) + ucoffsetval;

    ucldoVset = (uint8) ((ucldoVset<<ucShiftBit)&(0xFFu));

    xErrFlag = prvPmicCommWriteByteMask(PAGE_ID_0,ulvoltageAdd,ucMaskBit ,ucldoVset);

    if ( ullvoltageUv > pxldoState[ucindex].currentVoltage )
    {
        ultimeDelta = (uint32) (63u*( 7u + (ullvoltageUv-pxldoState[ucindex].currentVoltage)/50000u));
    }else
    {
        /* In case of down side voltage no need add any wait time */
        ultimeDelta = 0u;
    }
    

    busywait(ultimeDelta);  // Adding delay based on delta of voltage in case of voltage rampup  .. For ramp down no need to add any delay

    pxldoState[ucindex].currentVoltage = ullvoltageUv;

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicLdoReadEnable
 @Description         prvPmicLdoReadEnable is used to read enable status any particular ldo
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[out]          <benableStatus>  <PMIC_DISABLE,PMIC_ENABLE>
 @param[in, out]      <Ptr>
 @return              <err> <Return err type based on status of read transaction or input being passed>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


pmicErrFlagType_e prvPmicLdoReadEnable(uint8 ucindex , boolean *benableStatus)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32 ulldoCtrl = 0x0UL;    
    uint8 ucmaxPeripheralCount = 0x0u;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo(PMIC_LDO_CONFIG);

    if(ucindex >= ucmaxPeripheralCount)
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo(PMIC_LDO_CONFIG);

    ulldoCtrl = HWIO_PMIC(LDO1_CTRL)+ (uint32)ucindex;

    xErrFlag = prvPmicCommReadByteMask(PAGE_ID_0 , ulldoCtrl,PMIC_BMSK(LDO_CTRL,LDO_EN), benableStatus);

    pxldoState[ucindex].currentEnable = *benableStatus;

    return xErrFlag;
}



 
/**********************************************************************************************************
**                                  End of file pmicldo.c                                           **
**********************************************************************************************************/

