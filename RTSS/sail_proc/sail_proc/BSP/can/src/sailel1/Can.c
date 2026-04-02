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
    File Name.............. : Can.c
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
#ifdef __cplusplus
extern "C"{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
/* CAN module header file, this includes CAN Module configuration header file */
#include "Can_Drv.h"
#ifndef CAN_PLT_SAFERTOS_ENABLE
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/* Include the declarations of CAN callback functions and types */
#include "CanIf_Cbk.h"
#else
#include "Can_SafeRTOS.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
#include "SchM_Can.h"
#include "Can_Cfg.h"
#include "Can_Plt_Cfg.h"
#if(CAN_FUSA_ENABLE == STD_ON)
#include "Can_Fusa_Internal.h"
#endif
/*==============================================================================
|                       GLOBAL CONSTANTS                                       |
==============================================================================*/
/*==============================================================================
|                       GLOBAL VARIABLES                                       |
==============================================================================*/
#define CAN_START_SEC_VAR_CLEARED_ASIL_B_8
#include "Can_MemMap.h"
/* Variable to store the ApiID to report Det error */
static uint8 Can_ApiId ={0};
#define CAN_STOP_SEC_VAR_CLEARED_ASIL_B_8
#include "Can_MemMap.h"
/*==============================================================================
|                       LOCAL STRUCTURES, ENUMS, TYPEDEFS                      |
==============================================================================*/
/*==============================================================================
|                       LOCAL CONSTANTS and MACROS                             |
==============================================================================*/
#define CAN_AR_RELEASE_MAJOR_VERSION_C     4u
#define CAN_AR_RELEASE_MINOR_VERSION_C     8u
#define CAN_AR_RELEASE_REVISION_VERSION_C  0u
#define CAN_SW_MAJOR_VERSION_C     1u
#define CAN_SW_MINOR_VERSION_C     0u
#define CAN_SW_PATCH_VERSION_C     0u
/* Maximum size of the CAN Data */
#define CAN_PAYLOAD_MAX_BYTES         (8U)
/* Maximum size of the CAN FD  */
#define CAN_FD_PAYLOAD_MAX_BYTES      (64U)

#define CAN_IRQ_CALL_DEPTH_LIMIT	(255U)
/*==============================================================================
|                       LOCAL FUNCTION PROTOTYPES                              |
==============================================================================*/

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline Std_ReturnType Can_ReportDetParamController
                                    (uint8 ControllerId,
                                        uint8 ServiceId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline Std_ReturnType Can_WriteDetCheck(
                        Can_HwHandleType Hth,
                        const Can_PduType* PduInfo);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline Std_ReturnType Can_SetControllerModeDetCheck(uint8
                Controller, Can_ControllerStateType Transition);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*==============================================================================
|                       LOCAL VARIABLES                                        |
==============================================================================*/
#define CAN_START_SEC_VAR_CLEARED_ASIL_B_PTR
#include "Can_MemMap.h"
static const Can_ConfigType* Can_ConfigPtr;
#define CAN_STOP_SEC_VAR_CLEARED_ASIL_B_PTR
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static Can_MutexState Can_HthMutex[CAN_MAX_HTH_CONFIGURED] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
/* This flag stores the CAN driver state */
static CanHWUnitStateType CanHWUnitState = CAN_HW_UNINIT;
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
uint8 Can_InterruptDisableCount[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
                                             
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
Can_CtrlType Can_CtrlInfo[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
/*==============================================================================
|                       VERSION CHECK                                          |
==============================================================================*/
/* [SWS_BSW_00036] Inter module version check. */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#ifndef CAN_PLT_SAFERTOS_ENABLE
#if ((CAN_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
//#error "Autosar version numbers of Can.h and Det.h are different."
#endif
#if ((CAN_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
//#error "Autosar version numbers of Can.h and \
                EcuM.h are different."
#endif
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
//#error "Autosar version numbers of Can.h and \
                CanIf_Cbk.h are different."
#endif
/* SW version check of *.h/c of the own module */
#if ((CAN_SW_MAJOR_VERSION_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_C != CAN_SW_PATCH_VERSION))
//#error "The SW version number of Can.c and Can.h are different."
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
#endif
/*==============================================================================
|                       FUNCTION DEFINITIONS                                   |
==============================================================================*/

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_Init
Service ID (hex).. : 0x00
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant
Parameters (IN)... : Config
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function initializes the module.
Design IDs Covered :
*******************************************************************************/
void Can_Init(const Can_ConfigType* Config)
{
    uint8 ctrlIndex;
    Std_ReturnType status = E_OK;
    Can_ApiId = CAN_SID_INIT;
//#ifdef CAN_VARIANT_PRE_COMPILE
    Can_ConfigPtr = &Can_Config_Default;
//#endif
// #ifdef CAN_VARIANT_POST_BUILD
//     if (NULL_PTR == Config);
//     {
// #if(CAN_DEV_ERROR_DETECT == STD_ON)
//         /* Report to DET */
//         DEBUG_LOG(SAIL_WARNING,"%s : %d\r\n",__func__, __LINE__);
//         (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, Can_ApiId,
//                                                         CAN_E_PARAM_POINTER);
// #endif
//         status = E_NOT_OK;
//     }
//     if(status == E_OK)
// #endif /*end CAN_VARIANT_POST_BUILD */
    {
        if(CAN_HW_UNINIT != CanHWUnitState)
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, Can_ApiId,
                                                            CAN_E_TRANSITION);
#endif
            status = E_NOT_OK;
        }
        else
        {
            /* CAN Controller is not in state UNINIT */
            for(ctrlIndex=CAN_ZERO;ctrlIndex<((uint8)NUMBER_OF_ACTIVE_CAN_CTRL);ctrlIndex++)
            {
                /* SWS_Can_00408 */
                if(CAN_CS_UNINIT != Can_CtrlInfo[ctrlIndex].CanCtrlState)
                {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
                                            Can_ApiId, CAN_E_TRANSITION);
#endif
                    status = E_NOT_OK;
                    break;
                }
            }
        }
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    if (E_OK == status)
    {
        for(ctrlIndex=CAN_ZERO;ctrlIndex<((uint8)NUMBER_OF_ACTIVE_CAN_CTRL);ctrlIndex++)
        {
            if(CanFusa_Cntrl_In_SafeState(ctrlIndex) == TRUE)
            {
              status = E_NOT_OK;
              break;
            }
        }
        
    }
#endif    
    if (E_OK == status)
    {
        /*Store config pointer, such that it can be used throughout driver*/
// #ifdef CAN_VARIANT_POST_BUILD
//         Can_ConfigPtr = Config;
// #endif
		Can_Plt_Cfg_Init();
        Can_Drv_Cfg_Init(Can_ConfigPtr);
#if(CAN_FUSA_ENABLE == STD_ON)
        CanFusa_Cfg_Init(Can_ConfigPtr);
#endif
		for(ctrlIndex=CAN_ZERO;ctrlIndex<((uint8)NUMBER_OF_ACTIVE_CAN_CTRL);ctrlIndex++)
		{
			status = Can_Drv_Init(ctrlIndex);
			Can_Drv_Config_Interrupts(ctrlIndex, CAN_CS_STOPPED);
			if(status == E_OK)
			{
				Can_CtrlInfo[ctrlIndex].CanCtrlRequestedState = CAN_CS_STOPPED;
				Can_CtrlInfo[ctrlIndex].CanCtrlState = CAN_CS_STOPPED;
			}
			else
			{
				break;
			}
		}
		if(status == E_OK)
		{
			/* Change the driver state to initialized */
			CanHWUnitState = CAN_HW_READY;
		}
		else
		{
			/* Change the driver state to uninitialized */
			CanHWUnitState = CAN_HW_UNINIT;
#if(CAN_FUSA_ENABLE == STD_ON)
			/* Enable the Safe State mode  for all the controllers and report to SSM */
			(void) CanFusa_Set_CanDrv_SafeState(CAN_SID_INIT);
#endif
		}
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#if(CAN_VERSION_API_ENABLE == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_GetVersionInfo
Service ID (hex).. : 0x07
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : versioninfo
Return Value...... : None
Description....... : This function returns version information of this module.
Design IDs Covered :
*******************************************************************************/
void Can_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if(CAN_FUSA_ENABLE == STD_ON)
    Std_ReturnType status =E_OK;
    uint8 ctrlIndex =0;
    for(ctrlIndex=0; ctrlIndex < NUMBER_OF_ACTIVE_CAN_CTRL; ctrlIndex++)
    {
        if(CanFusa_Cntrl_In_SafeState(ctrlIndex)== TRUE)
        {
            status =E_NOT_OK;
            break;
        }
    }
    if(status ==E_OK)
#endif
    {        
        /* If the parameter versionInfo is a null pointer */
        if (NULL_PTR == versioninfo)
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_GETVERSIONINFO,
                                                            CAN_E_PARAM_POINTER);
#endif
        }
        else
        {
            /* module vendor Id */
            versioninfo->vendorID = CAN_VENDOR_ID;
            /* can module Id */
            versioninfo->moduleID = CAN_MODULE_ID;
            /* module major version */
            versioninfo->sw_major_version = CAN_SW_MAJOR_VERSION;
            /* module minor version */
            versioninfo->sw_minor_version = CAN_SW_MINOR_VERSION;
            /* module patch version */
            versioninfo->sw_patch_version = CAN_SW_PATCH_VERSION;
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif

#if(CAN_SET_BAUDRATE_API == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_SetBaudrate
Service ID (hex).. : 0x0f
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant for different Controllers. Non reentrant for the
                     same Controller.
Parameters (IN)... : Controller, BaudRateConfigID
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : This service shall set the baud rate configuration of the
                     CAN controller. Depending on necessary baud rate
                     modifications the controller might have to reset.
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_SetBaudrate(uint8 Controller,
                                    uint16 BaudRateConfigID)
{
    Std_ReturnType status;
    Can_ApiId = CAN_SID_SET_BAUDRATE;
    /* Check if CAN driver is initialized */
    status = Can_ReportDetUninit(Can_ApiId);
    if(E_OK == status)
    {
        /* Check if Controller is valid */
        status = Can_ReportDetParamController(Controller, Can_ApiId);
        /* if Controller is valid, then check the state */
        if (E_OK == status)
        {
            /* If the CAN controller is not in "stopped" state */
            if (Can_CtrlInfo[Controller].CanCtrlState != CAN_CS_STOPPED)
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                /* Report invalid state to DET */
                (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
                                    Can_ApiId, CAN_E_TRANSITION);
#endif
                status = E_NOT_OK ;
            }
        }
        else
        {
            status = E_NOT_OK ;
        }
    }
    if (E_OK == status)
    {
        /* check if BaudRateConfigID is invalid/unsupported */
        if(BaudRateConfigID >= Can_ConfigPtr->CanActiveCtrPtr[Controller].CanNumBaudrates)
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report invalid baudrate to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
                                    Can_ApiId, CAN_E_PARAM_BAUDRATE);
#endif
            status = E_NOT_OK;
        }
        else
        {
#if(CAN_FUSA_ENABLE == STD_ON)
            if(CanFusa_Cntrl_In_SafeState(Controller) == (uint8) TRUE)
            {
                status = E_NOT_OK;
            }
            else
#endif
            {
                status = Can_Drv_SetBaudrate(Controller,BaudRateConfigID);
            }
        }
    }
    return (status);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_SetControllerMode
Service ID (hex).. : 0x03
Sync/Async........ : Asynchronous
Reentrancy........ : Non Reentrant
Parameters (IN)... : Controller, Transition
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK,E_NOT_OK
Description....... : This function performs software triggered state transitions
                     of the CAN controller State machine.
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_SetControllerMode(uint8 Controller, 
                                Can_ControllerStateType Transition)
{
    Std_ReturnType retVal = E_OK;
    Can_ApiId = CAN_SID_SETCONTROLLERMODE ;
    /* Check if CAN driver is initialized */
    if(Can_ReportDetUninit(Can_ApiId) != E_OK)
    {
       retVal = E_NOT_OK;
    }
    /* Check if Controller is valid */
    else if(Can_ReportDetParamController(Controller,Can_ApiId) != E_OK)
    {
        retVal = E_NOT_OK;
    }
    /* Check if state transition is valid */
    else if(Can_SetControllerModeDetCheck(Controller,Transition) != E_OK)
    {
        retVal = E_NOT_OK;
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    else if((CanFusa_Cntrl_In_SafeState(Controller)== TRUE) &&
           (CanFusa_Cntrl_GetCurFaultCode(Controller)!= CAN_FUSA_FLT_CODE_CFG_MISMATCH))
            
    {
        retVal = E_NOT_OK;    
    }
    else if((CanFusa_Cntrl_In_SafeState(Controller)== TRUE) 
        &&(CanFusa_Cntrl_GetCurFaultCode(Controller)== CAN_FUSA_FLT_CODE_CFG_MISMATCH)
        &&(Transition != CAN_CS_STARTED))
    {
        retVal = E_NOT_OK;        
    }
#endif
    else
    {
       switch(Transition)
       {
            case CAN_CS_STARTED:
                Can_Drv_SetControllerMode(Controller,Transition);
                /* Change the requested controller state to started */
                Can_CtrlInfo[Controller].CanCtrlRequestedState = CAN_CS_STARTED;
                break;
            case CAN_CS_STOPPED:
                /* If requested transition state is same as the current state*/
                if(Can_CtrlInfo[Controller].CanCtrlState == CAN_CS_STOPPED)
                {
                    Can_Drv_CtrlModeIndication(Controller,CAN_CS_STOPPED);
                }
                else
                {
                    Can_Drv_SetControllerMode(Controller,Transition);
                    /* Change the requested controller state to stopped */
                    Can_CtrlInfo[Controller].CanCtrlRequestedState = CAN_CS_STOPPED;
                }
                break;
            case CAN_CS_SLEEP:
                /* If requested transition state is same as the current state*/
                if(Can_CtrlInfo[Controller].CanCtrlState == CAN_CS_SLEEP)
                {
                    Can_Drv_CtrlModeIndication(Controller,CAN_CS_SLEEP);
                }
                else
                {
                    Can_Drv_SetControllerMode(Controller,Transition);
                    /* Change the requested controller state to sleep */
                    Can_CtrlInfo[Controller].CanCtrlRequestedState = CAN_CS_SLEEP;
                }
                break;
            default:
                retVal = E_NOT_OK;
                break;
        }
#if(CAN_FUSA_ENABLE == STD_ON)
        CanFusa_Reset_ModeCheckCnt(Controller);
#endif
    }
    return(retVal);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_DisableControllerInterrupts
Service ID (hex).. : 0x04
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : Controller
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function disables all interrupts for this controller.
Design IDs Covered :
*******************************************************************************/
void Can_DisableControllerInterrupts(uint8 Controller)
{
    Std_ReturnType status = E_OK;
    Can_ApiId = CAN_SID_DISABLECONTROLLERINTERRUPTS;
    /* Check if CAN driver is initialized */
    status = Can_ReportDetUninit(Can_ApiId);
    if(status !=E_NOT_OK)
    {
        /* Check if Controller is valid */
        status = Can_ReportDetParamController(Controller, Can_ApiId);
    }
    if(status !=E_NOT_OK)
    {
#if(CAN_FUSA_ENABLE == STD_ON)
        if(CanFusa_Cntrl_In_SafeState(Controller) != (uint8) TRUE)
#endif
        {
            /* Enter Critical Section */
            SchM_Enter_Can_Exclusive_Area_00();
			if(Can_InterruptDisableCount[Controller] == CAN_IRQ_CALL_DEPTH_LIMIT)
			{	
				SchM_Exit_Can_Exclusive_Area_00();
				#if(CAN_DEV_ERROR_DETECT == STD_ON)
				(void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, Can_ApiId,
                                                        CAN_E_IRQ_CALL_DEPTH_OVERFLOW);
				#endif										
			}
            else if (Can_InterruptDisableCount[Controller] == CAN_ZERO)
            {
				Can_InterruptDisableCount[Controller]++;
                SchM_Exit_Can_Exclusive_Area_00();
                /* Disable controller interrupts */
                Can_Drv_DisableAllInterrupts(Controller);
            }
			else{
				/* Increment the Can_DisableControllerInterrupts call counter */
				Can_InterruptDisableCount[Controller]++;
				/* Exit Critical Section */
				SchM_Exit_Can_Exclusive_Area_00();
			}
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_EnableControllerInterrupts
Service ID (hex).. : 0x05
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : Controller
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function enables all allowed interrupts.
Design IDs Covered :
*******************************************************************************/
void Can_EnableControllerInterrupts(uint8 Controller)
{
    Std_ReturnType status = E_OK;
    Can_ApiId = CAN_SID_ENABLECONTROLLERINTERRUPTS;
    /* Check if CAN driver is initialized */
    status = Can_ReportDetUninit(Can_ApiId);
    if(status != E_NOT_OK)
    {
        /* Check if Controller is valid */
        status = Can_ReportDetParamController(Controller,Can_ApiId);
    }
    if (status != E_NOT_OK)
    {
#if(CAN_FUSA_ENABLE == STD_ON)
        if(CanFusa_Cntrl_In_SafeState(Controller) != (uint8) TRUE)
#endif
        {
            /* Enter Critical Section */
            SchM_Enter_Can_Exclusive_Area_00();
			if (Can_InterruptDisableCount[Controller] == CAN_ONE) {
				/* decrement interrupt disable count */
                Can_InterruptDisableCount[Controller]-- ;
				/* Exit Critical Section */
				SchM_Exit_Can_Exclusive_Area_00();
				/* Enable controller interrupts */
				Can_Drv_Config_Interrupts(Controller, Can_CtrlInfo[Controller].CanCtrlRequestedState);
            }
            else if (Can_InterruptDisableCount[Controller] > CAN_ONE) {
                /* decrement interrupt disable count */
                Can_InterruptDisableCount[Controller]-- ;
				SchM_Exit_Can_Exclusive_Area_00();
			}
            else {
				/* Exit Critical Section */
				SchM_Exit_Can_Exclusive_Area_00();
			}
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_Write
Service ID (hex).. : 0x06
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant (thread-safe)
Parameters (IN)... : Hth, PduInfo
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK, CAN_BUSY
Description....... : This function is called by CanIf to pass a CAN message to
                     CanDrv for transmission.
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_Write(Can_HwHandleType Hth,const Can_PduType* PduInfo)
{
    Std_ReturnType retVal ;
    uint8 txobjIndex ;
#if(CAN_FUSA_ENABLE == STD_ON)
    uint8 Controller;
#endif
    Can_ApiId = CAN_SID_WRITE;
    /* Check if CAN driver is initialized */
    if (Can_ReportDetUninit(Can_ApiId) != E_OK)
    {
       retVal = E_NOT_OK;
    }
    /* Check DET errors related to Can_Write API */
    else if(Can_WriteDetCheck(Hth,PduInfo) != E_OK)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /*Get the Tx object index*/
        txobjIndex = Can_ConfigPtr->CanTxRxObjMapPtr[Hth].ObjIndex;
#if(CAN_FUSA_ENABLE == STD_ON)
        Controller = Can_ConfigPtr->CanTxHwObjPtr[txobjIndex].HwTxObjectCtrlrId;
        if(CanFusa_Cntrl_In_SafeState(Controller) == (uint8) TRUE)
        {
            retVal = E_NOT_OK;
        }
        else
#endif
        {
            /*Enter Critical Section */
            SchM_Enter_Can_Exclusive_Area_02();
            /* Check the Tx object is busy.if not,set to busy */
            if (Can_HthMutex[txobjIndex] != MUTEX_SIGNALED )
            {
                Can_HthMutex[txobjIndex] = MUTEX_SIGNALED ;
                /*Exit Critical Section */
                SchM_Exit_Can_Exclusive_Area_02();
                /* Write the message into TX buffer */
                retVal = (Std_ReturnType)Can_Drv_Write(PduInfo,
                                            &Can_ConfigPtr->CanTxHwObjPtr[txobjIndex]);
                /*Enter Critical Section */
                SchM_Enter_Can_Exclusive_Area_02();
                /* set Tx object state to free */
                Can_HthMutex[txobjIndex] = MUTEX_RELEASED;
                /*Exit Critical Section */
                SchM_Exit_Can_Exclusive_Area_02();
            }
            else
            {
                /*Exit Critical Section */
                SchM_Exit_Can_Exclusive_Area_02();
                retVal = (Std_ReturnType)CAN_BUSY;
            }
        }
    }
    return(retVal);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_OFF)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_MainFunction_Write
Service ID (hex).. : 0x01
Sync/Async........ : NA
Reentrancy........ : NA
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function performs the polling of TX confirmation
                     when CAN_TX_PROCESSING is set to POLLING.
Design IDs Covered :
*******************************************************************************/
void Can_MainFunction_Write(void)
{
#if (CAN_MAIN_WRITE_FUNC_ENABLE == STD_ON)
    uint8 ctrlIndex=0;
    if( CanHWUnitState != CAN_HW_UNINIT ) {
		for(ctrlIndex=0; ctrlIndex < NUMBER_OF_ACTIVE_CAN_CTRL; ctrlIndex++)
		{
#if(CAN_FUSA_ENABLE == STD_ON)
			if(CanFusa_Cntrl_In_SafeState(ctrlIndex) == TRUE)
			{
				continue;
			}
			else
#endif
			{
				/*Check if CanTxProcessing Mode is polling */
				if(Can_ConfigPtr->CanActiveCtrPtr[ctrlIndex].CanTxProcessing == CAN_POLLING)
				{
					Can_Drv_TxComplete(ctrlIndex
#ifdef CAN_PLT_SAFERTOS_ENABLE
                                       ,FALSE
#endif
                                       );
				}
#if(CAN_MIXED_MODE_ENABLE == STD_ON)
				/*Check if CanTxProcessing Mode is Mixed */
				else if(Can_ConfigPtr->CanActiveCtrPtr[ctrlIndex].CanTxProcessing == CAN_MIXED)
				{
					Can_Drv_Process_PendingTxList(ctrlIndex);
				}
#endif
				else
				{
					/*Do Nothing */
				}
			}
		}
    }
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#else
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_MainFunction_Write_Period
Service ID (hex).. : 0x01
Sync/Async........ : NA
Reentrancy........ : NA
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function performs the polling of TX confirmation
                     when CAN_TX_PROCESSING is set to POLLING.
Design IDs Covered :
*******************************************************************************/
void Can_MainFunction_Write_Period(uint8 PeriodId)
{
#if (CAN_MAIN_WRITE_FUNC_ENABLE == STD_ON)
    uint8 ctrlIndex=0;
	if( CanHWUnitState != CAN_HW_UNINIT ) {
		for(ctrlIndex=0; ctrlIndex < NUMBER_OF_ACTIVE_CAN_CTRL; ctrlIndex++)
		{
#if(CAN_FUSA_ENABLE == STD_ON)
			if(CanFusa_Cntrl_In_SafeState(ctrlIndex) == TRUE)
			{
				continue;
			}
			else
#endif
			{
				/*Check if CanTxProcessing Mode is polling */
				if(Can_ConfigPtr->CanActiveCtrPtr[ctrlIndex].CanTxProcessing == CAN_POLLING)
				{
					Can_Drv_TxComplete(ctrlIndex, PeriodId
#ifdef CAN_PLT_SAFERTOS_ENABLE
                                       ,FALSE
#endif
                                       );
				}
				/*To process MIXED mode and already polled TX Messages*/
				Can_Drv_Process_PendingTxList(ctrlIndex, PeriodId);
			}
		}
	}
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_OFF)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_MainFunction_Read
Service ID (hex).. : 0x08
Sync/Async........ : NA
Reentrancy........ : NA
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function performs the polling of RX indications when
                     CAN_RX_PROCESSING is set to POLLING.
Design IDs Covered :
*******************************************************************************/
void Can_MainFunction_Read(void)
{
#if (CAN_MAIN_READ_FUNC_ENABLE == STD_ON)
    uint8 rxHwObjBufferIndex;
    uint16 rxHwObjIndex;
    CAN_CtrIdType rxHwObjControlId;
    Can_HwType mailBox = {.ControllerId = 0, .Hoh = 0};
    Can_RxBufferType rxHwObjBufferType;
	if( CanHWUnitState != CAN_HW_UNINIT ) {
		for(rxHwObjIndex=0;rxHwObjIndex< (Can_ConfigPtr->CanNumOfRxHwObj); rxHwObjIndex++)
		{
			rxHwObjControlId = Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].HwRxObjectCtrlrId;
#if(CAN_FUSA_ENABLE == STD_ON)
			if(CanFusa_Cntrl_In_SafeState(rxHwObjControlId) == (uint8)TRUE)
			{
				continue;
			}
			else
#endif
			{
				mailBox.ControllerId = rxHwObjControlId;
				mailBox.Hoh = Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].HwRxObjectId;
				rxHwObjBufferIndex = Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].RxBufferIndex;
				rxHwObjBufferType = Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].RxMsgBufType;
				if((Can_ConfigPtr->CanActiveCtrPtr[rxHwObjControlId].CanRxProcessing == CAN_POLLING)
#if(CAN_MIXED_MODE_ENABLE == STD_ON)
					||((Can_ConfigPtr->CanActiveCtrPtr[rxHwObjControlId].CanRxProcessing == CAN_MIXED) &&
						(Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].ObjectPollingEnabled == TRUE))
#endif
					)
				{
					if((CAN_RxFIFO0 == rxHwObjBufferType) || (CAN_RxFIFO1 == rxHwObjBufferType))
					{
#ifdef CAN_PLT_SAFERTOS_ENABLE
						Can_Drv_ProcessRxFIFO(mailBox,rxHwObjBufferType,FALSE);
#else
						Can_Drv_ProcessRxFIFO(mailBox,rxHwObjBufferType);
#endif
					}
					else
					{
						Can_Drv_RxProcessBuffer(mailBox,rxHwObjBufferIndex);
					}
				}
			}
		}
    }
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#else
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_MainFunction_Read_Period
Service ID (hex).. : 0x08
Sync/Async........ : NA
Reentrancy........ : NA
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function performs the polling of RX indications when
                     CAN_RX_PROCESSING is set to POLLING or MIXED.
Design IDs Covered :
*******************************************************************************/
void Can_MainFunction_Read_Period(uint8 PeriodId)
{
#if (CAN_MAIN_READ_FUNC_ENABLE == STD_ON)
    uint8 rxHwObjBufferIndex;
    uint16 rxHwObjIndex;
    CAN_CtrIdType rxHwObjControlId;
    Can_HwType mailBox = {.ControllerId = 0, .Hoh = 0};
    Can_RxBufferType rxHwObjBufferType;
	if( CanHWUnitState != CAN_HW_UNINIT ) {
		for(rxHwObjIndex=0;rxHwObjIndex< (Can_ConfigPtr->CanNumOfRxHwObj); rxHwObjIndex++)
		{
			rxHwObjControlId = Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].HwRxObjectCtrlrId;
#if(CAN_FUSA_ENABLE == STD_ON)
			if(CanFusa_Cntrl_In_SafeState(rxHwObjControlId) == (uint8)TRUE)
			{
				continue;
			}
			else
#endif
			{
				mailBox.ControllerId = rxHwObjControlId;
				mailBox.Hoh = Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].HwRxObjectId;
				rxHwObjBufferIndex = Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].RxBufferIndex;
				rxHwObjBufferType = Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].RxMsgBufType;
				if(((Can_ConfigPtr->CanActiveCtrPtr[rxHwObjControlId].CanRxProcessing == CAN_POLLING)
#if(CAN_MIXED_MODE_ENABLE == STD_ON)
					||((Can_ConfigPtr->CanActiveCtrPtr[rxHwObjControlId].CanRxProcessing == CAN_MIXED) &&
						(Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].ObjectPollingEnabled == TRUE))
#endif
					)
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
					&& (Can_ConfigPtr->CanRxHwObjPtr[rxHwObjIndex].RxPeriodId == PeriodId)
#endif
					)
				{
					if((CAN_RxFIFO0 == rxHwObjBufferType) || (CAN_RxFIFO1 == rxHwObjBufferType))
					{
#ifdef CAN_PLT_SAFERTOS_ENABLE
						Can_Drv_ProcessRxFIFO(mailBox,rxHwObjBufferType,FALSE);
#else
						Can_Drv_ProcessRxFIFO(mailBox,rxHwObjBufferType);
#endif
					}
					else
					{
						Can_Drv_RxProcessBuffer(mailBox,rxHwObjBufferIndex);
					}
				}
			}
		}
	}
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_MainFunction_BusOff
Service ID (hex).. : 0x09
Sync/Async........ : NA
Reentrancy........ : NA
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function performs the polling of bus-off events that
                     are configured statically as 'to be polled'.
Design IDs Covered :
*******************************************************************************/
void Can_MainFunction_BusOff(void)
{
#if(CAN_MAIN_BUSOFF_FUNC_ENABLE ==STD_ON)
    uint8 ctrlIndex;
	if( CanHWUnitState != CAN_HW_UNINIT ) {
		for(ctrlIndex=0u; ctrlIndex < NUMBER_OF_ACTIVE_CAN_CTRL ;ctrlIndex++)
		{
			/*Check if CanBusoffProcessing Mode is polling */
			if(Can_ConfigPtr->CanActiveCtrPtr[ctrlIndex].CanBusoffProcessing == CAN_POLLING)
			{
				Can_Drv_ProcessBusoff(ctrlIndex);
			}
			else
			{
				/* Do nothing */
			}
		}
	}
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_MainFunction_Wakeup
Service ID (hex).. : 0x0a
Sync/Async........ : NA
Reentrancy........ : NA
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function performs the polling of wake-up events that are configured statically
                     as 'to be polled.
Design IDs Covered :
*******************************************************************************/
void Can_MainFunction_Wakeup (void)
{
#if (CAN_MAIN_WAKEUP_FUNC_ENABLE == STD_ON)
    /*Keeping as Dummy as the CAN Controller doesn't have wake-up capability*/
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_CheckWakeup
Service ID (hex).. : 0x0b
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant
Parameters (IN)... : Controller
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : This function checks if a wakeup has occurred for
                     the given controller.
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_CheckWakeup (uint8 Controller)
{
    Std_ReturnType retValue = E_OK;
    Can_ApiId = CAN_SID_CHECKWAKEUP;
    /* Check if CAN driver is initialized */
    if(Can_ReportDetUninit(Can_ApiId) != E_OK)
    {
        retValue = E_NOT_OK;
    }
    /* Check if Controller is valid */
    else if(Can_ReportDetParamController(Controller, Can_ApiId) != E_OK)
    {
        retValue = E_NOT_OK;
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    else if(CanFusa_Cntrl_In_SafeState(Controller) == TRUE)
    {
        retValue = E_NOT_OK;            
    }
#endif
    else
    {
        /*Keeping as Dummy as the CAN Controller doesn't have wake-up capability*/
    }
    return(retValue);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_MainFunction_Mode
Service ID (hex).. : 0x0c
Sync/Async........ : NA
Reentrancy........ : NA
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function performs the polling of CAN controller mode
                     transitions.
Design IDs Covered :
*******************************************************************************/
void Can_MainFunction_Mode(void)
{
    uint8 ctrlIndex = 0;
    Std_ReturnType retVal = E_OK;
    Can_ControllerStateType currentCtrlState;
    Can_ControllerStateType requestedCtrlState;
    Can_ApiId = CAN_SID_MAINFUNCTION_MODE;
    Std_ReturnType status;
    /* Check if CAN driver is initialized */
    status = Can_ReportDetUninit(Can_ApiId);
    if(status != E_NOT_OK)
    {
        for(ctrlIndex=0;ctrlIndex< NUMBER_OF_ACTIVE_CAN_CTRL; ctrlIndex++)
        {
          currentCtrlState = Can_CtrlInfo[ctrlIndex].CanCtrlState;
          requestedCtrlState = Can_CtrlInfo[ctrlIndex].CanCtrlRequestedState;
          if(currentCtrlState != requestedCtrlState)
          {
            retVal = Can_Drv_PollModeTransition(ctrlIndex,requestedCtrlState);
            if(retVal!= E_NOT_OK)
            {
                Can_Drv_CtrlModeIndication(ctrlIndex,requestedCtrlState);
            }
#if(CAN_FUSA_ENABLE == STD_ON)
            else
            {
                CanFusa_Validate_ModeCheckCnt(ctrlIndex);
            }
#endif
          }
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_DeInit
Service ID (hex).. : 0x10
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This function de-initializes the module
Design IDs Covered :
*******************************************************************************/
void Can_DeInit(void)
{
    uint8 ctrlIndex;
    Std_ReturnType status = E_OK;
    Can_ApiId = CAN_SID_DEINIT;
    /* Check if CAN driver is initialized */
    if(CanHWUnitState != CAN_HW_READY)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, Can_ApiId,
                                                        CAN_E_TRANSITION);
#endif
        status=E_NOT_OK;
    }
    else
    {
        for(ctrlIndex=(uint8) 0;ctrlIndex < NUMBER_OF_ACTIVE_CAN_CTRL;ctrlIndex++)
        {
            if (Can_CtrlInfo[ctrlIndex].CanCtrlState== CAN_CS_STARTED )
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
                                           Can_ApiId,CAN_E_TRANSITION);
#endif
                status = E_NOT_OK;
                break;
            }
#if(CAN_FUSA_ENABLE == STD_ON)
            if(CanFusa_Cntrl_In_SafeState(ctrlIndex) == (uint8) TRUE)
            {
                status = E_NOT_OK;
                break;
            }
#endif
        }
    }

    if(status==E_OK)
    {
        CanHWUnitState = CAN_HW_UNINIT;
        for(ctrlIndex=(uint8) 0;ctrlIndex < NUMBER_OF_ACTIVE_CAN_CTRL;ctrlIndex++)
        {
            {
                Can_Drv_SetControllerMode(ctrlIndex,CAN_CS_UNINIT);
                Can_CtrlInfo[ctrlIndex].CanCtrlRequestedState = CAN_CS_UNINIT;
                Can_CtrlInfo[ctrlIndex].CanCtrlState = CAN_CS_UNINIT;
                Can_InterruptDisableCount[ctrlIndex] = CANSS_ZERO;
            }
        }
#if(CAN_FUSA_ENABLE == STD_ON)
		status = CanFusa_Fusa_DeInit();
		if(status != E_OK){
#if (CAN_DEV_ERROR_DETECT == STD_ON)
			(void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_DEINIT,
															CAN_E_FUSA_DEINIT_FAILED);
#endif
			(void) CanFusa_Set_CanDrv_SafeState(CAN_SID_DEINIT);
		}
#endif
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_GetControllerErrorState
Service ID (hex).. : 0x11
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant for the same ControllerId
Parameters (IN)... : ControllerId
Parameters (INOUT) : None
Parameters (OUT).. : ErrorStatePtr
Return Value...... : Std_ReturnType
Description....... : This service reports about the current status of the requested CAN controller
Design IDs Covered : This service obtains the error state of the CAN controller
*******************************************************************************/
Std_ReturnType Can_GetControllerErrorState(uint8 ControllerId,
                                                 Can_ErrorStateType* ErrorStatePtr)
 {
    Std_ReturnType retVal = E_OK;
    Can_ApiId = CAN_SID_GETCONTROLLERERRORSTATE;
    /* Check if CAN driver is initialized */
    if(Can_ReportDetUninit(Can_ApiId) != E_OK)
    {
        retVal = E_NOT_OK;
    }
    /* Check if Controller is valid */
    else if(Can_ReportDetParamController(ControllerId,Can_ApiId) !=E_OK)
    {
           retVal = E_NOT_OK;
    }
    /* Check if ErrorStatePtr is a null pointer */
    else if(ErrorStatePtr == NULL_PTR)
    {
        retVal = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, Can_ApiId,CAN_E_PARAM_POINTER);
#endif
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    else if (CanFusa_Cntrl_In_SafeState(ControllerId) == (uint8) TRUE)
    {
        retVal = E_NOT_OK;
    }
#endif
    else
    {
        Can_Drv_ReadErrorState(ControllerId,ErrorStatePtr);
    }
    return retVal;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_GetControllerMode
Service ID (hex).. : 0x12
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant
Parameters (IN)... : Controller
Parameters (INOUT) : None
Parameters (OUT).. : ControllerModePtr
Return Value...... : Std_ReturnType
Description....... : This service reports about the current status of the requested CAN controller
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_GetControllerMode(uint8 Controller,
                                       Can_ControllerStateType* ControllerModePtr)
 {
    Std_ReturnType retVal = E_OK;
    Can_ApiId = CAN_SID_GETCONTROLLERMODE;
    /* Check if CAN driver is initialized */
    if(Can_ReportDetUninit(Can_ApiId) != E_OK )
    {
        retVal=E_NOT_OK;
    }
    /* Check if Controller is valid */
    else if(Can_ReportDetParamController(Controller,Can_ApiId) != E_OK)
    {
           retVal=E_NOT_OK;
    }
    /* Check if ControllerModePtr is a null pointer */
    else if(ControllerModePtr == NULL_PTR)
    {
        retVal = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, Can_ApiId,CAN_E_PARAM_POINTER);
#endif
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    else if (CanFusa_Cntrl_In_SafeState(Controller) == (uint8) TRUE)
    {
        retVal = E_NOT_OK;
    }
#endif
    else
    {
        *ControllerModePtr = Can_CtrlInfo[Controller].CanCtrlState;
    }
    return retVal;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_GetControllerRxErrorCounter
Service ID (hex).. : 0x30
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant for the same ControllerId
Parameters (IN)... : ControllerId
Parameters (INOUT) : None
Parameters (OUT).. : RxErrorCounterPtr
Return Value...... : Std_ReturnType
Description....... : Returns the Rx error counter for a CAN controller
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_GetControllerRxErrorCounter(uint8 ControllerId,
                                                 uint8* RxErrorCounterPtr)
 {
    Std_ReturnType retVal = E_OK;
    Can_ApiId = CAN_SID_GETCONTROLLERRXERRORCOUNTER;
    /* Check if CAN driver is initialized */
    if(Can_ReportDetUninit(Can_ApiId) != E_OK)
    {
        retVal = E_NOT_OK;
    }
    /* Check if Controller is valid */
    else if(Can_ReportDetParamController(ControllerId,Can_ApiId) != E_OK)
    {
        retVal = E_NOT_OK;
    }
    /* Check if RxErrorCounterPtr is a null pointer */
    else if(RxErrorCounterPtr == NULL_PTR)
    {
        retVal = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, Can_ApiId,CAN_E_PARAM_POINTER);
#endif
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    else if (CanFusa_Cntrl_In_SafeState(ControllerId) == (uint8) TRUE)
    {
        retVal = E_NOT_OK;
    }
#endif
    else
    {
        Can_Drv_ReadRxErrorCounter(ControllerId,RxErrorCounterPtr);
    }
    return retVal;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_GetControllerTxErrorCounter
Service ID (hex).. : 0x31
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant for the same ControllerId
Parameters (IN)... : ControllerId
Parameters (INOUT) : None
Parameters (OUT).. : TxErrorCounterPtr
Return Value...... : Std_ReturnType
Description....... : Returns the Tx error counter for a CAN controller
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_GetControllerTxErrorCounter(uint8 ControllerId,
                                                 uint8* TxErrorCounterPtr)
 {
    Std_ReturnType retVal = E_OK;
    Can_ApiId = CAN_SID_GETCONTROLLERTXERRORCOUNTER;
    /* Check if CAN driver is initialized */
    if(Can_ReportDetUninit(Can_ApiId) != E_OK)
    {
        retVal = E_NOT_OK;
    }
    /* Check if Controller is valid */
    else if(Can_ReportDetParamController(ControllerId,Can_ApiId) != E_OK)
    {
           retVal = E_NOT_OK;
    }
    /* Check if TxErrorCounterPtr is a null pointer */
    else if(TxErrorCounterPtr == NULL_PTR)
    {
        retVal = E_NOT_OK;
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, Can_ApiId,CAN_E_PARAM_POINTER);
#endif
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    else if (CanFusa_Cntrl_In_SafeState(ControllerId) == (uint8) TRUE)
    {
        retVal = E_NOT_OK;
    }
#endif
    else
    {
        Can_Drv_ReadTxErrorCounter(ControllerId,TxErrorCounterPtr);
    }
    return retVal;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Internal Function
Service ID (hex).. : None
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : ServiceId - Service Id of the calling API
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : Checks the status of CAN driver initialization, If CAN
                     driver is not initialized, reports to DET.
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_ReportDetUninit (uint8 ServiceId)
{
    Std_ReturnType retVal;
    retVal = E_OK;
    /* Check if CAN driver is un-initialized */
    if(CAN_HW_UNINIT == CanHWUnitState)
    {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, ServiceId,
                                                                CAN_E_UNINIT);
#endif
        retVal = E_NOT_OK;
    }
    return(retVal);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Internal Function
Service ID (hex).. : None
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : ControllerId - CAN Controller Id, ServiceId - Service Id
                     of the calling API
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : Checks if ControllerId is valid or not, If ControllerId is
                     not valid, then report to DET.
Design IDs Covered :
*******************************************************************************/
static inline Std_ReturnType Can_ReportDetParamController
                                    (uint8 ControllerId,
                                        uint8 ServiceId)
{
    Std_ReturnType retVal;
    /* 'ControllerId' is out of range */
    if(ControllerId < NUMBER_OF_ACTIVE_CAN_CTRL)
    {
        retVal = E_OK;
    }
    else
    {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, ServiceId,
                                                CAN_E_PARAM_CONTROLLER);
#endif
        retVal = E_NOT_OK ;
    }
    return(retVal);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Internal Function
Service ID (hex).. : None
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : Hth, PduInfo
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : Checks DET Handles for Can_Write API
Design IDs Covered :
*******************************************************************************/
static inline Std_ReturnType Can_WriteDetCheck(
                        Can_HwHandleType Hth,
                        const Can_PduType* PduInfo)
{
    Std_ReturnType retVal;
    Can_HwObjType  objType;
    uint8 txobjIndex ;
    uint8 CtrlId ;
    retVal = E_OK;
    if(Hth >= CAN_MAX_HOH_CONFIGURED ){
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_WRITE,
                                                        CAN_E_PARAM_HANDLE);
#endif
        retVal = E_NOT_OK;
    }
    if(E_OK == retVal){
        objType = Can_ConfigPtr->CanTxRxObjMapPtr[Hth].ObjType;
        txobjIndex = Can_ConfigPtr->CanTxRxObjMapPtr[Hth].ObjIndex;
        CtrlId = Can_ConfigPtr -> CanTxHwObjPtr[txobjIndex].HwTxObjectCtrlrId;
        /* Check if 'Hth' is a valid transmit handle */
        if(objType != CAN_TXOBJ)
        {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_WRITE,
                                                CAN_E_PARAM_HANDLE);
#endif
            retVal = E_NOT_OK;
        }
        /* Check if PduInfo is a null pointer */
        else if (PduInfo == NULL_PTR)
        {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_WRITE,
                                                            CAN_E_PARAM_POINTER);
#endif
            retVal = E_NOT_OK;
        }
#if (CAN_FD_OPERATION_ENABLED == STD_OFF)
        /* check if DLC is greater than 8 */
        else if (PduInfo->length > CAN_PAYLOAD_MAX_BYTES)
        {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_WRITE,
                                                    CAN_E_PARAM_DATA_LENGTH);
#endif
            retVal = E_NOT_OK;
        }
#endif
#if (CAN_FD_OPERATION_ENABLED == STD_ON)
        else if ((PduInfo->length > CAN_PAYLOAD_MAX_BYTES) &&
                (Can_ConfigPtr->CanActiveCtrPtr[CtrlId].CanFDModeEnabled == FALSE))
        {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_WRITE,
                                            CAN_E_PARAM_DATA_LENGTH);
#endif
            retVal = E_NOT_OK;
        }
        else if (PduInfo->length > CAN_FD_PAYLOAD_MAX_BYTES)
        {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_WRITE,
                                            CAN_E_PARAM_DATA_LENGTH);
#endif
            retVal = E_NOT_OK;
        }
        else if (PduInfo->length > (Can_ConfigPtr -> CanTxHwObjPtr[txobjIndex].TxPayloadLength))
        {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_WRITE,
                                            CAN_E_PARAM_DATA_LENGTH);
#endif
            retVal = E_NOT_OK;
        }
        else if ((PduInfo->length > CAN_PAYLOAD_MAX_BYTES) &&
                    ((PduInfo->id & CAN_FRAME_TYPE_MASK) == CAN_ZERO))
        {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_WRITE,
                                            CAN_E_PARAM_DATA_LENGTH);
#endif
            retVal = E_NOT_OK;
        }
#endif
        /* Check if sdu is a null pointer */
        else if ((PduInfo->sdu == NULL_PTR) &&
          (Can_ConfigPtr->CanTxHwObjPtr[txobjIndex].TriggerTxEnable == FALSE))
        {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_WRITE,
                                                            CAN_E_PARAM_POINTER);
#endif
            retVal = E_NOT_OK;
        }
        else
        {
            /* Nothing to do */
        }
    }
    return(retVal);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Internal Function
Service ID (hex).. : None
Sync/Async........ : Synchronous
Reentrancy........ : Reentrant
Parameters (IN)... : Hth, PduInfo
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : Checks DET Handles for Can_SetControllerMode API
Design IDs Covered :
*******************************************************************************/
static inline Std_ReturnType Can_SetControllerModeDetCheck(uint8
                Controller, Can_ControllerStateType Transition)
{
    Std_ReturnType retValue;
    /*Raise Det error if invalid transition requested */
    if((Transition == CAN_CS_STARTED) && (Can_CtrlInfo[Controller].CanCtrlState != CAN_CS_STOPPED))
    {
        retValue = E_NOT_OK ;
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,CAN_SID_SETCONTROLLERMODE,CAN_E_TRANSITION);
#endif
    }
    else if((Transition == CAN_CS_STOPPED) && (Can_CtrlInfo[Controller].CanCtrlState != CAN_CS_STARTED) &&
                (Can_CtrlInfo[Controller].CanCtrlState != CAN_CS_SLEEP) && (Can_CtrlInfo[Controller].CanCtrlState != CAN_CS_STOPPED))
    {
        retValue = E_NOT_OK ;
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,CAN_SID_SETCONTROLLERMODE,CAN_E_TRANSITION);
#endif
    }
    else if((Transition == CAN_CS_SLEEP) && (Can_CtrlInfo[Controller].CanCtrlState != CAN_CS_SLEEP) &&
                   (Can_CtrlInfo[Controller].CanCtrlState != CAN_CS_STOPPED))
    {
        retValue = E_NOT_OK ;
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,CAN_SID_SETCONTROLLERMODE,CAN_E_TRANSITION);
#endif
    }
	else if( Transition != CAN_CS_STARTED  && Transition != CAN_CS_STOPPED && Transition != CAN_CS_SLEEP){
		retValue = E_NOT_OK ;
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,CAN_SID_SETCONTROLLERMODE,CAN_E_TRANSITION);
#endif
	}
    else
    {
        retValue = E_OK;
    }
    return retValue;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_GetCurrentTime
Service ID (hex).. : 0x32
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant
Parameters (IN)... : ControllerId
Parameters (INOUT) : None
Parameters (OUT).. : timeStampPtr
Return Value...... : E_OK, E_NOT_OK
Description....... : Returns a time value out of the HW registers according to
                     the capability of the HW
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_GetCurrentTime (
    uint8 ControllerId,
    Can_TimeStampType* timeStampPtr
){
    Std_ReturnType status = E_OK;
    Can_ApiId = CAN_SID_GETCURRENTTIME;
    /* Check if CAN driver is initialized */
    if(E_NOT_OK == Can_ReportDetUninit(Can_ApiId)){
        status = E_NOT_OK;
    }
    /* Check if Controller is valid */
    else if(E_NOT_OK == Can_ReportDetParamController(ControllerId, Can_ApiId)){
        status = E_NOT_OK;
    }
    /* Check if timeStampPtr is a null pointer */
    else if(NULL_PTR == timeStampPtr){
        status = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, Can_ApiId,CAN_E_PARAM_POINTER);
#endif
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    else if (CanFusa_Cntrl_In_SafeState(ControllerId) == (uint8)TRUE)
    {
        status = E_NOT_OK;
    }
#endif
    else
    {
        status = Can_Drv_GetCurrentTime(ControllerId, timeStampPtr);
    }
    return status;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_EnableEgressTimeStamp
Service ID (hex).. : 0x33
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant
Parameters (IN)... : Hth
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : Activates egress time stamping on a dedicated HTH.
Design IDs Covered :
*******************************************************************************/
void Can_EnableEgressTimeStamp (
    Can_HwHandleType Hth
){
    uint8 txObjId;
#if(CAN_FUSA_ENABLE == STD_ON)
    uint8 ControllerId;
#endif
    /* Check if CAN driver is initialized */
    if(CAN_HW_UNINIT == CanHWUnitState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_ENABLEEGRESSTIMESTAMP,
                                                 CAN_E_UNINIT);
#endif
    }
    /*check if Hth is valid */
    else if((Hth >= CAN_MAX_HOH_CONFIGURED) ||
        (Can_ConfigPtr->CanTxRxObjMapPtr[Hth].ObjType != CAN_TXOBJ)){
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_ENABLEEGRESSTIMESTAMP,
                        CAN_E_PARAM_HANDLE);
#endif
    }
    else
    {
        txObjId = Can_ConfigPtr->CanTxRxObjMapPtr[Hth].ObjIndex;
#if(CAN_FUSA_ENABLE == STD_ON)
        ControllerId = Can_ConfigPtr->CanTxHwObjPtr[txObjId].HwTxObjectCtrlrId;
        if (CanFusa_Cntrl_In_SafeState(ControllerId) != (uint8)TRUE)
#endif
        {
            Can_Drv_EnableEgressTimeStamp(txObjId);
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_GetEgressTimeStamp
Service ID (hex).. : 0x34
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant for the same TxPduId.
Parameters (IN)... : TxPduId, Hth
Parameters (INOUT) : None
Parameters (OUT).. : timeStampPtr
Return Value...... : E_OK, E_NOT_OK
Description....... : Reads back the egress time stamp on a dedicated message
                     object. It needs to be called within the TxConfirmation()
                     function.
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_GetEgressTimeStamp (
    PduIdType TxPduId,
    Can_HwHandleType Hth,
    Can_TimeStampType* timeStampPtr
){
    Std_ReturnType status = E_OK;
    Can_ApiId = CAN_SID_GETEGRESSTIMESTAMP;
    /* Check if CAN driver is initialized */
    if(E_NOT_OK == Can_ReportDetUninit(Can_ApiId)){
        status = E_NOT_OK;
    }
    /*check if Hth is valid */
    else if((Hth >= CAN_MAX_HOH_CONFIGURED) ||
        (Can_ConfigPtr->CanTxRxObjMapPtr[Hth].ObjType != CAN_TXOBJ)){
        /* Report to DET */
        status = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_GETEGRESSTIMESTAMP,
                        CAN_E_PARAM_HANDLE);
#endif
    }
    else if(NULL_PTR == timeStampPtr){
        /* Report to DET */
        status = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_GETEGRESSTIMESTAMP,
                        CAN_E_PARAM_POINTER);
#endif
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    else{
        uint8 txObjId = Can_ConfigPtr->CanTxRxObjMapPtr[Hth].ObjIndex;
        uint8 ControllerId = Can_ConfigPtr->CanTxHwObjPtr[txObjId].HwTxObjectCtrlrId;
        
        if (CanFusa_Cntrl_In_SafeState(ControllerId) == (uint8)TRUE)
        {
            status = E_NOT_OK;
        }
#endif
    else
    {
        status = Can_Drv_GetEgressTimeStamp( TxPduId, Hth, timeStampPtr);
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    }
#endif
    return status;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#if (CAN_GLOBAL_TIME_SUPPORT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*******************************************************************************
Service Name...... : Can_GetIngressTimeStamp
Service ID (hex).. : 0x34
Sync/Async........ : Synchronous
Reentrancy........ : Non Reentrant for the same TxPduId.
Parameters (IN)... : Hrh
Parameters (INOUT) : None
Parameters (OUT).. : timeStampPtr
Return Value...... : E_OK, E_NOT_OK
Description....... : Reads back the ingress time stamp on a dedicated message
                     object. It needs to be called within the RxIndication()
                     function.
Design IDs Covered :
*******************************************************************************/
Std_ReturnType Can_GetIngressTimeStamp (
    Can_HwHandleType Hrh,
    Can_TimeStampType* timeStampPtr
){
    Std_ReturnType status = E_OK;
    Can_ApiId = CAN_SID_GETINGRESSTIMESTAMP;
    /* Check if CAN driver is initialized */
    if(E_NOT_OK == Can_ReportDetUninit(Can_ApiId)){
        status = E_NOT_OK;
    }
    /*check if Hrh is valid */
    else if((Hrh >= CAN_MAX_HOH_CONFIGURED) ||
        (Can_ConfigPtr->CanTxRxObjMapPtr[Hrh].ObjType != CAN_RXOBJ)){
        /* Report to DET */
        status = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_GETINGRESSTIMESTAMP,
                        CAN_E_PARAM_HANDLE);
#endif
    }
    else if(NULL_PTR == timeStampPtr){
        /* Report to DET */
        status = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_GETINGRESSTIMESTAMP,
                        CAN_E_PARAM_POINTER);
#endif
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    else{
        uint8 rxObjID = Can_ConfigPtr->CanTxRxObjMapPtr[Hrh].ObjIndex;
        uint8 controllerId = Can_ConfigPtr->CanRxHwObjPtr[rxObjID].HwRxObjectCtrlrId;
        if (CanFusa_Cntrl_In_SafeState(controllerId) == (uint8)TRUE)
        {
            status = E_NOT_OK;
        }
#endif
    else
    {
        status = Can_Drv_GetIngressTimeStamp(Hrh, timeStampPtr);
    }
#if(CAN_FUSA_ENABLE == STD_ON)
    }
#endif
    return status;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#ifdef __cplusplus
}
#endif
/*==============================================================================
==============================================================================*/
