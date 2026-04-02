/*
===========================================================================
*/
/**
    @file  pwr_controller_trap.c
    @brief Implementation of Power Controller EL2 Trap services

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/src/sailhyp/pwr_controller_trap.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


#include "pwr_controller_cmn.h"
#include "pwr_controller_core.h"
#include "pwr_controller_trap.h"
#include "syscall.h"
#include "syscall_pub.h"

static boolean gPCTrapInitDone = FALSE;

/**********************************************************
 * Initialize Power Controller EL2 Trap layer
 *
 *
 * @param type void[IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCTrapInitEL2(void)
{
    gPCTrapInitDone = TRUE;

    return PC_SUCCESS;
}

/**********************************************************
 * De-initialize Power Controller EL2 Trap layer
 *
 * @param void[IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation
 *
 **********************************************************/
PCCoreStatusType_e xPCTrapDeInitEL2(void)
{
    gPCTrapInitDone = FALSE;
    return PC_SUCCESS;
}



/**********************************************************
 * Checks if EL2 Driver is initialized and ready for accepting sleep
 *
 * @param void[IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation
 *
 **********************************************************/
uint32 xPCTrapIsCoreInitialized(sailbsp_hvc_rsp_t *rsp)
{
    if (FALSE == gPCTrapInitDone)
    {
        rsp->data[0] = FALSE;
		return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)bPCCoreIsReadyForSleep());
	
	return HVC_SUCCESS;
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
uint32  xPCTrapConfigureWakeIRQ(void *pIRQMask, sailbsp_hvc_rsp_t *rsp)
{
    PCCoreStatusType_e eStatus;
    uint64 ullWakeIRQMask;

    ullWakeIRQMask = (uint64)(*(uint64*)pIRQMask);

    /* Cannot have all IRQs unmasked or all IRQs masked */
    if ((ullWakeIRQMask == 0) || (ullWakeIRQMask == ~0))
    {
        rsp->data[0] = PC_STATUS_FAIL;
		return HVC_SUCCESS;
    }

    eStatus = xPCCoreConfigureWakeIRQSource(ullWakeIRQMask);
    if (PC_SUCCESS != eStatus)
    {
        rsp->data[0] = PC_STATUS_FAIL;
		return HVC_SUCCESS;
    }

    rsp->data[0] = PC_STATUS_SUCCESS;
	
	return HVC_SUCCESS;
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
uint32  xPCTrapSleepEnter(PCSleepModeType_e eMode, sailbsp_hvc_rsp_t *rsp)
{
    PCCoreStatusType_e eStatus;

    if ( (eMode < PC_MODE_STANDBY) || (eMode > PC_MODE_DEEPSLEEP) )
    {
        rsp->data[0] = PC_STATUS_FAIL;
		return HVC_SUCCESS;
    }

    eStatus = xPCCoreSleepEnter((PCCoreSleepStatusType_e)eMode);
    if (PC_SUCCESS != eStatus)
    {
        rsp->data[0] = PC_STATUS_FAIL;
		return HVC_SUCCESS;
    }

    rsp->data[0] = PC_STATUS_SUCCESS;
	
	return HVC_SUCCESS;
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
uint32   xPCTrapSequencerEnableCtrl(uint32_t ucCtrl, sailbsp_hvc_rsp_t *rsp)
{
    PCCoreStatusType_e eStatus;

    eStatus = xPCCoreTriggerSequencer((boolean)ucCtrl);
    if (PC_SUCCESS != eStatus)
    {
        rsp->data[0] = PC_STATUS_FAIL;
		return HVC_SUCCESS;
    }

    rsp->data[0] = PC_STATUS_SUCCESS;
	
	return HVC_SUCCESS;
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
uint32   xPCTrapCtrlGlitchSrc(uint32_t bCtrl, sailbsp_hvc_rsp_t *rsp)
{
    PCCoreStatusType_e eStatus;

    eStatus = xPCCoreCtrlGlitchSrc((boolean)bCtrl);
    if (PC_SUCCESS != eStatus)
    {
        rsp->data[0] = PC_STATUS_FAIL;
		return HVC_SUCCESS;
    }

    rsp->data[0] = PC_STATUS_SUCCESS;
	
	return HVC_SUCCESS;
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
uint32   xPCTrapPopulateWakeupReason(void *puReasonMask, sailbsp_hvc_rsp_t *rsp)
{
    PCCoreStatusType_e eStatus;

    eStatus = xPCCorePopulateWakeupReason((uint64 *)puReasonMask);
    if (PC_SUCCESS != eStatus)
    {
        rsp->data[0] = PC_STATUS_FAIL;
		return HVC_SUCCESS;
    }

    rsp->data[0] = PC_STATUS_SUCCESS;
	
	return HVC_SUCCESS;
}

/**********************************************************
 *
 *
 * Power Controller service trap systemcall interface primitives
 *
 *
 **********************************************************/

/* SYS CALL DECLARATIONS */

SAIL_DEFINE_SYSCALL(  SAIL_PC_IS_CORE_INITIALIZED,
                      SAIL_PC_IS_CORE_INITIALIZED_PARAM_ID,
                      0,
                      xPCTrapIsCoreInitialized
                    );

SAIL_DEFINE_SYSCALL(  SAIL_PC_CONFIGURE_WAKEIRQ,
                      SAIL_PC_CONFIGURE_WAKEIRQ_PARAM_ID,
                      0,
                      xPCTrapConfigureWakeIRQ
                    );

SAIL_DEFINE_SYSCALL(  SAIL_PC_SLEEP_ENTER,
                      SAIL_PC_SLEEP_ENTER_PARAM_ID,
                      0,
                      xPCTrapSleepEnter
                    );

SAIL_DEFINE_SYSCALL(  SAIL_PC_SEQUENCER_EN_CTRL,
                      SAIL_PC_SEQUENCER_EN_CTRL_PARAM_ID,
                      0,
                      xPCTrapSequencerEnableCtrl
                    );

SAIL_DEFINE_SYSCALL(  SAIL_PC_GLITCH_SRC_CTRL,
                      SAIL_PC_GLITCH_SRC_CTRL_PARAM_ID,
                      0,
                      xPCTrapCtrlGlitchSrc
                    );

SAIL_DEFINE_SYSCALL(  SAIL_PC_POPULATE_WAKEUP_REASON,
                      SAIL_PC_POPULATE_WAKEUP_REASON_PARAM_ID,
                      0,
                      xPCTrapPopulateWakeupReason
                    );