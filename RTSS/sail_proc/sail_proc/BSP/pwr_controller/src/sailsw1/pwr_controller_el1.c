
/*
===========================================================================
*/
/**
    @file  pwr_controller_el1.c
    @brief Implementation of Power Controller Shim layer driver in EL1

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/src/sailsw1/pwr_controller_el1.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "pwr_controller_el1.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "err_fatal.h"

/* Status of the Power controller EL1 driver */
typedef enum
{
   PC_MODE_ACTIVE,               /* Active mode */
   PC_MODE_STANDBY_SET,          /* Standby mode */
   PC_MODE_SLEEP_SET             /* Sleep mode */
}PCSleepEL1StatusType_e;


static boolean bPCInitEL1Done =  FALSE;
static PCSleepEL1StatusType_e xPCSleepEL1Status = PC_MODE_ACTIVE;

/**********************************************************
 * Initalizes the Power controller driver in EL1
 *
 *
 * @param type [IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PWR_CONTROLLER_FUNC PCStatusType_e   xPCinitEL1(void)
{
    uint32_t hvc_id;
    uint32_t param_id;
    boolean retval;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    /* If the PC driver is already initialized then return success */
    if (TRUE == bPCInitEL1Done)
    {
        if (PC_MODE_ACTIVE != xPCSleepEL1Status)
        {
            xPCSleepEL1Status = PC_MODE_ACTIVE;
        }
        return PC_STATUS_SUCCESS;
    }

    /* Check if the EL2 PC driver is initialized and ready for accepting sleep */

    /* Construct the HVC call parameters */
    hvc_id=SAIL_PC_IS_CORE_INITIALIZED;
    param_id=SAIL_PC_IS_CORE_INITIALIZED_PARAM_ID;

#ifdef ENB_TRAP_CALL
    /* Make HVC call */
    if(HVC_SUCCESS != hvc_call(&hvc_id, &param_id, &arg1, &arg2, &arg3, &arg4))
	{
		err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
	}
	retval = (boolean)param_id;
#else
    retval =  (boolean)xPCTrapIsCoreInitialized();
#endif /* ENB_TRAP_CALL */

    if (FALSE == retval)
    {
        return PC_STATUS_FAIL;
    }

    xPCSleepEL1Status = PC_MODE_ACTIVE;

    bPCInitEL1Done = TRUE;

    return PC_STATUS_SUCCESS;
}

/**********************************************************
 * Configures the Wake IRQ in the Power controller
 *
 *
 * @param type [IN]
 *   Masks containing the IRQs that should be masked in the Power Controller
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PWR_CONTROLLER_FUNC PCStatusType_e   xPCConfigureWakeIRQEL1(uint64_t ullWakeIRQMask)
{
    uint32_t hvc_id;
    uint32_t param_id;
    PCStatusType_e eStatus;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if (FALSE == bPCInitEL1Done)
    {
        return PC_STATUS_FAIL;
    }

    /* Cannot have all IRQs unmasked or all IRQs masked */
    if ((ullWakeIRQMask == 0) || (ullWakeIRQMask == ~0))
    {
        return PC_STATUS_FAIL;
    }

    /* Construct the HVC call parameters */
    hvc_id=SAIL_PC_CONFIGURE_WAKEIRQ;
    param_id=SAIL_PC_CONFIGURE_WAKEIRQ_PARAM_ID;
    arg1 = (uint32_t)&ullWakeIRQMask;

#ifdef ENB_TRAP_CALL
    /* Make HVC call */
    if(HVC_SUCCESS != hvc_call(&hvc_id, &param_id,  &arg1, &arg2, &arg3, &arg4))
	{
		err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
	}
	eStatus = (PCStatusType_e)param_id;
#else
    eStatus = (PCStatusType_e)xPCTrapConfigureWakeIRQ((void *)arg1);
#endif /* ENB_TRAP_CALL */

    return eStatus;
}

/**********************************************************
 * Sleep Entry for Power Controller
 *
 *
 * @param type [IN]
 *   Sleep type to be configured in the Power controller Hardware
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PWR_CONTROLLER_FUNC PCStatusType_e   xPCSleepEnterEL1(PCSleepModeType_e eMode)
{
    uint32_t hvc_id;
    uint32_t param_id;
    PCStatusType_e eStatus;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if (FALSE == bPCInitEL1Done)
    {
        return PC_STATUS_FAIL;
    }

    if ( (eMode < PC_MODE_STANDBY) || (eMode > PC_MODE_DEEPSLEEP) )
    {
        return PC_STATUS_FAIL;
    }

    /* Construct the HVC call parameters */
    hvc_id=SAIL_PC_SLEEP_ENTER;
    param_id=SAIL_PC_SLEEP_ENTER_PARAM_ID;
    arg1 = (uint32_t)eMode;

#ifdef ENB_TRAP_CALL
    /* Make HVC call */
    if(HVC_SUCCESS != hvc_call(&hvc_id, &param_id,  &arg1, &arg2, &arg3, &arg4))
	{
		err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
	}
	eStatus = (PCStatusType_e)param_id;
#else
    eStatus = (PCStatusType_e)xPCTrapSleepEnter((PCSleepModeType_e)arg1);
#endif /* ENB_TRAP_CALL */

    if (PC_STATUS_SUCCESS == eStatus)
    {
        xPCSleepEL1Status = (PCSleepEL1StatusType_e)eMode;
    }

    return eStatus;
}

/**********************************************************
 * Controls the Power Controller Sequencer Enable
 *
 *
 * @param type [IN]
 *   Control for the Power controller Sequencer
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PWR_CONTROLLER_FUNC PCStatusType_e   xPCSequencerEnableCtrlEL1(boolean ucCtrl)
{
    uint32_t hvc_id;
    uint32_t param_id;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    PCStatusType_e eStatus;

    if (FALSE == bPCInitEL1Done)
    {
        return PC_STATUS_FAIL;
    }

    /* Sequencer Control in EL1 can only allow entry to Sleep */
    if (FALSE == ucCtrl)
    {
        return PC_STATUS_FAIL;
    }

    /* Sequencer cannot be triggered while sleep status is Active */
    if ((xPCSleepEL1Status < PC_MODE_STANDBY_SET) || (xPCSleepEL1Status > PC_MODE_SLEEP_SET) )
    {
        return PC_STATUS_FAIL;
    }

    /* Construct the HVC call parameters */
    hvc_id=SAIL_PC_SEQUENCER_EN_CTRL;
    param_id=SAIL_PC_SEQUENCER_EN_CTRL_PARAM_ID;
    arg1 = (uint32_t)ucCtrl;

#ifdef ENB_TRAP_CALL
    /* Make HVC call */
    if(HVC_SUCCESS != hvc_call(&hvc_id, &param_id,  &arg1, &arg2, &arg3, &arg4))
	{
		err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
	}
	eStatus = (PCStatusType_e)param_id;
#else
    eStatus = (PCStatusType_e)xPCTrapSequencerEnableCtrl((boolean)arg1);
#endif /* ENB_TRAP_CALL */

    return eStatus;
}

/**********************************************************
 * Controls the Power Controller Glitch Source and APM Comparator Enable
 *
 *
 * @param type [IN]
 *   Control for the Power controller Glitch Source and APM Comparator
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PWR_CONTROLLER_FUNC PCStatusType_e   xPCCtrlGlitchSrcEL1(boolean bCtrl)
{
    uint32_t hvc_id;
    uint32_t param_id;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    PCStatusType_e eStatus;

    if (FALSE == bPCInitEL1Done)
    {
        return PC_STATUS_FAIL;
    }

    /* Construct the HVC call parameters */
    hvc_id=SAIL_PC_GLITCH_SRC_CTRL;
    param_id=SAIL_PC_GLITCH_SRC_CTRL_PARAM_ID;
    arg1 = (uint32_t)bCtrl;

#ifdef ENB_TRAP_CALL
    /* Make HVC call */
    if(HVC_SUCCESS != hvc_call(&hvc_id, &param_id,  &arg1, &arg2, &arg3, &arg4))
	{
		err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
	}
	eStatus = (PCStatusType_e)param_id;
#else
    eStatus = (PCStatusType_e)xPCTrapCtrlGlitchSrc((boolean)arg1);
#endif /* ENB_TRAP_CALL */

    return eStatus;
}

/**********************************************************
 * Populates the wake up reason
 *
 *
 * @param type [IN/OUT]
 *   Pointer to Reason mask as input parameter
 *   Mask that provides the reason for the wakeup upon return
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PWR_CONTROLLER_FUNC PCStatusType_e   xPCPopulateWakeupReasonEL1(uint64_t *puReasonMask)
{
    uint32_t hvc_id;
    uint32_t param_id;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    PCStatusType_e eStatus;

    if (FALSE == bPCInitEL1Done)
    {
        return PC_STATUS_FAIL;
    }

    /* Construct the HVC call parameters */
    hvc_id=SAIL_PC_POPULATE_WAKEUP_REASON;
    param_id=SAIL_PC_POPULATE_WAKEUP_REASON_PARAM_ID;
    arg1 = (uint32_t)puReasonMask;

#ifdef ENB_TRAP_CALL
    /* Make HVC call */
    if(HVC_SUCCESS != hvc_call(&hvc_id, &param_id,  &arg1, &arg2, &arg3, &arg4))
	{
		err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
	}
	eStatus = (PCStatusType_e)param_id;
#else
    eStatus = (PCStatusType_e)xPCTrapPopulateWakeupReason((void *)arg1);
#endif /* ENB_TRAP_CALL */

    return eStatus;
}

