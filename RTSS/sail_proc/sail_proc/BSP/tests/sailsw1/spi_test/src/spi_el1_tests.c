/**********************************************************************************************************
    Copyright (c) 2024 Qualcomm Technologies, Inc.
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
**********************************************************************************************************/
//#ifdef SAILSW2
#include "tests.h"
#include "debug_log.h"
#include "Spi.h"
#include "busywait.h"

#define MAX_LB_LEN 10u
#define MAX_CAN_TRX_TRANS_LEN 4U
#define spiTOTAL_UNIT_USECASES 1U

#define spiCANTRX_SCRATCH_REG_ADDR  0xF
#define spiCANTRX_SCRATCH_REG_VAL   0x77
#define CAN_ADDR_SHIFT_VALUE        1U
#define CAN_WRITE_CNTRL             1U


uint8 ucTrxDeviceId[MAX_CAN_TRX_TRANS_LEN] = {0x0, 0x54, 0x43, 0x41};
SPI_DATA uint8 InputBuffer0[MAX_LB_LEN];
SPI_DATA uint8 OutputBuffer0[MAX_LB_LEN];
SPI_DATA uint8 InputBuffer1[MAX_CAN_TRX_TRANS_LEN];
SPI_DATA uint8 OutputBuffer1[MAX_CAN_TRX_TRANS_LEN];
SPI_DATA uint8 InputBuffer2[MAX_CAN_TRX_TRANS_LEN];
SPI_DATA uint8 OutputBuffer2[MAX_CAN_TRX_TRANS_LEN];
SPI_DATA uint8 InputBuffer3[MAX_LB_LEN];
SPI_DATA uint8 OutputBuffer3[MAX_LB_LEN];
SPI_DATA uint8 InputBuffer4[MAX_LB_LEN];
SPI_DATA uint8 OutputBuffer4[MAX_LB_LEN];
SPI_DATA uint8 InputBuffer5[MAX_LB_LEN];
SPI_DATA uint8 OutputBuffer5[MAX_LB_LEN];

#define SPI_ASYNC_MODE_TESTING 0x0U
#define SPI_UNIT_TEST 0x1U

uint8 volatile async_status = 0x7;
static void prvSPITestDebugPrint ( TESTerrorType_e result, const char * TestMsg, uint16_t usTestCaseNum )
{
    if( MODULE_TEST_PASSED == result )
    {
    	 DEBUG_LOG(SAIL_WARNING, "[TC_SPI_%03d]: %s - Passed\n\r", usTestCaseNum, TestMsg );
    }
    else
    {
    	 DEBUG_LOG(SAIL_WARNING, "[TC_SPI_%03d]: %s - Failed\n\r", usTestCaseNum, TestMsg);
    }
}

/*Test Synchronous transmission in Loopback mode*/
TESTerrorType_e TC_SPI_001(TestCaseType TCType )
{
    TESTerrorType_e retStatus = MODULE_TEST_PASSED;
	Std_ReturnType RetVal = E_NOT_OK;
	uint8 ucCount = 0;
	
    for(uint8 i=0; i <MAX_LB_LEN; i++)
    {
    	InputBuffer0[i] = 0xAA;
    	OutputBuffer0[i] = 0;
    }

	Spi_SetupEB( SpiChannel_0, &InputBuffer0[0], &OutputBuffer0[0],  MAX_LB_LEN);

	RetVal = Spi_SyncTransmit(SpiSequence_0);

	if( RetVal == E_OK)
	{
		retStatus = MODULE_TEST_PASSED;

		for(ucCount = 0; ucCount < MAX_LB_LEN; ucCount++)
		{
			if( OutputBuffer0[ucCount] != InputBuffer0[ucCount] )
			{
				retStatus = MODULE_TEST_FAILED;
				break;
			}
		}
	}
	else
	{
		retStatus = MODULE_TEST_FAILED;
	}
	if(TCType == UARTFRAMEWORK)
	{
		prvSPITestDebugPrint(retStatus, "Test Synchronous transmission in Loopback mode", 1 );
	}
	else if ( (TCType == DVFRAMEWORK) && (MODULE_TEST_FAILED == retStatus) )
	{
//		DebugPrint_DVTask(DVTASK_FAILED,1);
	}


    return retStatus;
}

/*>>>>>>>>>>>>>>> [TC_SPI_002] Test Read TCAN0 Device ID using synchronous transfer <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_002(void )
{
	TESTerrorType_e ulTestStatus = MODULE_TEST_PASSED;
	uint8 ucCount = 0;
	Std_ReturnType Std_Return = E_OK;

	/* Read CAN TRX0 device ID*/
	/* CAN Trx Channel config*/
	OutputBuffer1[0] = 0x0;
	for (uint8 i=0; i<4;i++)
	{
		InputBuffer1[i] = 0x0;
	}
	Std_Return |= Spi_SetupEB( SpiChannel_1, &InputBuffer1[0], &OutputBuffer1[0], 4 );

	Std_Return = Spi_SyncTransmit( SpiSequence_1 );

	if( E_OK == Std_Return )
	{
		for(ucCount = 1; ucCount < MAX_CAN_TRX_TRANS_LEN; ucCount++)
		{
			if( OutputBuffer1[ucCount] != ucTrxDeviceId[ucCount] )
			{
				ulTestStatus = MODULE_TEST_FAILED;
				break;
			}
		}
	}
	else
	{
		ulTestStatus = MODULE_TEST_FAILED;
	}

	prvSPITestDebugPrint(ulTestStatus, "Test Read TCAN0 Device ID using synchronous transfer", 2 );

	return ulTestStatus;
}

/*>>>>>>>>>>>>>>> [TC_SPI_003] Test Read TCAN1 Device ID using synchronous transfer <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_003(void )
{
	TESTerrorType_e ulTestStatus = MODULE_TEST_PASSED;
	uint8 ucCount = 0;
	Std_ReturnType Std_Return = E_OK;

	/* Read CAN TRX1 device ID*/
	/* CAN Trx Channel config*/
	OutputBuffer2[0] = 0x0;
	for (uint8 i=0; i<4;i++)
	{
		InputBuffer2[i] = 0x0;
	}
	Std_Return |= Spi_SetupEB( SpiChannel_2, &InputBuffer2[0], &OutputBuffer2[0], 4 );

	Std_Return = Spi_SyncTransmit( SpiSequence_2 );

	if( E_OK == Std_Return )
	{
		for(ucCount = 1; ucCount < MAX_CAN_TRX_TRANS_LEN; ucCount++)
		{
			if( OutputBuffer2[ucCount] != ucTrxDeviceId[ucCount] )
			{
				ulTestStatus = MODULE_TEST_FAILED;
				break;
			}
		}
	}
	else
	{
		ulTestStatus = MODULE_TEST_FAILED;
	}
	prvSPITestDebugPrint(ulTestStatus, "Test Read TCAN1 Device ID using synchronous transfer", 3 );

	return ulTestStatus;
}

/*>>>>>>>>>>>>>>> [TC_SPI_005] Test - Write/Read TCAN0 Scratch registe <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_005(void )
{
	TESTerrorType_e ulTestStatus = MODULE_TEST_FAILED;
	Std_ReturnType Std_Return = E_OK;

	for (uint8 i=0; i<4;i++)
	{
		OutputBuffer1[i] = 0x0;
	}

	/* Write into CAN TRX1 SPI scratch register*/
	InputBuffer1[0] = spiCANTRX_SCRATCH_REG_ADDR << CAN_ADDR_SHIFT_VALUE | CAN_WRITE_CNTRL;
	InputBuffer1[1] =  spiCANTRX_SCRATCH_REG_VAL;

	Std_Return |= Spi_SetupEB( SpiChannel_1, &InputBuffer1[0], &OutputBuffer1[0], 2 );

	Std_Return = Spi_SyncTransmit( SpiSequence_1 );

	if( E_OK == Std_Return )
	{
		/* Read the CAN TRX1 SPI scratch register*/
		InputBuffer1[0] = spiCANTRX_SCRATCH_REG_ADDR << CAN_ADDR_SHIFT_VALUE;
		OutputBuffer1[0] = 0x00;
		OutputBuffer1[1] = 0x00;
		Std_Return |= Spi_SetupEB( SpiChannel_1, &InputBuffer1[0], &OutputBuffer1[0], 2 );
		Std_Return = Spi_SyncTransmit( SpiSequence_1 );
		if( E_OK == Std_Return )
		{
			if( OutputBuffer1[1] == spiCANTRX_SCRATCH_REG_VAL )
			{
				ulTestStatus = MODULE_TEST_PASSED;
			}
		}
	}
	
	prvSPITestDebugPrint(ulTestStatus, "Test - Write/Read TCAN0 Scratch register", 5 );

	return ulTestStatus;
}

/*>>>>>>>>>>>>>>> [TC_SPI_007] Test SPI DeInit-Init  <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_007(void )
{
	TESTerrorType_e ulTestStatus = MODULE_TEST_FAILED;
	Std_ReturnType RetVal = E_OK;
	uint8 ucCount = 0;

	RetVal = Spi_DeInit();

	if(RetVal == E_OK)
	{
		Spi_Init(&Spi_Config);

		for(uint8 i=0; i <MAX_LB_LEN; i++)
		{
			InputBuffer0[i] = 0xAA;
			OutputBuffer0[i] = 0;
		}

		Spi_SetupEB( SpiChannel_0, &InputBuffer0[0], &OutputBuffer0[0],  MAX_LB_LEN);

		RetVal = Spi_SyncTransmit(SpiSequence_0);

		if( RetVal == E_OK)
		{
			ulTestStatus = MODULE_TEST_PASSED;

			for(ucCount = 0; ucCount < MAX_LB_LEN; ucCount++)
			{
				if( OutputBuffer0[ucCount] != InputBuffer0[ucCount] )
				{
					ulTestStatus = MODULE_TEST_FAILED;
					break;
				}
			}
		}
		else
		{
			ulTestStatus = MODULE_TEST_FAILED;
		}
	}

	prvSPITestDebugPrint(ulTestStatus, "Test SPI DeInit-Init", 7 );

	return ulTestStatus;
}

/*>>>>>>>>>>>>>>> [TC_SPI_008] Test Spi_GetJobResult API for a Job ID in sync mode <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_008(void)
{
    TESTerrorType_e retStatus = MODULE_TEST_FAILED;
    Spi_JobResultType JobResult = SPI_JOB_FAILED;

    JobResult= Spi_GetJobResult(SpiJob_2);
    if( JobResult == SPI_JOB_OK)
    {
    	retStatus = MODULE_TEST_PASSED;
    }

    prvSPITestDebugPrint(retStatus, "Test Spi_GetJobResult API for a Job ID in sync mode", 8 );

    return retStatus;
}

/*>>>>>>>>>>>>>>> [TC_SPI_009] Test Spi_GetSequenceResult API for a Sequence ID in sync mode <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_009(void)
{
    TESTerrorType_e retStatus = MODULE_TEST_FAILED;
	Spi_SeqResultType SeqResult = SPI_SEQ_FAILED;

	SeqResult = Spi_GetSequenceResult(SpiSequence_0);

    if( SeqResult == SPI_SEQ_OK)
    {
       	retStatus = MODULE_TEST_PASSED;
    }

    prvSPITestDebugPrint(retStatus, "Test Spi_GetSequenceResult API for a Sequence ID in sync mode", 9 );

    return retStatus;
}

/*>>>>>>>>>>>>>>>TC_SPI_010 - Test Spi_GetStatus API for Spi Handler driver in asynchronous mode <<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_010(void)
{
    TESTerrorType_e retStatus = MODULE_TEST_FAILED;
    Spi_StatusType RetVal;

    RetVal = Spi_GetStatus();
    if( RetVal == SPI_IDLE)
    {
    	retStatus = MODULE_TEST_PASSED;
    }

    prvSPITestDebugPrint(retStatus, "Test Spi_GetStatus API for Spi Handler driver", 10 );
    return retStatus;
}

#if (SPI_ASYNC_MODE_TESTING == 0x1U)
/*>>>>>>>>>>>>>>> [TC_SPI_004] Test asynchronous transfer in loopback mode <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_004(void )
{
	TESTerrorType_e ulTestStatus = MODULE_TEST_FAILED;
	Std_ReturnType Std_Return = E_OK;

    for(uint8 i=0; i <MAX_LB_LEN; i++)
    {
    	InputBuffer3[i] = 0xAA;
    	OutputBuffer3[i] = 0;
    	InputBuffer4[i] = 0xBB;
    	OutputBuffer4[i] = 0;
    	InputBuffer5[i] = 0xCC;
    	OutputBuffer5[i] = 0;
    }

	Std_Return |= Spi_SetupEB( SpiChannel_3, &InputBuffer3[0], &OutputBuffer3[0], 50 );
	Std_Return |= Spi_SetupEB( SpiChannel_4, &InputBuffer4[0], &OutputBuffer4[0], 250 );
	Spi_AsyncTransmit(3);

	while(async_status != 5)
	{
		busywait(10);
	}
	if(async_status == 0x5)
	{
		async_status = 7;
		ulTestStatus = MODULE_TEST_PASSED;
	}
	prvSPITestDebugPrint(ulTestStatus, "Test asynchronous transfer in loopback mode", 4 );

	return ulTestStatus;
}

/*>>>>>>>>>>>>>>> [TC_SPI_006] Test asynchronous transfer with can device <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_006(void )
{
	TESTerrorType_e ulTestStatus = MODULE_TEST_FAILED;
	Std_ReturnType Std_Return = E_OK;

	OutputBuffer1[0] = 0x0;
	for (uint8 i=0; i<4;i++)
	{
		InputBuffer1[i] = 0x0;
	}

	Std_Return |= Spi_SetupEB( SpiChannel_1, &InputBuffer1[0], &OutputBuffer1[0], 4 );
	Spi_AsyncTransmit(4);

	while(async_status != 5)
	{
		busywait(10);
	}
	if(async_status == 0x5)
	{
		async_status = 7;
		ulTestStatus = MODULE_TEST_PASSED;
	}
	prvSPITestDebugPrint(ulTestStatus, "Test Read TCAN0 Device ID using Asynchronous transfer", 6 );

	return ulTestStatus;
}

/*>>>>>>>>>>>>>>> [TC_SPI_011] Test Spi_GetJobResult API for a Job ID in Async mode <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_011(void)
{
    TESTerrorType_e retStatus = MODULE_TEST_FAILED;
    Spi_JobResultType JobResult = SPI_JOB_FAILED;

    JobResult= Spi_GetJobResult(SpiJob_4);
    if( JobResult == SPI_JOB_OK)
    {
    	retStatus = MODULE_TEST_PASSED;
    }

    prvSPITestDebugPrint(retStatus, "Test Spi_GetJobResult API for a Job ID in Async mode", 11 );

    return retStatus;
}

/*>>>>>>>>>>>>>>> [TC_SPI_012] Test Spi_GetSequenceResult API for a Sequence ID in Async mode <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_SPI_012(void)
{
    TESTerrorType_e retStatus = MODULE_TEST_FAILED;
	Spi_SeqResultType SeqResult = SPI_SEQ_FAILED;

	SeqResult = Spi_GetSequenceResult(SpiSequence_3);

    if( SeqResult == SPI_SEQ_OK)
    {
       	retStatus = MODULE_TEST_PASSED;
    }

    prvSPITestDebugPrint(retStatus, "Test Spi_GetSequenceResult API for a Sequence ID in Async mode", 12 );

    return retStatus;
}

#endif
/*ToDo: 1. Spi_Deinit API support
 * 2. Get sequence status API
 * 3. Get SPI Driver status API
 * */
void SpiSequence_3_Test_Notification()
{
	async_status = 0x5u;
}

void SpiSequence_4_Test_Notification()
{
	async_status = 0x5u;
}

TESTerrorType_e xTestSPIWrapper(void)
{
	TESTerrorType_e ulTestStatus = MODULE_TEST_FAILED;
	uint8 ucTestCaseCount = spiTOTAL_UNIT_USECASES;

#if (SPI_ASYNC_MODE_TESTING == 0x0U)
	if ( MODULE_TEST_FAILED == TC_SPI_001(UARTFRAMEWORK) )
	{
		ucTestCaseCount--;
	}
#endif

#if (SPI_UNIT_TEST == 0x1U)
	if ( MODULE_TEST_FAILED == TC_SPI_002() )
	{
		ucTestCaseCount--;
	}
	if ( MODULE_TEST_FAILED == TC_SPI_003() )
	{
		ucTestCaseCount--;
	}
	if ( MODULE_TEST_FAILED == TC_SPI_005() )
	{
		ucTestCaseCount--;
	}
//	if ( MODULE_TEST_FAILED == TC_SPI_007() )
//	{
//		ucTestCaseCount--;
//	}
	if ( MODULE_TEST_FAILED == TC_SPI_008() )
	{
		ucTestCaseCount--;
	}
	if ( MODULE_TEST_FAILED == TC_SPI_009() )
	{
		ucTestCaseCount--;
	}
	if ( MODULE_TEST_FAILED == TC_SPI_010() )
	{
		ucTestCaseCount--;
	}
#endif
#if (SPI_ASYNC_MODE_TESTING == 0x1U)
	if ( MODULE_TEST_FAILED == TC_SPI_004() )
	{
		ucTestCaseCount--;
	}
	if ( MODULE_TEST_FAILED == TC_SPI_006() )
	{
		ucTestCaseCount--;
	}
	if ( MODULE_TEST_FAILED == TC_SPI_010() )
	{
		ucTestCaseCount--;
	}
	if ( MODULE_TEST_FAILED == TC_SPI_011() )
	{
		ucTestCaseCount--;
	}
	if ( MODULE_TEST_FAILED == TC_SPI_012() )
	{
		ucTestCaseCount--;
	}
#endif
	if(ucTestCaseCount != spiTOTAL_UNIT_USECASES)
	{
		 DEBUG_LOG(SAIL_INFO,"[SPI] Testing is Failed\n\r");
	}
	else
	{
		ulTestStatus = MODULE_TEST_PASSED;
		 DEBUG_LOG(SAIL_INFO,"[SPI] All Test Cases are Passed\n\r");
	}
	return ulTestStatus;
}

TESTerrorType_e xSPIDVTestWrapper(void)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;

    xRetStatus = TC_SPI_001(DVFRAMEWORK);

    return xRetStatus;
}
//#endif
