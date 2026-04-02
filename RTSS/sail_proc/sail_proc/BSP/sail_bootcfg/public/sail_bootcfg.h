/**
 * @file sail_bootcfg.h
 * @brief Sail boot configs header
 * Header file for the definition of SAIL diagnostics utils API
 *
 *        Copyright (c) 2021 -2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
08.04.22   pmdonthi       Created
=============================================================================*/

#ifndef SAIL_BOOTCFG_H
#define SAIL_BOOTCFG_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "arm_acle.h"
/*===========================================================================
                           MACROS
===========================================================================*/

/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/

/*===========================================================================
                           EXTERNS
===========================================================================*/

/*
 *===========================================================================
                          FUNCTIONS
 *===========================================================================*/

/*===========================================================================
**  Function :  sailbsp_get_capt_sec_gpio_val
** ==========================================================================
*/
/*!
*
* @brief
*   Checks if the current cluster is in lockstep mode by reading the capt sec GPIO register
*
* @retval
*   value of the capt sec gpio
*/
uint8 sailbsp_get_capt_sec_gpio_val(void);
#endif