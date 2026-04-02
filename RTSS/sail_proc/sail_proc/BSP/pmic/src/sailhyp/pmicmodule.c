/*
===========================================================================
*/
/**
    @file  pmicmodule.c
    @brief This file contains all peripheral driver init calls

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
#include "pmicconfig.h"
#include "pmiccommon.h"
#include "pmicinternal.h"
#include "debug_log.h"

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/

static char const *pxRegulatorName[PMIC_RSRC_INVALID] =
{
    [PMIC_LDO] = "LDO",
    [PMIC_SMPS] = "SMPS",
};


/*=========================================================================================================
**                                        Local function prototypes                                      **
=========================================================================================================*/

static pmicErrFlagType_e prvPmicRegulatorGetVoltage(pmicRegulatorType_e xsmpsLdo , uint8 ucregulatorIndex , uint64 *pullvoltageUv);
static pmicErrFlagType_e prvPmicRegulatorSetVoltage(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex, uint64 ullvoltageUv);
static pmicErrFlagType_e prvPmicRegulatorGetMode(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex , pmicRegulatorModeType_e *xmodeVal);
static pmicErrFlagType_e prvPmicRegulatorSetMode(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex, pmicRegulatorModeType_e xmodeVal);
static pmicErrFlagType_e prvPmicRegulatorGetEnable(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex, boolean *benableStatus);
static pmicErrFlagType_e prvPmicRegulatorSetEnable(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex , boolean benableVal);
static pmicErrFlagType_e prvPmicRegulatorDriverInit(pmicRegulatorType_e xldoSmps);




/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/

/*=========================================================================================================
 @Service name        prvPmicDriverInit
 @Description         prvPmicDriverInit is to do init for PMIC_LDO ... PMIC_RSRC_INVALID based on enum present in pmic.h>
 @param[in]           <void>          <No Input>
 @param[out]          <void>
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


pmicErrFlagType_e prvPmicDriverInit(void)
{
    uint8 ucperipheralType = 0x0u ;
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;   

    for( ucperipheralType = (uint8) PMIC_LDO ; ucperipheralType < (uint8) PMIC_RSRC_INVALID ; ucperipheralType++)
    {
        xErrFlag =prvPmicRegulatorDriverInit( (pmicRegulatorType_e) ucperipheralType);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            return xErrFlag;
        }
    }
    return xErrFlag;
}

/*=========================================================================================================
**                                        Local function definitions                                     **
=========================================================================================================*/

/*=========================================================================================================
 @Service name        prvPmicRegulatorGetVoltage
 @Description         prvPmicRegulatorGetVoltage is used to get voltage of SMPS/LDO
 @param[in]           <xsmpsLdo>          <peripheral type i.e. PMIC_SMPS,PMIC_LDO>
 @param[in]           <ucregulatorIndex>   <regulator index i.e. 0,1,2 based on SMPS/LDO index>
 @param[out]          <pullvoltageUv>  <Configured voltage in micro Voltage>
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

static pmicErrFlagType_e prvPmicRegulatorGetVoltage(pmicRegulatorType_e xsmpsLdo , uint8 ucregulatorIndex , uint64 *pullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    switch(xsmpsLdo)
    {
        case PMIC_SMPS:
            xErrFlag = prvPmicSmpsReadVoltage(ucregulatorIndex , pullvoltageUv);
        break;

        case PMIC_LDO:
            xErrFlag = prvPmicLdoReadVoltage(ucregulatorIndex , pullvoltageUv);
        break;
        default:
            xErrFlag = PMIC_ERR_MODULE_NOT_SUPPORTED;
        break;

    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicRegulatorSetVoltage
 @Description         prvPmicRegulatorSetVoltage is used to get voltage of SMPS/LDO
 @param[in]           <xsmpsLdo>          <peripheral type i.e. PMIC_SMPS,PMIC_LDO>
 @param[in]           <ucregulatorIndex>   <regulator index i.e. 0,1,2 based on SMPS/LDO index>
 @param[in]           <ullvoltageUv>   <voltage in micro voltage i.e. 600000 for 600mV or 0.6V>
 @param[out]          NA>
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


static pmicErrFlagType_e prvPmicRegulatorSetVoltage(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex, uint64 ullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    switch(xsmpsLdo)
    {
        case PMIC_SMPS:
            xErrFlag = prvPmicSmpsWriteVoltage( ucregulatorIndex , ullvoltageUv);
        break;

        case PMIC_LDO:
            xErrFlag = prvPmicLdoWriteVoltage( ucregulatorIndex , ullvoltageUv);
        break;
        default:
            xErrFlag = PMIC_ERR_MODULE_NOT_SUPPORTED;
        break;

    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicRegulatorGetMode
 @Description         prvPmicRegulatorGetMode is used to get voltage of SMPS/LDO
 @param[in]           <xsmpsLdo>          <peripheral type i.e. PMIC_SMPS,PMIC_LDO>
 @param[in]           <ucregulatorIndex>   <regulator index i.e. 0,1,2 based on SMPS/LDO index>
 @param[out]          <xmodeVal> < mode of SMPS/LDO i.e. PWM or auto mode>
 @param[in, out]      <Ptr>
 @return              <xErrFlag> <Return xErrFlag type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/



static pmicErrFlagType_e prvPmicRegulatorGetMode(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex , pmicRegulatorModeType_e *xmodeVal)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    switch(xsmpsLdo)
    {
        case PMIC_SMPS:
            xErrFlag = xPmicSmpsReadMode(ucregulatorIndex,xmodeVal);
        break;
        case PMIC_LDO:
            *xmodeVal = PMIC_NOT_SUPPORTED_MODE;
        break;
        default:
            xErrFlag = PMIC_ERR_MODULE_NOT_SUPPORTED;
        break;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicRegulatorSetMode
 @Description         prvPmicRegulatorSetMode is used to set mode of SMPS currently mode doesn't support for LDO
 @param[in]           <xsmpsLdo>          <peripheral type i.e. ldo,smps>
 @param[in]           <ucregulatorIndex>   <regulator index i.e. 0,1,2 based on SMPS/LDO index>
 @param[in]           <xmodeVal>          < PMIC_AUTO_MODE, PMIC_FORCED_NPM_MODE >
 @param[out]          NA
 @param[in, out]      <Ptr>
 @return              <xErrFlag> <Return xErrFlag type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


static pmicErrFlagType_e prvPmicRegulatorSetMode(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex, pmicRegulatorModeType_e xmodeVal)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    switch(xsmpsLdo)
    {
        case PMIC_SMPS:
            xErrFlag = xPmicSmpsWriteMode(ucregulatorIndex,xmodeVal);
        break;
        case PMIC_LDO:
            xErrFlag = PMIC_ERR_MODULE_NOT_SUPPORTED;
        break;
        default:
            xErrFlag = PMIC_ERR_MODULE_NOT_SUPPORTED;
        break;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicRegulatorGetEnable
 @Description         prvPmicRegulatorGetEnable is used to get the enable status of LDO/SMPS
 @param[in]           <xsmpsLdo>          <peripheral type i.e. ldo,smps>
 @param[in]           <ucregulatorIndex>   <regulator index i.e. 0,1,2 based on SMPS/LDO index>
 @param[out]          <benableStatus> <PMIC_DISABLE,PMIC_ENABLE>
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



static pmicErrFlagType_e prvPmicRegulatorGetEnable(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex, boolean *benableStatus)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    switch(xsmpsLdo)
    {
        case PMIC_SMPS:
            xErrFlag = prvPmicSmpsReadEnable(ucregulatorIndex,benableStatus);
        break;
        case PMIC_LDO:
            xErrFlag = prvPmicLdoReadEnable(ucregulatorIndex,benableStatus);
        break;
        default:
            xErrFlag = PMIC_ERR_MODULE_NOT_SUPPORTED;
        break;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicRegulatorSetEnable
 @Description         prvPmicRegulatorSetEnable is used to enable or disable any LDO/SMPS
 @param[in]           <xsmpsLdo>          <peripheral type i.e. ldo,smps>
 @param[in]           <ucregulatorIndex>   <regulator index i.e. 0,1,2 based on SMPS/LDO index>
 @param[in]           <benableVal> <PMIC_DISABLE,PMIC_ENABLE>
 @param[out]          NA
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


static pmicErrFlagType_e prvPmicRegulatorSetEnable(pmicRegulatorType_e xsmpsLdo, uint8 ucregulatorIndex , boolean benableVal)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    switch(xsmpsLdo)
    {
        case PMIC_SMPS:
            xErrFlag = prvPmicSmpsWriteEnable(ucregulatorIndex,benableVal);
        break;
        case PMIC_LDO:
            xErrFlag = xPmicLdoWriteEnable(ucregulatorIndex,benableVal);
        break;
        default:
            xErrFlag = PMIC_ERR_MODULE_NOT_SUPPORTED;
        break;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicRegulatorDriverInit
 @Description         prvPmicRegulatorDriverInit is used do the initialization of all LDO's/SMPS's on PMIC
 @param[in]           <xsmpsLdo>          <peripheral type i.e. PMIC_SMPS,PMIC_LDO>
 @param[out]          NA
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

static pmicErrFlagType_e prvPmicRegulatorDriverInit(pmicRegulatorType_e xldoSmps)
{
    uint8 ucregulatorIndex = 0;
    uint64 ullcurrVoltageUv = 0;
    pmicRegulatorModeType_e xregMode = PMIC_AUTO_MODE;
    boolean benableStatus = (boolean) PMIC_ENABLE;
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    pmicRegulatorConfigType* pmicRsrcInfo = NULL;
    uint8 ucmaxPeripheralCount = 0;

    pmicRsrcInfo = (pmicRegulatorConfigType*) prvPmicTargetGetSpecInfo( (pmicConfigType_e) xldoSmps);

    ucmaxPeripheralCount = prvPmicTargetGetCountInfo( (pmicConfigType_e) xldoSmps);


    for(ucregulatorIndex = 0 ; ucregulatorIndex < ucmaxPeripheralCount ; ucregulatorIndex++ )
    {

        /*=================================================================================================================
        **  This code is to read the current voltage and configure the voltage if regulator voltage is not within range  **
        ==================================================================================================================*/
        xErrFlag = prvPmicRegulatorGetVoltage(xldoSmps, ucregulatorIndex, &ullcurrVoltageUv);

        if(PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {

            return xErrFlag;

        }

        if( ( ullcurrVoltageUv > (uint64) (pmicRsrcInfo[ucregulatorIndex].MaxVoltage*1000ULL)) || 
                            ullcurrVoltageUv < (uint64) (pmicRsrcInfo[ucregulatorIndex].MinVoltage*1000ULL) )
        {
            
            DEBUG_LOG(SAIL_ERROR,"Voltage voilation %s Index  %d",pxRegulatorName[xldoSmps],ucregulatorIndex);
            return PMIC_ERR_OUT_OF_BOUNDARY;
            
        }else
        {
            /*
                No action need if curr voltage in limit set in pmic_config.c file
            */  
        }


        /*=================================================================================================================
        **     This code is to read the mode and configure the mode of regulator if mode read is less the minpwr mode    **
        ==================================================================================================================*/

        xErrFlag = prvPmicRegulatorGetMode(xldoSmps, ucregulatorIndex , &xregMode);

        if(PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            
            DEBUG_LOG(SAIL_ERROR,"Mode Read Failed %s Index  %d",pxRegulatorName[xldoSmps],ucregulatorIndex);
            return xErrFlag;
        }


        if( (pmicRegulatorModeType_e) pmicRsrcInfo[ucregulatorIndex].MinPwrMode != PMIC_NOT_SUPPORTED_MODE && 
                xregMode < (pmicRegulatorModeType_e)pmicRsrcInfo[ucregulatorIndex].MinPwrMode)
        {
            xErrFlag = prvPmicRegulatorSetMode(xldoSmps , ucregulatorIndex , (pmicRegulatorModeType_e) pmicRsrcInfo[ucregulatorIndex].MinPwrMode);
            if(PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                DEBUG_LOG(SAIL_ERROR,"Mode Set Failed %s Index  %d",pxRegulatorName[xldoSmps],ucregulatorIndex);
                return xErrFlag;
                
            }
        }
        else
        {
            /*
                No action need if mode read is greater than minpwrmode configure in pmic_config.c file
            */
        }

        /*========================================================================================================================
        ** This code is to read the enable status and enable the regulator if regulator is always on , it is in OFF status     **
        =========================================================================================================================*/

        xErrFlag = prvPmicRegulatorGetEnable(xldoSmps , ucregulatorIndex , &benableStatus);            
        if(PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            DEBUG_LOG(SAIL_ERROR,"Enable Read Failed %s Index  %d",pxRegulatorName[xldoSmps],ucregulatorIndex);
            return xErrFlag;
        }

        if( (uint32) benableStatus < pmicRsrcInfo[ucregulatorIndex].AlwaysOn )
        {
            xErrFlag = prvPmicRegulatorSetEnable(xldoSmps ,ucregulatorIndex, (boolean) pmicRsrcInfo[ucregulatorIndex].AlwaysOn);
            if(PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                DEBUG_LOG(SAIL_ERROR,"Enable Set Failed %s Index  %d",pxRegulatorName[xldoSmps],ucregulatorIndex);
                return xErrFlag;
            }
        }
        else
        {
            /*
                No action need if regulator is already enable at this point of time
            */
        }
    }
    
    return xErrFlag;
}
 
/**********************************************************************************************************
**                                  End of file pmicmodule.c                                        **
**********************************************************************************************************/

