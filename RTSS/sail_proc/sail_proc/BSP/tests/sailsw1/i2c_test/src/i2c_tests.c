/*******************************************************************************
**                                                                            **
** Copyright (C)  2020, 2024 Qualcomm Technologies, Inc. (2020)                     **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Qualcomm       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : i2c_test.c                                                 **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2020-6-01                                                  **
**                                                                            **
**  PLATFORM     : Qualcomm SMSS                                              **
**                                                                            **
**  AUTHOR       : SMSS SW DEV                                                **
**                                                                            **
**  VENDOR       : Qualcomm Technologies, Inc.                                **
**                                                                            **
**  DESCRIPTION  : i2c test file                                              **
**                                                                            **
**  SPECIFICATION(S) : Unit test specification                                **
**                                                                            **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include <stdio.h>
#include "tests.h"
#include "i2c.h"
#include "hw_io.h"
#include "crc.h"
#include "crcconfig.h"
#include "debug_log.h"
#include "psailInternal.h"
#include "pmicapi.h"
#include "qup_common_hwio.h"
#include "hw_io.h"
//#include "wdt_safertos.h"
#include "FreeRTOSOsal.h"
#include "pmici2c.h"
//#include "monitor.h"
//#include "acmu_monitor.h"

/*******************************************************************************
**                Private Macro Definitions                                   **
*******************************************************************************/
#define i2cMergePmicTestCase            0x4U
#define i2cIndependentPmicTestCase      0xAU

#define i2cNUM_MODE                     0x3U
/*******************************************************************************
**                Global variables                                            **
*******************************************************************************/
TEST_BSS static i2cHwUnitCfgType xI2CHwConfig[MAX_NO_OF_SERIAL_ENGINE];

typedef struct
{
    uint32  ulSEClockFrequencyHz;
    uint32  ulBusSpeedKhz;
    uint8   ucClkDiv;
    uint8   ucTCycle;
    uint8   ucTHigh;
    uint8   ucTLow;
}i2cClockConfigType;

TEST_DATA static const i2cClockConfigType xI2cClkCfg[i2cNUM_MODE] =
{
    // src-freq, speed, div, cycle, high, low
    [I2C_STANDARD_MODE] = { 19200000, 100,  7, 26, 10, 11 },
    [I2C_FAST_MODE] = { 19200000, 400,  2, 24, 5,  12 },
    [I2C_FASTPLUS_MODE] ={ 19200000, 1000, 1, 18, 3,  9  }
};

/*==============================================================================
**                               function prototypes                          **
==============================================================================*/
TEST_FUNC void I2cChange_Mode(i2cMode_e xI2c_mode);
TEST_FUNC TESTerrorType_e TC_I2C_01(void);
TEST_FUNC TESTerrorType_e TC_I2C_02(void);
TEST_FUNC TESTerrorType_e TC_I2C_03(void);
TEST_FUNC TESTerrorType_e TC_I2C_04(void);
TEST_FUNC TESTerrorType_e TC_I2C_05(void);
TEST_FUNC TESTerrorType_e TC_I2C_06(void);
TEST_FUNC TESTerrorType_e TC_I2C_07(void);
TEST_FUNC TESTerrorType_e TC_I2C_08(void);
TEST_FUNC TESTerrorType_e TC_I2C_09(void);
TEST_FUNC TESTerrorType_e TC_I2C_010(void);
#ifdef SAILSW3
static portBaseType I2cEL2AcmuMonitorDeInit(eMonitorType MONITOR_ID);
#endif
/*******************************************************************************
**             				   Functions                                      **
*******************************************************************************/

TEST_FUNC void I2cChange_Mode(i2cMode_e xI2c_mode)
{
	uint32 ulSEBase = 0xF1900000; 
//Changing I2C mode 
/* Clock Configuration*/
        REG_OUT(ulSEBase, GENI_SER_M_CLK_CFG,
                         FLD_SET(GENI_SER_M_CLK_CFG, CLK_DIV_VALUE,
                                                     xI2cClkCfg[xI2c_mode].ucClkDiv) |
                         FLD_SET(GENI_SER_M_CLK_CFG, SER_CLK_EN,      1));

        /* SCL Configuration*/
        REG_OUT(ulSEBase, I2C_SCL_COUNTERS,
                         FLD_SET(I2C_SCL_COUNTERS, I2C_SCL_HIGH_COUNTER,
                                                   xI2cClkCfg[xI2c_mode].ucTHigh) |
                         FLD_SET(I2C_SCL_COUNTERS, I2C_SCL_LOW_COUNTER,
                                                   xI2cClkCfg[xI2c_mode].ucTLow)  |
                         FLD_SET(I2C_SCL_COUNTERS, I2C_SCL_CYCLE_COUNTER,
                                                   xI2cClkCfg[xI2c_mode].ucTCycle));
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Clock Monitor Disable <<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#ifdef SAILSW3
static portBaseType I2cEL2AcmuMonitorDeInit(eMonitorType MONITOR_ID)
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
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST CASES <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_01] READ AFTER WRITE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_01(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	pmicPageId_e xpageId = PAGE_ID_0; 
	uint32 uladdr = 0xC9;
	uint8 ucdata = 0x5;
	uint8 pcdata[1] = {0};
	if ( PMIC_ERR_FLAG_SUCCESS == prvPmicCommWriteByte( xpageId, uladdr , ucdata) )
	{
		vFreeRTOSTaskDelay(10);
		DEBUG_LOG(SAIL_INFO,"PMIC COMM WRITE BYTE SUCCESS. WRITE value: %d\r\n", ucdata);
		if ( PMIC_ERR_FLAG_SUCCESS == prvPmicCommReadByte(xpageId, uladdr , pcdata) )
		{
			if ( ucdata == pcdata[0])
			{
				vFreeRTOSTaskDelay(10);
				DEBUG_LOG(SAIL_INFO,"PMIC COMM READ BYTE VALUE: %d\r\n", pcdata[0]);
				xReturn = MODULE_TEST_PASSED;
			}
		}
		else
		{
			DEBUG_LOG(SAIL_INFO,"PMIC COMM READ BYTE FAIL.\r\n");
			xReturn = MODULE_TEST_FAILED;
		}
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"PMIC COMM WRITE BYTE FAIL.\r\n");
		xReturn = MODULE_TEST_FAILED;
	}
    return xReturn;
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_02] READ->WRITE->READ <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_02(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	pmicPageId_e xpageId = PAGE_ID_0; 
	uint32 uladdr = 0xC9;
	uint8 pcdata[1] = {0};
	uint8 ucdata = 0x3;
	if ( PMIC_ERR_FLAG_SUCCESS == prvPmicCommReadByte(xpageId, uladdr , pcdata) )
	{
		vFreeRTOSTaskDelay(10);
		DEBUG_LOG(SAIL_INFO,"PMIC COMM FIRST READ BYTE VALUE: 0x%x\r\n", pcdata[0]);
		if ( PMIC_ERR_FLAG_SUCCESS == prvPmicCommWriteByte( xpageId, uladdr , ucdata))
		{
			vFreeRTOSTaskDelay(10);
			DEBUG_LOG(SAIL_INFO,"PMIC COMM WRITE BYTE SUCCESS. WRITE value: 0x%x\r\n", ucdata);
			if (PMIC_ERR_FLAG_SUCCESS == prvPmicCommReadByte(xpageId, uladdr , pcdata))
			{
				if (pcdata[0] == ucdata)
				{
					vFreeRTOSTaskDelay(10);
					DEBUG_LOG(SAIL_INFO,"PMIC COMM SECOND READ BYTE VALUE: 0x%x\r\n", pcdata[0]);
					xReturn = MODULE_TEST_PASSED;
				}
			}
			else
			{
				DEBUG_LOG(SAIL_INFO,"PMIC COMM READ SECOND BYTE VALUE and WRITE BYTE VALUE DOESNT NOT MATCH. FAILS\r\n");
				xReturn = MODULE_TEST_FAILED;
			}
		}
		else
		{
			DEBUG_LOG(SAIL_INFO,"PMIC COMM WRITE BYTE FAIL.\r\n");
			xReturn = MODULE_TEST_FAILED;
		}
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"PMIC COMM FIRST READ BYTE FAIL.\r\n");
		xReturn = MODULE_TEST_FAILED;
	}
    return xReturn;
}

// /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_03] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_03(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	xReturn = TC_I2C_01();
	return xReturn;
}

// /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_04] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_04(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	
	xReturn = TC_I2C_02();
	return xReturn;
}

// /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_05] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_05(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	
	xReturn = TC_I2C_01();
	return xReturn;
}

// /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_06] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_06(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	
	xReturn = TC_I2C_02();
	return xReturn;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_08] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_08(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	uint8  ucHardwareId = 0;

#ifdef SAILSW3
    I2cEL2AcmuMonitorDeInit(CLOCK_MON);
#endif
	if ( I2C_SUCCESS == xI2cDeInit( ucHardwareId) )
	{
		DEBUG_LOG(SAIL_INFO,"TC_I2C_08: I2C DeInit Success.\r\n");
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_I2C_08: I2C DeInit FAIL.\r\n");
		xReturn = MODULE_TEST_FAILED;
	}
    return xReturn;
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_09] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_09(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	uint8  ucHardwareId = 0xFF;

	if ( I2C_HW_NOT_EXIST == xI2cInit(ucHardwareId) ) 
	{
		DEBUG_LOG(SAIL_INFO,"TC_I2C_09: I2C Init with Invalid HWID Success.\r\n");
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_I2C_09: I2C Init with Invalid HWID FAIL.\r\n");
		xReturn = MODULE_TEST_FAILED;
	}
#ifdef SAILSW3
    I2cEL2AcmuMonitorDeInit(CLOCK_MON);
#endif
	if ( I2C_HW_NOT_EXIST == xI2cDeInit( ucHardwareId) )
	{
		DEBUG_LOG(SAIL_INFO,"TC_I2C_09: I2C DeInit with Invalid HWID Success.\r\n");
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_I2C_09: I2C DeInit with Invalid HWID FAIL.\r\n");
		xReturn = MODULE_TEST_FAILED;
	}
    return xReturn;
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_I2C_010] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_010(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	uint8  ucHardwareId = 0;
	if ( I2C_SUCCESS == xI2cInit(ucHardwareId) ) 
	{
		DEBUG_LOG(SAIL_INFO,"TC_I2C_010: I2C Init Success.\r\n");
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_I2C_010: I2C Init FAIL.\r\n");
		xReturn = MODULE_TEST_FAILED;
	}
    return xReturn;
}

/*>>>>>>>>>>>>>>> [TC_I2C_07] Test - Readout RevID of All PSAIL Connected  <<<<<<<<<<<<<<<<<<*/

TEST_FUNC TESTerrorType_e TC_I2C_07(void)
{
    uint8 ucPsailChannel = PSAIL_B_ID;
    uint8 ucHardwareId = 0x0u;
    uint8 ucRevID[2] = {0x0u};
    TESTerrorType_e xReturn = MODULE_TEST_PASSED;
    i2cStatus_e xI2CStatus = I2C_SUCCESS;
    uint8 ucI2cPingCount = 0x0u;
	uint8 pcData = 0x48;
	uint8 ucReadback = 0x0u;
    for ( ucPsailChannel =  PSAIL_B_ID ; ucPsailChannel < MAX_PSAIL_ID  ; ucPsailChannel++)
    {
		vFreeRTOSTaskDelay(10);
        if ( I2C_SUCCESS == xI2cPingStatusFromSlave(ucPsailChannel,ucHardwareId))
        {
			vFreeRTOSTaskDelay(10);
            xI2CStatus = xI2cRead((uint8) ucPsailChannel, 0x104, 2, ucRevID);
            if ( I2C_SUCCESS ==  xI2CStatus)
            {
				vFreeRTOSTaskDelay(10);
                if( ( ucRevID[0] == psailREVID_PERPH_TYPE) && ( ucRevID[1] == psailREVID_PERPH_SUBTYPE))
                {
                    DEBUG_LOG(SAIL_INFO,"Psail %d Revid: 0x%x 0x%x\r\n",ucPsailChannel-PSAIL_B_ID,ucRevID[0],ucRevID[1]);
                }else
                {
                    xReturn |= MODULE_TEST_FAILED;
                }
            }else
            {
                xReturn |= MODULE_TEST_FAILED;
            }
			if ( I2C_SUCCESS == xI2cWrite((uint8) ucPsailChannel , 0x7777, 1, &pcData) )
			{
				vFreeRTOSTaskDelay(10);
				DEBUG_LOG(SAIL_INFO,"PSAIL WRITE: 0x%x\r\n", pcData);
				xI2CStatus = xI2cRead((uint8) ucPsailChannel, 0x7777, 1, &ucReadback);
				if ( ucReadback == pcData && I2C_SUCCESS == xI2CStatus )
				{
					vFreeRTOSTaskDelay(10);
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

/*
*
*
	<<<<<<<<<<<< xTestI2cWrapper >>>>>>>>>>>>>>>
*
*
*/

TEST_FUNC TESTerrorType_e xTestI2cWrapper(void)
{
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
    uint8 uI2cTestCaseCnt = i2cMergePmicTestCase;
    DEBUG_LOG(SAIL_INFO,">>>>>>  I2C Test Cases Started   <<<<<<<\r\n");

    if ( TRUE == bSailPmicPresent() )
    {
		DEBUG_LOG(SAIL_INFO,">>>>>>  PMIC Independent Test Cases:   <<<<<<<\r\n");
        uI2cTestCaseCnt = i2cIndependentPmicTestCase;
		
		DEBUG_LOG( SAIL_INFO, "I2C: STANDARD MODE\r\n" );
		I2cChange_Mode(I2C_STANDARD_MODE);
		
		if ( MODULE_TEST_PASSED != TC_I2C_01() )
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_01 Failed\r\n" );
		}else
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_01 Passed\r\n" );
			uI2cTestCaseCnt--;
		}
		if ( MODULE_TEST_PASSED != TC_I2C_02() )
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_02 Failed\r\n" );
		}else
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_02 Passed\r\n" );
			uI2cTestCaseCnt--;
		}
		
		DEBUG_LOG( SAIL_INFO, "I2C: FAST MODE\r\n" );
		I2cChange_Mode(I2C_FAST_MODE);
		
		if ( MODULE_TEST_PASSED != TC_I2C_03() )
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_03 Failed\r\n" );
		}else
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_03 Passed\r\n" );
			uI2cTestCaseCnt--;
		}
		if ( MODULE_TEST_PASSED != TC_I2C_04() )
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_04 Failed\r\n" );
		}else
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_04 Passed\r\n" );
			uI2cTestCaseCnt--;
		}
		
		DEBUG_LOG( SAIL_INFO, "I2C: FASTPLUS MODE\r\n" );
		I2cChange_Mode(I2C_FASTPLUS_MODE);
		
		if ( MODULE_TEST_PASSED != TC_I2C_05() )
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_05 Failed\r\n" );
		}else
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_05 Passed\r\n" );
			uI2cTestCaseCnt--;
		}
		if ( MODULE_TEST_PASSED != TC_I2C_06() )
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_06 Failed\r\n" );
		}else
		{
			DEBUG_LOG( SAIL_INFO, "TC_I2C_06 Passed\r\n" );
			uI2cTestCaseCnt--;
		}
	}
	
	if ( MODULE_TEST_PASSED != TC_I2C_07() )
    {
        DEBUG_LOG( SAIL_INFO, "TC_I2C_07: PSAIL Failed\r\n" );
    }
	else
    {
        DEBUG_LOG( SAIL_INFO, "TC_I2C_07: PSAIL Passed\r\n" );
            uI2cTestCaseCnt--;
    }
	
	
	if ( MODULE_TEST_PASSED != TC_I2C_08() )
    {
        DEBUG_LOG( SAIL_INFO, "TC_I2C_08: DeInit Failed\r\n" );
    }
	else
    {
        DEBUG_LOG( SAIL_INFO, "TC_I2C_08: DeInit Passed\r\n" );
            uI2cTestCaseCnt--;
    }
	vFreeRTOSTaskDelay(50); 

    if ( MODULE_TEST_PASSED != TC_I2C_09() )
    {
        DEBUG_LOG( SAIL_INFO, "TC_I2C_09: I2C Init-DeInit with Invalid HWID Failed\r\n" );
    }
	else
    {
        DEBUG_LOG( SAIL_INFO, "TC_I2C_09: I2C Init-DeInit with Invalid HWID Passed\r\n" );
            uI2cTestCaseCnt--;
    }
	vFreeRTOSTaskDelay(50); 

    if ( MODULE_TEST_PASSED != TC_I2C_010() )
    {
        DEBUG_LOG( SAIL_INFO, "TC_I2C_010: Init Failed\r\n" );
    }
	else
    {
        DEBUG_LOG( SAIL_INFO, "TC_I2C_010: Init Passed\r\n" );
            uI2cTestCaseCnt--;
    }

    if ( 0x0u == uI2cTestCaseCnt)
    {
        DEBUG_LOG( SAIL_WARNING, "[I2C tests Passed]\r\n" );
        xReturn =  MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG( SAIL_INFO, "[I2C tests Failed]\r\n" );
        xReturn =  MODULE_TEST_FAILED;
    }
	return xReturn;
}


