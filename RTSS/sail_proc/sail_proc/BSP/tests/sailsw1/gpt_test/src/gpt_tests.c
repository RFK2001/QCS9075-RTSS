/*
===================================================================================================
*/
/**
    @file  gpt_tests.c
    @brief This file contains test application for GPT Mcal driver

*/
/*
    ===============================================================================================

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

    ===============================================================================================

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===============================================================================================
*/
/*=================================================================================================
**                      Include Section                                       **
==================================================================================================*/
#include "debug_log.h"
#include "FreeRTOSOsal.h"
#include "types.h"
#include "freertos_init.h"
#include "common_functions.h"
#include "tests.h"
#include "event_groups.h"
#include "Gpt_Cfg.h"
#include "Gpt.h"
//#include "Gpt_PBcfg.h"
//#include "Gpt_Cfg.h"
#include "Gpt_Prv.h"
#define usToTicks(us)  ((us * 19200000) / 1000000)
/* The size of the periodic test task stack - must be a multiple of 64. */
#define STD_ON             0x01U
#define STD_OFF             0x00U
#define TEST_TIMER_TASK_STACK_SIZE                   ( 320 )
#define TASK_STACK_SIZE (2048)
static StackType_t xshellUARTTaskStack[TASK_STACK_SIZE]  __attribute__((aligned(MEM_ALIGNMENT_64))) = { 0 };
static StaticTask_t xShellTaskTCB = {0};
static int check_ret = 1;
TaskHandle_t xTestTimerTaskHandle;

/* Event group parameters */
TEST_DATA static StaticEventGroup_t xEventGroupGptBuffer  = { 0U };
TEST_DATA static EventGroupHandle_t  xEventGroupGptHandle  = NULL;
TEST_DATA static EventBits_t xEvBitsSet             		= { 0U };
TEST_DATA volatile uint64 timerPeriodInUS = 100;
TEST_DATA volatile uint64  lowest[12] = { 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
TEST_DATA static volatile uint64  highest[12] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };
TEST_DATA volatile uint32  count[12] = { 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
TEST_DATA static volatile uint64  sum[12] = { 0 };
TEST_DATA volatile uint64 startTime[12] = {0, 0};
TEST_DATA static StaticTask_t xTestTimerTaskTCB = { 0 };
TEST_DATA static StackType_t  xTestTimerTaskStack[ TEST_TIMER_TASK_STACK_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
TEST_DATA static TaskHandle_t timerTestTaskHandle;

TEST_FUNC BaseType_t xTestsTimerTaskInit( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior );
TEST_FUNC void vTestsTimerTask(void * pvParameters);
TEST_FUNC void xTestGptChannelNotification( uint8 timerId );
TEST_FUNC void xTestGptChannel0Notification(){xTestGptChannelNotification(0);}
TEST_FUNC void xTestGptChannel1Notification(){xTestGptChannelNotification(1);}
TEST_FUNC void xTestGptChannel2Notification(){xTestGptChannelNotification(2);}
TEST_FUNC void xTestGptChannel3Notification(){xTestGptChannelNotification(3);}
TEST_FUNC void xTestGptChannel4Notification(){xTestGptChannelNotification(4);}
TEST_FUNC void xTestGptChannel5Notification(){xTestGptChannelNotification(5);}
TEST_FUNC void xTestGptChannel6Notification(){xTestGptChannelNotification(6);}
TEST_FUNC void xTestGptChannel7Notification(){xTestGptChannelNotification(7);}
TEST_FUNC void xTestGptChannel8Notification(){xTestGptChannelNotification(8);}
TEST_FUNC void xTestGptChannel9Notification(){xTestGptChannelNotification(9);}
TEST_FUNC void xTestGptChannel10Notification(){xTestGptChannelNotification(10);}
TEST_FUNC void xTestGptChannel11Notification(){xTestGptChannelNotification(11);}
//xFreeRTOSTaskCreateAffinitySet
TEST_DATA TaskHandle_t xGpt_TaskHandle = NULL;


TEST_FUNC static BaseType_t xTestsTimerTaskDelete( void )
{
	if(xGpt_TaskHandle != NULL){
		(void) vFreeRTOSTaskDelete(xGpt_TaskHandle);
	DEBUG_LOG(SAIL_INFO, ">>>>> Stopped Timer Test Task\n\r");
	}else{
	DEBUG_LOG(SAIL_INFO, ">>>>> Timer test Task not started\n\r");
	}
	check_ret = 1;
	xGpt_TaskHandle = NULL;
	return 0;
}

TEST_FUNC void xTestGptChannelNotification( uint8 timerId )
{
	volatile uint64 currentTime = 0;
	volatile uint64 diffTime = 0;
#if 0
	//BaseType_t xHigherPriorityTaskWoken =  pdFALSE;
	//xEventGroupSetBitsFromISR(xEventGroupGptHandle, (1 << timerId));
	//freertosYIELD_FROM_ISR();
	currentTime = Gpt_GetCntFreeRunning(timerId);
         diffTime = GptPrv_GetTimeDifference(currentTime, startTime[timerId]);
	if(lowest[timerId] == 0 ||  diffTime < lowest[timerId]) 
	{
		lowest[timerId] = diffTime;
	}
	if(diffTime > highest[timerId]) 
	{
		highest[timerId] = diffTime;
	}
	count[timerId] += 1;
	sum[timerId] += diffTime;
#endif
	DEBUG_LOG(SAIL_ERROR, "xTestGptChannelNotification called %d channel\n\r",timerId);
}

TEST_FUNC static uint64 chatToInt(char *str)
{
    uint64 ullresult = 0x0u;
    uint8 ucIndex = 0x0u;

    for( ucIndex = 0x0u ; str[ucIndex]!= '\0' ; ucIndex++)
    {
        ullresult = ullresult*10u + (str[ucIndex]-'0');
    }

    return ullresult;
}

TEST_FUNC TESTerrorType_e XTestGptWrapper(uint8 *find)
{
	TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;
	uint8 timerId = 0;
	uint64 timervalue = 0;
	BaseType_t xResult = pdPASS;
	Gpt_ChannelConfigType * LGpt_ChannelConfig = NULL;

	if(NULL == xEventGroupGptHandle)
	{
        xResult = xFreeRTOSEventGroupCreate( &xEventGroupGptBuffer, &xEventGroupGptHandle);

        if( pdPASS != xResult )
		{
			xRetStatus = MODULE_TEST_FAILED;
			DEBUG_LOG( SAIL_DEBUG, "GPT Test Task Event Group Creation Failed.\r\n" );
			return xRetStatus;
		}
	}
	find = APPL_SAIL_Shell_gettoken(NULL);

	if(find == NULL){
		DEBUG_LOG(SAIL_WARNING,">>>>>> Check GPT command usage\n\r");
		return MODULE_TEST_INVALID;
	}

	// command: gpt start 
	if(APPL_SAIL_Shell_stricmp("start",(char*)find)) 
	{
		find = APPL_SAIL_Shell_gettoken(NULL);
		if(find == NULL){
			DEBUG_LOG(SAIL_WARNING,">>>>>>> Check GPT command usage\n\r");
			return MODULE_TEST_INVALID;
		}
		timerPeriodInUS = chatToInt((char *)find);
		if(check_ret == 1 && timerPeriodInUS != 0){
		    check_ret = 0;
			xTestsTimerTaskInit(0, 4);
		}else{
			DEBUG_LOG(SAIL_WARNING,">>>>> GPT timer already Initialized , deinit first using stop cmd\n\r");
		}
	}
	// command: gpt stop
	else if(APPL_SAIL_Shell_stricmp("stop",(char*)find)) 
	{
		xTestsTimerTaskDelete();
	}
	// command: gpt display_config <timer_channel>
	else if(APPL_SAIL_Shell_stricmp("display_config",(char*)find)) 
	{
		find = APPL_SAIL_Shell_gettoken(NULL);

		if(find == NULL){
			DEBUG_LOG(SAIL_WARNING,">>>>>> Check GPT command usage\n\r");
			return MODULE_TEST_INVALID;
		}
		
		timerId = chatToInt((char *) find);
#if 0
		LGpt_ChannelConfig = ( Gpt_ChannelConfigType *) &(Gpt_Config.ChannelConfig[timerId]);
		DEBUG_LOG(SAIL_INFO, "GPT Test Timer %d Configuration:\n\r", timerId);

			if(GPT_CH_MODE_CONTINUOUS == LGpt_ChannelConfig->GptChannelMode)
			{
				DEBUG_LOG(SAIL_INFO, ">> Channel Config: GPT_CH_MODE_CONTINUOUS\n\r");
			}
			else
			{
				DEBUG_LOG(SAIL_INFO, ">> Channel Config: GPT_CH_MODE_ONESHOT\n\r");
			}

			if(GPT_PREDEF_TIMER_2US_32BIT_RES == LGpt_ChannelConfig->GptPredefTimer)
			{
				DEBUG_LOG(SAIL_INFO, ">> Channel PreDef Resolution: GPT_PREDEF_TIMER_2US_32BIT_RES\n\r");
			}
			else if(GPT_PREDEF_TIMER_1US_16BIT == LGpt_ChannelConfig->GptPredefTimer)
			{
				DEBUG_LOG(SAIL_INFO, ">> Channel PreDef Resolution: GPT_PREDEF_TIMER_1US_16BIT\n\r");
			}
			else if(GPT_PREDEF_TIMER_1US_24BIT == LGpt_ChannelConfig->GptPredefTimer)
			{
				DEBUG_LOG(SAIL_INFO, ">> Channel PreDef Resolution: GPT_PREDEF_TIMER_1US_24BIT\n\r");
			}
			else if(GPT_PREDEF_TIMER_1US_32BIT == LGpt_ChannelConfig->GptPredefTimer)
			{
				DEBUG_LOG(SAIL_INFO, ">> Channel PreDef Resolution: GPT_PREDEF_TIMER_1US_32BIT\n\r");
			}
			else
			{
				DEBUG_LOG(SAIL_INFO, ">> Channel PreDef Resolution: GPT_PREDEF_TIMER_100US_32BIT\n\r");
			}

		if(STD_OFF == LGpt_ChannelConfig->Gpt_ChannelCbkEn)
		{
			DEBUG_LOG(SAIL_INFO, ">> Channel Notification is Disabled\n\r");
		}
		else
		{
			DEBUG_LOG(SAIL_INFO, ">> Channel Notification is Enabled\n\r");
		}
#endif
	}
	// command: gpt time_elapsed <timer_channel> 
	else if(APPL_SAIL_Shell_stricmp("time_elapsed",(char*)find)) 
	{
		find = APPL_SAIL_Shell_gettoken(NULL);
		if(find == NULL){
			DEBUG_LOG(SAIL_WARNING,">>>>>> Check GPT command usage\n\r");
			return MODULE_TEST_INVALID;
		}
		timerId = chatToInt((char *) find);

		timervalue = Gpt_GetTimeElapsed(timerId);

		DEBUG_LOG(SAIL_INFO, ">>>>>>> GPT Test Elapsed time for timer %d: %lu\n\r", timerId, timervalue);
	}
	// command: gpt time_current <timer_channel>
#if 0 
	else if(APPL_SAIL_Shell_stricmp("time_current",(char*)find)) 
	{
		find = APPL_SAIL_Shell_gettoken(NULL);
		if(find == NULL){
			DEBUG_LOG(SAIL_WARNING,">>>>> Check GPT command usage\n\r");
			return MODULE_TEST_INVALID;
		}
		timerId = chatToInt((char *) find);

		timervalue = Gpt_GetCntFreeRunning(timerId);

		DEBUG_LOG(SAIL_INFO, ">>>>>> GPT Test Current time for timer %d: %lu\n\r", timerId, timervalue);
	}
#endif
	// command: gpt stats
	else if(APPL_SAIL_Shell_stricmp("stats",(char*)find)) 
	{
		for(timerId = 0; timerId < 12; timerId++ )
		{
			timervalue = (sum[timerId]/count[timerId]);
			DEBUG_LOG(SAIL_INFO, "<<<<Timer %d Stats Start>>>>\n\r", timerId);
			DEBUG_LOG(SAIL_INFO, "High: %lu \n\r", highest[timerId]);
			DEBUG_LOG(SAIL_INFO, "Low: %lu \n\r",  lowest[timerId]);
			DEBUG_LOG(SAIL_INFO, "Avg is : %lu\n\r", timervalue);
			DEBUG_LOG(SAIL_INFO, "iters: %lu\n\r", count[timerId]);
			DEBUG_LOG(SAIL_INFO, "<<<<Timer %d Stats Start>>>>\n\r\n\r", timerId);
		}
	}
	else if(APPL_SAIL_Shell_stricmp("deinit_val",(char*)find))
	{
		uint64 timervalue1 = 0, timervalue2 = 0;
		timerId  = 0x0;
		Gpt_Init(&Gpt_Config);
		Gpt_StartTimer(timerId, 100);
		//startTime[timerId] = Gpt_GetCntFreeRunning(timerId);
		DEBUG_LOG(SAIL_INFO, "Time: %lu\n\r", startTime[timerId]);
		Gpt_DeInit();
		//startTime[timerId]  = Gpt_GetCntFreeRunning(timerId);
		DEBUG_LOG(SAIL_INFO, "Free Run Time after Deinit: %lu\n\r", startTime[timerId] );
		timervalue1 = Gpt_GetTimeElapsed(timerId);
		timervalue2 = Gpt_GetTimeRemaining(timerId);
		Gpt_EnableNotification(timerId);
		Gpt_StopTimer(timerId);
		DEBUG_LOG(SAIL_INFO, "Time after Deinit: %lu, %lu\n\r", timervalue1, timervalue2);
	}

	return xRetStatus;
}

TEST_FUNC BaseType_t xTestsTimerTaskInit( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior )
{
	static BaseType_t xDummy2TaskCreated = pdPASS;
	BaseType_t xResult = pdPASS;
	UBaseType_t uxCoreAffinityMask;
	TaskParams_t xInitTaskParameters1 = { 
		.pvTaskCode     = vTestsTimerTask,
		.pcName         = "vTestsTimerTask",
		.usStackDepth   = TEST_TIMER_TASK_STACK_SIZE,
		.pvParameters   = NULL,
		.uxPriority     = (5),
		.puxStackBuffer = xTestTimerTaskStack,
		.xRegions               =       {
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL }
		},
		.pxTaskBuffer   = &xTestTimerTaskTCB
	};  
	uxCoreAffinityMask = ( 1 << xSchdCore);
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters1, uxCoreAffinityMask, &xGpt_TaskHandle);
	if ( xResult != pdPASS){
		DEBUG_LOG(SAIL_WARNING, "xTestsTimerTaskInit creation failed\r\n");
	}else{
		DEBUG_LOG(SAIL_WARNING, "xTestsTimerTaskInit created\r\n");
	}
	return xResult;
}


TEST_FUNC void vTestsTimerTask(void * pvParameters)
{
	uint8 timerId = 0;
	/* The parameters are not used in this task. This just prevents a compiler
	 * warning. */
	( void ) pvParameters;
	Gpt_Init(&Gpt_Config);
	

	DEBUG_LOG(SAIL_INFO, "Timer test start>>>>\n\r");
	vFreeRTOSTaskSuspendAll();
	// channel 0 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_00_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_00_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_00_ID);
#if 1
// channel 1 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_01_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_01_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_01_ID);
// channel 2 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_02_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_02_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_02_ID);
// channel 3 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_03_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_03_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_03_ID);
// channel 4 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_04_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_04_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_04_ID);
// channel 5 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_05_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_05_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_05_ID);
// channel 6 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_06_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_06_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_06_ID);
// channel 7 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_07_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_07_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_07_ID);
// channel 8 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_08_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_08_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_08_ID);
// channel 9 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_09_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_09_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_09_ID);
// channel 10 test
	Gpt_StartTimer(GptConf_GptChannel_GptChannel_10_ID, timerPeriodInUS);
	Gpt_EnableNotification(GptConf_GptChannel_GptChannel_10_ID);
	startTime[timerId++] = Gpt_GetCntFreeRunning(GptConf_GptChannel_GptChannel_10_ID);
#endif
	xFreeRTOSTaskResumeAll();
	DEBUG_LOG(SAIL_INFO,">>>> GPt Test Done\n\r");
	for(  ;  ; ){
		( void ) vFreeRTOSTaskDelay(  10 );
	}
}
