#ifndef __BOOT_LOGGER_H__
#define __BOOT_LOGGER_H__
/*
===========================================================================
*/
/**
  @file boot_logger.h
  @brief Private interface include file for boot_logger.
*/
/*
  ===========================================================================

  Copyright (c) 2022-2025 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================
*/
/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#ifndef SAILEL2
#include "FreeRTOSOsal.h"
#include "freertos_init.h"
#endif

uint64 vBootLogger_LogDeltaTime(uint64 startTime,const char *message, int cpu);
uint64 uBootLogger_LogStartTime(const char *message, int cpu);
void uBootLogger_LogAbsTime(const char *message, int cpu);
#if 0 //ifndef SAILEL2
extern BaseType_t xSAILBSPVIPServiceTaskInit( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior );

extern BaseType_t xvSAILBSPVipSrvTaskRTOSFeatureInit( CPUIdType_e           xSchdCore);
#endif
#endif