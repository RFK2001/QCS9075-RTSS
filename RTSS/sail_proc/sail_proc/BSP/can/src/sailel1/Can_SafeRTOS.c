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
/*==============================================================================
    File Name.............. : Can_Safertos.c
    Description............ : This file contains functionality specific for SafeRTOS
    Autosar Release Version : 
    Platform............... :
    SW Release Version..... :
==============================================================================*/
/*==============================================================================
|                       MISRA-C VIOLATIONS                                     |
==============================================================================*/
/*
*/
#ifdef __cplusplus
extern "C"{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
#include "Can_SafeRTOS.h"
#include "Can_Irq.h"
#include "Can_Plt_Cfg.h"
#include "interrupts.h"

/*==============================================================================
|                       GLOBAL CONSTANTS                                       |
==============================================================================*/
/*==============================================================================
|                       GLOBAL VARIABLES                                       |
==============================================================================*/
/* DET FLAG */
CAN_DATA uint8 DetReportedOnCan;
CAN_DATA uint8 DetReportedOnTcan1044;
CAN_DATA uint8 DetReportedOnTcan1146;

/*==============================================================================
|                       LOCAL STRUCTURES, ENUMS, TYPEDEFS                      |
==============================================================================*/

/*==============================================================================
|                       LOCAL CONSTANTS and MACROS                             |
==============================================================================*/

/*==============================================================================
|                       LOCAL FUNCTION PROTOTYPES                              |
==============================================================================*/


/*==============================================================================
|                       LOCAL VARIABLES                                        |
==============================================================================*/


/*==============================================================================
|                       FUNCTION DEFINITIONS                                   |
==============================================================================*/

Std_ReturnType Can_Safertos_Interrupt_Register(uint8 ControllerId)
{
    intEl1Status_t xIntStatus = INT_EL1_ERR_GENERIC;
    Can_IRQ_Config_Type irq_cfg = {0};
    for(uint8 i = 0u; i < (uint8)NUM_IRQ_PER_CAN_CONTROLLER; i++)
    {
        Can_Plt_Cfg_Get_IRQ(ControllerId, i, &irq_cfg);

        xIntStatus = xGicSetIntEnable(irq_cfg.int_num, (boolean)FALSE);
        if(INT_EL1_SUCCESS != xIntStatus)
        {
            return E_NOT_OK;
        }
        xIntStatus = xGicRegisterIntHandler(irq_cfg.int_num, (InterruptHandle_t)irq_cfg.can_int_handler, (void*)&irq_cfg.Can_Controller_id);
        if(INT_EL1_SUCCESS != xIntStatus)
        {
            return E_NOT_OK;
        }

        xIntStatus = xGicConfigureInt(irq_cfg.int_num, (enum InterruptConfig_t)irq_cfg.int_cfg, NULL);
        if(INT_EL1_SUCCESS != xIntStatus)
        {
            return E_NOT_OK; 
        }
        xIntStatus = xGicSetIntEnable(irq_cfg.int_num, (boolean)TRUE);
        if(INT_EL1_SUCCESS != xIntStatus)
        {
            return E_NOT_OK;
        }

    }
    DEBUG_LOG( SAIL_DEBUG,"%s: Done \r\n",__func__);
    return E_OK;
}

Std_ReturnType Can_Safertos_Interrupt_Deregister(uint8 ControllerId)
{
    intEl1Status_t xIntStatus = INT_EL1_ERR_GENERIC;
    Can_IRQ_Config_Type irq_cfg = {0};

    for(uint8 i = 0u; i < (uint8)NUM_IRQ_PER_CAN_CONTROLLER; i++)
    {
        Can_Plt_Cfg_Get_IRQ(ControllerId, i, &irq_cfg);
        xIntStatus = xGicSetIntEnable(irq_cfg.int_num, (boolean)FALSE);
        if(INT_EL1_SUCCESS != xIntStatus)
        {
            return E_NOT_OK;
        }
        else
        {
            xIntStatus = xGicUnRegisterIntHandler(irq_cfg.int_num, (uint32_t)0x0U );
            if(INT_EL1_SUCCESS != xIntStatus)
            {
            return E_NOT_OK;
            }
        }
    }
    DEBUG_LOG( SAIL_DEBUG,"%s: Done \r\n",__func__);
    return E_OK;
}

Std_ReturnType Can_Safertos_Enable_Clock(uint8 ControllerId)
{
    ClockIdType nClockId  = {0};
    uint32_t ulGetfreq = 0U;
    bool pbIsEnabled = FALSE;
    ClockHandle hClient = 0U;
    (void)Clock_GetHandle(&hClient);
    CAN_MTTCAN_ClockType clock_cfg = {0};

	for (uint8 i = 0u; i < (uint8)NUM_CLOCKS_PER_CAN_CONTROLLER ;  i++)
	{
		Can_Plt_Cfg_Get_Clock(ControllerId, i, &clock_cfg);
		if ( CLOCK_SUCCESS != Clock_GetClockId( hClient, clock_cfg.clkName, &nClockId)){
            DEBUG_LOG( SAIL_DEBUG,"%s: Clock_GetClockId fail \r\n",__func__);
            return E_NOT_OK;
        }
        if ( CLOCK_SUCCESS != Clock_IsClockEnabled(hClient,nClockId,&pbIsEnabled)){
            DEBUG_LOG( SAIL_DEBUG,"%s: Clock_IsClockEnabled fail \r\n",__func__);
            return E_NOT_OK;
        } else {
            if(pbIsEnabled == true){
                break;
            }
        }

        if(CLOCK_SUCCESS != Clock_SetClockFrequency (hClient, nClockId, clock_cfg.freq, CLOCK_FREQUENCY_MHZ_AT_LEAST, ( uint32 *)&ulGetfreq))
        {
            DEBUG_LOG( SAIL_DEBUG,"%s: Clock_SetClockFrequency fail \r\n",__func__);
            return E_NOT_OK;
        }
        if (CLOCK_SUCCESS != Clock_EnableClockEx(hClient, nClockId, 0))
        {
            DEBUG_LOG( SAIL_DEBUG,"%s: Clock_EnableClock fail \r\n",__func__);
            return E_NOT_OK;
        }
    }
    return E_OK;
}

Std_ReturnType Can_Safertos_Disable_Clock(uint8 ControllerId)
{
    ClockIdType nClockId  = {0};
    bool pbIsEnabled = TRUE;
    ClockHandle hClient = (ClockHandle)NULL;
    (void)Clock_GetHandle(&hClient);
    CAN_MTTCAN_ClockType clock_cfg = {0};

   	for (uint8 i = 0u; i < (uint8)NUM_CLOCKS_PER_CAN_CONTROLLER ;  i++)
	{
	    Can_Plt_Cfg_Get_Clock(ControllerId, i, &clock_cfg);
        if ( CLOCK_SUCCESS != Clock_GetClockId( hClient, clock_cfg.clkName, &nClockId)){
            return E_NOT_OK;
        }

         if ( CLOCK_SUCCESS != Clock_IsClockEnabled(hClient,nClockId,&pbIsEnabled)){
            return E_NOT_OK;
        } else {
            if(pbIsEnabled == false){
                break;
            }
        }

        if (CLOCK_SUCCESS != Clock_DisableClockEx(hClient, nClockId, 0))
        {
            return E_NOT_OK;
        }
    }
    return E_OK;
}

Std_ReturnType Can_Safertos_Config_Gpio(uint8 ControllerId)
{
    Can_Gpio_Pin_Type gpio_cfg;

	for (uint8 i = 0u; i < (uint8)NUM_GPIO_PER_CAN_CONTROLLER ;  i++)
	{
	    Can_Plt_Cfg_Get_Gpio(ControllerId, i, &gpio_cfg);
        if (GPIO_E_NOT_OK == sail_gpio_config_pin((uint32_t)(gpio_cfg.num), gpio_cfg.cfg))
        {
            DEBUG_LOG( SAIL_DEBUG,"%s: CAN ID = %d GPIO config fail \r\n",__func__, ControllerId);
            return E_NOT_OK;
        }
    }
    return E_OK;
}

void Can_Safertos_Get_TransceiverId_For_Can(uint8 ControllerId, CAN_TRCV_MAP_Type* trcv_type, uint8* trcv_channel_id)
{
    Can_Plt_Get_TransceiverId_For_Can(ControllerId, trcv_type, trcv_channel_id);
    DEBUG_LOG( SAIL_DEBUG,"%s: CAN ID = %d, trcv_type = %d, trcv_channel_id = %d \r\n",__func__, ControllerId, *trcv_type, *trcv_channel_id);
}

/*========================================================================================================
 @Service name        Det_ReportError
 @Description         Service to report development errors
 @param[in]           -
 @param[out]          -
 @param[in, out]      -
 @return              -
 @Pre                 -
 @Post                -
 @Requirements IDs    -
 @Design IDs          -
 @service ID          0x01
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant
 @Note                Dummy stub function
============================================================================================================*/
Std_ReturnType Det_ReportError (
uint16 ModuleId,
uint8 InstanceId,
uint8 ApiId,
uint8 ErrorId
)
{
    if(ModuleId == 0x50u){
        /*0x50 stands for CAN module ID*/
        DetReportedOnCan = 1;
    }

    if (ModuleId == 0x0046u &&
        InstanceId == 1u)
    {
        DetReportedOnTcan1044 = 1;
    }

    if (ModuleId == 0x0046u &&
        InstanceId == 0u)
    {
        DetReportedOnTcan1146 = 1;
    }

    DEBUG_LOG( SAIL_ERROR," Det_ModuleId = %d, Det_InstanceId= %d,   Det_ApiId= %d,    Det_ErrorId= %d, <<<<<<<\r\n",
                                         ModuleId, InstanceId, ApiId, ErrorId );
    return 0;
}

/*=========================================================================================================
 @Service name        Det_ReportRuntimeError
 @Description         Service to report development errors
 @param[in]           -
 @param[out]          -
 @param[in, out]      -s
 @return              -
 @Pre                 -
 @Post                -
 @Requirements IDs    -
 @Design IDs          -
 @service ID          0x04
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant
 @Note                Dummy stub function
=========================================================================================================*/
Std_ReturnType Det_ReportRuntimeError (
uint16 ModuleId,
uint8 InstanceId,
uint8 ApiId,
uint8 ErrorId
)
{
    DEBUG_LOG( SAIL_ERROR," Det_ModuleIdRunErr = %d, Det_InstanceIdRunErr= %d,   Det_ApiIdRunErr= %d,    Det_ErrorIdRunErr= %d, <<<<<<<\r\n",
                                         ModuleId, InstanceId, ApiId, ErrorId );
    return 0;
}

#ifdef __cplusplus
}
#endif
/*==============================================================================
==============================================================================*/

