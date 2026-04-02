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
  File Name.............. : CanTrcv_184_Tcan1146.c
  Description............ : This file contains functionality of CAN
  Transceiver driver
  Autosar Release Version : R22-11
  Platform............... :
  SW Release Version..... :

  ============================================================================*/

/*==============================================================================
  |                       MISRA-C VIOLATIONS                                   |
  ============================================================================*/
/*

*/

/*==============================================================================
  |                       REVISION HISTORY                                     |
  ==============================================================================
  | Revision  Date            Changed By        Description                    |
  ==============================================================================
 
  ============================================================================*/

/*==============================================================================
  |                       INCLUDE FILES                                        |
  ============================================================================*/
#include "CanTrcv_184_Tcan1146.h"           /* Can Transceiver Driver header file */
#include "CanTrcv_184_Tcan1146_Drv.h"  /* CAN Transceiver Internal header file
*/
#include "SchM_CanTrcv_184_Tcan1146.h"      /* Scheduler Manager header file */
#ifndef CAN_PLT_SAFERTOS_ENABLE
#include "CanIf.h"

#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                 /* DET module header file */
#endif
#if (CANTRCV_184_TCAN1146_BUSERR_FLAG_SUPPORT == STD_ON)
#include "Dem.h"
#endif
#else
#include "debug_log.h"
#include "CanTrcv_184_Tcan1146_If.h"
#include "CanTrcv_184_Tcan1146_Plt_Cfg.h"
#include "CanTrcv_184_Tcan1146_SafeRTOS.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

/*==============================================================================
  |                       VERSION INFORMATION                                  |
  ============================================================================*/
/* AUTOSAR Specification Version Information */
#define CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION_C      4
#define CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION_C      8
#define CANTRCV_184_TCAN1146_AR_RELEASE_REVISION_VERSION_C   0

/* Software Version Information */
#define CANTRCV_184_TCAN1146_SW_MAJOR_VERSION_C   1
#define CANTRCV_184_TCAN1146_SW_MINOR_VERSION_C   1
#define CANTRCV_184_TCAN1146_SW_PATCH_VERSION_C   0

/*==============================================================================
  |                       VERSION CHECK                                        |
  ============================================================================*/
/* AUTOSAR version information check has to match definition in header file */
#if ((CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION != CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION_C) ||\
     (CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION != CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION_C) ||\
     (CANTRCV_184_TCAN1146_AR_RELEASE_REVISION_VERSION != CANTRCV_184_TCAN1146_AR_RELEASE_REVISION_VERSION_C))
#error "AUTOSAR Version Numbers of CanTrcv_184_Tcan1146.c and CanTrcv_184_Tcan1146.h are different"
#endif

#ifndef CAN_PLT_SAFERTOS_ENABLE
/* [SWS_BSW_00036] Inter module version check. */
#if ((CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "Autosar version numbers of CanTrcv_184_Tcan1146.h and CanIf.h are different."
#endif

#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
#if ((CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
#error "Autosar version numbers of CanTrcv_184_Tcan1146.h and Det.h are different."
#endif
#endif

#if (CANTRCV_184_TCAN1146_BUSERR_FLAG_SUPPORT == STD_ON)
#if ((CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
#error "Autosar version numbers of CanTrcv_184_Tcan1146.h and Dem.h are different."
#endif
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#if ((CANTRCV_184_TCAN1146_SW_MAJOR_VERSION != CANTRCV_184_TCAN1146_SW_MAJOR_VERSION_C) ||\
     (CANTRCV_184_TCAN1146_SW_MINOR_VERSION != CANTRCV_184_TCAN1146_SW_MINOR_VERSION_C) ||\
     (CANTRCV_184_TCAN1146_SW_PATCH_VERSION != CANTRCV_184_TCAN1146_SW_PATCH_VERSION_C))
#error "Vendor specific version numbers of CanTrcv_184_Tcan1146.c and CanTrcv_184_Tcan1146.h are inconsistent"
#endif

/*==============================================================================
  |                       GLOBAL VARIABLES                                     |
  ============================================================================*/
#define CANTRCV_184_TCAN1146_MAX_BAUDRATE       5000000u

#define CANTRCV_184_TCAN1146_START_SEC_CONST_NO_INIT_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"
static const CanTrcv_Tcan1146ConfigType* CanTrcv_184_Tcan1146_ConfigPtr;
#define CANTRCV_184_TCAN1146_STOP_SEC_CONST_NO_INIT_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_VAR_INIT_8
#include "CanTrcv_184_Tcan1146_MemMap.h"
/* Global variable to store Initialization status of CAN Transceiver Driver */
static uint8 CanTrcv_184_Tcan1146_DrvState = CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE;
#define CANTRCV_184_TCAN1146_STOP_SEC_VAR_INIT_8
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"
/* Global variable to store Initialization status of CAN Transceiver Channel */
CanTrcv_Tcan1146ChStateType CanTrcv_184_Tcan1146_ChannelState[CANTRCV_184_TCAN1146_NUM_OF_CHANNELS];
#define CANTRCV_184_TCAN1146_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"

/*==============================================================================
  |                       FUNCTION DEFINITIONS                                 |
  ============================================================================*/

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
 *
 Service Name...... : CanTrcv_184_Tcan1146_Init
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
void CanTrcv_184_Tcan1146_Init(const CanTrcv_Tcan1146ConfigType* ConfigPtr)
{
    CanTrcv_ReturnType status = CANTRCV_E_OK;
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    /* declare and set the channel value to zero */
    uint8 channel = 0;
    uint8 wakeupReason = CANTRCV_184_TCAN1146_WU_NOT_FOUND;
    uint8 statusBits = (uint8)TCAN1146_NO_STATUS_SET;
    uint8 currentStatusBits = (uint8)TCAN1146_NO_STATUS_SET;
    boolean PNCfgWritten = FALSE;
#if (CANTRCV_184_TCAN1146_CFG_POST_BUILD == STD_ON)
    if (NULL_PTR == ConfigPtr)
    {
#if (CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_INIT_SID, CANTRCV_184_TCAN1146_E_INIT_FAILED);
#endif
    }
    else
    {
        CanTrcv_184_Tcan1146_ConfigPtr = ConfigPtr;
#else
        CanTrcv_184_Tcan1146_ConfigPtr = &CanTrcv_184_Tcan1146_Config;
#endif
        CanTcrv1146_Plt_Cfg_Init();
        do
        {
            /* Get the pointer to the structure of the channel */
            channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[channel];
            /* Check if channel is used or not*/
            if ((TRUE == channelConfigPtr->ChannelUsed) &&
                (CANTRCV_184_TCAN1146_MAX_BAUDRATE < channelConfigPtr->MaxBaudrate))
            {
                /* Report to DET */
#if (CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                        CANTRCV_184_TCAN1146_INIT_SID, CANTRCV_184_TCAN1146_E_BAUDRATE_NOT_SUPPORTED);
#endif
                status = CANTRCV_E_NOT_OK;
            }
            /* Increment the channel number */
            channel++;
        } while ((channel < CANTRCV_184_TCAN1146_NUM_OF_CHANNELS) && (CANTRCV_E_OK == status));

        if (CANTRCV_E_OK == status)
        {
            channel = 0;
            /* Loop for initializing all the configured CAN Transceiver Driver networks */
            do
            {
                PNCfgWritten = FALSE;
                /* Get the pointer to the structure of the channel */
                channelConfigPtr= &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[channel];

                /* Invoke function to enable Data Protection */
                SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
                /* Set the State variables to default state */
                CanTrcv_184_Tcan1146_ChannelState[channel].OperMode = CANTRCV_TRCVMODE_SLEEP;
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
                CanTrcv_184_Tcan1146_ChannelState[channel].WakeupReason = CANTRCV_184_TCAN1146_WU_NOT_FOUND;
                CanTrcv_184_Tcan1146_ChannelState[channel].WakeupNotiforEvent = CANTRCV_WUMODE_ENABLE;
                CanTrcv_184_Tcan1146_ChannelState[channel].WakeupPending = FALSE;
                CanTrcv_184_Tcan1146_ChannelState[channel].StatusBits = (uint8)TCAN1146_NO_STATUS_SET;
#endif
                /* Invoke function to disable Data Protection */
                SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();

                /* Check if channel is used or not*/
                if (TRUE == channelConfigPtr->ChannelUsed)
                {
                    status = Tcan1146DrvSPIInit(channel);
                    if (CANTRCV_E_OK != status)
                    {
#ifndef CAN_PLT_SAFERTOS_ENABLE
                        DEBUGLOG_LOG(DEBUGLOG_SAIL_ERROR, "%s: channel= %d, SPI init fail\r\n",__func__, channel);
#else
                        DEBUG_LOG(SAIL_ERROR, "%s: channel= %d, SPI init fail\r\n",__func__, channel);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                        break;
                    }
#if (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
                    if ((TRUE == channelConfigPtr->HwPnSupport) &&
                        (TRUE == channelConfigPtr->PnCfg->PnEnabled) &&
                        (TRUE == channelConfigPtr->PnCfg->PowerOnFlag))
                    {
                        status = Tcan1146DrvGetTrcvStatusBits(channel, &statusBits);
                        if (CANTRCV_E_OK != status)
                        {
#ifndef CAN_PLT_SAFERTOS_ENABLE
                            DEBUGLOG_LOG(DEBUGLOG_SAIL_ERROR, "%s: channel= %d, read trcv status fail\r\n",__func__, channel);
#else
                            DEBUG_LOG(SAIL_ERROR, "%s: channel= %d, read trcv status fail\r\n",__func__, channel);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                            break;
                        }
                        /* For uninitiated Transceiver HW, ignoring wakeup bits
                         * otherthan power on bit */
                        currentStatusBits = (statusBits & (uint8)TCAN1146_POWER_ON);
                    }
#endif
                    status = Tcan1146DrvInit(channel, channelConfigPtr->InitState, &PNCfgWritten);
                    if (CANTRCV_E_OK != status)
                    {
#ifndef CAN_PLT_SAFERTOS_ENABLE
                        DEBUGLOG_LOG(DEBUGLOG_SAIL_ERROR, "%s: channel= %d, driver init fail\r\n",__func__, channel);
#else
                        DEBUG_LOG(SAIL_ERROR, "%s: channel= %d, driver init fail\r\n",__func__, channel);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                        break;
                    }
                    
#ifdef CAN_PLT_SAFERTOS_ENABLE
                    CanTrcv_184_Tcan1146_WakeUp_GPIO_Cfg(channel);
                    CanTrcv_184_Tcan1146_Register_WakeUp_IRQ(channel);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
                    status = Tcan1146DrvGetTrcvStatusBits(channel, &statusBits);
                    if (CANTRCV_E_OK != status)
                    {
#ifndef CAN_PLT_SAFERTOS_ENABLE
                        DEBUGLOG_LOG(DEBUGLOG_SAIL_ERROR, "%s: channel= %d, read trcv status after drv init fail\r\n",__func__, channel);
#else
                        DEBUG_LOG(SAIL_ERROR, "%s: channel= %d, read trcv status after drv init fail\r\n",__func__, channel);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
                        break;
                    }
                    currentStatusBits |= statusBits;
                    if (FALSE == PNCfgWritten)
                    {
                        currentStatusBits |= (uint8)TCAN1146_PN_CFG_FAIL;
                    }

                    if (0u != (currentStatusBits & (uint8)TCAN1146_POWER_ON))
                    {
                        wakeupReason = (uint8)CANTRCV_WU_POWER_ON;
                    }
                    else if ((0u != (currentStatusBits & (uint8)TCAN1146_FRAME_OVF)) ||
                             (0u != (currentStatusBits & (uint8)TCAN1146_PN_CFG_FAIL)))
                    {
                        wakeupReason = (uint8)CANTRCV_WU_BY_SYSERR;
                    }
                    else if (0u != (currentStatusBits & (uint8)TCAN1146_WU_BY_BUS))
                    {
                        wakeupReason = (uint8)CANTRCV_WU_BY_BUS;
                    }
                    else
                    {
                        /* Do nothing */
                    }
#endif

                    /* Invoke function to enable Data Protection */
                    SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
                    CanTrcv_184_Tcan1146_ChannelState[channel].OperMode = channelConfigPtr->InitState;
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
                    CanTrcv_184_Tcan1146_ChannelState[channel].StatusBits = currentStatusBits;
                    CanTrcv_184_Tcan1146_ChannelState[channel].WakeupReason = wakeupReason;
#endif
                    /* Invoke function to disable Data Protection */
                    SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();
                }
                /* Increment the channel number */
                channel++;
            } while ((channel < CANTRCV_184_TCAN1146_NUM_OF_CHANNELS) && (CANTRCV_E_OK == status));

            if (CANTRCV_E_OK == status)
            {
                /* Set the Driver State as Active */
                CanTrcv_184_Tcan1146_DrvState = CANTRCV_184_TCAN1146_STATE_ACTIVE;
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON) || (CANTRCV_184_TCAN1146_ICU_CHANNEL_SUPPORT == STD_ON)
                channel = 0;
                do
                {
                    /* Get the pointer to the structure of the channel */
                    channelConfigPtr= &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[channel];
#if (CANTRCV_184_TCAN1146_ICU_CHANNEL_SUPPORT == STD_ON)
                    if (TRUE == channelConfigPtr->IcuSupport)
                    {
                        /* Enabling ICU channel notification, for InitState Standby
                         * and Sleep */
                        Icu_EnableNotification(channelConfigPtr->IcuChannelId);
                    }
#endif

#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
                    /* Invoke function to enable Data Protection */
                    SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
                    currentStatusBits = CanTrcv_184_Tcan1146_ChannelState[channel].StatusBits;
                    //Clearing status bits that will be reported now
                    statusBits = currentStatusBits & (uint8)(~(((uint8)TCAN1146_POWER_ON) |
                                                               ((uint8)TCAN1146_WU_BY_BUS) |
                                                               ((uint8)TCAN1146_FRAME_OVF)));
                    CanTrcv_184_Tcan1146_ChannelState[channel].StatusBits = statusBits;
                    /* Invoke function to disable Data Protection */
                    SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();

                    //Retrieving only status bits that need to be reported now
                    currentStatusBits &= (uint8)(((uint8)TCAN1146_POWER_ON) |
                                                 ((uint8)TCAN1146_WU_BY_BUS) |
                                                 ((uint8)TCAN1146_FRAME_OVF) |
                                                 ((uint8)TCAN1146_PN_CFG_FAIL));
                    Tcan1146DrvReportStatus(channelConfigPtr, currentStatusBits);
#endif
                    /* Increment the channel number */
                    channel++;
                } while ((channel < CANTRCV_184_TCAN1146_NUM_OF_CHANNELS));
#endif
            }
            else /* status != CANTRCV_E_OK */
            {
                /* Set the Driver State as Active */
                CanTrcv_184_Tcan1146_DrvState = CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE;
                channel = 0;
                do
                {
                    /* Invoke function to enable Data Protection */
                    SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
                    /* Set the State variables to default state */
                    CanTrcv_184_Tcan1146_ChannelState[channel].OperMode = CANTRCV_TRCVMODE_SLEEP;
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
                    CanTrcv_184_Tcan1146_ChannelState[channel].WakeupReason = CANTRCV_184_TCAN1146_WU_NOT_FOUND;
                    CanTrcv_184_Tcan1146_ChannelState[channel].WakeupNotiforEvent = CANTRCV_WUMODE_ENABLE;
                    CanTrcv_184_Tcan1146_ChannelState[channel].WakeupPending = FALSE;
                    CanTrcv_184_Tcan1146_ChannelState[channel].StatusBits = (uint8)TCAN1146_NO_STATUS_SET;
#endif
                    /* Invoke function to disable Data Protection */
                    SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();
                    channel++;
                } while (channel < CANTRCV_184_TCAN1146_NUM_OF_CHANNELS);
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
                if (CANTRCV_E_CFG_FAILURE == status)
                {
                    (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                            CANTRCV_184_TCAN1146_INIT_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
                }
#endif
            }
        }
#if (CANTRCV_184_TCAN1146_CFG_POST_BUILD == STD_ON)
    }
#endif
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_SetOpMode
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
Std_ReturnType CanTrcv_184_Tcan1146_SetOpMode(uint8 Transceiver,
        CanTrcv_TrcvModeType OpMode)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    CanTrcv_TrcvModeType currentOpMode;
    Std_ReturnType returnValue = E_OK;
    CanTrcv_ReturnType drvReturnValue = CANTRCV_E_OK;
#if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON) && (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
    uint8 statusBits = (uint8)TCAN1146_NO_STATUS_SET;
#endif    
    //[SWS_CanTrcv_00122]
    /* Check whether the module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_SETOPMODE_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif
        /* Set the Api return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }

    /* CanTrcv132: If called with InvalidOpMode */
    else if((CANTRCV_TRCVMODE_NORMAL != OpMode) && (CANTRCV_TRCVMODE_STANDBY != OpMode)
            && (CANTRCV_TRCVMODE_SLEEP != OpMode))
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_SETOPMODE_SID, CANTRCV_184_TCAN1146_E_PARAM_TRCV_OPMODE);
#endif
        /* Set the Api return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* Check whether network is out of range */
    else if (CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_SETOPMODE_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif
        /* Set the Api return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Invoke function to enable Data Protection */
        SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
        /* Get the operational mode of CAN Transceiver Driver network */
        currentOpMode = CanTrcv_184_Tcan1146_ChannelState[Transceiver].OperMode;
        /* Invoke function to disable Data Protection */
        SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();

        /*  CanTrcv120: If called with OpMode CANTRCV_TRCVMODE_STANDBY when current
            OpMode is not CANTRCV_TRCVMODE_NORMAL or CANTRCV_TRCVMODE_STANDBY,
            that is, the current Opmode is CANTRCV_TRCVMODE_SLEEP */
        if((CANTRCV_TRCVMODE_STANDBY == OpMode) && (CANTRCV_TRCVMODE_SLEEP == currentOpMode))
        {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                    CANTRCV_184_TCAN1146_SETOPMODE_SID, CANTRCV_184_TCAN1146_E_TRCV_NOT_NORMAL);
#endif
            /* Set the Api return value to E_NOT_OK */
            returnValue = (Std_ReturnType)E_NOT_OK;
        }

        /*  CanTrcv121: If called with OpMode CANTRCV_TRCVMODE_SLEEP when current
            OpMode is not CANTRCV_TRCVMODE_STANDBY or CANTRCV_TRCVMODE_SLEEP,
            that is, the current Opmode is CANTRCV_TRCVMODE_NORMAL */
        else if((CANTRCV_TRCVMODE_SLEEP == OpMode) && (CANTRCV_TRCVMODE_NORMAL == currentOpMode))
        {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                    CANTRCV_184_TCAN1146_SETOPMODE_SID, CANTRCV_184_TCAN1146_E_TRCV_NOT_STANDBY);
#endif
            /* Set the Api return value to E_NOT_OK */
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
        /* If no DET error has occurred */
        else
        {
            /* Get the pointer to the structure of the requested network */
            channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
            /* Check if channel is used or not*/
            if (TRUE == channelConfigPtr->ChannelUsed)
            {
                drvReturnValue = Tcan1146DrvSetOpMode(Transceiver, OpMode);
                if (CANTRCV_E_OK == drvReturnValue)
                {
#ifdef CAN_PLT_SAFERTOS_ENABLE
                    if (CANTRCV_TRCVMODE_SLEEP == OpMode)
                    {
                        CanTrcv_184_Tcan1146_WakeUp_IRQ_Enable(Transceiver);
                    }
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
#if(CANTRCV_184_TCAN1146_ICU_CHANNEL_SUPPORT == STD_ON)
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
                    (void)CanIf_184_Tcan1146_TrcvModeIndication(Transceiver, OpMode);
#if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON) && (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
                    /* Invoke function to enable Data Protection */
                    SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
                    /* Get the operational mode of CAN Transceiver Driver network */
                    statusBits = CanTrcv_184_Tcan1146_ChannelState[Transceiver].StatusBits;
                    /* Invoke function to disable Data Protection */
                    SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();
                    if ((TRUE == channelConfigPtr->HwPnSupport) &&
                        (TRUE == channelConfigPtr->PnCfg->PnEnabled) &&
                        (0u == (statusBits & (uint8)TCAN1146_PN_CFG_FAIL)) &&
                        (CANTRCV_TRCVMODE_NORMAL == OpMode))
                    {
                        /* Inform CanNm that selective wakeup is enabled*/
                        (void)CanIf_184_Tcan1146_ConfirmPnAvailability(Transceiver);
                    }
#endif
                }
                else
                {
                    returnValue = (Std_ReturnType)E_NOT_OK;
                }
            }/*Channelused*/
            else
            {
                returnValue = (Std_ReturnType)E_NOT_OK;
            }
        }
    }

#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_E_CFG_FAILURE == drvReturnValue)
    {
        (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_SETOPMODE_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
    }
#endif

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_GetOpMode
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
Std_ReturnType CanTrcv_184_Tcan1146_GetOpMode(uint8 Transceiver,
        CanTrcv_TrcvModeType* OpMode)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    Std_ReturnType returnValue;

    /* Initialize return value to E_OK */
    returnValue = (Std_ReturnType)E_OK;
    /* Get the pointer to the structure of the requested network */
    channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];

    //[SWS_CanTrcv_00124]
    /* Check whether the module is Initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETOPMODE_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif
        /* Set the return value to E_NOT_OK  */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    //[SWS_CanTrcv_00129]
    /* Check whether the Transceiver id is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETOPMODE_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    //[SWS_CanTrcv_00132]
    /* Check for NULL POINTER */
    else if(NULL_PTR == OpMode)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETOPMODE_SID, CANTRCV_184_TCAN1146_E_PARAM_POINTER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* If no DET error has occurred */
    else
    {
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
            /* Get the operational mode of CAN Transceiver Driver network */
            *OpMode = CanTrcv_184_Tcan1146_ChannelState[Transceiver].OperMode;
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();
        }
        else
        {
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
    }

    return (returnValue); /* Return Std_ReturnType */
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_GetBusWuReason
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
Std_ReturnType CanTrcv_184_Tcan1146_GetBusWuReason(uint8 Transceiver,
        CanTrcv_TrcvWakeupReasonType* reason)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
    uint8 wakeupReason = CANTRCV_184_TCAN1146_WU_NOT_FOUND;
#endif
    Std_ReturnType returnValue;

    /* Initialize return value to E_OK */
    returnValue = (Std_ReturnType)E_OK;

    /* Check whether the module is Initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        /* Report to DET */
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETBUSWUREASON_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif
        /* Set the return value to E_NOT_OK  */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* Check whether the Transceiver id is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
        /* Report to DET */
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETBUSWUREASON_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* Check for NULL POINTER */
    else if(NULL_PTR == reason)
    {
        /* Report to DET */
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETBUSWUREASON_SID, CANTRCV_184_TCAN1146_E_PARAM_POINTER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* If no DET error has occurred */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(channelConfigPtr->ChannelUsed == TRUE)
        {
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
            wakeupReason = (uint8)CanTrcv_184_Tcan1146_ChannelState[Transceiver].WakeupReason;
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();
            if (CANTRCV_184_TCAN1146_WU_NOT_FOUND == wakeupReason)
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
            /* Set the return value to E_OK */
            returnValue = E_OK;
#endif
        } /* if(channelConfigPtr->ChannelUsed == TRUE) */
        else
        {
            /* Set the return value to E_NOT_OK */
            returnValue = E_NOT_OK;
        }
    } /* if(returnValue != E_NOT_OK)*/
    return returnValue;/* Return Std_ReturnType */
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_GetVersionInfo
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
#if (CANTRCV_184_TCAN1146_VERSION_INFO_API == STD_ON)
#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
void CanTrcv_184_Tcan1146_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    /* Check whether the versioninfo is not equal to null pointer */
    if(NULL_PTR != versioninfo)
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = CANTRCV_184_TCAN1146_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = CANTRCV_184_TCAN1146_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)CANTRCV_184_TCAN1146_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)CANTRCV_184_TCAN1146_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)CANTRCV_184_TCAN1146_SW_PATCH_VERSION;
    }
#if (CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
    else
    {
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETVERSIONINFO_SID, CANTRCV_184_TCAN1146_E_PARAM_POINTER);
    }
#endif /* (CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
#endif /* (CANTRCV_184_TCAN1146_VERSION_INFO_API == STD_ON) */

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_SetWakeupMode
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
Std_ReturnType CanTrcv_184_Tcan1146_SetWakeupMode(uint8 Transceiver,
        CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;

#if (STD_ON == CANTRCV_184_TCAN1146_WAKEUP_SUPPORT)
    CanTrcv_Tcan1146ChStateType* canTrcvChannelStatePtr;
#endif

    Std_ReturnType returnValue;

    /* Initialize return value to E_OK */
    returnValue = E_OK;

    //[SWS_CanTrcv_00127]
    /* Check whether the module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_SETWAKEUPMODE_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    //[SWS_CanTrcv_00131]
    /* Check whether network is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_SETWAKEUPMODE_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    //[SWS_CanTrcv_00089]
    /* Check whether TrcvWakeupMode is invalid */
    else if ((CANTRCV_WUMODE_ENABLE != TrcvWakeupMode) &&
            (CANTRCV_WUMODE_DISABLE != TrcvWakeupMode) &&
            (CANTRCV_WUMODE_CLEAR != TrcvWakeupMode))
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_SETWAKEUPMODE_SID, CANTRCV_184_TCAN1146_E_PARAM_TRCV_WAKEUP_MODE);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* If no DET error has occurred */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
#if (STD_ON == CANTRCV_184_TCAN1146_WAKEUP_SUPPORT)
            /* Get the pointer to the structure of the requested network */
            canTrcvChannelStatePtr = &CanTrcv_184_Tcan1146_ChannelState[Transceiver];

            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
            if ((CANTRCV_WUMODE_CLEAR == TrcvWakeupMode) &&
                    (CANTRCV_WUMODE_DISABLE == canTrcvChannelStatePtr->WakeupNotiforEvent))
            {
                (canTrcvChannelStatePtr->WakeupPending) = FALSE;
            }
            /* Updating the wake up notification mode */
            canTrcvChannelStatePtr->WakeupNotiforEvent = TrcvWakeupMode;
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();
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
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#if (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_GetTrcvSystemData
  Service ID (hex).. : 0x09
  Sync/Async........ : Synchronous
  Reentrancy........ : Non Reentrant
  Parameters (IN)... : Transceiver
  Parameters (INOUT) : None
  Parameters (OUT).. : TrcvSysData
  Return Value...... : E_OK, E_NOT_OK
  Description....... : Reads the transceiver configuration/status data and
  returns it through parameter TrcvSysData.
  Design IDs Covered :
 ******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1146_GetTrcvSystemData(uint8 Transceiver,
        uint32* TrcvSysData)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    Std_ReturnType returnValue;
    CanTrcv_ReturnType drvReturnValue;

    /* Initialize return values */
    returnValue = E_OK;
    drvReturnValue = CANTRCV_E_OK;

    /* Check whether the module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETTRCVSYSTEMDATA_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* Check whether network is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETTRCVSYSTEMDATA_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* Check for NULL POINTER */
    else if(NULL_PTR == TrcvSysData)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETTRCVSYSTEMDATA_SID, CANTRCV_184_TCAN1146_E_PARAM_POINTER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* If no DET error has occurred */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
            drvReturnValue =  Tcan1146DrvGetTrcvSystemData(Transceiver, TrcvSysData);
            if (CANTRCV_E_OK != drvReturnValue)
            {
                returnValue = (Std_ReturnType)E_NOT_OK;
            }
        }/*Channelused*/
        else
        {
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
    }/* if(returnValue != E_NOT_OK)*/
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_E_CFG_FAILURE == drvReturnValue)
    {
        (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_GETTRCVSYSTEMDATA_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
    }
#endif

    return (returnValue);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_ClearTrcvWufFlag
  Service ID (hex).. : 0x0a
  Sync/Async........ : Synchronous
  Reentrancy........ : Reentrant for different transceivers
  Parameters (IN)... : Transceiver
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : E_OK, E_NOT_OK
  Description....... : Clears the WUF flag in the transceiver hardware.
  Design IDs Covered :
 ******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1146_ClearTrcvWufFlag(uint8 Transceiver)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    Std_ReturnType returnValue;
    CanTrcv_ReturnType drvReturnValue;

    /* Initialize return values */
    returnValue = E_OK;
    drvReturnValue = CANTRCV_E_OK;

    /* Check whether the module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CLEARTRCVWUFFLAG_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* Check whether network is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CLEARTRCVWUFFLAG_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* If no DET error has occurred */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
            drvReturnValue =  Tcan1146DrvClearTrcvWufFlag(Transceiver);

            if (CANTRCV_E_OK == drvReturnValue)
            {
                /* Indicate to CanIf */
                (void)CanIf_184_Tcan1146_ClearTrcvWufFlagIndication(Transceiver);
            }
            else
            {
                returnValue = (Std_ReturnType)E_NOT_OK;
            }
        }/*Channelused*/
        else
        {
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
    }/* if(returnValue != E_NOT_OK)*/

#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_E_CFG_FAILURE == drvReturnValue)
    {
        (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CLEARTRCVWUFFLAG_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
    }
#endif

    return (returnValue);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_ReadTrcvTimeoutFlag
  Service ID (hex).. : 0x0b
  Sync/Async........ : Synchronous
  Reentrancy........ : Non Reentrant
  Parameters (IN)... : Transceiver
  Parameters (INOUT) : None
  Parameters (OUT).. : FlagState
  Return Value...... : E_OK, E_NOT_OK
  Description....... : Reads the status of the timeout flag from the transceiver
  hardware.
  Design IDs Covered :
 ******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1146_ReadTrcvTimeoutFlag(uint8 Transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* FlagState)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    Std_ReturnType returnValue;
    CanTrcv_ReturnType drvReturnValue;

    /* Initialize return values */
    returnValue = E_OK;
    drvReturnValue = CANTRCV_E_OK;

    /* Check whether the module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_READTRCVTIMEOUTFLAG_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* Check whether network is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_READTRCVTIMEOUTFLAG_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* Check for NULL POINTER */
    else if(NULL_PTR == FlagState)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_READTRCVTIMEOUTFLAG_SID, CANTRCV_184_TCAN1146_E_PARAM_POINTER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* If no DET error has occurred */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
            drvReturnValue =  Tcan1146DrvReadTrcvTimeoutFlag(Transceiver, FlagState);
            if (CANTRCV_E_OK != drvReturnValue)
            {
                returnValue = (Std_ReturnType)E_NOT_OK;
            }
        }/*Channelused*/
        else
        {
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
    }/* if(returnValue != E_NOT_OK)*/

#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_E_CFG_FAILURE == drvReturnValue)
    {
        (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_READTRCVTIMEOUTFLAG_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
    }
#endif

    return (returnValue);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_ClearTrcvTimeoutFlag
  Service ID (hex).. : 0x0c
  Sync/Async........ : Synchronous
  Reentrancy........ : Non Reentrant
  Parameters (IN)... : Transceiver
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : E_OK, E_NOT_OK
  Description....... : Clears the status of the timeout flag in the transceiver
  hardware.
  Design IDs Covered :
 ******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1146_ClearTrcvTimeoutFlag(uint8 Transceiver)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    Std_ReturnType returnValue;
    CanTrcv_ReturnType drvReturnValue;

    /* Initialize return values */
    returnValue = E_OK;
    drvReturnValue = CANTRCV_E_OK;

    /* Check whether the module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CLEARTRCVTIMEOUTFLAG_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* Check whether network is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CLEARTRCVTIMEOUTFLAG_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* Check any DET error has occurred */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
            drvReturnValue =  Tcan1146DrvClearTrcvTimeoutFlag(Transceiver);
            if (CANTRCV_E_OK != drvReturnValue)
            {
                returnValue = (Std_ReturnType)E_NOT_OK;
            }
        }/*Channelused*/
        else
        {
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
    }/* if(returnValue != E_NOT_OK)*/
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_E_CFG_FAILURE == drvReturnValue)
    {
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CLEARTRCVTIMEOUTFLAG_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
    }
#endif
    return (returnValue);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_ReadTrcvSilenceFlag
  Service ID (hex).. : 0x0d
  Sync/Async........ : Synchronous
  Reentrancy........ : Non Reentrant
  Parameters (IN)... : Transceiver
  Parameters (INOUT) : None
  Parameters (OUT).. : FlagState
  Return Value...... : E_OK, E_NOT_OK
  Description....... : Reads the status of the silence flag from the transceiver
  hardware.
  Design IDs Covered :
 ******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1146_ReadTrcvSilenceFlag(uint8 Transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* FlagState)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    Std_ReturnType returnValue;
    CanTrcv_ReturnType drvReturnValue;

    /* Initialize return values */
    returnValue = E_OK;
    drvReturnValue = CANTRCV_E_OK;

    /* Check whether the module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_READTRCVSILENCEFLAG_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* Check whether network is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
        /* Report to DET */
#if(STD_ON == CANTRCV_184_TCAN1146_DEV_ERROR_DETECT)
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_READTRCVSILENCEFLAG_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif/* #if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON) */
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* Check for NULL POINTER */
    else if(NULL_PTR == FlagState)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_READTRCVSILENCEFLAG_SID, CANTRCV_184_TCAN1146_E_PARAM_POINTER);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = (Std_ReturnType)E_NOT_OK;
    }
    /* Check any DET error has occurred */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
            drvReturnValue =  Tcan1146DrvReadTrcvSilenceFlag(Transceiver, FlagState);
            if (CANTRCV_E_OK != drvReturnValue)
            {
                returnValue = (Std_ReturnType)E_NOT_OK;
            }
        }/*Channelused*/
        else
        {
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
    }/* if(returnValue != E_NOT_OK)*/

#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_E_CFG_FAILURE == drvReturnValue)
    {
        (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_READTRCVSILENCEFLAG_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
    }
#endif
    return (returnValue);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
#endif

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_CheckWakeup
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
Std_ReturnType CanTrcv_184_Tcan1146_CheckWakeup(uint8 Transceiver)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
    CanTrcv_Tcan1146ChStateType* channelStatePtr;
    uint8 statusBits = (uint8)TCAN1146_NO_STATUS_SET;
    uint8 currentStatusBits = (uint8)TCAN1146_NO_STATUS_SET;
#endif
    Std_ReturnType returnValue = E_NOT_OK;

    //[SWS_CanTrcv_00144]
    /* Check whether module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CHECKWAKEUP_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif
    }
    //[SWS_CanTrcv_00145]
    /* Check whether Can Network id is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CHECKWAKEUP_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif
    }
    /* Check if any DET error has occured */
    else
    {
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not and the wake up by bus is enabled or not */
        if ((TRUE == channelConfigPtr->ChannelUsed) &&
            (TRUE == channelConfigPtr->WakeupbyBus))
        {

            /* Get the pointer to the structure of the requested network */
            channelStatePtr = &CanTrcv_184_Tcan1146_ChannelState[Transceiver];

            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
            /* Check if the wakeup notification event is enabled or not, and if
             * WakeupPending flag is set or not */
            if ((CANTRCV_WUMODE_ENABLE == channelStatePtr->WakeupNotiforEvent) &&
                (TRUE == channelStatePtr->WakeupPending))
            {
                /* Set the pointer WakeupPending to False */
                (channelStatePtr->WakeupPending) = FALSE;
                currentStatusBits = channelStatePtr->StatusBits;
                //Clearing status bits that will be reported now
                statusBits = currentStatusBits & (uint8)(~((uint8)TCAN1146_WU_BY_BUS | (uint8)TCAN1146_FRAME_OVF));
                channelStatePtr->StatusBits = statusBits;

                returnValue = E_OK;
            }
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();
        }
        if (E_OK == returnValue)
        {
            //Retrieving only status bits that need to be reported now
            currentStatusBits &= ((uint8)TCAN1146_WU_BY_BUS | (uint8)TCAN1146_FRAME_OVF);
            /* Report wake up to EcuM */
#ifndef CAN_PLT_SAFERTOS_ENABLE
            Tcan1146DrvReportStatus(channelConfigPtr, currentStatusBits);
#endif
        }

#endif /* (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON) */
    }

    return(returnValue);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_SetPNActivationState
  Service ID (hex).. : 0x0F
  Sync/Async........ : Synchronous
  Reentrancy........ : Non Reentrant
  Parameters (IN)... : ActivationState
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : E_OK, E_NOT_OK
  Description....... : The API configures the wake-up of the transceiver for
  Standby and Sleep Mode: Either the CAN transceiver is
  woken up by a remote wake-up pattern (standard CAN
  wake-up) or by the configured remote wake-up frame.
  Design IDs Covered :
 ******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1146_SetPNActivationState (
        CanTrcv_184_Tcan1146_PNActivationType ActivationState)
{
#if (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    CanTrcv_Tcan1146ChStateType* canTrcvChannelStatePtr;
    uint8 noOfCfgChanges = 0u;
    uint8 channel;
    CanTrcv_ReturnType drvReturnValue = CANTRCV_E_OK;
#endif
    Std_ReturnType returnValue = E_OK;


    /* Check whether module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_SETPNACTIVATIONSTATE_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    /* If called with Invalid Activation State */
    else if((CANTRCV_184_TCAN1146_PN_ENABLED != ActivationState) &&
            (CANTRCV_184_TCAN1146_PN_DISABLED != ActivationState))
    {
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
    }
    else
    {
#if(CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
        /* Initialize the network id to zero */
        channel = 0;
        do
        {
            /* Get the pointer to the structure of the network structure */
            channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[channel];
            canTrcvChannelStatePtr = &CanTrcv_184_Tcan1146_ChannelState[channel];

            if ((TRUE == channelConfigPtr->ChannelUsed) &&
                (0u == (canTrcvChannelStatePtr->StatusBits & (uint8)TCAN1146_PN_CFG_FAIL)))
            {
                if (CANTRCV_184_TCAN1146_PN_ENABLED == ActivationState)
                {
                    drvReturnValue = Tcan1146DrvSetPnEnable(channel, TRUE);
                }
                else
                {
                    drvReturnValue = Tcan1146DrvSetPnEnable(channel, FALSE);
                }
                if (CANTRCV_E_OK != drvReturnValue)
                {
                    break;
                }
                noOfCfgChanges++;
            }

            /* Increment the network */
            ++channel;
        } while(channel < CANTRCV_184_TCAN1146_NUM_OF_CHANNELS);

        if (0u == noOfCfgChanges)
        {
            /* Set the return value to E_NOT_OK */
            returnValue = E_NOT_OK;
        }

#else
        /* Set the return value to E_NOT_OK */
        returnValue = E_NOT_OK;
#endif
    }
    return(returnValue);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_CheckWakeFlag
  Service ID (hex).. : 0x0E
  Sync/Async........ : Asynchronous
  Reentrancy........ : Non Reentrant
  Parameters (IN)... : Transceiver
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : E_OK, E_NOT_OK
  Description....... : Requests to check the status of the wakeup flag from the
  transceiver hardware.
  Design IDs Covered :
 ******************************************************************************/
Std_ReturnType CanTrcv_184_Tcan1146_CheckWakeFlag(
        uint8 Transceiver)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
    uint8 wakeupReason = CANTRCV_184_TCAN1146_WU_NOT_FOUND;
    CanTrcv_TrcvWakeupModeType wakeupMode;
    uint8 statusBits = (uint8)TCAN1146_NO_STATUS_SET;
#endif
    Std_ReturnType returnValue;
    CanTrcv_ReturnType drvReturnValue;

    /* Initialize return values */
    returnValue = E_NOT_OK;
    drvReturnValue = CANTRCV_E_OK;

    //[SWS_CanTrcv_00144]
    /* Check whether module is initialized */
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CHECKWAKEFLAG_SID, CANTRCV_184_TCAN1146_E_UNINIT);
#endif
    }
    //[SWS_CanTrcv_00145]
    /* Check whether Can Network id is out of range */
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CHECKWAKEFLAG_SID, CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER);
#endif
    }
    /* Check if any DET error has occured */
    /* Implementation is done as per specified in the sequence diagram, defined
     * in section 9.3 De-Initialization (SPI Synchronous), in the CanTrcv SWS
     * version R22-11
     */
    else
    {
        /* Get the pointer to the structure of the requested network */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[Transceiver];
        /* Check if channel is used or not*/
        if(TRUE == channelConfigPtr->ChannelUsed)
        {
            /* Check if the wake up support is ON */
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)

            /* Invoke the function to check if any wakeup reason is detected */
            drvReturnValue = Tcan1146DrvGetTrcvStatusBits(Transceiver, &statusBits);

            if (CANTRCV_E_OK == drvReturnValue)
            {
                if (0u != (statusBits & ((uint8)TCAN1146_WU_BY_BUS | (uint8)TCAN1146_FRAME_OVF)))
                {
#if(CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
                    if (0u != (statusBits & (uint8)TCAN1146_FRAME_OVF))
                    {
                        wakeupReason = (uint8)CANTRCV_WU_BY_SYSERR;
                    }
                    else
#endif
                    {
                        wakeupReason = (uint8)CANTRCV_WU_BY_BUS;
                    }
                    /* Invoke function to enable Data Protection */
                    SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
                    CanTrcv_184_Tcan1146_ChannelState[Transceiver].WakeupReason = wakeupReason;
                    wakeupMode = CanTrcv_184_Tcan1146_ChannelState[Transceiver].WakeupNotiforEvent;
                    /* Invoke function to disable Data Protection */
                    SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();

                    if ((TRUE == channelConfigPtr->WakeupbyBus) &&
                        (CANTRCV_WUMODE_ENABLE == wakeupMode))
                    {
                        //Retrieving only status bits that need to be reported now
                        statusBits &= (uint8)(((uint8)TCAN1146_WU_BY_BUS) |
                                              ((uint8)TCAN1146_FRAME_OVF));
                        Tcan1146DrvReportStatus(channelConfigPtr, statusBits);
                    }
                }
#if (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
                (void)CanIf_184_Tcan1146_CheckTrcvWakeFlagIndication(Transceiver);
#endif
                /* Set the return value to E_OK */
                returnValue = E_OK;
            }
#endif /* (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON) */

        } /* if(channelConfigPtr->blChannelUsed == TRUE) */
    }
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_E_CFG_FAILURE == drvReturnValue)
    {
        (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                CANTRCV_184_TCAN1146_CHECKWAKEFLAG_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
    }
#endif
    return(returnValue);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_Deinit
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
void CanTrcv_184_Tcan1146_DeInit(void)
{
    Std_ReturnType status = E_OK;
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    /* declare and set the channel value to zero */
    uint8 channel = 0;
    CanTrcv_TrcvModeType currentOpMode;
    CanTrcv_ReturnType drvReturnValue = CANTRCV_E_OK;

    do
    {
        /* Get the pointer to the structure of the channel */
        channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[channel];

        /* Invoke function to enable Data Protection */
        SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
        /* Set the Operational Mode of the requested network */
        currentOpMode = CanTrcv_184_Tcan1146_ChannelState[channel].OperMode;
        /* Invoke function to disable Data Protection */
        SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();

        /* Check if channel is used or not, if currentOpMode is Normal */
        if ((TRUE == channelConfigPtr->ChannelUsed) &&
            (CANTRCV_TRCVMODE_NORMAL == currentOpMode))
        {
            /* Report to DET */
#if (CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError (CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                    CANTRCV_184_TCAN1146_DEINIT_SID, CANTRCV_184_TCAN1146_E_TRCV_NOT_STANDBY);
#endif
            status = E_NOT_OK;
        }
        /* Increment the channel number */
        channel++;
    } while ((channel < CANTRCV_184_TCAN1146_NUM_OF_CHANNELS) && (E_OK == status));

    if ((E_OK == status) &&
        (CANTRCV_184_TCAN1146_STATE_ACTIVE == CanTrcv_184_Tcan1146_DrvState))
    {
        /* Set the global Driver State to Not Active */
        CanTrcv_184_Tcan1146_DrvState = CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE;

        channel = 0;
        /* Loop for deinitializing all the configured CAN Transceiver Driver networks */
        do
        {
            /* Get the pointer to the structure of the channel */
            channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[channel];
            /* Check if channel is used or not*/
            if (TRUE == channelConfigPtr->ChannelUsed)
            {
#ifdef CAN_PLT_SAFERTOS_ENABLE
                CanTrcv_184_Tcan1146_Wakeup_IRQ_Disable(channel);
                CanTrcv_184_Tcan1146_Deregister_WakeUp_IRQ(channel);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

                drvReturnValue = Tcan1146DrvSoftReset(channel);
                if (CANTRCV_E_OK != drvReturnValue)
                {
                    status = E_NOT_OK;
                    break;
                }
                /* Disable all interrupts */
                drvReturnValue = Tcan1146DrvInterruptDis(channel);
                if (CANTRCV_E_OK != drvReturnValue)
                {
                    status = E_NOT_OK;
                    break;
                }
                /* Clear all pending interrupts */
                drvReturnValue = Tcan1146DrvInterruptClr(channel);
                if (CANTRCV_E_OK != drvReturnValue)
                {
                    status = E_NOT_OK;
                    break;
                }
                /* Invoke the function to set the CAN Transceiver Driver to
                 * Sleep Mode */
                drvReturnValue = Tcan1146DrvSetModeReg(channel, CANTRCV_TRCVMODE_SLEEP);
                if (CANTRCV_E_OK != drvReturnValue)
                {
                    status = E_NOT_OK;
                    break;
                }

                /* Invoke function to enable Data Protection */
                SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
                /* Set the Operational Mode of the requested network */
                CanTrcv_184_Tcan1146_ChannelState[channel].OperMode = CANTRCV_TRCVMODE_SLEEP;
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
                CanTrcv_184_Tcan1146_ChannelState[channel].WakeupNotiforEvent = CANTRCV_WUMODE_DISABLE;
                CanTrcv_184_Tcan1146_ChannelState[channel].WakeupPending = FALSE;
                CanTrcv_184_Tcan1146_ChannelState[channel].StatusBits = (uint8)TCAN1146_NO_STATUS_SET;
#endif
                /* Invoke function to disable Data Protection */
                SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();

            }
            /* Increment the channel number */
            channel++;
        } while (CANTRCV_184_TCAN1146_NUM_OF_CHANNELS > channel);
        /* Check whether the channel number is less than CANTRCV_184_TCAN1146_NUM_OF_CHANNELS */
    }
    if (E_OK == status)
    {
        CanTrcv_184_Tcan1146_ConfigPtr = NULL_PTR;
    }
    else
    {
        CanTrcv_184_Tcan1146_DrvState = CANTRCV_184_TCAN1146_STATE_ACTIVE;
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        if (CANTRCV_E_CFG_FAILURE == drvReturnValue)
        {
            (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                    CANTRCV_184_TCAN1146_DEINIT_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
        }
#endif
    }
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_MainFunction
  Service ID (hex).. : 0x06
  Parameters (IN)... : None
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : None
  Description....... : Service to scan all busses for wake up events and perform
  these event.
  Design IDs Covered :
 ******************************************************************************/
void CanTrcv_184_Tcan1146_MainFunction(void)
{
#if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    CanTrcv_Tcan1146ChStateType* canTrcvChannelStatePtr;
    uint8 wakeupReason = CANTRCV_184_TCAN1146_WU_NOT_FOUND;
    CanTrcv_TrcvModeType currentOpMode;
    uint8 statusBits = (uint8)TCAN1146_NO_STATUS_SET;

    uint8 channel;

    if (CANTRCV_184_TCAN1146_STATE_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        /* Initialize the network id to zero */
        channel = 0;
        do
        {
            /* Get the pointer to the structure of the network structure */
            channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[channel];
            /* Get the pointer to the structure of the first network */
            canTrcvChannelStatePtr = &CanTrcv_184_Tcan1146_ChannelState[channel];

            /* Invoke function to enable Data Protection */
            SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
            currentOpMode = canTrcvChannelStatePtr->OperMode;
            /* Invoke function to disable Data Protection */
            SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();

            /* Check if channel is used or not*/
            if ((TRUE == channelConfigPtr->ChannelUsed) &&
                (TRUE == channelConfigPtr->WakeupbyBus))
            {
                /* Check whether the current operation mode of the network is STANDBY */
                if ((CANTRCV_TRCVMODE_STANDBY == currentOpMode) ||
                    (CANTRCV_TRCVMODE_SLEEP == currentOpMode))
                {
                    /* Invoke the function to check if any wakeup reason is detected */
                    returnValue = Tcan1146DrvGetTrcvStatusBits(channel, &statusBits);
                    if (CANTRCV_E_OK != returnValue)
                    {
                        break;
                    }
                    if (0u != (statusBits & ((uint8)TCAN1146_WU_BY_BUS | (uint8)TCAN1146_FRAME_OVF)))
                    {
#if(CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
                        if (0u != (statusBits & (uint8)TCAN1146_FRAME_OVF))
                        {
                            wakeupReason = (uint8)CANTRCV_WU_BY_SYSERR;
                        }
                        else
#endif
                        {
                            wakeupReason = (uint8)CANTRCV_WU_BY_BUS;
                        }

                        /* Invoke function to enable Data Protection */
                        SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();

                        (canTrcvChannelStatePtr->StatusBits) |= statusBits;
                        (canTrcvChannelStatePtr->WakeupReason) = wakeupReason;
                        (canTrcvChannelStatePtr->WakeupPending) = TRUE;

                        /* Invoke function to disable Data Protection */
                        SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();
                    }
                } /*if(*(canTrcvChannelStatePtr->OperMode) != CANTRCV_OP_MODE_NORMAL)
                    & channelConfigPtr->WakeupbyBus == TRUE */
            }

            /* Increment the network */
            ++channel;
        }while(channel < CANTRCV_184_TCAN1146_NUM_OF_CHANNELS);
#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        if(CANTRCV_E_CFG_FAILURE == returnValue)
        {
            (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                    CANTRCV_184_TCAN1146_MAINFUNCTION_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
        }
#endif
    }
#endif /* #if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON) */
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1146_MemMap.h"

#if (CANTRCV_184_TCAN1146_BUSERR_FLAG_SUPPORT == STD_ON)
#define CANTRCV_184_TCAN1146_START_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1146_MemMap.h"
void CanTrcv_184_Tcan1146_MainFunctionDiagnostics(void)
{
    const CanTrcv_Tcan1146ChConfigType* channelConfigPtr;
    CanTrcv_184_Tcan1146_TrcvFlagStateType busErrBit = CANTRCV_184_TCAN1146_FLAG_CLEARED;
    CanTrcv_ReturnType drvReturnValue = CANTRCV_E_OK;
    boolean runtimeErr = FALSE;

    uint8 channel;

    if (CANTRCV_184_TCAN1146_STATE_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        /* Initialize the network id to zero */
        channel = 0;
        do
        {
            /* Get the pointer to the structure of the network structure */
            channelConfigPtr = &CanTrcv_184_Tcan1146_ConfigPtr->ChannelConfig[channel];

            /* Check if channel is used or not*/
            if ((TRUE == channelConfigPtr->ChannelUsed) &&
                (TRUE == channelConfigPtr->HwPnSupport) &&
                (TRUE == channelConfigPtr->PnCfg->BusErrFlag) &&
                (0u != channelConfigPtr->DemEventId))
            {
                /* Invoke the function to check if any wakeup reason is detected */
                drvReturnValue = Tcan1146DrvCheckBusErrFlag(channel, &busErrBit);

                if (CANTRCV_E_OK != drvReturnValue)
                {
                    runtimeErr = TRUE;
                    /* Increment the network */
                    ++channel;
                    continue;
                }

                if (CANTRCV_184_TCAN1146_FLAG_SET == busErrBit)
                {
#if (CANTRCV_184_TCAN1146_DEM_STD_REPORTING == STD_ON)
                        (void)Dem_SetEventStatus (channelConfigPtr->DemEventId, DEM_EVENT_STATUS_FAILED);
#endif
                    drvReturnValue = Tcan1146DrvClearBusErrFlag(channel);
                    if (CANTRCV_E_OK != drvReturnValue)
                    {
                        runtimeErr = TRUE;
                    }
                }
                else
                {
#if (CANTRCV_184_TCAN1146_DEM_STD_REPORTING == STD_ON)
                    (void)Dem_SetEventStatus (channelConfigPtr->DemEventId, DEM_EVENT_STATUS_PASSED);
#endif
                }
            }

            /* Increment the network */
            ++channel;
        } while (channel < CANTRCV_184_TCAN1146_NUM_OF_CHANNELS);

#if(CANTRCV_184_TCAN1146_DEV_ERROR_DETECT == STD_ON)
        if (TRUE == runtimeErr)
        {
            (void)Det_ReportRuntimeError(CANTRCV_184_TCAN1146_MODULE_ID, CANTRCV_184_TCAN1146_INSTANCE_ID,
                    CANTRCV_184_TCAN1146_MAINFUNCTIONDIAGNOSTICS_SID, CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL);
        }
#endif
    }
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1146_MemMap.h"
#endif

#ifdef CAN_PLT_SAFERTOS_ENABLE
#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
void CanTrcv_184_Tcan1146_SetOpModeToStandby(uint8 Transceiver)
{
    if (CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE == CanTrcv_184_Tcan1146_DrvState)
    {
        DEBUG_LOG(SAIL_DEBUG, "%s: channel %d uninit\r\n",__func__,Transceiver);
    }
    else if(CANTRCV_184_TCAN1146_NUM_OF_CHANNELS <= Transceiver)
    {
        DEBUG_LOG(SAIL_DEBUG, "%s: channel %d invalid\r\n",__func__,Transceiver);
    }
    else
    {
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
        CanTrcv_184_Tcan1146_ChannelState[Transceiver].OperMode = CANTRCV_TRCVMODE_STANDBY;
#endif
    }
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

/*=============================================================================
  |                       END OF FILE                                           |
  =============================================================================*/
