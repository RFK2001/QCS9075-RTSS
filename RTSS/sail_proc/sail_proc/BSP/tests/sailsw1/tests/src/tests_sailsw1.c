/**
 * @file tests.c
 * @brief
 * Source file for tests
 *
 *        Copyright (c) Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
/*==========================================================================*/


/*============================================================================
 * Include Files
 *============================================================================*/
#include <stdio.h>
#include <limits.h>
#include "debug_log.h"
#include "tests.h"
#include "uart.h"
#include "spi_test.h"
#include "sail_security_control_hwio.h"
#include "IPCC.h"
#include "common_functions.h"
#include "gpio.h"
#ifdef CPU_RUNTIME_STATISTICS_EN
#include "CPUruntimestats.h"
#endif
#include "chipinfo.h"
#include "md_sail_pm_defs.h"
#include "busywait.h"
//#include "isd_el1.h"
#include "tests.h"
#include "version.h"
#include "freertos_init.h"
#include "tests_sailsw1.h"
#include "Spi.h"
#include "tests.h"
#include "task.h"
#include "FreeRTOSOsal.h"

#if __has_include("dma_crc.h")
	#include "dma_crc.h"
#endif


/*============================================================================
  MACROS
  ============================================================================*/
#define shellTASK_STACK_SIZE 		             ( 4096U )
#define shellTASK_STACK_SIZE_second 		     ( 512U )
#define shellTASK_STACK_SIZE_third 		     ( 512U )
#define syscallTestTASK_STACK_SIZE 		     ( 512 )

#ifndef CORE0
#define CORE0                                      ( 0U )
#endif

#define BID_PASS 0x0042494450415353
#define BID_FAIL 0x004249444641494C
#define TASK_STACK_SIZE    ( 4096U )
#define TASK_STACK_SIZE_second    ( 4096U )

#define CHIPINFO_PARTNUM_SA_LEMANSAU_IVI       0x1CF
#define INT32_MIN_VALUE  (0x80000000U)
#define spiSEQ_Q_LEN            ( 10U )
#define spiQ_ITEM_SIZE        (sizeof(TestFramework_info))
#define spiQ_BUFFER_SIZE      ( spiSEQ_Q_LEN * spiQ_ITEM_SIZE )




/*============================================================================
  LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE
  ============================================================================*/

extern void APPL_SAIL_Shell_help(void);
extern void APPL_SAIL_Shell_reset(void);


static StackType_t xshellUARTTaskStack[TASK_STACK_SIZE]  __attribute__((aligned(MEM_ALIGNMENT_64))) = { 0 };
TaskHandle_t xSAILShellTaskHandle = NULL;
static StackType_t xshellUARTTaskStack1[TASK_STACK_SIZE_second]  __attribute__((aligned(MEM_ALIGNMENT_64))) = { 0 };
static StackType_t xshellUARTTaskStack2[TASK_STACK_SIZE_second]  __attribute__((aligned(MEM_ALIGNMENT_64))) = { 0 };

TaskHandle_t xTest_core1_TaskHandle = NULL;
TaskHandle_t xTest_core2_TaskHandle = NULL;


/* TODO : Remove in future */

uint8 mbtf_result_length = 0;

uint8 mbtf_result_databuff[MAX_BUFF_LENG];

TESTerrorType_e Can_test_ret; 

//#ifdef TEST_SRC_ENABLED
/*** Test Framework Resources ***/
typedef struct
{
	uint8 UartRxCmdIdx;
	t_eTestMode eTestMode;
    t_eRWStatus eFlushCmd;
}GstTestInfo;

/*** Test Chip Info ***/
typedef enum
{
	LEMANS_IVI = 0,
	LEMANS_ADAS,
}TestChipInfo;

typedef struct Rx_tokens
{
    uint8* NxtTknPtr;
}t_Gsttoken;

typedef enum
{
	CAN=0,
	SPI,
}Select_test_app;

/*typedef enum
{
  CORE_0 = 0,
  CORE_1,
  CORE_2,
  CORE_3,
}Select_core;*/

typedef struct test_framework
{
  uartInitializationCoreId_e core_info;
  Select_test_app test_app;
  volatile uint8 Rxqueue[HAL_SAIL_TEST_RXBUFF_SIZE];
}TestFramework_info;

TestFramework_info Test_app_info_send;
TestFramework_info Test_app_info_receive;

uint8 APPL_SAIL_Shell_getStringLength(uint8* str);
void converInttoASCII(uint32 Value);

TEST_DATA TestChipInfo ChipVersion;
typedef void (*UartTestFuncPtr) (IPCC_CBData nData, IPCC_Client eSenderID, IPCC_Signal nSignal);
TEST_DATA static t_Gsttoken tokeninfo;
TEST_DATA volatile GstTestInfo UartRxTestData;
TEST_DATA volatile uint8 UartRxCmd[HAL_SAIL_TEST_RXBUFF_SIZE];
TEST_DATA volatile uint8 UartRxCmdCpy[HAL_SAIL_TEST_RXBUFF_SIZE];
volatile uint8 Rxqueue[HAL_SAIL_TEST_RXBUFF_SIZE];
TEST_DATA TestIDType Active_testCaseID = MAX_TEST_ID;
TEST_DATA volatile uint8 UnitTestActive = 1U;


/*Mailbox IPCC handle*/
TEST_DATA static IPCC_Handle xUartTst_IpccHandle = NULL;

TEST_DATA static StaticTask_t xShellTaskTCB = {0};
// TEST_DATA static StackType_t xShellTaskStack[ shellTASK_STACK_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
    
TEST_DATA static StaticTask_t xSyscallTestTaskTCB = {0};
TEST_DATA static StaticTask_t xShellTaskTCB_core1 = {0};
TEST_DATA static StaticTask_t xShellTaskTCB_core2 = {0};

TEST_DATA static StackType_t xSyscallTestTaskStack[ syscallTestTASK_STACK_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };


TEST_FUNC static int test_myAtoi(const char* str);


TEST_DATA QueueHandle_t xSMTest1QueueHandle = NULL;


TEST_DATA TaskHandle_t xShellTaskHandle = NULL;


static StaticSemaphore_t xShellSemaphoreBuffer;
SemaphoreHandle_t xShellSemaphoreHandle = NULL;


uint8_t xTestSEQXFERQBuffer[ spiQ_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
uint8_t xQueue_handle_QBuffer_core2[ spiQ_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
QueueHandle_t xTestSEQXFERQHandle = NULL;
QueueHandle_t xQueue_handle_core2 = NULL;
StaticQueue_t xTestQueueBuffer;
StaticQueue_t xQueue_DS_core2;


TEST_FUNC BaseType_t xAPPLShellTaskRTOSFeatureInit( CPUIdType_e  xSchdCore)

{
	BaseType_t xCreateResult = pdPASS;
	BaseType_t xReturn1 = xFreeRTOSSemaphoreCreateBinary(&xShellSemaphoreBuffer,&xShellSemaphoreHandle);
	if( pdFALSE == xReturn1)
	{
		DEBUG_LOG( SAIL_WARNING, "SPI Callback Binary Semaphore Creation failed\n\r" );
		xCreateResult = pdFAIL;
	}else{
		if( xFreeRTOSSemaphoreGive (xShellSemaphoreHandle) != pdTRUE ){
			DEBUG_LOG(SAIL_WARNING,"[ UART test framework ] Semaphore GIVE failed\n\r");
		}else{
			DEBUG_LOG(SAIL_WARNING,"[ UART test framework]  Semaphore GIVE sucess\n\r");
		}

		xCreateResult = xFreeRTOSQueueCreate( xTestSEQXFERQBuffer,
				spiSEQ_Q_LEN,
				spiQ_ITEM_SIZE,
				&xTestSEQXFERQHandle,&xTestQueueBuffer );
		if( xCreateResult != pdPASS )
		{
			xCreateResult = pdFAIL;
		}
		xCreateResult = xFreeRTOSQueueCreate(xQueue_handle_QBuffer_core2,
				spiSEQ_Q_LEN,
				spiQ_ITEM_SIZE,
				&xQueue_handle_core2,&xQueue_DS_core2 );
		if( xCreateResult != pdPASS )
		{
			xCreateResult = pdFAIL;
		}

	}
	return xCreateResult;      
}



TEST_FUNC static void Test_SAIL_UART_Rx_Notification(volatile void *rslt)
{
	volatile uartJobHandleType *Uart_JobResult = (volatile uartJobHandleType *)rslt;
	BaseType_t xHigherPriorityTaskWoken=pdFALSE;
	if(Uart_JobResult->psRxBufferPtr != NULL)
	{
		switch(*(Uart_JobResult->psRxBufferPtr)){
		case HAL_SAIL_TEST_CR_KEY:
			if(UartRxTestData.eFlushCmd == HAL_SAIL_BUFF_WR)
			{
			    UartRxCmd[UartRxTestData.UartRxCmdIdx] = '\0';
				UartRxTestData.eFlushCmd = HAL_SAIL_BUFF_RD;
					BaseType_t xCreateResult \
					= xFreeRTOSSemaphoreGiveFromISR(xShellSemaphoreHandle,&xHigherPriorityTaskWoken );
					if(xCreateResult == pdPASS)
					{
						freertosYIELD_FROM_ISR( );
					}
			}
			break;
		default:
			if((UartRxTestData.UartRxCmdIdx < HAL_SAIL_TEST_RXBUFF_SIZE) && \
			  (UartRxTestData.eFlushCmd == HAL_SAIL_BUFF_WR))
			{
				UartRxCmd[UartRxTestData.UartRxCmdIdx] \
				= *(Uart_JobResult->psRxBufferPtr);
				++UartRxTestData.UartRxCmdIdx;
			}
		}
	}
	return;
}

TEST_FUNC void vTestModuleInit ( void )
{
    vDebugLogRegNotifyCb(Test_SAIL_UART_Rx_Notification);
}
/*******************************************************************************
** Syntax           : void APPL_SAIL_Shell_exit (void)                        **
**                                                                            **
** Description      : variables set to exit status and disables Rx port,      **
**                    after calling this API test mode is disabled.           **
**                    To enable test mode again system reset required.        **
** Parameters(in)   : None    						      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Parameters (in-out):                                                       **
**                                                                            **
** Return value     : None			                              **
**                                                                            **
*******************************************************************************/
TEST_FUNC void APPL_SAIL_Shell_exit(void)
{
	/* Need RST to start the APT Test */
	UartRxTestData.UartRxCmdIdx = 0U;
	UartRxTestData.eTestMode = HAL_SAIL_TEST_OFF;
	UartRxTestData.eFlushCmd = HAL_SAIL_BUFF_RD_WR_OFF;
	memset((char*)&UartRxCmd[0],'\0',HAL_SAIL_TEST_RXBUFF_SIZE);
	DEBUG_LOG(SAIL_INFO,"SAIL test mode exit done....!\n\r" \
		      "Please restart to enter in test mode....\n\r");

	return;
}

/*******************************************************************************
** Syntax           : void APPL_SAIL_Shell_reset                              **
**                    (    	void        				      **
**                    )                                                       **
**                                                                            **
** Description      :  clear vars. and set test mode configuration            **
**					               		              **
**                           				                      **
**                                                                            **
** Parameters(in)   : None                               		      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/
TEST_FUNC void APPL_SAIL_Shell_reset(void)
{
	UartRxTestData.UartRxCmdIdx = 0U;
	memset((char*)&UartRxCmd[0],'\0',HAL_SAIL_TEST_RXBUFF_SIZE);
	Active_testCaseID = MAX_TEST_ID;
	/* default  OFF --> ON --> OFF */
    if(UartRxTestData.eTestMode != HAL_SAIL_TEST_OFF)
	{
		UartRxTestData.eTestMode = HAL_SAIL_TEST_ON;
		UartRxTestData.eFlushCmd = HAL_SAIL_BUFF_WR;
		DEBUG_LOG(SAIL_WARNING,"Please use help or exit command....\n\r");
		DEBUG_LOG(SAIL_WARNING,"sail_proc@home$\n\r");
	}
	return ;
}

/*******************************************************************************
** Syntax           : uint8 APPL_SAIL_Shell_stricmp                           **
**                    (    	char const *str1, char const *str2            **
**                    )                                                       **
**                                                                            **
** Description      :  string compare                                         **
**					               		              **
**                           				                      **
**                                                                            **
** Parameters(in)   : *str1 - ptr to string in small caps ended with \0       **
** Parameters(in)   : *str2 - ptr to string needs to be compare               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     :  1 - compare success                                    **
** Return value     :  0 - compare fail                                       **
**                                                                            **
*******************************************************************************/
TEST_FUNC uint8 APPL_SAIL_Shell_stricmp(char const *str1, char const *str2)
{
	uint32 retval = 0U;
	uint32 temp = 0U;
	int res = 0;

	if((str1 != NULL) && (str2 != NULL))
	{
		/* loop limit is not req. as str1 is hard coded string test cmd */
		while(*str1!='\0')
		{
			temp = *str2;

			if((temp >= 'A') && (temp <= 'Z'))
			temp = temp + 32;

			res = *str1 - temp;

			if(res != 0U)
			{
				retval = 0U;
				break;
			}
			str1++;
			str2++;
		}

		if(*str1 == '\0' && *str2 == '\0')
		{
			retval = 1U;
		}
	}
    /* compare success ret 1 else 0 */
    return (uint8)retval;
}

/*******************************************************************************
** Syntax           : uint8* APPL_SAIL_Shell_gettoken                         **
**                    (    	uint8* str  				      **
**                    )                                                       **
**                                                                            **
** Description      : Method parse the input string into tokens               **
**                    specific to test application        		      **
**                                      		                      **
** Parameters(in)   : uint8* str  - ptr to shell command		      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     : ptr to last valid token from shell command string       **
**                    or NULL if token not found                              **
**                                                                            **
*******************************************************************************/

TEST_FUNC uint8* APPL_SAIL_Shell_gettoken(uint8* str)
{
    uint8 len  = 0U;
	uint8 len1 = 0U;
    if(str!=NULL)
    {
        ;
    }
    else
    {
        str = tokeninfo.NxtTknPtr;
    }

    if(str!=NULL)
    {
        for(len=0U; ((str[len]!=' ') && (str[len]!='\0') && (len<HAL_SAIL_TEST_RXBUFF_SIZE));len++);

        if(*(str+len) != '\0')
        {
            *(str+len) = '\0';

            for(len1=len+1; ((str[len1]==' ') && (str[len1]!='\0') && (len1<HAL_SAIL_TEST_RXBUFF_SIZE));len1++);

            tokeninfo.NxtTknPtr = (str+len1);
        }
        else
        {
           tokeninfo.NxtTknPtr = NULL;
        }
    }
	else
	{
		;
	}
    return str;
}

uint8 APPL_SAIL_Shell_getStringLength(uint8* str)
{
    uint8 len=0;
    if(str!=NULL)
    {
        for(len=0U; ((str[len]!=' ') && (str[len]!='\0') && (len<HAL_SAIL_TEST_RXBUFF_SIZE));len++);

    }
    return len;
}

void converInttoASCII(uint32 Value)
{
    char ASCIIstring[8] ={' '};

	uint8 len = 0;
	while(Value != 0)
	{
		ASCIIstring[len++] = (Value%10 + '0');
		Value = Value/10;	
	}

    for(int i=len-1;i>=0;i--)
    {
        if ( mbtf_result_length < MAX_BUFF_LENG )
        {
            mbtf_result_databuff[mbtf_result_length++] =ASCIIstring[i];
        }else
        {
            return;
        }
    }

}

TEST_FUNC static int test_myAtoi(const char* str)
{
    int sign = 1, base = 0, i = 0;

    // if whitespaces then ignore.
    while (str[i] == ' ')
    {
        i++;
    }
    // sign of number
    if (str[i] == '-' || str[i] == '+')
    {
        boolean value = (str[i++] == '-');
        sign = (int)1 - (int)2 * (int)value;
    }

    // checking for valid input
    while (str[i] >= '0' && str[i] <= '9')
    {
        // handling overflow test case
        if (base > INT_MAX / 10
                || (base == INT_MAX / 10
                    && str[i] - '0' > 7))
        {
            if (sign == 1)
            {
                return INT_MAX;
            }
            else
            {
                return (int)INT32_MIN_VALUE;
            }
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}
TEST_FUNC void APPL_SAIL_Shell_start(TestFrameworkType eTFType, uint8* databuff)
{
	TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;
	uint8 count;
	uint32 ulcpu_ID;
	/* TODO: Remove infuture */
	uint8 str_el2[MAX_BUFF_LENG]  = "setlog info el2";
	uint8 str_el1[MAX_BUFF_LENG]  = "setlog info el1";
	ulcpu_ID = get_curr_phys_cpu_num();
	for(count = 0; count<MAX_BUFF_LENG;count++)
	{
		UartRxCmdCpy[count] = databuff[count];
	}
	if(vLogGetLevel() == LOG_ERROR){
         DEBUG_LOG(SAIL_ERROR,"=====> log level set to ERROR\n\r");
        }
/*-------------------------------------------------------------------------------
*  CORE 0 Section -:  If You want to call Test API from CORE 0 , then Place API here
*-------------------------------------------------------------------------------*/
	uint8* find = APPL_SAIL_Shell_gettoken((uint8*)&databuff[0U]);
	/* Mission Mode Commands */
	if(APPL_SAIL_Shell_stricmp("getsailversion",(char*)find)) {
		DEBUG_LOG(SAIL_WARNING,"SAIL image id: %s \n\r", SAIL_IMAGE_VERSION);
	}else if(APPL_SAIL_Shell_stricmp("help",(char*)find)) {
		APPL_SAIL_Shell_help();

	}
	else if(APPL_SAIL_Shell_stricmp("spi",(char*)find)) {
		uint32_t ulcpu_id;
		ulcpu_id = get_curr_phys_cpu_num();
		if(ulcpu_id == 0){
		Test_app_info_send.core_info = CORE_1;
		Test_app_info_send.test_app = SPI;
		sailbsp_strlcpy((char *)Test_app_info_send.Rxqueue,(const char *)UartRxCmdCpy,sizeof(Test_app_info_send.Rxqueue));

		if( pdPASS != xFreeRTOSQueueSend ( xTestSEQXFERQHandle, (void*)&Test_app_info_send, 0))
		{
			DEBUG_LOG(SAIL_ERROR,"[ UART-SPI ] Queue send for core 1 failed\n");
		}
		}
	}
	else if(APPL_SAIL_Shell_stricmp("gpt",(char*)find)) {
		if(get_curr_phys_cpu_num() == 0){
			xRetStatus = XTestGptWrapper(find);
		}
	}
	else if(APPL_SAIL_Shell_stricmp("setlog",(char*)find)) {
		if(get_curr_phys_cpu_num() == 0){
		xTestUartLoglevelWrapper((uint8*)&UartRxCmdCpy[0]);
		}
	}
	else if(APPL_SAIL_Shell_stricmp("sleep",(char*)find)) {
		if(get_curr_phys_cpu_num() == 0){
                xRetStatus = xTestSleepWrapper();
		}
        }else if(APPL_SAIL_Shell_stricmp("i2cel1",(char*)find)) {
		 xRetStatus = xTestI2cEl1Wrapper();
	}


/*--------------------------------------------------------------------------------
* CORE 1 Section -: If you want to call Test API from CORE 1 , then use xFreeRTOSQueueSend
*                  API to send Test command to core 1 test function
*		  Use below space for CORE 1 
*---------------------------------------------------------------------------------*/
	else if(APPL_SAIL_Shell_stricmp("can",(char*)find)) {
			Test_app_info_send.core_info = CORE_1;
			Test_app_info_send.test_app = CAN;
			sailbsp_strlcpy((char *)Test_app_info_send.Rxqueue,(const char *)UartRxCmdCpy,sizeof(Test_app_info_send.Rxqueue));

			if( pdPASS != xFreeRTOSQueueSend ( xTestSEQXFERQHandle, (void*)&Test_app_info_send, 0))
			{
				DEBUG_LOG(SAIL_ERROR,"[ UART-CAN ] Queue send for core 1 failed\n");
			}else{

				DEBUG_LOG(SAIL_ERROR,"[ UART-CAN ] Queue send for core 1 pass\n");
			}
	}
/*--------------------------------------------------------------------------------
* CORE 2 Section -: If you want to call Test API from CORE 2 , then use xFreeRTOSQueueSend
*		    to call API
*---------------------------------------------------------------------------------*/

// This is only test function, to test Queue TX/RX with core 2

	else if(APPL_SAIL_Shell_stricmp("core_2",(char*)find)){
		Test_app_info_send.core_info = CORE_2;
		Test_app_info_send.test_app = CAN; 
		sailbsp_strlcpy((char *)Test_app_info_send.Rxqueue,(const char *)UartRxCmdCpy,sizeof(Test_app_info_send.Rxqueue));
		if( pdPASS != xFreeRTOSQueueSend (xQueue_handle_core2, (void*)&Test_app_info_send, 0))
		{
			DEBUG_LOG(SAIL_ERROR,"[ UART ] Queue send for core 2 failed\r\n");
		}else{

			DEBUG_LOG(SAIL_ERROR,"[ UART ] Queue send for core 2 pass\r\n");
		}
	}else{


	}

	find = NULL;
	return;
}
#if 1
TEST_FUNC void APPL_SAIL_Shell_help(void)
{
      DEBUG_LOG(SAIL_INFO,"=====    SAIL Command Usage	=====\n\r");
      DEBUG_LOG(SAIL_INFO,"1)  getsailversion\n\r \
			       usage -: getsailversion ( No param for this cmd)\n\r\n\r");
      DEBUG_LOG(SAIL_INFO,"2)  i2cel1\n\r \
			       usage -: i2cel1\n\r\n\r");
      DEBUG_LOG(SAIL_INFO,"3)  spi\n\r \
			       usage -: spi\n\r\n\r");
      DEBUG_LOG(SAIL_INFO,"4)  gpt\n\r \
			       usage -: gpt start < value > \n\r \
				        gpt stop\n\r  \
					gpt stats\n\r");
      DEBUG_LOG(SAIL_INFO,"5)  setlog\n\r \
			       usage -: setlog info el1 \n\r \
			       usage -: setlog err el1 \n\r \
			       usage -: setlog warn el1 \n\r \
			       usage -: setlog dbg el1 \n\r \
			       usage -: setlog info el2 \n\r \
			       usage -: setlog err el2 \n\r \
			       usage -: setlog warn el2 \n\r \
			       usage -: setlog dbg el2 \n\r" );
	
    return;

}
#endif
#if 0
TEST_FUNC void APPL_SAIL_Shell_help(void)
{
        DEBUG_LOG(SAIL_INFO,"\n\r>>>> Usage Ref <<<<\n\r" \
        " Main Command SubCommand Input<CR>\n\r" \
        " [ ] Optional\n\r" \
        " < > Mandatory\n\r" \
        " ( ) choose one option or none for all Choices\n\r" \
        " Commands are case insensitive\n\r" \
        "\n\r>>>> Command Ref <<<<\n\r" \
        " Main Command   SubCommand              Input\n\r" \
        " rd             <Addr in Hex>           n.a\n\r"\
        " wr             <Addr in Hex>           <Value in Hex>\n\r"\
        );

        DEBUG_LOG(SAIL_INFO,
        " dht             Core Id                <Number of Run>\n\r" \
        " spi             n.a                    n.a\n\r" \
        " i2cel1          n.a                    n.a\n\r" \
        " help            n.a                    n.a\n\r" \
        " gpt            <ch no>                < value> \n\r" \
        " exit            n.a                    n.a\n\r" \
        );

        if( ChipVersion == LEMANS_ADAS)
        {
                DEBUG_LOG(SAIL_INFO,
                " i2c             n.a                    n.a\n\r" \
            " pmic            corewrite              <rail_name>         <voltage_uV>\n\r" \
                );
        }
        return;
}
#endif
#if 0
TEST_FUNC void APPL_SAIL_Shell_help(void)
{
	DEBUG_LOG(SAIL_INFO,"\n\r>>>> Usage Ref <<<<\n\r" \
	" Main Command SubCommand Input<CR>\n\r" \
	" [ ] Optional\n\r" \
	" < > Mandatory\n\r" \
	" ( ) choose one option or none for all Choices\n\r" \
	" Commands are case insensitive\n\r" \
	"\n\r>>>> Command Ref <<<<\n\r" \
	" Main Command   SubCommand              Input\n\r" \
	" rd             <Addr in Hex>           n.a\n\r"\
	" wr             <Addr in Hex>           <Value in Hex>\n\r"\
	);

	DEBUG_LOG(SAIL_INFO,
	" dht             Core Id                <Number of Run>\n\r" \
	"       Core Id 4 shall the DHT on all core parallelly\n\r" \
	" fusa            n.a                    n.a\n\r" \
	" errcnt_fusa     n.a                    n.a\n\r" \
	" core_health	  n.a					 n.a\n\r" \
	" get_core_health n.a					 n.a \n\r"\
	" spi             n.a                    n.a\n\r" \
	" boot_status     n.a                    n.a\n\r" \
	" acmu            n.a                    n.a\n\r" \
	" gpio            input                  <gpio_number>\n\r" \
	" gpio            output                 <gpio_number>\n\r" \
	" gpio            low                  	 <gpio_number>\n\r" \
	" gpio            high                   <gpio_number>\n\r" \
	" gpio            intr_low               <gpio_number>\n\r" \
	" gpio            intr_high              <gpio_number>\n\r" \
	" gpio            intr_rising            <gpio_number>\n\r" \
	" gpio            intr_falling           <gpio_number>\n\r" \
	" gpio            intr_dual              <gpio_number>\n\r" \
	" gpio            intr_trigger           <gpio_number>\n\r" \
	" wdg             test                   n.a\n\r" \
	" wdg             core0                   <cmd>\n\r" \
	" wdg             core1                   <cmd>\n\r" \
	" wdg             core2                   <cmd>\n\r" \
	" wdg             core3                   <cmd>\n\r" \
	" emac            help                    n.a\n\r" \
    " tsc             gettime                 n.a\n\r" \
    " tsc             settime                 n.a\n\r" \
    " tsc             adjtime                 n.a\n\r" \
    " tsc             adjfreq                 n.a\n\r" \
    " tsc             counterror              n.a\n\r" \
	" ospinor_el1     n.a                    n.a\n\r" \
	" ospinor_el2     n.a                    n.a\n\r" \
        " qfprom          n.a                    n.a\n\r" \
	" mdlc            n.a                    [on/off]\n\r" \
	" i2cel1          n.a                    n.a\n\r" \
	" help            n.a                    n.a\n\r" \
	" exit            n.a                    n.a\n\r" \
	);

	if( ChipVersion == LEMANS_ADAS)
	{
		DEBUG_LOG(SAIL_INFO,
		" i2c             n.a                    n.a\n\r" \
		" pmic            test                   n.a\n\r" \
		" pmic            cx_rdt                 n.a\n\r" \
		" pmic            mx_rdt                 n.a\n\r" \
		" pmic            cx_wrt                 <corner_name>\n\r" \
		" pmic            mx_wrt                 <corner_name>\n\r" \
		" pmic            coredn                 <rail_name>\n\r" \
		" pmic            coreup                 <rail_name>\n\r" \
	    " pmic            corewrite              <rail_name>         <voltage_uV>\n\r" \
		);
	}
//#ifdef TEST_SRC_ENABLED
	DEBUG_LOG(SAIL_INFO,
	" clock           n.a                    n.a\n\r" \
	" gpio            n.a                    n.a\n\r" \
	" ospinor         n.a                    n.a\n\r" \
	" qfprom          n.a                    n.a\n\r" \
	" bist            n.a                    n.a\n\r" \
	" ospinor_el2     n.a                    n.a\n\r" \
	" gic             n.a                    n.a\n\r" \
	" comparator      n.a                    n.a\n\r" \
	" crypto          n.a                    n.a\n\r" \
	" hwkm            n.a                    n.a\n\r" \
	" el2mpu          n.a                    n.a\n\r" \
	" sec_syscall     n.a                    n.a\n\r" \
	" ipcc            n.a                    n.a\n\r" \
	" memheap         n.a                    n.a\n\r" \
	" ac              n.a                    n.a\n\r" \
	" lc              n.a                    n.a\n\r" \
	" tsens           n.a                    n.a\n\r" \
	" vsens           n.a                    n.a\n\r" \
	" ce_dmacrc       n.a                    n.a\n\r" \
	" pwr_controller  n.a                    n.a\n\r" \
	" memerraggr      n.a                    n.a\n\r" \
	" mdpshold        n.a                    n.a\n\r" \
	" isd             n.a                    n.a\n\r" \
	" can             n.a                    n.a\n\r" \
	" cpr             n.a                    n.a\n\r" \
	" acmu            n.a                    n.a\n\r" \
	" cpurts          n.a                    n.a\n\r" \
    )
//#endif
	return;
}
#endif
TEST_DATA volatile int task_check =0;
TEST_FUNC static void  GetChip_ID(void)
{
	ChipInfoIdType eChipID;

    eChipID = ChipInfo_GetChipId();
    if( eChipID == CHIPINFO_PARTNUM_SA_LEMANSAU_IVI)
    {
    	ChipVersion = LEMANS_IVI;
    }
	else
	{
		ChipVersion = LEMANS_ADAS;
	}
}
/**************************************************
* Task function for Core 2
*
**************************************************/
TEST_FUNC void vSAILAPPLShelltask_core2(void *pvParameters)
{
        BaseType_t SpiQStaus;
                if(get_curr_phys_cpu_num() == 2){
                        DEBUG_LOG( SAIL_WARNING, "vSAILAPPLShelltask_core2 task running on core 2\n\r");
                } 
        for( ;  ; )
        {
                SpiQStaus = xFreeRTOSQueueReceive ( xQueue_handle_core2, (void*)&Test_app_info_receive, pdMS_TO_TICKS(freertosMAX_DELAY));
                if( pdFAIL == SpiQStaus )
                {       
                        DEBUG_LOG( SAIL_WARNING, "vSPIXferHandlerTask(): Rx Seq Q FAIL on core 2!\n\r");
                }else{
     
                        DEBUG_LOG( SAIL_WARNING, "vSPIXferHandlerTask(): WARN core 2 Rx Seq Q SUCCESS -:%s\n\r",(char *)Test_app_info_receive.Rxqueue);
                }

        }
}
void Core1_Test_apps(){

	switch(Test_app_info_receive.test_app){

		case CAN: Can_test_ret = can_mcal_test((char*)&Test_app_info_receive.Rxqueue);
			 break;
		case SPI:xTestSPIWrapper();
			 break;
		default:DEBUG_LOG(SAIL_ERROR,"[UART_Test core 1] Wrong API ID\n\r"); 
	}


}
/************************************************
* Task function for Core 1
*
************************************************/
TEST_FUNC void vSAILAPPLShelltask_core1(void *pvParameters)
{
        BaseType_t SpiQStaus;
        if(get_curr_phys_cpu_num() == 1){
                DEBUG_LOG( SAIL_WARNING, "vSAILAPPLShelltask_core1 task running on core 1\n\r");
        }
        for( ;  ; )  
        {

                SpiQStaus = xFreeRTOSQueueReceive ( xTestSEQXFERQHandle, (void*)&Test_app_info_receive, pdMS_TO_TICKS(freertosMAX_DELAY));
                if( pdFAIL == SpiQStaus )
                {
                        DEBUG_LOG( SAIL_WARNING, "vSAILAPPLShelltask_core1: Rx Seq Q FAIL !\n\r");
                }else{

                        DEBUG_LOG( SAIL_WARNING, "vSAILAPPLShelltask_core1: Rx Seq Q SUCCESS -:%s\n\r",(char *)Test_app_info_receive.Rxqueue);
                }
		Core1_Test_apps();
                //can_mcal_test((char*)&Test_app_info_receive.Rxqueue);
        }
}
/************************************************
* Task function for Core 0
*
************************************************/

TEST_FUNC void vSAILAPPLShelltask_core0(void *pvParameters)  
{
	(void)pvParameters;
	uint32 ulcpu_ID;
	/* Get the Current CPU Id.*/
	ulcpu_ID = get_curr_phys_cpu_num();
	if ( 0UL == ulcpu_ID )
	{
		/* sailsw1 registers dbg log uart Rx IRQ handler. */
		vTestModuleInit ( );
	}
	for( ; ; )
	{		

		if(UartRxTestData.eFlushCmd == HAL_SAIL_BUFF_RD)     //this will be forever in look and start whenever it gets data 
		{
			APPL_SAIL_Shell_start(TEST_FRAMEWORK_UART, (uint8*)&UartRxCmd[0]);
			/* clear for Next Rx - RTR */
			APPL_SAIL_Shell_reset();
		}
		if( pdPASS != xFreeRTOSSemaphoreTake( xShellSemaphoreHandle , pdMS_TO_TICKS(freertosMAX_DELAY) ) )
		{
			DEBUG_LOG(SAIL_WARNING,"SPI Callback Semaphore could not acquire\n\r");
		}

//		freertosYIELD();
		vFreeRTOSTaskDelay(pdMS_TO_TICKS(100));

	}


	return; 
}
BaseType_t xSAILshellTaskInit_core0( CPUIdType_e  xSchdCore,UBaseType_t  xTaskPrior )
{
	static BaseType_t xDummy1TaskCreated = pdPASS;
	BaseType_t xResult = pdPASS;
	UBaseType_t uxCoreAffinityMask;
	TaskParams_t xInitTaskParameters = { 
		.pvTaskCode     = vSAILAPPLShelltask_core0,
		.pcName         = "UART SHELL TASK",
		.usStackDepth   = shellTASK_STACK_SIZE,
		.pvParameters   = NULL,
		.uxPriority     = (xTaskPrior),
		.puxStackBuffer = xshellUARTTaskStack,
		.xRegions               =       {
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL }
		},
		.pxTaskBuffer   = &xShellTaskTCB
	};  
	uxCoreAffinityMask = ( 1 << 0 );

	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters, uxCoreAffinityMask, &xSAILShellTaskHandle);
	if ( xResult != pdPASS){
		DEBUG_LOG(SAIL_WARNING, "Task not created\r\n");
		xDummy1TaskCreated = pdFALSE;
	}else{
		DEBUG_LOG(SAIL_WARNING, "vSAILAPPLShelltask Task created\r\n");
	}


	return xResult;

}
BaseType_t xSAILshellTaskInit_core1( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior )
{	
	static BaseType_t xDummy2TaskCreated = pdPASS;
	BaseType_t xResult = pdPASS;
	UBaseType_t uxCoreAffinityMask;
	TaskParams_t xInitTaskParameters1 = { 
		.pvTaskCode     = vSAILAPPLShelltask_core1,
		.pcName         = "core 1",
		.usStackDepth   = shellTASK_STACK_SIZE_second,
		.pvParameters   = NULL,
		.uxPriority     = (xTaskPrior),
		.puxStackBuffer = xshellUARTTaskStack1,
		.xRegions               =       {
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL }
		},
		.pxTaskBuffer   = &xShellTaskTCB_core1
	};  
	uxCoreAffinityMask = ( 1 << xSchdCore);
	DEBUG_LOG(SAIL_WARNING, "uxCoreAffinityMask value 1 -:%d  xSchdCore-:%d\r\n",uxCoreAffinityMask,xSchdCore);
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters1, uxCoreAffinityMask, &xTest_core1_TaskHandle);
	if ( xResult != pdPASS){
		DEBUG_LOG(SAIL_WARNING, "Task on core 1 not created\r\n");
	}else{
		DEBUG_LOG(SAIL_WARNING, "New Task 1 created\r\n");
	}
	return xResult;
}
BaseType_t xSAILshellTaskInit_core2( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior )
{
	static BaseType_t xDummy2TaskCreated = pdPASS;
	BaseType_t xResult = pdPASS;
	UBaseType_t uxCoreAffinityMask;
	uxCoreAffinityMask = ( 1 << 2);
	TaskParams_t xInitTaskParameters2 = { 
		.pvTaskCode     = vSAILAPPLShelltask_core2,
		.pcName         = "core 2",
		.usStackDepth   = shellTASK_STACK_SIZE_third,
		.pvParameters   = NULL,
		.uxPriority     = (xTaskPrior),
		.puxStackBuffer = xshellUARTTaskStack2,
		.xRegions               =       {
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL }
		},
		.pxTaskBuffer   = &xShellTaskTCB_core2
	};  
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters2, uxCoreAffinityMask, &xTest_core2_TaskHandle);
	if ( xResult != pdPASS){
		DEBUG_LOG(SAIL_WARNING, "Task on core 2 not created\r\n");
	}else{
		DEBUG_LOG(SAIL_WARNING, "New Task 2 created\r\n");
	}
	return xResult;
}
