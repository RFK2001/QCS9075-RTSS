/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Can_GeneralTypes.h"
#include "Can.h"

#define CAN_CONFIG_COUNT  8u
#define CAN_TC_API_COUNT 46
#define PDU_INFO_COUNT 8u
#define CAN_MAX_BAUDRATE 0xFF
#define CAN_MAX_UINT8 0xFF

#define CAN_HARWARE_OBJECT_TX_1       3u
#define CAN_TESTCASE_COUNT            74
#define CAN_MRAM_INDEX_SIZE          0x4
#define CAN_ECC_SEC_ERROR_INJ_VAL    0x1 
#define CAN_ECC_DED_ERROR_INJ_VAL    0x3
#define CAN_ECC_FAULT_INJ_DATA       0xFFFFFFFFu

#define CAN_PDU_INDEX_STD_CAN		 0
#define CAN_PDU_INDEX_FD_STD_CAN     1
#define CAN_PDU_INDEX_EXT_CAN		 2
#define CAN_PDU_INDEX_FD_EXT_CAN	 3
#define CAN_PDU_INDEX_VALID_LENGTH	 5

#define CAN_CNTRL_0_HW_OBJ_TX_DEDI_BUFF		0
#define CAN_CNTRL_0_HW_OBJ_TX_FIFO_BUFF		1
#define CAN_CNTRL_0_HW_OBJ_RX_DEDI_BUFF		2
#define CAN_CNTRL_0_HW_OBJ_RX_FIFO0_BUFF	3
#define CAN_CNTRL_0_HW_OBJ_RX_FIFO1_BUFF	4
#define CAN_CNTRL_1_HW_OBJ_TX_DEDI_BUFF		5
#define CAN_CNTRL_1_HW_OBJ_TX_FIFO_BUFF		6
#define CAN_CNTRL_1_HW_OBJ_RX_DEDI_BUFF		7
#define CAN_CNTRL_1_HW_OBJ_RX_FIFO0_BUFF	8
#define CAN_CNTRL_1_HW_OBJ_RX_FIFO1_BUFF	9
#define CAN_CNTRL_2_HW_OBJ_TX_DEDI_BUFF		10
#define CAN_CNTRL_2_HW_OBJ_TX_FIFO_BUFF		11
#define CAN_CNTRL_2_HW_OBJ_RX_DEDI_BUFF		12
#define CAN_CNTRL_2_HW_OBJ_RX_FIFO0_BUFF	13
#define CAN_CNTRL_2_HW_OBJ_RX_FIFO1_BUFF	14
#define CAN_CNTRL_3_HW_OBJ_TX_DEDI_BUFF		15
#define CAN_CNTRL_3_HW_OBJ_TX_FIFO_BUFF		16
#define CAN_CNTRL_3_HW_OBJ_RX_DEDI_BUFF		17
#define CAN_CNTRL_3_HW_OBJ_RX_FIFO0_BUFF	18
#define CAN_CNTRL_3_HW_OBJ_RX_FIFO1_BUFF	19
#define CAN_CNTRL_4_HW_OBJ_TX_DEDI_BUFF		20
#define CAN_CNTRL_4_HW_OBJ_TX_FIFO_BUFF		21
#define CAN_CNTRL_4_HW_OBJ_RX_DEDI_BUFF		22
#define CAN_CNTRL_4_HW_OBJ_RX_FIFO0_BUFF	23
#define CAN_CNTRL_4_HW_OBJ_RX_FIFO1_BUFF	24
#define CAN_CNTRL_5_HW_OBJ_TX_DEDI_BUFF		25
#define CAN_CNTRL_5_HW_OBJ_TX_FIFO_BUFF		26
#define CAN_CNTRL_5_HW_OBJ_RX_DEDI_BUFF		27
#define CAN_CNTRL_5_HW_OBJ_RX_FIFO0_BUFF	28
#define CAN_CNTRL_5_HW_OBJ_RX_FIFO1_BUFF	29
#define CAN_CNTRL_6_HW_OBJ_TX_DEDI_BUFF		30
#define CAN_CNTRL_6_HW_OBJ_TX_FIFO_BUFF		31
#define CAN_CNTRL_6_HW_OBJ_RX_DEDI_BUFF		32
#define CAN_CNTRL_6_HW_OBJ_RX_FIFO0_BUFF	33
#define CAN_CNTRL_6_HW_OBJ_RX_FIFO1_BUFF	34
#define CAN_CNTRL_7_HW_OBJ_TX_DEDI_BUFF		35
#define CAN_CNTRL_7_HW_OBJ_TX_FIFO_BUFF		36
#define CAN_CNTRL_7_HW_OBJ_RX_DEDI_BUFF		37
#define CAN_CNTRL_7_HW_OBJ_RX_FIFO0_BUFF	38
#define CAN_CNTRL_7_HW_OBJ_RX_FIFO1_BUFF	39

/********************************************************************/
/**                 Enums for fault injection tests                **/
/********************************************************************/
typedef struct Std_ReturnType (*FuncPointer)(void);
typedef struct 
{
	Std_ReturnType (*Func)(void);

}Testcase;

typedef enum {
	CTRL_ZERO = 0,
	CTRL_ONE,
	CTRL_TWO,
	CTRL_THREE,
	CTRL_FOUR,
	CTRL_FIVE,
	CTRL_SIX,
	CTRL_SEVEN
}CanCTRLIndex;
typedef enum {
 
    FUSA_ECC_ERR_DATA_SEC,
 
    FUSA_ECC_ERR_ADDR_SEC,
 
    FUSA_ECC_ERR_DATA_DED,
 
    FUSA_ECC_ERR_ADDR_DED
 
} ECC_FUSA_ERROR;

typedef enum {
    CAN_FUSA_TIMEOUT_FLT_INJ_DMA_MRAM_AHB,
    CAN_FUSA_TIMEOUT_FLT_INJ_AHB_SLAVE_ARB,
    CAN_FUSA_TIMEOUT_FLT_INJ_MRAM_ARB,
    CAN_FUSA_TIMEOUT_FLT_INJ_DMA_FSM
} CAN_FUSA_TIMEOUT_FLT_INJ;
 
typedef enum {
 
    MRAM_ARB_TIMEOUT_FAULT_INJ_MCAN_ARB1,
 
    MRAM_ARB_TIMEOUT_FAULT_INJ_DMU_ARB2
 
} MRAM_ARBITER_TIMEOUT_FAULT_INJ;
 
typedef enum {
	AHB_SLAVE_ARB_TIMEOUT_FAULT_INJ_DMA_MRAM_ARB1,
	AHB_SLAVE_ARB_TIMEOUT_FAULT_INJ_NOC_AHB_ARB2
} AHB_SLAVE_ARB_TIMEOUT_FAULT_INJ;

/********************************************************************/
/**                 DET driver Global variables                    **/
/********************************************************************/
extern uint8 DetReportedOnCan;
/********************************************************************/
/**                 CanIf driver Global variables                  **/
/********************************************************************/
#ifndef CAN_PLT_SAFERTOS_ENABLE
extern uint8 TriggerTransmitDataLength;
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
/********************************************************************/
/**                      CAN Config variables                      **/
/********************************************************************/
extern const Can_ConfigType Can_Config_Default;
extern const Can_ConfigType Can_Config_NewEntry;
extern const Can_ConfigType Can_Config_WaterMark;
extern const Can_ConfigType Can_Config_Dma;
extern const Can_ConfigType Can_Config_Filter;
extern const Can_ConfigType Can_Config_TxQueue;
extern const Can_ConfigType Can_Config_FdDisabled;
extern const Can_ConfigType Can_Config_Mixed;
extern const Can_ConfigType Can_Config_UT;

/********************************************************************/
/**                       CAN Testapp function                     **/
/********************************************************************/
void Can_Test(void);
void CanTest_RegisterCallBacks(void);
void CanTest_DeRegister_All_Clients(void);

/********************************************************************/
/**                          CANTC function                        **/
/********************************************************************/
extern Std_ReturnType CanTC_ReadRegister(void);
extern Std_ReturnType CanTC_ReadRegRange(void);
extern Std_ReturnType CanTC_SetRegister(void);
extern Std_ReturnType CanTC_SetCanCtrlInfo(void);
extern Std_ReturnType CanTC_Init(void);
#if(CAN_VERSION_API_ENABLE == STD_ON)
extern Std_ReturnType CanTC_GetVersionInfo(void);
#endif
#if(CAN_SET_BAUDRATE_API == STD_ON)
extern Std_ReturnType CanTC_SetBaudrate(void);
#endif
extern Std_ReturnType CanTC_SetControllerMode(void);
extern Std_ReturnType CanTC_DisableControllerInterrupts(void);
extern Std_ReturnType CanTC_EnableControllerInterrupts(void);
extern Std_ReturnType CanTC_Write(void);
extern Std_ReturnType CanTC_MainFunction_Write(void);
extern Std_ReturnType CanTC_MainFunction_Read(void);
extern Std_ReturnType CanTC_MainFunction_BusOff(void);
extern Std_ReturnType CanTC_MainFunction_Wakeup(void);
extern Std_ReturnType CanTC_MainFunction_Mode(void);
extern Std_ReturnType CanTC_MainFunction_SSR_HM(void);
extern Std_ReturnType CanTC_CheckWakeup(void);
extern Std_ReturnType CanTC_DeInit(void);
extern Std_ReturnType CanTC_GetControllerErrorState(void);
extern Std_ReturnType CanTC_GetControllerMode(void);
extern Std_ReturnType CanTC_GetControllerRxErrorCounter(void);
extern Std_ReturnType CanTC_GetControllerTxErrorCounter(void);
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
extern Std_ReturnType CanTC_GetCurrentTime(void);
extern Std_ReturnType CanTC_EnableEgressTimeStamp(void);
extern Std_ReturnType CanTC_GetEgressTimeStamp(void);
extern Std_ReturnType CanTC_GetIngressTimeStamp(void);
#endif
extern Std_ReturnType CanTC_MainFunction_ConfigCheck(void);
extern Std_ReturnType CanTC_TimeoutFaultInjectionTest(void);
extern Std_ReturnType CanTC_EccFaultInjectionTest(void);
extern Std_ReturnType CanTC_ConfigureInterrupts(void);
extern Std_ReturnType CanTC_Write_TxFIFO(void);
extern Std_ReturnType CanTC_Write_TxClassicalStandardID(void);
extern Std_ReturnType CanTC_Write_TxClassicalExtendedID(void);
extern Std_ReturnType CanTC_Write_TxFdStandardID(void);
extern Std_ReturnType CanTC_Write_TxFdExtendedID(void);
extern Std_ReturnType CanTC_Write_TxAlltypesofFrames(void);
extern Std_ReturnType CanTC_SetControllerMode_Sleep(void);
extern Std_ReturnType CanTC_Fusa_Timeout_Status(void);
extern Std_ReturnType CanTC_Fusa_ECC_Status(void);
extern Std_ReturnType CanTC_Fusa_Protocol_Status(void);
extern Std_ReturnType CanTC_ExternalLoopback_Enable(void);
extern Std_ReturnType CanTC_InternalLoopback_Enable(void);
extern Std_ReturnType CanTC_Loopback_Disable(void);

