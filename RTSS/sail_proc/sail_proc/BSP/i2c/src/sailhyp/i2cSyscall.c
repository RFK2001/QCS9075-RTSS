/*
===============================================================================
*/
/**
    @file  i2cSyscall.c
    @brief contains top level API exposed to EL1 which is calling internal I2C
    driver API

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
#include <stdbool.h>
#include "debug_log.h"
#include "types.h"
#include "i2c.h"
#include "syscall.h"
#include "syscall_pub.h"

/*=================================================================================================
**                                       Local macros, variables and constants                   **
==================================================================================================*/


/*=================================================================================================
**                                   Local function prototypes                                   **
==================================================================================================*/


/*=================================================================================================
**                                   Global function definitions                                 **
==================================================================================================*/

/*=================================================================================================
 @Service name        I2CSysCallDeInit
 @Description         SysCall to call Internal I2C API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 
=================================================================================================*/
uint32 I2CSysCallDeInit(
    uint32 ucHardwareID,
    sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = xI2cDeInit((uint8)ucHardwareID);

    return HVC_SUCCESS;
}


/*=================================================================================================
 @Service name        I2CSysCallInit
 @Description         SysCall to call Internal I2C API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>

=================================================================================================*/
uint32 I2CSysCallInit(
    uint32 ucHardwareID,
    sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = xI2cInit((uint8)ucHardwareID);

    return HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        I2CSysCallPingStatusFromSlave
 @Description         SysCall to call Internal I2C API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

uint32 I2CSysCallPingStatusFromSlave(uint32 ucChannelId,
    uint32 ucHardwareId,
    sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = xI2cPingStatusFromSlave(ucChannelId,ucHardwareId);

    return HVC_SUCCESS;
}


/*=================================================================================================
 @Service name        I2CSysCallRead
 @Description         SysCall to call Internal I2C API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

uint32 I2CSysCallRead(uint32 ucChannelId,
    uint32 ulAddress,
    uint32 ucLength,
    uint8 *pucDataPtr,
    sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = xI2cRead(ucChannelId,ulAddress,ucLength,pucDataPtr);

    return HVC_SUCCESS;
}

/*=================================================================================================
 @Service name        I2CSysCallWrite
 @Description         SysCall to call Internal I2C API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

uint32 I2CSysCallWrite(uint32 ucChannelId,
    uint32 ulAddress,
    uint32 ucLength,
    uint8 *pucDataPtr,
    sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = xI2cWrite(ucChannelId,ulAddress,ucLength,pucDataPtr);

    return HVC_SUCCESS;
}

/* SYS CALL DECLARATIONS */

SAIL_DEFINE_SYSCALL(  I2C_DEINIT,
                      I2C_DEINIT_PARM_ID,
                      0,
                      I2CSysCallDeInit
                    );

SAIL_DEFINE_SYSCALL(  I2C_INIT,
                      I2C_INIT_PARM_ID,
                      0,
                      I2CSysCallInit
                    );

SAIL_DEFINE_SYSCALL(  I2C_READ,
                      I2C_READ_PARM_ID,
                      0,
                      I2CSysCallRead
                    );

SAIL_DEFINE_SYSCALL(  I2C_WRITE,
                      I2C_WRITE_PARM_ID,
                      0,
                      I2CSysCallWrite
                    );


SAIL_DEFINE_SYSCALL(  I2C_PING_STATUS,
                      I2C_PING_STATUS_PARM_ID,
                      0,
                      I2CSysCallPingStatusFromSlave
                    );



/**********************************************************************************************************
**                                  End of file i2cSyscall.c                                             **
**********************************************************************************************************/
