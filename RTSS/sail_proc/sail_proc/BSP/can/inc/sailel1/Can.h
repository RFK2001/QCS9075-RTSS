/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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

    ===========================================================================

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/
/*==============================================================================
    File Name.............. : Can_Main.h
    Description............ : This file contains functionality of CAN driver
    Autosar Release Version : R22-11
    Platform............... :
    SW Release Version..... :
==============================================================================*/
/*==============================================================================
|                       MISRA-C VIOLATIONS                                     |
==============================================================================*/
/*
*/
#ifndef CAN_H
#define CAN_H
#ifdef __cplusplus
extern "C"{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
/* Includes all types and constants that are shared among the
   AUTOSAR CAN modules Can and CanIf */
#include "Can_GeneralTypes.h"
#include "Std_Types.h"
#include "Can_Cfg.h"
#include "EcuM_Cbk.h"
/*==============================================================================
|                       EXPORTED CONSTANTS and MACROS                          |
==============================================================================*/
/* [SWS_BSW_00059] Published information elements. */
#ifndef CAN_AR_RELEASE_MAJOR_VERSION
#define CAN_VENDOR_ID   0xB8u
#define CAN_MODULE_ID   0x50u
#define CAN_AR_RELEASE_MAJOR_VERSION     4u
#define CAN_AR_RELEASE_MINOR_VERSION     8u
#define CAN_AR_RELEASE_REVISION_VERSION  0u
#endif
#define CAN_SW_MAJOR_VERSION     1u
#define CAN_SW_MINOR_VERSION     0u
#define CAN_SW_PATCH_VERSION     0u
#define CAN_INSTANCE_ID   CAN_CFG_INSTANCE_ID
/* Service IDs. Used while reporting development errors */
#define CAN_SID_INIT                        ((uint8)0x00)
#define CAN_SID_MAINFUNCTION_WRITE          ((uint8)0x01)
#define CAN_SID_SETCONTROLLERMODE           ((uint8)0x03)
#define CAN_SID_DISABLECONTROLLERINTERRUPTS ((uint8)0x04)
#define CAN_SID_ENABLECONTROLLERINTERRUPTS  ((uint8)0x05)
#define CAN_SID_WRITE                       ((uint8)0x06)
#define CAN_SID_GETVERSIONINFO              ((uint8)0x07)
#define CAN_SID_MAINFUNCTION_READ           ((uint8)0x08)
#define CAN_SID_MAINFUNCTION_BUSOFF         ((uint8)0x09)
#define CAN_SID_MAINFUNCTION_WAKEUP         ((uint8)0x0a)
#define CAN_SID_CHECKWAKEUP                 ((uint8)0x0b)
#define CAN_SID_MAINFUNCTION_MODE           ((uint8)0x0c)
#define CAN_SID_SET_BAUDRATE                ((uint8)0x0f)
#define CAN_SID_DEINIT                      ((uint8)0x10)
#define CAN_SID_GETCONTROLLERERRORSTATE     ((uint8)0x11)
#define CAN_SID_GETCONTROLLERMODE           ((uint8)0x12)
#define CAN_SID_GETCONTROLLERRXERRORCOUNTER ((uint8)0x30)
#define CAN_SID_GETCONTROLLERTXERRORCOUNTER ((uint8)0x31)
#define CAN_SID_GETCURRENTTIME              ((uint8)0x32)
#define CAN_SID_ENABLEEGRESSTIMESTAMP       ((uint8)0x33)
#define CAN_SID_GETEGRESSTIMESTAMP          ((uint8)0x34)
#define CAN_SID_GETINGRESSTIMESTAMP         ((uint8)0x35)
/* Custom API IDs */
#define CAN_SID_ISR                         ((uint8)0xF0)
#define CAN_SID_FUSA_MAINFUNCTION           ((uint8)0xF1)
#define CAN_SID_WARNING_ISR                 ((uint8)0xF2)
#define CAN_SID_ERROR_ISR                   ((uint8)0xF3)
#define CAN_SID_FUSA_MAINFUNCTION_HM        ((uint8)0xF4)

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/* API Service called with wrong parameter: Config is a null pointer */
#define CAN_E_PARAM_POINTER      ((uint8)0x1)
/* API Service called with wrong parameter:: Handle parameter is not a
   configured Hardware Transmit Handle*/
#define CAN_E_PARAM_HANDLE       ((uint8)0x2)
/* API Service called with wrong parameter:Invalid Data length */
#define CAN_E_PARAM_DATA_LENGTH  ((uint8)0x3)
/* API Service called with wrong parameter : Parameter Controller is out of range  */
#define CAN_E_PARAM_CONTROLLER   ((uint8)0x4)
/* API Service used without initialization */
#define CAN_E_UNINIT             ((uint8)0x5)
/* Invalid transition requested OR Invalid CAN controller state */
#define CAN_E_TRANSITION         ((uint8)0x6)
/* Parameter Baudrate has an invalid value */
#define CAN_E_PARAM_BAUDRATE     ((uint8)0x7)
/* Invalid configuration set selection */
#define CAN_E_INIT_FAILED        ((uint8)0x9)
/* API service called with invalid PDU ID */
#define CAN_E_PARAM_LPDU         ((uint8)0x0a)
/* fusa init failed */
#define CAN_E_FUSA_INIT_FAILED   ((uint8)0x0b)

#define CAN_E_FUSA_SM_NOTIFY_FAILED ((uint8)0x0c)
#define CAN_E_FUSA_DEINIT_FAILED ((uint8)0x0d)
#define CAN_E_FUSA_HM_REPORT_FAILED ((uint8)0x0e)
#define CAN_E_IRQ_CALL_DEPTH_OVERFLOW ((uint8)0x0f)
#endif /* #if (CAN_DEV_ERROR_DETECT == STD_ON) */
/* Runtime Errors */
#define CAN_E_DATALOST           ((uint8)0x1)
/*Can message ID is Standard*/
#define CAN_STANDARD_ID          ((uint8)0x0)
/*Can message ID is EXTENDED*/
#define CAN_EXTENDED_ID          ((uint8)0x1)
/*Can message ID is MIXED*/
#define CAN_MIXED_ID             ((uint8)0x2)
#define CAN_ZERO                 0x0u
#define CAN_ONE                  0x1u
#define CAN_MAX_FD_LENGTH        0x40u
#define CAN_PERIODID_IGNORE      0xFFu
/*==============================================================================
|                       EXPORTED STRUCTURES, ENUMS, TYPEDEFS                   |
==============================================================================*/
/* Type for CAN Driver states */
typedef uint8 Can_DriverStateType;
/* Type to reperesent identifier type of an L-PDU */
typedef uint8 Can_FrameType;
/*
  Values for CAN Driver states.
*/
typedef enum
{
    CAN_HW_UNINIT = 0u,
    CAN_HW_READY
}CanHWUnitStateType;
typedef enum
{
    CAN_POLLING = 0u,
    CAN_INTERRUPT,
    CAN_INTERRUPT_ON_NEW_ENTRY,
    CAN_INTERRUPT_ON_WATERMARK,
    CAN_MIXED
}CanProcessingMode;
typedef enum
{
    CAN_TSZERO =0u,
    CAN_INTERNAL,
    CAN_EXTERNAL
}Can_TSSelectType;
typedef enum
{
    MUTEX_RELEASED=0u,
    MUTEX_SIGNALED
}Can_MutexState;
typedef enum
{
    CAN_RANGE = 0u,
    CAN_DUALID,
    CAN_CLASSIC
}Can_HwFilterModeType;
typedef enum
{
    CAN_BASIC = 0u,
    CAN_FULL
}Can_HandleType;
typedef enum
{
    CAN_TXOBJ = 0u,
    CAN_RXOBJ
}Can_HwObjType;
typedef enum
{
    CAN_CTR_INACTIVE =0u,
    CAN_CTR_ACTIVE
}Can_CtrlActivationState;
typedef enum
{
    CAN_TxFIFO =0u,
    CAN_TxQUEUE,
    CAN_TxBuffer
}Can_TxBufferType;
typedef enum
{
    CAN_RxFIFO0 =0u,
    CAN_RxFIFO1,
    CAN_RxDedicatedBuffer
}Can_RxBufferType;
typedef enum
{
    CAN_LOOPBACK_DISABLED = 0u,
    CAN_LOOPBACK_INTERNAL,
    CAN_LOOPBACK_EXTERNAL
}Can_LoopBackType;

typedef uint8 CAN_CtrIdType;
/* Structure for defining Can Controller States */
typedef struct
{
    /* Can Controller Unit ID*/
    uint8 CanCtrlUnitID;
    /* Can Controller Current State*/
    Can_ControllerStateType CanCtrlState;
    /* Can Controller Requested State*/
    Can_ControllerStateType CanCtrlRequestedState;
    /* Can Controller Current Baudrate Index*/
    uint16 CanCtrlCurBaudrateIdx;
}Can_CtrlType;
typedef struct
{
    /*CAN Hardware Object Type*/
    Can_HwObjType ObjType;
    /*CAN Hardware Object Index */
    uint8 ObjIndex;
} Can_TxRxObjMappingType;
/* CanFD Baudrate Configuration Parameters */
typedef struct
{
    /* Can Controller Baudrate */
    uint16 Baudrate;
    /* Can Controller PropSeg */
    uint8  ControllerPropSeg;
    /* Can Controller Seg1 */
    uint8  ControllerPhaseSeg1;
    /* Can Controller Seg2 */
    uint8  ControllerPhaseSeg2;
    /* Can Controller SyncJumpWidth */
    uint8  ControllerSyncSeg;
	/* Can Controller BRP Value */
    uint16 DataBRPValue ;
    boolean DelayEnable;
    /* Can Controller Trcv Delay Compensation offset*/
    uint16 TrcvCompDelayOffset;
    /* Can Controller Trcv Delay Compensation filter window length*/
    uint16 TrcvCompDelayFilterLength;
    /* Can Controller FD Tx BitRate Switch Enabled */
    boolean BrsSwitch;
} Can_DataBaudConfigPtrType;
/* Baudrate Configuration Parameters */
typedef struct
{
    /* Can Controller Baudrate */
    uint16 Baudrate;
    /* Can Controller PropSeg */
    uint8  ControllerPropSeg;
    /* Can Controller Seg1 */
    uint8  ControllerPhaseSeg1;
    /* Can Controller Seg2 */
    uint8  ControllerPhaseSeg2;
    /* Can Controller Sync Segment */
    uint8  ControllerSyncSeg;
    /*Nominal Bit Rate Prescaler*/
    uint8  NominalBRPValue;
    /* Pointer to CanFD Configurations */
    const  Can_DataBaudConfigPtrType *DataBaudRatePtr;
} Can_NominalBaudConfigPtrType;
/* CAN Hardware filter Configurations */
typedef struct
{
    /*Can Hardware filter mode*/
    Can_HwFilterModeType HwFilterType;
    /*Can Hardware filter mask value*/
    uint32 HwFilterMask;
    /*Can Hardware filter value*/
    uint32 HwFilterValue;
    /*Can Hardware filter event number*/
    uint8 HwFilterEvent;
}Can_HwFilterConfigType;
/* CAN Hardware Objects (HRH)  Configurations */
typedef struct
{
    /* Can Hardware Object ID */
    Can_HwHandleType  HwRxObjectId;
    /* Can Hardware Object controller Id */
    uint8  HwRxObjectCtrlrId;
    /* Can Rx Buffer Index */
    uint8  RxBufferIndex;
    /*Rx message buffer type*/
    Can_RxBufferType RxMsgBufType;
    /*Can type of the hardware object :Full-CAN or Basic-CAN */
    Can_HandleType HwRxObjHandle;
    /* Can Identifier type */
    uint8 CanIdType;
	/*Object Payload length */
    uint8  RxPayloadLength;
    /*Number of filters configured for the given HOH*/
    uint8 HwFilterCount;
    /*Pointer to filter configurations */
    const Can_HwFilterConfigType *HwFilterPtr;
#if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    boolean ObjectPollingEnabled;
#endif
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
    uint8 RxPeriodId;
#endif
} Can_RxHOHType;
typedef struct
{
    /* Can Hardware Object ID */
    Can_HwHandleType HwTxObjectId;
    /*Can type of the hardware object :Full-CAN or Basic-CAN */
    Can_HandleType HwTxObjHandle;
    /* Can Identifier type */
    Can_IdType CanIdType;
    /* Can Tx Buffer Index */
    Can_TxBufferType TxMsgBufType;
    /*Buffer Index corresponding to the HW object*/
    uint8 TxBufferIndex;
    /* Can Hardware Object controller Id */
    uint8 HwTxObjectCtrlrId;
    /* Padding value*/
    uint8 PaddingValue;
    /*Payload length*/
    uint8 TxPayloadLength;
    /* Trigger Transmit Enabled*/
    boolean TriggerTxEnable;
#if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    boolean ObjectPollingEnabled;
#endif
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
    uint8 TxPeriodId;
#endif
} Can_TxHOHType;
typedef struct
{
    /*Atlease one Tx buffer is configured as FIFO*/
    boolean TxFIFOUsed;
    /*Atlease one Tx buffer is configured as QUEUE*/
    boolean TxQUEUEUsed;
    /*if Tx Event FIFO is configured*/
    boolean TxEventFIFOUsed;
    /*Atlease one Rx buffer is configured as FIFO0*/
    boolean RxFIFO0Used;
    /*Atlease one Rx buffer is configured as FIFO1*/
    boolean RxFIFO1Used;
    /*RX buffer is used*/
    boolean RxBufferUsed;
    boolean AcceptNonMatchFrameSTDRXFIFO0;
    boolean AcceptNonMatchFrameSTDRXFIFO1;
    boolean AcceptNonMatchFrameEXTRXFIFO0;
    boolean AcceptNonMatchFrameEXTRXFIFO1;
    uint8 RxMaxBufferDlc;
    uint8 RxMaxFIFO1Dlc;
    uint8 RxMaxFIFO0Dlc;
    uint8 TxMaxBufferDlc;
    uint8 StdandardIdFiltersCount;
    uint8 ExtendedIdFiltersCount;
    uint8 RxFifo0BufferCount;
    uint8 RxFifo1BufferCount;
    uint8 DedicatedRxBufferCount;
    uint8 TxEventFIFOCount;
    uint8 TxFIFOQueueCount;
    uint8 TxBufferCount;
    uint16 FilterListSTDStartAdd;
    uint16 FilterListEXTStartAdd;
    uint16 RxFIFO0StartAdd;
    uint16 RxFIFO1StartAdd;
    uint16 RxBufferStartAdd;
    uint16 TxEventFIFOStartAdd;
    uint16 TxBufferStartAdd;
}Can_MsgRamConfigType;
typedef struct
{
    /*Can Controller ID */
    CAN_CtrIdType CanCtrID;
    /*Pointer to the base address of controller */
    const CanBaseAddressType *CanCtrBaseAdr;
    /*Can Controller TX Processing mode */
    CanProcessingMode CanTxProcessing;
    /*Can Controller RX Processing mode */
    CanProcessingMode CanRxProcessing;
    /*Can Controller Wakeup Processing mode */
    CanProcessingMode CanWakeupProcessing;
    /*Can Controller Busoff Processing mode */
    CanProcessingMode CanBusoffProcessing;
    /*Defines whether Wakeup is supported*/
    boolean CanWakeupSupport;
    /*Index of Default Baud Configurations*/
    uint8 DefaultBaudRateIndex;
    /*Pointer to Nominal Baud Configurations*/
    const Can_NominalBaudConfigPtrType *CanCtrlNominalBaudrate;
#if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    const uint32 *CanControllerEcucPartitionPtr;
#endif
    const EcuM_WakeupSourceType *CanWakeupSourcePtr;
    /*Defines whether Can FD Mode Enabled */
    boolean  CanFDModeEnabled;
    /*Number of baudrates configured for the controller used*/
    uint8 CanNumBaudrates;
    /*pointer to message ram configuration*/
    const Can_MsgRamConfigType* CanMsgRamConfig;
    /*Defines whether DMA enabled or not*/
    boolean CanDmaEnable;
    /*timestamp Prescalar*/
    uint8 CanTimeStampPreScalar;
    /*Tx FIFO watermark level*/
    uint8 CanTxFifoWaterMark;
    /*Rx FIFO 0 watermark level*/
    uint8 CanRxFifo0WaterMark;
	/*Rx FIFO 1 watermark level*/
    uint8 CanRxFifo1WaterMark;
    /* Loopback Enable */
    Can_LoopBackType CanLoopBackEnable;
}Can_CtrlConfigType;
/* Type of CAN external data structure containing the overall initialization
    data for the CAN Driver and settings affecting all controllers */
typedef struct
{
    /* Pointer to controller configurations */
    const Can_CtrlConfigType *CanActiveCtrPtr;
    /* Number of Tx Hardware Objects */
    Can_HwHandleType  CanNumOfTxHwObj;
    /* Pointer to Tx Hardware Objects(HTH) Configurations */
    const Can_TxHOHType *CanTxHwObjPtr;
    /* Number of Rx Hardware Objects */
    Can_HwHandleType CanNumOfRxHwObj;
    /* Pointer to Rx Hardware Objects(HTH) Configurations */
    const Can_RxHOHType *CanRxHwObjPtr;
    /* Pointer to store HOH object Id to index map */
    const Can_TxRxObjMappingType *CanTxRxObjMapPtr;
} Can_ConfigType;
/* Extern declarations of CAN configuration */
extern const Can_ConfigType Can_Config_Default;
/*==============================================================================
|                       EXPORTED FUNCTIONS                                     |
==============================================================================*/
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Init(const Can_ConfigType* Config);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_VERSION_API_ENABLE == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_GetVersionInfo(Std_VersionInfoType* versioninfo);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#if(CAN_SET_BAUDRATE_API == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_SetBaudrate(uint8 Controller,
                                    uint16 BaudRateConfigID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_SetControllerMode(uint8 Controller, 
                                     Can_ControllerStateType Transition);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_DisableControllerInterrupts(uint8 Controller);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_EnableControllerInterrupts(uint8 Controller);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_Write(Can_HwHandleType Hth,const Can_PduType* PduInfo);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_MainFunction_Write_Period(uint8 PeriodId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_MainFunction_Read_Period(uint8 PeriodId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_CheckWakeup(uint8 Controller);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_DeInit(void);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_GetControllerMode(uint8 Controller,
                                                 Can_ControllerStateType* ControllerModePtr);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_GetControllerTxErrorCounter(uint8 ControllerId,
                                                          uint8* TxErrorCounterPtr);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_GetControllerRxErrorCounter(uint8 ControllerId,
                                                          uint8* RxErrorCounterPtr);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_GetControllerErrorState(uint8 ControllerId,
                                                 Can_ErrorStateType* ErrorStatePtr);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#ifdef CAN_GLOBAL_TIME_SUPPORT
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
Std_ReturnType Can_GetCurrentTime (uint8 ControllerId,
                                           Can_TimeStampType* timeStampPtr
);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_EnableEgressTimeStamp(Can_HwHandleType Hth);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_GetEgressTimeStamp(PduIdType TxPduId,
											 Can_HwHandleType Hth,
											 Can_TimeStampType* timeStampPtr);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_GetIngressTimeStamp(
                                    Can_HwHandleType Hrh,
                                    Can_TimeStampType* timeStampPtr);

#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif

void Can_MainFunction_Mode(void);

/*==============================================================================
|                       EXPORTED VARIABLES                                     |
==============================================================================*/
/*==============================================================================
|                       VERSION CHECK                                          |
==============================================================================*/
/* SW version check of *.h/c of the own module */
#if ((CAN_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION_CFG_H) || \
     (CAN_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION_CFG_H) || \
     (CAN_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION_CFG_H))
    //#error "The SW version number of Can.h and Can_Cfg.h are different."
#endif
#ifdef __cplusplus
}
#endif
#endif /* CAN_H */
/*==============================================================================
==============================================================================*/
