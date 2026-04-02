/*
===========================================================================
*/
/**
  @file IPCCRx.c

  IPC Controller driver Rx portion of the driver.
*/
/*
  ====================================================================

  Copyright (c) 2021-2025 Qualcomm Technologies,Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies,Inc.

  ====================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/src/IPCCRx.c#1 $
  $DateTime: 2025/02/01 11:39:23 $
  $Author: smarru $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/
#include "IPCC.h"
#include "IPCC_Internal.h"
#include "IPCC_Rx.h"
#include "IPCC_Log.h"
#include "IPCCHWIO.h"
#include "target.h"
#include <stdlib.h>
#include <string.h>
#include "errno.h"
#include "common_functions.h"


/*=========================================================================
      Static defiintions
==========================================================================*/
#define IPCCRX_MAX_PROTOCOLS_USED	        4
static SM_APP_DATA IPCCRxDrvType          RxDrv;
static SM_APP_DATA IPCCRxDrvType          RxDrvEx[SAILBSP_CPU_COUNT][IPCC_P_TOTAL];



/*=========================================================================
      Internal functions
==========================================================================*/

/* =========================================================================
**  Function : IPCC_RxIsrEx_CB
** =========================================================================*/

IPCC_FUNC static void
IPCC_RxIsrEx_CB
(
  void* nArg
)
{
  IPCC_CB           pfnCB;
  IPCC_CBData       nData;
  IPCC_Client       eCid;
  IPCC_Signal       nSig;
  uint32_t          nInData;
  IPCCRxDataType*   pRxList;
  IPCCProtocolType* pProtocol = (IPCCProtocolType*)nArg; 

  /*-------------------------------------------------------------------------*/
  uint8 cpu_id = 0;
  uint8 bClientFound = 0;
  IPCC_Protocol eProtocol_id = pProtocol->nProtocolId;
    

  for( cpu_id = 0;cpu_id < (uint8_t)SAILBSP_CPU_COUNT;cpu_id++)
  {
    if(&(IPCCBSPData[cpu_id].pProtocols[eProtocol_id]) == pProtocol)
    {
      bClientFound = 1;
      break;
    }     
  }

  if(!(bClientFound != 0u))
  {
    IPCCLog_Out(2, "IPCC_RxIsrEx client not found", 0, 0);
    return;
  }

  /* Read IPCC_RECV register to determine the signal */
  nInData = HWIO_INXI2(pProtocol->nVirtBaseAddress, IPC_RECV_ID, 0, 0 );

  while ( nInData != IPCC_NO_DATA )
  {
    /* First clear signal */
    HWIO_OUTXI2(pProtocol->nVirtBaseAddress, IPC_RECV_SIGNAL_CLEAR, 0, 0, nInData);

    /* Clear callback data */
    pfnCB = NULL;
    nData = NULL;

    /* Get Sender CID and SID */
    eCid = (IPCC_Client)IPCC_GET_CID(nInData);
    nSig = (IPCC_Signal)IPCC_GET_SID(nInData);


    /* Enter list critical section */
    if((pProtocol->nProtocolId < IPCC_P_TOTAL) && (eProtocol_id < IPCC_P_TOTAL) && (cpu_id < SAILBSP_CPU_COUNT))
    {
    	IPCCOS_MutexLock(&RxDrvEx[cpu_id][eProtocol_id].RxProtocolDrv[pProtocol->nProtocolId].sMutex);
    }

    /* Get the callback */
    pRxList = pProtocol->pClients[eCid].pList;
    while( pRxList != NULL )
    {
      if( nSig >= pRxList->nSignalLow && nSig <= pRxList->nSignalHigh )
      {
        /* Get Callback Data */
        pfnCB = pRxList->pfnCb;
        nData = pRxList->nArg;

        /* Break since it was handled */
        break;
      }

      pRxList = pRxList->pNext;
    }

    /* Exit list critical section */
    if((pProtocol->nProtocolId < IPCC_P_TOTAL) && (eProtocol_id < IPCC_P_TOTAL) && (cpu_id < SAILBSP_CPU_COUNT))
    {
    	IPCCOS_MutexUnlock(&RxDrvEx[cpu_id][eProtocol_id].RxProtocolDrv[pProtocol->nProtocolId].sMutex);
    }


    if ( pfnCB != NULL )
    {
      pfnCB(nData, eCid, nSig);
    }
    else
    {
      IPCCLog_Out(2, "IPCC_RxIsrEx unhandled signal for eCID %d, nSignal %d", eCid, nSig);
    }
    
    /* Read IPCC_RECV register to check for any other signals */
    nInData = HWIO_INXI2(pProtocol->nVirtBaseAddress, IPC_RECV_ID, 0, 0 );
  }
	
}

IPCC_FUNC static void
IPCC_RxIsrEx
(
  void* nArg
)
{
  //EL1(FreeRTOS)/EL2 ISR handles FPU registers save/restore.
  IPCC_RxIsrEx_CB(nArg);
}


/* =========================================================================
**  Function : IPCCRx_IsOverlap
** =========================================================================*/

IPCC_FUNC  static
boolean 
IPCCRx_IsOverlap
(
   IPCCRxDataType* pData,
   IPCC_Signal     nSignalLow,
   IPCC_Signal     nSignalHigh
)
{

  /*-------------------------------------------------------------------------*/

  if( ( nSignalLow <= pData->nSignalHigh && nSignalLow >= pData->nSignalLow ) ||
      ( nSignalHigh >= pData->nSignalLow && nSignalHigh <= pData->nSignalHigh ) )
  {
    return TRUE;
  }

  return FALSE;
}

/* =========================================================================
**  Function : IPCCRx_IsExactOverlap
** =========================================================================*/

IPCC_FUNC  static
boolean 
IPCCRx_IsExactOverlap
(
   IPCCRxDataType* pData,
   IPCC_Signal     nSignalLow,
   IPCC_Signal     nSignalHigh
)
{

  /*-------------------------------------------------------------------------*/

  if( ( nSignalLow  == pData->nSignalLow  ) && 
      ( nSignalHigh == pData->nSignalHigh ) )
  {
    return TRUE;
  }

  return FALSE;
}

/*=========================================================================
      Functions
==========================================================================*/

/* =========================================================================
**  Function : IPCCRx_InitEx
** =========================================================================*/
/**
  Initialize the IPCC Rx driver.

  This function initializes the IPC controller Rx driver,
  it is the main init entry point for this driver.

  @param
  None.

  @return
  None.

  @dependencies
  None.
*/

IPCC_FUNC  void
IPCCRx_InitEx
(
   IPCCDrvCtxt* pDrv,
   IPCC_Protocol eProtocol,
   uint32_t   sail_client_idx
)
{
    

  /*-------------------------------------------------------------------------*/
  /* Apply Rx Drv to Master Drv */
  if ( pDrv != NULL )
  {
    pDrv->pRxDrv = &RxDrvEx[sail_client_idx][eProtocol];
      //IPCCLog_Out(0, "IPCCRx Initialized DRV: %x\r\n",pDrv);
  }

  IPCCLog_Out(0, "IPCCRx Initialized\r\n");
}



/* =========================================================================
**  Function : IPCCRx_AttachEx
** =========================================================================*/
IPCC_FUNC  void
IPCCRx_AttachEx
(
  IPCCClientCtxt*   pClientCtxt,
  uint32_t sail_client_id
)
{

  /*-------------------------------------------------------------------------*/
  uint32_t cpu_num = 0u;
  uint8 protocol_id = 0u;
  uint8 bClientFound = 0u;
    

  if ( (NULL != pClientCtxt) &&
       (NULL != pClientCtxt->pProtocol) )
  {
    for(protocol_id = 0;protocol_id < (uint8)IPCC_P_TOTAL;protocol_id++)
    {
      if(IPCCBSPData[sail_client_id].pProtocols[protocol_id].nProtocolId == pClientCtxt->pProtocol->nProtocolId)
      {
        bClientFound = 1;
        break;
      }
    }

    if(!(bClientFound != 0u)){

        /* Log failure in registration */
        IPCCLog_Out(3,"IPCCRx_Attach: Client not found\r\n", 
                        0, 
                        0, 
                        0 );
        return ;
    }
    cpu_num = (sail_client_id % 2u); //add a function to get teh cpu num for arch cpu num
  
    if((pClientCtxt->pProtocol->nProtocolId < IPCC_P_TOTAL) && (protocol_id <IPCC_P_TOTAL) && (sail_client_id < SAILBSP_CPU_COUNT))
    {
      pClientCtxt->pRxDrv = &RxDrvEx[sail_client_id][protocol_id].RxProtocolDrv[pClientCtxt->pProtocol->nProtocolId];
    }
    


    /* Check if this is the first reference */
    if( pClientCtxt->pRxDrv->nRefs == (uint32_t)0 && (protocol_id <IPCC_P_TOTAL) && (sail_client_id < SAILBSP_CPU_COUNT))
    {
      /* Initialize Rx Data */
      IPCCOS_MutexInit(&pClientCtxt->pRxDrv->sMutex);

      /* Register for Rx Interrupt */
      if ( IPCC_EOK != (int32_t)IPCCOS_RegisterInterruptEx( &RxDrvEx[sail_client_id][protocol_id].hInterruptHandle,
                                                 pClientCtxt->pProtocol->nInterrupt, 
                                                 0,
                                                 IPCCOS_TRIGGER_HIGH,
                                                 (IPCCOSCB)IPCC_RxIsrEx,
                                                 (void*)pClientCtxt->pProtocol,
                                                 cpu_num  )) 
      {
        /* Log failure in registration */
        IPCCLog_Out(3,"IPCCRx_Attach: Could not register interrupt %d for protocol ID %d\r\n", 
                        pClientCtxt->pProtocol->nInterrupt, 
                        (uintptr_t)pClientCtxt->pProtocol->nProtocolId, 
                        0 );
      }
    }
  if((protocol_id <IPCC_P_TOTAL) && (sail_client_id < SAILBSP_CPU_COUNT))
  {
    pClientCtxt->pRxDrv->nRefs++;
    RxDrvEx[sail_client_id][protocol_id].nRefs++;
  }

  }
}

/* =========================================================================
**  Function : IPCCRx_DetachEx
** =========================================================================*/

IPCC_FUNC  void
IPCCRx_DetachEx
(
  IPCCClientCtxt*   pClientCtxt,
  uint32_t sail_client_id
)
{
  IPCC_Protocol protocol_id;
    
  /*-------------------------------------------------------------------------*/

  if ( pClientCtxt != NULL &&
       pClientCtxt->pRxDrv != NULL)
  {

    protocol_id = pClientCtxt->pProtocol->nProtocolId;

	if( pClientCtxt->pRxDrv->nRefs > (uint32_t)0)
	{
		pClientCtxt->pRxDrv->nRefs--;
	}

	/* KW fix*/
	if((sail_client_id < (uint32_t)SAILBSP_CPU_COUNT) && (protocol_id < IPCC_P_TOTAL))
	{
		RxDrvEx[sail_client_id][protocol_id].nRefs--;
	}

    /* Check if we were the last reference */
    if( pClientCtxt->pRxDrv->nRefs == (uint32_t)0 && sail_client_id < (uint32_t)SAILBSP_CPU_COUNT && (protocol_id < IPCC_P_TOTAL) )
    {
      /* Unregister for Rx Interrupt */
      if ( IPCC_EOK != (int32_t)IPCCOS_DeregisterInterrupt( &RxDrvEx[sail_client_id][protocol_id].hInterruptHandle,
                                                    pClientCtxt->pProtocol->nInterrupt ) ) 
													
      {
        /* Log failure if deregistration fails */
        IPCCLog_Out(3,"IPCCRx_Attach: Could not unregister interrupt %d for protocol ID %d\r\n", 
                        pClientCtxt->pProtocol->nInterrupt, 
                        (uintptr_t)pClientCtxt->pProtocol->nProtocolId, 
                        0 );
      }

      /* Kill mutex */
      IPCCOS_MutexDeinit(&pClientCtxt->pRxDrv->sMutex);
    }

    pClientCtxt->pRxDrv = NULL;
  }
}


/* =========================================================================
**  Function : IPCCRx_RegisterInterrupt
** =========================================================================*/

IPCC_FUNC  IPCC_Status_t
IPCCRx_RegisterInterrupt
(
  IPCCClientCtxt*   pClientCtxt,
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh,
  IPCC_CB           pfnCB,
  IPCC_CBData       nData
)
{
  IPCCRxDataType* pRxData, *pRxList;
  uint32_t nIdx, nSigEn;

  /*-------------------------------------------------------------------------*/

  if( pClientCtxt == NULL ||
      pClientCtxt->pProtocol == NULL ||
      (uint8_t)eCID >= pClientCtxt->pProtocol->nNumClients ||
      nSignalLow > nSignalHigh ||
      nSignalHigh >= pClientCtxt->pProtocol->nNumSigs || 
      pfnCB == NULL )
  {
    IPCCLog_Out(3, "IPCCRx_RegisterInterrupt failed (arg) for eCID %d, nSignalLow %d, nSignalHigh %d\r\n", eCID, nSignalLow, nSignalHigh);
    return IPCC_EARG;
  }

  IPCCLog_Out(3, "IPCCRx_RegisterInterrupt called for eCID %d, SignalLow: %d, SignalHigh: %d\r\n", eCID, nSignalLow, nSignalHigh);

  /* Enter critical section */
  IPCCOS_MutexLock(&pClientCtxt->pRxDrv->sMutex);

  /* Check that all requested lines are not in use */
  pRxList = pClientCtxt->pProtocol->pClients[eCID].pList;
  while( pRxList != NULL )
  {
    if( IPCCRx_IsOverlap(pRxList, nSignalLow, nSignalHigh) )
    {
      IPCCLog_Out(3, "IPCCRx_RegisterInterrupt failed (in use) for eCID %d, nSignalLow %d, nSignalHigh %d\r\n", eCID, nSignalLow, nSignalHigh);

      /* Leave critical section */
      IPCCOS_MutexUnlock(&pClientCtxt->pRxDrv->sMutex);

      return IPCC_EINUSE;
    }

    pRxList = pRxList->pNext;
  }

  /* Now we've confirmed that the lines are not in use, let's get memory and add it to the list */
  pRxData = (IPCCRxDataType*) IPCCOS_Malloc ( sizeof(IPCCRxDataType) );

  /* Fail if we're out of memory for whatever reason */
  if ( pRxData == NULL ) 
  {
    IPCCLog_Out(3, "IPCCRx_RegisterInterrupt failed (no memory) for eCID %d, nSignalLow %d, nSignalHigh %d\r\n", eCID, nSignalLow, nSignalHigh);

    /* Leave critical section */
    IPCCOS_MutexUnlock(&pClientCtxt->pRxDrv->sMutex);

    return IPCC_EMEM;
  }

  /* Clear the memory */
  (void)memset( pRxData, 0, sizeof(IPCCRxDataType) );

  /* Populate structure accordingly */
  pRxData->nSignalLow = nSignalLow;
  pRxData->nSignalHigh = nSignalHigh;
  pRxData->pfnCb = pfnCB;
  pRxData->nArg = nData;

  /* Insert in the list */
  pRxList = pClientCtxt->pProtocol->pClients[eCID].pList;
  if( pRxList == NULL ||
      pRxList->nSignalLow > pRxData->nSignalHigh )
  {
    /* Insert at the front */
    pClientCtxt->pProtocol->pClients[eCID].pList = pRxData;
    pRxData->pNext = pRxList;
  }
  else
  {
    while( pRxList->pNext != NULL )
    {
      if( pRxList->pNext->nSignalLow > pRxData->nSignalHigh )
      {
        break;
      }

      pRxList = pRxList->pNext;
    }

    /* Insert after pRxList */
    pRxData->pNext = pRxList->pNext;
    pRxList->pNext = pRxData;
  }

  /* Leave critical section */
  IPCCOS_MutexUnlock(&pClientCtxt->pRxDrv->sMutex);

  /* Enable the signal for incoming interrupts */
  /* For now, enable one-by-one, but ideally we can use Global enable mask */
  for( nIdx = nSignalLow; nIdx <= nSignalHigh; nIdx++ )
  {
    if(HWIO_SHFT(IPC_RECV_SIGNAL_DISABLE, CLIENT_ID) <= 31)
    {
      nSigEn = ( (uint32_t)eCID << HWIO_SHFT(IPC_RECV_SIGNAL_ENABLE, CLIENT_ID) ) | nIdx;
      HWIO_OUTXI2(pClientCtxt->pProtocol->nVirtBaseAddress, IPC_RECV_SIGNAL_ENABLE, 0, 0, nSigEn);
    }

  }

  return IPCC_EOK;
}


/* =========================================================================
**  Function : IPCCRx_DeregisterInterrupt
** =========================================================================*/

IPCC_FUNC  IPCC_Status_t
IPCCRx_DeregisterInterrupt
(
  IPCCClientCtxt*   pClientCtxt,
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
)
{
  IPCCRxDataType* pRxData, *pRxToRemove, **ppRxList;
  uint32_t nIdx, nSigEn;

  /*-------------------------------------------------------------------------*/

  if( pClientCtxt == NULL ||
      pClientCtxt->pProtocol == NULL ||
      (uint8_t)eCID >= pClientCtxt->pProtocol->nNumClients ||
      nSignalLow > nSignalHigh ||
      nSignalHigh >= pClientCtxt->pProtocol->nNumSigs )
  {
    IPCCLog_Out(3, "IPCCRx_DeregisterInterrupt failed (arg) for eCID %d, nSignalLow %d, nSignalHigh %d\r\n", eCID, nSignalLow, nSignalHigh);
    return IPCC_EARG;
  }

  /* Enter critical section */
  IPCCOS_MutexLock(&pClientCtxt->pRxDrv->sMutex);

  /* Check that all requested lines are in use */
  /* NOTE: Currently the same continuous signal vector needs to be unregistered as registered */
  ppRxList = &pClientCtxt->pProtocol->pClients[eCID].pList;

  if ( *ppRxList == NULL )
  { 
    IPCCLog_Out(3, "IPCCRx_DeregisterInterrupt failed (empty list) for eCID %d, nSignalLow %d, nSignalHigh %d\r\n", eCID, nSignalLow, nSignalHigh);

    /* Leave critical section */
    IPCCOS_MutexUnlock(&pClientCtxt->pRxDrv->sMutex);

    return IPCC_EUNUSED;
  }

  pRxData = *ppRxList;

  if ( ( IPCCRx_IsExactOverlap(*ppRxList, nSignalLow, nSignalHigh) ) )
  {
    /* Head of the list is the match */
    *ppRxList = pRxData->pNext;

    /* Disable in IPCC */
    for ( nIdx = nSignalLow; nIdx <= nSignalHigh; nIdx++ )
    {
      if(HWIO_SHFT(IPC_RECV_SIGNAL_DISABLE, CLIENT_ID) <= 31)
      {
        nSigEn = ( (uint32_t)eCID << HWIO_SHFT(IPC_RECV_SIGNAL_DISABLE, CLIENT_ID) ) | nIdx;
        HWIO_OUTXI2(pClientCtxt->pProtocol->nVirtBaseAddress, IPC_RECV_SIGNAL_DISABLE, 0, 0, nSigEn);
      }

    }

    /* Free memory */
    IPCCOS_Free(pRxData);

    /* Leave critical section */
    IPCCOS_MutexUnlock(&pClientCtxt->pRxDrv->sMutex);

    /* Log removal */
    IPCCLog_Out(3, "IPCCRx_DeregisterInterrupt successful for eCID %d, nSignalLow %d, nSignalHigh %d from head\r\n", eCID, nSignalLow, nSignalHigh);

    return IPCC_EOK;
  }

  while( pRxData->pNext != NULL )
  {
    if( IPCCRx_IsExactOverlap(pRxData->pNext, nSignalLow, nSignalHigh) )
    {
      /* Remove between */
      pRxToRemove = pRxData->pNext;
      pRxData->pNext = pRxToRemove->pNext;

      /* Disable in IPCC */
      for ( nIdx = nSignalLow; nIdx <= nSignalHigh; nIdx++ )
      {
        if(HWIO_SHFT(IPC_RECV_SIGNAL_DISABLE, CLIENT_ID) <= 31)
        {
          nSigEn = ( (uint32_t)eCID << HWIO_SHFT(IPC_RECV_SIGNAL_DISABLE, CLIENT_ID) ) | nIdx;
          HWIO_OUTXI2(pClientCtxt->pProtocol->nVirtBaseAddress, IPC_RECV_SIGNAL_DISABLE, 0, 0, nSigEn);
        }

      }

      /* Free memory */
      IPCCOS_Free(pRxToRemove);

      /* Leave critical section */
      IPCCOS_MutexUnlock(&pClientCtxt->pRxDrv->sMutex);

      /* Log removal */
      IPCCLog_Out(3, "IPCCRx_DeregisterInterrupt successful for eCID %d, nSignalLow %d, nSignalHigh %d from between\r\n", eCID, nSignalLow, nSignalHigh);

      return IPCC_EOK;
    }

    pRxData = pRxData->pNext;
  }

  /* Leave critical section */
  IPCCOS_MutexUnlock(&pClientCtxt->pRxDrv->sMutex);

  IPCCLog_Out(3, "IPCCRx_DeregisterInterrupt failed (not found) for eCID %d, SignalLow: %d, SignalHigh: %d\r\n", eCID, nSignalLow, nSignalHigh);

  return IPCC_ENOTFOUND;
}
