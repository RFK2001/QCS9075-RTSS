/**************************************************************************************************
    Copyright (c) 2023 Qualcomm Technologies, Inc.
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
    File Name          : i2c_el1_test_wrapper.c
    Component Name     : I2C EL1 test
    Description        : I2C EL1 test
    $Header: 
    $DateTime: 
    $Author: 
=================================================================================================*/

#ifndef I2C_EL1_TEST_WRAPPER_H
#define I2C_EL1_TEST_WRAPPER_H

/*==================================================================================================
 *                                  Dependencies
 *================================================================================================*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "tests.h"
#include "i2c_el1.h"
#include "sleep_cmm.h"

TEST_FUNC  void I2cDeInitSleep(const sleepModeType_e SleepState) 
{
    I2cDeInit_Sleep(SleepState);
}


TEST_FUNC i2cEl1Status_e I2cEL1LoadConfigurations(uint8 I2cHardwareID)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2CLoadConfigurations(I2cHardwareID);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2c_InitStatusCheck(uint8 ucHardwareId)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2cInitStatusCheck(ucHardwareId);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2C_InitErrorCheck(uint8 ucHardwareId)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2CInitErrorCheck(ucHardwareId);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2c_ChannelIdcheck(uint8 ChannelId)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2cChannelIdcheck(ChannelId);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2cGetSlaveAddress(uint8 ChannelId)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	static uint8 ucSlaveAddress = 0x0;
	
	Status = xI2c_EL1_GetSlaveAddress(ChannelId,&ucSlaveAddress);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2c_ClockEnable(i2cEl1HwUnitCfgType *I2cHwConfigPtr)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2cClockEnable(I2cHwConfigPtr);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2c_ClockDisable(i2cEl1HwUnitCfgType *I2cHwConfigPtr)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2cClockDisable(I2cHwConfigPtr);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2c_GetCmdOpcode(uint32 Flags, uint32 DataLength)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	i2cCmdOpcode_e OpcodeStatus = CMD_INVALID;
	OpcodeStatus = I2cGetCmdOpcode(Flags ,DataLength);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2cWrite(uint8 ChannelId,uint32 Address,uint8 DataLength,uint8 *I2cDataPtr)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = xI2c_EL1_Write(ChannelId,Address,DataLength,I2cDataPtr);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2cRead(uint8 ChannelId,uint32 Address,uint8 DataLength,uint8 *I2cDataPtr)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = xI2c_EL1_Read(ChannelId,Address,DataLength,I2cDataPtr);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2c_GeniSEIsr(uint32 ucHardwareId)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	I2cGeniSEIsr((void *)ucHardwareId);
	return Status;
}

TEST_FUNC void I2c_Transfer(uint8 ChannelId, uint32 DataLength, uint32 Flag, uint32 *RegMaskPtr)
{
	I2cTransfer(ChannelId,DataLength,Flag,RegMaskPtr);
}

TEST_FUNC i2cEl1Status_e I2c_ReadErrorcheck(const uint8 ChannelId, uint8 *I2cDataPtr)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2cReadErrorcheck(ChannelId,I2cDataPtr);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2c_WriteErrorcheck(const uint8 ChannelId, uint8 *I2cDataPtr)
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2cWriteErrorcheck(ChannelId,I2cDataPtr);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2c_SerialEngineDeInit(i2cEl1HwUnitCfgType *I2cSE0HwUnitCfg,uint32 BaseAdd )
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2cSerialEngineDeInit(I2cSE0HwUnitCfg,BaseAdd);
	return Status;
}

TEST_FUNC i2cEl1Status_e I2c_SerialEngineInit(i2cEl1HwUnitCfgType *I2cSE0HwUnitCfg,uint32 BaseAdd )
{
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	Status = I2cSerialEngineInit(I2cSE0HwUnitCfg,BaseAdd);
	return Status;
}

TEST_FUNC void I2c_FiFoWrite(uint8 I2cHardwareID)
{
	I2cFiFoWrite(I2cHardwareID);
}

TEST_FUNC void I2c_FiFoRead(uint8 I2cHardwareID)
{
	I2cFiFoRead(I2cHardwareID);
}
#endif /* I2C_EL1_TEST_WRAPPER_H */
