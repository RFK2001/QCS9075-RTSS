#ifndef SPI_UT_H
#define SPI_UT_H
/**************************************************************************************************
    Copyright (c) 2023-2024 Qualcomm Technologies, Inc.
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
    File Name          : spi_ut.h
    Component Name     : SPI
    Description        : Spi driver unit test header file
    $Header: $
    $DateTime:  $
    $Author: $
=================================================================================================*/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include <stdio.h>
#include "hw_io.h"
#include "spi_hal.h"

/******************************************************************************
**                			Private Macro and Variables                      **
******************************************************************************/
#define TEST_DATA  __attribute__ ( ( section ("test_data" ) ) )
#define TEST_FUNC  __attribute__ ( ( section ("test_func" ) ) )

/*******************************************************************************
**                    Local Fucntion Definitions                              **
*******************************************************************************/
#ifdef SPI_UT_ENABLE
TEST_FUNC void UT_Configure_Sequence( void )
{
	prvSPIPackingConfig(0xF1910000,8);
	prvSPIPackingConfig(0xF1910000,16);
	prvSPIPackingConfig(0xF1910000,32);
}

TEST_FUNC void UT_Read_Write_FiFo( void )
{
	xSpiChannelData[0].ulTransLen = 0x0;
	prvSPIReadFromFifo(0);
	prvSPIWriteToFifo(0);

	xSpiChannelData[0].ulTransLen = 0x50;
	prvSPIReadFromFifo(0);
	prvSPIWriteToFifo(0);
}

TEST_FUNC void UT_ConfigureChannel( void )
{
	spiChannelCfgType xTestChCfg =
	{
				0, //ucChannelId;
				0,//ucAssignedHwId;
				1, //ucSPISlaveIndex;
				1, //ucCSClkDelayCycles;
				1, //ucInterWordDealyCycles;
				1, //bCSToggle;
				1, //bLeaveCSAsserted;
				32, //ucSPIBitsPerWord;
				1, //xSPICsPolarity;
				NULL,
				NULL

	};
	prvSPIConfigureChannel(&xTestChCfg, 0xF1910000);
}

TEST_FUNC void UT_ControlClock( void )
{
	spiHwUnitCfgType HwTestCfg2 =
	{
			0xF1910000, //ulSEBaseAddr;
			0, //ulHardwareId;
			0, //ucActiveChannelId;
			0, //SpiDataShiftEdge;
			0, //SpiShiftClockIdleLevel;
			2, //ucNoOfChannels;
			0, //ulSlave;
			1, //ulLoopbackMode;
			0, //ulIntNum;
			0, //ucSpiBaudrate;
			0, //ulClkFrequency;
			NULL,// *psSE_clock;
			1,// eAccessMode;
			0//status
	};

	spiHwUnitCfgType HwTestCfg =
	{
			0xF1910000, //ulSEBaseAddr;
			0, //ulHardwareId;
			0, //ucActiveChannelId;
			0, //SpiDataShiftEdge;
			0, //SpiShiftClockIdleLevel;
			2, //ucNoOfChannels;
			0, //ulSlave;
			1, //ulLoopbackMode;
			0, //ulIntNum;
			0, //ucSpiBaudrate;
			100, //ulClkFrequency;
			"sailss_cc_qupv3_wrap0_s4_clk",// *psSE_clock;
			0,// eAccessMode;
			0//status
	};
	/*Re- Enable the clock*/
	prvSPIClockEnable( &HwTestCfg);
	/* return failure for Clock_IsClockEnabled*/
	prvSPIClockEnable( &HwTestCfg);
	prvSPIClockDisable( &HwTestCfg);

	/* Change get handle as NULL*/
	prvSPIClockDisable( &HwTestCfg2);
	/* Change get handle as NULL*/
	prvSPIClockEnable( &HwTestCfg2);

	/* Change get clock id */
	prvSPIClockDisable( &HwTestCfg);
	prvSPIClockEnable( &HwTestCfg2);

	/*change Clock_SetClockFrequency return val*/
	prvSPIClockEnable( &HwTestCfg);

	/*change enable clock and disable clock return err*/
	prvSPIClockEnable( &HwTestCfg);
	prvSPIClockDisable( &HwTestCfg);
}

TEST_FUNC void UT_DeviceTreeParam( void )
{
	/*change no.of device to 0*/
	prvSPILoadDeviceTreeSettings();

	/*change path to null*/
	prvSPILoadDeviceTreeSettings();
	 // CHIPINFO_FAMILY_MONACOAU   is 0x91
	prvSPILoadDeviceTreeSettings();
}

TEST_FUNC void UT_BusTransferErr( void )
{
	int arg = 0x0;
	spiHwUnitCfgType HwTestCfg2 =
	{
			0xF1910000, //ulSEBaseAddr;
			0, //ulHardwareId;
			0, //ucActiveChannelId;
			0, //SpiDataShiftEdge;
			0, //SpiShiftClockIdleLevel;
			2, //ucNoOfChannels;
			1, //ulSlave;
			1, //ulLoopbackMode;
			0x196, //ulIntNum;
			4, //ucSpiBaudrate;
			100000000, //ulClkFrequency;
			"sailss_cc_qupv3_wrap0_s4_clk",// *psSE_clock;
			1,// eAccessMode;
			0//status
	};
	/*Change intrpt register failure for FIFO mode as 0x0*/
	prvSPISerialEngineInit(&HwTestCfg2, 0xf1900000);

	HwTestCfg2.eAccessMode = 0x2;
	/*Change intrpt register failure for DMA mode*/
	prvSPISerialEngineInit(&HwTestCfg2, 0xf1900000);

}

TEST_FUNC void UT_UpdateChannelStatus(void)
{
	xSpiChannelData[0].xXferState = SPI_TRANSFER_IN_PROGRESS;
}
#endif
#endif /* SPI_UT_H */
