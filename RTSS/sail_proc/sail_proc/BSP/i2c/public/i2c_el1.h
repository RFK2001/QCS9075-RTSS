/**************************************************************************************************
    Copyright (c) Qualcomm Technologies, Inc.
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
**************************************************************************************************/

/*=================================================================================================
    File Name          : i2c_el1.h
    Component Name     : I2c driver header file
    Description        : I2c driver header file
    $Header: 
    $DateTime: 
    $Author: 
=================================================================================================*/

#ifndef I2C_EL1_H
#define I2C_EL1_H

/*=================================================================================================
**                                     Include files                                             **
=================================================================================================*/
#include "types.h"


/*=================================================================================================
**                                         defines and macros                                    **
=================================================================================================*/

// Macro I2C_TEST_ENABLE is for enabling the I2C EL1 Code Coverage Tests
//#define I2C_TEST_ENABLE


/*=================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs         **
=================================================================================================*/
/* Type definition for the i2c status*/
typedef enum
{
    I2C_EL1_UNKNOWN_FAILURE = 0,
    I2C_EL1_NOT_INITIALIZED,
    I2C_EL1_ERROR_NULL_PTR,
    I2C_EL1_ERROR_ALREADY_INITIALIZED,
    I2C_EL1_ERROR_NOT_INITIALIZED,
    I2C_EL1_ERROR_CLOCK_FAILURE,
    I2C_EL1_ERROR_INVALID_CHANNEL_ID,
    I2C_EL1_ERROR_INVALID_OPCODE,
    I2C_EL1_ERROR_INTERRUPT_INSTALL,
    I2C_EL1_ERROR_INTERRUPT_UNINSTALL,
    I2C_EL1_TRANSFER_TRIGGERED,
    I2C_EL1_TRANSFER_ONGOING,
    I2C_EL1_TRANSFER_SUCCESS,
    I2C_EL1_CHANNEL_READY,
    I2C_EL1_CHANNEL_INACTIVE,
    I2C_EL1_CHANNEL_BUSY,
    I2C_EL1_HARDWARE_BUSY,
    I2C_EL1_FIFO_READ_ERROR,
    I2C_EL1_FIFO_WRITE_ERROR,
    I2C_EL1_PROTOCOL_ERROR,
    I2C_EL1_SLAVE_NACK_ERROR,
    I2C_EL1_HW_NOT_ENABLED,
    I2C_EL1_HW_NOT_EXIST,
    I2C_EL1_SUCCESS,
    I2C_EL1_ERROR_TIMEOUT,
    I2C_EL1_ERROR_INVALID_HW_ID,
    I2C_EL1_ARBITRATION_LOST_ERROR,
    I2C_EL1_ERROR_TX_SBE,
    I2C_EL1_ERROR_RX_SBE,
    I2C_EL1_ERROR_M_CMD_FAILURE,
    I2C_EL1_ERROR_M_CMD_ILLEGAL,
    I2C_EL1_ERROR_M_CMD_OVERRUN,
    I2C_EL1_ERROR_S_CMD_FAILURE,
    I2C_EL1_ERROR_S_CMD_ILLEGAL,
    I2C_EL1_ERROR_S_CMD_OVERRUN,
    I2C_EL1_ERROR_TX_FIFO_RD_ERR,
    I2C_EL1_ERROR_TX_FIFO_WR_ERR,
    I2C_EL1_ERROR_RX_FIFO_RD_ERR,
    I2C_EL1_ERROR_RX_FIFO_WR_ERR
}i2cEl1Status_e;

/* Type definition for I2C mode*/
typedef enum : uint32
{
    I2C_EL1_STANDARD_MODE = 0,
    I2C_EL1_FAST_MODE,
    I2C_EL1_FASTPLUS_MODE
}i2cEl1Mode_e;

typedef enum : uint32
{
    I2C_EL1_POLLING_MODE = 0,
    I2C_EL1_FIFO_MODE,
    I2C_EL1_DMA_MODE
}i2cEl1AccessMode_e;

typedef enum : uint32
{
    I2C_EL1_INVALID_BYTE_ADDRESSING = 0,
    I2C_EL1_ONE_BYTE_ADDRESSING,
    I2C_EL1_TWO_BYTE_ADDRESSING,
    I2C_EL1_THREE_BYTE_ADDRESSING,
    I2C_EL1_FOUR_BYTE_ADDRESSING
}i2cEl1AddressingModeType;


/* Type definition for the i2cEl1NotificationFuncPtr */
typedef void (*i2cEl1NotificationFuncPtr)    (i2cEl1Status_e Channel_Status);


typedef struct
{
    uint8                      AssignedHwId;
    uint8                      SlaveAddress;
    uint8                      Delay_PreCmdus;
    i2cEl1AddressingModeType   Addressing_Mode;
    uint8                      timestamp_en;
    i2cEl1NotificationFuncPtr  NotifFuncPtr;
}i2cEl1ChannelCfgType;

typedef struct
{
    uint32              Hw_ChannelId;
    uint32              se_base_addr;
    uint32              Intr_Num;
    uint8               NoOfChannels;
    uint8               MinChannelId;
    uint8               MaxChannelId;
    i2cEl1AccessMode_e  Access_Mode;
    i2cEl1Mode_e        Mode;
    const char          *psSE_clock;
    uint32              status;

}i2cEl1HwUnitCfgType;

typedef struct
{

    const i2cEl1HwUnitCfgType   *HwUnitCfgPtr;
    const i2cEl1ChannelCfgType  *ChCfgPtr;
}i2cEl1CoreConfigType;

extern const i2cEl1CoreConfigType  I2cCoreConfig[];
/*=================================================================================================
**                                    Global function prototypes                                 **
=================================================================================================*/

/*=================================================================================================
 @Service name        xI2cGetSlaveAddressEl1
 @Description         This API is to get Slave ID address for corresponding Channel ID
 @param[in]           ChannelId - Channel ID for every Page
 @param[out]          pSlaveAddress - Slave Address of every Page
 @param[in, out]      NA
 @return              return status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/

i2cEl1Status_e xI2c_EL1_GetSlaveAddress(uint8 ChannelId , uint8 *pSlaveAddress);


/*=================================================================================================
 @Service name        xI2cPingStatusFromSlaveEl1
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

i2cEl1Status_e xI2c_EL1_PingStatusFromSlave( uint8 ucChannelId , uint8 ucHardwareId);

/*=================================================================================================
 @Service name        xI2cInitEl1
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
i2cEl1Status_e xI2c_EL1_Init(const uint8 I2cHardwareID);

/*=================================================================================================
 @Service name        xI2cWriteEl1
 @Description         This API shall write the given data into the I2C bus
 @param[in]           ucChannelId - Channel ID
                      ulAddress   - Address of the memory to be read
                      ucLength    - Number of data to write.
                      pucDataPtr  - Pointer to the data t be write
 @param[out]          NA
 @param[in, out]      NA
 @return              Write status
 @Pre                 xI2cInitEl1 shall be invoked before calling this function
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant for different Hardware serial engine. Non Reentrant for same
                      hardware serial engine.
 @Note                -
=================================================================================================*/
i2cEl1Status_e xI2c_EL1_Write(
    const uint8 ucChannelId,
    uint32 ulAddress,
    uint8 ucLength,uint8 *pucDataPtr);

/*=================================================================================================
 @Service name        xI2cReadEl1
 @Description         This API shall read the data from the I2c bus
 @param[in]           ucChannelId     - Channel ID
                      ulAddress       - Address of the memory to be read
                      ucLength        - Number of data to read.
 @param[out]          pucDataPtr      - Pointer to the read data to be stored
 @param[in, out]      NA
 @return              Write status
 @Pre                 xI2cInitEl1 shall be invoked before calling this function
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant for different Hardware serial engine. Non Reentrant for same
                      hardware serial engine.
 @Note                -
=================================================================================================*/
i2cEl1Status_e xI2c_EL1_Read(
    const uint8 ucChannelId,
    uint32 ulAddress,
    uint8 ucLength,
    uint8 *pucDataPtr);

/*=================================================================================================
 @Service name        xI2cDeInitEl1
 @Description         This API shall De-initializes the serial engines assigned for the I2C driver
                      and also it will de-initialize the clock for the SE and disable the SDL and SCL
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
i2cEl1Status_e xI2c_EL1_DeInit( uint8 ucHardwareId);
#endif /* I2C_EL1_H */

/**************************************************************************************************
**                                  End of file i2c_el1.h                                        **
**************************************************************************************************/

