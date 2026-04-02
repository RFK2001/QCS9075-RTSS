/*
===========================================================================
*/
/**
    @file  sleepEl1.c
    @brief Defination of El1 function of sleep driver

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
    File Name          : sleepEl1.c
    Component Name     : sleep
    Description        : Defination of El1 function of sleep driver
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sleep/src/sailsw1/sleepEl1.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

#ifdef SAILSW1

#include "types.h"
#include "pwr_controller_el1.h"
#include "sleepEl1.h"
#include "sleep_core.h"
#include "pmicapi.h"
#include "busywait.h"
//#include "wdt_safertos.h"
#include "chipinfo.h"
#include "Clock.h"
#include "ClockDefs.h"
#include "uart.h"
#include "sleepSafeRtos.h"
#include "common_functions.h"
#include "sleep_internal.h"
#include "debug_log.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "HALhwio.h"
#include "err_fatal.h"
#include "commonClient.h"


/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#define CORE1_2_SLEEP_STATUS             0x6u
#define CORE2_SLEEP_STATUS               0x4u
#define MAX_RETRY                        0xFU

extern uint64 ulCoreStatusMask;

uint64 ulSleepCoreStatus = 0x0u;

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

void vsleepDataUpdateEl1(sleepMarkerUpdate_e xdataType)
{
    uint32_t hvcId     = SLEEP_DATA;
    uint32_t paramId   = SLEEP_DATA_PARM_ID;
    uint32_t arg1      = (uint32_t)xdataType;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
    	err_fatal(SLEEP, ERR_FATAL_HVC_CALL_FAILED);
    }
}

/*=========================================================================================================
 @Service name        vSleepConfig
 @Description         vSleepConfig function performs sleep mode configuration
 @param[in]           sleepModeType_e --> STR_SLEEP_MODE, DEEP_SLEEP_MODE
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
void vSleepConfig ( sleepModeType_e xSleepMode )
{
    uint32_t hvcId     = SLEEP_CONFIG_DATA;
    uint32_t paramId   = SLEEP_CONFIG_DATA_PARM_ID;
    uint32_t arg1      = (uint32_t)xSleepMode;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        err_fatal(SLEEP, ERR_FATAL_HVC_CALL_FAILED);
        }
}

/*=========================================================================================================
 @Service name        vSleepResetASILDNoc
 @Description         vSleepResetASILDNoc function does the ASILD/B NoC Reset
 @param[in]           NA
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
void vSleepResetASILDNoc(void)
{
	uint32 xErrFlag = 0;
    uint32 hvcId     = (uint32)SLEEP_ASILD_NOC_RESET;
    uint32 paramId   = (uint32)SLEEP_ASILD_NOC_RESET_PARM_ID;
    uint32 arg1      = 0;
    uint32 arg2      = 0;
    uint32 arg3      = 0;
    uint32 arg4      = 0;

    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
        err_fatal(SLEEP, ERR_FATAL_HVC_CALL_FAILED);
    }
    else
    {
	}
	
	if(SLEEP_ERR_FLAG_SUCCESS != (sleepErrType_e) paramId)
	{
		err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
	}
	
    return ;
}

#include "gpio.h"

/*=========================================================================================================
 @Service name        xSleepEnter
 @Description         xSleepEnter function will enable Seq needed on sleep entry path 
 @param[in]           sleepModeType_e --> STR_SLEEP_MODE, DEEP_SLEEP_MODE
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

sleepErrType_e xSleepEnter(sleepModeType_e xSleepMode)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint64 ulSleepCoreStatus = 0x0u;
    uint8 ucCluster0Id = 0x0u;
    uint8 ucMaxCount = MAX_RETRY;

    ulSleepCoreStatus = in_dword(SLEEP_CORE_STATUS);

    if (  xSleepMode < STR_SLEEP_MODE || xSleepMode >= INVALID_SLEEP_MODE )
    {
        return SLEEP_ERR_ENTRY_FAIL;
    }


    while( ulCoreStatusMask != ulSleepCoreStatus && 0U != ucMaxCount)
    {
        vFreeRTOSTaskDelay(1u); //Adding delay of 15msec to allow other core to go into WFI State
        ulSleepCoreStatus = in_dword(SLEEP_CORE_STATUS);
        ucMaxCount--;
    }

    if ( ulSleepCoreStatus != ulCoreStatusMask )
    {
        DEBUG_LOG(SAIL_ERROR,"Sleep Ack from other core Failed Ex : 0x%x Ac :0x%x \r\n",ulCoreStatusMask,ulSleepCoreStatus);
        return SLEEP_ERR_ENTRY_FAIL;
    }


    if ( SLEEP_ERR_FLAG_SUCCESS != xSleepDriverStatusEl1(get_curr_phys_cpu_num())) // wait function to check if all register tasks
                                                                      // went to sleep state
    {
        return SLEEP_ERR_ENTRY_FAIL;
    }

    if ( STR_SLEEP_MODE == xSleepMode )
    {

        vSleepConfig(STR_SLEEP_MODE);

        /* Disable PC Glitch source and APM comparator */
        if (PC_STATUS_SUCCESS != xPCCtrlGlitchSrcEL1(FALSE))
        {
            return SLEEP_ERR_ENTRY_FAIL;
        }

        /*
            3.  SAIL PMIC Low Power Entry Programming
                a.  Incase of Independent PMIC, Program SAIL_PMIC Registers to set SAIL_MX to Turbo and SAIL_CX to NOM through I2C commands
                b.  Wait for 2ms
                c.  Poll the PMIC registers to check the rail voltages.
                d.  In 2ms, rails would have reached to required values. If not repeat steps #3 & #4 till the rails reached the prescribed voltages.
        */

        if ( TRUE == bSailPmicPresent() )
        {
            xErrFlag = xPmicChangeCornerVolt(PMIC_CX_RAIL,PMIC_CPR_VOLTAGE_LEVEL_TURBO);
            xErrFlag |= xPmicChangeCornerVolt(PMIC_MX_RAIL,PMIC_CPR_VOLTAGE_LEVEL_NOMINAL);

            if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
            {
                return SLEEP_ERR_ENTRY_FAIL;
            }

            busywait(2000); // 2msec
        }
		vSleepResetASILDNoc();
    }else if ( DEEP_SLEEP_MODE == xSleepMode )
    {
        vSleepConfig(DEEP_SLEEP_MODE);
    }else
    {
        /*added for misra*/
    }

    return SLEEP_ERR_FLAG_SUCCESS;

}

/**********************************************************************************************************
**                                  End of file sleepEL1.c                                               **
**********************************************************************************************************/

#endif /* SAILSW1 */
