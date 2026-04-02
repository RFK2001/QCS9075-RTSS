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
    File Name          : i2c_el1_tests.c
    Component Name     : I2C EL1 test
    Description        : I2C EL1 test
    $Header: 
    $DateTime: 
    $Author: 
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <stdio.h>
#include "tests.h"
#include "i2c_el1.h"
#include "hw_io.h"
#include "crc.h"
#include "crcconfig.h"
#include "debug_log.h"
#include "psailInternal.h"
#include "pmicapi.h"
#include "qup_common_hwio.h"
#include "hw_io.h"
//#include "wdt_safertos.h"
#include "sleep_cmm.h"
//#include "monitor.h"
//#include "acmu_monitor.h"

/*=================================================================================================
**                                     Macros                                                    **
=================================================================================================*/

/*********************************** SE0 Configuration *******************************************/

/* No of Channels support for Serial Engines */
#define i2cSE0_MIN_CHANNEL_ID                                                      0U
#define i2cSE0_MAX_CHANNEL_ID                                                      6U
#define i2cSE0_MAX_CHANNELS                                                        7U

/* I2C HW Configuration & Interrupt Number */
#define i2cSE0_HW_CHANNEL_INT_NUM                                                  402U

/* SE0 I2C Slave Address Configuration */
#define i2cTI_PMIC_SLAVEADDRESS_PAGE0                                              0x28U
#define i2cTI_PMIC_SLAVEADDRESS_PAGE1                                              0x29U
#define i2cTI_PMIC_SLAVEADDRESS_PAGE4                                              0x12U
#define i2cPSAIL_KOBRA_B_SLAVEADDRESS                                              0x11U
#define i2cPSAIL_KOBRA_D_SLAVEADDRESS                                              0x13U
#define i2cPSAIL_KOBRA_F_SLAVEADDRESS                                              0x15U
#define i2cPSAIL_KOBRA_H_SLAVEADDRESS                                              0x17U

/* SE0 I2C Channels for i2cHW_CHANNEL_0 */ 
#define i2cTI_PMIC_PAGE_0_0                                                        0U
#define i2cTI_PMIC_PAGE_1_1                                                        1U
#define i2cTI_PMIC_PAGE_4_2                                                        2U
#define i2cKobra_PSAIL_B                                                           3U
#define i2cKobra_PSAIL_D                                                           4U
#define i2cKobra_PSAIL_F                                                           5U
#define i2cKobra_PSAIL_H                                                           6U

/*********************************** SE3 Configuration *******************************************/

/* No of Channels support for Serial Engines */
#define i2cSE3_MIN_CHANNEL_ID                                                      7U
#define i2cSE3_MAX_CHANNEL_ID                                                      7U
#define i2cSE3_MAX_CHANNELS                                                        1U

/* I2C HW Configuration & Interrupt Number */
#define i2cSE3_HW_CHANNEL_INT_NUM                                                  405U

/* SE3 I2C Slave Address Configuration */
#define i2cSE3_SLAVEADDRESS_0                                                      0x2U


/* SE3 I2C Channels for i2cHW_CHANNEL_0 */ 
#define i2cSE3_CHANNEL_ID_0                                                        7U

/*********************************** Common Configuration ****************************************/
/* No of Hardwares supported by I2C */
#define i2cMAX_HW_ID                                                               2U

/* I2C TimeStamp enable/disable configuration */
#define i2cTIMESTAMP_ENABLE                                                        1U
#define i2cTIMESTAMP_DISABLE                                                       0U

/* QUP Common Base Address */
//Do not need to update this
#ifndef I2C_QUP_COMMON_BASE_ADDRESS
#define I2C_QUP_COMMON_BASE_ADDRESS                                                (0xF1900000U)
#endif

#ifndef I2C_SE0BASE
#define I2C_SE0BASE                                                                (0xF1900000U)
#endif

#ifndef I2C_SE1BASE
#define I2C_SE1BASE                                                                (0xF1904000U)
#endif

#ifndef I2C_SE2BASE
#define I2C_SE2BASE                                                                (0xF1908000U)
#endif

#ifndef I2C_SE3BASE
#define I2C_SE3BASE                                                                (0xF190C000U)
#endif

#ifndef I2C_SE4BASE
#define I2C_SE4BASE                                                                (0xF1910000U)
#endif

/*=================================================================================================
**                                        Global variables and constants                         **
=================================================================================================*/

#ifdef I2C_TEST_ENABLE
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> I2C Configurations <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

static i2cEl1ChannelCfgType I2cSE0ChannelCfg[i2cSE0_MAX_CHANNELS]=
{
    {
        i2cSE0_HW_CHANNEL,
        i2cTI_PMIC_SLAVEADDRESS_PAGE0,
        0,
        I2C_EL1_ONE_BYTE_ADDRESSING,
        i2cTIMESTAMP_DISABLE,
        NULL
    },
    {
        i2cSE0_HW_CHANNEL,
        i2cTI_PMIC_SLAVEADDRESS_PAGE1,
        0,
        I2C_EL1_ONE_BYTE_ADDRESSING,
        i2cTIMESTAMP_DISABLE,
        NULL
    },
    {
        i2cSE0_HW_CHANNEL,
        i2cTI_PMIC_SLAVEADDRESS_PAGE4,
        0,
        I2C_EL1_ONE_BYTE_ADDRESSING,
        i2cTIMESTAMP_DISABLE,
        NULL
    },
    {
        i2cSE0_HW_CHANNEL,
        i2cPSAIL_KOBRA_B_SLAVEADDRESS,
        0,
        I2C_EL1_TWO_BYTE_ADDRESSING,
        i2cTIMESTAMP_DISABLE,
        NULL
    },
    {
        i2cSE0_HW_CHANNEL,
        i2cPSAIL_KOBRA_D_SLAVEADDRESS,
        0,
        I2C_EL1_TWO_BYTE_ADDRESSING,
        i2cTIMESTAMP_DISABLE,
        NULL
    },
    {
        i2cSE0_HW_CHANNEL,
        i2cPSAIL_KOBRA_F_SLAVEADDRESS,
        0,
        I2C_EL1_TWO_BYTE_ADDRESSING,
        i2cTIMESTAMP_DISABLE,
        NULL
    },
    {
        i2cSE0_HW_CHANNEL,
        i2cPSAIL_KOBRA_H_SLAVEADDRESS,
        0,
        I2C_EL1_TWO_BYTE_ADDRESSING,
        i2cTIMESTAMP_DISABLE,
        NULL
    },
    
};

static i2cEl1HwUnitCfgType I2cSE0HwUnitCfg[] =
{
    {
        i2cSE0_HW_CHANNEL, 
        I2C_SE0BASE,
        i2cSE0_HW_CHANNEL_INT_NUM,
        i2cSE0_MAX_CHANNELS,
        i2cSE0_MIN_CHANNEL_ID,
        i2cSE0_MAX_CHANNEL_ID,
        I2C_EL1_DMA_MODE,
        I2C_EL1_FASTPLUS_MODE,
        (const char *) "sailss_cc_qupv3_wrap0_s0_clk",
        1
    }
    
};

/*********************************** SE3 Configuration *******************************************/

static i2cEl1ChannelCfgType I2cSE3ChannelCfg[i2cSE3_MAX_CHANNELS]=
{
    {
        i2cSE3_HW_CHANNEL,
        i2cSE3_SLAVEADDRESS_0,
        0,
        I2C_EL1_ONE_BYTE_ADDRESSING,
        i2cTIMESTAMP_DISABLE,
        NULL
    }    
};

static i2cEl1HwUnitCfgType I2cSE3HwUnitCfg[] =
{
    {
        i2cSE3_HW_CHANNEL, 
        I2C_SE3BASE,
        i2cSE3_HW_CHANNEL_INT_NUM,
        i2cSE3_MAX_CHANNELS,
        i2cSE3_MIN_CHANNEL_ID,
        i2cSE3_MAX_CHANNEL_ID,
        I2C_EL1_DMA_MODE,
        I2C_EL1_FASTPLUS_MODE,
        (const char *) "sailss_cc_qupv3_wrap0_s3_clk",
        1
    }
    
};

/*********************************** Common Configuration ****************************************/

i2cEl1CoreConfigType I2CCoreConfig[i2cMAX_HW_ID] =
{
    {
        I2cSE0HwUnitCfg,
        I2cSE0ChannelCfg
    },
    {
        I2cSE3HwUnitCfg,
        I2cSE3ChannelCfg
    },
};

#endif

/*=================================================================================================
**                                        Local function prototypes                              **
=================================================================================================*/
#ifdef SAILSW3
static portBaseType I2cEL1AcmuMonitorDeInit(eMonitorType MONITOR_ID);
#endif
TEST_FUNC TESTerrorType_e TC_I2C_EL1_01(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_02(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_03(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_04(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_05(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_06(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_07(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_08(void);
#ifdef I2C_TEST_ENABLE
TEST_FUNC TESTerrorType_e TC_I2C_EL1_09(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_10(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_11(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_12(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_13(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_14(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_15(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_16(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_17(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_18(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_19(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_20(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_21(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_22(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_23(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_24(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_25(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_26(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_27(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_28(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_29(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_30(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_31(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_32(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_33(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_34(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_35(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_36(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_37(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_38(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_39(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_40(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_41(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_42(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_43(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_44(void);
TEST_FUNC TESTerrorType_e TC_I2C_EL1_45(void);
TEST_FUNC void I2cDeInitSleep(const sleepModeType_e SleepState);
TEST_FUNC i2cEl1Status_e I2c_InitStatusCheck(uint8 ucHardwareId);
TEST_FUNC i2cEl1Status_e I2C_InitErrorCheck(uint8 ucHardwareId);
TEST_FUNC i2cEl1Status_e I2c_ChannelIdcheck(uint8 ChannelId);
TEST_FUNC i2cEl1Status_e I2cGetSlaveAddress(uint8 ChannelId);
TEST_FUNC i2cEl1Status_e I2c_ClockEnable(i2cEl1HwUnitCfgType *I2cHwConfigPtr);
TEST_FUNC i2cEl1Status_e I2c_ClockDisable(i2cEl1HwUnitCfgType *I2cHwConfigPtr);
TEST_FUNC i2cEl1Status_e I2c_GetCmdOpcode(uint32 Flags, uint32 DataLength);
TEST_FUNC i2cEl1Status_e I2cWrite(uint8 ChannelId,uint32 Address,uint8 DataLength,uint8 *I2cDataPtr);
TEST_FUNC i2cEl1Status_e I2cRead(uint8 ChannelId,uint32 Address,uint8 DataLength,uint8 *I2cDataPtr);
TEST_FUNC void I2c_Transfer(uint8 ChannelId, uint32 DataLength, uint32 Flag, uint32 *RegMaskPtr);
TEST_FUNC i2cEl1Status_e I2c_ReadErrorcheck(const uint8 ChannelId, uint8 *I2cDataPtr);
TEST_FUNC i2cEl1Status_e I2c_WriteErrorcheck(const uint8 ChannelId, uint8 *I2cDataPtr);
TEST_FUNC i2cEl1Status_e I2c_SerialEngineDeInit(i2cEl1HwUnitCfgType *I2cSE0HwUnitCfg,uint32 BaseAdd );
TEST_FUNC i2cEl1Status_e I2c_SerialEngineInit(i2cEl1HwUnitCfgType *I2cSE0HwUnitCfg,uint32 BaseAdd );
TEST_FUNC void I2c_FiFoWrite(uint8 I2cHardwareID);
TEST_FUNC void I2c_FiFoRead(uint8 I2cHardwareID);
TEST_FUNC i2cEl1Status_e I2cEL1LoadConfigurations(uint8 I2cHardwareID);
TEST_FUNC i2cEl1Status_e I2c_GeniSEIsr(uint32 ucHardwareId);
#endif

/*=================================================================================================
**                                        functions definition                                   **
=================================================================================================*/
#ifdef SAILSW3
static portBaseType I2cEL1AcmuMonitorDeInit(eMonitorType MONITOR_ID)
{
	portBaseType ret =  pdFAIL;
	eMonitorStateType peMonState = MON_UNINITIALIZED;
	if( MON_RET_SUCCESS == xACMUMonitorGetStatus(MONITOR_ID, &peMonState))
	{
		if(MON_RUNNING == peMonState)
		{
			if(MON_RET_SUCCESS == xACMUMonitorStop(MONITOR_ID))
			{
				DEBUG_LOG(SAIL_ERROR, "CLOCK Monitoring Stopped \n\r");

				if(MON_RET_SUCCESS == xMonitorDeInit(MONITOR_ID))
				{
					DEBUG_LOG(SAIL_ERROR, "CLOCK Monitoring De-Initialized \n\r");
					ret = pdPASS;
				}
				else
				{
					DEBUG_LOG(SAIL_ERROR, "CLOCK Monitoring driver De-Initialization failed \n\r");
				}
			}
			else
			{
				DEBUG_LOG(SAIL_ERROR, "CLOCK Monitoring driver stop failure \n\r");
			}
		}
	}
	return ret;
}
#endif

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_01] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_01(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    uint8  ucHardwareId = 0;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    
    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_01] I2C El1 Initialization test\r\n");
    #ifdef I2C_TEST_ENABLE
        Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
    #else
        Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
    #endif
    if ( I2C_EL1_SUCCESS == Status ) 
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_01] I2C0 Init Success.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else if ( I2C_EL1_ERROR_ALREADY_INITIALIZED == Status )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_01] I2C0  driver already initialized.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_01] I2C0 Init FAIL.\r\n");
        xReturn = MODULE_TEST_FAILED;
    }
    #ifdef I2C_TEST_ENABLE
        Status = xI2c_EL1_Init(i2cSE3_HW_CHANNEL);
    #else
        Status = xI2c_EL1_Init(i2cSE3_HW_CHANNEL);
    #endif
    if ( I2C_EL1_SUCCESS == Status ) 
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_01] I2C1 Init Success.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else if ( I2C_EL1_ERROR_ALREADY_INITIALIZED == Status )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_01] I2C1 driver already initialized.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_01] I2C1 Init FAIL.\r\n");
        xReturn = MODULE_TEST_FAILED;
    }
    return xReturn;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_02] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_02(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    static uint8 ucSlaveAddress = 0x0;

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] I2C El1 Get Slave Address test\r\n");
    if ( I2C_EL1_SUCCESS == xI2c_EL1_GetSlaveAddress((uint8)0,&ucSlaveAddress))
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress Success for PAGE_ID_0 Slave address= 0x%x.\r\n",ucSlaveAddress);
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress FAIL for PAGE_ID_0 .\r\n");
        xReturn = MODULE_TEST_FAILED;
    }
    if ( I2C_EL1_SUCCESS == xI2c_EL1_GetSlaveAddress((uint8)1,&ucSlaveAddress))
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress Success for PAGE_ID_1 Slave address= 0x%x.\r\n",ucSlaveAddress);
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress FAIL for PAGE_ID_1.\r\n");
        xReturn = MODULE_TEST_FAILED;
    }
        if ( I2C_EL1_SUCCESS == xI2c_EL1_GetSlaveAddress((uint8)2,&ucSlaveAddress))
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress Success for PAGE_ID_4 Slave address= 0x%x.\r\n",ucSlaveAddress);
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress FAIL for PAGE_ID_4.\r\n");
        xReturn = MODULE_TEST_FAILED;
    }

    if ( I2C_EL1_SUCCESS == xI2c_EL1_GetSlaveAddress((uint8)7,&ucSlaveAddress))
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress Success for i2cSE3_CHANNEL_ID_0 Slave address= 0x%x.\r\n",ucSlaveAddress);
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress FAIL for i2cSE3_CHANNEL_ID_0 .\r\n");
        xReturn = MODULE_TEST_FAILED;
    }

    if ( I2C_EL1_SUCCESS == xI2c_EL1_GetSlaveAddress((uint8)10,&ucSlaveAddress))
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress Success for ChannelID 10 Slave address= 0x%x.\r\n",ucSlaveAddress);
        xReturn = MODULE_TEST_FAILED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_02] xI2c_EL1_GetSlaveAddress FAIL for ChannelID 10 .\r\n");
        xReturn = MODULE_TEST_PASSED;
    }

    return xReturn;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_03] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_03(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    static uint8 ucSlaveAddress = 0x0;
    uint8 xpageId = 0; 
    uint32 uladdr = 0xC9U;
    uint8 ucdata = 0x10;
    uint8 pxdata[2] = {0x0 , 0x0};
    uint8 pxCRCData[3] = { 0x0 , 0x0 , 0x0 };
    uint8 ucHardwareId = 0U;

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_03] I2C El1 WRITE test\r\n");

    if(I2C_EL1_SUCCESS == xI2c_EL1_PingStatusFromSlave(xpageId , ucHardwareId))
    {
		if (I2C_EL1_SUCCESS != xI2c_EL1_GetSlaveAddress((uint8)xpageId,&ucSlaveAddress))
		{
			return MODULE_TEST_FAILED;
		}
		pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
		pxCRCData[1] = (uint8) uladdr;  // Address
		pxCRCData[2] = ucdata; // Value Need to be written in PMIC
		if ( CRC_SUCCESS != xCrc8Generate( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 3 , &pxdata[1] ) )
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_03] xCrc8Generate FAIL.\r\n");
			return MODULE_TEST_FAILED;
		}
		pxdata[0] = ucdata;

		if ( I2C_EL1_SUCCESS != xI2c_EL1_Write((uint8)xpageId,uladdr,2u,pxdata) )
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_03] xI2c_EL1_Write FAIL for PAGE_ID_0.\r\n");
			return MODULE_TEST_FAILED;
		}
		else
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_03] I2C COMM WRITE BYTE VALUE: 0x%x\r\n", pxdata[0]);
			xReturn = MODULE_TEST_PASSED;
		}
    }
    else
    {
    	DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_03] I2C El1 WRITE test, Slave not Detected on I2C Bus \r\n");
    	return MODULE_TEST_FAILED;
    }
    return xReturn;
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_04] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_04(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    static uint8 ucSlaveAddress = 0x0;
    uint8 xpageId = 0; 
    uint32 uladdr = 0xC9U;
    uint8 ucdata = 0x10;
    uint8 pxdata[2] = {0x0 , 0x0};
    uint8 pxCRCData[4] = { 0x0 , 0x0 , 0x0 , 0x0 };
    uint8 ucHardwareId = 0U;

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_04] I2C El1 READ test\r\n");
    if(I2C_EL1_SUCCESS == xI2c_EL1_PingStatusFromSlave(xpageId , ucHardwareId))
    {
		if ( I2C_EL1_SUCCESS !=  xI2c_EL1_Read((uint8)xpageId,uladdr,2u,pxdata))
		{
			return MODULE_TEST_FAILED;
		}

		if ( I2C_EL1_SUCCESS !=  xI2c_EL1_GetSlaveAddress((uint8)xpageId,&ucSlaveAddress))
		{
			return MODULE_TEST_FAILED;
		}
		pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
		pxCRCData[1] = (uint8) uladdr;  // Address
		pxCRCData[2] = (ucSlaveAddress<<1u)|(0x1u); // ( SLAVE ID Left shift by one and 0bit is set for write)
		pxCRCData[3] = pxdata[0]; // Value being read from PMIC
		if ( CRC_SUCCESS != xCrc8Verify( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 4 , pxdata[1] ) )
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_04] xCrc8Verify FAIL.\r\n");
			return MODULE_TEST_FAILED;
		}

		if ( ucdata == pxdata[0])
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_04] I2C COMM READ BYTE VALUE: 0x%x\r\n", pxdata[0]);
			xReturn = MODULE_TEST_PASSED;
		}
    }
    else
    {
    	DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_04] I2C El1 READ test, Slave not Detected on I2C Bus \r\n");
    	return MODULE_TEST_FAILED;
    }
    return xReturn;
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_05] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_05(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    static uint8 ucSlaveAddress = 0x0;
    uint8 xpageId = 0; 
    uint32 uladdr = 0xC9U;
    uint8 ucdata = 0x20;
    uint8 pxdata[2] = {0x0 , 0x0};
    uint8 pxCRCData[4] = { 0x0 , 0x0 , 0x0 , 0x0 };
    uint8 ucHardwareId = 0U;

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_05] I2C El1 READ-WRITE-READ test\r\n");
    if(I2C_EL1_SUCCESS == xI2c_EL1_PingStatusFromSlave(xpageId , ucHardwareId))
    {
		if ( I2C_EL1_SUCCESS !=  xI2c_EL1_Read((uint8)xpageId,uladdr,2u,pxdata))
		{
			return MODULE_TEST_FAILED;
		}

		if ( I2C_EL1_SUCCESS !=  xI2c_EL1_GetSlaveAddress((uint8)xpageId,&ucSlaveAddress))
		{
			return MODULE_TEST_FAILED;
		}
		pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
		pxCRCData[1] = (uint8) uladdr;  // Address
		pxCRCData[2] = (ucSlaveAddress<<1u)|(0x1u); // ( SLAVE ID Left shift by one and 0bit is set for write)
		pxCRCData[3] = pxdata[0]; // Value being read from PMIC
		if ( CRC_SUCCESS != xCrc8Verify( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 4 , pxdata[1] ) )
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_05] xCrc8Verify FAIL.\r\n");
			return MODULE_TEST_FAILED;
		}

		DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_05] I2C COMM READ BYTE VALUE: 0x%x\r\n", pxdata[0]);

		pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
		pxCRCData[1] = (uint8) uladdr;  // Address
		pxCRCData[2] = ucdata; // Value Need to be written in PMIC
		if ( CRC_SUCCESS != xCrc8Generate( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 3 , &pxdata[1] ) )
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_05] xCrc8Generate FAIL.\r\n");
			return MODULE_TEST_FAILED;
		}
		pxdata[0] = ucdata;

		if ( I2C_EL1_SUCCESS != xI2c_EL1_Write((uint8)xpageId,uladdr,2u,pxdata) )
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_05] xI2c_EL1_Write FAIL for PAGE_ID_0.\r\n");
			return MODULE_TEST_FAILED;
		}
		else
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_05] I2C COMM WRITE BYTE VALUE: 0x%x\r\n", pxdata[0]);
			xReturn = MODULE_TEST_PASSED;
		}

		if ( I2C_EL1_SUCCESS !=  xI2c_EL1_Read((uint8)xpageId,uladdr,2u,pxdata))
		{
			return MODULE_TEST_FAILED;
		}

		if ( I2C_EL1_SUCCESS !=  xI2c_EL1_GetSlaveAddress((uint8)xpageId,&ucSlaveAddress))
		{
			return MODULE_TEST_FAILED;
		}
		pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
		pxCRCData[1] = (uint8) uladdr;  // Address
		pxCRCData[2] = (ucSlaveAddress<<1u)|(0x1u); // ( SLAVE ID Left shift by one and 0bit is set for write)
		pxCRCData[3] = pxdata[0]; // Value being read from PMIC
		if ( CRC_SUCCESS != xCrc8Verify( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 4 , pxdata[1] ) )
		{
			return MODULE_TEST_FAILED;
		}

		if ( ucdata == pxdata[0])
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_05] I2C COMM READ BYTE VALUE: 0x%x\r\n", pxdata[0]);
			xReturn = MODULE_TEST_PASSED;
		}
    }
    else
    {
    	DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_05] I2C El1 READ-WRITE-READ test, Slave not Detected on I2C Bus \r\n");
    	return MODULE_TEST_FAILED;
    }
    return xReturn;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_06] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_06(void)
{
    uint8  ucHardwareId = 0;
	uint8 ucI2cPingCount = 0x0u;
	uint8 ucPsailChannel = 0U;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	TESTerrorType_e xReturn = MODULE_TEST_PASSED;

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_06] I2C El1 xI2c_EL1_PingStatusFromSlave Positive test for PSAIL Slaves \r\n");
    for ( ucPsailChannel =  PSAIL_B_ID ; ucPsailChannel < MAX_PSAIL_ID  ; ucPsailChannel++)
    {
        if ( I2C_EL1_SUCCESS == xI2c_EL1_PingStatusFromSlave(ucPsailChannel,ucHardwareId))
        {
			ucI2cPingCount++;
		}
		else
		{
			DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_06] PSAIL %d not present.\r\n",ucPsailChannel-PSAIL_B_ID);
		}
	}
	if ( ucI2cPingCount == 0x0u )
    {
        xReturn |= MODULE_TEST_FAILED;
    }
	
	/* xI2c_EL1_PingStatusFromSlave Negative test for Invalid HW ID */
	DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_06] I2C El1 Negative test for Invalid HW ID \r\n");
	ucHardwareId = 1;
	if ( I2C_EL1_ERROR_INVALID_HW_ID == xI2c_EL1_PingStatusFromSlave(PSAIL_B_ID,ucHardwareId))
	{
		xReturn |= MODULE_TEST_PASSED;
	}
	else
	{
		xReturn |= MODULE_TEST_FAILED;
	}
	
    return xReturn;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_07] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_07(void)
{
    uint8 ucPsailChannel = 0U;
    uint8 ucHardwareId = 0x0u;
    uint8 ucRevID[2] = {0x0u};
    TESTerrorType_e xReturn = MODULE_TEST_PASSED;
    i2cEl1Status_e xI2CStatus = I2C_EL1_SUCCESS;
    uint8 ucI2cPingCount = 0x0u;
	uint8 pcData = 0x48;
	uint8 ucReadback = 0x0u;
    for ( ucPsailChannel =  PSAIL_B_ID ; ucPsailChannel < MAX_PSAIL_ID  ; ucPsailChannel++)
    {
        if ( I2C_EL1_SUCCESS == xI2c_EL1_PingStatusFromSlave(ucPsailChannel,ucHardwareId))
        {
			if ( I2C_EL1_SUCCESS == xI2c_EL1_Write((uint8) ucPsailChannel , 0x7777, 1, &pcData) )
			{
				DEBUG_LOG(SAIL_INFO,"PSAIL WRITE: 0x%x\r\n", pcData);
				xI2CStatus = xI2c_EL1_Read((uint8) ucPsailChannel, 0x7777, 1, &ucReadback);
				if ( ucReadback == pcData && I2C_EL1_SUCCESS == xI2CStatus )
				{
					DEBUG_LOG(SAIL_INFO,"PSAIL READ: 0x%x\r\n", ucReadback);
					xReturn |= MODULE_TEST_PASSED;
				}
				else
				{
					DEBUG_LOG(SAIL_INFO,"PSAIL READ FAILS.\r\n");
					xReturn |= MODULE_TEST_FAILED;
				}
			}

			ucI2cPingCount++;
		}
		else
		{
			DEBUG_LOG(SAIL_INFO,"PSAIL %d not present.\r\n",ucPsailChannel-PSAIL_B_ID);
		}
	}

    if ( ucI2cPingCount == 0x0u )
    {
        xReturn |= MODULE_TEST_FAILED;
    }

    return xReturn;
}


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_08] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_08(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    uint8  ucHardwareId = 0;
	i2cEl1Status_e Status = I2C_EL1_SUCCESS;

#ifdef SAILSW3
    I2cEL1AcmuMonitorDeInit(CLOCK_MON);
#endif
    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C El1 DeInit test with Invalid HWID\r\n");

    ucHardwareId = 0xFF;
    if ( I2C_EL1_HW_NOT_EXIST == xI2c_EL1_DeInit( ucHardwareId) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C0 DeInit with Invalid HWID Success.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C0 DeInit with Invalid HWID Failed.\r\n");
        return MODULE_TEST_FAILED;
    }

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C El1 DeInit-ReInit-DeInit test\r\n");
    ucHardwareId = 0;
    if ( I2C_EL1_SUCCESS == xI2c_EL1_DeInit( ucHardwareId) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C0 DeInit Success.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C0 DeInit FAIL.\r\n");
        return MODULE_TEST_FAILED;
    }

    #ifdef I2C_TEST_ENABLE
        Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
    #else
        Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
    #endif
    if ( I2C_EL1_SUCCESS == Status ) 
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C0 Init Success.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else if ( I2C_EL1_ERROR_ALREADY_INITIALIZED == Status )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C0 driver already initialized.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C0 Init FAIL.\r\n");
        return MODULE_TEST_FAILED;
    }
    ucHardwareId = 1;
    if ( I2C_EL1_SUCCESS == xI2c_EL1_DeInit( ucHardwareId) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C1 DeInit Success.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C1 DeInit FAIL.\r\n");
        return MODULE_TEST_FAILED;
    }

    #ifdef I2C_TEST_ENABLE
        Status = xI2c_EL1_Init(i2cSE3_HW_CHANNEL);
    #else
        Status = xI2c_EL1_Init(i2cSE3_HW_CHANNEL);
    #endif
    if ( I2C_EL1_SUCCESS == Status ) 
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C1 Init Success.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else if ( I2C_EL1_ERROR_ALREADY_INITIALIZED == Status )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C1 driver already initialized.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C1 Init FAIL.\r\n");
        return MODULE_TEST_FAILED;
    }
    ucHardwareId = 0;
    if ( I2C_EL1_SUCCESS == xI2c_EL1_DeInit( ucHardwareId) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C DeInit Success.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C DeInit FAIL.\r\n");
        xReturn = MODULE_TEST_FAILED;
    }
    ucHardwareId = 1;
    if ( I2C_EL1_SUCCESS == xI2c_EL1_DeInit( ucHardwareId) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C DeInit Success.\r\n");
        xReturn = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_08] I2C DeInit FAIL.\r\n");
        xReturn = MODULE_TEST_FAILED;
    }
    return xReturn;
}

#ifdef I2C_TEST_ENABLE
/*                      I2C Initialization in POLLING mode  Test case                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_09] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_09(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    uint8  ucHardwareId = 0;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	
    I2cSE0HwUnitCfg->Access_Mode = I2C_EL1_POLLING_MODE;
	I2cSE3HwUnitCfg->Access_Mode = I2C_EL1_POLLING_MODE;
	
    // Initilaization I2C0 with Polling mode
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
    
	// Initilaization I2C1 with Polling mode
    Status = xI2c_EL1_Init(i2cSE3_HW_CHANNEL);
    
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                           I2C Write test with polling mode                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_10] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_10(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    static uint8 ucSlaveAddress = 0x0;
    uint8 xpageId = 0; 
    uint32 uladdr = 0xC9U;
    uint8 ucdata = 0xAA;
    uint8 pxdata[2] = {0x0 , 0x0};
    uint8 pxCRCData[3] = { 0x0 , 0x0 , 0x0 };

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_10] I2C El1 WRITE test\r\n");
    if (I2C_EL1_SUCCESS != xI2c_EL1_GetSlaveAddress((uint8)xpageId,&ucSlaveAddress))
    {
        return MODULE_TEST_FAILED;
    }
    pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
    pxCRCData[1] = (uint8) uladdr;  // Address
    pxCRCData[2] = ucdata; // Value Need to be written in PMIC
    if ( CRC_SUCCESS != xCrc8Generate( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 3 , &pxdata[1] ) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_10] xCrc8Generate FAIL.\r\n");
        return MODULE_TEST_FAILED;
    }
    pxdata[0] = ucdata;

    if ( I2C_EL1_SUCCESS != xI2c_EL1_Write((uint8)xpageId,uladdr,2u,pxdata) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_10] xI2c_EL1_Write FAIL for PAGE_ID_0.\r\n");
        return MODULE_TEST_FAILED;
    }
    else
    {
        xTaskDelay(10);
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_10] I2C COMM WRITE BYTE VALUE: 0x%x\r\n", pxdata[0]);
        xReturn = MODULE_TEST_PASSED;
    }

    return xReturn;
}

/*                           I2C Read test with polling mode                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_11] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_11(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    static uint8 ucSlaveAddress = 0x0;
    uint8 xpageId = 0; 
    uint32 uladdr = 0xC9U;
    uint8 ucdata = 0xAA;
    uint8 pxdata[2] = {0x0 , 0x0};
    uint8 pxCRCData[4] = { 0x0 , 0x0 , 0x0 , 0x0 };

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_11] I2C El1 READ test\r\n");
    if ( I2C_EL1_SUCCESS !=  xI2c_EL1_Read((uint8)xpageId,uladdr,2u,pxdata))
    {
        return MODULE_TEST_FAILED;
    }

    if ( I2C_EL1_SUCCESS !=  xI2c_EL1_GetSlaveAddress((uint8)xpageId,&ucSlaveAddress))
    {
        return MODULE_TEST_FAILED;
    }
    xTaskDelay(10);
    pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
    pxCRCData[1] = (uint8) uladdr;  // Address
    pxCRCData[2] = (ucSlaveAddress<<1u)|(0x1u); // ( SLAVE ID Left shift by one and 0bit is set for write)
    pxCRCData[3] = pxdata[0]; // Value being read from PMIC
    if ( CRC_SUCCESS != xCrc8Verify( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 4 , pxdata[1] ) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_11] xCrc8Verify FAIL.\r\n");
        return MODULE_TEST_FAILED;
    }

    if ( ucdata == pxdata[0])
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_11] I2C COMM READ BYTE VALUE: 0x%x\r\n", pxdata[0]);
        xReturn = MODULE_TEST_PASSED;
    }
    return xReturn;
}


/*                      I2C Initialization in FIFO mode  Test case                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_12] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_12(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    uint8  ucHardwareId = 0;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	
    I2cSE0HwUnitCfg->Access_Mode = I2C_EL1_FIFO_MODE;
	I2cSE3HwUnitCfg->Access_Mode = I2C_EL1_FIFO_MODE;
	
	xI2c_EL1_DeInit(0U);
	xI2c_EL1_DeInit(1U);
	
	// Initilaization I2C0 with FIFO mode
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
    
	// Initilaization I2C1 with FIFO mode
    Status = xI2c_EL1_Init(i2cSE3_HW_CHANNEL);
    
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                           I2C Write test with FIFO mode                                */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_13] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_13(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    static uint8 ucSlaveAddress = 0x0;
    uint8 xpageId = 0; 
    uint32 uladdr = 0xC9U;
    uint8 ucdata = 0xBB;
    uint8 pxdata[2] = {0x0 , 0x0};
    uint8 pxCRCData[3] = { 0x0 , 0x0 , 0x0 };

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_13] I2C El1 FIFO WRITE test\r\n");
    if (I2C_EL1_SUCCESS != xI2c_EL1_GetSlaveAddress((uint8)xpageId,&ucSlaveAddress))
    {
        return MODULE_TEST_FAILED;
    }
    pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
    pxCRCData[1] = (uint8) uladdr;  // Address
    pxCRCData[2] = ucdata; // Value Need to be written in PMIC
    if ( CRC_SUCCESS != xCrc8Generate( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 3 , &pxdata[1] ) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_13] xCrc8Generate FAIL.\r\n");
        return MODULE_TEST_FAILED;
    }
    pxdata[0] = ucdata;

    if ( I2C_EL1_SUCCESS != xI2c_EL1_Write((uint8)xpageId,uladdr,2u,pxdata) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_13] xI2c_EL1_Write FAIL for PAGE_ID_0.\r\n");
        return MODULE_TEST_FAILED;
    }
    else
    {
        xTaskDelay(10);
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_13] I2C COMM WRITE BYTE VALUE: 0x%x\r\n", pxdata[0]);
        xReturn = MODULE_TEST_PASSED;
    }

    return xReturn;
}

/*                           I2C Read test with FIFO mode                                 */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_14] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_14(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    static uint8 ucSlaveAddress = 0x0;
    uint8 xpageId = 0; 
    uint32 uladdr = 0xC9U;
    uint8 ucdata = 0xBB;
    uint8 pxdata[2] = {0x0 , 0x0};
    uint8 pxCRCData[4] = { 0x0 , 0x0 , 0x0 , 0x0 };

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_14] I2C El1 FIFO READ test\r\n");
    if ( I2C_EL1_SUCCESS !=  xI2c_EL1_Read((uint8)xpageId,uladdr,2u,pxdata))
    {
        return MODULE_TEST_FAILED;
    }

    if ( I2C_EL1_SUCCESS !=  xI2c_EL1_GetSlaveAddress((uint8)xpageId,&ucSlaveAddress))
    {
        return MODULE_TEST_FAILED;
    }
    xTaskDelay(10);
    pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
    pxCRCData[1] = (uint8) uladdr;  // Address
    pxCRCData[2] = (ucSlaveAddress<<1u)|(0x1u); // ( SLAVE ID Left shift by one and 0bit is set for write)
    pxCRCData[3] = pxdata[0]; // Value being read from PMIC
    if ( CRC_SUCCESS != xCrc8Verify( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 4 , pxdata[1] ) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_14] xCrc8Verify FAIL.\r\n");
        return MODULE_TEST_FAILED;
    }

    if ( ucdata == pxdata[0])
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_14] I2C COMM READ BYTE VALUE: 0x%x\r\n", pxdata[0]);
        xReturn = MODULE_TEST_PASSED;
    }
    return xReturn;
}

/*                             I2C I2cChannelIdcheck Negative Test case                            */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_15] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_15(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_15] I2C I2cChannelIdcheck test.\r\n");

    Status = xI2c_EL1_PingStatusFromSlave(0 , 1);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                             I2C DeInit Test case                            */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_16] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_16(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_16] I2C DeInit test.\r\n");

    Status = xI2c_EL1_DeInit(0);
	
	Status = xI2c_EL1_DeInit(1);
	
    xReturn = MODULE_TEST_PASSED;

    return xReturn;
}

/*                     I2C Write-Read with Invalid Channel Test case                      */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_17] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_17(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_17] I2C Write-Read with Invalid Channel Test.\r\n");

    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	Status = xI2c_EL1_Init(i2cSE3_HW_CHANNEL);
	
	// I2C Write Invalid Channel Test
	Status = xI2c_EL1_Write(10,0xFF,2u,NULL);

	// I2C Write Invalid Channel Test
	Status =xI2c_EL1_Read(10,0xFF,2u,NULL);

    xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                     I2C Write-Read with NULL pointer Test case                         */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_18] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_18(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_18] I2C Write-Read with NULL pointer Test.\r\n");
	
	// I2C Write NULL test
	Status = xI2c_EL1_Write(0,0xC9,2u,NULL);

	// I2C Read NULL test
	Status =xI2c_EL1_Read(0,0xC9,2u,NULL);

    xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                     I2C SE0 Sleep DeInit with SleepState=0 Test case                   */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_19] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_19(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    // I2C SE0 Sleep DeInit with SleepState=0 
	I2cDeInitSleep(0U);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                     I2C SE0 Sleep DeInit with SleepState=1 Test case                   */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_20] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_20(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

	// I2C SE0 Sleep DeInit with SleepState=1 
	I2cDeInitSleep(1U);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                     I2C Sleep DeInit with SleepState=0 Test case                   */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_21] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_21(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	
	// I2C SE3 Sleep DeInit with SleepState=0 
	I2cDeInitSleep(0U);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                     I2C Sleep DeInit with SleepState=1 Test case                   */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_22] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_22(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

	// I2C SE3 Sleep DeInit with SleepState=1 
	I2cDeInitSleep(1U);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                     I2C SE0 Load Configuration Invalid HWID Test case                  */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_23] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_23(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

	I2cSE0ChannelCfg[0].AssignedHwId = 10U;
	
	// I2C SE0 Load Configuration Invalid HWID
	Status = I2cEL1LoadConfigurations(i2cSE0_HW_CHANNEL);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                     I2C SE0 Load Configuration Initialization Test case                  */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_24] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_24(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint8 ucHardwareId = 0U;

	Status = xI2c_EL1_DeInit( ucHardwareId);
	I2cSE0ChannelCfg[0].AssignedHwId = 0U;
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C Initialization negative test
	Status = I2cEL1LoadConfigurations(i2cSE0_HW_CHANNEL);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                    I2C SE0 Load Configuration Enable Status Test case                  */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_25] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_25(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    uint8 ucHardwareId = 0U;

    Status = xI2c_EL1_DeInit( ucHardwareId);
    I2cSE0HwUnitCfg->status = 0U;

    Status = I2cEL1LoadConfigurations(i2cSE0_HW_CHANNEL);

    I2cSE0HwUnitCfg->status = 1U;
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                      I2C SE0 Initialization status check Test case                     */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_26] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_26(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint8 ucHardwareId = 0U;
	
    Status = xI2c_EL1_DeInit( ucHardwareId);
	
	// I2C SE0 Initialization status check Test
	Status = I2c_InitStatusCheck( ucHardwareId);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                  I2C SE0 Initialization Error status check Test case                   */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_27] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_27(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint8 ucHardwareId = 0U;
	
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C SE0 Initialization Error status check Test
	Status = I2C_InitErrorCheck( ucHardwareId);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                         I2C SE0 Channel ID check Test case                             */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_28] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_28(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	
	Status = xI2c_EL1_DeInit(0U);
	I2cSE0HwUnitCfg->MinChannelId = 3U;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C Min channel Id negative test
	Status = I2c_ChannelIdcheck(2U);
	
	
	Status = xI2c_EL1_DeInit(0U);
	I2cSE0HwUnitCfg->MaxChannelId = 5U;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C Max channel Id negative test
	Status = I2c_ChannelIdcheck(6U);
	
	
	
	Status = xI2c_EL1_DeInit(0U);
	
	I2cSE0HwUnitCfg->MinChannelId = 3U;
	I2cSE0HwUnitCfg->MaxChannelId = 5U;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C channel Id Positive test
	Status = I2c_ChannelIdcheck(4U);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                  I2C SE0 Get Slave Address Channel ID check Test case                  */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_29] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_29(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	
	Status = xI2c_EL1_DeInit(0U);
	I2cSE0HwUnitCfg->MinChannelId = 3U;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C Get slave address Channel Id Negative test
	Status = I2cGetSlaveAddress(2U);
	
    xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                         I2C SE0 Get Command OpCode Test case                           */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_30] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_30(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint32 DataLength = 0U;
	uint32 Flags = 0U;
	
	Status = xI2c_EL1_DeInit(0U);
	I2cSE0HwUnitCfg->MinChannelId = 0U;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2c_GetCmdOpcode with Flag & DataLength = 0
	Status = I2c_GetCmdOpcode(Flags,DataLength);
	

    DataLength = 0U;
	Flags = 2U;
	
	// I2c_GetCmdOpcode with Flag=2 & DataLength = 0
    Status = I2c_GetCmdOpcode(Flags,DataLength);
	
	
    DataLength = 0U;
	Flags = 100U;
	
	// I2c_GetCmdOpcode with Flag=100 & DataLength = 0
    Status = I2c_GetCmdOpcode(Flags,DataLength);

	
	DataLength = 1U;
	Flags = 0U;
	
	// I2c_GetCmdOpcode with Flag=0 & DataLength = 1
    Status = I2c_GetCmdOpcode(Flags,DataLength);
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                         I2C SE0 I2C Write Negative Test case                            */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_31] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_31(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint32 DataLength = 0U;
	uint8 ChannelId = 0U;
	uint8 Data = 0U;
	uint32 Address = 0xC9U;
	
	// I2C Write Command Invalid test
	Status = I2cWrite(ChannelId, Address, DataLength,&Data);
	
	
	DataLength = 0U;
	ChannelId = 0U;
	Data = 0U;
	Address = 0xC9;
	
	// I2C Write Command Invalid test
	Status = I2cRead(ChannelId, Address, DataLength,&Data);
	
	xReturn = MODULE_TEST_PASSED;	
	return xReturn;
}

/*                         I2C SE0 I2C ISR Negative Test case                            */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_32] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_32(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint32 ucHardwareId = 0U;

	
	Status = xI2c_EL1_DeInit(ucHardwareId);
	
	// I2C Init status check test in ISR
	Status = I2c_GeniSEIsr(ucHardwareId);
	
	
	
	I2cSE0HwUnitCfg->Access_Mode = I2C_EL1_POLLING_MODE;
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C ISR call with Polling mode
	Status = I2c_GeniSEIsr(ucHardwareId);
	
	
	Status = xI2c_EL1_DeInit(0U);
	I2cSE0HwUnitCfg->Access_Mode = I2C_EL1_DMA_MODE;
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	Status = I2c_GeniSEIsr(ucHardwareId);
	
	xReturn = MODULE_TEST_PASSED;
	return xReturn;
}

/*                     I2C Read test to cover the Negative test in ISR                    */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_33] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_EL1_33(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    static uint8 ucSlaveAddress = 0x0;
    uint8 xpageId = 0; 
    uint32 uladdr = 0xC9U;
    uint8 ucdata = 0x10;
    uint8 pxdata[2] = {0x0 , 0x0};
    uint8 pxCRCData[4] = { 0x0 , 0x0 , 0x0 , 0x0 };


    if ( I2C_EL1_SUCCESS !=  xI2c_EL1_Read((uint8)xpageId,uladdr,2u,pxdata))
    {
        return MODULE_TEST_FAILED;
    }

    if ( I2C_EL1_SUCCESS !=  xI2c_EL1_GetSlaveAddress((uint8)xpageId,&ucSlaveAddress))
    {
        return MODULE_TEST_FAILED;
    }
    xTaskDelay(10);
    pxCRCData[0] = ucSlaveAddress<<1u; // ( SLAVE ID Left shift by one for Read and and 0bit is unset for read)
    pxCRCData[1] = (uint8) uladdr;  // Address
    pxCRCData[2] = (ucSlaveAddress<<1u)|(0x1u); // ( SLAVE ID Left shift by one and 0bit is set for write)
    pxCRCData[3] = pxdata[0]; // Value being read from PMIC
    if ( CRC_SUCCESS != xCrc8Verify( crcTIPMIC_CHANNEL_CRC8 , pxCRCData , 4 , pxdata[1] ) )
    {
        DEBUG_LOG(SAIL_INFO,"[TC_I2C_EL1_33] xCrc8Verify FAIL.\r\n");
        return MODULE_TEST_FAILED;
    }
	
	xReturn = MODULE_TEST_PASSED;
    return xReturn;
}

/*                     I2C Initialization test with NULL Configurations                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_34] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_34(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	i2cEl1CoreConfigType *I2cSE0Config = NULL;
	i2cEl1CoreConfigType *I2cSE3Config = NULL;
	uint32 ucHardwareId = 0U;

	
	Status = xI2c_EL1_DeInit(ucHardwareId);
    
    // I2C Initialization with NULL configuration
    Status = xI2c_EL1_Init(NULL);
	
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C ReInit Negative test
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	
	Status = xI2c_EL1_DeInit(ucHardwareId);
	I2cSE0HwUnitCfg->status = 0;
	
	// I2C Load Configuration Negative test
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
    xReturn = MODULE_TEST_PASSED;
	return xReturn;
}

/*                    I2C GetSlaveStatus test with Invalid channel case                   */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_35] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_35(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint32 ucHardwareId = 0U;
	uint8 ucSlaveAddress = 0x0;
	
	I2cSE0HwUnitCfg->status = 1;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C Get Slave address with Invalid channel case
	Status = xI2c_EL1_GetSlaveAddress((uint8)100,&ucSlaveAddress);
	
	xReturn = MODULE_TEST_PASSED;
	return xReturn;
}	

/*                I2C Transfer test with Invalid flag and datalength case                 */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_36] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_36(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint32 DataLength = 0U;
	uint32 Flag = 0U;
	uint8 ChannelId = 0U;
	uint32 RegMask = 0U;
	
	Status = xI2c_EL1_DeInit(0U);
    I2cSE0ChannelCfg[0].Delay_PreCmdus = 1U;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	I2c_Transfer(ChannelId, DataLength,Flag, &RegMask);
	
	Status = xI2c_EL1_DeInit(0U);
    I2cSE0ChannelCfg[0].Delay_PreCmdus = 0U;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	Flag = 0x10U;
	I2c_Transfer(ChannelId, DataLength,Flag, &RegMask);
	
	DataLength = 1U;
	Flag = 32U;
	I2c_Transfer(ChannelId, DataLength,Flag, &RegMask);
	
	DataLength = 0U;
	Flag = 0x11U;
	I2c_Transfer(ChannelId, DataLength,Flag, &RegMask);
	
	DataLength = 0U;
	Flag = 0x12U;
	I2c_Transfer(ChannelId, DataLength,Flag, &RegMask);
	
	
	xReturn = MODULE_TEST_PASSED;
	return xReturn;
}

/*                            I2C Read Error Check Negative case                          */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_37] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_37(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint8 Data = 0U;
	uint8 ChannelId = 0U;
	
	Status = xI2c_EL1_DeInit(0U);
	
	// I2C Not Initialized test
	Status = I2c_ReadErrorcheck(ChannelId,&Data);
		
	
	Status = xI2c_EL1_DeInit(0U);
	I2cSE0HwUnitCfg->MaxChannelId = 5U;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	ChannelId = 10U;
	
	// I2c Invalid channel Id (MAX Negative test)
	Status = I2c_ReadErrorcheck(ChannelId,&Data);
	
	ChannelId = 4U;
	
	// I2c Cahnnel Id positive test
	Status = I2c_ReadErrorcheck(ChannelId,&Data);
	
	xReturn = MODULE_TEST_PASSED;
	return xReturn;
}

/*                            I2C Write Error Check Negative case                          */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_38] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_38(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint8 Data = 0U;
	uint8 ChannelId = 0U;
	
	Status = xI2c_EL1_DeInit(0U);
	
	// I2C Not Initialized test
	Status = I2c_WriteErrorcheck(ChannelId,&Data);

	
	Status = xI2c_EL1_DeInit(0U);
	I2cSE0HwUnitCfg->MaxChannelId = 5U;
    Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	ChannelId = 10U;
	
	// I2c Invalid channel Id (MAX Negative test)
	Status = I2c_WriteErrorcheck(ChannelId,&Data);
	
	ChannelId = 4U;
	
	// I2c Cahnnel Id positive test
	Status = I2c_WriteErrorcheck(ChannelId,&Data);
	
	xReturn = MODULE_TEST_PASSED;
	return xReturn;
}

/*                          I2C Clock Enable-Disable Negative case                        */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_39] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_39(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	
	Status = xI2c_EL1_DeInit(0U);
	
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// Clock_GetClockId Negative test 
	Status = I2c_ClockEnable(&I2cSE0HwUnitCfg[0]);
	
	// Clock_SetClockFrequency Negative test
	Status = I2c_ClockEnable(&I2cSE0HwUnitCfg[0]);
	
	// xSleepRegisterCallBack Negative test
	Status = I2c_ClockEnable(&I2cSE0HwUnitCfg[0]);
	
	// Clock_GetClockId Negative test
	Status = I2c_ClockDisable(&I2cSE0HwUnitCfg[0]);
	
	// Clock_DisableClock Negative test
	Status = I2c_ClockDisable(&I2cSE0HwUnitCfg[0]);
	
	xReturn = MODULE_TEST_PASSED;
	
	return xReturn;
	
}

/*                                  I2C Read-Write Negative case                                */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_40] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_40(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
	uint8 xpageId = 0; 
    uint32 uladdr = 0xC9U;
    uint8 pxdata[2] = {0x0 , 0x0};

	Status = xI2c_EL1_DeInit(0U);
	I2cSE0HwUnitCfg->Access_Mode = I2C_EL1_POLLING_MODE;
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	//Command Invalid test case
	Status = xI2c_EL1_Read((uint8)xpageId,uladdr,2u,pxdata);
	
	//I2cReadGeniError Negative test
	Status = xI2c_EL1_Read((uint8)xpageId,uladdr,2u,pxdata);
	
	//Command Invalid test case
	Status = xI2c_EL1_Write((uint8)xpageId,uladdr,2u,pxdata);
	
	xReturn = MODULE_TEST_PASSED;
	
	return xReturn;
	
}

/*                        I2C PingStatusFromSlave Negative Test case                      */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_41] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_41(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

    // MAX channel negative test
    Status = xI2c_EL1_PingStatusFromSlave(100U , 0U);
	
	// Channel negative test
	Status = xI2c_EL1_PingStatusFromSlave(6U , 0U);
	
	// Inavlid Command negative test
	Status = xI2c_EL1_PingStatusFromSlave(4U , 0U);
	
	xReturn = MODULE_TEST_PASSED;
	
	return xReturn;
	
}

/*                   I2C Serial Engine Init-DeInit Negative Test case                     */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_42] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_42(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;
    uint32 BaseAdd = 0x0;
	
    Status = xI2c_EL1_DeInit(0U);
	I2cSE0HwUnitCfg->Access_Mode = I2C_EL1_DMA_MODE;
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// Negative test for Status
	Status = I2c_SerialEngineInit(&I2cSE0HwUnitCfg[0],BaseAdd);
	
	// xPortEnableInterrupt negative test
	Status = I2c_SerialEngineInit(&I2cSE0HwUnitCfg[0],BaseAdd);
	
	// xPortUninstallInterruptHandler negative test
	Status = I2c_SerialEngineInit(&I2cSE0HwUnitCfg[0],BaseAdd);
	
	// xPortEnableInterrupt negative test
	Status = I2c_SerialEngineDeInit(&I2cSE0HwUnitCfg[0],BaseAdd);
	
	// xPortUninstallInterruptHandler negative test
	Status = I2c_SerialEngineDeInit(&I2cSE0HwUnitCfg[0],BaseAdd);
	
	xReturn = MODULE_TEST_PASSED;
	
	return xReturn;
	
}

/*                  I2C Serial Engine Sleep DeInit Negative Test case                     */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_43] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_43(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

	
	// Core 0 negative test
	I2cDeInitSleep(0);
	
	// xSleepDriverAck negative test
	I2cDeInitSleep(0);
	
	xReturn = MODULE_TEST_PASSED;
	
	return xReturn;
	
}

/*                          I2C FiFo Read-Write Negative Test case                        */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_44] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_44(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

	// data write negative test
	I2c_FiFoWrite(0U);
	
	// Transferred Length Negative test
	I2c_FiFoWrite(0U);
	
	// Active command Negative test
	I2c_FiFoWrite(0U);
	
	// Active command Negative test
	I2c_FiFoRead(0U);
	
	xReturn = MODULE_TEST_PASSED;
	
	return xReturn;
	
}


/*                  I2C DeInit-Init Negative Test case                     */      
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_EL1_45] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_I2C_EL1_45(void)
{
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    i2cEl1Status_e Status = I2C_EL1_SUCCESS;

	
	// I2C Clock Disable Negative test	
	Status = xI2c_EL1_DeInit(0U);
	
	// I2C Clock Enable Negative test
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	// I2C Serial Engine Negative test
	Status = xI2c_EL1_Init(i2cSE0_HW_CHANNEL);
	
	xReturn = MODULE_TEST_PASSED;
	
	return xReturn;
	
}

#endif

TEST_FUNC TESTerrorType_e xTestI2cEl1Wrapper(void)
{

    //Wdt_Command_Type xWdt_Test_Command = {WDT_INVALID, 50};
    TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    uint8 I2cTestCaseCnt = 0;
    boolean pmicPresent = TRUE;
    pmicPresent = bSailPmicPresent();
    if (pmicPresent == TRUE)
    {
        #ifdef I2C_TEST_ENABLE
            I2cTestCaseCnt = 45;
        #else
            I2cTestCaseCnt = 8;
        #endif
    }
    else
    {
        #ifdef I2C_TEST_ENABLE
            I2cTestCaseCnt = 45;
        #else
            I2cTestCaseCnt = 5;
        #endif
    }

    DEBUG_LOG(SAIL_INFO,">>>>>>  I2C El1 Test Cases Started   <<<<<<<\r\n");
    //xWdt_Test_Command.Command = WDT_DISABLE;
    //xWdt_Send_Command(xWdt_Test_Command);

        if ( MODULE_TEST_PASSED != TC_I2C_EL1_01() )
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_01] I2C EL1 DMA Initialization test Failed\r\n" );
        }
        else
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_01] I2C El1 DMA Initialization test Passed \r\n");
            I2cTestCaseCnt--;
        }
        if ( MODULE_TEST_PASSED != TC_I2C_EL1_02() )
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_02] I2C El1 Get Slave Address test Failed\r\n" );
        }
        else
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_02] I2C El1 Get Slave Address test Passed \r\n");
            I2cTestCaseCnt--;
        }
        if (pmicPresent == TRUE)
        {
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_03() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_03] I2C El1 DMA mode WRITE test for TI PMIC slave Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_03] I2C El1 DMA mode WRITE test for TI PMIC slave Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_04() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_04] I2C El1 DMA mode READ test for TI PMIC slave Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_04] I2C El1 DMA mode READ test for TI PMIC slave Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_05() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_05] I2C El1 DMA mode READ-WRITE-READ test for TI PMIC slave Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_05] I2C El1 DMA mode READ-WRITE-READ test for TI PMIC slave Passed \r\n");
                I2cTestCaseCnt--;
            }
        }
        if ( MODULE_TEST_PASSED != TC_I2C_EL1_06() )
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_06] I2C El1 DMA xI2c_EL1_PingStatusFromSlave test Failed\r\n" );
        }
        else
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_06] I2C El1 DMA xI2c_EL1_PingStatusFromSlave test Passed \r\n");
            I2cTestCaseCnt--;
        }
        if ( MODULE_TEST_PASSED != TC_I2C_EL1_07() )
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_07] I2C El1 DMA mode READ-WRITE test for Kobra PMIC slave Failed\r\n" );
        }
        else
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_07] I2C El1 DMA mode READ-WRITE test for Kobra PMIC slave Passed \r\n");
            I2cTestCaseCnt--;
        }
        if ( MODULE_TEST_PASSED != TC_I2C_EL1_08() )
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_08] I2C El1 DeInit-ReInit-DeInit test Failed\r\n" );
        }
        else
        {
            DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_08] I2C El1 DeInit-ReInit-DeInit test Passed \r\n");
            I2cTestCaseCnt--;
        }
		
		#ifdef I2C_TEST_ENABLE
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_09() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_09] I2C EL1 Polling Initialization test Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_09] I2C El1 Polling Initialization test Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_10() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_10] I2C El1 Polling mode WRITE test Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_10] I2C El1 Polling mode WRITE test Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_11() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_11] I2C El1 Polling mode READ test Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_12] I2C El1 Polling mode READ test Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_12() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_12] I2C EL1 FIFO Initialization test Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_12] I2C El1 FIFO Initialization test Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_13() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_13] I2C El1 FIFO mode WRITE test Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_13] I2C El1 FIFO mode WRITE test Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_14() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_14] I2C El1 FIFO mode READ test Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_14] I2C El1 FIFO mode READ test Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_15() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_15] I2C I2cChannelIdcheck Negative Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_15] I2C I2cChannelIdcheck Negative Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_16() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_16] I2C DeInit Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_16] I2C DeInit Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_17() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_17] I2C Write-Read with Invalid Channel Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_17] I2C Write-Read with Invalid Channel Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_18() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_18] I2C Write-Read with NULL pointer Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_18] I2C Write-Read with NULL pointer Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_19() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_19] I2C SE0 Sleep DeInit with SleepState=0 Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_19] I2C SE0 Sleep DeInit with SleepState=0 Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_20() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_20] I2C SE0 Sleep DeInit with SleepState=1 Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_20] I2C SE0 Sleep DeInit with SleepState=1 Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_21() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_21] I2C SE0 Sleep DeInit with SleepState=0 Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_21] I2C SE0 Sleep DeInit with SleepState=0 Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_22() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_22] I2C SE0 Sleep DeInit with SleepState=1 Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_22] I2C SE0 Sleep DeInit with SleepState=1 Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_23() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_23] I2C SE0 Load Configuration Invalid HWID Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_23] I2C SE0 Load Configuration Invalid HWID Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_24() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_24] I2C SE0 Load Configuration Initialization Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_24] I2C SE0 Load Configuration Initialization Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_25() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_25] I2C SE0 Load Configuration Enable Status Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_25] I2C SE0 Load Configuration Enable Status Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_26() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_26] I2C SE0 Initialization status check Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_26] I2C SE0 Initialization status check Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_27() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_27] I2C SE0 Initialization Error status check Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_27] I2C SE0 Initialization Error status check Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_28() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_28] I2C SE0 Channel ID check Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_28] I2C SE0 Channel ID check Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_29() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_29] I2C SE0 Get Slave Address Channel ID check Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_29] I2C SE0 Get Slave Address Channel ID check Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_30() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_30] I2C SE0 Clock Enable Negative Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_30] I2C SE0 Clock Enable Negative Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_31() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_31] I2C SE0 I2C Write Negative Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_31] I2C SE0 I2C Write Negative Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_32() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_32] I2C SE0 I2C ISR Negative Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_32] I2C SE0 I2C ISR Negative Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_33() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_33] I2C Initialization test with NULL Configurations case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_33] I2C Initialization test with NULL Configurations case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_34() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_34] I2C GetSlaveStatus test with Invalid channel case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_34] I2C GetSlaveStatus test with Invalid channel case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_35() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_35] I2C Transfer test with Invalid flag and datalength case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_35] I2C Transfer test with Invalid flag and datalength case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_36() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_36] I2C Transfer test with Invalid flag and datalength case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_36] I2C Transfer test with Invalid flag and datalength case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_37() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_37] I2C Read Error Check Negative case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_37] I2C Read Error Check Negative case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_38() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_38] I2C Write Error Check Negative case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_38] I2C Write Error Check Negative case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_39() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_39] I2C Clock Enable-Disable Negative case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_39] I2C Clock Enable-Disable Negative case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_40() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_40] I2C Read-Write Negative case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_40] I2C Read-Write Negative case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_41() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_41] I2C PingStatusFromSlave Negative Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_41] I2C PingStatusFromSlave Negative Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_42() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_42] I2C Serial Engine DeInit Negative Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_42] I2C Serial Engine DeInit Negative Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_43() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_43] I2C Serial Engine Sleep DeInit Negative Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_43] I2C Serial Engine Sleep DeInit Negative Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_44() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_44] I2C FiFo Read-Write Negative Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_44] I2C FiFo Read-Write Negative Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            if ( MODULE_TEST_PASSED != TC_I2C_EL1_45() )
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_45] I2C DeInit Negative Test case Failed\r\n" );
            }
            else
            {
                DEBUG_LOG( SAIL_INFO, "[TC_I2C_EL1_45] I2C DeInit Negative Test case Passed \r\n");
                I2cTestCaseCnt--;
            }
            
		    //CppTest_SendCoverage();
		#endif
        if(I2cTestCaseCnt != 0)
        {
            DEBUG_LOG( SAIL_ERROR, "I2C EL1 Unit test validation failed!!!\r\n" );
        }
        else
        {
            DEBUG_LOG( SAIL_ERROR, "I2C EL1 Unit test validation Passed!!!\r\n" );
        }

    return xReturn;
}