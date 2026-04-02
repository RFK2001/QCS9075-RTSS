
#ifndef __PWR_CONTROLLER_EL2_H__
#define __PWR_CONTROLLER_EL2_H__

/*
===========================================================================
*/
/**
    @file  pwr_controller_el2.h
    @brief Public interface declaration for the Power Controller for EL2.

*/
/*
    ===========================================================================

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

    ===========================================================================

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/public/sailhyp/pwr_controller_el2.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


#include "pwr_controller_cmn.h"

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
PCStatusType_e   xPCinitEL2(PCPMICType_e ePMICType);

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
PCStatusType_e   xPCConfigureWakeIRQEL2(uint64 ullWakeIRQMask);

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
//PCStatusType_e   xPCSleepEnterEL2(PCSleepModeType_e eMode);

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
//PCStatusType_e   xPCSequencerEnableCtrlEL2(boolean ucCtrl);

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
PCStatusType_e   xPCSleepExitEL2(void);

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
PCStatusType_e   xPCCtrlGlitchSrcEL2(boolean bCtrl);

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
PCStatusType_e   xPCPopulateWakeupReasonEL2(uint64 *puReasonMask);

#endif /* __PWR_CONTROLLER_EL2_H__ */
