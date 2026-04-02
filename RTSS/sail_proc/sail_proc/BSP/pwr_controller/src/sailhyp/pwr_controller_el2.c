
/*
===========================================================================
*/
/**
    @file  pwr_controller_el2.c
    @brief Implementation of Power Controller driver APIs in EL2

*/
/*
    ===========================================================================

    Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/src/sailhyp/pwr_controller_el2.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "pwr_controller_el2.h"
#include "pwr_controller_core.h"
#include "pwr_controller_trap.h"

static boolean bPCInitEL2Done =  FALSE;

/**********************************************************
 * Initalizes the Power controller driver and Hardware
 *
 *
 * @param type [IN]
 *   PMIC type to configure the hardware accordingly
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCStatusType_e   xPCinitEL2(PCPMICType_e ePMICType)
{
    PCCoreStatusType_e eStatus;

    /* If the PC driver is already initialized then return success */
    if (TRUE == bPCInitEL2Done)
    {
        return PC_STATUS_SUCCESS;
    }

    /* Initialize the PC driver */
    eStatus = xPCDrvInit();
    if (PC_SUCCESS != eStatus)
    {
        return PC_STATUS_FAIL;
    }

    /* Initialize the PC Trap layer */
    eStatus = xPCTrapInitEL2();
    if (PC_SUCCESS != eStatus)
    {
        return PC_STATUS_FAIL;
    }

    /* Initialize the PC controller core */
    eStatus = xPCCoreInit((PCCorePMICType_e)ePMICType);
    if (PC_SUCCESS != eStatus)
    {
        return PC_STATUS_FAIL;
    }

    bPCInitEL2Done = TRUE;

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
PCStatusType_e   xPCConfigureWakeIRQEL2(uint64 ullWakeIRQMask)
{
    PCCoreStatusType_e eStatus;

    /* Cannot have all IRQs unmasked or all IRQs masked */
    if ((ullWakeIRQMask == 0) || (ullWakeIRQMask == ~0))
    {
        return PC_STATUS_FAIL;
    }

    eStatus = xPCCoreConfigureWakeIRQSource(ullWakeIRQMask);
    if (PC_SUCCESS != eStatus)
    {
        return PC_STATUS_FAIL;
    }

    return PC_STATUS_SUCCESS;
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
//PCStatusType_e   xPCSleepEnterEL2(PCSleepModeType_e eMode)
//{
//    PCCoreStatusType_e eStatus;
//
//    if ( (eMode < PC_MODE_STANDBY) || (eMode > PC_MODE_SLEEP) )
//    {
//        return PC_STATUS_FAIL;
//    }
//
//    eStatus = xPCCoreSleepEnter((PCCoreSleepStatusType_e)eMode);
//    if (PC_SUCCESS != eStatus)
//    {
//        return PC_STATUS_FAIL;
//    }
//
//    return PC_STATUS_SUCCESS;
//}

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
//PCStatusType_e   xPCSequencerEnableCtrlEL2(boolean ucCtrl)
//{
//    PCCoreStatusType_e eStatus;
//
//    eStatus = xPCCoreTriggerSequencer(ucCtrl);
//    if (PC_SUCCESS != eStatus)
//    {
//        return PC_STATUS_FAIL;
//    }
//
//    return PC_STATUS_SUCCESS;
//}

/**********************************************************
 * Sleep Exit for Power Controller
 *
 *
 * @param type [IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCStatusType_e   xPCSleepExitEL2(void)
{
    PCCoreStatusType_e eStatus;

    eStatus = xPCCoreSleepExit();
    if (PC_SUCCESS != eStatus)
    {
        return PC_STATUS_FAIL;
    }

    return PC_STATUS_SUCCESS;
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
PCStatusType_e   xPCCtrlGlitchSrcEL2(boolean bCtrl)
{
    PCCoreStatusType_e eStatus;

    eStatus = xPCCoreCtrlGlitchSrc(bCtrl);
    if (PC_SUCCESS != eStatus)
    {
        return PC_STATUS_FAIL;
    }

    return PC_STATUS_SUCCESS;
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
PCStatusType_e   xPCPopulateWakeupReasonEL2(uint64 *puReasonMask)
{
    PCCoreStatusType_e eStatus;

    eStatus = xPCCorePopulateWakeupReason(puReasonMask);
    if (PC_SUCCESS != eStatus)
    {
        return PC_STATUS_FAIL;
    }

    return PC_STATUS_SUCCESS;
}

