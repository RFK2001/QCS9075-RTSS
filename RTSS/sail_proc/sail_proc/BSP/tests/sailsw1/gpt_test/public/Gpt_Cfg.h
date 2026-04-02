/**************************************************************************************************
    Copyright (c) 2022 Qualcomm Technologies, Inc.
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
**************************************************************************************************/

/*=================================================================================================
    File Name          : Gpt_Cfg.h
    Component Name     : MCalCfg
    Description        : Public Header file for gpt config
    $Header:
    $DateTime:
    $Author:
=================================================================================================*/
#ifndef GPT_CFG_H
#define GPT_CFG_H
/*==============================================================================
**                      Include Section                                       **
==============================================================================*/

/*==============================================================================
**                      Global Macro                                          **
==============================================================================*/

#define GPT_DEV_ERROR_DETECT                              (STD_ON)
#define GPT_REPORT_WAKEUP_SOURCE                          (STD_OFF)

#define GPT_PREDEF_TIMER_1US_16BIT_EN                     (STD_ON)
#define GPT_PREDEF_TIMER_1US_24BIT_EN                     (STD_ON)
#define GPT_PREDEF_TIMER_1US_32BIT_EN                     (STD_ON)
#define GPT_PREDEF_TIMER_2US_32BIT_EN                     (STD_ON)
#define GPT_PREDEF_TIMER_100US_32BIT_EN                   (STD_ON)

#define GPT_VERSION_INFO_API                              (STD_ON)
#define GPT_DEINIT_API                              	  (STD_ON)
#define GPT_ENABLE_DISABLE_NOTIFICATION_API               (STD_ON)
#define GPT_TIME_ELAPSED_API                              (STD_ON)
#define GPT_TIME_REMAINING_API                            (STD_ON)
#define GPT_WAKEUP_FUNCTIONALITY_API                      (STD_OFF)

#define GPT_ONESHOT_USED                                  (STD_ON)

/* Number of channels */
#define GPT_MAX_CHANNELS	12U		
#define SAIL_USSTEST_ENABLED
/*==============================================================================
**                      Gpt Channels                                          **
==============================================================================*/
extern void xTestGptChannel0Notification( void);
extern void xTestGptChannel1Notification( void);
extern void xTestGptChannel2Notification( void);
extern void xTestGptChannel3Notification( void);
extern void xTestGptChannel4Notification( void);
extern void xTestGptChannel5Notification( void);
extern void xTestGptChannel6Notification( void);
extern void xTestGptChannel7Notification( void);
extern void xTestGptChannel8Notification( void);
extern void xTestGptChannel9Notification( void);
extern void xTestGptChannel10Notification( void);
extern void xTestGptChannel11Notification( void);


#define GptConf_GptChannel_GptChannel_00_Used
#define GptConf_GptChannel_GptChannel_01_Used
#define GptConf_GptChannel_GptChannel_02_Used
#define GptConf_GptChannel_GptChannel_03_Used
#define GptConf_GptChannel_GptChannel_04_Used
#define GptConf_GptChannel_GptChannel_05_Used
#define GptConf_GptChannel_GptChannel_06_Used
#define GptConf_GptChannel_GptChannel_07_Used
#define GptConf_GptChannel_GptChannel_08_Used
#define GptConf_GptChannel_GptChannel_09_Used
#define GptConf_GptChannel_GptChannel_10_Used
#define GptConf_GptChannel_GptChannel_11_Used


enum gpt_timer_chan_e
{
    #ifdef GptConf_GptChannel_GptChannel_00_Used 
        GptChannel_00_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_01_Used  
        GptChannel_01_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_02_Used  
        GptChannel_02_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_03_Used  
        GptChannel_03_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_04_Used  
        GptChannel_04_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_05_Used  
        GptChannel_05_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_06_Used  
        GptChannel_06_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_07_Used  
        GptChannel_07_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_08_Used  
        GptChannel_08_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_09_Used  
        GptChannel_09_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_10_Used  
        GptChannel_10_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_11_Used  
        GptChannel_11_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_12_Used  
        GptChannel_12_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_13_Used  
        GptChannel_13_ID,
    #endif
    #ifdef GptConf_GptChannel_GptChannel_14_Used  
        GptChannel_14_ID,
    #endif
    GptChannel_MAX_ID,
};
#define Gpt_GenPubChannel_ID( cfg , chan ) ( ( ( ( (uint32)(cfg) ) << 0x8U ) & 0xFF00U ) | ( ( chan ) & 0xFFU ) )
#ifdef GptConf_GptChannel_GptChannel_00_Used
    #define GptConf_GptChannel_GptChannel_00_ID Gpt_GenPubChannel_ID( GptChannel_00_ID, 0x00U )
#endif

#ifdef GptConf_GptChannel_GptChannel_01_Used
    #define GptConf_GptChannel_GptChannel_01_ID Gpt_GenPubChannel_ID( GptChannel_01_ID, 0x01U )
#endif

#ifdef GptConf_GptChannel_GptChannel_02_Used
    #define GptConf_GptChannel_GptChannel_02_ID Gpt_GenPubChannel_ID( GptChannel_02_ID, 0x02U )
#endif

#ifdef GptConf_GptChannel_GptChannel_03_Used
    #define GptConf_GptChannel_GptChannel_03_ID Gpt_GenPubChannel_ID( GptChannel_03_ID, 0x03U )
#endif

#ifdef GptConf_GptChannel_GptChannel_04_Used
    #define GptConf_GptChannel_GptChannel_04_ID Gpt_GenPubChannel_ID( GptChannel_04_ID, 0x04U )
#endif

#ifdef GptConf_GptChannel_GptChannel_05_Used
    #define GptConf_GptChannel_GptChannel_05_ID Gpt_GenPubChannel_ID( GptChannel_05_ID, 0x05U )
#endif

#ifdef GptConf_GptChannel_GptChannel_06_Used
    #define GptConf_GptChannel_GptChannel_06_ID Gpt_GenPubChannel_ID( GptChannel_06_ID, 0x06U )
#endif

#ifdef GptConf_GptChannel_GptChannel_07_Used
    #define GptConf_GptChannel_GptChannel_07_ID Gpt_GenPubChannel_ID( GptChannel_07_ID, 0x07U )
#endif

#ifdef GptConf_GptChannel_GptChannel_08_Used
    #define GptConf_GptChannel_GptChannel_08_ID Gpt_GenPubChannel_ID( GptChannel_08_ID, 0x08U )
#endif

#ifdef GptConf_GptChannel_GptChannel_09_Used
    #define GptConf_GptChannel_GptChannel_09_ID Gpt_GenPubChannel_ID( GptChannel_09_ID, 0x09U )
#endif

#ifdef GptConf_GptChannel_GptChannel_10_Used
    #define GptConf_GptChannel_GptChannel_10_ID Gpt_GenPubChannel_ID( GptChannel_10_ID, 0x0AU )
#endif

#ifdef GptConf_GptChannel_GptChannel_11_Used
    #define GptConf_GptChannel_GptChannel_11_ID Gpt_GenPubChannel_ID( GptChannel_11_ID, 0x0BU )
#endif

#ifdef GptConf_GptChannel_GptChannel_12_Used
    #define GptConf_GptChannel_GptChannel_12_ID Gpt_GenPubChannel_ID( GptChannel_12_ID, 0x0CU )
#endif

#ifdef GptConf_GptChannel_GptChannel_13_Used
    #define GptConf_GptChannel_GptChannel_13_ID Gpt_GenPubChannel_ID( GptChannel_13_ID, 0x0DU )
#endif

#ifdef GptConf_GptChannel_GptChannel_14_Used
    #define GptConf_GptChannel_GptChannel_14_ID Gpt_GenPubChannel_ID( GptChannel_14_ID, 0x0EU )
#endif


#ifndef GptConf_GptChannel_GptChannel_0
#define GptConf_GptChannel_GptChannel_0 ((Gpt_ChannelType)0U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_0_Notification STMR_EventCh0_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_0_Notification xTestGptChannel0Notification
#else
#define GptConf_GptChannel_GptChannel_1_Notification NULL
#endif	
#endif

#ifndef GptConf_GptChannel_GptChannel_1
#define GptConf_GptChannel_GptChannel_1 ((Gpt_ChannelType)1U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_1_Notification STMR_EventCh1_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_1_Notification xTestGptChannel1Notification
#else
#define GptConf_GptChannel_GptChannel_1_Notification NULL
#endif	
#endif

#ifndef GptConf_GptChannel_GptChannel_2
#define GptConf_GptChannel_GptChannel_2 ((Gpt_ChannelType)2U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_2_Notification STMR_EventCh2_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_2_Notification xTestGptChannel2Notification
#else
#define GptConf_GptChannel_GptChannel_2_Notification NULL
#endif	
#endif

#ifndef GptConf_GptChannel_GptChannel_3
#define GptConf_GptChannel_GptChannel_3 ((Gpt_ChannelType)3U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_3_Notification STMR_EventCh3_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_3_Notification xTestGptChannel3Notification
#else
#define GptConf_GptChannel_GptChannel_3_Notification NULL
#endif
#endif

#ifndef GptConf_GptChannel_GptChannel_4
#define GptConf_GptChannel_GptChannel_4 ((Gpt_ChannelType)4U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_4_Notification STMR_EventCh4_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_4_Notification xTestGptChannel4Notification
#else
#define GptConf_GptChannel_GptChannel_4_Notification NULL
#endif	
#endif

#ifndef GptConf_GptChannel_GptChannel_5
#define GptConf_GptChannel_GptChannel_5 ((Gpt_ChannelType)5U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_5_Notification STMR_EventCh5_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_5_Notification xTestGptChannel5Notification
#else
#define GptConf_GptChannel_GptChannel_5_Notification NULL
#endif	
#endif

#ifndef GptConf_GptChannel_GptChannel_6
#define GptConf_GptChannel_GptChannel_6 ((Gpt_ChannelType)6U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_6_Notification STMR_EventCh6_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_6_Notification xTestGptChannel6Notification
#else
#define GptConf_GptChannel_GptChannel_6_Notification NULL
#endif	
#endif

#ifndef GptConf_GptChannel_GptChannel_7
#define GptConf_GptChannel_GptChannel_7 ((Gpt_ChannelType)7U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_7_Notification STMR_EventCh7_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_7_Notification xTestGptChannel7Notification
#else
#define GptConf_GptChannel_GptChannel_7_Notification NULL
#endif
#endif

#ifndef GptConf_GptChannel_GptChannel_8
#define GptConf_GptChannel_GptChannel_8 ((Gpt_ChannelType)8U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_8_Notification STMR_EventCh8_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_8_Notification xTestGptChannel8Notification
#else
#define GptConf_GptChannel_GptChannel_8_Notification NULL
#endif	
#endif

#ifndef GptConf_GptChannel_GptChannel_9
#define GptConf_GptChannel_GptChannel_9 ((Gpt_ChannelType)9U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_9_Notification STMR_EventCh9_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_9_Notification xTestGptChannel9Notification
#else
#define GptConf_GptChannel_GptChannel_9_Notification NULL
#endif
#endif

#ifndef GptConf_GptChannel_GptChannel_10
#define GptConf_GptChannel_GptChannel_10 ((Gpt_ChannelType)10U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_10_Notification STMR_EventCh10_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_10_Notification xTestGptChannel10Notification
#else
#define GptConf_GptChannel_GptChannel_10_Notification NULL
#endif	
#endif

#ifndef GptConf_GptChannel_GptChannel_11
#define GptConf_GptChannel_GptChannel_11 ((Gpt_ChannelType)11U)
#ifdef USSAPP_ENABLED
#define GptConf_GptChannel_GptChannel_11_Notification STMR_EventCh11_ISR
#elif defined SAIL_USSTEST_ENABLED
#define GptConf_GptChannel_GptChannel_11_Notification xTestGptChannel11Notification
#else
#define GptConf_GptChannel_GptChannel_11_Notification NULL
#endif
#endif


#endif /* GPT_CFG_H */
/*==============================================================================
**                      			END	                               		  **
==============================================================================*/