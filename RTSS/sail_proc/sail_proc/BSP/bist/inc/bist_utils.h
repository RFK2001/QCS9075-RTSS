/*
 * Copyright (c) 2022-2025 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Export of this technology or software is regulated by the U.S. Government.
 * Diversion contrary to U.S. law prohibited.
 *
 * All ideas, data and information contained in or disclosed by
 * this document are confidential and proprietary information of
 * Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
 * By accepting this material the recipient agrees that this material
 * and the information contained therein are held in confidence and in
 * trust and will not be used, copied, reproduced in whole or in part,
 * nor its contents revealed in any manner to others without the express
 * written permission of Qualcomm Technologies, Inc.
 */

#ifndef BIST_UTILS_H_
#define BIST_UTILS_H_

#include <stdint.h>

#define MD_BIST_FUNC  __attribute__ ( ( section ("md_bist_func" ) ) )
#define MD_BIST_DATA  __attribute__ ( ( section ("md_bist_data" ) ) )

#define BIST_WAIT_TIMEOUT               (10UL * 1000UL)   /* 10msec */

#define BIST_PON_MBIST_COMPLETE \
            HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_SAIL2MAIN_MD_PH1_BIST_PWR_ON_MBIST_COMPLETE_BMSK
#define BIST_PON_LBIST_COMPLETE \
            HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_SAIL2MAIN_MD_PH1_BIST_PWR_ON_LBIST_COMPLETE_BMSK
#define BIST_PON_MBIST_PASS \
            HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_SAIL2MAIN_MD_PH1_BIST_PWR_ON_MBIST_PASS_BMSK
#define BIST_PON_LBIST_PASS    \
            HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_SAIL2MAIN_MD_PH1_BIST_PWR_ON_LBIST_PASS_BMSK
#define BIST_POFF_MBIST_COMPLETE    \
            HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_SAIL2MAIN_MD_PH1_BIST_PWR_OFF_MBIST_COMPLETE_BMSK
#define BIST_POFF_LBIST_COMPLETE    \
            HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_SAIL2MAIN_MD_PH1_BIST_PWR_OFF_LBIST_COMPLETE_BMSK
#define BIST_POFF_MBIST_PASS    \
            HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_SAIL2MAIN_MD_PH1_BIST_PWR_OFF_MBIST_PASS_BMSK
#define BIST_POFF_LBIST_PASS    \
            HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_SAIL2MAIN_MD_PH1_BIST_PWR_OFF_LBIST_PASS_BMSK

enum BISTFuncType
{
    BIST_FUNC_POWER_ON,
    BIST_FUNC_PRE_MBIST,
    BIST_FUNC_MBIST_CLK_EN,
    BIST_FUNC_POST_MBIST,
    BIST_FUNC_PRE_LBIST,
    BIST_FUNC_POST_LBIST,
    BIST_FUNC_POST_BIST,
    BIST_FUNC_POWER_OFF,
};

typedef enum {
    BIST_TIMING_START = 0,
    BIST_TIMING_P1_MBIST_START,
    BIST_TIMING_P1_MBIST_END,
    BIST_TIMING_P1_LBIST_START,
    BIST_TIMING_P1_LBIST_END,
    BIST_TIMING_P2_POWERON_START,
    BIST_TIMING_P2_MBIST_START,
    BIST_TIMING_P2_MBIST_END,
    BIST_TIMING_P2_LBIST_START,
    BIST_TIMING_P2_LBIST_END,
    BIST_TIMING_END,
    BIST_TIMING_MAX,
} BISTTimingTag_e;


MD_BIST_FUNC uint32_t slEnableClock(const char *pcName, uint32_t ulFreqMHzTarget);
MD_BIST_FUNC uint32_t slEnableClockSource(const char *pcName, uint32_t ulFreqMHzTarget);
MD_BIST_FUNC uint32_t slDisableClock(const char *pcName);

MD_BIST_FUNC uint32_t slWriteTCSRRegister(uint32_t ulAddr, uint32_t ulMask, uint32_t ulValue);
MD_BIST_FUNC uint32_t slPollRegisterValue(uint32_t ulAddr, uint32_t ulMask, uint32_t ulValue, uint32_t ulTimeOut);

MD_BIST_FUNC void vUpdateBistResult(uint32_t ulPhase, uint32_t ulBit);

MD_BIST_FUNC void vBISTTimestamp(BISTTimingTag_e eTag);
MD_BIST_FUNC void vBISTTimePrint(void);

MD_BIST_FUNC void vBISTSetDelayMultiplier(uint32_t ulMult);
MD_BIST_FUNC uint32_t ulBISTGetDelayMultiplier(void);

#endif  //BIST_UTILS_H_
