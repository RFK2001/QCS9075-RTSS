#ifndef __SPINOR_EL1_TRAP_H__
#define __SPINOR_EL1_TRAP_H__

/*
===========================================================================
*/
/**
    @file  spinor_el1_trap.h
    @brief SPI NOR  EL1 Trap Service.
           This file describes the spinor service external interface.

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/sailsw1/spinor_el1_trap.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/**  \mainpage spinor Functional Overview
 *
 * The spinor driver provides a high-level interface for clients, such
 * as bootloaders, file systems, and tools to interact with the spinor devices. It
 * handles the spinor device specifics and abstracts with the client from the device-
 * specific algorithms, interfaces, and OS adaptations.
 *
 * \n
 *
 */


#include "spinor_cm_defs.h"
#include "spinor_trap_defs.h"

/**********************************************************
 * Syscall wrapper for spinor Trap interface
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trap_syscall_wrap(spinorTrapEventID_t eventID, spinorTrapParams_t* trapParam);

#endif /* __SPINOR_EL1_TRAP_H__ */
