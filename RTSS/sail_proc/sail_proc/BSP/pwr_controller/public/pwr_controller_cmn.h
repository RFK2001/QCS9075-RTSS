
#ifndef __PWR_CONTROLLER_CMN_H__
#define __PWR_CONTROLLER_CMN_H__

/*
===========================================================================
*/
/**
    @file  pwr_controller_cmn.h
    @brief Public common interface declaration for the Power Controller.

*/
/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/public/pwr_controller_cmn.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


#include "types.h"

/* Status Return Type */
typedef enum
{
   PC_STATUS_SUCCESS,            /* Success */
   PC_STATUS_FAIL,               /* Failure */
   PC_STATUS_MAX = 0x7FFFFFFF    /* Max type */
}PCStatusType_e;

/* PMIC Type */
typedef enum
{
   PC_PMIC_INDEPENDENT = 0x1,    /* Independent SAIL PMIC */
   PC_PMIC_MERGED,               /* Dependent Merged PMIC */
   PC_PMIC_MAX = 0x7FFFFFFF      /* Max Type */
}PCPMICType_e;


/* Sleep Mode Type */
typedef enum
{
   PC_MODE_STANDBY = 0x1,       /* Stand-by Mode */
   PC_MODE_SLEEP,               /* Sleep Mode */
   PC_MODE_DEEPSLEEP,           /* Deep Sleep Mode */
   PC_MODE_MAX = 0x7FFFFFFF     /* Max Type */
}PCSleepModeType_e;


// Enable this macro when EL1 driver needs to be enabled for SW1
// and to enable trap calls from EL1->EL2
#define ENB_TRAP_CALL

#ifndef ENB_TRAP_CALL
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
uint32_t xPCTrapIsCoreInitialized(void);

/**********************************************************
 * Configures the Wake IRQ in the Power controller
 *
 *
 * @param type [IN]
 *   Pointer to the mask value of IRQs that should be masked in the Power Controller
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
uint32_t  xPCTrapConfigureWakeIRQ(void *pIRQMask);

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
uint32_t  xPCTrapSleepEnter(PCSleepModeType_e eMode);

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
uint32_t   xPCTrapSequencerEnableCtrl(uint32_t ucCtrl);

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
uint32_t   xPCTrapCtrlGlitchSrc(uint32_t bCtrl);

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
uint32_t   xPCTrapPopulateWakeupReason(void *puReasonMask);

#endif /* ENB_TRAP_CALL */

#endif /* __PWR_CONTROLLER_CMN_H__ */
