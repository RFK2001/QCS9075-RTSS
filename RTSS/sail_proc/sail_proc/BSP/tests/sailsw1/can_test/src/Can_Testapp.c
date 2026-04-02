
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include<stdio.h>
#include "CanTrcv_184_Tcan1146.h"
#include "CanTrcv_184_Tcan1044.h"
#include "Can_Testapp.h"
#include "Can_Drv.h"
#include "tests_sailsw1.h"
#include "xCanSrv.h"
#include "debug_log.h"
#include "freertos_init.h"
#include "FreeRTOSOsal.h"

#define CAN_COVERAGE_TEST STD_OFF
#define NUMBER_OF_INTERRUPT_HANDLERS 9
#define CAN_TX_FIFO_OFFSET			1
#define CAN_TX_FIFO_DIFF			5
#define TEST_MAX_CLIENT_CNT         16

static uint32 Test_CanClientHandle[TEST_MAX_CLIENT_CNT] = {0};

uint8 Bussoff_Flag;
Can_ControllerStateType Get_Transition;
CanTrcv_TrcvModeType Trc_Get_Transition;
CanTrcv_TrcvWakeupReasonType Trc_Wu_reason;
Std_VersionInfoType *pInfoVersion;
Std_VersionInfoType *pTrcv_infoversion;
Std_VersionInfoType Trcv_infoversion;

static uint8 runApi = 0;
static uint8* nextFind =NULL;
static PduIdType CanTest_TxPduId = 0;

static char *input_cmd = NULL;

static Std_ReturnType DummyTestFunction(){
	DEBUG_LOG( SAIL_INFO, "Invoked Dummy function\r\n");
	return E_OK;
}


#define APPL_SAILTF_MSG_PYLD_SZ (58U)
typedef enum
{
	MODULE_TEST_PASSED,
	MODULE_TEST_FAILED,
	MODULE_TEST_INVALID
} TESTerrorType_e;

typedef struct Rx_tokens
{
	uint8 *NxtTknPtr;
} t_Gsttoken;

static t_Gsttoken tokeninfo;
uint8 *pucAPPL_SAILTF_gettoken(uint8 *str)
{
	uint8 len = 0U;
	uint8 len1 = 0U;

	if (str != NULL)
	{
		;
	}
	else
	{
		str = tokeninfo.NxtTknPtr;
	}

	if (str != NULL)
	{
		for (len = 0U; ((str[len] != ' ') && (str[len] != '\0') && (len < APPL_SAILTF_MSG_PYLD_SZ)); len++)
			;

		if (*(str + len) != '\0')
		{
			*(str + len) = '\0';

			for (len1 = len + 1U; ((str[len1] == ' ') && (str[len1] != '\0') && (len1 < APPL_SAILTF_MSG_PYLD_SZ)); len1++)
				;

			tokeninfo.NxtTknPtr = (str + len1);
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

uint8 ucAPPL_SAILTF_stricmp(char const *str1, char const *str2)
{
	uint32 retval = 0U;
	uint32 temp = 0U;
	int res = 0;

	if ((str1 != NULL) && (str2 != NULL))
	{
		/* loop limit is not req. as str1 is hard coded string test cmd */
		while (*str1 != '\0' && *str2 != '\0')
		{
			temp = *str2;

			if ((temp >= 'A') && (temp <= 'Z'))
				temp = temp + 32;

			res = *str1 - temp;

			if (res != 0U)
			{
				retval = 0U;
				break;
			}
			str1++;
			str2++;
		}

		if (*str1 == '\0' && *str2 == '\0')
		{
			retval = 1U;
		}
	}
	/* compare success ret 1 else 0 */
	return (uint8)retval;
}

static Testcase CanTCApis[CAN_TC_API_COUNT] = {
	{CanTC_Init},                             // -t 0
	{CanTC_Write_TxFIFO},                     // -t 1
#if(CAN_SET_BAUDRATE_API == STD_ON)
	{CanTC_SetBaudrate},                      // -t 2
#else
	{DummyTestFunction},
#endif
	{CanTC_Write_TxClassicalStandardID},      // -t 3
	{CanTC_Write_TxClassicalExtendedID},      // -t 4
	{CanTC_Write_TxFdStandardID},             // -t 5
	{CanTC_Write_TxFdExtendedID},             // -t 6
	{CanTC_Write_TxAlltypesofFrames},         // -t 7
	{CanTC_DeInit},                           // -t 8
	{CanTC_ExternalLoopback_Enable},          // -t 9
	{CanTC_InternalLoopback_Enable},          // -t 10
	{CanTC_Loopback_Disable},                 // -t 11
	{DummyTestFunction},                      // -t 12
	{CanTC_GetControllerErrorState},          // -t 13
	{CanTC_GetControllerTxErrorCounter},      // -t 14
	{CanTC_GetControllerRxErrorCounter},      // -t 15
	{CanTC_SetControllerMode_Sleep},          // -t 16
	{CanTC_EccFaultInjectionTest},            // -t 17
	{CanTC_Fusa_ECC_Status},                  // -t 18
	{CanTC_TimeoutFaultInjectionTest},        // -t 19
	{CanTC_Fusa_Timeout_Status},              // -t 20
	{CanTC_Fusa_Protocol_Status},             // -t 21
	{CanTC_ReadRegister},                     // -t 22
	{CanTC_SetControllerMode},                // -t 23
	{CanTC_GetControllerMode},                // -t 24
#if(CAN_VERSION_API_ENABLE == STD_ON)
	{CanTC_GetVersionInfo},                   // -t 25
#else
	{DummyTestFunction},
#endif
	{CanTC_EnableControllerInterrupts},       // -t 26
	{CanTC_DisableControllerInterrupts},      // -t 27
	{DummyTestFunction},                      // -t 28
	{CanTC_SetRegister},                      // -t 29
	{CanTC_MainFunction_ConfigCheck},         // -t 30
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
	{CanTC_EnableEgressTimeStamp},            // -t 31
	{CanTC_GetCurrentTime},                   // -t 32
	{CanTC_GetEgressTimeStamp},               // -t 33
	{CanTC_GetIngressTimeStamp},              // -t 34
#else
	{DummyTestFunction},
	{DummyTestFunction},
	{DummyTestFunction},
	{{DummyTestFunction},
#endif
	{CanTC_ReadRegRange},                     // -t 35
	{CanTC_SetCanCtrlInfo},                   // -t 36
	{CanTC_MainFunction_SSR_HM},              // -t 37
	{CanTC_ConfigureInterrupts},              // -t 38
	{CanTC_MainFunction_Write},               // -t 39
	{CanTC_MainFunction_Read},                // -t 40
	{CanTC_MainFunction_BusOff},              // -t 41
	{CanTC_MainFunction_Wakeup},              // -t 42
	{CanTC_MainFunction_Mode},                // -t 43
	{CanTC_CheckWakeup},                      // -t 44
	{CanTC_Write}							  // -t 45
};

static uint32 CanMainFunctionPeriod = 100;
static uint32 CanCount = 1;
static uint8 CanController[NUMBER_OF_ACTIVE_CAN_CTRL + 1]= {0};
static uint8 configIndex= 0;
static uint8 null = 0;
static Can_ControllerStateType Transition = 0;
static uint16 BaudRateConfigID = 0;
static Std_VersionInfoType infoversion;
static int temp;
static int TimeoutFault = 0 ;
static uint8 SubTestTimeoutFault =0;

uint8 MramIndex = 0;
static const Can_ConfigType *Config[CAN_CONFIG_COUNT+1]= {&Can_Config_Default,
                                                 &Can_Config_NewEntry,
                                                 &Can_Config_WaterMark,
                                                 &Can_Config_Dma,
                                                 &Can_Config_Filter,
                                                 &Can_Config_TxQueue,
                                                 &Can_Config_FdDisabled,
                                                 &Can_Config_Mixed,
												 NULL_PTR};


static Can_HwHandleType Hoh[CAN_MAX_HOH_CONFIGURED + 1];

static uint8 pduIndex = 0;
uint8 acceptCommand = 1;
__attribute__((used)) static uint8 tx_data_1[8] = {0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x51, 0x52};
__attribute__((used)) static uint8 tx_data_2[9] = {0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x51, 0x52, 0x53};
__attribute__((used)) static uint8 tx_data_3[8] = {0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33};
__attribute__((used)) static uint8 tx_data_4[16] = {	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
						0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F};
__attribute__((used)) static uint8 tx_data_5[60] = { 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA,0xAA,0xAA,
						0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB,0xBB,0xBB,
						0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,0xCC,0xCC,
						0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD,0xDD,0xDD,
						0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE,0xEE,0xEE,
						0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,0xFF,0xFF};

__attribute__((used)) static Can_PduType Pdu1 = { 1,8, 0x155, tx_data_1 };
__attribute__((used)) static Can_PduType Pdu2 = { 2,9, 0x40000177, tx_data_2 };
__attribute__((used)) static Can_PduType Pdu3 = { 3,8, 0x90000131, tx_data_3 };
__attribute__((used)) static Can_PduType Pdu4 = { 4,16, 0xD0000141, tx_data_4 };
__attribute__((used)) static Can_PduType Pdu5 = { 5,60, 0xDF000222, tx_data_5 };
__attribute__((used)) static Can_PduType Pdu6 = { 6,48, 0x80, NULL };
__attribute__((used)) static Can_PduType Pdu7 = { 7,65, 0x40000100, NULL };
__attribute__((used)) static Can_PduType Pdu8 = { 8,20, 0x40000101, NULL };
__attribute__((used)) static Can_PduType Pdu9 = { 9,8, 0x157, NULL };
__attribute__((used)) static Can_PduType Pdu10 ={10,9, 0x156, tx_data_2 };

static Can_PduType * PduInfo[PDU_INFO_COUNT + 1] = {&Pdu1, &Pdu2, &Pdu3, &Pdu4, &Pdu5, &Pdu6, &Pdu7,&Pdu8, NULL_PTR};
static uint32 addr = 0, startAddr = 0, endAddr = 0, value = 0;
/********************************************************************************
Local functions
********************************************************************************/
static int Can_Atoi(uint8 * str);
static Std_ReturnType CanGetApi(void);
static void CanGetConfig(void);
static void CanGetController(void);
static void CanGetBaudrate(void);
static void CanGetObjects(void);
static void CanGetMode(void);
static void CanGetPeriod(void);
static void CanGetCount(void);
static void CanGetPdu(void);
static void CanGetAddr(void);
static void CanGetFromAddr(void);
static void CanGetToAddr(void);
static void CanGetRegValue(void);
//static void CanGetDataLength(void);
static void CanCheckNull(void);
static void CanCoverageTest(void);
static void CanWriteTest(void);
static void CanGetSubTestTimeout(void);
static void CanGetMramIndex(void);
static void CanGetTimeoutFault(void);
static void CT_CanDrvISR(void);
static void CT_Fusa(void);
static void CanHwGetObject(void);


/* CAN call backs */
void CanTest_TxConfirmation(PduIdType swPduHandle, Can_HwHandleType Hth, Can_TimeStampType timeStamp)
{
    DEBUG_LOG( SAIL_ERROR, "%s with swPduHandle: %d, Hth: %d,  timeStamp.sec:%d timeStamp.ns:%d\r\n",
                                        __func__, swPduHandle, Hth, timeStamp.seconds, timeStamp.nanoseconds);
}

void CanTest_RxIndication(const Can_HwType* Mailbox, uint8* Data, PduLengthType DataLength, Can_TimeStampType timeStamp)
{
	DEBUG_LOG( SAIL_INFO, "%s is invoked with:\r\n", __func__);
	DEBUG_LOG( SAIL_INFO, "Mailbox-> CanId:0x%x\r\n",Mailbox-> CanId);
	DEBUG_LOG( SAIL_INFO, "Mailbox-> Hoh:%d\r\n",Mailbox-> Hoh);
	DEBUG_LOG( SAIL_INFO, "Mailbox-> ControllerId:%d\r\n",Mailbox-> ControllerId);
	DEBUG_LOG( SAIL_INFO, "timeStamp.sec:%d timeStamp.ns:%d \r\n",timeStamp.seconds, timeStamp.nanoseconds);
	//DEBUGLOG_LOG(DEBUGLOG_SAIL_LOG_NOUART, "PduInfoPtr-> SduDataPtr:\r\n");
	DEBUG_LOG( SAIL_INFO, "DataLength:%d\r\n",DataLength);
	for(int i=0; i<DataLength; i++){
		DEBUG_LOG( SAIL_INFO, "0x%x\r\n",Data[i]);
	}
}

void CanTest_GetCurrentTime(uint8 ControllerId, Can_TimeStampType timeStampPtr)
{
    DEBUG_LOG( SAIL_INFO, "%s: For Controller %d Current time %d:%d\r\n", __func__, ControllerId, timeStampPtr.seconds, timeStampPtr.nanoseconds);
}

void CanTest_ControllerBusOff(uint8 ControllerId)
{
    DEBUG_LOG( SAIL_INFO, "For Controller %d %s is invoked\r\n", ControllerId, __func__);
}

void CanTest_ControllerMode(uint8 ControllerId, Can_ControllerStateType ControllerMode)
{
    DEBUG_LOG( SAIL_INFO, "%s: CtrlId=%d, mode= %d\r\n", __func__, ControllerId, ControllerMode);
}

void CanTest_ControllerErrorStatePassive (uint8 ControllerId, uint16 RxErrorCounter, uint16 TxErrorCounter)
{
	DEBUG_LOG( SAIL_INFO, "For Controller %d %s is invoked\r\n with RxErrorCounter: %d and TxErrorCounter: %d\r\n", ControllerId, __func__, RxErrorCounter, TxErrorCounter);
}

void CanTest_ErrorNotification (uint8 ControllerId, Can_ErrorType Can_ErrorType)
{
    DEBUG_LOG( SAIL_INFO, "For Controller %d %s is invoked with ErrorType: %d\r\n", ControllerId, __func__, Can_ErrorType);
}

void CanTest_FusaReport (uint8 ControllerId/*, FUSAQueueMsgType CanFUSAMsg*/)
{
//    DEBUG_LOG( SAIL_INFO, "For Controller %d %s is invoked with:\r\n", ControllerId, __func__);
//    DEBUG_LOG( SAIL_INFO, "eEventId = %d, eEventDomain = %d, CanFaultSeverity = %d, eEventType = %d, CanFaultCode= %d, ApiID= %d:\r\n",
//        CanFUSAMsg.eEventId, CanFUSAMsg.eEventDomain, CanFUSAMsg.eEventSource,CanFUSAMsg.eEventType, CanFUSAMsg.ucErrData[0], CanFUSAMsg.ucErrData[1]);
}

void CanTest_Tcan1044_WakeupIndication(uint8 TrcvId, uint8 ControllerId)
{
    DEBUG_LOG( SAIL_INFO, "For Controller %d %s is invoked with TrcvId: %d\r\n", ControllerId, __func__, TrcvId);
}

void CanTest_Tcan1146_WakeupIndication(uint8 TrcvId, uint8 ControllerId)
{
    DEBUG_LOG( SAIL_INFO, "For Controller %d %s is invoked with TrcvId: %d\r\n", ControllerId, __func__, TrcvId);
}

void CanTest_Register(uint32 xCanClientHandle, Std_ReturnType Status)
{
    DEBUG_LOG( SAIL_INFO, " %s ClientHandle 0x%x invoked with status: %d\r\n", __func__, xCanClientHandle, Status);
    if (Status == E_OK)
    {
        for (int i = 0; i < TEST_MAX_CLIENT_CNT; i++)
        {
        	if(Test_CanClientHandle[i] == 0)
        	{
        		Test_CanClientHandle[i] = xCanClientHandle;
                DEBUG_LOG( SAIL_INFO, " %s client No.%d is redisted\r\n", __func__, i);
                break;
            }
        }
    }
}

void CanTest_Deregister(uint32 xCanClientHandle, Std_ReturnType Status)
{
    DEBUG_LOG( SAIL_INFO, " %s ClientHandle 0x%x invoked with status: %d\r\n", __func__, xCanClientHandle, Status);
    if (Status == E_OK)
    {
        for (int i = 0; i < TEST_MAX_CLIENT_CNT; i++)
        {
        	if(Test_CanClientHandle[i] == xCanClientHandle)
        	{
        		Test_CanClientHandle[i] = 0;
                DEBUG_LOG( SAIL_INFO, " %s client No.%d is deregisted\r\n", __func__, i);
                break;
            }
        }
    }
}

void CanTest_RegisterCallBacks(void)
{
	xCan_ClientCtxt_Type CanTestNotifiers = {NULL};

	CanTestNotifiers.xCanSrv_Cb_Reg_Client = CanTest_Register;
	CanTestNotifiers.xCanSrv_Cb_Dereg_Client = CanTest_Deregister;
	CanTestNotifiers.xCanSrv_Cb_TxConfirmation = CanTest_TxConfirmation;
	CanTestNotifiers.xCanSrv_Cb_RxIndication = CanTest_RxIndication;
	CanTestNotifiers.xCanSrv_Cb_ControllerMode = CanTest_ControllerMode;
	CanTestNotifiers.xCanSrv_Cb_ControllerBusOff = CanTest_ControllerBusOff;
	CanTestNotifiers.xCanSrv_Cb_ControllerErrorStatePassive = CanTest_ControllerErrorStatePassive;
	CanTestNotifiers.xCanSrv_Cb_GetCurrentTimeStamp = CanTest_GetCurrentTime;
	CanTestNotifiers.xCanSrv_Cb_ErrorNotification = CanTest_ErrorNotification;
	// CanTestNotifiers.xCanSrv_Cb_ReportFusaError = CanTest_FusaReport;
	CanTestNotifiers.xCanSrv_Cb_184_Tcan1044_WakeupIndication = CanTest_Tcan1044_WakeupIndication;
	CanTestNotifiers.xCanSrv_Cb_184_Tcan1146_WakeupIndication = CanTest_Tcan1146_WakeupIndication;

    /* Test app subcribes all HOHs */
    for (uint8 i = 0; i < MAX_HW_OBJ_CNT; i++)
    {
        CanTestNotifiers.HwObjId[i] = i;
    }
	CanTestNotifiers.HwObjCnt= MAX_HW_OBJ_CNT;

	xCanSrv_Register_Client(CanTestNotifiers);

}

void CanTest_DeRegister_All_Clients(void)
{
    for (int i = 0; i < TEST_MAX_CLIENT_CNT; i++)
    {
        if(Test_CanClientHandle[i] != 0)
        {
            DEBUG_LOG( SAIL_INFO, " %s Deregister client No.%d\r\n", __func__, i);
            xCanSrv_Deregister_Client(Test_CanClientHandle[i]);
            Test_CanClientHandle[i] = 0;
        }
    }

}

TESTerrorType_e can_mcal_test(char *cmd)
{
	DEBUG_LOG(SAIL_ERROR, "%s : %d Entered string : %s\r\n", __func__, __LINE__, cmd);
	// Skip the first token if it's "can"
	char *token = strtok(cmd," ");
	if(token != NULL && strcmp(token, "can") == 0)
	{
		input_cmd = strtok(NULL,"");
	}
	else {
		input_cmd = cmd;
	}
	//DEBUG_LOG(SAIL_ERROR, "%s : %d input_cmd : %s\r\n", __func__, __LINE__, input_cmd);
    Can_Test();
	return MODULE_TEST_PASSED;
}


/********************************************************************************
** Syntax           : void Can_Test(void)                         **
**                                                                             **
**                                                                             **
**                                                                             **
** Description      : CAN Test Wrapper fun 									   **
**                    									                       **
**                                                                             **
** Parameters(in)   : None                                                     **
**                                                                             **
** Parameters (out) : None                                                     **
**                                                                             **
** Parameters (in-out):                                                        **
**                                                                             **
** Return value     : None			                                           **
**                                                                             **
********************************************************************************/
void Can_Test(void)
{

	// DEBUG_LOG( SAIL_INFO, "*********************************************************************\r\n");
	// DEBUG_LOG( SAIL_INFO, "Entering Can Testapp\r\n");
	// DEBUG_LOG( SAIL_INFO, "*********************************************************************\r\n\r\n\r\n\r\n");
	Std_ReturnType ret = E_OK;
	acceptCommand = 1;
	nextFind = pucAPPL_SAILTF_gettoken((uint8 *)input_cmd);
	input_cmd = NULL;
	while (nextFind != NULL){
		if (ucAPPL_SAILTF_stricmp("-t", (char*)nextFind)) {
			if(CanGetApi() == E_NOT_OK){
				acceptCommand = 0;
				break;
			}
		}
		else if(ucAPPL_SAILTF_stricmp("-config", (char*)nextFind)){
			//select the configuration
			CanGetConfig();

		}
		else if(ucAPPL_SAILTF_stricmp("-count", (char*)nextFind)){
			//Main function repeat
			CanGetCount();

		}
		else if(ucAPPL_SAILTF_stricmp("-ct", (char*)nextFind)){
			CanCoverageTest();
			acceptCommand = 0;
			break;
		}
		else if(ucAPPL_SAILTF_stricmp("-init", (char*)nextFind)){
#if(CAN_COVERAGE_TEST == STD_ON)
			CppTest_InitializeRuntime();
#endif
			acceptCommand = 0;
			break;
		}
		else if(ucAPPL_SAILTF_stricmp("-fusa", (char*)nextFind)){
			CT_Fusa();
			acceptCommand = 0;
			break;
		}
		else if(ucAPPL_SAILTF_stricmp("-drv", (char*)nextFind)){
			CT_CanDrvISR();
			acceptCommand = 0;
			break;
		}
		else if(ucAPPL_SAILTF_stricmp("-wt", (char*)nextFind)){
			CanWriteTest();
			acceptCommand = 0;
			break;
		}
		else if(ucAPPL_SAILTF_stricmp("-c", (char*)nextFind)){
			//Enable controllers
			CanGetController();
			continue;
		}
		else if(ucAPPL_SAILTF_stricmp("-b", (char*)nextFind)){
			//baudrate config ID
			CanGetBaudrate();
		}
		else if(ucAPPL_SAILTF_stricmp("-obj", (char*)nextFind)){
			//Enable Objects
			CanGetObjects();
			continue;
		}
		else if(ucAPPL_SAILTF_stricmp("-s", (char*)nextFind)){
			// Timeout Fault
			CanGetTimeoutFault();
		}
		else if(ucAPPL_SAILTF_stricmp("-mramindex", (char*)nextFind)){
			//Message Ram Index
			CanGetMramIndex();
		}
		else if(ucAPPL_SAILTF_stricmp("-o", (char*)nextFind)){
			//Mode
			CanGetMode();
		}
		else if(ucAPPL_SAILTF_stricmp("-i", (char*)nextFind)){
			CanGetSubTestTimeout();
		}
		else if(ucAPPL_SAILTF_stricmp("-period", (char*)nextFind)){
			//main function period
			CanGetPeriod();
		}
		else if(ucAPPL_SAILTF_stricmp("-pdu", (char*)nextFind)){
			CanGetPdu();
		}
		else if(ucAPPL_SAILTF_stricmp("-r", (char*)nextFind)){
			//Main function repeat
			CanGetAddr();
		}
		else if(ucAPPL_SAILTF_stricmp("-regfrom", (char*)nextFind)){
			//Main function repeat
			CanGetFromAddr();
		}
		else if(ucAPPL_SAILTF_stricmp("-regto", (char*)nextFind)){
			//Main function repeat
			CanGetToAddr();
		}
		else if(ucAPPL_SAILTF_stricmp("-v", (char*)nextFind)){
			//Main function repeat
			CanGetRegValue();
		}
		/*else if(APPL_Shell_stricmp("-datalength", (char*)nextFind)){
			CanGetDataLength();
		}*/
		else if(ucAPPL_SAILTF_stricmp("-null", (char*)nextFind)){
			CanCheckNull();
		}
		else{
			DEBUG_LOG( SAIL_INFO, "Incorrect option\r\n");
			acceptCommand = 0;
			break;
		}
		nextFind = pucAPPL_SAILTF_gettoken(NULL);
	}
	if(acceptCommand){
		ret = CanTCApis[runApi].Func();
#if(CAN_COVERAGE_TEST == STD_ON)
		CppTest_SendCoverage();
#endif
	}
	// DEBUG_LOG( SAIL_INFO, "*********************************************************************\r\n");
	DEBUG_LOG( SAIL_INFO, "Exiting Can Testapp with return : %d\r\n",ret);
	// DEBUG_LOG( SAIL_INFO, "*********************************************************************\r\n\r\n\r\n\r\n");
}
/********************************************************************************
** Description      : CAN Test Wrapper fun 									   **
**                                                                             **
** Parameters(in)   : None                                                     **
**                                                                             **
** Parameters (out) : None                                                     **
**                                                                             **
** Parameters (in-out):                                                        **
**                                                                             **
** Return value     : Status of excecution			                                           **
**                                                                             **
********************************************************************************/
Std_ReturnType CanTC_ReadRegister(void){
	DEBUG_LOG( SAIL_INFO, "At register address 0x%x value is: 0x%x \r\n", addr, in_dword((uint32*)(addr)));
	return E_OK;
}
Std_ReturnType CanTC_ReadRegRange(void){
	DEBUG_LOG( SAIL_INFO, "From the register address 0x%x to the address 0x%x the data are:\r\n", startAddr, endAddr);
	while( startAddr <= endAddr ){
		DEBUG_LOG( SAIL_INFO, "0x%x =>    0x%x \r\n", startAddr, in_dword((uint32*)(startAddr)));
		startAddr+=4;
	}
	return E_OK;
}
Std_ReturnType CanTC_SetRegister(void){
	out_dword((uint32*) addr, value);
	DEBUG_LOG( SAIL_INFO, "Register address 0x%x updated value is: 0x%x \r\n", addr, in_dword((uint32*)(addr)));
	return E_OK;
}
Std_ReturnType CanTC_SetCanCtrlInfo(void){
	for(int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			Can_CtrlInfo[Controller].CanCtrlState = Transition;
		}
	}
	return E_OK;
}

Std_ReturnType CanTC_Init(void)
{
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_Init\r\n");
    CanTest_RegisterCallBacks();
	DEBUG_LOG( SAIL_INFO, "Can Test Callback Registration Done\r\n");
	return E_OK;
}

#if(CAN_VERSION_API_ENABLE == STD_ON)
Std_ReturnType CanTC_GetVersionInfo(void)
{
	Std_ReturnType Status = E_NOT_OK;
	Std_VersionInfoType * pInfoVersion = &infoversion;
	DetReportedOnCan = 0;
	if(null){
		pInfoVersion = NULL_PTR;
	}
	Can_GetVersionInfo(pInfoVersion);
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_GetVersionInfo\r\n");
	if(DetReportedOnCan == 1){
		DEBUG_LOG(SAIL_ERROR, "Can_GetVersionInfo failed with DET\r\n");
	}
	else{
		if(pInfoVersion != NULL_PTR){
			DEBUG_LOG( SAIL_INFO, "Version info API returned with \r\nvendorID: %d  \r\nmoduleID: %d \r\nsw_major_version: %d \r\nsw_minor_version: %d, and sw_patch_version: %d\r\n",
			pInfoVersion->vendorID, pInfoVersion->moduleID, pInfoVersion->sw_major_version, pInfoVersion->sw_minor_version, pInfoVersion->sw_patch_version);
			if(pInfoVersion->vendorID == 184 && pInfoVersion->moduleID == 80 && pInfoVersion->sw_major_version == 1 && pInfoVersion->sw_minor_version == 0 && pInfoVersion->sw_patch_version == 0)
			{
				DEBUG_LOG( SAIL_INFO, "Version information returned is correct\r\n");
				Status = E_OK;
			}
			else
			{
				DEBUG_LOG(SAIL_ERROR, "Version information returned is incorrect\r\n");
				Status = E_NOT_OK;
			}
		}
	}
	return Status;
}
#endif

#if(CAN_SET_BAUDRATE_API == STD_ON)
Std_ReturnType CanTC_SetBaudrate(void){
	uint8 Status, retValue = E_OK;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_SetBaudrate\r\n");
	for(int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "Baudrate registers before invoking xCanSrv_SetBaudrate for controller %d\r\n", Controller);
			DEBUG_LOG( SAIL_INFO, "For Controller %d, register NBTP is initialized with value: 0x%x \r\n", Controller, IN_CAN_HW_REG(Controller,NBTP));
			DEBUG_LOG( SAIL_INFO, "For Controller %d, register DBTP is initialized with value: 0x%x \r\n", Controller, IN_CAN_HW_REG(Controller,DBTP));
			DEBUG_LOG( SAIL_INFO, "For Controller %d, register TDCR is initialized with value: 0x%x \r\n", Controller, IN_CAN_HW_REG(Controller,TDCR));
			DetReportedOnCan = 0;
			Status = xCanSrv_SetBaudrate(Controller, BaudRateConfigID);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "xCanSrv_SetBaudrate failed with DET\r\n");
			}
			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "Baudrate is successfully updated for controller: %d\r\n", Controller);
			}
			DEBUG_LOG( SAIL_INFO, "Baudrate registers after invoking xCanSrv_SetBaudrate for controller %d\r\n", Controller);
			DEBUG_LOG( SAIL_INFO, "For Controller %d, register NBTP is initialized with value: 0x%x \r\n", Controller, IN_CAN_HW_REG(Controller,NBTP));
			DEBUG_LOG( SAIL_INFO, "For Controller %d, register DBTP is initialized with value: 0x%x \r\n", Controller, IN_CAN_HW_REG(Controller,DBTP));
			DEBUG_LOG( SAIL_INFO, "For Controller %d, register TDCR is initialized with value: 0x%x \r\n", Controller, IN_CAN_HW_REG(Controller,TDCR));
		}
	}
	return retValue;
}
#endif

Std_ReturnType CanTC_SetControllerMode(void)
{
	uint8 Status= E_OK, retValue = E_OK;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_SetControllerMode\r\n");
	for(int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d requesting mode transition to: %d \r\n", Controller, Transition);
			DetReportedOnCan = 0;
			Status = xCanSrv_SetControllerMode(Controller, Transition);
			if(DetReportedOnCan == 1){
				DEBUG_LOG(SAIL_ERROR, "CanTC_SetControllerMode failed with DET\r\n");
				retValue = E_NOT_OK;
			}

			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For Controller %d mode updated to: %d\r\n", Controller, Transition);
			}
		}
	}
	return retValue;
}

Std_ReturnType CanTC_SetControllerMode_Sleep(void)
{
	uint8 Status= E_OK, retValue = E_OK;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_SetControllerMode\r\n");
	for(int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d requesting mode transition to: %d \r\n", Controller, Transition);
			DetReportedOnCan = 0;
			Status = xCanSrv_SetControllerMode(Controller, CAN_CS_SLEEP);
			if(DetReportedOnCan == 1){
				DEBUG_LOG(SAIL_ERROR, "CanTC_SetControllerMode failed with DET\r\n");
				retValue = E_NOT_OK;
			}

			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For Controller %d mode updated to: %d\r\n", Controller, Transition);
			}
		}
	}
	return retValue;
}

Std_ReturnType CanTC_DisableControllerInterrupts(void)
{
	uint8 retValue = E_OK;
	uint8 Controller;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_DisableControllerInterrupts\r\n");
	for (uint32 i =0; i<CanCount; i++){
		for(Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
			if(CanController[Controller] == 1){
				DEBUG_LOG( SAIL_INFO, "For Controller %d Disabling the Interrupts \r\n", Controller);
				DetReportedOnCan = 0;
				Can_DisableControllerInterrupts(Controller);
				if(DetReportedOnCan == 1){
					retValue = E_NOT_OK;
					DEBUG_LOG(SAIL_ERROR, "Can_DisableControllerInterrupts failed with DET\r\n");
				}
				else{
					DEBUG_LOG( SAIL_INFO, "For Controller %d Interrupts Disabled \r\n", Controller);
				}
			}
		}
	}
	return retValue;
}

Std_ReturnType CanTC_EnableControllerInterrupts(void)
{
	uint8 retValue= E_OK;
	uint8 Controller;
    uint32 i;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_EnableControllerInterrupts\r\n");
	for (i =0; i<CanCount; i++){
		for(Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
			if(CanController[Controller] == 1){
				DEBUG_LOG( SAIL_INFO, "For Controller %d Enabling the Interrupts \r\n", Controller);
				DetReportedOnCan = 0;
				Can_EnableControllerInterrupts(Controller);
				if(DetReportedOnCan == 1){
					retValue = E_NOT_OK;
					DEBUG_LOG(SAIL_ERROR, "Can_EnableControllerInterrupts failed with DET\r\n");
				}
				else{
					DEBUG_LOG( SAIL_INFO, "For Controller %d Interrupts Enabled \r\n", Controller);
				}
			}
		}
	}
	return retValue;
}

Std_ReturnType CanTC_ExternalLoopback_Enable(void)
{
	DEBUG_LOG( SAIL_ERROR, "Invoked %s\r\n",__func__);
	uint8 retValue= E_OK;
	uint8 Controller;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_ExternalLoopback_Enable\r\n");
	for(Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d Enabling the ExternalLoopback Enable \r\n", Controller);
			Can_LoopBackType *Loopback = (Can_LoopBackType *)&Config[configIndex]->CanActiveCtrPtr->CanLoopBackEnable;
			*(Can_LoopBackType *)Loopback = CAN_LOOPBACK_EXTERNAL;
		}
	}
	return retValue;
}

Std_ReturnType CanTC_InternalLoopback_Enable(void)
{
	uint8 retValue= E_OK;
	uint8 Controller;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_InternalLoopback_Enable\r\n");
	for(Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d Enabling the InternalLoopback Enable \r\n", Controller);
			Can_LoopBackType *Loopback = (Can_LoopBackType *)&Config[configIndex]->CanActiveCtrPtr->CanLoopBackEnable;
			*(Can_LoopBackType *)Loopback = CAN_LOOPBACK_INTERNAL;
		}
	}
	return retValue;
}

Std_ReturnType CanTC_Loopback_Disable(void)
{
	uint8 retValue= E_OK;
	uint8 Controller;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_Loopback_Disable\r\n");
	for(Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d Enabling the Loopback Disable \r\n", Controller);
			Can_LoopBackType *Loopback = (Can_LoopBackType *)&Config[configIndex]->CanActiveCtrPtr->CanLoopBackEnable;
			*(Can_LoopBackType *)Loopback = CAN_LOOPBACK_DISABLED;
		}
	}
	return retValue;
}

/* inject unique PDU ID for each write */
static Std_ReturnType Cantest_write(Can_HwHandleType Hth, const Can_PduType* PduInfo)
{
    Std_ReturnType Status= E_OK;
    CanTest_TxPduId ++;
    const Can_PduType Tx_PduInfo = { CanTest_TxPduId,
                                     PduInfo->length,
                                     PduInfo->id,
                                     PduInfo->sdu };

    Status = xCanSrv_Write(Hth, &Tx_PduInfo);

    return Status;
}

Std_ReturnType CanTC_Write_TxFIFO(void)
{
	uint8 Status= E_OK;
	uint8 j;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_Write\r\n");

	pduIndex = CAN_PDU_INDEX_STD_CAN; // PDU index 0 is meant for standard frame with classical CAN

	CanHwGetObject();

	for(int i =0; i< CanCount; i++){
		DetReportedOnCan = 0;
		vFreeRTOSTaskDelay(CanMainFunctionPeriod);
		for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
			if(Hoh[j] == 1){
				// DEBUG_LOG( SAIL_INFO, "On the object %d, %d bytes message is transmitting with Can ID: 0x%x and \r\n",
				// j, PduInfo[pduIndex]->length, PduInfo[pduIndex]->id);
				// if(PduInfo[pduIndex]->sdu != NULL){
				// 	DEBUG_LOG( SAIL_INFO, "Data: \r\n");
				// 	for(uint8 k=0; k < PduInfo[pduIndex]->length; k++){
				// 		DEBUG_LOG( SAIL_INFO, "  0x%x\r\n", PduInfo[pduIndex]->sdu[k]);
				// 	}
				// }
				// else{
				// 	DEBUG_LOG( SAIL_INFO, "SDU Data is empty \r\n");
				// }
				Status = Cantest_write(j, PduInfo[pduIndex]);
				if(DetReportedOnCan == 1){
					DEBUG_LOG(SAIL_ERROR, "xCanSrv_Write failed with DET\r\n");
				}
				else{
					if(Status == E_OK){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write Successful on object %d with swPduHandle %d\r\n", j, CanTest_TxPduId);
					}
					else if(Status == CAN_BUSY){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed  on object %d with swPduHandle %d for hitting Can Busy\r\n", j, CanTest_TxPduId);
					}
					else{
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed, returned E_NOT_OK\r\n");
					}
				}
			}
		}
	}
	return Status;
}

Std_ReturnType CanTC_Write_TxClassicalStandardID(void)
{
	uint8 Status= E_OK;
	uint8 j;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_Write\r\n");

	pduIndex = CAN_PDU_INDEX_STD_CAN; // PDU index 0 is meant for standard frame with classical CAN

	CanHwGetObject();

	for(int i =0; i< CanCount; i++){
		DetReportedOnCan = 0;
		vFreeRTOSTaskDelay(CanMainFunctionPeriod);
		for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
			if(Hoh[j] == 1){
				// DEBUG_LOG( SAIL_INFO, "On the object %d, %d bytes message is transmitting with Can ID: 0x%x and \r\n",
				// j, PduInfo[pduIndex]->length, PduInfo[pduIndex]->id);
				// if(PduInfo[pduIndex]->sdu != NULL){
				// 	DEBUG_LOG( SAIL_INFO, "Data: \r\n");
				// 	for(uint8 k=0; k < PduInfo[pduIndex]->length; k++){
				// 		DEBUG_LOG( SAIL_INFO, "  0x%x\r\n", PduInfo[pduIndex]->sdu[k]);
				// 	}
				// }
				// else{
				// 	DEBUG_LOG( SAIL_INFO, "SDU Data is empty \r\n");
				// }
				Status = Cantest_write(j, PduInfo[pduIndex]);
				if(DetReportedOnCan == 1){
					DEBUG_LOG(SAIL_ERROR, "xCanSrv_Write failed with DET\r\n");
				}
				else{
					if(Status == E_OK){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write Successful on object %d with swPduHandle %d\r\n", j, CanTest_TxPduId);
					}
					else if(Status == CAN_BUSY){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed  on object %d with swPduHandle %d for hitting Can Busy\r\n", j, CanTest_TxPduId);
					}
					else{
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed, returned E_NOT_OK\r\n");
					}
				}
			}
		}
	}
	return Status;
}

Std_ReturnType CanTC_Write_TxClassicalExtendedID(void)
{
	uint8 Status= E_OK;
	uint8 j;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_Write\r\n");

	pduIndex = CAN_PDU_INDEX_EXT_CAN; // PDU index 2 is meant for extended frame with classical CAN

	CanHwGetObject();

	for(int i =0; i< CanCount; i++){
		DetReportedOnCan = 0;
		vFreeRTOSTaskDelay(CanMainFunctionPeriod);
		for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
			if(Hoh[j] == 1){
				// DEBUG_LOG( SAIL_INFO, "On the object %d, %d bytes message is transmitting with Can ID: 0x%x and \r\n",
				// j, PduInfo[pduIndex]->length, PduInfo[pduIndex]->id);
				// if(PduInfo[pduIndex]->sdu != NULL){
				// 	DEBUG_LOG( SAIL_INFO, "Data: \r\n");
				// 	for(uint8 k=0; k < PduInfo[pduIndex]->length; k++){
				// 		DEBUG_LOG( SAIL_INFO, "  0x%x\r\n", PduInfo[pduIndex]->sdu[k]);
				// 	}
				// }
				// else{
				// 	DEBUG_LOG( SAIL_INFO, "SDU Data is empty \r\n");
				// }
				Status = Cantest_write(j, PduInfo[pduIndex]);
				if(DetReportedOnCan == 1){
					DEBUG_LOG(SAIL_ERROR, "xCanSrv_Write failed with DET\r\n");
				}
				else{
					if(Status == E_OK){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write Successful on object %d with swPduHandle %d \r\n", j, CanTest_TxPduId);
					}
					else if(Status == CAN_BUSY){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed  on object %d with swPduHandle %d for hitting Can Busy\r\n", j, CanTest_TxPduId);
					}
					else{
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed, returned E_NOT_OK\r\n");
					}
				}
			}
		}
	}
	return Status;
}

Std_ReturnType CanTC_Write_TxFdStandardID(void)
{
	uint8 Status= E_OK;
	uint8 j;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_Write\r\n");

	pduIndex = CAN_PDU_INDEX_FD_STD_CAN; // PDU index 1 is meant for Standard frame with FD CAN

	CanHwGetObject();

	for(int i =0; i< CanCount; i++){
		DetReportedOnCan = 0;
		vFreeRTOSTaskDelay(CanMainFunctionPeriod);
		for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
			if(Hoh[j] == 1){
				// DEBUG_LOG( SAIL_INFO, "On the object %d, %d bytes message is transmitting with Can ID: 0x%x and \r\n",
				// j, PduInfo[pduIndex]->length, PduInfo[pduIndex]->id);
				// if(PduInfo[pduIndex]->sdu != NULL){
				// 	DEBUG_LOG( SAIL_INFO, "Data: \r\n");
				// 	for(uint8 k=0; k < PduInfo[pduIndex]->length; k++){
				// 		DEBUG_LOG( SAIL_INFO, "  0x%x\r\n", PduInfo[pduIndex]->sdu[k]);
				// 	}
				// }
				// else{
				// 	DEBUG_LOG( SAIL_INFO, "SDU Data is empty \r\n");
				// }
				Status = Cantest_write(j, PduInfo[pduIndex]);
				if(DetReportedOnCan == 1){
					DEBUG_LOG(SAIL_ERROR, "xCanSrv_Write failed with DET\r\n");
				}
				else{
					if(Status == E_OK){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write Successful on object %d with swPduHandle %d\r\n", j, CanTest_TxPduId);
					}
					else if(Status == CAN_BUSY){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed  on object %d with swPduHandle %d for hitting Can Busy\r\n", j, CanTest_TxPduId);
					}
					else{
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed, returned E_NOT_OK\r\n");
					}
				}
			}
		}
	}
	return Status;
}

Std_ReturnType CanTC_Write_TxFdExtendedID(void)
{
	uint8 Status= E_OK;
	uint8 j;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_Write\r\n");

	pduIndex = CAN_PDU_INDEX_FD_EXT_CAN; // PDU index 3 is meant for Extended frame with FD CAN

	CanHwGetObject();

	for(int i =0; i< CanCount; i++){
		DetReportedOnCan = 0;
		vFreeRTOSTaskDelay(CanMainFunctionPeriod);
		for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
			if(Hoh[j] == 1){
				// DEBUG_LOG( SAIL_INFO, "On the object %d, %d bytes message is transmitting with Can ID: 0x%x and \r\n",
				// j, PduInfo[pduIndex]->length, PduInfo[pduIndex]->id);
				// if(PduInfo[pduIndex]->sdu != NULL){
				// 	DEBUG_LOG( SAIL_INFO, "Data: \r\n");
				// 	for(uint8 k=0; k < PduInfo[pduIndex]->length; k++){
				// 		DEBUG_LOG( SAIL_INFO, "  0x%x\r\n", PduInfo[pduIndex]->sdu[k]);
				// 	}
				// }
				// else{
				// 	DEBUG_LOG( SAIL_INFO, "SDU Data is empty \r\n");
				// }
				Status = Cantest_write(j, PduInfo[pduIndex]);
				if(DetReportedOnCan == 1){
					DEBUG_LOG(SAIL_ERROR, "xCanSrv_Write failed with DET\r\n");
				}
				else{
					if(Status == E_OK){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write Successful on object %d with swPduHandle %d\r\n", j, CanTest_TxPduId);
					}
					else if(Status == CAN_BUSY){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed  on object %d with swPduHandle %d for hitting Can Busy\r\n", j, CanTest_TxPduId);
					}
					else{
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed, returned E_NOT_OK\r\n");
					}
				}
			}
		}
	}
	return Status;
}

Std_ReturnType CanTC_Write_TxAlltypesofFrames(void)
{
	uint8 Status= E_OK;
	uint8 j;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_Write\r\n");

	CanHwGetObject();

	// PDU index from 0 to 4 is having all set of CAN frames with different DLC lengths
	for(pduIndex = 0; pduIndex < CAN_PDU_INDEX_VALID_LENGTH; pduIndex++){
		for(int i =0; i< CanCount; i++){
			DetReportedOnCan = 0;
			vFreeRTOSTaskDelay(CanMainFunctionPeriod);
			for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
				if(Hoh[j] == 1){
					// DEBUG_LOG( SAIL_INFO, "On the object %d, %d bytes message is transmitting with Can ID: 0x%x and \r\n",
					// j, PduInfo[pduIndex]->length, PduInfo[pduIndex]->id);
					// if(PduInfo[pduIndex]->sdu != NULL){
					// 	DEBUG_LOG( SAIL_INFO, "Data: \r\n");
					// 	for(uint8 k=0; k < PduInfo[pduIndex]->length; k++){
					// 		DEBUG_LOG( SAIL_INFO, "  0x%x\r\n", PduInfo[pduIndex]->sdu[k]);
					// 	}
					// }
					// else{
					// 	DEBUG_LOG( SAIL_INFO, "SDU Data is empty \r\n");
					// }
					Status = Cantest_write(j, PduInfo[pduIndex]);
					if(DetReportedOnCan == 1){
						DEBUG_LOG(SAIL_ERROR, "xCanSrv_Write failed with DET\r\n");
					}
					else{
						if(Status == E_OK){
							DEBUG_LOG( SAIL_INFO, "xCanSrv_Write Successful on object %d with swPduHandle %d\r\n", j, CanTest_TxPduId);
						}
						else if(Status == CAN_BUSY){
							DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed  on object %d with swPduHandle %d for hitting Can Busy\r\n", j, CanTest_TxPduId);
						}
						else{
							DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed, returned E_NOT_OK\r\n");
						}
					}
				}
			}
		}
	}
	return Status;
}

Std_ReturnType CanTC_Write(void)
{
	uint8 Status= E_OK;
	uint8 j;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_Write\r\n");
	for(int i =0; i< CanCount; i++){
		DetReportedOnCan = 0;
		vFreeRTOSTaskDelay(CanMainFunctionPeriod);
		for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
			if(Hoh[j] == 1){
				// DEBUG_LOG( SAIL_INFO, "On the object %d, %d bytes message is transmitting with Can ID: 0x%x and \r\n",
				// j, PduInfo[pduIndex]->length, PduInfo[pduIndex]->id);
				// if(PduInfo[pduIndex]->sdu != NULL){
				// 	DEBUG_LOG( SAIL_INFO, "Data: \r\n");
				// 	for(uint8 k=0; k < PduInfo[pduIndex]->length; k++){
				// 		DEBUG_LOG( SAIL_INFO, "  0x%x\r\n", PduInfo[pduIndex]->sdu[k]);
				// 	}
				// }
				// else{
				// 	DEBUG_LOG( SAIL_INFO, "SDU Data is empty \r\n");
				// }
				Status = Cantest_write(j, PduInfo[pduIndex]);
				if(DetReportedOnCan == 1){
					DEBUG_LOG(SAIL_ERROR, "xCanSrv_Write failed with DET\r\n");
				}
				else{
					if(Status == E_OK){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write Successful on object %d with swPduHandle %d\r\n", j, CanTest_TxPduId);
					}
					else if(Status == CAN_BUSY){
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed  on object %d with swPduHandle %d for hitting Can Busy\r\n", j, CanTest_TxPduId);
					}
					else{
						DEBUG_LOG( SAIL_INFO, "xCanSrv_Write failed, returned E_NOT_OK\r\n");
					}
				}
			}
		}
	}
	return Status;
}

Std_ReturnType CanTC_MainFunction_Write(void)
{
	uint8 Status= E_OK;
	DetReportedOnCan = 0;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_MainFunction_Write\r\n");
	DEBUG_LOG( SAIL_INFO, "Can_MainFunction_Write will be invoked at the interval of %dus for %d times\r\n",
	CanMainFunctionPeriod, CanCount);
	for(int i =0; i< CanCount; i++){
		vFreeRTOSTaskDelay(CanMainFunctionPeriod);
		xCanSrv_Can_MainFunction_Write();
		if(DetReportedOnCan == 1){
			DEBUG_LOG( SAIL_ERROR, "Can_MainFunction_Write failed with DET\r\n");
			break;
		}
	}

	return Status;
}

Std_ReturnType CanTC_MainFunction_Read(void)
{
	uint8 Status= E_OK;
	DetReportedOnCan = 0;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_MainFunction_Read\r\n");
	DEBUG_LOG( SAIL_INFO, "Can_MainFunction_Read will be invoked at the interval of %dus for %d times\r\n",
	CanMainFunctionPeriod, CanCount);
	for(int i =0; i< CanCount; i++){
		vFreeRTOSTaskDelay(CanMainFunctionPeriod);
		xCanSrv_Can_MainFunction_Read();
		if(DetReportedOnCan == 1){
			DEBUG_LOG( SAIL_ERROR, "Can_MainFunction_Read failed with DET\r\n");
			break;
		}
	}

	return Status;
}

Std_ReturnType CanTC_MainFunction_BusOff(void)
{
	DEBUG_LOG( SAIL_INFO, "Can_MainFunction_BusOff not supported in SAFERTOS \r\n");
	return E_OK;
}

Std_ReturnType CanTC_MainFunction_Wakeup(void)
{
	DEBUG_LOG( SAIL_INFO, "Can_MainFunction_Wakeup not supported in SAFERTOS \r\n");
	return E_OK;
}

Std_ReturnType CanTC_MainFunction_Mode(void)
{
	DEBUG_LOG( SAIL_INFO, "Can_MainFunction_Mode not supported in SAFERTOS \r\n");
	return E_OK;
}

Std_ReturnType CanTC_CheckWakeup(void)
{
	uint8 Status= E_OK, retValue = E_OK;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_CheckWakeup\r\n");
	for(int Controller = CTRL_ZERO; Controller <= NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d invoking Can_CheckWakeup\r\n", Controller);
			DetReportedOnCan = 0;
			Status = Can_CheckWakeup(Controller);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "Can_CheckWakeup failed with DET\r\n");
			}
			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For Controller %d Can_CheckWakeup returned E_OK \r\n", Controller);
			}
		}
	}
	return retValue;
}

Std_ReturnType CanTC_DeInit(void)
{
    DEBUG_LOG( SAIL_INFO, "CanTC_DeInit not supported in SAFERTOS \r\n");
	return E_OK;
}

Std_ReturnType CanTC_GetControllerErrorState(void)
{
	uint8 Status= E_OK, retValue = E_OK;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_GetControllerErrorState\r\n");
	Can_ErrorStateType ErrorState = CAN_ERRORSTATE_ACTIVE,*pErrorState;
	for(int Controller = CTRL_ZERO; Controller <= NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d invoking xCanSrv_GetControllerErrorState\r\n", Controller);
			DetReportedOnCan = 0;
			pErrorState = &ErrorState;
			if(null == 1){
				pErrorState = NULL_PTR;
			}
			Status = xCanSrv_GetControllerErrorState(Controller, pErrorState);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "xCanSrv_GetControllerErrorState failed with DET\r\n");
			}

			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For Controller %d xCanSrv_GetControllerErrorState returned E_OK with error state: %d \r\n( 0 => CAN_ERRORSTATE_ACTIVE, 1 => CAN_ERRORSTATE_PASSIVE, 2 => CAN_ERRORSTATE_BUSOFF)\r\n", Controller, ErrorState);
			}
		}
	}

	return retValue;
}

Std_ReturnType CanTC_GetControllerMode(void)
{
	uint8 Status= E_OK, retValue = E_OK;
	Can_ControllerStateType ControllerMode = CAN_CS_UNINIT, *pControllerMode;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_GetControllerMode\r\n");
	for(int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d invoking xCanSrv_GetControllerMode\r\n", Controller);
			DetReportedOnCan = 0;
			pControllerMode= &ControllerMode;
			if(null == 1){
				pControllerMode = NULL_PTR;
			}
			Status = xCanSrv_GetControllerMode(Controller, pControllerMode);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "xCanSrv_GetControllerMode failed with DET\r\n");
			}

			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For Controller %d xCanSrv_GetControllerMode returned E_OK with mode %d \r\n(0 => CAN_CS_UNINIT, 1 => CAN_CS_STARTED, 2 => CAN_CS_STOPPED, 3 => CAN_CS_SLEEP) \r\n", Controller, ControllerMode);
			}
		}
	}
	return retValue;
}

Std_ReturnType CanTC_GetControllerRxErrorCounter(void)
{
	uint8 Status= E_OK, retValue = E_OK;
	uint8 RxErrorCounter = 0, *pRxErrorCounter;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_GetControllerRxErrorCounter\r\n");
	for(int Controller = CTRL_ZERO; Controller <= NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d invoking Can_GetControllerRxErrorCounter\r\n", Controller);
			DetReportedOnCan = 0;
			pRxErrorCounter = &RxErrorCounter;
			if(null == 1){
				pRxErrorCounter = NULL_PTR;
			}
			Status = Can_GetControllerRxErrorCounter(Controller, pRxErrorCounter);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "Can_GetControllerRxErrorCounter failed with DET\r\n");
			}
			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For Controller %d Can_GetControllerRxErrorCounter returned E_OK with RX error count %d \r\n", Controller, RxErrorCounter);
			}
		}
	}
	return retValue;
}

Std_ReturnType CanTC_GetControllerTxErrorCounter(void)
{
	uint8 Status= E_OK, retValue = E_OK;
	uint8 TxErrorCounter = 0, *pTxErrorCounter;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_GetControllerTxErrorCounter\r\n");
	for(int Controller = CTRL_ZERO; Controller <= NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d invoking Can_GetControllerTxErrorCounter\r\n", Controller);
			DetReportedOnCan = 0;
			pTxErrorCounter = &TxErrorCounter;
			if(null == 1){
				pTxErrorCounter = NULL_PTR;
			}
			Status = Can_GetControllerTxErrorCounter(Controller, pTxErrorCounter);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "Can_GetControllerTxErrorCounter failed with DET\r\n");
			}
			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For Controller %d Can_GetControllerTxErrorCounter returned E_OK with TX error count %d \r\n", Controller, TxErrorCounter);
			}
		}
	}
	return retValue;
}
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
Std_ReturnType CanTC_GetCurrentTime(void)
{
	uint8 Status= E_OK, retValue = E_OK;
	Can_TimeStampType timeStamp = {0}, *ptimeStamp;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_GetCurrentTime\r\n");
	for(int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			DEBUG_LOG( SAIL_INFO, "For Controller %d invoking Can_GetCurrentTime\r\n", Controller);
			DetReportedOnCan = 0;
			ptimeStamp = &timeStamp;
			if(null == 1){
				ptimeStamp = NULL_PTR;
			}
			Status = Can_GetCurrentTime(Controller, ptimeStamp);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "Can_GetCurrentTime failed with DET\r\n");
			}
			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For Controller %d Can_GetCurrentTime returned the timestamp with time\r\n", Controller);
				DEBUG_LOG( SAIL_INFO, "%d seconds and %d nanoseconds\r\n", timeStamp.seconds, timeStamp.nanoseconds);
			}
		}
	}
	return retValue;
}
#endif
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
Std_ReturnType CanTC_EnableEgressTimeStamp(void)
{
	uint8 retValue = E_OK, j;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_EnableEgressTimeStamp\r\n");
	for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
		if(Hoh[j] == 1){
			DEBUG_LOG( SAIL_INFO, " Can_EnableEgressTimeStamp invoked for TX object: %d\r\n", j);
			DetReportedOnCan = 0;
			Can_EnableEgressTimeStamp(j);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "Can_EnableEgressTimeStamp failed with DET\r\n");
			}
			else{
				DEBUG_LOG( SAIL_INFO, "For TX Object %d timestamp is enabled\r\n", j);
			}
		}
	}
	return retValue;
}
#endif
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
Std_ReturnType CanTC_GetEgressTimeStamp(void)
{
	uint8 Status= E_OK, retValue = E_OK, j;
	Can_TimeStampType timeStamp = {0}, *ptimeStamp;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_GetEgressTimeStamp\r\n");
	for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
		if(Hoh[j] == 1){
			DEBUG_LOG( SAIL_INFO, "For Tx Object %d with PduID %d invoking Can_GetEgressTimeStamp\r\n", j, PduInfo[pduIndex]->swPduHandle);
			DetReportedOnCan = 0;
			ptimeStamp = &timeStamp;
			if(null == 1){
				ptimeStamp = NULL_PTR;
			}
			Status = Can_GetEgressTimeStamp(PduInfo[pduIndex]->swPduHandle, j, ptimeStamp);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "Can_GetEgressTimeStamp failed with DET\r\n");
			}

			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For TX Object %d with PduID %d Can_GetEgressTimeStamp returned the timestamp with time\r\n", j, PduInfo[pduIndex]->swPduHandle);
				DEBUG_LOG( SAIL_INFO, "%d seconds and %d nanoseconds\r\n", timeStamp.seconds, timeStamp.nanoseconds);
			}
		}
	}

	return retValue;
}
#endif
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
Std_ReturnType CanTC_GetIngressTimeStamp(void)
{
	uint8 Status= E_OK, retValue = E_OK, j;
	Can_TimeStampType timeStamp = {0}, *ptimeStamp;
	DEBUG_LOG( SAIL_INFO, "Invoked CanTC_GetIngressTimeStamp\r\n");
	for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
		if(Hoh[j] == 1){
			DEBUG_LOG( SAIL_INFO, "For Rx Object %d invoking Can_GetIngressTimeStamp\r\n", j);
			DetReportedOnCan = 0;

			ptimeStamp = &timeStamp;
			if(null == 1){
				ptimeStamp = NULL_PTR;
			}
			Status = Can_GetIngressTimeStamp( j, ptimeStamp);
			if(DetReportedOnCan == 1){
				retValue = E_NOT_OK;
				DEBUG_LOG(SAIL_ERROR, "Can_GetIngressTimeStamp failed with DET\r\n");
			}
			if(Status == E_OK){
				DEBUG_LOG( SAIL_INFO, "For Rx Object %d Can_GetIngressTimeStamp returned the timestamp with time\r\n", j);
				DEBUG_LOG( SAIL_INFO, "%d seconds and %d nanoseconds\r\n", timeStamp.seconds, timeStamp.nanoseconds);
			}
		}
	}
	return retValue;
}
#endif
#define NO_ERROR 0
Std_ReturnType CanTC_ConfigureInterrupts(void)
{
    DEBUG_LOG( SAIL_INFO, "Interrupts are configured in initialization \r\n");
	return E_OK;
}

Std_ReturnType CanTC_MainFunction_ConfigCheck(void)
{
    DEBUG_LOG( SAIL_INFO, "CanTC_MainFunction_ConfigCheck not supported in SAFERTOS \r\n");
	return E_OK;
}

Std_ReturnType CanTC_MainFunction_SSR_HM(void)
{

    DEBUG_LOG( SAIL_INFO, "CanTC_MainFunction_SSR_HM not supported in SAFERTOS \r\n");
	return E_OK;
}

Std_ReturnType CanTC_Fusa_Timeout_Status(void)
{
	uint8 retValue= E_OK;
// 	DEBUG_LOG(SAIL_ERROR, "CanTC_Fusa_Timeout_Status\r\n");
// 	for (int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++)
// 	{
// 		if (CanController[Controller] == 1)
// 		{
// #if (CAN_FUSA_ENABLE == STD_ON)
// 			CANSS_FUSA_TIMEOUT_STATUS(Controller);
// #endif
// 		}
// 	}
	return retValue;
}

Std_ReturnType CanTC_Fusa_ECC_Status(void)
{
	uint8 retValue= E_OK;
// 	DEBUG_LOG(SAIL_ERROR, "CanTC_Fusa_ECC_Status\r\n");
// 	for (int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++)
// 	{
// 		if (CanController[Controller] == 1)
// 		{
// #if (CAN_FUSA_ENABLE == STD_ON)
// 			CANSS_FUSA_ECC_STATUS(Controller);
// #endif
// 		}
// 	}
	return retValue;
}

Std_ReturnType CanTC_Fusa_Protocol_Status(void)
{
	uint8 retValue= E_OK;
// 	DEBUG_LOG(SAIL_ERROR, "CanTC_Fusa_Protocol_Status\r\n");
// 	for (int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++)
// 	{
// 		if (CanController[Controller] == 1)
// 		{
// #if (CAN_FUSA_ENABLE == STD_ON)
// 			CANSS_FUSA_PROTOCOL_STATUS(Controller);
// #endif
// 		}
// 	}
	return retValue;
}

Std_ReturnType CanTC_TimeoutFaultInjectionTest(void)
{
	uint8 retValue= E_OK;
// 	volatile int testvalue;
// 	DEBUG_LOG(SAIL_ERROR, "CanTC_TimeoutFaultInjectionTest\r\n");
// 	for (int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++)
// 	{
// 		if (CanController[Controller] == 1)
// 		{
// 			DEBUG_LOG(SAIL_ERROR, "For Controller %d invoking CanTC_TimeoutFaultInjectionTest\r\n", Controller);
// 			switch (TimeoutFault)
// 			{
// 			case CAN_FUSA_TIMEOUT_FLT_INJ_AHB_SLAVE_ARB:

// 				if ((AHB_SLAVE_ARB_TIMEOUT_FAULT_INJ)SubTestTimeoutFault == AHB_SLAVE_ARB_TIMEOUT_FAULT_INJ_DMA_MRAM_ARB1)
// 				{
// 					DEBUG_LOG(SAIL_ERROR, "Performing AHB ARB1 Timeout Error injection test \r\n");
// 					/*Enabling Fault Injection */
// 					SET_CAN_HW_FIELD(Controller, CANSS_AHB_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_EN_ARB_1, CANSS_ONE);
// 					/*Starting Fault Injection*/
// 					testvalue = 2;
// 					SET_CAN_HW_FIELD(Controller, CANSS_AHB_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_ARB_1_START, CANSS_ONE);
// 					testvalue = 4;
// 					/*Stopping Fault Injection*/
// 					// SET_CAN_HW_FIELD(Controller,CANSS_AHB_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_ARB_1_STOP,CANSS_ONE);
// 				}
// 				else if ((AHB_SLAVE_ARB_TIMEOUT_FAULT_INJ)SubTestTimeoutFault == AHB_SLAVE_ARB_TIMEOUT_FAULT_INJ_NOC_AHB_ARB2)
// 				{
// 					DEBUG_LOG(SAIL_ERROR, "Performing AHB ARB2 Timeout Error injection test \r\n");
// 					/*Enabling Fault Injection */
// 					SET_CAN_HW_FIELD(Controller, CANSS_AHB_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_EN_ARB_2, CANSS_ONE);
// 					/*Starting Fault Injection*/
// 					SET_CAN_HW_FIELD(Controller, CANSS_AHB_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_ARB_2_START, CANSS_ONE);
// 					/*Stopping Fault Injection*/
// 					// SET_CAN_HW_FIELD(Controller,CANSS_AHB_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_ARB_2_STOP,CANSS_ONE);
// 				}
// 				else
// 				{
// 					DEBUG_LOG(SAIL_ERROR, "Invalid option \r\n");
// 				}
// 				break;
// 			case CAN_FUSA_TIMEOUT_FLT_INJ_DMA_FSM:
// 				DEBUG_LOG(SAIL_ERROR, "Performing DMA FSM Timeout Error injection test for Dma channel %d \r\n", SubTestTimeoutFault);
// 				/*Enabling Fault Injection */
// 				SET_CAN_HW_FIELD_OFFS(Controller, SubTestTimeoutFault, CANSS_DMA_FSM_TIMEOUT_FAULT_INJ_CTRLn, FSM_TIMEOUT_FAULT_INJ_EN, CANSS_ONE);
// 				/*Injecting Fault */
// 				SET_CAN_HW_FIELD_OFFS(Controller, SubTestTimeoutFault, CANSS_DMA_FSM_TIMEOUT_FAULT_INJ_CTRLn, FSM_TIMEOUT_NEXT_STATE_FAULT_IN, CANSS_FIVE);
// 				SET_CAN_HW_FIELD_OFFS(Controller, SubTestTimeoutFault, CANSS_DMA_FSM_TIMEOUT_FAULT_INJ_CTRLn, FSM_TIMEOUT_CURRENT_STATE_FAULT_IN, CANSS_FIVE);
// 				break;
// 			case CAN_FUSA_TIMEOUT_FLT_INJ_DMA_MRAM_AHB:
// 				DEBUG_LOG(SAIL_ERROR, "Performing INT AHB Timeout Error injection test \r\n");
// 				/*Enabling Fault Injection */
// 				SET_CAN_HW_FIELD(Controller, CANSS_INT_AHB_TIMEOUT_FAULT_INJ_CTRL, FAULT_EN, CANSS_ONE);
// 				/*Starting Fault Injection*/
// 				SET_CAN_HW_FIELD(Controller, CANSS_INT_AHB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_START, CANSS_ONE);
// 				/*Stopping Fault Injection*/
// 				// SET_CAN_HW_FIELD(Controller,CANSS_INT_AHB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_STOP, CANSS_ONE);
// 				break;
// 			case CAN_FUSA_TIMEOUT_FLT_INJ_MRAM_ARB:
// 				if ((MRAM_ARBITER_TIMEOUT_FAULT_INJ)SubTestTimeoutFault == MRAM_ARB_TIMEOUT_FAULT_INJ_MCAN_ARB1)
// 				{
// 					DEBUG_LOG(SAIL_ERROR, "Performing MRAM ARB1 Timeout Error injection test\r\n", Controller);
// 					/*Enabling Fault Injection */
// 					SET_CAN_HW_FIELD(Controller, CANSS_MRAM_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_EN_ARB_1, CANSS_ONE);
// 					/*Starting Fault Injection*/
// 					SET_CAN_HW_FIELD(Controller, CANSS_MRAM_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_ARB_1_START, CANSS_ONE);
// 					/*Stopping Fault Injection*/
// 					// SET_CAN_HW_FIELD(Controller,CANSS_MRAM_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_ARB_1_STOP, CANSS_ONE);
// 				}
// 				else if ((MRAM_ARBITER_TIMEOUT_FAULT_INJ)SubTestTimeoutFault == MRAM_ARB_TIMEOUT_FAULT_INJ_DMU_ARB2)
// 				{
// 					DEBUG_LOG(SAIL_ERROR, "Performing MRAM ARB2 Timeout Error injection test\r\n", Controller);
// 					/*Enabling Fault Injection */
// 					SET_CAN_HW_FIELD(Controller, CANSS_MRAM_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_EN_ARB_2, CANSS_ONE);
// 					/*Starting Fault Injection*/
// 					SET_CAN_HW_FIELD(Controller, CANSS_MRAM_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_ARB_2_START, CANSS_ONE);
// 					/*Stopping Fault Injection*/
// 					// SET_CAN_HW_FIELD(Controller,CANSS_MRAM_ARB_TIMEOUT_FAULT_INJ_CTRL, FAULT_INJ_ARB_2_STOP, CANSS_ONE);
// 				}
// 				else
// 				{
// 					DEBUG_LOG(SAIL_ERROR, "Invalid option \r\n");
// 				}
// 				break;

// 			default:
// 				DEBUG_LOG(SAIL_ERROR, "Invalid option \r\n");
// 				break;
// 			}
// 		}
// 	}
	return  retValue;
}

Std_ReturnType CanTC_EccFaultInjectionTest(void)
{
 	uint8 retValue = E_OK;
// 	uint32 DataReadVal = 0;
// 	DEBUG_LOG(SAIL_ERROR, "CanTC_EccFaultInjectionTest\r\n");
// 	for (int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++)
// 	{
// 		if (CanController[Controller] == 1)
// 		{
// 			DEBUG_LOG(SAIL_ERROR, "For Controller %d invoking CanTC_EccFaultInjectionTest\n", Controller);
// 			/*Enable ECC fault injection */
// 			SET_CAN_HW_FIELD(Controller, ECC_CONTROL, ENABLE_FAULT_INJECT, CANSS_TEN);
// 			/*Enable Interrupt for ECC error due to fault injection */
// 			SET_CAN_HW_FIELD(Controller, ECC_CONTROL, FAULT_INJ_IRQ_EN, CANSS_ONE);
// 			/*Update with the MRAM address where fault injection needs to be done */
// 			SET_CAN_HW_REG(Controller, ECC_FAULT_INJ_ADDR, MramIndex);
// 			switch (TimeoutFault)
// 			{
// 			case FUSA_ECC_ERR_DATA_SEC:
// 				DEBUG_LOG(SAIL_ERROR, "Performing ECC data based Single bit fault injection \r\n");
// 				SET_CAN_HW_REG_OFFS(Controller, (MramIndex * CAN_MRAM_INDEX_SIZE), ECC_FAULT_INJ_i_DATA, CAN_ECC_SEC_ERROR_INJ_VAL);
// 				/*Assign data to MRAM address where fault injection needs to be done*/
// 				SET_CAN_HW_REG_OFFS(Controller, (MramIndex * CAN_MRAM_INDEX_SIZE), CANSS_MRAMn, (uint32)CAN_ECC_FAULT_INJ_DATA);
// 				/*Read back from MRAM address*/
// 				DataReadVal = IN_CAN_HW_REG_OFFS(Controller, (MramIndex * CAN_MRAM_INDEX_SIZE), CANSS_MRAMn);
// 				break;

// 			case FUSA_ECC_ERR_ADDR_SEC:
// 				DEBUG_LOG(SAIL_ERROR, "Performing ECC address based Single bit fault injection \r\n");
// 				/*Update with the fault injection syndrome pattern for 1 bit error*/
// 				SET_CAN_HW_REG(Controller, ECC_FAULT_INJ_SYNDROME, CAN_ECC_SEC_ERROR_INJ_VAL);
// 				/*Assign data to MRAM address where fault injection needs to be done*/
// 				SET_CAN_HW_REG_OFFS(Controller, (MramIndex * CAN_MRAM_INDEX_SIZE), CANSS_MRAMn, (uint32)CAN_ECC_FAULT_INJ_DATA);
// 				/*Read back from MRAM address*/
// 				DataReadVal = IN_CAN_HW_REG_OFFS(Controller, (MramIndex * CAN_MRAM_INDEX_SIZE), CANSS_MRAMn);
// 				break;

// 			case FUSA_ECC_ERR_DATA_DED:
// 				DEBUG_LOG(SAIL_ERROR, "Performing ECC data based double bit fault injection \r\n");
// 				SET_CAN_HW_REG_OFFS(Controller, (MramIndex * CAN_MRAM_INDEX_SIZE), ECC_FAULT_INJ_i_DATA, CAN_ECC_DED_ERROR_INJ_VAL);
// 				/*Assign data to MRAM address where fault injection needs to be done*/
// 				SET_CAN_HW_REG_OFFS(Controller, (MramIndex * CAN_MRAM_INDEX_SIZE), CANSS_MRAMn, (uint32)CAN_ECC_FAULT_INJ_DATA);
// 				/*Read back from MRAM address*/
// 				DataReadVal = IN_CAN_HW_REG_OFFS(Controller, (MramIndex * CAN_MRAM_INDEX_SIZE), CANSS_MRAMn);
// 				break;

// 			case FUSA_ECC_ERR_ADDR_DED:
// 				DEBUG_LOG(SAIL_ERROR, "Performing ECC address based double bit fault injection \r\n");
// 				/*Update with the fault injection syndrome pattern for 2 bit error*/
// 				SET_CAN_HW_REG(Controller, ECC_FAULT_INJ_SYNDROME, CAN_ECC_DED_ERROR_INJ_VAL);
// 				/*Assign data to MRAM address where fault injection needs to be done*/
// 				SET_CAN_HW_REG_OFFS(Controller, (CAN_MRAM_INDEX_SIZE * CAN_MRAM_INDEX_SIZE), CANSS_MRAMn, (uint32)CAN_ECC_FAULT_INJ_DATA);
// 				/*Read back from MRAM address*/
// 				DataReadVal = IN_CAN_HW_REG_OFFS(Controller, (MramIndex * CAN_MRAM_INDEX_SIZE), CANSS_MRAMn);
// 				break;

// 			default:
// 				DEBUG_LOG(SAIL_ERROR, "Invalid option \r\n");
// 				break;
// 			}
// 		}
// 	}
	return  retValue;
}
/********************************************************************************
** Syntax           : void Can_Atoi(void)                                 **
**                                                                             **
**                                                                             **
**                                                                             **
** Description      : CAN string to integer function						   **
**                    									                       **
**                                                                             **
** Parameters(in)   : None                                                     **
**                                                                             **
** Parameters (out) : None                                                     **
**                                                                             **
** Parameters (in-out):                                                        **
**                                                                             **
** Return value     : None			                                           **
**                                                                             **
********************************************************************************/
static int Can_Atoi(uint8 * str)
{
	int sign = 1, i = 0, num = 0;

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

	if(str[i] == '0' && (str[i+1] == 'x' || str[i+1] == 'X')){
		i+=2;
		while(str[i] != '\0'){
			if(str[i] >= '0' && str[i] <= '9'){
				num = num * 16 + str[i] - '0';
			}
			else if(str[i] >= 'a' && str[i] <= 'f'){
				num = num * 16 + str[i] - 'a'+10;
			}
			else if(str[i] >= 'A' && str[i] <= 'F'){
				num = num * 16 + str[i] - 'A'+10;
			}
			i++;
		}
	}

	// checking for valid input
	else{
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = 10 * num + (str[i++] - '0');
		}
	}
	return num * sign;
}

static Std_ReturnType CanGetApi(void){
	Std_ReturnType ret = E_OK;
	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		runApi = Can_Atoi(nextFind);
		if(runApi >= CAN_TC_API_COUNT){
			DEBUG_LOG( SAIL_INFO, "Invalid API Index\r\n");
			ret = E_NOT_OK;
		}
	}
	return ret;
}
static void CanGetConfig(void){

	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		configIndex = Can_Atoi(nextFind);
		if(configIndex >= CAN_CONFIG_COUNT){
			configIndex = CAN_CONFIG_COUNT;
			DEBUG_LOG( SAIL_INFO, "Config index out of range setting it to NULL_PTR Config Index\r\n");
		}
	}
	else{
		configIndex = CAN_CONFIG_COUNT;
		DEBUG_LOG( SAIL_INFO, "Config index not entered, setting it to NULL_PTR Config Index\r\n");
	}
}
static void CanGetController(void){

	for(int i = CTRL_ZERO; i <= NUMBER_OF_ACTIVE_CAN_CTRL; i++){
		CanController[i] = 0;
	}
	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	while(nextFind !=NULL && nextFind[0] != '-' && nextFind[0] != '\0' ){
		temp = Can_Atoi(nextFind);
		if(temp == NUMBER_OF_ACTIVE_CAN_CTRL){
			for(int i=CTRL_ZERO;i<NUMBER_OF_ACTIVE_CAN_CTRL; i++){
				CanController[i] = 1;
			}
		}
		else if(temp < NUMBER_OF_ACTIVE_CAN_CTRL){
			CanController[temp] = 1;
		}
		else if(temp > NUMBER_OF_ACTIVE_CAN_CTRL){
			CanController[NUMBER_OF_ACTIVE_CAN_CTRL] = 1;
		}
		nextFind = pucAPPL_SAILTF_gettoken(NULL);
	}
}
static void CanGetBaudrate(void){

	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		BaudRateConfigID = Can_Atoi(nextFind);
	}
	else{
		BaudRateConfigID = CAN_MAX_BAUDRATE;
		DEBUG_LOG( SAIL_INFO, "Baud rate Config index not entered, setting it to max Config Index\r\n");
	}
}
static void CanGetObjects(void){

	for(int i = 0; i <= CAN_MAX_HOH_CONFIGURED; i++){
		Hoh[i] = 0;
	}
	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	while(nextFind !=NULL && nextFind[0] != '-' && nextFind[0] != '\0' ){
		//Object ID
		temp = Can_Atoi(nextFind);
		if(temp == CAN_MAX_HOH_CONFIGURED){
			for(int i=0;i<CAN_MAX_HOH_CONFIGURED; i++){
				Hoh[i] = 1;
			}
		}
		else if(temp < CAN_MAX_HOH_CONFIGURED){
			Hoh[temp] = 1;
		}
		else{
			Hoh[CAN_MAX_HOH_CONFIGURED] = 1;
		}
		nextFind = pucAPPL_SAILTF_gettoken(NULL);
	}
}
static void CanGetMode(void){

	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		Transition = Can_Atoi(nextFind);
	}
	else{
		Transition = CAN_MAX_UINT8;
	}
}
static void CanGetPeriod(void){

	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		CanMainFunctionPeriod = Can_Atoi(nextFind);
	}
	else{
		CanMainFunctionPeriod = 100;
	}
}
static void CanGetCount(void){

	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		CanCount = Can_Atoi(nextFind);
	}
	else{
		CanCount = 10;
	}
}
static void CanGetPdu(void){
	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		pduIndex = Can_Atoi(nextFind);
		if(pduIndex > PDU_INFO_COUNT){
			pduIndex = PDU_INFO_COUNT;
		}
	}
	else{
		pduIndex = PDU_INFO_COUNT;
	}
}
static void CanGetAddr(void){
	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		addr = Can_Atoi(nextFind);
	}
}
static void CanGetFromAddr(void){
	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		startAddr = Can_Atoi(nextFind);
	}
}
static void CanGetToAddr(void){
	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		endAddr = Can_Atoi(nextFind);
	}
}
static void CanGetRegValue(void){
	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(nextFind != NULL){
		value = Can_Atoi(nextFind);
	}
}
/*static void CanGetDataLength(void){
	nextFind = APPL_Shell_gettoken(NULL);
	if(nextFind != NULL){
		TriggerTransmitDataLength = Can_Atoi(nextFind);
	}
}*/
static void CanCheckNull(void){
	nextFind = pucAPPL_SAILTF_gettoken(NULL);
	if(ucAPPL_SAILTF_stricmp("0", (char*)nextFind)){
		null = 0;
	}
	else{
		null = 1;
	}
}

static void CanGetTimeoutFault(void){

	nextFind = pucAPPL_SAILTF_gettoken(NULL);

	if(nextFind != NULL){
	    TimeoutFault = Can_Atoi(nextFind);
	}
    else{
			DEBUG_LOG( SAIL_INFO, "Incorrect option\r\n");
			acceptCommand = 0;
	}

}

static void CanGetMramIndex(void){

	nextFind = pucAPPL_SAILTF_gettoken(NULL);

	if(nextFind != NULL){
	    MramIndex= Can_Atoi(nextFind);
	}
    else{
			DEBUG_LOG( SAIL_INFO, "Incorrect option\r\n");
			acceptCommand = 0;
	}

}

static void CanGetSubTestTimeout(void){

	nextFind = pucAPPL_SAILTF_gettoken(NULL);

	if(nextFind != NULL){
	    SubTestTimeoutFault = Can_Atoi(nextFind);
	}
    else{
			DEBUG_LOG( SAIL_INFO, "Incorrect option\r\n");
			acceptCommand = 0;
	}

}

static void CanHwGetObject(void){

	uint8 j;

	/* Zeroed out here for all the Hardware Objects */
	for( j = 0; j < CAN_MAX_HOH_CONFIGURED + 1; j++){
		Hoh[j] = 0;
	}

	// Hoh for Tx FIFO
	for(int Controller = CTRL_ZERO; Controller < NUMBER_OF_ACTIVE_CAN_CTRL; Controller++){
		if(CanController[Controller] == 1){
			switch(Controller){
				case CTRL_ZERO:
					Hoh[CAN_CNTRL_0_HW_OBJ_TX_FIFO_BUFF] = 1;
					break;
				case CTRL_ONE:
					Hoh[CAN_CNTRL_1_HW_OBJ_TX_FIFO_BUFF] = 1;
					break;
				case CTRL_TWO:
					Hoh[CAN_CNTRL_2_HW_OBJ_TX_FIFO_BUFF] = 1;
					break;
				case CTRL_THREE:
					Hoh[CAN_CNTRL_3_HW_OBJ_TX_FIFO_BUFF] = 1;
					break;
				case CTRL_FOUR:
					Hoh[CAN_CNTRL_4_HW_OBJ_TX_FIFO_BUFF] = 1;
					break;
				case CTRL_FIVE:
					Hoh[CAN_CNTRL_5_HW_OBJ_TX_FIFO_BUFF] = 1;
					break;
				case CTRL_SIX:
					Hoh[CAN_CNTRL_6_HW_OBJ_TX_FIFO_BUFF] = 1;
					break;
				case CTRL_SEVEN:
					Hoh[CAN_CNTRL_7_HW_OBJ_TX_FIFO_BUFF] = 1;
					break;
				default:
					/* Undefined hardware object */
					break;
			}
		}
	}

}


static void CanWriteTest(void)
{

	DEBUG_LOG( SAIL_ERROR, "Invoked CanWriteTest\r\n");
	static volatile uint32 wrCount;
	static volatile bool intenableflag=1;
	static volatile bool alltxenable =0;
	static volatile bool controller7enabled =1;
	static volatile int delay =10000;
	volatile uint8 loop = 0;
	Can_Init(&Can_Config_NewEntry);
    CanTest_RegisterCallBacks();
	if(alltxenable ==1){
		for(uint8 controller=0;controller < NUMBER_OF_ACTIVE_CAN_CTRL;controller++){
			CanController[controller]=1;
			xCanSrv_SetControllerMode(controller,CAN_CS_STARTED);
		}
	}
	else{
		/*Need to check*/
		// CanController[CTRL_SEVEN]=1;
		// xCanSrv_SetControllerMode(CTRL_SEVEN,CAN_CS_STARTED);
	}
	vFreeRTOSTaskDelay(1000);
	if(intenableflag){
		CanTC_ConfigureInterrupts();
	}
	while(loop){
		// Transmit messages from PCAN
	}
	for ( wrCount=0;wrCount <= CanCount;wrCount++){
		if((wrCount == 5000) || (wrCount == 10000))
		{
			DEBUG_LOG( SAIL_INFO, "Invoked Can Write 5000/10000 times");
		}
		if(alltxenable ==1){
			Cantest_write(CAN_HW_OBJ_0, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_1, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_5, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_6, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_10, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_11, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_15, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_16, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_20, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_21, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_25, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_26, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_30, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_31, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_35, &Pdu1);
			vFreeRTOSTaskDelay(1000);
			Cantest_write(CAN_HW_OBJ_36, &Pdu1);
			vFreeRTOSTaskDelay(1000);
		}
		else
		{
			if(controller7enabled==1){
				Cantest_write(CAN_HW_OBJ_36, &Pdu1);
				vFreeRTOSTaskDelay(delay);
			}
		}

	}

	// vFreeRTOSTaskDelay(delay * 400);
}

__attribute__((used)) static void CT_InitDeinit(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	Can_Init(NULL_PTR);
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
	setCanHWUnitState(CAN_HW_READY);
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_CtrlInfo[CTRL_SEVEN].CanCtrlState = CAN_CS_STARTED;
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
	setCanHWUnitState(CAN_HW_UNINIT);
	Can_CtrlInfo[CTRL_SEVEN].CanCtrlState = CAN_CS_STOPPED;
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_CtrlInfo[CTRL_SEVEN].CanCtrlState = CAN_CS_UNINIT;
	volatile uint8 loop =1;
	while(loop);
	/*step through can_init and manually set the Can_Drv_Init return value prefer controller 0
	* get the return value Can_Drv_MRAM_ResetCheck at controller 0
	*/
	volatile uint8 controller = 0;
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	for(int i=0; i<NUMBER_OF_ACTIVE_CAN_CTRL; i++){
		CanFusa_ReInit_Controller(i);
		Can_CtrlInfo[i].CanCtrlState = CAN_CS_UNINIT;
	}
	setCanHWUnitState(CAN_HW_UNINIT);
	SET_CAN_HW_REG(CTRL_ONE,IR,0xF);
	SET_CAN_HW_FIELD(CTRL_ONE, NDAT1, ND, 0xF);
	SET_CAN_HW_FIELD(CTRL_TWO, NDAT1, ND, 0xF);
	SET_CAN_HW_FIELD(CTRL_THREE, NDAT1, ND, 0xF);
	SET_CAN_HW_FIELD(CTRL_ONE, NDAT2, ND, 0xF);
	SET_CAN_HW_FIELD(CTRL_TWO, NDAT2, ND, 0xF);
	SET_CAN_HW_FIELD(CTRL_THREE, NDAT2, ND, 0xF);
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_SEVEN, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	Can_DeInit();
	CanFusa_ReInit_Controller(CTRL_SEVEN);
	setCanHWUnitState(CAN_HW_READY);
	Can_DeInit();
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_SEVEN, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	Can_CtrlInfo[CTRL_SEVEN].CanCtrlState = CAN_CS_UNINIT;
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	CanFusa_ReInit_Controller(CTRL_SEVEN);
	CppTest_SendCoverage();
	loop=1;
	while(loop);
	//set the return value of CanFusa_Fusa_Init to E_NOT_OK
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	loop=1;
	while(loop);
	//set the return value of CanFusa_Fusa_DeInit to E_NOT_OK
	Can_DeInit();
	CppTest_SendCoverage();
	for(uint8 i = CTRL_ZERO;i<NUMBER_OF_ACTIVE_CAN_CTRL;i++){
		CanFusa_ReInit_Controller(i);
	CppTest_SendCoverage();
		Can_CtrlInfo[i].CanCtrlState = CAN_CS_UNINIT;
		Can_CtrlInfo[i].CanCtrlRequestedState = CAN_CS_UNINIT;
	}
#endif
}
__attribute__((used)) static void CT_VersionInfo(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	Std_VersionInfoType versioninfo;
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_GetVersionInfo(NULL_PTR);
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_THREE, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	Can_GetVersionInfo(&versioninfo);
	CppTest_SendCoverage();
	CanFusa_ReInit_Controller(CTRL_THREE);
	CppTest_SendCoverage();
	Can_GetVersionInfo(&versioninfo);
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
__attribute__((used)) static void CT_SetBaudrate(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	xCanSrv_SetBaudrate(CTRL_ZERO,0);
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	xCanSrv_SetBaudrate(NUMBER_OF_ACTIVE_CAN_CTRL+1,0);
	CppTest_SendCoverage();
	Can_CtrlInfo[CTRL_ZERO].CanCtrlState = CAN_CS_STARTED;
	xCanSrv_SetBaudrate(CTRL_ZERO,0);
	CppTest_SendCoverage();
	Can_CtrlInfo[CTRL_ZERO].CanCtrlState = CAN_CS_STOPPED;
	xCanSrv_SetBaudrate(CTRL_ZERO,7);
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_ZERO, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	xCanSrv_SetBaudrate(CTRL_ZERO,0);
	CppTest_SendCoverage();
	CanFusa_ReInit_Controller(CTRL_ZERO);
	CppTest_SendCoverage();
	volatile uint8 loop =1;
	while(loop);
	/* ensure to return false from Can_Drv_CCControlInit	by setting timeout to zero at "if (timeout == 0UL)" */
	xCanSrv_SetBaudrate(CTRL_ZERO,0);
	CppTest_SendCoverage();
	xCanSrv_SetBaudrate(CTRL_ZERO,0);
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
__attribute__((used)) static void CT_Mode(){
#if(CAN_COVERAGE_TEST == STD_ON)
	Can_ControllerStateType ControllerMode;
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STARTED);
	CppTest_SendCoverage();
	xCanSrv_GetControllerMode(CTRL_ZERO, &ControllerMode);
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(NUMBER_OF_ACTIVE_CAN_CTRL, CAN_CS_STARTED);
	CppTest_SendCoverage();
	xCanSrv_GetControllerMode(NUMBER_OF_ACTIVE_CAN_CTRL, &ControllerMode);
	CppTest_SendCoverage();
	xCanSrv_GetControllerMode(CTRL_ZERO, NULL_PTR);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	Can_CtrlInfo[CTRL_ZERO].CanCtrlState = CAN_CS_UNINIT;
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STOPPED);
	Can_CtrlInfo[CTRL_ZERO].CanCtrlState = CAN_CS_STARTED;
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STARTED);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_SLEEP);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STOPPED);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	CppTest_SendCoverage();
	Can_CtrlInfo[CTRL_ZERO].CanCtrlState = CAN_CS_STOPPED;
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STOPPED);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_SLEEP);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	CppTest_SendCoverage();
	Can_CtrlInfo[CTRL_ZERO].CanCtrlState = CAN_CS_SLEEP;
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_SLEEP);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STARTED);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STOPPED);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	CppTest_SendCoverage();
	Can_CtrlInfo[CTRL_ZERO].CanCtrlState = CAN_CS_STOPPED;
	CanFusa_EnterSafeState(CTRL_ZERO, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	xCanSrv_GetControllerMode(CTRL_ZERO, &ControllerMode);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STOPPED);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STARTED);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	Can_CtrlInfo[CTRL_ZERO].CanCtrlState = CAN_CS_STARTED;
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_ZERO, CAN_FUSA_FLT_CODE_STATE_TRANS_FAILED);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STOPPED);
	CppTest_SendCoverage();
	CanFusa_ReInit_Controller(CTRL_ZERO);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STOPPED);
	CppTest_SendCoverage();
	volatile uint8 loop = 1;
	while(loop);
	//set the return value of GetCounterValue to E_NOT_OK to hit break conditio
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STOPPED);
	CppTest_SendCoverage();
	loop = 1;
	while(loop);
	//set the trasition to UNINIT for default case
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_STOPPED);
	CppTest_SendCoverage();
	xCanSrv_GetControllerMode(CTRL_ZERO, &ControllerMode);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_ZERO, CAN_CS_UNINIT);
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
__attribute__((used)) static void CT_Interrupts(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	Can_DisableControllerInterrupts(CTRL_ZERO);
	CppTest_SendCoverage();
	Can_EnableControllerInterrupts(CTRL_ZERO);
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_DisableControllerInterrupts(NUMBER_OF_ACTIVE_CAN_CTRL);
	CppTest_SendCoverage();
	Can_EnableControllerInterrupts(NUMBER_OF_ACTIVE_CAN_CTRL);
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_ZERO, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	Can_DisableControllerInterrupts(CTRL_ZERO);
	CppTest_SendCoverage();
	Can_EnableControllerInterrupts(CTRL_ZERO);
	CppTest_SendCoverage();
	CanFusa_ReInit_Controller(CTRL_ZERO);
	CppTest_SendCoverage();
	Can_DisableControllerInterrupts(CTRL_ZERO);
	CppTest_SendCoverage();
	Can_DisableControllerInterrupts(CTRL_ZERO);
	CppTest_SendCoverage();
	Can_EnableControllerInterrupts(CTRL_ZERO);
	CppTest_SendCoverage();
	Can_EnableControllerInterrupts(CTRL_ZERO);
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
__attribute__((used)) static void CT_Wakeup(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	Can_MainFunction_Wakeup();
	CppTest_SendCoverage();
	Can_CheckWakeup(CTRL_ZERO);
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_MainFunction_Wakeup();
	CppTest_SendCoverage();
	Can_CheckWakeup(NUMBER_OF_ACTIVE_CAN_CTRL);
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_SEVEN, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	Can_CheckWakeup(CTRL_SEVEN);
	CppTest_SendCoverage();
	CanFusa_ReInit_Controller(CTRL_SEVEN);
	CppTest_SendCoverage();
	Can_CheckWakeup(CTRL_SEVEN);
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
__attribute__((used)) static void CT_ErrorState(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	Can_ErrorStateType ErrorState = CAN_ERRORSTATE_ACTIVE;
	volatile uint8 loop;
	uint8 Counter;
	xCanSrv_GetControllerErrorState(CTRL_SEVEN, &ErrorState);
	CppTest_SendCoverage();
	Can_GetControllerRxErrorCounter(CTRL_SEVEN, &Counter);
	CppTest_SendCoverage();
	Can_GetControllerTxErrorCounter(CTRL_SEVEN, &Counter);
	CppTest_SendCoverage();
	Can_MainFunction_BusOff();
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	xCanSrv_GetControllerErrorState(NUMBER_OF_ACTIVE_CAN_CTRL, &ErrorState);
	CppTest_SendCoverage();
	Can_GetControllerRxErrorCounter(NUMBER_OF_ACTIVE_CAN_CTRL, &Counter);
	CppTest_SendCoverage();
	Can_GetControllerTxErrorCounter(NUMBER_OF_ACTIVE_CAN_CTRL, &Counter);
	CppTest_SendCoverage();
	xCanSrv_GetControllerErrorState(CTRL_SEVEN, NULL_PTR);
	CppTest_SendCoverage();
	Can_GetControllerRxErrorCounter(CTRL_SEVEN, NULL_PTR);
	CppTest_SendCoverage();
	Can_GetControllerTxErrorCounter(CTRL_SEVEN, NULL_PTR);
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_SEVEN, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	xCanSrv_GetControllerErrorState(CTRL_SEVEN, &ErrorState);
	CppTest_SendCoverage();
	Can_GetControllerRxErrorCounter(CTRL_SEVEN, &Counter);
	CppTest_SendCoverage();
	Can_GetControllerTxErrorCounter(CTRL_SEVEN, &Counter);
	CppTest_SendCoverage();
	CanFusa_ReInit_Controller(CTRL_SEVEN);
	CppTest_SendCoverage();
	xCanSrv_SetBaudrate(CTRL_SEVEN, 1);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_SEVEN, CAN_CS_STARTED);
	Can_MainFunction_Mode();
	Can_CtrlInfo[CTRL_SEVEN].CanCtrlState = CAN_CS_STARTED;
	CppTest_SendCoverage();
	loop = 1;
	while(loop);
	while (ErrorState != CAN_ERRORSTATE_BUSOFF){
		Cantest_write(CAN_HW_OBJ_35, &Pdu1);
	CppTest_SendCoverage();
		Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
		Can_MainFunction_Read();
	CppTest_SendCoverage();
		Can_MainFunction_Write();
	CppTest_SendCoverage();
		xCanSrv_GetControllerErrorState(CTRL_SEVEN, &ErrorState);
	CppTest_SendCoverage();
		Can_GetControllerRxErrorCounter(CTRL_SEVEN, &Counter);
	CppTest_SendCoverage();
		Can_GetControllerTxErrorCounter(CTRL_SEVEN, &Counter);
	CppTest_SendCoverage();
		Can_MainFunction_BusOff();
	CppTest_SendCoverage();
	}
	xCanSrv_SetControllerMode(CTRL_SEVEN, CAN_CS_STOPPED);
	Can_MainFunction_Mode();
	Can_CtrlInfo[CTRL_SEVEN].CanCtrlState = CAN_CS_STOPPED;
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
__attribute__((used)) static void CT_Read(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	volatile uint8 loop, repeat = 1;
	Can_TimeStampType timeStamp;
	Can_MainFunction_Read();
	CppTest_SendCoverage();
	Can_GetIngressTimeStamp(37, &timeStamp);
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_GetIngressTimeStamp(40, &timeStamp);
	CppTest_SendCoverage();
	Can_GetIngressTimeStamp(36, &timeStamp);
	CppTest_SendCoverage();
	Can_GetIngressTimeStamp(37, NULL_PTR);
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_SEVEN, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	Can_MainFunction_Read();
	CppTest_SendCoverage();
	Can_GetIngressTimeStamp(37, &timeStamp);
	CppTest_SendCoverage();
	CanFusa_ReInit_Controller(CTRL_SEVEN);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_SEVEN, CAN_CS_STARTED);
	Can_MainFunction_Mode();
	Can_CtrlInfo[CTRL_SEVEN].CanCtrlState = CAN_CS_STARTED;
	CppTest_SendCoverage();
	loop = 1;
	while(loop);
	while(repeat){
		/*Transmit a message from PCAN with Can ID 0x50, 0x100, 0x10000155*/
		Can_MainFunction_Read();
	CppTest_SendCoverage();
		Can_GetIngressTimeStamp(37, &timeStamp);
	CppTest_SendCoverage();
	}
	xCanSrv_SetControllerMode(CTRL_SEVEN, CAN_CS_STOPPED);
	Can_MainFunction_Mode();
	Can_CtrlInfo[CTRL_SEVEN].CanCtrlState = CAN_CS_STOPPED;
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
__attribute__((used)) static void CT_Write(){
#if(CAN_COVERAGE_TEST == STD_ON)
	volatile uint8 loop;
	Can_TimeStampType timeStamp;
	setCanHWUnitState(CAN_HW_UNINIT);
	Cantest_write(35, &Pdu1);
	CppTest_SendCoverage();
	Can_MainFunction_Write();
	CppTest_SendCoverage();
	Can_EnableEgressTimeStamp(35);
	CppTest_SendCoverage();
	Can_GetEgressTimeStamp(CTRL_ONE, 35, &timeStamp);
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Cantest_write(40, &Pdu1);
	CppTest_SendCoverage();
	Can_EnableEgressTimeStamp(40);
	CppTest_SendCoverage();
	Can_GetEgressTimeStamp(CTRL_ONE, 40, &timeStamp);
	CppTest_SendCoverage();
	Cantest_write(39, &Pdu1);
	CppTest_SendCoverage();
	Can_EnableEgressTimeStamp(39);
	CppTest_SendCoverage();
	Can_GetEgressTimeStamp(CTRL_ONE, 39, &timeStamp);
	CppTest_SendCoverage();
	Cantest_write(35, NULL_PTR);
	CppTest_SendCoverage();
	Can_GetEgressTimeStamp(CTRL_ONE, 35, NULL_PTR);
	CppTest_SendCoverage();
	Cantest_write(0, &Pdu2); //fd disabled
	CppTest_SendCoverage();
	Cantest_write(35, &Pdu7); // sdu length is greater than 65
	CppTest_SendCoverage();
	Cantest_write(5, &Pdu5); // data length is greater than the buffer length
	CppTest_SendCoverage();
	Cantest_write(35, &Pdu6); // can ID is not fd but message is
	CppTest_SendCoverage();
	Cantest_write(5, &Pdu9); // Trigger transmit is disabled but SDU is null
	CppTest_SendCoverage();
	CanFusa_EnterSafeState(CTRL_SEVEN, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	//set Can_HthMutex[14]= MUTEX_SIGNALED =1
	Cantest_write(35, &Pdu1);

	Can_EnableEgressTimeStamp(35);
	CppTest_SendCoverage();

	Can_MainFunction_Write();
	CppTest_SendCoverage();
	Can_GetEgressTimeStamp(CTRL_ONE, 35, &timeStamp);
	CppTest_SendCoverage();
	CanFusa_ReInit_Controller(CTRL_SEVEN);
	loop = 1;
	while(loop);
	//set Can_HthMutex[14]= MUTEX_SIGNALED =1
	Cantest_write(35, &Pdu1);
	CppTest_SendCoverage();
	//set Can_HthMutex[14] = MUTEX_RELEASED = 0
	Cantest_write(35, &Pdu1);
	CppTest_SendCoverage();
	Can_MainFunction_Write();
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_SEVEN, CAN_CS_STARTED);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	CppTest_SendCoverage();
	Can_CtrlInfo[CTRL_ZERO].CanCtrlState = CAN_CS_STARTED;
	CppTest_SendCoverage();
	Can_EnableEgressTimeStamp(35);
	CppTest_SendCoverage();
	Can_EnableEgressTimeStamp(35);
	CppTest_SendCoverage();
	Cantest_write(35, &Pdu1);// no worries just transmit
	CppTest_SendCoverage();
	Cantest_write(36, &Pdu3);// extended message trasmission
	CppTest_SendCoverage();
	//TriggerTransmitDataLength = 65;
	Cantest_write(36, &Pdu8);// fail trigger transmit
	CppTest_SendCoverage();
	//TriggerTransmitDataLength = 8;
	loop = 1;
	while(loop);
	//for the false condition of the line in can_drv_write if(pMRamConfig->TxMaxBufferDlc > (uint8)CANSS_ZERO)
	loop = 1;
	//force a DMA trasfer
	while(loop);
	Cantest_write(36, &Pdu2);// fd message trasmission
	CppTest_SendCoverage();
	for(int i=0;i<10;i++){
		Cantest_write(36, &Pdu8);// no worries just transmit
	CppTest_SendCoverage();
	}
	loop = 1;
	while(loop){
		Can_MainFunction_Write();
	CppTest_SendCoverage();
	}
	Can_GetEgressTimeStamp(CTRL_ONE, 35, &timeStamp);
	CppTest_SendCoverage();
	Can_GetEgressTimeStamp(CTRL_ONE, 36, &timeStamp);
	CppTest_SendCoverage();
	xCanSrv_SetControllerMode(CTRL_SEVEN, CAN_CS_STOPPED);
	CppTest_SendCoverage();
	Can_MainFunction_Mode();
	Can_CtrlInfo[CTRL_SEVEN].CanCtrlState = CAN_CS_STOPPED;
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
__attribute__((used)) static void CT_CurrentTime(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	Can_TimeStampType timeStamp;
	Can_GetCurrentTime(CTRL_SEVEN, &timeStamp);
	CppTest_SendCoverage();
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	Can_GetCurrentTime(NUMBER_OF_ACTIVE_CAN_CTRL, &timeStamp);
	CppTest_SendCoverage();
	Can_GetCurrentTime(CTRL_SEVEN, NULL_PTR);
	CppTest_SendCoverage();
	// CanFusa_EnterSafeState(CTRL_SEVEN, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	// CppTest_SendCoverage();
	Can_GetCurrentTime(CTRL_SEVEN, &timeStamp);
	CppTest_SendCoverage();
	// CanFusa_ReInit_Controller(CTRL_SEVEN);
	Can_GetCurrentTime(CTRL_SEVEN, &timeStamp);
	xCanSrv_SetBaudrate(CTRL_SEVEN,8);
	Can_GetCurrentTime(CTRL_SEVEN, &timeStamp);
	CppTest_SendCoverage();
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
static void CT_Fusa(){
//#if(CAN_COVERAGE_TEST == STD_ON)
//	volatile uint8 loop = 1, i =0;
//	for(i = CTRL_ZERO;i<NUMBER_OF_ACTIVE_CAN_CTRL + 1;i++){
//		UT_CanFusa_SM_Fault_Notification(i, CAN_FUSA_FLT_CODE_CFG_MISMATCH, 0,SSM_SAFETY_SUBSYSTEM_FATAL_ERROR );
//	CppTest_SendCoverage();
//	}
//	UT_CanFusa();
//	CppTest_SendCoverage();
//#endif
}

__attribute__((used)) static void CT_TriggerInterrupts(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	uint8 i = 0;
	volatile uint8 loop;
	CanController[CTRL_SEVEN] = 1;
	CanTC_ConfigureInterrupts();
	CppTest_SendCoverage();
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		CanFusa_ReInit_Controller(i);
		Can_CtrlInfo[i].CanCtrlState = CAN_CS_UNINIT;
		i++;
	}
	setCanHWUnitState(CAN_HW_UNINIT);
	Can_Init(&Can_Config_NewEntry);
	CppTest_SendCoverage();
	i =0;
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		xCanSrv_SetControllerMode(i,CAN_CS_STARTED);
	CppTest_SendCoverage();
		i++;
	}
	Cantest_write(CAN_HW_OBJ_35, &Pdu1);
	CppTest_SendCoverage();
	vFreeRTOSTaskDelay(1000);
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	vFreeRTOSTaskDelay(1000);
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	vFreeRTOSTaskDelay(1000);
	loop = 1;
	while(loop){
		//Tranmit all sort of messages from pcan so that the receive interrupts can be processed
	}
	i=0;
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		xCanSrv_SetControllerMode(i,CAN_CS_STOPPED);
	CppTest_SendCoverage();
		Can_CtrlInfo[i].CanCtrlState = CAN_CS_STOPPED;
		xCanSrv_SetBaudrate(i, 1);
		xCanSrv_SetControllerMode(i,CAN_CS_STARTED);
	CppTest_SendCoverage();
		i++;
	}
	loop = 1;
	while(loop){
		//transmit and receive the messages to hit busoff
		Cantest_write(CAN_HW_OBJ_35, &Pdu1);
	CppTest_SendCoverage();
	}
	i=0;
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		xCanSrv_SetControllerMode(i,CAN_CS_STOPPED);
	CppTest_SendCoverage();
		Can_CtrlInfo[i].CanCtrlState = CAN_CS_STOPPED;
		CanFusa_ReInit_Controller(i);
	CppTest_SendCoverage();
		i++;
	}
	Can_DeInit();
	CppTest_SendCoverage();
	Can_Init(&Can_Config_WaterMark);
	CppTest_SendCoverage();
	i=0;
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		xCanSrv_SetControllerMode(i,CAN_CS_STARTED);
	CppTest_SendCoverage();
		i++;
	}
	Cantest_write(CAN_HW_OBJ_35, &Pdu1);
	CppTest_SendCoverage();
	vFreeRTOSTaskDelay(1000);
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	vFreeRTOSTaskDelay(1000);
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	vFreeRTOSTaskDelay(1000);
	loop = 1;
	while(loop){
		//Tranmit all sort of messages from pcan so that the receive interrupts can be processed
	}
	i=0;
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		xCanSrv_SetControllerMode(i,CAN_CS_STOPPED);
	CppTest_SendCoverage();
		Can_CtrlInfo[i].CanCtrlState = CAN_CS_STOPPED;
		xCanSrv_SetBaudrate(i, 1);
		xCanSrv_SetControllerMode(i,CAN_CS_STARTED);
	CppTest_SendCoverage();
		i++;
	}
	loop = 1;
	while(loop){
		//transmit and receive the messages to hit busoff
		Cantest_write(CAN_HW_OBJ_35, &Pdu1);
	CppTest_SendCoverage();
	}
	i=0;
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		xCanSrv_SetControllerMode(i,CAN_CS_STOPPED);
	CppTest_SendCoverage();
		Can_CtrlInfo[i].CanCtrlState = CAN_CS_STOPPED;
		CanFusa_ReInit_Controller(i);
	CppTest_SendCoverage();
		i++;
	}
	Can_DeInit();
	CppTest_SendCoverage();
	Can_Init(&Can_Config_Dma);
	CppTest_SendCoverage();
	i=CTRL_ZERO;
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		xCanSrv_SetControllerMode(i,CAN_CS_STARTED);
	CppTest_SendCoverage();
		i++;
	}
	Cantest_write(CAN_HW_OBJ_35, &Pdu1);
	CppTest_SendCoverage();
	vFreeRTOSTaskDelay(1000);
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	vFreeRTOSTaskDelay(1000);
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	Cantest_write(CAN_HW_OBJ_36, &Pdu1);
	CppTest_SendCoverage();
	vFreeRTOSTaskDelay(1000);
	loop = 1;
	while(loop){
		//Tranmit all sort of messages from pcan so that the receive interrupts can be processed
	}
	i=CTRL_ZERO;
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		xCanSrv_SetControllerMode(i,CAN_CS_STOPPED);
	CppTest_SendCoverage();
		Can_CtrlInfo[i].CanCtrlState = CAN_CS_STOPPED;
		xCanSrv_SetBaudrate(i, 1);
		xCanSrv_SetControllerMode(i,CAN_CS_STARTED);
	CppTest_SendCoverage();
		i++;
	}
	loop = 1;
	while(loop){
		//transmit and receive the messages to hit busoff
		Cantest_write(CAN_HW_OBJ_35, &Pdu1);
	CppTest_SendCoverage();
	}
	i=CTRL_ZERO;
	while(i<NUMBER_OF_ACTIVE_CAN_CTRL){
		xCanSrv_SetControllerMode(i,CAN_CS_STOPPED);
	CppTest_SendCoverage();
		Can_CtrlInfo[i].CanCtrlState = CAN_CS_STOPPED;
		CanFusa_ReInit_Controller(i);
	CppTest_SendCoverage();
		i++;
	}
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
static void CT_CanDrvISR(void){
#if(CAN_COVERAGE_TEST == STD_ON)
	CppTest_SendCoverage();
	int i;
	Can_Init(&Can_Config_UT);
	CppTest_SendCoverage();
	volatile int loop = 1;
	while(loop);
	for(i=CTRL_ZERO; i<NUMBER_OF_ACTIVE_CAN_CTRL; i++){
		xCanSrv_SetControllerMode(i,CAN_CS_STARTED);
	CppTest_SendCoverage();
	}
	CanFusa_EnterSafeState(CTRL_ZERO, CAN_FUSA_FLT_CODE_CFG_MISMATCH);
	CppTest_SendCoverage();
	for(i=CTRL_ZERO; i<NUMBER_OF_ACTIVE_CAN_CTRL; i++){
		CANSS_COMMON_DMA_HANDLER(i);
	CppTest_SendCoverage();
	    CANSS_COMMON_DMU_HANDLER(i);
	CppTest_SendCoverage();
	    CANSS_INT0_COMMON_HANDLER(i);
	CppTest_SendCoverage();
	    CANSS_INT1_COMMON_HANDLER(i);
	CppTest_SendCoverage();
	    CANSS_FE0_COMMON_HANDLER(i);
	CppTest_SendCoverage();
	    CANSS_FE1_COMMON_HANDLER(i);
	CppTest_SendCoverage();
	    CANSS_FE2_COMMON_HANDLER(i);
	CppTest_SendCoverage();
	    CanDrv_Arb_Phase_Error_Handler(i);
	CppTest_SendCoverage();
	    CanDrv_Data_Phase_Error_Handler(i);
	CppTest_SendCoverage();
	}
	CanFusa_ReInit_Controller(CTRL_ZERO);
	CppTest_SendCoverage();
	for(i=CTRL_ZERO; i<NUMBER_OF_ACTIVE_CAN_CTRL; i++){
		xCanSrv_SetControllerMode(i,CAN_CS_STOPPED);
	CppTest_SendCoverage();
	}
	Can_DeInit();
	CppTest_SendCoverage();
#endif
}
//Can_Drv_CCControlInit failure in set baudrate
static void CanCoverageTest(void)
{
#if(CAN_COVERAGE_TEST == STD_ON)
	CT_InitDeinit();
	CppTest_SendCoverage();
	CT_VersionInfo();
	CppTest_SendCoverage();
	CT_SetBaudrate();
	CppTest_SendCoverage();
	CT_Mode();
	CppTest_SendCoverage();
	CT_Interrupts();
	CppTest_SendCoverage();
	CT_Wakeup();
	CppTest_SendCoverage();
	CT_ErrorState();
	CppTest_SendCoverage();
	CT_Read();
	CppTest_SendCoverage();
	CT_Write();
	CppTest_SendCoverage();
	CT_CurrentTime();
	CppTest_SendCoverage();
#endif
}
