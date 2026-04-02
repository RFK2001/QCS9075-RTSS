/**
 * @file isd_os.c
 * @brief
 * Source file for os apis of SAIL
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
// ToDo remove this file while migrating driver to EL1
/*==========================================================================*/

#include "isd_drv.h"
#include <stdlib.h>
#include "sailbsp_mutex.h"
#include "interrupts.h"
#include "debug_log.h"

/*=========================================================================
      Function Definitions
==========================================================================*/

/* =========================================================================
**  Function : eISDOS_RegisterInterrupt
** =========================================================================*/

isdResultsType_e 
eISDOS_RegisterInterrupt
(
    uint32_t nVectorId,
    ISDOS_TriggerType eTrigger,
    ISDOS_InterruptHandle *pISR,
    void *args
)
{
    uint32_t nTrigger;

    isdResultsType_e eReturnValue = ISD_NOT_OK;

    nTrigger = (uint32_t)eTrigger;
    (void)mask_interrupt(nVectorId);
    (void)register_int_handler(nVectorId, (int_handler )pISR, args);
    if (0 != configure_interrupt(nVectorId, (enum intr_config)nTrigger, args))
    {
        eReturnValue =  ISD_NOT_OK;
    }
    else
    {
        (void)unmask_interrupt(nVectorId);
        eReturnValue = ISD_OK;
    }

    return eReturnValue;
}

/* =========================================================================
**  Function : eISDOS_DeRegisterInterrupt
** =========================================================================*/

isdResultsType_e 
eISDOS_DeRegisterInterrupt
(
    uint32_t nVectorId,
    uint32_t nFlags
)
{
    (void)mask_interrupt(nVectorId);
    (void)unregister_int_handler(nVectorId, nFlags);

    return ISD_OK;
}
