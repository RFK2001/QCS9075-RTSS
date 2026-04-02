/**
 * @file isd_drv.c
 * @brief
 * Source file for private APIs of SAIL isd driver
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

#include "isd_drv.h"
#include "isd_os.h"
#include "HALhwio.h"
#include "sail_csr_hwio.h"

/*===========================================================================
**  Function :  eISDDrv_QAMV4Present
** ==========================================================================
*/
/*!
*
* @brief
*   This function return True if QAMV4 is detected from MD side
*   Mode
*
* @param
*   none
* @par Dependencies
*   None
* @retval
*   boolean True if QAMV4 is present
*
*/

ISD_FUNC boolean eISDDrv_QAMV4Present
(
    void
)
{

    return  (boolean) (ISD_CONTEXT_BASE_ADDRESS->QAMV4_Present);
}


/*===========================================================================
**  Function :  eISDDrv_DeregisterNotification
** ==========================================================================
*/
/*!
*
* @brief
*   This function deregisters an ISD notification
*   Mode
*
* @param
*   pISDDriverContext   ISD Driver context variable
*   pCB                 pointer to callback function
* @par Dependencies
*   None
* @retval
*   isdResultsType_e    ISD_NOT_OK:         ISD Driver not initialised or
*                                           Notification list is NULL
*                       ISD_OK:             De registered sucessfully
*                       ISD_INVALID_FPTR:   passed function pointer
*                                           is not registered
*
*/
ISD_FUNC isdResultsType_e eISDDrv_DeregisterNotification
(
    ISD_DriverContext_t *pISDDriverContext, 
    ISD_ClientNotificationCallbackFn pCB
)
{
    uint32_t nCurrCPU = ISD_GET_CURRENT_CORE();
    isdNotificationListType *pList;
    int8_t nIdx = 0, nIndexToRemove = -1;
    isdResultsType_e returnValue = ISD_NOT_OK;

    if((NULL != pISDDriverContext) && (NULL != pCB))
    {
        pList = &(pISDDriverContext->eNotifyData[nCurrCPU]);

        mutex_lock(&pISDDriverContext->stCoreLock[nCurrCPU]);
        if(pList->nTail > 0u && (pList->nTail < (int8_t)ISD_SAIL_MAX_NOTIFY_CLIENTS) )
        {
            /* Find the element */

            for(nIdx = 0; nIdx < ((int8_t)ISD_SAIL_MAX_NOTIFY_CLIENTS); nIdx++)
            {
                if(pList->eDataArray[nIdx].pCB == pCB)
                {
                    nIndexToRemove = nIdx;
                    break;
                }
            }

            if(nIndexToRemove >= (int8_t)0 )
            {
                /* Shift the elements */
                for(nIdx = nIndexToRemove; nIdx < (pList->nTail - 1); nIdx++)
                {
                    pList->eDataArray[nIdx] = pList->eDataArray[nIdx + 1];
                }

                /* Clear the current tail as it has been shifted */
                pList->eDataArray[nIdx].pCB = NULL;
                pList->eDataArray[nIdx].pCBData = NULL;
                pList->nTail--;

                returnValue = ISD_OK;
            }
            else
            {
                returnValue = ISD_NOT_OK;
            }
            
        }

        mutex_unlock(&pISDDriverContext->stCoreLock[nCurrCPU]);
    }



    return returnValue;
}


ISD_FUNC isdResultsType_e eISDDrv_RegisterNotification
(
    ISD_DriverContext_t *pISDDriverContext, 
    ISD_ClientNotificationCallbackFn pCB, 
    void *pCBData
)
{
	uint32 nCurrCPU = ISD_GET_CURRENT_CORE();
	isdNotificationListType *pList;
    int8_t nIdx = 0;
    isdResultsType_e returnValue = ISD_NOT_OK;

    if((NULL != pISDDriverContext) && (NULL != pCB))
    {
        pList = &(pISDDriverContext->eNotifyData[nCurrCPU]);

        /* Enter critical Section */
        mutex_lock(&pISDDriverContext->stCoreLock[nCurrCPU]);
   
        if(pList->nTail >= (int8_t)ISD_SAIL_MAX_NOTIFY_CLIENTS )
        {
            /* Queue is full */
            returnValue = ISD_INSUFFICIENT_MEMORY;
        }
        else
        {
            /* Check if already exists */
            for(nIdx = 0; nIdx < pList->nTail; nIdx++)
            {
                if(pList->eDataArray[nIdx].pCB == pCB)
                {

                    returnValue = ISD_INVALID_FPTR;
                }
            }
            if(ISD_INVALID_FPTR != returnValue)
            {
                pList->eDataArray[pList->nTail].pCB = pCB;
                pList->eDataArray[pList->nTail].pCBData = pCBData;
                pList->nTail++;
                returnValue = ISD_OK;
            }

        }

        /* Exit critical Section */
        mutex_unlock(&pISDDriverContext->stCoreLock[nCurrCPU]);
    }



    return returnValue;
}

/*===========================================================================
**  Function :  eISD_GetMDBootErrorCode
** ==========================================================================
*/
/*!
*
* @brief
*   This functions returns unique error code for MD boot failures
* @param
*   None
* @par Dependencies
*   None
* @retval
*   uint32 :Unique error code for boot failures from each MD boot stage.
*
*/
ISD_FUNC uint32 eISD_GetMDBootErrorCode(void)
{
  uint32 err_code = 0u;
 
    err_code = ( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG_IN & 0xFFu );
    err_code |= (( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG_IN & 0xFFu ) << 8u );
    err_code |= (( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG_IN & 0xFFu ) << 16u );
    err_code |= (( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG_IN & 0xFFu ) << 24u );
	
  return(err_code);  
}
