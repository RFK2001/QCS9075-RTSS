/**
 * @file noc_diagnostics.h
 * @brief Sail NOC diagnostics 
 * Header file for the definition of NOC diagnostics API
 *
 *        Copyright (c) 2021 -2022 Qualcomm Technologies, Inc.
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

#ifndef NOC_DIAGNOSTICS_H
#define NOC_DIAGNOSTICS_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "arm_acle.h"
#include "target.h"
/*===========================================================================
                           MACROS
===========================================================================*/
/* Valid fault aggregator IDs in SAIL ASIL D NOC */
#define SAIL_ASIL_D_NOC_FAULT_AGGR 106

/* Valid fault aggregator IDs in SAIL ASIL B NOC */
#define SAIL_ASIL_B_NOC_FAULT_AGGR 46
/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/

typedef enum
{
    NOC_ERRINJ_PASS = 0,
    NOC_ERRINJ_FAIL =1
}NOCTestStats_e;

/*===========================================================================
                           EXTERNS
===========================================================================*/

/*
 *===========================================================================
                          FUNCTIONS
 *===========================================================================*/

/*===========================================================================
**  Function :  NOC_tests_ASIL_D
** ==========================================================================
*/
/*!
*
* @brief
*   Performs SAIL ASIL D NOC diagnostics
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   Status of the operation
* @par Side Effects
*   None
*
*/
extern int NOC_tests_ASIL_D(void);

/*===========================================================================
**  Function :  NOC_tests_ASIL_B
** ==========================================================================
*/
/*!
*
* @brief
*   Performs SAIL ASIL B NOC diagnostics
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   Status of the operation
* @par Side Effects
*   None
*
*/
extern int NOC_tests_ASIL_B(void);

/*===========================================================================
**  Function :  config_sftyctrl_asild_intr
** ==========================================================================
*/
/*!
*
* @brief
*   Configures the safety controlled interrupts for SAIL ASIL D NOCs
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   Status of the operation
* @par Side Effects
*   None
*
*/
extern int config_sftyctrl_asild_intr(void);

/*===========================================================================
**  Function :  config_sftyctrl_asilb_intr
** ==========================================================================
*/
/*!
*
* @brief
*   Configures the safety controlled interrupts for SAIL ASIL B NOCs
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   Status of the operation
* @par Side Effects
*   None
*
*/
extern int config_sftyctrl_asilb_intr(void);
#endif