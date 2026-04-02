/*
===========================================================================
*/
/**
    @file  i2cclient.c
    @brief This file contains API exposed to EL1 which calls HVC calls to EL2

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


/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

#include "i2c.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "syscall_svc.h"
#include "err_fatal.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/


/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/
/*=================================================================================================
 @Service name        xI2cDeInit
 @Description         This API shall De-initializes the serial engines assigned for the I2C driver
                      and also it will de-initialize the clock for the SE and enable the SDL and SCL
                      Pins
 @param[in]           ConfigPtr - Configuration pointer
 @param[out]          NA
 @param[in, out]      NA
 @return              I2C driver De-initialization status
 @Pre                 I2C driver shall be initialized before calling this function
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/

i2cStatus_e xI2cDeInit( uint8 ucHardwareId)
{
    i2cStatus_e xErrorValue = I2C_SUCCESS;

    uint32_t hvcId     = I2C_DEINIT;
    uint32_t paramId   = I2C_DEINIT_PARM_ID;
    uint32_t arg1      = (uint32_t)ucHardwareId;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
                err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrorValue = paramId;

    return xErrorValue;
}


/*=================================================================================================
 @Service name        xI2cInit
 @Description         This API shall initializes the serial engines assigned for the I2C driver
                      and also it will initialize the clock for the SE and enable the SDL and SCL
                      Pins
 @param[in]           ConfigPtr - Configuration pointer
 @param[out]          NA
 @param[in, out]      NA
 @return              I2C driver Initialization status
 @Pre                 Clock driver shall be initialized before calling this function
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
i2cStatus_e xI2cInit(
    const uint8 ucHardwareId)
{
    i2cStatus_e xErrorValue = I2C_SUCCESS;

    uint32_t hvcId     = I2C_INIT;
    uint32_t paramId   = I2C_INIT_PARM_ID;
    uint32_t arg1      = (uint32_t)ucHardwareId ;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
                err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrorValue = paramId;

    return xErrorValue;
}


/*=================================================================================================
 @Service name        xI2cPingStatusFromSlave
 @Description         This function is used to get ping from slave connected to I2C bus
 @param[in]           ucChannelId -> Channel Id of Slave connected
                      ucHardwareId -> HW channel of particular SE
 @param[out]          NA
 @param[in, out]      NA
 @return              Execution status
 @Pre                 Interrupt configuration has be done in the Initialization function
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          -
 @Reentrancy          -
 @Note                -
=================================================================================================*/


i2cStatus_e xI2cPingStatusFromSlave( uint8 ucChannelId , uint8 ucHardwareId)
{
    i2cStatus_e xErrorValue = I2C_SUCCESS;

    uint32_t hvcId     = I2C_PING_STATUS;
    uint32_t paramId   = I2C_PING_STATUS_PARM_ID;
    uint32_t arg1      = (uint32_t)ucChannelId;
    uint32_t arg2      = (uint32_t)ucHardwareId;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
                err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrorValue = paramId;

    return xErrorValue;
}



/*=================================================================================================
 @Service name        xI2cWrite
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

i2cStatus_e xI2cWrite(
    const uint8 ucChannelId,
    uint32 ulAddress,
    uint8 ucLength,
    uint8 *pucDataPtr)
{
    i2cStatus_e xErrorValue = I2C_SUCCESS;

    uint32_t hvcId     = I2C_WRITE;
    uint32_t paramId   = I2C_WRITE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucChannelId;
    uint32_t arg2      = (uint32_t)ulAddress;
    uint32_t arg3      = (uint32_t)ucLength;;
    uint32_t arg4      = (uint32_t)pucDataPtr;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
                err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrorValue = paramId;

    return xErrorValue;
}



/*=================================================================================================
 @Service name        xI2cRead
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

i2cStatus_e xI2cRead(
    const uint8 ucChannelId,
    uint32 ulAddress,
    uint8 ucLength,
    uint8 *pucDataPtr)
{
    i2cStatus_e xErrorValue = I2C_SUCCESS;

    uint32_t hvcId     = I2C_READ;
    uint32_t paramId   = I2C_READ_PARM_ID;
    uint32_t arg1      = (uint32_t)ucChannelId;
    uint32_t arg2      = (uint32_t)ulAddress;
    uint32_t arg3      = (uint32_t)ucLength;;
    uint32_t arg4      = (uint32_t)pucDataPtr;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
                err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    xErrorValue = paramId;

    return xErrorValue;
}
 
/**********************************************************************************************************
**                                  End of file i2cclient.c                                              **
**********************************************************************************************************/

