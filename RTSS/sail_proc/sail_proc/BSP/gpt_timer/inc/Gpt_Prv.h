/*
  ==============================================================================
*/
/*==============================================================================
  File Name          : Gpt_Prv.h
  Component Name     : MCAL Gpt module as gpt_timer RTD Module 
  Description        : AutoSAR R 24-11
  $Header: 
  $DateTime: 
  $Author: 
  ============================================================================*/
/*
  ==============================================================================
  
  Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
   
  ==============================================================================

  $Header: 
  $DateTime:
  $Author:

  ==============================================================================
*/
/*
  ==============================================================================

  EDIT HISTORY FOR MODULE

  when       who      what, where, why
  --------   -------  ----------------------------------------------------------

  ==============================================================================
*/
#ifndef GPT_PRV_H__
#define GPT_PRV_H__
/*==============================================================================
**                              Include files                                 **
==============================================================================*/
#include "Gpt.h"
#include "msmhwiobase.h"
#include "g_SAIL_QTMR.h"
#include "HALhwio.h"
#include "hw_io.h"
/*==============================================================================
**                              defines and macros                            **
==============================================================================*/
#define GPT_MICROSEC           (uint64)(1000000U)
#define GPT_TICKPERSEC         (uint64)(19200000U)
#define Gpt_PHYIRQ_0                                            96U
#define Gpt_PHYIRQ_PROC                                         26U
#define Gpt_CNT_MAX                                             0xFFFFFFFFFFFFFFUL
#define Gpt_VAL_HI_MASK                                         0x00FFFFFFUL
#define Gpt_VAL_LO_MASK                                         0xFFFFFFFFUL
#define Gpt_CNT_PROC_MAX                                        0xFFFFFFFFFFFFFFFFUL

/* Timer channel Represents a logical timer entity assigned to a timer hardware */

#define Gpt_BASE_ADDR_OFFSET(timerId)                           (SAILSS_QTMR_SAILSS_QTMR_BASE + ((timerId) * 0x1000U))
#define Gpt_CNTPCT_LO_OFFSET(timerId)                           (Gpt_BASE_ADDR_OFFSET(timerId))
#define Gpt_CNTPCT_HI_OFFSET(timerId)                           (Gpt_BASE_ADDR_OFFSET(timerId) + 0x4U)
#define Gpt_CNTFREQ_OFFSET(timerId)                             (Gpt_BASE_ADDR_OFFSET(timerId) + 0x10U)
#define Gpt_CNTPLO_ACR_OFFSET(timerId)                          (Gpt_BASE_ADDR_OFFSET(timerId) + 0x14U)
#define Gpt_CNTP_CVAL_LO_OFFSET(timerId)                        (Gpt_BASE_ADDR_OFFSET(timerId) + 0x20U)
#define Gpt_CNTP_CVAL_HI_OFFSET(timerId)                        (Gpt_BASE_ADDR_OFFSET(timerId) + 0x24U)
#define Gpt_CNTP_TVAL_OFFSET(timerId)                           (Gpt_BASE_ADDR_OFFSET(timerId) + 0x28U)
#define Gpt_CNTP_CTRL_OFFSET(timerId)                           (Gpt_BASE_ADDR_OFFSET(timerId) + 0x2CU)
#define Gpt_VERSION_OFFSET(timerId)                             (Gpt_BASE_ADDR_OFFSET(timerId) + 0xFD0U)
#define Gpt_AC_BASE_ADDR_OFFSET                                 (SAILSS_QTMR_SAILSS_QTMR_BASE  + 0xC000U)
#define Gpt_AC_CNTACR_FG0_BASE_ADDR_OFFSET(timerId)             (Gpt_AC_BASE_ADDR_OFFSET + ( 0x4 * (timerId)) + 0x40U)
#define Gpt_AC_CNTACR_FG1_BASE_ADDR_OFFSET(timerId)             (Gpt_AC_BASE_ADDR_OFFSET + ( 0x4 * (timerId)) + 0x140U)
/*==============================================================================
**                              Private Declarations                          **
==============================================================================*/
/* Channel specific RTD */
typedef struct 
{
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    uint8                     GptChannelCbkEn;
    uint8                     GptChannelCbkBckEn;
    #endif
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    Gpt_EnableWakeupType GptEnableWakeup;                     /* en-dis wakeup */
    #endif
    Gpt_ChanHWType            GptChanHW;
    Gpt_ChannelStateType      GptChannelState;                /*  GPT Autosa Init, running, stopped, expired  */
    Gpt_ValueType             GptTargetTime;                  /*  Value stored for each timer when start timer API called, in micro second  ticks */
    uint64                    GptTargetTimeInHwTicks;         /*  Autosar ticks are in micro second  ticks converted into Hw ticks*/
    uint64                    GptStartValueInHWTicks;         /*  Value of free running cnt when each timer start requested and ticks are with respect to HW */    
    uint64                    GptStopValueInHwTicks;          /*  Value written to CVAL /Tval register to trigger ISR when free running cnt reached in HW ticks*/
    uint64                    GptStopReqTimeInHwTicks;        /*  Value of free running cnt timer ticks when time stop API Called  */
}Gpt_ChannelCoreDataType;

/* Module specific RTD */
typedef struct 
{
    const Gpt_ChannelConfigType *pGpt_ChannelConfig;   /* Hw and driver Config*/
    const Gpt_ModuleConfigType  *pGpt_ModuleConfig;    /* Driver Config*/
    Gpt_ChannelCoreDataType Gpt_ChannelCoreData[GptChannel_MAX_ID];
	Gpt_StateType 	      GptDrvState;           /*  INIT and UN-INIT*/
	Gpt_ModeType 	      GptDrvMode;            /*  Normal mode and Sleep mode */
    uint32                GptPredefTimerEn;      /*  predef channel mask */
    uint64                GptPredefTimerTickvOffs;   /*  HW doesnt support directly emulate using HW base ticker */
    uint64                GptPredefTimerTickMax;    /*  HW doesnt support directly emulate using HW base ticker */
    uint32                GptDetErrCnt;
    uint32                GptRunErrCnt;
}Gpt_ModuleCoreDataType;
/*==============================================================================
**                              Function Declarations                         **
==============================================================================*/
/*******************************************************************************
* Service Name:    : GptPrv_SetCounterValue
* Syntax           : GptPrv_SetCounterValue( const Gpt_ChannelType timerId,
                        const Gpt_ChanHWType ChanHW,
                        const uint64 value, uint64 *startValue )
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : NonReentrant for same channel
* Parameters(IN)   : timerId : Numeric identifier of the GPT.
*                    ChanHW  : Numeric identifier of the HW SWI.
*                    value   : Timeout value for the GPT   
* Parameters(OUT)  : startValue : Value of tick at which timer was started
* Return Value     : uint64     : Value of tick at which GPT woudl expire
* Description      : Sets the timeout tick value for the selected timer.
*******************************************************************************/
GPT_TIMER_FUNC uint64 GptPrv_SetCounterValue( const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW, const uint64 value, uint64 *startValue );
/*******************************************************************************
* Service Name:    : GptPrv_GetCounterValue
* Syntax           : uint64 GptPrv_GetCounterValue(const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW)
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Non Reentrant for same channel
* Parameters(IN)   : timerId : Numeric identifier of the GPT.
* Parameters(IN)   : ChanHW  : Numeric identifier of the HW SWI.
* Return Value     : counter value
* Description      : Gets the current tick value for the selected timer.
*******************************************************************************/
GPT_TIMER_FUNC uint64 GptPrv_GetCounterValue(const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW);
/*******************************************************************************
* Service Name:    : GptPrv_GetTimeDifference
* Syntax           : uint64 GptPrv_GetTimeDifference( const uint64 time1,  const uint64 time2)
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant 
* Parameters(IN)   : time1 : First timestamp.
*                    time2 : Second timestamp
* Return Value     : uint64 : Difference between two timestamps
* Description      : Finds the difference between two timestamps
*******************************************************************************/
GPT_TIMER_FUNC uint64 GptPrv_GetTimeDifference( const uint64 time1,  const uint64 time2);
/*******************************************************************************
* Service Name:    : GptPrv_EnableTimer
* Syntax           : void GptPrv_EnableTimer(const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW)
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Non Reentrant for same channel
* Parameters(IN)   : timerId : Numeric identifier of the GPT.
* Parameters(IN)   : ChanHW  : Numeric identifier of the HW SWI.
* Description      : Enables the selected timer 
*******************************************************************************/
GPT_TIMER_FUNC void GptPrv_EnableTimer(const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW);
/*******************************************************************************
* Service Name:    : GptPrv_DisableTimer
* Syntax           : void GptPrv_DisableTimer(const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW)
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Non Reentrant for same channel
* Parameters(IN)   : timerId : Numeric identifier of the GPT.
* Parameters(IN)   : ChanHW  : Numeric identifier of the HW SWI.
* Description      : Disables the selected timer 
*******************************************************************************/
GPT_TIMER_FUNC void GptPrv_DisableTimer(const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW);
/*******************************************************************************
* Service Name:    : GptPrv_ConvertUSTicksToHwTicks
* Syntax           : uint64 GptPrv_ConvertUSTicksToHwTicks( const uint64 usTicks, const uint32 preDefResolution )
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant 
* Parameters(IN)   : usTicks : ticks in microseconds.
*                    preDefResolution : predefined resolution of timer
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : uint64 : time in scaled HW ticks
* Description      : Converts microseconds ticks to  scaled HW ticks
*******************************************************************************/
GPT_TIMER_FUNC uint64 GptPrv_ConvertUSTicksToHwTicks( const uint64 usTicks, const uint32 preDefResolution );
/*******************************************************************************
* Service Name:    : GptPrv_ConvertHwTicksToUSTicks
* Syntax           : uint64 GptPrv_ConvertHwTicksToUSTicks( const uint64 Hwticks, const uint32 preDefResolution )
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant 
* Parameters(IN)   : Hwticks : time in ticks.
*                    preDefResolution : predefined resolution of timer
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : uint64 : time in microseconds
* Description      : Converts ticks to microseconds
*******************************************************************************/
GPT_TIMER_FUNC uint64 GptPrv_ConvertHwTicksToUSTicks( const uint64 Hwticks, const uint32 preDefResolution );
/*******************************************************************************
* Service Name:    : GptPrv_GetHWChanTicks
* Syntax           : uint64 GptPrv_GetHWChanTicks( const uint64 swtick, const uint64 fHz )
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant 
* Parameters(IN)   : swtick : time in ticks.
*                    fHz : frequency in Hz
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : uint64 : time in ticks
* Description      : map HW ticks to SW ticks
*******************************************************************************/
GPT_TIMER_FUNC uint64 GptPrv_GetHWChanTicks( const uint64 swtick, const uint64 fHz );
/*******************************************************************************
* Service Name:    : GptPrv_GetSWChanTicks
* Syntax           : uint64 GptPrv_GetSWChanTicks( const uint64 hwtick, const uint64 fHz )
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant 
* Parameters(IN)   : hwtick : time in ticks.
*                    fHz : frequency in Hz
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : uint64 : time in ticks
* Description      : map HW ticks to SW ticks
*******************************************************************************/
GPT_TIMER_FUNC uint64 GptPrv_GetSWChanTicks( const uint64 hwtick, const uint64 fHz );
/*******************************************************************************
* Service Name:    : GptPrv_GetHWChanTickMax
* Syntax           : uint64 GptPrv_GetHWChanTickMax( const Gpt_ChanHWType Chan )
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant 
* Parameters(IN)   : Chan : channel interface 
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : uint64 : time in ticks
* Description      : provide Max HW ticks
*******************************************************************************/
GPT_TIMER_FUNC uint64 GptPrv_GetHWChanTickMax( const Gpt_ChanHWType Chan );
#endif /* GPT_PRV_H */
/*==============================================================================
**                    End of file Gpt_Prv.h                                   **
==============================================================================*/
