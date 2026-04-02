/*
===========================================================================
*/
/**
    @file  psail.c
    @brief This file contains PSAIL driver implementation for MD PMIC monitoring 

*/
/*
    ===========================================================================

    Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
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


#include "types.h"
#include "psailInternal.h"
#include "debug_log.h"
#include "i2c.h"
#include "timetick.h"
#include "psailhwio.h"
#include "chipinfo.h"
#include "chipinfodefs.h"
#include "gpio.h"
#include "hw_io.h"
#include "freertos_init.h"
#include "timetick.h"
#include "sleep_hwio.h"
#include "psail.h"
#include "psail_sail_hwio.h"
#include "msmhwiobase.h"
#include "sail_pwr_ctrl_hwio.h"
#include "isd.h"
#include "logcode.h"
/*=================================================================================================
**                                       Local macros, variables and constants                   **
==================================================================================================*/

#define SLAVE_NOT_PRESENT                           ((uint8)0x0u)
#define SLAVE_PRESENT                               ((uint8)0x1u)
#define MAX_TIMER_GPIO_POLL                         ((uint8)0x15u)
#define IVI_FAULT_COOKIE_SET                        ((uint8)0x40u)
#define MAX_PING_ATTEMPTS_PSAILB                    ((uint8)0xAu)
#define MAXINDEX_OF_FUSAMESSAGE_ERRORDATA           ((uint8)0x10u)
#define GET_STATUS_REGISTER_ADDRESS(x)              ((((uint16)(x)) << 8u) | 0x40u)      
#define GET_THRESHOLD_VIOLATION(x)                  (((x) >> 4u) & 0x3u)      
#define PFLR_COOKIE_TO_SM                           ((uint8)0x80u)

PSAIL_DATA static boolean ucPsailInitStatus = TRUE;
PSAIL_DATA static boolean ucPsailIVIPFLRMode = FALSE;
PSAIL_DATA static boolean psailFaultInfo[psailMAX_CHIP_ON_SOC] = {FALSE,FALSE,FALSE,FALSE};
PSAIL_DATA static uint8 ucPsailSlaveCount = 0x0u;
PSAIL_DATA static psailDeviceInfoType xpsailDeviceInfo[psailMAX_CHIP_ON_SOC] =
{
    {
        PSAIL_B_ID,
        FALSE,
        psailDEFAULT_REVID,
        psailDEFAULT_REVID,
        psailDEFAULT_LOG_EVT_CNT,
        SLAVE_NOT_PRESENT,
    },
    {
        PSAIL_D_ID,
        FALSE,
        psailDEFAULT_REVID,
        psailDEFAULT_REVID,
        psailDEFAULT_LOG_EVT_CNT,
        SLAVE_NOT_PRESENT,
    },
    {
        PSAIL_F_ID,
        FALSE,
        psailDEFAULT_REVID,
        psailDEFAULT_REVID,
        psailDEFAULT_LOG_EVT_CNT,
        SLAVE_NOT_PRESENT,
    },
    {
        PSAIL_H_ID,
        FALSE,
        psailDEFAULT_REVID,
        psailDEFAULT_REVID,
        psailDEFAULT_LOG_EVT_CNT,
        SLAVE_NOT_PRESENT,
    }
};

/*=================================================================================================
**                                   Local function prototypes                                   **
==================================================================================================*/


static PSAILStatusType_e prvPsailReadFaultLog( uint8 ucPsailIndex, uint8 AggrFaultInfo[], PsailFaultLogDataType ucPsailFaultLog[]);
static i2cStatus_e prvPSAILWrite(const uint8 ucChannelId,uint32 ulAddress,uint8 ucLength,uint8 *pucDataPtr);
static i2cStatus_e prvPSAILRead(const uint8 ucChannelId,uint32 ulAddress,uint8 ucLength,uint8 *pucDataPtr);
static void vPSailPinBISTConfig_WeakPullUp_IN(void);
static void vPSailPinBISTConfig_AltFunc_1_IN(void);
static void vPSailPinBISTConfig_StrongPullDown_Out(void);
static void vpsail_MDPShold_Deassert(void);
/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/


/*=================================================================================================
 @Service name        xPSAILCollectFirstFaultLog
 @Description         xPSAILCollectFirstFaultLog to collects and print the Monitor PID and Monitor Index of the First L2 fault that occured. 
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <PSAILStatusType_e> <Return err type based on status of I2C Read>
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


PSAILStatusType_e xPSAILCollectFirstFaultLog(uint8 ucPsailErrorData[MAXINDEX_OF_FUSAMESSAGE_ERRORDATA])
{
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    i2cStatus_e xI2CStatus1 = I2C_SUCCESS;
    PSAILStatusType_e xRetStatus = PSAIL_SUCCESS;
    uint8 ucFaultSt[2u] = {0x0u};
    uint8 ucPsailCount = 0x0u;
    psailChannelType_e ucPsailChId = PSAIL_B_ID;
    uint8 ucIterator = 0x0u;
    uint16 usFaultStatusAddress = 0x0u;
    uint8 ucThresholdData = 0x0u;
    uint32 ulLoggerinfo = 0x0u;

    if ( ucPsailInitStatus == FALSE )
    {
        return PSAIL_SUCCESS;
    }
    for( ucPsailCount = 0U; ucPsailCount < psailMAX_CHIP_ON_SOC; ucPsailCount++)
    {
        if ( SLAVE_PRESENT == xpsailDeviceInfo[ucPsailCount].ucPsailPingStatus && xpsailDeviceInfo[ucPsailCount].bPsailPresent)
        {
            ucPsailChId = xpsailDeviceInfo[ucPsailCount].eChannelId;
            
            /* Read the fault status register 2 and 3*/
            xI2CStatus = prvPSAILRead( (uint8) ucPsailChId, HWIO_PSAIL(FAULT_AGG_STATUS2), 2u, ucFaultSt);
            if(xI2CStatus == I2C_SUCCESS) 
            {
                if(ucFaultSt[0] != 0u)
                {
                    psailFaultInfo[ucPsailCount] = TRUE;
                    usFaultStatusAddress = GET_STATUS_REGISTER_ADDRESS(ucFaultSt[0]);
                    xI2CStatus1 = prvPSAILRead( (uint8) ucPsailChId,usFaultStatusAddress, 1u, &ucThresholdData);
                    DEBUG_LOG(SAIL_DEBUG,"[PSAIL]  ucThresholdData BEFORE WORK = %d AND ADDRESS = 0x%x\n\r",ucThresholdData, usFaultStatusAddress);
                    ucThresholdData = GET_THRESHOLD_VIOLATION(ucThresholdData);
                    DEBUG_LOG(SAIL_DEBUG,"[PSAIL]  ucThresholdData AFTER WORK = %d AND ADDRESS = 0x%x\n\r",ucThresholdData, usFaultStatusAddress);
                    if(ucIterator <= (MAXINDEX_OF_FUSAMESSAGE_ERRORDATA-4u))
                    {
                        ucPsailErrorData[ucIterator++] = ucPsailCount;
                        ucPsailErrorData[ucIterator++] = ucFaultSt[0]; // FIRST_LEVEL2_PID
                        ucPsailErrorData[ucIterator++] = ucFaultSt[1]; // FIRST_LEVEL2_MONITOR_INDEX
                        ucPsailErrorData[ucIterator++] = ucThresholdData;
                        /*
                        *    +---------+-------------+-------------+-------------+-------------+-------------+---------------+----------------+----------------+
                        *    |         |      7      |      6      |      5      |      4      |      3      |       2       |        1       |        0       |
                        *    +---------+-------------+-------------+-------------+-------------+-------------+---------------+----------------+----------------+
                        *    | Data[0] | PFLR_Cookie |   PSAIL_ID  |   PSAIL_ID  |   PSAIL_ID  |   PSAIL_ID  |    PSAIL_ID   |    PSAIL_ID    |    PSAIL_ID    |
                        *    +---------+-------------+-------------+-------------+-------------+-------------+---------------+----------------+----------------+
                        *    | Data[1] | Monitor_PID | Monitor_PID | Monitor_PID | Monitor_PID | Monitor_PID |  Monitor_PID  |   Monitor_PID  |   Monitor_PID  |
                        *    +---------+-------------+-------------+-------------+-------------+-------------+---------------+----------------+----------------+
                        *    | Data[2] |             |             |             |             |             | Monitor_Index |  Monitor_Index |  Monitor_Index |
                        *    +---------+-------------+-------------+-------------+-------------+-------------+---------------+----------------+----------------+
                        *    | Data[3] |             |             |             |             |             |               | Threshold_Data | Threshold_Data |
                        *    +---------+-------------+-------------+-------------+-------------+-------------+---------------+----------------+----------------+          
                        */           
                    }
                    else
                    {
                        DEBUG_LOG(SAIL_DEBUG,"Preventing Buffer Overflow\n\r"); // Added for Code Coverage
                    }
                    
                    DEBUG_LOG(SAIL_WARNING,"PSAIL FAULT INFO --------------->> PSAIL : %d\tMonitor PID : 0x%x\tMonitor Index = 0x%x\tThreshold Violated = %d\r\n",ucPsailCount, ucFaultSt[0],ucFaultSt[1], ucThresholdData);
                    if(ucPsailIVIPFLRMode == TRUE)
                    {
                        ucPsailErrorData[0] |= PFLR_COOKIE_TO_SM;
                    } 
                }
                else
                {
                    DEBUG_LOG(SAIL_DEBUG,"[PSAIL] NO Fault Found\r\n");
                }
                
            }
            else 
            {
                xRetStatus = PSAIL_ERROR;
                DEBUG_LOG(SAIL_INFO,"No comms with PSAIL %d, xI2CStatus = %d\n\r",ucPsailCount, xI2CStatus);
            }
        }
        else
        {
            DEBUG_LOG(SAIL_DEBUG,"[PSAIL %d] Does not exist\r\n",ucPsailCount);
        }
    }

    /* We need to pack the psail fault info to send via bootlogger - We are limited by size and can only send information about 1 fault. */
    /*
    *   +---------------------+---------------------+--------------------+-----------------+-------------------+
    *   | ulLoggerinfo[31-24] | ulLoggerinfo[23-16] | ulLoggerinfo[15-8] | ulLoggerinfo[7] | ulLoggerinfo[6-0] |
    *   +---------------------+---------------------+--------------------+-----------------+-------------------+
    *   | LC_MD_PSAIL_FAULT   | Monitor Index       | Monitor PID        | PFLR Mode       | PSAIL ID          |
    *   +---------------------+---------------------+--------------------+-----------------+-------------------+ 
    */
    ulLoggerinfo =   ((uint32)ucPsailErrorData[0]);
    ulLoggerinfo |=  ((uint32)ucPsailErrorData[1] << 8u);
    ulLoggerinfo |=  ((uint32)ucPsailErrorData[2] << 16u);
    ulLoggerinfo |=  ((uint32)LC_MD_PSAIL_FAULT << 24u);


    /* Use BootLogger to send the info via boot logging as well */
    (void) vLcWriteLogCode(MD_BOOT_MILESTONES, FAIL, &ulLoggerinfo, 1u);
    
    return xRetStatus;
}

/*=================================================================================================
 @Service name        xPSAILDumpSDAMMemory
 @Description         xPSAILDumpSDAMMemory to dump SDAM_MEM041 to SDAM_MEM056 register
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <PSAILStatusType_e> <Return err type based on status of I2C Read>
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


PSAILStatusType_e xPSAILDumpSDAMMemory(void)
{
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    PSAILStatusType_e xRetStatus = PSAIL_SUCCESS;
    uint8 ucPsailCount = 0x0u;
    psailChannelType_e ucPsailChId = PSAIL_B_ID;
    uint8 ucSDAMData[16] = {0u};
    uint8 ucLength = 16u;
    for( ucPsailCount = 0U; ucPsailCount < psailMAX_CHIP_ON_SOC; ucPsailCount++)
    {
        ucPsailChId = xpsailDeviceInfo[ucPsailCount].eChannelId;
        if ( SLAVE_PRESENT == xpsailDeviceInfo[ucPsailCount].ucPsailPingStatus && xpsailDeviceInfo[ucPsailCount].bPsailPresent)
        {
            xI2CStatus = prvPSAILRead((uint8) ucPsailChId, HWIO_PSAIL(TZ_SDAM_PBS_OTP_CRC_STATUS), ucLength, ucSDAMData);
            if( xI2CStatus != I2C_SUCCESS )
            {
                xRetStatus = PSAIL_ERROR;
                break;
            }else
            {
                /* Call the DEBUG_LOG function */
                DEBUG_LOG(SAIL_ERROR," PSAILId : %d \r\n"\
                                     " ucSDAMData : 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\r\n"\
                                     " 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\r\n"\
                                     " 0x%x 0x%x 0x%x 0x%x\r\n",ucPsailCount,ucSDAMData[0],
                                     ucSDAMData[1],ucSDAMData[2],ucSDAMData[3],ucSDAMData[4],ucSDAMData[5],ucSDAMData[6],ucSDAMData[7],
                                    ucSDAMData[8],ucSDAMData[9],ucSDAMData[10],ucSDAMData[11],ucSDAMData[12],ucSDAMData[13],ucSDAMData[14],
                                    ucSDAMData[15]);
            }
        }    
    }

    return xRetStatus;
}

/*=================================================================================================
 @Service name        xPSAILDumpFaultLog
 @Description         xPSAILDumpFaultLog to collect PSAIL dump from PSAIL connected on MD side
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <PSAILStatusType_e> <Return err type based on status of initialization>
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


PSAILStatusType_e xPSAILDumpFaultLog( PsailFaultLogDataType ucPsailFaultLog[] )
{
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    PSAILStatusType_e xRetStatus = PSAIL_SUCCESS;
    uint8 ucFaultSt[5u] = {0x0u};
    uint8 ucPsailCount = 0x0u;
    psailChannelType_e ucPsailChId;

    if ( ucPsailInitStatus == FALSE )
    {
        return PSAIL_SUCCESS;
    }

    for( ucPsailCount = 0U; ucPsailCount < psailMAX_CHIP_ON_SOC; ucPsailCount++)
    {

        if ( SLAVE_PRESENT == xpsailDeviceInfo[ucPsailCount].ucPsailPingStatus && xpsailDeviceInfo[ucPsailCount].bPsailPresent)
        {
            ucPsailFaultLog[ucPsailCount].PsailId = ucPsailCount;
            ucPsailChId = xpsailDeviceInfo[ucPsailCount].eChannelId;

            /* Read the fault status register1*/
            xI2CStatus = prvPSAILRead( (uint8) ucPsailChId, HWIO_PSAIL(FAULT_AGG_STATUS1), 5u, ucFaultSt);
            DEBUG_LOG(SAIL_DEBUG,"PSAIL:%d Fault \n\r",ucPsailCount);
            DEBUG_LOG(SAIL_DEBUG,"ucFaultSt:0x%x,0x%x,0x%x,0x%x,0x%x,xI2CStatus:0x%x\r\n",ucFaultSt[0],
                                        ucFaultSt[1],ucFaultSt[2],ucFaultSt[3],ucFaultSt[4],xI2CStatus);
                
            if( xI2CStatus == I2C_SUCCESS)
            {
                /*Read fault log from PSAIL via I2C*/
                xRetStatus = prvPsailReadFaultLog(ucPsailCount, ucFaultSt,ucPsailFaultLog);
            }
            else
            {
                DEBUG_LOG(SAIL_DEBUG,"PSAIL:%d No Communication\n\r",ucPsailCount);
            }
        }
        else
        {
            DEBUG_LOG(SAIL_DEBUG,"[PSAIL %d] Does not exist\r\n",ucPsailCount);
        }
    }
    return xRetStatus;
}



/*=================================================================================================
 @Service name        xPsailDriverInit
 @Description         Exposing SYScall to call internal PSAIL Driver in EL2. Initilizes the driver by collecting how many Psails are present
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <PSAILStatusType_e> <Return err type based on status of initialization>
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

PSAILStatusType_e xPsailDriverInit(void)
{
    PSAILStatusType_e xRetStatus = PSAIL_SUCCESS;
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    uint8 ucPsailIndex = 0x0u;
    psailChannelType_e ucPsailChId = PSAIL_B_ID;
    uint8 ucRevID[2] = {0x0u};
    uint8 ucHardwareId = 0x0u;
    ChipInfoIdType eChipId = CHIPINFO_ID_UNKNOWN;
    uint8 ucStatus1 = 0x0u;
    uint8 RegValue1 = 0x0u;
    uint8 RegValue2 = 0x0u;
    uint8 EnablePFLRVal = 0x1u;
    
    eChipId = ChipInfo_GetChipId();
    DEBUG_LOG(SAIL_DEBUG,"Chip info ID = 0x%x !!\n\r",eChipId);


    for ( ucPsailIndex = 0x0u ; ucPsailIndex < psailMAX_CHIP_ON_SOC ; ucPsailIndex++ )
    {
        ucPsailChId = xpsailDeviceInfo[ucPsailIndex].eChannelId;

        xI2CStatus = xI2cPingStatusFromSlave((uint8) ucPsailChId , ucHardwareId);

        if( I2C_SUCCESS == xI2CStatus )
        {
            xpsailDeviceInfo[ucPsailIndex].ucPsailPingStatus = SLAVE_PRESENT;

            xI2CStatus = xI2cRead((uint8) ucPsailChId, HWIO_PSAIL(REVID_PERPH_TYPE), 2u, ucRevID);

            DEBUG_LOG(SAIL_DEBUG,"ucRevID : 0x%x 0x%x , xI2CStatus : 0x%x\n\r",ucRevID[0],ucRevID[1],xI2CStatus);
        
            if ( I2C_SUCCESS == xI2CStatus )
            {
                if( ( ucRevID[0] == psailREVID_PERPH_TYPE) && ( ucRevID[1] == psailREVID_PERPH_SUBTYPE))
                {
                    xpsailDeviceInfo[ucPsailIndex].bPsailPresent  = TRUE;
                    xpsailDeviceInfo[ucPsailIndex].ucRevIdType    = ucRevID[0];
                    xpsailDeviceInfo[ucPsailIndex].ucRevIdSubType = ucRevID[1];
                    ucPsailSlaveCount++;
                }
                else
                {
                    DEBUG_LOG(SAIL_DEBUG,"PSAIL:%d No Communication\n\r",ucPsailIndex);
                }
            }
            else 
            {
                xRetStatus = PSAIL_ERROR;
                ucPsailInitStatus = FALSE;
            }
        }
        else
        {
            DEBUG_LOG(SAIL_DEBUG,"[PSAIL %d] Does not exist\r\n",ucPsailIndex);
        }
    }

    //Below Code Enables PFLR and reads Crashcookie.
    if ((eChipId == CHIPINFO_ID_SA_LEMANSAU_IVI) || (eChipId == CHIPINFO_ID_SA_MONACOAU_IVI))
    {
        // Set Kobra_PSAIL_B.BIST_CTL.SCRATCH_2 to 1 - This enables RePON Post Fault
        xI2CStatus = prvPSAILWrite( (uint8) PSAIL_B_ID, HWIO_PSAIL(BIST_CTL_SCRATCH_2), 1u, &EnablePFLRVal);
        // Read SDAM1.MEM_034 in PSAIL_B on PON. - This is the Error Cookie. If it is = 0x40, We are in PFLR Mode
        xI2CStatus = prvPSAILRead( (uint8) PSAIL_B_ID, HWIO_PSAIL(SDAM01_MEM_034), 1u, &RegValue1);
        // Read Pon_PBS_FAULT_REASON2 -> Ensure that Restart PON bit is 0 to confirm PFLR mode.
        xI2CStatus = prvPSAILRead( (uint8) PSAIL_B_ID, HWIO_PSAIL(PON_PBS_FAULT_REASON2), 1u, &RegValue2);

        if( (FLD_GET(RegValue2, PON_PBS_FAULT_REASON2, RESTART_PON) == 0u) && (RegValue1 == IVI_FAULT_COOKIE_SET))
        {
            xRetStatus = PSAIL_IVI_PFLR_Mode;
            ucPsailIVIPFLRMode = TRUE;
        }
        else
        {
            DEBUG_LOG(SAIL_DEBUG,"[PSAIL] Crash Cookie Not Set\n\r",ucPsailIndex);
        }
    }
    else
    {
        // Do Nothing
    }

    return xRetStatus;
}


/*=================================================================================================
 @Service name        xPinBIST
 @Description         Exposing SYScall to call internal PSAIL Driver in EL2
 @param[in]           NA		
 @param[out]          NA
 @param[in, out]      NA
 @return              <PSAILStatusType_e> <Return err type based on status of initialization>
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


PSAILStatusType_e xPinBIST(void)
{
    PSAILStatusType_e xRetStatus = PSAIL_SUCCESS;
    PSAILStatusType_e xRetStatus_Phase2 = PSAIL_SUCCESS;
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    uint8 ucPsailIndex = 0x0u;
    psailChannelType_e ucPsailChId = PSAIL_B_ID;
    uint8 ucRevID[2] = {0x0u};
    uint8 ucStatus1 = 0x0u;
    uint8 ucdetectedPsailCount = 0x0u;
    uint32 ulRegOut = 0x0u;
    uint8 ucGPIOwaitcounter = 0x0u;
    ChipInfoVersionType nVersion = 0;
    uint32 ulRegReadback = 0x0u;
    uint32 ulGpioBaseAddress = SAILSS_TLMM_SAILSS_TLMM_BASE;
    uint32 ulPWRCntrlBaseAddress = SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_BASE;
    ChipInfoFamilyType eFamilyId = CHIPINFO_FAMILY_32BITS;


    eFamilyId = ChipInfo_GetChipFamily();
    nVersion = ChipInfo_GetChipVersion();
    DEBUG_LOG(SAIL_DEBUG,"Chip info ID = 0x%x and Version = 0x%x!!\n\r",eFamilyId,nVersion);

    // Skip PinBIST if we are in IVI PFLR Mode.
    if(ucPsailIVIPFLRMode == TRUE)
    {
        DEBUG_LOG(SAIL_WARNING,"PSAIL PinBIST Skipped - Psail IVI Fault Detected - PFLR Mode!!\n\r",eFamilyId,nVersion);
        return xRetStatus;
    }
    else
    {

    }

    #ifdef lemans

    ucPsailSlaveCount = 0x0;

    for ( ucPsailIndex = 0x0u ; ucPsailIndex < psailMAX_CHIP_ON_SOC ; ucPsailIndex++ )
    {
        if(xpsailDeviceInfo[ucPsailIndex].ucPsailPingStatus == SLAVE_PRESENT)
        {
            ucPsailChId = xpsailDeviceInfo[ucPsailIndex].eChannelId;
            xI2CStatus = xI2cRead( (uint8) ucPsailChId, HWIO_PSAIL(FAULT_AGG_STATUS1), 1u, &ucStatus1);
            DEBUG_LOG(SAIL_DEBUG,"ucStatus1 : 0x%x , xI2CStatus : 0x%x\n\r",ucStatus1,xI2CStatus);
            if( I2C_SUCCESS == xI2CStatus )
            {   
                if((FLD_GET(ucStatus1, FAULT_AGG_STATUS1, EXTERNAL_PSAIL_ERR_N) == 1u) && (FLD_GET(ucStatus1, FAULT_AGG_STATUS1, LOCAL_PSAIL_ERR_N) == 1u))
                {
                    DEBUG_LOG(SAIL_DEBUG,"PSAIL Pin BIST Part 1 :%d Pass \n\r",ucPsailIndex);
                    DEBUG_LOG(SAIL_DEBUG,"PSAIL:%d No Fault Detected at the start of BIST\n\r",ucPsailIndex);
                    ucPsailSlaveCount++;
                    
                }else
                {
                    DEBUG_LOG(SAIL_ERROR,"PSAIL Pin BIST Part 1 :%d FAIL! \n\r",ucPsailIndex);
                    DEBUG_LOG(SAIL_ERROR,"PSAIL Fault Detected After PINBIST on PSAIL:%d !!!! FAULT AGG = %x \n\r",ucPsailIndex,ucStatus1);
                    xRetStatus = PSAIL_ERROR;
                    return xRetStatus;
                }
            }
        }
        else
        {
            DEBUG_LOG(SAIL_DEBUG,"[PSAIL %d] Does not exist\r\n",ucPsailIndex);
        }
    }

    // Change GPIO Config to a strong Pull Down. GPIO direction had to be changed to output to pull down. 
    vPSailPinBISTConfig_StrongPullDown_Out();

    while(GPIO_HIGH == sail_gpio_ReadPin(psailPinGPIONumber) && ucGPIOwaitcounter < MAX_TIMER_GPIO_POLL)
    {
        (void) vFreeRTOSTaskDelay(1);
        ucGPIOwaitcounter++;

    }
    ucGPIOwaitcounter = 0u;

    // Check on SAIL side to confirm that the pin was indeed pulled down.
    if ( GPIO_LOW == sail_gpio_ReadPin(psailPinGPIONumber) )
    {
        DEBUG_LOG(SAIL_DEBUG,"GPIO %d Detected Low after pull down\n\r",psailPinGPIONumber);
    }else
    {
        DEBUG_LOG(SAIL_ERROR,"GPIO %d Detected High after pull down!!\n\r",psailPinGPIONumber);
        xRetStatus = PSAIL_ERROR;
    }

    #endif

    // Check on PSAIL side to confirm that the pin was indeed pulled down.
    for ( ucPsailIndex = 0x0u ; ucPsailIndex < ucPsailSlaveCount ; ucPsailIndex++ )
    {
        ucPsailChId = xpsailDeviceInfo[ucPsailIndex].eChannelId;

        xI2CStatus = xI2cRead( (uint8) ucPsailChId, HWIO_PSAIL(FAULT_AGG_STATUS1), 1u, &ucStatus1);
                
        DEBUG_LOG(SAIL_DEBUG,"ucStatus1 : 0x%x , xI2CStatus : 0x%x\n\r",ucStatus1,xI2CStatus);

        if( I2C_SUCCESS == xI2CStatus )
        {   
            if(FLD_GET(ucStatus1, FAULT_AGG_STATUS1, EXTERNAL_PSAIL_ERR_N) == 0u)
            {
                DEBUG_LOG(SAIL_DEBUG,"PSAIL:%d Detected \n\r",ucPsailIndex);
            }else
            {
                DEBUG_LOG(SAIL_ERROR,"PSAIL Pin BIST Part 2 :%d FAIL! FAULT AGG = %x \n\r",ucPsailIndex,ucStatus1);
                xRetStatus_Phase2 = PSAIL_ERROR;
            }
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"Unable to communicate with PSAIL:%d !!!!\n\r",ucPsailIndex);
            xRetStatus_Phase2 = PSAIL_ERROR;
        }
    }
                    
    vPSailPinBISTConfig_WeakPullUp_IN();
    // Below delay is added to ensure that the pin goes high. Without the delay the pin wouldnt have pulled high yet.
    (void)vFreeRTOSTaskDelay(5);
    while(GPIO_LOW == sail_gpio_ReadPin(psailPinGPIONumber) && ucGPIOwaitcounter < MAX_TIMER_GPIO_POLL)
    {
        (void)vFreeRTOSTaskDelay(1);
        ucGPIOwaitcounter++;

    }
    
    if ( GPIO_HIGH == sail_gpio_ReadPin(psailPinGPIONumber) )
    {
        DEBUG_LOG(SAIL_DEBUG,"GPIO %d Detected High after Weak PU\n\r",psailPinGPIONumber);
    }else
    {
        DEBUG_LOG(SAIL_ERROR,"GPIO %d Detected Low after Weak PU !!\n\r",psailPinGPIONumber);
        xRetStatus = PSAIL_ERROR;  
    }
    

    // Check for PSAIL Error and check for external Psail Error

    for ( ucPsailIndex = 0x0u ; ucPsailIndex < ucPsailSlaveCount ; ucPsailIndex++ )
    {
        ucPsailChId = xpsailDeviceInfo[ucPsailIndex].eChannelId;

        xI2CStatus = xI2cRead( (uint8) ucPsailChId, HWIO_PSAIL(FAULT_AGG_STATUS1), 1u, &ucStatus1);
                
        DEBUG_LOG(SAIL_DEBUG,"ucStatus1 : 0x%x , xI2CStatus : 0x%x\n\r",ucStatus1,xI2CStatus);

        if( I2C_SUCCESS == xI2CStatus )
        {
            if((FLD_GET(ucStatus1, FAULT_AGG_STATUS1, EXTERNAL_PSAIL_ERR_N) == 1u) && (FLD_GET(ucStatus1, FAULT_AGG_STATUS1, LOCAL_PSAIL_ERR_N) == 1u))
            {
                DEBUG_LOG(SAIL_DEBUG,"PSAIL:%d No Fault Detected at the end of BIST\n\r",ucPsailIndex);
                ucdetectedPsailCount++;

            }else
            {
                DEBUG_LOG(SAIL_ERROR,"PSAIL Fault Detected After PINBIST on PSAIL:%d !!!! FAULT AGG = 0x%x \n\r",ucPsailIndex,ucStatus1); 
                xRetStatus = PSAIL_ERROR;               
            }
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"Unable to communicate with PSAIL:%d !!!!\n\r",ucPsailIndex);
            xRetStatus = PSAIL_ERROR;  
        }
    }

    vPSailPinBISTConfig_AltFunc_1_IN();                
    /*
    4 Conditions need to be met before we say Psail PinBIST passed
    1) We were able to communicate & read from every Psail that responded to Pings.
    2) The number of Psails that were able to communicate with SAIL is not equal to 0.
    3) Phase 1 Pin BIST - Where we apply a weak pull up and check for internal errors, passed.
    4) Phase 2 Pin BIST - Where we apply a weak Pull down, passed.
    */
    if ( (ucdetectedPsailCount == ucPsailSlaveCount) && (0x0u != ucdetectedPsailCount) 
                        && (xRetStatus != PSAIL_ERROR) && (xRetStatus_Phase2 != PSAIL_ERROR))
    {
        DEBUG_LOG(SAIL_WARNING,"PSAIL PinBIST Pass!!\n\r");
    }else
    {
        DEBUG_LOG(SAIL_ERROR,"PSAIL PinBIST Fail!! -- Unable to verify Electrical Integrity of the Psail_err_n pin\n\r");
        xRetStatus = PSAIL_ERROR;
    }

    //  if Lemans V1 or Monaco V1/V2 : Set 10th bit of TLMM_WEST_MPM_WAKEUP_INT_EN_1;  
/*========================================================================================================

+--------------+--------------------------------------------+--------------------------------------------+
| Lemans V1/V2 |                 Init Value                 |                RunTime Value               |
+--------------+------------------------+-------------------+------------------------+-------------------+
|              | TLMM_Wakeup (10th bit) | GPIO Alt Function | TLMM_Wakeup (10th bit) | GPIO Alt Function |
+--------------+------------------------+-------------------+------------------------+-------------------+
|      V1      |            0           |         0         |            1           |                   |
+--------------+------------------------+-------------------+------------------------+-------------------+
|      V2      |            1           |         1         |            1           |         1         |
+--------------+------------------------+-------------------+------------------------+-------------------+

=========================================================================================================*/

    if( ((eFamilyId == CHIPINFO_FAMILY_LEMANSAU) && (nVersion == 0x20000u)) ||
                (eFamilyId == CHIPINFO_FAMILY_MONACOAU)) // in case of monaco or LeMans V2 TLMM_WEST_MPM_WAKEUP_INT_EN_1 write is not required
    {

    }
    else
    {
        REG_OUTF(ulGpioBaseAddress,SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1,GPIO_63,0x1u);// Setting 10th so that SAIL doesn't get reset on occurrence of PSAIL_ERROR
        DEBUG_LOG(SAIL_INFO,"Wrote TLMM Register!!\n\r");
    }


    return xRetStatus;
}


/*=================================================================================================
 @Service name        vPSAILClearError
 @Description         Clears the PSAIL external interrupt in PSAIL_ERR_N_LATCH_CLEAR register
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

void vPSAILClearError( void)
{
    psailChannelType_e ucPsailChId;
    uint8 ucClearErr = 0x1U;
    uint8 ucPsailCount = 0x0u;
    i2cStatus_e xI2CStatus = I2C_SUCCESS;

    for( ucPsailCount = 0U; ucPsailCount < psailMAX_CHIP_ON_SOC; ucPsailCount++)
    {
        ucPsailChId = xpsailDeviceInfo[ucPsailCount].eChannelId;
        if( (xpsailDeviceInfo[ucPsailCount].bPsailPresent) && (SLAVE_PRESENT == xpsailDeviceInfo[ucPsailCount].ucPsailPingStatus))
        {
            if( TRUE ==  psailFaultInfo[ucPsailCount]) // In Case of Any Fault Detected Clear Error
            {
                xI2CStatus = prvPSAILWrite((uint8) ucPsailChId, HWIO_PSAIL(FAULT_AGG_PSAIL_ERR_N_LATCH_CLEAR), 1, &ucClearErr);
            }
            else
            {
                DEBUG_LOG(SAIL_DEBUG,"[PSAIL %d] No Fault\r\n",ucPsailCount);
            }
        }
        else
        {
            DEBUG_LOG(SAIL_DEBUG,"[PSAIL %d] Does not exist\r\n",ucPsailCount);
        }
    }

    if(ucPsailIVIPFLRMode == TRUE)
    {
        vpsail_MDPShold_Deassert();
    }
    else
    {
        // Added for MISRA
    }
}

/*=================================================================================================
**                                        Local function definitions                             **
=================================================================================================*/



/*=================================================================================================
 @Service name        prvPsailReadFaultLog
 @Description         Read fault log from all PSAIL chips and store it in a structure
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              PSAILStatusType_e - status of execution
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/
static PSAILStatusType_e prvPsailReadFaultLog( uint8 ucPsailIndex, uint8 AggrFaultInfo[], PsailFaultLogDataType ucPsailFaultLog[])
{
    PSAILStatusType_e eRetStatus = PSAIL_SUCCESS;
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    uint8 ucBufferData[psailNUM_OF_MEM_INTF_RD_DATA_REG] = {0};
    uint8 ucWriteCapInc = 0x1U;
    uint8 ucNumLogEvents = 0x0U;
    psailChannelType_e ucPsailChId;
    uint8 ucLvl2FaultCnt = 0x0u;
    uint8 ucEvtCnt = 0u;
    uint16 usFaultStatusAddress = 0x0u;
    uint8 ucThresholdData = 0x0u;

    ucPsailChId = xpsailDeviceInfo[ucPsailIndex].eChannelId;
    ucNumLogEvents = AggrFaultInfo[4];
    DEBUG_LOG(SAIL_DEBUG,"ucNumLogEvents : 0x%x , xI2CStatus : 0x%x \r\n",ucNumLogEvents,xI2CStatus);
    
    for( ucEvtCnt = 0U; ucEvtCnt < ucNumLogEvents; ucEvtCnt++)
    {

        xI2CStatus = prvPSAILWrite( (uint8) ucPsailChId, HWIO_PSAIL(FAULT_AGG_CAPTURE_INC), 1u, &ucWriteCapInc);

        if( xI2CStatus == I2C_SUCCESS)
        {

            xI2CStatus = prvPSAILRead( (uint8) ucPsailChId, HWIO_PSAIL(FAULT_AGG_MEM_INTF_RD_DATA0),
                                psailNUM_OF_MEM_INTF_RD_DATA_REG, ucBufferData);

            psailFaultInfo[ucPsailIndex] = TRUE; // Mark here true for particular PSAIL if there is any data present in buffer

            DEBUG_LOG(SAIL_DEBUG,"ucBufferData : 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x xI2CStatus : 0x%x \r\n",
                    ucBufferData[0],ucBufferData[1],ucBufferData[2],ucBufferData[3],
                    ucBufferData[4],ucBufferData[5],xI2CStatus);

            if ( ucLvl2FaultCnt >= MaxFaultDataPerPsail )
            {
                ucLvl2FaultCnt = 0u;
            }
            else
            {
                DEBUG_LOG(SAIL_DEBUG,"[PSAIL] Preventing Buffer Overflow\r\n");
            }

            if( xI2CStatus == I2C_SUCCESS)
            {
                if( ((ucBufferData[5]>>2u)&0x3u) == 0x2u ) // Filter Lvl2 Fault
                {
                    ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucTimeStamp = ucBufferData[3];
                    ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucTimeStamp = ((ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucTimeStamp)<<8u)|ucBufferData[2];
                    ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucTimeStamp = ((ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucTimeStamp)<<8u)|ucBufferData[1];
                    ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucTimeStamp = ((ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucTimeStamp)<<8u)|ucBufferData[0];
                    ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucMonitorIndex  =  ( ucBufferData [5] >> 4u) & 0x7U;
                    ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucNewError     =  ( ucBufferData[5] >> 2u) & 0x3U;
                    ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucOldError     =  ucBufferData[5] & 0x3U;
                    ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucMonitorPID    =  ucBufferData[4];

                    // Collect and store Threshold Violation data for each PID. 
                    usFaultStatusAddress = GET_STATUS_REGISTER_ADDRESS(ucBufferData[4]);
                    xI2CStatus = prvPSAILRead( (uint8) ucPsailChId,usFaultStatusAddress, 1u, &ucThresholdData);
                    ucPsailFaultLog[ucPsailIndex].Lvl2ErrorInfo[ucLvl2FaultCnt].ucThresholdViolation = GET_THRESHOLD_VIOLATION(ucThresholdData);
                    if( xI2CStatus != I2C_SUCCESS)
                    {
                        DEBUG_LOG(SAIL_INFO,"[PSAIL] No Threshold DATA \r\n",ucNumLogEvents,xI2CStatus);
                    }
                    else
                    {
                        DEBUG_LOG(SAIL_DEBUG,"[PSAIL %d] Threshhold Data Collection successful exist\r\n",ucPsailIndex);
                    }
                    ucLvl2FaultCnt++;
                }
                else
                {
                    DEBUG_LOG(SAIL_DEBUG,"[PSAIL] Level1 Fault not stored.\r\n");
                }
            }else
            {
                eRetStatus =PSAIL_LOG_DUMP_ERROR;
            }
        }else
        {
            eRetStatus =PSAIL_LOG_DUMP_ERROR;
        }
    }

    ucPsailFaultLog[ucPsailIndex].ucLvl2FaultCount  = ucLvl2FaultCnt;

    return eRetStatus;
}

/*=================================================================================================
 @Service name        prvPSAILWrite
 @Description         This API shall write the given data into the I2C bus
 @param[in]           ucChannelId - Channel ID
                      ulAddress   - Address of the memory to be read
                      ucLength    - Number of data to write.
                      pucDataPtr  - Pointer to the data t be write
 @param[out]          NA
 @param[in, out]      NA
 @return              Write status
 @Pre                 xI2cInit shall be invoked before calling this function
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant for different Hardware serial engine. Non Reentrant for same
                      hardware serial engine.
 @Note                -
=================================================================================================*/

static i2cStatus_e prvPSAILWrite(const uint8 ucChannelId,
    uint32 ulAddress,
    uint8 ucLength,
    uint8 *pucDataPtr)
{
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    xI2CStatus = xI2cWrite(ucChannelId,ulAddress,ucLength,pucDataPtr);
    return xI2CStatus;
}

/*=================================================================================================
 @Service name        prvPSAILRead
 @Description         This API shall read the data from the I2c bus
 @param[in]           ucChannelId     - Channel ID
                      ulAddress       - Address of the memory to be read
                      ucLength        - Number of data to read.
 @param[out]          pucDataPtr      - Pointer to the read data to be stored
 @param[in, out]      NA
 @return              Write status
 @Pre                 xI2cInit shall be invoked before calling this function
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant for different Hardware serial engine. Non Reentrant for same
                      hardware serial engine.
 @Note                -
=================================================================================================*/

static i2cStatus_e prvPSAILRead(const uint8 ucChannelId,
    uint32 ulAddress,
    uint8 ucLength,
    uint8 *pucDataPtr)
{
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    xI2CStatus = xI2cRead(ucChannelId,ulAddress,ucLength,pucDataPtr);
    return xI2CStatus;
}

/*===========================================================================================================================================================================================================================================
 @Service name        vPSailPinBISTConfig_WeakPullUp_IN
 @Description         Function Configured GPIO related register.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ============================================================================================================================================================================================================================================*/

static void vPSailPinBISTConfig_WeakPullUp_IN(void)
{
  GPIOConfigType cfg = {
                            .func=   0,
                            .dir =  (uint32) GPIO_IN,
                            .pull =  (uint32) GPIO_PU,
                            .drive = (uint32) GPIO_2MA
                        };
  (void) sail_gpio_config_pin(psailPinGPIONumber, cfg);
}

/*===========================================================================================================================================================================================================================================
 @Service name        vPSailPinBISTConfig_AltFunc_1_IN
 @Description         Function Configured GPIO related register.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ============================================================================================================================================================================================================================================*/
static void vPSailPinBISTConfig_AltFunc_1_IN(void)
{
  GPIOConfigType cfg = {
                            .func=   1,
                            .dir =  (uint32) GPIO_IN,
                            .pull = (uint32) GPIO_PU,
                            .drive = (uint32) GPIO_2MA
                        };
  (void) sail_gpio_config_pin(psailPinGPIONumber, cfg);
}

/*===================================================================================================================================================================================================================================================
 @Service name        vPSailPinBISTConfig_StrongPullDown_Out
 @Description         Function Configured GPIO related register.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ====================================================================================================================================================================================================================================================*/
static void vPSailPinBISTConfig_StrongPullDown_Out(void)
{
  GPIOConfigType cfg = {
                            .func =   0,
                            .dir =  (uint32) GPIO_OUT,
                            .pull = (uint32) GPIO_PD,
                            .drive = (uint32) GPIO_16MA
                        };
  (void) sail_gpio_config_pin(psailPinGPIONumber, cfg);
}



/*===================================================================================================================================================================================================================================================
 @Service name        xPsailBPingTillReady
 @Description         Once an Error is detected, Ping Psail B until it is ready for communicaiton or fails to respond 10 times.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <PSAILStatusType_e> <Return err type based on status of initialization>
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ====================================================================================================================================================================================================================================================*/
PSAILStatusType_e xPsailBPingTillReady(void)
{
    psailChannelType_e ucPsailChId = PSAIL_B_ID;
    uint8 PsailBPingAttempt = 0u;
    i2cStatus_e xI2CStatus = I2C_NOT_INITIALIZED;
    uint8 ucHardwareId = 0x0u;
    PSAILStatusType_e xRetStatus = PSAIL_SUCCESS;
    uint8 ucPsailCount = 0u;

    for( ucPsailCount = 0U; ucPsailCount < psailMAX_CHIP_ON_SOC; ucPsailCount++)
    {
        ucPsailChId = xpsailDeviceInfo[ucPsailCount].eChannelId;
        PsailBPingAttempt = 0u;
        xI2CStatus = I2C_NOT_INITIALIZED;
        if ( SLAVE_PRESENT == xpsailDeviceInfo[ucPsailCount].ucPsailPingStatus )
        {
		    while( (xI2CStatus != I2C_SUCCESS) && (PsailBPingAttempt < MAX_PING_ATTEMPTS_PSAILB))
		    {
		        xI2CStatus = xI2cPingStatusFromSlave((uint8) ucPsailChId , ucHardwareId);
		        PsailBPingAttempt++;
		    }
		    if(xI2CStatus != I2C_SUCCESS)
		    {
		        xRetStatus = PSAIL_ERROR;
                DEBUG_LOG(SAIL_INFO,"[PSAIL]PSAIL Ping Attempt Fail on Psail %d, attempt no %d and xI2CStatus = %d!!\r\n", ucPsailCount, PsailBPingAttempt, xI2CStatus);
		    }
            else
            {
                DEBUG_LOG(SAIL_DEBUG,"[PSAIL]PSAIL Ping Attempt Pass on Psail %d, attempt no %d and xI2CStatus = %d!!\r\n", ucPsailCount, PsailBPingAttempt, xI2CStatus);
            }
        }
        else
        {
            DEBUG_LOG(SAIL_DEBUG,"[PSAIL %d] Does not exist\r\n",ucPsailCount);
        }
    }

    return xRetStatus;
    
}



/*===================================================================================================================================================================================================================================================
 @Service name        vpsail_MDPShold_Deassert
 @Description         Deassert MD_Pshold. 
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ====================================================================================================================================================================================================================================================*/

static void vpsail_MDPShold_Deassert(void)
{
    /* 
    * Add a delay here - In case SSM is not in DebugMode, we want to print logs on UART. 
    * Give about a 100ms to ensure that Logs are printed on UART console. 
    * In DebugMode, SSM triggers WDG in 40ms, which is not enough to print logs on console.
    * WDG Bite in turn, deasserts MD_Pshold
    */
    
    (void)vFreeRTOSTaskDelay(1000);
    (void)eISDSailToMDPSHoldDeAssert();
}

/**********************************************************************************************************
**                                  End of file psail.c                                                  **
**********************************************************************************************************/
