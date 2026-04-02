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

/*==========================================================================*/

#include "isd.h"
#include "isd_os.h"
#include <stdlib.h>
#include "sailbsp_mutex.h"
#include "interrupts.h"
/*=========================================================================
      Function Definitions
==========================================================================*/

/* =========================================================================
**  Function : eISDOS_RegisterInterrupt
** =========================================================================*/

ISD_FUNC isdResultsType_e
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
    (void)xGicSetIntEnable(nVectorId, (boolean)FALSE);
    (void)xGicRegisterIntHandler(nVectorId, (InterruptHandle_t )pISR, args);
    if (0 != xGicConfigureInt(nVectorId, (enum InterruptConfig_t)nTrigger, NULL))
    {
        eReturnValue =  ISD_NOT_OK;
    }
    else
    {
        (void)xGicSetIntEnable(nVectorId, (boolean)TRUE);
        eReturnValue = ISD_OK;
    }

    return eReturnValue;
}

/* =========================================================================
**  Function : eISDOS_DeRegisterInterrupt
** =========================================================================*/

ISD_FUNC isdResultsType_e
eISDOS_DeRegisterInterrupt
(
    uint32_t nVectorId,
    uint32_t nFlags
)
{
    (void)xGicSetIntEnable(nVectorId, (boolean)FALSE);
    (void)xGicUnRegisterIntHandler(nVectorId, nFlags);

    return ISD_OK;
}
