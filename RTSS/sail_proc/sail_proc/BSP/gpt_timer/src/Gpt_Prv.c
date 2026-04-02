/*
  ==============================================================================
*/
/*==============================================================================
  File Name          : Gpt_Prv.c
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
/*==============================================================================
**                              Include files                                 **
==============================================================================*/
#include "Gpt.h"
#include "Gpt_Prv.h"
#include "HALhwio.h"
/*==============================================================================
**                              defines and macros                            **
==============================================================================*/
GPT_TIMER_FUNC static uint64 GptPrv_GetCounterTargetValue( const Gpt_ChanHWType Chan, const uint64 counter, const uint64 value );
/*==============================================================================
**                           Utility API Defs                                 **
==============================================================================*/
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
GPT_TIMER_FUNC uint64 GptPrv_GetHWChanTicks( const uint64 swtick, const uint64 fHz )
{
    return ( ( swtick *  GPT_TICKPERSEC ) / fHz );  
}
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
GPT_TIMER_FUNC uint64 GptPrv_GetSWChanTicks( const uint64 hwtick, const uint64 fHz )
{
    return ( ( hwtick *  fHz ) / GPT_TICKPERSEC );  
}
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
GPT_TIMER_FUNC uint64 GptPrv_GetHWChanTickMax( const Gpt_ChanHWType Chan )
{
    uint64 Ret = Gpt_CNT_PROC_MAX;
    if(Chan == GPT_CHAN_HWTIMER_PL0_QTMR)
    {
        Ret = Gpt_CNT_MAX;
    }
    return Ret;
}
/*******************************************************************************
* Service Name:    : GptPrv_GetCounterTargetValue
* Syntax           : GptPrv_GetCounterTargetValue( const Gpt_ChanHWType Chan, const uint64 counter, const uint64 value )
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant 
* Parameters(IN)   : Chan : channel interface 
* Parameters(IN)   : counter : current counter value 
* Parameters(IN)   : value : set value requested 
* Parameters(OUT)  : None
* Return Value     : uint64 : time in ticks
* Description      : provides target counter value 
*******************************************************************************/
GPT_TIMER_FUNC static uint64 GptPrv_GetCounterTargetValue( const Gpt_ChanHWType Chan, const uint64 counter, const uint64 value )
{
    uint64 CounterMAX = Gpt_CNT_PROC_MAX;
    uint64 TargetCounter = 0U;
    uint64 CounterRollOff = 0U;
    if(Chan == GPT_CHAN_HWTIMER_PL0_QTMR)
    {
        CounterMAX = Gpt_CNT_MAX;
    }
    CounterRollOff = ( CounterMAX - counter );
    if( CounterRollOff >= value )
    {
        TargetCounter = counter + value;
    }
    else 
    {
        TargetCounter = ((value - CounterRollOff) + 1U);
        if( TargetCounter >= counter )
        {
            TargetCounter = CounterMAX;
        }
    }
    return TargetCounter;
}
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
GPT_TIMER_FUNC void GptPrv_EnableTimer(const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW)
{
    /* Unmask interrupt bit 1 and enable timer bit 0*/
    switch(ChanHW)
    {
        case GPT_CHAN_HWTIMER_PL2_PHY:
            __asm__ volatile( "ldr r4, =1\n\t"
                              "mcr p15, 4, r4, c14, c2, 2\n\t": : :"r4");
            break;
        case GPT_CHAN_HWTIMER_PL1_PHY:
            __asm__ volatile( "ldr r4, =1\n\t"
                              "mcr p15, 0, r4, c14, c2, 1\n\t": : :"r4");
            break;  
        case GPT_CHAN_HWTIMER_PL1_VRT:
            __asm__ volatile( "ldr r4, =1\n\t"
                              "mcr p15, 0, r4, c14, c3, 1\n\t": : :"r4");
            break;
        default:
            outpdw((uint32)Gpt_CNTP_CTRL_OFFSET(timerId), (uint32)0x1);
            break;
    }
    return;
}
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
GPT_TIMER_FUNC void GptPrv_DisableTimer(const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW)
{
    /* Enable timer      0st bit position =   1 ( 0x0 Disabled, 0x1 Enabled)
    * Un-mask interrupt 1nd bit position =   0 ( 0x0 Unmask,   0x1 Mask) */
    switch(ChanHW)
    {
        case GPT_CHAN_HWTIMER_PL2_PHY:
            __asm__ volatile( "ldr r4, =2\n\t"
                              "mcr p15, 4, r4, c14, c2, 2\n\t": : :"r4");
            break;
        case GPT_CHAN_HWTIMER_PL1_PHY:
            __asm__ volatile( "ldr r4, =2\n\t"
                              "mcr p15, 0, r4, c14, c2, 1\n\t": : :"r4");
            break;  
        case GPT_CHAN_HWTIMER_PL1_VRT:
            __asm__ volatile( "ldr r4, =2\n\t"
                              "mcr p15, 0, r4, c14, c3, 1\n\t": : :"r4");
            break;    
        default:
            outpdw((uint32)Gpt_CNTP_CTRL_OFFSET(timerId), (uint32)0x2);
            break;
    }
    return;
}
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
GPT_TIMER_FUNC uint64 GptPrv_GetCounterValue(const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW)
{
    uint32 lHigh  = 0U;
    uint32 lLow   = 0U;
    switch( ChanHW )
    {
        /* common */
        case GPT_CHAN_HWTIMER_PL2_PHY:
        case GPT_CHAN_HWTIMER_PL1_PHY:
            __asm__ volatile( "dsb\n\t"
                              "isb\n\t"
                              "mrrc p15, 0, %0, %1, c14\n\t" : "=r" (lLow), "=r" (lHigh));
            break;
            
        case GPT_CHAN_HWTIMER_PL1_VRT:
            __asm__ volatile( "dsb\n\t"
                              "isb\n\t"
                              "mrrc p15, 1, %0, %1, c14\n\t" : "=r" (lLow), "=r" (lHigh));
            break;
     
        default:
            lHigh = inpdw(Gpt_CNTPCT_HI_OFFSET(timerId));
            lLow = inpdw(Gpt_CNTPCT_LO_OFFSET(timerId));
            break;
    }
    return (((uint64)lHigh << 32U) | ((uint64)lLow));
}
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
GPT_TIMER_FUNC uint64 GptPrv_SetCounterValue( const Gpt_ChannelType timerId, const Gpt_ChanHWType ChanHW, const uint64 value, uint64 *startValue )
{
    uint32 lHigh = 0U;
    uint32 lLow = 0U;
    uint64 lCurrentValue = 0U;
    uint64 lNewValue = 0U;
    switch( ChanHW )
    {
        case GPT_CHAN_HWTIMER_PL2_PHY: 
            __asm__ volatile("dsb");
            __asm__ volatile("isb");
            __asm__ volatile("mrrc p15, 0, %Q0, %R0, c14" : "=r" (lCurrentValue)::"memory");
            lNewValue = GptPrv_GetCounterTargetValue(ChanHW, lCurrentValue , value); 
            __asm__ volatile("mcrr p15, 6, %Q0, %R0, c14" :: "r" (lNewValue):"memory");
            if(NULL_PTR != startValue)
            {
                *startValue = lCurrentValue;
            }             
            break;
        case GPT_CHAN_HWTIMER_PL1_PHY:
            __asm__ volatile("dsb");
            __asm__ volatile("isb");
            __asm__ volatile("mrrc p15, 0, %Q0, %R0, c14" : "=r" (lCurrentValue)::"memory");
            lNewValue = GptPrv_GetCounterTargetValue(ChanHW, lCurrentValue , value); 
            __asm__ volatile("mcrr p15, 2, %Q0, %R0, c14" :: "r" (lNewValue):"memory");
            if(NULL_PTR != startValue)
            {
                *startValue = lCurrentValue;
            }
            break;             
        case GPT_CHAN_HWTIMER_PL1_VRT:
            __asm__ volatile("dsb");
            __asm__ volatile("isb");
            __asm__ volatile("mrrc p15, 1, %Q0, %R0, c14" : "=r" (lCurrentValue)::"memory");
            lNewValue = GptPrv_GetCounterTargetValue(ChanHW, lCurrentValue , value); 
            __asm__ volatile("mcrr p15, 3, %Q0, %R0, c14" :: "r" (lNewValue):"memory");
            if(NULL_PTR != startValue)
            {
                *startValue = lCurrentValue;
            }
            break;    
        default:
            lCurrentValue = GptPrv_GetCounterValue(timerId, ChanHW);
            lNewValue = GptPrv_GetCounterTargetValue(ChanHW, lCurrentValue , value); 
            lHigh = (uint32)(((uint64)lNewValue >> 32U) & Gpt_VAL_HI_MASK);
            lLow  = (uint32)((uint64)lNewValue & Gpt_VAL_LO_MASK);
            outpdw(Gpt_CNTP_CVAL_HI_OFFSET(timerId), lHigh);
            outpdw(Gpt_CNTP_CVAL_LO_OFFSET(timerId), lLow);
            if(NULL_PTR != startValue)
            {
                *startValue = lCurrentValue;
            }
            break;
    }
    return lNewValue;
}
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
GPT_TIMER_FUNC uint64 GptPrv_GetTimeDifference( const uint64 time1,  const uint64 time2)
{
    uint64 lReturn = 0U;
    if(time1 > time2)
    {
        lReturn = time1 - time2;
    }
    else
    {
        lReturn = time2 - time1;
    }
    return lReturn;
}
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
GPT_TIMER_FUNC uint64 GptPrv_ConvertUSTicksToHwTicks( const uint64 usTicks, const uint32 preDefResolution )
{
	return ((uint64)(((usTicks * (preDefResolution * GPT_TICKPERSEC))/ GPT_MICROSEC)));
}
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
GPT_TIMER_FUNC uint64 GptPrv_ConvertHwTicksToUSTicks( const uint64 Hwticks, const uint32 preDefResolution )
{
	return ((uint64)(( GPT_MICROSEC * Hwticks ) / (preDefResolution * GPT_TICKPERSEC )));
}
/*==============================================================================
**                    End of file Gpt_Prv.c                                   **
==============================================================================*/
