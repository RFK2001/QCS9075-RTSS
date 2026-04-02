/*
 * Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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

#include <stdint.h>
#include <errno.h>
#include <debug_log.h>
#include <timetick.h>
#include <busywait.h>
#include <Clock.h>
#include <HALhwio.h>
#include <msmhwiobase.h>

/* TODO: this is internal to ClockDriver..
 * need to expose the Source functions if possible. */
#include <ClockDriver.h>

#include "bist.h"
#include "bist_internal.h"
#include "bist_utils.h"
#include "sail_csr_hwio.h"
#include "sail_security_control_hwio.h"
#include "g_SAIL_TO_MD_GCC_HWIO.h"

#define BIST_TCSR_READBACK_WAIT_TIMEOUT (10ULL * 1000ULL)       // 10ms

MD_BIST_DATA static timetick_type_64 gaBistTimestamp[BIST_TIMING_MAX] = { 0, };
MD_BIST_DATA static uint32_t gulDelayMultiplier = 1U;

MD_BIST_FUNC uint32_t slEnableClock(const char *pcName, uint32_t ulFreqMHzTarget)
{
    uint32_t slRet = BIST_E_SUCCESS;

    if (NULL != pcName)
    {
        ClockHandle     hClk = { 0 };
        ClockResult     crResult = CLOCK_SUCCESS;
        uint32_t        ulClkId = 0U;
        uint32_t        ulFreqMHz;

        (void)Clock_GetHandle(&hClk);

        crResult = Clock_GetClockId(hClk, pcName, &ulClkId);
        if (CLOCK_SUCCESS != crResult)
        {
            LOG_ERROR("%s: getting clockid failed for %s\r\n", __func__, pcName);
            slRet = BIST_E_NO_DEV;
        }

        if (BIST_E_SUCCESS == slRet)
        {
            if (0U != ulFreqMHzTarget)
            {
                crResult = Clock_SetClockFrequency(hClk,
                                                   ulClkId,
                                                   ulFreqMHzTarget,
                                                   CLOCK_FREQUENCY_MHZ_AT_LEAST,
                                                   &ulFreqMHz);
                if (CLOCK_SUCCESS != crResult)
                {
                    LOG_ERROR("%s: setting frequency failed for %s to %u\r\n", __func__, pcName, ulFreqMHzTarget);
                    slRet = BIST_E_INVALID_ARG;
                }
            }
        }

        if (BIST_E_SUCCESS == slRet)
        {
            crResult = Clock_EnableClock(hClk, ulClkId);
            if (CLOCK_SUCCESS != crResult)
            {
                LOG_ERROR("%s: clock enable failed for %s\r\n", __func__, pcName);
                slRet = BIST_E_DEV_FAILURE;
            }
        }
    }
    else
    {
        LOG_ERROR("%s: name of clock is NULL\r\n", __func__);
        slRet = BIST_E_INVALID_ARG;
    }

    return slRet;
}

MD_BIST_FUNC uint32_t slEnableClockSource(const char *pcName, uint32_t ulFreqMHzTarget)
{
    uint32_t slRet = BIST_E_SUCCESS;

    if (NULL != pcName)
    {
        ClockHandle     hClk = { 0 };
        ClockResult     crResult = CLOCK_SUCCESS;
        uint32_t        ulClkId = 0U;
        uint32_t        ulFreqMHz;

        (void)Clock_GetHandle(&hClk);

        crResult = Clock_GetSourceId(hClk, pcName, &ulClkId);
        if (CLOCK_SUCCESS != crResult)
        {
            LOG_ERROR("%s: getting clockid failed for %s\r\n", __func__, pcName);
            slRet = BIST_E_NO_DEV;
        }

        if (BIST_E_SUCCESS == slRet)
        {
            if (0U != ulFreqMHzTarget)
            {
                crResult = Clock_SetSourceFrequency(hClk,
                                                   ulClkId,
                                                   ulFreqMHzTarget,
                                                   CLOCK_FREQUENCY_MHZ_AT_LEAST,
                                                   &ulFreqMHz);
                if (CLOCK_SUCCESS != crResult)
                {
                    LOG_ERROR("%s: setting frequency failed for %s to %u\r\n", __func__, pcName, ulFreqMHzTarget);
                    slRet = BIST_E_INVALID_ARG;
                }
            }
        }

        if (BIST_E_SUCCESS == slRet)
        {
            crResult = Clock_EnableSource(hClk, ulClkId);
            if (CLOCK_SUCCESS != crResult)
            {
                LOG_ERROR("%s: clock enable failed for %s\r\n", __func__, pcName);
                slRet = BIST_E_DEV_FAILURE;
            }
        }
    }
    else
    {
        LOG_ERROR("%s: name of clock is NULL\r\n", __func__);
        slRet = BIST_E_INVALID_ARG;
    }

    return slRet;
}

MD_BIST_FUNC uint32_t slDisableClock(const char *pcName)
{
    uint32_t slRet = BIST_E_SUCCESS;

    if (NULL != pcName)
    {
        ClockHandle     hClk = { 0 };
        ClockResult     crResult = CLOCK_SUCCESS;
        uint32_t        ulClkId = 0U;

        (void)Clock_GetHandle(&hClk);

        crResult = Clock_GetClockId(hClk, pcName, &ulClkId);
        if (CLOCK_SUCCESS != crResult)
        {
            LOG_ERROR("%s: getting clockid failed for %s\r\n", __func__, pcName);
            slRet = BIST_E_NO_DEV;
        }

        if (BIST_E_SUCCESS == slRet)
        {
            crResult = Clock_DisableClock(hClk, ulClkId);
            if (CLOCK_SUCCESS != crResult)
            {
                LOG_ERROR("%s: clock disable failed for %s\r\n", __func__, pcName);
                slRet = BIST_E_DEV_FAILURE;
            }
        }
    }
    else
    {
        LOG_ERROR("%s: name of clock is NULL\r\n", __func__);
        slRet = BIST_E_INVALID_ARG;
    }

    return slRet;
}

MD_BIST_FUNC uint32_t slWriteTCSRRegister(uint32_t ulAddr, uint32_t ulMask, uint32_t ulValue)
{
    timetick_type_64    xStartTime;
    uint32_t            ulRegVal = 0U;
    uint32_t             slRet = BIST_E_SUCCESS;

    /* write masked value */
    ulRegVal = in_dword(ulAddr);
    ulRegVal &= ~(ulMask);
    ulRegVal |= (ulValue & ulMask);
    out_dword(ulAddr, ulRegVal);

    /* TCSR safety requirement: read back and check if the write was applied */
    xStartTime = timetick_get64();
    while((in_dword(ulAddr) & ulMask) != ulValue)
    {
        if (elapsedtime_us(timetick_get64(), xStartTime) > BIST_TCSR_READBACK_WAIT_TIMEOUT)
        {
            LOG_ERROR("%s: read back of TCSR write failed\r\n", __func__);
            slRet = BIST_E_TIMER_EXP;
            break;
        }
    }

    return slRet;
}

MD_BIST_FUNC uint32_t slPollRegisterValue(uint32_t ulAddr, uint32_t ulMask, uint32_t ulValue, uint32_t ulTimeOut)
{
    timetick_type_64    xStartTime;
    uint32_t             slRet = BIST_E_SUCCESS;

    xStartTime = timetick_get64();
    while ((ulValue & ulMask) != (ulMask & in_dword(ulAddr)))
    {
        if (elapsedtime_us(timetick_get64(), xStartTime) > ulTimeOut)
        {
            slRet = BIST_E_TIMER_EXP;
            break;
        }
    }

    return slRet;
}

MD_BIST_FUNC void vUpdateBistResult(uint32_t ulPhase, uint32_t ulBit)
{
        switch (ulPhase)
        {
            case BIST_MD_PHASE1:
                {
                    (void)slWriteTCSRRegister(HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_ADDR,
                                              ulBit,
                                              ulBit);
                    break;
                }
            case BIST_MD_PHASE2:
                {
                    (void)slWriteTCSRRegister(HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH2_BIST_STATUS_REG_ADDR,
                                              ulBit,
                                              ulBit);
                    break;
                }
            case BIST_MD_POFF:
                {
                    (void)slWriteTCSRRegister(HWIO_SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG_ADDR,
                                              (ulBit << 0x4U),
                                              (ulBit << 0x4U));
                    break;
                }
            default:
                {
                    LOG_ERROR("%s: invalid BIST phase\r\n", __func__);
                    break;
                }
        }
}

MD_BIST_FUNC void vBISTTimestamp(BISTTimingTag_e eTag)
{
    gaBistTimestamp[eTag] = timetick_get64();
}

MD_BIST_FUNC static uint32_t prvBISTGetTimeDiff(BISTTimingTag_e eEnd, BISTTimingTag_e eStart)
{
    uint64_t ullDuration = 0ULL;

    if ((eStart < BIST_TIMING_MAX) && (eEnd < BIST_TIMING_MAX))
    {
        ullDuration = elapsedtime_us(gaBistTimestamp[eEnd], gaBistTimestamp[eStart]);
    }

    return (uint32_t)ullDuration;
}

MD_BIST_FUNC void vBISTTimePrint(void)
{
    LOG_WARNING("BIST time report\r\n");
    LOG_WARNING("KPI_MARKER: overall (total, P1, P2) : %u, %u, %u\r\n",
            prvBISTGetTimeDiff(BIST_TIMING_END, BIST_TIMING_START),
            prvBISTGetTimeDiff(BIST_TIMING_P1_MBIST_END, BIST_TIMING_START),
            prvBISTGetTimeDiff(BIST_TIMING_END, BIST_TIMING_P2_POWERON_START));
    LOG_WARNING("PH1 BIST time (pre, MBIST, LBIST) : %u, %u, %u\r\n",
            prvBISTGetTimeDiff(BIST_TIMING_P1_MBIST_START, BIST_TIMING_START),
            prvBISTGetTimeDiff(BIST_TIMING_P1_MBIST_END, BIST_TIMING_P1_MBIST_START) - prvBISTGetTimeDiff(BIST_TIMING_P1_LBIST_END, BIST_TIMING_P1_LBIST_START),
            prvBISTGetTimeDiff(BIST_TIMING_P1_LBIST_END, BIST_TIMING_P1_LBIST_START));
    LOG_WARNING("MD reset time : %u\r\n", prvBISTGetTimeDiff(BIST_TIMING_P2_POWERON_START, BIST_TIMING_P1_LBIST_END));
    LOG_WARNING("PH2 BIST time (pre, MBIST, LBIST, post) : %u, %u, %u, %u\r\n",
            prvBISTGetTimeDiff(BIST_TIMING_P2_MBIST_START, BIST_TIMING_P2_POWERON_START),
            prvBISTGetTimeDiff(BIST_TIMING_P2_MBIST_END, BIST_TIMING_P2_MBIST_START),
            prvBISTGetTimeDiff(BIST_TIMING_P2_LBIST_END, BIST_TIMING_P2_LBIST_START),
            prvBISTGetTimeDiff(BIST_TIMING_END, BIST_TIMING_P2_LBIST_END));
}

MD_BIST_FUNC void vBISTSetDelayMultiplier(uint32_t ulMult)
{
    gulDelayMultiplier = ulMult;
}

MD_BIST_FUNC uint32_t ulBISTGetDelayMultiplier(void)
{
    return gulDelayMultiplier;
}
