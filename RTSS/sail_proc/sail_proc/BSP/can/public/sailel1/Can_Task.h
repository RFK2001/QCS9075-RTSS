/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/
#ifndef CAN_TASK_H
#define CAN_TASK_H
#ifdef __cplusplus
extern "C"{
#endif

#include "freertos_init.h"
#include "FreeRTOSOsal.h"

BaseType_t xCanTaskInit( CPUIdType_e xSchdCore, UBaseType_t  xTaskPrior );
BaseType_t xCanTaskQueueInit(CPUIdType_e xSchdCore);

BaseType_t xCanSrvTaskInit(CPUIdType_e xSchdCore, UBaseType_t xTaskPrior );
BaseType_t xCanSrvTaskQueueInit(CPUIdType_e xSchdCore );

BaseType_t xCanTrcvTaskInit(CPUIdType_e xSchdCore, UBaseType_t xTaskPrior );
BaseType_t xCanTrcvTaskQueueInit(CPUIdType_e xSchdCore );

#ifdef __cplusplus
}
#endif
#endif /* CAN_TASK_H */

