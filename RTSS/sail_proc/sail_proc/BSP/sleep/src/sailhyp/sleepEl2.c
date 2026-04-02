/*
===========================================================================
*/
/**
    @file  sleep_cmm.h
    @brief Header file of Sleep driver where common data is present between EL2/EL1

*/
/*
    ===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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
    File Name          : sleepEl2.c
    Component Name     : sleep
    Description        : contains functions need to be taken care at sleep exit
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sleep/src/sailhyp/sleepEl2.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

#include "types.h"
#include "hw_io.h"
#include "HALhwio.h"
#include "pwr_controller_el2.h"
#include "sleepEl2.h"
//#include "wdt.h"
#include "Clock.h"
#include "ClockDefs.h"
#include "sleep_hwio.h"
#include "common_functions.h"
#include "syscall.h"
#include "syscall_pub.h"
#include "timetick.h"
#include "sleep_internal.h"
#include "sleep_core.h"
#include "busywait.h"
/*=========================================================================================================
**                                        Global variables and constants                                 **
=========================================================================================================*/

sleepDebugInformation stSleepDebugInfo = {0};

#define ASIL_D_NOC_PARTIAL_RESET_TIMEOUT   (250U)       /* 250usec */

/*=========================================================================================================
**                                        Local functions Prototype                                    **
=========================================================================================================*/

sleepErrType_e prvSleepSailRTCUSecondaryToWFI(void);
sleepErrType_e prvSleepClockDisable(void);
void prvSleepConfig (sleepModeType_e xSleepMode);
sleepErrType_e prvSleepAsilDNocReset(void);
sleepErrType_e prvSleepGpio(void);

/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/


/*=========================================================================================================
 @Service name        vsleepDataUpdate
 @Description         vsleepDataUpdate function update sleep marker
                      in sleep state
 @param[in]           sleepMarkerUpdate_e < SLEEP_ENTRY_MAKER, SLEEP_EXIT_MARKER >
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

void vsleepDataUpdate(sleepMarkerUpdate_e xdataType)
{
    switch(xdataType)
    {
        case SLEEP_ENTRY_MAKER :
            stSleepDebugInfo.entryTimeStamp = timetick_CvtTimetick64ToTime( timetick_get64(), T_USEC );
            stSleepDebugInfo.sleepCount += 1;
            break;
        case SLEEP_EXIT_MARKER:
            stSleepDebugInfo.exitTimeStamp = timetick_CvtTimetick64ToTime( timetick_get64(), T_USEC );
            stSleepDebugInfo.TimeElapseInSleep = (stSleepDebugInfo.exitTimeStamp-stSleepDebugInfo.entryTimeStamp);
            break;
        default:
            return;
    }
}

/*=========================================================================================================
 @Service name        SleepSysCallsleepDataUpdate
 @Description         SleepSysCallsleepDataUpdate HVC call registered to El1 sleep code
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 HVC call status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

uint32 SleepSysCallsleepDataUpdate(uint32 dataType,sailbsp_hvc_rsp_t *rsp)
{
    vsleepDataUpdate((sleepMarkerUpdate_e) dataType);

    return HVC_SUCCESS;
}

/*=========================================================================================================
 @Service name        SleepSysCallsleepGetData
 @Description         SleepSysCallsleepGetData HVC call registered to El1 sleep code
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 HVC call status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

uint32 SleepSysCallsleepGetData( sleepDebugInformation *pSleepData,sailbsp_hvc_rsp_t *rsp)
{
    (void)memcpy(pSleepData,&stSleepDebugInfo,sizeof(sleepDebugInformation));
    return HVC_SUCCESS;
}

/*=========================================================================================================
 @Service name        SleepSysCallsleepRTCUSetting
 @Description         SleepSysCallsleepRTCUSetting HVC call registered to El1 sleep code
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 HVC call status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


uint32 SleepSysCallsleepRTCUSetting( sailbsp_hvc_rsp_t *rsp)
{
    prvSleepSailRTCUSecondaryToWFI();

    return HVC_SUCCESS;
}

/*=========================================================================================================
 @Service name        SleepSysCallsleepclockdisable
 @Description         SleepSysCallsleepclockdisable HVC call registered to El1 sleep code
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 HVC call status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

uint32 SleepSysCallsleepclockdisable(sailbsp_hvc_rsp_t *rsp)
{

    rsp->data[0] = prvSleepClockDisable();

    return HVC_SUCCESS;
}

/*=========================================================================================================
 @Service name        SleepSysCallsleepConfig
 @Description         SleepSysCallsleepConfig HVC call registered to El1 sleep code
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 HVC call status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

uint32 SleepSysCallsleepConfig( uint32 ulSleepMode , sailbsp_hvc_rsp_t *rsp)
{
    prvSleepConfig((sleepModeType_e) ulSleepMode);

    return HVC_SUCCESS;
}


/*=========================================================================================================
 @Service name        SleepSysCallsleepAsildReset
 @Description         SleepSysCallsleepAsildReset HVC call registered to El1 Autosar sleep code for NOC reset
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 HVC call status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

uint32 SleepSysCallsleepAsildReset(sailbsp_hvc_rsp_t *rsp)
{
	rsp->data[0] = (uint32)prvSleepAsilDNocReset();
	
    return HVC_SUCCESS;
}

/*=========================================================================================================
 @Service name        low_power
 @Description         low_power function will put current CPU in WFI
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

void  __attribute__((__aligned__(32))) low_power(void)
{
    uint32_t grpen = 0;
    uint32 ulcpu_ID;

    ulcpu_ID = get_curr_phys_cpu_num();

    if(ulcpu_ID==0)
    {
        __asm__("MCR p15,0,%0,c12,c12,6"::"r"(grpen));
        __asm__("MCR p15,0,%0,c12,c12,7"::"r"(grpen));
        HWIO_OUTF(SAILSS_GIC0_ALIAS0_GICR_WAKER, PROCESSORSLEEP, 0x1);
        while(!HWIO_INF(SAILSS_GIC0_ALIAS0_GICR_WAKER, CHILDRENASLEEP));
        __asm__("ISB");
        __asm__("wfi");

    }
    else if(ulcpu_ID==0x1)
    {
        __asm__("MCR p15,0,%0,c12,c12,6"::"r"(grpen));
        __asm__("MCR p15,0,%0,c12,c12,7"::"r"(grpen));
        HWIO_OUTF(SAILSS_GIC0_ALIAS1_GICR_WAKER, PROCESSORSLEEP, 0x1);
        while(!HWIO_INF(SAILSS_GIC0_ALIAS1_GICR_WAKER, CHILDRENASLEEP));
        __asm__("ISB");
        __asm__("wfi");
    }
    else if(ulcpu_ID==0x2)
    {
        __asm__("MCR p15,0,%0,c12,c12,6"::"r"(grpen));
        __asm__("MCR p15,0,%0,c12,c12,7"::"r"(grpen));
        HWIO_OUTF(SAILSS_GIC1_ALIAS0_GICR_WAKER, PROCESSORSLEEP, 0x1);
        while(!HWIO_INF(SAILSS_GIC1_ALIAS0_GICR_WAKER, CHILDRENASLEEP));
        __asm__("ISB");
        __asm__("wfi");
    }
    else if(ulcpu_ID==0x3)
    {
        __asm__("MCR p15,0,%0,c12,c12,6"::"r"(grpen));
        __asm__("MCR p15,0,%0,c12,c12,7"::"r"(grpen));
        HWIO_OUTF(SAILSS_GIC1_ALIAS1_GICR_WAKER, PROCESSORSLEEP, 0x1);
        while(!HWIO_INF(SAILSS_GIC1_ALIAS1_GICR_WAKER, CHILDRENASLEEP));
        __asm__("ISB");
        __asm__("wfi");
    }
}


/*=========================================================================================================
 @Service name        prvSleepClockDisable
 @Description         prvSleepClockDisable to put required clock to XO and turn off PLL which are not needed
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              sleepErrType_e
 @Pre                 PMICInit,PCInit,ISD,CLKInit should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

sleepErrType_e prvSleepClockDisable(void)
{
    /*  7.  SAILCC Low Power programming.
                a.  Switch the sleep clk GFMUX to choose from RO PLL (PLL5)
                    i.  Program SAILSS_CLKCTL_SAILSS_CC_XO_RO_GFMUX_MUXR[CLK_SEL] to 0x1


                b.  Switch the below RCGs (which will be on during low power) to PLL5 source
                    SAILSS_CLKCTL_SAILSS_CC_SWAO_CFG_RCGR
                    SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CFG_RCGR
                    SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CFG_RCGR
                    SAILSS_CLKCTL_SAILSS_CC_BMTX_NOC_QH_CFG_RCGR
                    SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CFG_RCGR
                c.  Switch all the remaining RCGs to XO source
                d.  Turn OFF all the PLLs except PLL5
    */

        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CFG_RCGR, SRC_SEL, 0x0);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CFG_RCGR, SRC_DIV, 0x1);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CMD_RCGR, UPDATE, 1);
        while(HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CMD_RCGR, UPDATE));

        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ACC_CFG_RCGR, SRC_SEL, 0x0);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ACC_CFG_RCGR, SRC_DIV, 0x1);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ACC_CMD_RCGR, UPDATE, 1);
        while(HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ACC_CMD_RCGR, UPDATE));

        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CE1_CFG_RCGR, SRC_SEL, 0x0);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CE1_CFG_RCGR, SRC_DIV, 0x1);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CE1_CMD_RCGR, UPDATE, 1);
        while(HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_CE1_CMD_RCGR, UPDATE));


        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_LBIST_CFG_RCGR, SRC_SEL, 0x0);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_LBIST_CFG_RCGR, SRC_DIV, 0x1);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_LBIST_CMD_RCGR, UPDATE, 1);
        while (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_LBIST_CMD_RCGR, UPDATE));

        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_PRIM_CFG_RCGR, SRC_SEL, 0x0);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_PRIM_CFG_RCGR, SRC_DIV, 0x1);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_PRIM_CMD_RCGR, UPDATE, 1);
        while (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_PRIM_CMD_RCGR, UPDATE));
        

        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_SEC_CFG_RCGR, SRC_SEL, 0x0);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_SEC_CFG_RCGR, SRC_DIV, 0x1);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_SEC_CMD_RCGR, UPDATE, 1);
        while (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_SEC_CMD_RCGR, UPDATE));

        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CFG_RCGR, SRC_SEL, 0x0);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CFG_RCGR, SRC_DIV, 0x1);
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CMD_RCGR, UPDATE, 1);
        while (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CMD_RCGR, UPDATE));

        

        if ( CLOCK_SUCCESS !=  Clock_SleepEntry())
        {
            return SLEEP_ERR_ENTRY_FAIL;
        }

        //d.   Turn OFF all the PLLs except PLL5
        HWIO_OUT(SAILSS_CLKCTL_SAILSS_CC_PLL0_PLL_MODE,0);
        HWIO_OUT(SAILSS_CLKCTL_SAILSS_CC_PLL0_PLL_OPMODE,0);

        return SLEEP_ERR_FLAG_SUCCESS;
}

/*=========================================================================================================
 @Service name        prvSleepSailRTCUSecondaryToWFI
 @Description         prvSleepSailRTCUSecondaryToWFI is used to put secondary core to WFI
 @param[in]           <No Input Parameter>
 @param[out]          NA
 @param[in, out]      NA
 @return              <Return type is sleepErrType_e>
 @Pre                 ClkInit should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

sleepErrType_e prvSleepSailRTCUSecondaryToWFI(void)
{

    uint32 ulRegOut = 0x0;

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CBCR, FORCE_MEM_PERIPH_ON, 0x0);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CBCR, FORCE_MEM_PERIPH_ON, 0x0);

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CBCR, FORCE_MEM_CORE_ON, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CBCR, FORCE_MEM_CORE_ON, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM0_AXI_CBCR, FORCE_MEM_CORE_ON, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM1_AXI_CBCR, FORCE_MEM_CORE_ON, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM2_AXI_CBCR, FORCE_MEM_CORE_ON, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM3_AXI_CBCR, FORCE_MEM_CORE_ON, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM4_AXI_CBCR, FORCE_MEM_CORE_ON, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM5_AXI_CBCR, FORCE_MEM_CORE_ON, 0x1);

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM0_AXI_SREGR, PSCBC_SLP_STG_MODE_CSR, 0x0 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM0_AXI_CBCR, CLK_ENABLE, 0x1 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM1_AXI_SREGR, PSCBC_SLP_STG_MODE_CSR, 0x0 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM1_AXI_CBCR, CLK_ENABLE, 0x1 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM2_AXI_SREGR, PSCBC_SLP_STG_MODE_CSR, 0x0 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM2_AXI_CBCR, CLK_ENABLE, 0x1 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM3_AXI_SREGR, PSCBC_SLP_STG_MODE_CSR, 0x0 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM3_AXI_CBCR, CLK_ENABLE, 0x1 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM4_AXI_SREGR, PSCBC_SLP_STG_MODE_CSR, 0x0 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM4_AXI_CBCR, CLK_ENABLE, 0x1 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM5_AXI_SREGR, PSCBC_SLP_STG_MODE_CSR, 0x0 );
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SRAM5_AXI_CBCR, CLK_ENABLE, 0x1 );


    ulRegOut = HWIO_IN( SAILSS_CSR_RTCU_CONTROL);
    ulRegOut &= (~((BIT_1)));
    HWIO_OUT( SAILSS_CSR_RTCU_CONTROL, ulRegOut);

/*
    pc_sleep_test_AssertCoreReset(3);
    pc_sleep_test_AssertCoreReset(2);

    pc_sleep_test_AeassertClusterReset(1);

    pc_sleep_test_AssertCoreReset(1);


    pc_sleep_test_initsmp_for_wfi();
*/

    HWIO_OUTF( SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0, CFGVECTABLE, (SAILBSP_ENTRY_BASE)>>5);

    HWIO_OUTF( SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0, CFGVECTABLE, (SAILBSP_ENTRY_BASE)>>5);

    HWIO_OUTF( SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0, CFGVECTABLE, (SAILBSP_ENTRY_BASE)>>5);

    HWIO_OUTF( SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0, CFGVECTABLE, (SAILBSP_ENTRY_BASE)>>5);


    return SLEEP_ERR_FLAG_SUCCESS;
}


/*=========================================================================================================
 @Service name        xSleepConfig
 @Description         xSleepConfig function is used to do configuration required for deep sleep / Str
 @param[in]           sleepModeType_e <STR_SLEEP_MODE, DEEP_SLEEP_MODE>
 @param[out]          <No Input Parameter>
 @param[in, out]      NA
 @return              sleepErrType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

void prvSleepConfig (sleepModeType_e xSleepMode)
{
    uint32 ulRegOut = 0x0;

    if( STR_SLEEP_MODE == xSleepMode )
    {
        HWIO_OUT(SAILSS_PWR_CTRL_ISD_SPARE_REG_0, 0x3FF);// TODO: Need to move to ISD Init

        /* Below Can be moved to ISD */

        HWIO_OUT( SAILSS_PWR_CTRL_ISD_SPARE_REG_0, 0x0);

        HWIO_OUT(SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK, 0x0);

        /*TODO: 6.  GPIOs Low Power Programming
            a.  Need to enable all Wake IO SAIL_MX paths
            b.  Please follow Section 2.4 - Interrupts / MPM wake up Interrupts in TLMM HPG – 
            https://dragoncompiler.qualcomm.com/release/hpg/default/index.html?hpg_id=1995&ver=0.4&loc=hpg%3Adefault%3Arelease
            SAIL_PWR_RDY - SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1 - bit 10 - value 1
            PSAIL_ERR_N - SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1 - bit 12 - value 1
        */

        prvSleepGpio();
        /*
            13. Disable unwanted Fatal error detection for the sail_ps_hold de-assertion during the Low power.
            a.  Program SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK to 0x167
        */
        HWIO_OUT(SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK, 0x167);

        /*
            TODO :5.  SAIL_SW to Disable vsense_controller
            a.  Program as per vsense_controller HPG – 
            https://qualcomm.sharepoint.com/:w:/r/teams/IPCatalog/HPG/Power/vsense_controller_4.0.0_
            HPG.docm?d=w29a8b4da9bad4e5e9418238d7f12fa55&csf=1&web=1&e=f5VuZA
        */


        /*4.  Error Aggregator Module Low Power Programming
            a.  SAIL_SW to poll for any pending FUSA errors and complete the necessary actions prior to disabling all the Error Monitoring
                i.  Read the registers SAILSS_CSR_FUSA_ERROR_STATUS_0..7 and make sure no existing FUSA errors.
            b.  SAIL_SW to Disable the error monitoring in Error Aggregator Module and assert the SM_ERROR.
                i.  Program SAILSS_CSR_spare_reg0[5:1] to 5'b0
                ii. Program SAILSS_CSR_SM_ERROR_CTRL_2[CFG_SW_ASSERT_ERR] to 0x1
            c.  Disable all Island State Detector and Power Controller glitch sources
                i.  Program SAILSS_PWR_CTRL_ISD_SPARE_REG_0 = 0x0
                ii. Program SAILSS_PWR_CTRL_PwR_CTRL_SPARE_REG_0[20:2]=0x0
        */


        ulRegOut = HWIO_IN(SAILSS_CSR_SPARE_REG0);
        ulRegOut &= (~(0x3e)); 
        HWIO_OUT(SAILSS_CSR_SPARE_REG0 , ulRegOut);

    }else if( DEEP_SLEEP_MODE == xSleepMode )
    {
        HWIO_OUT(SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK, 0xC00);
        HWIO_OUT(SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK, 0x1E4);

    }else
    {
        //Added for misra
    }
}




/*=========================================================================================================
 @Service name        prvSleepGpio
 @Description         prvSleepGpio function is used to enable all Wake IO SAIL_MX paths
 @param[in]           <No Input Parameter>
 @param[out]          <No Input Parameter>
 @param[in, out]      NA
 @return              sleepErrType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


sleepErrType_e prvSleepGpio(void)
{

    uint32 ulRegOut = 0x0;

    #if lemans

    ulRegOut = HWIO_IN(SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_0);
    HWIO_OUT( SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_0 , ulRegOut | BIT_12 | BIT_11| BIT_10| BIT_1 );

    ulRegOut = HWIO_IN(SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1);
    HWIO_OUT( SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1 , ulRegOut | BIT_10 | BIT_1 | BIT_0);
    #else

        ulRegOut = HWIO_IN(SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1);
        HWIO_OUT( SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1 , ulRegOut | BIT_4 | BIT_3 | BIT_1);

    #endif

    return SLEEP_ERR_FLAG_SUCCESS;
}


/*=========================================================================================================
 @Service name        prvSleepAsilDNocReset
 @Description         prvSleepAsilDNocReset function is used to reset ASIL D NOC
 @param[in]           <No Input Parameter>
 @param[out]          <No Input Parameter>
 @param[in, out]      NA
 @return              sleepErrType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/
sleepErrType_e prvSleepAsilDNocReset(void)
{
    uint16 usTimeout = 0u;
    /*ASIL_D, NoC Partial reset trigger*/
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTREQN, 0x0);

    while((HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTACKN)) && (usTimeout <= ASIL_D_NOC_PARTIAL_RESET_TIMEOUT))
    {
        busywait(1U);
		++usTimeout;
	}
	
	if(usTimeout >= ASIL_D_NOC_PARTIAL_RESET_TIMEOUT)
    {
		return SLEEP_ERR_EXIT_FAIL;
	}		

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_CBCR, CLK_ARES, 0x1);


    busywait(10U);

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_CBCR, CLK_ARES, 0x0);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET, RSTREQN, 0x1);

    busywait(10U);

#if defined (SAIL_RTOS)   
	/*ASIL_B, NoC Partial reset trigger*/
	usTimeout = 0x0;
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTREQN, 0x0);

    while((HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTACKN)) && (usTimeout <= ASIL_D_NOC_PARTIAL_RESET_TIMEOUT))
    {
        busywait(1U);
		++usTimeout;
	}
	
	if(usTimeout >= ASIL_D_NOC_PARTIAL_RESET_TIMEOUT)
    {
		return SLEEP_ERR_EXIT_FAIL;
	}		

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_CBCR, CLK_ARES, 0x1);


    busywait(10U);

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_CBCR, CLK_ARES, 0x0);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_PARTIAL_RESET, RSTREQN, 0x1);

    busywait(10U);
#endif

    return SLEEP_ERR_FLAG_SUCCESS;
}


/*=========================================================================================================
 @Service name        xSleepEl2Exit
 @Description         xSleepEl2Exit function will enable Seq needed on sleep exit path 
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              sleepErrType_e
 @Pre                 PMICInit,PCInit,ISD,CLKInit should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

sleepErrType_e xSleepEl2Exit(void)
{
    uint64 puReasonMask = 0x0;
    uint32 ulRegOut = 0x0;
    sleepErrType_e xSleepStatus = SLEEP_ERR_FLAG_SUCCESS;
    PCStatusType_e xPcStatus = PC_STATUS_SUCCESS;

    xPcStatus = xPCSleepExitEL2();

    if ( xPcStatus != PC_STATUS_SUCCESS )
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    vsleepDataUpdate(SLEEP_EXIT_MARKER);

    //d.   Turn ON all the PLLs except PLL5 Manually. TODO: Need to be removed
    HWIO_OUT(SAILSS_CLKCTL_SAILSS_CC_PLL0_PLL_MODE,0xE0000005);
    HWIO_OUT(SAILSS_CLKCTL_SAILSS_CC_PLL0_PLL_OPMODE,0x1);

    if ( CLOCK_SUCCESS !=  Clock_SleepExit())
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CFG_RCGR, SRC_SEL, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CFG_RCGR, SRC_DIV, 0xF);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CMD_RCGR, UPDATE, 1);
    while(HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_HWKM_KM_CMD_RCGR, UPDATE));

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ACC_CFG_RCGR, SRC_SEL, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ACC_CFG_RCGR, SRC_DIV, 0x5);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ACC_CMD_RCGR, UPDATE, 1);
    while(HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_ACC_CMD_RCGR, UPDATE));

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CE1_CFG_RCGR, SRC_SEL, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CE1_CFG_RCGR, SRC_DIV, 0x5);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CE1_CMD_RCGR, UPDATE, 1);
    while(HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_CE1_CMD_RCGR, UPDATE));

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_LBIST_CFG_RCGR, SRC_SEL, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_LBIST_CFG_RCGR, SRC_DIV, 0x9);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_LBIST_CMD_RCGR, UPDATE, 1);
    while (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_LBIST_CMD_RCGR, UPDATE));

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_PRIM_CFG_RCGR, SRC_SEL, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_PRIM_CFG_RCGR, SRC_DIV, 0x3);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_PRIM_CMD_RCGR, UPDATE, 1);
    while (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_PRIM_CMD_RCGR, UPDATE));

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_SEC_CFG_RCGR, SRC_SEL, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_SEC_CFG_RCGR, SRC_DIV, 0x3);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_SEC_CMD_RCGR, UPDATE, 1);
    while (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_VSENSOR_SEC_CMD_RCGR, UPDATE));

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CFG_RCGR, SRC_SEL, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CFG_RCGR, SRC_DIV, 0x2);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CMD_RCGR, UPDATE, 1);
    while (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_PKA_CORE_CMD_RCGR, UPDATE));


    /* TODO : 10. SAIL_SW to Enable vsense_controller
        a.  Program as per vsense_controller HPG – https://qualcomm.sharepoint.com/:w:/r/teams/IPCatalog
        /HPG/Power/vsense_controller_4.0.0_HPG.docm?d=w29a8b4da9bad4e5e9418238d7f12fa55&csf=1&web=1&e=f5VuZA
    */


    /* 11.  Error Aggregator Module Low Power Programming */

    // a.   Clear the FUSA errors status registers. These are W1TC registers.    
    HWIO_OUT(SAILSS_CSR_FUSA_ERROR_STATUS_0, 0xFFFFFFFFU);
    HWIO_OUT(SAILSS_CSR_FUSA_ERROR_STATUS_1, 0xFFFFFFFFU);
    HWIO_OUT(SAILSS_CSR_FUSA_ERROR_STATUS_2, 0xFFFFFFFFU);
    HWIO_OUT(SAILSS_CSR_FUSA_ERROR_STATUS_3, 0xFFFFFFFFU);
    HWIO_OUT(SAILSS_CSR_FUSA_ERROR_STATUS_4, 0xFFFFFFFFU);
    HWIO_OUT(SAILSS_CSR_FUSA_ERROR_STATUS_5, 0xFFFFFFFFU);
    HWIO_OUT(SAILSS_CSR_FUSA_ERROR_STATUS_6, 0xFFFFFFFFU);
    HWIO_OUT(SAILSS_CSR_FUSA_ERROR_STATUS_7, 0xFFFFFFFFU);

    /* b. Read SAILSS_CSR_FUSA_ERROR_STATUS_0..7 to make sure all bits are cleared */

    if (0x0U != HWIO_IN(SAILSS_CSR_FUSA_ERROR_STATUS_0))
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    if (0x0U != HWIO_IN(SAILSS_CSR_FUSA_ERROR_STATUS_1))
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    if (0x0U != HWIO_IN(SAILSS_CSR_FUSA_ERROR_STATUS_2))
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    if (0x0U != HWIO_IN(SAILSS_CSR_FUSA_ERROR_STATUS_3))
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    if (0x0U != HWIO_IN(SAILSS_CSR_FUSA_ERROR_STATUS_4))
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    if (0x0U != HWIO_IN(SAILSS_CSR_FUSA_ERROR_STATUS_5))
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    if (0x0U != HWIO_IN(SAILSS_CSR_FUSA_ERROR_STATUS_6))
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    if (0x0U != HWIO_IN(SAILSS_CSR_FUSA_ERROR_STATUS_7))
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    /* 
     * TODO : Here Init of all driver need to be called out
     */


    /* 
        c.  Remove SW configuration for SM_ERROR assertion.
            i.  Program SAILSS_CSR_SM_ERROR_CTRL_2[CFG_SW_ASSERT_ERR] to 0x0
	    SM Error will be deasserted from SM
    */
    
    /*HWIO_OUTF(SAILSS_CSR_SM_ERROR_CTRL_2, CFG_SW_ASSERT_ERR, 0x0); */

    
    /*
        d.  Enable all Island State Detector and Power Controller glitch sources
            i.  Program SAILSS_PWR_CTRL_ISD_SPARE_REG_0 = 0x3FF
    */
    
    HWIO_OUT(SAILSS_PWR_CTRL_ISD_SPARE_REG_0, 0x3FFU);


    /* 12. Enable PC Glitch source and APM comparator */

    xPcStatus = xPCCtrlGlitchSrcEL2(TRUE);

    if ( PC_STATUS_SUCCESS !=  xPcStatus)
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    /*
        13.   Enable HW Fatal error detection for the boundary Isolation
            a.  Program SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK to 0xC03
    */
    
    HWIO_OUT(SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK, 0xC03);

    /*
        14. Enable HW Fatal error detection for the sail_ps_hold de-assertion during active mode
            a.  Program SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK to 0x1FC
    */
    
    HWIO_OUT(SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK, 0x1FC);

    xPcStatus = xPCPopulateWakeupReasonEL2(&puReasonMask);

    if ( PC_STATUS_SUCCESS != xPcStatus  )
    {
        xSleepStatus = SLEEP_ERR_EXIT_FAIL;
        goto sleepSailErr;
    }

    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CBCR, FORCE_MEM_PERIPH_ON, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CBCR, FORCE_MEM_PERIPH_ON, 0x1);

    sleepSailErr:
        return xSleepStatus;
}


SAIL_DEFINE_SYSCALL(  SLEEP_RTCU_SETTING,
                      SLEEP_RTCU_SETTING_PARM_ID,
                      0,
                      SleepSysCallsleepRTCUSetting
                    );

SAIL_DEFINE_SYSCALL(  SLEEP_CLOCK_DISABLE,
                      SLEEP_CLOCK_DISABLE_PARM_ID,
                      0,
                      SleepSysCallsleepclockdisable
                    );

SAIL_DEFINE_SYSCALL(  SLEEP_DATA,
                      SLEEP_DATA_PARM_ID,
                      0,
                      SleepSysCallsleepDataUpdate
                    );

SAIL_DEFINE_SYSCALL(  SLEEP_GET_DATA,
                      SLEEP_GET_DATA_PARM_ID,
                      0,
                      SleepSysCallsleepGetData
                    );


SAIL_DEFINE_SYSCALL(  SLEEP_CONFIG_DATA,
                      SLEEP_CONFIG_DATA_PARM_ID,
                      0,
                      SleepSysCallsleepConfig
                    );


SAIL_DEFINE_SYSCALL(  SLEEP_ASILD_NOC_RESET,
                      SLEEP_ASILD_NOC_RESET_PARM_ID,
                      0,
                      SleepSysCallsleepAsildReset
                    );