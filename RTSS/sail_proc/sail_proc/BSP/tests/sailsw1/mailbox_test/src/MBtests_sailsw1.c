/**
 * @file MBtests_sailsw1.c
 * @brief
 * Source file for mialbox test framework
 *
 *        Copyright (c) 2021-24 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
/*==========================================================================*/


/*============================================================================
 * Include Files
 *============================================================================*/
#include <stdio.h>
#include "debug_log.h"
#include "tests.h"
#include "uart.h"
//#include "tsens_api.h"
//#include "tsens_test_framework_api.h"
//#include "mailboxInt_api.h"
#include "mailboxExt_api.h"
#include "sail_security_control_hwio.h"
#include "IPCC.h"
#include "freertos_init.h"
#include "FreeRTOSConfig.h"
//#include "fusa.h"
#include "msmhwiobase.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "sail_csr_hwio.h"
#include "gpio.h"
//#include "emac_api_task.h"
#include "common_functions.h"
#include "types.h"      
#include "sail_pwr_cntrl_hwio.h"  
#include "version.h"
#include "logcode.h"
#include "Crashdbg_api.h"
#include "tests_sailsw1.h"
#include "sail_pwr_cntrl_hwio.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "mailboxExt_api.h"
#include "FreeRTOS.h"
#include "tests_sailsw1.h"


#if __has_include("dma_crc.h")
	#include "dma_crc.h"
#endif

/** 
 * uncomment MBTF_LFS_PARASOFTCC_FILERD_EN macro to read parasoft CC file.
 * uncomment MBTF_LFS_FILERD_DEMO_EN macro to test user build with demo file read code
 * before proceding to parasoft library integration.
 * 1. before using above macros make sure LFS component compilation enabled in build. 
 * 2. lfs_port_init() and file creation , linking with parasoft object file should be done
 *     by user explictly
 */
 /* #define MBTF_LFS_FILERD_DEMO_EN */
 /* #define MBTF_LFS_PARASOFTCC_FILERD_EN */
#ifdef MBTF_LFS_PARASOFTCC_FILERD_EN
#include "lfs_port.h"
#endif
/*============================================================================
 *  Mailbox Test Suite Command Parsing Global Types and Macros.
 *============================================================================*/
typedef struct
{
	uint8 crc8;
	uint8 cmd;
	uint8 version;
	uint8 len;
	uint8 seq_no;
	uint8 msg_id;
	uint8 databuff[58U];
}xMBTestMsgType;

TaskHandle_t MD_test_handle;
#if 1
typedef enum
{
        /* follow naming convention : FUNCTIONLAITY_CORE[TX CORE NUMBER]_[RX CORE NUMBER] */
    SMFLT_CORE1_2 = 0,
    SMHLTH_CORE1_2,
    SMCFG_CORE1_2,
    SMSUBS_CORE1_2,
    TESTCH_CORE0_0,
    TESTCH_CORE0_1,
    TESTCH_CORE0_2,
    TESTCH_CORE1_0,
    TESTCH_CORE2_0,
    UARTTESTFRAME_CORE0_1,
    UARTTESTFRAME_CORE0_2,
    DVTASK_CORE0_1,
    DVTASK_CORE0_2,
    SLEEP_CORE0_0,
    SLEEP_CORE0_1,
    SLEEP_CORE0_2,
    SLEEP_CORE0_3,
    SMTST_CORE0_2,
    MBTF_COREX_0,
    MBTF_CORE0_1,
    MBTF_CORE0_2,
    AUX_CORE0_2,
    AUX_CORE2_0,
        /* IB mb new channel goes here .. */
        IB_CHAN_MAX,
}mailboxIBChannelType;
#endif
/* saildbg pkt info */
#define HAL_MBTF_VERSION		( 0x10 )
#define HAL_MBTF_MSG_HDR_SZ		( 6U )
#define HAL_MBTF_MSG_PAYLOAD_SZ	( 58U )
#define HAL_MBTF_MSG_SZ				( sizeof( xMBTestMsgType ) )
#define HAL_MBTF_CMD_TEST			( (uint8_t)0x30U )
#define HAL_MBTF_CMD_LOOPBACK_TEST	( (uint8_t)0x31U )
#define HAL_MBTF_CMD_QSAR			( (uint8_t)0x29U )
#define HAL_MBTF_MODULE_SEL_IDX				( 0x0U )
#define HAL_MBTF_MODULE_FTUTCT_SEL_IDX		( 0x1U )
#define HAL_MBTF_MODULE_RESULT_SEL_IDX		( 0x2U )
#define HAL_MBTF_XCORE_REPLY_FLAG			( 0xF7U)
#define HAL_MBTF_XCORE_NOREPLY_FLAG			( 0xFFU )

/* saildbg test type FT: functional , UT: Unit test, CT: Code Coverage */
#define HAL_MBTF_FT		( (uint8_t)0xF0U )
#define HAL_MBTF_UT		( (uint8_t)0xF1U )
#define HAL_MBTF_CT		( (uint8_t)0xF2U )

/* mbtf os task param sand resources */
#define freertosapiQUEUE_OVERHEAD_BYTES         ( 140U )
#define HAL_MBTF_MSG_Q_LEN		( 20U )
#define HAL_MBTF_MSG_Q_ITEM_SZ	( 64U )
#define HAL_MBTF_MSG_Q_BUFF_SZ	( ( HAL_MBTF_MSG_Q_LEN * HAL_MBTF_MSG_Q_ITEM_SZ ) + freertosapiQUEUE_OVERHEAD_BYTES )
#define HAL_MBTF_TASK_STACK_SZ	( 2048U )

/* saildbg test exec core identifier */
#define HAL_MBTF_CORE0		( 0U )
#define HAL_MBTF_CORE1		( 1U )
#define HAL_MBTF_CORE2		( 2U )
#define HAL_MBTF_CORE3		( 3U )
#define HAL_MBTF_CORE_MASK	( 0xFU )
#define HAL_MBTF_CORE_MAX 	( 4U ) 

/* saildbg test reseult reply msg aligned encoding */
#define HAL_MBTF_TEST_FAILED		( (uint8_t)0U )
#define HAL_MBTF_TEST_PASSED		( (uint8_t)1U )
#define HAL_MBTF_TEST_RUNNING		( (uint8_t)2U )
#define HAL_MBTF_TEST_STOPPED		( (uint8_t)3U )
#define HAL_MBTF_TEST_TIMEOUT		( (uint8_t)4U )
#define HAL_MBTF_TEST_NOTSUPPORTED	( (uint8_t)5U )



/* task cfg buffers */
TEST_DATA static StaticTask_t xMBTFTaskTCB = {0};
TEST_DATA static StackType_t xMBTFTaskStack[ HAL_MBTF_TASK_STACK_SZ ] __attribute__( ( aligned(MEM_ALIGNMENT_64) ) ) = { 0 };
#ifdef SAILSW1
TEST_DATA uint8_t xMBTestTaskQueueBuffer[ HAL_MBTF_MSG_Q_BUFF_SZ ] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
/* mbtf queue handle  */
TEST_DATA QueueHandle_t  xMBTestTaskQueueHandle = NULL;
TEST_DATA StaticQueue_t xMBTestTaskQueueBufferStatic;
#endif
TEST_DATA uint8_t xMBTFCoreXTaskQueueBuffer[ HAL_MBTF_MSG_Q_BUFF_SZ ] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
TEST_DATA StaticQueue_t xMBTFCoreXTaskQueueBufferStatic;
/* mbtf queue handle  */
TEST_DATA QueueHandle_t  xMBTFCoreXTaskQueueHandle = NULL;
/* mbtf other test dependencies  */
//extern DVtaskStatusType DVtaskStat;
//extern EventGroupHandle_t xEventGroupDVTest;
TEST_DATA uint8 Uart_Data_send[256U] = { 0U };
extern TESTerrorType_e Can_test_ret;
extern QueueHandle_t  xDDRMilestoneQHandle;
//extern BaseType_t SmMonitoring_Deinit(void);
/*============================================================================
 *  					Private APIs
 *============================================================================*/
TEST_FUNC portBASE_TYPE HAL_MBTF_SendMsgXCore(  uint32_t chan , xMBTestMsgType *pTxMsg );
TEST_FUNC portBASE_TYPE HAL_MBTF_RecMsgXCore( xMBTestMsgType *pTxMsg );
TEST_FUNC void HAL_MBTF_WaitForFreeItem( void );
TEST_FUNC portBASE_TYPE HAL_MBTF_SendResult( xMBTestMsgType *pTxMsg );
/*============================================================================
 *  					Global Vars and Declaration 
 *============================================================================*/
/*============================================================================
 *  Module Main Command and SubCommand Entries and mbtf test configuration
 *============================================================================*/
/*============================================================================
 *  Module Main Command and SubCommand Entries and mbtf test configuration
 *============================================================================*/
 /**
  * eMBTFTestIDn_t - component under test using MBTF( Mailbox test framwork )
  * Naming convention - eHAL_MBTF_<Module Name>_IDN
  */
/*  typedef enum 
 {
	eHAL_MBTF_UNK_IDN = 0,
	eHAL_MBTF_DV_IDN,
	eHAL_MBTF_TSENSE_IDN,
	eHAL_MBTF_EMAC_IDN,
	eHAL_MBTF_SMERROR_IDN,
	eHAL_MBTF_GPIO_IDN,
	eHAL_MBTF_LOGCODETS_IDN,
	eHAL_MBTF_PSAIL_IDN,
	eHAL_MBTF_ACMU_IDN,
	eHAL_MBTF_FUSA_IDN,
	eHAL_MBTF_SPI_IDN,
	eHAL_MBTF_CAN_IDN,
	eHAL_MBTF_VSENS_IDN,
	eHAL_MBTF_WDT_IDN,
	eHAL_MBTF_MAX_IDN
 }eMBTFTestIDn_t;
 
typedef uint8_t ucMBTFTestResult_t; */
 
/* Driver Test Record : on which test need to execute */
/* ucMBTFTestResult_t GaMBTFComponetstatus[ eHAL_MBTF_MAX_IDN ] =
{

}; */

/**
 *	Naming Convension for command entries 
 *	1. Main module branch selector command => 
 *		
 *	#define HAL_MBTF_CMD_<Module Name>	<Unique code get it from SAIL platform BSP team or refer saildbg conflunce page for unique code allocation>
 *	
 *	2. Module subtest commands for multiple functional test defined by module
 *		onwer as per usecase =>
 *		
 *	#define HAL_MBTF_SCMD<Test Number>_<Module Name>_<Functionlaity Name>
 *	
 *	e.g EMAC 
 *		
 *	ETH Main Command => HAL_MBTF_CMD_ETH
 *	ETH Subtest Command => HAL_MBTF_SCMD0_ETH_LINKSTATUS
 */
 
/** DV Task module dbg commands */
#define HAL_MBTF_CMD_DV						( (uint8_t)0xACU )
#define HAL_MBTF_SCMD0_DVTASK_START			( (uint8_t)0x01U )
#define HAL_MBTF_SCMD1_DVTASK_STOP			( (uint8_t)0x00U )
/** End DV Commands */

/** TSENSE module dbg commands */
#define HAL_MBTF_CMD_TSENS						( (uint8_t)0xAAU )
#define HAL_MBTF_SCMD0_TSENS_GET_TEMP			( (uint8_t)0x10U )
#define HAL_MBTF_SCMD0_TSENS_GET_NUM_SENSORS	( (uint8_t)0x13U )
/** End TSENSE Commands */

/** PMIC module dbg commands */
#define HAL_MBTF_CMD_PMIC					( (uint8_t)0xA6U )
#define HAL_MBTF_SCMD0_PMIC					( (uint8_t)0x01U )
/** End PMIC Commands */

/** MAC module dbg commands */
#define HAL_MBTF_CMD_ETH					( (uint8_t)0xB0U )
#define HAL_MBTF_SCMD0_ETH_LINKSTATUS		( (uint8_t)0x01U )
/** End EMAC Commands */

/** SMERROR module dbg commands */
#define HAL_MBTF_CMD_SMERROR		( (uint8_t)0xADU )
#define HAL_MBTF_SCMD0_SMERROR		( (uint8_t)0x01U )
#define HAL_MBTF_SCMD1_SMERROR		( (uint8_t)0x00U )
#define HAL_MBTF_SCMD2_SMERROR		( (uint8_t)0x02U )
/** End SMERROR Commands */

/** GPIO module dbg commands */
#define HAL_MBTF_CMD_GPIO			( (uint8_t)0xA4U )
/** End GPIO Commands */

/** I2C module dbg commands */
#define HAL_MBTF_CMD_I2C			( (uint8_t)0xA3U )
#define HAL_MBTF_SCMD0_I2C			( (uint8_t)0x01U )
/** End GPIO Commands */

/** LOGCODE module dbg commands */
#define HAL_MBTF_CMD_LOGCODETS		( (uint8_t)0xAEU )
#define HAL_MBTF_SCMD0_LOGCODETS	( (uint8_t)0x01U )
/** End LOGCODE Commands */

/** PSAIL module dbg commands */
#define HAL_MBTF_CMD_PSAIL			( (uint8_t)0xB1U )
#define HAL_MBTF_SCMD0_PSAIL		( (uint8_t)0x01U )
/** End PSAIL Commands */

/** VIP Data TX dbg commands */
#define HAL_MBTF_CMD_UART			( (uint8_t)0xA2U )
#define HAL_MBTF_SCMD0_UART			( (uint8_t)0x01U )
/** End WDT Commands */

/** ACMU dbg commands */
#define HAL_MBTF_CMD_ACMU			( (uint8_t)0xB2U )
#define HAL_MBTF_SCMD0_ACMU_CLK		( (uint8_t)0x0AU )
#define HAL_MBTF_SCMD1_ACMU_PLL		( (uint8_t)0x0BU )
/** End WDT Commands */

/** Fusa dbg commands */
#define HAL_MBTF_CMD_FUSA			( (uint8_t)0xA1U )
#define HAL_MBTF_SCMD0_FUSA			( (uint8_t)0x01U )
/** End Fusa Commands */

/** CAN dbg commands */
#define HAL_MBTF_CMD_CAN			( (uint8_t)0xA7U )
#define HAL_MBTF_SCMD0_CAN			( (uint8_t)0x01U )
/** End CAN Commands */

/** CRASHDEBUG dbg commands */
#define HAL_MBTF_CMD_CRASHDBG		( (uint8_t)0xA9U )
#define HAL_MBTF_SCMD0_CRASHDBG		( (uint8_t)0x01U )
/** End CRASHDEBUG Commands */

/** SPI dbg commands */
#define HAL_MBTF_CMD_SPI			( (uint8_t)0xA5U )
#define HAL_MBTF_SCMD0_SPI			( (uint8_t)0x01U )
/** End SPI Commands */

/** SPINOREL1 dbg commands */
#define HAL_MBTF_CMD_SPINOREL1		( (uint8_t)0xA0U )
#define HAL_MBTF_SCMD0_SPINOREL1	( (uint8_t)0x01U )
/** End SPINOREL1 Commands */

/** ICB dbg commands */
#define HAL_MBTF_CMD_ICB			( (uint8_t)0xCAU )
#define HAL_MBTF_test_ICB			( (uint8_t)0x01U )  
/** End ICB Commands */

/** WDT dbg commands */
#define HAL_MBTF_CMD_WDT			( (uint8_t)0xB4U )
#define HAL_MBTF_core0_WDT			( (uint8_t)0x00U ) 
#define HAL_MBTF_core1_WDT			( (uint8_t)0x01U ) 
#define HAL_MBTF_core2_WDT			( (uint8_t)0x02U ) 
/** End WDT Commands */

/** Core Reset dbg commands */
#define HAL_MBTF_CMD_CORE_RESET		( (uint8_t)0xB3U )
#define HAL_MBTF_core_reset			( (uint8_t)0x01U )
/** End Core Reset Commands */

/** CLOCK dbg commands */
#define HAL_MBTF_CMD_CLOCK			( (uint8_t)0xB5U )
#define HAL_MBTF_SCMD0_CLOCK		( (uint8_t)0x01U )
/** End CLOCK Commands */

/** BIST dbg commands */
#define HAL_MBTF_CMD_BIST			( (uint8_t)0xB6U )
#define HAL_MBTF_SCMD0_BIST			( (uint8_t)0x01U )
/** End BIST Commands */

/** IPCC dbg commands */
#define HAL_MBTF_CMD_IPCC			( (uint8_t)0xB7U )
#define HAL_MBTF_SCMD0_IPCC			( (uint8_t)0x01U )
/** End IPCC Commands */

/** AC dbg commands */
#define HAL_MBTF_CMD_AC				( (uint8_t)0xB8U )
#define HAL_MBTF_SCMD0_AC			( (uint8_t)0x01U )
/** End AC Commands */

/** HWKM dbg commands */
#define HAL_MBTF_CMD_HWKM			( (uint8_t)0xB9U )
#define HAL_MBTF_SCMD0_HWKM			( (uint8_t)0x01U )
/** End HWKM Commands */

/** GIC dbg commands */
#define HAL_MBTF_CMD_GIC			( (uint8_t)0xBAU )
#define HAL_MBTF_SCMD0_GIC			( (uint8_t)0x01U )
/** End GIC Commands */

/** ISD dbg commands */
#define HAL_MBTF_CMD_ISD			( (uint8_t)0xBCU )
#define HAL_MBTF_SCMD0_ISD			( (uint8_t)0x01U )
/** End ISD Commands */
  
/** MDPSHOLD dbg commands */
#define HAL_MBTF_CMD_MDPSHOLD		( (uint8_t)0xBDU )
#define HAL_MBTF_SCMD0_MDPSHOLD		( (uint8_t)0x01U )
/** End MDPSHOLD Commands */

/** CPR dbg commands */
#define HAL_MBTF_CMD_CPR			( (uint8_t)0xBEU )
#define HAL_MBTF_SCMD0_CPR			( (uint8_t)0x01U )
/** End CPR Commands */

/** VSENS dbg commands */
#define HAL_MBTF_CMD_VSENS			( (uint8_t)0xABU )
#define HAL_MBTF_SCMD0_VSENS		( (uint8_t)0x01U )
/** End VSENS Commands */

/** OSAL dbg commands */
#define HAL_MBTF_CMD_OSAL			( (uint8_t)0xAFU )
#define HAL_MBTF_SCMD0_OSAL			( (uint8_t)0x01U )
/** End OSAL Commands */

/** Internal Mailbox dbg commands */
#define HAL_MBTF_CMD_IBMAILBOX		( (uint8_t)0xA8U )
#define HAL_MBTF_SCMD0_IBMAILBOX	( (uint8_t)0x01U )
/** End Internal Mailbox Commands */

/** TRUSENS dbg commands */
#define HAL_MBTF_CMD_TRUSENS		( (uint8_t)0xC0U )
#define HAL_MBTF_SCMD0_TRUSENS		( (uint8_t)0x01U )
/** End TRUSENS Commands */

/** SPINOREL2 dbg commands */
#define HAL_MBTF_CMD_SPINOREL2		( (uint8_t)0xC1U )
#define HAL_MBTF_SCMD0_SPINOREL2	( (uint8_t)0x01U )
/** End SPINOREL2 Commands */

/** SecuritySecBoot dbg commands */
#define HAL_MBTF_CMD_SECURITYSECBOOT 	( (uint8_t)0xC2U )
#define HAL_MBTF_SCMD0_SECURITYSECBOOT	( (uint8_t)0x01U )
/** End SecuritySecBoot Commands */

/** BootStatus dbg commands */
#define HAL_MBTF_CMD_BOOTSTATUS		 ( (uint8_t)0xC3U )
#define HAL_MBTF_SCMD0_BOOTSTATUS	 ( (uint8_t)0x01U )
/** End BootStatus Commands */

/** DTSQUP dbg commands */
#define HAL_MBTF_CMD_DTSQUP	 		 ( (uint8_t)0xC4U )
#define HAL_MBTF_SCMD0_DTSQUP		 ( (uint8_t)0x01U )
/** End DTSQUP Commands */

/** DMACRC dbg commands */
#define HAL_MBTF_CMD_DMACRC	 		 ( (uint8_t)0xC5U )
#define HAL_MBTF_SCMD0_DMACRC		 ( (uint8_t)0x01U )
/** End DMACRC Commands */

/** TIME dbg commands */
#define HAL_MBTF_CMD_TIME		 	 ( (uint8_t)0xC7U )
#define HAL_MBTF_SCMD0_TIME			 ( (uint8_t)0x01U )
/** End TIME Commands */

/** LFS file upload command */
#define HAL_MBTF_CMD_LFS			( (uint8_t)0xC6 )
#define HAL_MBTF_SCMD0_LFS_CC		( (uint8_t)0x01 )
/** End LFS Commands */

/** GET SAIL VERSION command */
#define HAL_MBTF_CMD_SAILVERSION	( (uint8_t)0xC8 )
#define HAL_MBTF_SCMD0_SAILVERSION	( (uint8_t)0x01 )
/** End GET SAIL VERSION Commands */

/** I2CEL1 command */
#define HAL_MBTF_CMD_I2CEL1			( (uint8_t)0xC9 )
#define HAL_MBTF_SCMD0_I2CEL1		( (uint8_t)0x01 )
/** End I2CEL1 Commands */

/** QFPROM_EL1 command */
#define HAL_MBTF_CMD_QFPROM_EL1		( (uint8_t)0xD1 )
#define HAL_MBTF_SCMD0_QFPROM_EL1	( (uint8_t)0x01 )
/** End QFPROM_EL1 Commands */


/** SAIL_GPIO_TIME_SYNC module dbg commands */
#define HAL_MBTF_CMD_SAIL_GPIO_TS			( (uint8_t)0xD2U )
#define HAL_MBTF_SCMD0_SAIL_GPIO_TS			( (uint8_t)0x01U )
/** End SAIL_GPIO_TIME_SYNC Commands */

/** SAILFS command */
#define HAL_MBTF_CMD_SAILFS			( (uint8_t)0xD3 )
#define HAL_MBTF_SCMD0_SAILFS		( (uint8_t)0x01 )
/** End SAILFS Commands */

/** EXTMAILBOX command */
#define HAL_MBTF_CMD_EXTMAILBOX     ( (uint8_t)0xD4 )
#define HAL_MBTF_SCMD0_EXTMAILBOX   ( (uint8_t)0x01 )
/** End EXTMAILBOX Commands */


/** SSM command */
#define HAL_MBTF_CMD_SSM            ( (uint8_t)0xD5 )
#define HAL_MBTF_SCMD0_SSM   	    ( (uint8_t)0x01 )
/** End SSM Commands */

/** SAIL SPINOR backup logdump collect command */
#define HAL_MBTF_CMD_SPINOR_CRASHDUMP_RESTORE			( (uint8_t)0xD6 )
#define HAL_MBTF_SCMD0_LOGDUMP							( (uint8_t)0x01 )
#define HAL_MBTF_SCMD0_REGDUMP							( (uint8_t)0x02 )
/** End logdump collect Commands */

/** GET SAIL VERSION V2 command */
#define HAL_MBTF_CMD_SAILVERSION_V2	( (uint8_t)0xD7 )
#define HAL_MBTF_SCMD0_SAILVERSION_V2	( (uint8_t)0x01 )
/** End GET SAIL VERSION V2 Commands */

extern uint8 mbtf_result_length;
extern uint8 mbtf_result_databuff[58];
/*============================================================================
 *  						Module Test Wrapper APIs goes here  
 *============================================================================*/

TEST_FUNC BaseType_t HAL_MBTF_LogdumpRetrieveWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	uint32_t remaining_size = 0U;
	uint32_t fetch_address = 0U;
	uint16_t i = 0U;

	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* reply should zero, protocol - progresive file download */
		/* once module subcommand detected change status */
		if (HAL_MBTF_SCMD0_LOGDUMP ==  pRxMsg->databuff[2U])
		{
			/* Get start address and size of restored logdump */
			Crashdbg_getLogdumpRestoreInfo(&fetch_address, &remaining_size);
		}
		else if (HAL_MBTF_SCMD0_REGDUMP == pRxMsg->databuff[2U])
		{
			/* Get start address and size of restored regdump */
			Crashdbg_getRegdumpRestoreInfo(&fetch_address, &remaining_size);
		}
		else
		{
			/* invalid testcase */
		}

		if ((0U != fetch_address) && (0U != remaining_size))
		{
			/* divide total size into chunks of length HAL_MBTF_MSG_PAYLOAD_SZ and send chunks back to back*/
			for (i = (remaining_size/HAL_MBTF_MSG_PAYLOAD_SZ); i > 0; i--)
			{
				memcpy((void*)&pRxMsg->databuff[0], (void*)fetch_address, HAL_MBTF_MSG_PAYLOAD_SZ);
				pRxMsg->len = HAL_MBTF_MSG_PAYLOAD_SZ;
				xStatus = pdFAIL;
				if( pdPASS != HAL_MBTF_SendResult( pRxMsg ) )
				{
					break;
				}
				fetch_address += HAL_MBTF_MSG_PAYLOAD_SZ;
				remaining_size -= HAL_MBTF_MSG_PAYLOAD_SZ;
				HAL_MBTF_WaitForFreeItem();					
			}

			/* check if the above loop is broken */
			if (i > 0)
			{
				pRxMsg->len = 0U;
				DEBUG_LOG( SAIL_ERROR, "MBTF: restore dump data transfer incomplete\n\r");
				HAL_MBTF_WaitForFreeItem();
			}
			else
			{
				/* transfer remaining bytes, if total size is not a multiple of HAL_MBTF_MSG_PAYLOAD_SZ */
				if (remaining_size > 0)
				{
					memcpy((void*)&pRxMsg->databuff[0], (void*)fetch_address, remaining_size);
					pRxMsg->len = remaining_size;
					if( pdPASS != HAL_MBTF_SendResult( pRxMsg ) )
					{
						DEBUG_LOG( SAIL_ERROR, "MBTF: restore dump send result failed\n\r");
					}
					else
					{
						xStatus = pdPASS;
					}
					pRxMsg->len = 0U;
					HAL_MBTF_WaitForFreeItem();
				}
			}
		}
		else
		{
			DEBUG_LOG( SAIL_WARNING, "MBTF: restore dump data is not available\n\r");
			pRxMsg->len = 0U;
			xStatus = pdPASS;
		}
	}
	else
	{
		pRxMsg->len = 0U;
		xStatus = pdPASS;
	}
	#endif
	/* default value used by other core return */
    return xStatus;
}

/*============================================================================
 *  						LFS Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_LFSCCWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	#ifdef MBTF_LFS_PARASOFTCC_FILERD_EN
	lfs_t *g_lfs = NULL;
	lfs_file_t fd  = { 0 };
	int32_t nbytes = 0;
	int32_t g_fileSize = 0;
	#endif
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{	
		#ifdef MBTF_LFS_PARASOFTCC_FILERD_EN
		/* reply should zero, protocol - progresive file download */
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_LFS_CC ==  pRxMsg->databuff[2U] )
		{
			#ifdef MBTF_LFS_FILERD_DEMO_EN
			int retval = lfs_port_init();
			if( retval != 0)
			{
				DEBUG_LOG( SAIL_ERROR, "Port init failed, retval = %d\n\r", retval);
				while(1);
			} 
			#endif
			g_lfs = lfs_port_get_lfs();
			if( NULL == g_lfs )
			{
				pRxMsg->len = 0U;
				xStatus = pdFAIL;
				DEBUG_LOG( SAIL_ERROR, "MBTF: lfs_port_get_lfs() failed\n\r");
			}
			#ifdef MBTF_LFS_FILERD_DEMO_EN
			else if( 0 > (lfs_file_open( g_lfs, &fd, (void*)&pRxMsg->databuff[pRxMsg->len], LFS_O_RDWR | LFS_O_CREAT )))
			#else
			else if( 0 > (lfs_file_open( g_lfs, &fd, (void*)&pRxMsg->databuff[pRxMsg->len], LFS_O_RDONLY )))
			#endif
			{
				pRxMsg->len = 0U;
				xStatus = pdFAIL;
				DEBUG_LOG( SAIL_ERROR, "MBTF: lfs_file_open() failed\n\r");
			}
			else
			{
				pRxMsg->len = 0U;
				#ifdef MBTF_LFS_FILERD_DEMO_EN
				while( nbytes < 1024 )
				{
					nbytes += lfs_file_write( g_lfs, &fd, "abcdefghijklmnopqrstuvwxyz", 26 );
				}
				nbytes = 0;
				lfs_file_seek(g_lfs, &fd, 0, LFS_SEEK_SET);
				#endif
				g_fileSize = lfs_file_size( g_lfs, &fd );
				if(0 >= g_fileSize)
				{
					xStatus = pdFAIL;
					DEBUG_LOG( SAIL_ERROR, "MBTF: lfs_file_size():%d, failed\n\r", g_fileSize);
				}
				else
				{
					do 
					{
						nbytes = lfs_file_read( g_lfs, &fd, (void*)&pRxMsg->databuff[0], HAL_MBTF_MSG_PAYLOAD_SZ );
						if( 0 < nbytes )
						{
							xStatus = pdFAIL;
							pRxMsg->len = nbytes;
							if( pdPASS != HAL_MBTF_SendResult( pRxMsg ) )
							{
								DEBUG_LOG( SAIL_ERROR, "MBTF: send result failed\n\r");
							}
							HAL_MBTF_WaitForFreeItem();
						}
						else
						{
							(void)lfs_file_close(g_lfs, &fd);
							pRxMsg->len = 0U;
							xStatus = pdPASS;
							HAL_MBTF_WaitForFreeItem();
						}
					}while( pRxMsg->len > 0U );
					#ifdef MBTF_LFS_FILERD_DEMO_EN
					(void)lfs_port_deinit();
					#endif
				}
			}
		}
		else
		#endif
		{
			pRxMsg->len = 0U;
			xStatus = pdPASS;
		}
	}
	else
	{
		pRxMsg->len = 0U;
		xStatus = pdPASS;
	}
	#endif
	/* default value used by other core return */
    return xStatus;
}

/*============================================================================
 *  						TSENS Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_TsenseWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_TSENS != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_TSENS_GET_TEMP == pRxMsg->databuff[2U] )
		{	
			/* once module subcommand detected change status */
			if( (uint8_t)4U > pRxMsg->databuff[3U] )
			{
				pRxMsg->len = 4U;
				//pRxMsg->databuff[2U] = HAL_MBTF_TEST_RUNNING;
				uint32 ulSensorID = pRxMsg->databuff[3U];
				int8_t suSensorTemp = 0U;
				if ( true == bSailTsensGetPerSensorTempWrappper( ulSensorID , &suSensorTemp) )
				{
					DEBUG_LOG(SAIL_INFO,"Get Sensor Temperature Done: %d\n\r",suSensorTemp);
					pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
				}
				else
				{
					pRxMsg->databuff[2U] = HAL_MBTF_TEST_FAILED;
				}
				//1'b sign + 11'b data * 10
				if( suSensorTemp < 0 )
				{
					suSensorTemp *= -1;
					pRxMsg->len = 5U;
					pRxMsg->databuff[4U] = 0x1;
				}
				pRxMsg->databuff[3U] = (uint8_t)(suSensorTemp);
			}
			else
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
				pRxMsg->len = 3U;
			}
		}
		else if (HAL_MBTF_SCMD0_TSENS_GET_NUM_SENSORS == pRxMsg->databuff[2U] )
		{
			uint8_t pulTsensNumSensor = 0;
			pRxMsg->len = 4U;
			if (true == bSailTsensGetNumOfSensorWrappper( &pulTsensNumSensor))
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
				DEBUG_LOG(SAIL_INFO,"Number of Sensors: %d\n\r",pulTsensNumSensor);
			}
			else
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Number of Sensors: FAILED %d\n\r");
			}
			pRxMsg->databuff[3U] = pulTsensNumSensor;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						DV Task Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_DVTaskWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{	
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_DVTASK_START ==  pRxMsg->databuff[2U] )
		{
			//pRxMsg->databuff[2U] = HAL_MBTF_TEST_RUNNING;
			pRxMsg->len = 3U;
			/* start DV */
			uint8_t DVTASK_STatus = 1;
            uint32_t xEventBitsToSet = 0x1;
		//	DVtaskStat = DVTASK_RUNNING;
       //     (void)xEventGroupSetBits( xEventGroupDVTest, xEventBitsToSet);
        //    (void)slMailboxIBSend( DVTASK_CORE0_1, 1,&DVTASK_STatus);
           // (void)slMailboxIBSend( DVTASK_CORE0_2, 1,&DVTASK_STatus);
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
		}
		else if( HAL_MBTF_SCMD1_DVTASK_STOP ==  pRxMsg->databuff[2U] )
		{
			//pRxMsg->databuff[2U] = HAL_MBTF_TEST_RUNNING;
			pRxMsg->len = 3U;
			/* stop DV */
			uint8_t DVTASK_STatus = 0;
			uint32_t  xEventBitsToSet = 0x1;
            //DVtaskStat = DVTASK_STOPPED;
			//DebugPrint_DVTask(DVTASK_STOPPED,DVTASK_All_TESTCASE_PASSED);
           // (void)slMailboxIBSend( DVTASK_CORE0_1, 1,&DVTASK_STatus);
          //  (void)slMailboxIBSend( DVTASK_CORE0_2, 1,&DVTASK_STatus);
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED; /* ignore any status update might fail robo framework */
		}
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	#endif
	/* default value used by other core return */
    return xStatus;
}
/*============================================================================
 *  						SM ERROR Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_SMERRORWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_SMERROR != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_SMERROR == pRxMsg->databuff[2U] )
		{	
			/* once module subcommand detected change status */
			AssertSMErr(1,0,fusa_DEFAULT_ERR_ID);
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
			pRxMsg->databuff[3U] = 0x1;
		}
		else if( HAL_MBTF_SCMD1_SMERROR == pRxMsg->databuff[2U] )
		{
			/* once module subcommand detected change status */
			//pRxMsg->databuff[2U] = HAL_MBTF_TEST_RUNNING;
			AssertSMErr(0,0, fusa_DEFAULT_ERR_ID);
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
			pRxMsg->databuff[3U] = 0x1;
		}
		else if( HAL_MBTF_SCMD2_SMERROR == pRxMsg->databuff[2U] )
		{
			//pRxMsg->databuff[2U] = HAL_MBTF_TEST_RUNNING;
			uint32_t SM_ERR_Status = REG_IN(SAILSS_CSR_SAILSS_CSR_BASE, SAILSS_CSR_SM_ERROR_STATUS);
            if ( (SM_ERR_Status & 0x3U ) == 0x01U )
            {
            	pRxMsg->databuff[3U]  = (uint8)0x0U;
            }
            if ( (SM_ERR_Status & 0x3U ) == 0x02U )
            {
            	pRxMsg->databuff[3U]  = (uint8)0x1U;
            }
            pRxMsg->len = 4U;
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	/* default value used by other core return */
    return xStatus;
}
/*============================================================================
 *  						GPIO Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_GPIOWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		pRxMsg->databuff[3U]  = sail_gpio_ReadPin( pRxMsg->databuff[2U] );
		pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
		pRxMsg->len = 4U;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						UART or VIP Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_UARTWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_UART == pRxMsg->databuff[2U] )
		{	
			/* once module subcommand detected change status */
			if(pRxMsg->databuff[3] == (uint8)0x0)
            {
				uint32_t count = 0U;
				Uart_Data_send[0] = 2U;
            	for(count = 0; count< ( pRxMsg->len - 4U ); count++)
            	{
            	    Uart_Data_send[1U + count] = pRxMsg->databuff[count + 4U];
            	}
        //    	(void)slMailboxIBSend( DVTASK_CORE0_2, ( pRxMsg->len-4U+1U ), &Uart_Data_send[0U] );
				// ulUartWrite(1 , &Uart_Data_send[0], 255);
            	vTaskDelay(100U);
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
				pRxMsg->len = 3U;
            }
			else
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
			}
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	#endif
	/* default value used by other core return */
    return xStatus;
}
/*============================================================================
 *  						LOGCODE Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_LOGCODEWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	/* temp until LCT adds logger any new marker need to place as per its enum index defined in LCT lib */
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
	int nbytes = 0;
	int cnt = 0;
	uint64_t *Tstamp     = (uint64_t*)LOGCODE_TIMESTAMP_ADDR ;
	uint8_t *Tstamp_core = (uint8_t*)LOGCODE_TIMESTAMP_CORE_ADDR;
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if((HAL_MBTF_SCMD0_LOGCODETS == pRxMsg->databuff[2U]) \
			&& (1U == sailbsp_stricmp("sailbm.log", (void*)&pRxMsg->databuff[pRxMsg->len])))
		{
			cnt = 0;
			// get bmetric log
			do
			{
				nbytes = snprintf( (void*)&pRxMsg->databuff[0],
					                HAL_MBTF_MSG_PAYLOAD_SZ,
									"B -  %-8llu  [c%u] %s\n\r",
									Tstamp[cnt], Tstamp_core[cnt], scMbtfsbmlist[cnt]);
				if( 0 < nbytes )
				{
					pRxMsg->len = nbytes;
					if( pdPASS != HAL_MBTF_SendResult( pRxMsg ) )
					{
						DEBUG_LOG( SAIL_ERROR, "MBTF: send result failed\n\r");
					}
					HAL_MBTF_WaitForFreeItem();
				}
				else
				{
					pRxMsg->len = 0U;
					HAL_MBTF_WaitForFreeItem();
				}
				++cnt;
			}while((eSAIL_BSTAGE_MAX > cnt) && (pRxMsg->len > 0U));
			HAL_MBTF_WaitForFreeItem();
		}
		else
		{
			pRxMsg->databuff[2U]  = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		pRxMsg->len = 0U;
		xStatus = pdPASS;
	}
	#endif
	/* default value used by other core return */
    return xStatus;
}

/*============================================================================
 *  						EMAC Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_EMACWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_ETH_LINKSTATUS == pRxMsg->databuff[2U] )
		{
			unsigned char  cpLinkStatus = 0U;
			//vEMAC0GetLinkStatus(&cpLinkStatus);       // Need to Enable
			pRxMsg->databuff[3U] = (uint8)cpLinkStatus;
			pRxMsg->databuff[2U]  = HAL_MBTF_TEST_PASSED;
			pRxMsg->len = 4U;	
		}
		else
		{
			pRxMsg->databuff[2U]  = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	#endif
	/* default value used by other core return */
    return xStatus;
}

/*============================================================================
 *  						PSAIL Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_PSAILWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_PSAIL != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_PSAIL == pRxMsg->databuff[2U] )
		{
			pRxMsg->databuff[2U] = (uint8) xReadOutPsailLogs( &pRxMsg->databuff[3U], 1U, &pRxMsg->len);
			pRxMsg->len += 3U;	
		}
		else
		{
			pRxMsg->databuff[2U]  = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	/* default value used by other core return */
    return xStatus;
}

/*============================================================================
 *  						ACMU Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_ACMUWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_ACMU != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_ACMU_CLK == pRxMsg->databuff[2U] )
		{	
			/* once module subcommand detected change status */
			/* need fix ret value */
			if ( MODULE_TEST_PASSED == xTestACMUWrappper( HAL_MBTF_SCMD0_ACMU_CLK ) )
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3U] = 0X1;
		}
		else if( HAL_MBTF_SCMD1_ACMU_PLL == pRxMsg->databuff[2U] )
		{	
			/* once module subcommand detected change status */
			/* need fix ret value */
			if (MODULE_TEST_PASSED == xTestACMUWrappper( HAL_MBTF_SCMD1_ACMU_PLL ))
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3U] = 0X1;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}

/*============================================================================
 *  						SSM Wrapper   
 *============================================================================*/

TEST_FUNC BaseType_t HAL_MBTF_SSMWrapper( xMBTestMsgType *pRxMsg )
{
    BaseType_t xStatus = pdFAIL;
    uint64 warm_boot_status = 0x0;

    /* sender doesnt have to modify or update X core msg 
                only verify correct msg received */
    #ifdef SAILSW1
	    if( NULL == pRxMsg )
	    {
	        xStatus = pdFAIL; 
	    }
	    else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	    {
	        xStatus = pdFAIL;
	    }
	    else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	    {
	        /* channces of interpreting incorrect result so blocking call */
	        xStatus = pdFAIL;
	    }
	    else if( HAL_MBTF_CMD_SSM != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	    {
	        /* test execution for current test failed cant proceed */
	        xStatus = pdFAIL;
	    }
	    else
	    {
	        xStatus = pdPASS;
	    }

	    warm_boot_status = in_dword(WARM_BOOT_STATUS);

	     if ( DEVICE_IS_IN_WARM_BOOT != warm_boot_status )
	     {
	     	HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE,3,0x40020005);
	     	HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE,2,0x40000005);
	     }

    #endif

    #ifdef SAILSW3
    if( NULL == pRxMsg )
    {
        xStatus = pdFAIL; 
    }
    else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
    {
        if( HAL_MBTF_SCMD0_SSM == pRxMsg->databuff[2U] )
        {

           SmMonitoring_Deinit();

            pRxMsg->databuff[3] = 0x1;
        }
        else
        {
            pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
        }
        xStatus = pdPASS;
    }
    else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
    {
        /* execute unit test cases of module */
        pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
        xStatus = pdPASS;
    }
    else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
    {
        /* execute coverage test cases of module */
        pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
        xStatus = pdPASS;
    }
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
    /* pack msg at after exec do not consider test result */
    if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
    {
        xStatus = pdFAIL;
    }
    else
    {
        xStatus = pdPASS;
    }
    #endif
    return xStatus;
}

/*============================================================================
 *  						ExtMailbox Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_ExtMailboxWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 

				only verify correct msg received */
        uint32_t usMsgDmSts = 0U;
        uint32 nCurrCPU = 0;

	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_EXTMAILBOX == pRxMsg->databuff[2U] )
		{
			
			pRxMsg->databuff[2U]  = HAL_MBTF_TEST_PASSED;
			pRxMsg->len = 3U;
			(void)eLogToMBSAILConsoleOff();
			usMsgDmSts = 0xD0030000U ;
			if( NULL != xDDRMilestoneQHandle )
			{
				BaseType_t return_check = pdFALSE;
			return_check = xFreeRTOSQueueSendFromISR( xDDRMilestoneQHandle, &usMsgDmSts);
				if (pdPASS == return_check )
				{
					portYIELD_FROM_ISR(pdTRUE);
				}
				else
				{
					DEBUG_LOG(SAIL_ERROR,"xDDRMilestoneQHandle ESEND:%d,%d\n\r", xStatus, nCurrCPU );
				}
			}
		}
	
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CMD_EXTMAILBOX != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	#endif
    return xStatus;
}


/*============================================================================
 *  						FUSA Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_FUSAWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_FUSA != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_FUSA == pRxMsg->databuff[2U] )
		{
			/* need fix ret value */
			if ( MODULE_TEST_PASSED == xTestFUSAWrapper())
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2U] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->databuff[3U] = 0x1;

			pRxMsg->len = 4U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */

		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						VSENS Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_VSENSWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_VSENS != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_VSENS == pRxMsg->databuff[2U] )
		{
		/* once module subcommand detected change status */
			if( MODULE_TEST_PASSED == xTestVSENSWrappper() )
			{  
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						I2C Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_I2CWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
#if defined(SAILSW1) || defined(SAILSW2) || defined(SAILSW)
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_I2C == pRxMsg->databuff[2U] )
		{
			if ( MODULE_TEST_PASSED == xTestI2cWrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
#endif 
    return xStatus;
}
/*============================================================================
 *  						GetSAILVersion Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_GetSAILVersionWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
				
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_SAILVERSION == pRxMsg->databuff[2U] )
		{
			DEBUG_LOG(SAIL_INFO,"SAIL image id: %s \n\r", SAIL_IMAGE_VERSION);
			pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	
    return xStatus;
}
/*============================================================================
 *  						PMIC Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_PMICWrapper( xMBTestMsgType *pRxMsg )
{
    BaseType_t xStatus = pdFAIL;
    /* sender doesnt have to modify or update X core msg 
                only verify correct msg received */
    #ifdef SAILSW1
    if( NULL == pRxMsg )
    {
        xStatus = pdFAIL; 
    }
    else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
    {
        xStatus = pdFAIL;
    }
    else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
    {
        /* channces of interpreting incorrect result so blocking call */
        xStatus = pdFAIL;
    }
    else if( HAL_MBTF_CMD_PMIC != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
    {
        /* test execution for current test failed cant proceed */
        xStatus = pdFAIL;
    }
    else
    {
        xStatus = pdPASS;
    }
    #endif

    #ifdef SAILSW3
    if( NULL == pRxMsg )
    {
        xStatus = pdFAIL; 
    }
    else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
    {
        if( HAL_MBTF_SCMD0_PMIC == pRxMsg->databuff[2U] )
        {
            /* once module subcommand detected change status */
            uint32 Cx_Mx, up_down;
			uint64 Abs_volt_lower,Abs_volt_higher; 

            Cx_Mx = pRxMsg->databuff[3];
            up_down = pRxMsg->databuff[4];
            Abs_volt_lower = pRxMsg->databuff[5];
            Abs_volt_higher = pRxMsg->databuff[6];
            pRxMsg->len = 4U;

            if ( MODULE_TEST_PASSED == xTestPmicMBWrapper(Cx_Mx,  Abs_volt_lower,Abs_volt_higher,  up_down, &pRxMsg->databuff[4U], &pRxMsg->len) )
            {
                pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
            }
            else
            {
                pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
            }
            pRxMsg->databuff[3] = 0x1;
        }
        else
        {
            pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
        }
        xStatus = pdPASS;
    }
    else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
    {
        /* execute unit test cases of module */
        pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
        xStatus = pdPASS;
    }
    else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
    {
        /* execute coverage test cases of module */
        pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
        xStatus = pdPASS;
    }
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
    /* pack msg at after exec do not consider test result */
    if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
    {
        xStatus = pdFAIL;
    }
    else
    {
        xStatus = pdPASS;
    }
    #endif
    return xStatus;
}
/*============================================================================
 *  						SAIL_GPIO_TIME_SYNC Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_SAIL_GPIO_TSWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_SAIL_GPIO_TS == pRxMsg->databuff[2U] )
		{
			/* once module subcommand detected */
			uint8 core_id;
			uint8 test_id;

			core_id = pRxMsg->databuff[3];
			test_id = pRxMsg->databuff[4];
			pRxMsg->len = 4U;

			if (core_id == 0x00)
			{
				#ifdef SAILSW1
//				if ( MODULE_TEST_PASSED == xTestSailGPIOTSMBWrapper(test_id) )
//				{
//					pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
//				}
//				else
//				{
//					pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
//				}
				pRxMsg->databuff[3] = 0x1;
				xStatus = pdPASS;
				#endif
			}
			else if (core_id == 0x01)
			{
				#ifndef SAILSW2
				if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_1, pRxMsg ) )
				{
					xStatus = pdFAIL;
				}
				else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
				{
					/* channces of interpreting incorrect result so blocking call */
					xStatus = pdFAIL;
				}
				else if( HAL_MBTF_CMD_SAIL_GPIO_TS != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
				{
					/* test execution for current test failed cant proceed */
					xStatus = pdFAIL;
				}
				else
				{
					xStatus = pdPASS;
				}
				return xStatus;	
				#endif
				#ifdef SAILSW2
				if ( MODULE_TEST_PASSED == xTestSailGPIOTSMBWrapper(test_id) )
				{
					pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
				}
				else
				{
					pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
				}
				pRxMsg->databuff[3] = 0x1;
				xStatus = pdPASS;
				#endif
			}
			else if (core_id == 0x02)
			{
				#ifndef SAILSW3
				if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
				{
					xStatus = pdFAIL;
				}
				else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
				{
					/* channces of interpreting incorrect result so blocking call */
					xStatus = pdFAIL;
				}
				else if( HAL_MBTF_CMD_SAIL_GPIO_TS != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
				{
					/* test execution for current test failed cant proceed */
					xStatus = pdFAIL;
				}
				else
				{
					xStatus = pdPASS;
				}
				return xStatus;
				#endif
				#ifdef SAILSW3
				if ( MODULE_TEST_PASSED == xTestSailGPIOTSMBWrapper(test_id) )
				{
					pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
				}
				else
				{
					pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
				}
				pRxMsg->databuff[3] = 0x1;
				xStatus = pdPASS;
				#endif
			}
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
			xStatus = pdPASS;
		}
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	if( NULL != pRxMsg )
	{
		if ( pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] == HAL_MBTF_TEST_NOTSUPPORTED )
		{
			pRxMsg->len = 3U; 
		}
		/* pack msg at after exec do not consider test result */
		if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
		{
			xStatus = pdFAIL;
		}
		else
		{
			xStatus = pdPASS;
		}
	}

    return xStatus;
}

/*============================================================================
 *  						CAN Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_CANWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_CAN != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
			/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_CAN == pRxMsg->databuff[2U] )
		{
			/*if (MODULE_TEST_PASSED == xTestCANWrappper())
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; */
			
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
			pRxMsg->len = 3U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						CRASHDEBUG Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_CrashDebugWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_CRASHDBG != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_CRASHDBG == pRxMsg->databuff[2U] )
		{
			/* once module subcommand detected change status */
			if( MODULE_TEST_PASSED == x_TestCrashdbg_El1_Wrapper())
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1;  
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						SPI Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_SPIWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_1, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_SPI != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW2 
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_SPI == pRxMsg->databuff[2U] )
		{
			/* once module subcommand detected change status */
			if ( MODULE_TEST_PASSED == xTestSPIWrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}

/*============================================================================
 *  						Core Reset Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_CoreResetWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */

#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
#endif

#ifdef SAILSW3
	uint8_t corereset_command = 0x0U;
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if(HAL_MBTF_core_reset == pRxMsg->databuff[3U] )
		{	
			corereset_command = pRxMsg->databuff[2];
			pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			xStatus = pdPASS;
		}
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}

		/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}

	// core2 have to reset the core2 after returning the result because core0 would crash hile MBTF is processing this test case
	if ( xStatus == pdPASS )
	{
		(void)xTestCoreResetMBWrapper(&corereset_command);
	}


#endif
    return xStatus;
}
/*============================================================================
 *  						WDT Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_WDTWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if(HAL_MBTF_core0_WDT == pRxMsg->databuff[3U] )
	{
	//	if ( MODULE_TEST_PASSED == xTestWDTMBWrapper(&pRxMsg->databuff[2U], &pRxMsg->len) )
	//	{
	//		pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
	//	}
	//	else
	//	{
	//		pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
	//	}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_core1_WDT == pRxMsg->databuff[3U] )
	{
		if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_1, pRxMsg ) )
		{
			xStatus = pdFAIL;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_core2_WDT == pRxMsg->databuff[3U] )
	{
		if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
		{
			xStatus = pdFAIL;
		}
		xStatus = pdPASS;
	}
#endif
	
#ifndef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if ( MODULE_TEST_PASSED == xTestWDTMBWrapper(&pRxMsg->databuff[2U], &pRxMsg->len) )
		{
			pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
		}
		else
		{
			pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
#endif
    return xStatus;
}
/*============================================================================
 *  						ICB Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_ICBWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */

#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if(HAL_MBTF_test_ICB == pRxMsg->databuff[3U] )
		{	
			if ( MODULE_TEST_PASSED == xTestICBMBWrapper(&pRxMsg->databuff[2U], &pRxMsg->len) )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
		}	
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}		
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}

		/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}

#endif
    return xStatus;
}
/*============================================================================
 *  						SPINOREL1 Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_SPINOREL1Wrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_SPINOREL1 == pRxMsg->databuff[2U] )
		{
			/* once module subcommand detected change status */
			if ( MODULE_TEST_PASSED == TestOSPINOR_El1_Wrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}	
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}		
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						SPINOREL2 Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_SPINOREL2FROMEL1Wrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_SPINOREL2 == pRxMsg->databuff[2U] )
		{
			/* once module subcommand detected change status */
			if ( MODULE_TEST_PASSED == xTestSpinorEL2WrapperFromSW1() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}		
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}		
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						CLOCK Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_CLOCKWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_CLOCK != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_CLOCK == pRxMsg->databuff[2U] )
		{
			/* once module subcommand detected change status */
			if ( MODULE_TEST_PASSED == xTestClockHVCWrappper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}	
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}			
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						BIST Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_BISTWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_BIST != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_BIST == pRxMsg->databuff[2U] )
		{
			/*if ( MODULE_TEST_PASSED == TestBISTWrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			} 
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1;*/
			
			pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
			pRxMsg->len = 3U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						IPCC Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_IPCCWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_IPCC != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_IPCC == pRxMsg->databuff[2U] )
		{
			/*if ( MODULE_TEST_PASSED == xTestIPCCWrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			} 
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; */
			
			pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
			pRxMsg->len = 3U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		/* once module subcommand detected change status */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						AC Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_ACWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_AC != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_AC == pRxMsg->databuff[2U] )
		{
			/*if ( MODULE_TEST_PASSED == xTestACWrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			} 
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; */
			
			pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
			pRxMsg->len = 3U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		} 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		/* once module subcommand detected change status */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						HWKM Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_HWKMWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_HWKM != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_HWKM == pRxMsg->databuff[2U] )
		{
			/*if ( MODULE_TEST_PASSED == TestHWKMWrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			} 
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1;*/
			pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
			pRxMsg->len = 3U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		} 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		/* once module subcommand detected change status */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						GIC Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_GICWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_GIC != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_GIC == pRxMsg->databuff[2U] )
		{
			/*if ( MODULE_TEST_PASSED == xTestGICWrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			} 
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1;*/
			
			pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
			pRxMsg->len = 3U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		} 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		/* once module subcommand detected change status */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						ISD Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_ISDWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_ISD != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_ISD == pRxMsg->databuff[2U] )
		{
			/*if ( MODULE_TEST_PASSED == xTestISDWrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; */
			
			pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
			pRxMsg->len = 3U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}

#if __has_include("ts_el1.h")
/*============================================================================
 *  						TRUSENS Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_TRUSENSWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_TRUSENS != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_TRUSENS == pRxMsg->databuff[2U] )
		{
			if ( MODULE_TEST_PASSED == xTestTRUSENSWrappper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
#endif /*__has_include*/

/*============================================================================
 *  						MDPSHOLD Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_MDPSHOLDWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_MDPSHOLD != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_MDPSHOLD == pRxMsg->databuff[2U] )
		{
			/*if ( MODULE_TEST_PASSED == xTestMDPSHoldWrappper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			} 
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; */
			
			pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
			pRxMsg->len = 3U;			
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						CPR Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_CPRWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_CPR != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_CPR == pRxMsg->databuff[2U] )
		{
			/* if ( MODULE_TEST_PASSED == xTestCPRWrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}  
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; */
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
			pRxMsg->len = 3U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		} 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						I2CEL1 Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_I2CEL1Wrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
#if defined(SAILSW1) || defined(SAILSW2) || defined(SAILSW)
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_I2CEL1 == pRxMsg->databuff[2U] )
		{
			if ( MODULE_TEST_PASSED == xTestI2cEl1Wrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}  
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		} 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
#endif 
    return xStatus;
}
/*============================================================================
 *  						QFPROM_EL1 Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_QFPROM_EL1Wrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
#if defined(SAILSW1) || defined(SAILSW2) || defined(SAILSW)
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_QFPROM_EL1 == pRxMsg->databuff[2U] )
		{
			/* if ( MODULE_TEST_PASSED == xTestQFPROMEL2WrapperFromSW1() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}  
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; */
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
			pRxMsg->len = 3U; 
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		} 
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
#endif
    return xStatus; 
}
/*============================================================================
 *  						DTSQUP Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_DTSQUPWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_DTSQUP != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_DTSQUP == pRxMsg->databuff[2U] )
		{
			if ( MODULE_TEST_PASSED == xTestDTS_QUP_Wrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			} 
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1;  
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}

#ifdef DMA_CRC_ENABLE

/*============================================================================
 *  						DMACRC Wrapper   
 *============================================================================*/
 
TEST_FUNC BaseType_t HAL_MBTF_DMACRCWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_DMACRC != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_DMACRC == pRxMsg->databuff[2U] )
		{
			if ( MODULE_TEST_PASSED == xTestCEDMACRCWrappper(0) )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			} 
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1;  
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
#endif

/*============================================================================
 *  						IBMailbox Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_IBMailboxWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_IBMAILBOX != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_IBMAILBOX == pRxMsg->databuff[2U] )
		{
			uint32_t res = 0;
			uint8 mailboxIntDataSend[64];
			uint8 mailboxIntDataReceive[64];
			for(uint8 count = 0;count<25;count++)
			{
				mailboxIntDataSend[count] = count;
			}
			mailboxIntDataSend[0] = 0xA1;
			mailboxIntDataSend[1] = 0xA2;
			mailboxIntDataSend[2] = 0xA3;
			mailboxIntDataSend[3] = 0xA4;
			mailboxIntDataSend[4] = 0xA5;

	//		(void)slMailboxIBSend( TESTCH_CORE0_0, 25, &mailboxIntDataSend[0]);
	//		(void)slMailboxIBSend( TESTCH_CORE0_1, 25, &mailboxIntDataSend[0]);
	//		(void)slMailboxIBSend( TESTCH_CORE0_2, 25, &mailboxIntDataSend[0]);
			DEBUG_LOG( SAIL_ERROR,"MailboxInt Send");  

			pRxMsg->databuff[2U] = HAL_MBTF_TEST_PASSED;
			pRxMsg->databuff[3U] = 0x1;
			pRxMsg->len = 4U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						OSAL Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_OSALWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_OSAL != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_OSAL == pRxMsg->databuff[2U] )
		{
			uint8 m_id = pRxMsg->databuff[3U];
			if ( MODULE_TEST_PASSED == xTestOSALMutexWrappper(m_id) )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}   
			pRxMsg->databuff[3U] = 0x1;
			pRxMsg->len = 4U;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						BootStatus Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_BootStatusWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_BOOTSTATUS != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_BOOTSTATUS == pRxMsg->databuff[2U] )
		{
			if ( MODULE_TEST_PASSED == xTestBootStatus_Wrapper() )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						SecuritySecBoot Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_SecuritySecBootWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		if( HAL_MBTF_SCMD0_SECURITYSECBOOT == pRxMsg->databuff[2U] )
		{
//			if ( MODULE_TEST_PASSED == xTestSecuritySecboot_El1_Wrapper() )
//			{
//				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
//			}
//			else
//			{
//				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
//			}
			DEBUG_LOG(SAIL_INFO,"Security Boot EL1 Wrapper\n\r");
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1;
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						Time Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_TimeWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_TIME != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_TIME == pRxMsg->databuff[2U] )
		{
			if ( MODULE_TEST_PASSED == xTestTimeWrapper())
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}

/*============================================================================
 *  						SAILFS Wrapper   
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_SAILFSWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
	/* sender doesnt have to modify or update X core msg 
				only verify correct msg received */
	#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_CORE0_2, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else if( pdPASS != HAL_MBTF_RecMsgXCore( pRxMsg ) )
	{
		/* channces of interpreting incorrect result so blocking call */
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_CMD_SAILFS != pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
	{
		/* test execution for current test failed cant proceed */
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
	
	#ifdef SAILSW3
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL; 
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* once module subcommand detected change status */
		if( HAL_MBTF_SCMD0_SAILFS == pRxMsg->databuff[2U] )
		{
			uint8 test_type, tc_num;
			test_type = pRxMsg->databuff[3U];
			tc_num = pRxMsg->databuff[4U];
			#ifdef SAILFS_INTERNAL_DRIVER_FLAG
			if ( MODULE_TEST_PASSED == eSAILFSMBTFTestsWrapper(test_type, tc_num) )
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_PASSED;
			}
			else
			{
				pRxMsg->databuff[2] = HAL_MBTF_TEST_FAILED;
			}
			#endif //	SAILFS_INTERNAL_DRIVER_FLAG
			pRxMsg->len = 4U;
			pRxMsg->databuff[3] = 0x1; 
		}
		else
		{
			pRxMsg->databuff[2U] = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_UT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute unit test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else if( HAL_MBTF_CT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{
		/* execute coverage test cases of module */
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED;
		xStatus = pdPASS;
	}
	else
	{
		pRxMsg->databuff[HAL_MBTF_MODULE_RESULT_SEL_IDX] = HAL_MBTF_TEST_NOTSUPPORTED; 
		xStatus = pdPASS;
		pRxMsg->len = 3U; 
	}
	/* pack msg at after exec do not consider test result */
	if( pdPASS != HAL_MBTF_SendMsgXCore( MBTF_COREX_0, pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		xStatus = pdPASS;
	}
	#endif
    return xStatus;
}
/*============================================================================
 *  						GetSAILVersion V2 Wrapper
 *============================================================================*/
TEST_FUNC BaseType_t HAL_MBTF_GetSAILVersionWrapper_V2( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdFAIL;
#ifdef SAILSW1
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL;
	}
	else if( HAL_MBTF_FT == pRxMsg->databuff[HAL_MBTF_MODULE_FTUTCT_SEL_IDX] )
	{

		int nbytes = 0;
		if((HAL_MBTF_SCMD0_SAILVERSION_V2 == pRxMsg->databuff[2U]) \
			&& (1U == sailbsp_stricmp("sailversion.log", (void*)&pRxMsg->databuff[pRxMsg->len])))
		{
			nbytes = snprintf( (void*)&pRxMsg->databuff[0], HAL_MBTF_MSG_PAYLOAD_SZ, "%s\n\r", SAIL_IMAGE_VERSION);
			if( 0 < nbytes )
			{
				pRxMsg->len = nbytes;
				if( pdPASS != HAL_MBTF_SendResult( pRxMsg ) )
				{
					DEBUG_LOG( SAIL_ERROR, "MBTF: send result failed\n\r");
				}
				HAL_MBTF_WaitForFreeItem();
			}
		}
		else
		{
			pRxMsg->databuff[2U]  = HAL_MBTF_TEST_NOTSUPPORTED;
		}
		pRxMsg->len = 0U;
		xStatus = pdPASS;
	}
#endif
	return xStatus;
}
/*============================================================================
 *  				MBTF Framework related APIs goes here 
 *============================================================================*/
#ifdef SAILSW1
TEST_FUNC void vMBTFCbk(xMailboxExtclienttype MBclient_ID)
{

	BaseType_t 	xQSendStatus = pdFAIL;
	int32 sllNumValidItemLoc;
	uint8 numofitemcount;
	xMBTestMsgType Databuff;
	DEBUG_LOG( SAIL_ERROR, "=====> vMBTFCbk callback called Databuff-:%d\n\r",Databuff.databuff);
    /* Get the number of valid item for the requested region*/
    sllNumValidItemLoc = slMailbox_Get_ValidItemNum(MBclient_ID);
    if(sllNumValidItemLoc>0)
    {
    	for(numofitemcount = 0; numofitemcount<sllNumValidItemLoc;numofitemcount++)
    	{
            if( slMailboxRead( MBclient_ID, 1, (uint8*)&Databuff) > 0 )
            {
            	BaseType_t Status = xFreeRTOSQueueSendFromISR( xMBTestTaskQueueHandle, &Databuff);
            }
    	}
    	portYIELD_FROM_ISR( pdTRUE );;
    }
}
#endif
TEST_FUNC void MBTF_IBCoreXCbk( xMailboxExtclienttype MBChannelId)
{
	xMBTestMsgType Databuff = { 0U };
	BaseType_t 	xQSendStatus = pdFAIL;
	int32 slNumValidItemLoc;
	slNumValidItemLoc = slMailbox_Get_ValidItemNum(MBChannelId);
	if(slNumValidItemLoc>0)
	{
		for( int32 numofitemcount = 0; numofitemcount<slNumValidItemLoc; numofitemcount++)
		{
			if( slMailboxRead( MBChannelId, 1U, (uint8*)&Databuff) > 0 )
			{
				BaseType_t xQSendStatus = xFreeRTOSQueueSendFromISR( xMBTFCoreXTaskQueueHandle, &Databuff);
				if(xQSendStatus == pdPASS)
				{
					portYIELD_FROM_ISR( pdTRUE );;
				}
				else
				{
					DEBUG_LOG(SAIL_ERROR, "vMBTF_IBCoreXCbk( ) msg send failed %d\n\r", xQSendStatus);
				}
			}
		}
	}
	return;
}

TEST_FUNC BaseType_t HAL_MBTF_SendMsgXCore(  uint32_t chan , xMBTestMsgType *pTxMsg )
{
	BaseType_t xStatus = pdFAIL;
//	(void)slMailboxIBChannelReg_V2( chan, MBIB_SENDER , NULL);
//	if ( ( slMailboxIBSend( chan, 1U, (void*)pTxMsg ) ) > 0 )
//	{
//		xStatus = pdPASS;
//	}
	return xStatus;
}

TEST_FUNC BaseType_t HAL_MBTF_RecMsgXCore( xMBTestMsgType *pMsgRx  )
{
	return ( xFreeRTOSQueueReceive( xMBTFCoreXTaskQueueHandle , pMsgRx, pdMS_TO_TICKS( portMAX_DELAY) ) );
}

TEST_FUNC BaseType_t HAL_MBTF_SendResult( xMBTestMsgType *pTxMsg )
{
	BaseType_t xStatus = pdPASS;
	if( NULL == pTxMsg )
	{
		xStatus = pdFAIL;
	}
	else if( ( slMailboxWrite( MAILBOX_HLOSTST, 1, ( void * )pTxMsg ) )  > 0 )
	{
		xStatus = pdPASS;
	}
	else
	{
		xStatus = pdFAIL;
	}
	return xStatus;
}

TEST_FUNC BaseType_t HAL_MBTF_LoopbackWrapper( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdPASS;
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL;
	}
    return xStatus;
}

TEST_FUNC void HAL_MBTF_WaitForFreeItem( void )
{
	while( 0 >= slMailbox_Get_FreeItemNum( MAILBOX_HLOSTST ) )
	{
		vTaskDelay(5U);
	}
	return;
}

TEST_FUNC BaseType_t HAL_MBTF_WaitforCmd(QueueHandle_t Qhandle, xMBTestMsgType *pRxMsg )
{
	return ( xFreeRTOSQueueReceive( Qhandle, pRxMsg, pdMS_TO_TICKS(portMAX_DELAY) ) );
}

TEST_FUNC BaseType_t HAL_MBTF_UpdateCRC( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdPASS;
	if( NULL == ( pRxMsg ) )
	{
		xStatus = pdFAIL;
		DEBUG_LOG( SAIL_ERROR, "HAL_MBTF_UpdateCRC() NULL IO\n\r");
	}
	else
	{
		// Calculate CRC and Update
		// update id, seq 
		pRxMsg->crc8 = (uint8_t)0xFFU;
	}
	return xStatus;
}

TEST_FUNC BaseType_t HAL_MBTF_VerifyCRC( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdPASS;
	if( NULL == ( pRxMsg ) )
	{
		xStatus = pdFAIL;
		DEBUG_LOG( SAIL_ERROR,"HAL_MBTF_VerifyCRC() NULL IO\n\r");
	}
	else
	{
		// verify CRC and Seq , ID 
	}
	return xStatus;
}

TEST_FUNC BaseType_t HAL_MBTF_ExecuteCmd( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdPASS;
	uint8 UartRxCmd[255]={0};
	if( NULL == ( pRxMsg ) )
	{
		xStatus = pdFAIL;
	}
	else
	{
		DEBUG_LOG( SAIL_ERROR,"----> pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] -:%d\n\r",pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX]);
		/* select requested module */
		switch ( pRxMsg->databuff[HAL_MBTF_MODULE_SEL_IDX] )
		{
			case HAL_MBTF_CMD_LFS:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_LFS;
					xStatus = HAL_MBTF_LFSCCWrapper( pRxMsg );
				}
				break;
			case HAL_MBTF_CMD_DV:
				{
					 pRxMsg->databuff[0] = HAL_MBTF_CMD_DV;
					xStatus = HAL_MBTF_DVTaskWrapper( pRxMsg );
				}
				break;
			case HAL_MBTF_CMD_TSENS:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_TSENS;
		//			xStatus = HAL_MBTF_TsenseWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_ETH:
				{ 
					pRxMsg->databuff[0] = HAL_MBTF_CMD_ETH;
					xStatus = HAL_MBTF_EMACWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_SMERROR:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_SMERROR;
					xStatus = HAL_MBTF_SMERRORWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_GPIO:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_GPIO;
					xStatus = HAL_MBTF_GPIOWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_LOGCODETS:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_LOGCODETS;
					xStatus = HAL_MBTF_LOGCODEWrapper( pRxMsg );
				}
				break;
			case HAL_MBTF_CMD_PSAIL:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_PSAIL;
					xStatus = HAL_MBTF_PSAILWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_UART:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_UART;
					xStatus = HAL_MBTF_UARTWrapper( pRxMsg );
				}
				break;
			case HAL_MBTF_CMD_ACMU:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_ACMU;
					xStatus = HAL_MBTF_ACMUWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_FUSA:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_FUSA;
					xStatus = HAL_MBTF_FUSAWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_PMIC:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_PMIC;
					xStatus = HAL_MBTF_PMICWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_SAIL_GPIO_TS:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_SAIL_GPIO_TS;
					xStatus = HAL_MBTF_SAIL_GPIO_TSWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_CAN:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_CAN;
					sailbsp_strlcpy((char *)UartRxCmd,(const char *)"can -t 0 -config 1",sizeof(UartRxCmd));
					DEBUG_LOG(SAIL_ERROR,"---> CAN case -:%s\n\r",(char*)UartRxCmd);
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,(const char *)"can -t 3 -c 0",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can-t 5 -c 0",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can -t 3 -c 1",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can-t 5 -c 1",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can -t 3 -c 2",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can-t 5 -c 2",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can -t 3 -c 3",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can-t 5 -c 3",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can -t 3 -c 4",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can-t 5 -c 4",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can -t 3 -c 5",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					if(Can_test_ret ==  MODULE_TEST_PASSED)
					{
					sailbsp_strlcpy((char *)UartRxCmd,"can-t 5 -c 5",sizeof(UartRxCmd));
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					}
					//xStatus = HAL_MBTF_CANWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_I2C:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_I2C;
					xStatus = HAL_MBTF_I2CWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_SAILVERSION:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_SAILVERSION;
					xStatus = HAL_MBTF_GetSAILVersionWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_CRASHDBG:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_CRASHDBG;
					xStatus = HAL_MBTF_CrashDebugWrapper( pRxMsg);
				}
				break;	
			case HAL_MBTF_CMD_SPI:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_SPI;
					sailbsp_strlcpy((char *)UartRxCmd,"spi",sizeof(UartRxCmd));
					DEBUG_LOG(SAIL_ERROR,"---> SPI case -:%d\n\r",(char*)UartRxCmd);
					APPL_SAIL_Shell_start(0,(uint8*)&UartRxCmd);
					//xStatus = HAL_MBTF_SPIWrapper( pRxMsg);
				}
				break;	
			case HAL_MBTF_CMD_WDT:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_WDT;
					xStatus = HAL_MBTF_WDTWrapper( pRxMsg);
				}
				break;	
			case HAL_MBTF_CMD_CORE_RESET:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_CORE_RESET;
					xStatus = HAL_MBTF_CoreResetWrapper( pRxMsg);
				}
				break;	
			case HAL_MBTF_CMD_ICB:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_ICB;
					xStatus = HAL_MBTF_ICBWrapper( pRxMsg);
				}
				break;				
			case HAL_MBTF_CMD_SPINOREL1:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_SPINOREL1;
					xStatus = HAL_MBTF_SPINOREL1Wrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_CLOCK:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_CLOCK;
					xStatus = HAL_MBTF_CLOCKWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_BIST:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_BIST;
					xStatus = HAL_MBTF_BISTWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_IPCC:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_IPCC;
					xStatus = HAL_MBTF_IPCCWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_AC:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_AC;
					xStatus = HAL_MBTF_ACWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_HWKM:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_HWKM;
					xStatus = HAL_MBTF_HWKMWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_GIC:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_GIC;
					xStatus = HAL_MBTF_GICWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_ISD:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_ISD;
					xStatus = HAL_MBTF_ISDWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_MDPSHOLD:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_MDPSHOLD;
					xStatus = HAL_MBTF_MDPSHOLDWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_CPR:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_CPR;
					xStatus = HAL_MBTF_CPRWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_VSENS:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_VSENS;
					xStatus = HAL_MBTF_VSENSWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_OSAL:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_OSAL;
					xStatus = HAL_MBTF_OSALWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_IBMAILBOX:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_IBMAILBOX;
					xStatus = HAL_MBTF_IBMailboxWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_TRUSENS:
				{
					#if __has_include("ts_el1.h")
					pRxMsg->databuff[0] = HAL_MBTF_CMD_TRUSENS;
					xStatus = HAL_MBTF_TRUSENSWrapper( pRxMsg);
					#else 
					DEBUG_LOG( SAIL_ERROR, "MBTF : Trusens not supported!.\n\r");
		            xStatus = pdFAIL;
		            #endif /*#if __has_include("ts_el1.h")*/
				}
				break;
			case HAL_MBTF_CMD_SPINOREL2:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_SPINOREL2;
					xStatus = HAL_MBTF_SPINOREL2FROMEL1Wrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_BOOTSTATUS:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_BOOTSTATUS;
					xStatus = HAL_MBTF_BootStatusWrapper( pRxMsg);
				}
				break;
			case HAL_MBTF_CMD_SECURITYSECBOOT:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_SECURITYSECBOOT;
					xStatus = HAL_MBTF_SecuritySecBootWrapper( pRxMsg);
				} 
				break;
			case HAL_MBTF_CMD_DTSQUP:
			{
				pRxMsg->databuff[0] = HAL_MBTF_CMD_DTSQUP;
				xStatus = HAL_MBTF_DTSQUPWrapper( pRxMsg);
			} 
			break;
			#ifdef DMA_CRC_ENABLE
			case HAL_MBTF_CMD_DMACRC:
			{
				pRxMsg->databuff[0] = HAL_MBTF_CMD_DMACRC;
				xStatus = HAL_MBTF_DMACRCWrapper( pRxMsg);
			} 
			break;
			#endif
			case HAL_MBTF_CMD_TIME:
			{
				pRxMsg->databuff[0] = HAL_MBTF_CMD_TIME;
				xStatus = HAL_MBTF_TimeWrapper( pRxMsg);
			} 
			break;	
			case HAL_MBTF_CMD_I2CEL1:
			{
				pRxMsg->databuff[0] = HAL_MBTF_CMD_I2CEL1;
				xStatus = HAL_MBTF_I2CEL1Wrapper( pRxMsg);
			} 
			break;	
			case HAL_MBTF_CMD_QFPROM_EL1:
			{
				pRxMsg->databuff[0] = HAL_MBTF_CMD_QFPROM_EL1;
				xStatus = HAL_MBTF_QFPROM_EL1Wrapper( pRxMsg);
			} 
			break;
			case HAL_MBTF_CMD_SAILFS:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_SAILFS;
					#ifdef SAILFS_INTERNAL_DRIVER_FLAG
					xStatus = HAL_MBTF_SAILFSWrapper( pRxMsg);
					#endif	//	SAILFS_INTERNAL_DRIVER_FLAG
				}
			break;
			case HAL_MBTF_CMD_SSM:
				{
					pRxMsg->databuff[0] = HAL_MBTF_CMD_SSM;
					xStatus = HAL_MBTF_SSMWrapper(pRxMsg);
				}
			break;
			case HAL_MBTF_CMD_EXTMAILBOX:
				{

					pRxMsg->databuff[0] = HAL_MBTF_CMD_EXTMAILBOX;
					xStatus = HAL_MBTF_ExtMailboxWrapper(pRxMsg);
				}
			break;
			case HAL_MBTF_CMD_SPINOR_CRASHDUMP_RESTORE:
			{
				pRxMsg->databuff[0] = HAL_MBTF_CMD_SPINOR_CRASHDUMP_RESTORE;
				xStatus = HAL_MBTF_LogdumpRetrieveWrapper(pRxMsg);
			}
			break;
			case HAL_MBTF_CMD_SAILVERSION_V2:
			{
				pRxMsg->databuff[0] = HAL_MBTF_CMD_SAILVERSION_V2;
				xStatus = HAL_MBTF_GetSAILVersionWrapper_V2( pRxMsg);
			}
			break;
			default:
				DEBUG_LOG( SAIL_ERROR, "MBTF : unknown cmd please try again!.\n\r");
			break;
		}	
	}
    return xStatus;
}

TEST_FUNC BaseType_t HAL_MBTF_ProcessCmd( xMBTestMsgType *pRxMsg )
{
	BaseType_t xStatus = pdPASS;
		DEBUG_LOG( SAIL_ERROR,"===> proccess cmd\n\r");
	if( NULL == pRxMsg )
	{
		xStatus = pdFAIL;	
	}
	else if( HAL_MBTF_CMD_LOOPBACK_TEST == pRxMsg->cmd )
	{
		/* mailbox end to end verification with all POSIX Async | sync notification and connectivity test  */
		xStatus = HAL_MBTF_LoopbackWrapper( pRxMsg );	
	}
	else if( HAL_MBTF_CMD_TEST == pRxMsg->cmd )
	{
		xStatus = HAL_MBTF_ExecuteCmd( pRxMsg );
	}
	else if(HAL_MBTF_CMD_QSAR == pRxMsg->cmd)
	{
		APPL_SAIL_Shell_start(TEST_FRAMEWORK_MB,&(pRxMsg->databuff[0]) );	
		pRxMsg->len = mbtf_result_length;
		for(int i=0;i<mbtf_result_length;i++)
		{
			pRxMsg->databuff[i] = mbtf_result_databuff[i];
		}
	}
	else
	{
		DEBUG_LOG( SAIL_ERROR,"MBTF : unknown cmd please try again!.\n\r");
	}
    return xStatus;
}

/* mbtf task */
TEST_FUNC void vSAILMBTesttask(void *pvParameters)
{
	( void ) pvParameters;
	BaseType_t xStatus = pdPASS;
	int32_t slSensorTemp = 0;
	/* default lock */
	xMBTestMsgType xMBTestRequestMsg;
	for( ; ; )
	{	
#ifdef SAILSW1
		xStatus = HAL_MBTF_WaitforCmd( xMBTestTaskQueueHandle, &xMBTestRequestMsg );
#else
		//   xStatus = HAL_MBTF_WaitforCmd( xMBTFCoreXTaskQueueHandle, &xMBTestRequestMsg );
#endif
		if( pdPASS != xStatus )
		{
			DEBUG_LOG( SAIL_ERROR, "MBTF: cmd wait error , %d\n\r", xStatus);
		}
#ifdef SAILSW1
		else if( pdPASS != HAL_MBTF_VerifyCRC( &xMBTestRequestMsg ) )
		{
			xStatus = pdFAIL;
			DEBUG_LOG( SAIL_ERROR, "MBTF: crc failed\n\r");
		}
#endif
		else if( pdPASS != HAL_MBTF_ProcessCmd( &xMBTestRequestMsg ) )
		{
			xStatus = pdFAIL;
			DEBUG_LOG( SAIL_ERROR, "MBTF: process cmd failed\n\r");
		}
#ifdef SAILSW1
		else if( pdPASS != HAL_MBTF_UpdateCRC( &xMBTestRequestMsg ) )
		{
			xStatus = pdFAIL;
			DEBUG_LOG( SAIL_ERROR, "MBTF: CRC update failed\n\r");
		}
#endif
		else
		{
			/* ok do nothing */
		}
		/* response always expected   */
#ifdef SAILSW1
		if( pdPASS != HAL_MBTF_SendResult( &xMBTestRequestMsg ) )
		{
			DEBUG_LOG( SAIL_ERROR, "MBTF: send result failed\n\r");
		}
		/* Resetting the buffer after the cmd execution is finished */
		memset(&xMBTestRequestMsg, 0, sizeof(xMBTestRequestMsg));
#endif
		/* response always expected   */
#ifndef SAILSW1
		if( xStatus == pdFAIL )
		{
			(void)HAL_MBTF_SendMsgXCore(  MBTF_COREX_0, &xMBTestRequestMsg );
		}
#endif
	}
}

#if 1
BaseType_t xSAILMBTestTaskInit( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior )
{
	BaseType_t xCreateResult;
	uint8 ulcpu_ID;
	UBaseType_t uxCoreAffinityMask;
	uxCoreAffinityMask = ( 1 << xSchdCore);
	/* Shell task param. */
	TaskParams_t xShellTaskParam = {
                .pvTaskCode     = vSAILMBTesttask,
                .pcName         = "vSAILMBTesttas",
                .usStackDepth   = HAL_MBTF_TASK_STACK_SZ,
                .pvParameters   = NULL,
                .uxPriority     = (xTaskPrior),
                .puxStackBuffer = xMBTFTaskStack,
                .xRegions               =       {
                        { NULL, 0UL, 0UL },
                        { NULL, 0UL, 0UL },
                        { NULL, 0UL, 0UL },
                        { NULL, 0UL, 0UL },
                        { NULL, 0UL, 0UL },
                        { NULL, 0UL, 0UL }
                },
                .pxTaskBuffer   = &xMBTFTaskTCB,
        };


	xCreateResult = xFreeRTOSTaskCreateAffinitySet( &xShellTaskParam, uxCoreAffinityMask,&MD_test_handle);

#ifdef SAILSW1
	(void)slMailboxClientReg( MAILBOX_HLOSTST, vMBTFCbk );
	//	(void)slMailboxIBChannelReg_V2( MBTF_COREX_0, MBIB_RECEIVER, vMBTF_IBCoreXCbk );
	//	(void)slMailboxIBChannelReg_V2( MBTF_CORE0_1, MBIB_SENDER , NULL);
	//	(void)slMailboxIBChannelReg_V2( MBTF_CORE0_2, MBIB_SENDER , NULL);
#endif

#ifdef SAILSW2
//	(void)slMailboxIBChannelReg_V2( MBTF_CORE0_1, MBIB_RECEIVER , vMBTF_IBCoreXCbk );
#endif

#ifdef SAILSW3
//	(void)slMailboxIBChannelReg_V2( MBTF_CORE0_2, MBIB_RECEIVER , vMBTF_IBCoreXCbk );
#endif

	if(xCreateResult != pdPASS)
	{
		xCreateResult = pdFAIL;
	} 
	return xCreateResult;
}
#endif 
TEST_FUNC BaseType_t xMBTestTaskRTOSFeatureInit( CPUIdType_e           xSchdCore)
                                         
{
	BaseType_t xCreateResult = pdPASS;
#ifdef SAILSW1
	xCreateResult = xFreeRTOSQueueCreate( xMBTestTaskQueueBuffer,
			HAL_MBTF_MSG_Q_BUFF_SZ,
			HAL_MBTF_MSG_Q_ITEM_SZ,
			&xMBTestTaskQueueHandle,&xMBTestTaskQueueBufferStatic );
	if( xCreateResult != pdPASS )
	{
		xCreateResult = pdFAIL;
	}
#endif
    //	xCreateResult = xFreeRTOSQueueCreate( xMBTFCoreXTaskQueueBuffer,
    //  		                     HAL_MBTF_MSG_Q_BUFF_SZ,
    //			                     HAL_MBTF_MSG_Q_ITEM_SZ,
    //                                &xMBTFCoreXTaskQueueHandle,&xMBTFCoreXTaskQueueBufferStatic );
    //   if( xCreateResult != pdPASS )
    //    {
    //        xCreateResult = pdFAIL;
    //    }

    return xCreateResult;      
}
/*============================================================================
 *  							MBTF EOF
 *============================================================================*/
