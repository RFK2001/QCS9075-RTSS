/**
 * @file syscall_hvc.h
 * @brief API to enable HVC invocation from EL1 
 * Header file for the definition of  HVC Trap call.
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
06.02.21   rrahul       Created
=============================================================================*/

#ifndef SYSCALL_HVC_H
#define SYSCALL_HVC_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include "types.h"

/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/
 

/*===========================================================================
                           EXTERNS
===========================================================================*/
 

/*===========================================================================
                           MACROS
===========================================================================*/
 
/*===========================================================================
                           FUNCTION APIs
===========================================================================*/

/*===========================================================================
**  Function :  hvc_call
** ==========================================================================
*/
/*!
*
* @brief
*   Incoke HVC from EL1 mode.
*
* @param
    uint32_t *cmd_id       -- HVC ID
    uint32_t *param_id     -- PARAM ID
    uint32_t *arg1         -- Arg1
    uint32_t *arg2         -- Arg2
    uint32_t *arg3         -- Arg3
    uint32_t *arg4         -- Arg4
* @par Dependencies
*   None
* @retval
*   Success or Error code
* @par Side Effects
*   None
*
*/
int hvc_call(uint32_t *cmd_id, uint32_t *param_id, uint32_t *arg1, uint32_t *arg2, uint32_t *arg3, uint32_t *arg4);

#endif  //SYSCALL_HVC_H
