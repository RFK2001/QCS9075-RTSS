
#ifndef __TESTS_H__
#define __TESTS_H__
/**
 * @file tests.h
 * @brief
 * Header file for testing modules
 *
 *        Copyright (c) Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
/*==========================================================================*/

#include <stdio.h>
#include "types.h"
#include "FreeRTOSOsal.h"
#include "freertos_init.h"
#include "common_functions.h"

#define TEST_FUNC  __attribute__ ( ( section ("test_func" ) ) )
#define TEST_DATA  __attribute__ ( ( section ("test_data" ) ) )
#define TEST_BSS  __attribute__ ( ( section ("test_bss" ) ) )

/*#define UNIT_TEST_EL1_DISABLED*/
/* ToDo: Macro will be removed once test is ported to EL1.
 * Enable the below command to execute test cases for image qualification*/
//#define SAIL_IMAGE_QUAL_TEST
#define TEST_GIC_ENABLE         0x0U
#define TEST_IPCC_ENABLE        0x0U
#define TEST_MEMHEAP_ENABLE     0x0U
#define TEST_ISD_ENABLE         0x0U

// #define VSENS_DRIVER_UNIT_TESTS

/* Flag to enable SPINOR Asynchronous tests */
#define SPINOR_ASYNC_TEST

#define ACMU_CLK_TEST 0xA
#define ACMU_PLL_TEST 0xB
#define ACMU_SW_FATAL_TEST 0xC
#define ACMU_CLK_INFO 0xD
typedef enum
{
    WDT_FAIL,
    WDT_PASS,
}WdtTest_StatusType_e;

typedef enum
{
    CORERESET_FAIL,
    CORERESET_PASS,
}CoreResetTest_StatusType_e;

typedef enum
{
    CLOCK_TEST_ID = 1,
    ACMU_TEST_ID,
    GPIO_TEST_ID,
    OSPINOR_TEST_ID,
    BIST_TEST_ID,
    OSPINOR_EL2_TEST_ID,
    OSPINOR_EL1_TEST_ID,
    GIC_TEST_ID,
    CRYPTO_SAIL_TEST_ID,
    HWKM_SAIL_TEST_ID,
	EL2_MPU_TEST_ID,
	SEC_SYSCALL_SAIL_TEST_ID,
    IPCC_TEST_ID,
    FUSA_TEST_ID,
    SAIL_MEMHEAP_TEST_ID,
    AC_SAIL_TEST_ID,
    TSENS_TEST_ID,
    CE_DMACRC_TEST_ID,
    PWR_CONTROLLER_TEST_ID,
    MD_PS_HOLD_TEST_ID,
	ISD_TEST_ID,
	CAN_TEST_ID,
	SPI_TEST_ID,
	CPR_TEST_ID,
    MAILBOX_TEST_ID,
    VSENS_TEST_ID,
    PMIC_TEST_ID,
    I2C_TEST_ID,
	EXIT,
	HELP,
	RD,
	WR,
	DHT_ID,
	LOGCODE_TEST_ID,
	TRUSENS_TEST_ID,
    EMAC_TEST_ID,
	QFPROM_TEST_ID,
	MAX_TEST_ID = 255
}TestIDType;

typedef enum
{
    MODULE_TEST_PASSED,
    MODULE_TEST_FAILED,
    MODULE_TEST_INVALID,
}TESTerrorType_e;

typedef enum
{
	CX = 3,
    MX = 4,
}PmicRailType;

typedef enum
{
	DVTASK_STOPPED = 0,
	DVTASK_STARTED,
	DVTASK_RUNNING,
	DVTASK_FAILED,
}DVtaskStatusType;

typedef enum
{
	UARTFRAMEWORK,
	MBFRAMEWORK,
	DVFRAMEWORK,
}TestCaseType;

typedef uint8 t_eTestMode;
typedef uint8 t_eRWStatus;
#define HAL_SAIL_BUFF_WR	    0U
#define HAL_SAIL_BUFF_RD	    1U
#define HAL_SAIL_BUFF_RD_WR_OFF	2U

#define HAL_SAIL_TEST_ON	1U
#define HAL_SAIL_TEST_OFF	2U

#define HAL_SAIL_TEST_RXBUFF_SIZE  	255U
#define HAL_SAIL_TEST_CR_KEY	  	13U

#define DVTASK_All_TESTCASE_PASSED  (255U)
/* IPCC Signal Ids for Internal mailbox*/
#define UartTestSIGID                30U
/*
typedef enum
{
    ACMU_TEST_ID,
}TestIDType;
*/


extern QueueHandle_t xSMTest1QueueHandle;
extern TESTerrorType_e xTestSPIWrapper(void);
extern volatile uint64 startTime[12];
extern TESTerrorType_e xTestUARTWrapper(void);
extern TESTerrorType_e xTestUartLoglevelWrapper(uint8* databuff);
extern uint8* APPL_SAIL_Shell_gettoken(uint8* str);
extern uint8 APPL_SAIL_Shell_stricmp(char const *str1, char const *str2);
extern void vTestModuleInit ( void );
extern TESTerrorType_e xTestModule ( TestIDType xTestId );
extern TESTerrorType_e xTestACMUWrappper( uint32_t ulTestId );
extern TESTerrorType_e xTestACMUFttiInject( uint32_t ulTestId );
extern int xTestClockHVCWrappper(void);  
extern TESTerrorType_e xTestFUSAWrapper(void);
extern TESTerrorType_e vFusaErrCntWrapper(void);
extern TESTerrorType_e xTestSPIWrapper(void);
extern TESTerrorType_e xTestSpinorEL2WrapperFromSW1(void);
extern TESTerrorType_e xTestQFPROMEL2WrapperFromSW1(void);
extern TESTerrorType_e TestOSPINOR_El1_Wrapper(void);
extern TESTerrorType_e xTestGPIOWrappper( void );
TEST_FUNC BaseType_t xSAILAPPLShellTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  xTaskPrior  );
extern BaseType_t xFusaSMTaskInit( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior );
 TEST_FUNC BaseType_t xAPPLShellTaskRTOSFeatureInit( CPUIdType_e           xSchdCore );
TEST_FUNC BaseType_t xSAILAPPLShellTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  xTaskPrior  );
TEST_FUNC BaseType_t xSAILConsoleUartTaskRTOSFeatureInit( CPUIdType_e           xSchdCore);
TEST_FUNC BaseType_t xSAILConsoleUartTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  xTaskPrior  );
TEST_FUNC BaseType_t xMBTestTaskRTOSFeatureInit( CPUIdType_e           xSchdCore);
TEST_FUNC BaseType_t xSAILMBTestTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  xTaskPrior  );
TEST_FUNC BaseType_t xDVTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  xTaskPrior  );
TEST_FUNC BaseType_t xDVTaskRTOSFeatureInit( CPUIdType_e           xSchdCore);
extern TESTerrorType_e xTestPmicWrapper(void);
extern TESTerrorType_e xTestSleepWrapper(void);
extern TESTerrorType_e xTestI2cWrapper(void);
extern TESTerrorType_e xTestI2cEl1Wrapper(void);
extern TESTerrorType_e xTestsLCWrappper( void );
extern TESTerrorType_e xTestsLCTstampWrappper( void );
extern TESTerrorType_e xLCTestWrappper( void );
extern TESTerrorType_e xTestVSENSWrappper( void );
extern TESTerrorType_e xTestIPCCWrapper(void);
extern TESTerrorType_e xTestWDT_El1_Wrapper(void);
extern TESTerrorType_e xTestWDTMBWrapper(uint8 *DataBuff , uint8 *ucLength);
extern TESTerrorType_e xTestSBIST_El1_Wrapper(void);
extern TESTerrorType_e xTestCoreResetMBWrapper(uint8 *DataBuff);
extern TESTerrorType_e xTestICBMBWrapper(uint8 *DataBuff , uint8 *ucLength);
extern TESTerrorType_e xTestSailUpdater_El1_Wrapper(void);
extern TESTerrorType_e xTestICB_El1_Wrapper(void);
extern TESTerrorType_e xTestSailUpdater_FastBootTest_Wrapper(void);
extern TESTerrorType_e HAL_SAIL_Test_GPIO(uint8* find);
TEST_FUNC TESTerrorType_e XTestGptWrapper(uint8 *find);
extern void xSailMemheapTestShell(uint8 *find);
TEST_FUNC TESTerrorType_e xFusaDVTestWrapper(void);
TEST_FUNC TESTerrorType_e xSPIDVTestWrapper(void);
extern TESTerrorType_e xSuwTestWrappper( void );
TEST_FUNC TESTerrorType_e xOSPINORDVTestWrapper(void);
TEST_FUNC TESTerrorType_e xACMUDVTestWrappper(void);
TEST_FUNC TESTerrorType_e xPMICDVTestWrapper(void);
TEST_FUNC TESTerrorType_e xTestPsailWrapper(void);
extern TESTerrorType_e xTestBootStatus_Wrapper(void);
TEST_FUNC void DebugPrint_DVTask(DVtaskStatusType DVTaskState, uint8 TestCase_ID);
TEST_FUNC TESTerrorType_e xReadOutPsailLogs(uint8  PsailData[] , boolean bTypeOfCmd , uint8 *len );
extern void vSuspendSMTasks( void );
extern void vResumeSMTasks( void );

#if defined SST_SS_SRC || defined SST_SHE_SRC 
#ifdef SAILSW1
extern TESTerrorType_e xTestSSTSW1Wrapper(void);
#endif /* SAILSW1 */
#endif /* SST_SS_SRC, SST_SHE_SRC */
#if defined SST_PRNG_SRC || defined SST_GPCE_SRC || defined SST_PKE_SRC || defined SST_SECBOOT_SRC 
#ifdef SAILSW2
extern TESTerrorType_e xTestSSTSW2Wrapper(void);
#endif /* SAILSW2 */
#endif /* SST_PRNG_SRC, SST_GPCE_SRC, SST_PKE_SRC, SST_SECBOOT_SRC */

extern TESTerrorType_e xTestDTS_QUP_Wrapper(void);
extern TESTerrorType_e xTRUSENSTestWrappper( void );
extern void xTestTrusensEL2WrapperHvcCallFromSW3( void );
extern TESTerrorType_e xTestCANWrappper(void);
extern TESTerrorType_e can_mcal_test(char *cmd);
extern TESTerrorType_e xTestCEDMACRCWrappper(uint8 test_id);

extern BaseType_t xSAILAPPLShellTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  xTaskPrior  ) ;

extern TESTerrorType_e emac_aux_test(uint8 *pRxCmd);
extern TESTerrorType_e tsc_api_test(uint8 *pRxCmd);
TEST_FUNC TESTerrorType_e xTestOsalWrapper( void );
TEST_FUNC TESTerrorType_e xTestTSENSWrappper(void);
TEST_FUNC TESTerrorType_e xTestSafeRTOSWrapper(void);
TEST_FUNC TESTerrorType_e xTestReadCxVoltWrapper(void);
TEST_FUNC WdtTest_StatusType_e vWDTTestFunctionality(void);
TEST_FUNC TESTerrorType_e x_TestCrashdbg_El1_Wrapper(void);
TEST_FUNC TESTerrorType_e TestBISTWrapper(void);
TEST_FUNC TESTerrorType_e xTestACWrapper( void );
TEST_FUNC TESTerrorType_e xTestGICWrapper(void);
TEST_FUNC TESTerrorType_e xTestMDPSHoldWrappper( void );
TEST_FUNC TESTerrorType_e xTestISDWrapper(void);
TEST_FUNC TESTerrorType_e xTestCPRWrapper( void );
TEST_FUNC TESTerrorType_e TestHWKMWrapper(void);
TEST_FUNC TESTerrorType_e xTestVSENSWrappper( void );
TEST_FUNC TESTerrorType_e xTestEnableVSENSWrappper( void );
TEST_FUNC TESTerrorType_e xVSENSGetSensorVolt( char * controller_type, uint32 ulSensorID );
TEST_FUNC TESTerrorType_e xTestOSALMutexWrappper( uint8 tcid);
TEST_FUNC TESTerrorType_e xTestBootStatus_Wrapper(void);
TEST_FUNC TESTerrorType_e xTestSecuritySecboot_El1_Wrapper(void);
TEST_FUNC TESTerrorType_e xTestTRUSENSWrappper( void );
TEST_FUNC TESTerrorType_e xTestTsEl1Cc( void );
TEST_FUNC TESTerrorType_e xTestDTS_QUP_Wrapper(void);
TEST_FUNC TESTerrorType_e xTestCEDMACRCWrappper(uint8 test_id);
TEST_FUNC TESTerrorType_e xTestPmicMBWrapper(uint32 Cx_Mx, uint64 Abs_volt_lower, uint64 Abs_volt_higher , uint32 up_down , uint8 *DataBuff , uint8 *ucLength) ;
TEST_FUNC TESTerrorType_e xTestTimeWrapper(void);
TEST_FUNC static TESTerrorType_e prvPmiclogPrint(void);        
extern TESTerrorType_e xTestMBWrapper(void);
TEST_FUNC TESTerrorType_e xTestSailGPIOTSMBWrapper(uint8 test_id);
extern TESTerrorType_e eSAILFSTestsWrapper(void);
extern TESTerrorType_e eSAILFSCatCmdWrapper(void);
extern TESTerrorType_e eSAILFSMBTFTestsWrapper(uint8 test_type, uint8 testcase_num);
extern TESTerrorType_e eXBLTestWrapper(void);
extern BaseType_t xCreateQueue( CPUIdType_e           xSchdCore );
extern BaseType_t xCreateQueue1( CPUIdType_e           xSchdCore );
#ifdef SPINOR_ASYNC_TEST
BaseType_t xSpinorEL1TestHiTaskInit(CPUIdType_e  xSchdCore, UBaseType_t  xTaskPrior);
BaseType_t xSpinorEl1TestTaskHiResourceInit(CPUIdType_e xSchdCore);
BaseType_t xSpinorEL1TestLoTaskInit(CPUIdType_e  xSchdCore, UBaseType_t  xTaskPrior);
BaseType_t xSpinorEl1TestTaskLoResourceInit(CPUIdType_e xSchdCore);
#endif

#ifdef SECURE_STORAGE_TEST
extern TESTerrorType_e xSecureStorageTestWrapper(void);
#endif

#endif //__TESTS_H__
