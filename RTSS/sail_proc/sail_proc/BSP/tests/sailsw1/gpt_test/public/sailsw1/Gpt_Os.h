#ifndef __GPT_OS_H__
#define __GPT_OS_H__

/**************************************************************************************************
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
**************************************************************************************************/

/*=================================================================================================
    File Name          : Gpt_Os.h
    Component Name     : MCalCfg
    Description        : Public Header file for gpt os abstarction layer
    $Header:
    $DateTime:
    $Author:
=================================================================================================*/

#include "types.h"
#include "Gpt.h"
/*=========================================================================
      Type Definitions
==========================================================================*/
/**
 * Definition of trigger types for interrupt registration
 */
typedef enum
{
  GptOs_TRIGGER_LEVEL=0,
  GptOs_TRIGGER_EDGE=1,
  GptOs_MAX
}
GptOs_TriggerType;

/* =========================================================================
**  Function : eGptOs_RegisterInterrupt
** =========================================================================*/
void 
eGptOs_RegisterInterrupt
(
    unsigned int nVectorId,
    GptOs_TriggerType eTrigger,
    Gpt_EventPtrType *pISR,
    void *args
);

/* =========================================================================
**  Function : eGptOs_DeRegisterInterrupt
** =========================================================================*/

status_t 
eGptOs_DeRegisterInterrupt
(
    unsigned int nVectorId,
    unsigned int nFlags
);
#endif