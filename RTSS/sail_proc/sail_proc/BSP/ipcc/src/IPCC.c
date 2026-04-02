/**
  @file IPCC.c

  Interface implementation file for the IPC Controller driver.
*/
/*
  ====================================================================

  Copyright (c) 2021 Qualcomm Technologies,Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies,Inc.

  ====================================================================

  $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/ipcc/src/IPCC.c#1 $
  $DateTime: 2025/07/09 22:36:30 $
  $Author: rmunibyr $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/
#include "IPCC.h"
#include "IPCC_Drv.h"
#include "IPCC_Internal.h"
#include "IPCC_Rx.h"
#include "IPCC_Tx.h"
#include "IPCC_Image.h"
#include "IPCC_Log.h"
#include <stdlib.h>
#include <string.h>
#include "target.h"
#include "common_functions.h"
#include "sail_csr_hwio.h"
#include "IPCCHWIO.h"
#include "hw_io.h"
#include "busywait.h"
/*=========================================================================
      Extern Declaration
==========================================================================*/
#define FUSA_ERROR_STATUS_IPCC_BIT            (0x02000000u)//(25U)
#define IPCC_DIAG_TIMEOUT                     (10U)

/*=========================================================================
      Static Variables
==========================================================================*/

static SM_APP_DATA IPCCDrvCtxt IPCCDrv;
static SM_APP_DATA IPCCDrvCtxt IPCCDrvEx[SAILBSP_CPU_COUNT];
static IPCC_Handle IpccHandle_diagnostics = NULL;
static IPCC_Signal LowSignalId = 0U;
static IPCC_Signal HighSignalId = 1U;


/*=========================================================================
      Static Functions
==========================================================================*/

/*=========================================================================
      Functions
==========================================================================*/

/* =========================================================================
**  Function : IPCC_InitEx
** =========================================================================*/
/**
  Initialize the IPCC driver.

  This function initializes the IPC controller driver,
  it is the main init entry point for this driver.

  @param
  None.

  @return
  None.

  @dependencies
  None.
*/

IPCC_FUNC void
IPCC_InitEx
(
  IPCC_Protocol eProtocol,
  uint32_t   sail_client_idx
)
{

  /*-------------------------------------------------------------------------*/
  /* Initialize Log */
  IPCCLog_Init();

  /* Initialize BSP data */
  IPCC_InitImageEx(&IPCCDrvEx[sail_client_idx], eProtocol, sail_client_idx);

  /* Initialize Rx Driver */
  IPCCRx_InitEx(&IPCCDrvEx[sail_client_idx], eProtocol, sail_client_idx);

  /* Initialize Rx Driver */
  IPCCTx_Init(&IPCCDrvEx[sail_client_idx]);

}

/* =========================================================================
**  Function : IPCCDrv_AttachEx
** =========================================================================*/

IPCC_FUNC IPCC_Status_t IPCCDrv_AttachEx
(
  IPCC_Handle   *pH,
  IPCC_Protocol eProtocol,
  IPCC_Client   eClient,
  uint32_t      sail_client_idx
)
{
  IPCCClientCtxt* pClientCtxt;
  uint32_t nIdx=0;
  uint32_t bClientFound = 0;
  IPCC_Protocol eProtocol_id;
  /*-------------------------------------------------------------------------*/

  /* Verify input argument(s) */
  if ( ( pH == NULL                ) ||
       ( eProtocol >= IPCC_P_TOTAL )  ) 
  {
    IPCCLog_Out(1, "IPCCDrvEx_Attach failed, (arg) Protocol %d\r\n", eProtocol);
    return IPCC_EARG;
  }

  /* Make sure driver is initialized */
  if ( IPCCDrvEx[sail_client_idx].pBSP  != NULL)
  {
    for ( nIdx = 0; nIdx < IPCCDrvEx[sail_client_idx].pBSP->nNumProtocols; nIdx++ )
    {
      eProtocol_id =  IPCCDrvEx[sail_client_idx].pBSP->pProtocols[nIdx].nProtocolId;
      if ( eProtocol_id == eProtocol )
      {
        bClientFound = 1;
        break;
      }
    }

    if(!(bClientFound != 0u))
    {
      IPCCLog_Out(1,"IPCCDrvEx_Attach Failed,(arg) Client %d\r\n", eClient);
      return IPCC_EARG;
    }
    /* Check if this protocol is supported */
    if ( IPCCDrvEx[sail_client_idx].pBSP->pProtocols[nIdx].bIsSupported == (uint8_t)FALSE )
    {
      IPCCLog_Out(1, "IPCCDrv_AttachEx failed, Protocol %d not supported on this subsystem\r\n", eProtocol);
      return IPCC_ENOTSUPPORTED;
    }

    /* Malloc client context */
    pClientCtxt = (IPCCClientCtxt*) IPCCOS_Malloc ( sizeof(IPCCClientCtxt) );
    if ( pClientCtxt != NULL )
    {
      /* Clear memory */
      (void)memset(pClientCtxt, 0, sizeof(IPCCClientCtxt));

      /* Set variables for client context */
      pClientCtxt->pProtocol = &IPCCDrvEx[sail_client_idx].pBSP->pProtocols[nIdx];

      /* Attach to the Rx driver */
      if ( pClientCtxt->pProtocol->bIPCCModeSupported == 1u )
      {
        IPCCRx_AttachEx( pClientCtxt,sail_client_idx);
      }

     /* Set client pointer */
     *pH = (IPCC_Handle)pClientCtxt;

     /* Return success */
      return IPCC_EOK;
    }
    IPCCLog_Out(1, "IPCCDrvEx_Attach failed, (arg) IPCCOS_Malloc failed \r\n");
    return IPCC_EMEM;
  }
  
  /* IPCC is not yet initialized */
  IPCCLog_Out(1, "IPCCDrvEx_Attach failed, IPCC is not yet initialized \r\n");
  return IPCC_EGENERR;
}


/* =========================================================================
**  Function : IPCCDrv_Detach
** =========================================================================*/

IPCC_FUNC IPCC_Status_t IPCCDrv_Detach(IPCC_Handle *pH)
{
  IPCCClientCtxt* pClientCtxt;

  /*-------------------------------------------------------------------------*/

  /* Check argument(s) */
  if ( pH != NULL ) 
  {
    /* Get client context */
    pClientCtxt = (IPCCClientCtxt *)*pH;

    /* Clean up client context */
    pClientCtxt->pProtocol = NULL;

    /* Free up the memory */
    IPCCOS_Free(pClientCtxt);

    /* Clear pointer */
    *pH = NULL;

    /* Return success */
    return IPCC_EOK;
  }

  return IPCC_EARG;
}

IPCC_FUNC IPCC_Status_t IPCCDrv_DetachEx
( 
	IPCC_Handle *pH,
	uint32_t sail_client_id
)
{
  IPCCClientCtxt* pClientCtxt;
  /*-------------------------------------------------------------------------*/
  /* Check argument(s) */
  if ( pH != NULL ) 
  {
    /* Get client context */
    pClientCtxt = (IPCCClientCtxt *)*pH;

    if ((pClientCtxt->pProtocol != NULL) && (sail_client_id < SAILBSP_CPU_COUNT ) \
		&& ( pClientCtxt->pProtocol->bIPCCModeSupported == 1u) && (pClientCtxt->pProtocol->nProtocolId< IPCC_P_TOTAL))
	{
      (void)IPCCRx_DetachEx( pClientCtxt, sail_client_id );
    }
    /* Clean up client context */
    pClientCtxt->pProtocol = NULL;
    /* Free up the memory */
    IPCCOS_Free(pClientCtxt);
    /* Clear pointer */
    *pH = NULL;
    /* Return success */
    return IPCC_EOK;
  }
  return IPCC_EARG;
}

/* =========================================================================
**  Function : IPCCDrv_RegisterInterrupt
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCCDrv_RegisterInterrupt
(
  IPCC_Handle       h,
  IPCC_Client       eSenderCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh,
  IPCC_CB           pfnCB,
  IPCC_CBData       nData
)
{
  IPCCClientCtxt* pClientCtxt = (IPCCClientCtxt*)h;
  IPCC_Status_t Ipcc_Status  = IPCC_EGENERR; 

  /*-------------------------------------------------------------------------*/

  /* Check argument(s) */
  if ( ( pClientCtxt == NULL                                ) ||
       ( pfnCB == NULL                                      ) ||
       ( nSignalLow > nSignalHigh                           ) || 
       ( (uint8_t)eSenderCID >= pClientCtxt->pProtocol->nNumClients  )  ) 
  {
    IPCCLog_Out(3, "IPCCDrv_RegisterInterrupt failed (arg) for eSenderCID %d, nSignalLow %d, nSignalHigh %d\r\n", eSenderCID, nSignalLow, nSignalHigh);
    Ipcc_Status = IPCC_EARG;
  }
  
  else if ( pClientCtxt->pProtocol->bIPCCModeSupported == 1u)
  {
    Ipcc_Status = IPCCRx_RegisterInterrupt(pClientCtxt, 
                                    eSenderCID, 
                                    nSignalLow, 
                                    nSignalHigh, 
                                    pfnCB, 
                                    nData);
  }
  else
  {
    IPCCLog_Out(3, "IPCCDrv_RegisterInterrupt failed (not supported) for eSenderCID %d, nSignalLow %d, nSignalHigh %d\r\n", eSenderCID, nSignalLow, nSignalHigh);
    Ipcc_Status = IPCC_ENOTSUPPORTED;
  }

  return Ipcc_Status;
}


/* =========================================================================
**  Function : IPCCDrv_DeregisterInterrupt
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCCDrv_DeregisterInterrupt
(
  IPCC_Handle       h,
  IPCC_Client       eSenderCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
)
{
  IPCCClientCtxt* pClientCtxt = (IPCCClientCtxt*)h;
  IPCC_Status_t Ipcc_Status  = IPCC_EGENERR;

  /*-------------------------------------------------------------------------*/

  /* Check argument(s) */
  if ( ( pClientCtxt == NULL                                ) ||
       ( nSignalLow > nSignalHigh                           ) || 
       ( (uint8_t)eSenderCID >= pClientCtxt->pProtocol->nNumClients  )  ) 
  {
    IPCCLog_Out(3, "IPCCDrv_DeregisterInterrupt failed (arg) for eSenderCID %d, nSignalLow %d, nSignalHigh %d\r\n", eSenderCID, nSignalLow, nSignalHigh);
    Ipcc_Status = IPCC_EARG;
  }

  else if ( pClientCtxt->pProtocol->bIPCCModeSupported == 1u)
  {
    Ipcc_Status = IPCCRx_DeregisterInterrupt(pClientCtxt, 
                                      eSenderCID, 
                                      nSignalLow, 
                                      nSignalHigh);
  }
  else
  {
    IPCCLog_Out(3, "IPCCDrv_DeregisterInterrupt failed (not supported) for eSenderCID %d, nSignalLow %d, nSignalHigh %d\r\n", eSenderCID, nSignalLow, nSignalHigh);
    Ipcc_Status = IPCC_ENOTSUPPORTED;
  }

  return Ipcc_Status;
}


/* =========================================================================
**  Function : IPCCDrv_Trigger
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCCDrv_Trigger
(
  IPCC_Handle       h,
  IPCC_Client       eTargetCID,
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
)
{
  IPCCClientCtxt* pClientCtxt = (IPCCClientCtxt*)h;
  IPCC_Status_t Ipcc_Status  = IPCC_EGENERR;

  /*-------------------------------------------------------------------------*/

  /* Check argument(s) */
  if ( ( pClientCtxt == NULL                                ) ||
       ( (uint8_t)eTargetCID >= pClientCtxt->pProtocol->nNumClients  ) ) 
  {
    IPCCLog_Out(3, "IPCCDrv_Trigger failed (arg) for eTargetCID %d, nSignalLow %d, nSignalHigh %d\r\n", eTargetCID, nSignalLow, nSignalHigh);
    Ipcc_Status = IPCC_EARG;
  }

  else if ( pClientCtxt->pProtocol->bIPCCModeSupported  == 1u)
  {
    Ipcc_Status = IPCCTx_Trigger(pClientCtxt, 
                          eTargetCID, 
                          nSignalLow,
                          nSignalHigh);
  }
  else
  {
    IPCCLog_Out(3, "IPCCDrv_Trigger failed (not supported) for eTargetCID %d, nSignalLow %d, nSignalHigh %d\r\n", eTargetCID, nSignalLow, nSignalHigh);
    Ipcc_Status = IPCC_ENOTSUPPORTED;
  }

  return Ipcc_Status;
}


/* =========================================================================
**  Function : IPCC_diagnostics
** =========================================================================*/
/**
  IPCC Diagnostics function

  @param
  ProtocolType: Internal IPCC protocol
  CpuId:  CPIU/ Core Number


  @return
  None.

  @dependencies
  None.
*/
IPCC_FUNC IPCC_Status_t IPCC_diagnostics(void)
 {
    IPCC_Status_t state = IPCC_EGENERR;
    uint32 timeout_val=0;
    uint32 status = 0;

    // Inject the ipcc err
    REG_OUTF( SAILSS_CSR_SAILSS_CSR_BASE, SAILSS_CSR_IPCC_ERR_INJ_EN, IPCC_ERR_INJ_EN, 0x1);
  
    //Restore the injection enable bit
    REG_OUTF( SAILSS_CSR_SAILSS_CSR_BASE, SAILSS_CSR_IPCC_ERR_INJ_EN, IPCC_ERR_INJ_EN, 0x0);

    //Clear the err_inj register
    REG_OUTF( SAILSS_CSR_SAILSS_CSR_BASE, SAILSS_CSR_IPCC_ERR_INJ_EN_CLR, IPCC_ERR_INJ_EN_CLR	, 0x1);
    
    status = REG_IN(SAILSS_CSR_SAILSS_CSR_BASE, SAILSS_CSR_FUSA_ERROR_STATUS_2);

    do
    {
        if((status & (FUSA_ERROR_STATUS_IPCC_BIT)) != 0u)
        {
          state = IPCC_EOK;
          REG_OUT( SAILSS_CSR_SAILSS_CSR_BASE, SAILSS_CSR_FUSA_ERROR_STATUS_2,FUSA_ERROR_STATUS_IPCC_BIT);
          break;
        }

      //Check the FUSA err_status
      status = REG_IN(SAILSS_CSR_SAILSS_CSR_BASE, SAILSS_CSR_FUSA_ERROR_STATUS_2);   
      busywait(1u);
      timeout_val++;
      
    }while(timeout_val < IPCC_DIAG_TIMEOUT);

    //Restore the inj clr register value
    REG_OUTF( SAILSS_CSR_SAILSS_CSR_BASE, SAILSS_CSR_IPCC_ERR_INJ_EN_CLR, IPCC_ERR_INJ_EN_CLR	, 0x0);

    return state;
  
 }

