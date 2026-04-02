/*
  ==============================================================================
*/
/*==============================================================================
  File Name          : Gpt_PBcfg.c
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
/*==============================================================================
**                           channel config macros                            **
==============================================================================*/
#define Gpt_GenChanWakeUpSrc( chan ) ( (uint32)(chan) << 5U )  
/*==============================================================================
**                           channel config macros                            **
==============================================================================*/
extern void xTestGptChannel0Notification();
 extern void xTestGptChannel1Notification();
 extern void xTestGptChannel2Notification();
 extern void xTestGptChannel3Notification();
 extern void xTestGptChannel4Notification();
 extern void xTestGptChannel5Notification();
 extern void xTestGptChannel6Notification();
 extern void xTestGptChannel7Notification();
 extern void xTestGptChannel8Notification();
 extern void xTestGptChannel9Notification();
 extern void xTestGptChannel10Notification();
 extern void xTestGptChannel11Notification();
/* Only for BSP module MCAL GPT TIMER RTD Manually build Config Post Build file */
#ifdef GptConf_GptChannel_GptChannel_00_ID  
    #define GptConf_GptChannel_GptChannel_00_TickFrequency       1000000U                   /* User configured channel 1Mhz freq */   
    #define GptConf_GptChannel_GptChannel_00_TickValueMax        0xFFFFFFFFU                /* Max Roll off Ticks */
    #define GptConf_GptChannel_GptChannel_00_ChannelMode         GPT_CH_MODE_ONESHOT        /* CONT OR ONETIME */
    #define GptConf_GptChannel_GptChannel_00_Notification        xTestGptChannel0Notification   /* user configured notification */    
    #define GptConf_GptChannel_GptChannel_00_HWType              GPT_CHAN_HWTIMER_PL0_QTMR  /* deafult:GPT_CHAN_HWTIMER_PL0_QTMR  else GPT_CHAN_HWTIMER_PL1_PHY */    
    #define GptConf_GptChannel_GptChannel_00_WakeUpEnable        GPT_FALSE                  /* user configured wakeup */    
    #define GptConf_GptChannel_GptChannel_00_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_00_ID )   /* default wakeup src config */    
#endif /* GptConf_GptChannel_GptChannel_00_ID */

#ifdef GptConf_GptChannel_GptChannel_01_ID  
    #define GptConf_GptChannel_GptChannel_01_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_01_TickValueMax        0xFFFFFFFFU
    #define GptConf_GptChannel_GptChannel_01_ChannelMode         GPT_CH_MODE_ONESHOT
    //#define GptConf_GptChannel_GptChannel_01_Notification        Gpt_Notification_Default
    #define GptConf_GptChannel_GptChannel_01_Notification        xTestGptChannel1Notification
    #define GptConf_GptChannel_GptChannel_01_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_01_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_01_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_01_ID )
#endif /* GptConf_GptChannel_GptChannel_01_ID */

#ifdef GptConf_GptChannel_GptChannel_02_ID  
    #define GptConf_GptChannel_GptChannel_02_TickFrequency       2000000U          
    #define GptConf_GptChannel_GptChannel_02_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_02_ChannelMode         GPT_CH_MODE_ONESHOT    
    #define GptConf_GptChannel_GptChannel_02_Notification        xTestGptChannel2Notification
    #define GptConf_GptChannel_GptChannel_02_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_02_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_02_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_02_ID )    
#endif /* GptConf_GptChannel_GptChannel_02_ID */

#ifdef GptConf_GptChannel_GptChannel_03_ID  
    #define GptConf_GptChannel_GptChannel_03_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_03_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_03_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_03_Notification        xTestGptChannel3Notification
    #define GptConf_GptChannel_GptChannel_03_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_03_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_03_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_03_ID )    
#endif /* GptConf_GptChannel_GptChannel_03_ID */

#ifdef GptConf_GptChannel_GptChannel_04_ID  
    #define GptConf_GptChannel_GptChannel_04_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_04_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_04_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_04_Notification        xTestGptChannel4Notification
    #define GptConf_GptChannel_GptChannel_04_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_04_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_04_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_04_ID )    
#endif /* GptConf_GptChannel_GptChannel_04_ID */

#ifdef GptConf_GptChannel_GptChannel_05_ID  
    #define GptConf_GptChannel_GptChannel_05_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_05_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_05_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_05_Notification        xTestGptChannel5Notification
    #define GptConf_GptChannel_GptChannel_05_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_05_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_05_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_05_ID )    
#endif /* GptConf_GptChannel_GptChannel_05_ID */

#ifdef GptConf_GptChannel_GptChannel_06_ID  
    #define GptConf_GptChannel_GptChannel_06_TickFrequency       1000000U          
    #define GptConf_GptChannel_GptChannel_06_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_06_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_06_Notification        xTestGptChannel6Notification
    #define GptConf_GptChannel_GptChannel_06_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_06_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_06_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_06_ID )    
#endif /* GptConf_GptChannel_GptChannel_06_ID */

#ifdef GptConf_GptChannel_GptChannel_07_ID  
    #define GptConf_GptChannel_GptChannel_07_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_07_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_07_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_07_Notification        xTestGptChannel7Notification
    #define GptConf_GptChannel_GptChannel_07_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_07_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_07_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_07_ID )    
#endif /* GptConf_GptChannel_GptChannel_07_ID */

#ifdef GptConf_GptChannel_GptChannel_08_ID  
    #define GptConf_GptChannel_GptChannel_08_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_08_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_08_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_08_Notification        xTestGptChannel8Notification
    #define GptConf_GptChannel_GptChannel_08_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_08_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_08_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_08_ID )    
#endif /* GptConf_GptChannel_GptChannel_08_ID */

#ifdef GptConf_GptChannel_GptChannel_09_ID  
    #define GptConf_GptChannel_GptChannel_09_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_09_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_09_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_09_Notification        xTestGptChannel9Notification
    #define GptConf_GptChannel_GptChannel_09_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_09_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_09_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_09_ID )     
#endif /* GptConf_GptChannel_GptChannel_09_ID */

#ifdef GptConf_GptChannel_GptChannel_10_ID  
    #define GptConf_GptChannel_GptChannel_10_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_10_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_10_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_10_Notification        xTestGptChannel10Notification
    #define GptConf_GptChannel_GptChannel_10_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_10_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_10_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_10_ID )      
#endif /* GptConf_GptChannel_GptChannel_10_ID */

#ifdef GptConf_GptChannel_GptChannel_11_ID  
    #define GptConf_GptChannel_GptChannel_11_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_11_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_11_ChannelMode         GPT_CH_MODE_ONESHOT
    #define GptConf_GptChannel_GptChannel_11_Notification        xTestGptChannel11Notification   
    #define GptConf_GptChannel_GptChannel_11_HWType              GPT_CHAN_HWTIMER_PL0_QTMR
    #define GptConf_GptChannel_GptChannel_11_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_11_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_11_ID )        
#endif /* GptConf_GptChannel_GptChannel_11_ID */

#ifdef GptConf_GptChannel_GptChannel_12_ID  
    #define GptConf_GptChannel_GptChannel_12_TickFrequency       1000000U          
    #define GptConf_GptChannel_GptChannel_12_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_12_ChannelMode         GPT_CH_MODE_ONESHOT
    #define GptConf_GptChannel_GptChannel_12_Notification        Gpt_Notification_Default
    #define GptConf_GptChannel_GptChannel_12_HWType              GPT_CHAN_HWTIMER_PL1_PHY
    #define GptConf_GptChannel_GptChannel_12_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_12_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_12_ID )  
#endif /* GptConf_GptChannel_GptChannel_12_ID */

#ifdef GptConf_GptChannel_GptChannel_13_ID  
    #define GptConf_GptChannel_GptChannel_13_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_13_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_13_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_13_Notification        Gpt_Notification_Default
    #define GptConf_GptChannel_GptChannel_13_HWType              GPT_CHAN_HWTIMER_PL1_VRT
    #define GptConf_GptChannel_GptChannel_13_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_13_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_13_ID )    
#endif /* GptConf_GptChannel_GptChannel_13_ID */

#ifdef GptConf_GptChannel_GptChannel_14_ID  
    #define GptConf_GptChannel_GptChannel_14_TickFrequency       19200000U          
    #define GptConf_GptChannel_GptChannel_14_TickValueMax        0xFFFFFFFFU    
    #define GptConf_GptChannel_GptChannel_14_ChannelMode         GPT_CH_MODE_ONESHOT           
    #define GptConf_GptChannel_GptChannel_14_Notification        Gpt_Notification_Default
    #define GptConf_GptChannel_GptChannel_14_HWType              GPT_CHAN_HWTIMER_PL2_PHY
    #define GptConf_GptChannel_GptChannel_14_WakeUpEnable        GPT_FALSE
    #define GptConf_GptChannel_GptChannel_14_WakeUpSrc           Gpt_GenChanWakeUpSrc( GptConf_GptChannel_GptChannel_14_ID )    
#endif /* GptConf_GptChannel_GptChannel_14_ID */

/*==============================================================================
**      Golbal typedefs : Enums, Structures Union and other typedefs          **
==============================================================================*/
#define Gpt_GenPrvChannel_ID( PubChannel ) ( ( PubChannel ) & 0x00FFU )

GPT_TIMER_CONST static const Gpt_ChannelConfigType Gpt_ChannelConfig[] =
{
    #ifdef GptConf_GptChannel_GptChannel_00_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_00_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_00_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_00_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_00_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_00_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_00_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_00_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_00_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_00_ID */
 
    #ifdef GptConf_GptChannel_GptChannel_01_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_01_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_01_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_01_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_01_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_01_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_01_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_01_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_01_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_01_ID */
 
    #ifdef GptConf_GptChannel_GptChannel_02_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_02_WakeUpSrc,
        #endif  
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_02_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_02_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_02_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_02_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_02_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_02_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_02_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_02_ID */
  
    #ifdef GptConf_GptChannel_GptChannel_03_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_03_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_03_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_03_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_03_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_03_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_03_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_03_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_03_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_03_ID */
   
    #ifdef GptConf_GptChannel_GptChannel_04_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_04_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_04_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_04_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_04_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_04_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_04_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_04_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_04_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_04_ID */
 
    #ifdef GptConf_GptChannel_GptChannel_05_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_05_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_05_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_05_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_05_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_05_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_05_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_05_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_05_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_05_ID */
  
    #ifdef GptConf_GptChannel_GptChannel_06_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_06_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_06_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_06_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_06_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_06_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_06_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_06_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_06_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_06_ID */
    
    #ifdef GptConf_GptChannel_GptChannel_07_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_07_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_07_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_07_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_07_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_07_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_07_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_07_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_07_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_07_ID */
    
    #ifdef GptConf_GptChannel_GptChannel_08_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_08_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_08_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_08_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_08_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_08_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_08_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_08_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_08_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_08_ID */
     
    #ifdef GptConf_GptChannel_GptChannel_09_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_09_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_09_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_09_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_09_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_09_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_09_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_09_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_09_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_09_ID */
      
    #ifdef GptConf_GptChannel_GptChannel_10_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_10_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_10_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_10_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_10_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_10_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_10_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_10_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_10_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_10_ID */
  
    #ifdef GptConf_GptChannel_GptChannel_11_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_11_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_11_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_11_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_11_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_11_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_11_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_11_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_11_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_11_ID */
 
    #ifdef GptConf_GptChannel_GptChannel_12_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_12_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_12_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_12_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_12_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_12_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_12_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_12_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_12_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_12_ID */
 
    #ifdef GptConf_GptChannel_GptChannel_13_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_13_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_13_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_13_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_13_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_13_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_13_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_13_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_13_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_13_ID */
 
    #ifdef GptConf_GptChannel_GptChannel_14_ID  
    {
        #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .GptChannelWakeupInfo = GptConf_GptChannel_GptChannel_14_WakeUpSrc,
        #endif
        #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .GptEnableWakeup = GptConf_GptChannel_GptChannel_14_WakeUpEnable,
        #endif
        #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .GptNotification     			   = GptConf_GptChannel_GptChannel_14_Notification,      
        #endif
        .GptChanHW                         = GptConf_GptChannel_GptChannel_14_HWType,
        .GptChannelID 					   = (Gpt_ChannelType) Gpt_GenPrvChannel_ID( GptConf_GptChannel_GptChannel_14_ID ),
        .GptChannelMode 				   = GptConf_GptChannel_GptChannel_14_ChannelMode,
        .GptChannelTickFrequency           = GptConf_GptChannel_GptChannel_14_TickFrequency,
        .GptChannelTickValueMax            = GptConf_GptChannel_GptChannel_14_TickValueMax,  
    },
    #endif /* GptConf_GptChannel_GptChannel_14_ID */
};
/*==============================================================================
**      Golbal typedefs : Enums, Structures Union and other typedefs          **
==============================================================================*/
GPT_TIMER_CONST static const Gpt_ModuleConfigType Gpt_ModuleConfig =
{
    #ifdef GPT_PREDEF_TIMER_1US_ENABLING_GRADE
        .GptPredefTimer1usEnablingGrade = GPT_PREDEF_TIMER_1US_ENABLING_GRADE,
    #else
        .GptPredefTimer1usEnablingGrade = GPT_PREDEF_TIMER_1US_DISABLED, /* default */
    #endif /* GPT_PREDEF_TIMER_1US_XXBIT_ENABLE */
    #ifdef GPT_PREDEF_TIMER_100US_32BIT_ENABLE
        .GptPredefTimer100us32bitEnable = GPT_PREDEF_TIMER_100US_32BIT_ENABLE,
    #endif /* GPT_PREDEF_TIMER_100US_32BIT_ENABLE */
    #ifdef GPT_PREDEF_TIMER_2US_32BIT_ENABLE
        .GptPredefTimer2us32bitEnable = GPT_PREDEF_TIMER_2US_32BIT_ENABLE,
    #endif /* GPT_PREDEF_TIMER_2US_32BIT_ENABLE */
    #ifdef GPT_PREDEF_TIMER_HWTYPE
        .GptPredefTimerHWType = GPT_PREDEF_TIMER_HWTYPE,
    #else /* GPT_PREDEF_TIMER_HWTYPE */
        .GptPredefTimerHWType = GPT_CHAN_HWTIMER_PL0_QTMR,
    #endif
 	.GptDrvChannelMaxConfig = (Gpt_ChannelType)GptChannel_MAX_ID /* Number of Channel configured.  */
};
/*==============================================================================
**      Golbal typedefs : Enums, Structures Union and other typedefs          **
==============================================================================*/
GPT_TIMER_CONST const Gpt_ConfigType Gpt_Config =
{
    &Gpt_ChannelConfig[0U],
    &Gpt_ModuleConfig,
};
/*==============================================================================
**                    End of file Gpt_PBCfg.c                                 **
==============================================================================*/
