/**
 * @file lc_tests.c
 * @brief
 * Source file for testing lc driver of safety manager
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
/*==========================================================================*/

#include <math.h>
#include "logcode.h"
#include "tests.h"
#include <stdlib.h>
#include "debug_log.h"
#include "HALhwio.h"
#include "common_functions.h"

/* Test Wrapper function to test the LOG CODES ,SAIL BOOT MILESTONES module */
TEST_FUNC TESTerrorType_e xTestsLCWrappper( void ) {
	TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;
	
	uint8_t *receive_result; 

	// SAIL MILESTONES
	receive_result = LcReadLogCode( SAIL_BOOT_MILESTONES );
	if(receive_result != NULL)
	{
		DEBUG_LOG( SAIL_INFO, "SAIL BOOT MILESTONE STATUS : ");
		
		for(int i=0; i<LOGCODE_SAIL_BOOT_SIZE;i++)
		{
			DEBUG_LOG_NOTIMESTAMP(SAIL_INFO, "0x%X ", receive_result[i]);
		}	
	}
	DEBUG_LOG_NOTIMESTAMP(SAIL_INFO, "\n\r");

	// MD MILESTONES
	receive_result = LcReadLogCode( MD_BOOT_MILESTONES );
	if(receive_result != NULL)
	{
		DEBUG_LOG( SAIL_INFO, "MD BOOT MILESTONE STATUS : ");
		
		for(int i=0; i<LOGCODE_MD_BOOT_SIZE;i++)
		{
			DEBUG_LOG_NOTIMESTAMP(SAIL_INFO, "0x%X ", receive_result[i]);
		}	
	}
	DEBUG_LOG_NOTIMESTAMP(SAIL_INFO, "\n\r");
	return xRetStatus;
}

/* Test Wrapper function to test the Timestamp module */
TEST_FUNC TESTerrorType_e xTestsLCTstampWrappper( void ){
	TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;

	uint64_t *Tstamp     = (uint64_t*)LOGCODE_TIMESTAMP_ADDR ;
	uint8_t *Tstamp_core = (uint8_t*)LOGCODE_TIMESTAMP_CORE_ADDR;
	
	#define MBTF_BMRKR_STR(str) #str
	const char *scMbtfsbmlist[eSAIL_BSTAGE_MAX] =
	{
		MBTF_BMRKR_STR(CORE0_EL2_START),
		MBTF_BMRKR_STR(PMIC_START),
		MBTF_BMRKR_STR(PMIC_END),
		MBTF_BMRKR_STR(SPI_NOR_START),
		MBTF_BMRKR_STR(SPI_NOR_END),
		MBTF_BMRKR_STR(BIST_PH1_START),
		MBTF_BMRKR_STR(BIST_PH1_END),
		MBTF_BMRKR_STR(BIST_PH2_START),
		MBTF_BMRKR_STR(BIST_PH2_END),
		MBTF_BMRKR_STR(SBL_START),
		MBTF_BMRKR_STR(CORE1_EL2_START),
		MBTF_BMRKR_STR(CORE2_EL2_START),
		MBTF_BMRKR_STR(CORE3_EL2_START),
		MBTF_BMRKR_STR(CORE1_EL1_LOAD_START),
		MBTF_BMRKR_STR(CORE2_EL1_LOAD_START),
		MBTF_BMRKR_STR(CORE3_EL1_LOAD_START),
		MBTF_BMRKR_STR(CORE1_EL1_LOAD_END),
		MBTF_BMRKR_STR(CORE2_EL1_LOAD_END),
		MBTF_BMRKR_STR(CORE3_EL1_LOAD_END),
		MBTF_BMRKR_STR(CORE1_EL2_END),
		MBTF_BMRKR_STR(CORE2_EL2_END),
		MBTF_BMRKR_STR(CORE3_EL2_END),
		MBTF_BMRKR_STR(CORE1_EL1_STARTS),
		MBTF_BMRKR_STR(CORE2_EL1_STARTS),
		MBTF_BMRKR_STR(CORE3_EL1_STARTS),
		MBTF_BMRKR_STR(CORE0_EL1_LOAD_START),
		MBTF_BMRKR_STR(CORE0_EL1_LOAD_END),
		MBTF_BMRKR_STR(SBL_END),
		MBTF_BMRKR_STR(CORE0_EL2_END),
		MBTF_BMRKR_STR(CORE0_EL1_STARTS),
		MBTF_BMRKR_STR(CORE1_HLOS_KERNEL_START),
		MBTF_BMRKR_STR(CORE2_HLOS_KERNEL_START),
		MBTF_BMRKR_STR(CORE3_HLOS_KERNEL_START),
		MBTF_BMRKR_STR(CORE0_HLOS_KERNEL_START),
		MBTF_BMRKR_STR(SAIL_CAN_READY),
		MBTF_BMRKR_STR(SAIL_DDR_READY),
		MBTF_BMRKR_STR(SAIL_TZ_READY),
		MBTF_BMRKR_STR(SAIL_S1_READY),
	};

	uint8_t cnt = 0;
	do
	{
		DEBUG_LOG( SAIL_INFO,"B -  %-8llu  [c%u] %s\n\r", Tstamp[cnt], Tstamp_core[cnt], scMbtfsbmlist[cnt]);
		++cnt;
	}while(eSAIL_BSTAGE_MAX > cnt);

	return xRetStatus;
}




