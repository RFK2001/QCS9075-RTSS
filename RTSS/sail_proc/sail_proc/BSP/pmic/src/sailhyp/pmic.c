/*
===========================================================================
*/
/**
    @file  pmic.c
    @brief Contain All top level function of PMIC driver

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

#include <stdio.h>
#include "pmicapi.h"
#include "types.h"
#include "pmicinternal.h"
#include "pmictarget.h"
#include "Crashdbg_api.h"
#include "pmicconfig.h"
#include "boot_logger.h"
#include "debug_log.h"
#include "i2c.h"
#include "pmici2c.h"
#include "chipinfo.h"
#include "chipinfodefs.h"

/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/

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

pmicErrFlagType_e xPmicInit(void)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint64 ullStartTimePmic = 0x0;
    uint8 xpageId = 0x0u;
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    uint8 ucHardwareId = 0x0;
    uint8 ucPmicSlaveCount = 0x0;
    ChipInfoIdType xChipID = CHIPINFO_ID_32BITS;
    char const *PmicStartStr = "Pmic Init Start on core";
    char const *PmicEndStr = "Pmic Init Delta on core";

    xChipID = ChipInfo_GetChipId();

    /* 
     * In the starting of PMIC Init check for ping from all the slave connected
     * if count of PMIC Slave connected to I2C Bus is matching with expected number
     * of slave
     */
    for ( xpageId = (uint8) PAGE_ID_0 ; xpageId <= (uint8) PAGE_ID_4 ; xpageId++ )
    {
        xI2CStatus = xI2cPingStatusFromSlave(xpageId , ucHardwareId);
        if( I2C_SUCCESS == xI2CStatus )
        {
            vSetPmicPingStatus((pmicPageId_e)xpageId);
            ucPmicSlaveCount++;
        }
    }

        // In case of IVI and IOT Chipset Skip the PMIC Driver
        // For IVI board if no slaves are connected, skip pmic initialization and return with success
        if(ucPmicSlaveCount == SLAVE_NOT_PRESENT)
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC Driver Skipped, ChipId = %d\n\r", xChipID);
            return PMIC_ERR_FLAG_SUCCESS;
        }
        // For IVI board if any slave is present, wrong PMIC DIP switch configurations for IVI board

        // For ADAS board if PMIC slave detected on I2C bus is less than expected then return Error
        if( ucPmicSlaveCount < (uint8 ) MAX_PMIC_PAGE_ID) 
        {
            DEBUG_LOG(SAIL_ERROR,"Partial PMIC Slave Detected on I2C Bus\n\r");
            DEBUG_LOG(SAIL_ERROR,"Slave Ping Status:[%d] [%d] [%d]\n\r",ucGetPmicPingStatus(PAGE_ID_0),
                                    ucGetPmicPingStatus(PAGE_ID_1),ucGetPmicPingStatus(PAGE_ID_4));
            return PMIC_INIT_ERROR;
    }

    ullStartTimePmic = uBootLogger_LogStartTime(PmicStartStr, 0);

    if ( PMIC_ERR_FLAG_SUCCESS != prvPmicVersionDetect() )
    {
        DEBUG_LOG(SAIL_ERROR,"prvPmicVersionDetect Failed\n\r");
        xErrFlag =  PMIC_ERR_VERSION_INIT_FAILED;
        goto pmicEnd;
    }

    // In Case of PASS2 dont do Full Init Just check for version 
    if( Crashdbg_GetSailResetCtrlFSMState() >= SP_PRE_DDR_INIT_ST )
    {
        return PMIC_ERR_FLAG_SUCCESS;
    }


        /*
        * LeMans :- 
        *  There are some PMIC HW Shippped by TI which contains NVMCode2 = 0x3 but customer NVM ID 
        *  is 0x1 so PMIC FW upgrade is not support on this device ( due to mismatch in static 
        *  CRC Config) . Latest RTL revision NVMCode2 = 0x3 already have PMIC NVM 0x2 .So , PMIC FW 
        *  upgrade is not required if NVMCode2 = 0x3. By default for all internal NVM Release NVMCODE2
        *  is 0x1.
        *
        * Monaco :- 
        *  There are some PMIC HW Shippped by TI which contains NVMCode2 = 0x1 but customer NVM ID 
        *  is 0x0 so PMIC FW upgrade is not support on this device ( due to mismatch in static 
        *  CRC Config) . Latest RTL revision NVMCode2 = 0x1 already have PMIC NVM 0x6 .So , PMIC FW 
        *  upgrade is not required if NVMCode2 = 0x1.By default for all internal NVM Release NVMCODE2
        *  is 0x0.
        */
        /* PMIC FW Version check for MCU supported */
    #if 0
        if ( prvGetSAILPMICInfo(NVMCODE2) == PMIC_NVM_CODE2_FW_SUPPORTED )
        {
            if( prvGetSAILPMICInfo(CUSTOMER_NVMID) !=  PMIC_CONFIG_CUSTOMER_NVM_ID) 
            {
                DEBUG_LOG(SAIL_WARNING,"Current PMIC FW is not as Expected\n\r");
                DEBUG_LOG(SAIL_WARNING,"Use Test App to update PMIC FW to %d \n\r",PMIC_CONFIG_CUSTOMER_NVM_ID);
                DEBUG_LOG(SAIL_WARNING,"Cmd : pmic nvm %d \n\r",PMIC_CONFIG_CUSTOMER_NVM_ID);
            }        
        }
    #endif		


    if ( PMIC_ERR_FLAG_SUCCESS !=  prvPmicPreTargetInit())
    {
         DEBUG_LOG(SAIL_ERROR,"prvPmicPreTargetInit Failed\n\r");
         xErrFlag =  PMIC_ERR_PRE_INIT_FAILED;
         goto pmicEnd;
    }
      
    if( PMIC_ERR_FLAG_SUCCESS != prvPmicDriverInit() )
    {
        DEBUG_LOG(SAIL_ERROR,"prvPmicDriverInit Failed\n\r");
        xErrFlag =  PMIC_ERR_DRIVER_INIT_FAILED;
        goto pmicEnd;
    }

    if(PMIC_ERR_FLAG_SUCCESS !=  prvPmicPostTargetInit())
    {
        DEBUG_LOG(SAIL_ERROR,"prvPmicPostTargetInit Failed\n\r");
        xErrFlag = PMIC_ERR_POST_INIT_FAILED;
        goto pmicEnd;
    }

    (void) vBootLogger_LogDeltaTime(ullStartTimePmic,PmicEndStr, 0);

    pmicEnd:
    return xErrFlag;

}
 
/**********************************************************************************************************
**                                  End of file pmic.c                                                **
**********************************************************************************************************/
