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
#include <HALhwio.h>
#include <Clock.h>
#include <timetick.h>
// #include "logcode.h"
#include "boot_logger.h"
#include <debug_log.h>
#include <busywait.h>
#include <chipinfo.h>
// #include <wdt.h>
#include <msmhwiobase.h>
#include "boot.h"
#include "libfdt.h"
#include "fdt_utils.h"
#include "err_fatal.h"
#include "common_functions.h"

#include "bist.h"
#include "bist_internal.h"
#include "bist_utils.h"
#include "sail_asild_iso_hwio.h"
#include "sail_clkctl_hwio.h"
#include "HALclkHWIO.h"
#include "sail_csr_hwio.h"
#include "sail_security_control_hwio.h"
#include "g_SAIL_HBCU_HWIO.h"
#include "g_SAIL_PWR_CTRL.h"
#include "g_SAIL_ASIL_B.h"
#include "g_SAIL_TO_MD_SECURITY_CONTROL_CORE_HWIO.h"

#ifdef lemans
    #define BIST_MD_WAIT_TIMEOUT            (500UL * 1000UL)    /* 500msec */
#else
    /* 
     * On Monaco due to EMMC Init Issue on MD side MD to SAIL status has been delayed
     * increase delay to 1sec to avoid HW issue
     */
    #define BIST_MD_WAIT_TIMEOUT            (1000UL * 1000UL)    /* 1000msec */
#endif
#define ASIL_D_B_NOC_PARTIAL_RESET_TIMEOUT   (250U)              /* 250usec */
#define HBCU_FAILURE_NOTI_PERIOD             (100UL * 1000UL)    /* 100msec */
#define HBCU_FAILURE_NOTI_COUNT              (10U)
#define BIST_P2_DELAY                        (25UL * 1000UL)     /* 25msec */

#define INIT_MD_PRE_BIST_COOKIE         (0xba010000U)
#define INIT_MD_PRE_BIST_IVI            (0xba010001U)
#define INIT_MD_PRE_BIST_PH2_COOKIE     (0xba010002U)
#define INIT_MD_PRE_BIST_DONE_COOKIE    (0xba010003U)
#define INIT_MD_PRE_BIST_PH1_RUNNING    (0xba010004U)
#define INIT_MD_PRE_BIST_PH2_RUNNING    (0xba010005U)
#define INIT_MD_PRE_BIST_POFF_BIST      (0xba010010U)
#define INIT_MD_PRE_BIST_NO_BIST        (0xba010020U)

#define BIST_RECONFIG_WDT_MS    25000U

MD_BIST_DATA static uint32_t bistcfg_eGpioConfig;
MD_BIST_DATA static uint32_t bistcfg_SAIL_TO_MD_BOOT_CONFIG;
MD_BIST_DATA uint32_t bistErrorInjection = 0UL;
extern uint8_t bootcfg_MDBIST_core;
extern bool sailbsp_checkwarmboot(void);
extern bool sailbsp_readClusterLockStepConfig(uint8_t cluster_num);
extern uint32_t is_el2_wdt_enabled;

enum BISTGpioConfig
{
    BIST_GPIO_RESERVED  = 0x0U,
    BIST_GPIO_PON       = 0x1U,
    BIST_GPIO_POFF      = 0x2U,
    BIST_GPIO_NOBIST    = 0x3U,
};

/**********************************************************
*
*
* Boot configration trap systemcall interface primitives
*
*
**********************************************************/
/* SYS CALL DECLARATIONS */
SAIL_DEFINE_SYSCALL(BOOTCFG_GET_MDBIST_CORE_HVC_ID,
                    BOOTCFG_GET_MDBIST_CORE_PARAM_ID,
                    0,
                    BOOTCFG_GET_MDBIST_CORE);
                    
MD_BIST_FUNC static void prvHandleHBCUFailure(int32_t id)
{
    uint32_t    log_data = 0u ;
    uint32_t    i = 0;

    #if 0
    /* ensuare watchdog is enabled */
    wdt_init_el2();
    #endif

    // log_data = (uint32_t)SAIL_BIST_STATUS;
    

    for (i = 0U; i < HBCU_FAILURE_NOTI_COUNT; i++)
    {
        // (void)vLcWriteLogCode(SAIL_BOOT_MILESTONES, FAIL, &log_data, 1U);
        busywait(HBCU_FAILURE_NOTI_PERIOD);
    }

    err_fatal(HBCU, id);
}

MD_BIST_FUNC void vCaptureDisableHBCU(void)
{
    uint32_t ulStart = 0U;
    uint32_t ulDone = 0U;
    boolean  bBISTPass = TRUE;
    uint32_t log_data ;

    /* disable sequencer */
    HWIO_OUTF(SAILSS_HBCU_HBCU_SEQ_EN, SEQUENCER_ENABLE, 0x0U);

    /* capture SAIL MBIST result */
    ulStart = HWIO_IN(SAILSS_HBCU_HBCU_MBIST_STARTED);
    ulDone = HWIO_IN(SAILSS_HBCU_HBCU_MBIST_DONE);
    HWIO_OUT(SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED, ulStart);
    HWIO_OUT(SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE, ulDone);
    if ((ulStart != 0x0U) && (ulDone != 0x0U))
    {
        uint32_t ulPass = HWIO_IN(SAILSS_HBCU_HBCU_MBIST_PASS);
        
        HWIO_OUT(SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS, ulPass);
        if ((0U == ulPass) || ((bistErrorInjection & INJ_SAIL_MBIST_ERR) != 0UL))
        {
            LOG_ERROR("%s: SAIL MBIST failed\r\n", __func__);
            prvHandleHBCUFailure(0x1);
        }
    }
    else
    {
        bBISTPass = FALSE;
        HWIO_OUT(SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS, 0x0U);
        LOG_ERROR("%s: SAIL MBIST skipped\r\n", __func__);
    }

    /* capture SAIL LBIST result */
    ulStart = HWIO_IN(SAILSS_HBCU_HBCU_LBIST_STARTED);
    ulDone = HWIO_IN(SAILSS_HBCU_HBCU_LBIST_DONE);
    HWIO_OUT(SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED, ulStart);
    HWIO_OUT(SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE, ulDone);
    if ((ulStart != 0x0U) && (ulDone != 0x0U))
    {
        uint32_t ulPass = HWIO_IN(SAILSS_HBCU_HBCU_LBIST_PASS);

        HWIO_OUT(SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS, ulPass);
        if ((0U == ulPass) || ((bistErrorInjection & INJ_SAIL_LBIST_ERR) != 0UL))
        {
            LOG_ERROR("%s: SAIL LBIST failed\r\n", __func__);
            prvHandleHBCUFailure(0x2);
        }
    }
    else
    {
        bBISTPass = FALSE;
        HWIO_OUT(SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS, 0x0U);
        LOG_ERROR("%s: SAIL LBIST skipped\r\n", __func__);
    }

    if (TRUE == bBISTPass)
    {
        // (log_data) = (uint32_t)SAIL_BIST_STATUS;
        // (void)vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1U);

        LOG_WARNING("%s: SAIL BIST pass\r\n", __func__);

#ifdef SKIP_DISABLE_HBCU    /* TODO: temp skip HBCU disablement because of warm-reset failure in PBL */
        /* inform NoC about HBCU disable state */
        HWIO_OUT(SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW,
                 HWIO_SAILSS_ASIL_B_ASIL_B_NOC_ASIL_B_NOC_DEVICEBUFFER_SBM_SBM_FLAGOUTSET0_LOW_PORT13_BMSK);

        /* configure HBCU isolation */
        HWIO_OUTM(SAILSS_CSR_HBCU_ISOLATION, 0x3U, 0x1U);

        /* wait for 10 HCLK cycles */
        busywait(110U);

        /* configure HBCU to be disabled */
        HWIO_OUTM(SAILSS_CSR_HBCU_CONTROL, 0x3U, 0x1U);
#endif
    }
}

MD_BIST_FUNC static void prvWriteBootStatus(uint32_t ulVal)
{
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS0_REG, (ulVal & 0xffU));
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS1_REG, ((ulVal >> 8U) & 0xffU));
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS2_REG, ((ulVal >> 16U) & 0xffU));
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS3_REG, ((ulVal >> 24U) & 0xffU));
}

MD_BIST_FUNC static uint32_t prvRunMDChipWideReset(void)
{
    uint16_t usTimeout = 0U;
    uint32_t ulAsilDNocPartRes = 0U;
    uint32_t ulAsilBNocPartRes = 0U;
    uint32_t ulSailCcDemetCbcr = 0U;

    /* enable isolation */
    HWIO_OUTF(SAILSS_PWR_CTRL_ISD_CONTROL, ISD_MOVE_TO_ISLAND_STATE, 0x1U);
    while(0x0u == (HWIO_INF(SAILSS_PWR_CTRL_ISD_STATUS, ISD_ISLAND_STATE)) && usTimeout < 1U)
    {
        busywait(1U);
        ++usTimeout;
    }
    if( ( 0x0u == (HWIO_INF(SAILSS_PWR_CTRL_ISD_STATUS, ISD_ISLAND_STATE)) ) && usTimeout >= 1U )
    {
        DEBUG_LOG(SAIL_ERROR,"BIST:ISD Entry Failed\r\n");
        return BIST_E_TIMER_EXP;
    }
    HWIO_OUTF(SAILSS_PWR_CTRL_ISD_CONTROL, ISD_MOVE_TO_ISLAND_STATE, 0x0U);

    /*ASIL_D, ASIL_B Iso NoC Partial reset trigger*/
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTREQN, 0x0);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTREQN, 0x0);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR, CLK_ENABLE, 0x1);

    ulAsilBNocPartRes = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTACKN);
    ulAsilDNocPartRes = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTACKN);
    ulSailCcDemetCbcr = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR, CLK_OFF);
    
    while((0x1u == ulAsilDNocPartRes)&& (0x1u == ulAsilBNocPartRes)&& (0x1u == ulSailCcDemetCbcr)
        && (usTimeout <= ASIL_D_B_NOC_PARTIAL_RESET_TIMEOUT))
    {
        busywait(1U);
        ulAsilBNocPartRes = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTACKN);
        ulAsilDNocPartRes = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTACKN);
        ulSailCcDemetCbcr = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR, CLK_OFF);        
        ++usTimeout;
    }
    
    if(usTimeout >= ASIL_D_B_NOC_PARTIAL_RESET_TIMEOUT)
    {
        if((0x1u == HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTACKN)))
        {
            DEBUG_LOG(SAIL_ERROR,"BIST:ASILB_NOC_PARTIAL_RESET Failed\r\n");
            return BIST_E_TIMER_EXP;
        }
        else if((0x1u == HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTACKN)))
        {
            DEBUG_LOG(SAIL_ERROR,"BIST:ASILD_NOC_PARTIAL_RESET Failed\r\n");
            return BIST_E_TIMER_EXP;
        }
        else if((0x1u == HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR, CLK_OFF)))
        {
            DEBUG_LOG(SAIL_ERROR,"BIST:SAILSS_CC_DEMET_CBCR OFF Failed\r\n");
            return BIST_E_TIMER_EXP;
        }
        else
        {
            //Do nothing
        }
    }

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_CBCR, CLK_ARES, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_CBCR, CLK_ARES, 0x1);

    /* assert MD reset */
    HWIO_OUTF(SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET, START, 0x1U);

    /* wait more than 200ns */
    busywait(1U);

    /* disable GEMNOC isolation */
    HWIO_OUTM(SAILSS_CSR_SAIL_GEMNOC_ANA_ISOLATION_ENABLE_REG, 0x3U, 0x0U);
    HWIO_OUTM(SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG, 0x3U, 0x0U);
    HWIO_OUTM(SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG, (0x1U << 2U), 0x0U);
    HWIO_OUTM(SAILSS_CSR_SAIL_GEMNOC_ISOLATION_ENABLE_REG, (0x1U << 3U), 0x0U);

    /* deassert MD reset */
    HWIO_OUTF(SAILSS_CSR_LBIST_MD_CHIPWIDE_RESET, START, 0x0U);

    /* HPG update QCTDD11655537 */
    busywait(250U);
    
    /* disable isolation */
    HWIO_OUTF(SAILSS_PWR_CTRL_ISD_CONTROL, ISD_MOVE_TO_NORMAL_STATE, 0x1U);
    busywait(1U);
    HWIO_OUTF(SAILSS_PWR_CTRL_ISD_CONTROL, ISD_MOVE_TO_NORMAL_STATE, 0x0U);

    /*Wake up NoC*/
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_CBCR, CLK_ARES, 0x0);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_CBCR, CLK_ARES, 0x0);

   	HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTREQN, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTREQN, 0x1);	

    usTimeout = 0U;
    ulAsilBNocPartRes = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTACKN);
    ulAsilDNocPartRes = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTACKN);
    while((0x0u == ulAsilBNocPartRes) && (0x0u == ulAsilDNocPartRes) 
        && (usTimeout <= ASIL_D_B_NOC_PARTIAL_RESET_TIMEOUT))
    {
        busywait(1U);
        ulAsilBNocPartRes = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTACKN);
        ulAsilDNocPartRes = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTACKN);        
        ++usTimeout;
    }
    
    if(usTimeout >= ASIL_D_B_NOC_PARTIAL_RESET_TIMEOUT)
    {
        if((0x0u == HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTACKN)))
        {
            DEBUG_LOG(SAIL_ERROR,"BIST:ASILB_NOC_PARTIAL_RESET Failed\r\n");
            return BIST_E_TIMER_EXP;	
        }
        else if((0x0u == HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTACKN)))
        {
            DEBUG_LOG(SAIL_ERROR,"BIST:ASILD_NOC_PARTIAL_RESET Failed\r\n");
            return BIST_E_TIMER_EXP;
        }
        else
        {
            //Do nothing
        }
    }

    HWIO_OUT(SAILSS_PWR_CTRL_ISD_SPARE_REG_0, 0x3ffU);

    return BIST_E_SUCCESS;
}

MD_BIST_FUNC static uint32_t slRunPOFFIVIBIST(void)
{
    uint32_t             slRet = BIST_E_SUCCESS;
    return slRet;
}

MD_BIST_FUNC static uint32_t slRunPOFFBIST(void)
{
    uint32_t             slRet = BIST_E_SUCCESS;

    prvWriteBootStatus(INIT_MD_PRE_BIST_POFF_BIST);

    return slRet;
}

MD_BIST_FUNC static uint32_t slRunPONIVIBIST(void)
{
    uint32_t             slRet = BIST_E_SUCCESS;
    const ChipInfoIdType chipInfo_Id = ChipInfo_GetChipId();
    uint8_t pBTotalIPs = 0U;    

    prvWriteBootStatus(INIT_MD_PRE_BIST_IVI);

    /* wait PH1 BIST complete from MD : READY bit is used for completion here */
    vBISTTimestamp(BIST_TIMING_P1_MBIST_START);
    slRet = slPollRegisterValue(HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_ADDR,
                                HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH1_BIST_READY_BMSK,
                                0x1U << HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH1_BIST_READY_SHFT,
                                BIST_MD_WAIT_TIMEOUT);
    if (BIST_E_SUCCESS != slRet)
    {
        LOG_ERROR("%s: MD PH1 BIST is not ready in time\r\n", __func__);
        slRet = BIST_E_TIMER_EXP;
    }

    if (BIST_E_SUCCESS == slRet)
    {
        prvWriteBootStatus(INIT_MD_PRE_BIST_PH2_COOKIE);

        vBISTTimestamp(BIST_TIMING_P1_MBIST_END);
        vBISTTimestamp(BIST_TIMING_P1_LBIST_START);
        vBISTTimestamp(BIST_TIMING_P1_LBIST_END);
        vBISTTimestamp(BIST_TIMING_P2_POWERON_START);

        /* wait PH2 BIST ready from MD */
        slRet = slPollRegisterValue(HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_ADDR,
                                    HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH2_BIST_READY_BMSK,
                                    0x1U << HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH2_BIST_READY_SHFT,
                                    BIST_MD_WAIT_TIMEOUT);
        if (BIST_E_SUCCESS != slRet)
        {
            LOG_ERROR("%s: MD PH2 BIST is not ready in time\r\n", __func__);
        }
    }

    if (BIST_E_SUCCESS == slRet)
    {
        prvWriteBootStatus(INIT_MD_PRE_BIST_PH2_RUNNING);

        /* PH2 BIST. Skip V1. Skip for IOT */
        vUpdateBistResult(BIST_MD_PHASE2, BIST_PON_MBIST_COMPLETE);
        vUpdateBistResult(BIST_MD_PHASE2, BIST_PON_LBIST_COMPLETE);
    }

    if (BIST_E_SUCCESS == slRet)
    {
        HWIO_OUTF(SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG, MD_PH2_BIST_COMPLETE, 0x1U);

        prvWriteBootStatus(INIT_MD_PRE_BIST_DONE_COOKIE);

        (void)Clock_ReInitMDClockBSP();
    }

    return slRet;
}

MD_BIST_FUNC static uint32_t slRunPONBIST(void)
{
    const struct BISTIPInfo   *pP1BISTIPInfo = NULL;
    const struct BISTIPInfo   *pP2BISTIPInfo = NULL;
    uint32_t             slRet = BIST_E_SUCCESS;
    const ChipInfoIdType chipInfo_Id = ChipInfo_GetChipId();

    prvWriteBootStatus(INIT_MD_PRE_BIST_COOKIE);

    /* wait PH1 BIST ready from MD */
    slRet = slPollRegisterValue(HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_ADDR,
                                HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH1_BIST_READY_BMSK,
                                0x1U << HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH1_BIST_READY_SHFT,
                                BIST_MD_WAIT_TIMEOUT);
    if (BIST_E_SUCCESS != slRet)
    {
        LOG_ERROR("%s: MD PH1 BIST is not ready in time\r\n", __func__);
    }

    if (BIST_E_SUCCESS == slRet)
    {
        prvWriteBootStatus(INIT_MD_PRE_BIST_PH1_RUNNING);
        /* PH1. Skip V1. Skip for IOT */
        vUpdateBistResult(BIST_MD_PHASE1, BIST_PON_MBIST_COMPLETE);
        vUpdateBistResult(BIST_MD_PHASE1, BIST_PON_LBIST_COMPLETE);
    }

    if (BIST_E_SUCCESS == slRet)
    {
        HWIO_OUTF(SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG, MD_PH1_BIST_COMPLETE, 0x1U);

        /* execute chip wide reset */
        slRet = prvRunMDChipWideReset();
        if (BIST_E_SUCCESS != slRet)
        {
            LOG_ERROR("%s: MD reset failed after MD BIST Phase1 ret=%d\r\n", __func__, slRet);
        }
        // vLCWriteTimeStamp( BIST_PH1_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
    }

    if (BIST_E_SUCCESS == slRet)
    {
        (void)Clock_ReInitMDClockBSP();

        prvWriteBootStatus(INIT_MD_PRE_BIST_PH2_COOKIE);

        /* wait PH2 BIST ready from MD */
        slRet = slPollRegisterValue(HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_ADDR,
                                    HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH2_BIST_READY_BMSK,
                                    0x1U << HWIO_SAILSS_CSR_MAIN2SAIL_MD_BIST_READY_REG_MD_PH2_BIST_READY_SHFT,
                                    BIST_MD_WAIT_TIMEOUT);

        // vLCWriteTimeStamp( BIST_PH2_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );

#ifdef monaco                                    
        busywait(BIST_P2_DELAY);                                    
#endif        
        if (BIST_E_SUCCESS != slRet)
        {
            LOG_ERROR("%s: MD PH2 BIST is not ready in time\r\n", __func__);
        }
    }

    if (BIST_E_SUCCESS == slRet)
    {
        prvWriteBootStatus(INIT_MD_PRE_BIST_PH2_RUNNING);
        
         /* PH2 BIST. Skip V1. Skip for IOT */
        vUpdateBistResult(BIST_MD_PHASE2, BIST_PON_MBIST_COMPLETE);
        vUpdateBistResult(BIST_MD_PHASE2, BIST_PON_LBIST_COMPLETE);
    }

    HWIO_OUTF(SAILSS_CSR_SAIL2MAIN_MD_BIST_COMPLETE_REG, MD_PH2_BIST_COMPLETE, 0x1U);

    prvWriteBootStatus(INIT_MD_PRE_BIST_DONE_COOKIE);

    if (BIST_E_SUCCESS == slRet)
    {
        (void)Clock_ReInitMDClockBSP();

        #ifndef FORCE_SKIP_MD_BIST_EXECUTION
        if (ChipInfo_GetChipVersion() >= BIST_SOC_VERSION_2 || (CHIPINFO_FAMILY_MONACOAU == ChipInfo_GetChipFamily()))
        {
            /* Re enable GPU clock after BIST due to race condition with XBL Clock init */
            slRet = slEnableClock("gpu_cc_rbcpr_clk", 0U);
        }
        #endif
    }

    return slRet;
}

MD_BIST_FUNC uint32_t slRunMDBIST(void)
{
    uint64 initStartTime = 0;
    int                 cpu;
    ChipInfoIdType      xChipInfo = ChipInfo_GetChipId();
    enum BISTGpioConfig eGpioConfig = BIST_GPIO_PON;
    uint32_t            slRet = BIST_E_SUCCESS;
    boolean             bSkipMDBIST = FALSE;
    uint32_t            log_data;

    cpu = (int) get_curr_phys_cpu_num();
    // initStartTime = uBootLogger_LogStartTime("BIST Init on core", cpu);

    /* wait isolation is disabled */
    slRet = slPollRegisterValue(HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ADDR,
                                HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK,
                                0x0U,
                                BIST_MD_WAIT_TIMEOUT);
    if (BIST_E_SUCCESS != slRet)
    {
        LOG_ERROR("%s: MD Isolation was not cleared in time\r\n", __func__);
    }

    if (BIST_E_SUCCESS == slRet)
    {

        if (0x1U == bistcfg_SAIL_TO_MD_BOOT_CONFIG)
        {
            bSkipMDBIST = TRUE;
        }

        eGpioConfig = (enum BISTGpioConfig) bistcfg_eGpioConfig;

#ifdef IVI_FLOW_DISABLE
        if((CHIPINFO_ID_SA_LEMANSAU_IVI != xChipInfo) && bSkipMDBIST)
#else
        if(bSkipMDBIST)
#endif
        {
            eGpioConfig = BIST_GPIO_NOBIST;
        }

        vBISTTimestamp(BIST_TIMING_START);

        /* indicate to MD that SAIL is ready to run PH1 BIST */
        if (BIST_GPIO_PON == eGpioConfig)
        {
            /* PON BIST case */
            /* FULL ADAS flow for both ADAS and IVI */
            slRet = slRunPONBIST();
        }
        else if(BIST_GPIO_POFF == eGpioConfig)
        {
            /* POFF BIST case */
            if(CHIPINFO_ID_SA_LEMANSAU_IVI != xChipInfo)
            {
                slRet = slRunPOFFBIST();
            }
            else
            {
                slRet = slRunPOFFIVIBIST();
            }
        }
        else if (BIST_GPIO_NOBIST == eGpioConfig)
        {
            prvWriteBootStatus(INIT_MD_PRE_BIST_NO_BIST);
            LOG_WARNING("%s: skip BIST execution completely\r\n", __func__);
            slRet = BIST_E_SUCCESS;
        }
        else
        {
            prvWriteBootStatus(INIT_MD_PRE_BIST_NO_BIST);
            LOG_WARNING("%s: reserved value - skip BIST execution completely for now\r\n", __func__);
            slRet = BIST_E_SUCCESS;
        }
    }

    /* If V2 device and PON or POFF BIST is enabled*/
    #ifndef FORCE_SKIP_MD_BIST_EXECUTION
    if((ChipInfo_GetChipVersion() >= BIST_SOC_VERSION_2 || (CHIPINFO_FAMILY_MONACOAU == ChipInfo_GetChipFamily())) && ((BIST_GPIO_PON == eGpioConfig) || (BIST_GPIO_POFF == eGpioConfig)))
    {
        vBISTTimestamp(BIST_TIMING_END);
        vBISTTimePrint();

        if(slRet == BIST_E_SUCCESS)
        {
            LOG_WARNING("BIST execution completed\r\n");
            // (log_data) = (uint32_t)MD_BIST_STATUS;
            // (void)vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
        }
        else
        {
            LOG_WARNING("BIST execution failed\r\n");
        }

        #if 0
        /* Config 25s WDT if loading EL1 to DDR. S1_MAP_READY may take longer than 4s WDT */
        if((sailbsp_get_imageLoadToDDR_config() == 0x1U) && (is_el2_wdt_enabled == 0x1U))
        {
            wdt_trigger_bite_el2(BIST_RECONFIG_WDT_MS);
            LOG_WARNING("BIST set WDT to 25s\r\n");
        }
        #endif
    }
    #endif

    // (void)vBootLogger_LogDeltaTime(initStartTime, "BIST Init Done on core", cpu);

    return slRet;
}

/*===========================================================================
**  Function :  pre_BIST_init
** ==========================================================================
*/
/*
* @brief
*   This function would read MD BIST configuration from the GPIO. It also gets the bistErrorInjection config from device tree.
*/
MD_BIST_FUNC void pre_BIST_init(void)
{
    uint32_t    log_data = 0u;
    int retval;
    void *pDTB = NULL;
    int32_t root_offset = 0;
	uint32_t bistpropval = 0UL;

    bistcfg_eGpioConfig = HWIO_INF(SAILSS_SECURITY_CONTROL_CAPT_SEC_GPIO, BIST_CONFIG_GPIO);
    bistcfg_SAIL_TO_MD_BOOT_CONFIG = HWIO_INF(SAIL_TO_MD_BOOT_CONFIG, SKIP_MD_BIST);

    // log_data = (uint32_t)SKIP_SAIL_BIST;
    // (void)vLcWriteLogCode(SAIL_BOOT_MILESTONES, (((bistcfg_eGpioConfig == 0x1U)||(bistcfg_eGpioConfig == 0x2U))?FAIL:PASS), &log_data, 1U);
    // log_data = (uint32_t)SKIP_MD_BIST;
    // (void)vLcWriteLogCode(SAIL_BOOT_MILESTONES, ((bistcfg_SAIL_TO_MD_BOOT_CONFIG == 0x1U)?PASS:FAIL), &log_data, 1U);


    /* Get the DTB entries for bistErrorInjection configuration */
    pDTB = fdt_get_dtb();
    if (NULL != pDTB)
    {
        root_offset = fdt_path_offset(pDTB, "/bistErrorInjection");
        if(root_offset > 0)
        {
            (void)fdt_getprop_u32(pDTB, root_offset, "SAIL-MBIST-ERR", &bistpropval);
            bistErrorInjection |= bistpropval;
            (void)fdt_getprop_u32(pDTB, root_offset, "SAIL-LBIST-ERR", &bistpropval);
            bistErrorInjection |= bistpropval << 1UL;
            (void)fdt_getprop_u32(pDTB, root_offset, "MD-PH1-MBIST-ERR", &bistpropval);
            bistErrorInjection |= bistpropval << 2UL;
            (void)fdt_getprop_u32(pDTB, root_offset, "MD-PH1-LBIST-ERR", &bistpropval);
            bistErrorInjection |= bistpropval << 3UL;
            (void)fdt_getprop_u32(pDTB, root_offset, "MD-PH2-MBIST-ERR", &bistpropval);
            bistErrorInjection |= bistpropval << 4UL;
            (void)fdt_getprop_u32(pDTB, root_offset, "MD-PH2-LBIST-ERR", &bistpropval);
            bistErrorInjection |= bistpropval << 5UL;
        }
    }
}

/*===========================================================================
**  Function :  getSkipMDBISTConfig
** ==========================================================================
*/
/*
* @brief
*   This function would return MD BIST configuration.
* @retval
*   TRUE - MD BIST is skipped according to the dip swtich configuration.
*   FALSE -MD BIST is not being skipped.
*/
MD_BIST_FUNC bool getSkipMDBISTConfig(void)
{
    bool skipMDBISTConfig = TRUE;
    if((0x0U == bistcfg_SAIL_TO_MD_BOOT_CONFIG)&&((bistcfg_eGpioConfig==0x1U)||(bistcfg_eGpioConfig==0x2U)))
    {
        skipMDBISTConfig = FALSE;
    }
    return skipMDBISTConfig;
}

/*===========================================================================
**  Function :  bootcfg_el2_setMDBIST_core
** ==========================================================================
*/
/*
* @brief
*   This function would update bootcfg_MDBIST_core according to different BIST situations. 
* @param
*   boot_mode_type* bootmode
*
*/
void bootcfg_el2_setMDBIST_core(boot_mode_type* bootmode)
{
    void *pDTB = NULL;
    int32_t root_offset = 0;
	uint32_t bistpropval = 0UL;	
    if((sailbsp_checkwarmboot()==FALSE)&&
        (FALSE == sailbsp_checkmdedl())&&
        (getSkipMDBISTConfig() == FALSE))
    {   
        bootcfg_MDBIST_core = 0x0U;
    }
    else
    {
        bootcfg_MDBIST_core = 0xFFU;
        LOG_ERROR("bootcfg: skip BIST execution completely\r\n");
    }
}

/*===========================================================================
**  Function :  bootcfg_el2_getMDBIST_core
** ==========================================================================
*/
/*
* @brief
*   This function would return the updated bootcfg_MDBIST_core according to different BIST situations. 
* @param
*   boot_mode_type* bootmode
*
*/
uint8_t bootcfg_el2_getMDBIST_core(void){
  return bootcfg_MDBIST_core;
}

/* =========================================================================
**  Function : BOOTCFG_GET_MDBIST_CORE
** =========================================================================*/
/**
  
  Boot Configuration System Call Wrapper

  Get the MD BIST core.
   
  This function returns the core number that MDBIST would run on.
   
  @return
  SVC_SUCCESS
   
  @param rsp [out], BIST Status

  @dependencies
  None.
*/
uint32_t BOOTCFG_GET_MDBIST_CORE(sailbsp_hvc_rsp_t *rsp)
{
  uint8_t rsp_data = bootcfg_el2_getMDBIST_core();

  if (rsp_data != 0U)
  {
      rsp->data[0] = rsp_data;
  }  
  return ((uint32_t)HVC_SUCCESS);
}

