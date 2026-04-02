/*
===========================================================================
*/
/**
    @file  isd_resets.c
    @brief This file implements the resets handling from ISD

*/
/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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

#include "isd_drv.h"
#include "isd_resets.h"
#include "pmicapi.h"
#include "chipinfo.h"
#include "HALhwio.h"
#include "sail_csr_hwio.h"
#include "debug_log.h"
#include "Crashdbg_api.h"
#include "logcode.h"
#include "mailboxExt_api.h"
#include "isd.h"
#include "isd_common_def.h"
#include "err_fatal.h"
#include "xbl_def.h"
#include "isd_cfg.h"
#include "AccessControlAPI.h"
#include <timetick.h>

extern ISD_ErrCode_sailboot eISD_GetSailBootErrorCode(eXblImageIdType image_id);

/* MD_PS_HOLD_MASK Status Register
*/
#define SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK       0xF1149420u
#define SAIL_FOLLOW_MD_FSM_STATE_MASK_VAL             0xCFF8u


/* ToDo - MD Interrupt reason from shadow register to be passed from ISD Interrupt context to Task Context */

  #define WR_SAIL_ISLAND           0xCD050000UL
  #define AUTH_FAIL_SWITCH_LUN_HR  0xCC020000UL
  #define FAILURE_FORCE_PASS2      0xCC040000UL
  #define RESET_READY              0xCC050000UL
  #define SW_MD_CR                 0xCD010000UL


static const ISD_IntrConfigType stISDSailMDStatus[] = {
                                                            { MD_SEC_FUSE_HR              , 0xCD000000u },
                                                            { MD_SW_CR                    , 0xCD010000u },
                                                            { MD_VSENSE_STATUS            , 0xCD020001u },
                                                            { MD_SOC_WR                   , 0xCD030000u },
                                                            { MD_WR_SAIL_ISLAND           , 0xCD050000u },
                                                            { MD_DDR_READY                , 0xCC010000u },
                                                            { MD_AUTH_FAIL_SWITCH_LUN_HR  , 0xCC020000u },
                                                            { MD_FORCE_EDL                , 0xCC030000u },
                                                            { MD_FAILURE_FORCE_PASS2      , 0xCC040000u },
                                                            { MD_RESET_READY              , 0xCC050000u },
                                                            { MD_GRACEFUL_SHUTDOWN        , 0xCD060000u },
                                                            { XBLSEC_BOOT_SUCCESS         , 0xCB000001u },
                                                            { XBLLDR_BOOT_SUCCESS         , 0xCB000003u },
                                                            { TZ_BOOT_SUCCESS             , 0xCB000007u },
                                                            { QHEE_BOOT_SUCCESS           , 0xCB00000Fu },
                                                            { UEFI_BOOT_SUCCESS           , 0xCB00001Fu },
                                                            { ABL_BOOT_SUCCESS            , 0xCB00003Fu },
                                                            { MD_SOC_HR                   , 0xCD070000u },
															{ MD_SAIL_LPM_DDR_SUSPEND 	  , 0xD0030000u },
                                                            { MD_S1_READY           	  , 0xD0000000u },
															{ MD_MB_READY           	  , 0xD0020000u },
                                                            { SAIL_SEC_FUSE_HR            , 0xAA010000u },
                                                            { SAIL_VSENSE_READY           , 0xAA020000u },
                                                            { SAIL_RESET_READY            , 0xAA030000u },
                                                            { SAIL_RGMII_VOL_SEL          , 0xAA040000u },
                                                            { SAIL_SW_CR                  , 0xAA050000u },
                                                            { SAIL_TEST_MANAGER_MODE      , 0xAA060000u },
                                                            { SAIL_ISLAND_READY           , 0xAA070000u },
                                                            { SAIL_OSPI_MD_CTRL           , 0xAA080000u },
                                                            { SAIL_QAMV4_DETECTION        , 0xCC070000u },
                                                        };

#define ARRAY_SIZE(x)      (sizeof((x))/sizeof((x)[0]))

/*===========================================================================
**  Function :  prvISDGetMDStatus
** ==========================================================================
*/
/*!
*
* @brief
*   This functions reads the shadow registers and returns the value as a uint32
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   uint32          : MD shadow register value
*
*/
static uint32 prvISDGetMDStatus(void)
{
    uint32 nReturnValue = 0u;

    nReturnValue = ( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_IN & 0xFFu );
    nReturnValue |= (( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_IN & 0xFFu ) << 8u );
    nReturnValue |= (( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_IN & 0xFFu ) << 16u );
    nReturnValue |= (( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_IN & 0xFFu ) << 24u );

    return nReturnValue;
}


/*===========================================================================
**  Function :  prvISDSetSAILMDMsg
** ==========================================================================
*/
/*!
*
* @brief
*   This functions updates the shadow registers with value from a uint32
*
* @param
*   nStatus         : Value to be written to the 4 shadow registers
* @par Dependencies
*   None
* @retval
*   None
*
*/
static void prvISDSetSAILMDMsg(uint32 nStatus)
{
    HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_OUT( nStatus & 0x000000FFu );
    HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_OUT((( nStatus & 0x0000FF00u ) >> 8u ));
    HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_OUT((( nStatus & 0x00FF0000u ) >> 16u ));
    HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_OUT((( nStatus & 0xFF000000u ) >> 24u ));
    DEBUG_LOG(SAIL_WARNING, "Ack sent to MD : 0x%X\r\n", nStatus);
}

/*===========================================================================
**  Function :  prvXBLIPCNonSecISR
** ==========================================================================
*/
/*!
*
* @brief
*   ISR for non secure interrupt from MD boot stages
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   None
*
*/
void prvIPCNonSecISR(void *args)
{
    ISD_DriverContext_t *pContxt = (ISD_DriverContext_t *) args;
    uint8 i = 0;
    ISD_SailMDStatusType nIntrReason = ISD_TaskStatesMAX;
    uint32 nStatus = 0;

    /* Get MD boot stages status via shadow register */
    nStatus = prvISDGetMDStatus();
    /* Find interrupt reason*/
    for(i = (uint8_t)MD_SEC_FUSE_HR; i < ARRAY_SIZE(stISDSailMDStatus); i++)
    {
        if( stISDSailMDStatus[i].value == nStatus)
        {
            /* Interrupt reason is found */
            nIntrReason = stISDSailMDStatus[i].eIntrReason;
            break;
        }
    }
    DEBUG_LOG(SAIL_WARNING, "Received MD Interrupt : 0x%X\r\n", nStatus);

    /* Call the error handler API*/
    prvISD_MDIntrHandler(&pContxt, nIntrReason);
}

/*===========================================================================
**  Function :  prvTZIPCSecISR
** ==========================================================================
*/
/*!
*
* @brief
*   ISR for TZ secure interrupt
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   None
*
*/
void prvTZIPCSecISR(void *args)
{
    ISD_DriverContext_t *pContxt = (ISD_DriverContext_t *) args;
    uint8 i = 0;
    ISD_SailMDStatusType nResetReason = ISD_TaskStatesMAX;
    uint32 nStatus = 0;
#ifdef ISD_RTOS_ENABLE
    ISD_QueueMsgType xISDMsg = { 0 };
    portBaseType 	xQSendStatus 			  = pdFAIL;
#endif

    nStatus = prvISDGetMDStatus();
    /* Find interrupt reason*/
    for(i = (uint8_t)MD_SEC_FUSE_HR; i < ARRAY_SIZE(stISDSailMDStatus); i++)
    {
        if( stISDSailMDStatus[i].value == nStatus)
        {
            /* Interrupt reason is found */
            nResetReason = stISDSailMDStatus[i].eIntrReason;
            break;
        }
    }
    DEBUG_LOG(SAIL_WARNING, " Received MD TZ Interrupt: 0x%X\r\n", nStatus);

#ifdef ISD_RTOS_ENABLE
    /* Send message to queue */
    xISDMsg.eIntrType = NON_SECURE_INTR;
    xISDMsg.stStatus = nResetReason;

    xQSendStatus = xQueueSendToFrontFromISR(xISDQueueHandle, &xISDMsg);
    if(xQSendStatus != pdPASS)
    {
        /* Queue Send failed. Enable Logging*/

    }
#else
    /* Call the error handler API*/
    prvISD_MDIntrHandler(&pContxt, nResetReason);
#endif
}

/*===========================================================================
**  Function :  prvISD_IPCCIntrHandler
** ==========================================================================
*/
/*!
*
* @brief
*   This functions handles the IPC interrupt by doing one/more of following:
*               1. Sending ACK to MD
*               2. Enabling Isoaltions
*               3. Configuring to PMIC to Warm Reset
*               4. De-assert SAIL_PS_HOLD
*
* @param
*   state       : new state of SAIL
* @par Dependencies
*   None
* @retval
*   None
*
*/
void prvISD_IPCCIntrHandler(isdStatesType_e state)
{
    uint32_t MD_IntrReason = 0u;
     /*
    *   TODO with EL1
    *   Move this handling to the task context with SafeRTOS.
    *   It is placed here for el2 beacuse Isolations shall be
    *   after notifying the client. The client notifications
    *   are sent in IPCC interrupt handler. Since nested interrupts
    *   are not enabled now, notifications will be sent after
    *   enabling isolations, same in case of SAIL_PS_HOLD de-assertion
    *   as well
    */
    MD_IntrReason = prvISDGetMDStatus();

    switch(state)
    {
        case ISLAND_STATE:
#ifdef ISLAND_ENABLE
            /* TODO: call SAIL de-init API */
			/* ACK to MD only when MD triggers direct interrupt to SAIL about any MD error/crash */
            /* In case of SAIL isolation via FUSA, ACK to MD must be skipped. */
            if ( (MD_IntrReason == AUTH_FAIL_SWITCH_LUN_HR) ||
                     (MD_IntrReason == FAILURE_FORCE_PASS2) ||
                     (MD_IntrReason == WR_SAIL_ISLAND) ||
                     (MD_IntrReason == RESET_READY)
                   )
            {
				if(CHIPINFO_ID_SA_LEMANSAU_IVI == ChipInfo_GetChipId())
				{
					/* Indicate sail is RESET_READY to MD*/
					prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_RESET_READY].value);
				} else
				{
					/* Indicate sail is ISLAND_READY to MD*/
					prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_ISLAND_READY].value);
				}
			}
            eISDEnableIsolations();
            DEBUG_LOG(SAIL_WARNING, "SAIL in island mode \r\n");
#else
            /* PMIC configuration will be the default one, set for mission/production mode. */
            /* ACK to MD only when MD triggers direct interrupt to SAIL about any MD error/crash */
            /* In case of SAIL isolation via FUSA, ACK to MD must be skipped. */
            if (MD_IntrReason == SW_MD_CR)
            {
              /* Indicate sail is RESET_READY to MD*/
              prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_RESET_READY].value);
            } 
#endif
            break;

        case SOC_SHUTDOWN:
        {
            pmicErrFlagType_e eReturnValue;
            
            /*
                MD has requested for SOC Shutdown. Indicate SAIL reset ready and program PMIC for shutdown
                and pull SAIL_PS_HOLD low. For dependent PMIC also de-init all the drivers
            */
            /* TODO: call SAIL de-init API */
            /* Configure PMIC for shutdown and then ack MD. Platform(IVI or ADAS) check is done within PMIC API */
            eReturnValue = xPmicSetResetState(PMIC_POFF);
             if(PMIC_ERR_FLAG_SUCCESS == eReturnValue )
             {
                prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_RESET_READY].value);
             }
        }
        break;

        case SOC_WARM_RESET:
        {
            pmicErrFlagType_e eReturnValue;
            /*
                MD has requested for SOC Warm Reset. Indicate SAIL reset ready and program PMIC for warm reset
                and pull SAIL_PS_HOLD low. For dependent PMIC also de-init all the drivers
            */
            /* Configure PMIC for shutdown and then ack MD. Platform(IVI or ADAS) check is done within PMIC API */
            eReturnValue = xPmicSetResetState(PMIC_WARM_RESET);
            if(PMIC_ERR_FLAG_SUCCESS == eReturnValue )
            {
                /* SAIL shall reset with MD during a)MD XBL direct ramdump, and
                b)MD warm reset island request
                To support island enable/disable requirement within SAIL Image, SAIL must ACK with Island ready to avoid ACK timeout on MD. */
                if ( (MD_IntrReason == FAILURE_FORCE_PASS2) ||
                     (MD_IntrReason == WR_SAIL_ISLAND))
                {
                    prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_ISLAND_READY].value);
                }
                else
                {
                    prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_RESET_READY].value);
                }
            }
        }
            break;

        case SOC_CRASH_RESET:
            /*
                MD known crash. Indicate SAIL reset ready to enter concurrent crash reset.
            */
            /* TODO: call SAIL de-init API */

            prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_RESET_READY].value);
            break;

        case SOC_HARD_RESET:
        {
            pmicErrFlagType_e eReturnValue;
            
            /*
                MD has requested for SOC Hard Reset. Indicate SAIL reset ready and program PMIC for hard reset
                and pull SAIL_PS_HOLD low. For dependent PMIC, de-init all the drivers.
            */
            /* TODO: call SAIL de-init API */

            /* Configure PMIC for hard reset and then ack MD. Platform(IVI or ADAS) check is done within PMIC API */
            eReturnValue = xPmicSetResetState(PMIC_POFF_PON_SKIP_KPD);

            if(PMIC_ERR_FLAG_SUCCESS == eReturnValue )
            {
                /* ToDO - In EL1, Inform FUSA/SM about SOC_HARD_RESET and
                consider MD_PS_HOLD de-assertion as non-fatal in this case */
                #ifdef ISLAND_ENABLE
                prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_RESET_READY].value);
                /* The below code is to overwrite SAIL ACK for below use cases */
                #else
                /* SAIL shall reset with MD during a) MD LUN switch hard reset,
                 and b) MD XBL direct ramdump - hard reset after dump collection.
                To support island enable/disable requirement within SAIL, SAIL must ACK with Island ready to avoid ACK timeout on MD. */
                if ( (MD_IntrReason == AUTH_FAIL_SWITCH_LUN_HR) ||
                 (MD_IntrReason == RESET_READY)
                )
                {
                    prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_ISLAND_READY].value);
                }
                else
                {
                    prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_RESET_READY].value);
                }
                #endif
                /* MD_PS_HOLD will be de-asserted after this ACK. MD_PS_HOLD Neg edge ISR will be executed
               where we will check for this SOC_HARD_RESET case and then de-assert SAIL_PS_HOLD,
               so that both MD and SAIL will go through hard reset */
            }
        }
        break;
        default:
        //default case
        break;
    }
}

/*===========================================================================
**  Function :  prvISD_MDIntrHandler
** ==========================================================================
*/
/*!
*
* @brief
*   This functions handles the MD interrupt by doing one/more of following:
*               1. Updates SAIL context var with the new state
*               2. Sends IPCC Interrupts to all core to notify the registered
*                  clients
*
* @param
*   pISDContext       : ISD Context variable
*   nResetReason      : Status of MD as read from Shadow registers
* @par Dependencies
*   None
* @retval
*   None
*
*/
void prvISD_MDIntrHandler(ISD_DriverContext_t **pISDContext, ISD_SailMDStatusType nResetReason)
{
    int32_t idx = 0;
    ISD_DriverContext_t *pContext = *pISDContext;
    uint32_t ShdwRegVal = 0;
    int32_t ret = 0;
    uint32_t uACStatus = 0U;

    switch(nResetReason)
    {
        case MD_GRACEFUL_SHUTDOWN:

            /* Set Current State and also notify the registered drivers */
            pContext->isdState = SOC_SHUTDOWN;
            /* Disable SAIL SDI or crash reset flow by,
               a) clearing SAIL crash reset debug enablement register and
               b) set "MD_PS_HOLD_MASK" as 0xFFFF */
            if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
            {
              DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
            }
            prvISD_IPCCIntrHandler(pContext->isdState);

        break;

        case MD_AUTH_FAIL_SWITCH_LUN_HR:
        case MD_FAILURE_FORCE_PASS2:
        case MD_WR_SAIL_ISLAND:
        case MD_RESET_READY: //To isolate SAIL during MD PASS2 hard reset(actual MD crash or direct PASS2 entry from MD XBL_LDR)
#ifdef ISLAND_ENABLE
            /* Set Current State and also notify the registered drivers */
            pContext->isdState = ISLAND_STATE;
            pContext->eISDStatus = ISD_MD2SAIL_STATUS_FAILED;//DDR_NOT_READY;
            /* In these use cases, MD will go through reset when SAIL is isolated.
            Hence, mask SAIL to follow MD_PS_HOLD enabled by crash debug feature,
            to avoid SAIL reset */
            if(Crashdbg_disable(DEP_CRASH_DISABLED) != DBG_DISABLED)
            {
                
                DEBUG_LOG(SAIL_ERROR, "Mask SAIL follow MD_PS_HOLD failed \r\n");
            }
            prvISD_IPCCIntrHandler(pContext->isdState);
#else
            /* Set Current State and also notify the registered drivers 
            that it's not a fatal error               */
            if ( (nResetReason == MD_FAILURE_FORCE_PASS2) ||
                 (nResetReason == MD_WR_SAIL_ISLAND) )
            {
              pContext->isdState = SOC_WARM_RESET;
            }
            else
            {
              pContext->isdState = SOC_HARD_RESET;
            }
            /* When MD hard resets via fastboot reboot/qnx reset commands or post MD secure fuse blown,
            allow SAIL to go through hard reset but not crash reset flow.
            Hence, crash debug feature must be disabled to avoid entering crash reset flow upon md_ps_hold low */
            if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
            {
                
                DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
            }
            prvISD_IPCCIntrHandler(pContext->isdState);
#endif

        break;

        case MD_FORCE_EDL:
        case MD_SOC_WR:

            /* Set Current State and also notify the registered drivers */
            pContext->isdState = SOC_WARM_RESET;
            /* When MD warm resets via adb commands or to enter EDL mode,
            allow SAIL to go through warm reset but not crash reset flow.
            Hence, crash debug feature must be disabled to avoid entering crash reset flow upon md_ps_hold low */
            if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
            {

                DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
            }
            prvISD_IPCCIntrHandler(pContext->isdState);

        break;

        case MD_DDR_READY:
        {
            uint32_t log_data = (uint32_t)LC_MD_DDR_READY;

            pContext->eISDStatus = DDR_READY;
            DEBUG_LOG(SAIL_WARNING, "DDR READY \r\n");
            vLCWriteTimeStamp( SAIL_DDR_READY ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case XBLSEC_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_XBLSEC_BOOT;

            pContext->eISDStatus = XBL_SEC_BOOT_SECCESS;
            DEBUG_LOG(SAIL_WARNING, "XBL_SEC BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case XBLLDR_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_XBLLDR_BOOT;

            pContext->eISDStatus = XBL_LOADER_BOOT_SUCCESS;
            DEBUG_LOG(SAIL_WARNING, "XBL_LDR BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case TZ_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_TZ_BOOT;

            pContext->eISDStatus  = TZ_SUCCESS;
            DEBUG_LOG(SAIL_WARNING, "TZ BOOT SUCCESS \r\n");			
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case QHEE_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_QHEE_BOOT;

            pContext->eISDStatus  = QHEE_SUCCESS;
            DEBUG_LOG(SAIL_WARNING, "QHEE BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case UEFI_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_UEFI_BOOT;

            pContext->eISDStatus  = UEFI_SUCCESS;
            DEBUG_LOG(SAIL_WARNING, "UEFI BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case ABL_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_ABL_BOOT;

            pContext->eISDStatus  = ABL_SUCCESS;
            DEBUG_LOG(SAIL_WARNING, "ABL BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case MD_SW_CR:
            /* When SAIL dependent crash for MD fatal error is enabled,
               SAIL will go through crash reset flow, concurrently with MD.
               Otherwise, Isolate SAIL (ISLAND mode) */
            if(Crashdbg_disable(DEP_CRASH_ENABLED) == DBG_SUCCESS)
            {
              /* Set Current State and also notify the registered drivers
              that it's a known crash               */
              pContext->isdState = SOC_CRASH_RESET;
            }
            else
            {
              /* Switch SAIL to Island mode */
              pContext->isdState = ISLAND_STATE;
              pContext->eISDStatus = ISD_MD2SAIL_STATUS_FAILED;
            }
            prvISD_IPCCIntrHandler(pContext->isdState);

	    break;

        case MD_SEC_FUSE_HR:
        case MD_SOC_HR:

            /* Set Current State and also notify the registered drivers
            that it's not a fatal error               */
            pContext->isdState = SOC_HARD_RESET;
            /* When MD hard resets via fastboot reboot/qnx reset commands or post MD secure fuse blown,
            allow SAIL to go through hard reset but not crash reset flow.
            Hence, crash debug feature must be disabled to avoid entering crash reset flow upon md_ps_hold low */
            if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
            {

                DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
            }
            prvISD_IPCCIntrHandler(pContext->isdState);
        break;
		
		case MD_SAIL_LPM_DDR_SUSPEND:
			pContext->eISDStatus  = LPM_DDR_SUSPEND_SUCCESS;
			DEBUG_LOG(SAIL_WARNING,"LPM DDR SUSPEND\n\r");
			break;		
		
        case MD_S1_READY:
			pContext->eISDStatus  = S1_READY_SUCCESS; 
			DEBUG_LOG(SAIL_WARNING,"MD_S1_READY\r\n");
			vMailbox_S1_Handler();
			break;
			
		case MD_MB_READY:
			pContext->eISDStatus  = MB_READY_SUCCESS; 
			DEBUG_LOG(SAIL_WARNING,"MD_MB_READY\r\n");
			vMailbox_S1_Handler();
			break;
        case SAIL_QAMV4_DETECTION:
            pContext-> QAMV4_Present = QAMV4_PRESENT;
            DEBUG_LOG(SAIL_WARNING,"SAIL_QAMV4_DETECTION\r\n");
            break;
        default:
           ShdwRegVal = prvISDGetMDStatus();
           DEBUG_LOG(SAIL_ERROR,"Invalid msg received at SAIL 0x%x\n\r",ShdwRegVal);
        break;
    }
   
    if(TZ_BOOT_SUCCESS <= nResetReason)
    {	
        uACStatus = in_dword(SAILAC_INIT_STATUS);

        if(0UL == uACStatus)
        {
            ret = SAILbspACCalcMSARGGVTrigger();
            if(ret != 0)
            {
                DEBUG_LOG(SAIL_ERROR, "[SAIL AC -ISD]MSA RG Golden Value calculation failure \r\n");
            }
        }
    }
}

/*===========================================================================
**  Function :  eISD_InitiateResetFrmSail
** ==========================================================================
*/
/*!
*
* @brief
*   This functions handles resetting SOC from SAIL by doing one/more of following:
*               1. Updates SAIL context with new ISD state
*               2. Notify all registered clients that it's known reset
*               3. Configuring PMIC for reset(Independent PMIC case)
*				4. Send SOC reset reason to MD.
*               5. De-assert SAIL_PS_HOLD after MD_PS_HOLD is deasserted(Independent PMIC case)
*					to ensure both SAIL and MD resets together i.e SOC Reset
* @param
*   state       : new state of SAIL
* @par Dependencies
*   None
* @retval
*   None
*
*/
void eISD_InitiateResetFrmSail(isdStatesType_e state)
{
    switch(state)
    {
        case SOC_HARD_RESET:
		{
            DEBUG_LOG(SAIL_INFO, "Rx SAIL ISD state change to %d\r\n",state);
			pmicErrFlagType_e eReturnValue;
            /*
                SAIL has initiated SOC Hard Reset. Notify MD about Hard reset.
                Wait for MD_PS_HOLD low and pull SAIL_PS_HOLD low.
				For dependent PMIC, de-init all the drivers.
            */
            /* TODO: call SAIL de-init API */
            /* Set Current State and also notify the registered drivers
            that it's not a fatal error               */
            eISDSetStateinDriverContext(SOC_HARD_RESET);
			eISDNotifyAll(SOC_HARD_RESET);

            /* Configure PMIC for hard reset and then ack MD. Platform(IVI or ADAS) check is done within PMIC API */
            eReturnValue = xPmicSetResetState(PMIC_POFF_PON); /* Configure PMIC for hard reset */
		    if(PMIC_ERR_FLAG_SUCCESS == eReturnValue )
		    {
				/* In SAIL HW , Unmask/Allow SAIL_PS_HOLD to follow MD_PS_HOLD low, after SAIL secure fuse blown */
				out_dword(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, SAIL_FOLLOW_MD_FSM_STATE_MASK_VAL);
				/* Send Reset Reason message to MD to pull MD_PS_HOLD low */
				prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_SEC_FUSE_HR].value);
		    }
	    	break;
		}
	
        default:
        // do nothing
        break;
    }
}

/*===========================================================================
**  Function :  eISD_GetSailBootErrorCode
** ==========================================================================
*/
/*!
*
* @brief
*   This functions returns unique error code for SAIL boot failures
* @param
*   image_id       : SAIL Image ID
* @par Dependencies
*   None
* @retval
*   ISD_ErrCode_sailboot :Unique error code for SAIL boot failures
*
*/
ISD_ErrCode_sailboot eISD_GetSailBootErrorCode(eXblImageIdType image_id)
{
  ISD_ErrCode_sailboot err_code;
 
  switch(image_id)
  {
    case XBL_IMAGE_ID_SW1:
      err_code = ISD_FATAL_ERR_SAILSW1_LOAD_FAIL;
    break;
    case XBL_IMAGE_ID_SW2:
      err_code = ISD_FATAL_ERR_SAILSW2_LOAD_FAIL;
    break;
    case XBL_IMAGE_ID_SW3:
      err_code = ISD_FATAL_ERR_SAILSW3_LOAD_FAIL;
    break;
    case XBL_IMAGE_ID_SW4:
      err_code = ISD_FATAL_ERR_SAILSW4_LOAD_FAIL;
    break;
    case XBL_IMAGE_ID_DBG_POLICY:
      err_code = ISD_FATAL_ERR_SAILDP_LOAD_FAIL;
	break;
    default:
      err_code = ISD_FATAL_ERR_MAX;
    break;	
  }
  return(err_code);  
}

/*===========================================================================
**  Function :  eISD_InitiateEDLentryFrmSail
** ==========================================================================
*/
/*!
*
* @brief
*   This functions handles EDL entry from SAIL by doing one/more of following:
*               1. Updates SAIL context with new ISD state
*               2. Notify all registered clients that it's a known warm reset to enter EDL.
*               3. Configuring PMIC for warm reset(Independent PMIC case)
*				4. Send SOC reset reason to MD.
*               5. De-assert SAIL_PS_HOLD after MD_PS_HOLD is deasserted(Independent PMIC case)
*					to ensure both SAIL and MD resets together i.e SOC Reset
* @param
*   state       : new state of SAIL
* @par Dependencies
*   None
* @retval
*   None
*
*/
void eISD_InitiateEDLentryFrmSail(isdStatesType_e state, uint32_t image_id)
{
  ISD_ErrCode_sailboot err_code;
  pmicErrFlagType_e eReturnValue;

  //ToDo - SOC_EDL is used to notify known reset incase FUSA MD_PS_HOLD de-assertion interrupt is received.
  DEBUG_LOG(SAIL_INFO, "Rx SAIL ISD state change to %d\r\n",state);
  /*
      SAIL has initiated SOC warm reset to enter EDL mode, due to SAIL EL1 Image Auth/hash/load failure.
      Wait for MD_PS_HOLD low and pull SAIL_PS_HOLD low.
		For dependent PMIC, de-init all the drivers.
  */
  /* TODO: call SAIL de-init API */
  /* Set Current State and also notify the registered drivers
  that it's not a fatal error               */
  eISDSetStateinDriverContext(SOC_WARM_RESET);
  eISDNotifyAll(SOC_WARM_RESET);
  /* When MD warm resets to enter EDL mode,
   allow SAIL to go through warm reset but not crash reset flow.
   Hence, crash debug feature must be disabled to avoid entering crash reset flow upon md_ps_hold low */
  if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
  {
  	DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
  }

   /* Configure PMIC for warm reset and then ack MD. Platform(IVI or ADAS) check is done within PMIC API */
   eReturnValue = xPmicSetResetState(PMIC_WARM_RESET); /* Configure PMIC for warm reset */
   if(PMIC_ERR_FLAG_SUCCESS == eReturnValue )
   {
	/* For SAIL_PS_HOLD to automatically follow MD_PS_HOLD de-assertion via SAIL PS_HOLD generation HW block: 
	a) Unmask fields - bit[2:0] i.e bit[NORMAL_RESET_ST:POR_ST] in SAILSS_CC_MD_PS_HOLD_MASK register,
	b) Unmask field - bit[0] i.e bit[MD_PS_HOLD_EN_MASK] in SAIL_FATAL_ERR_PS_HOLD_EN_MASK register(OR) PwrSeq_busy = 1,
	c) MD_PS_HOLD from padring must be de-asserted i.e transition from high to low.
	Reference: SAIL Power Controller HDD - SAIL PS_HOLD generation HW block */
	out_dword(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, SAIL_FOLLOW_MD_FSM_STATE_MASK_VAL);
	(void)eISDCfgFatalErrSailPsHoldMask(MD_PS_HOLD_EN, ISD_FATAL_ERR_ACTIVE);
    /* Send Reset Reason message to MD to pull MD_PS_HOLD low */
    prvISDSetSAILMDMsg(stISDSailMDStatus[SAIL_OSPI_MD_CTRL].value);
   }
   else
   {
  	DEBUG_LOG(SAIL_ERROR, "SAIL EDL - PMIC cfg failed \r\n");
   }
	   
   /* stay in a loop until MD pulls MD_PS_HOLD */
   while(1)
   {

   }

}

