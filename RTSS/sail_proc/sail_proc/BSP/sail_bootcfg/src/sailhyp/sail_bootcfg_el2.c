/**
 * @file sail_bootcfg_el2.c
 * @brief Sail boot configs functions
 * Source file for the definition of Sail diagnostics util functions
 *
 *        Copyright (c) 2021 - 2025 Qualcomm Technologies, Inc.
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

#include <stdlib.h>
#include <stdio.h>
#include "sail_csr_hwio.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "sail_security_control_hwio.h"
#include "sail_bootcfg.h"
#include "syscall.h"
#include "syscall_pub.h"
#include "common_functions.h"

/**********************************************************
 * Funtion checks the value of the capt sec GPIO register for the current cluster configuration
 *
 * @return uint8 [OUT]
 *   value of the Capt sec GPIO register.
 **********************************************************/
uint8 sailbsp_EL2_get_capt_sec_gpio_val(void)
{
    uint8 capt_sec_gpio_val = 0;
    
    capt_sec_gpio_val = REG_INF(SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE, SAILSS_SECURITY_CONTROL_CAPT_SEC_GPIO, CLUSTER_CONFIG_GPIO);
    
    return capt_sec_gpio_val;
}

/**********************************************************
 * EL2 trap function for the sail diagnostics utils get capt sec GPIO
 *
 * @return uint32 [OUT]
 *   Result of the operation.
 **********************************************************/
uint32 sailbsp_El2trap_get_capt_sec_gpio_val(sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = ((uint8)sailbsp_EL2_get_capt_sec_gpio_val());

    return HVC_SUCCESS;
}

/* SYS CALL DECLARATIONS */
SAIL_DEFINE_SYSCALL(  SAIL_GET_CAPT_SEC_GPIO,
                      SAIL_GET_CAPT_SEC_GPIO_PARAM_ID,
                      0,
                      sailbsp_El2trap_get_capt_sec_gpio_val
                    );