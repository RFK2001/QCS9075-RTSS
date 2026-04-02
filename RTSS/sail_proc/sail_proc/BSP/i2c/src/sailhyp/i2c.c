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
    File Name          : i2c.c
    Component Name     : I2C Device driver
    Description        : I2C Device driver Initial version
    $Header: //components/rel/bsp.sail/1.0/i2c/src/i2c.c#11 $
    $DateTime: 2022/08/01 23:52:27 $
    $Author: pwbldsvc $
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "hw_io.h"
#include "gpio.h"
#include "cache_ops.h"
#include "debug_log.h"
#include "busywait.h"
#include "Clock.h"
#include "interrupts.h"
#include "common_functions.h"
#include "i2c.h"
#include "qup_common_hwio.h"
#include <libfdt.h>
#include "fdt_utils.h"
#include "sleepEl2.h"
#include "debug_log.h"
#include "Crashdbg_api.h"
#include "sailbsp_mutex.h"

/*=================================================================================================
**                                        Local defines and macros                               **
=================================================================================================*/
#define i2cNUMBER_OF_I2C_PINS               2U
#define i2cPOLLINTERVAL_US                  5U
#define i2cBYTES_PER_FIFO_REG               4U
#define i2cBITS_PER_BYTE                    8U
#define i2cIRQ_CLEAR_MASK                   0xFFFFFFFFU
#define i2cNUM_MODE                         3U
/* TX and RX packing configuration. Fixed 4x8.*/
#define i2cTX_PACKING_CFG0_VAL              0x7F8FEU
#define i2cTX_PACKING_CFG1_VAL              0xFFEFEU
#define i2cRX_PACKING_CFG0_VAL              0x7F8FEU
#define i2cRX_PACKING_CFG1_VAL              0xFFEFEU
/* FLAGs for transfer descriptor. */
/* Specifies that the transfer begins with a START - S */
#define i2cFLAG_START                       0x1U
/** Specifies that the transfer ends with a STOP - P */
#define i2cFLAG_STOP                        0x2U
/*flag to indicate a WRITE transfer */
#define i2cFLAG_WRITE                       0x4U
/*flag to indicate a READ transfer */
#define i2cFLAG_READ                        0x8U
/* Flag to indicate the capture of timestamp for START or STOP. When set with
   the START bit, START timestamp is recorded. When set with STOP bit, STOP
   timestamp is recorded. When set with both START and STOP, only START
   timestamp is recorded.*/
#define i2cFLAG_TIMESTAMP                   0x10U
/*
    Delay of 1mSec while getting status from connected Slave
*/
#define i2cMaxPollingTime                   0xAu

#define HWIO_GENI_M_CMD0_I2C_SLAVE_ADDRESS_BMSK                               0xFE00
#define HWIO_GENI_M_CMD0_I2C_SLAVE_ADDRESS_SHFT                                  0x9

#define HWIO_GENI_M_CMD0_I2C_PRE_CMD_DELAY_BMSK                           0x00000001
#define HWIO_GENI_M_CMD0_I2C_PRE_CMD_DELAY_SHFT                                  0x0

#define HWIO_GENI_M_CMD0_I2C_TIMESTAMP_BEFORE_BMSK                        0x00000002
#define HWIO_GENI_M_CMD0_I2C_TIMESTAMP_BEFORE_SHFT                               0x1

#define HWIO_GENI_M_CMD0_I2C_STRETCH_BMSK                                 0x00000004
#define HWIO_GENI_M_CMD0_I2C_STRETCH_SHFT                                        0x2

#define HWIO_GENI_M_CMD0_I2C_TIMESTAMP_AFTER_BMSK                         0x00000008
#define HWIO_GENI_M_CMD0_I2C_TIMESTAMP_AFTER_SHFT                                0x3

#define HWIO_GENI_M_CMD0_POST_CMD_DELAY_BMSK                              0x00000010
#define HWIO_GENI_M_CMD0_POST_CMD_DELAY_SHFT                                     0x4

#define HWIO_GENI_M_CMD0_I2C_IGNORE_ADDR_NACK_BMSK                        0x00000040
#define HWIO_GENI_M_CMD0_I2C_IGNORE_ADDR_NACK_SHFT                               0x6

#define HWIO_GENI_M_CMD0_I2C_READ_FINISH_WITH_ACK_BMSK                    0x00000080
#define HWIO_GENI_M_CMD0_I2C_READ_FINISH_WITH_ACK_SHFT                           0x7

#define HWIO_GENI_M_CMD0_I2C_BYPASS_ADDRESS_PHASE_BMSK                    0x00000100
#define HWIO_GENI_M_CMD0_I2C_BYPASS_ADDRESS_PHASE_SHFT                           0x8


#define  I2C_CRITCAL_SECTION_START()                            mutex_lock(&stI2cCoreLock)
#define  I2C_CRITCAL_SECTION_END()                              mutex_unlock(&stI2cCoreLock);

/*=================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs         **
=================================================================================================*/


/* Driver status type definition*/
typedef enum
{
    I2C_UNINITIALIZED = 0,
    I2C_INITIALIZED
}i2cInitStatusType_e;

/* Type definition for command Opcode*/
typedef enum
{
    CMD_INVALID                 = 0,
    CMD_I2C_WRITE               = 1,
    CMD_I2C_READ                = 2,
    CMD_I2C_WRITE_THEN_READ     = 3,
    CMD_I2C_ADDRESS_ONLY        = 4,
    CMD_I2C_BUS_CLEAR           = 6,
    CMD_I2C_STOP_ON_BUS         = 7,
}i2cCmdOpcode_e;

/* Clock Configuration type definition*/
typedef struct
{
    uint32  ulSEClockFrequencyHz;
    uint32  ulBusSpeedKhz;
    uint8   ucClkDiv;
    uint8   ucTCycle;
    uint8   ucTHigh;
    uint8   ucTLow;
}i2cClockConfigType;

typedef enum
{
    I2C_PING_COMMAND = 0,
	I2C_WRITE_COMMAND,
	I2C_READ_COMMAND
}i2cCommandReq_e;

typedef struct
{
    i2cStatus_e      xChannelStatus;
    i2cCommandReq_e  xActiveCommand;
    uint32           ucBufferLength;
    uint32           ulAddress;
    uint32           ucTransferredLength;
    uint8            *pucDataPtr;
    uint8            ucActiveChannel;
}i2cChannelDataType;

/*=================================================================================================
**                                        Global variables and constants                         **
=================================================================================================*/

static i2cInitStatusType_e xI2cInitStatus[MAX_NO_OF_SERIAL_ENGINE];
static i2cHwUnitCfgType xI2CHwConfig[MAX_NO_OF_SERIAL_ENGINE];
static i2cChannelCfgType xI2CChannelCfg[MAX_NO_OF_I2C_CHANNELS];
static i2cChannelDataType xI2cSEChannelData[MAX_NO_OF_SERIAL_ENGINE];
static uint8 *I2c_TstSendDataDMA;
static uint32 ulQupCommonBase;
mutex_t stI2cCoreLock;

/* Clock settings for the various I2C modes.
    Index 0 - Standard mode
    Index 1 - Fast mode
    Index 2 - Fast Plus Mode  */
static const i2cClockConfigType xI2cClkCfg[i2cNUM_MODE] =
{
    // src-freq, speed, div, cycle, high, low
    { 19200000, 100,  7, 26, 10, 11 },
    { 19200000, 400,  2, 24, 5,  12 },
    { 19200000, 1000, 1, 18, 3,  9  }
};

static uint8 *I2c_TstSendDataDMA = (uint8 *) 0x01F00000;
static uint32 ulI2cSleepHandle;
static GPIOConfigType I2cResetStatePinCfg[MAX_NO_OF_SERIAL_ENGINE][i2cNUMBER_OF_I2C_PINS] = {0x0u};

/*=================================================================================================
**                                        Local function prototypes                              **
=================================================================================================*/
static i2cCmdOpcode_e prvI2cGetCmdOpcode (uint32 ulFlags, uint32 ulLength);
static i2cStatus_e prvI2cSerialEngineInit(const i2cHwUnitCfgType *pxHwconfig,
                                                                       uint32 ulQupCommonAddr);
static ClockResult prvI2cClockEnable (const i2cHwUnitCfgType *pxHwconfig);
static i2cStatus_e prvI2cChannelIdcheck(const uint8 ucChannelId);
static i2cStatus_e prvI2cPtrCheck(uint8 *pucDataPtr);
static i2cStatus_e prvI2cWriteErrorcheck(const uint8 ucChannelId, uint8 *pucDataPtr);
static i2cStatus_e prvI2cReadErrorcheck(const uint8 ucChannelId, uint8 *pucDataPtr);
static void prvI2cTransfer(uint8 ucChannelId, uint32 ulLength, uint32 ulFlag, uint32 *pulRegMask);
static void prvI2cFiFoRead(uint8 ucHardwareId);
static void prvI2cFiFoWrite(uint8 ucHardwareId);
static void prvI2cSerialEngineDeInit(const i2cHwUnitCfgType *pxHwconfig, uint32 ulQupCommonAddr);
static void prvI2cReadGeniError(i2cStatus_e *pxErrorValue, uint8 ucChannelId);
static i2cStatus_e prvI2CInitErrorCheck(uint8 ucHardwareId);
static i2cStatus_e prvI2CLoadDeviceTreeSettings(uint8 ucHardwareID);
static ClockResult prvI2cClockDisable (const i2cHwUnitCfgType *pxHwconfig);
static void prvI2cDeInit_Sleep( const sleepModeType_e eState );
static void prvI2cPinCtlReset(uint8 I2cHardwareID);
/*=================================================================================================
**                                        Interrupt Handler                                      **
=================================================================================================*/

//_Interrupt
static enum handler_return xI2cGeniSEIsr(void *arg);


/*=================================================================================================
**                                        Global functions definition                            **
=================================================================================================*/
extern CRASHDBG_RST_CTRL_FSM_ST Crashdbg_GetSailResetCtrlFSMState(void);
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
    const uint8 ucHardwareID)
{
	i2cStatus_e xStatus ;
    uint8 ucCount;

    xStatus =  prvI2CInitErrorCheck(ucHardwareID);
    if( I2C_SUCCESS == xStatus)
    {
    	xStatus = prvI2CLoadDeviceTreeSettings(ucHardwareID);
    	if(xStatus == I2C_SUCCESS)
    	{
    		if ( CLOCK_SUCCESS == prvI2cClockEnable(&xI2CHwConfig[ucHardwareID]))
    		{
    			/* Initialize the Serial Engine*/
    			xStatus = prvI2cSerialEngineInit(&xI2CHwConfig[ucHardwareID],
        			ulQupCommonBase);
    			if(xStatus == I2C_SUCCESS)
    			{
    				xI2cSEChannelData[ucHardwareID].xChannelStatus  =  I2C_CHANNEL_READY;
    				xI2cInitStatus[ucHardwareID] = I2C_INITIALIZED;

	if (Crashdbg_GetSailResetCtrlFSMState() < SP_PRE_DDR_INIT_ST ) //Not pass2 case then register for sleep 
	{
		if ( 0x0u == ulI2cSleepHandle )
		{
			if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBack(&prvI2cDeInit_Sleep,&ulI2cSleepHandle))
			{
				DEBUG_LOG(SAIL_INFO,"prvI2cDeInit_Sleep Sleep Reg Failed\n\r");
			}
		}
	}
    			}
    		}
    		else
    		{
    			xStatus = I2C_ERROR_CLOCK_FAILURE;
    		}
    	}
    }

    mutex_init(&stI2cCoreLock);

    /* Return the Status*/
    return xStatus;
}

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


i2cStatus_e xI2cGetSlaveAddress(uint8 ChannelId , uint8 *pSlaveAddress)
{
    i2cStatus_e xErrorValue = I2C_SUCCESS;

    xErrorValue = prvI2cChannelIdcheck(ChannelId);
    if(I2C_SUCCESS == xErrorValue)
    {
        *pSlaveAddress = xI2CChannelCfg[ChannelId].SlaveAddress;
    }

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
    i2cCmdOpcode_e xOpcode  = CMD_INVALID;
    uint32 ulRegMask;
    uint32 ulSEBase;
    uint32 ulFlag;
    uint8  ucHardwareId = 0;
    uint8  ucCommandLength = 0;
    uint32 ulcount = 0;

    I2C_CRITCAL_SECTION_START();

    xErrorValue = prvI2cWriteErrorcheck(ucChannelId, pucDataPtr);
    if(xErrorValue == I2C_SUCCESS)
    {
        ulFlag = i2cFLAG_START | i2cFLAG_STOP | i2cFLAG_WRITE;
        /* Get the command opcode*/
        xOpcode = prvI2cGetCmdOpcode(ulFlag, ucLength);
        if(xOpcode != CMD_INVALID)
        {
            ucHardwareId = xI2CChannelCfg[ucChannelId].AssignedHwId;
            ulSEBase = xI2CHwConfig[ucHardwareId].se_base_addr;
            /* Call the I2C Transfer function */
            prvI2cTransfer(ucChannelId, ucLength,ulFlag, &ulRegMask);
            /* Write the Opcode and PARAM content*/
            REG_OUT(ulSEBase, GENI_M_CMD0, FLD_SET(GENI_M_CMD0, OPCODE, xOpcode) |
                                         FLD_SET(GENI_M_CMD0, PARAM,  ulRegMask));
            /* Check if the Opcode is for I2C Write. Note. I2C Write will be returned when
               buffer length is not 0.*/
            if(xOpcode == CMD_I2C_WRITE)
            {
                /* Configure the buffer length*/
                REG_OUT(ulSEBase, I2C_TX_TRANS_LEN, (ucLength + (uint8)xI2CChannelCfg[ucChannelId].Addressing_Mode));
                xI2cSEChannelData[ucHardwareId].ucBufferLength = ucLength;
                xI2cSEChannelData[ucHardwareId].ulAddress = ulAddress;
                xI2cSEChannelData[ucHardwareId].ucTransferredLength = 0;
                xI2cSEChannelData[ucHardwareId].pucDataPtr = pucDataPtr;
                xI2cSEChannelData[ucHardwareId].xActiveCommand = I2C_WRITE_COMMAND;
                xI2cSEChannelData[ucHardwareId].ucActiveChannel = ucChannelId;
                /* Check if the FIFO mode is configured*/
                if(xI2CHwConfig[ucHardwareId].Access_Mode == I2C_POLLING_MODE)
                {
                    /* Continue to send the data till all the requested number of data is transferred*/
                    do
                    {
                        REG_OUTF(ulSEBase, GENI_M_IRQ_CLEAR,M_CMD_DONE_CLEAR,1);
                        /* Write the Data into the TX FIFO*/
                        prvI2cFiFoWrite(ucHardwareId);
                        while((FLD_GET(REG_IN(ulSEBase, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS, M_CMD_DONE) != 1U))
                        {
                            ;
                        }
                        /* while doing the I2C transfers(Write/read)in between the transfer, explicitly 
                           connecting the I2C SDA line to ground(to create ARB loss error). when this happened 
                           we are expecting the ARB LOST and GSI channels to move in error state. 
                           But ARB lost updated in GENI register but CMD_FAILURE is not reported.
                           We can not only depend on M_CMD_DONE value and need to check for other errors like ARB lost etc */
                        prvI2cReadGeniError(&xErrorValue,ucChannelId);
                        if ( I2C_SUCCESS != xErrorValue )
                        {
                            xI2cSEChannelData[ucHardwareId].xChannelStatus =  I2C_CHANNEL_READY;
                            /* Clear any pending IRQs */
                            REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, REG_IN(ulSEBase, GENI_M_IRQ_STATUS));
                            goto end;
                        }
                        REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, REG_IN(ulSEBase, GENI_M_IRQ_STATUS));
                    }while(xI2cSEChannelData[ucHardwareId].ucTransferredLength < xI2cSEChannelData[ucHardwareId].ucBufferLength);
                    xI2cSEChannelData[ucHardwareId].xChannelStatus =  I2C_CHANNEL_READY;
                }
                else if(xI2CHwConfig[ucHardwareId].Access_Mode == I2C_FIFO_MODE)
                {
                    /* Enable the TX watermark level as 1. So as soon as interrupt is enabled the
                       ISR will hit and in ISR the FIFO will be updated.*/
                    REG_OUT(ulSEBase, GENI_TX_WATERMARK_REG,
                                 FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 1));
                }
                else
                {
                	ucCommandLength = (uint8)xI2CChannelCfg[ucChannelId].Addressing_Mode;
                	for(ulcount = 0;ulcount < (ucCommandLength + ucLength);ulcount++)
                	{
                		if(ulcount < ucCommandLength)
                		{
                	 	    I2c_TstSendDataDMA[ulcount] = ((ulAddress >> (ulcount*8U)) & 0xFFU);
                		}
                		else
                		{
                			I2c_TstSendDataDMA[ulcount] = pucDataPtr[ulcount-ucCommandLength];
                		}
                	}
                    /* Set the Granularity for the DMA mode. Fixed 4x8 */
                    REG_OUT(ulSEBase, GENI_BYTE_GRANULARITY,
                        FLD_SET(GENI_BYTE_GRANULARITY, GENI_BYTE_GRANULARITY, 0));
                    /* Update the buffer address that needs to be transfered*/
                    REG_OUT(ulSEBase,DMA_TX_PTR_L,
                         FLD_SET(DMA_TX_PTR_L,TX_PTR_L,&I2c_TstSendDataDMA));
                    REG_OUT(ulSEBase,DMA_TX_PTR_H,
                         FLD_SET(DMA_TX_PTR_H,TX_PTR_H,0));
                    /* Set the End of Transfer attribute.*/
                    REG_OUT(ulSEBase,DMA_TX_ATTR,
                         FLD_SET(DMA_TX_ATTR,EOT,1));
                    /* Configure the buffer length*/
                    REG_OUT(ulSEBase,DMA_TX_LENGTH,
                         FLD_SET(DMA_TX_LENGTH,TX_LENGTH,(ucLength + ucCommandLength)));
                }
            }
        }
        else
        {
            xErrorValue = I2C_ERROR_INVALID_OPCODE;
        }
    }

end:
    I2C_CRITCAL_SECTION_END();
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
    i2cCmdOpcode_e xOpcode = CMD_INVALID;
    uint32 ulRegMask;
    uint32 ulSEBase;
    uint32 ulFlag;
    uint8 ucHardwareId;
    uint8 ulcount;

    I2C_CRITCAL_SECTION_START();

    xErrorValue = prvI2cReadErrorcheck(ucChannelId, pucDataPtr);

    if(xErrorValue == I2C_SUCCESS)
    {
        ulFlag = i2cFLAG_START | i2cFLAG_STOP | i2cFLAG_READ;
        /* Get the command Opcode*/
        xOpcode = prvI2cGetCmdOpcode(ulFlag, ucLength);
        if(xOpcode != CMD_INVALID)
        {
            ucHardwareId = xI2CChannelCfg[ucChannelId].AssignedHwId;
            ulSEBase = xI2CHwConfig[ucHardwareId].se_base_addr;
            prvI2cTransfer(ucChannelId, ucLength,ulFlag, &ulRegMask);
            /* Write the Opcode and PARAM content*/
            REG_OUT(ulSEBase, GENI_M_CMD0, FLD_SET(GENI_M_CMD0, OPCODE, xOpcode) |
                                                          FLD_SET(GENI_M_CMD0, PARAM,  ulRegMask));
            if(xOpcode == CMD_I2C_WRITE_THEN_READ)
            {
                xI2cSEChannelData[ucHardwareId].ucBufferLength = ucLength;
                xI2cSEChannelData[ucHardwareId].ulAddress = ulAddress;
                xI2cSEChannelData[ucHardwareId].ucTransferredLength = 0;
                xI2cSEChannelData[ucHardwareId].pucDataPtr = pucDataPtr;
                xI2cSEChannelData[ucHardwareId].xActiveCommand = I2C_READ_COMMAND;
                xI2cSEChannelData[ucHardwareId].ucActiveChannel = ucChannelId;
                /* Configure the Tx buffer length*/
                REG_OUT(ulSEBase, I2C_TX_TRANS_LEN,
                		xI2CChannelCfg[ucChannelId].Addressing_Mode);
                /* Update the Rx buffer length*/
                REG_OUT(ulSEBase, I2C_RX_TRANS_LEN, ucLength);
                if(xI2CHwConfig[ucHardwareId].Access_Mode == I2C_POLLING_MODE)
                {
                    REG_OUTF(ulSEBase, GENI_M_IRQ_CLEAR,M_CMD_DONE_CLEAR,1);
                    prvI2cFiFoWrite(ucHardwareId);
                    do
                    {
                        while((FLD_GET(REG_IN(ulSEBase, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,
                        		                                               M_CMD_DONE) != 1U))
                        {
                            ;
                        }

                        /*
                         * I2c shouldn't block the next transaction on any same/any other slave connected to I2c bus . 
                         * Hence, making that channel active if I2c driver is seeing any error on channel so
                         * that next transaction on same or any other slave won't get block
                         */
                        prvI2cReadGeniError(&xErrorValue,ucChannelId);
                        if ( I2C_SUCCESS != xErrorValue )
                        {
                            xI2cSEChannelData[ucHardwareId].xChannelStatus =  I2C_CHANNEL_READY;
                            /* Clear any pending IRQs */
                            REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
                            return xErrorValue;
                        }
                        REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
                        /* Read the Data from the RX FIFO*/
                        prvI2cFiFoRead(ucHardwareId);
                        REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, REG_IN(ulSEBase, GENI_M_IRQ_STATUS));
                    }while(xI2cSEChannelData[ucHardwareId].ucTransferredLength <
                    		                        xI2cSEChannelData[ucHardwareId].ucBufferLength);
                    xI2cSEChannelData[ucHardwareId].xChannelStatus =  I2C_CHANNEL_READY;
                }
                /* Check if the configure mode is FIFO*/
                else if(xI2CHwConfig[ucHardwareId].Access_Mode == I2C_FIFO_MODE)
                {
                    REG_OUT(ulSEBase, GENI_RX_WATERMARK_REG,
                                    FLD_SET(GENI_RX_WATERMARK_REG, RX_WATERMARK, 0));
                    REG_OUT(ulSEBase, GENI_TX_WATERMARK_REG,
                                    FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 1));
                }
                else
                {
                	for(ulcount = 0U;ulcount < (uint8)xI2CChannelCfg[ucChannelId].Addressing_Mode;ulcount++)
                	{
                		I2c_TstSendDataDMA[ulcount] = ((ulAddress >> (ulcount*8U)) & 0xFFU);
                	}
                    /* Update the buffer address that needs to be updated*/
                    REG_OUT(ulSEBase,DMA_RX_PTR_L,
                          FLD_SET(DMA_RX_PTR_L,RX_PTR_L,(uint8 *)pucDataPtr));
                    REG_OUT(ulSEBase,DMA_RX_PTR_H,
                          FLD_SET(DMA_RX_PTR_H,RX_PTR_H,0));
                    /* reset the DMA RX attribute*/
                    REG_OUT(ulSEBase,DMA_RX_ATTR,0);
                    /* update the buffer length for the DMA transfer*/
                    REG_OUT(ulSEBase,DMA_RX_LENGTH,
                          FLD_SET(DMA_RX_LENGTH,RX_LENGTH,ucLength));

                    /* Update the buffer address that needs to be transfered*/
                    REG_OUT(ulSEBase,DMA_TX_PTR_L,
                          FLD_SET(DMA_TX_PTR_L,TX_PTR_L,I2c_TstSendDataDMA));
                    REG_OUT(ulSEBase,DMA_TX_PTR_H,
                          FLD_SET(DMA_TX_PTR_H,TX_PTR_H,0));
                    /* Set the End of Transfer attribute.*/
                    REG_OUT(ulSEBase,DMA_TX_ATTR,
                          FLD_SET(DMA_TX_ATTR,EOT,1));
                    /* Configure the buffer length*/
                    REG_OUT(ulSEBase,DMA_TX_LENGTH,
                          FLD_SET(DMA_TX_LENGTH,TX_LENGTH,
                        		  xI2CChannelCfg[ucChannelId].Addressing_Mode));
                }
            }
        }
    }

    I2C_CRITCAL_SECTION_END();

    return xErrorValue;
}

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
	i2cStatus_e xStatus = I2C_NOT_INITIALIZED;

    I2C_CRITCAL_SECTION_START();

    if ( ucHardwareId >= MAX_NO_OF_SERIAL_ENGINE )
    {
        xStatus = I2C_HW_NOT_EXIST;
        goto end;
    }
    if( xI2cInitStatus[ucHardwareId] == I2C_INITIALIZED)
    {
    	/* Disable the QuPV3 clocks*/
        if ( CLOCK_SUCCESS == prvI2cClockDisable(&xI2CHwConfig[ucHardwareId]) )
        {

            /* DeInitialize the Serial Engine*/
            prvI2cSerialEngineDeInit(&xI2CHwConfig[ucHardwareId], ulQupCommonBase);
            prvI2cPinCtlReset(ucHardwareId);
            xI2cSEChannelData[ucHardwareId].xChannelStatus      = I2C_CHANNEL_INACTIVE;
            xI2cSEChannelData[ucHardwareId].xActiveCommand      = I2C_PING_COMMAND;
            xI2cSEChannelData[ucHardwareId].ucBufferLength      = 0U;
            xI2cSEChannelData[ucHardwareId].ulAddress 	        = 0U;
            xI2cSEChannelData[ucHardwareId].ucTransferredLength = 0U;
            xI2cSEChannelData[ucHardwareId].pucDataPtr          = NULL;
            xI2cSEChannelData[ucHardwareId].ucActiveChannel     = 0U;
            xI2cInitStatus[ucHardwareId] = I2C_UNINITIALIZED;

            xStatus = I2C_SUCCESS;
            goto end;
        }
        else
        {
            xStatus = I2C_ERROR_CLOCK_FAILURE;
            goto end;
        }
    }
    else
    {
        xStatus = I2C_NOT_INITIALIZED;
        goto end;     
    }

end:
    I2C_CRITCAL_SECTION_END();
    return xStatus;
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
    uint8 SlaveAddress = 0x0;
    i2cStatus_e xErrorVal = I2C_SUCCESS;
    uint32 ulFlag = i2cFLAG_START;
    i2cCmdOpcode_e xOpcode  = CMD_INVALID;
    uint32 ulLength = 0x0;
    uint32 ulSEBase = 0x0;
    uint32 ucCmdDone = 0x0;
    uint8  ucTimeOut = 0x0;

    I2C_CRITCAL_SECTION_START();

    xErrorVal = prvI2cChannelIdcheck(ucChannelId);

    if ( I2C_SUCCESS == xErrorVal )
    {
        xOpcode = prvI2cGetCmdOpcode(ulFlag,ulLength);
        if ( xOpcode != CMD_INVALID )
        {
            ucHardwareId = xI2CChannelCfg[ucChannelId].AssignedHwId;
            ulSEBase = xI2CHwConfig[ucHardwareId].se_base_addr;

            SlaveAddress = xI2CChannelCfg[ucChannelId].SlaveAddress;

            REG_OUT(ulSEBase, GENI_M_CMD0, FLD_SET(GENI_M_CMD0, OPCODE, xOpcode) |
                                        FLD_SET(GENI_M_CMD0, PARAM,  SlaveAddress<<9));
            ucCmdDone = REG_IN(ulSEBase, GENI_M_IRQ_STATUS);

            while(FLD_GET(ucCmdDone, GENI_M_IRQ_STATUS,M_CMD_DONE)!= 0x1u && ucTimeOut<=i2cMaxPollingTime)
            {
                busywait(100);
                ucCmdDone = REG_IN(ulSEBase, GENI_M_IRQ_STATUS);
                ucTimeOut++;
            }

            prvI2cReadGeniError(&xErrorVal,ucChannelId);

            REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);

        }
    }

    I2C_CRITCAL_SECTION_END();

    return xErrorVal;
}


/*=================================================================================================
**                                        Interrupt Handler                                      **
=================================================================================================*/

/*=================================================================================================
 @Service name        xI2cGeniSEIsr
 @Description         This Handler handles the FIFO read/Write in case of FIFO Mode and change the
                      status of the transfer in case of DMA mode
 @param[in]           arg     - Serial engne Id
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
//_Interrupt
static enum handler_return xI2cGeniSEIsr(
    void *arg)
{
    i2cStatus_e xStatus = I2C_UNKNOWN_FAILURE;
    uint32 I2c_IrqStatusM;
    uint32 I2c_IrqStatusS;
    uint32 Dma_TxIrqStatus;
    uint32 Dma_RxIrqStatus;
    uint32 ulSEBase;
    uint32 ucHardwareId = 0;

    I2C_CRITCAL_SECTION_START();

    ucHardwareId = (uint32)arg;

    if(I2cInitStatusCheck(ucHardwareId) == I2C_SUCCESS)
    {
        /* Get the Serial engine base address*/
        ulSEBase = xI2CHwConfig[ucHardwareId].se_base_addr;

        /* Read the IRQ status register*/
        I2c_IrqStatusM = REG_IN(ulSEBase, GENI_M_IRQ_STATUS);

        I2c_IrqStatusS = REG_IN(ulSEBase, GENI_M_IRQ_STATUS);

         /* Check for FIFO interrupt*/
        if(xI2CHwConfig[ucHardwareId].Access_Mode == I2C_FIFO_MODE)
        {
            /* Check if the interrupt is due to RX FIFO Watermark level */
            if (FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, RX_FIFO_WATERMARK) != 0U)
            {
                /* Call the FIFO read function to read data from the RX FIFO*/
                prvI2cFiFoRead(ucHardwareId);
                /* Set the status as I2C_TRANSFER_SUCCESS*/
                xStatus = I2C_TRANSFER_ONGOING;
            }
            /* Check if the interrupt is due to TX Watermark level*/
            if (FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, TX_FIFO_WATERMARK) != 0U)
            {
                /* Call the FIFO write function to write data to the FIFO*/
                prvI2cFiFoWrite(ucHardwareId);
                /* Set the status as I2C_TRANSFER_SUCCESS*/
                xStatus = I2C_TRANSFER_ONGOING;
            }
        }
        else if(xI2CHwConfig[ucHardwareId].Access_Mode == I2C_DMA_MODE)
        {
        	/* Read the DMA interrupt status register*/
        	Dma_TxIrqStatus = REG_IN(ulSEBase, DMA_TX_IRQ_STAT);
        	Dma_RxIrqStatus = REG_IN(ulSEBase, DMA_RX_IRQ_STAT);

            /* Check if the TX DMA done*/
            if(FLD_GET(Dma_TxIrqStatus, DMA_TX_IRQ_STAT, DMA_DONE) != 0U)
        	{
        	    /* Set the status to success*/
//                xStatus = I2C_TRANSFER_SUCCESS;
        	}
            /* Check if the RX DMA done*/
        	if(FLD_GET(Dma_RxIrqStatus, DMA_RX_IRQ_STAT, DMA_DONE) != 0U)
        	{
        	    /* Set the status to success*/
//        	    xStatus = I2C_TRANSFER_SUCCESS;
        	}
        	else
        	{
        	    /* Misra*/
        	}
        	if(Dma_TxIrqStatus != 0U)
        	{
        	  /* Clear the Interrupt flag*/
        	  REG_OUT(ulSEBase, DMA_TX_IRQ_CLR, Dma_TxIrqStatus);
        	}
        	if(Dma_RxIrqStatus != 0U)
        	{
        	  /* Clear the Interrupt flag*/
        	  REG_OUT(ulSEBase, DMA_RX_IRQ_CLR, Dma_RxIrqStatus);
        	}
        }
        else
        {
        	; /*MCDC*/
        }
        /* Check if the interrupt due to command done*/
        if (FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, M_CMD_DONE) != 0U)
        {
            /* Set the status as I2C_TRANSFER_SUCCESS*/
            xStatus = I2C_TRANSFER_SUCCESS;
        }
        /* Clear all the GENI_M_IRQ*/
        if(I2c_IrqStatusM != 0U)
        {
            /* Clear the Interrupt flag*/
            REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, I2c_IrqStatusM);
        }
        /* Clear all the GENI_M_IRQ*/
        if(I2c_IrqStatusS != 0U)
        {
            /* Clear the Interrupt flag*/
            REG_OUT(ulSEBase, GENI_S_IRQ_CLEAR, I2c_IrqStatusS);
        }
        if(xStatus == I2C_TRANSFER_SUCCESS)
        {
            /* Notification function call needs to be added*/
        	xI2cSEChannelData[ucHardwareId].xChannelStatus =  I2C_CHANNEL_READY;
        }

    }

    I2C_CRITCAL_SECTION_END();

    return INT_NO_RESCHEDULE;
}

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
i2cStatus_e I2cInitStatusCheck(uint8 ucHardwareID)
{
    i2cStatus_e xErrorVal = I2C_SUCCESS;

    if ( ucHardwareID >= MAX_NO_OF_SERIAL_ENGINE )
    {
        xErrorVal = I2C_HW_NOT_EXIST;
    }
    else if(xI2cInitStatus[ucHardwareID] == I2C_UNINITIALIZED)
    {
        xErrorVal = I2C_NOT_INITIALIZED;
    }
    else
    {
        xErrorVal = I2C_SUCCESS;
    }
    return xErrorVal;
}

/*=================================================================================================
**                                        Local function definitions                             **
=================================================================================================*/
/*=================================================================================================
 @Service name        prvI2CLoadDeviceTreeSettings
 @Description         This function loads hardware specific parameters from DTS file
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uartStatusType_e - Initialization status
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/


static i2cStatus_e prvI2CLoadDeviceTreeSettings(uint8 ucHardwareID)
{
	i2cStatus_e ret = I2C_SUCCESS;
	int offset = 0, root_offset = 0;
	const char *path;
	uint32_t slave_array[MAX_NO_OF_I2C_CHANNELS] = {0};
	uint32_t mode_array[MAX_NO_OF_I2C_CHANNELS] = {0};
	uint32_t delay_array[MAX_NO_OF_I2C_CHANNELS] = {0};
	uint32_t ts_array[MAX_NO_OF_I2C_CHANNELS] = {0};
    uint8 ucNoI2CChannels = 0x0u;
	int Size = MAX_NO_OF_I2C_CHANNELS;
	int valSize_st = 5;
    uint32_t val_array0[i2cNUMBER_OF_I2C_PINS] = {0};
    uint32_t val_array1[i2cNUMBER_OF_I2C_PINS] = {0};
    uint32_t val_array2[i2cNUMBER_OF_I2C_PINS] = {0};
    uint32_t val_array3[i2cNUMBER_OF_I2C_PINS] = {0};
    uint32_t val_array4[i2cNUMBER_OF_I2C_PINS] = {0};
    int valSize = i2cNUMBER_OF_I2C_PINS;
	char i2c_name[5] = {'i', '2', 'c','0','\0'};
    GPIOConfigType xqupPinCfg = {0x0u};
	void *pDTB = NULL;
    uint8 ucGpioNumbers = 0x0u;

    if ( ucHardwareID >= MAX_NO_OF_SERIAL_ENGINE )
	{
        ret = I2C_HW_NOT_EXIST;
        goto end;
    }

    if ( I2C_INITIALIZED == xI2cInitStatus[ucHardwareID] )
		{
        ret = I2C_ERROR_ALREADY_INITIALIZED;
        goto end;
	}

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/qup");
		(void)fdt_getprop_u32(pDTB, root_offset, "common-addr", &ulQupCommonBase);
		root_offset = fdt_path_offset(pDTB, "/aliases");
		i2c_name[3] = (ucHardwareID+48);
		path = (const char*)fdt_getprop(pDTB, root_offset, i2c_name , NULL);
		if (path != NULL) 
        {
			offset = fdt_path_offset(pDTB, path);
			(void)fdt_getprop_u32(pDTB, offset, "reg-base", &xI2CHwConfig[ucHardwareID].se_base_addr);
			(void)fdt_getprop_u32_array(pDTB, offset, "slave-addr", slave_array, &Size);
			(void)fdt_getprop_u32_array(pDTB, offset, "addressing-mode", mode_array, &Size);
			(void)fdt_getprop_u32_array(pDTB, offset, "timestamp", ts_array, &Size);
			(void)fdt_getprop_u32_array(pDTB, offset, "precmd-delay", delay_array, &Size);
			xI2CHwConfig[ucHardwareID].psSE_clock = (char*) fdt_getprop(pDTB, offset, "clock-name", &valSize_st);
			xI2CHwConfig[ucHardwareID].NoOfChannels = (uint8)Size;
			for( uint8 i = 0 ; i < (uint8)Size; i++)
			{
				xI2CChannelCfg[i].SlaveAddress = (uint8)slave_array[i];
				xI2CChannelCfg[i].Addressing_Mode = mode_array[i];
				xI2CChannelCfg[i].ChannelId = ucNoI2CChannels;
				xI2CChannelCfg[i].AssignedHwId = ucHardwareID;
				xI2CChannelCfg[i].Delay_PreCmdus = (uint8)delay_array[i];
				xI2CChannelCfg[i].timestamp_en = (uint8)ts_array[i];
			}
			(void)fdt_getprop_u32(pDTB, offset, "status", &xI2CHwConfig[ucHardwareID].status);
			(void)fdt_getprop_u32(pDTB, offset, "i2c-mode", &xI2CHwConfig[ucHardwareID].Mode);
			(void)fdt_getprop_u32(pDTB, offset, "access-mode", &xI2CHwConfig[ucHardwareID].Access_Mode);
			(void)fdt_getprop_u32(pDTB, offset, "interrupt", &xI2CHwConfig[ucHardwareID].Intr_Num);

            if( xI2CHwConfig[ucHardwareID].status == 0x0U)
            {
                ret = I2C_HW_NOT_ENABLED;
                goto end;
            }
            else
            {
            path = (char*)fdt_getprop(pDTB, offset, "pinctrl", NULL);
            if( NULL != path)
            {
                offset = fdt_path_offset(pDTB, path);
                (void)fdt_getprop_u32_array(pDTB, offset, "pins", val_array0, &valSize);
                (void)fdt_getprop_u32_array(pDTB, offset, "func", val_array1, &valSize);
                (void)fdt_getprop_u32_array(pDTB, offset, "drive-strength", val_array2, &valSize);
                (void)fdt_getprop_u32_array(pDTB, offset, "dir", val_array3, &valSize);
                (void)fdt_getprop_u32_array(pDTB, offset, "bias", val_array4, &valSize);
                for( int i = 0; i < valSize; i++)
                {
                    ucGpioNumbers = (uint8)val_array0[i];
                    sail_gpio_get_pin_config(ucGpioNumbers,&I2cResetStatePinCfg[ucHardwareID][i]);
                    xqupPinCfg.func = val_array1[i];
                    xqupPinCfg.drive = val_array2[i];
                    xqupPinCfg.dir = val_array3[i];
                    xqupPinCfg.pull = val_array4[i];
                    sail_gpio_config_pin(ucGpioNumbers,xqupPinCfg);
                }
            }
            else
            {
                ret = I2C_HW_NOT_EXIST;
                    goto end;
                }
            }
		}
		else
		{
			ret = I2C_HW_NOT_EXIST;
            goto end;
		}
	}

end:
	return ret;
}

/*=================================================================================================
 @Service name        prvI2cSerialEngineInit
 @Description         This function Initialize the Serial engine of the QUP Hw for the I2c Protocol
 @param[in]           pxHwconfig      - Pointer for the Hardware configuration
                      ulQupCommonAddr - QUP common CSR space address
 @param[out]          NA
 @param[in, out]      NA
 @return              Initialization status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static i2cStatus_e prvI2cSerialEngineInit(
    const i2cHwUnitCfgType *pxHwconfig,
	uint32 ulQupCommonAddr)
{
    i2cStatus_e xStatus = I2C_SUCCESS;
    uint32 ulSEBase = pxHwconfig->se_base_addr;
    uint32 ulTimeoutMax = 500;
    uint32 ulFifodepth;
    uint32 ulRegMIRQ = 0;
    uint32 ulRegSIRQ = 0;

    /* HPG section 3.1.7.1 is skipped since the DFS enabling is not required*/
    /* Check if the DMA mode is configured. As per 3.1.7.2*/
    if(pxHwconfig->Access_Mode == I2C_DMA_MODE)
    {
        /* Reset the DMA*/
        REG_OUT(ulSEBase, DMA_RX_FSM_RST,
                                    FLD_SET(DMA_RX_FSM_RST, RX_FSM_RST, 0x1));
        /* Wait till the reset is done or timeout occured*/
        do
        {
            /* Check if the Reset is done*/
            if(REG_INF(ulSEBase,DMA_RX_IRQ_STAT,RESET_DONE) != 0U)
            {
                // Clear the Reset done IRQ bit
                REG_OUTF(ulSEBase, DMA_RX_IRQ_CLR,RESET_DONE_CLR, 0x1);
                REG_OUTF(ulSEBase, DMA_RX_IRQ_CLR,DMA_DONE_CLR, 0x1);
                break;
            }
            else
            {
                /* Wait for i2cPOLLINTERVAL_US*/
                busywait(i2cPOLLINTERVAL_US);
                /* Decrement the timeout*/
                ulTimeoutMax -= i2cPOLLINTERVAL_US;
            }
        }while ((ulTimeoutMax != 0U));
    }

    /* First, ensure GENI FW is disabled */
    /* Disable the Output */
    REG_OUT(ulSEBase, GENI_OUTPUT_CTRL,
              FLD_SET(GENI_OUTPUT_CTRL, IO_OUTPUT_CTRL, 0x0));
    REG_OUTF(ulSEBase, GENI_DFS_IF_CFG, DFS_IF_EN, 0);

    /* Check if the DMA mode is configured*. As per 3.1.7.3 */
    if(pxHwconfig->Access_Mode == I2C_DMA_MODE)
    {
        // Clock related to DMA. As per HPG. 3.1.7.3.
        REG_OUT(ulSEBase, DMA_GENERAL_CFG,
                         FLD_SET(DMA_GENERAL_CFG, AHB_SEC_SLV_CLK_CGC_ON, 1) |
                         FLD_SET(DMA_GENERAL_CFG, DMA_AHB_SLV_CLK_CGC_ON, 1) |
                         FLD_SET(DMA_GENERAL_CFG, DMA_TX_CLK_CGC_ON, 1) |
                         FLD_SET(DMA_GENERAL_CFG, DMA_RX_CLK_CGC_ON, 1));
    }
    /* Clock gating control for GENI.As per HPG section 3.1.7.3 */
    REG_OUT(ulSEBase, GENI_CGC_CTRL,
                     FLD_SET(GENI_CGC_CTRL, EXT_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, RX_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, TX_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, SCLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, DATA_AHB_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, CFG_AHB_WR_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, CFG_AHB_CLK_CGC_ON, 1));

    /* Check if the Firmware loading is done*/
    if(xStatus == I2C_SUCCESS)
    {
        /* Enable IO GENI output. As per HPG section 3.1.7.5*/
        REG_OUT(ulSEBase, GENI_OUTPUT_CTRL,
                         FLD_SET(GENI_OUTPUT_CTRL, IO_OUTPUT_CTRL, 0x7f));
        /* Check the configured mode is FIFO mode. As per HPG section 3.1.7.6 */
        if(pxHwconfig->Access_Mode != I2C_DMA_MODE)
        {
            /* Disable the DMA*/
            REG_OUT(ulSEBase, GENI_DMA_MODE_EN,
                             FLD_SET(GENI_DMA_MODE_EN, GENI_DMA_MODE_EN, 0));
        }
        else
        {
            /* Enable the DMA*/
            REG_OUT(ulSEBase, GENI_DMA_MODE_EN,
                             FLD_SET(GENI_DMA_MODE_EN, GENI_DMA_MODE_EN, 1));
        }
        /* HPG section 3.1.7.9 */
        /* non-UART configuration, UART driver can configure as desired for UART */
        ulFifodepth = REG_INF(ulSEBase, SE_HW_PARAM_1, RX_FIFO_DEPTH);

        REG_OUT(ulSEBase, GENI_RX_RFR_WATERMARK_REG,
                         FLD_SET(GENI_RX_RFR_WATERMARK_REG, RX_RFR_WATERMARK, (ulFifodepth - 2U)));

        if(pxHwconfig->Access_Mode != I2C_POLLING_MODE)
        {
            /* Configure the Interrupt handler*/
            (void)mask_interrupt(pxHwconfig->Intr_Num);
            (void)configure_interrupt(pxHwconfig->Intr_Num, INT_CONFIG_LEVEL_TRIGGER, 0U);
            (void)register_int_handler(pxHwconfig->Intr_Num, xI2cGeniSEIsr,
                                                               (void *)pxHwconfig->Hw_ChannelId);
            (void)unmask_interrupt(pxHwconfig->Intr_Num);

            /* Clear any pending Interrupt. This will ensure the fresh start*/
            REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
            REG_OUT(ulSEBase, GENI_S_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
            REG_OUT(ulSEBase, DMA_TX_IRQ_CLR, i2cIRQ_CLEAR_MASK);
            REG_OUT(ulSEBase, DMA_RX_IRQ_CLR, i2cIRQ_CLEAR_MASK);

            /* Enable the Interrupts*/
            REG_OUT(ulSEBase, SE_IRQ_EN,
                             FLD_SET(SE_IRQ_EN, DMA_RX_IRQ_EN, 1) |
                             FLD_SET(SE_IRQ_EN, DMA_TX_IRQ_EN, 1) |
                             FLD_SET(SE_IRQ_EN, GENI_M_IRQ_EN, 1) |
                             FLD_SET(SE_IRQ_EN, GENI_S_IRQ_EN, 1));
            REG_OUT(ulSEBase, SE_GSI_EVENT_EN,0);

            /* Frame the common M_IRQ enable*/
            ulRegMIRQ = (ulRegMIRQ | FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_OVERRUN_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, M_ILLEGAL_CMD_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, M_TIMESTAMP_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_RD_ERR_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_WR_ERR_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_RD_ERR_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_WR_ERR_EN, 1));
            /* Frame the common S_IRQ enable*/
            ulRegSIRQ = (ulRegSIRQ | FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_OVERRUN_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_ILLEGAL_CMD_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_0_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_1_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_2_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_3_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, RX_FIFO_WR_ERR_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, RX_FIFO_RD_ERR_EN, 1));
            /* Check if the Configured mode is FIFO*/
            if(pxHwconfig->Access_Mode == I2C_FIFO_MODE)
            {
                REG_OUT(ulSEBase, GENI_M_IRQ_ENABLE,
                                 ulRegMIRQ |
                                 FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_WATERMARK_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_WATERMARK_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_LAST_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_DONE_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_FAILURE_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_CANCEL_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_ABORT_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, SEC_IRQ_EN, 1));

              REG_OUT(ulSEBase, GENI_S_IRQ_ENABLE,
                               ulRegSIRQ |
                               FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_CANCEL_EN, 1) |
                               FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_ABORT_EN, 1) |
                               FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_DONE_EN, 1));
            }
            /* Enable the Interrupts for DMA Mode*/
            else if(pxHwconfig->Access_Mode == I2C_DMA_MODE)
            {
                REG_OUT(ulSEBase, GENI_M_IRQ_ENABLE, ulRegMIRQ);

                REG_OUT(ulSEBase, GENI_S_IRQ_ENABLE, ulRegSIRQ);

                REG_OUT(ulSEBase, DMA_TX_IRQ_EN_SET,
                                 FLD_SET(DMA_TX_IRQ_EN_SET, DMA_DONE_EN_SET, 1) |
                                 FLD_SET(DMA_TX_IRQ_EN_SET, SBE_EN_SET, 1) |
                                 FLD_SET(DMA_TX_IRQ_EN_SET, RESET_DONE_EN_SET, 1));

                REG_OUT(ulSEBase, DMA_RX_IRQ_EN_SET,
                                 FLD_SET(DMA_RX_IRQ_EN_SET, DMA_DONE_EN_SET, 1) |
                                 FLD_SET(DMA_RX_IRQ_EN_SET, SBE_EN_SET, 1) |
                                 FLD_SET(DMA_RX_IRQ_EN_SET, RESET_DONE_EN_SET, 1));
            }
            else
            {
                /* Dummy else*/
            }
        }

        /* Enable the force Default. */
        REG_OUT(ulSEBase, GENI_FORCE_DEFAULT_REG,
                         FLD_SET(GENI_FORCE_DEFAULT_REG, FORCE_DEFAULT, 1));

        REG_OUTF(ulSEBase, GENI_CGC_CTRL,PROG_RAM_SCLK_OFF,1);
        REG_OUTF(ulSEBase, GENI_CGC_CTRL,PROG_RAM_HCLK_OFF,1);

        REG_OUT(ulSEBase, GENI_CLK_CTRL,
                         FLD_SET(GENI_CLK_CTRL, SER_CLK_SEL, 0x1));

        REG_OUTF(ulSEBase, GENI_CGC_CTRL,PROG_RAM_SCLK_OFF,0);
        REG_OUTF(ulSEBase, GENI_CGC_CTRL,PROG_RAM_HCLK_OFF,0);

        /* Check if the FIFO mode is configured. As per HPG section 3.1.7.13 */
        if(pxHwconfig->Access_Mode != I2C_DMA_MODE)
        {
            /* Disable the DMA mode*/
            REG_OUT(ulSEBase, DMA_IF_EN,
                             FLD_SET(DMA_IF_EN, DMA_IF_EN, 0x0));
            /* Enable the FIFO mode*/
            REG_OUT(ulSEBase, FIFO_IF_DISABLE,
                             FLD_SET(FIFO_IF_DISABLE, FIFO_IF_DISABLE, 0x0));
        }
        else
        {
            /* Enable the DMA mode*/
            REG_OUT(ulSEBase, DMA_IF_EN,
                             FLD_SET(DMA_IF_EN, DMA_IF_EN, 0x1));
            /* Disable the FIFO mode*/
            REG_OUT(ulSEBase, FIFO_IF_DISABLE,
                             FLD_SET(FIFO_IF_DISABLE, FIFO_IF_DISABLE, 0x1));
            /* Set the Granularity for the DMA mode. Fixed 4x8 */
            REG_OUT(ulSEBase, GENI_BYTE_GRANULARITY,
                FLD_SET(GENI_BYTE_GRANULARITY, GENI_BYTE_GRANULARITY, 0));
        }

        /* As per H.P.G 3.2.1. clock select*/
        REG_OUT(ulSEBase, GENI_CLK_SEL, FLD_SET(GENI_CLK_SEL, CLK_SEL, 0));

        /* Configure the TX and RX Packing. Fixed to 4x8 Packing */
        REG_OUT(ulSEBase, GENI_TX_PACKING_CFG0, i2cTX_PACKING_CFG0_VAL);
        REG_OUT(ulSEBase, GENI_TX_PACKING_CFG1, i2cTX_PACKING_CFG1_VAL);
        REG_OUT(ulSEBase, GENI_RX_PACKING_CFG0, i2cRX_PACKING_CFG0_VAL);
        REG_OUT(ulSEBase, GENI_RX_PACKING_CFG1, i2cRX_PACKING_CFG1_VAL);

        /* Clock Configuration*/
        REG_OUT(ulSEBase, GENI_SER_M_CLK_CFG,
                         FLD_SET(GENI_SER_M_CLK_CFG, CLK_DIV_VALUE,
                                                     xI2cClkCfg[pxHwconfig->Mode].ucClkDiv) |
                         FLD_SET(GENI_SER_M_CLK_CFG, SER_CLK_EN,      1));

        /* SCL Configuration*/
        REG_OUT(ulSEBase, I2C_SCL_COUNTERS,
                         FLD_SET(I2C_SCL_COUNTERS, I2C_SCL_HIGH_COUNTER,
                                                   xI2cClkCfg[pxHwconfig->Mode].ucTHigh) |
                         FLD_SET(I2C_SCL_COUNTERS, I2C_SCL_LOW_COUNTER,
                                                   xI2cClkCfg[pxHwconfig->Mode].ucTLow)  |
                         FLD_SET(I2C_SCL_COUNTERS, I2C_SCL_CYCLE_COUNTER,
                                                   xI2cClkCfg[pxHwconfig->Mode].ucTCycle));
    }
    return xStatus;
}

/*=================================================================================================
 @Service name        prvI2cSerialEngineDeInit
 @Description         This function DeInitialize the Serial engine of the QUP Hw for the I2c Protocol
 @param[in]           pxHwconfig      - Pointer for the Hardware configuration
                      ulQupCommonAddr - QUP common CSR space address
 @param[out]          NA
 @param[in, out]      NA
 @return              Initialization status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static void prvI2cSerialEngineDeInit(
    const i2cHwUnitCfgType *pxHwconfig,
	uint32 ulQupCommonAddr)
{
    uint32 ulSEBase = pxHwconfig->se_base_addr;
	uint8  ucI2CFWRev_Reset = 0xFFU;

    if(pxHwconfig->Access_Mode != I2C_POLLING_MODE)
    {
        /* Disable the Interrupts*/
        REG_OUT(ulSEBase, SE_IRQ_EN,
                         FLD_SET(SE_IRQ_EN, DMA_RX_IRQ_EN, 0) |
                         FLD_SET(SE_IRQ_EN, DMA_TX_IRQ_EN, 0) |
                         FLD_SET(SE_IRQ_EN, GENI_M_IRQ_EN, 0) |
                         FLD_SET(SE_IRQ_EN, GENI_S_IRQ_EN, 0));
        REG_OUT(ulSEBase, SE_GSI_EVENT_EN,0);
        /* Clear any pending Interrupt.*/
        REG_OUT(ulSEBase, DMA_TX_IRQ_CLR, i2cIRQ_CLEAR_MASK);
        REG_OUT(ulSEBase, DMA_RX_IRQ_CLR, i2cIRQ_CLEAR_MASK);
    /* Reset the DMA*/
    REG_OUT(ulSEBase, DMA_RX_FSM_RST,
                                FLD_SET(DMA_RX_FSM_RST, RX_FSM_RST, 0x1));
    REG_OUT(ulSEBase, DMA_RX_FSM_RST,
                                FLD_SET(DMA_TX_FSM_RST, TX_FSM_RST, 0x1));
    	/* Unregister the Interrupt handler*/
    	(void)mask_interrupt(pxHwconfig->Intr_Num);
    	(void)unregister_int_handler(pxHwconfig->Intr_Num, 0U);
    }

    REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
    REG_OUT(ulSEBase, GENI_S_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);

    /*Enable the force Default.
    REG_OUT(ulSEBase, GENI_FORCE_DEFAULT_REG,
                     FLD_SET(GENI_FORCE_DEFAULT_REG, FORCE_DEFAULT, 1));*/
}

/*=================================================================================================
 @Service name        prvI2cClockEnable
 @Description         This function configure and enable the clock for the serial engine
 @param[in]           pxHwconfig      - Pointer for the Hardware configuration
 @param[out]          NA
 @param[in, out]      NA
 @return              Clock enable status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static ClockResult prvI2cClockEnable (const i2cHwUnitCfgType *pxHwconfig)
{
    ClockResult eResult = CLOCK_ERROR;
    ClockIdType nClockId = {0};;
    uint32_t ulNfreq = 0U;
    ClockHandle hClient = 0U;
	
    Clock_GetHandle( &hClient);
    eResult = Clock_GetClockId( hClient, pxHwconfig->psSE_clock, &nClockId);

    if ( eResult == CLOCK_SUCCESS )
    {
        eResult = Clock_SetClockFrequency
                              ( hClient, nClockId,
                               xI2cClkCfg[ pxHwconfig->Mode].ulSEClockFrequencyHz,
                               CLOCK_FREQUENCY_HZ_AT_LEAST, &ulNfreq);

        if( CLOCK_SUCCESS == eResult )
        {
			eResult = Clock_EnableClock( hClient, nClockId);
            if ( CLOCK_SUCCESS != eResult )
            {
            	DEBUG_LOG( SAIL_ERROR,"Failed to enable serial engine clock \r\n");
            }
		}
    }
    return eResult;
}

/*=================================================================================================
 @Service name        prvI2cClockDisable
 @Description         This function disable the clock for the serial engine
 @param[in]           pxHwconfig      - Pointer for the Hardware configuration
 @param[out]          NA
 @param[in, out]      NA
 @return              Clock disable status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static ClockResult prvI2cClockDisable (const i2cHwUnitCfgType *pxHwconfig)
{
	ClockResult eResult = CLOCK_ERROR;
	ClockIdType nClockId   = {0};
    ClockHandle hClient = 0U;

    Clock_GetHandle(&hClient);
    if ( CLOCK_SUCCESS == Clock_GetClockId( hClient, pxHwconfig->psSE_clock, &nClockId ) )
    {
        eResult = Clock_DisableClock( hClient, nClockId);
        if ( CLOCK_SUCCESS != eResult )
        {
            DEBUG_LOG(SAIL_ERROR,"Failed to disable serial engine clock \r\n");
        }
    }
    return eResult;
}

/*=================================================================================================
 @Service name        prvI2cGetCmdOpcode
 @Description         This function detect the opcode to be used for the current transfer
 @param[in]           ulFlags     - It contains the information about the START,STOP,Read or write
                      ulLength    - Length of the transfer
                      ulCmdLength - Length of the command to be send in case read after write
                                    operation
 @param[out]          NA
 @param[in, out]      NA
 @return              Opcode
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static i2cCmdOpcode_e prvI2cGetCmdOpcode (uint32 ulFlags, uint32 ulLength)
{
    i2cCmdOpcode_e xReturnVal = CMD_INVALID;
    /* Check if the length is 0*/
    if (ulLength == 0U)
    {
        /* Check if the Start flag is set*/
        if((ulFlags & i2cFLAG_START) == i2cFLAG_START)
        {
            /* I2C address only command*/
            xReturnVal = CMD_I2C_ADDRESS_ONLY;
        }
        /* Check if the stop flag is set*/
        else if((ulFlags & i2cFLAG_STOP) == i2cFLAG_STOP)
        {
            /* I2C stop on bus command*/
            xReturnVal = CMD_I2C_STOP_ON_BUS;
        }
        else if (ulFlags == 0U)
        {
            /* Bus clear command*/
            xReturnVal = CMD_I2C_BUS_CLEAR;
        }
        else
        {
        	;/*MCDC*/
        }
    }
    else
    {
        /* Check if the Write falg is set*/
        if ( (ulFlags & i2cFLAG_WRITE) != 0U)
        {
            /* I2C Write command*/
            xReturnVal = CMD_I2C_WRITE;
        }
        /* Check if the read flag is set*/
        else if ( (ulFlags & i2cFLAG_READ) != 0U )
        {
            /* I2C Write then read command*/
            xReturnVal = CMD_I2C_WRITE_THEN_READ;
        }
        else
        {
        	;/*MCDC*/
        }
    }
    return xReturnVal;
}

/*=================================================================================================
 @Service name        prvI2cFiFoWrite
 @Description         This function write the data to be send into the FIFO
 @param[in]           ucChannelId  - Channel ID
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static void prvI2cFiFoWrite(uint8 ucHardwareId)
{
    uint32 ulSEBase = xI2CHwConfig[ucHardwareId].se_base_addr;
    uint32 ulTxWaterMark = REG_INF(ulSEBase, GENI_TX_WATERMARK_REG, TX_WATERMARK);
    uint32 ulTxFifoDepth = REG_INF(ulSEBase, SE_HW_PARAM_0, TX_FIFO_DEPTH);
    uint32 ulBytesToWrite = (ulTxFifoDepth << 2U) - (ulTxWaterMark << 2U);
    uint32 ulWord = 0U;
    uint32 ulLength = 0U;
    uint8  ucWriteCount = 0U;
    uint8  ucChannelId = xI2cSEChannelData[ucHardwareId].ucActiveChannel;
    uint8 *pucBufferPtr = xI2cSEChannelData[ucHardwareId].pucDataPtr +  xI2cSEChannelData[ucHardwareId].ucTransferredLength;
    uint8  ucAddressCount = 0U;
    uint8  ucAddressLength = (uint8)xI2CChannelCfg[ucChannelId].Addressing_Mode;
    uint32 ulAddress = xI2cSEChannelData[ucHardwareId].ulAddress;

    if(xI2cSEChannelData[ucHardwareId].xActiveCommand == I2C_READ_COMMAND)
    {
        /* reset the TX watermark level*/
        REG_OUT(ulSEBase, GENI_TX_WATERMARK_REG,
                                    FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 0));


        for ( ucWriteCount = 0 ; ucWriteCount < ucAddressLength ; ucWriteCount++ )
        {
            ulWord = (ulWord<<8) | ( ulAddress&0xFF);
            ulAddress = ulAddress>>8U;
        }

        REG_OUTI(ulSEBase, GENI_TX_FIFOn, 0, ulWord);
    }
    else if(xI2cSEChannelData[ucHardwareId].xActiveCommand == I2C_WRITE_COMMAND)
    {
    	ulLength = xI2cSEChannelData[ucHardwareId].ucBufferLength;
        /* Check if the data to be write is less then the Fifo size*/
        if (((ulLength + ucAddressLength) - xI2cSEChannelData[ucHardwareId].ucTransferredLength) < ulBytesToWrite)
        {
            /* Calculate the bytes to be write*/
            ulBytesToWrite = ulLength - xI2cSEChannelData[ucHardwareId].ucTransferredLength;
            /* reset the TX watermark level*/
            REG_OUT(ulSEBase, GENI_TX_WATERMARK_REG,
                                        FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 0));
        }

        if(xI2cSEChannelData[ucHardwareId].ucTransferredLength == 0U)
        {
            for ( ucWriteCount = 0U ; ucWriteCount < ucAddressLength ; ucWriteCount++ )
            {
                ulWord = (ulWord<<8U) | ( ulAddress&0xFFU);
                ulAddress = ulAddress>>8U;
            }
        	ucAddressCount = ucAddressLength;
        }
        /* Write the data into FIFO*/
        for (ucWriteCount = ucAddressCount; ucWriteCount < (ulBytesToWrite + ucAddressCount); ucWriteCount++)
        {
            /* Pack the 4 bytes to a single 32 bit. So it can be write directly to TX FIFO */
            if ((ucWriteCount != 0U) && ((ucWriteCount % i2cBYTES_PER_FIFO_REG) == 0U))
            {
                REG_OUTI(ulSEBase, GENI_TX_FIFOn,0, ulWord);
                ulWord = 0U;
            }
            ulWord = ulWord | (pucBufferPtr[(ucWriteCount - ucAddressCount)] <<
                                           ((ucWriteCount % i2cBYTES_PER_FIFO_REG)*i2cBITS_PER_BYTE));
        }
        REG_OUTI(ulSEBase, GENI_TX_FIFOn,0, ulWord);

        /* Update the data count to be transfered*/
        xI2cSEChannelData[ucHardwareId].ucTransferredLength += ulBytesToWrite;
    }
    else
    {
        /* Dummy else */
    }
}

/*=================================================================================================
 @Service name        prvI2cFiFoRead
 @Description         This function read the data from the RX FIFO and copy into the user space
 @param[in]           ucChannelId - Channel ID
 @param[out]          NA
 @param[in, out]      NA
 @return              Initialization status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static void prvI2cFiFoRead(uint8 ucHardwareId)
{
    uint32 ulSEBase = xI2CHwConfig[ucHardwareId].se_base_addr;
    uint32 ulRxFifoStatus = REG_IN(ulSEBase, GENI_RX_FIFO_STATUS);
    uint32 ulBytesToRead = FLD_GET(ulRxFifoStatus, GENI_RX_FIFO_STATUS, RX_FIFO_WC) * i2cBYTES_PER_FIFO_REG;
    uint32 ulTransferedCount = xI2cSEChannelData[ucHardwareId].ucTransferredLength;
    uint32 ulLength = xI2cSEChannelData[ucHardwareId].ucBufferLength;
    uint32 ulWord = 0U;
    uint8  ucReadCount;
    uint8 *pucBufferPtr = xI2cSEChannelData[ucHardwareId].pucDataPtr + ulTransferedCount;
    uint8  ucBytesInLastWord = 0U;

    /* Check if the Last waord is set*/
    if (FLD_GET(ulRxFifoStatus, GENI_RX_FIFO_STATUS, RX_LAST))
    {
        /* Get the last valid byte*/
        ucBytesInLastWord = FLD_GET(ulRxFifoStatus, GENI_RX_FIFO_STATUS, RX_LAST_BYTE_VALID);
        /* update the bytes to read*/
        ulBytesToRead = (ulBytesToRead - i2cBYTES_PER_FIFO_REG) + ucBytesInLastWord;
    }
    /* Check if the Transfer count is less then bytes to read*/
    if ((ulLength - ulTransferedCount) < ulBytesToRead)
    {
        /* Find the bytes to read */
        ulBytesToRead = ulLength - ulTransferedCount;
    }
    /* Read the data*/
    for (ucReadCount = 0U; ucReadCount < ulBytesToRead; ucReadCount++)
    {
        if ((ucReadCount % i2cBYTES_PER_FIFO_REG) == 0U)
        {
            ulWord = REG_INI(ulSEBase, GENI_RX_FIFOn, 0);
        }
        pucBufferPtr[ucReadCount] = (ulWord >> ((ucReadCount % i2cBYTES_PER_FIFO_REG)*i2cBITS_PER_BYTE)) & 0xFF;
    }

    /* Update the transfered count*/
    xI2cSEChannelData[ucHardwareId].ucTransferredLength += ulBytesToRead;

    /*Check if all the requested data is received */
    if(xI2cSEChannelData[ucHardwareId].ucTransferredLength == ulLength)
    {
        REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_LAST_CLEAR_BMSK);
    }
    /* Clear the Watermark status bit*/
    REG_OUT(ulSEBase, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_WATERMARK_CLEAR_BMSK);
}

/*=================================================================================================
 @Service name        prvI2cTransfer
 @Description         This function frame the opcode to be write for the current transfer
 @param[in]           ucChannelId - Channel ID
                      ulLength    - Length of the transfer
                      ulFlag      - Flag information
 @param[out]          pulRegMask  - Pointer to the Register mask
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static void prvI2cTransfer(uint8 ucChannelId, uint32 ulLength, uint32 ulFlag, uint32 *pulRegMask)
{
    i2cMode_e xMode;
    uint32 ulDelayTick;
    uint32 ulRegMask = 0U;
    uint32 ulSEBase;
    uint8 ucHardwareId;
    uint8 ucPreCmdDelay = 0U;

    ucHardwareId = xI2CChannelCfg[ucChannelId].AssignedHwId;
    ulSEBase = xI2CHwConfig[ucHardwareId].se_base_addr;
    ucPreCmdDelay = xI2CChannelCfg[ucChannelId].Delay_PreCmdus;
    xMode = xI2CHwConfig[ucHardwareId].Mode;

    /* Delay tick calculation for the pre-command*/
    ulDelayTick = ((ucPreCmdDelay) * (xI2cClkCfg[xMode].ulSEClockFrequencyHz))/1000000;

    ulRegMask =  ulRegMask | FLD_SET(GENI_M_CMD0, I2C_SLAVE_ADDRESS,
    		xI2CChannelCfg[ucChannelId].SlaveAddress);
    /* Check if the Calculated tick is not 0*/
    if(ulDelayTick != 0U)
    {
        /* TODO : Precommand delay configuration*/
        REG_OUT(ulSEBase, I2C_DELAY_COUNTER,
                         FLD_SET(I2C_DELAY_COUNTER, I2C_DELAY_COUNTER, ulDelayTick));
        ulRegMask =  ulRegMask | FLD_SET(GENI_M_CMD0, I2C_PRE_CMD_DELAY, 1);
    }
    /* Check if the timestamp is requested*/
    if (ulFlag & i2cFLAG_TIMESTAMP)
    {
        /* Check if the requested timestamp is for the START bit */
        if ((ulFlag & i2cFLAG_START) != 0U)
        {
            /* Configure the I2C timestamp before bit */
            ulRegMask = ulRegMask | FLD_SET(GENI_M_CMD0, I2C_TIMESTAMP_BEFORE, 1);
        }
        /* Check if the timestamp is requested for the STOP bit*/
        else if ( (ulFlag & i2cFLAG_STOP) != 0U)
        {
            /* Set the timestamp after bit*/
            ulRegMask = ulRegMask | FLD_SET(GENI_M_CMD0, I2C_TIMESTAMP_AFTER, 1);
        }
    }
    /* Check if the buffer lenght is not zero*/
    if (ulLength!= 0U)
    {
        /* Check if the I2C Stop flag is not requested*/
        if ((ulFlag & i2cFLAG_STOP) != i2cFLAG_STOP)
        {
            /* Enable the I2C Stretch bit*/
            ulRegMask = ulRegMask | FLD_SET(GENI_M_CMD0, I2C_STRETCH, 1);
        }
        /* Check if the I2C START flag not requested*/
        if ((ulFlag & i2cFLAG_START) != i2cFLAG_START)
        {
            /* Enable the Bypass address phase bit*/
            ulRegMask = ulRegMask | FLD_SET(GENI_M_CMD0, I2C_BYPASS_ADDRESS_PHASE, 1);
        }
    }
  *pulRegMask = ulRegMask;
}

/*=================================================================================================
 @Service name        prvI2cChannelIdcheck
 @Description         This function check the validity of the channel ID
                      ucChannelId - Channel ID
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
static i2cStatus_e prvI2cChannelIdcheck(const uint8 ucChannelId)
{
    i2cStatus_e xErrorVal = I2C_SUCCESS;

    if(ucChannelId >= xI2CHwConfig[xI2CChannelCfg[ucChannelId].AssignedHwId].NoOfChannels)
    {
        xErrorVal = I2C_ERROR_INVALID_CHANNEL_ID;
    }
    return xErrorVal;
}

/*=================================================================================================
 @Service name        prvI2cPtrCheck
 @Description         This function check if the passed pointer is NULL or not
 @param[in]           pucDataPtr      - Pointer to be checked
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
static i2cStatus_e prvI2cPtrCheck(uint8 *pucDataPtr)
{
    i2cStatus_e xErrorVal = I2C_SUCCESS;

    if(pucDataPtr == NULL)
    {
        xErrorVal = I2C_ERROR_NULL_PTR;
    }
    return xErrorVal;
}

/*=================================================================================================
 @Service name        prvI2cReadGeniError
 @Description         This functions check if any critical error are there on status register
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              Error status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Asynchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/

static void prvI2cReadGeniError(i2cStatus_e *pxErrorValue, uint8 ucChannelId)
{
    uint8 ucHardwareId = 0x0U;
    uint32 ulSEBase = 0x0U;

    ucHardwareId = xI2CChannelCfg[ucChannelId].AssignedHwId;
    ulSEBase = xI2CHwConfig[ucHardwareId].se_base_addr;

    if(FLD_GET(REG_IN(ulSEBase, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,TX_FIFO_WR_ERR)
        || FLD_GET(REG_IN(ulSEBase, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,RX_FIFO_WR_ERR) )
    {
        *pxErrorValue = I2C_FIFO_WRITE_ERROR;
    }

    if(FLD_GET(REG_IN(ulSEBase, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,TX_FIFO_RD_ERR)
        || FLD_GET(REG_IN(ulSEBase, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,RX_FIFO_RD_ERR) )
    {
        *pxErrorValue = I2C_FIFO_READ_ERROR;
    }

    if(FLD_GET(REG_IN(ulSEBase, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,M_GP_IRQ_3))
    {
        *pxErrorValue = I2C_PROTOCOL_ERROR;
    }

    if(FLD_GET(REG_IN(ulSEBase, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,M_GP_IRQ_1))
    {
        *pxErrorValue = I2C_SLAVE_NACK_ERROR;
    }

    if(FLD_GET(REG_IN(ulSEBase, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,M_GP_IRQ_4))
    {
        *pxErrorValue = I2C_ARBITRATION_LOST_ERROR;
    }

}


/*=================================================================================================
 @Service name        prvI2cWriteErrorcheck
 @Description         This function check for any error for the I2C write function
 @param[in]           ucChannelId  - Channel ID
                      pucDataPtr   - Pointer to store the data to be send
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
static i2cStatus_e prvI2cWriteErrorcheck(const uint8 ucChannelId, uint8 *pucDataPtr)
{
    i2cStatus_e xErrorVal = I2C_SUCCESS;
    uint8 ucHardwareId;

    xErrorVal = I2cInitStatusCheck(xI2CChannelCfg[ucChannelId].AssignedHwId);
    if(xErrorVal == I2C_SUCCESS)
    {
        xErrorVal = prvI2cChannelIdcheck(ucChannelId);
        if(xErrorVal == I2C_SUCCESS)
        {
            xErrorVal = prvI2cPtrCheck(pucDataPtr);
            if(xErrorVal == I2C_SUCCESS)
            {
                ucHardwareId = xI2CChannelCfg[ucChannelId].AssignedHwId;
                /* Need to put SpinLock to avoid data inconsistency*/
                if(xI2cSEChannelData[ucHardwareId].xChannelStatus != I2C_CHANNEL_READY)
                {
                    xErrorVal = I2C_CHANNEL_BUSY;
                }
                else
                {
                    xI2cSEChannelData[ucHardwareId].xChannelStatus =  I2C_CHANNEL_BUSY;
                }
                /*End of SpinLock*/
            }
        }
    }
    return xErrorVal;
}

/*=================================================================================================
 @Service name        prvI2cReadErrorcheck
 @Description         This function check for nay error for the I2C read API
 @param[in]           ucChannelId  - Channel ID
                      pucDataPtr   - Pointer to the read data to be stored
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
static i2cStatus_e prvI2cReadErrorcheck(const uint8 ucChannelId, uint8 *pucDataPtr)
{
    i2cStatus_e xErrorVal = I2C_SUCCESS;
    uint8 ucHardwareId;

    ucHardwareId = xI2CChannelCfg[ucChannelId].AssignedHwId;
    xErrorVal = I2cInitStatusCheck(ucHardwareId);
    if(xErrorVal == I2C_SUCCESS)
    {
        xErrorVal = prvI2cChannelIdcheck(ucChannelId);

        if(xErrorVal == I2C_SUCCESS)
        {
            xErrorVal = prvI2cPtrCheck(pucDataPtr);
            if(xErrorVal == I2C_SUCCESS)
            {
                /* Need to put SpinLock to avoid data inconsistency*/
                if(xI2cSEChannelData[ucHardwareId].xChannelStatus != I2C_CHANNEL_READY)
                {
                    xErrorVal = I2C_CHANNEL_BUSY;
                }
                else
                {
                    xI2cSEChannelData[ucHardwareId].xChannelStatus =  I2C_CHANNEL_BUSY;
                }
                /*End of SpinLock*/
            }
        }
    }

    return xErrorVal;
}

/*=================================================================================================
 @Service name        prvI2CInitErrorCheck
 @Description         This function check and report any Error for the Init function
 @param[in]           ucHardwareId      - HardwareID
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
static i2cStatus_e prvI2CInitErrorCheck(uint8 ucHardwareId)
{
    i2cStatus_e xStatus = I2C_SUCCESS;

    if ( ucHardwareId >= MAX_NO_OF_SERIAL_ENGINE )
    {
        return I2C_HW_NOT_EXIST;
    }
	if(xI2cInitStatus[ucHardwareId] == I2C_INITIALIZED)
	{
		xStatus = I2C_ERROR_ALREADY_INITIALIZED;
	}

    return xStatus;
}

/*========================================================================================================
 @Service name        prvI2cDeInit_Sleep
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           eState -> SLEEP_ENTRY = arg from sleep driver to Deinit PSAIL Driver
                                SLEEP_ABORT = arg from sleep driver in case sleep Driver want to abort sleep
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
 =========================================================================================================*/

void prvI2cDeInit_Sleep( const sleepModeType_e eState )
{
    uint32_t phys_core_id = get_curr_phys_cpu_num();
    if( STR_SLEEP_MODE == eState )
    {
        if ( I2C_SUCCESS == xI2cDeInit(i2cPMIC_PSAIL_HW) )
        {
            if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAck(ulI2cSleepHandle,DRIVER_SLEEP))
            {
                DEBUG_LOG(SAIL_INFO,"prvI2cDeInit_Sleep xSleepDriverAck Success\n\r");
            }else
            {
                DEBUG_LOG(SAIL_ERROR,"prvI2cDeInit_Sleep xSleepDriverAck Failed\n\r");
            }
        }else
        {
            DEBUG_LOG(SAIL_ERROR,"xI2cDeInit Failed\n\r");
        }
    }else
    {
        /* 
        * Directly calling ack back to sleep driver as there is a handshake with AOP
        * which use i2c driver so i2c de-init is not need in case of deep sleep
        */  
        
        if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAck(ulI2cSleepHandle,DRIVER_SLEEP))
        {
            DEBUG_LOG(SAIL_INFO,"prvI2cDeInit_Sleep xSleepDriverAck Success\n\r");
        }else
        {
            DEBUG_LOG(SAIL_ERROR,"prvI2cDeInit_Sleep xSleepDriverAck Failed\n\r");
        }
    }
}

/*=================================================================================================
 @Service name        prvI2cPinCtlReset
 @Description         Reset the Pin configuration of I2c before DeInitialization 
 @param[in]           NA
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
 ================================================================================================*/
static void prvI2cPinCtlReset(uint8 I2cHardwareID)
{
    void *pDTB = NULL;
    int32_t offset = 0; 
    int32_t root_offset = 0;
    const char *path;
    char i2c_name[5] = {'i', '2', 'c','0','\0'};
    uint32_t val_array0[2] = {0};
    int valSize = 2;
    uint8 ucGpioNumbers = 0x0u;
    GPIOConfigType xqupPinCfg = {0x0u};

    pDTB = fdt_get_dtb();
    if (NULL != pDTB)
    {
        root_offset = fdt_path_offset(pDTB, "/aliases");
        i2c_name[3] = (I2cHardwareID + 48);
        path = (const char*)fdt_getprop(pDTB, root_offset, i2c_name , NULL);
        if (path != NULL) 
        {
            offset = fdt_path_offset(pDTB, path);
            path = (char*)fdt_getprop(pDTB, offset, "pinctrl", NULL);
            if( NULL != path)
            {
                offset = fdt_path_offset(pDTB, path);
                (void)fdt_getprop_u32_array(pDTB, offset, "pins", val_array0, &valSize);
                for( int i = 0; i < valSize; i++)
                {
                    ucGpioNumbers    = (uint8)val_array0[i];
                    sail_gpio_config_pin(ucGpioNumbers,I2cResetStatePinCfg[I2cHardwareID][i]);
                }
            }
        } 
    }

}
/* End of File*/
