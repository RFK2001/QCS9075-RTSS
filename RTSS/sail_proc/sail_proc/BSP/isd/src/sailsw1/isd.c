/**
 * @file isd.c
 * @brief
 * Source file for isd driver of SAIL
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

#include <stdio.h>
#include "isd_drv.h"
#include "HALhwio.h"
#include "sail_pwr_ctrl_hwio.h"
#include "sail_asild_iso_hwio.h"
#include "sail_clkctl_hwio.h"
#include "isd_cfg.h"
#include "isd_resets.h"
#include "boot_logger.h"
#include "debug_log.h"
#include "Crashdbg_api.h"
#include "mailboxExt_api.h"
#include "sleepEl1.h"
#include "sailbsp_mutex.h"
#include "ddrmilestone.h"
//#include "vsens_el1_api.h"
#include "FreeRTOSOsal.h"
#include "interrupts.h"


/*=========================================================================
      Macros
==========================================================================*/
#define ISD_MOVE_TO_NORMAL              0x1U
#define ISD_MOVE_TO_ISLAND              0x2U
#define ISD_MD_PS_HOLD_POS_INTR         752U
#define ISD_MD_PS_HOLD_NEG_INTR         753U

#define ISD_QUEUE_LENGTH                ( 10U )
#define ISD_QUEUE_ITEM_SIZE             ( sizeof(ISD_QueueMsgType) )
#define ISD_QUEUE_BUFFER_SIZE           ( ISD_QUEUE_LENGTH * ISD_QUEUE_ITEM_SIZE )

#define MD_OSPI_NOR_LOG_ADDR            (void *) 0x31300000U
#define MD_OSPI_NOR_LOG_LEN             0x10000U
/*=========================================================================
      ISD Driver Context
==========================================================================*/

extern isdResultsType_e uiIsdInitStatus;


/* Number of ISD Tasks */
/* The size of the periodic test task stack - must be a multiple of 64. */
#define ISD_TASK_STACK_SIZE                   ( 1024U )
/* Declare task TCB. */
static StaticTask_t xISDTaskTCB[ISD_TASK_INSTANCE] = { 0 };

/* Declare task stack:
 * The check task stack is protected by an MPU region, so the alignment must
 * follow MPU alignment rules and aligned to a 64-byte boundary. */
static StackType_t xISDTaskStack[ISD_TASK_INSTANCE][ISD_TASK_STACK_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
static uint8_t xISDQueueBuffer[ISD_TASK_INSTANCE][ISD_QUEUE_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
ISD_DATA  QueueHandle_t xISDQueueHandle[ISD_QUEUE_INSTANCE];   
StaticQueue_t xISDQueueBufferStatic[ISD_QUEUE_INSTANCE];
ISD_DATA static IPCC_Handle xISD_IpccHandle[SAILBSP_CPU_COUNT] = { NULL, NULL, NULL, NULL }; 

static TaskHandle_t xISDTaskHandle[ISD_TASK_INSTANCE] = { NULL, NULL, NULL };

static uint32 ulISDSleepHandle;

isdResultsType_e uiIsdInitStatus = ISD_NOT_INITIALISED;

/*=========================================================================
      ISD Function Prototypes
==========================================================================*/

static void prvISDNotifyAll(const isdStatesType_e eNewState);

static void prvISDDeInit_Sleep( const sleepModeType_e eState );
/*===========================================================================
**  Function :  prvMDFatalErrSWIntrISR
** ==========================================================================
*/
/*!
*
* @brief
*   ISR for IPCC Interrupt to handle fatal error
*   Sent from Primary core to all cores including itself
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC static void prvMDFatalErrSWIntrISR(IPCC_CBData args,IPCC_Client eSenderID,IPCC_Signal nSignal)
{
	uint32_t usMsgDmSts = 0U;
	uint32 nCurrCPU = 0;
    isdStatesType_e state = NORMAL_STATE;
    ISD_DriverContext_t *pContext = (ISD_DriverContext_t *)args;
    BaseType_t 	xQReturn = pdFAIL;
    ISD_QueueMsgType xMsg = { 0 };
    if(pContext != NULL)
    {
        state = pContext->isdState;
        DEBUG_LOG( SAIL_WARNING, "prvMDFatalErrSWIntrCB: isdSt=%d\n\r", state);
        nCurrCPU = ISD_GET_CURRENT_CORE();
		/* without os sched delay mailbox 
			new transaction can be blocked in early stage other client handling done using ISD cbk  */
		if( LPM_DDR_SUSPEND_SUCCESS == pContext->eISDStatus)
		{
			(void)eLogToMBSAILConsoleOff();
			usMsgDmSts = DDRMilestone_DDR_SUSPEND;
			if( NULL != xDDRMilestoneQHandle )
			{
				xQReturn = xFreeRTOSQueueSendFromISR( xDDRMilestoneQHandle, &usMsgDmSts);
				if (pdPASS == xQReturn )
				{
					freertosYIELD_FROM_ISR();
				}
				else
				{
					DEBUG_LOG(SAIL_ERROR,"xDDRMilestoneQHandle ESEND:%d,%d\n\r", xQReturn, nCurrCPU );
				}
			}
		}
		else
		{
			(void)eMailbox_Abort();
			/* In this callback triggered by SAIL IPCC,
			Notify ISD State to all ISD clients that runs in respective SAIL core */
			xMsg.stStatus = state;
			xQReturn = xFreeRTOSQueueSendFromISR((xISDQueueHandle[0]), &xMsg);
			if( pdPASS == xQReturn)
			{
				freertosYIELD_FROM_ISR();
			}
			else
			{
				DEBUG_LOG(SAIL_ERROR,"Queue send err from core %d \n\r",nCurrCPU)
			}
		}
    }
}

/*===========================================================================
**  Function :  prvMDPSHoldNegEdgeISR_CB
** ==========================================================================
*/
/*!
*
* @brief
*   ISR for negative edge of MD_PS_HOLD
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC static void prvMDPSHoldNegEdgeISR_CB(void* args)
{
    ISD_DriverContext_t *pContxt = (ISD_DriverContext_t *) args;
    isdStatesType_e state;

    state = pContxt->isdState;

    switch(state)
    {
        case SOC_WARM_RESET:
        case SOC_SHUTDOWN:
        case SOC_HARD_RESET:
        case SOC_DEEP_SLEEP:
            /* De-assert SAIL_PS_HOLD upon MD_PS_HOLD deassertion
               so that both MD and SAIL goes through reset simultaneously */
            (void)eISDSailPSHoldDeAssert();
            break;
        default:
        //default switch case
        break;
    }
}

ISD_FUNC static void prvMDPSHoldNegEdgeISR(void* args)
{
    //Freertos ISR handles FPU registers save/restore.
    prvMDPSHoldNegEdgeISR_CB(args);
}

/*===========================================================================
**  Function :  prvMDPSHoldPosEdgeISR_CB
** ==========================================================================
*/
/*!
*
* @brief
*   ISR for positive edge of MD_PS_HOLD
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC static void prvMDPSHoldPosEdgeISR_CB(void* args)
{
    ISD_DriverContext_t *pContxt = (ISD_DriverContext_t *) args;
    volatile uint8 return_value;

    //De-isolate SAIL to switch to Normal mode.
    (void)eISDDisableIsolations();

    //Make SAIL to follow MD_PS_HOLD to detect any MD crash in the next MD boot.
    //MD_PS_HOLD pos edge means MD_PS_HOLD is asserted to start MD boot.
    if (Crashdbg_disable(DEP_CRASH_ENABLED) != DBG_SUCCESS)
    {
        DEBUG_LOG(SAIL_INFO, "MDpshldposedge:Dependent crashdbg disabled \r\n");
    }

    /* Assert SAIL_TO_MD_PS_HOLD */
    (void)eISDSailToMDPSHoldFlwMDPSHold();

    pContxt->isdState = NORMAL_STATE;

    (void)prvISDSendIPCCInterrupt();

}

ISD_FUNC static void prvMDPSHoldPosEdgeISR(void* args)
{
    //Freertos ISR handles FPU registers save/restore.
	prvMDPSHoldPosEdgeISR_CB(args);
}

/*===========================================================================
**  Function :  prvISDNotifyAll
** ==========================================================================
*/
/*!
*
* @brief
*   This function notifies all the registered subscribes regarding state change
*
* @param
*   isdStatesType_e eNewState: state to which ISD has switched
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC static void prvISDNotifyAll(const isdStatesType_e eNewState)
{
    /* local variables */
    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    
    uint32_t nCurrCPU = ISD_GET_CURRENT_CORE();
    isdNotificationListType *pList = &(pISDDriverContext->eNotifyData[nCurrCPU]);
    int32_t nIdx = 0;


    for(nIdx = 0; nIdx < pList->nTail; nIdx++)
    {
        if(pList->eDataArray[nIdx].pCB != NULL)
        {
            pList->eDataArray[nIdx].pCB(eNewState, pList->eDataArray[nIdx].pCBData);
        }
    }

}

/*===========================================================================
**  Function :  prvISDAsilDNoCReset
** ==========================================================================
*/
/*!
*
* @brief
*   This function resets ASIL D NOC
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC static void prvISDAsilDNoCReset(void)
{
    /* Enable Isolations for ASIL D NOC */
    HWIO_SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_REFCTL0_LOW_OUT
                                        (HWIO_SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_REFCTL0_LOW_ENABLE_BMSK);

    HWIO_SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_REFCTL1_LOW_OUT
                                        (HWIO_SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_REFCTL1_LOW_ENABLE_BMSK);
    
    HWIO_SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_MAINCTL_LOW_OUT
                                        (HWIO_SAILSS_ASIL_D_ISOLATIONNOC_SAIL_ISOLATION_TIMEOUT_REFGEN_REFGEN_MAINCTL_LOW_GLBEN_BMSK);
    
    /* Request ASIL D NOC partial reset */
    HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_OUT
                                        (HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTREQN_ASSERT_RSTREQN_FVAL);
    
    /* Wait for ASIL D NOC partial reset ACK*/
    while(!HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_INM(HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILD_NOC_PARTIAL_RESET_RSTACKN_BMSK));
}


/*===========================================================================
**  Function :  eISDGetStatus
** ==========================================================================
*/
/*!
*
* @brief
*   This function returns the DDR status
* @param
*   None
* @par Dependencies
*   None
* @retval
*   isdResultsType_e DDR_NOT_READY: DDR not initialised
*                    DDR_READY: DDR is initialised 
*
*/

ISD_FUNC isdStatusType_e eISDGetStatus(isdGetStatusType_e eGetStatus)
{


    volatile isdStatusType_e eStatus = ISD_MD2SAIL_STATUS_FAILED;

        switch(eGetStatus)
        {
            case ISD_GET_XBL_SEC_STATUS: 
            {

                if((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= XBL_SEC_BOOT_SECCESS))
                {
                    eStatus  = XBL_SEC_BOOT_SECCESS;
                }
            }
            break;
            case ISD_GET_DDR_STATUS:
            {   

                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= DDR_READY))
                {
                    eStatus  = DDR_READY;
                }
            }
            break;
            case ISD_GET_XBL_LOADER_STATUS:
            {

                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= XBL_LOADER_BOOT_SUCCESS))
                {
                    eStatus  = XBL_LOADER_BOOT_SUCCESS;
                }
            }
            break;
            case ISD_GET_VSENSE_STATUS:
            {

                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= MD_VSENSE_SUCCESS))
                {
                    eStatus  = MD_VSENSE_SUCCESS;
                }
            }
            break;
            case ISD_GET_TZ_STATUS:
            {

                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= TZ_SUCCESS))
                {
                    eStatus  = TZ_SUCCESS;
                }
            }
            break;
            case ISD_GET_QHEE_STATUS:
            {

                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= QHEE_SUCCESS))
                {
                    eStatus  = QHEE_SUCCESS;
                }
            }
            break;
            case ISD_GET_UEFI_STATUS:
            {

                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= UEFI_SUCCESS))
                {
                    eStatus  = UEFI_SUCCESS;
                }
            }
            break;
            
            case ISD_GET_ABL_STATUS:
            {

                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= ABL_SUCCESS))
                {
                    eStatus  = ABL_SUCCESS;
                }
            }
            break;
            
            case ISD_GET_LPM_DDR_SUSPEND_STATUS:
            {
                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= LPM_DDR_SUSPEND_SUCCESS))

                {
                    eStatus  = LPM_DDR_SUSPEND_SUCCESS;
                }
            }
            break; 
            
            case ISD_GET_S1_READY_STATUS:
            {
                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= S1_READY_SUCCESS))

                {
                    eStatus  = S1_READY_SUCCESS;
                }
            }
            break;
            
            case ISD_GET_MB_READY_STATUS:
            {
                if ((ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= MB_READY_SUCCESS))

                {
                    eStatus  = MB_READY_SUCCESS;
                }
            }
            break;

            default:
            // default switch case
            break;
        }

    return eStatus;
}
/*===========================================================================
**  Function :  eISDGetCurrentState
** ==========================================================================
*/
/*!
*
* @brief
*   This function returns the current state fo SAIL SS
* @param
*   None
* @par Dependencies
*   None
* @retval
*   isdResultsType_e UNDEFINED_STATE: ISD Driver is not initialised
*                    ISLAND_STATE: SAIL is in Island State
*                    NORMAL_STATE: SAIL is in Normal State 
*
*/
ISD_FUNC isdStatesType_e  eISDGetCurrentState(void)
{
    isdStatesType_e eReturnValue = NORMAL_STATE;
    /* check if SAIL is in Island Mode */
    if(HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK ==
    HWIO_SAILSS_PWR_CTRL_ISD_STATUS_INM(HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK))
    {
        eReturnValue = ISLAND_STATE;
    }

    /* SAIL is in Normal mode*/
    return eReturnValue;
}

/*===========================================================================
**  Function :  eISDSWOverrideIsoCtrl
** ==========================================================================
*/
/*!
*
* @brief
*   This function overrides control from HW to enable/disable isolations
*
* @param
*   value           0: Disable Override
*                   1: Enable Override
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_OK: CSR update failed
*                    ISD_OK: Isolations enabled
*
*/
ISD_FUNC isdResultsType_e eISDSWOverrideIsoCtrl(uint8 value)
{
    isdResultsType_e return_value = ISD_NOT_OK;

    if( value == 0u )
    {
        /* Disable - isolations and overide controls from hardware */
        HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_OUTM(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK, value);

        if(value == HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_INM(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK))
        {
            return_value = ISD_OK;
        }
    }
    else if( value == 1u )
    {
        /* Disable - isolations and overide controls from hardware */
        HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_OUTM(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK, 
                                              HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK);

        if( HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK == 
            HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_INM(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK))
        {
            return_value = ISD_OK;
        }
    }
    else
    {
        // do nothing
    }

    return return_value;
}

ISD_FUNC isdResultsType_e eISDSWIsolationsEnableAll(void)
{
    isdResultsType_e return_value = ISD_NOT_OK;

    HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_OUT(HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_RMSK);
    //ToDO - NOC partial reset via SAILCC must be done via HVC call. Also the reset sequence to be re-checked.
    //prvISDAsilDNoCReset();

    if(HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_RMSK == HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_IN)
    {
        return_value = ISD_OK;
    }

    return return_value;
}
/*===========================================================================
**  Function :  eISDEnableIsolations
** ==========================================================================
*/
/*!
*
* @brief
*   This function enables the isolations on the SAIL boundary and moves SAIL 
*   to Island Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_INITIALISED: ISD Driver is not initialised
*                    ISD_OK: Isolations enabled
*
*/
ISD_FUNC isdResultsType_e eISDEnableIsolations(void)
{


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        // if condition is true then return value is ISD_NOT_INITIALISED
    }
    else
    {
        /* if already in Island state then return */
        if(HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK ==
        HWIO_SAILSS_PWR_CTRL_ISD_STATUS_INM(HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK))
        {
            eReturnValue = ISD_OK;
        }
        else
        {

            mutex_lock(&pISDDriverContext->stLock);
            /* update state in isd driver context*/
            pISDDriverContext->isdState = ISLAND_STATE;

            /* Overide isolation controls from hardware */
            /* Writting 1'b1 to SAIL_FROM_MD_ISO_EN_SW_OVRD_EN disables  */
            /* hardware control of isolations */
            /* Writting 1'b1 to ISD_MOVE_TO_ISLAND_STATE bit moves SAIL to island mode */
            HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_OUT((ISD_MOVE_TO_ISLAND));

            //ToDO - NOC partial reset via SAILCC must be done via HVC call. Also the reset sequence to be re-checked.
            //prvISDAsilDNoCReset();

            mutex_unlock(&pISDDriverContext->stLock);

            eReturnValue = ISD_OK;
        }

    }


    return eReturnValue;
}

/*===========================================================================
**  Function :  eISDDisableIsolations
** ==========================================================================
*/
/*!
*
* @brief
*   This function disables Isolations on SAIL boundary and moves SAIL to Normal 
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_INITIALISED: ISD is not initialised
*                    ISD_OK: isolations are disabled
*
*/
ISD_FUNC isdResultsType_e eISDDisableIsolations(void)
{


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        // if condition is true then return value is ISD_NOT_INITIALISED
    }
    else 
    {

        /* if not in Island State then return */
        if(HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK !=
        HWIO_SAILSS_PWR_CTRL_ISD_STATUS_INM(HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK))
        {
            eReturnValue = ISD_OK;
        }
        else
        {
            mutex_lock(&pISDDriverContext->stLock);
            /* Disable - isolations and overide controls from hardware */
            HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_OUT(ISD_MOVE_TO_NORMAL);

            /* update state in isd driver context*/
            pISDDriverContext->isdState = NORMAL_STATE; 
            mutex_unlock(&pISDDriverContext->stLock);
            eReturnValue = ISD_OK;
        }


    }


    return eReturnValue;
}

/*===========================================================================
**  Function :  eISDSailPSHoldAssert
** ==========================================================================
*/
/*!
*
* @brief
*   This function sets SAIL_PS_HOLD 
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_OK: SAIL_PS_HOLD cannot be set
*                    ISD_OK: SAIL_PS_HOLD is set
*
*/
ISD_FUNC isdResultsType_e eISDSailPSHoldAssert(void)
{


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        // if condition is true then return value is ISD_NOT_INITIALISED
    }
    else 
    {
        HWIO_SAILSS_PWR_CTRL_PS_HOLD_OUTM( HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_PS_HOLD_BMSK, 
                                            HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_PS_HOLD_BMSK );

        if( HWIO_SAILSS_PWR_CTRL_PS_HOLD_INM( HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_PS_HOLD_BMSK )
            == HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_PS_HOLD_BMSK )
        {
            eReturnValue = ISD_OK;
        }
        else
        {
            eReturnValue = ISD_NOT_OK;
        }
    }

    return eReturnValue;
}

/*===========================================================================
**  Function :  eISDSailPSHoldDeAssert
** ==========================================================================
*/
/*!
*
* @brief
*   This function de-asserts SAIL_PS_HOLD 
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_OK: SAIL_PS_HOLD cannot be reset
*                    ISD_OK: SAIL_PS_HOLD has been reset
*
*/
ISD_FUNC isdResultsType_e eISDSailPSHoldDeAssert(void)
{
    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        // if condition is true then return value is ISD_NOT_INITIALISED
    }
    else 
    {
        HWIO_SAILSS_PWR_CTRL_PS_HOLD_OUTM(HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_PS_HOLD_BMSK, 0);

        if( HWIO_SAILSS_PWR_CTRL_PS_HOLD_INM(HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_PS_HOLD_BMSK)
            != HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_PS_HOLD_BMSK )
        {
            eReturnValue = ISD_OK;
        }
        else
        {
            eReturnValue = ISD_NOT_OK;
        }
    }

    return eReturnValue;
}

/*===========================================================================
**  Function :  eISDSailToMDPSHoldFlwMDPSHold
** ==========================================================================
*/
/*!
*
* @brief
*   This function sets SAIL_TO_MD_PS_HOLD 
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_INITIALISED: ISD is not initialised
*                    ISD_NOT_OK: Failed to set SAIL_TO_MD_PS_HOLD
*                    ISD_OK: Successfully set SAIL_TO_MD_PS_HOLD
*
*/
ISD_FUNC isdResultsType_e eISDSailToMDPSHoldFlwMDPSHold(void)
{


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;

    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        eReturnValue = ISD_NOT_INITIALISED;
    }
    else 
    {

        /*Set SAIL_TO_MD_PS_HOLD to assert/de-assert with SAIL_PS_HOLD depepnding on MD conditions*/
        HWIO_SAILSS_PWR_CTRL_PS_HOLD_OUTM( HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_TO_MD_PS_HOLD_BMSK, 
                                        HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_TO_MD_PS_HOLD_BMSK );
        eReturnValue = ISD_OK;
    }

    return eReturnValue;

}

/*===========================================================================
**  Function :  eISDSailToMDPSHoldDeAssert
** ==========================================================================
*/
/*!
*
* @brief
*   This function resets SAIL_TO_MD_PS_HOLD 
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_INITIALISED: ISD is not initialised
*                    ISD_NOT_OK: Failed to reset SAIL_TO_MD_PS_HOLD
*                    ISD_OK: Successfully reset SAIL_TO_MD_PS_HOLD
*
*/
ISD_FUNC isdResultsType_e eISDSailToMDPSHoldDeAssert(void)
{


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        // if condition is true then return value is ISD_NOT_INITIALISED
    }
    else 
    {
        /*Force SAIL_TO_MD_PS_HOLD to be 0*/
        HWIO_SAILSS_PWR_CTRL_PS_HOLD_OUTM( HWIO_SAILSS_PWR_CTRL_PS_HOLD_SAIL_TO_MD_PS_HOLD_BMSK, 0 );

        eReturnValue = ISD_OK;
    }

    return eReturnValue;
}

/*===========================================================================
**  Function :  eISDFatalError
** ==========================================================================
*/
/*!
*
* @brief
*   Callback functions for FUSA fatal error notification.
*   Mode
*
* @param
*   nIntr   : vector number
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_INITIALISED: ISD is not initialised
*                    ISD_NOT_OK: Failed to reset SAIL_TO_MD_PS_HOLD
*                    ISD_OK: Successfully reset SAIL_TO_MD_PS_HOLD
*
*/
ISD_FUNC isdResultsType_e eISDFatalError(uint32 nIntr)
{
    ISD_UNUSED_PARAMETER(nIntr);
    isdResultsType_e return_value = ISD_NOT_OK;
    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;

    /* Skip isolations if SAIL is already in Island state */

    if(pISDDriverContext->isdState == ISLAND_STATE)
    {
        return_value = ISD_OK;
    }
    else
    {
        pISDDriverContext->isdState = ISLAND_STATE;
        pISDDriverContext->eISDStatus = ISD_MD2SAIL_STATUS_FAILED;
        //Max CPUs=4, trigger IPCC to core2,1 and 0, to inform about ISD state change into Island mode.		

        return_value = prvISDSendIPCCInterrupt();

    }

    return return_value;

}

/*===========================================================================
**  Function :  GetSailPSHoldFatalErrStatus
** ==========================================================================
*/
/*!
*
* @brief
*   Function to get the status of all fatal errors leading to sail_ps_hold
*   de-assertion
*   Mode
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   uint32    sail_ps_hold fatal error status
*
*/
ISD_FUNC uint32 GetSailPSHoldFatalErrStatus(void)
{
    return HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_IN;
}

/*===========================================================================
**  Function :  GetIsoEnFatalErrStatus
** ==========================================================================
*/
/*!
*
* @brief
*   Function to get the status of all fatal errors leading to isolation enable
*   Mode
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   uint32    isoaltion enable fatal error status
*
*/
uint32 GetIsoEnFatalErrStatus(void)
{
    return HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_IN;
}

/*===========================================================================
**  Function :  eISDConfigFatalErrIsoEnMask
** ==========================================================================
*/
/*!
*
* @brief
*   Function to set the fatal error isolation en mask 
*   Mode
*
* @param
*   eFatalErr       : fatal error id
*   eFatalErrMask : mask value of the fatal error
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_OK: Incorrect mask value
*                    ISD_OK: Successfully set mask value for the fatal error
*
*/
ISD_FUNC isdResultsType_e eISDConfigFatalErrIsoEnMask(isdFataErrType_e eFatalErr, isdFatalErrMaskType eFatalErrMask)
{
    isdResultsType_e eReturnValue = ISD_NOT_OK;

    if((eFatalErr <= SPARE_FATAL_EN) && (eFatalErrMask < ISD_FATA_ERR_INVALID) )
    {
        HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_OUTM( (1 << eFatalErr), (eFatalErrMask << eFatalErr));

        eReturnValue = ISD_OK;  
    }

    return eReturnValue;      
}

/*===========================================================================
**  Function :  CfgFatalErrSailPsHoldMask
** ==========================================================================
*/
/*!
*
* @brief
*   Function to set the fatal error sail_ps_hold de-assertion mask 
*   Mode
*
* @param
*   eFatalErr       : fatal error id
*   eFatalErrMask : mask value of the fatal error
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_OK: Incorrect mask value
*                    ISD_OK: Successfully set mask value for the fatal error
*
*/
ISD_FUNC isdResultsType_e CfgFatalErrSailPsHoldMask(isdFataErrType_e eFatalErr, isdFatalErrMaskType eFatalErrMask)
{
    isdResultsType_e eReturnValue = ISD_NOT_OK;

    if((eFatalErr <= SPARE_FATAL_EN) && (eFatalErrMask < ISD_FATA_ERR_INVALID))
    {
        HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OUTM( (1 << eFatalErr), (eFatalErrMask << eFatalErr));

        eReturnValue = ISD_OK;
    }

    return eReturnValue;        
}

/*===========================================================================
**  Function :  eISDSetIsolationState
** ==========================================================================
*/
/*!
*
* @brief
*   Function to set the fatal error sail_ps_hold de-assertion mask 
*   Mode
*
* @param
*   eIso       : isoaltion id
*   eState     : isolation state
* @par Dependencies
*   None
* @retval
*   isdResultsType_e ISD_NOT_OK: Incorrect input values
*                    ISD_OK: Successfully set isolation state
*
*/
ISD_FUNC isdResultsType_e eISDSetIsolationState(
                    isdIsolationTypes_e eIso,
                    isdIsolationStateType_e eState)
{
    isdResultsType_e eReturnValue = ISD_NOT_OK;

    if((eIso < ISD_SAIL_ISO_TYPE_MAX) && (eState < ISD_ISOLATION_INVALID) )
    {
        /* Enable SW OVD to enable isolation*/
        HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_OUTM(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK,
        HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK);
        HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_OUTM((1 << eIso), (eState << eIso));
        HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_OUTM(HWIO_SAILSS_PWR_CTRL_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK, 0);

        eReturnValue = ISD_OK;
    }

    return eReturnValue;
}

/*===========================================================================
**  Function :  eISDGetIsolationState
** ==========================================================================
*/
/*!
*
* @brief
*   Function to set the fatal error sail_ps_hold de-assertion mask 
*   Mode
*
* @param
*   eIso       : isoaltion id
* @par Dependencies
*   None
* @retval
*   isdIsolationStateType_e isolation state
*
*/
ISD_FUNC isdIsolationStateType_e eISDGetIsolationState(
                    isdIsolationTypes_e eIso)
{
    volatile uint8 nValue = 0;
    isdIsolationStateType_e eReturnValue = ISD_ISOALTION_DISABLE;

    if(eIso < ISD_SAIL_ISO_TYPE_MAX)
    {
        nValue = HWIO_SAILSS_PWR_CTRL_ISD_ISO_STATUS_INM((1u << eIso));
        if(0u != nValue)
        {
            eReturnValue = ISD_ISOLATION_EN;
        }
    }

    return eReturnValue;
}

/*===========================================================================
**  Function :  eISDRegisterNotification
** ==========================================================================
*/
/*!
*
* @brief
*   This function registers an ISD notification
*   Mode
*
* @param
*   pCB                 pointer to callback function
*   pCBData             pointer to data to be passed to callback function
* @par Dependencies
*   None
* @retval
*   isdResultsType_e    check enum declaration for more details
*
*/
ISD_FUNC isdResultsType_e eISDRegisterNotification(
                    ISD_ClientNotificationCallbackFn pCB,
                    void *pCBData)
{

    return eISDDrv_RegisterNotification(ISD_CONTEXT_BASE_ADDRESS, pCB, pCBData);
 
}

/*===========================================================================
**  Function :  eISDDeregisterNotification
** ==========================================================================
*/
/*!
*
* @brief
*   This function deregisters an ISD notification
*   Mode
*
* @param
*   pCB                 pointer to callback function
* @par Dependencies
*   None
* @retval
*   isdResultsType_e    check enum declaration for more details
*
*/
ISD_FUNC isdResultsType_e eISDDeregisterNotification(
                    ISD_ClientNotificationCallbackFn pCB)
{

    return eISDDrv_DeregisterNotification(ISD_CONTEXT_BASE_ADDRESS, pCB);

}
/*===========================================================================
**  Function :  vISDInit
** ==========================================================================
*/
/*!
*
* @brief
*   This function initialises ISD Driver 
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/

ISD_FUNC void vISDInit(void)
{
    /* local variables */

    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;

    uint32_t nCurrCPU = ISD_GET_CURRENT_CORE();
    
    uint32            CoreNum = 0;

    uint32_t ui32IsdFatalErrIsolation = 0;

    uint32_t ui32IsdFatalErrPSHold = 0;

    uint64 ISDtime = 0;
	uint32 clientID  = 0U;

    //@Todo:use current CPU number
    ISDtime = uBootLogger_LogStartTime("ISD Init Started on core", 0);

    /* initialise mutex*/
    (void)mutex_init(&pISDDriverContext->stLock);

    /* get the current state of SAIL */
    if(
        HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK ==
        HWIO_SAILSS_PWR_CTRL_ISD_STATUS_INM
            (
                HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK
            )
    )
    {
        pISDDriverContext->isdState = ISLAND_STATE;
    }
    else
    {
        pISDDriverContext->isdState = NORMAL_STATE;
    }



    /* Reading the register and Configuring ISD_FATAL_ERR_ISOLATION_EN_MASK */
    ui32IsdFatalErrIsolation = HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_IN;

    HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_OUT(ui32IsdFatalErrIsolation);

    /* Reading the register and  Configure ISD_FATAL_ERR_PS_HOLD_EN_MASK */
    ui32IsdFatalErrPSHold  = HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_IN;

    HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OUT(ui32IsdFatalErrPSHold);


    /* Configure MD_PS_HOLD pos/neg edge inetrrupt and register for it*/
    (void)eISDOS_RegisterInterrupt(ISD_MD_PS_HOLD_POS_INTR,   ISDOS_TRIGGER_EDGE, (ISDOS_InterruptHandle *)prvMDPSHoldPosEdgeISR, (void *) ISD_CONTEXT_BASE_ADDRESS);
    (void)eISDOS_RegisterInterrupt(ISD_MD_PS_HOLD_NEG_INTR,   ISDOS_TRIGGER_EDGE, (ISDOS_InterruptHandle *)prvMDPSHoldNegEdgeISR, (void *) ISD_CONTEXT_BASE_ADDRESS);
    /* Configure MAIN2SAIL status inetrrupts and register for them*/
    (void)eISDOS_RegisterInterrupt(ISD_TZ_IPC_SEC_INTR,  ISDOS_TRIGGER_EDGE, (ISDOS_InterruptHandle *)prvTZIPCSecISR, (void *) ISD_CONTEXT_BASE_ADDRESS);
    /* Configure MAIN2SAIL non secure interrupt from MD boot stages  and register for it */
    (void)eISDOS_RegisterInterrupt(ISD_TZ_IPC_NON_SEC_INTR,  ISDOS_TRIGGER_EDGE, (ISDOS_InterruptHandle *)prvIPCNonSecISR, (void *) ISD_CONTEXT_BASE_ADDRESS);


	clientID = (uint)IPCC_C_SAIL0 + nCurrCPU;
    if( IPCC_EOK != IPCC_AttachEx( &xISD_IpccHandle[nCurrCPU],
                                    IPCC_P_SAIL_MPROC,
											  (IPCC_Client)clientID, nCurrCPU) )
     {
        DEBUG_LOG( SAIL_ERROR,"vISDInit(%d): IPCC Attach failed. %d\n\r", nCurrCPU,clientID);
     }
	else
	{
 
		if( IPCC_EOK == IPCC_RegisterInterrupt( xISD_IpccHandle[nCurrCPU],(IPCC_C_SAIL0),27u, 27u,(IPCC_CB)prvMDFatalErrSWIntrISR,(IPCC_CBData)ISD_CONTEXT_BASE_ADDRESS) )
        {
            CoreNum |= (1u << ISD_CORE_0);
        }
		if( IPCC_EOK == IPCC_RegisterInterrupt( xISD_IpccHandle[nCurrCPU],(IPCC_C_SAIL1),27u, 27u,(IPCC_CB)prvMDFatalErrSWIntrISR,(IPCC_CBData)ISD_CONTEXT_BASE_ADDRESS) )
        {
            CoreNum |= (1u << ISD_CORE_1);
        }
		if( IPCC_EOK == IPCC_RegisterInterrupt( xISD_IpccHandle[nCurrCPU],(IPCC_C_SAIL2),27u, 27u,(IPCC_CB)prvMDFatalErrSWIntrISR,(IPCC_CBData)ISD_CONTEXT_BASE_ADDRESS) )
        {
            CoreNum |= (1u << ISD_CORE_2);
        }

        if(0x7u != CoreNum)
        {
            DEBUG_LOG( SAIL_ERROR, "vISDInit(%d): IPCC Register interrupt failed.\n\r", CoreNum);
            return;
        }

    }


    
    /* Disable Isolations to exit Island Mode */
    if(ISD_OK != eISDDisableIsolations())
    {
        while(1)
        {

        }
        /* TODO Enable logging/error handling */
    }
    //@Todo:use current CPU number
    (void)vBootLogger_LogDeltaTime(ISDtime, "ISD Init Done on core", 0);

   #if 0
   if ( 0x0u == ulISDSleepHandle )
    {
        if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1(&prvISDDeInit_Sleep,&ulISDSleepHandle,get_curr_phys_cpu_num()))
        {
            DEBUG_LOG(SAIL_INFO,"prvISDDeInit_Sleep Sleep Reg Failed\n\r");
        }
    }

    #endif

    uiIsdInitStatus = ISD_OK;

}

/*===========================================================================
**  Function :  eISDDeInit
** ==========================================================================
*/
/*!
*
* @brief
*   This function De-initialises ISD Driver 
*   
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/

ISD_FUNC isdResultsType_e eISDDeInit(void)
{
    isdResultsType_e eReturnValue = ISD_NOT_OK;

    if(ISD_OK == uiIsdInitStatus)
    {
        (void)eISDOS_DeRegisterInterrupt(ISD_TZ_IPC_SEC_INTR, FALSE);

        (void)eISDOS_DeRegisterInterrupt(ISD_TZ_IPC_NON_SEC_INTR, FALSE);

        // de-init the shared memory

        ISD_CONTEXT_BASE_ADDRESS->eISDStatus =  ISD_MD2SAIL_STATUS_FAILED;

        eReturnValue = ISD_OK;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"ISD DeInit Failed\n\r");
    }

    return eReturnValue;



}

/*===========================================================================
**  Function :  vISDInitSMP
** ==========================================================================
*/
/*!
*
* @brief
*   This function initialises ISD Driver on secondary cores
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC void vISDInitSMP(void)
{

    uint32_t nCurrCPU = ISD_GET_CURRENT_CORE();

    uint32 clientID  = 0U;

    uint32 CoreNum  = 0U;



    /* Initialize mutex */
    (void)mutex_init(&(ISD_CONTEXT_BASE_ADDRESS->stCoreLock[nCurrCPU]));
    
    /*
        Secondary core need to register for this IPCC intr. 
        This IPCC Intr is triggered from primary core when 
        an MD Fatal error/crash occurs.
    */


	clientID = (uint)IPCC_C_SAIL0 + nCurrCPU;
    if(  IPCC_EOK != IPCC_AttachEx( &xISD_IpccHandle[nCurrCPU],
                                    IPCC_P_SAIL_MPROC,
											  (IPCC_Client)clientID, nCurrCPU) )
     {
        DEBUG_LOG( SAIL_ERROR,"vISDInitSMP(%d): IPCC Attach failed.\n\r", nCurrCPU);
     }
	else
	{
		if( IPCC_EOK == IPCC_RegisterInterrupt( xISD_IpccHandle[nCurrCPU],(IPCC_C_SAIL0),27u, 27u,(IPCC_CB)prvMDFatalErrSWIntrISR,(IPCC_CBData)ISD_CONTEXT_BASE_ADDRESS) )
        {
            CoreNum |= (1u << ISD_CORE_0);
        }
		if( IPCC_EOK == IPCC_RegisterInterrupt( xISD_IpccHandle[nCurrCPU],(IPCC_C_SAIL1),27u, 27u,(IPCC_CB)prvMDFatalErrSWIntrISR,(IPCC_CBData)ISD_CONTEXT_BASE_ADDRESS) )
        {
            CoreNum |= (1u << ISD_CORE_1);
        }
		if( IPCC_EOK == IPCC_RegisterInterrupt( xISD_IpccHandle[nCurrCPU],(IPCC_C_SAIL2),27u, 27u,(IPCC_CB)prvMDFatalErrSWIntrISR,(IPCC_CBData)ISD_CONTEXT_BASE_ADDRESS) )
        {
            CoreNum |= (1u << ISD_CORE_2);
        }

        if(0x7U != CoreNum)
        {
            DEBUG_LOG( SAIL_ERROR, "vISDInit(%d): IPCC Register interrupt failed.\n\r", CoreNum);
            return;
        }

    }




}

/*===========================================================================
**  Function :  vISDTask
** ==========================================================================
*/
/*!
*
* @brief
*   ISD SafeRTOS Task for primary core
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC void vISDTask(void* arg)
{
    ISD_UNUSED_PARAMETER(arg);
    isdStatesType_e nResetReason = UNDEFINED_STATE;
    ISD_QueueMsgType xISDMsg = { 0 };
    BaseType_t xReturn = pdFAIL;
    uint32_t nCurrCPU = ISD_GET_CURRENT_CORE();

    if(nCurrCPU == 0){
      /* Initialize ISD Driver */
       vISDInit();
    }else{
        vISDInitSMP();
    }

    for(;;)
    {
        /* Receive msg on queue and parse message */
        xReturn = xFreeRTOSQueueReceive((xISDQueueHandle[nCurrCPU]), &xISDMsg, freertosMAX_DELAY);
        if ( pdPASS == xReturn )
        {
            nResetReason = xISDMsg.stStatus;
            prvISDNotifyAll(nResetReason);
            prvISD_ISDStateHandler(ISD_CONTEXT_BASE_ADDRESS, nResetReason);
        }
    }
}

/*===========================================================================
**  Function :  xISDTaskInit
** ==========================================================================
*/
/*!
*
* @brief
*   ISD SafeRTOS Task Init function for primary core
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC BaseType_t xISDTaskInit( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior )
{
//    ISD_UNUSED_PARAMETER(xSchdCore);
	UBaseType_t uxCoreAffinityMask;
    BaseType_t xResult = pdFAIL;
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
        .pvTaskCode = vISDTask,                 /* The function that implements the task being created. */
        .pcName = "ISDTask",                 /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer = &(xISDTaskTCB[xSchdCore]),              /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer = &(xISDTaskStack[xSchdCore][0]),             /* The buffer allocated for use as the task stack. */
        .usStackDepth = ISD_TASK_STACK_SIZE,      /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters = NULL,                               /* The task parameter, not used in this case. */
        .uxPriority = (xTaskPrior),                         /* The priority assigned to the task being created. */
		.xRegions = {				   /* The MPU task parameters. */
						 {NULL, 0UL, 0UL}, /* No additional region definitions are required. */
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL}}};


    /* Create Queue */
    xResult = xFreeRTOSQueueCreate(&(xISDQueueBuffer[xSchdCore][0]), ISD_QUEUE_LENGTH, ISD_QUEUE_ITEM_SIZE, &(xISDQueueHandle[xSchdCore]),&xISDQueueBufferStatic[xSchdCore]);
    if(xResult == pdPASS)
    {
        /* Create the check task. */
		uxCoreAffinityMask = (1 << xSchdCore);
		xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters, uxCoreAffinityMask, &xISDTaskHandle[xSchdCore]);
    }
    return xResult;
}



/*===========================================================================
**  Function :  prvISDSendIPCCInterrupt
** ==========================================================================
*/
/*!
*
* @brief
*   This function triggers an IPCC Interrupt to all SAIL cores
*   Mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC isdResultsType_e prvISDSendIPCCInterrupt(void)
{
    uint32_t CoreNum = 0u;
    isdResultsType_e status = ISD_NOT_OK;
    uint32_t nCurrCPU = ISD_GET_CURRENT_CORE();

    if(xISD_IpccHandle[nCurrCPU] != NULL)
    {
        if( IPCC_EOK == IPCC_Trigger(xISD_IpccHandle[nCurrCPU],(IPCC_C_SAIL2),27u,27u))
        {
            CoreNum |= (1u << ISD_CORE_2);
        }
        if( IPCC_EOK == IPCC_Trigger(xISD_IpccHandle[nCurrCPU],(IPCC_C_SAIL1),27u,27u))
        {
            CoreNum |= (1u << ISD_CORE_1);
        }
        if( IPCC_EOK == IPCC_Trigger(xISD_IpccHandle[nCurrCPU],(IPCC_C_SAIL0),27u,27u))
        {
            CoreNum |= (1u << ISD_CORE_0);
        }

        if(0x7U == CoreNum)
        {
            status = ISD_OK;
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"IPCC Triggered Failed for CoreNum = 0x%x\n\r",CoreNum);
        }

    }

    return status;
}

static ISD_FUNC void prvISDDeInit_Sleep( const sleepModeType_e eState )
 {

    if(( STR_SLEEP_MODE == eState ) || (DEEP_SLEEP_MODE == eState))
    {
        if ( ISD_OK ==  eISDDeInit())
        { 
            if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(ulISDSleepHandle,DRIVER_SLEEP,get_curr_phys_cpu_num()))
            {
                DEBUG_LOG(SAIL_INFO,"prvISDDeInit_Sleep xSleepDriverAck Success\n\r");
            }else
            {
                DEBUG_LOG(SAIL_ERROR,"prvISDDeInit_Sleep xSleepDriverAck Failed\n\r");
            }
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"eISDDeInit Failed \n\r");
        }
    }
 }
