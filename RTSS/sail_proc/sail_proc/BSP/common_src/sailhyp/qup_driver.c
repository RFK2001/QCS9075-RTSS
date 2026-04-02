
/*
===========================================================================
*/
/**
    @file  qup_driver.c
    @brief SAIL QUP driver initialization

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/common_src/sailhyp/qup_driver.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/
/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <string.h>
#include <libfdt.h>
#include "fdt_utils.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "Clock.h"
#include "common_functions.h"
#include "qup_common_hwio.h"
#include "gpio.h"
#include "sailbsp_mutex.h"

/*=================================================================================================
**                                        Local defines and macros                               **
=================================================================================================*/
#define SAIL_QUPV3_HW_VERSION            0x300B0000U

#define FWARRAY_IDXBOUNDARY         	0x13U
#define FWARRAY_IDXOFFSET           	0x2DU
#define FWCFGSIZE                   	0x45U

#define UART_FWCFGVERSION               0x0AU
#define UART_FWVERSION                  0x0404U
#define UART_SERIALPROTOCOL             0x2U

#define SPIS_FWCFGSIZE          		0x44U
#define SPIS_FWCFGVERSION       		0x6U
#define SPI_FWARRAY_IDXOFFSET   		0x2DU
#define SPIM_FWCFGVERSION       		0x9U
#define SPIS_SERIALPROTOCOL             0x5U
#define SPIS_FWVERSION                  0x010AU
#define SPIM_SERIALPROTOCOL             0x1U
#define SPIM_FWVERSION                  0x0b02U

#define i2cFWCFGVERSION             	0x9U
#define i2cFWPROTOCOL               	0x3U
#define i2cFWVERSION                	0x0103U

#define UART_PROTOCOL 					1U
#define I2C_PROTOCOL 					2U
#define SPI_PROTOCOL 					3U
#define SPI_SLAVE_PROTOCOL 				4U

#define HWIO_GENI_CFG_REGn_OFFS(n)                      (GENI4_IMAGE_REGS_REG_BASE_OFFS+ 0x4*n)

#define  QUP_CRITCAL_SECTION_START()                            mutex_lock(&stQupCoreLock)
#define  QUP_CRITCAL_SECTION_END()                              mutex_unlock(&stQupCoreLock)

/*=================================================================================================
**                  Static variables, structures and constants                                 **
=================================================================================================*/
typedef struct
{
	uint32 protocol;
	uint32 ulreg_base;
	const char   *psSE_clock;
	uint32 clock_freq;
} qupHWConfigType;

static qupHWConfigType xqupHWConfigType;
static qupHWConfigType xqupHWConfigType = {0};
static uint32 ulQupCommonBase;
mutex_t stQupCoreLock = {0};

static uint32  ulQupV3SPISlaveFW[] =
{
	0x00000000, 0x00000400, 0x00000000, 0x00000000, 0x0000f078, 0x00000045, 0x00000007, 0x00000000,
	0x00000000, 0x0001000a, 0x00000140, 0x00000000, 0x00000000, 0x0004501c, 0x000ba800, 0x00c083a2,
	0x00800128, 0x00801008, 0x00000000, 0x00000201, 0x0000ce05, 0x0002c2e7, 0x0a415c00, 0x0010011a,
	0x08800000, 0x00000000, 0x00092c00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00008D01, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x0004380e, 0x000c3e0e, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0007f807, 0x000ffefe, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000
};

static uint32 ulQupV3SPIMasterFW[] =
{
	0x00000000, 0x00000400, 0x00000000, 0x00000000, 0x00240e78, 0x00011088, 0x00240007, 0x00000000,
	0x00000000, 0x0001000a, 0x00000300, 0x00000000, 0x00000000, 0x00000000, 0x00154400, 0x001483a0,
	0x00aa8128, 0x00641002, 0x00004000, 0x00000201, 0x0001fe05, 0x0002c2e7, 0x0a435c00, 0x0010011a,
	0x08800000, 0x00000000, 0x100cac00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x000018e4, 0x00000000, 0x00000003, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x0007f807, 0x000ffefe, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00200000, 0x00000004, 0x00000009, 0x0007f807, 0x000ffefe, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00c0033f,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000055
};

static uint32  ulSail_qup_v1_2_uart_fw[] =
{
    0x00000024U, 0x00000000U, 0x00000024U, 0x00000000U, 0x00019a00U, 0x00400000U, 0x00e00000U, 0x00010020U,
    0x00000000U, 0x00000000U, 0x00000300U, 0x00000700U, 0x00000400U, 0x00000000U, 0x00000000U, 0x00c00000U,
    0x00000000U, 0x00c00024U, 0x00000b00U, 0x00020231U, 0x0000ce05U, 0x000360e7U, 0x0941e6a8U, 0x00100510U,
    0x42c01e51U, 0x00000401U, 0x002e8400U, 0x1694581aU, 0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000001U, 0x0000031cU, 0x00000000U, 0x0000000fU, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00081c06U, 0x00004010U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x0000000dU, 0x00000000U, 0x00081c06U, 0x00004010U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00c02415U, 0x0000000eU, 0x00000001U, 0x00000001U, 0x00000000U, 0x00c00000U,
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U, 0x00000055U
};

static uint32 qup_v3_1_i2c_fw[] =
{
    0x00000090, 0x00000000, 0x00000090, 0x00000000, 0x00038028, 0x00084080, 0x00000343, 0x00010000,
    0x00000000, 0x00001a00, 0x00000100, 0x00000000, 0x00000000, 0x00000000, 0x00808008, 0x001c0020,
    0x00000000, 0x00020000, 0x00000000, 0x00000201, 0x0001fc01, 0x00036222, 0x09c01ffc, 0x00100120,
    0x02c00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001,
    0x00000000, 0x00000000, 0x00000000, 0x00000409, 0x00000003, 0x00000002, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0007f8fe, 0x000ffefe, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x0007f807, 0x000ffefe, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00c00000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000055
};
void vQupPlatformDriverInit(void);
/*=================================================================================================
**                                        Local function prototypes                              **
=================================================================================================*/
static void prvLoadSEFirmware(uint32 ulProtocol, uint32 ulSERegBase);
static void prvReadDeviceTreeSettings(const char *path, uint32 protocol);
static ClockResult prvDisableSEClock( const char *clk_name);
/*=================================================================================================
**                                   Global function definitions                                 **
=================================================================================================*/
/*=================================================================================================
 @Service name        vQupPlatformDriverInit
 @Description         This function loads firmware, initialize gpio and clock of all SE
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              Nil
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
void vQupPlatformDriverInit(void)
{
	static uint8 qupInitializationFlag = 0;
	int32_t root_offset = 0;
	const char *path;
	char uart_name[6] = {'u', 'a', 'r', 't','0','\0'};
	char i2c_name[5] = {'i', '2', 'c','0','\0'};
	char spi_name[5] = {'s', 'p', 'i','0','\0'};
	void *pDTB = NULL;

	QUP_CRITCAL_SECTION_START();

	if(1 == qupInitializationFlag){
		return;
	}

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/qup");
		(void)fdt_getprop_u32(pDTB, root_offset, "common-addr", &ulQupCommonBase);
		root_offset = fdt_path_offset(pDTB, "/aliases");

		for(uint8 k = 0 ; k < (uint8)MAX_NO_OF_SERIAL_ENGINE; k++)
		{
			uart_name[4] = (k+48);
			path = (const char*)fdt_getprop(pDTB, root_offset, uart_name , NULL);
			if (path != NULL) {
				prvReadDeviceTreeSettings(path, UART_PROTOCOL);
			}
		}

		for(int k = 0 ; k < (uint8)MAX_NO_OF_SERIAL_ENGINE; k++)
		{
			 i2c_name[3] = (k+48);
			 path = (const char*)fdt_getprop(pDTB, root_offset, i2c_name , NULL);
			 if (path != NULL) {
				 prvReadDeviceTreeSettings(path, I2C_PROTOCOL);
			 }
		}

		for(int k = 0 ; k < (uint8)MAX_NO_OF_SERIAL_ENGINE; k++)
		{
			spi_name[3] = (k+48);
			path = (const char*)fdt_getprop(pDTB, root_offset, spi_name , NULL);
			if (path != NULL) {
				prvReadDeviceTreeSettings(path, SPI_PROTOCOL);
			}
		}
	}
	qupInitializationFlag = 1;

	QUP_CRITCAL_SECTION_END(); 
}

/*=================================================================================================
**                                   Local function definitions                                 **
=================================================================================================*/
/*=================================================================================================
 @Service name        prvLoadSEFirmware
 @Description         This function loads firmware of all SE
 @param[in]           ulProtocol - selected protocol
 	 	 	 	 	  ulSERegBase - base address
 @param[out]          NA
 @param[in, out]      NA
 @return              Nil
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
static void prvLoadSEFirmware(uint32 ulProtocol, uint32 ulSERegBase)
{
	uint8 ucCfgRegCount = 0x0U;
    uint32 ulFwConfigVersion = 0x0U;
    uint32 *puFwArrayptr = ulQupV3SPISlaveFW;
    uint32 ulSerialProtocol = 0x0U;
    uint32 ulFwVersion = 0x0U;
    uint32 ulFirmwareSize  = FWCFGSIZE;
    uint8 ucCfgReg_count = 0x0U;

	uint32 ulQupV3HWVer = REG_IN( ulQupCommonBase, QUPV3_HW_VERSION);
    /* HPG section 3.1.2 */
    REG_OUTF(ulQupCommonBase, QUPV3_COMMON_CFG, FAST_SWITCH_TO_HIGH_DISABLE,1);

    /* SE-WRAPPER CGC clock-on.As per HPG section 3.1.7.3 */
    REG_OUTF(ulQupCommonBase, QUPV3_SE_AHB_M_CFG, AHB_M_CLK_CGC_ON,1);

	if( ( ulProtocol == (uint32)SPI_PROTOCOL) || (ulProtocol == (uint32)SPI_SLAVE_PROTOCOL))
	{
		if( ulProtocol == (uint32)SPI_SLAVE_PROTOCOL )
		{
			/* Update the Firmware config properties for SPI slave*/
			ulFwConfigVersion = SPIS_FWCFGVERSION;
			puFwArrayptr = ulQupV3SPISlaveFW;
			ulFirmwareSize = SPIS_FWCFGSIZE;
			ulSerialProtocol = SPIS_SERIALPROTOCOL;
			ulFwVersion = SPIS_FWVERSION;
		}
		else
		{
			/* Update the Firmware config properties for SPI Master*/
			ulFwConfigVersion = SPIM_FWCFGVERSION;
			puFwArrayptr = ulQupV3SPIMasterFW;
			ulSerialProtocol = SPIM_SERIALPROTOCOL;
			ulFwVersion = SPIM_FWVERSION;
		}
	}
	else if( ulProtocol == (uint32)UART_PROTOCOL)
	{
		ulFwConfigVersion = UART_FWCFGVERSION;
		puFwArrayptr = ulSail_qup_v1_2_uart_fw;
		ulSerialProtocol = UART_SERIALPROTOCOL;
		ulFwVersion = UART_FWVERSION;
	}
	else if( ulProtocol == (uint32)I2C_PROTOCOL)
	{
		ulFwConfigVersion = i2cFWCFGVERSION;
		puFwArrayptr = qup_v3_1_i2c_fw;
		ulSerialProtocol = i2cFWPROTOCOL;
		ulFwVersion = i2cFWVERSION;
	}
	else
	{
		; /*MCDC*/
	}

	/* Check if the HW version is matching*/
	if( ulQupV3HWVer == SAIL_QUPV3_HW_VERSION)
	{
		REG_OUT( ulSERegBase, GENI_FW_REVISION,
			FLD_SET( GENI_FW_REVISION, PROTOCOL, ulSerialProtocol) |
			FLD_SET( GENI_FW_REVISION, VERSION, ulFwVersion));

		REG_OUT( ulSERegBase, GENI_S_FW_REVISION,
			FLD_SET( GENI_S_FW_REVISION, PROTOCOL, ulSerialProtocol) |
			FLD_SET( GENI_S_FW_REVISION, VERSION, ulFwVersion));

		/* Update the configuration version HPG section 3.1.7.4 */
		REG_OUT(ulSERegBase, GENI_INIT_CFG_REVISION,
					FLD_SET(GENI_INIT_CFG_REVISION, VERSION, ulFwConfigVersion));

		REG_OUT(ulSERegBase, GENI_S_INIT_CFG_REVISION,
					FLD_SET(GENI_S_INIT_CFG_REVISION, VERSION, ulFwConfigVersion));

		/* Write the GENI Primitive table Configuration for UART protocol*/
		for (ucCfgRegCount = 0U; ucCfgRegCount < FWARRAY_IDXBOUNDARY; ucCfgRegCount++)
		{
			REG_OUTI( ulSERegBase, GENI_CFG_REGn, ucCfgRegCount, puFwArrayptr[ucCfgRegCount]);
		}
		/* Write the GENI functional configuration for UART protocol*/
		for (ucCfgRegCount = FWARRAY_IDXBOUNDARY; ucCfgRegCount < ulFirmwareSize; ucCfgRegCount++)
		{
			REG_OUTI( ulSERegBase, GENI_CFG_REGn, (ucCfgRegCount + FWARRAY_IDXOFFSET), puFwArrayptr[ucCfgRegCount] );
		}
	}

}

/*=================================================================================================
 @Service name        prvEnableSEClock
 @Description         This function enables the clock of all SE
 @param[in]           clock_freq - selected frequency
 	 	 	 	 	  clk_name - clock name
 @param[out]          NA
 @param[in, out]      NA
 @return              ClockResult - clock enable status
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
static ClockResult prvEnableSEClock( uint32 clock_freq, const char *clk_name)
{
    ClockResult eResult = CLOCK_ERROR;
    ClockIdType nClockId = 0U;
    uint32_t ulNFreq;
    uint8 ucCount = 0U;
	ClockHandle hClient = 0U;

	(void)Clock_GetHandle(&hClient);

    eResult = Clock_GetClockId(hClient, clk_name,  (ClockIdType *)&nClockId);

    if ( eResult == CLOCK_SUCCESS )
    {
        eResult = Clock_SetClockFrequency(hClient, nClockId,
        								clock_freq,
										  CLOCK_FREQUENCY_HZ_AT_LEAST,&ulNFreq);

        eResult = Clock_EnableClock(hClient, nClockId);

    }
    return eResult;
}

/*=================================================================================================
 @Service name        prvDisableSEClock
 @Description         This function disables the clock of all SE
 @param[in]           clk_name - clock name
 @param[out]          NA
 @param[in, out]      NA
 @return              ClockResult - clock disable status
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
static ClockResult prvDisableSEClock( const char *clk_name)
{
    ClockResult eResult = CLOCK_SUCCESS;
    ClockIdType nClockId = 0U;
    uint32_t ulNFreq;
    uint8 ucCount = 0U;
	ClockHandle hClient = 0U;

	(void)Clock_GetHandle(&hClient);

    eResult = Clock_GetClockId(hClient, clk_name,  (ClockIdType *)&nClockId);

    if ( eResult == CLOCK_SUCCESS )
    {
    	if( CLOCK_SUCCESS != Clock_DisableClock( hClient, nClockId))
    	{
    		eResult = CLOCK_ERROR;
    	}
    }
    return eResult;
}

/*=================================================================================================
 @Service name        prvReadDeviceTreeSettings
 @Description         This function reads configuration parameters from DTS file
 @param[in]           path - node path
 	 	 	 	 	  protocol - selected protocol
 @param[out]          NA
 @param[in, out]      NA
 @return              Nil
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
static void prvReadDeviceTreeSettings(const char *path, uint32 protocol)
{
	int32_t offset = 0, root_offset = 0;
	const char *pin_path;
	uint32_t val_array0[5] = {0}, val_array1[5], val_array2[5],val_array3[5], val_array4[5];
	int32_t valSize = 5, val = 5;
	int valSize_st = 2;
	uint32 spi_slave;
	ClockResult xClockRet = CLOCK_ERROR;
	void *pDTB = NULL;

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		offset = fdt_path_offset(pDTB, path);
		(void)fdt_getprop_u32(pDTB, offset, "reg-base", &xqupHWConfigType.ulreg_base);
		xqupHWConfigType.psSE_clock = (char*) fdt_getprop(pDTB, offset, "clock-name", &valSize_st);
		(void)fdt_getprop_u32(pDTB, offset, "clock-frequency", &xqupHWConfigType.clock_freq);
			if(protocol == (uint32)SPI_PROTOCOL)
			{
				(void)fdt_getprop_u32(pDTB, offset, "slave", &spi_slave);
				if(spi_slave == 0x1U)
				{
					protocol = (uint32)SPI_SLAVE_PROTOCOL;
				}
			}
		/* Enables the clock*/
		xClockRet = prvEnableSEClock(xqupHWConfigType.clock_freq, xqupHWConfigType.psSE_clock);
		if(xClockRet == CLOCK_SUCCESS)
		{
			/* Load  the firmware*/
			prvLoadSEFirmware( protocol, xqupHWConfigType.ulreg_base);
		}
		prvDisableSEClock( xqupHWConfigType.psSE_clock);
	}
}


