/**************************************************************************************************
    Copyright (c) 2021, 2024 Qualcomm Technologies, Inc.
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
    File Name          : i2c_api.h
    Component Name     : I2c driver header file
    Description        : I2c driver header file
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/i2c/public/i2c.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
=================================================================================================*/

#ifndef I2C_H
#define I2C_H

/*=================================================================================================
**                                     Include files                                             **
=================================================================================================*/
#include "types.h"

/*=================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs         **
=================================================================================================*/
/* Type definition for the i2c status*/
typedef enum
{
    I2C_UNKNOWN_FAILURE = 0,
    I2C_NOT_INITIALIZED,
    I2C_ERROR_NULL_PTR,
    I2C_ERROR_ALREADY_INITIALIZED,
    I2C_ERROR_NOT_INITIALIZED,
    I2C_ERROR_CLOCK_FAILURE,
    I2C_ERROR_INVALID_CHANNEL_ID,
    I2C_ERROR_INVALID_OPCODE,
    I2C_TRANSFER_TRIGGERED,
    I2C_TRANSFER_ONGOING,
    I2C_TRANSFER_SUCCESS,
    I2C_CHANNEL_READY,
    I2C_CHANNEL_INACTIVE,
    I2C_CHANNEL_BUSY,
    I2C_HARDWARE_BUSY,
    I2C_FIFO_READ_ERROR,
    I2C_FIFO_WRITE_ERROR,
    I2C_PROTOCOL_ERROR,
    I2C_SLAVE_NACK_ERROR,
    I2C_HW_NOT_ENABLED,
    I2C_HW_NOT_EXIST,
    I2C_SUCCESS,
    I2C_ARBITRATION_LOST_ERROR
}i2cStatus_e;

/* Type definition for I2C mode*/
typedef enum : uint32
{
    I2C_STANDARD_MODE = 0,
    I2C_FAST_MODE,
    I2C_FASTPLUS_MODE
}i2cMode_e;

typedef enum : uint32
{
    I2C_POLLING_MODE = 0,
    I2C_FIFO_MODE,
    I2C_DMA_MODE
}i2cAccessMode_e;

typedef enum : uint32
{
    I2C_INVALID_BYTE_ADDRESSING = 0,
    I2C_ONE_BYTE_ADDRESSING,
	I2C_TWO_BYTE_ADDRESSING,
	I2C_THREE_BYTE_ADDRESSING,
	I2C_FOUR_BYTE_ADDRESSING
}i2cAddressingModeType;

typedef enum : uint32
{
	I2C_CHANNEL_ID_0 = 0,
	I2C_CHANNEL_ID_1,
	I2C_CHANNEL_ID_2,
	I2C_CHANNEL_ID_3,
	I2C_CHANNEL_ID_4,
	I2C_CHANNEL_ID_5,
	I2C_CHANNEL_ID_6,
	I2C_CHANNEL_ID_7,
	I2C_CHANNEL_ID_8,
	I2C_CHANNEL_ID_9,
	I2C_CHANNEL_ID_10,
	I2C_CHANNEL_ID_11,
	I2C_CHANNEL_ID_12,
	I2C_CHANNEL_ID_13,
	I2C_CHANNEL_ID_14,
	I2C_CHANNEL_ID_15,
} i2cChannelIdType_e;

/* Type definition for the i2cNotificationFuncPtrtype */
typedef void (*i2cNotificationFuncPtr)    (i2cStatus_e Channel_Status);


typedef struct
{
    uint8                   ChannelId;
    uint8                   AssignedHwId;
    uint8                   SlaveAddress;
    uint8                   Delay_PreCmdus;
    i2cAddressingModeType   Addressing_Mode;
    uint8                 	timestamp_en;
    i2cNotificationFuncPtr  NotifFuncPtr;
}i2cChannelCfgType;

typedef struct
{
    uint32           Hw_ChannelId;
    uint32           se_base_addr;
    uint32           Intr_Num;
    uint8 			 NoOfChannels;
    uint8 			 MinChId;
    i2cAccessMode_e  Access_Mode;
    i2cMode_e        Mode;
    const char       *psSE_clock;
    uint32 status;

}i2cHwUnitCfgType;

/*=================================================================================================
**                                    Global function prototypes                                 **
=================================================================================================*/

/*=================================================================================================
 @Service name        xI2cGetSlaveAddress
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

i2cStatus_e xI2cGetSlaveAddress(uint8 ChannelId , uint8 *pSlaveAddress);


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

i2cStatus_e xI2cPingStatusFromSlave( uint8 ucChannelId , uint8 ucHardwareId);

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
i2cStatus_e xI2cInit(const uint8 ucHardwareID);

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
    uint8 ucLength,uint8 *pucDataPtr);

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
    uint8 *pucDataPtr);

/*=================================================================================================
 @Service name        xI2cDeInit
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
i2cStatus_e xI2cDeInit( uint8 ucHardwareId);

/*=================================================================================================
 @Service name        I2cInitStatusCheck
 @Description         This function check if the driver initialization is done
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              Error status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
i2cStatus_e I2cInitStatusCheck(uint8 ucHardwareID);


#endif /* _I2C_H_ */

