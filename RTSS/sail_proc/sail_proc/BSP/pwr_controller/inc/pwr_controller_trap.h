
#ifndef __PWR_CONTROLLER_TRAP_H__
#define __PWR_CONTROLLER_TRAP_H__

/*
===========================================================================
*/
/**
    @file  pwr_controller_trap.h
    @brief This file provides definitions for the Power Controller Trap Services.

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/inc/pwr_controller_trap.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "pwr_controller_core.h"

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
PCCoreStatusType_e xPCTrapInitEL2(void);

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
PCCoreStatusType_e xPCTrapDeInitEL2(void);

#endif /* __PWR_CONTROLLER_TRAP_H__ */
