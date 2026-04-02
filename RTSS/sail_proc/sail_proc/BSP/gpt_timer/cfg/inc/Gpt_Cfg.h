/*
  ==============================================================================
*/
/*==============================================================================
  File Name          : Gpt_Cfg.h
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
#ifndef GPT_CFG_H__
#define GPT_CFG_H__
/*==============================================================================
**                              Include files                                 **
==============================================================================*/

/*@Requirements : [SRS_BSW_00318]
 *@brief : Each AUTOSAR Basic Software Module file shall provide version numbers in the header file */
 /* AUTOSAR specification version numbers for GPT module*/
#define GPT_AR_RELEASE_MAJOR_VERSION                   24U
#define GPT_AR_RELEASE_MINOR_VERSION                   11U
#define GPT_AR_RELEASE_REVISION_VERSION                0U
/* Vendor specific implementation version information for GPT module  */
#define GPT_SW_MAJOR_VERSION                           1U
#define GPT_SW_MINOR_VERSION                           0U
#define GPT_SW_PATCH_VERSION                           0U

/*==============================================================================
**                         GptDriverConfiguration                             **
==============================================================================*/

/*
* @brief : Switches the development error detection and notification on or off.
* @implements :   
*                 STD_ON: detection and notification is enabled.(true)
*                 STD_OFF: detection and notification is disabled.(false)
* @Requirements : [ECUC_Gpt_00321]
*/
#define GPT_DEV_ERROR_DETECT                     (STD_ON)

/*
* @brief : Enables/disables the GPT Predef Timer 100?s32bit.
* @implements : 
*               STD_ON: Function is enabled.
*               STD_OFF: Function is disabled.   
* @Requirements : [ECUC_Gpt_00335]
*/
#define GPT_PREDEF_TIMER_100US_32BIT_ENABLE      (STD_ON)

/*
* @brief : Enables/disables the GPT Predef Timer 100?s32bit.
* @implements : 
*               STD_ON: Function is enabled.
*               STD_OFF: Function is disabled.   
* @Requirements : [ECUC_Gpt_00335]
*/
#define GPT_PREDEF_TIMER_2US_32BIT_ENABLE       ( STD_ON )

/*
* @brief : Specifies the grade of enabling the GPT Predef Timers with 1MicroSecond tick duration.
* @implements : 
*         GPT_PREDEF_TIMER_1US_16BIT_ENABLED :16bit timer enabled
*         GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED :16 and 24bit timers enabled.
*         GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED : 16, 24 and 32bit timers enabled
*         GPT_PREDEF_TIMER_1US_DISABLED disabled
* @Requirements : [ECUC_Gpt_00334]
*/

#define GPT_PREDEF_TIMER_1US_ENABLING_GRADE    (GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED)

/*
* @brief : Specifies the Base HW channel Type Allocated to GPT Predef Timers
* @implements : 
*         GPT_CHAN_HWTIMER_PL1_VRT : predef timer el1 base virtual ticker
*         GPT_CHAN_HWTIMER_PL1_PHY : predef timer el1 base physical ticker
*         GPT_CHAN_HWTIMER_PL0_QTMR : deafult predef timer el0/el1/el2 base phy ticker
* @Requirements : [ECUC_Gpt_00334]
*/

#define GPT_PREDEF_TIMER_HWTYPE         ( GPT_CHAN_HWTIMER_PL0_QTMR )


/*
* @brief : Enables/Disables wakeup source reporting.
* @implements :
*             STD_ON: detection and notification is enabled.(true)
*             STD_OFF: detection and notification is disabled.(false)
* @Requirements : [ECUC_Gpt_00322]
*/

#define GPT_REPORT_WAKEUP_SOURCE               (STD_ON)

/*
* @brief : Maps the GPT driver to zero or multiple ECUC partitions to make the driver
*          API available in the according partition. Depending on the addressed timer
           resource the interfaces operate as follows:
           a) In case of partition local timer resources (n:1 mapping) the API operates as
           an independent instance in the according ECUC partition.
           b) In case of global timer resources (1:m mapping) the API operates on the
           global timer resource either by protected access to the resource or by
           implementing an according kernel.
* @implements : Reference to EcucPartition
*
* @Requirements : [ECUC_Gpt_00337]
*/

 #define GPT_ECUC_PARTITION_REF        (STD_ON)

/*
* @brief : Maps the GPT kernel to zero or one ECUC partitions to assign the driver
           kernel to a certain core. The ECUC partition referenced is a subset of the
           ECUC partitions where the GPT driver is mapped to.
           Note: The kernel reference shall not be set in case the GPT driver is
           implemented without a kernel (refer to definition of GptEcucPartitionRef).
* @implements :  Reference to EcucPartition
* @Requirements : [ECUC_Gpt_00338]
*/

 #define GPT_KERNEL_ECUC_PARTITION_REF   (STD_ON)

/*
* @brief : Reference to a container of the type McuClockReferencePoint, to select an input clock.
           The configuration editor for the GPT module can support the integrator by only 
           allowing a selection of those clock reference points that can be connected 
           physically to the GPT hardware peripheral. The desired frequency (desired by 
           GPT) has to be the same as the selected and provided frequency of the MCU 
           configuration. This has to be checked automatically.
* @implements : Reference to McuClockReferencePoint
* @Requirements : [ECUC_Gpt_00330]
*/

 #define GPT_CLOCK_REF_POINT            (STD_ON)
 
/*==============================================================================
**                         GptConfigurationOfOptApiServices                   **
==============================================================================*/
/*
* @brief : Adds / removes the service Gpt_DeInit() from the code
* @implements :
*                 STD_ON: detection and notification is enabled.(true)
*                 STD_OFF: detection and notification is disabled.(false)
* @Requirements : [ECUC_Gpt_00314]
*/
#define GPT_DEINIT_API                                  (STD_ON)

/*
* @brief : Adds / removes the services Gpt_EnableNotification() and Gpt_Disable
*          Notification from the code.
* @implements :
*                 STD_ON: detection and notification is enabled.(true)
*                 STD_OFF: detection and notification is disabled.(false)
* @Requirements : [ECUC_Gpt_00315]
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API             (STD_ON)

/*
* @brief : Adds / removes the service Gpt_GetTimeElapsed() from the code.
* @implements :
*                 STD_ON: detection and notification is enabled.(true)
*                 STD_OFF: detection and notification is disabled.(false)
* @Requirements : [ECUC_Gpt_00317]
*/
#define GPT_TIME_ELAPSED_API                             (STD_ON)

/*
* @brief : Adds / removes the service Gpt_GetTimeRemaining() from the code.
* @implements :
*                 STD_ON: detection and notification is enabled.(true)
*                 STD_OFF: detection and notification is disabled.(false)
* @Requirements : [ECUC_Gpt_00318]
*/
#define GPT_TIME_REMAINING_API                            (STD_ON)

/*
* @brief : Adds / removes the service Gpt_GetVersionInfo() from the code.
* @implements :
*                 STD_ON: detection and notification is enabled.(true)
*                 STD_OFF: detection and notification is disabled.(false)
* @Requirements : [ECUC_Gpt_00319]
*/
#define GPT_VERSION_INFO_API                                 (STD_ON)

/*
* @brief : Adds / removes the services Gpt_SetMode(), Gpt_EnableWakeup() Gpt_
*             DisableWakeup() and Gpt_CheckWakeup() from the code.
* @implements :
*                 STD_ON: detection and notification is enabled.(true)
*                 STD_OFF: detection and notification is disabled.(false)
* @Requirements : [ECUC_Gpt_00320]
*/
#define GPT_WAKEUP_FUNCTIONALITY_API                        (STD_ON)


/*
* @brief : The Gpt Driver modules implementer shall publish the symbolic names through the file Gpt.h
           The user of the Gpt Driver module shall configure the symbolic names of the Gpt channel of the MCU.
           Channel Id of the GPT channel. This value will be assigned to the symbolic
           name derived of the GptChannelConfiguration container short name.
* @implements : [ECUC_Gpt_00308 ]<index number(8bits)><Channel number(8bits)>
*/

/*==============================================================================
**                         GptConfigurationOfChannel                          **
==============================================================================*/
/*******************************************************************************
  User Defined Symbolic names of all port pins Port_ConfigSet
  @[TPS_ECUC_02108] Rule for the creation of #define symbols in the header
  file for parameters with the symbolicNameValue set to TRUE 
*******************************************************************************/
/*******************************************************************************
    ECUC_Gpt_00308 / GptChannelId : Channel Id of the GPT channel. This value
    will be assigned to the symbolic name derived of the GptChannelConfiguration
    container short name.
    GptConf_GptChannel_< Short Name of GptChannelId > 
*******************************************************************************/
/* manual cfg for BSP MCAL GPT Timer RTD */
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

//Do not Enable this channel 
/*#define GptConf_GptChannel_GptChannel_12_Used*/ /* arm phy 1*/ 
/* #define GptConf_GptChannel_GptChannel_13_Used */ /* arm vrt 1 */
/* #define GptConf_GptChannel_GptChannel_14_Used */ /* arm phy 2 */

/* supported channel list */
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

#define GptConf_GptChannel_GptChannel_MAX_ID GptChannel_MAX_ID
/*==============================================================================
**                                                                            **
==============================================================================*/
#endif /* GPT_CFG_H */
/*==============================================================================
**                    End of file Gpt_Cfg.h                                   **
==============================================================================*/
