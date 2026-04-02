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
    File Name          : Gpt_Irq.h
    Component Name     : MCalCfg
    Description        : Public Header file for gpt isr handlers
    $Header:
    $DateTime:
    $Author:
=================================================================================================*/
#ifndef GPT_IRQ_H
#define GPT_IRQ_H

#include "Gpt.h"

void Gpt_TimerIrq0ISR(void *args);
void Gpt_TimerIrq1ISR(void *args);
void Gpt_TimerIrq2ISR(void *args);
void Gpt_TimerIrq3ISR(void *args);
void Gpt_TimerIrq4ISR(void *args);
void Gpt_TimerIrq5ISR(void *args);
void Gpt_TimerIrq6ISR(void *args);
void Gpt_TimerIrq7ISR(void *args);
void Gpt_TimerIrq8ISR(void *args);
void Gpt_TimerIrq9ISR(void *args);
void Gpt_TimerIrq10ISR(void *args);
void Gpt_TimerIrq11ISR(void *args);
Gpt_EventPtrType *prvQTimerGetISR(const Gpt_ChannelType timerId);
#endif