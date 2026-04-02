/*
===========================================================================
*/
/**
    @file  pmici2.c
    @brief contains functions which communicate directly with I2c bus

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

#include "pmichwio.h"
#include "pmicapi.h"
#include "types.h"
#include "i2c.h"
#include "pmicconfig.h"
#include "pmici2c.h"
#include "crc.h"
#include "crcconfig.h"
#include "busywait.h"
#include "debug_log.h"


/*=========================================================================================================
**                                        Static variables and constants                                 **
=========================================================================================================*/

static boolean ucpmicI2cInitialized = FALSE;


static uint8 ucPingStatusOfPmicChannel[MAX_PMIC_PAGE_ID] = {0x0u};

static pmicDeviceInfoType xpmicDeviceInfoArr[PMIC_MAX_NUM_PMICS] = {0x0u};


/*=========================================================================================================
**                                        Local function prototypes                                      **
=========================================================================================================*/


/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#define TRIGGER_I2C_1                      0x2u
#define MAX_RETRY                          0x5u

/*=================================================================================================
**                                        Global function definitions                             **
=================================================================================================*/



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

boolean bSailPmicPresent (void)
{
    uint8 ucpmicIndex = 0x0u;
    boolean ucPmicPresent = FALSE;

    if ( PMIC_CONFIG_DEV_REV == xpmicDeviceInfoArr[ucpmicIndex].deviceId )
    {
        ucPmicPresent = TRUE;
    }

    return ucPmicPresent;
}


/*=========================================================================================================
 @Service name        vPmicDeInit
 @Description         vPmicDeInit is used to clear ucpmicI2cInitialized flag so that on hardreset
                      I2c validation can be done in prvPmicVersionDetect function
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

void vPmicDeInit(void)
{
    uint8 ucpmicIndex = 0x0u;
    uint8 xpageId = 0x0u;
    
    ucpmicI2cInitialized = FALSE;
    xpmicDeviceInfoArr[ucpmicIndex].deviceId = 0;
    xpmicDeviceInfoArr[ucpmicIndex].nvmCode1 = 0;
    xpmicDeviceInfoArr[ucpmicIndex].nvmCode2 = 0;
    xpmicDeviceInfoArr[ucpmicIndex].customerNvmId = 0;

    for ( xpageId = (uint8) PAGE_ID_0 ; xpageId < (uint8) MAX_PMIC_PAGE_ID ; xpageId++ )
    {
        ucPingStatusOfPmicChannel[xpageId] = SLAVE_NOT_PRESENT;
    }
}

/*=================================================================================================
**                                        Local function definitions                             **
=================================================================================================*/

/*=========================================================================================================
 @Service name        prvPmicCRCEnable
 @Description         prvPmicCRCEnable is used to enable I2C CRC
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              pmicErrFlagType_e based on I2C status received
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


pmicErrFlagType_e prvPmicCRCEnable( void )
{
    pmicErrFlagType_e     xErrFlag = PMIC_ERR_FLAG_SUCCESS ;
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    uint8 uci2cTriggerData = TRIGGER_I2C_1;

    if(TRUE == ucpmicI2cInitialized)
    {
        xI2CStatus = xI2cWrite((uint8) PAGE_ID_0, HWIO_PMIC(FSM_I2C_TRIGGERS),1u,&uci2cTriggerData);
        if( I2C_SUCCESS ==  xI2CStatus)
        {
            busywait(2000); // 2msec of delay is needed to complete FSM to enable CRC
        }else
        {
            xErrFlag = PMIC_ERR_CRC_TRIGGER_FAILED;
        }
    }else
    {
        xErrFlag = PMIC_ERR_I2C_FAILED;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicVersionDetect
 @Description         This function will detect important config parameter like nvm_id , device id and customer_id
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              pmicErrFlagType_e based on I2C status received
 @Pre                 I2C init should be successfull
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

pmicErrFlagType_e prvPmicVersionDetect(void)
{
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    pmicErrFlagType_e     xErrFlag = PMIC_ERR_FLAG_SUCCESS ;
    uint8 ucpmicIndex = 0x0;
    uint8 ucreadData[3] = {0};
    uint8 uccustomerNvmId = 0x0;

    if( TRUE == ucpmicI2cInitialized )
    {
        return xErrFlag;
    }
    
    /*
    I2C code to detect version of TI PMIC
    */

    xI2CStatus = xI2cRead((uint8) PAGE_ID_0, HWIO_PMIC(DEV_REV),1u,&ucreadData[0]);
    if( I2C_SUCCESS !=  xI2CStatus)
    {
        return PMIC_ERR_VERSION_INIT_FAILED;
    }

    xI2CStatus = xI2cRead((uint8) PAGE_ID_0, HWIO_PMIC(NVM_CODE_1),1u,&ucreadData[1]);
    if( I2C_SUCCESS !=  xI2CStatus)
    {
        return PMIC_ERR_VERSION_INIT_FAILED;
    }

    xI2CStatus = xI2cRead((uint8) PAGE_ID_0, HWIO_PMIC(NVM_CODE_2),1u,&ucreadData[2]);
    if( I2C_SUCCESS !=  xI2CStatus)
    {
        return PMIC_ERR_VERSION_INIT_FAILED;
    }

    xI2CStatus = xI2cRead((uint8)PAGE_ID_0, HWIO_PMIC(CUSTOMER_NVM_ID_REG),1u,&uccustomerNvmId);
    if( I2C_SUCCESS !=  xI2CStatus)
    {
        return PMIC_ERR_VERSION_INIT_FAILED;
    }
    


    xpmicDeviceInfoArr[ucpmicIndex].deviceId = ucreadData[0];
    xpmicDeviceInfoArr[ucpmicIndex].nvmCode1 = ucreadData[1];
    xpmicDeviceInfoArr[ucpmicIndex].nvmCode2 = ucreadData[2];
    xpmicDeviceInfoArr[ucpmicIndex].customerNvmId = uccustomerNvmId;

    if( xpmicDeviceInfoArr[ucpmicIndex].deviceId == PMIC_CONFIG_DEV_REV ) // More condition can be added here
    {
        DEBUG_LOG(SAIL_WARNING,"PMICFW Version 0x%x, DeviceId 0x%x, nvmCode1 0x%x, nvmCode2 0x%x \n\r",xpmicDeviceInfoArr[ucpmicIndex].customerNvmId,
                    xpmicDeviceInfoArr[ucpmicIndex].deviceId,xpmicDeviceInfoArr[ucpmicIndex].nvmCode1,xpmicDeviceInfoArr[ucpmicIndex].nvmCode2);
        ucpmicI2cInitialized = TRUE;
    }else
    {
        xErrFlag = PMIC_ERR_VERSION_INIT_FAILED;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        vSetPmicPingStatus
 @Description         This function is used get ping status of PMIC I2C channel
 @param[in]           xpageId < PAGE_ID_0,PAGE_ID_1,PAGE_ID_4>
 @param[out]          NA
 @param[in, out]      NA
 @return              void 
 @Pre                 I2C init should be successfull
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/
void vSetPmicPingStatus(pmicPageId_e xpageId)
{
    if ( xpageId >= MAX_PMIC_PAGE_ID )
    {
        return;
    }
     
    ucPingStatusOfPmicChannel[xpageId] = SLAVE_PRESENT;
}

/*=========================================================================================================
 @Service name        ucGetPmicPingStatus
 @Description         This function is used get ping status of PMIC I2C channel
 @param[in]           xpageId < PAGE_ID_0,PAGE_ID_1,PAGE_ID_4>
 @param[out]          NA
 @param[in, out]      NA
 @return              uint8 
                      < 0 -> if slave didn't responded during PMIC Init>
                      < 1 -> if slave responded during PMIC Init>
 @Pre                 I2C init should be successfull
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

uint8 ucGetPmicPingStatus(pmicPageId_e xpageId)
{
    if ( xpageId >= MAX_PMIC_PAGE_ID )
    {
        return SLAVE_NOT_PRESENT;
    }

    return ucPingStatusOfPmicChannel[xpageId];
}

/*=========================================================================================================
 @Service name        prvGetSAILPMICInfo
 @Description         prvGetSAILPMICInfo is used to get PMIC HW specific id
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      <Ptr>
 @return              PMIC HW Specific id
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


uint8 prvGetSAILPMICInfo( pmicInfo_e xPmicInfoType )
{
    uint8 ucpmicIndex = 0x0u;
    uint8 ucReturnData = 0x0u;

    switch(xPmicInfoType)
    {
        case  DEVICE_ID:
            ucReturnData = xpmicDeviceInfoArr[ucpmicIndex].deviceId;
        break;
        case  NVMCODE1:
            ucReturnData = xpmicDeviceInfoArr[ucpmicIndex].nvmCode1;
        break;
        case  NVMCODE2:
            ucReturnData = xpmicDeviceInfoArr[ucpmicIndex].nvmCode2;
        break;
        case  CUSTOMER_NVMID:
            ucReturnData = xpmicDeviceInfoArr[ucpmicIndex].customerNvmId;
        break;
        default:
            // Do nothing
        break;
    }

    return ucReturnData;

}


/*=========================================================================================================
 @Service name        prvPmicCommReadByte
 @Description         This function is used to read PMIC Addr using I2C bus
 @param[in]           <xpageId> <PAGE_ID_0 , PAGE_ID_1 ... PAGE_ID_4>
 @param[in]           <uladdr> <Address which user wants to read>
 @param[out]          <pcdata> <return value present on uladdr of PMIC>
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

pmicErrFlagType_e prvPmicCommReadByte(pmicPageId_e xpageId, uint32 uladdr , uint8 *pcdata)
{
    i2cStatus_e           xStatus = I2C_SUCCESS;
    pmicErrFlagType_e     xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8                 pxdata[2] = {0x0 , 0x0};
    uint8                 pxCRCData[4] = { 0x0 , 0x0 , 0x0 , 0x0 };
    boolean               bStatus = FALSE;
    uint8                 ucSlaveAddress = 0x0;
    uint8                 ucReTryCount = 0u;


    if ( SLAVE_NOT_PRESENT == ucGetPmicPingStatus(xpageId) )
    {
        return PMIC_ERR_FLAG_SUCCESS;
    }
    
    if(TRUE == ucpmicI2cInitialized) /*check here If i2c is initialize or not*/
    {
        do
        {

            xStatus = xI2cRead((uint8)xpageId,uladdr,2u,pxdata); // here I2c driver is reading two value in seq if CRC is enabled 
                                                        //pxdata[0]  = value present in PMIC at address = uladdr
                                                        //pxdata[1]  = CRC data calculated by PMIC
            if ( I2C_SUCCESS !=  xStatus)
            {
                xErrFlag = PMIC_ERR_I2C_FAILED;
                goto PmicEnd;
            }
            xStatus = xI2cGetSlaveAddress((uint8)xpageId,&ucSlaveAddress);
            if ( I2C_SUCCESS !=  xStatus)
            {
                xErrFlag =  PMIC_ERR_I2C_FAILED;
                goto PmicEnd;
            }

            pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
            pxCRCData[1] = (uint8) uladdr;  // Address
            pxCRCData[2] = (ucSlaveAddress<<1u)|(0x1u); // ( SLAVE ID Left shift by one and 0bit is set for write)
            pxCRCData[3] = pxdata[0]; // Value being read from PMIC
            if ( CRC_SUCCESS != xCrc8Verify( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 4 , pxdata[1] ) )
            {
                xErrFlag = PMIC_CRC_ERROR;
                goto PmicEnd;
            }
            PmicEnd:
                ucReTryCount++;

        }while( ucReTryCount < MAX_RETRY && xErrFlag != PMIC_ERR_FLAG_SUCCESS);

        *pcdata = pxdata[0];
    }
    else
    {
      xErrFlag = PMIC_ERR_I2C_FAILED;
    }

    return xErrFlag;
}


/*=========================================================================================================
 @Service name        prvPmicCommReadByteMask
 @Description         prvPmicCommReadByteMask is used to read particular ucmask of pcdata present 
                      on PMIC Addr using I2C bus
 @param[in]           <xpageId> <PAGE_ID_0 , PAGE_ID_1 ... PAGE_ID_4>
 @param[in]           <uladdr> <PMIC Addr need to be read out>
 @param[in]           <ucmask> <ucmask value on which pcdata need to be read out>
 @param[out]          <pcdata> <return value present on uladdr of PMIC>
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

pmicErrFlagType_e prvPmicCommReadByteMask(pmicPageId_e xpageId,uint32 uladdr, uint8 ucmask, uint8* pcdata)
{
    pmicErrFlagType_e     xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    xErrFlag = prvPmicCommReadByte(xpageId,uladdr,pcdata);

    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag ) 
    { 
        xErrFlag = PMIC_ERR_I2C_FAILED; 
    }
    else 
    { 
        *pcdata = *pcdata & ucmask;
    }
    
    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicCommWriteByte
 @Description         prvPmicCommWriteByte is used to write on PMIC Addr using I2C bus
 @param[in]           <xpageId> <PAGE_ID_0 , PAGE_ID_1 ... PAGE_ID_4>
 @param[in]           <uladdr> <Address which user wants to read>
 @param[in]           <pcdata> <value need to be written on uladdr of PMIC>
 @param[in, out]      <Ptr>
 @return              <xErrFlag> <Return xErrFlagtype based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/



pmicErrFlagType_e prvPmicCommWriteByte(pmicPageId_e xpageId,uint32 uladdr ,uint8 ucdata)
{
    uint8                 pxdata[2] = {0x0 , 0x0};
    uint8                 pxCRCData[3] = { 0x0 , 0x0 , 0x0 };
    i2cStatus_e           xStatus = I2C_SUCCESS;
    pmicErrFlagType_e     xErrFlag = PMIC_ERR_FLAG_SUCCESS ;
    boolean               bStatus = FALSE;
    uint8                 ucSlaveAddress = 0x0;
    uint8                 ucReTryCount = 0u;


    if ( SLAVE_NOT_PRESENT == ucGetPmicPingStatus(xpageId) )
    {
        return PMIC_ERR_FLAG_SUCCESS;
    }
    
    if(TRUE == ucpmicI2cInitialized)
    {
        do
        {
            xStatus = xI2cGetSlaveAddress((uint8)xpageId,&ucSlaveAddress);
            if (I2C_SUCCESS != xStatus)
            {
                xErrFlag = PMIC_ERR_I2C_FAILED;
                goto PmicEnd;
            }
            pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
            pxCRCData[1] = (uint8) uladdr;  // Address
            pxCRCData[2] = ucdata; // Value Need to be written in PMIC
            if ( CRC_SUCCESS != xCrc8Generate( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 3 , &pxdata[1] ) )
            {
               xErrFlag = PMIC_CRC_ERROR;
               goto PmicEnd;
            }
            pxdata[0] = ucdata;
            xStatus = xI2cWrite((uint8)xpageId,uladdr,2u,pxdata);
            if ( I2C_SUCCESS != xStatus ) 
            { 
                xErrFlag = PMIC_ERR_I2C_FAILED;
                goto PmicEnd;
            }
            PmicEnd:
                ucReTryCount++;
        }while( ucReTryCount < MAX_RETRY && xErrFlag != PMIC_ERR_FLAG_SUCCESS);
    }
    else
    {
        xErrFlag = PMIC_ERR_I2C_FAILED;
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicCommWriteByteMask
 @Description         prvPmicCommWriteByteMask is used to write on particular ucmask of PMIC Addr using I2C bus
 @param[in]           <xpageId> <PAGE_ID_0 , PAGE_ID_1 ... PAGE_ID_4>
 @param[in]           <uladdr> <Address which user wants to read>
 @param[in]           <ucmask> <ucmask value on which pcdata need to be read out>
 @param[in]           <value> <value need to be written on uladdr of PMIC>
 @param[in, out]      <Ptr>
 @return              <xErrFlag> <Return xErrFlagtype based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

pmicErrFlagType_e prvPmicCommWriteByteMask(pmicPageId_e xpageId,uint32 uladdr,uint8 ucmask, uint8 ucvalue)
{
    i2cStatus_e           xStatus = I2C_SUCCESS;
    pmicErrFlagType_e     xErrFlag = PMIC_ERR_FLAG_SUCCESS ;
    uint8                 ucdata = 0;

    /*Read the ucdata from the I2c and leave all the bits other than the ucmask to the previous state*/
    xErrFlag = prvPmicCommReadByte(xpageId,uladdr,&ucdata);

    if ( xErrFlag == PMIC_ERR_FLAG_SUCCESS )
    {
        ucdata &= (~ucmask); 
        ucdata |= (ucvalue & ucmask);
        xErrFlag = prvPmicCommWriteByte(xpageId,uladdr,ucdata);
    }else
    {
        xErrFlag = PMIC_ERR_I2C_FAILED;
    }

    return xErrFlag;
}
 
/**********************************************************************************************************
**                                  End of file pmici2c.c                                           **
**********************************************************************************************************/

