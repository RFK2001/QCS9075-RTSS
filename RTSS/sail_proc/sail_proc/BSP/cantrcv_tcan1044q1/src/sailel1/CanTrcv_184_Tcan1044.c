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

/*=============================================================================
    File Name.............. : CanTrcv_184_Tcan1044.c
    Description............ : This file contains functionality of CAN
                              Transceiver TCAN1044 driver
    Autosar Release Version : R22-11
    Platform............... :
    SW Release Version..... :

=============================================================================*/

/*=============================================================================
|                       MISRA-C VIOLATIONS                                    |
=============================================================================*/
/*

*/

/*=============================================================================
|                       REVISION HISTORY                                      |
===============================================================================
| Revision  Date            Changed By        Description                     |
===============================================================================

=============================================================================*/

/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/
#include "CanTrcv_184_Tcan1044.h"       /* CAN Transceiver TCAN1044 Driver header file*/
#include "CanTrcv_184_Tcan1044_Drv.h"   /* CAN Transceiver TCAN1044 Internal header file */
#include "SchM_CanTrcv_184_Tcan1044.h"  /* Scheduler Manager header file */
#include "CanTrcv_184_Tcan1044_Plt_Cfg.h"
#ifndef CAN_PLT_SAFERTOS_ENABLE
#include "CanIf.h"

#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                        /* DET module header file */
#endif
#if(CANTRCV_184_TCAN1044_1US16BIT_TIMER_SUPPORT == STD_ON)
#include "Tm.h"                         /* Time Service module header file */
#endif
#else
#include "debug_log.h"
#include "gpio.h"
#include "FreeRTOSOsal.h"
#include "freertos_init.h"
#include "CanTrcv_184_Tcan1044_If.h"
#include "CanTrcv_184_Tcan1044_SafeRTOS.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

/*=============================================================================
|                       VERSION INFORMATION                                   |
=============================================================================*/
/* AUTOSAR Specification Version Information */
#define CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION_C      4
#define CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION_C      8
#define CANTRCV_184_TCAN1044_AR_RELEASE_REVISION_VERSION_C   0

/* Software Version Information */
#define CANTRCV_184_TCAN1044_SW_MAJOR_VERSION_C   1
#define CANTRCV_184_TCAN1044_SW_MINOR_VERSION_C   2
#define CANTRCV_184_TCAN1044_SW_PATCH_VERSION_C   0

/*=============================================================================
|                       VERSION CHECK                                         |
=============================================================================*/
/* AUTOSAR version information check has to match definition in header file */
#if ((CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION != CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION_C) ||\
     (CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION != CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION_C) ||\
     (CANTRCV_184_TCAN1044_AR_RELEASE_REVISION_VERSION != CANTRCV_184_TCAN1044_AR_RELEASE_REVISION_VERSION_C))
//#error "Autosar version numbers of CanTrcv_184_Tcan1044.h and CanTrcv_184_Tcan1044.c are different."
#endif

#ifndef CAN_PLT_SAFERTOS_ENABLE
/* [SWS_BSW_00036] Inter module version check. */
#if ((CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
//#error "Autosar version numbers of CanTrcv_184_Tcan1044.h and CanIf.h are different."
#endif

#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
#if ((CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
//#error "Autosar version numbers of CanTrcv_184_Tcan1044.h and Det.h are different."
#endif
#endif
#endif

/* SW version check of *.h/c of the own module */
#if ((CANTRCV_184_TCAN1044_SW_MAJOR_VERSION != CANTRCV_184_TCAN1044_SW_MAJOR_VERSION_C) ||\
     (CANTRCV_184_TCAN1044_SW_MINOR_VERSION != CANTRCV_184_TCAN1044_SW_MINOR_VERSION_C) ||\
     (CANTRCV_184_TCAN1044_SW_PATCH_VERSION != CANTRCV_184_TCAN1044_SW_PATCH_VERSION_C))
//#error "Vendor specific version numbers of CanTrcv_184_Tcan1044.c and CanTrcv_184_Tcan1044.h are inconsistent"
#endif

/*=============================================================================
|                       GLOBAL VARIABLES                                      |
=============================================================================*/
#define CANTRCV_184_TCAN1044_MAX_BAUDRATE       8000000u

#define CANTRCV_184_TCAN1044_START_SEC_CONST_NO_INIT_UNSPECIFIED
#include "CanTrcv_184_Tcan1044_MemMap.h"
static const CanTrcv_Tcan1044ConfigType *CanTrcv_184_Tcan1044_ConfigPtr;
#define CANTRCV_184_TCAN1044_STOP_SEC_CONST_NO_INIT_UNSPECIFIED
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_VAR_INIT_8
#include "CanTrcv_184_Tcan1044_MemMap.h"
/* Global variable to store Initialization status of CAN Transceiver Driver */
static uint8 CanTrcv_184_Tcan1044_DrvState = CANTRCV_184_TCAN1044_STATE_NOT_ACTIVE;
#define CANTRCV_184_TCAN1044_STOP_SEC_VAR_INIT_8
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTrcv_184_Tcan1044_MemMap.h"
/* Global variable to store Initialization status of CAN Transceiver Channel */
static CanTrcv_Tcan1044ChStateType CanTrcv_184_Tcan1044_ChState[CANTRCV_184_TCAN1044_NUM_OF_CHANNELS];
#define CANTRCV_184_TCAN1044_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTrcv_184_Tcan1044_MemMap.h"

/*=============================================================================
|                       FUNCTION DEFINITIONS                                  |
=============================================================================*/

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
 *
Service Name...... : CanTrcv_184_Tcan1044_Init
Service ID (hex).. : 0x00
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant
Parameters (IN)... : ConfigPtr
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : Initializes the CanTrcv module.
Design IDs Covered :
******************************************************************************/
void CanTrcv_184_Tcan1044_Init(const CanTrcv_Tcan1044ConfigType *ConfigPtr)
{
    Std_ReturnType status = E_OK;
    const CanTrcv_Tcan1044ChConfigType *channelConfigPtr;
    CanTrcv_Tcan1044ChStateType *channelStatePtr;
    /* declare and set the channel value to zero */
    uint8 channel = 0;
#ifndef CAN_PLT_SAFERTOS_ENABLE 
#if(CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
    Dio_LevelType dioValue;
#endif
#endif /*END of CAN_PLT_SAFERTOS_ENABLE*/

#if (CANTRCV_184_TCAN1044_CFG_POST_BUILD == STD_ON)
    if (NULL_PTR == ConfigPtr)
    {
#if (CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_INIT_SID, CANTRCV_184_TCAN1044_E_INIT_FAILED);
#endif
    }
    else
    {
        CanTrcv_184_Tcan1044_ConfigPtr = ConfigPtr;
#else
        CanTrcv_184_Tcan1044_ConfigPtr = &CanTrcv_184_Tcan1044_Config;
#endif
        CanTcrv1044_Plt_Cfg_Init();
        do
        {
            /* Get the pointer to the structure of the channel */
            channelConfigPtr = &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[channel];
            /* Check if channel is used or not*/
            if ((TRUE == channelConfigPtr->ChannelUsed) &&
                (CANTRCV_184_TCAN1044_MAX_BAUDRATE < channelConfigPtr->MaxBaudrate))
            {
                /* Report to DET */
#if (CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError (CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                        CANTRCV_184_TCAN1044_INIT_SID, CANTRCV_184_TCAN1044_E_BAUDRATE_NOT_SUPPORTED);
#endif
                status = E_NOT_OK;
                break;
            }
#ifdef CAN_PLT_SAFERTOS_ENABLE
             CanTrcv_184_Tcan1044_Config_Standby_Gpio(channel);
#endif /*END of CAN_PLT_SAFERTOS_ENABLE*/

            /* Set the Operational Mode to Standby or Sleep according to
             * InitState configuration. Since the transceiver support only
             * Standby, setting it here.
             */
            Tcan1044DrvSetStandbyMode(channelConfigPtr);

            /* Get the pointer to the structure of the first network */
            channelStatePtr = &CanTrcv_184_Tcan1044_ChState[channel];

            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
            /* Set the Operational Mode of the requested network */
            channelStatePtr->OperMode = channelConfigPtr->InitState;
#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
            /* Storing wakeup reason of the CAN Transceiver */
            channelStatePtr->WakeupReason = CANTRCV_184_TCAN1044_WU_NOT_FOUND;
            /* Enabling BusWakeUp Notification */
            channelStatePtr->WakeupNotiforEvent = CANTRCV_WUMODE_ENABLE;
            /* Clearing WakeupPending state */
            channelStatePtr->WakeupPending = FALSE;
#endif
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();

#ifdef CAN_PLT_SAFERTOS_ENABLE
            CanTrcv_184_Tcan1044_Register_WakeUp_IRQ(channel);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

            /* Increment the channel number */
            channel++;
        } while (channel < CANTRCV_184_TCAN1044_NUM_OF_CHANNELS);

        /* If module initializd successfully, set the global variable for init
         * status to initialized */
        if(E_OK == status)
        {
            /* Set the Driver State as Active */
            CanTrcv_184_Tcan1044_DrvState = CANTRCV_184_TCAN1044_STATE_ACTIVE;

/* No ICU & ECU in SafeRTOS */ 
#ifndef CAN_PLT_SAFERTOS_ENABLE 
#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
            channel = 0;
            do
            {
                /* Get the pointer to the structure of the channel */
                channelConfigPtr= &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[channel];
                
                /* Check if channel is used or not*/
                if(TRUE == channelConfigPtr->ChannelUsed)
                {
#if (CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT == STD_ON)
                    if (TRUE == channelConfigPtr->IcuSupport)
                    {
                        /* Enabling ICU channel notification, for InitState Standby
                         * and Sleep */
                        Icu_EnableNotification(channelConfigPtr->IcuChannelId);
                    }
#endif
                    dioValue = Dio_ReadChannel(channelConfigPtr->RxdPin);
                    if ((TRUE == channelConfigPtr->WakeupbyBus) &&
                        (STD_LOW == dioValue))
                    {
                        /* Invoke function to enable Data Protection */
                        SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
                        CanTrcv_184_Tcan1044_ChState[channel].WakeupReason = (uint8)CANTRCV_WU_BY_BUS;
                        /* Invoke function to disable Data Protection */
                        SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
                        EcuM_SetWakeupEvent(channelConfigPtr->WakeupSourceId);
                    }

                }
                /* Increment the channel number */
                channel++;
            } while (channel < CANTRCV_184_TCAN1044_NUM_OF_CHANNELS);
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
        }
#if (CANTRCV_184_TCAN1044_CFG_POST_BUILD == STD_ON)
    }
#endif
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_Tcan1044_SetOpMode
Service ID (hex).. : 0x01
Sync/Async........ : Asynchronous
Reentrancy........ : Reentrant for different transceivers
Parameters (IN)... : Transceiver, OpMode
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : Sets the mode of the Transceiver to the value OpMode.
Design IDs Covered :
******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1044_SetOpMode(
        uint8 Transceiver,
        CanTrcv_TrcvModeType OpMode)
{
    const CanTrcv_Tcan1044ChConfigType *channelConfigPtr;
    CanTrcv_TrcvModeType currentOpMode;
    Std_ReturnType returnValue;

    /* Initialize return value to E_OK */
    returnValue = (Std_ReturnType)E_OK;

    /* CanTrcv122: Check whether the module is initialized */
    if (CANTRCV_184_TCAN1044_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1044_DrvState)
    {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_SETOPMODE_SID, CANTRCV_184_TCAN1044_E_UNINIT);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* CanTrcv87: If called with InvalidOpMode */
    else if((CANTRCV_TRCVMODE_NORMAL != OpMode) &&
            (CANTRCV_TRCVMODE_STANDBY != OpMode) &&
            (CANTRCV_TRCVMODE_SLEEP != OpMode))
    {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_SETOPMODE_SID, CANTRCV_184_TCAN1044_E_PARAM_TRCV_OPMODE);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* CanTrcv123: Check whether network is out of range */
    else if(CANTRCV_184_TCAN1044_NUM_OF_CHANNELS <= Transceiver)
    {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_SETOPMODE_SID, CANTRCV_184_TCAN1044_E_INVALID_TRANSCEIVER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Invoke function to enable Data Protection */
        SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
        /* Get the operational mode of CAN Transceiver Driver network */
        currentOpMode = CanTrcv_184_Tcan1044_ChState[Transceiver].OperMode;
        /* Invoke function to disable Data Protection */
        SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
        /*  CanTrcv120: If called with OpMode CANTRCV_TRCVMODE_STANDBY when current
            OpMode is not CANTRCV_TRCVMODE_NORMAL or CANTRCV_TRCVMODE_STANDBY,
            that is, the current Opmode is CANTRCV_TRCVMODE_SLEEP */
        if ((CANTRCV_TRCVMODE_STANDBY == OpMode) &&
                (CANTRCV_TRCVMODE_SLEEP == currentOpMode))
        {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                    CANTRCV_184_TCAN1044_SETOPMODE_SID, CANTRCV_184_TCAN1044_E_TRCV_NOT_NORMAL);
#endif
            /* Set the return value to E_NOT_OK */
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
        /*  CanTrcv121: If called with OpMode CANTRCV_TRCVMODE_SLEEP when current
            OpMode is not CANTRCV_TRCVMODE_STANDBY or CANTRCV_TRCVMODE_SLEEP,
            that is, the current Opmode is CANTRCV_TRCVMODE_NORMAL */
        else if((CANTRCV_TRCVMODE_SLEEP == OpMode) &&
                (CANTRCV_TRCVMODE_NORMAL == currentOpMode))
        {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                    CANTRCV_184_TCAN1044_SETOPMODE_SID, CANTRCV_184_TCAN1044_E_TRCV_NOT_STANDBY);
#endif
            /* Set the return value to E_NOT_OK */
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
        /* If no DET error has occurred */
        else
        {
            /* Get the pointer to the structure of the requested network */
            channelConfigPtr = &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[Transceiver];
            /* Check if channel is used or not*/
            if (TRUE == channelConfigPtr->ChannelUsed)
            {
                if (currentOpMode != OpMode)
                {
                    if(OpMode == CANTRCV_TRCVMODE_NORMAL)
                    {
                        /* Invoke the CanTrcv_184_Tcan1044_NormalMode if OpMode is Normal Mode */
                        Tcan1044DrvSetNormalMode(channelConfigPtr);

                        /* Busywait for Transceiver State Change wait time */
#if(CANTRCV_184_TCAN1044_1US16BIT_TIMER_SUPPORT == STD_ON)
#ifndef CAN_PLT_SAFERTOS_ENABLE
                        (void)Tm_BusyWait1us16bit(CANTRCV_184_TCAN1044_WAITTIME_IN_US);
#else
                        vFreeRTOSTaskDelay(pdMS_TO_TICKS(CANTRCV_184_TCAN1044_DELAY_IN_MS));
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
#endif

                        /* If Dio_WriteChannel failed */
#ifndef CAN_PLT_SAFERTOS_ENABLE
                        if (STD_LOW != Dio_ReadChannel(channelConfigPtr->StandBypin))
#else
                        if (STD_LOW != (Dio_LevelType)sail_gpio_ReadPinOutput(channelConfigPtr->StandBypin))
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                        {
#ifndef CAN_PLT_SAFERTOS_ENABLE
                            DEBUGLOG_LOG(DEBUGLOG_SAIL_DEBUG, "%s: Tcan1044 channel %d GPIO read back fail in setting NORMAL mode\r\n",__func__,Transceiver);
#else
                            DEBUG_LOG(SAIL_DEBUG, "%s: Tcan1044 channel %d GPIO read back fail in setting NORMAL mode\r\n",__func__,Transceiver);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                            returnValue = (Std_ReturnType)E_NOT_OK;
                        }
                    }
                    else
                    {
                        /* Invoke the CanTrcv_184_Tcan1044_StandbyMode to set the Standby Mode */
                        Tcan1044DrvSetStandbyMode(channelConfigPtr);

                        /* Busywait for Transceiver State Change wait time */
#if(CANTRCV_184_TCAN1044_1US16BIT_TIMER_SUPPORT == STD_ON)
#ifndef CAN_PLT_SAFERTOS_ENABLE
                        (void)Tm_BusyWait1us16bit(CANTRCV_184_TCAN1044_WAITTIME_IN_US);
#else
                        vFreeRTOSTaskDelay(pdMS_TO_TICKS(CANTRCV_184_TCAN1044_DELAY_IN_MS));
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
#endif
                        /* If Dio_WriteChannel failed */
#ifndef CAN_PLT_SAFERTOS_ENABLE
                        if (STD_HIGH != Dio_ReadChannel(channelConfigPtr->StandBypin))
#else
                        if (STD_HIGH != (Dio_LevelType)sail_gpio_ReadPinOutput(channelConfigPtr->StandBypin))
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                        {
#ifndef CAN_PLT_SAFERTOS_ENABLE
                            DEBUGLOG_LOG(DEBUGLOG_SAIL_DEBUG, "%s: Tcan1044 channel %d GPIO read back fail in setting STANDBY mode\r\n",__func__,Transceiver);
#else
                            DEBUG_LOG(SAIL_DEBUG, "%s: Tcan1044 channel %d GPIO read back fail in setting STANDBY mode\r\n",__func__,Transceiver);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                            returnValue = (Std_ReturnType)E_NOT_OK;
                        }
                    }

                    /* If the mode change successful */
                    if (E_OK == returnValue)
                    {
                        /* Invoke function to enable Data Protection */
                        SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
                        /* Set the Operational Mode of the requested network */
                        CanTrcv_184_Tcan1044_ChState[Transceiver].OperMode = OpMode;
#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
                        if (CANTRCV_TRCVMODE_NORMAL == OpMode)
                        {
                            /* For Normal mode, clearing the Wakeup pending status */
                            CanTrcv_184_Tcan1044_ChState[Transceiver].WakeupPending = FALSE;
                            if (CANTRCV_184_TCAN1044_WU_NOT_FOUND ==
                                    CanTrcv_184_Tcan1044_ChState[Transceiver].WakeupReason)
                            {
                                /* If the Opmode is Normal and WakeupReason is not found, set WakeupReason to Internal */
                                CanTrcv_184_Tcan1044_ChState[Transceiver].WakeupReason = (uint8)CANTRCV_WU_INTERNALLY;
                            }
                        }
                        else
                        {
                            /* If the Opmode is Standby or Sleep, set Wakeupreason to not found */
                            CanTrcv_184_Tcan1044_ChState[Transceiver].WakeupReason = CANTRCV_184_TCAN1044_WU_NOT_FOUND;
#ifdef CAN_PLT_SAFERTOS_ENABLE
                            if (CANTRCV_TRCVMODE_SLEEP == OpMode)
                            {
                                CanTrcv_184_Tcan1044_Config_Wakeup_Gpio(Transceiver);
                                CanTrcv_184_Tcan1044_WakeUp_IRQ_Enable(Transceiver);
                            }
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                        }
#endif
                        /* Invoke function to disable Data Protection */
                        SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
#if(CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT == STD_ON)
                        if (TRUE == channelConfigPtr->IcuSupport)
                        {
                            /* If the Opmode is Normal, disabling ICU channel
                             * notification */
                            if (CANTRCV_TRCVMODE_NORMAL == OpMode)
                            {
                                Icu_DisableNotification(channelConfigPtr->IcuChannelId);
                            }
                            /* If the Opmode is Standby, enabling ICU channel
                             * notification */
                            else if (CANTRCV_TRCVMODE_STANDBY == OpMode)
                            {
                                Icu_EnableNotification(channelConfigPtr->IcuChannelId);
                            }
                            /* If the Opmode is Sleep, doing nothing since ICU channel
                             * notification already enabled when transitioning to
                             * Standby(CanTrcv can be set to Sleep only if current
                             * mode is Standby) */
                            else
                            {
                                /* Do nothing */
                            }
                        }
#endif

                        /* Indicate mode change to CanIf */
                        (void)CanIf_184_Tcan1044_TrcvModeIndication(Transceiver, OpMode);
                    }
                    else
                    {
                        /* Indicate mode change to CanIf */
                        (void)CanIf_184_Tcan1044_TrcvModeIndication(Transceiver, currentOpMode);
                    }
                }
                else
                {
                    /* Indicate mode change to CanIf */
                    (void)CanIf_184_Tcan1044_TrcvModeIndication(Transceiver, currentOpMode);
                }
            }/*Channelused*/
            else
            {
#ifndef CAN_PLT_SAFERTOS_ENABLE
                DEBUGLOG_LOG(DEBUGLOG_SAIL_DEBUG, "%s: channel %d unused\r\n",__func__,Transceiver);
#else
                DEBUG_LOG(SAIL_DEBUG, "%s: channel %d unused\r\n",__func__,Transceiver);
#endif
                returnValue = (Std_ReturnType)E_NOT_OK;
            }
        }/* if(returnValue != E_NOT_OK)*/
    }
    return (returnValue);/* Return Std_ReturnType */
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_Tcan1044_GetOpMode
Service ID (hex).. : 0x02
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : Transceiver
Parameters (INOUT) : None
Parameters (OUT).. : OpMode
Return Value...... : E_OK, E_NOT_OK
Description....... : Gets the mode of the Transceiver and returns it in OpMode.
Design IDs Covered :
******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1044_GetOpMode(
        uint8 Transceiver,
        CanTrcv_TrcvModeType *OpMode)
{
    const CanTrcv_Tcan1044ChConfigType *channelConfigPtr;
    Std_ReturnType returnValue;

    /* Initialize return value to E_OK */
    returnValue = (Std_ReturnType)E_OK;
    /* Get the pointer to the structure of the requested network */
    channelConfigPtr = &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[Transceiver];

    /* CanTrcv124: Check whether the module is Initialized */
    if (CANTRCV_184_TCAN1044_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1044_DrvState)
    {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_GETOPMODE_SID, CANTRCV_184_TCAN1044_E_UNINIT);
#endif
        /* Set the return value to E_NOT_OK  */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* CanTrcv_129: Check whether the Transceiver id is out of range */
    else if(CANTRCV_184_TCAN1044_NUM_OF_CHANNELS <= Transceiver)
    {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_GETOPMODE_SID, CANTRCV_184_TCAN1044_E_INVALID_TRANSCEIVER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* CanTrcv132: Check for NULL POINTER */
    else if(NULL_PTR == OpMode)
    {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_GETOPMODE_SID, CANTRCV_184_TCAN1044_E_PARAM_POINTER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* Check whether any DET error has occurred */
    else
    {
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
            /* Get the operational mode of CAN Transceiver Driver network */
            *OpMode = CanTrcv_184_Tcan1044_ChState[Transceiver].OperMode;
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
        }
        else
        {
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
    }

    return (returnValue); /* Return Std_ReturnType */
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_TCAN1044_GetBusWuReason
Service ID (hex).. : 0x03
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : Transceiver
Parameters (INOUT) : None
Parameters (OUT).. : reason
Return Value...... : E_OK, E_NOT_OK
Description....... : Gets the wakeup reason for the Transceiver and returns it
                     in parameter Reason.
Design IDs Covered :
******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1044_GetBusWuReason(
        uint8 Transceiver,
        CanTrcv_TrcvWakeupReasonType *reason)
{
    const CanTrcv_Tcan1044ChConfigType *channelConfigPtr;
#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
    uint8 wakeupReason = CANTRCV_184_TCAN1044_WU_NOT_FOUND;
#endif
    Std_ReturnType returnValue;

    /* Initialize return value to E_OK */
    returnValue = (Std_ReturnType)E_OK;

    /* Check whether the module is Initialized */
    if (CANTRCV_184_TCAN1044_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1044_DrvState)
    {
        /* Report to DET */
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError (CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_GETBUSWUREASON_SID, CANTRCV_184_TCAN1044_E_UNINIT);
#endif
        /* Set the return value to E_NOT_OK  */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* Check whether the Transceiver id is out of range */
    else if(CANTRCV_184_TCAN1044_NUM_OF_CHANNELS <= Transceiver)
    {
        /* Report to DET */
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_GETBUSWUREASON_SID, CANTRCV_184_TCAN1044_E_INVALID_TRANSCEIVER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* Check for NULL POINTER */
    else if(NULL_PTR == reason)
    {
        /* Report to DET */
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_GETBUSWUREASON_SID, CANTRCV_184_TCAN1044_E_PARAM_POINTER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* Check whether any DET error has occurred */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
            wakeupReason = (uint8)CanTrcv_184_Tcan1044_ChState[Transceiver].WakeupReason;
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
            if (CANTRCV_184_TCAN1044_WU_NOT_FOUND == wakeupReason)
            {
                returnValue = E_NOT_OK;
            }
            else
            {
                *reason = (CanTrcv_TrcvWakeupReasonType)wakeupReason;
            }
#else
            /* Set the Wakeup Reason to CANTRCV_WU_NOT_SUPPORTED */
            *reason = CANTRCV_WU_NOT_SUPPORTED;
            /* Set the return value to E_NOT_OK */
            returnValue = E_OK;
#endif
        } /* if(TRUE == channelConfigPtr->ChannelUsed) */
        else
        {
            /* Set the return value to E_NOT_OK */
            returnValue = E_NOT_OK;
        }
    } /* if(returnValue != E_NOT_OK)*/
    return (returnValue);/* Return Std_ReturnType */
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#if (CANTRCV_184_TCAN1044_VERSION_INFO_API == STD_ON)
#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_Tcan1044_GetVersionInfo
Service ID (hex).. : 0x04
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : versioninfo
Return Value...... : None
Description....... : Gets the version of the module and returns it in
                     VersionInfo.
Design IDs Covered :
******************************************************************************/
void CanTrcv_184_Tcan1044_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    /* Check whether the versioninfo is not equal to null pointer */
    if(NULL_PTR != versioninfo)
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = CANTRCV_184_TCAN1044_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = CANTRCV_184_TCAN1044_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)CANTRCV_184_TCAN1044_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)CANTRCV_184_TCAN1044_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)CANTRCV_184_TCAN1044_SW_PATCH_VERSION;
    }
#if (CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_GETVERSIONINFO_SID, CANTRCV_184_TCAN1044_E_PARAM_POINTER);
    }
#endif /* (CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON) */
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
#endif /* (CANTRCV_184_TCAN1044_VERSION_INFO_API == STD_ON) */

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_Tcan1044_SetWakeupMode
Service ID (hex).. : 0x05
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant for different transceivers
Parameters (IN)... : Transceiver, TrcvWakeupMode
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : Enables, disables or clears wake-up events of the
                     Transceiver according to TrcvWakeupMode.
Design IDs Covered :
******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1044_SetWakeupMode(
        uint8 Transceiver,
        CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
    const CanTrcv_Tcan1044ChConfigType *channelConfigPtr;
#if (STD_ON == CANTRCV_184_TCAN1044_WAKEUP_SUPPORT)
    CanTrcv_Tcan1044ChStateType *channelStatePtr;
#endif
    Std_ReturnType returnValue;

    /* Initialize return value to E_OK */
    returnValue = (Std_ReturnType)E_OK;

    /* CanTrcv127: Check whether the module is initialized */
    if (CANTRCV_184_TCAN1044_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1044_DrvState)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1044_DEV_ERROR_DETECT)
        (void)Det_ReportError (CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_SETWAKEUPMODE_SID, CANTRCV_184_TCAN1044_E_UNINIT);
#endif/* #if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* CanTrcv131: Check whether network is out of range */
    else if(CANTRCV_184_TCAN1044_NUM_OF_CHANNELS <= Transceiver)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1044_DEV_ERROR_DETECT)
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_SETWAKEUPMODE_SID, CANTRCV_184_TCAN1044_E_INVALID_TRANSCEIVER);
#endif/* #if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* CanTrcv89: Check whether TrcvWakeupMode is invalid */
    else if((CANTRCV_WUMODE_ENABLE != TrcvWakeupMode) &&
            (CANTRCV_WUMODE_DISABLE != TrcvWakeupMode) &&
            (CANTRCV_WUMODE_CLEAR != TrcvWakeupMode))
    {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_SETWAKEUPMODE_SID, CANTRCV_184_TCAN1044_E_PARAM_TRCV_WAKEUP_MODE);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* Check if any DET Error has occured */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
#if (STD_ON == CANTRCV_184_TCAN1044_WAKEUP_SUPPORT)
            /* Get the pointer to the structure of the requested network */
            channelStatePtr = &CanTrcv_184_Tcan1044_ChState[Transceiver];

            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
            if ((CANTRCV_WUMODE_CLEAR == TrcvWakeupMode) &&
                    (CANTRCV_WUMODE_DISABLE == channelStatePtr->WakeupNotiforEvent))
            {
                (channelStatePtr->WakeupPending) = FALSE;
            }
            /* Updating the wake up notification mode */
            channelStatePtr->WakeupNotiforEvent = TrcvWakeupMode;
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
#else
            /* Set the return value to E_NOT_OK */
            returnValue = E_NOT_OK;
#endif
        }
        else
        {
            /* Set the return value to E_NOT_OK */
            returnValue = E_NOT_OK;
        }
    }

    /* Return Std_ReturnType */
    return (returnValue);
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_Tcan1044_CheckWakeup
Service ID (hex).. : 0x07
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : Transceiver
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : Service is called by underlying CANIF in case a wake up
                     interrupt is detected.
Design IDs Covered :
******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1044_CheckWakeup(uint8 Transceiver)
{
    Std_ReturnType returnValue = E_NOT_OK;
#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
    const CanTrcv_Tcan1044ChConfigType *channelConfigPtr;
    CanTrcv_Tcan1044ChStateType *channelStatePtr;
#endif

    /* [SWS_CanTrcv_00144] : Check whether module is initialized */
    if (CANTRCV_184_TCAN1044_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1044_DrvState)
    {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_CHECKWAKEUP_SID, CANTRCV_184_TCAN1044_E_UNINIT);
#endif
    }
    /* [SWS_CanTrcv_00145] : Check whether Can Network id is out of range */
    else if(CANTRCV_184_TCAN1044_NUM_OF_CHANNELS <= Transceiver)
    {
#if(CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                CANTRCV_184_TCAN1044_CHECKWAKEUP_SID, CANTRCV_184_TCAN1044_E_INVALID_TRANSCEIVER);
#endif
    }
    /* If no DET error has occured */
    else
    {
#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not and the wake up by bus is enabled or not
        */
        if ((TRUE == channelConfigPtr->ChannelUsed) &&
            (TRUE == channelConfigPtr->WakeupbyBus))
        {
            /* Get the pointer to the structure of the requested network */
            channelStatePtr = &CanTrcv_184_Tcan1044_ChState[Transceiver];

            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();

            /* Check if the wakeup notification event is enabled or not, and if
             * WakeupPending flag is set or not */
            if ((CANTRCV_WUMODE_ENABLE == channelStatePtr->WakeupNotiforEvent) &&
                (TRUE == channelStatePtr->WakeupPending))
            {
                /* Set the pointer WakeupPending to False */
                (channelStatePtr->WakeupPending) = FALSE;

                returnValue = E_OK;
            }
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
        }

        if (E_OK == returnValue)
        {
            /* Report wake up to EcuM */
#ifndef CAN_PLT_SAFERTOS_ENABLE
            EcuM_SetWakeupEvent(channelConfigPtr->WakeupSourceId);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
        }
#endif
    }

    return returnValue;
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_Tcan1044_Deinit
Service ID (hex).. : 0x10
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : De-initializes the CanTrcv module.
Design IDs Covered :
******************************************************************************/
void CanTrcv_184_Tcan1044_DeInit(void)
{
    const CanTrcv_Tcan1044ChConfigType *channelConfigPtr;
    CanTrcv_Tcan1044ChStateType *channelStatePtr;
    /* declare and set the channel value to zero */
    uint8 channel = 0;
    CanTrcv_TrcvModeType currentOpMode;
    Std_ReturnType status = E_OK;

    do
    {
        /* Get the pointer to the structure of the channel */
        channelConfigPtr = &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[channel];

        /* Invoke function to enable Data Protection */
        SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
        currentOpMode = CanTrcv_184_Tcan1044_ChState[channel].OperMode;
        /* Invoke function to disable Data Protection */
        SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
        /* Check if channel is used or not*/
        if ((TRUE == channelConfigPtr->ChannelUsed) &&
            (CANTRCV_TRCVMODE_NORMAL == currentOpMode))
        {
            /* Report to DET */
#if (CANTRCV_184_TCAN1044_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError (CANTRCV_184_TCAN1044_MODULE_ID, CANTRCV_184_TCAN1044_INSTANCE_ID,
                    CANTRCV_184_TCAN1044_DEINIT_SID, CANTRCV_184_TCAN1044_E_TRCV_NOT_STANDBY);
#endif
            status = E_NOT_OK;
        }

        /* Increment the channel number */
        channel++;
    } while ((channel < CANTRCV_184_TCAN1044_NUM_OF_CHANNELS) && (E_OK == status));

    if (E_OK == status)
    {
        /* Set the global Driver State to Not Active */
        CanTrcv_184_Tcan1044_DrvState = CANTRCV_184_TCAN1044_STATE_NOT_ACTIVE;

        channel = 0;
        do
        {
            /* Get the pointer to the structure of the channel */
            channelConfigPtr = &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[channel];

            /* Check if channel is used or not*/
            if (TRUE == channelConfigPtr->ChannelUsed)
            {
#ifdef CAN_PLT_SAFERTOS_ENABLE
                CanTrcv_184_Tcan1044_Wakeup_IRQ_Disable(channel);
                CanTrcv_184_Tcan1044_Deregister_WakeUp_IRQ(channel);
                /* for CAN controller connect with TCAN1044, Rx reused as wake up pin
                   set this pin cfg back to rx */
                Can_Safertos_Config_Gpio(channel);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                /*Invoke the function to set the CAN Transceiver Driver to Standby
                  Mode*/
                Tcan1044DrvSetStandbyMode(channelConfigPtr);

                /* Get the pointer to the structure of the requested network */
                channelStatePtr = &CanTrcv_184_Tcan1044_ChState[channel];

                /* Invoke function to enable Data Protection */
                SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
                /* Set the Operational Mode to Standby */
                channelStatePtr->OperMode = CANTRCV_TRCVMODE_STANDBY;
#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
                /* Disable Wakeup Notification and clear any pending wakeup events */
                channelStatePtr->WakeupNotiforEvent = CANTRCV_WUMODE_DISABLE;
                channelStatePtr->WakeupPending = FALSE;
#endif
                /* Invoke function to disable Data Protection */
                SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
            }
            /* Increment the channel number */
            channel++;
        } while (channel < CANTRCV_184_TCAN1044_NUM_OF_CHANNELS);

        CanTrcv_184_Tcan1044_ConfigPtr = NULL_PTR;
    }
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_Tcan1044_MainFunction
Service ID (hex).. : 0x06
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : Service to scan all busses for wake up events and perform
                     these event.
Design IDs Covered :
******************************************************************************/
void CanTrcv_184_Tcan1044_MainFunction(void)
{
#if(CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
    const CanTrcv_Tcan1044ChConfigType *channelConfigPtr;
    CanTrcv_Tcan1044ChStateType *channelStatePtr;
    Dio_LevelType dioValue;
    CanTrcv_TrcvModeType currentOpMode;
    uint8 channel;

    if (CANTRCV_184_TCAN1044_STATE_ACTIVE == CanTrcv_184_Tcan1044_DrvState)
    {
        /* Initialize the network id to zero */
        channel = 0;
        do
        {
            /* Get the pointer to the structure of the network structure */
            channelConfigPtr = &CanTrcv_184_Tcan1044_ConfigPtr->ChannelConfig[channel];
            /* Get the pointer to the structure of the first network */
            channelStatePtr = &CanTrcv_184_Tcan1044_ChState[channel];

            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();
            currentOpMode = channelStatePtr->OperMode;
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
            /* Check if channel is used or not*/
            if ((TRUE == channelConfigPtr->ChannelUsed) &&
                (TRUE == channelConfigPtr->WakeupbyBus))
            {
                /* Check whether the current operation mode of the network is STANDBY */
                if ((CANTRCV_TRCVMODE_STANDBY == currentOpMode) ||
                    (CANTRCV_TRCVMODE_SLEEP == currentOpMode))
                {
                    /* Invoke the function Dio_ReadChannel to read the value of the
                       Wakeup pin(Rxd) */
#ifndef CAN_PLT_SAFERTOS_ENABLE
                    dioValue = Dio_ReadChannel(channelConfigPtr->RxdPin);
#else
                    dioValue = (Dio_LevelType)sail_gpio_ReadPin(channelConfigPtr->RxdPin);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                    /* Check if the Dio return value is LOW */
                    if (STD_LOW == dioValue)
                    {
                        /* Invoke function to enable Data Protection */
                        SchM_Enter_CanTrcv_184_Tcan1044_Exclusive_Area();

                        (channelStatePtr->WakeupReason) = (uint8)CANTRCV_WU_BY_BUS;

                        /* Set wakeuppending as True */
                        (channelStatePtr->WakeupPending) = TRUE;

                        /* Invoke function to disable Data Protection */
                        SchM_Exit_CanTrcv_184_Tcan1044_Exclusive_Area();
                    } /*if(dioValue == STD_LOW)*/
                } /*if(*(channelStatePtr->OperMode) != CANTRCV_OP_MODE_NORMAL)
                    & channelConfigPtr->WakeupbyBus == TRUE */
            }

            /* Increment the network */
            ++channel;
        }while(channel < CANTRCV_184_TCAN1044_NUM_OF_CHANNELS);
    }
#endif /* #if(CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON) */
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1044_MemMap.h"

#ifdef CAN_PLT_SAFERTOS_ENABLE
#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
void CanTrcv_184_Tcan1044_SetOpModeToStandby(uint8 Transceiver)
{
    if (CANTRCV_184_TCAN1044_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1044_DrvState)
    {
        DEBUG_LOG(SAIL_DEBUG, "%s: channel %d uninit\r\n",__func__,Transceiver);
    }
    else if(CANTRCV_184_TCAN1044_NUM_OF_CHANNELS <= Transceiver)
    {
        DEBUG_LOG(SAIL_DEBUG, "%s: channel %d invalid\r\n",__func__,Transceiver);
    }
    else
    {
#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
        CanTrcv_184_Tcan1044_ChState[Transceiver].OperMode = CANTRCV_TRCVMODE_STANDBY;
#endif
     }
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

/*=============================================================================
|                       END OF FILE                                           |
=============================================================================*/
