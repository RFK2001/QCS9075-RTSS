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
#include "busywait.h"
#include "HALhwio.h"
#include "sail_pwr_ctrl_hwio.h"
#include "hw_io.h"
#include "sail_asild_iso_hwio.h"
#include "sail_clkctl_hwio.h"
#include "sail_clkctl_rststs_hwio.h"
#include "isd_cfg.h"
#include "isd_resets.h"
#include "boot_logger.h"
#include "sailbsp_mutex.h"
#include "syscall.h"
#include "syscall_pub.h"
#include "debug_log.h"
#include "Crashdbg_api.h"

/*=========================================================================
      Macros
==========================================================================*/
#define ISD_MOVE_TO_NORMAL              0x1U
#define ISD_MOVE_TO_ISLAND              0x2U
#define ISD_MD_PS_HOLD_POS_INTR         752U
#define ISD_MD_PS_HOLD_NEG_INTR         753U

/*=========================================================================
      ISD Driver Context
==========================================================================*/

ISD_DATA static IPCC_Handle xISD_Hyp_IpccHandle = NULL;
static isdResultsType_e eIsdInitStatus = ISD_NOT_INITIALISED;

/*=========================================================================
      ISD Function Prototypes
==========================================================================*/

void vISD_Mdpshold_poll(void);

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
static void prvMDFatalErrSWIntrISR(IPCC_CBData args,IPCC_Client eSenderID,IPCC_Signal nSignal)
{
    uint32 nCurrCPU = 0;
    isdStatesType_e state = NORMAL_STATE;
    ISD_DriverContext_t *pContext = (ISD_DriverContext_t *)args;

    if(pContext != NULL)
    {
        state = pContext->isdState;

        /* Notify drivers: TBD */
        eISDNotifyAll(state);

        nCurrCPU = ISD_GET_CURRENT_CORE();
        if((0u == nCurrCPU) )
        {
            prvISD_IPCCIntrHandler(state);
        }
        else
        {
            if(state == SOC_EDL)
            {
                __asm__ volatile("cpsid  aif");
                while(1)
                {

                }
            }
        }
    }


}

/*===========================================================================
**  Function :  prvMDPSHoldPosEdgeISR
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
static void prvMDPSHoldPosEdgeISR(void* args)
{
    ISD_UNUSED_PARAMETER(args);
    (void)eISDDisableIsolations();

    //Make SAIL to follow MD_PS_HOLD to detect any MD crash in the next MD boot.
    //MD_PS_HOLD pos edge means MD_PS_HOLD is asserted to start MD boot.
    if (Crashdbg_disable(DEP_CRASH_ENABLED) != DBG_SUCCESS)
    {
        DEBUG_LOG(SAIL_INFO, "MDpshldposedge:Dependent crashdbg disabled \r\n");
    }

    /* Assert SAIL_TO_MD_PS_HOLD */
    (void)eISDSailToMDPSHoldFlwMDPSHold();

}

/*===========================================================================
**  Function :  prvMDPSHoldNegEdgeISR
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
static void prvMDPSHoldNegEdgeISR(void* args)
{
    ISD_DriverContext_t *pContxt = (ISD_DriverContext_t *) args;
    isdStatesType_e state;

    state = pContxt->isdState;

    switch(state)
    {
        case SOC_WARM_RESET:
        case SOC_SHUTDOWN:
        case SOC_HARD_RESET:
            /* De-assert SAIL_PS_HOLD upon MD_PS_HOLD deassertion
               so that both MD and SAIL goes through reset simultaneously */
            (void)eISDSailPSHoldDeAssert();
            break;
        default:
        // default 
        break;
    }
}

/*===========================================================================
**  Function :  eISDNotifyAll
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
void eISDNotifyAll(const isdStatesType_e eNewState)
{
    /* local variables */
    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;//ISD_CONTEXT_BASE_ADDRESS;

    uint32_t nCurrCPU = ISD_GET_CURRENT_CORE();
   isdNotificationListType *pList = &(pISDDriverContext->eNotifyData[nCurrCPU]);
    int8_t nIdx = 0;

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
static void prvISDAsilDNoCReset(void)
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
**  Function :  eISDSetStateinDriverContext
** ==========================================================================
*/
/*!
*
* @brief
*   Function to set the new ISD state in ISD driver context
*   Mode
*
* @param
*   isdStatesType_e eNewState: state to which ISD has switched
* @par Dependencies
*   None
* @retval
*   None
*
*/
void eISDSetStateinDriverContext(isdStatesType_e eNewState)
{
    /* local variables */
    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;


	
    pISDDriverContext->isdState = eNewState;	
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
isdStatusType_e eISDGetStatus(isdGetStatusType_e eGetStatus)
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
            //default switch case
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
isdStatesType_e  eISDGetCurrentState(void)
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
**  Function :  eISDSWOverrideIsolationsCtrl
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
isdResultsType_e eISDSWOverrideIsolationsCtrl(uint8 value)
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

isdResultsType_e eISDSWIsolationsEnableAll(void)
{
    isdResultsType_e return_value = ISD_NOT_OK;

    HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_OUT(HWIO_SAILSS_PWR_CTRL_ISD_ISO_CTRL_RMSK);
    //ToDO - NOC partial reset sequence to be re-checked.
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
isdResultsType_e eISDEnableIsolations(void)
{


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        //if condition true then return value is ISD_NOT_INITIALISED
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

            //ToDO - NOC partial reset sequence to be re-checked.
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
isdResultsType_e eISDDisableIsolations(void)
{


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        // if condition is tru then return value is ISD_NOT_INITIALISED
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

            /* Notify drivers: TBD */
            eISDNotifyAll(NORMAL_STATE);

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
isdResultsType_e eISDSailPSHoldAssert(void)
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
*   This function deasserts SAIL_PS_HOLD 
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
isdResultsType_e eISDSailPSHoldDeAssert(void)
{


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        // if condition is true then return value is  ISD_NOT_INITIALISED
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
isdResultsType_e eISDSailToMDPSHoldFlwMDPSHold(void)
{
    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue  = ISD_NOT_INITIALISED;


    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        // if condition is true then return value is  ISD_NOT_INITIALISED
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
isdResultsType_e eISDSailToMDPSHoldDeAssert(void)
{


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;
    isdResultsType_e eReturnValue = ISD_NOT_INITIALISED;

    /* check if ISD_Driver has been initialised */
    if(pISDDriverContext->isdState == UNDEFINED_STATE)
    {
        // if condition is true then return value is  ISD_NOT_INITIALISED
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
*   Callback functions for FUSA fatal error notification 
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
isdResultsType_e eISDFatalError(uint32 nIntr)
{
    ISD_UNUSED_PARAMETER(nIntr);
    int32_t idx = 0;
    isdResultsType_e return_value = ISD_NOT_OK;
    uint32_t Count = 0;

    /* Skip isolations if SAIL is already in Island state */

    if(ISD_CONTEXT_BASE_ADDRESS->isdState == ISLAND_STATE)
    {
        return_value = ISD_OK;

    }
    else
    {
        ISD_CONTEXT_BASE_ADDRESS->isdState = ISLAND_STATE;
 
       return_value = prvISDSendIPCCInterrupt();

    }
    
    return return_value;

}

/*===========================================================================
**  Function :  ISDGetSailPSHoldFatalErrStatus
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
uint32 ISDGetSailPSHoldFatalErrStatus(void)
{
    return HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_IN;
}

/*===========================================================================
**  Function :  nISDGetIsoEnFatalErrorStatus
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
uint32 nISDGetIsoEnFatalErrorStatus(void)
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
isdResultsType_e eISDConfigFatalErrIsoEnMask(isdFataErrType_e eFatalErr, isdFatalErrMaskType eFatalErrMask)
{
    isdResultsType_e eReturnValue = ISD_NOT_OK;

    if( (eFatalErr <= SPARE_FATAL_EN) && (eFatalErrMask < ISD_FATA_ERR_INVALID ) )
    {
        HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_OUTM( (1u << eFatalErr), (eFatalErrMask << eFatalErr));
        eReturnValue = ISD_OK;
    }    

    return eReturnValue;      
}

/*===========================================================================
**  Function :  eISDCfgFatalErrSailPsHoldMask
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
isdResultsType_e eISDCfgFatalErrSailPsHoldMask(isdFataErrType_e eFatalErr, isdFatalErrMaskType eFatalErrMask)
{
    isdResultsType_e eReturnValue = ISD_NOT_OK;

    if( (eFatalErr <= SPARE_FATAL_EN) && (eFatalErrMask < ISD_FATA_ERR_INVALID))
    {
        HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OUTM( (1 << eFatalErr), (eFatalErrMask << eFatalErr));
        eReturnValue =  ISD_OK;
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
isdResultsType_e eISDSetIsolationState(
                    isdIsolationTypes_e eIso,
                    isdIsolationStateType_e eState)
{
    isdResultsType_e eReturnValue = ISD_NOT_OK;

    if((eIso < ISD_SAIL_ISO_TYPE_MAX) && (eState < ISD_ISOLATION_INVALID))
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
isdIsolationStateType_e eISDGetIsolationState(isdIsolationTypes_e eIso)
{
    volatile uint8 nValue = 0u;
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
isdResultsType_e eISDRegisterNotification( 
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
isdResultsType_e eISDDeregisterNotification( 
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
void vISDInit(void)
{
    /* local variables */


    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS;

    uint8             usIdx = 0;

    uint64 Isdtime = 0;
    //@Todo: use current cpu number
    Isdtime = uBootLogger_LogStartTime("ISD Init Started on core",0);;
    if(pISDDriverContext->isdState != UNDEFINED_STATE)
    {
        // isd state is undefined ;
    }
    else
    {
        /* initialise mutex*/
        (void)mutex_init(&pISDDriverContext->stLock);

        /* get the current state of SAIL */
        if(
            HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK ==
            HWIO_SAILSS_PWR_CTRL_ISD_STATUS_INM ( HWIO_SAILSS_PWR_CTRL_ISD_STATUS_ISD_ISLAND_STATE_BMSK )
        )
        {
            pISDDriverContext->isdState = ISLAND_STATE;
        }
        else
        {
            pISDDriverContext->isdState = NORMAL_STATE;
        }

        /* Configure ISD_FATAL_ERR_ISOLATION_EN_MASK */
        HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK_OUT(ISD_FATAL_ERR_ISOLATION_EN_MASK);

        /* Configure ISD_FATAL_ERR_PS_HOLD_EN_MASK */
        HWIO_SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OUT(ISD_FATAL_ERR_PS_HOLD_EN_MASK);




        /* Configure MD_PS_HOLD pos/neg edge inetrrupt and register for it*/
        (void)eISDOS_RegisterInterrupt(ISD_MD_PS_HOLD_POS_INTR,   ISDOS_TRIGGER_EDGE, (ISDOS_InterruptHandle *)prvMDPSHoldPosEdgeISR, (void *) ISD_CONTEXT_BASE_ADDRESS);
        (void)eISDOS_RegisterInterrupt(ISD_MD_PS_HOLD_NEG_INTR,   ISDOS_TRIGGER_EDGE, (ISDOS_InterruptHandle *)prvMDPSHoldNegEdgeISR, (void *) ISD_CONTEXT_BASE_ADDRESS);
        /* Configure MAIN2SAIL status inetrrupts and register for them*/
        (void)eISDOS_RegisterInterrupt(ISD_TZ_IPC_SEC_INTR,  ISDOS_TRIGGER_EDGE, (ISDOS_InterruptHandle *)prvTZIPCSecISR, (void *) ISD_CONTEXT_BASE_ADDRESS);
        /* Configure MAIN2SAIL non secure interrupt from MD boot stages  and register for it */
        (void)eISDOS_RegisterInterrupt(ISD_TZ_IPC_NON_SEC_INTR,  ISDOS_TRIGGER_EDGE, (ISDOS_InterruptHandle *)prvIPCNonSecISR, (void *) ISD_CONTEXT_BASE_ADDRESS);



        if( IPCC_EOK != IPCC_AttachEx(
                                        &xISD_Hyp_IpccHandle,
                                        IPCC_P_SAIL_MPROC,
                                        IPCC_C_SAIL0,
                                        0
                                      )
         )
         {
             /* Enable Logging */
         }

         if( IPCC_EOK != IPCC_RegisterInterrupt ( 
                                                    xISD_Hyp_IpccHandle,
                                                    IPCC_C_SAIL0,
                                                    ISD_MD_FATAL_ERR_SW_INTR,
                                                    ISD_MD_FATAL_ERR_SW_INTR,
                                                    (IPCC_CB)prvMDFatalErrSWIntrISR,
                                                    (IPCC_CBData)ISD_CONTEXT_BASE_ADDRESS

                                                )
            )
            {
                /* Enable Logging */
            }


        /* Assert sail_to_md_ps_hold */
        (void)eISDSailToMDPSHoldFlwMDPSHold();

        /* Disable Isolations to exit Island Mode */
        if(ISD_OK != eISDDisableIsolations())
        {
            while(1)
            {

            }
            /* TODO Enable logging/error handling */
        }
        //@Todo: use current cpu number
        (void)vBootLogger_LogDeltaTime(Isdtime, "ISD Init Done on core",0);

        eIsdInitStatus = ISD_OK;
    }

   
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

isdResultsType_e eISDDeInit(void)
{
    isdResultsType_e eStatus = ISD_NOT_OK;

    if(ISD_OK == eIsdInitStatus)
    {
        (void)eISDOS_DeRegisterInterrupt(ISD_TZ_IPC_SEC_INTR, FALSE);

        (void)eISDOS_DeRegisterInterrupt(ISD_TZ_IPC_NON_SEC_INTR, FALSE);

        // de-init the shared memory

        ISD_CONTEXT_BASE_ADDRESS->eISDStatus =  ISD_MD2SAIL_STATUS_FAILED;

        eStatus = ISD_OK;
    }
    else
    {
        DEBUG_LOG(SAIL_ERROR,"ISD DeInit Failed\n\r");
    }

    return eStatus;

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
void vISDInitSMP(void)
{

    uint32_t nCurrCPU = ISD_GET_CURRENT_CORE();
    uint32 clientID  = 0U;
    clientID = (uint32)IPCC_C_SAIL0 + nCurrCPU;

    /* Initialize mutex */
    (void)mutex_init(&(ISD_CONTEXT_BASE_ADDRESS->stCoreLock[nCurrCPU]));

    
    /*
        Secondary core need to register for this IPCC intr. 
        This IPCC Intr is triggered from primary core when 
        an MD Fatal error/crash occurs.
    */
    /*eISDOS_RegisterInterrupt
    (ISD_MD_FATAL_ERR_SW_INTR,  ISDOS_TRIGGER_EDGE, 
    (ISDOS_InterruptHandle *)prvMDFatalErrSWIntrISR,
     (void *) ISD_CONTEXT_BASE_ADDRESS);*/
     if( IPCC_EOK != IPCC_AttachEx(
                                    &xISD_Hyp_IpccHandle,
                                    IPCC_P_SAIL_MPROC,
                                    (IPCC_Client)(clientID),
                                    nCurrCPU
                                  )
     )
     {
         /* Enable Logging */
     }

     if( IPCC_EOK != IPCC_RegisterInterrupt ( 
                                                xISD_Hyp_IpccHandle,
                                                IPCC_C_SAIL0,
                                                ISD_MD_FATAL_ERR_SW_INTR,
                                                ISD_MD_FATAL_ERR_SW_INTR,
                                                (IPCC_CB)prvMDFatalErrSWIntrISR,
                                                (IPCC_CBData)ISD_CONTEXT_BASE_ADDRESS
                                            )
        )
        {
            /* Enable Logging */
        }



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
isdResultsType_e prvISDSendIPCCInterrupt(void)
{
    uint32_t CoreNum = 0u;

    isdResultsType_e status = ISD_NOT_OK;

    if(xISD_Hyp_IpccHandle != NULL)
    {
        if(IPCC_EOK == IPCC_Trigger(xISD_Hyp_IpccHandle,(IPCC_C_SAIL2),ISD_MD_FATAL_ERR_SW_INTR,ISD_MD_FATAL_ERR_SW_INTR))
        {
            CoreNum |= (1u << ISD_CORE_2);
        }
        if(IPCC_EOK == IPCC_Trigger(xISD_Hyp_IpccHandle,(IPCC_C_SAIL1),ISD_MD_FATAL_ERR_SW_INTR,ISD_MD_FATAL_ERR_SW_INTR))
        {
            CoreNum |= (1u << ISD_CORE_1);
        }
        if(IPCC_EOK == IPCC_Trigger(xISD_Hyp_IpccHandle,(IPCC_C_SAIL0),ISD_MD_FATAL_ERR_SW_INTR,ISD_MD_FATAL_ERR_SW_INTR))
        {
            CoreNum |= (1u << ISD_CORE_0);
        }

        if(0x7u == CoreNum)
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

/*===========================================================================
**  Function :  eISDSetCustomMDEvStatus
** ==========================================================================
*/
/*!
*
* @brief
*   This function sets custom ISD status (added for TFTP usecase as of now)
*   
*
* @param
*   isdStatusType_e
* @par Dependencies
*   None
* @retval
*   isdStatusType_e
*
*/
isdStatusType_e eISDSetCustomMDEvStatus(isdStatusType_e eSetStatus)
{
    if ((ISD_MD2SAIL_STATUS_FAILED != ISD_CONTEXT_BASE_ADDRESS->eISDStatus) && (ISD_CONTEXT_BASE_ADDRESS->eISDStatus >= eSetStatus))
    {
        ISD_CONTEXT_BASE_ADDRESS->eISDStatus  = eSetStatus;
    }
    return ISD_CONTEXT_BASE_ADDRESS->eISDStatus;
}



/*===========================================================================
**  Function :  vISD_Mdpshold_poll
** ==========================================================================
*/
/*!
*
* @brief
*   This function polls MD_Pshold and then deasserts SAIL_pshold
*   
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   Void
*
*/

void vISD_Mdpshold_poll(void)
{
    volatile uint32 uMDpsholdstat = 0xFFu;
    uMDpsholdstat = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS, MD_PS_HOLD_RAW_STATUS);
    while( 1u == uMDpsholdstat)
    {
        busywait(1u);
        uMDpsholdstat = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS, MD_PS_HOLD_RAW_STATUS);
    }
    /* Point of no return - Deassert Ps hold*/
    (void)eISDSailPSHoldDeAssert();

    /* Will never reach here */
    return;
}

/*=================================================================================================
 @Service name        ISDHVCCallMD_PsHold_Poll
 @Description         SysCall to call Internal ISD API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <HVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

 uint32 ISDHVCCallMD_PsHold_Poll(sailbsp_hvc_rsp_t *rsp)
{
    vISD_Mdpshold_poll();

    return (uint32) HVC_SUCCESS;
}





SAIL_DEFINE_SYSCALL(  (uint32_t)ISD_WRAPPER_POLL_MDPSHOLD_HVC_ID,
                      (uint32_t)ISD_WRAPPER_POLL_MDPSHOLD_PARAM_ID,
                      0u,
                      ISDHVCCallMD_PsHold_Poll
                    );