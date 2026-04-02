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
    File Name          : i2c_el1.c
    Component Name     : I2C EL1 Device driver
    Description        : I2C EL1 Device driver Initial version
    $Header: 
    $DateTime: 
    $Author: 
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "hw_io.h"
#include "cache_ops.h"
#include "debug_log.h"
#include "busywait.h"
#include "Clock.h"
#include "interrupts.h"
#include "common_functions.h"
#include "i2c_el1.h"
#include "qup_common_hwio.h"
#include <libfdt.h>
#include "fdt_utils.h"
#include "sleepEl1.h"
#include "debug_log.h"
#include "FreeRTOSOsal.h"
#include "sailbsp_mutex.h"
#include "err_fatal.h"
#include "gpio.h"

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

/* Throughput for I2c Write  = 60usec/Byte transfer */
/* Throughput for I2c Read  = 70usec/Byte transfer */
/* Worstcase Throughput for I2c Read/Write considered in driver = 100usec/Byte transfer */

/* I2c FIFO Write API will write 64 bytes in one go, 
   considering 100usec time for 1 Byte transfer, 64 bytes needs ~6.4msec.
   Below macro will help to achieve the delay of 7msec with help of vFreeRTOSTaskDelay(1u) 
   to fulfill 6.4msec requirement */
#define I2C_FIFO_WRITE_MAX_TIMEOUT                                        7U

/* For Trasmission of 256 bytes we need delay of ~25.6msec 
   I2c FIFO Write API will be get called 4 times to write 64*4=256 bytes data
   Below macro will help to achieve the run the loop 4 times so 256 bytes successfully
   transmitted */
#define I2C_TRANSFERED_LENGTH_POLLING_COUNTER                             4U

/* For Trasmission of 256 bytes we need delay of ~25.6msec (100usec*256)
   to achieve above delay with help of vFreeRTOSTaskDelay(1u), need to run the counter for 26 times
   Below macro will provide that delay */
#define I2C_MAXIMUM_TIMEOUT                                               26U

/* I2c EL1 critical section macros */
#define  I2C_EL1_CRITCAL_SECTION_START()                            mutex_lock(&stI2cEl1CoreLock)
#define  I2C_EL1_CRITCAL_SECTION_END()                              mutex_unlock(&stI2cEl1CoreLock);
#define  i2cM_IRQ_ERROR_MSK                                         0x3320000EU
#define  i2cS_IRQ_ERROR_MSK                                         0x0300000EU
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
    uint32  SEClockFrequencyHz;
    uint32  BusSpeedKhz;
    uint8   ClkDiv;
    uint8   TCycle;
    uint8   THigh;
    uint8   TLow;
}i2cClockConfigType;

typedef enum
{
    I2C_PING_COMMAND = 0,
    I2C_WRITE_COMMAND,
    I2C_READ_COMMAND
}i2cCommandReq_e;

typedef struct
{
    volatile i2cEl1Status_e      ChannelStatus;
    i2cCommandReq_e              ActiveCommand;
    uint32                       BufferLength;
    uint32                       Address;
    uint32                       TransferredLength;
    uint8                        *I2cDataPtr;
    uint8                        ActiveChannel;
}i2cChannelDataType;

typedef enum
{
    I2c_Transmit = 0,
    I2c_Receive,
    I2c_InvalidOperation = 2
} i2cOperationType;
/*=================================================================================================
**                                        Global variables and constants                         **
=================================================================================================*/

static i2cInitStatusType_e    I2cInitStatus[MAX_NO_OF_SERIAL_ENGINE];
static i2cEl1HwUnitCfgType    I2CHwConfig[MAX_NO_OF_SERIAL_ENGINE];
static i2cEl1ChannelCfgType   I2CChannelCfg[MAX_NO_OF_I2C_EL1_CHANNELS];
static i2cChannelDataType     I2cSEChannelData[MAX_NO_OF_SERIAL_ENGINE];
static uint8                  *I2c_TstSendDataDMA;
static uint32                 QupCommonBase;
static uint8 ChannelNum = 0;

/* Clock settings for the various I2C modes.
    Index 0 - Standard mode
    Index 1 - Fast mode
    Index 2 - Fast Plus Mode  */
static const i2cClockConfigType I2cClkCfg[i2cNUM_MODE] =
{
    // src-freq, speed, div, cycle, high, low
    { 19200000, 100,  7, 26, 10, 11 },
    { 19200000, 400,  2, 24, 5,  12 },
    { 19200000, 1000, 1, 18, 3,  9  }
};

static uint8 *I2c_TstSendDataDMA = (uint8 *) I2C_TX_DMA_ADDR;
static uint8 *I2c_TstRecvDataDMA = (uint8 *) I2C_RX_DMA_ADDR;
static uint32 I2cSleepHandle[MAX_NO_OF_SERIAL_ENGINE];
static GPIOConfigType I2cEl1ResetStatePinCfg[MAX_NO_OF_SERIAL_ENGINE][i2cNUMBER_OF_I2C_PINS] = {0x0u};
mutex_t stI2cEl1CoreLock;
static i2cEl1Status_e i2cOperationStatus = I2C_EL1_SUCCESS;
/*=================================================================================================
**                                        Local function prototypes                              **
=================================================================================================*/
static i2cCmdOpcode_e    I2cGetCmdOpcode (uint32 Flags, uint32 DataLength);
static ClockResult       I2cClockEnable (const i2cEl1HwUnitCfgType *I2cHwConfigPtr);
static i2cEl1Status_e    I2cChannelIdcheck(const uint8 ChannelId);
static i2cEl1Status_e    I2cPtrCheck(uint8 *I2cDataPtr);
static i2cEl1Status_e    I2cInitStatusCheck(uint8 I2cHardwareID);
static i2cEl1Status_e    I2cWriteErrorcheck(const uint8 ChannelId, uint8 *I2cDataPtr);
static i2cEl1Status_e    I2cReadErrorcheck(const uint8 ChannelId, uint8 *I2cDataPtr);
static i2cEl1Status_e    I2CInitErrorCheck(uint8 I2cHardwareID);
static i2cEl1Status_e    I2CLoadConfigurations(uint8 I2cHardwareID);
static ClockResult       I2cClockDisable (const i2cEl1HwUnitCfgType *I2cHwConfigPtr);
static i2cEl1Status_e    I2cSerialEngineInit(const i2cEl1HwUnitCfgType *I2cHwConfigPtr, \
                                          uint32 QupCommonAddr);
static i2cEl1Status_e    I2cSerialEngineDeInit(const i2cEl1HwUnitCfgType *I2cHwConfigPtr, \
                                            uint32 QupCommonAddr);
static void              I2cFiFoRead(uint8 I2cHardwareID);
static void              I2cFiFoWrite(uint8 I2cHardwareID);
static void              I2cReadGeniError(i2cEl1Status_e *StatusPtr, uint8 ChannelId);
static void              I2cDeInit_Sleep(const sleepModeType_e SleepState);
static void              I2cTransfer(uint8 ChannelId, uint32 DataLength, uint32 Flag, \
                                     uint32 *RegMaskPtr);
static void              I2cPinCtlReset(uint8 I2cHardwareID);
static void              I2cErrorHandle(i2cEl1Status_e errorStatus,uint32 I2cHardwareID);
static i2cEl1Status_e    I2cCmdCancleHandle(uint32 ucHardwareId, i2cOperationType operation);
static i2cEl1Status_e    I2cDMAResetHandle(uint32 ucHardwareId, i2cOperationType operation);
static i2cEl1Status_e    I2cCmdAbortHandle(uint32 ucHardwareId, i2cOperationType operation);
/*=================================================================================================
**                                        Interrupt Handler                                      **
=================================================================================================*/

static void I2cGeniSEIsr(void *arg);

/*=================================================================================================
**                                        Global functions definition                            **
=================================================================================================*/

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
i2cEl1Status_e xI2c_EL1_Init(const uint8 I2cHardwareID)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    
    if (I2cHardwareID >= MAX_NO_OF_SERIAL_ENGINE)
    {
        Status = I2C_EL1_HW_NOT_EXIST;
    }
    else
    {
        Status = I2CInitErrorCheck(I2cHardwareID);
        if( I2C_EL1_SUCCESS == Status)
        {
            Status = I2CLoadConfigurations(I2cHardwareID);
            if(Status == I2C_EL1_SUCCESS)
            {
                if ( CLOCK_SUCCESS == I2cClockEnable(&I2CHwConfig[I2cHardwareID]))
                {
                    /* Initialize the Serial Engine*/
                    Status = I2cSerialEngineInit(&I2CHwConfig[I2cHardwareID],
                                                 QupCommonBase);
                    if(Status == I2C_EL1_SUCCESS)
                    {
                        I2cSEChannelData[I2cHardwareID].ChannelStatus  =  I2C_EL1_CHANNEL_READY;
                        I2cInitStatus[I2cHardwareID] = I2C_INITIALIZED;

                        if ( 0x0u == I2cSleepHandle[I2cHardwareID] )
                        {
                            if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1(&I2cDeInit_Sleep,&I2cSleepHandle[I2cHardwareID],get_curr_phys_cpu_num()))
                            {
                                DEBUG_LOG(SAIL_INFO,"I2c%d DeInit_Sleep Sleep Reg Failed\n\r", I2cHardwareID);
                            }
                        }
                    }
                    else
                    {
                        Status = I2C_EL1_NOT_INITIALIZED;
                    }
                }
                else
                {
                    Status = I2C_EL1_ERROR_CLOCK_FAILURE;
                }
            }
        }
        else if(I2C_EL1_ERROR_ALREADY_INITIALIZED == Status)
        {
            Status = I2C_EL1_ERROR_ALREADY_INITIALIZED;
        }
        else
        {
            Status = I2C_EL1_HW_NOT_EXIST;
        }
        mutex_init(&stI2cEl1CoreLock);
    }    
    /* Return the Status*/
    return Status;
}

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


i2cEl1Status_e xI2c_EL1_GetSlaveAddress(uint8 ChannelId , uint8 *pSlaveAddress)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    I2C_EL1_CRITCAL_SECTION_START();

    if(ChannelId < MAX_NO_OF_I2C_EL1_CHANNELS)
    {
        Status = I2cChannelIdcheck(ChannelId);
        if(I2C_EL1_SUCCESS == Status)
        {
            *pSlaveAddress = I2CChannelCfg[ChannelId].SlaveAddress;
        }
    }
    else
    {
        Status = I2C_EL1_ERROR_INVALID_CHANNEL_ID;
    }

    I2C_EL1_CRITCAL_SECTION_END();

    return Status;
}

/*=================================================================================================
 @Service name        xI2cWriteEl1
 @Description         This API shall write the given data into the I2C bus
 @param[in]           ChannelId - Channel ID
                      Address   - Address of the memory to be Write
                      DataLength    - Number of data to write.
                      I2cDataPtr     - Pointer to the data to be write
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
    const uint8 ChannelId,
    uint32 Address,
    uint8 DataLength,
    uint8 *I2cDataPtr)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    i2cCmdOpcode_e CmdOpCode  = CMD_INVALID;
    uint32 RegMask;
    uint32 SEBaseAddr;
    uint32 Flag;
    uint8  I2cHardwareID = 0;
    uint8  I2cCommandLength = 0;
    uint32 Counter = 0;
    uint16 timeoutCounter = 0u;
    uint8  I2cPollingCounter = 0U;

    I2C_EL1_CRITCAL_SECTION_START();
    if(ChannelId < MAX_NO_OF_I2C_EL1_CHANNELS)
    {
        Status = I2cWriteErrorcheck(ChannelId, I2cDataPtr);
        if(Status == I2C_EL1_SUCCESS)
        {
            Flag = i2cFLAG_START | i2cFLAG_STOP | i2cFLAG_WRITE;
            /* Get the command opcode*/
            CmdOpCode = I2cGetCmdOpcode(Flag, DataLength);
            if(CmdOpCode != CMD_INVALID)
            {
                I2cHardwareID = I2CChannelCfg[ChannelId].AssignedHwId;
                SEBaseAddr = I2CHwConfig[I2cHardwareID].se_base_addr;
                /* Call the I2C Transfer function */
                I2cTransfer(ChannelId, DataLength,Flag, &RegMask);
                /* Write the Opcode and PARAM content*/
                REG_OUT(SEBaseAddr, GENI_M_CMD0, FLD_SET(GENI_M_CMD0, OPCODE, CmdOpCode) |
                                             FLD_SET(GENI_M_CMD0, PARAM,  RegMask));
                /* Check if the Opcode is for I2C Write. Note. I2C Write will be returned when
                   buffer length is not 0.*/
                if(CmdOpCode == CMD_I2C_WRITE)
                {
                    /* Configure the buffer length*/
                    REG_OUT(SEBaseAddr, I2C_TX_TRANS_LEN, (DataLength + (uint8)I2CChannelCfg[ChannelId].Addressing_Mode));
                    I2cSEChannelData[I2cHardwareID].BufferLength = DataLength;
                    I2cSEChannelData[I2cHardwareID].Address = Address;
                    I2cSEChannelData[I2cHardwareID].TransferredLength = 0;
                    I2cSEChannelData[I2cHardwareID].I2cDataPtr = I2cDataPtr;
                    I2cSEChannelData[I2cHardwareID].ActiveCommand = I2C_WRITE_COMMAND;
                    I2cSEChannelData[I2cHardwareID].ActiveChannel = ChannelId;
                    /* Check if the FIFO mode is configured*/
                    if(I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_POLLING_MODE)
                    {
                        /* Continue to send the data till all the requested number of data is transferred*/
                        /* loop will terminate when data is transmited successfully or timeout reached (timeout = ~25600us/25.6ms for 256bytes transfer)*/
                        do
                        {
                            REG_OUTF(SEBaseAddr, GENI_M_IRQ_CLEAR,M_CMD_DONE_CLEAR,1);
                            /* Write the Data into the TX FIFO*/
                            I2cFiFoWrite(I2cHardwareID);
                            while((FLD_GET(REG_IN(SEBaseAddr, GENI_TX_FIFO_STATUS), GENI_TX_FIFO_STATUS, TX_AFIFO_WC) != 0U) && \
                            (timeoutCounter < I2C_FIFO_WRITE_MAX_TIMEOUT))
                            {
                                /* Delay of ~6.4ms for transimmision of 64 bytes(Max supported) in prvI2cFiFoWriteEl1 call*/
                                /* 1ms of vFreeRTOSTaskDelay*/
                                vFreeRTOSTaskDelay(1u);
                                timeoutCounter++;
                            }
                            if((timeoutCounter >= I2C_FIFO_WRITE_MAX_TIMEOUT) && \
                            (FLD_GET(REG_IN(SEBaseAddr, GENI_TX_FIFO_STATUS), GENI_TX_FIFO_STATUS, TX_AFIFO_WC) != 0U))
                            {
                                Status = I2C_EL1_ERROR_TIMEOUT;
                                /* I2c Transfer unsuccessful & timeout occured, make I2c Channel ready for next transfer */
                                I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                                goto end;
                            }
                            else
                            {
                                I2cPollingCounter++;
                            }
                        }while((I2cSEChannelData[I2cHardwareID].TransferredLength < I2cSEChannelData[I2cHardwareID].BufferLength) && \
                        (I2cPollingCounter < I2C_TRANSFERED_LENGTH_POLLING_COUNTER));

                        if((FLD_GET(REG_IN(SEBaseAddr, GENI_TX_FIFO_STATUS), GENI_TX_FIFO_STATUS, TX_AFIFO_WC) != 0U) || \
                           (I2cSEChannelData[I2cHardwareID].TransferredLength < I2cSEChannelData[I2cHardwareID].BufferLength))
                        {
                            Status = I2C_EL1_ERROR_TIMEOUT;
                            /* I2c Transfer unsuccessful & timeout occured, make I2c Channel ready for next transfer */
                            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                            goto end;
                        }

                        timeoutCounter = 0u;
                        /* Worst case Delay of ~25.6ms to get the M_CMD_DONE set, in ideal scenario it wont take Delay of ~25.6ms to set M_CMD_DONE*/
                        /* Timeout check here is preacautionary to remove infinite loop scenario */
                        while((FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS, M_CMD_DONE) != 1U) && \
                        (timeoutCounter < I2C_MAXIMUM_TIMEOUT))
                        {
                                /* 1ms of vFreeRTOSTaskDelay*/
                                vFreeRTOSTaskDelay(1u);
                                timeoutCounter++;
                        }
                        /* while doing the I2C transfers(Write/read)in between the transfer, explicitly 
                           connecting the I2C SDA line to ground(to create ARB loss error). when this happened 
                           we are expecting the ARB LOST and GSI channels to move in error state. 
                           But ARB lost updated in GENI register but CMD_FAILURE is not reported.
                           We can not only depend on M_CMD_DONE value and need to check for other errors like ARB lost etc */
                        I2cReadGeniError(&Status,ChannelId);
                        if ( I2C_EL1_SUCCESS != Status )
                        {
                            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                            /* Clear any pending IRQs */
                            REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
                            goto end;
                        }

                        if(FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS, M_CMD_DONE) != 1U)
                        {
                            Status = I2C_EL1_ERROR_TIMEOUT;
                            /* I2c Transfer unsuccessful due to timeout, make I2c Channel ready for next transfer */
                            I2cSEChannelData[I2cHardwareID].ChannelStatus = I2C_EL1_CHANNEL_READY;
                            goto end;
                        }

                        REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS));
                        /* I2c Transfer successful, make I2c Channel ready for next transfer */
                        I2cSEChannelData[I2cHardwareID].ChannelStatus = I2C_EL1_CHANNEL_READY;
                    }
                    else if(I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_FIFO_MODE)
                    {
                        /* Enable the TX watermark level as 1. So as soon as interrupt is enabled the
                           ISR will hit and in ISR the FIFO will be updated.*/
                        REG_OUT(SEBaseAddr, GENI_TX_WATERMARK_REG,
                                     FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 1));
                    }
                    else
                    {
                        I2cCommandLength = (uint8)I2CChannelCfg[ChannelId].Addressing_Mode;
                        for(Counter = 0;Counter < (I2cCommandLength + DataLength);Counter++)
                        {
                            if(Counter < I2cCommandLength)
                            {
                                I2c_TstSendDataDMA[Counter] = ((Address >> (Counter*8U)) & 0xFFU);
                            }
                            else
                            {
                                I2c_TstSendDataDMA[Counter] = I2cDataPtr[Counter-I2cCommandLength];
                            }
                        }
                        /* Set the Granularity for the DMA mode. Fixed 4x8 */
                        REG_OUT(SEBaseAddr, GENI_BYTE_GRANULARITY,
                            FLD_SET(GENI_BYTE_GRANULARITY, GENI_BYTE_GRANULARITY, 0));
                        /* Update the buffer address that needs to be transfered*/
                        REG_OUT(SEBaseAddr,DMA_TX_PTR_L,
                             FLD_SET(DMA_TX_PTR_L,TX_PTR_L,I2c_TstSendDataDMA));
                        REG_OUT(SEBaseAddr,DMA_TX_PTR_H,
                             FLD_SET(DMA_TX_PTR_H,TX_PTR_H,0));
                        /* Set the End of Transfer attribute.*/
                        REG_OUT(SEBaseAddr,DMA_TX_ATTR,
                             FLD_SET(DMA_TX_ATTR,EOT,1));
                        /* Configure the buffer length*/
                        REG_OUT(SEBaseAddr,DMA_TX_LENGTH,
                             FLD_SET(DMA_TX_LENGTH,TX_LENGTH,(DataLength + I2cCommandLength)));
                    }
                    /*
                     * wait till ISR routine updates i2c channel status to Ready for subsequent I2c operations
                     * considering worstcase scenario delay of 26ms (100usec*256bytes) if datalength for read/write is 256 bytes.
                    */
                    if(I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_FIFO_MODE || I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_DMA_MODE)
                    {
                        timeoutCounter = 0u;
                        do
                        {
                            vFreeRTOSTaskDelay(1u);
                            timeoutCounter++;
                        }while((I2cSEChannelData[I2cHardwareID].ChannelStatus  ==  I2C_EL1_CHANNEL_BUSY) && \
                        (timeoutCounter < I2C_MAXIMUM_TIMEOUT));
                        if(I2cSEChannelData[I2cHardwareID].ChannelStatus ==  I2C_EL1_CHANNEL_READY)
                        {
                            // Due to error in communication i2cOperationStatus will be set to error occured in transmission.
                            // If i2cOperationStatus is not I2C_EL1_SUCCESS, report transmission error to application
                            if((i2cOperationStatus != I2C_EL1_SUCCESS))
                            {
                                Status = i2cOperationStatus;
                                // reset the i2cOperationStatus to I2C_EL1_SUCCESS
                                i2cOperationStatus = I2C_EL1_SUCCESS;
                                goto end;
                            }
                            else
                            {
                                Status = I2C_EL1_SUCCESS;
                                goto end;
                            }
                        }
                        if(I2cSEChannelData[I2cHardwareID].ChannelStatus  ==  I2C_EL1_CHANNEL_BUSY)
                        {
                            Status = I2C_EL1_ERROR_TIMEOUT;
                            /* I2c Interrupt not received, make I2c Channel ready for next transfer */
                            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                            goto end;
                        }
                    }
                }
            }
            else
            {
                Status = I2C_EL1_ERROR_INVALID_OPCODE;
            }
        }
    }
    else
    {
        Status = I2C_EL1_ERROR_INVALID_CHANNEL_ID;
    }

end:
    I2C_EL1_CRITCAL_SECTION_END();
    return Status;
}

/*=================================================================================================
 @Service name        xI2cReadEl1
 @Description         This API shall read the data from the I2c bus
 @param[in]           ChannelId     - Channel ID
                      Address       - Address of the memory to be read
                      DataLength        - Number of data to read.
 @param[out]          I2cDataPtr      - Pointer to the read data to be stored
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
    const uint8 ChannelId,
    uint32 Address,
    uint8 DataLength,
    uint8 *I2cDataPtr)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    i2cCmdOpcode_e CmdOpCode = CMD_INVALID;
    uint32 RegMask;
    uint32 SEBaseAddr;
    uint32 Flag;
    uint8 I2cHardwareID;
    uint8 Counter;
    uint16 timeoutCounter = 0u;

    I2C_EL1_CRITCAL_SECTION_START();
    if(ChannelId < MAX_NO_OF_I2C_EL1_CHANNELS)
    {
        Status = I2cReadErrorcheck(ChannelId, I2cDataPtr);
        
        if(Status == I2C_EL1_SUCCESS)
        {
            Flag = i2cFLAG_START | i2cFLAG_STOP | i2cFLAG_READ;
            /* Get the command Opcode*/
            CmdOpCode = I2cGetCmdOpcode(Flag, DataLength);
            if(CmdOpCode != CMD_INVALID)
            {
                I2cHardwareID = I2CChannelCfg[ChannelId].AssignedHwId;
                SEBaseAddr = I2CHwConfig[I2cHardwareID].se_base_addr;
                I2cTransfer(ChannelId, DataLength,Flag, &RegMask);
                /* Write the Opcode and PARAM content*/
                REG_OUT(SEBaseAddr, GENI_M_CMD0, FLD_SET(GENI_M_CMD0, OPCODE, CmdOpCode) |
                                                              FLD_SET(GENI_M_CMD0, PARAM,  RegMask));
                if(CmdOpCode == CMD_I2C_WRITE_THEN_READ)
                {
                    I2cSEChannelData[I2cHardwareID].BufferLength = DataLength;
                    I2cSEChannelData[I2cHardwareID].Address = Address;
                    I2cSEChannelData[I2cHardwareID].TransferredLength = 0;
                    I2cSEChannelData[I2cHardwareID].I2cDataPtr = I2cDataPtr;
                    I2cSEChannelData[I2cHardwareID].ActiveCommand = I2C_READ_COMMAND;
                    I2cSEChannelData[I2cHardwareID].ActiveChannel = ChannelId;
                    /* Configure the Tx buffer length*/
                    REG_OUT(SEBaseAddr, I2C_TX_TRANS_LEN,
                            I2CChannelCfg[ChannelId].Addressing_Mode);
                    /* Update the Rx buffer length*/
                    REG_OUT(SEBaseAddr, I2C_RX_TRANS_LEN, DataLength);
                    if(I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_POLLING_MODE)
                    {
                        REG_OUTF(SEBaseAddr, GENI_M_IRQ_CLEAR,M_CMD_DONE_CLEAR,1);
                        I2cFiFoWrite(I2cHardwareID);
                        while((FLD_GET(REG_IN(SEBaseAddr, GENI_TX_FIFO_STATUS), GENI_TX_FIFO_STATUS, TX_AFIFO_WC) != 0U) && \
                        (timeoutCounter < I2C_FIFO_WRITE_MAX_TIMEOUT))
                        {
                            /* Delay of ~6.4ms for transimmision of 64 bytes(Max supported) in prvI2cFiFoWriteEl1 call*/
                            /* 1ms of vFreeRTOSTaskDelay*/
                            vFreeRTOSTaskDelay(1u);
                            timeoutCounter++;
                        }

                        if(FLD_GET(REG_IN(SEBaseAddr, GENI_TX_FIFO_STATUS), GENI_TX_FIFO_STATUS, TX_AFIFO_WC) != 0U)
                        {
                            Status = I2C_EL1_ERROR_TIMEOUT;
                            /* I2c Transfer unsuccessful & timeout occured, make I2c Channel ready for next transfer */
                            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                            goto end;
                        }

                        timeoutCounter = 0U;
                        do
                        {
                            /*
                             * I2c shouldn't block the next transaction on any same/any other slave connected to I2c bus . 
                             * Hence, making that channel active if I2c driver is seeing any error on channel so
                             * that next transaction on same or any other slave won't get block
                             */
                            I2cReadGeniError(&Status,ChannelId);
                            if ( I2C_EL1_SUCCESS != Status )
                            {
                                I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                                /* Clear any pending IRQs */
                                REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
                                goto end;
                            }

                            /* Read the Data from the RX FIFO*/
                            I2cFiFoRead(I2cHardwareID);
                            REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS));
                            /* Delay of ~25.6ms for Reading of 256 bytes(Max supported) in prvI2cFiFoReadEl1 call*/
                            /* 1ms of TaskDelay*/
                            vFreeRTOSTaskDelay(1u);
                            timeoutCounter++;
                        }while((I2cSEChannelData[I2cHardwareID].TransferredLength < I2cSEChannelData[I2cHardwareID].BufferLength) && \
                        (timeoutCounter < I2C_MAXIMUM_TIMEOUT));

                        if(I2cSEChannelData[I2cHardwareID].TransferredLength < I2cSEChannelData[I2cHardwareID].BufferLength)
                        {
                            Status = I2C_EL1_ERROR_TIMEOUT;
                            /* I2c Read unsuccessful & timeout occured, make I2c Channel ready for next transfer */
                            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                            goto end;
                        }
                        I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                    }
                    /* Check if the configure mode is FIFO*/
                    else if(I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_FIFO_MODE)
                    {
                        REG_OUT(SEBaseAddr, GENI_RX_WATERMARK_REG,
                                        FLD_SET(GENI_RX_WATERMARK_REG, RX_WATERMARK, 0));
                        REG_OUT(SEBaseAddr, GENI_TX_WATERMARK_REG,
                                        FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 1));
                    }
                    else
                    {
                        for(Counter = 0U;Counter < (uint8)I2CChannelCfg[ChannelId].Addressing_Mode;Counter++)
                        {
                            I2c_TstSendDataDMA[Counter] = ((Address >> (Counter*8U)) & 0xFFU);
                        }
                        /* Update the buffer address that needs to be updated*/
                        REG_OUT(SEBaseAddr,DMA_RX_PTR_L,
                              FLD_SET(DMA_RX_PTR_L,RX_PTR_L,I2c_TstRecvDataDMA));
                        REG_OUT(SEBaseAddr,DMA_RX_PTR_H,
                              FLD_SET(DMA_RX_PTR_H,RX_PTR_H,0));
                        /* reset the DMA RX attribute*/
                        REG_OUT(SEBaseAddr,DMA_RX_ATTR,0);
                        /* update the buffer length for the DMA transfer*/
                        REG_OUT(SEBaseAddr,DMA_RX_LENGTH,
                              FLD_SET(DMA_RX_LENGTH,RX_LENGTH,DataLength));

                        /* Update the buffer address that needs to be transfered*/
                        REG_OUT(SEBaseAddr,DMA_TX_PTR_L,
                              FLD_SET(DMA_TX_PTR_L,TX_PTR_L,I2c_TstSendDataDMA));
                        REG_OUT(SEBaseAddr,DMA_TX_PTR_H,
                              FLD_SET(DMA_TX_PTR_H,TX_PTR_H,0));
                        /* Set the End of Transfer attribute.*/
                        REG_OUT(SEBaseAddr,DMA_TX_ATTR,
                              FLD_SET(DMA_TX_ATTR,EOT,1));
                        /* Configure the buffer length*/
                        REG_OUT(SEBaseAddr,DMA_TX_LENGTH,
                              FLD_SET(DMA_TX_LENGTH,TX_LENGTH,
                                      I2CChannelCfg[ChannelId].Addressing_Mode));
                    }
                    /*
                     * wait till ISR routine updates i2c channel status to Ready for subsequent I2c operations
                     * considering worstcase scenario delay of 26ms (100usec*256bytes) if datalength for read/write is 256 bytes.
                    */
                    timeoutCounter = 0u;
                    if(I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_FIFO_MODE || I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_DMA_MODE)
                    {
                        do
                        {
                            vFreeRTOSTaskDelay(1u);
                            timeoutCounter++;
                        }while((I2cSEChannelData[I2cHardwareID].ChannelStatus  ==  I2C_EL1_CHANNEL_BUSY) && \
                        (timeoutCounter < I2C_MAXIMUM_TIMEOUT)); 
                        if(I2cSEChannelData[I2cHardwareID].ChannelStatus ==  I2C_EL1_CHANNEL_READY)
                        {
                            // Due to error in communication i2cOperationStatus will be set to error occured in reception.
                            // If i2cOperationStatus is not I2C_EL1_SUCCESS, report reception error to application
                            if((i2cOperationStatus != I2C_EL1_SUCCESS))
                            {
                                Status = i2cOperationStatus;
                                // reset the i2cOperationStatus to I2C_EL1_SUCCESS
                                i2cOperationStatus = I2C_EL1_SUCCESS;
                                goto end;
                            }
                            else
                            {
                                Status = I2C_EL1_SUCCESS;
                                goto end;
                            }
                        }
                        if(I2cSEChannelData[I2cHardwareID].ChannelStatus  ==  I2C_EL1_CHANNEL_BUSY)
                        {
                            Status = I2C_EL1_ERROR_TIMEOUT;
                            /* I2c Interrupt not received, make I2c Channel ready for next transfer */
                            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                            goto end;
                        }
                    }
                }
            }
        }
    }
    else
    {
        Status = I2C_EL1_ERROR_INVALID_CHANNEL_ID;
    }

end:
    I2C_EL1_CRITCAL_SECTION_END();
    return Status;
}

/*=================================================================================================
 @Service name        xI2cDeInitEl1
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
i2cEl1Status_e xI2c_EL1_DeInit( uint8 I2cHardwareID)
{
    i2cEl1Status_e Status = I2C_EL1_NOT_INITIALIZED;
    I2C_EL1_CRITCAL_SECTION_START();
    if ( I2cHardwareID >= MAX_NO_OF_SERIAL_ENGINE )
    {
        Status = I2C_EL1_HW_NOT_EXIST;
        goto end;
    }
    if( I2cInitStatus[I2cHardwareID] == I2C_INITIALIZED)
    {
        /* Disable the QuPV3 clocks*/
        if ( CLOCK_SUCCESS == I2cClockDisable(&I2CHwConfig[I2cHardwareID]) )
        {
            /* DeInitialize the Serial Engine*/
            Status = I2cSerialEngineDeInit(&I2CHwConfig[I2cHardwareID], QupCommonBase);
            /* I2c PinCtl Resets */
            I2cPinCtlReset(I2cHardwareID);
            I2cSEChannelData[I2cHardwareID].ChannelStatus      = I2C_EL1_CHANNEL_INACTIVE;
            I2cSEChannelData[I2cHardwareID].ActiveCommand      = I2C_PING_COMMAND;
            I2cSEChannelData[I2cHardwareID].BufferLength       = 0U;
            I2cSEChannelData[I2cHardwareID].Address            = 0U;
            I2cSEChannelData[I2cHardwareID].TransferredLength  = 0U;
            I2cSEChannelData[I2cHardwareID].I2cDataPtr         = NULL;
            I2cSEChannelData[I2cHardwareID].ActiveChannel      = 0U;
            I2cInitStatus[I2cHardwareID] = I2C_UNINITIALIZED;
            Status = I2C_EL1_SUCCESS;
            ChannelNum = ChannelNum - I2CHwConfig[I2cHardwareID].NoOfChannels;
        }
        else
        {
            Status = I2C_EL1_ERROR_CLOCK_FAILURE;
        }
    }

end:
    /* Return the Status*/
    I2C_EL1_CRITCAL_SECTION_END();
    return Status;
}


/*=================================================================================================
 @Service name        xI2cPingStatusFromSlaveEl1
 @Description         This function is used to get ping from slave connected to I2C bus
 @param[in]           ChannelId -> Channel Id of Slave connected
                      I2cHardwareID -> HW channel of particular SE
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

i2cEl1Status_e xI2c_EL1_PingStatusFromSlave( uint8 ChannelId , uint8 I2cHardwareID)
{
    uint8 SlaveAddress = 0x0;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    uint32 Flag = i2cFLAG_START;
    i2cCmdOpcode_e CmdOpCode  = CMD_INVALID;
    uint32 DataLength = 0x0;
    uint32 SEBaseAddr = 0x0;
    uint32 CmdDoneStatus = 0x0;
    uint8  PollingTimeOut = 0x0;

    I2C_EL1_CRITCAL_SECTION_START();
    if(ChannelId < MAX_NO_OF_I2C_EL1_CHANNELS)
    {
        Status = I2cChannelIdcheck(ChannelId);
        
        if ( I2C_EL1_SUCCESS == Status )
        {
            CmdOpCode = I2cGetCmdOpcode(Flag,DataLength);
            if ( CmdOpCode != CMD_INVALID )
            {
                if(I2cHardwareID != I2CChannelCfg[ChannelId].AssignedHwId)
                {
                    Status = I2C_EL1_ERROR_INVALID_HW_ID;
                }
                else
                {
                    SEBaseAddr = I2CHwConfig[I2cHardwareID].se_base_addr;

                    SlaveAddress = I2CChannelCfg[ChannelId].SlaveAddress;

                    REG_OUT(SEBaseAddr, GENI_M_CMD0, FLD_SET(GENI_M_CMD0, OPCODE, CmdOpCode) |
                                                FLD_SET(GENI_M_CMD0, PARAM,  SlaveAddress<<9));
                    CmdDoneStatus = REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS);

                    while(FLD_GET(CmdDoneStatus, GENI_M_IRQ_STATUS,M_CMD_DONE)!= 0x1u && PollingTimeOut<=i2cMaxPollingTime)
                    {
                        busywait(100);
                        CmdDoneStatus = REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS);
                        PollingTimeOut++;
                    }

                    I2cReadGeniError(&Status,ChannelId);

                    REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
                }

            }
        }
    }
    else
    {
        Status = I2C_EL1_ERROR_INVALID_CHANNEL_ID;
    }
    I2C_EL1_CRITCAL_SECTION_END();
    return Status;
}


/*=================================================================================================
**                                        Interrupt Handler                                      **
=================================================================================================*/

/*=================================================================================================
 @Service name        prvI2cGeniSEIsrEl1_CB
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

static void I2cGeniSEIsr_CB(
    void *arg)
{
    i2cEl1Status_e RxStatus = I2C_EL1_UNKNOWN_FAILURE;
    i2cEl1Status_e TxStatus = I2C_EL1_UNKNOWN_FAILURE;
    uint32 I2c_IrqStatusM;
    uint32 I2c_IrqStatusS;
    uint32 Dma_TxIrqStatus;
    uint32 Dma_RxIrqStatus;
    uint32 SEBaseAddr;
    uint32 I2cHardwareID = 0;
    uint8  counter = 0U;
    i2cEl1Status_e lStatus = I2C_EL1_UNKNOWN_FAILURE;

    I2cHardwareID = (uint32)arg;

    if(I2cInitStatusCheck(I2cHardwareID) == I2C_EL1_SUCCESS)
    {
        /* Get the Serial engine base address*/
        SEBaseAddr = I2CHwConfig[I2cHardwareID].se_base_addr;

        /* Read the IRQ status register*/
        I2c_IrqStatusM = REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS);

        I2c_IrqStatusS = REG_IN(SEBaseAddr, GENI_S_IRQ_STATUS);

        if((I2c_IrqStatusM & i2cM_IRQ_ERROR_MSK) != 0U)
        {
            if(FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, M_CMD_FAILURE) != 0U)
            {
                lStatus = I2C_EL1_ERROR_M_CMD_FAILURE;
            }
            if(FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, M_ILLEGAL_CMD) != 0U)
            {
                lStatus = I2C_EL1_ERROR_M_CMD_ILLEGAL;
            }
            if(FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, M_CMD_OVERRUN) != 0U)
            {
                lStatus = I2C_EL1_ERROR_M_CMD_OVERRUN;
            }
            if(FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, TX_FIFO_RD_ERR) != 0U)
            {
                lStatus = I2C_EL1_ERROR_TX_FIFO_RD_ERR;
            }
            if(FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, TX_FIFO_WR_ERR) != 0U)
            {
                lStatus = I2C_EL1_ERROR_TX_FIFO_WR_ERR;
            }
            if(FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, RX_FIFO_RD_ERR) != 0U)
            {
                lStatus = I2C_EL1_ERROR_RX_FIFO_RD_ERR;
            }
            if(FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, RX_FIFO_WR_ERR) != 0U)
            {
                lStatus = I2C_EL1_ERROR_RX_FIFO_WR_ERR;
            }

            I2cErrorHandle(lStatus, I2cHardwareID);
            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
            i2cOperationStatus = lStatus;
        }
        else if((I2c_IrqStatusS & i2cS_IRQ_ERROR_MSK) != 0U)
        {
            if(FLD_GET(I2c_IrqStatusS, GENI_S_IRQ_STATUS, S_CMD_FAILURE) != 0U)
            {
                lStatus = I2C_EL1_ERROR_S_CMD_FAILURE;
            }
            if(FLD_GET(I2c_IrqStatusS, GENI_S_IRQ_STATUS, S_ILLEGAL_CMD) != 0U)
            {
                lStatus = I2C_EL1_ERROR_S_CMD_ILLEGAL;
            }
            if(FLD_GET(I2c_IrqStatusS, GENI_S_IRQ_STATUS, S_CMD_OVERRUN) != 0U)
            {
                lStatus = I2C_EL1_ERROR_S_CMD_OVERRUN;
            }
            if(FLD_GET(I2c_IrqStatusS, GENI_S_IRQ_STATUS, RX_FIFO_RD_ERR) != 0U)
            {
                lStatus = I2C_EL1_ERROR_RX_FIFO_RD_ERR;
            }
            if(FLD_GET(I2c_IrqStatusS, GENI_S_IRQ_STATUS, RX_FIFO_WR_ERR) != 0U)
            {
                lStatus = I2C_EL1_ERROR_RX_FIFO_WR_ERR;
            }

            I2cErrorHandle(lStatus, I2cHardwareID);
            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
            i2cOperationStatus = lStatus;
        }
        else 
        {
         /* Check for FIFO interrupt*/
            if(I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_FIFO_MODE)
        {
            /* Check if the interrupt is due to RX FIFO Watermark level */
            if (FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, RX_FIFO_WATERMARK) != 0U)
            {
                /* Call the FIFO read function to read data from the RX FIFO*/
                    I2cFiFoRead(I2cHardwareID);
                /* Set the status as I2C_EL1_TRANSFER_SUCCESS*/
                RxStatus = I2C_EL1_TRANSFER_ONGOING;
            }
            /* Check if the interrupt is due to TX Watermark level*/
            if (FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, TX_FIFO_WATERMARK) != 0U)
            {
                /* Call the FIFO write function to write data to the FIFO*/
                    I2cFiFoWrite(I2cHardwareID);
                /* Set the status as I2C_EL1_TRANSFER_SUCCESS*/
                TxStatus = I2C_EL1_TRANSFER_ONGOING;
            }

            /* Check if the interrupt due to command done*/
            if (FLD_GET(I2c_IrqStatusM, GENI_M_IRQ_STATUS, M_CMD_DONE) != 0U)
            {
                if(FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,M_GP_IRQ_1))
                {
                    // Do nothing
                }
                else
                {
                    /* Set the status as I2C_EL1_TRANSFER_SUCCESS*/
                    TxStatus = I2C_EL1_TRANSFER_SUCCESS;
                    RxStatus = I2C_EL1_TRANSFER_SUCCESS;
                }
            }

            }
            else if(I2CHwConfig[I2cHardwareID].Access_Mode == I2C_EL1_DMA_MODE)
            {
                /* Read the DMA interrupt status register*/
                Dma_TxIrqStatus = REG_IN(SEBaseAddr, DMA_TX_IRQ_STAT);
                Dma_RxIrqStatus = REG_IN(SEBaseAddr, DMA_RX_IRQ_STAT);

                if((FLD_GET(Dma_TxIrqStatus, DMA_TX_IRQ_STAT, SBE) != 0U))
                {
                    lStatus = I2C_EL1_ERROR_TX_SBE;
                    I2cErrorHandle(lStatus, I2cHardwareID);
                    I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                    i2cOperationStatus = lStatus;
                } 
                else if((FLD_GET(Dma_RxIrqStatus, DMA_RX_IRQ_STAT, SBE) != 0U))
                {
                    lStatus = I2C_EL1_ERROR_RX_SBE;
                    I2cErrorHandle(lStatus, I2cHardwareID);
                    I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
                    i2cOperationStatus = lStatus;
                }
                else
                {
                    /* Check if the TX DMA done*/
                    if(FLD_GET(Dma_TxIrqStatus, DMA_TX_IRQ_STAT, DMA_DONE) != 0U)
                    {
                        /* Set the status to success*/
                        TxStatus = I2C_EL1_TRANSFER_SUCCESS;
                    }
                    /* Check if the RX DMA done*/
                    if(FLD_GET(Dma_RxIrqStatus, DMA_RX_IRQ_STAT, DMA_DONE) != 0U)
                    {
                        /* Set the status to success*/
                        for(counter=0; counter < I2cSEChannelData[I2cHardwareID].BufferLength;counter++)
                        {
                            I2cSEChannelData[I2cHardwareID].I2cDataPtr[counter] = I2c_TstRecvDataDMA[counter];
                        }
                RxStatus = I2C_EL1_TRANSFER_SUCCESS;
            }
            else
            {
                /* Misra*/
            }
            if(Dma_TxIrqStatus != 0U)
            {
              /* Clear the Interrupt flag*/
              REG_OUT(SEBaseAddr, DMA_TX_IRQ_CLR, Dma_TxIrqStatus);
            }
            if(Dma_RxIrqStatus != 0U)
            {
              /* Clear the Interrupt flag*/
              REG_OUT(SEBaseAddr, DMA_RX_IRQ_CLR, Dma_RxIrqStatus);
            }
        }
            }
            else
            {
                ; /*MCDC*/
            }
        }

        /* Clear all the GENI_M_IRQ*/
        if(I2c_IrqStatusM != 0U)
        {
            /* Clear the Interrupt flag*/
            REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, I2c_IrqStatusM);
        }
        /* Clear all the GENI_M_IRQ*/
        if(I2c_IrqStatusS != 0U)
        {
            /* Clear the Interrupt flag*/
            REG_OUT(SEBaseAddr, GENI_S_IRQ_CLEAR, I2c_IrqStatusS);
        }

        if(I2cSEChannelData[I2cHardwareID].ActiveCommand == I2C_WRITE_COMMAND && TxStatus == I2C_EL1_TRANSFER_SUCCESS)
        {
            /* Notification function call needs to be added*/
            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
        }
        if(I2cSEChannelData[I2cHardwareID].ActiveCommand == I2C_READ_COMMAND && RxStatus == I2C_EL1_TRANSFER_SUCCESS)
        {
            /* Notification function call needs to be added*/
            I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_READY;
        }

    }
}

static void I2cGeniSEIsr(
    void *arg)
{
    /* Freertos ISR handles FPU registers save/restore. */
    I2cGeniSEIsr_CB(arg);
}

/*=================================================================================================
**                                        Local function definitions                             **
=================================================================================================*/
/*=================================================================================================
 @Service name        prvI2CLoadConfigurationseEl1
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


static i2cEl1Status_e I2CLoadConfigurations(uint8 I2cHardwareID)
{
    i2cEl1Status_e Status = I2C_EL1_HW_NOT_ENABLED;
    int32_t offset = 0, root_offset = 0;
	const char *path;
	uint32_t slave_array[MAX_NO_OF_I2C_EL1_CHANNELS] = {0};
	uint32_t mode_array[MAX_NO_OF_I2C_EL1_CHANNELS] = {0};
	uint32_t delay_array[MAX_NO_OF_I2C_EL1_CHANNELS] = {0};
	uint32_t ts_array[MAX_NO_OF_I2C_EL1_CHANNELS] = {0};
	int Size = MAX_NO_OF_I2C_EL1_CHANNELS;
    int valSize_st = 5;
    uint32_t val_array0[i2cNUMBER_OF_I2C_PINS] = {0};
    uint32_t val_array1[i2cNUMBER_OF_I2C_PINS] = {0};
    uint32_t val_array2[i2cNUMBER_OF_I2C_PINS] = {0};
    uint32_t val_array3[i2cNUMBER_OF_I2C_PINS] = {0};
    uint32_t val_array4[i2cNUMBER_OF_I2C_PINS] = {0};
    int valSize = i2cNUMBER_OF_I2C_PINS;
    char i2c_name[5] = {'i', '2', 'c','0','\0'};
    GPIOConfigType QupPinCfg = {0x0u};
    uint8 GpioNumber = 0x0u;
    void *pDTB = NULL;
    
        
    if ( I2cHardwareID >= MAX_NO_OF_SERIAL_ENGINE )
    {
        Status = I2C_EL1_HW_NOT_EXIST;
        goto end;
    }

    if ( I2C_INITIALIZED == I2cInitStatus[I2cHardwareID] )
    {
        Status = I2C_EL1_ERROR_ALREADY_INITIALIZED;
        goto end;
    }
    
    pDTB = fdt_get_dtb();
    if (NULL != pDTB)
    {
        root_offset = fdt_path_offset(pDTB, "/qup");
		(void)fdt_getprop_u32(pDTB, root_offset, "common-addr", &QupCommonBase);
        root_offset = fdt_path_offset(pDTB, "/aliases");
        i2c_name[3] = (I2cHardwareID+48);
        path = (const char*)fdt_getprop(pDTB, root_offset, i2c_name , NULL);
        if (path != NULL) 
        {
            offset = fdt_path_offset(pDTB, path);
			(void)fdt_getprop_u32(pDTB, offset, "reg-base", &I2CHwConfig[I2cHardwareID].se_base_addr);
			(void)fdt_getprop_u32_array(pDTB, offset, "slave-addr", slave_array, &Size);
			(void)fdt_getprop_u32_array(pDTB, offset, "addressing-mode", mode_array, &Size);
			(void)fdt_getprop_u32_array(pDTB, offset, "timestamp", ts_array, &Size);
			(void)fdt_getprop_u32_array(pDTB, offset, "precmd-delay", delay_array, &Size);
            I2CHwConfig[I2cHardwareID].Hw_ChannelId = I2cHardwareID;
            I2CHwConfig[I2cHardwareID].psSE_clock = (char*) fdt_getprop(pDTB, offset, "clock-name", &valSize_st);
			I2CHwConfig[I2cHardwareID].NoOfChannels = (uint8)Size;
            I2CHwConfig[I2cHardwareID].MinChannelId = (uint8)ChannelNum;
            I2CHwConfig[I2cHardwareID].MaxChannelId = (uint8)(Size + ChannelNum - 1);
            for( uint8 i = 0U ; i < (uint8)Size; i++)
            {
                uint8 j = i + ChannelNum;
                I2CChannelCfg[j].SlaveAddress = (uint8)slave_array[i];
                I2CChannelCfg[j].Addressing_Mode = mode_array[i];    
                I2CChannelCfg[j].AssignedHwId = I2cHardwareID;
                I2CChannelCfg[j].Delay_PreCmdus = (uint8)delay_array[i];
                I2CChannelCfg[j].timestamp_en = (uint8)ts_array[i];
                I2CChannelCfg[j].NotifFuncPtr    = NULL;
            }
            ChannelNum = ChannelNum + Size;
            (void)fdt_getprop_u32(pDTB, offset, "status", &I2CHwConfig[I2cHardwareID].status);
            (void)fdt_getprop_u32(pDTB, offset, "i2c-mode", &I2CHwConfig[I2cHardwareID].Mode);
            (void)fdt_getprop_u32(pDTB, offset, "access-mode", &I2CHwConfig[I2cHardwareID].Access_Mode);
            (void)fdt_getprop_u32(pDTB, offset, "interrupt", &I2CHwConfig[I2cHardwareID].Intr_Num);

            if( I2CHwConfig[I2cHardwareID].status == 0x0U)
            {
                Status = I2C_EL1_HW_NOT_ENABLED;
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
                        GpioNumber = (uint8)val_array0[i];
                        sail_gpio_get_pin_config(GpioNumber,&I2cEl1ResetStatePinCfg[I2cHardwareID][i]);
                        QupPinCfg.func = val_array1[i];
                        QupPinCfg.drive = val_array2[i];
                        QupPinCfg.dir = val_array3[i];
                        QupPinCfg.pull = val_array4[i];
                        sail_gpio_config_pin(GpioNumber,QupPinCfg);
                    }
                }
                else
                {
                    Status = I2C_EL1_HW_NOT_EXIST;
                    goto end;
                }
            }
        }
        else
		{
			Status = I2C_EL1_HW_NOT_EXIST;
            goto end;
		}
    }

        Status = I2C_EL1_SUCCESS;

end:
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cSerialEngineInitEl1
 @Description         This function Initialize the Serial engine of the QUP Hw for the I2c Protocol
 @param[in]           I2cHwConfigPtr      - Pointer for the Hardware configuration
                      QupCommonAddr - QUP common CSR space address
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
static i2cEl1Status_e I2cSerialEngineInit(
    const i2cEl1HwUnitCfgType *I2cHwConfigPtr,
    uint32 QupCommonAddr)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    intEl1Status_t IntStatus = INT_EL1_SUCCESS;
    uint32 SEBaseAddr = I2cHwConfigPtr->se_base_addr;
    uint32 TimeoutMax = 500;
    uint32 Fifodepth;
    uint32 RegMIRQ = 0;
    uint32 RegSIRQ = 0;

    /* HPG section 3.1.7.1 is skipped since the DFS enabling is not required*/
    /* Check if the DMA mode is configured. As per 3.1.7.2*/
    if(I2cHwConfigPtr->Access_Mode == I2C_EL1_DMA_MODE)
    {
        /* Reset the DMA*/
        REG_OUT(SEBaseAddr, DMA_RX_FSM_RST,
                                    FLD_SET(DMA_RX_FSM_RST, RX_FSM_RST, 0x1));
        /* Wait till the reset is done or timeout occured*/
        do
        {
            /* Check if the Reset is done*/
            if(REG_INF(SEBaseAddr,DMA_RX_IRQ_STAT,RESET_DONE) != 0U)
            {
                // Clear the Reset done IRQ bit
                REG_OUTF(SEBaseAddr, DMA_RX_IRQ_CLR,RESET_DONE_CLR, 0x1);
                REG_OUTF(SEBaseAddr, DMA_RX_IRQ_CLR,DMA_DONE_CLR, 0x1);
                break;
            }
            else
            {
                /* Wait for i2cPOLLINTERVAL_US*/
                busywait(i2cPOLLINTERVAL_US);
                /* Decrement the timeout*/
                TimeoutMax -= i2cPOLLINTERVAL_US;
            }
        }while ((TimeoutMax != 0U));
    }

    /* First, ensure GENI FW is disabled */
    /* Disable the Output */
    REG_OUT(SEBaseAddr, GENI_OUTPUT_CTRL,
              FLD_SET(GENI_OUTPUT_CTRL, IO_OUTPUT_CTRL, 0x0));
    REG_OUTF(SEBaseAddr, GENI_DFS_IF_CFG, DFS_IF_EN, 0);

    /* Check if the DMA mode is configured*. As per 3.1.7.3 */
    if(I2cHwConfigPtr->Access_Mode == I2C_EL1_DMA_MODE)
    {
        // Clock related to DMA. As per HPG. 3.1.7.3.
        REG_OUT(SEBaseAddr, DMA_GENERAL_CFG,
                         FLD_SET(DMA_GENERAL_CFG, AHB_SEC_SLV_CLK_CGC_ON, 1) |
                         FLD_SET(DMA_GENERAL_CFG, DMA_AHB_SLV_CLK_CGC_ON, 1) |
                         FLD_SET(DMA_GENERAL_CFG, DMA_TX_CLK_CGC_ON, 1) |
                         FLD_SET(DMA_GENERAL_CFG, DMA_RX_CLK_CGC_ON, 1));
    }
    /* Clock gating control for GENI.As per HPG section 3.1.7.3 */
    REG_OUT(SEBaseAddr, GENI_CGC_CTRL,
                     FLD_SET(GENI_CGC_CTRL, EXT_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, RX_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, TX_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, SCLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, DATA_AHB_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, CFG_AHB_WR_CLK_CGC_ON, 1) |
                     FLD_SET(GENI_CGC_CTRL, CFG_AHB_CLK_CGC_ON, 1));

    /* Check if the Firmware loading is done*/
    if(Status == I2C_EL1_SUCCESS)
    {
        /* Enable IO GENI output. As per HPG section 3.1.7.5*/
        REG_OUT(SEBaseAddr, GENI_OUTPUT_CTRL,
                         FLD_SET(GENI_OUTPUT_CTRL, IO_OUTPUT_CTRL, 0x7f));
        /* Check the configured mode is FIFO mode. As per HPG section 3.1.7.6 */
        if(I2cHwConfigPtr->Access_Mode != I2C_EL1_DMA_MODE)
        {
            /* Disable the DMA*/
            REG_OUT(SEBaseAddr, GENI_DMA_MODE_EN,
                             FLD_SET(GENI_DMA_MODE_EN, GENI_DMA_MODE_EN, 0));
        }
        else
        {
            /* Enable the DMA*/
            REG_OUT(SEBaseAddr, GENI_DMA_MODE_EN,
                             FLD_SET(GENI_DMA_MODE_EN, GENI_DMA_MODE_EN, 1));
        }
        /* HPG section 3.1.7.9 */
        /* non-UART configuration, UART driver can configure as desired for UART */
        Fifodepth = REG_INF(SEBaseAddr, SE_HW_PARAM_1, RX_FIFO_DEPTH);

        REG_OUT(SEBaseAddr, GENI_RX_RFR_WATERMARK_REG,
                         FLD_SET(GENI_RX_RFR_WATERMARK_REG, RX_RFR_WATERMARK, (Fifodepth - 2U)));

        if(I2cHwConfigPtr->Access_Mode != I2C_EL1_POLLING_MODE)
        {
            /* Configure the Interrupt handler*/
            IntStatus = xGicSetIntEnable(I2cHwConfigPtr->Intr_Num, (boolean)FALSE);
            if(INT_EL1_SUCCESS != IntStatus)
            {
                Status = I2C_EL1_ERROR_INTERRUPT_INSTALL;
                return Status;
            }
            IntStatus = xGicRegisterIntHandler(I2cHwConfigPtr->Intr_Num, (InterruptHandle_t)I2cGeniSEIsr, (void *)I2cHwConfigPtr->Hw_ChannelId);
            if(INT_EL1_SUCCESS != IntStatus)
            {
                Status = I2C_EL1_ERROR_INTERRUPT_INSTALL;
                return Status;
            }
            IntStatus = xGicConfigureInt(I2cHwConfigPtr->Intr_Num, (enum InterruptConfig_t)EL1_INT_CONFIG_LEVEL_TRIGGER, NULL);
            if(INT_EL1_SUCCESS != IntStatus)
            {
                Status = I2C_EL1_ERROR_INTERRUPT_INSTALL;
                return Status;
            }
            IntStatus = xGicSetIntEnable(I2cHwConfigPtr->Intr_Num, (boolean)TRUE);
            if(INT_EL1_SUCCESS != IntStatus)
            {
                Status = I2C_EL1_ERROR_INTERRUPT_INSTALL;
                return Status;
            }

            /* Clear any pending Interrupt. This will ensure the fresh start*/
            REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
            REG_OUT(SEBaseAddr, GENI_S_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
            REG_OUT(SEBaseAddr, DMA_TX_IRQ_CLR, i2cIRQ_CLEAR_MASK);
            REG_OUT(SEBaseAddr, DMA_RX_IRQ_CLR, i2cIRQ_CLEAR_MASK);

            /* Enable the Interrupts*/
            REG_OUT(SEBaseAddr, SE_IRQ_EN,
                             FLD_SET(SE_IRQ_EN, DMA_RX_IRQ_EN, 1) |
                             FLD_SET(SE_IRQ_EN, DMA_TX_IRQ_EN, 1) |
                             FLD_SET(SE_IRQ_EN, GENI_M_IRQ_EN, 1) |
                             FLD_SET(SE_IRQ_EN, GENI_S_IRQ_EN, 1));
            REG_OUT(SEBaseAddr, SE_GSI_EVENT_EN,0);

            /* Frame the common M_IRQ enable*/
            RegMIRQ = (RegMIRQ | FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_OVERRUN_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, M_ILLEGAL_CMD_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, M_TIMESTAMP_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_RD_ERR_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_WR_ERR_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_RD_ERR_EN, 1) |
                                   FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_WR_ERR_EN, 1));
            /* Frame the common S_IRQ enable*/
            RegSIRQ = (RegSIRQ | FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_OVERRUN_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_ILLEGAL_CMD_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_0_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_1_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_2_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, S_GP_IRQ_3_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, RX_FIFO_WR_ERR_EN, 1) |
                                   FLD_SET(GENI_S_IRQ_ENABLE, RX_FIFO_RD_ERR_EN, 1));
            /* Check if the Configured mode is FIFO*/
            if(I2cHwConfigPtr->Access_Mode == I2C_EL1_FIFO_MODE)
            {
                REG_OUT(SEBaseAddr, GENI_M_IRQ_ENABLE,
                                 RegMIRQ |
                                 FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_WATERMARK_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_WATERMARK_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_LAST_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_DONE_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_FAILURE_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_CANCEL_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_ABORT_EN, 1) |
                                 FLD_SET(GENI_M_IRQ_ENABLE, SEC_IRQ_EN, 1));

              REG_OUT(SEBaseAddr, GENI_S_IRQ_ENABLE,
                               RegSIRQ |
                               FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_CANCEL_EN, 1) |
                               FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_ABORT_EN, 1) |
                               FLD_SET(GENI_S_IRQ_ENABLE, S_CMD_DONE_EN, 1));
            }
            /* Enable the Interrupts for DMA Mode*/
            else if(I2cHwConfigPtr->Access_Mode == I2C_EL1_DMA_MODE)
            {
                REG_OUT(SEBaseAddr, GENI_M_IRQ_ENABLE, RegMIRQ);

                REG_OUT(SEBaseAddr, GENI_S_IRQ_ENABLE, RegSIRQ);

                REG_OUT(SEBaseAddr, DMA_TX_IRQ_EN_SET,
                                 FLD_SET(DMA_TX_IRQ_EN_SET, DMA_DONE_EN_SET, 1) |
                                 FLD_SET(DMA_TX_IRQ_EN_SET, SBE_EN_SET, 1) |
                                 FLD_SET(DMA_TX_IRQ_EN_SET, RESET_DONE_EN_SET, 1));

                REG_OUT(SEBaseAddr, DMA_RX_IRQ_EN_SET,
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
        REG_OUT(SEBaseAddr, GENI_FORCE_DEFAULT_REG,
                         FLD_SET(GENI_FORCE_DEFAULT_REG, FORCE_DEFAULT, 1));

        REG_OUTF(SEBaseAddr, GENI_CGC_CTRL,PROG_RAM_SCLK_OFF,1);
        REG_OUTF(SEBaseAddr, GENI_CGC_CTRL,PROG_RAM_HCLK_OFF,1);

        REG_OUT(SEBaseAddr, GENI_CLK_CTRL,
                         FLD_SET(GENI_CLK_CTRL, SER_CLK_SEL, 0x1));

        REG_OUTF(SEBaseAddr, GENI_CGC_CTRL,PROG_RAM_SCLK_OFF,0);
        REG_OUTF(SEBaseAddr, GENI_CGC_CTRL,PROG_RAM_HCLK_OFF,0);

        /* Check if the FIFO mode is configured. As per HPG section 3.1.7.13 */
        if(I2cHwConfigPtr->Access_Mode != I2C_EL1_DMA_MODE)
        {
            /* Disable the DMA mode*/
            REG_OUT(SEBaseAddr, DMA_IF_EN,
                             FLD_SET(DMA_IF_EN, DMA_IF_EN, 0x0));
            /* Enable the FIFO mode*/
            REG_OUT(SEBaseAddr, FIFO_IF_DISABLE,
                             FLD_SET(FIFO_IF_DISABLE, FIFO_IF_DISABLE, 0x0));
        }
        else
        {
            /* Enable the DMA mode*/
            REG_OUT(SEBaseAddr, DMA_IF_EN,
                             FLD_SET(DMA_IF_EN, DMA_IF_EN, 0x1));
            /* Disable the FIFO mode*/
            REG_OUT(SEBaseAddr, FIFO_IF_DISABLE,
                             FLD_SET(FIFO_IF_DISABLE, FIFO_IF_DISABLE, 0x1));
            /* Set the Granularity for the DMA mode. Fixed 4x8 */
            REG_OUT(SEBaseAddr, GENI_BYTE_GRANULARITY,
                FLD_SET(GENI_BYTE_GRANULARITY, GENI_BYTE_GRANULARITY, 0));
        }

        /* As per H.P.G 3.2.1. clock select*/
        REG_OUT(SEBaseAddr, GENI_CLK_SEL, FLD_SET(GENI_CLK_SEL, CLK_SEL, 0));

        /* Configure the TX and RX Packing. Fixed to 4x8 Packing */
        REG_OUT(SEBaseAddr, GENI_TX_PACKING_CFG0, i2cTX_PACKING_CFG0_VAL);
        REG_OUT(SEBaseAddr, GENI_TX_PACKING_CFG1, i2cTX_PACKING_CFG1_VAL);
        REG_OUT(SEBaseAddr, GENI_RX_PACKING_CFG0, i2cRX_PACKING_CFG0_VAL);
        REG_OUT(SEBaseAddr, GENI_RX_PACKING_CFG1, i2cRX_PACKING_CFG1_VAL);

        /* Clock Configuration*/
        REG_OUT(SEBaseAddr, GENI_SER_M_CLK_CFG,
                         FLD_SET(GENI_SER_M_CLK_CFG, CLK_DIV_VALUE,
                                                     I2cClkCfg[I2cHwConfigPtr->Mode].ClkDiv) |
                         FLD_SET(GENI_SER_M_CLK_CFG, SER_CLK_EN,      1));

        /* SCL Configuration*/
        REG_OUT(SEBaseAddr, I2C_SCL_COUNTERS,
                         FLD_SET(I2C_SCL_COUNTERS, I2C_SCL_HIGH_COUNTER,
                                                   I2cClkCfg[I2cHwConfigPtr->Mode].THigh) |
                         FLD_SET(I2C_SCL_COUNTERS, I2C_SCL_LOW_COUNTER,
                                                   I2cClkCfg[I2cHwConfigPtr->Mode].TLow)  |
                         FLD_SET(I2C_SCL_COUNTERS, I2C_SCL_CYCLE_COUNTER,
                                                   I2cClkCfg[I2cHwConfigPtr->Mode].TCycle));
    }
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cSerialEngineDeInitEl1
 @Description         This function DeInitialize the Serial engine of the QUP Hw for the I2c Protocol
 @param[in]           I2cHwConfigPtr      - Pointer for the Hardware configuration
                      QupCommonAddr - QUP common CSR space address
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
static i2cEl1Status_e I2cSerialEngineDeInit(
    const i2cEl1HwUnitCfgType *I2cHwConfigPtr,
    uint32 QupCommonAddr)
{
    uint32 SEBaseAddr = I2cHwConfigPtr->se_base_addr;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    intEl1Status_t IntStatus = INT_EL1_SUCCESS;

    if(I2cHwConfigPtr->Access_Mode != I2C_EL1_POLLING_MODE)
    {
        /* Disable the Interrupts*/
        REG_OUT(SEBaseAddr, SE_IRQ_EN,
                         FLD_SET(SE_IRQ_EN, DMA_RX_IRQ_EN, 0) |
                         FLD_SET(SE_IRQ_EN, DMA_TX_IRQ_EN, 0) |
                         FLD_SET(SE_IRQ_EN, GENI_M_IRQ_EN, 0) |
                         FLD_SET(SE_IRQ_EN, GENI_S_IRQ_EN, 0));
        REG_OUT(SEBaseAddr, SE_GSI_EVENT_EN,0);
        /* Clear any pending Interrupt.*/
        REG_OUT(SEBaseAddr, DMA_TX_IRQ_CLR, i2cIRQ_CLEAR_MASK);
        REG_OUT(SEBaseAddr, DMA_RX_IRQ_CLR, i2cIRQ_CLEAR_MASK);
    /* Reset the DMA*/
    REG_OUT(SEBaseAddr, DMA_RX_FSM_RST,
                                FLD_SET(DMA_RX_FSM_RST, RX_FSM_RST, 0x1));
    REG_OUT(SEBaseAddr, DMA_RX_FSM_RST,
                                FLD_SET(DMA_TX_FSM_RST, TX_FSM_RST, 0x1));
        /* Unregister the Interrupt handler*/
        IntStatus = xGicSetIntEnable(I2cHwConfigPtr->Intr_Num, (boolean)FALSE);
        if(INT_EL1_SUCCESS != IntStatus)
        {
            Status = I2C_EL1_ERROR_INTERRUPT_UNINSTALL;
        }
        else
        {
            IntStatus = xGicUnRegisterIntHandler(I2cHwConfigPtr->Intr_Num, (uint32_t)0U);
            if(INT_EL1_SUCCESS != IntStatus)
            {
                Status = I2C_EL1_ERROR_INTERRUPT_UNINSTALL;
            }
        }
    }

    REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);
    REG_OUT(SEBaseAddr, GENI_S_IRQ_CLEAR, i2cIRQ_CLEAR_MASK);

    /*Enable the force Default.
    REG_OUT(SEBaseAddr, GENI_FORCE_DEFAULT_REG,
                     FLD_SET(GENI_FORCE_DEFAULT_REG, FORCE_DEFAULT, 1));*/
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cClockEnableEl1
 @Description         This function configure and enable the clock for the serial engine
 @param[in]           I2cHwConfigPtr      - Pointer for the Hardware configuration
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
static ClockResult I2cClockEnable (const i2cEl1HwUnitCfgType *I2cHwConfigPtr)
{
    ClockResult Status = CLOCK_ERROR;
    ClockIdType ClockId = {0};
    uint32_t ClockResultfreq = 0U;
    ClockHandle ClientHandle = 0U;
    
    Clock_GetHandle( &ClientHandle);
    Status = Clock_GetClockId( ClientHandle, I2cHwConfigPtr->psSE_clock, &ClockId);

    if ( Status == CLOCK_SUCCESS )
    {
        Status = Clock_SetClockFrequency
                              ( ClientHandle, ClockId,
                               I2cClkCfg[ I2cHwConfigPtr->Mode].SEClockFrequencyHz,
                               CLOCK_FREQUENCY_HZ_AT_LEAST, &ClockResultfreq);

        if( CLOCK_SUCCESS == Status )
        {
            Status = Clock_EnableClock( ClientHandle, ClockId);
            if ( CLOCK_SUCCESS != Status )
            {
                DEBUG_LOG( SAIL_ERROR,"Failed to enable serial engine clock \r\n");
            }
        }
    }
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cClockDisableEl1
 @Description         This function disable the clock for the serial engine
 @param[in]           I2cHwConfigPtr      - Pointer for the Hardware configuration
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
static ClockResult I2cClockDisable (const i2cEl1HwUnitCfgType *I2cHwConfigPtr)
{
    ClockResult Status = CLOCK_ERROR;
    ClockIdType ClockId   = {0};
    ClockHandle ClientHandle = 0U;

    Clock_GetHandle(&ClientHandle);
    if ( CLOCK_SUCCESS == Clock_GetClockId( ClientHandle, I2cHwConfigPtr->psSE_clock, &ClockId ) )
    {
        Status = Clock_DisableClock( ClientHandle, ClockId);
        if ( CLOCK_SUCCESS != Status )
        {
            DEBUG_LOG(SAIL_ERROR,"Failed to disable serial engine clock \r\n");
        }
    }
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cGetCmdOpcodeEl1
 @Description         This function detect the opcode to be used for the current transfer
 @param[in]           Flags     - It contains the information about the START,STOP,Read or write
                      DataLength    - Length of the transfer
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
static i2cCmdOpcode_e I2cGetCmdOpcode (uint32 Flags, uint32 DataLength)
{
    i2cCmdOpcode_e Status = CMD_INVALID;
    /* Check if the length is 0*/
    if (DataLength == 0U)
    {
        /* Check if the Start flag is set*/
        if((Flags & i2cFLAG_START) == i2cFLAG_START)
        {
            /* I2C address only command*/
            Status = CMD_I2C_ADDRESS_ONLY;
        }
        /* Check if the stop flag is set*/
        else if((Flags & i2cFLAG_STOP) == i2cFLAG_STOP)
        {
            /* I2C stop on bus command*/
            Status = CMD_I2C_STOP_ON_BUS;
        }
        else if (Flags == 0U)
        {
            /* Bus clear command*/
            Status = CMD_I2C_BUS_CLEAR;
        }
        else
        {
            ;/*MCDC*/
        }
    }
    else
    {
        /* Check if the Write falg is set*/
        if ( (Flags & i2cFLAG_WRITE) != 0U)
        {
            /* I2C Write command*/
            Status = CMD_I2C_WRITE;
        }
        /* Check if the read flag is set*/
        else if ( (Flags & i2cFLAG_READ) != 0U )
        {
            /* I2C Write then read command*/
            Status = CMD_I2C_WRITE_THEN_READ;
        }
        else
        {
            ;/*MCDC*/
        }
    }
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cFiFoWriteEl1
 @Description         This function write the data to be send into the FIFO
 @param[in]           ChannelId  - Channel ID
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
static void I2cFiFoWrite(uint8 I2cHardwareID)
{
    uint32 SEBaseAddr = I2CHwConfig[I2cHardwareID].se_base_addr;
    uint32 TxWaterMark = REG_INF(SEBaseAddr, GENI_TX_WATERMARK_REG, TX_WATERMARK);
    uint32 TxFifoDepth = REG_INF(SEBaseAddr, SE_HW_PARAM_0, TX_FIFO_DEPTH);
    uint32 BytesToWrite = (TxFifoDepth << 2U) - (TxWaterMark << 2U);
    uint32 Word = 0U;
    uint32 DataLength = 0U;
    uint8  WriteCounter = 0U;
    uint8  ChannelId = I2cSEChannelData[I2cHardwareID].ActiveChannel;
    uint8 *BufferPtr = I2cSEChannelData[I2cHardwareID].I2cDataPtr +  I2cSEChannelData[I2cHardwareID].TransferredLength;
    uint8  AddressCounter = 0U;
    uint8  AddressLength = (uint8)I2CChannelCfg[ChannelId].Addressing_Mode;
    uint32 Address = I2cSEChannelData[I2cHardwareID].Address;

    if(I2cSEChannelData[I2cHardwareID].ActiveCommand == I2C_READ_COMMAND)
    {
        /* reset the TX watermark level*/
        REG_OUT(SEBaseAddr, GENI_TX_WATERMARK_REG,
                                    FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 0));


        for ( WriteCounter = 0 ; WriteCounter < AddressLength ; WriteCounter++ )
        {
            Word = (Word<<8) | ( Address&0xFF);
            Address = Address>>8U;
        }

        REG_OUTI(SEBaseAddr, GENI_TX_FIFOn, 0, Word);
    }
    else if(I2cSEChannelData[I2cHardwareID].ActiveCommand == I2C_WRITE_COMMAND)
    {
        DataLength = I2cSEChannelData[I2cHardwareID].BufferLength;
        /* Check if the data to be write is less then the Fifo size*/
        if (((DataLength + AddressLength) - I2cSEChannelData[I2cHardwareID].TransferredLength) < BytesToWrite)
        {
            /* Calculate the bytes to be write*/
            BytesToWrite = DataLength - I2cSEChannelData[I2cHardwareID].TransferredLength;
            /* reset the TX watermark level*/
            REG_OUT(SEBaseAddr, GENI_TX_WATERMARK_REG,
                                        FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 0));
        }

        if(I2cSEChannelData[I2cHardwareID].TransferredLength == 0U)
        {
            for ( WriteCounter = 0U ; WriteCounter < AddressLength ; WriteCounter++ )
            {
                Word = (Word<<8U) | ( Address&0xFFU);
                Address = Address>>8U;
            }
            AddressCounter = AddressLength;
        }
        /* Write the data into FIFO*/
        for (WriteCounter = AddressCounter; WriteCounter < (BytesToWrite + AddressCounter); WriteCounter++)
        {
            /* Pack the 4 bytes to a single 32 bit. So it can be write directly to TX FIFO */
            if ((WriteCounter != 0U) && ((WriteCounter % i2cBYTES_PER_FIFO_REG) == 0U))
            {
                REG_OUTI(SEBaseAddr, GENI_TX_FIFOn,0, Word);
                Word = 0U;
            }
            Word = Word | (BufferPtr[(WriteCounter - AddressCounter)] <<
                                           ((WriteCounter % i2cBYTES_PER_FIFO_REG)*i2cBITS_PER_BYTE));
        }
        REG_OUTI(SEBaseAddr, GENI_TX_FIFOn,0, Word);

        /* Update the data count to be transfered*/
        I2cSEChannelData[I2cHardwareID].TransferredLength += BytesToWrite;
    }
    else
    {
        /* Dummy else */
    }
}

/*=================================================================================================
 @Service name        prvI2cFiFoReadEl1
 @Description         This function read the data from the RX FIFO and copy into the user space
 @param[in]           ChannelId - Channel ID
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
static void I2cFiFoRead(uint8 I2cHardwareID)
{
    uint32 SEBaseAddr = I2CHwConfig[I2cHardwareID].se_base_addr;
    uint32 RxFifoStatus = REG_IN(SEBaseAddr, GENI_RX_FIFO_STATUS);
    uint32 BytesToRead = FLD_GET(RxFifoStatus, GENI_RX_FIFO_STATUS, RX_FIFO_WC) * i2cBYTES_PER_FIFO_REG;
    uint32 TransferedCount = I2cSEChannelData[I2cHardwareID].TransferredLength;
    uint32 DataLength = I2cSEChannelData[I2cHardwareID].BufferLength;
    uint32 Word = 0U;
    uint8  ReadCounter;
    uint8 *BufferPtr = I2cSEChannelData[I2cHardwareID].I2cDataPtr + TransferedCount;
    uint8  BytesInLastWord = 0U;

    /* Check if the Last waord is set*/
    if (FLD_GET(RxFifoStatus, GENI_RX_FIFO_STATUS, RX_LAST))
    {
        /* Get the last valid byte*/
        BytesInLastWord = FLD_GET(RxFifoStatus, GENI_RX_FIFO_STATUS, RX_LAST_BYTE_VALID);
        /* update the bytes to read*/
        BytesToRead = (BytesToRead - i2cBYTES_PER_FIFO_REG) + BytesInLastWord;
    }
    /* Check if the Transfer count is less then bytes to read*/
    if ((DataLength - TransferedCount) < BytesToRead)
    {
        /* Find the bytes to read */
        BytesToRead = DataLength - TransferedCount;
    }
    /* Read the data*/
    for (ReadCounter = 0U; ReadCounter < BytesToRead; ReadCounter++)
    {
        if ((ReadCounter % i2cBYTES_PER_FIFO_REG) == 0U)
        {
            Word = REG_INI(SEBaseAddr, GENI_RX_FIFOn, 0);
        }
        BufferPtr[ReadCounter] = (Word >> ((ReadCounter % i2cBYTES_PER_FIFO_REG)*i2cBITS_PER_BYTE)) & 0xFF;
    }

    /* Update the transfered count*/
    I2cSEChannelData[I2cHardwareID].TransferredLength += BytesToRead;

    /*Check if all the requested data is received */
    if(I2cSEChannelData[I2cHardwareID].TransferredLength == DataLength)
    {
        REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_LAST_CLEAR_BMSK);
    }
    /* Clear the Watermark status bit*/
    REG_OUT(SEBaseAddr, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_WATERMARK_CLEAR_BMSK);
}

/*=================================================================================================
 @Service name        prvI2cTransferEl1
 @Description         This function frame the opcode to be write for the current transfer
 @param[in]           ChannelId - Channel ID
                      DataLength    - Length of the transfer
                      Flag      - Flag information
 @param[out]          RegMaskPtr  - Pointer to the Register mask
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
static void I2cTransfer(uint8 ChannelId, uint32 DataLength, uint32 Flag, uint32 *RegMaskPtr)
{
    i2cEl1Mode_e I2cMode;
    uint32 DelayTick;
    uint32 RegMask = 0U;
    uint32 SEBaseAddr;
    uint8 I2cHardwareID;
    uint8 PreCmdDelay = 0U;

    I2cHardwareID = I2CChannelCfg[ChannelId].AssignedHwId;
    SEBaseAddr = I2CHwConfig[I2cHardwareID].se_base_addr;
    PreCmdDelay = I2CChannelCfg[ChannelId].Delay_PreCmdus;
    I2cMode = I2CHwConfig[I2cHardwareID].Mode;

    /* Delay tick calculation for the pre-command*/
    DelayTick = ((PreCmdDelay) * (I2cClkCfg[I2cMode].SEClockFrequencyHz))/1000000;

    RegMask =  RegMask | FLD_SET(GENI_M_CMD0, I2C_SLAVE_ADDRESS,
            I2CChannelCfg[ChannelId].SlaveAddress);
    /* Check if the Calculated tick is not 0*/
    if(DelayTick != 0U)
    {
        /* TODO : Precommand delay configuration*/
        REG_OUT(SEBaseAddr, I2C_DELAY_COUNTER,
                         FLD_SET(I2C_DELAY_COUNTER, I2C_DELAY_COUNTER, DelayTick));
        RegMask =  RegMask | FLD_SET(GENI_M_CMD0, I2C_PRE_CMD_DELAY, 1);
    }
    /* Check if the timestamp is requested*/
    if (Flag & i2cFLAG_TIMESTAMP)
    {
        /* Check if the requested timestamp is for the START bit */
        if ((Flag & i2cFLAG_START) != 0U)
        {
            /* Configure the I2C timestamp before bit */
            RegMask = RegMask | FLD_SET(GENI_M_CMD0, I2C_TIMESTAMP_BEFORE, 1);
        }
        /* Check if the timestamp is requested for the STOP bit*/
        else if ( (Flag & i2cFLAG_STOP) != 0U)
        {
            /* Set the timestamp after bit*/
            RegMask = RegMask | FLD_SET(GENI_M_CMD0, I2C_TIMESTAMP_AFTER, 1);
        }
    }
    /* Check if the buffer lenght is not zero*/
    if (DataLength != 0U)
    {
        /* Check if the I2C Stop flag is not requested*/
        if ((Flag & i2cFLAG_STOP) != i2cFLAG_STOP)
        {
            /* Enable the I2C Stretch bit*/
            RegMask = RegMask | FLD_SET(GENI_M_CMD0, I2C_STRETCH, 1);
        }
        /* Check if the I2C START flag not requested*/
        if ((Flag & i2cFLAG_START) != i2cFLAG_START)
        {
            /* Enable the Bypass address phase bit*/
            RegMask = RegMask | FLD_SET(GENI_M_CMD0, I2C_BYPASS_ADDRESS_PHASE, 1);
        }
    }
  *RegMaskPtr = RegMask;
}

/*=================================================================================================
 @Service name        prvI2cChannelIdcheckEl1
 @Description         This function check the validity of the channel ID
                      ChannelId - Channel ID
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
static i2cEl1Status_e I2cChannelIdcheck(const uint8 ChannelId)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    if((ChannelId < I2CHwConfig[I2CChannelCfg[ChannelId].AssignedHwId].MinChannelId) || 
       (ChannelId > I2CHwConfig[I2CChannelCfg[ChannelId].AssignedHwId].MaxChannelId))
    {
        Status = I2C_EL1_ERROR_INVALID_CHANNEL_ID;
    }
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cPtrCheckEl1
 @Description         This function check if the passed pointer is NULL or not
 @param[in]           I2cDataPtr      - Pointer to be checked
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
static i2cEl1Status_e I2cPtrCheck(uint8 *I2cDataPtr)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    if(I2cDataPtr == NULL)
    {
        Status = I2C_EL1_ERROR_NULL_PTR;
    }
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cInitStatusCheckEl1
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
static i2cEl1Status_e I2cInitStatusCheck(uint8 I2cHardwareID)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    if ( I2cHardwareID >= MAX_NO_OF_SERIAL_ENGINE )
    {
        return I2C_EL1_HW_NOT_EXIST;
    }
    if(I2cInitStatus[I2cHardwareID] == I2C_UNINITIALIZED)
    {
        Status = I2C_EL1_NOT_INITIALIZED;
    }
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cReadGeniErrorEl1
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

static void I2cReadGeniError(i2cEl1Status_e *StatusPtr, uint8 ChannelId)
{
    uint8 I2cHardwareID = 0x0U;
    uint32 SEBaseAddr = 0x0U;

    I2cHardwareID = I2CChannelCfg[ChannelId].AssignedHwId;
    SEBaseAddr = I2CHwConfig[I2cHardwareID].se_base_addr;

    if(FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,TX_FIFO_WR_ERR)
        || FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,RX_FIFO_WR_ERR) )
    {
        *StatusPtr = I2C_EL1_FIFO_WRITE_ERROR;
    }

    if(FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,TX_FIFO_RD_ERR)
        || FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,RX_FIFO_RD_ERR) )
    {
        *StatusPtr = I2C_EL1_FIFO_READ_ERROR;
    }

    if(FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,M_GP_IRQ_3))
    {
        *StatusPtr = I2C_EL1_PROTOCOL_ERROR;
    }

    if(FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,M_GP_IRQ_1))
    {
        *StatusPtr = I2C_EL1_SLAVE_NACK_ERROR;
    }

    if(FLD_GET(REG_IN(SEBaseAddr, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS,M_GP_IRQ_4))
    {
        *StatusPtr = I2C_EL1_SLAVE_NACK_ERROR;
    }
}


/*=================================================================================================
 @Service name        prvI2cWriteErrorcheckEl1
 @Description         This function check for any error for the I2C write function
 @param[in]           ChannelId  - Channel ID
                      I2cDataPtr   - Pointer to store the data to be send
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
static i2cEl1Status_e I2cWriteErrorcheck(const uint8 ChannelId, uint8 *I2cDataPtr)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    uint8 I2cHardwareID;

    Status = I2cInitStatusCheck(I2CChannelCfg[ChannelId].AssignedHwId);
    if(Status == I2C_EL1_SUCCESS)
    {
        Status = I2cChannelIdcheck(ChannelId);
        if(Status == I2C_EL1_SUCCESS)
        {
            Status = I2cPtrCheck(I2cDataPtr);
            if(Status == I2C_EL1_SUCCESS)
            {
                I2cHardwareID = I2CChannelCfg[ChannelId].AssignedHwId;
                /* Need to put SpinLock to avoid data inconsistency*/
                if(I2cSEChannelData[I2cHardwareID].ChannelStatus != I2C_EL1_CHANNEL_READY)
                {
                    Status = I2C_EL1_CHANNEL_BUSY;
                }
                else
                {
                    I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_BUSY;
                }
                /*End of SpinLock*/
            }
        }
    }
    return Status;
}

/*=================================================================================================
 @Service name        prvI2cReadErrorcheckEl1
 @Description         This function check for nay error for the I2C read API
 @param[in]           ChannelId  - Channel ID
                      I2cDataPtr   - Pointer to the read data to be stored
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
static i2cEl1Status_e I2cReadErrorcheck(const uint8 ChannelId, uint8 *I2cDataPtr)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    uint8 I2cHardwareID;

    I2cHardwareID = I2CChannelCfg[ChannelId].AssignedHwId;
    Status = I2cInitStatusCheck(I2cHardwareID);
    if(Status == I2C_EL1_SUCCESS)
    {
        Status = I2cChannelIdcheck(ChannelId);

        if(Status == I2C_EL1_SUCCESS)
        {
            Status = I2cPtrCheck(I2cDataPtr);
            if(Status == I2C_EL1_SUCCESS)
            {
                /* Need to put SpinLock to avoid data inconsistency*/
                if(I2cSEChannelData[I2cHardwareID].ChannelStatus != I2C_EL1_CHANNEL_READY)
                {
                    Status = I2C_EL1_CHANNEL_BUSY;
                }
                else
                {
                    I2cSEChannelData[I2cHardwareID].ChannelStatus =  I2C_EL1_CHANNEL_BUSY;
                }
                /*End of SpinLock*/
            }
        }
    }

    return Status;
}

/*=================================================================================================
 @Service name        prvI2CInitErrorCheckEl1
 @Description         This function check and report any Error for the Init function
 @param[in]           I2cHardwareID      - HardwareID
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
static i2cEl1Status_e I2CInitErrorCheck(uint8 I2cHardwareID)
{
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    if ( I2cHardwareID >= MAX_NO_OF_SERIAL_ENGINE )
    {
        Status = I2C_EL1_HW_NOT_EXIST;
    }
    else if(I2cInitStatus[I2cHardwareID] == I2C_INITIALIZED)
    {
        Status = I2C_EL1_ERROR_ALREADY_INITIALIZED;
    }
    else
    {
        Status = I2C_EL1_SUCCESS; 
    }

    return Status;
}

/*=================================================================================================
 @Service name        prvI2cSE0DeInit_SleepEl1
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           SleepState -> SLEEP_ENTRY = arg from sleep driver to Deinit PSAIL Driver
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
 ================================================================================================*/
void I2cDeInit_Sleep( const sleepModeType_e SleepState )
{
    uint8 I2cHardwareID;
    if(STR_SLEEP_MODE == SleepState)
    {
        for(I2cHardwareID = 0U; I2cHardwareID < MAX_NO_OF_SERIAL_ENGINE; I2cHardwareID++)
        {
            if(I2cInitStatus[I2cHardwareID] == I2C_INITIALIZED)
            {
                if ( I2C_EL1_SUCCESS == xI2c_EL1_DeInit(I2cHardwareID) )
                {
                    if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(I2cSleepHandle[I2cHardwareID],DRIVER_SLEEP,get_curr_phys_cpu_num()))
                    {
                        DEBUG_LOG(SAIL_INFO,"I2c%d DeInit_Sleep xSleepDriverAck Success\n\r", I2cHardwareID);
                        I2cSleepHandle[I2cHardwareID] = 0x0u;
                    }else
                    {
                        DEBUG_LOG(SAIL_ERROR,"I2c%d DeInit_Sleep xSleepDriverAck Failed\n\r", I2cHardwareID);
                    }
                }else
                {
                    DEBUG_LOG(SAIL_ERROR,"I2c%d_DeInit Failed\n\r", I2cHardwareID);
                    err_fatal(I2CEL1,ERR_FATAL_FAULT_DETECTED);
                }
            }
        }
    }
}




/*=================================================================================================
 @Service name        prvI2cPinCtlResetEl1
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
static void I2cPinCtlReset(uint8 I2cHardwareID)
{
    void *pDTB = NULL;
    int offset = 0; 
    int root_offset = 0;
    const char *path;
    char i2c_name[5] = {'i', '2', 'c','0','\0'};
    uint32_t val_array0[2] = {0};
    int valSize = 2;
    uint8 ucGpioNumbers = 0x0u;
    GPIOConfigType QupPinCfg = {0x0u};

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
                    sail_gpio_config_pin(ucGpioNumbers,I2cEl1ResetStatePinCfg[I2cHardwareID][i]);
                }
            }
        } 
    }
}

/*=================================================================================================
 @Service name        I2cErrorHandle
 @Description         This function check for error status and call error handling sequence
 @param[in]           errorStatus  - Error such TX/RX SBE error. CMD Failure 
                      ucHardwareId   - I2c HW id
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
void I2cErrorHandle(i2cEl1Status_e errorStatus,uint32 ucHardwareId)
{
    i2cEl1Status_e status = I2C_EL1_UNKNOWN_FAILURE;
    switch (errorStatus)
    {
        case I2C_EL1_ERROR_TX_SBE:
            if(I2C_EL1_SUCCESS != I2cDMAResetHandle(ucHardwareId,I2c_Transmit))
            {
                DEBUG_LOG(LOG_ERROR,"Failure in DMA Reset operation for TX Reset\r\n");
            }
            if(I2C_EL1_SUCCESS != I2cCmdAbortHandle(ucHardwareId,I2c_Transmit))
            {
                DEBUG_LOG(LOG_ERROR,"Failure in CMD abort for TX Reset\r\n");
            }
        break;

        case I2C_EL1_ERROR_RX_SBE:
            if(I2C_EL1_SUCCESS != I2cDMAResetHandle(ucHardwareId,I2c_Receive))
            {
                DEBUG_LOG(LOG_ERROR,"Failure in DMA Reset operation for RX Reset\r\n");
            }
        break;

        case I2C_EL1_ERROR_M_CMD_FAILURE:
            if(I2C_EL1_SUCCESS != I2cCmdCancleHandle(ucHardwareId,I2c_Transmit))
            {
                DEBUG_LOG(LOG_ERROR,"Failure in CMD Cancle operation for Main Sequencer Command Failure, proceeding wth CMD Abort\r\n");
                if(I2C_EL1_SUCCESS != I2cCmdAbortHandle(ucHardwareId,I2c_Transmit))
                {
                    DEBUG_LOG(LOG_ERROR,"Failure in CMD abort for Main Sequencer Command Failure\r\n");
                }
                if(I2CHwConfig[ucHardwareId].Access_Mode == I2C_EL1_DMA_MODE)
                {
                    if(I2C_EL1_SUCCESS != I2cDMAResetHandle(ucHardwareId,I2c_Transmit))
                    {
                        DEBUG_LOG(LOG_ERROR,"Failure in DMA Reset operation for Main Sequencer Command Failure\r\n");
                    }
                }
            }
        break;

        case I2C_EL1_ERROR_M_CMD_OVERRUN:
            DEBUG_LOG(LOG_ERROR,"Reported a CMD Overrun in Main Sequencer \r\n");
        break;

        case I2C_EL1_ERROR_M_CMD_ILLEGAL:
            DEBUG_LOG(LOG_ERROR,"Reported a CMD Illegal in Main Sequencer \r\n");
        break;

        case I2C_EL1_ERROR_TX_FIFO_RD_ERR:
            DEBUG_LOG(LOG_ERROR,"Reported a TX FIFO Read Error \r\n");
        break;

        case I2C_EL1_ERROR_TX_FIFO_WR_ERR:
            DEBUG_LOG(LOG_ERROR,"Reported a TX FIFO Write Error \r\n");
        break;

        case I2C_EL1_ERROR_RX_FIFO_RD_ERR:
            DEBUG_LOG(LOG_ERROR,"Reported a RX FIFO Read Error \r\n");
        break;

        case I2C_EL1_ERROR_RX_FIFO_WR_ERR:
            DEBUG_LOG(LOG_ERROR,"Reported a RX FIFO Write Error \r\n");
        break;

        case I2C_EL1_ERROR_S_CMD_FAILURE: 
            if(I2C_EL1_SUCCESS != I2cCmdCancleHandle(ucHardwareId,I2c_Receive))
            {
                DEBUG_LOG(LOG_ERROR,"Failure in CMD Cancle operation for Secondary Sequencer Command Failure\r\n");
                if(I2C_EL1_SUCCESS != I2cCmdAbortHandle(ucHardwareId,I2c_Receive))
                {
                    DEBUG_LOG(LOG_ERROR,"Failure in CMD abort for Secondary Sequencer Command Failure\r\n");
                }
                if(I2CHwConfig[ucHardwareId].Access_Mode == I2C_EL1_DMA_MODE)
                {
                    if(I2C_EL1_SUCCESS != I2cDMAResetHandle(ucHardwareId,I2c_Receive))
                    {
                        DEBUG_LOG(LOG_ERROR,"Failure in DMA Reset operation for Secondary Sequencer Command Failure\r\n");
                    }
                }
            }        
        break;

        case I2C_EL1_ERROR_S_CMD_OVERRUN:
            DEBUG_LOG(LOG_ERROR,"Reported a CMD Overrun in Secondary Sequencer \r\n");
        break;

        case I2C_EL1_ERROR_S_CMD_ILLEGAL:
            DEBUG_LOG(LOG_ERROR,"Reported a CMD Illegal in Secondary Sequencer \r\n");
        break;

        default:

        break;        
    }

    return;    
}

/*=================================================================================================
 @Service name        I2cCmdCancleHandle
 @Description         This function performs Command cancel operation for DMA mode 
 @param[in]           ucHardwareId   - I2c HW id
                      operation      - Transmit/Receive operation
 @param[out]          NA
 @param[in, out]      NA
 @return              i2cEl1Status_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static i2cEl1Status_e I2cCmdCancleHandle(uint32 ucHardwareId, i2cOperationType operation)
{
    i2cEl1Status_e status = I2C_EL1_UNKNOWN_FAILURE;
    uint32 ulTimeoutMax = 500U;
    uint32 ulSE_Base = 0U;
    ulSE_Base = I2CHwConfig[ucHardwareId].se_base_addr;
    
	switch (operation) 
    {
        case I2c_Transmit:
            if(I2CHwConfig[ucHardwareId].Access_Mode == I2C_EL1_DMA_MODE)
            {
                REG_OUT(ulSE_Base,GENI_M_CMD_CTRL_REG,
                FLD_SET(GENI_M_CMD_CTRL_REG, M_GENI_CMD_CANCEL, 0x1));
                do
                {
                    /* Check if the Cancel IRQ Interrupt set */
                    if(REG_INF(ulSE_Base,DMA_TX_IRQ_STAT,GENI_CANCEL_IRQ) != 0U)
                    {
                        break;
                    }
                    else
                    {
                        busywait(5U);
                        ulTimeoutMax -= 5U;
                        if ( 0U == ulTimeoutMax )
                        {
                            return I2C_EL1_ERROR_TIMEOUT;
                        }
                    }
                }while ((ulTimeoutMax != 0U));
            }
            else if(I2CHwConfig[ucHardwareId].Access_Mode ==  I2C_EL1_FIFO_MODE)
            {
                REG_OUT(ulSE_Base,GENI_M_CMD_CTRL_REG,
                FLD_SET(GENI_M_CMD_CTRL_REG, M_GENI_CMD_CANCEL, 0x1));
                do
                {
                    /* Check if the Cancel IRQ Interrupt set */
                    if (FLD_GET(REG_IN(ulSE_Base, GENI_M_IRQ_STATUS), GENI_M_IRQ_STATUS, M_CMD_CANCEL) != 0U)
                    {
                        REG_OUT(ulSE_Base, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_M_CMD_CANCEL_CLEAR_BMSK);
                        if(REG_INF(ulSE_Base,GENI_M_IRQ_STATUS,M_RX_IRQ) == 0U)
                        {
                            uint8 txWordCount = REG_INF(ulSE_Base,GENI_M_GP_LENGTH,M_GP_LENGTH);
                        }
                        break;
                    }
                    else
                    {
                        busywait(5U);
                        ulTimeoutMax -= 5U;
                        if ( 0U == ulTimeoutMax )
                        {
                            return I2C_EL1_ERROR_TIMEOUT;
                        }
                    }
                }while ((ulTimeoutMax != 0U));                
            }
            else
            {
                // polling
            }

        break;

        case I2c_Receive:
            if(I2CHwConfig[ucHardwareId].Access_Mode == I2C_EL1_DMA_MODE)
            {
                REG_OUT(ulSE_Base,GENI_S_CMD_CTRL_REG,
                FLD_SET(GENI_S_CMD_CTRL_REG, S_GENI_CMD_CANCEL, 0x1));
                
                do
                {
                    /* Check if the Cancel IRQ Interrupt set */
                    if(REG_INF(ulSE_Base,DMA_RX_IRQ_STAT,EOT) != 0U)
                    {
                        break;
                    }
                    else
                    {
                        busywait(5U);
                        ulTimeoutMax -= 5U;
                        if ( 0U == ulTimeoutMax )
                        {
                            return I2C_EL1_ERROR_TIMEOUT;
                        }
                    }
                }while ((ulTimeoutMax != 0U));
            }
            else if(I2CHwConfig[ucHardwareId].Access_Mode == I2C_EL1_FIFO_MODE)
            {
                REG_OUT(ulSE_Base,GENI_S_CMD_CTRL_REG,
                FLD_SET(GENI_S_CMD_CTRL_REG, S_GENI_CMD_CANCEL, 0x1));
                
                do
                {
                    if (FLD_GET(REG_IN(ulSE_Base, GENI_S_IRQ_STATUS), GENI_S_IRQ_STATUS , S_CMD_CANCEL) != 0U)
                    {
                        REG_OUT(ulSE_Base, GENI_S_IRQ_CLEAR, HWIO_GENI_S_IRQ_CLEAR_S_CMD_CANCEL_CLEAR_BMSK);
                        // Read GENI_RX_FIFO_STATUS for WC. If WC > 0, read GENI_RX_FIFO registers
                        // Clear GENI_S_IRQ_STATUS.RX_LAST and GENI_S_IRQ_STATUS.S_GP_SYNC_IRQ interrupts.
                        if(REG_INF(ulSE_Base,GENI_RX_FIFO_STATUS,RX_LAST) == 1U)
                        {
                            uint32 ulRx_FifoStatus = REG_IN(ulSE_Base, GENI_RX_FIFO_STATUS);
                            uint32 ulBytes_ToRead =  FLD_GET(ulRx_FifoStatus, GENI_RX_FIFO_STATUS, RX_FIFO_WC) * i2cBYTES_PER_FIFO_REG;
                            uint16 ucReadCount = 0U;
                            uint32 ulWord = 0U;

                            if(ulBytes_ToRead > 0U)
                            {
                                for(ucReadCount = 0U; ucReadCount < ulBytes_ToRead; ucReadCount++)
                                {
                                    if((ucReadCount % i2cBYTES_PER_FIFO_REG) == 0U)
                                    {
                                        ulWord = REG_INI(ulSE_Base, GENI_RX_FIFOn, 0);
                                    }
                                }
                            }
                        }
                        REG_OUT(ulSE_Base, GENI_S_IRQ_CLEAR, HWIO_GENI_S_IRQ_CLEAR_RX_FIFO_LAST_CLEAR_BMSK);
                        REG_OUT(ulSE_Base, GENI_S_IRQ_CLEAR, HWIO_GENI_S_IRQ_CLEAR_S_GP_SYNC_IRQ_0_CLEAR_BMSK);
                        break;
                    }
                    else
                    {
                        busywait(5U);
                        ulTimeoutMax -= 5U;
                        if ( 0U == ulTimeoutMax )
                        {
                            return I2C_EL1_ERROR_TIMEOUT;
                        }
                    }
                }while ((ulTimeoutMax != 0U));
            }
            else
            {
                // polling
            }

        break;

        default:

        break;
    }

    status = I2C_EL1_SUCCESS;
    return status;
}

/*=================================================================================================
 @Service name        I2cDMAResetHandle
 @Description         This function performs Command cancel operation for DMA mode 
 @param[in]           ucHardwareId   - I2c HW id
                      operation      - Transmit/Receive operation
 @param[out]          NA
 @param[in, out]      NA
 @return              i2cEl1Status_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static i2cEl1Status_e I2cDMAResetHandle(uint32 ucHardwareId, i2cOperationType operation)
{
    i2cEl1Status_e status = I2C_EL1_UNKNOWN_FAILURE;
    uint32 ulTimeoutMax = 500U;
    uint32 ulSE_Base = 0U;
    ulSE_Base = I2CHwConfig[ucHardwareId].se_base_addr;

	switch (operation) 
    {
        case I2c_Transmit:
            REG_OUT(ulSE_Base,DMA_TX_FSM_RST,
            FLD_SET(DMA_TX_FSM_RST, TX_FSM_RST, 0x1));
            do
            {
                /* Check if the Reset is done*/
                if( REG_INF(ulSE_Base,DMA_TX_IRQ_STAT,RESET_DONE) != 0U)
                {
                    // Clear the Reset done IRQ bit
                    REG_OUT(ulSE_Base, DMA_TX_IRQ_CLR, HWIO_DMA_TX_IRQ_CLR_RESET_DONE_CLR_BMSK);
                    REG_OUT(ulSE_Base, DMA_TX_IRQ_CLR, HWIO_DMA_TX_IRQ_CLR_DMA_DONE_CLR_BMSK);
                    break;
                }
                else
                {
                    busywait(5U);
                    ulTimeoutMax -= 5U;
                    if ( 0U == ulTimeoutMax )
                    {
                        return I2C_EL1_ERROR_TIMEOUT;
                    }
                }
            }while ((ulTimeoutMax != 0U));

        break;

        case  I2c_Receive:
            REG_OUT(ulSE_Base,DMA_RX_FSM_RST,
            FLD_SET(DMA_RX_FSM_RST, RX_FSM_RST, 0x1));

            do
            {
                /* Check if the Reset is done*/
                if( REG_INF(ulSE_Base,DMA_RX_IRQ_STAT,RESET_DONE) == 1U)
                {
                    // Clear the Reset done IRQ bit

                    REG_OUT(ulSE_Base, DMA_RX_IRQ_CLR, HWIO_DMA_RX_IRQ_CLR_RESET_DONE_CLR_BMSK);
                    REG_OUT(ulSE_Base, DMA_RX_IRQ_CLR, HWIO_DMA_RX_IRQ_CLR_DMA_DONE_CLR_BMSK);
                    break;
                }
                else
                {
                    busywait(5U);
                    ulTimeoutMax -= 5U;
                    if ( 0U == ulTimeoutMax )
                    {
                        return I2C_EL1_ERROR_TIMEOUT;
                    }
                }
            }while ((ulTimeoutMax != 0U));

        break;

        default:

        break;        
    }

    status = I2C_EL1_SUCCESS;
    return status;
}

/*=================================================================================================
 @Service name        I2cCmdAbortHandle
 @Description         This function performs Command Abort operation if timeout happens while CMD 
                      cancel operation
 @param[in]           ucHardwareId   - I2c HW id
                      operation      - Transmit/Receive operation
 @param[out]          NA
 @param[in, out]      NA
 @return              i2cEl1Status_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
static i2cEl1Status_e I2cCmdAbortHandle(uint32 ucHardwareId, i2cOperationType operation)
{
    i2cEl1Status_e status = I2C_EL1_UNKNOWN_FAILURE;
    uint32 ulTimeoutMax = 500U;
    uint32 ulSE_Base = 0U;

    ulSE_Base = I2CHwConfig[ucHardwareId].se_base_addr;

    switch (operation)
    {
        case I2c_Transmit:
            REG_OUT(ulSE_Base,GENI_M_CMD_CTRL_REG,
            FLD_SET(GENI_M_CMD_CTRL_REG, M_GENI_CMD_ABORT, 0x1));
            do
            {
                /* Check if the CMD abort is done*/
                if( REG_INF(ulSE_Base,GENI_M_IRQ_STATUS,M_CMD_ABORT) != 0U)
                {
                    // Clear the Reset done IRQ bit
                    REG_OUT(ulSE_Base, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_M_CMD_ABORT_CLEAR_BMSK);
                    REG_OUT(ulSE_Base,GENI_FORCE_DEFAULT_REG, FLD_SET(GENI_FORCE_DEFAULT_REG, FORCE_DEFAULT, 0x1));
                    break;
                }
                else
                {
                    busywait(5U);
                    ulTimeoutMax -= 5U;
                    if ( 0U == ulTimeoutMax )
                    {
                        return I2C_EL1_ERROR_TIMEOUT;
                    }
                }
            }while ((ulTimeoutMax != 0U));

        break;

        case I2c_Receive:      
            REG_OUT(ulSE_Base,GENI_S_CMD_CTRL_REG,
            FLD_SET(GENI_S_CMD_CTRL_REG, S_GENI_CMD_ABORT, 0x1));
            do
            {
                /* Check if the CMD abort is done*/
                if( REG_INF(ulSE_Base,GENI_S_IRQ_STATUS,S_CMD_ABORT) != 0U)
                {
                    // Clear the Reset done IRQ bit
                    REG_OUT(ulSE_Base, GENI_S_IRQ_CLEAR, HWIO_GENI_S_IRQ_CLEAR_S_CMD_ABORT_CLEAR_BMSK);
                    break;
                }
                else
                {
                    busywait(5U);
                    ulTimeoutMax -= 5U;
                    if ( 0U == ulTimeoutMax )
                    {
                        return I2C_EL1_ERROR_TIMEOUT;
                    }
                }
            }while ((ulTimeoutMax != 0U));

            REG_OUT(ulSE_Base,GENI_FORCE_DEFAULT_REG,
            FLD_SET(GENI_FORCE_DEFAULT_REG, FORCE_DEFAULT, 0x1));
        break;

        default:

        break;        
    }

    status = I2C_EL1_SUCCESS;
    return status;

}
/**************************************************************************************************
**                                  End of file i2c_el1.c                                        **
**************************************************************************************************/
#ifdef I2C_TEST_ENABLE
#include "i2c_el1_test_wrapper.h"
#endif
