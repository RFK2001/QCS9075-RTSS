#ifndef Gpt_DRV_H_
#define Gpt_DRV_H_
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
    File Name          : Gpt_Prv.h
    Component Name     : Time
    Description        : Private Header file for GPT Driver
    $Header:
    $DateTime:
    $Author:
=================================================================================================*/

#include "Gpt.h"
#include "msmhwiobase.h"
#include "g_SAIL_QTMR.h"
#include "sailbsp_mutex.h"

#define Gpt_PHYIRQ_0             96U
#define Gpt_CNT_MAX              0xFFFFFFFFFFFFFFUL
#define Gpt_VAL_HI_MASK          0x00FFFFFFUL
#define Gpt_VAL_LO_MASK          0xFFFFFFFFUL

#define Gpt_BASE_ADDR_OFFSET(timerId)                            (SAILSS_QTMR_SAILSS_QTMR_BASE + (timerId * 0x1000U))
#define Gpt_CNTPCT_LO_OFFSET(timerId)                            (Gpt_BASE_ADDR_OFFSET(timerId))
#define Gpt_CNTPCT_HI_OFFSET(timerId)                            (Gpt_BASE_ADDR_OFFSET(timerId) + 0x4U)
#define Gpt_CNTFREQ_OFFSET(timerId)                              (Gpt_BASE_ADDR_OFFSET(timerId) + 0x10U) 
#define Gpt_CNTP_CVAL_LO_OFFSET(timerId)                        (Gpt_BASE_ADDR_OFFSET(timerId) + 0x20U)
#define Gpt_CNTP_CVAL_HI_OFFSET(timerId)                        (Gpt_BASE_ADDR_OFFSET(timerId) + 0x24U) 
#define Gpt_CNTP_CTRL_OFFSET(timerId)                           (Gpt_BASE_ADDR_OFFSET(timerId) + 0x2CU)
#define Gpt_VERSION_OFFSET(timerId)                              (Gpt_BASE_ADDR_OFFSET(timerId) + 0xFD0U) 

uint64 GptPrv_SetCounterValue( const Gpt_ChannelType timerId, const uint64 value, uint64 *startValue );
uint64 GptPrv_GetCounterValue(const Gpt_ChannelType timerId);
uint64 GptPrv_GetTimeDifference( uint64 time1,  uint64 time2);
void GptPrv_EnableTimer(const Gpt_ChannelType timerId);
void GptPrv_DisableTimer(const Gpt_ChannelType timerId);
uint64 GptPrv_ConvertUSToTicks( uint64 us, uint8 preDefResolution );
uint64 GptPrv_ConvertTicksToUS( uint64 ticks, uint8 preDefResolution );
#endif