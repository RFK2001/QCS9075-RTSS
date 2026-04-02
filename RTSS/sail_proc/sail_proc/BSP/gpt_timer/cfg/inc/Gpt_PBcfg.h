/*
  ==============================================================================
*/
/*==============================================================================
  File Name          : Gpt_PBcfg.h
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
#ifndef GPT_PBCFG_H__
#define GPT_PBCFG_H__

/*==============================================================================
**                          Include files                                     **
==============================================================================*/

#include "Gpt_Cfg.h"

/*==============================================================================
**                             defines and macros                             **
==============================================================================*/


/*==============================================================================
**       Global typedefs : Enums, Structures Union and other typedefs         **
==============================================================================*/

/* Extern declaration of Gpt Config Set */
GPT_TIMER_CONST extern const Gpt_ConfigType Gpt_Config;

/*==============================================================================
**          GptConfigurationOfChannel   Notifications                         **
==============================================================================*/
/*
* @brief : GPT Notification.
* @implements :  The notification prototype Gpt_Notification_<channel> is for the notification 
                  callback function and shall be implemented by the user
                  Gpt_Notification_<channel>
* @Requirements : [SWS_Gpt_00292]
*/

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
GPT_TIMER_FUNC void Gpt_Notification_Default (void);
#endif

/*
* @brief : GPT Runtime Error Notfication to application callout configuration.
* @implements :  prvides interface to configure application action on GPT 
                    module error action, shall be implemented by the user
* @Requirements : for BSP GPT Module Error handling
*/

extern Std_ReturnType Det_ReportRuntimeError( 
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId );  

#define Det_ReportRuntimeError( mid, giid, sid, err )   E_NOT_OK

/*
* @brief : GPT Dev Error API stub for application callout configuration.
* @implements :  prvides interface to configure application action on GPT 
                    module dev error action, shall be implemented by the user
* @Requirements : for BSP GPT Module Dev Error handling
*/
#if (GPT_DEV_ERROR_DETECT == STD_ON)
Std_ReturnType Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
#define Det_ReportError( mid, giid, sid, err )  E_NOT_OK
#endif

/*
* @brief : GPT RTD callout configuration for BSP.
* @implements :  prvides interface to configure application action on GPT 
                   wakeup action, shall be implemented by the user
* @Requirements : for BSP GPT Module wakeup handling
*/
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/* default */
#define EcuM_SetWakeupEvent( WakeupSource )       
#define EcuM_CheckWakeup( WakeupSource )  
#endif
#endif
/*==============================================================================
**                                                                            **
==============================================================================*/
#endif /* GPT_CFG_H */
/*==============================================================================
**                    End of file Gpr_PBcfG.h                                 **
==============================================================================*/
